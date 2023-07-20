#include <Arduino.h>

#include <vector>
#include <map>

#ifdef ESP8266
#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266HTTPUpdateServer.h>
#else //ESP32 or ESP32S2
#include <WiFi.h>
#include <WebServer.h>
#include <HTTPUpdateServer.h>
#endif

#include <DNSServer.h> //for Captive Portal

#include <NTPClient.h>
#include <WiFiUdp.h>
#include <EEPROM.h>

#include <MD_MAX72xx.h>
#include <EncButton.h>

#include <TCFonts.h>

#define MAX_HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_MAX_DEVICES 4
//#define MAX_DATA_PIN 0 //if using HW SPI then it's automatically MOSI 13
//#define MAX_CLK_PIN 5 //if using HW SPI then it's automatically SCK 14
#define MAX_CS_PIN 15 //if using HW SPI then it's SS 15 (not automatically)

#define ENCODER_TURN_LEFT_PIN 4
#define ENCODER_TURN_RIGHT_PIN 5
#define ENCODER_BUTTON_PIN 0

#define BEEPER_PIN 16

bool isNewBoard = false;
const char* getFirmwareVersion() { const char* result = "1.00"; return result; }

//wifi access point configuration
const char* getWiFiAccessPointSsid() { const char* result = "Timer Clock"; return result; };
const char* getWiFiAccessPointPassword() { const char* result = "1029384756"; return result; };
const IPAddress getWiFiAccessPointIp() { IPAddress result( 192, 168, 1, 1 ); return result; };
const IPAddress getWiFiAccessPointNetMask() { IPAddress result( 255, 255, 255, 0 ); return result; };
const uint32_t TIMEOUT_AP = 180000;

//wifi client configuration
const uint8_t WIFI_SSID_MAX_LENGTH = 32;
const uint8_t WIFI_PASSWORD_MAX_LENGTH = 32;
const char* getWiFiHostName() { const char* result = "Timer-Clock"; return result; }
const uint32_t TIMEOUT_CONNECT_WIFI_SYNC = 90000;
const uint32_t DELAY_WIFI_CONNECTION_CHECK = 60000;

//internal on-board status led config
#ifdef ESP8266
const bool INVERT_INTERNAL_LED = true;
#else //ESP32 or ESP32S2
const bool INVERT_INTERNAL_LED = false;
#endif
const bool INTERNAL_LED_IS_USED = true;
const uint16_t DELAY_INTERNAL_LED_ANIMATION_LOW = 59800;
const uint16_t DELAY_INTERNAL_LED_ANIMATION_HIGH = 200;

//time settings
const uint16_t TIMEOUT_NTP_CLIENT_CONNECT = 2500;
const uint16_t DELAY_NTP_UPDATED_CHECK = 10000;
const uint32_t DELAY_NTP_TIME_SYNC = 3600000;
const bool SEMICOLON_ANIMATION_FAST = true; //semicolon period, true = 60 blinks per minute; false = 30 blinks per minute
const uint16_t DELAY_DISPLAY_ANIMATION = 50; //led animation speed, in ms

//timer settings
uint8_t timerSetupResetTimeSeconds = 30; //CONFIGURABLE amount of time IN SECONDS, if not touched within this amount of time, timer setup will return to clock mode
uint8_t timerRememberLastInputTimeMinutes = 30; //CONFIGURABLE amount of time IN MINUTES during which timer will remember the last used time (to reuse it on single button click)
uint8_t timerDeltaTurnSeconds = 60; //CONFIGURABLE amount IN SECONDS which would be added by default on turn
uint8_t timerDeltaPressMinutes = 5; //CONFIGURABLE amount IN MINUTES which would be added by default on press
uint8_t timerBlinkingTimeMinutes = 60; //CONFIGURABLE max amount of time IN MINUTES the timer would blink when timer is completed
uint8_t timerLongBeepingTimeSeconds = 120; //CONFIGURABLE max amount of time IN SECONDS the timer would beep when timer is completed
uint8_t timerShortBeepingTimeMillis = 50; //max amount of time IN MILLISECONDS the timer would beep for some actions
const bool IS_LOW_LEVEL_BUZZER = true;

uint32_t TIMER_MAX_TIME_TO_SET_UP = ( 23 * 60 + 59 ) * 10 * 1000;

uint32_t timerOldSetupInMillis = 0; //amount of time which was used last time in timer; will be used within timerRememberLastInputTimeMinutes seconds
unsigned long timerOldFinishedTimeMillis = 0; //time when the last timer has been finished; used to determine the timerRememberLastInputTimeMinutes
bool isTimerOldFinished = false; //whether the last timer has finished; used to determine the timerRememberLastInputTimeMinutes (can not use lastTimerFinishedTime as 0 can be a valid millis amount)

uint32_t timerCurrentSetupInMillis = 0 * 60 * 1000; //this is the amount of time user has set up
unsigned long timerCurrentStartedTimeMillis = 0 * 60 * 1000; //when timer started running
bool isTimerRunning = false; //whether timer is running

unsigned long timerSetupLastUpdateMillis = 0; //when setup action was last performed to determine when to return to clock mode after timeout when the user has not started the timer but entered the setting mode
bool isTimerSetupRunning = false; //whether timer setting is running

uint16_t TIMER_BLINKING_DELAY = 1000; //how fast the display will blink when timer is completed
unsigned long timerBlinkingStartTimeMillis = 0;
bool isTimerBlinking = false;
bool isTimerBlinkingShown = false;
unsigned long timerBlinkingLastUpdateMillis = 0;

unsigned long timerLongBeepingStartTimeMillis = 0; //indicates when timer started long beeping
unsigned long timerShortBeepingStartTimeMillis = 0; //indicates when timer started short beeping
bool isTimerLongBeeping = false; //indicates whether timer is beeping long
bool isTimerShortBeeping = false; //indicates whether timer is beeping short

//variables used in the code, don't change anything here
char wiFiClientSsid[WIFI_SSID_MAX_LENGTH];
char wiFiClientPassword[WIFI_PASSWORD_MAX_LENGTH];

uint8_t displayFontTypeNumber = 0;
bool isDisplayBoldFontUsed = true;
bool isDisplaySecondsShown = false;
bool isProgressIndicatorShown = false;
uint8_t displayDayModeBrightness = 9;
uint8_t displayNightModeBrightness = 1;
bool isForceDisplaySync = true;
bool isForceDisplaySyncDisplayRenderOverride = false;
bool isSingleDigitHourShown = false;
bool isRotateDisplay = false;

//brightness settings
const uint16_t DELAY_SENSOR_BRIGHTNESS_UPDATE_CHECK = 50;
const uint16_t SENSOR_BRIGHTNESS_NIGHT_LEVEL = 30;
const uint16_t SENSOR_BRIGHTNESS_DAY_LEVEL = 130;


#ifdef ESP8266
ESP8266WebServer wifiWebServer(80);
ESP8266HTTPUpdateServer httpUpdater;
#else //ESP32 or ESP32S2
WebServer wifiWebServer(80);
HTTPUpdateServer httpUpdater;
#endif

DNSServer dnsServer;
WiFiUDP ntpUdp;
NTPClient timeClient(ntpUdp);
//MD_MAX72XX display = MD_MAX72XX( MAX_HARDWARE_TYPE, MAX_DATA_PIN, MAX_CLK_PIN, MAX_CS_PIN, MAX_MAX_DEVICES );
MD_MAX72XX display = MD_MAX72XX( MAX_HARDWARE_TYPE, MAX_CS_PIN, MAX_MAX_DEVICES );
EncButton<EB_TICK, ENCODER_TURN_LEFT_PIN, ENCODER_TURN_RIGHT_PIN, ENCODER_BUTTON_PIN> enc( INPUT_PULLUP );


//init methods
bool isFirstLoopRun = true;
unsigned long previousMillisDisplayAnimation = millis();
unsigned long previousMillisSemicolonAnimation = millis();
unsigned long previousMillisInternalLed = millis();
unsigned long previousMillisNtpUpdatedCheck = millis();
unsigned long previousMillisWiFiStatusCheck = millis();
unsigned long previousMillisTimeClientStatusCheck = millis();
unsigned long previousMillisSensorBrightnessCheck = millis();

bool forceNtpUpdate = false;

void initVariables() {
  isFirstLoopRun = true;
  unsigned long currentMillis = millis();
  previousMillisDisplayAnimation = currentMillis;
  previousMillisSemicolonAnimation = currentMillis;
  previousMillisInternalLed = currentMillis;
  previousMillisNtpUpdatedCheck = currentMillis;
  previousMillisWiFiStatusCheck = currentMillis;
  previousMillisTimeClientStatusCheck = currentMillis;
  previousMillisSensorBrightnessCheck = currentMillis;
}



//auxiliary functions
unsigned long calculateDiffMillis( unsigned long startMillis, unsigned long endMillis ) { //this function accounts for millis overflow when calculating millis difference
  if( endMillis >= startMillis ) {
    return endMillis - startMillis;
  } else {
    return( ULONG_MAX - startMillis ) + endMillis + 1;
  }
}



//eeprom functionality
const uint16_t eepromIsNewBoardIndex = 0;
const uint16_t eepromWiFiSsidIndex = eepromIsNewBoardIndex + 1;
const uint16_t eepromWiFiPasswordIndex = eepromWiFiSsidIndex + WIFI_SSID_MAX_LENGTH;
const uint16_t eepromDisplayFontTypeNumberIndex = eepromWiFiPasswordIndex + WIFI_PASSWORD_MAX_LENGTH;
const uint16_t eepromIsFontBoldUsedIndex = eepromDisplayFontTypeNumberIndex + 1;
const uint16_t eepromIsDisplaySecondsShownIndex = eepromIsFontBoldUsedIndex + 1;
const uint16_t eepromDisplayDayModeBrightnessIndex = eepromIsDisplaySecondsShownIndex + 1;
const uint16_t eepromDisplayNightModeBrightnessIndex = eepromDisplayDayModeBrightnessIndex + 1;
const uint16_t eepromTimerSetupResetTimeIndex = eepromDisplayNightModeBrightnessIndex + 1;
const uint16_t eepromTimerRememberLastInputTimeIndex = eepromTimerSetupResetTimeIndex + 1;
const uint16_t eepromTimerDeltaPressIndex = eepromTimerRememberLastInputTimeIndex + 1;
const uint16_t eepromTimerDeltaTurnIndex = eepromTimerDeltaPressIndex + 1;
const uint16_t eepromTimerBlinkingTimeIndex = eepromTimerDeltaTurnIndex + 1;
const uint16_t eepromTimerBeepingTimeIndex = eepromTimerBlinkingTimeIndex + 1;
const uint16_t eepromTimerIsProgressIndicatorShownIndex = eepromTimerBeepingTimeIndex + 1;
const uint16_t eepromIsSingleDigitHourShownIndex = eepromTimerIsProgressIndicatorShownIndex + 1;
const uint16_t eepromIsRotateDisplayIndex = eepromIsSingleDigitHourShownIndex + 1;
const uint16_t eepromLastByteIndex = eepromIsRotateDisplayIndex + 1;

const uint16_t EEPROM_ALLOCATED_SIZE = eepromLastByteIndex;
void initEeprom() {
  EEPROM.begin( EEPROM_ALLOCATED_SIZE ); //init this many bytes
}

bool readEepromCharArray( const uint16_t& eepromIndex, char* variableWithValue, uint8_t maxLength, bool doApplyValue ) {
  bool isDifferentValue = false;
  uint16_t eepromStartIndex = eepromIndex;
  for( uint16_t i = eepromStartIndex; i < eepromStartIndex + maxLength; i++ ) {
    char eepromChar = EEPROM.read(i);
    if( doApplyValue ) {
      variableWithValue[i-eepromStartIndex] = eepromChar;
    } else {
      isDifferentValue = isDifferentValue || variableWithValue[i-eepromStartIndex] != eepromChar;
    }
  }
  return isDifferentValue;
}

bool writeEepromCharArray( const uint16_t& eepromIndex, char* newValue, uint8_t maxLength ) {
  bool isDifferentValue = readEepromCharArray( eepromIndex, newValue, maxLength, false );
  if( !isDifferentValue ) return false;
  uint16_t eepromStartIndex = eepromIndex;
  for( uint16_t i = eepromStartIndex; i < eepromStartIndex + maxLength; i++ ) {
    EEPROM.write( i, newValue[i-eepromStartIndex] );
  }
  EEPROM.commit();
  delay( 20 );
  return true;
}

