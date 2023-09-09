#include <Arduino.h>
#include <vector>
#include <map>

class TCFonts {

  public:
    static uint8_t getSymbolWidth( uint8_t fontIndex, char symbol, bool isBold, bool isWide, bool isProgress, bool isSmall );
    static std::vector<uint8_t> getSymbol( uint8_t fontIndex, char symbol, bool isBold, bool isWide, bool isProgress, bool isSmall );

  private:
    static bool isFontInitialised;
    static uint8_t fontIndex;
    static std::map<String, std::vector<uint8_t>> symbols;
    static void initFont0();
    static void initFont1();

};
