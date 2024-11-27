#include "TCData.h"

static const uint8_t TRANSPARENT_PIXEL[] PROGMEM  = {
  0x1F, 0x8B, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x73, 0xF7, 0x74, 0xB3, 0xB0, 0x4C, 0x64, 0x64, 0x60, 0x64, 0x68, 0x60, 0x60, 0xF8, 0xFF, 0xFF, 0x3F, 0x03, 0x03, 0x83, 0xE2, 0x4F,
  0x16, 0x46, 0x20, 0xC5, 0xA0, 0x03, 0x22, 0x40, 0x32, 0x0C, 0x4C, 0x4C, 0x2E, 0x8C, 0x0C, 0xD6, 0x00, 0xB1, 0xEA, 0xCC, 0x9A, 0x2B, 0x00, 0x00, 0x00
};

static const uint8_t ANIMATION_01[] PROGMEM = {
  0x1F, 0x8B, 0x08, 0x08, 0x31, 0xDC, 0x37, 0x66, 0x00, 0x0B, 0x7A, 0x2E, 0x67, 0x69, 0x66, 0x00, 0x73, 0xF7, 0x74, 0xB3, 0xB0, 0x4C, 0xE4, 0x60, 0xE0, 0x60, 0x68, 0x60, 0x00, 0x01, 0xE7, 0xFD,
  0x3A, 0x8A, 0xFF, 0xB9, 0xFD, 0x5C, 0x43, 0x82, 0x9D, 0x1D, 0x03, 0x5C, 0x8D, 0xF4, 0x0C, 0x98, 0x19, 0x81, 0xA2, 0x8A, 0x3F, 0x59, 0x58, 0xF8, 0x81, 0xB4, 0x0E, 0x48, 0x09, 0x48, 0x31, 0x03,
  0x13, 0xAF, 0x4B, 0x5F, 0xC2, 0xAA, 0x83, 0x6F, 0xEE, 0x4D, 0xFA, 0xEC, 0x5A, 0xF9, 0x56, 0x1B, 0xA1, 0x02, 0xA4, 0x9C, 0x0D, 0x08, 0x19, 0x98, 0x38, 0x5B, 0xE4, 0x57, 0x16, 0x1E, 0xB8, 0x21,
  0xC7, 0xC2, 0x8A, 0x2E, 0xCB, 0x0E, 0x94, 0xE5, 0x76, 0x91, 0x5B, 0x90, 0xDD, 0x31, 0x27, 0x2C, 0x64, 0xF2, 0x2A, 0x26, 0x74, 0x79, 0x90, 0xF9, 0x3C, 0x3C, 0x7C, 0x62, 0xD9, 0x1D, 0x3C, 0xB1,
  0xD6, 0xC6, 0x96, 0xDC, 0x5C, 0xC8, 0x0A, 0x18, 0xA1, 0xC6, 0x73, 0xC1, 0x14, 0x2C, 0x63, 0x40, 0x96, 0x66, 0xC2, 0x2F, 0x0D, 0x37, 0xDE, 0x45, 0x8E, 0x2D, 0xFB, 0xE4, 0x71, 0x91, 0xA2, 0x8D,
  0xBE, 0x59, 0x5C, 0xB8, 0xEC, 0x5F, 0x3D, 0xA3, 0x6D, 0x5A, 0xF0, 0x19, 0xD7, 0x6D, 0x18, 0xF6, 0x83, 0x3D, 0x00, 0x57, 0xB0, 0x10, 0xE2, 0x01, 0x90, 0x66, 0x0C, 0x1B, 0x3A, 0x15, 0xB2, 0x3F,
  0x5F, 0x49, 0xE3, 0x66, 0xB0, 0x06, 0x00, 0x96, 0x97, 0x47, 0xDA, 0x69, 0x01, 0x00, 0x00, 0x0D, 0x0A, 0x00, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x57, 0x65, 0x62, 0x4B, 0x69, 0x74, 0x46, 0x6F, 0x72,
  0x6D, 0x42, 0x6F, 0x75, 0x6E, 0x64, 0x61, 0x72, 0x79, 0x6C, 0x30, 0x4E, 0x5A, 0x67, 0x30, 0x34, 0x49, 0x4E, 0x58, 0x73, 0x51, 0x34, 0x78, 0x36, 0x30, 0x0D, 0x0A, 0x43, 0x6F, 0x6E, 0x74, 0x65,
  0x6E, 0x74, 0x2D, 0x44, 0x69, 0x73, 0x70, 0x6F, 0x73, 0x69, 0x74, 0x69, 0x6F, 0x6E, 0x3A, 0x20, 0x66, 0x6F, 0x72, 0x6D, 0x2D, 0x64, 0x61, 0x74, 0x61, 0x3B, 0x20, 0x6E, 0x61, 0x6D, 0x65, 0x3D,
  0x22, 0x63, 0x6D, 0x64, 0x00, 0x0D, 0x0A, 0x0D, 0x0A, 0x43, 0x6F, 0x6E, 0x76, 0x65, 0x72, 0x74, 0x00, 0x00, 0x00, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x57, 0x65, 0x62, 0x4B, 0x69, 0x74, 0x46, 0x6F,
  0x72, 0x6D, 0x42, 0x6F, 0x75, 0x6E, 0x64, 0x61, 0x72, 0x79, 0x6C, 0x30, 0x4E, 0x5A, 0x67, 0x30, 0x34, 0x49, 0x4E, 0x58, 0x73, 0x51, 0x34, 0x78, 0x36, 0x30, 0x2D, 0x2D, 0x0D, 0x0A, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x43, 0x6F, 0x6E, 0x74, 0x65, 0x6E, 0x74, 0x2D, 0x74, 0x79, 0x70, 0x65, 0x3A, 0x20, 0x74, 0x65, 0x78, 0x74,
  0x2F, 0x70, 0x6C, 0x61, 0x69, 0x6E, 0x0D, 0x0A, 0x0D, 0x0A, 0x2F, 0x2F, 0x20, 0x42, 0x4C, 0x4F, 0x42, 0x49, 0x4E, 0x41, 0x54, 0x49, 0x4F, 0x52, 0x3A, 0x20, 0x30, 0x2E, 0x67, 0x69, 0x66, 0x2E,
  0x67, 0x7A, 0x0A, 0x0A, 0x75, 0x6E, 0x73, 0x69, 0x67, 0x6E, 0x65, 0x64, 0x20, 0x63, 0x68, 0x61, 0x72, 0x20, 0x30, 0x2E, 0x67, 0x69, 0x66, 0x5B, 0x34, 0x39, 0x36, 0x5D, 0x20, 0x3D, 0x0A, 0x7B,
  0x0A, 0x20, 0x20, 0x20, 0x30, 0x78, 0x31, 0x46, 0x2C, 0x30, 0x78, 0x38, 0x42, 0x2C, 0x30, 0x78, 0x30, 0x38, 0x2C, 0x30, 0x78, 0x30, 0x38, 0x2C, 0x30, 0x78, 0x33, 0x31, 0x2C, 0x30, 0x78, 0x44,
  0x43, 0x2C, 0x30, 0x78, 0x33, 0x37, 0x2C, 0x30, 0x78, 0x36, 0x36, 0x2C, 0x30, 0x78, 0x30, 0x30
};