uint8_t readEepromIntValue( const uint16_t& eepromIndex, uint8_t& variableWithValue, bool doApplyValue ) {
  uint8_t eepromValue = EEPROM.read( eepromIndex );
  if( doApplyValue ) {
    variableWithValue = eepromValue;
  }
  return eepromValue;
}

bool writeEepromIntValue( const uint16_t& eepromIndex, uint8_t newValue ) {
  bool eepromWritten = false;
  if( readEepromIntValue( eepromIndex, newValue, false ) != newValue ) {
    EEPROM.write( eepromIndex, newValue );
    eepromWritten = true;
  }
  if( eepromWritten ) {
    EEPROM.commit();
    delay( 20 );
  }
  return eepromWritten;
}

bool readEepromBoolValue( const uint16_t& eepromIndex, bool& variableWithValue, bool doApplyValue ) {
  uint8_t eepromValue = EEPROM.read( eepromIndex ) != 0 ? 1 : 0;
  if( doApplyValue ) {
    variableWithValue = eepromValue;
  }
  return eepromValue;
}

bool writeEepromBoolValue( const uint16_t& eepromIndex, bool newValue ) {
  bool eepromWritten = false;
  if( readEepromBoolValue( eepromIndex, newValue, false ) != newValue ) {
    EEPROM.write( eepromIndex, newValue ? 1 : 0 );
    eepromWritten = true;
  }
  if( eepromWritten ) {
    EEPROM.commit();
    delay( 20 );
  }
  return eepromWritten;
}

void loadEepromData() {
  readEepromBoolValue( eepromIsNewBoardIndex, isNewBoard, true );
  if( !isNewBoard ) {

    readEepromCharArray( eepromWiFiSsidIndex, wiFiClientSsid, WIFI_SSID_MAX_LENGTH, true );
    readEepromCharArray( eepromWiFiPasswordIndex, wiFiClientPassword, WIFI_PASSWORD_MAX_LENGTH, true );
    readEepromIntValue( eepromDisplayFontTypeNumberIndex, displayFontTypeNumber, true );
    readEepromBoolValue( eepromIsFontBoldUsedIndex, isDisplayBoldFontUsed, true );
    readEepromBoolValue( eepromIsDisplaySecondsShownIndex, isDisplaySecondsShown, true );
    readEepromIntValue( eepromDisplayDayModeBrightnessIndex, displayDayModeBrightness, true );
    readEepromIntValue( eepromDisplayNightModeBrightnessIndex, displayNightModeBrightness, true );
    if( timerSetupResetTimeSeconds < 5 ) timerSetupResetTimeSeconds = 30;
    readEepromIntValue( eepromTimerSetupResetTimeIndex, timerSetupResetTimeSeconds, true );
    readEepromIntValue( eepromTimerRememberLastInputTimeIndex, timerRememberLastInputTimeMinutes, true );
    readEepromIntValue( eepromTimerDeltaPressIndex, timerDeltaPressMinutes, true );
    readEepromIntValue( eepromTimerDeltaTurnIndex, timerDeltaTurnSeconds, true );
    if( timerDeltaTurnSeconds == 0 ) timerDeltaTurnSeconds = 60;
    readEepromIntValue( eepromTimerBlinkingTimeIndex, timerBlinkingTimeMinutes, true );
    readEepromIntValue( eepromTimerBeepingTimeIndex, timerLongBeepingTimeSeconds, true );
    readEepromBoolValue( eepromTimerIsProgressIndicatorShownIndex, isProgressIndicatorShown, true );
    readEepromBoolValue( eepromIsSingleDigitHourShownIndex, isSingleDigitHourShown, true );
    readEepromBoolValue( eepromIsRotateDisplayIndex, isRotateDisplay, true );

  } else { //fill EEPROM with default values when starting the new board
    writeEepromBoolValue( eepromIsNewBoardIndex, false );

    writeEepromCharArray( eepromWiFiSsidIndex, wiFiClientSsid, WIFI_SSID_MAX_LENGTH );
    writeEepromCharArray( eepromWiFiPasswordIndex, wiFiClientPassword, WIFI_PASSWORD_MAX_LENGTH );
    writeEepromIntValue( eepromDisplayFontTypeNumberIndex, displayFontTypeNumber );
    writeEepromBoolValue( eepromIsFontBoldUsedIndex, isDisplayBoldFontUsed );
    writeEepromBoolValue( eepromIsDisplaySecondsShownIndex, isDisplaySecondsShown );
    writeEepromIntValue( eepromDisplayDayModeBrightnessIndex, displayDayModeBrightness );
    writeEepromIntValue( eepromDisplayNightModeBrightnessIndex, displayNightModeBrightness );
    if( timerSetupResetTimeSeconds < 5 ) timerSetupResetTimeSeconds = 30;
    writeEepromIntValue( eepromTimerSetupResetTimeIndex, timerSetupResetTimeSeconds );
    writeEepromIntValue( eepromTimerRememberLastInputTimeIndex, timerRememberLastInputTimeMinutes );
    writeEepromIntValue( eepromTimerDeltaPressIndex, timerDeltaPressMinutes );
    if( timerDeltaTurnSeconds == 0 ) timerDeltaTurnSeconds = 60;
    writeEepromIntValue( eepromTimerDeltaTurnIndex, timerDeltaTurnSeconds );
    writeEepromIntValue( eepromTimerBlinkingTimeIndex, timerBlinkingTimeMinutes );
    writeEepromIntValue( eepromTimerBeepingTimeIndex, timerLongBeepingTimeSeconds );
    writeEepromBoolValue( eepromTimerIsProgressIndicatorShownIndex, isProgressIndicatorShown );
    writeEepromBoolValue( eepromIsSingleDigitHourShownIndex, isSingleDigitHourShown );
    writeEepromBoolValue( eepromIsRotateDisplayIndex, isRotateDisplay );

    isNewBoard = false;
  }
}


//wifi connection as AP
bool isApInitialized = false;
unsigned long apStartedMillis;

void createAccessPoint() {
  if( isApInitialized ) return;
  isApInitialized = true;
  apStartedMillis = millis();
  Serial.print( F("Creating WiFi AP...") );
  WiFi.softAPConfig( getWiFiAccessPointIp(), getWiFiAccessPointIp(), getWiFiAccessPointNetMask() );
  WiFi.softAP( ( String( getWiFiAccessPointSsid() ) + " " + String( ESP.getChipId() ) ).c_str(), getWiFiAccessPointPassword(), 0, false );
  IPAddress accessPointIp = WiFi.softAPIP();
  dnsServer.start( 53, "*", accessPointIp );
  Serial.println( String( F(" done | IP: ") ) + accessPointIp.toString() );
}

void shutdownAccessPoint() {
  if( !isApInitialized ) return;
  isApInitialized = false;
  Serial.print( F("Shutting down WiFi AP...") );
  dnsServer.stop();
  WiFi.softAPdisconnect( true );
  Serial.println( F(" done") );
}


//internal led functionality
uint8_t internalLedStatus = HIGH;

uint8_t getInternalLedStatus() {
   return internalLedStatus;
}

void setInternalLedStatus( uint8_t status ) {
  internalLedStatus = status;

  if( INTERNAL_LED_IS_USED ) {
    digitalWrite( LED_BUILTIN, INVERT_INTERNAL_LED ? ( status == HIGH ? LOW : HIGH ) : status );
  }
}

void initInternalLed() {
  if( INTERNAL_LED_IS_USED ) {
    pinMode( LED_BUILTIN, OUTPUT );
  }
  setInternalLedStatus( internalLedStatus );
}


//time of day functionality
bool isTimeClientInitialised = false;
unsigned long timeClientUpdatedMillis = 0;
bool timeClientTimeInitStatus = false;
void initTimeClient() {
  if( WiFi.isConnected() && !isTimeClientInitialised ) {
    timeClient.setUpdateInterval( DELAY_NTP_TIME_SYNC );
    Serial.print( F("Starting NTP client...") );
    timeClient.begin();
    isTimeClientInitialised = true;
    Serial.println( F(" done") );
  }
}

bool updateTimeClient( bool canWait ) {
  if( !WiFi.isConnected() ) return false;
  if( !timeClient.isTimeSet() ) {
    if( !isTimeClientInitialised ) {
      initTimeClient();
    }
    if( isTimeClientInitialised ) {
      Serial.print( F("Updating NTP time...") );
      timeClient.update();
      if( canWait ) {
        timeClientUpdatedMillis = millis();
        while( !timeClient.isTimeSet() && ( calculateDiffMillis( timeClientUpdatedMillis, millis() ) < TIMEOUT_NTP_CLIENT_CONNECT ) ) {
          delay( 250 );
          Serial.print( "." );
        }
      }
      Serial.println( F(" done") );
      previousMillisTimeClientStatusCheck = millis();
    }
  }
  return true;
}

bool isWithinDstBoundaries( time_t dt ) {
  struct tm *timeinfo = gmtime(&dt);

  // Get the last Sunday of March in the current year
  struct tm lastMarchSunday = {0};
  lastMarchSunday.tm_year = timeinfo->tm_year;
  lastMarchSunday.tm_mon = 2; // March (0-based)
  lastMarchSunday.tm_mday = 31; // Last day of March
  mktime(&lastMarchSunday);
  while (lastMarchSunday.tm_wday != 0) { // 0 = Sunday
    lastMarchSunday.tm_mday--;
    mktime(&lastMarchSunday);
  }
  lastMarchSunday.tm_hour = 1;
  lastMarchSunday.tm_min = 0;
  lastMarchSunday.tm_sec = 0;

  // Get the last Sunday of October in the current year
  struct tm lastOctoberSunday = {0};
  lastOctoberSunday.tm_year = timeinfo->tm_year;
  lastOctoberSunday.tm_mon = 9; // October (0-based)
  lastOctoberSunday.tm_mday = 31; // Last day of October
  mktime(&lastOctoberSunday);
  while (lastOctoberSunday.tm_wday != 0) { // 0 = Sunday
    lastOctoberSunday.tm_mday--;
    mktime(&lastOctoberSunday);
  }
  lastOctoberSunday.tm_hour = 1;
  lastOctoberSunday.tm_min = 0;
  lastOctoberSunday.tm_sec = 0;

  // Convert the struct tm to time_t
  time_t lastMarchSunday_t = mktime(&lastMarchSunday);
  time_t lastOctoberSunday_t = mktime(&lastOctoberSunday);

  // Check if the datetime is within the DST boundaries
  return dt > lastMarchSunday_t && dt < lastOctoberSunday_t;
}


//display functionality
double displayCurrentBrightness = static_cast<double>(displayNightModeBrightness);
double displayPreviousBrightness = -1.0;
double sensorBrightnessAverage = -1.0;
//uint16_t DELAY_DISPLAY_BRIGHTNESS_TOLERANCE_MILLIS = 5000;
//unsigned long previousDisplayBrightnessToleranceUpdatedMillis = millis();

void calculateDisplayBrightness() {
  uint16_t currentBrightness = analogRead(A0);
  if( sensorBrightnessAverage < 0 ) {
    sensorBrightnessAverage = currentBrightness;
  } else {
    uint8_t sensorBrightnessSamples = 50;
    sensorBrightnessAverage = ( sensorBrightnessAverage * ( sensorBrightnessSamples - 1 ) + currentBrightness ) / sensorBrightnessSamples;
  }

  if( sensorBrightnessAverage >= SENSOR_BRIGHTNESS_DAY_LEVEL ) {
    displayCurrentBrightness = static_cast<double>(displayDayModeBrightness);
  } else if( sensorBrightnessAverage <= SENSOR_BRIGHTNESS_NIGHT_LEVEL ) {
    displayCurrentBrightness = static_cast<double>(displayNightModeBrightness);
  } else {
    displayCurrentBrightness = displayNightModeBrightness + static_cast<double>( displayDayModeBrightness - displayNightModeBrightness ) * ( sensorBrightnessAverage - SENSOR_BRIGHTNESS_NIGHT_LEVEL ) / ( SENSOR_BRIGHTNESS_DAY_LEVEL - SENSOR_BRIGHTNESS_NIGHT_LEVEL );
  }
}

