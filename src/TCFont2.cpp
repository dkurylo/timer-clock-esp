#include "TCFont2.h"

const uint8_t TCFont2::font[][8] PROGMEM = {
  { 0b00100000,
    0b01100000,
    0b00100000,
    0b00100000,
    0b00100000,
    0b00100000,
    0b00100000,
    0b00100000 },
  { 0b01100000,
    0b11100000,
    0b01100000,
    0b01100000,
    0b01100000,
    0b01100000,
    0b01100000,
    0b01100000 },
  { 0b00100000,
    0b01100000,
    0b00100000,
    0b00100000,
    0b00100000,
    0b00100000,
    0b00100000,
    0b00100000 },
  { 0b01100000,
    0b11100000,
    0b01100000,
    0b01100000,
    0b01100000,
    0b01100000,
    0b01100000,
    0b01100000 },
  { 0b00000000,
    0b00000000,
    0b00100000,
    0b01100000,
    0b00100000,
    0b00100000,
    0b00100000,
    0b00100000 },
  { 0b00000000,
    0b00000000,
    0b01100000,
    0b11100000,
    0b01100000,
    0b01100000,
    0b01100000,
    0b01100000 },
  { 0b00000000,
    0b00000000,
    0b00100000,
    0b01100000,
    0b00100000,
    0b00100000,
    0b00100000,
    0b00100000 },
  { 0b00000000,
    0b00000000,
    0b01100000,
    0b11100000,
    0b01100000,
    0b01100000,
    0b01100000,
    0b01100000 },

  { 0b00000000,
    0b00000000,
    0b00100000,
    0b01100000,
    0b00100000,
    0b00100000,
    0b00100000,
    0b00100000 },
  { 0b00000000,
    0b00000000,
    0b01100000,
    0b11100000,
    0b01100000,
    0b01100000,
    0b01100000,
    0b01100000 },
  { 0b00000000,
    0b00000000,
    0b00100000,
    0b01100000,
    0b00100000,
    0b00100000,
    0b00100000,
    0b00100000 },
  { 0b00000000,
    0b00000000,
    0b00100000,
    0b01100000,
    0b00100000,
    0b00100000,
    0b00100000,
    0b00100000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00100000,
    0b01100000,
    0b00100000,
    0b00100000,
    0b00100000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b01100000,
    0b11100000,
    0b01100000,
    0b01100000,
    0b01100000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b01000000,
    0b11000000,
    0b01000000,
    0b01000000,
    0b01000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b01000000,
    0b11000000,
    0b01000000,
    0b01000000,
    0b01000000 },


  { 0b11111100,
    0b00000100,
    0b00000100,
    0b11111100,
    0b10000000,
    0b10000000,
    0b10000000,
    0b11111100 },
  { 0b11111100,
    0b00001100,
    0b00001100,
    0b11111100,
    0b11000000,
    0b11000000,
    0b11000000,
    0b11111100 },
  { 0b11110000,
    0b00010000,
    0b00010000,
    0b11110000,
    0b10000000,
    0b10000000,
    0b10000000,
    0b11110000 },
  { 0b11110000,
    0b00110000,
    0b00110000,
    0b11110000,
    0b11000000,
    0b11000000,
    0b11000000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b11111100,
    0b00000100,
    0b11111100,
    0b10000000,
    0b10000000,
    0b11111100 },
  { 0b00000000,
    0b00000000,
    0b11111100,
    0b00001100,
    0b11111100,
    0b11000000,
    0b11000000,
    0b11111100 },
  { 0b00000000,
    0b00000000,
    0b11110000,
    0b00010000,
    0b11110000,
    0b10000000,
    0b10000000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b11110000,
    0b00110000,
    0b11110000,
    0b11000000,
    0b11000000,
    0b11110000 },

  { 0b00000000,
    0b00000000,
    0b11110000,
    0b00010000,
    0b11110000,
    0b10000000,
    0b10000000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b11110000,
    0b00110000,
    0b11110000,
    0b11000000,
    0b11000000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b11100000,
    0b00100000,
    0b11100000,
    0b10000000,
    0b10000000,
    0b11100000 },
  { 0b00000000,
    0b00000000,
    0b11100000,
    0b00100000,
    0b11100000,
    0b10000000,
    0b10000000,
    0b11100000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11110000,
    0b00010000,
    0b11110000,
    0b10000000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11110000,
    0b00110000,
    0b11110000,
    0b11000000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11100000,
    0b00100000,
    0b11100000,
    0b10000000,
    0b11100000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11100000,
    0b00100000,
    0b11100000,
    0b10000000,
    0b11100000 },


  { 0b11111100,
    0b00000100,
    0b00000100,
    0b01111100,
    0b00000100,
    0b00000100,
    0b00000100,
    0b11111100 },
  { 0b11111100,
    0b00001100,
    0b00001100,
    0b01111100,
    0b00001100,
    0b00001100,
    0b00001100,
    0b11111100 },
  { 0b11110000,
    0b00010000,
    0b00010000,
    0b01110000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b11110000 },
  { 0b11110000,
    0b00110000,
    0b00110000,
    0b11110000,
    0b00110000,
    0b00110000,
    0b00110000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b11111100,
    0b00000100,
    0b01111100,
    0b00000100,
    0b00000100,
    0b11111100 },
  { 0b00000000,
    0b00000000,
    0b11111100,
    0b00001100,
    0b01111100,
    0b00001100,
    0b00001100,
    0b11111100 },
  { 0b00000000,
    0b00000000,
    0b11110000,
    0b00010000,
    0b01110000,
    0b00010000,
    0b00010000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b11110000,
    0b00110000,
    0b11110000,
    0b00110000,
    0b00110000,
    0b11110000 },

  { 0b00000000,
    0b00000000,
    0b11110000,
    0b00010000,
    0b01110000,
    0b00010000,
    0b00010000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b11110000,
    0b00110000,
    0b01110000,
    0b00110000,
    0b00110000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b11100000,
    0b00100000,
    0b01100000,
    0b00100000,
    0b00100000,
    0b11100000 },
  { 0b00000000,
    0b00000000,
    0b11100000,
    0b00100000,
    0b01100000,
    0b00100000,
    0b00100000,
    0b11100000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11110000,
    0b00010000,
    0b01110000,
    0b00010000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11110000,
    0b00110000,
    0b01110000,
    0b00110000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11100000,
    0b00100000,
    0b01100000,
    0b00100000,
    0b11100000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11100000,
    0b00100000,
    0b01100000,
    0b00100000,
    0b11100000 },


  { 0b10000100,
    0b10000100,
    0b10000100,
    0b10000100,
    0b11111100,
    0b00000100,
    0b00000100,
    0b00000100 },
  { 0b11001100,
    0b11001100,
    0b11001100,
    0b11001100,
    0b11111100,
    0b00001100,
    0b00001100,
    0b00001100 },
  { 0b10010000,
    0b10010000,
    0b10010000,
    0b10010000,
    0b11110000,
    0b00010000,
    0b00010000,
    0b00010000 },
  { 0b10110000,
    0b10110000,
    0b10110000,
    0b10110000,
    0b11110000,
    0b00110000,
    0b00110000,
    0b00110000 },
  { 0b00000000,
    0b00000000,
    0b10000100,
    0b10000100,
    0b10000100,
    0b11111100,
    0b00000100,
    0b00000100 },
  { 0b00000000,
    0b00000000,
    0b11001100,
    0b11001100,
    0b11001100,
    0b11111100,
    0b00001100,
    0b00001100 },
  { 0b00000000,
    0b00000000,
    0b10010000,
    0b10010000,
    0b10010000,
    0b11110000,
    0b00010000,
    0b00010000 },
  { 0b00000000,
    0b00000000,
    0b10110000,
    0b10110000,
    0b10110000,
    0b11110000,
    0b00110000,
    0b00110000 },

  { 0b00000000,
    0b00000000,
    0b10010000,
    0b10010000,
    0b10010000,
    0b11110000,
    0b00010000,
    0b00010000 },
  { 0b00000000,
    0b00000000,
    0b10110000,
    0b10110000,
    0b10110000,
    0b11110000,
    0b00110000,
    0b00110000 },
  { 0b00000000,
    0b00000000,
    0b10100000,
    0b10100000,
    0b10100000,
    0b11100000,
    0b00100000,
    0b00100000 },
  { 0b00000000,
    0b00000000,
    0b10100000,
    0b10100000,
    0b10100000,
    0b11100000,
    0b00100000,
    0b00100000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b10010000,
    0b10010000,
    0b11110000,
    0b00010000,
    0b00010000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b10110000,
    0b10110000,
    0b11110000,
    0b00110000,
    0b00110000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b10100000,
    0b10100000,
    0b11100000,
    0b00100000,
    0b00100000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b10100000,
    0b10100000,
    0b11100000,
    0b00100000,
    0b00100000 },


  { 0b11111100,
    0b10000000,
    0b10000000,
    0b11111100,
    0b00000100,
    0b00000100,
    0b00000100,
    0b11111100 },
  { 0b11111100,
    0b11000000,
    0b11000000,
    0b11111100,
    0b00001100,
    0b00001100,
    0b00001100,
    0b11111100 },
  { 0b11110000,
    0b10000000,
    0b10000000,
    0b11110000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b11110000 },
  { 0b11110000,
    0b11000000,
    0b11000000,
    0b11110000,
    0b00110000,
    0b00110000,
    0b00110000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b11111100,
    0b10000000,
    0b11111100,
    0b00000100,
    0b00000100,
    0b11111100 },
  { 0b00000000,
    0b00000000,
    0b11111100,
    0b11000000,
    0b11111100,
    0b00001100,
    0b00001100,
    0b11111100 },
  { 0b00000000,
    0b00000000,
    0b11110000,
    0b10000000,
    0b11110000,
    0b00010000,
    0b00010000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b11110000,
    0b11000000,
    0b11110000,
    0b00110000,
    0b00110000,
    0b11110000 },

  { 0b00000000,
    0b00000000,
    0b11110000,
    0b10000000,
    0b11110000,
    0b00010000,
    0b00010000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b11110000,
    0b11000000,
    0b11110000,
    0b00110000,
    0b00110000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b11100000,
    0b10000000,
    0b11100000,
    0b00100000,
    0b00100000,
    0b11100000 },
  { 0b00000000,
    0b00000000,
    0b11100000,
    0b10000000,
    0b11100000,
    0b00100000,
    0b00100000,
    0b11100000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11110000,
    0b10000000,
    0b11110000,
    0b00010000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11110000,
    0b11000000,
    0b11110000,
    0b00110000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11100000,
    0b10000000,
    0b11100000,
    0b00100000,
    0b11100000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11100000,
    0b10000000,
    0b11100000,
    0b00100000,
    0b11100000 },


  { 0b11111100,
    0b10000000,
    0b10000000,
    0b11111100,
    0b10000100,
    0b10000100,
    0b10000100,
    0b11111100 },
  { 0b11111100,
    0b11000000,
    0b11000000,
    0b11111100,
    0b11001100,
    0b11001100,
    0b11001100,
    0b11111100 },
  { 0b11110000,
    0b10000000,
    0b10000000,
    0b11110000,
    0b10010000,
    0b10010000,
    0b10010000,
    0b11110000 },
  { 0b11110000,
    0b11000000,
    0b11000000,
    0b11110000,
    0b11010000,
    0b11010000,
    0b11010000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b11111100,
    0b10000000,
    0b11111100,
    0b10000100,
    0b10000100,
    0b11111100 },
  { 0b00000000,
    0b00000000,
    0b11111100,
    0b11000000,
    0b11111100,
    0b11001100,
    0b11001100,
    0b11111100 },
  { 0b00000000,
    0b00000000,
    0b11110000,
    0b10000000,
    0b11110000,
    0b10010000,
    0b10010000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b11110000,
    0b11000000,
    0b11110000,
    0b11010000,
    0b11010000,
    0b11110000 },

  { 0b00000000,
    0b00000000,
    0b11110000,
    0b10000000,
    0b11110000,
    0b10010000,
    0b10010000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b11110000,
    0b11000000,
    0b11110000,
    0b11010000,
    0b11010000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b11100000,
    0b10000000,
    0b11100000,
    0b10100000,
    0b10100000,
    0b11100000 },
  { 0b00000000,
    0b00000000,
    0b11100000,
    0b10000000,
    0b11100000,
    0b10100000,
    0b10100000,
    0b11100000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11110000,
    0b10000000,
    0b11110000,
    0b10010000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11110000,
    0b11000000,
    0b11110000,
    0b11010000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11100000,
    0b10000000,
    0b11100000,
    0b10100000,
    0b11100000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11100000,
    0b10000000,
    0b11100000,
    0b10100000,
    0b11100000 },


  { 0b11111100,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00000100 },
  { 0b11111100,
    0b00001100,
    0b00001100,
    0b00001100,
    0b00001100,
    0b00001100,
    0b00001100,
    0b00001100 },
  { 0b11110000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000 },
  { 0b11110000,
    0b00110000,
    0b00110000,
    0b00110000,
    0b00110000,
    0b00110000,
    0b00110000,
    0b00110000 },
  { 0b00000000,
    0b00000000,
    0b11111100,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00000100,
    0b00000100 },
  { 0b00000000,
    0b00000000,
    0b11111100,
    0b00001100,
    0b00001100,
    0b00001100,
    0b00001100,
    0b00001100 },
  { 0b00000000,
    0b00000000,
    0b11110000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000 },
  { 0b00000000,
    0b00000000,
    0b11110000,
    0b00110000,
    0b00110000,
    0b00110000,
    0b00110000,
    0b00110000 },

  { 0b00000000,
    0b00000000,
    0b11110000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000 },
  { 0b00000000,
    0b00000000,
    0b11110000,
    0b00110000,
    0b00110000,
    0b00110000,
    0b00110000,
    0b00110000 },
  { 0b00000000,
    0b00000000,
    0b11100000,
    0b00100000,
    0b00100000,
    0b00100000,
    0b00100000,
    0b00100000 },
  { 0b00000000,
    0b00000000,
    0b11100000,
    0b00100000,
    0b00100000,
    0b00100000,
    0b00100000,
    0b00100000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11110000,
    0b00010000,
    0b00010000,
    0b00010000,
    0b00010000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11110000,
    0b00110000,
    0b00110000,
    0b00110000,
    0b00110000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11100000,
    0b00100000,
    0b00100000,
    0b00100000,
    0b00100000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11100000,
    0b00100000,
    0b00100000,
    0b00100000,
    0b00100000 },


  { 0b11111100,
    0b10000100,
    0b10000100,
    0b11111100,
    0b10000100,
    0b10000100,
    0b10000100,
    0b11111100 },
  { 0b11111100,
    0b11001100,
    0b11001100,
    0b11111100,
    0b11001100,
    0b11001100,
    0b11001100,
    0b11111100 },
  { 0b11110000,
    0b10010000,
    0b10010000,
    0b11110000,
    0b10010000,
    0b10010000,
    0b10010000,
    0b11110000 },
  { 0b11110000,
    0b10110000,
    0b10110000,
    0b11110000,
    0b10110000,
    0b10110000,
    0b10110000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b11111100,
    0b10000100,
    0b11111100,
    0b10000100,
    0b10000100,
    0b11111100 },
  { 0b00000000,
    0b00000000,
    0b11111100,
    0b11001100,
    0b11111100,
    0b11001100,
    0b11001100,
    0b11111100 },
  { 0b00000000,
    0b00000000,
    0b11110000,
    0b10010000,
    0b11110000,
    0b10010000,
    0b10010000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b11110000,
    0b10110000,
    0b11110000,
    0b10110000,
    0b10110000,
    0b11110000 },

  { 0b00000000,
    0b00000000,
    0b11110000,
    0b10010000,
    0b11110000,
    0b10010000,
    0b10010000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b11110000,
    0b10110000,
    0b11110000,
    0b10110000,
    0b10110000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b11100000,
    0b10100000,
    0b11100000,
    0b10100000,
    0b10100000,
    0b11100000 },
  { 0b00000000,
    0b00000000,
    0b11100000,
    0b10100000,
    0b11100000,
    0b10100000,
    0b10100000,
    0b11100000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11110000,
    0b10010000,
    0b11110000,
    0b10010000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11110000,
    0b10110000,
    0b11110000,
    0b10110000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11100000,
    0b10100000,
    0b11100000,
    0b10100000,
    0b11100000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11100000,
    0b10100000,
    0b11100000,
    0b10100000,
    0b11100000 },


  { 0b11111100,
    0b10000100,
    0b10000100,
    0b10000100,
    0b11111100,
    0b00000100,
    0b00000100,
    0b11111100 },
  { 0b11111100,
    0b11001100,
    0b11001100,
    0b11001100,
    0b11111100,
    0b00001100,
    0b00001100,
    0b11111100 },
  { 0b11110000,
    0b10010000,
    0b10010000,
    0b10010000,
    0b11110000,
    0b00010000,
    0b00010000,
    0b11110000 },
  { 0b11110000,
    0b10110000,
    0b10110000,
    0b10110000,
    0b11110000,
    0b00110000,
    0b00110000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b11111100,
    0b10000100,
    0b10000100,
    0b11111100,
    0b00000100,
    0b11111100 },
  { 0b00000000,
    0b00000000,
    0b11111100,
    0b11001100,
    0b11001100,
    0b11111100,
    0b00001100,
    0b11111100 },
  { 0b00000000,
    0b00000000,
    0b11110000,
    0b10010000,
    0b10010000,
    0b11110000,
    0b00010000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b11110000,
    0b10110000,
    0b10110000,
    0b11110000,
    0b00110000,
    0b11110000 },

  { 0b00000000,
    0b00000000,
    0b11110000,
    0b10010000,
    0b10010000,
    0b11110000,
    0b00010000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b11110000,
    0b10110000,
    0b10110000,
    0b11110000,
    0b00110000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b11100000,
    0b10100000,
    0b10100000,
    0b11100000,
    0b00100000,
    0b11100000 },
  { 0b00000000,
    0b00000000,
    0b11100000,
    0b10100000,
    0b10100000,
    0b11100000,
    0b00100000,
    0b11100000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11110000,
    0b10010000,
    0b11110000,
    0b00010000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11110000,
    0b10110000,
    0b11110000,
    0b00110000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11100000,
    0b10100000,
    0b11100000,
    0b00100000,
    0b11100000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11100000,
    0b10100000,
    0b11100000,
    0b00100000,
    0b11100000 },


  { 0b11111100,
    0b10000100,
    0b10000100,
    0b10000100,
    0b10000100,
    0b10000100,
    0b10000100,
    0b11111100 },
  { 0b11111100,
    0b11001100,
    0b11001100,
    0b11001100,
    0b11001100,
    0b11001100,
    0b11001100,
    0b11111100 },
  { 0b11110000,
    0b10010000,
    0b10010000,
    0b10010000,
    0b10010000,
    0b10010000,
    0b10010000,
    0b11110000 },
  { 0b11110000,
    0b10110000,
    0b10110000,
    0b10110000,
    0b10110000,
    0b10110000,
    0b10110000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b11111100,
    0b10000100,
    0b10000100,
    0b10000100,
    0b10000100,
    0b11111100 },
  { 0b00000000,
    0b00000000,
    0b11111100,
    0b11001100,
    0b11001100,
    0b11001100,
    0b11001100,
    0b11111100 },
  { 0b00000000,
    0b00000000,
    0b11110000,
    0b10010000,
    0b10010000,
    0b10010000,
    0b10010000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b11110000,
    0b10110000,
    0b10110000,
    0b10110000,
    0b10110000,
    0b11110000 },

  { 0b00000000,
    0b00000000,
    0b11110000,
    0b10010000,
    0b10010000,
    0b10010000,
    0b10010000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b11110000,
    0b10110000,
    0b10110000,
    0b10110000,
    0b10110000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b11100000,
    0b10100000,
    0b10100000,
    0b10100000,
    0b10100000,
    0b11100000 },
  { 0b00000000,
    0b00000000,
    0b11100000,
    0b10100000,
    0b10100000,
    0b10100000,
    0b10100000,
    0b11100000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11110000,
    0b10010000,
    0b10010000,
    0b10010000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11110000,
    0b10110000,
    0b10110000,
    0b10110000,
    0b11110000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11100000,
    0b10100000,
    0b10100000,
    0b10100000,
    0b11100000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b11100000,
    0b10100000,
    0b10100000,
    0b10100000,
    0b11100000 },


  { 0b00000000,
    0b00000000,
    0b00000000,
    0b01111000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b01111000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b01100000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b01100000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b01111000,
    0b00000000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b01111000,
    0b00000000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b01100000,
    0b00000000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b01100000,
    0b00000000,
    0b00000000,
    0b00000000 },

  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b11110000,
    0b00000000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b11110000,
    0b00000000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b11100000,
    0b00000000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b11100000,
    0b00000000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b11110000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b11110000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b11100000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b11100000,
    0b00000000,
    0b00000000 },


  { 0b00000000,
    0b00000000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b10000000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b10000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b10000000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b10000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b10000000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b10000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b10000000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b10000000 },

  { 0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000,
    0b10000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000,
    0b10000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000,
    0b10000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000,
    0b10000000,
    0b00000000 },


  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b10000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b10000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b10000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b10000000 },

  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000 },


  { 0b00000000,
    0b00000000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b10000000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b10000000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b10000000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b10000000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000 },

  { 0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b00000000 },
  { 0b00000000,
    0b00000000,
    0b00000000,
    0b00000000,
    0b10000000,
    0b00000000,
    0b00000000,
    0b00000000 }
};