static const uint8_t ANIMATION_02[] PROGMEM = {
  0x1F, 0x8B, 0x08, 0x08, 0xA7, 0xE0, 0x37, 0x66, 0x00, 0x0B, 0x31, 0x31, 0x2E, 0x67, 0x69, 0x66, 0x00, 0x73, 0xF7, 0x74, 0xB3, 0xB0, 0x4C, 0xE4, 0x60, 0xE0, 0x60, 0x68, 0x60, 0x00, 0x01, 0xE7,
  0xFD, 0x3A, 0x8A, 0xFF, 0xB9, 0xFD, 0x5C, 0x43, 0x82, 0x9D, 0x1D, 0x03, 0x5C, 0x8D, 0xF4, 0x0C, 0x98, 0x19, 0x81, 0xA2, 0x8A, 0x3F, 0x59, 0x58, 0xF8, 0x81, 0xB4, 0x0E, 0x48, 0x09, 0x48, 0x31,
  0x03, 0x13, 0xAF, 0x4B, 0x5F, 0xC2, 0xAA, 0x83, 0x6F, 0xEE, 0x4D, 0xFA, 0xEC, 0x5A, 0xF9, 0x56, 0x1B, 0xA1, 0x02, 0xA4, 0x9C, 0x8D, 0x01, 0x48, 0x32, 0x31, 0xB5, 0xC4, 0xA3, 0x0B, 0x33, 0x01,
  0x85, 0x59, 0x5D, 0xE4, 0x16, 0x70, 0xB3, 0x22, 0xCB, 0x30, 0x42, 0x65, 0x58, 0x78, 0xF8, 0xDA, 0xC2, 0x91, 0x25, 0x98, 0xB0, 0x4B, 0x30, 0x31, 0x30, 0x33, 0xB0, 0x40, 0x24, 0x7A, 0x98, 0x39,
  0x51, 0x8C, 0x62, 0xC1, 0x65, 0x14, 0x2B, 0x2E, 0x09, 0x36, 0x0C, 0x09, 0x90, 0x5B, 0x81, 0x76, 0xB0, 0x03, 0x0D, 0x03, 0x7B, 0xA3, 0x27, 0x98, 0xC1, 0x1A, 0x00, 0x91, 0xB6, 0xCA, 0x74, 0x27,
  0x01, 0x00, 0x00, 0x0D, 0x0A, 0x00, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x57, 0x65, 0x62, 0x4B, 0x69, 0x74, 0x46, 0x6F, 0x72, 0x6D, 0x42, 0x6F, 0x75, 0x6E, 0x64, 0x61, 0x72, 0x79, 0x6E, 0x49, 0x66,
  0x4D, 0x74, 0x79, 0x75, 0x6A, 0x43, 0x51, 0x4E, 0x42, 0x78, 0x4F, 0x64, 0x6B, 0x0D, 0x0A, 0x43, 0x6F, 0x6E, 0x74, 0x65, 0x6E, 0x74, 0x2D, 0x44, 0x69, 0x73, 0x70, 0x6F, 0x73, 0x69, 0x74, 0x69,
  0x6F, 0x6E, 0x3A, 0x20, 0x66, 0x6F, 0x72, 0x6D, 0x2D, 0x64, 0x61, 0x74, 0x61, 0x3B, 0x20, 0x6E, 0x61, 0x6D, 0x65, 0x3D, 0x22, 0x63, 0x6D, 0x64, 0x00, 0x0D, 0x0A, 0x0D, 0x0A, 0x43, 0x6F, 0x6E,
  0x76, 0x65, 0x72, 0x74, 0x00, 0x00, 0x00, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x57, 0x65, 0x62, 0x4B, 0x69, 0x74, 0x46, 0x6F, 0x72, 0x6D, 0x42, 0x6F, 0x75, 0x6E, 0x64, 0x61, 0x72, 0x79, 0x6E, 0x49,
  0x66, 0x4D, 0x74, 0x79, 0x75, 0x6A, 0x43, 0x51, 0x4E, 0x42, 0x78, 0x4F, 0x64, 0x6B, 0x2D, 0x2D, 0x0D, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x43, 0x6F,
  0x6E, 0x74, 0x65, 0x6E, 0x74, 0x2D, 0x74, 0x79, 0x70, 0x65, 0x3A, 0x20, 0x74, 0x65, 0x78, 0x74, 0x2F, 0x70, 0x6C, 0x61, 0x69, 0x6E, 0x0D, 0x0A, 0x0D, 0x0A, 0x2F, 0x2F, 0x20, 0x42, 0x4C, 0x4F,
  0x42, 0x49, 0x4E, 0x41, 0x54, 0x49, 0x4F, 0x52, 0x3A, 0x20, 0x31, 0x2E, 0x67, 0x69, 0x66, 0x2E, 0x67, 0x7A, 0x0A, 0x0A, 0x75, 0x6E, 0x73, 0x69, 0x67, 0x6E, 0x65, 0x64, 0x20, 0x63, 0x68, 0x61,
  0x72, 0x20, 0x31, 0x2E, 0x67, 0x69, 0x66, 0x5B, 0x34, 0x35, 0x32, 0x5D, 0x20, 0x3D, 0x0A, 0x7B, 0x0A, 0x20, 0x20, 0x20, 0x30, 0x78, 0x31, 0x46, 0x2C, 0x30, 0x78, 0x38, 0x42, 0x2C, 0x30, 0x78,
  0x30, 0x38, 0x2C, 0x30, 0x78, 0x30, 0x38, 0x2C, 0x30, 0x78, 0x41, 0x37, 0x2C, 0x30, 0x78, 0x45, 0x30, 0x2C, 0x30, 0x78, 0x33, 0x37, 0x2C, 0x30, 0x78, 0x36, 0x36, 0x2C, 0x30, 0x78, 0x30, 0x30,
  0x2C, 0x30, 0x78, 0x30
};