void setDisplayBrightness( uint8_t displayNewBrightness ) {
  display.control( MD_MAX72XX::INTENSITY, displayNewBrightness );
  display.control( MD_MAX72XX::UPDATE, MD_MAX72XX::OFF );
}

void setDisplayBrightness( bool isInit ) {
  //unsigned long currentMillis = millis();
  bool updateDisplayBrightness = false;
  uint8_t displayCurrentBrightnessInt = static_cast<uint8_t>( round( displayCurrentBrightness ) );
  uint8_t displayPreviousBrightnessInt = static_cast<uint8_t>( round( displayPreviousBrightness ) );

  if( isInit || displayPreviousBrightness < 0 ) {
    updateDisplayBrightness = true;
  } else if( displayCurrentBrightnessInt != displayPreviousBrightnessInt ) {
    double hysteresis = 0.1;
    if( ( displayCurrentBrightness > displayPreviousBrightness && ( displayCurrentBrightness > ( ceil( displayCurrentBrightness ) - 0.5 + hysteresis ) ) ) ||
        ( displayCurrentBrightness < displayPreviousBrightness && ( displayCurrentBrightness < ( floor(  displayCurrentBrightness ) + 0.5 - hysteresis ) ) ) ) {
      updateDisplayBrightness = true;
    }
  }

  /*if( isInit ) {
    updateDisplayBrightness = true;
  } else if( displayCurrentBrightnessInt != displayPreviousBrightnessInt ) {
    if( calculateDiffMillis( previousDisplayBrightnessToleranceUpdatedMillis, currentMillis ) < DELAY_DISPLAY_BRIGHTNESS_TOLERANCE_MILLIS ) {
      uint8_t diffTolerance = 1;
      uint8_t brightnessDiff = displayCurrentBrightnessInt > displayPreviousBrightnessInt ? displayCurrentBrightnessInt - displayPreviousBrightnessInt : displayPreviousBrightnessInt - displayCurrentBrightnessInt;
      if( brightnessDiff > diffTolerance ) {
        updateDisplayBrightness = true;
      }
    } else {
      updateDisplayBrightness = true;
    }
  }*/

  if( updateDisplayBrightness ) {
    setDisplayBrightness( displayCurrentBrightnessInt );
    displayPreviousBrightness = displayCurrentBrightness;
    //previousDisplayBrightnessToleranceUpdatedMillis = currentMillis;
  }
}

void initDisplay() {
  calculateDisplayBrightness();
  display.begin();
  setDisplayBrightness( true );
  display.clear();
}

void brightnessProcessLoopTick() {
  if( calculateDiffMillis( previousMillisSensorBrightnessCheck, millis() ) >= DELAY_SENSOR_BRIGHTNESS_UPDATE_CHECK ) {
    calculateDisplayBrightness();
    setDisplayBrightness( false );
    previousMillisSensorBrightnessCheck = millis();
  }
}

const uint8_t DISPLAY_WIDTH = 32;
const uint8_t DISPLAY_HEIGHT = 8;

bool isSemicolonShown = true;
void renderDisplayText( String textToDisplayLarge, String textToDisplaySmall ) {
  uint8_t displayWidthUsed = 0;
  for( size_t charToDisplayIndex = 0; charToDisplayIndex < textToDisplayLarge.length(); ++charToDisplayIndex ) {
    char charToDisplay = textToDisplayLarge.charAt( charToDisplayIndex );
    uint8_t charWidth = TCFonts::getSymbolWidth( displayFontTypeNumber, charToDisplay, isDisplayBoldFontUsed, !isDisplaySecondsShown, isTimerRunning ? isProgressIndicatorShown : false, false );
    if( displayWidthUsed + charWidth > DISPLAY_WIDTH ) {
      charWidth = DISPLAY_WIDTH - displayWidthUsed;
    }
    if( charWidth == 0 ) continue;
    std::vector<uint8_t> charImage = TCFonts::getSymbol( displayFontTypeNumber, charToDisplay, isDisplayBoldFontUsed, !isDisplaySecondsShown, isTimerRunning ? isProgressIndicatorShown : false, false );

    for( uint8_t charY = 0; charY < DISPLAY_HEIGHT; ++charY ) {
      for( uint8_t charX = 0; charX < charWidth; ++charX ) {
        if( isRotateDisplay ) {
          display.setPoint(
            DISPLAY_HEIGHT - 1 - charY,
            displayWidthUsed + charX,
            ( charY < DISPLAY_HEIGHT - charImage.size() ) ? 0 : ( charImage[charY - DISPLAY_HEIGHT + charImage.size()] >> ( DISPLAY_HEIGHT - 1 - charX ) ) & 1
          );
        } else {
          display.setPoint(
            charY,
            DISPLAY_WIDTH - 1 - ( displayWidthUsed + charX ),
            ( charY < DISPLAY_HEIGHT - charImage.size() ) ? 0 : ( charImage[charY - DISPLAY_HEIGHT + charImage.size()] >> ( DISPLAY_HEIGHT - 1 - charX ) ) & 1
          );
        }
      }
    }
    displayWidthUsed += charWidth;
  }

  for( size_t charToDisplayIndex = 0; charToDisplayIndex < textToDisplaySmall.length(); ++charToDisplayIndex ) {
    char charToDisplay = textToDisplaySmall.charAt( charToDisplayIndex );
    uint8_t charWidth = TCFonts::getSymbolWidth( displayFontTypeNumber, charToDisplay, isDisplayBoldFontUsed, !isDisplaySecondsShown, isTimerRunning ? isProgressIndicatorShown : false, true );
    if( displayWidthUsed + charWidth > DISPLAY_WIDTH ) {
      charWidth = DISPLAY_WIDTH - displayWidthUsed;
    }
    if( charWidth == 0 ) continue;
    std::vector<uint8_t> charImage = TCFonts::getSymbol( displayFontTypeNumber, charToDisplay, isDisplayBoldFontUsed, !isDisplaySecondsShown, isTimerRunning ? isProgressIndicatorShown : false, true );

    for( uint8_t charY = 0; charY < DISPLAY_HEIGHT; ++charY ) {
      for( uint8_t charX = 0; charX < charWidth; ++charX ) {
        if( isRotateDisplay ) {
          display.setPoint(
            DISPLAY_HEIGHT - 1 - charY,
            displayWidthUsed + charX,
            ( charY < DISPLAY_HEIGHT - charImage.size() ) ? 0 : ( charImage[charY - DISPLAY_HEIGHT + charImage.size()] >> ( DISPLAY_HEIGHT - 1 - charX ) ) & 1
          );
        } else {
          display.setPoint(
            charY,
            DISPLAY_WIDTH - 1 - ( displayWidthUsed + charX ),
            ( charY < DISPLAY_HEIGHT - charImage.size() ) ? 0 : ( charImage[charY - DISPLAY_HEIGHT + charImage.size()] >> ( DISPLAY_HEIGHT - 1 - charX ) ) & 1
          );
        }
      }
    }
    displayWidthUsed += charWidth;
  }

  if( displayWidthUsed < DISPLAY_WIDTH ) { //fill the rest of the screen
    for( uint8_t charY = 0; charY < DISPLAY_HEIGHT; ++charY ) {
      for( uint8_t charX = 0; charX < DISPLAY_WIDTH - displayWidthUsed; ++charX ) {
        if( isRotateDisplay ) {
          display.setPoint(
            DISPLAY_HEIGHT - 1 - charY,
            displayWidthUsed + charX,
            false
          );
        } else {
          display.setPoint(
            charY,
            DISPLAY_WIDTH - 1 - ( displayWidthUsed + charX ),
            false
          );
        }
      }
    }
  }
}

void renderProgressIndicator( unsigned long timerRemainingMillis ) {
  if( !isProgressIndicatorShown ) return;
  unsigned long numberOfDots = timerRemainingMillis == 0 ? 0 : ( timerRemainingMillis * ( DISPLAY_WIDTH + 1 ) / timerCurrentSetupInMillis );
  for( uint8_t charX = 0; charX < DISPLAY_WIDTH; ++charX ) {
    if( isRotateDisplay ) {
      display.setPoint(
        DISPLAY_HEIGHT - 1,
        charX,
        charX < numberOfDots
      );
    } else {
      display.setPoint(
        0,
        DISPLAY_WIDTH - 1 - ( charX ),
        charX < numberOfDots
      );
    }
  }
}

void renderDisplay() {
  if( isTimerRunning ) {
    unsigned long timerRemainingMillis = timerCurrentStartedTimeMillis + timerCurrentSetupInMillis < millis() ? 0 : timerCurrentStartedTimeMillis + timerCurrentSetupInMillis - millis();
    unsigned long hour = timerRemainingMillis / (1000UL * 60UL * 60UL);
    unsigned long remainingMillis = timerRemainingMillis % (1000UL * 60UL * 60UL);
    unsigned long minute = remainingMillis / (1000UL * 60UL);
    remainingMillis %= (1000UL * 60UL);
    unsigned long second = remainingMillis / 1000UL;

    String hourStr = ( hour < 10 ? ( isSingleDigitHourShown ? " " : "0" ) : "" ) + String( hour );
    String minuteStr = ( minute < 10 ? "0" : "" ) + String( minute );
    String secondStr = ( second < 10 ? "0" : "" ) + String( second );

    String textToDisplayLarge = ( isDisplaySecondsShown || hour > 0 ) ? ( hourStr + ( isSemicolonShown ? "\b" : "\f" ) + minuteStr ) : ( minuteStr + ( isSemicolonShown ? "\b" : "\f" ) + secondStr );
    String textToDisplaySmall = isDisplaySecondsShown ? secondStr : String( "" );
    renderDisplayText( textToDisplayLarge, textToDisplaySmall );
    renderProgressIndicator( timerRemainingMillis );

  } else if( isTimerSetupRunning ) {
    unsigned long hour = timerCurrentSetupInMillis / (1000UL * 60UL * 60UL);
    unsigned long remainingMillis = timerCurrentSetupInMillis % (1000UL * 60UL * 60UL);
    unsigned long minute = remainingMillis / (1000UL * 60UL);
    remainingMillis %= (1000UL * 60UL);
    unsigned long second = remainingMillis / 1000UL;

    String hourStr = ( hour < 10 ? ( isSingleDigitHourShown ? " " : "0" ) : "" ) + String( hour );
    String minuteStr = ( minute < 10 ? "0" : "" ) + String( minute );
    String secondStr = ( second < 10 ? "0" : "" ) + String( second );

    String textToDisplayLarge = ( isDisplaySecondsShown || hour > 0 ) ? ( hourStr + String( ":" ) + minuteStr ) : ( minuteStr + String( ":" ) + secondStr );
    String textToDisplaySmall = isDisplaySecondsShown ? secondStr : String( "" );
    renderDisplayText( textToDisplayLarge, textToDisplaySmall );

  } else if( isTimerBlinking ) {
    if( calculateDiffMillis( timerBlinkingLastUpdateMillis, millis() ) >= TIMER_BLINKING_DELAY ) {
      isTimerBlinkingShown = !isTimerBlinkingShown;
      timerBlinkingLastUpdateMillis += TIMER_BLINKING_DELAY;
    }

    String textToDisplayLarge = isTimerBlinkingShown ? String( "00:00" ) : String( "  \t  " );
    String textToDisplaySmall = isTimerBlinkingShown ? ( isDisplaySecondsShown ? String( "00" ) : String( "" ) ) : ( isDisplaySecondsShown ? String( "  " ) : String( "" ) );
    renderDisplayText( textToDisplayLarge, textToDisplaySmall );

  } else if( timeClient.isTimeSet() ) {
    time_t dt = timeClient.getEpochTime();
    struct tm* dtStruct = localtime(&dt);
    uint8_t hour = dtStruct->tm_hour;
    hour += isWithinDstBoundaries( dt ) ? 3 : 2;
    if( hour >= 24 ) {
      hour = hour - 24;
    }
    String hourStr = ( hour < 10 ? ( isSingleDigitHourShown ? " " : "0" ) : "" ) + String( hour );
    uint8_t minute = dtStruct->tm_min;
    String minuteStr = ( minute < 10 ? "0" : "" ) + String( minute );
    uint8_t second = dtStruct->tm_sec;
    String secondStr = ( second < 10 ? "0" : "" ) + String( second );

    String textToDisplayLarge = hourStr + ( isSemicolonShown ? ":" : "\t" ) + minuteStr;
    String textToDisplaySmall = isDisplaySecondsShown ? secondStr : String( "" );
    renderDisplayText( textToDisplayLarge, textToDisplaySmall );
  } else {
    String textToDisplayLarge = String( "  " ) + ( isSemicolonShown ? ":" : "\t" ) + String( "  " );
    String textToDisplaySmall = isDisplaySecondsShown ? String( "  " ) : String( "" );
    renderDisplayText( textToDisplayLarge, textToDisplaySmall );
  }
  display.update();
}


