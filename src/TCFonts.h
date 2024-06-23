#include <Arduino.h>
#include <vector>
#include <map>

class TCFonts {

  public:
    static uint8_t getSymbolWidth( uint8_t fontIndex, char symbol, bool isCompact, bool isWide, bool isSmall );
    static uint8_t getSymbolLp( uint8_t fontIndex, char symbol, bool isCompact, bool isWide, bool isSmall );
    static uint8_t getSymbolRp( uint8_t fontIndex, char symbol, bool isCompact, bool isWide, bool isSmall );
    static std::map<String, std::vector<uint8_t>> getFont( uint8_t fontIndex );
    static void setFont( uint8_t fontIndex );
    static std::vector<uint8_t> getSymbol( std::map<String, std::vector<uint8_t>> font, char symbol, bool isCompact, bool isBold, bool isWide, bool isSmall, bool isProgress );

  private:
    static bool isFontInitialised;
    static uint8_t fontIndex;
    static std::map<String, std::vector<uint8_t>> symbols;

    static void initFont( uint8_t fontIndex, std::map<String, std::vector<uint8_t>>& font );

    static void initFont0( std::map<String, std::vector<uint8_t>>& font );
    static void initFont1( std::map<String, std::vector<uint8_t>>& font );
    static void initFont2( std::map<String, std::vector<uint8_t>>& font );

};