static const uint8_t ANIMATION_03[] PROGMEM = {
  0x1F, 0x8B, 0x08, 0x08, 0xBE, 0xE1, 0x37, 0x66, 0x00, 0x0B, 0x32, 0x32, 0x2E, 0x67, 0x69, 0x66, 0x00, 0x73, 0xF7, 0x74, 0xB3, 0xB0, 0x4C, 0xE4, 0x60, 0xE0, 0x60, 0x68, 0x60, 0x00, 0x01, 0xE7,
  0xFD, 0x3A, 0x8A, 0xFF, 0xB9, 0xFD, 0x5C, 0x43, 0x82, 0x9D, 0x1D, 0x03, 0x5C, 0x8D, 0xF4, 0x0C, 0x98, 0x19, 0x81, 0xA2, 0x8A, 0x3F, 0x59, 0x58, 0xF8, 0x81, 0xB4, 0x0E, 0x48, 0x09, 0x48, 0x31,
  0x03, 0x13, 0xAF, 0x4B, 0x5F, 0xC2, 0xAA, 0x83, 0x6F, 0xEE, 0x4D, 0xFA, 0xEC, 0x5A, 0xF9, 0x56, 0x1B, 0xA1, 0x02, 0xA4, 0x9C, 0x8D, 0x01, 0x48, 0x32, 0x31, 0xBB, 0xC8, 0x05, 0xA0, 0xEA, 0x64,
  0x04, 0x8B, 0x33, 0xB9, 0x30, 0x22, 0x2B, 0x67, 0x82, 0x29, 0xE7, 0xE1, 0x0B, 0x44, 0x88, 0x33, 0x31, 0x30, 0x33, 0xB0, 0x40, 0x94, 0xF7, 0x04, 0x23, 0x2B, 0x67, 0xC1, 0xAA, 0x9C, 0x91, 0x81,
  0x15, 0x87, 0x38, 0x1B, 0x0E, 0xE3, 0xD9, 0xD1, 0x8C, 0x07, 0x39, 0x1C, 0xCD, 0x91, 0xD6, 0x00, 0xE0, 0x3F, 0xE9, 0x20, 0x1D, 0x01, 0x00, 0x00, 0x0D, 0x0A, 0x00, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D,
  0x57, 0x65, 0x62, 0x4B, 0x69, 0x74, 0x46, 0x6F, 0x72, 0x6D, 0x42, 0x6F, 0x75, 0x6E, 0x64, 0x61, 0x72, 0x79, 0x64, 0x69, 0x55, 0x4F, 0x65, 0x51, 0x51, 0x4D, 0x53, 0x36, 0x38, 0x6C, 0x42, 0x73,
  0x75, 0x66, 0x0D, 0x0A, 0x43, 0x6F, 0x6E, 0x74, 0x65, 0x6E, 0x74, 0x2D, 0x44, 0x69, 0x73, 0x70, 0x6F, 0x73, 0x69, 0x74, 0x69, 0x6F, 0x6E, 0x3A, 0x20, 0x66, 0x6F, 0x72, 0x6D, 0x2D, 0x64, 0x61,
  0x74, 0x61, 0x3B, 0x20, 0x6E, 0x61, 0x6D, 0x65, 0x3D, 0x22, 0x63, 0x6D, 0x64, 0x00, 0x0D, 0x0A, 0x0D, 0x0A, 0x43, 0x6F, 0x6E, 0x76, 0x65, 0x72, 0x74, 0x00, 0x00, 0x00, 0x2D, 0x2D, 0x2D, 0x2D,
  0x2D, 0x57, 0x65, 0x62, 0x4B, 0x69, 0x74, 0x46, 0x6F, 0x72, 0x6D, 0x42, 0x6F, 0x75, 0x6E, 0x64, 0x61, 0x72, 0x79, 0x64, 0x69, 0x55, 0x4F, 0x65, 0x51, 0x51, 0x4D, 0x53, 0x36, 0x38, 0x6C, 0x42,
  0x73, 0x75, 0x66, 0x2D, 0x2D, 0x0D, 0x0A, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x43, 0x6F,
  0x6E, 0x74, 0x65, 0x6E, 0x74, 0x2D, 0x74, 0x79, 0x70, 0x65, 0x3A, 0x20, 0x74, 0x65, 0x78, 0x74, 0x2F, 0x70, 0x6C, 0x61, 0x69, 0x6E, 0x0D, 0x0A, 0x0D, 0x0A, 0x2F, 0x2F, 0x20, 0x42, 0x4C, 0x4F,
  0x42, 0x49, 0x4E, 0x41, 0x54, 0x49, 0x4F, 0x52, 0x3A, 0x20, 0x32, 0x2E, 0x67, 0x69, 0x66, 0x2E, 0x67, 0x7A, 0x0A, 0x0A, 0x75, 0x6E, 0x73, 0x69, 0x67, 0x6E, 0x65, 0x64, 0x20, 0x63, 0x68, 0x61,
  0x72, 0x20, 0x32, 0x2E, 0x67, 0x69, 0x66, 0x5B, 0x34, 0x34, 0x31, 0x5D, 0x20, 0x3D, 0x0A, 0x7B, 0x0A, 0x20, 0x20, 0x20, 0x30, 0x78, 0x31, 0x46, 0x2C, 0x30, 0x78, 0x38, 0x42, 0x2C, 0x30, 0x78,
  0x30, 0x38, 0x2C, 0x30, 0x78, 0x30, 0x38, 0x2C, 0x30, 0x78, 0x42, 0x45, 0x2C, 0x30, 0x78, 0x45, 0x31, 0x2C, 0x30, 0x78, 0x33, 0x37, 0x2C, 0x30, 0x78
};