//data update helpers
void forceRefreshData() {
  initVariables();
  initTimeClient();
}


//wifi connection as a client
const String getWiFiStatusText( wl_status_t status ) {
  switch (status) {
    case WL_IDLE_STATUS:
      return F("IDLE_STATUS");
    case WL_NO_SSID_AVAIL:
      return F("NO_SSID_AVAIL");
    case WL_SCAN_COMPLETED:
      return F("SCAN_COMPLETED");
    case WL_CONNECTED:
      return F("CONNECTED");
    case WL_CONNECT_FAILED:
      return F("CONNECT_FAILED");
    case WL_CONNECTION_LOST:
      return F("CONNECTION_LOST");
    case WL_WRONG_PASSWORD:
      return F("WRONG_PASSWORD");
    case WL_DISCONNECTED:
      return F("DISCONNECTED");
    default:
      return F("Unknown");
  }
}

void disconnectFromWiFi( bool erasePreviousCredentials ) {
  wl_status_t wifiStatus = WiFi.status();
  if( wifiStatus != WL_IDLE_STATUS ) {
    Serial.print( String( F("Disconnecting from WiFi '") ) + WiFi.SSID() + String( F("'...") ) );
    uint8_t previousInternalLedStatus = getInternalLedStatus();
    setInternalLedStatus( HIGH );
    WiFi.disconnect( false, erasePreviousCredentials );
    delay( 10 );
    while( true ) {
      wifiStatus = WiFi.status();
      if( wifiStatus == WL_DISCONNECTED || wifiStatus == WL_IDLE_STATUS ) break;
      delay( 500 );
      Serial.print( "." );
    }
    Serial.println( F(" done") );
    setInternalLedStatus( previousInternalLedStatus );
  }
}

void connectToWiFiAsync( bool isInit ) {
  if( strlen(wiFiClientSsid) == 0 ) {
    createAccessPoint();
    return;
  }

  Serial.print( String( F("Connecting to WiFi '") ) + String( wiFiClientSsid ) + "'..." );
  WiFi.hostname( ( String( getWiFiHostName() ) + "-" + String( ESP.getChipId() ) ).c_str() );
  WiFi.begin( wiFiClientSsid, wiFiClientPassword );

  if( WiFi.isConnected() ) {
    shutdownAccessPoint();
    return;
  } else {
    Serial.println();
  }

  wl_status_t wifiStatus = WiFi.status();
  if( WiFi.isConnected() ) {
    Serial.println( String( F(" done. WiFi status: ") ) + getWiFiStatusText( wifiStatus ) );
    shutdownAccessPoint();
    forceRefreshData();
  } else if( !isInit && ( wifiStatus == WL_NO_SSID_AVAIL || wifiStatus == WL_CONNECT_FAILED || wifiStatus == WL_CONNECTION_LOST || wifiStatus == WL_IDLE_STATUS || wifiStatus == WL_DISCONNECTED ) ) {
    Serial.println( String( F("ERROR. WiFi status: ") ) + getWiFiStatusText( wifiStatus ) );
    disconnectFromWiFi( false );
    createAccessPoint();
  }
}


void connectToWiFiSync() {
  if( strlen(wiFiClientSsid) == 0 ) {
    createAccessPoint();
    return;
  }

  Serial.println( String( F("Connecting to WiFi '") ) + String( wiFiClientSsid ) + "'..." );
  WiFi.hostname( ( String( getWiFiHostName() ) + "-" + String( ESP.getChipId() ) ).c_str() );
  WiFi.begin( wiFiClientSsid, wiFiClientPassword );

  if( WiFi.isConnected() ) {
    shutdownAccessPoint();
    return;
  }

  unsigned long wiFiConnectStartedMillis = millis();
  uint8_t previousInternalLedStatus = getInternalLedStatus();
  while( true ) {
    setInternalLedStatus( HIGH );
    delay( 1000 );
    wl_status_t wifiStatus = WiFi.status();
    if( WiFi.isConnected() ) {
      Serial.println( F(" done") );
      setInternalLedStatus( previousInternalLedStatus );
      shutdownAccessPoint();
      forceRefreshData();
      break;
    } else if( ( wifiStatus == WL_NO_SSID_AVAIL || wifiStatus == WL_CONNECT_FAILED || wifiStatus == WL_CONNECTION_LOST || wifiStatus == WL_IDLE_STATUS ) && ( calculateDiffMillis( wiFiConnectStartedMillis, millis() ) >= TIMEOUT_CONNECT_WIFI_SYNC ) ) {
      Serial.println( String( F(" ERROR: ") ) + getWiFiStatusText( wifiStatus ) );
      setInternalLedStatus( previousInternalLedStatus );
      disconnectFromWiFi( false );
      createAccessPoint();
      break;
    }
  }
}


//web server
const char HTML_PAGE_START[] PROGMEM = "<!DOCTYPE html>"
"<html>"
  "<head>"
    "<meta charset=\"UTF-8\">"
    "<title>Таймер-годинник</title>"
    "<style>"
      ":root{--f:22px;}"
      "body{margin:0;background-color:#444;font-family:sans-serif;color:#FFF;}"
      "body,input,button{font-size:var(--f);}"
      ".wrp{width:60%;min-width:460px;max-width:600px;margin:auto;margin-bottom:10px;}"
      "h2{color:#FFF;font-size:calc(var(--f)*1.2);text-align:center;margin-top:0.3em;margin-bottom:0.3em;}"
      ".fx{display:flex;flex-wrap:wrap;margin:auto;margin-top:0.3em;}"
      ".fx .fi{display:flex;align-items:center;margin-top:0.3em;width:100%;}"
      ".fx .fi:first-of-type,.fx.fv .fi{margin-top:0;}"
      ".fv{flex-direction:column;align-items:flex-start;}"
      ".ex.ext:before{color:#888;cursor:pointer;content:\"▶\";}"
      ".ex.exon .ex.ext:before{content:\"▼\";}"
      ".ex.exc{height:0;margin-top:0;}.ex.exc>*{visibility:hidden;}"
      ".ex.exc.exon{height:inherit;}.ex.exc.exon>*{visibility:initial;}"
      "label{flex:none;padding-right:0.6em;max-width:50%;overflow:hidden;text-overflow:ellipsis;white-space:nowrap;}"
      "input{width:100%;padding:0.1em 0.2em;}"
      "input[type=\"radio\"],input[type=\"checkbox\"]{flex:none;margin:0.1em 0;width:calc(var(--f)*1.2);height:calc(var(--f)*1.2);}"
      "input[type=\"radio\"]+label,input[type=\"checkbox\"]+label{padding-left:0.6em;padding-right:initial;flex:1 1 auto;max-width:initial;}"
      "input[type=\"range\"]{-webkit-appearance:none;background:transparent;padding:0;}"
      "input[type=\"range\"]::-webkit-slider-runnable-track{appearance:none;height:calc(0.4*var(--f));border:2px solid #EEE;border-radius:4px;background:#666;}"
      "input[type=\"range\"]::-webkit-slider-thumb{appearance:none;background:#FFF;border-radius:50%;margin-top:calc(-0.4*var(--f));height:calc(var(--f));width:calc(var(--f));}"
      "input[type=\"color\"]{padding:0;height:var(--f);}"
      "input[type=\"color\"]::-webkit-color-swatch-wrapper{padding:2px;}"
      "output{padding-left:0.6em;}"
      "button{width:100%;padding:0.2em;}"
      "a{color:#AAA;}"
      ".sub+.sub{padding-left:0.6em;}"
      ".ft{margin-top:1em;}"
      ".pl{padding-left:0.6em;}"
      ".pll{padding-left:calc(var(--f)*1.2 + 0.6em);}"
      ".lnk{margin:auto;color:#AAA;}"
      ".i{color:#CCC;margin-left:0.2em;border:1px solid #777;border-radius:50%;background-color:#666;cursor:default;font-size:65%;vertical-align:top;width:1em;height:1em;display:inline-block;text-align:center;}"
      ".i:before{content:\"i\";position:relative;top:-0.07em;}"
      ".i:hover{background-color:#777;color:#DDD;}"
      "@media(max-device-width:800px) and (orientation:portrait){:root{--f:4vw;}.wrp{width:94%;max-width:100%;}}"
    "</style>"
  "</head>"
  "<body>"
    "<div class=\"wrp\">"
      "<h2>ТАЙМЕР-ГОДИННИК<div class=\"lnk\" style=\"font-size:50%;\">Розробник: <a href=\"mailto:kurylo.press@gmail.com?subject=Timer Clock\">Дмитро Курило</a></div></h2>";
const char HTML_PAGE_END[] PROGMEM = "</div>"
  "</body>"
"</html>";

String getHtmlPage( String pageBody ) {
  String result;
  result.reserve( strlen_P(HTML_PAGE_START) + pageBody.length() + strlen_P(HTML_PAGE_END) + 1 );
  char c;
  for( uint16_t i = 0; i < strlen_P(HTML_PAGE_START); i++ ) {
    c = pgm_read_byte( &HTML_PAGE_START[i] );
    result += c;
  }
  result += pageBody;
  for( uint16_t i = 0; i < strlen_P(HTML_PAGE_END); i++ ) {
    c = pgm_read_byte( &HTML_PAGE_END[i] );
    result += c;
  }
  return result;
}

String getHtmlLink( const char* href, String label ) {
  return String( F("<a href=\"") ) + String( href ) + "\">" + label + String( F("</a>") );
}

String getHtmlLabel( String label, const char* elId, bool addColon ) {
  return String( F("<label") ) + (strlen(elId) > 0 ? String( F(" for=\"") ) + String( elId ) + "\"" : "") + ">" + label + ( addColon ? ":" : "" ) + String( F("</label>") );
}

const char* HTML_INPUT_TEXT = "text";
const char* HTML_INPUT_PASSWORD = "password";
const char* HTML_INPUT_CHECKBOX = "checkbox";
const char* HTML_INPUT_RADIO = "radio";
const char* HTML_INPUT_COLOR = "color";
const char* HTML_INPUT_RANGE = "range";

String getHtmlInput( String label, const char* type, const char* value, const char* elId, const char* elName, uint8_t minLength, uint8_t maxLength, bool isRequired, bool isChecked ) {
  return ( (strcmp(type, HTML_INPUT_TEXT) == 0 || strcmp(type, HTML_INPUT_PASSWORD) == 0 || strcmp(type, HTML_INPUT_COLOR) == 0 || strcmp(type, HTML_INPUT_RANGE) == 0) ? getHtmlLabel( label, elId, true ) : "" ) +
    String( F("<input"
      " type=\"") ) + type + String( F("\""
      " id=\"") ) + String(elId) + F("\""
      " name=\"") + String(elName) + "\"" +
      ( maxLength > 0 && (strcmp(type, HTML_INPUT_TEXT) == 0 || strcmp(type, HTML_INPUT_PASSWORD) == 0) ? String( F(" maxLength=\"") ) + String( maxLength ) + "\"" : "" ) +
      ( (strcmp(type, HTML_INPUT_CHECKBOX) != 0) ? String( F(" value=\"") ) + String( value ) + "\"" : "" ) +
      ( isRequired && (strcmp(type, HTML_INPUT_TEXT) == 0 || strcmp(type, HTML_INPUT_PASSWORD) == 0) ? F(" required") : F("") ) +
      ( isChecked && (strcmp(type, HTML_INPUT_RADIO) == 0 || strcmp(type, HTML_INPUT_CHECKBOX) == 0) ? F(" checked") : F("") ) +
      ( (strcmp(type, HTML_INPUT_RANGE) == 0) ? String( F(" min=\"") ) + String( minLength ) + String( F("\" max=\"") ) + String(maxLength) + String( F("\" oninput=\"this.nextElementSibling.value=this.value;\"><output>") ) + String( value ) + String( F("</output") ) : "" ) +
    ">" +
      ( (strcmp(type, HTML_INPUT_TEXT) != 0 && strcmp(type, HTML_INPUT_PASSWORD) != 0 && strcmp(type, HTML_INPUT_COLOR) != 0 && strcmp(type, HTML_INPUT_RANGE) != 0) ? getHtmlLabel( label, elId, false ) : "" );
}

const uint8_t getWiFiClientSsidNameMaxLength() { return WIFI_SSID_MAX_LENGTH - 1;}
const uint8_t getWiFiClientSsidPasswordMaxLength() { return WIFI_PASSWORD_MAX_LENGTH - 1;}

const char* HTML_PAGE_ROOT_ENDPOINT = "/";
const char* HTML_PAGE_REBOOT_ENDPOINT = "/reboot";
const char* HTML_PAGE_TESTLED_ENDPOINT = "/testled";
const char* HTML_PAGE_TEST_NIGHT_ENDPOINT = "/testdim";
const char* HTML_PAGE_UPDATE_ENDPOINT = "/update";

const char* HTML_PAGE_WIFI_SSID_NAME = "ssid";
const char* HTML_PAGE_WIFI_PWD_NAME = "pwd";

const char* HTML_PAGE_TIMER_SETUP_RESET_TIME_NAME = "tsr";
const char* HTML_PAGE_TIMER_REMEMBER_LAST_INPUT_NAME = "tre";
const char* HTML_PAGE_TIMER_PRESS_AMOUNT_NAME = "tpr";
const char* HTML_PAGE_TIMER_TURN_AMOUNT_NAME = "ttu";
const char* HTML_PAGE_TIMER_BLINKING_TIME_NAME = "tbl";
const char* HTML_PAGE_TIMER_BEEPING_TIME_NAME = "tbe";
const char* HTML_PAGE_TIMER_SHOW_PROGRESS_INDICATOR_NAME = "tpi";
const char* HTML_PAGE_TIMER_SHOW_SINGLE_DIGIT_HOUR_NAME = "sdh";
const char* HTML_PAGE_TIMER_ROTATE_DISPLAY_NAME = "rt";

const char* HTML_PAGE_FONT_TYPE_NAME = "fnt";
const char* HTML_PAGE_BOLD_FONT_NAME = "bld";
const char* HTML_PAGE_SHOW_SECS_NAME = "sec";
const char* HTML_PAGE_BRIGHTNESS_DAY_NAME = "brtd";
const char* HTML_PAGE_BRIGHTNESS_NIGHT_NAME = "brtn";

void handleWebServerGet() {
  String content = getHtmlPage(
String( F("<script>function ex(el){Array.from(el.parentElement.parentElement.children).forEach(ch=>{if(ch.classList.contains(\"ex\"))ch.classList.toggle(\"exon\");});}</script>"
  "<form method=\"POST\">"
  "<div class=\"fx\">"
    "<h2>Приєднатись до WiFi:</h2>"
    "<div class=\"fi pl\">") ) + getHtmlInput( F("SSID назва"), HTML_INPUT_TEXT, wiFiClientSsid, HTML_PAGE_WIFI_SSID_NAME, HTML_PAGE_WIFI_SSID_NAME, 0, getWiFiClientSsidNameMaxLength(), true, false ) + String( F("</div>"
    "<div class=\"fi pl\">") ) + getHtmlInput( F("SSID пароль"), HTML_INPUT_PASSWORD, wiFiClientPassword, HTML_PAGE_WIFI_PWD_NAME, HTML_PAGE_WIFI_PWD_NAME, 0, getWiFiClientSsidPasswordMaxLength(), true, false ) + String( F("</div>"
  "</div>"
  "<div class=\"fx\">"
    "<h2>Налаштування таймера:</h2>"
    "<div class=\"fi pl\">") ) + getHtmlInput( F("Вихід з налаштувань (сек)"), HTML_INPUT_RANGE, String(timerSetupResetTimeSeconds).c_str(), HTML_PAGE_TIMER_SETUP_RESET_TIME_NAME, HTML_PAGE_TIMER_SETUP_RESET_TIME_NAME, 5, 240, false, timerSetupResetTimeSeconds ) + String( F("</div>"
    "<div class=\"fi pl\">") ) + getHtmlInput( F("Пам'ять таймера (хв)"), HTML_INPUT_RANGE, String(timerRememberLastInputTimeMinutes).c_str(), HTML_PAGE_TIMER_REMEMBER_LAST_INPUT_NAME, HTML_PAGE_TIMER_REMEMBER_LAST_INPUT_NAME, 0, 240, false, timerRememberLastInputTimeMinutes ) + String( F("</div>"
    "<div class=\"fi pl\">") ) + getHtmlInput( F("Час при натиску (хв)"), HTML_INPUT_RANGE, String(timerDeltaPressMinutes).c_str(), HTML_PAGE_TIMER_PRESS_AMOUNT_NAME, HTML_PAGE_TIMER_PRESS_AMOUNT_NAME, 0, 60, false, timerDeltaPressMinutes ) + String( F("</div>"
    "<div class=\"fi pl\">") ) + getHtmlInput( F("Час при повороті (сек)"), HTML_INPUT_RANGE, String(timerDeltaTurnSeconds).c_str(), HTML_PAGE_TIMER_TURN_AMOUNT_NAME, HTML_PAGE_TIMER_TURN_AMOUNT_NAME, 1, 240, false, timerDeltaTurnSeconds ) + String( F("</div>"
    "<div class=\"fi pl\">") ) + getHtmlInput( F("Час моргання (хв)"), HTML_INPUT_RANGE, String(timerBlinkingTimeMinutes).c_str(), HTML_PAGE_TIMER_BLINKING_TIME_NAME, HTML_PAGE_TIMER_BLINKING_TIME_NAME, 0, 240, false, timerBlinkingTimeMinutes ) + String( F("</div>"
    "<div class=\"fi pl\">") ) + getHtmlInput( F("Час пищання (сек)"), HTML_INPUT_RANGE, String(timerLongBeepingTimeSeconds).c_str(), HTML_PAGE_TIMER_BEEPING_TIME_NAME, HTML_PAGE_TIMER_BEEPING_TIME_NAME, 0, 240, false, timerLongBeepingTimeSeconds ) + String( F("</div>"
    "<div class=\"fi pl\">") ) + getHtmlInput( F("Показувати прогрес таймера"), HTML_INPUT_CHECKBOX, "", HTML_PAGE_TIMER_SHOW_PROGRESS_INDICATOR_NAME, HTML_PAGE_TIMER_SHOW_PROGRESS_INDICATOR_NAME, 0, 0, false, isProgressIndicatorShown ) + String( F("</div>"
  "</div>"
  "<div class=\"fx\">"
    "<h2>Налаштування дисплею:</h2>"
    "<div class=\"fi pl\">") ) + getHtmlInput( F("Вид шрифта"), HTML_INPUT_RANGE, String(displayFontTypeNumber).c_str(), HTML_PAGE_FONT_TYPE_NAME, HTML_PAGE_FONT_TYPE_NAME, 0, 1, false, displayFontTypeNumber ) + String( F("</div>"
    "<div class=\"fi pl\">") ) + getHtmlInput( F("Жирний шрифт"), HTML_INPUT_CHECKBOX, "", HTML_PAGE_BOLD_FONT_NAME, HTML_PAGE_BOLD_FONT_NAME, 0, 0, false, isDisplayBoldFontUsed ) + String( F("</div>"
    "<div class=\"fi pl\">") ) + getHtmlInput( F("Показувати секунди"), HTML_INPUT_CHECKBOX, "", HTML_PAGE_SHOW_SECS_NAME, HTML_PAGE_SHOW_SECS_NAME, 0, 0, false, isDisplaySecondsShown ) + String( F("</div>"
    "<div class=\"fi pl\">") ) + getHtmlInput( F("Години 0-9 без 0 (8:30 замість 08:30)"), HTML_INPUT_CHECKBOX, "", HTML_PAGE_TIMER_SHOW_SINGLE_DIGIT_HOUR_NAME, HTML_PAGE_TIMER_SHOW_SINGLE_DIGIT_HOUR_NAME, 0, 0, false, isSingleDigitHourShown ) + String( F("</div>"
    "<div class=\"fi pl\">") ) + getHtmlInput( F("Розвернути дисплей на 180°"), HTML_INPUT_CHECKBOX, "", HTML_PAGE_TIMER_ROTATE_DISPLAY_NAME, HTML_PAGE_TIMER_ROTATE_DISPLAY_NAME, 0, 0, false, isRotateDisplay ) + String( F("</div>"
    "<div class=\"fi pl\">") ) + getHtmlInput( F("Яскравість вдень"), HTML_INPUT_RANGE, String(displayDayModeBrightness).c_str(), HTML_PAGE_BRIGHTNESS_DAY_NAME, HTML_PAGE_BRIGHTNESS_DAY_NAME, 0, 15, false, displayDayModeBrightness ) + String( F("</div>"
    "<div class=\"fi pl\">") ) + getHtmlInput( F("Яскравість вночі"), HTML_INPUT_RANGE, String(displayNightModeBrightness).c_str(), HTML_PAGE_BRIGHTNESS_NIGHT_NAME, HTML_PAGE_BRIGHTNESS_NIGHT_NAME, 0, 15, false, displayNightModeBrightness ) + String( F("</div>"
  "</div>"
  "<div class=\"fx ft\">"
    "<div class=\"fi\"><button type=\"submit\">Застосувати</button></div>"
  "</div>"
"</form>"
"<div class=\"fx ft\">"
  "<span>"
    "<span class=\"sub\">") ) + getHtmlLink( HTML_PAGE_TEST_NIGHT_ENDPOINT, F("Перевірити нічний режим") ) + String( F("<span class=\"i\" title=\"Застосуйте налаштування перед перевіркою!\"></span></span>"
    "<span class=\"sub\">") ) + getHtmlLink( HTML_PAGE_TESTLED_ENDPOINT, F("Перевірити матрицю") ) + String( F("</span>"
  "</span>"
  "<span class=\"lnk\"></span>"
  "<span>"
    "<span class=\"sub\">") ) + getHtmlLink( HTML_PAGE_UPDATE_ENDPOINT, F("Оновити прошивку") ) + String( F("<span class=\"i\" title=\"Поточна версія: ") ) + String( getFirmwareVersion() ) + String( F("\"></span></span>"
    "<span class=\"sub\">") ) + getHtmlLink( HTML_PAGE_REBOOT_ENDPOINT, F("Перезавантажити") ) + String( F("</span>"
  "</span>"
"</div>") ) );
  wifiWebServer.sendHeader( String( F("Content-Length") ).c_str(), String( content.length() ) );
  wifiWebServer.send( 200, F("text/html"), content );
}

const char HTML_PAGE_FILLUP_START[] PROGMEM = "<style>"
  "#fill{border:2px solid #FFF;background:#666;margin:1em 0;}#fill>div{width:0;height:2.5vw;background-color:#FFF;animation:fill ";
const char HTML_PAGE_FILLUP_MID[] PROGMEM = "s linear forwards;}"
  "@keyframes fill{0%{width:0;}100%{width:100%;}}"
"</style>"
"<div id=\"fill\"><div></div></div>"  
"<script>document.addEventListener(\"DOMContentLoaded\",()=>{setTimeout(()=>{window.location.href=\"/\";},";
const char HTML_PAGE_FILLUP_END[] PROGMEM = "000);});</script>";

String getHtmlPageFillup( String animationLength, String redirectLength ) {
  String result;
  result.reserve( strlen_P(HTML_PAGE_FILLUP_START) + animationLength.length() + strlen_P(HTML_PAGE_FILLUP_MID) + redirectLength.length() + strlen_P(HTML_PAGE_FILLUP_END) + 1 );
  char c;
  for( uint16_t i = 0; i < strlen_P(HTML_PAGE_FILLUP_START); i++ ) {
    c = pgm_read_byte( &HTML_PAGE_FILLUP_START[i] );
    result += c;
  }
  result += animationLength;
  for( uint16_t i = 0; i < strlen_P(HTML_PAGE_FILLUP_MID); i++ ) {
    c = pgm_read_byte( &HTML_PAGE_FILLUP_MID[i] );
    result += c;
  }
  result += redirectLength;
  for( uint16_t i = 0; i < strlen_P(HTML_PAGE_FILLUP_END); i++ ) {
    c = pgm_read_byte( &HTML_PAGE_FILLUP_END[i] );
    result += c;
  }
  return result;
}