static const uint8_t ANIMATION_04[] PROGMEM = {
  0x1F, 0x8B, 0x08, 0x08, 0x80, 0xE3, 0x37, 0x66, 0x00, 0x0B, 0x33, 0x33, 0x2E, 0x67, 0x69, 0x66, 0x00, 0x73, 0xF7, 0x74, 0xB3, 0xB0, 0x4C, 0xE4, 0x60, 0xE0, 0x60, 0x68, 0x60, 0x00, 0x01, 0xE7,
  0xFD, 0x3A, 0x8A, 0xFF, 0xB9, 0xFD, 0x5C, 0x43, 0x82, 0x9D, 0x1D, 0x03, 0x5C, 0x8D, 0xF4, 0x0C, 0x98, 0x19, 0x81, 0xA2, 0x8A, 0x3F, 0x59, 0x58, 0xF8, 0x81, 0xB4, 0x0E, 0x48, 0x09, 0x48, 0x31,
  0x03, 0x13, 0xAF, 0x4B, 0x5F, 0xC2, 0xAA, 0x83, 0x6F, 0xEE, 0x4D, 0xFA, 0xEC, 0x5A, 0xF9, 0x56, 0x1B, 0xA1, 0x02, 0xA4, 0x9C, 0x0D, 0x08, 0x19, 0x98, 0x38, 0x5B, 0xE4, 0x57, 0x16, 0x1E, 0xB8,
  0x21, 0xC7, 0xC2, 0x8A, 0x2E, 0xCB, 0x0E, 0x94, 0xE5, 0x76, 0x91, 0x5B, 0x90, 0xDD, 0x31, 0x27, 0x2C, 0x64, 0xF2, 0x2A, 0x26, 0x64, 0x79, 0x46, 0x98, 0x3C, 0x0F, 0x5F, 0x9B, 0xF8, 0xDB, 0x53,
  0x62, 0x3E, 0xDD, 0x4D, 0x28, 0xF2, 0x4C, 0x40, 0x79, 0x56, 0xA0, 0x3C, 0x07, 0x44, 0x7E, 0x9A, 0x26, 0xB2, 0x24, 0x33, 0x4C, 0x12, 0x6A, 0xB8, 0x16, 0xB2, 0x24, 0x0B, 0x50, 0x92, 0x05, 0x28,
  0xC9, 0x0E, 0xD1, 0xC9, 0x85, 0x2C, 0xC7, 0x0A, 0x94, 0x63, 0x06, 0xCA, 0xB1, 0x81, 0xE5, 0x50, 0x1C, 0x0C, 0xF2, 0x0C, 0x13, 0x50, 0x8A, 0x05, 0x28, 0x15, 0x0E, 0x96, 0x00, 0xF9, 0x42, 0x87,
  0x09, 0xE8, 0x4A, 0x16, 0xA0, 0x6B, 0x19, 0x98, 0x98, 0x7A, 0x82, 0x19, 0xAC, 0x01, 0xCE, 0xA5, 0x4F, 0xA1, 0x48, 0x01, 0x00, 0x00, 0x0D, 0x0A, 0x00, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x57, 0x65,
  0x62, 0x4B, 0x69, 0x74, 0x46, 0x6F, 0x72, 0x6D, 0x42, 0x6F, 0x75, 0x6E, 0x64, 0x61, 0x72, 0x79, 0x6A, 0x42, 0x5A, 0x6E, 0x52, 0x6B, 0x59, 0x41, 0x47, 0x41, 0x6B, 0x39, 0x33, 0x5A, 0x45, 0x73,
  0x0D, 0x0A, 0x43, 0x6F, 0x6E, 0x74, 0x65, 0x6E, 0x74, 0x2D, 0x44, 0x69, 0x73, 0x70, 0x6F, 0x73, 0x69, 0x74, 0x69, 0x6F, 0x6E, 0x3A, 0x20, 0x66, 0x6F, 0x72, 0x6D, 0x2D, 0x64, 0x61, 0x74, 0x61,
  0x3B, 0x20, 0x6E, 0x61, 0x6D, 0x65, 0x3D, 0x22, 0x63, 0x6D, 0x64, 0x00, 0x0D, 0x0A, 0x0D, 0x0A, 0x43, 0x6F, 0x6E, 0x76, 0x65, 0x72, 0x74, 0x00, 0x00, 0x00, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x57,
  0x65, 0x62, 0x4B, 0x69, 0x74, 0x46, 0x6F, 0x72, 0x6D, 0x42, 0x6F, 0x75, 0x6E, 0x64, 0x61, 0x72, 0x79, 0x6A, 0x42, 0x5A, 0x6E, 0x52, 0x6B, 0x59, 0x41, 0x47, 0x41, 0x6B, 0x39, 0x33, 0x5A, 0x45,
  0x73, 0x2D, 0x2D, 0x0D, 0x0A, 0x00, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x43, 0x6F, 0x6E, 0x74, 0x65, 0x6E, 0x74, 0x2D, 0x74, 0x79, 0x70, 0x65, 0x3A, 0x20, 0x74, 0x65, 0x78, 0x74,
  0x2F, 0x70, 0x6C, 0x61, 0x69, 0x6E, 0x0D, 0x0A, 0x0D, 0x0A, 0x2F, 0x2F, 0x20, 0x42, 0x4C, 0x4F, 0x42, 0x49, 0x4E, 0x41, 0x54, 0x49, 0x4F, 0x52, 0x3A, 0x20, 0x33, 0x2E, 0x67, 0x69, 0x66, 0x2E,
  0x67, 0x7A, 0x0A, 0x0A, 0x75, 0x6E, 0x73, 0x69, 0x67, 0x6E, 0x65, 0x64, 0x20, 0x63, 0x68, 0x61, 0x72, 0x20, 0x33, 0x2E, 0x67, 0x69, 0x66, 0x5B, 0x35, 0x30, 0x33, 0x5D, 0x20, 0x3D, 0x0A, 0x7B,
  0x0A, 0x20, 0x20, 0x20, 0x30, 0x78, 0x31, 0x46, 0x2C, 0x30, 0x78, 0x38, 0x42, 0x2C, 0x30, 0x78, 0x30, 0x38, 0x2C, 0x30, 0x78, 0x30, 0x38, 0x2C, 0x30, 0x78, 0x38, 0x30, 0x2C, 0x30, 0x78, 0x45,
  0x33, 0x2C, 0x30, 0x78, 0x33, 0x37, 0x2C, 0x30, 0x78, 0x36, 0x36, 0x2C, 0x30, 0x78, 0x30, 0x30, 0x2C, 0x30, 0x78, 0x30, 0x42, 0x2C, 0x30
};