void handleWebServerPost() {
  String htmlPageSsidNameReceived = wifiWebServer.arg( HTML_PAGE_WIFI_SSID_NAME );
  String htmlPageSsidPasswordReceived = wifiWebServer.arg( HTML_PAGE_WIFI_PWD_NAME );

  if( htmlPageSsidNameReceived.length() == 0 ) {
    String content = getHtmlPage( String( F("<h2>Error: Missing SSID Name</h2>") ) );
    wifiWebServer.sendHeader( String( F("Content-Length") ).c_str(), String( content.length() ) );
    wifiWebServer.send( 400, F("text/html"), content );
    return;
  }
  if( htmlPageSsidPasswordReceived.length() == 0 ) {
    String content = getHtmlPage( String( F("<h2>Error: Missing SSID Password</h2>") ) );
    wifiWebServer.sendHeader( String( F("Content-Length") ).c_str(), String( content.length() ) );
    wifiWebServer.send( 400, F("text/html"), content );
    return;
  }
  if( htmlPageSsidNameReceived.length() > getWiFiClientSsidNameMaxLength() ) {
    String content = getHtmlPage( String( F("<h2>Error: SSID Name exceeds maximum length of ") ) + String( getWiFiClientSsidNameMaxLength() ) + String( F("</h2>") ) );
    wifiWebServer.sendHeader( String( F("Content-Length") ).c_str(), String( content.length() ) );
    wifiWebServer.send( 400, F("text/html"), content );
    return;
  }
  if( htmlPageSsidPasswordReceived.length() > getWiFiClientSsidPasswordMaxLength() ) {
    String content = getHtmlPage( String( F("<h2>Error: SSID Password exceeds maximum length of ") ) + String( getWiFiClientSsidPasswordMaxLength() ) + String( F("</h2>") ) );
    wifiWebServer.sendHeader( String( F("Content-Length") ).c_str(), String( content.length() ) );
    wifiWebServer.send( 400, F("text/html"), content );
    return;
  }


  String htmlPageTimerSetupResetTimeSecondsReceived = wifiWebServer.arg( HTML_PAGE_TIMER_REMEMBER_LAST_INPUT_NAME );
  uint timerSetupResetTimeSecondsReceived = htmlPageTimerSetupResetTimeSecondsReceived.toInt();
  bool timerSetupResetTimeSecondsReceivedPopulated = false;
  if( timerSetupResetTimeSecondsReceived >= 0 || timerSetupResetTimeSecondsReceived <= 255 ) {
    timerSetupResetTimeSecondsReceivedPopulated = true;
  }

  String htmlPageTimerRememberLastInputTimeReceived = wifiWebServer.arg( HTML_PAGE_TIMER_REMEMBER_LAST_INPUT_NAME );
  uint timerRememberLastInputTimeReceived = htmlPageTimerRememberLastInputTimeReceived.toInt();
  bool timerRememberLastInputTimeReceivedPopulated = false;
  if( timerRememberLastInputTimeReceived >= 0 || timerRememberLastInputTimeReceived <= 255 ) {
    timerRememberLastInputTimeReceivedPopulated = true;
  }

  String htmlPageTimerDeltaPressReceived = wifiWebServer.arg( HTML_PAGE_TIMER_PRESS_AMOUNT_NAME );
  uint timerDeltaPressReceived = htmlPageTimerDeltaPressReceived.toInt();
  bool timerDeltaPressReceivedPopulated = false;
  if( timerDeltaPressReceived >= 0 || timerDeltaPressReceived <= 255 ) {
    timerDeltaPressReceivedPopulated = true;
  }

  String htmlPageTimerDeltaTurnReceived = wifiWebServer.arg( HTML_PAGE_TIMER_TURN_AMOUNT_NAME );
  uint timerDeltaTurnReceived = htmlPageTimerDeltaTurnReceived.toInt();
  bool timerDeltaTurnReceivedPopulated = false;
  if( timerDeltaTurnReceived > 0 || timerDeltaTurnReceived <= 255 ) {
    timerDeltaTurnReceivedPopulated = true;
  }

  String htmlPageTimerBlinkingTimeReceived = wifiWebServer.arg( HTML_PAGE_TIMER_BLINKING_TIME_NAME );
  uint timerBlinkingTimeReceived = htmlPageTimerBlinkingTimeReceived.toInt();
  bool timerBlinkingTimeReceivedPopulated = false;
  if( timerBlinkingTimeReceived >= 0 || timerBlinkingTimeReceived <= 255 ) {
    timerBlinkingTimeReceivedPopulated = true;
  }

  String htmlPageTimerBeepingTimeReceived = wifiWebServer.arg( HTML_PAGE_TIMER_BEEPING_TIME_NAME );
  uint timerBeepingTimeReceived = htmlPageTimerBeepingTimeReceived.toInt();
  bool timerBeepingTimeReceivedPopulated = false;
  if( timerBeepingTimeReceived >= 0 || timerBeepingTimeReceived <= 255 ) {
    timerBeepingTimeReceivedPopulated = true;
  }

  String htmlPageTimerShowProgressIndicatorReceived = wifiWebServer.arg( HTML_PAGE_TIMER_SHOW_PROGRESS_INDICATOR_NAME );
  bool timerShowProgressIndicatorReceived = false;
  bool timerShowProgressIndicatorReceivedPopulated = false;
  if( htmlPageTimerShowProgressIndicatorReceived == "on" ) {
    timerShowProgressIndicatorReceived = true;
    timerShowProgressIndicatorReceivedPopulated = true;
  } else if( htmlPageTimerShowProgressIndicatorReceived == "" ) {
    timerShowProgressIndicatorReceived = false;
    timerShowProgressIndicatorReceivedPopulated = true;
  }


  String htmlPageDisplayFontTypeNumberReceived = wifiWebServer.arg( HTML_PAGE_FONT_TYPE_NAME );
  uint displayFontTypeNumberReceived = htmlPageDisplayFontTypeNumberReceived.toInt();
  bool displayFontTypeNumberReceivedPopulated = false;
  if( displayFontTypeNumberReceived > 0 || displayFontTypeNumberReceived <= 1 ) {
    displayFontTypeNumberReceivedPopulated = true;
  }

  String htmlPageIsDisplayBoldFondUsedReceived = wifiWebServer.arg( HTML_PAGE_BOLD_FONT_NAME );
  bool isDisplayBoldFondUsedReceived = false;
  bool isDisplayBoldFondUsedReceivedPopulated = false;
  if( htmlPageIsDisplayBoldFondUsedReceived == "on" ) {
    isDisplayBoldFondUsedReceived = true;
    isDisplayBoldFondUsedReceivedPopulated = true;
  } else if( htmlPageIsDisplayBoldFondUsedReceived == "" ) {
    isDisplayBoldFondUsedReceived = false;
    isDisplayBoldFondUsedReceivedPopulated = true;
  }

  String htmlPageIsDisplaySecondsShownReceived = wifiWebServer.arg( HTML_PAGE_SHOW_SECS_NAME );
  bool isDisplaySecondsShownReceived = false;
  bool isDisplaySecondsShownReceivedPopulated = false;
  if( htmlPageIsDisplaySecondsShownReceived == "on" ) {
    isDisplaySecondsShownReceived = true;
    isDisplaySecondsShownReceivedPopulated = true;
  } else if( htmlPageIsDisplaySecondsShownReceived == "" ) {
    isDisplaySecondsShownReceived = false;
    isDisplaySecondsShownReceivedPopulated = true;
  }

  String htmlPageIsSingleDigitHourShownReceived = wifiWebServer.arg( HTML_PAGE_TIMER_SHOW_SINGLE_DIGIT_HOUR_NAME );
  bool isSingleDigitHourShownReceived = false;
  bool isSingleDigitHourShownReceivedPopulated = false;
  if( htmlPageIsSingleDigitHourShownReceived == "on" ) {
    isSingleDigitHourShownReceived = true;
    isSingleDigitHourShownReceivedPopulated = true;
  } else if( htmlPageIsSingleDigitHourShownReceived == "" ) {
    isSingleDigitHourShownReceived = false;
    isSingleDigitHourShownReceivedPopulated = true;
  }

  String htmlPageIsRotateDisplayReceived = wifiWebServer.arg( HTML_PAGE_TIMER_ROTATE_DISPLAY_NAME );
  bool isRotateDisplayReceived = false;
  bool isRotateDisplayReceivedPopulated = false;
  if( htmlPageIsRotateDisplayReceived == "on" ) {
    isRotateDisplayReceived = true;
    isRotateDisplayReceivedPopulated = true;
  } else if( htmlPageIsRotateDisplayReceived == "" ) {
    isRotateDisplayReceived = false;
    isRotateDisplayReceivedPopulated = true;
  }

  String htmlPageDisplayDayModeBrightnessReceived = wifiWebServer.arg( HTML_PAGE_BRIGHTNESS_DAY_NAME );
  uint displayDayModeBrightnessReceived = htmlPageDisplayDayModeBrightnessReceived.toInt();
  bool displayDayModeBrightnessReceivedPopulated = false;
  if( displayDayModeBrightnessReceived > 0 || displayDayModeBrightnessReceived <= 15 ) {
    displayDayModeBrightnessReceivedPopulated = true;
  }

  String htmlPageDisplayNightModeBrightnessReceived = wifiWebServer.arg( HTML_PAGE_BRIGHTNESS_NIGHT_NAME );
  uint displayNightModeBrightnessReceived = htmlPageDisplayNightModeBrightnessReceived.toInt();
  bool displayNightModeBrightnessReceivedPopulated = false;
  if( displayNightModeBrightnessReceived > 0 || displayNightModeBrightnessReceived <= 15 ) {
    displayNightModeBrightnessReceivedPopulated = true;
    if( displayNightModeBrightnessReceived > displayDayModeBrightnessReceived ) {
      displayNightModeBrightnessReceived = displayDayModeBrightnessReceived;
    }
  }

  bool isWiFiChanged = strcmp( wiFiClientSsid, htmlPageSsidNameReceived.c_str() ) != 0 || strcmp( wiFiClientPassword, htmlPageSsidPasswordReceived.c_str() ) != 0;

  String waitTime = isWiFiChanged ? String(TIMEOUT_CONNECT_WIFI_SYNC/1000 + 6) : "2";
  String content = getHtmlPage( getHtmlPageFillup( waitTime, waitTime ) + String( F("<h2>Зберігаю...</h2>") ) );
  wifiWebServer.sendHeader( String( F("Content-Length") ).c_str(), String( content.length() ) );
  wifiWebServer.send( 200, F("text/html"), content );

  bool isDisplayIntensityUpdateRequired = false;
  bool isDisplayRerenderRequired = false;

  if( timerSetupResetTimeSecondsReceivedPopulated && timerSetupResetTimeSecondsReceived != timerSetupResetTimeSeconds ) {
    timerSetupResetTimeSeconds = timerSetupResetTimeSecondsReceived;
    Serial.println( F("Remember setup reset time updated") );
    writeEepromIntValue( eepromTimerSetupResetTimeIndex, timerSetupResetTimeSecondsReceived );
  }

  if( timerRememberLastInputTimeReceivedPopulated && timerRememberLastInputTimeReceived != timerRememberLastInputTimeMinutes ) {
    timerRememberLastInputTimeMinutes = timerRememberLastInputTimeReceived;
    Serial.println( F("Remember last timer input time updated") );
    writeEepromIntValue( eepromTimerRememberLastInputTimeIndex, timerRememberLastInputTimeReceived );
  }

  if( timerDeltaPressReceivedPopulated && timerDeltaPressReceived != timerDeltaPressMinutes ) {
    timerDeltaPressMinutes = timerDeltaPressReceived;
    Serial.println( F("Timer press delta time updated") );
    writeEepromIntValue( eepromTimerDeltaPressIndex, timerDeltaPressReceived );
  }

  if( timerDeltaTurnReceivedPopulated && timerDeltaTurnReceived != timerDeltaTurnSeconds ) {
    timerDeltaTurnSeconds = timerDeltaTurnReceived;
    Serial.println( F("Timer turn delta time updated") );
    writeEepromIntValue( eepromTimerDeltaTurnIndex, timerDeltaTurnReceived );
  }

  if( timerBlinkingTimeReceivedPopulated && timerBlinkingTimeReceived != timerBlinkingTimeMinutes ) {
    timerBlinkingTimeMinutes = timerBlinkingTimeReceived;
    Serial.println( F("Timer blinking time updated") );
    writeEepromIntValue( eepromTimerBlinkingTimeIndex, timerBlinkingTimeReceived );
  }

  if( timerBeepingTimeReceivedPopulated && timerBeepingTimeReceived != timerLongBeepingTimeSeconds ) {
    timerLongBeepingTimeSeconds = timerBeepingTimeReceived;
    Serial.println( F("Timer beeping time updated") );
    writeEepromIntValue( eepromTimerBeepingTimeIndex, timerBeepingTimeReceived );
  }

  if( timerShowProgressIndicatorReceivedPopulated && timerShowProgressIndicatorReceived != isProgressIndicatorShown ) {
    isProgressIndicatorShown = timerShowProgressIndicatorReceived;
    isDisplayRerenderRequired = true;
    Serial.println( F("Timer show progress updated") );
    writeEepromBoolValue( eepromTimerIsProgressIndicatorShownIndex, timerShowProgressIndicatorReceived );
  }


  if( displayFontTypeNumberReceivedPopulated && displayFontTypeNumberReceived != displayFontTypeNumber ) {
    displayFontTypeNumber = displayFontTypeNumberReceived;
    isDisplayRerenderRequired = true;
    Serial.println( F("Display font updated") );
    writeEepromIntValue( eepromDisplayFontTypeNumberIndex, displayFontTypeNumberReceived );
  }

  if( isDisplayBoldFondUsedReceivedPopulated && isDisplayBoldFondUsedReceived != isDisplayBoldFontUsed ) {
    isDisplayBoldFontUsed = isDisplayBoldFondUsedReceived;
    isDisplayRerenderRequired = true;
    Serial.println( F("Show seconds updated") );
    writeEepromBoolValue( eepromIsFontBoldUsedIndex, isDisplayBoldFondUsedReceived );
  }

  if( isDisplaySecondsShownReceivedPopulated && isDisplaySecondsShownReceived != isDisplaySecondsShown ) {
    isDisplaySecondsShown = isDisplaySecondsShownReceived;
    isDisplayRerenderRequired = true;
    Serial.println( F("Show seconds updated") );
    writeEepromBoolValue( eepromIsDisplaySecondsShownIndex, isDisplaySecondsShownReceived );
  }

  if( isSingleDigitHourShownReceivedPopulated && isSingleDigitHourShownReceived != isSingleDigitHourShown ) {
    isSingleDigitHourShown = isSingleDigitHourShownReceived;
    isDisplayRerenderRequired = true;
    Serial.println( F("Show single digit hour updated") );
    writeEepromBoolValue( eepromIsSingleDigitHourShownIndex, isSingleDigitHourShownReceived );
  }

  if( isRotateDisplayReceivedPopulated && isRotateDisplayReceived != isRotateDisplay ) {
    isRotateDisplay = isRotateDisplayReceived;
    isDisplayRerenderRequired = true;
    Serial.println( F("Display rotation updated") );
    writeEepromBoolValue( eepromIsRotateDisplayIndex, isRotateDisplayReceived );
  }

  if( displayDayModeBrightnessReceivedPopulated && displayDayModeBrightnessReceived != displayDayModeBrightness ) {
    displayDayModeBrightness = displayDayModeBrightnessReceived;
    isDisplayIntensityUpdateRequired = true;
    isDisplayRerenderRequired = true;
    Serial.println( F("Display brightness updated") );
    writeEepromIntValue( eepromDisplayDayModeBrightnessIndex, displayDayModeBrightnessReceived );
  }

  if( displayNightModeBrightnessReceivedPopulated && displayNightModeBrightnessReceived != displayNightModeBrightness ) {
    displayNightModeBrightness = displayNightModeBrightnessReceived;
    isDisplayIntensityUpdateRequired = true;
    isDisplayRerenderRequired = true;
    Serial.println( F("Display night mode brightness updated") );
    writeEepromIntValue( eepromDisplayNightModeBrightnessIndex, displayNightModeBrightnessReceived );
  }

  if( isDisplayIntensityUpdateRequired ) {
    setDisplayBrightness( true );
  }
  if( isDisplayRerenderRequired ) {
    renderDisplay();
  }

  if( isWiFiChanged ) {
    Serial.println( F("WiFi settings updated") );
    strncpy( wiFiClientSsid, htmlPageSsidNameReceived.c_str(), sizeof(wiFiClientSsid) );
    strncpy( wiFiClientPassword, htmlPageSsidPasswordReceived.c_str(), sizeof(wiFiClientPassword) );
    writeEepromCharArray( eepromWiFiSsidIndex, wiFiClientSsid, WIFI_SSID_MAX_LENGTH );
    writeEepromCharArray( eepromWiFiPasswordIndex, wiFiClientPassword, WIFI_PASSWORD_MAX_LENGTH );
    shutdownAccessPoint();
    connectToWiFiSync();
  }
}

void handleWebServerGetTestNight() {
  String content = getHtmlPage( getHtmlPageFillup( "5", "5" ) + String( F("<h2>Перевіряю нічний режим...</h2>") ) );
  wifiWebServer.sendHeader( String( F("Content-Length") ).c_str(), String( content.length() ) );
  wifiWebServer.send( 200, F("text/html"), content );
    setDisplayBrightness( displayNightModeBrightness );
    renderDisplay();
    delay( 6000 );
    setDisplayBrightness( true );
    renderDisplay();
}

void handleWebServerGetTestLeds() {
  String content = getHtmlPage( getHtmlPageFillup( "12", "12" ) + String( F("<h2>Перевіряю матрицю...</h2>") ) );
  wifiWebServer.sendHeader( String( F("Content-Length") ).c_str(), String( content.length() ) );
  wifiWebServer.send( 200, F("text/html"), content );
  for( uint8_t row = 0; row < 8; ++row ) {
    for( uint8_t y = 0; y < 8; ++y ) {
      for( uint8_t x = 0; x < 32; ++x ) {
        display.setPoint( y, 32 - 1 - x, row == y );
      }
    }
    display.update();
    delay( 400 );
  }
  for( uint8_t column = 0; column < 31; ++column ) {
    for( uint8_t y = 0; y < 8; ++y ) {
      for( uint8_t x = 0; x < 32; ++x ) {
        display.setPoint( y, 32 - 1 - x, column == x );
      }
    }
    display.update();
    delay( 200 );
  }
  for( uint8_t y = 0; y < 8; ++y ) {
    for( uint8_t x = 0; x < 32; ++x ) {
      display.setPoint( y, 32 - 1 - x, true );
    }
  }
  display.update();
  delay( 2000 );
}

void handleWebServerGetReboot() {
  String content = getHtmlPage( getHtmlPageFillup( "9", "9" ) + String( F("<h2>Перезавантажуюсь...</h2>") ) );
  wifiWebServer.sendHeader( String( F("Content-Length") ).c_str(), String( content.length() ) );
  wifiWebServer.send( 200, F("text/html"), content );
  delay( 200 );
  ESP.restart();
}

void handleWebServerRedirect() {
  wifiWebServer.sendHeader( F("Location"), String( F("http://") ) + WiFi.softAPIP().toString() );
  wifiWebServer.send( 302, F("text/html"), "" );
  wifiWebServer.client().stop();
}

bool isWebServerInitialized = false;
void stopWebServer() {
  if( !isWebServerInitialized ) return;
  wifiWebServer.stop();
  isWebServerInitialized = false;
}

void startWebServer() {
  if( isWebServerInitialized ) return;
  Serial.print( F("Starting web server...") );
  wifiWebServer.begin();
  isWebServerInitialized = true;
  Serial.println( " done" );
}

void configureWebServer() {
  wifiWebServer.on( HTML_PAGE_ROOT_ENDPOINT, HTTP_GET,  handleWebServerGet );
  wifiWebServer.on( HTML_PAGE_ROOT_ENDPOINT, HTTP_POST, handleWebServerPost );
  wifiWebServer.on( HTML_PAGE_TEST_NIGHT_ENDPOINT, HTTP_GET, handleWebServerGetTestNight );
  wifiWebServer.on( HTML_PAGE_TESTLED_ENDPOINT, HTTP_GET, handleWebServerGetTestLeds );
  wifiWebServer.on( HTML_PAGE_REBOOT_ENDPOINT, HTTP_GET, handleWebServerGetReboot );
  wifiWebServer.onNotFound([]() {
    handleWebServerRedirect();
  });
  httpUpdater.setup( &wifiWebServer );
}


//beeper functions
bool beeperPinStatus = false;
void startBeeping() {
  if( beeperPinStatus ) return;
  digitalWrite( BEEPER_PIN, IS_LOW_LEVEL_BUZZER ? 0 : 1 );
  beeperPinStatus = true;
}

void stopBeeping( bool isInit ) {
  if( !isInit && !beeperPinStatus ) return;
  digitalWrite( BEEPER_PIN, IS_LOW_LEVEL_BUZZER ? 1 : 0 );
  beeperPinStatus = false;
}

void stopBeeping() {
  stopBeeping( false );
}

void initBeeper() {
  pinMode( BEEPER_PIN, OUTPUT );
  stopBeeping( true );
}

void startLongBeep() {
  if( timerLongBeepingTimeSeconds == 0 ) return;
  isTimerLongBeeping = true;
  timerLongBeepingStartTimeMillis = millis();
  startBeeping();
}

void stopLongBeep() {
  isTimerLongBeeping = false;
  timerLongBeepingStartTimeMillis = 0;
  if( !isTimerLongBeeping && !isTimerShortBeeping ) {
    stopBeeping();
  }
}

void startShortBeep() {
  isTimerShortBeeping = true;
  timerShortBeepingStartTimeMillis = millis();
  startBeeping();
}

void stopShortBeep() {
  isTimerShortBeeping = false;
  timerShortBeepingStartTimeMillis = 0;
  if( !isTimerLongBeeping && !isTimerShortBeeping ) {
    stopBeeping();
  }
}

void beeperProcessLoopTick() {
  if( isTimerShortBeeping && ( timerShortBeepingTimeMillis == 0 || calculateDiffMillis( timerShortBeepingStartTimeMillis, millis() ) >= ( timerShortBeepingTimeMillis ) ) ) {
    stopShortBeep();
  }
  if( isTimerLongBeeping ) {
    unsigned long timerIsBeepingForTime = calculateDiffMillis( timerLongBeepingStartTimeMillis, millis() );
    if( timerLongBeepingTimeSeconds == 0 || timerIsBeepingForTime >= ( timerLongBeepingTimeSeconds * 1000 ) ) {
      stopLongBeep();
    } else {
      uint8_t timerFirstStageLongBeepingTimeSeconds = timerLongBeepingTimeSeconds / 8;
      uint8_t timerSecondStageLongBeepingTimeSeconds = timerLongBeepingTimeSeconds / 4;
      uint8_t timerThirdStageLongBeepingTimeSeconds = timerLongBeepingTimeSeconds / 2;
      if( timerIsBeepingForTime < timerFirstStageLongBeepingTimeSeconds * 1000 ) {
        if( timerIsBeepingForTime % 1000 < 500 ) {
          startBeeping();
        } else {
          stopBeeping();
        }
      } else if( timerIsBeepingForTime < timerSecondStageLongBeepingTimeSeconds * 1000 ) {
        if( timerIsBeepingForTime % 2000 < 500 ) {
          startBeeping();
        } else {
          stopBeeping();
        }
      } else if( timerIsBeepingForTime < timerThirdStageLongBeepingTimeSeconds * 1000 ) {
        if( timerIsBeepingForTime % 4000 < 500 ) {
          startBeeping();
        } else {
          stopBeeping();
        }
      } else {
        if( timerIsBeepingForTime % 8000 < 500 ) {
          startBeeping();
        } else {
          stopBeeping();
        }
      }
    }
  }
}


//timer functions
unsigned long timeClientSecondsAtDisplaySyncStart = 0;
void forceDisplaySync() {
  if( timeClient.isTimeSet() ) {
    timeClientSecondsAtDisplaySyncStart = timeClient.getEpochTime();
  }
  isForceDisplaySync = true;
  isForceDisplaySyncDisplayRenderOverride = true;
}