static const uint8_t ANIMATION_05[] PROGMEM = {
  0x1F, 0x8B, 0x08, 0x08, 0x67, 0xFD, 0x40, 0x66, 0x00, 0x0B, 0x35, 0x2E, 0x67, 0x69, 0x66, 0x00, 0x73, 0xF7, 0x74, 0xB3, 0xB0, 0x4C, 0xE4, 0x60, 0xE0, 0x60, 0x68, 0x60, 0x00, 0x01, 0xE7, 0xFD,
  0x3A, 0x8A, 0xFF, 0xB9, 0xFD, 0x5C, 0x43, 0x82, 0x9D, 0x1D, 0x03, 0x5C, 0x8D, 0xF4, 0x0C, 0x98, 0x19, 0x81, 0xA2, 0x8A, 0x3F, 0x59, 0x58, 0xF8, 0x81, 0xB4, 0x0E, 0x48, 0x09, 0x48, 0x31, 0x03,
  0x13, 0xAF, 0x4B, 0x5F, 0xC2, 0xAA, 0x83, 0x6F, 0xEE, 0x4D, 0xFA, 0xEC, 0x5A, 0xF9, 0x56, 0x1B, 0xA1, 0x02, 0xA4, 0x9C, 0x0D, 0x08, 0x19, 0x98, 0xB8, 0x5C, 0xE4, 0xDA, 0x38, 0x72, 0xFF, 0xC5,
  0x34, 0x6D, 0x66, 0x40, 0x96, 0x66, 0x84, 0x49, 0xF3, 0xF0, 0x2D, 0x5C, 0x3D, 0x23, 0x2F, 0x60, 0xCA, 0x72, 0x14, 0x69, 0x26, 0xFC, 0xD2, 0xCC, 0x40, 0x49, 0x16, 0xA0, 0x34, 0x3B, 0xC4, 0x70,
  0x2E, 0x64, 0x39, 0x16, 0x98, 0x1C, 0x44, 0x2B, 0x8A, 0x1C, 0x2B, 0x50, 0x8E, 0x19, 0x28, 0xC7, 0x06, 0x96, 0x63, 0x45, 0x48, 0x31, 0x81, 0x35, 0x31, 0x01, 0xA5, 0x58, 0x5A, 0x04, 0x25, 0x59,
  0x91, 0xF5, 0xB0, 0x03, 0xA5, 0x80, 0xDE, 0x61, 0x62, 0x76, 0x91, 0x0B, 0x00, 0x8B, 0x83, 0x3C, 0x07, 0x0E, 0x02, 0x46, 0xB0, 0x38, 0x93, 0x0B, 0x23, 0x83, 0x35, 0x00, 0x1B, 0x6E, 0xF5, 0x4F,
  0x41, 0x01, 0x00, 0x00, 0x0D, 0x0A, 0x00, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x57, 0x65, 0x62, 0x4B, 0x69, 0x74, 0x46, 0x6F, 0x72, 0x6D, 0x42, 0x6F, 0x75, 0x6E, 0x64, 0x61, 0x72, 0x79, 0x6A, 0x39,
  0x49, 0x78, 0x50, 0x68, 0x5A, 0x32, 0x4F, 0x4D, 0x49, 0x4E, 0x6C, 0x32, 0x65, 0x70, 0x0D, 0x0A, 0x43, 0x6F, 0x6E, 0x74, 0x65, 0x6E, 0x74, 0x2D, 0x44, 0x69, 0x73, 0x70, 0x6F, 0x73, 0x69, 0x74,
  0x69, 0x6F, 0x6E, 0x3A, 0x20, 0x66, 0x6F, 0x72, 0x6D, 0x2D, 0x64, 0x61, 0x74, 0x61, 0x3B, 0x20, 0x6E, 0x61, 0x6D, 0x65, 0x3D, 0x22, 0x63, 0x6D, 0x64, 0x00, 0x0D, 0x0A, 0x0D, 0x0A, 0x43, 0x6F,
  0x6E, 0x76, 0x65, 0x72, 0x74, 0x00, 0x00, 0x00, 0x2D, 0x2D, 0x2D, 0x2D, 0x2D, 0x57, 0x65, 0x62, 0x4B, 0x69, 0x74, 0x46, 0x6F, 0x72, 0x6D, 0x42, 0x6F, 0x75, 0x6E, 0x64, 0x61, 0x72, 0x79, 0x6A,
  0x39, 0x49, 0x78, 0x50, 0x68, 0x5A, 0x32, 0x4F, 0x4D, 0x49, 0x4E, 0x6C, 0x32, 0x65, 0x70, 0x2D, 0x2D, 0x0D, 0x0A, 0x00, 0x00, 0x00, 0x11, 0x10, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x43, 0x6F,
  0x6E, 0x74, 0x65, 0x6E, 0x74, 0x2D, 0x74, 0x79, 0x70, 0x65, 0x3A, 0x20, 0x74, 0x65, 0x78, 0x74, 0x2F, 0x70, 0x6C, 0x61, 0x69, 0x6E, 0x0D, 0x0A, 0x0D, 0x0A, 0x2F, 0x2F, 0x20, 0x42, 0x4C, 0x4F,
  0x42, 0x49, 0x4E, 0x41, 0x54, 0x49, 0x4F, 0x52, 0x3A, 0x20, 0x34, 0x2E, 0x67, 0x69, 0x66, 0x2E, 0x67, 0x7A, 0x0A, 0x0A, 0x75, 0x6E, 0x73, 0x69, 0x67, 0x6E, 0x65, 0x64, 0x20, 0x63, 0x68, 0x61,
  0x72, 0x20, 0x34, 0x2E, 0x67, 0x69, 0x66, 0x5B, 0x34, 0x38, 0x35, 0x5D, 0x20, 0x3D, 0x0A, 0x7B, 0x0A, 0x20, 0x20, 0x20, 0x30, 0x78, 0x31, 0x46, 0x2C, 0x30, 0x78, 0x38, 0x42, 0x2C, 0x30, 0x78,
  0x30, 0x38, 0x2C, 0x30, 0x78, 0x30, 0x38, 0x2C, 0x30, 0x78, 0x36, 0x37, 0x2C, 0x30, 0x78, 0x46, 0x44, 0x2C, 0x30, 0x78, 0x34, 0x30, 0x2C, 0x30, 0x78, 0x36, 0x36, 0x2C, 0x30, 0x78, 0x30, 0x30,
  0x2C, 0x30, 0x78, 0x30, 0x42
};