void startBlinking() {
  if( timerBlinkingTimeMinutes == 0 ) return;
  unsigned long currentMillis = millis();
  isTimerBlinking = true;
  timerBlinkingStartTimeMillis = currentMillis;
  isTimerBlinkingShown = false;
  timerBlinkingLastUpdateMillis = currentMillis;
}

void stopBlinking() {
  isTimerBlinking = false;
  timerBlinkingStartTimeMillis = 0;
  isTimerBlinkingShown = false;
  timerBlinkingLastUpdateMillis = 0;

  forceDisplaySync();
}

void exitTimerSetupMode() {
  isTimerSetupRunning = false;
  timerSetupLastUpdateMillis = 0;
}

void enterTimerSetupMode() {
  isTimerSetupRunning = true;
  timerSetupLastUpdateMillis = millis();
}

boolean startTimer() {
  if( isTimerRunning ) return false;
  if( timerCurrentSetupInMillis == 0 ) {
    if( isTimerOldFinished && timerOldSetupInMillis >= timerDeltaTurnSeconds * 1000 && timerRememberLastInputTimeMinutes > 0 && calculateDiffMillis( timerOldFinishedTimeMillis, millis() ) <= ( timerRememberLastInputTimeMinutes * 60 * 1000 ) ) {
      uint16_t wholeSecondRemainder = timerOldSetupInMillis % 1000;
      timerCurrentSetupInMillis = timerOldSetupInMillis - wholeSecondRemainder + ( wholeSecondRemainder < 500 ? 0 : 1000 );
    } else {
      if( timerDeltaPressMinutes == 0 ) return false;
      timerCurrentSetupInMillis = ( timerDeltaPressMinutes * 60 * 1000 );
    }
  }
  exitTimerSetupMode();
  timerCurrentStartedTimeMillis = millis();
  isTimerRunning = true;

  forceDisplaySync();
  return true;
}

bool cancelTimer() {
  if( !isTimerRunning ) return false;
  if( timerRememberLastInputTimeMinutes > 0 ) {
    timerOldSetupInMillis = calculateDiffMillis( timerCurrentStartedTimeMillis, millis() ); //when calcelling timer, the amount of time passed from its start will be temporarily stored in order to restart the times with that time
    if( timerOldSetupInMillis > TIMER_MAX_TIME_TO_SET_UP ) {
      timerOldSetupInMillis = TIMER_MAX_TIME_TO_SET_UP;
    }
    if( timerOldSetupInMillis > 0 ) {
      timerOldFinishedTimeMillis = millis();
      isTimerOldFinished = true;
    }
  }
  timerCurrentSetupInMillis = 0;
  isTimerRunning = false;

  forceDisplaySync();
  return true;
}

bool stopBeepingOrBlinking() {
  if( isTimerLongBeeping || isTimerBlinking ) {
    bool wasTimerLongBeepingOrBlinking = false;
    if( isTimerLongBeeping ) {
      stopLongBeep();
      wasTimerLongBeepingOrBlinking = true;
    }
    if( isTimerBlinking ) {
      stopBlinking();
      startShortBeep();
      wasTimerLongBeepingOrBlinking = true;
    }
    if( wasTimerLongBeepingOrBlinking ) {
      exitTimerSetupMode();
      timerCurrentSetupInMillis = 0;
      return true;
    }
  }
  return false;
}


void timerButtonShortPress() {
  if( stopBeepingOrBlinking() ) return;

  if( isTimerRunning ) {
    if( timerDeltaPressMinutes > 0 ) {
      timerCurrentSetupInMillis += ( timerDeltaPressMinutes * 60 * 1000 );
    }
    if( timerCurrentSetupInMillis > TIMER_MAX_TIME_TO_SET_UP ) {
      timerCurrentSetupInMillis = TIMER_MAX_TIME_TO_SET_UP;
    }
    return;
  }
  if( startTimer() ) {
    startShortBeep();
  }
}

void timerButtonLongPress() {
  if( stopBeepingOrBlinking() ) return;

  if( isTimerSetupRunning ) {
    exitTimerSetupMode();
    timerCurrentSetupInMillis = 0;
    return;
  }
  if( isTimerRunning ) {
    if( cancelTimer() ) {
      startShortBeep();
    }
    return;
  }
  if( startTimer() ) {
    startShortBeep();
  }
}

void timerTurnLeft() {
  if( stopBeepingOrBlinking() ) return;

  if( timerCurrentSetupInMillis >= ( timerDeltaTurnSeconds * 1000 ) ) {
    timerCurrentSetupInMillis -= ( timerDeltaTurnSeconds * 1000 );
  } else {
    timerCurrentSetupInMillis = 0;    
  }

  if( isTimerRunning ) {
    if( calculateDiffMillis( timerCurrentStartedTimeMillis, millis() ) >= timerCurrentSetupInMillis ) {
      if( cancelTimer() ) {
        startShortBeep();
      }
    }
    return;
  }
  enterTimerSetupMode();
}

void timerTurnRight() {
  if( stopBeepingOrBlinking() ) return;

  timerCurrentSetupInMillis += ( timerDeltaTurnSeconds * 1000 );
  if( timerCurrentSetupInMillis > TIMER_MAX_TIME_TO_SET_UP ) {
    timerCurrentSetupInMillis = TIMER_MAX_TIME_TO_SET_UP;
  }
  if( isTimerRunning ) {
    return;
  }
  enterTimerSetupMode();
}

void timerProcessLoopTick() {
  if( isTimerBlinking && ( timerBlinkingTimeMinutes == 0 || calculateDiffMillis( timerBlinkingStartTimeMillis, millis() ) >= ( timerBlinkingTimeMinutes * 60 * 1000 ) ) ) {
    stopBlinking();
  }
  if( isTimerOldFinished && timerOldSetupInMillis > 0 && timerRememberLastInputTimeMinutes > 0 && calculateDiffMillis( timerOldFinishedTimeMillis, millis() ) > ( timerRememberLastInputTimeMinutes * 60 * 1000 ) ) {
    timerOldFinishedTimeMillis = 0;
    timerOldSetupInMillis = 0;
    isTimerOldFinished = false;
  }
  if( !isTimerRunning ) {
    if( isTimerSetupRunning && calculateDiffMillis( timerSetupLastUpdateMillis, millis() ) >= ( timerSetupResetTimeSeconds * 1000 ) ) {
      isTimerSetupRunning = false;
      timerSetupLastUpdateMillis = 0;
      timerCurrentSetupInMillis = 0;
    }
  } else {
    if( calculateDiffMillis( timerCurrentStartedTimeMillis, millis() ) >= timerCurrentSetupInMillis ) {
      cancelTimer();
      startLongBeep();
      startBlinking();
    }
  }
}

void encoderProcessLoopTick() {
  enc.tick();
  if( enc.left() || enc.leftH() ) {
    timerTurnLeft();
  } else if( enc.right() || enc.rightH() ) {
    timerTurnRight();
  } else if( enc.click() ) {
    timerButtonShortPress();
  } else if( enc.held() ) {
    timerButtonLongPress();
  }
}


WiFiEventHandler wiFiEventHandler;
void onWiFiConnected( const WiFiEventStationModeConnected&event ) {
  Serial.println( String( F("WiFi is connected to '") + String( event.ssid ) ) + String ( F("'") ) );
  forceNtpUpdate = true;
}

void setup() {
  initBeeper();
  initInternalLed();

  Serial.begin( 115200 );
  Serial.println();
  Serial.println( String( F("Timer Clock by Dmytro Kurylo. V@") ) + getFirmwareVersion() + String( F(" CPU@") ) + String( ESP.getCpuFreqMHz() ) );

  initEeprom();
  loadEepromData();
  initVariables();
  initDisplay();

  configureWebServer();
  wiFiEventHandler = WiFi.onStationModeConnected( &onWiFiConnected );
  connectToWiFiAsync( true );
  startWebServer();
  initTimeClient();
}

void loop() {
  unsigned long currentMillis = millis();

  if( isFirstLoopRun || ( calculateDiffMillis( previousMillisInternalLed, currentMillis ) >= ( getInternalLedStatus() == HIGH ? DELAY_INTERNAL_LED_ANIMATION_HIGH : DELAY_INTERNAL_LED_ANIMATION_LOW ) ) ) {
    previousMillisInternalLed = currentMillis;
    setInternalLedStatus( getInternalLedStatus() == HIGH ? LOW : HIGH );
  }

  encoderProcessLoopTick();
  timerProcessLoopTick();
  beeperProcessLoopTick();

  if( isApInitialized ) {
    dnsServer.processNextRequest();
  }
  wifiWebServer.handleClient();

  brightnessProcessLoopTick();

  currentMillis = millis();
  if( isApInitialized && ( calculateDiffMillis( apStartedMillis, currentMillis ) >= TIMEOUT_AP ) ) {
    shutdownAccessPoint();
    connectToWiFiSync();
  }

  if( /*isFirstLoopRun || */( calculateDiffMillis( previousMillisWiFiStatusCheck, currentMillis ) >= DELAY_WIFI_CONNECTION_CHECK ) ) {
    if( !WiFi.isConnected() ) {
      if( !isApInitialized ) {
        connectToWiFiAsync( false );
      }
    }
    previousMillisWiFiStatusCheck = currentMillis;
  }

  currentMillis = millis();
  if( isFirstLoopRun || forceNtpUpdate || ( calculateDiffMillis( previousMillisNtpUpdatedCheck, millis() ) >= DELAY_NTP_UPDATED_CHECK ) ) {
    if( updateTimeClient( false ) ) {
      forceNtpUpdate = false;
    }
    previousMillisNtpUpdatedCheck = currentMillis;
  }
  bool timeClientInitStatusChanged = timeClientTimeInitStatus != timeClient.isTimeSet();
  if( timeClientInitStatusChanged ) {
    forceDisplaySync();
    timeClientTimeInitStatus = timeClient.isTimeSet();
  }

  currentMillis = millis();
  if( isFirstLoopRun || isForceDisplaySync || ( calculateDiffMillis( previousMillisDisplayAnimation, currentMillis ) >= DELAY_DISPLAY_ANIMATION ) ) {
    bool doRenderDisplay = true;
    if( isForceDisplaySync ) {
      if( isTimerRunning ) {
        previousMillisSemicolonAnimation = timerCurrentStartedTimeMillis;
        previousMillisDisplayAnimation = timerCurrentStartedTimeMillis;
        isForceDisplaySync = false;
      } else if( isTimerBlinking ) {
        isSemicolonShown = false;
        previousMillisSemicolonAnimation = timerBlinkingStartTimeMillis;
        previousMillisDisplayAnimation = timerBlinkingStartTimeMillis;
        isForceDisplaySync = false;
      } else if( timeClient.isTimeSet() ) {
        unsigned long timeClientSecondsCurrent = timeClient.getEpochTime();
        if( !SEMICOLON_ANIMATION_FAST ) {
          isSemicolonShown = timeClientSecondsCurrent % 2 == 0;
        } else { //else if 500 let it remain blank until the next second comes
          isSemicolonShown = false;
        }
        if( timeClientInitStatusChanged || timeClientSecondsAtDisplaySyncStart != timeClientSecondsCurrent ) {
          if( SEMICOLON_ANIMATION_FAST ) {
            isSemicolonShown = true;
          }
          previousMillisSemicolonAnimation = currentMillis;
          previousMillisDisplayAnimation = currentMillis;
          isForceDisplaySync = false;
        } else {
          doRenderDisplay = false;
        }
      } else {
        isSemicolonShown = !isSemicolonShown;
        previousMillisSemicolonAnimation = currentMillis;
        previousMillisDisplayAnimation = currentMillis;
        isForceDisplaySync = false;
      }
    } else {
      previousMillisDisplayAnimation += DELAY_DISPLAY_ANIMATION;
      if( calculateDiffMillis( previousMillisSemicolonAnimation, currentMillis ) >= ( SEMICOLON_ANIMATION_FAST ? 500 : 1000 ) ) {
        isSemicolonShown = !isSemicolonShown;
        previousMillisSemicolonAnimation += ( SEMICOLON_ANIMATION_FAST ? 500 : 1000 );
      }
    }

    if( doRenderDisplay || isForceDisplaySyncDisplayRenderOverride ) {
      renderDisplay();
      isForceDisplaySyncDisplayRenderOverride = false;
    }
  }

  isFirstLoopRun = false;
  delay(2); //https://www.tablix.org/~avian/blog/archives/2022/08/saving_power_on_an_esp8266_web_server_using_delays/
}