const uint8_t* TCData::getAnimation( uint8_t index ) {
  switch( index ) {
    case 1:
      return ANIMATION_01;
    case 2:
      return ANIMATION_02;
    case 3:
      return ANIMATION_03;
    case 4:
      return ANIMATION_04;
    case 5:
      return ANIMATION_05;
    default:
      return TRANSPARENT_PIXEL;
  }
}

const uint16_t TCData::getAnimationSize( uint8_t index ) {
  switch( index ) {
    case 1:
      return sizeof( ANIMATION_01 );
    case 2:
      return sizeof( ANIMATION_02 );
    case 3:
      return sizeof( ANIMATION_03 );
    case 4:
      return sizeof( ANIMATION_04 );
    case 5:
      return sizeof( ANIMATION_05 );
    default:
      return sizeof( TRANSPARENT_PIXEL );
  }
}

static const uint8_t FAVICON_ICO_GZ[] PROGMEM = {
  0x1F, 0x8B, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x63, 0x60, 0x60, 0x04, 0x42, 0x01, 0x01, 0x26, 0x30, 0xBD, 0x81, 0x81, 0x81, 0x41, 0x0C, 0x88, 0x35, 0x80, 0x58, 0x00, 0x88, 0x15,
  0x80, 0x18, 0x24, 0x0E, 0x02, 0x0E, 0x0C, 0x08, 0xC0, 0x04, 0xC5, 0xD6, 0xD6, 0xD6, 0x0C, 0x15, 0x7F, 0x36, 0xC3, 0xC5, 0x0F, 0xF0, 0x43, 0xB0, 0xB1, 0x01, 0x04, 0x1B, 0xA0, 0x61, 0x98, 0x38,
  0x4C, 0x1D, 0xB5, 0x00, 0x00, 0xE9, 0xAE, 0x62, 0x09, 0xC6, 0x00, 0x00, 0x00
};

const uint8_t* TCData::getFavIcon() {
  return FAVICON_ICO_GZ;
}

const uint16_t TCData::getFavIconSize() {
  return sizeof( FAVICON_ICO_GZ );
}
