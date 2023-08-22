#include <Arduino.h>
#include <vector>

class TCFonts {

public:

    static uint8_t getSymbolWidth( uint8_t fontIndex, char symbol, bool isBold, bool isWide, bool isProgress, bool isSmall ) {
      switch( fontIndex ) {
        case 0: {
          switch( isSmall ) {
            case false: {
              switch( symbol ) {
                case '1': {
                  switch( isWide ) {
                    case true: {
                      return 7;
                    }
                    case false: {
                      return 5;
                    }
                  }
                }
                case '2': {
                  switch( isWide ) {
                    case true: {
                      return 7;
                    }
                    case false: {
                      return 5;
                    }
                  }
                }
                case '3': {
                  switch( isWide ) {
                    case true: {
                      return 7;
                    }
                    case false: {
                      return 5;
                    }
                  }
                }
                case '4': {
                  switch( isWide ) {
                    case true: {
                      return 7;
                    }
                    case false: {
                      return 5;
                    }
                  }
                }
                case '5': {
                  switch( isWide ) {
                    case true: {
                      return 7;
                    }
                    case false: {
                      return 5;
                    }
                  }
                }
                case '6': {
                  switch( isWide ) {
                    case true: {
                      return 7;
                    }
                    case false: {
                      return 5;
                    }
                  }
                }
                case '7': {
                  switch( isWide ) {
                    case true: {
                      return 7;
                    }
                    case false: {
                      return 5;
                    }
                  }
                }
                case '8': {
                  switch( isWide ) {
                    case true: {
                      return 7;
                    }
                    case false: {
                      return 5;
                    }
                  }
                }
                case '9': {
                  switch( isWide ) {
                    case true: {
                      return 7;
                    }
                    case false: {
                      return 5;
                    }
                  }
                }
                case '0': {
                  switch( isWide ) {
                    case true: {
                      return 7;
                    }
                    case false: {
                      return 5;
                    }
                  }
                }
                case ' ': {
                  switch( isWide ) {
                    case true: {
                      return 7;
                    }
                    case false: {
                      return 5;
                    }
                  }
                }
                case '-': {
                  switch( isWide ) {
                    case true: {
                      return 7;
                    }
                    case false: {
                      return 5;
                    }
                  }
                }
                case ':': {
                  switch( isWide ) {
                    case true: {
                      return 4;
                    }
                    case false: {
                      return 4;
                    }
                  }
                }
                case '\b': {
                  switch( isWide ) {
                    case true: {
                      return 4;
                    }
                    case false: {
                      return 4;
                    }
                  }
                }
                case '\f': {
                  switch( isWide ) {
                    case true: {
                      return 4;
                    }
                    case false: {
                      return 4;
                    }
                  }
                }
                case '\t': {
                  switch( isWide ) {
                    case true: {
                      return 4;
                    }
                    case false: {
                      return 4;
                    }
                  }
                }
              }
            }
            case true: {
              switch( isWide ) {
                case false: {
                  return 4;
                }
              }
            }
          }
        }
        case 1: {
          switch( isSmall ) {
            case false: {
              switch( symbol ) {
                case '1': {
                  switch( isWide ) {
                    case true: {
                      return 7;
                    }
                    case false: {
                      return 5;
                    }
                  }
                }
                case '2': {
                  switch( isWide ) {
                    case true: {
                      return 7;
                    }
                    case false: {
                      return 5;
                    }
                  }
                }
                case '3': {
                  switch( isWide ) {
                    case true: {
                      return 7;
                    }
                    case false: {
                      return 5;
                    }
                  }
                }
                case '4': {
                  switch( isWide ) {
                    case true: {
                      return 7;
                    }
                    case false: {
                      return 5;
                    }
                  }
                }
                case '5': {
                  switch( isWide ) {
                    case true: {
                      return 7;
                    }
                    case false: {
                      return 5;
                    }
                  }
                }
                case '6': {
                  switch( isWide ) {
                    case true: {
                      return 7;
                    }
                    case false: {
                      return 5;
                    }
                  }
                }
                case '7': {
                  switch( isWide ) {
                    case true: {
                      return 7;
                    }
                    case false: {
                      return 5;
                    }
                  }
                }
                case '8': {
                  switch( isWide ) {
                    case true: {
                      return 7;
                    }
                    case false: {
                      return 5;
                    }
                  }
                }
                case '9': {
                  switch( isWide ) {
                    case true: {
                      return 7;
                    }
                    case false: {
                      return 5;
                    }
                  }
                }
                case '0': {
                  switch( isWide ) {
                    case true: {
                      return 7;
                    }
                    case false: {
                      return 5;
                    }
                  }
                }
                case ' ': {
                  switch( isWide ) {
                    case true: {
                      return 7;
                    }
                    case false: {
                      return 5;
                    }
                  }
                }
                case '-': {
                  switch( isWide ) {
                    case true: {
                      return 7;
                    }
                    case false: {
                      return 5;
                    }
                  }
                }
                case ':': {
                  switch( isWide ) {
                    case true: {
                      return 4;
                    }
                    case false: {
                      return 4;
                    }
                  }
                }
                case '\b': {
                  switch( isWide ) {
                    case true: {
                      return 4;
                    }
                    case false: {
                      return 4;
                    }
                  }
                }
                case '\f': {
                  switch( isWide ) {
                    case true: {
                      return 4;
                    }
                    case false: {
                      return 4;
                    }
                  }
                }
                case '\t': {
                  switch( isWide ) {
                    case true: {
                      return 4;
                    }
                    case false: {
                      return 4;
                    }
                  }
                }
              }
            }
            case true: {
              switch( isWide ) {
                case false: {
                  return 4;
                }
              }
            }
          }
        }
      }
      return 0;
    }

    static std::vector<uint8_t> getSymbol( uint8_t fontIndex, char symbol, bool isBold, bool isWide, bool isProgress, bool isSmall ) {
      switch( fontIndex ) {
        case 0: {
          switch( isSmall ) {
            case false: {
              switch( symbol ) {
                case '1': {
                  switch( isProgress ) {
                    case false: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00011000,
                                       0b00111000,
                                       0b00011000,
                                       0b00011000,
                                       0b00011000,
                                       0b00011000,
                                       0b00011000,
                                       0b00111100 };
                            }
                            case false: {
                              return { 0b00001000,
                                       0b00011000,
                                       0b00001000,
                                       0b00001000,
                                       0b00001000,
                                       0b00001000,
                                       0b00001000,
                                       0b00011100 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01100000,
                                       0b11100000,
                                       0b01100000,
                                       0b01100000,
                                       0b01100000,
                                       0b01100000,
                                       0b01100000,
                                       0b11110000 };
                            }
                            case false: {
                              return { 0b00100000,
                                       0b01100000,
                                       0b00100000,
                                       0b00100000,
                                       0b00100000,
                                       0b00100000,
                                       0b00100000,
                                       0b01110000 };
                            }
                          }
                        }
                      }
                    }
                    case true: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00011000,
                                       0b00111000,
                                       0b00011000,
                                       0b00011000,
                                       0b00011000,
                                       0b00111100 };
                            }
                            case false: {
                              return { 0b00001000,
                                       0b00011000,
                                       0b00001000,
                                       0b00001000,
                                       0b00001000,
                                       0b00011100 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01100000,
                                       0b11100000,
                                       0b01100000,
                                       0b01100000,
                                       0b01100000,
                                       0b11110000 };
                            }
                            case false: {
                              return { 0b00100000,
                                       0b01100000,
                                       0b00100000,
                                       0b00100000,
                                       0b00100000,
                                       0b01110000 };
                            }
                          }
                        }
                      }
                    }
                  }
                }
                case '2': {
                  switch( isProgress ) {
                    case false: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00111100,
                                       0b01100110,
                                       0b00000110,
                                       0b00000110,
                                       0b00001100,
                                       0b00111000,
                                       0b01100000,
                                       0b01111110 };
                            }
                            case false: {
                              return { 0b00111100,
                                       0b01000010,
                                       0b00000010,
                                       0b00000010,
                                       0b00001100,
                                       0b00110000,
                                       0b01000000,
                                       0b01111110 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01100000,
                                       0b10110000,
                                       0b00110000,
                                       0b00110000,
                                       0b00110000,
                                       0b01100000,
                                       0b11000000,
                                       0b11110000 };
                            }
                            case false: {
                              return { 0b01100000,
                                       0b10010000,
                                       0b00010000,
                                       0b00010000,
                                       0b00100000,
                                       0b01000000,
                                       0b10000000,
                                       0b11110000 };
                            }
                          }
                        }
                      }
                    }
                    case true: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00111100,
                                       0b01100110,
                                       0b00000110,
                                       0b00111100,
                                       0b01100000,
                                       0b01111110 };
                            }
                            case false: {
                              return { 0b00111100,
                                       0b01000010,
                                       0b00000010,
                                       0b00111100,
                                       0b01000000,
                                       0b01111110 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01100000,
                                       0b10110000,
                                       0b00110000,
                                       0b01100000,
                                       0b11000000,
                                       0b11110000 };
                            }
                            case false: {
                              return { 0b01100000,
                                       0b10010000,
                                       0b00010000,
                                       0b01100000,
                                       0b10000000,
                                       0b11110000 };
                            }
                          }
                        }
                      }
                    }
                  }
                }
                case '3': {
                  switch( isProgress ) {
                    case false: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00111100,
                                       0b01100110,
                                       0b00000110,
                                       0b00001100,
                                       0b00000110,
                                       0b00000110,
                                       0b01100110,
                                       0b00111100 };
                            }
                            case false: {
                              return { 0b00111100,
                                       0b01000010,
                                       0b00000010,
                                       0b00011100,
                                       0b00000010,
                                       0b00000010,
                                       0b01000010,
                                       0b00111100 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01100000,
                                       0b10110000,
                                       0b00110000,
                                       0b01100000,
                                       0b00110000,
                                       0b00110000,
                                       0b10110000,
                                       0b01100000 };
                            }
                            case false: {
                              return { 0b01100000,
                                       0b10010000,
                                       0b00010000,
                                       0b01100000,
                                       0b00010000,
                                       0b00010000,
                                       0b10010000,
                                       0b01100000 };
                            }
                          }
                        }
                      }
                    }
                    case true: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00111100,
                                       0b01100110,
                                       0b00001100,
                                       0b00000110,
                                       0b01100110,
                                       0b00111100 };
                            }
                            case false: {
                              return { 0b00111100,
                                       0b01000010,
                                       0b00011100,
                                       0b00000010,
                                       0b01000010,
                                       0b00111100 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b11100000,
                                       0b00110000,
                                       0b01100000,
                                       0b00110000,
                                       0b00110000,
                                       0b11100000 };
                            }
                            case false: {
                              return { 0b11100000,
                                       0b00010000,
                                       0b01100000,
                                       0b00010000,
                                       0b00010000,
                                       0b11100000 };
                            }
                          }
                        }
                      }
                    }
                  }
                }
                case '4': {
                  switch( isProgress ) {
                    case false: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00001110,
                                       0b00010110,
                                       0b00100110,
                                       0b01100110,
                                       0b01100110,
                                       0b01111110,
                                       0b00000110,
                                       0b00000110 };
                            }
                            case false: {
                              return { 0b00001100,
                                       0b00010100,
                                       0b00100100,
                                       0b01000100,
                                       0b01000100,
                                       0b01111110,
                                       0b00000100,
                                       0b00000100 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00110000,
                                       0b01110000,
                                       0b10110000,
                                       0b10110000,
                                       0b10110000,
                                       0b11110000,
                                       0b00110000,
                                       0b00110000 };
                            }
                            case false: {
                              return { 0b00110000,
                                       0b01010000,
                                       0b10010000,
                                       0b10010000,
                                       0b10010000,
                                       0b11110000,
                                       0b00010000,
                                       0b00010000 };
                            }
                          }
                        }
                      }
                    }
                    case true: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00001110,
                                       0b00010110,
                                       0b00100110,
                                       0b01100110,
                                       0b01111110,
                                       0b00000110 };
                            }
                            case false: {
                              return { 0b00001100,
                                       0b00010100,
                                       0b00100100,
                                       0b01000100,
                                       0b01111110,
                                       0b00000100 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00110000,
                                       0b01110000,
                                       0b10110000,
                                       0b10110000,
                                       0b11110000,
                                       0b00110000 };
                            }
                            case false: {
                              return { 0b00110000,
                                       0b01010000,
                                       0b10010000,
                                       0b10010000,
                                       0b11110000,
                                       0b00010000 };
                            }
                          }
                        }
                      }
                    }
                  }
                }
                case '5': {
                  switch( isProgress ) {
                    case false: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01111110,
                                       0b01100000,
                                       0b01100000,
                                       0b01111100,
                                       0b00000110,
                                       0b00000110,
                                       0b01100110,
                                       0b00111100 };
                            }
                            case false: {
                              return { 0b01111110,
                                       0b01000000,
                                       0b01000000,
                                       0b01111100,
                                       0b00000010,
                                       0b00000010,
                                       0b01000010,
                                       0b00111100 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b11110000,
                                       0b10000000,
                                       0b10000000,
                                       0b11100000,
                                       0b00110000,
                                       0b00110000,
                                       0b00110000,
                                       0b11100000 };
                            }
                            case false: {
                              return { 0b11110000,
                                       0b10000000,
                                       0b10000000,
                                       0b11100000,
                                       0b00010000,
                                       0b00010000,
                                       0b00010000,
                                       0b11100000 };
                            }
                          }
                        }
                      }
                    }
                    case true: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01111110,
                                       0b01100000,
                                       0b01111100,
                                       0b00000110,
                                       0b01100110,
                                       0b00111100 };
                            }
                            case false: {
                              return { 0b01111110,
                                       0b01000000,
                                       0b01111100,
                                       0b00000010,
                                       0b01000010,
                                       0b00111100 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b11110000,
                                       0b10000000,
                                       0b11100000,
                                       0b00110000,
                                       0b00110000,
                                       0b11100000 };
                            }
                            case false: {
                              return { 0b11110000,
                                       0b10000000,
                                       0b11100000,
                                       0b00010000,
                                       0b00010000,
                                       0b11100000 };
                            }
                          }
                        }
                      }
                    }
                  }
                }
                case '6': {
                  switch( isProgress ) {
                    case false: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00011100,
                                       0b00110000,
                                       0b01100000,
                                       0b01111100,
                                       0b01100110,
                                       0b01100110,
                                       0b01100110,
                                       0b00111100 };
                            }
                            case false: {
                              return { 0b00011100,
                                       0b00100000,
                                       0b01000000,
                                       0b01111100,
                                       0b01000010,
                                       0b01000010,
                                       0b01000010,
                                       0b00111100 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01110000,
                                       0b11000000,
                                       0b11000000,
                                       0b11100000,
                                       0b11010000,
                                       0b11010000,
                                       0b11010000,
                                       0b01100000 };
                            }
                            case false: {
                              return { 0b01100000,
                                       0b10000000,
                                       0b10000000,
                                       0b11100000,
                                       0b10010000,
                                       0b10010000,
                                       0b10010000,
                                       0b01100000 };
                            }
                          }
                        }
                      }
                    }
                    case true: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00111100,
                                       0b01100000,
                                       0b01111100,
                                       0b01100110,
                                       0b01100110,
                                       0b00111100 };
                            }
                            case false: {
                              return { 0b00111100,
                                       0b01000000,
                                       0b01111100,
                                       0b01000010,
                                       0b01000010,
                                       0b00111100 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01110000,
                                       0b11000000,
                                       0b11100000,
                                       0b11010000,
                                       0b11010000,
                                       0b01100000 };
                            }
                            case false: {
                              return { 0b01100000,
                                       0b10000000,
                                       0b11100000,
                                       0b10010000,
                                       0b10010000,
                                       0b01100000 };
                            }
                          }
                        }
                      }
                    }
                  }
                }
                case '7': {
                  switch( isProgress ) {
                    case false: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01111110,
                                       0b01100110,
                                       0b00000110,
                                       0b00001100,
                                       0b00001100,
                                       0b00011000,
                                       0b00011000,
                                       0b00011000 };
                            }
                            case false: {
                              return { 0b01111110,
                                       0b01000010,
                                       0b00000100,
                                       0b00001000,
                                       0b00001000,
                                       0b00010000,
                                       0b00010000,
                                       0b00010000 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b11110000,
                                       0b00110000,
                                       0b00110000,
                                       0b01100000,
                                       0b01100000,
                                       0b11000000,
                                       0b11000000,
                                       0b11000000 };
                            }
                            case false: {
                              return { 0b11110000,
                                       0b00010000,
                                       0b00010000,
                                       0b00100000,
                                       0b00100000,
                                       0b01000000,
                                       0b01000000,
                                       0b01000000 };
                            }
                          }
                        }
                      }
                    }
                    case true: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01111110,
                                       0b01000110,
                                       0b00001100,
                                       0b00001100,
                                       0b00011000,
                                       0b00011000 };
                            }
                            case false: {
                              return { 0b01111110,
                                       0b01000010,
                                       0b00000100,
                                       0b00001000,
                                       0b00010000,
                                       0b00010000 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b11110000,
                                       0b00110000,
                                       0b00110000,
                                       0b01100000,
                                       0b01100000,
                                       0b01100000 };
                            }
                            case false: {
                              return { 0b11110000,
                                       0b00010000,
                                       0b00100000,
                                       0b00100000,
                                       0b01000000,
                                       0b01000000 };
                            }
                          }
                        }
                      }
                    }
                  }
                }
                case '8': {
                  switch( isProgress ) {
                    case false: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00111100,
                                       0b01100110,
                                       0b01100110,
                                       0b00111100,
                                       0b01100110,
                                       0b01100110,
                                       0b01100110,
                                       0b00111100 };
                            }
                            case false: {
                              return { 0b00111100,
                                       0b01000010,
                                       0b01000010,
                                       0b00111100,
                                       0b01000010,
                                       0b01000010,
                                       0b01000010,
                                       0b00111100 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01100000,
                                       0b10110000,
                                       0b10110000,
                                       0b01100000,
                                       0b10110000,
                                       0b10110000,
                                       0b10110000,
                                       0b01100000 };
                            }
                            case false: {
                              return { 0b01100000,
                                       0b10010000,
                                       0b10010000,
                                       0b01100000,
                                       0b10010000,
                                       0b10010000,
                                       0b10010000,
                                       0b01100000 };
                            }
                          }
                        }
                      }
                    }
                    case true: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00111100,
                                       0b01100110,
                                       0b00111100,
                                       0b01100110,
                                       0b01100110,
                                       0b00111100 };
                            }
                            case false: {
                              return { 0b00111100,
                                       0b01000010,
                                       0b00111100,
                                       0b01000010,
                                       0b01000010,
                                       0b00111100 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01100000,
                                       0b10110000,
                                       0b01100000,
                                       0b10110000,
                                       0b10110000,
                                       0b01100000 };
                            }
                            case false: {
                              return { 0b01100000,
                                       0b10010000,
                                       0b01100000,
                                       0b10010000,
                                       0b10010000,
                                       0b01100000 };
                            }
                          }
                        }
                      }
                    }
                  }
                }
                case '9': {
                  switch( isProgress ) {
                    case false: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00111100,
                                       0b01100110,
                                       0b01100110,
                                       0b01100110,
                                       0b00111110,
                                       0b00000110,
                                       0b00001100,
                                       0b00111000 };
                            }
                            case false: {
                              return { 0b00111100,
                                       0b01000010,
                                       0b01000010,
                                       0b01000010,
                                       0b00111110,
                                       0b00000010,
                                       0b00000100,
                                       0b00111000 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01100000,
                                       0b10110000,
                                       0b10110000,
                                       0b10110000,
                                       0b01110000,
                                       0b00110000,
                                       0b00110000,
                                       0b11100000 };
                            }
                            case false: {
                              return { 0b01100000,
                                       0b10010000,
                                       0b10010000,
                                       0b10010000,
                                       0b01110000,
                                       0b00010000,
                                       0b00010000,
                                       0b01100000 };
                            }
                          }
                        }
                      }
                    }
                    case true: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00111100,
                                       0b01100110,
                                       0b01100110,
                                       0b00111110,
                                       0b00000110,
                                       0b00111100 };
                            }
                            case false: {
                              return { 0b00111100,
                                       0b01000010,
                                       0b01000010,
                                       0b00111110,
                                       0b00000010,
                                       0b00111100 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01100000,
                                       0b10110000,
                                       0b10110000,
                                       0b01110000,
                                       0b00110000,
                                       0b11100000 };
                            }
                            case false: {
                              return { 0b01100000,
                                       0b10010000,
                                       0b10010000,
                                       0b01110000,
                                       0b00010000,
                                       0b01100000 };
                            }
                          }
                        }
                      }
                    }
                  }
                }
                case '0': {
                  switch( isProgress ) {
                    case false: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00111100,
                                       0b01100110,
                                       0b01100110,
                                       0b01100110,
                                       0b01100110,
                                       0b01100110,
                                       0b01100110,
                                       0b00111100 };
                            }
                            case false: {
                              return { 0b00111100,
                                       0b01000010,
                                       0b01000010,
                                       0b01000010,
                                       0b01000010,
                                       0b01000010,
                                       0b01000010,
                                       0b00111100 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01100000,
                                       0b10110000,
                                       0b10110000,
                                       0b10110000,
                                       0b10110000,
                                       0b10110000,
                                       0b10110000,
                                       0b01100000 };
                            }
                            case false: {
                              return { 0b01100000,
                                       0b10010000,
                                       0b10010000,
                                       0b10010000,
                                       0b10010000,
                                       0b10010000,
                                       0b10010000,
                                       0b01100000 };
                            }
                          }
                        }
                      }
                    }
                    case true: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00111100,
                                       0b01100110,
                                       0b01100110,
                                       0b01100110,
                                       0b01100110,
                                       0b00111100 };
                            }
                            case false: {
                              return { 0b00111100,
                                       0b01000010,
                                       0b01000010,
                                       0b01000010,
                                       0b01000010,
                                       0b00111100 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01100000,
                                       0b10110000,
                                       0b10110000,
                                       0b10110000,
                                       0b10110000,
                                       0b01100000 };
                            }
                            case false: {
                              return { 0b01100000,
                                       0b10010000,
                                       0b10010000,
                                       0b10010000,
                                       0b10010000,
                                       0b01100000 };
                            }
                          }
                        }
                      }
                    }
                  }
                }
                case '-': {
                  switch( isProgress ) {
                    case false: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00111100,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00111100,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b01100000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b01100000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                          }
                        }
                      }
                    }
                    case true: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00111100,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00111100,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b01100000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b01100000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                          }
                        }
                      }
                    }
                  }
                }
                case ':': {
                  switch( isProgress ) {
                    case false: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00000000,
                                       0b00100000,
                                       0b00100000,
                                       0b00000000,
                                       0b00000000,
                                       0b00100000,
                                       0b00100000,
                                       0b00000000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00100000,
                                       0b00000000,
                                       0b00000000,
                                       0b00100000,
                                       0b00000000,
                                       0b00000000 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00000000,
                                       0b01000000,
                                       0b01000000,
                                       0b00000000,
                                       0b00000000,
                                       0b01000000,
                                       0b01000000,
                                       0b00000000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b01000000,
                                       0b00000000,
                                       0b00000000,
                                       0b01000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                          }
                        }
                      }
                    }
                    case true: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00100000,
                                       0b00100000,
                                       0b00000000,
                                       0b00000000,
                                       0b00100000,
                                       0b00100000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b00100000,
                                       0b00000000,
                                       0b00000000,
                                       0b00100000,
                                       0b00000000 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01000000,
                                       0b01000000,
                                       0b00000000,
                                       0b00000000,
                                       0b01000000,
                                       0b01000000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b01000000,
                                       0b00000000,
                                       0b00000000,
                                       0b01000000,
                                       0b00000000 };
                            }
                          }
                        }
                      }
                    }
                  }
                }
                case '\b': {
                  switch( isProgress ) {
                    case false: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00100000,
                                       0b00100000,
                                       0b00000000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00100000,
                                       0b00000000,
                                       0b00000000 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b01000000,
                                       0b01000000,
                                       0b00000000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b01000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                          }
                        }
                      }
                    }
                    case true: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00100000,
                                       0b00100000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00100000,
                                       0b00000000 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b01000000,
                                       0b01000000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b01000000,
                                       0b00000000 };
                            }
                          }
                        }
                      }
                    }
                  }
                }
                case '\f': {
                  switch( isProgress ) {
                    case false: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00000000,
                                       0b00100000,
                                       0b00100000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00100000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00000000,
                                       0b01000000,
                                       0b01000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b01000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                          }
                        }
                      }
                    }
                    case true: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00100000,
                                       0b00100000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b00100000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01000000,
                                       0b01000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b01000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            case true: {
              switch( symbol ) {
                case '1': {
                  switch( isProgress ) {
                    case false: {
                      return { 0b00100000,
                               0b01100000,
                               0b00100000,
                               0b00100000,
                               0b00100000,
                               0b00100000 };
                    }
                    case true: {
                      return { 0b00100000,
                               0b01100000,
                               0b00100000,
                               0b00100000,
                               0b00100000 };
                    }
                  }
                }
                case '2': {
                  switch( isProgress ) {
                    case false: {
                      return { 0b00110000,
                               0b01010000,
                               0b00010000,
                               0b00100000,
                               0b01000000,
                               0b01110000 };
                    }
                    case true: {
                      return { 0b01100000,
                               0b00010000,
                               0b00100000,
                               0b01000000,
                               0b01110000 };
                    }
                  }
                }
                case '3': {
                  switch( isProgress ) {
                    case false: {
                      return { 0b01110000,
                               0b00010000,
                               0b00100000,
                               0b00010000,
                               0b00010000,
                               0b01100000 };
                    }
                    case true: {
                      return { 0b01110000,
                               0b00010000,
                               0b00110000,
                               0b00010000,
                               0b01100000 };
                    }
                  }
                }
                case '4': {
                  switch( isProgress ) {
                    case false: {
                      return { 0b00010000,
                               0b00110000,
                               0b01010000,
                               0b01010000,
                               0b01110000,
                               0b00010000 };
                    }
                    case true: {
                      return { 0b00010000,
                               0b00110000,
                               0b01010000,
                               0b01110000,
                               0b00010000 };
                    }
                  }
                }
                case '5': {
                  switch( isProgress ) {
                    case false: {
                      return { 0b01110000,
                               0b01000000,
                               0b01110000,
                               0b00010000,
                               0b00010000,
                               0b01100000 };
                    }
                    case true: {
                      return { 0b01110000,
                               0b01000000,
                               0b01110000,
                               0b00010000,
                               0b01100000 };
                    }
                  }
                }
                case '6': {
                  switch( isProgress ) {
                    case false: {
                      return { 0b00110000,
                               0b01000000,
                               0b01110000,
                               0b01010000,
                               0b01010000,
                               0b01100000 };
                    }
                    case true: {
                      return { 0b00110000,
                               0b01000000,
                               0b01110000,
                               0b01010000,
                               0b01100000 };
                    }
                  }
                }
                case '7': {
                  switch( isProgress ) {
                    case false: {
                      return { 0b01110000,
                               0b00010000,
                               0b00010000,
                               0b00100000,
                               0b00100000,
                               0b00100000 };
                    }
                    case true: {
                      return { 0b01110000,
                               0b00010000,
                               0b00100000,
                               0b00100000,
                               0b00100000 };
                    }
                  }
                }
                case '8': {
                  switch( isProgress ) {
                    case false: {
                      return { 0b00110000,
                               0b01010000,
                               0b00100000,
                               0b01010000,
                               0b01010000,
                               0b01100000 };
                    }
                    case true: {
                      return { 0b00110000,
                               0b01010000,
                               0b00100000,
                               0b01010000,
                               0b01100000 };
                    }
                  }
                }
                case '9': {
                  switch( isProgress ) {
                    case false: {
                      return { 0b00110000,
                               0b01010000,
                               0b01010000,
                               0b01110000,
                               0b00010000,
                               0b01100000 };
                    }
                    case true: {
                      return { 0b00110000,
                               0b01010000,
                               0b01110000,
                               0b00010000,
                               0b01100000 };
                    }
                  }
                }
                case '0': {
                  switch( isProgress ) {
                    case false: {
                      return { 0b00110000,
                               0b01010000,
                               0b01010000,
                               0b01010000,
                               0b01010000,
                               0b01100000 };
                    }
                    case true: {
                      return { 0b00110000,
                               0b01010000,
                               0b01010000,
                               0b01010000,
                               0b01100000 };
                    }
                  }
                }
                case '-': {
                  switch( isProgress ) {
                    case false: {
                      return { 0b00000000,
                               0b00000000,
                               0b01110000,
                               0b00000000,
                               0b00000000,
                               0b00000000 };
                    }
                    case true: {
                      return { 0b00000000,
                               0b00000000,
                               0b01110000,
                               0b00000000,
                               0b00000000 };
                    }
                  }
                }
              }
            }
          }
        }
        case 1: {
          switch( isSmall ) {
            case false: {
              switch( symbol ) {
                case '1': {
                  switch( isProgress ) {
                    case false: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00011000,
                                       0b00111000,
                                       0b00011000,
                                       0b00011000,
                                       0b00011000,
                                       0b00011000,
                                       0b00011000,
                                       0b00011000 };
                            }
                            case false: {
                              return { 0b00001000,
                                       0b00011000,
                                       0b00001000,
                                       0b00001000,
                                       0b00001000,
                                       0b00001000,
                                       0b00001000,
                                       0b00001000 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01100000,
                                       0b11100000,
                                       0b01100000,
                                       0b01100000,
                                       0b01100000,
                                       0b01100000,
                                       0b01100000,
                                       0b01100000 };
                            }
                            case false: {
                              return { 0b00100000,
                                       0b01100000,
                                       0b00100000,
                                       0b00100000,
                                       0b00100000,
                                       0b00100000,
                                       0b00100000,
                                       0b00100000 };
                            }
                          }
                        }
                      }
                    }
                    case true: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00011000,
                                       0b00111000,
                                       0b00011000,
                                       0b00011000,
                                       0b00011000,
                                       0b00011000 };
                            }
                            case false: {
                              return { 0b00001000,
                                       0b00011000,
                                       0b00001000,
                                       0b00001000,
                                       0b00001000,
                                       0b00001000 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01100000,
                                       0b11100000,
                                       0b01100000,
                                       0b01100000,
                                       0b01100000,
                                       0b01100000 };
                            }
                            case false: {
                              return { 0b00100000,
                                       0b01100000,
                                       0b00100000,
                                       0b00100000,
                                       0b00100000,
                                       0b00100000 };
                            }
                          }
                        }
                      }
                    }
                  }
                }
                case '2': {
                  switch( isProgress ) {
                    case false: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01111110,
                                       0b00000110,
                                       0b00000110,
                                       0b01111110,
                                       0b01100000,
                                       0b01100000,
                                       0b01100000,
                                       0b01111110 };
                            }
                            case false: {
                              return { 0b01111110,
                                       0b00000010,
                                       0b00000010,
                                       0b01111110,
                                       0b01000000,
                                       0b01000000,
                                       0b01000000,
                                       0b01111110 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b11110000,
                                       0b00110000,
                                       0b00110000,
                                       0b11110000,
                                       0b11000000,
                                       0b11000000,
                                       0b11000000,
                                       0b11110000 };
                            }
                            case false: {
                              return { 0b11110000,
                                       0b00010000,
                                       0b00010000,
                                       0b11110000,
                                       0b10000000,
                                       0b10000000,
                                       0b10000000,
                                       0b11110000 };
                            }
                          }
                        }
                      }
                    }
                    case true: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01111110,
                                       0b00000110,
                                       0b01111110,
                                       0b01100000,
                                       0b01100000,
                                       0b01111110 };
                            }
                            case false: {
                              return { 0b01111110,
                                       0b00000010,
                                       0b01111110,
                                       0b01000000,
                                       0b01000000,
                                       0b01111110 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b11110000,
                                       0b00110000,
                                       0b11110000,
                                       0b11000000,
                                       0b11000000,
                                       0b11110000 };
                            }
                            case false: {
                              return { 0b11110000,
                                       0b00010000,
                                       0b11110000,
                                       0b10000000,
                                       0b10000000,
                                       0b11110000 };
                            }
                          }
                        }
                      }
                    }
                  }
                }
                case '3': {
                  switch( isProgress ) {
                    case false: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01111110,
                                       0b00000110,
                                       0b00000110,
                                       0b00111110,
                                       0b00000110,
                                       0b00000110,
                                       0b00000110,
                                       0b01111110 };
                            }
                            case false: {
                              return { 0b01111110,
                                       0b00000010,
                                       0b00000010,
                                       0b00111110,
                                       0b00000010,
                                       0b00000010,
                                       0b00000010,
                                       0b01111110 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b11110000,
                                       0b00110000,
                                       0b00110000,
                                       0b11110000,
                                       0b00110000,
                                       0b00110000,
                                       0b00110000,
                                       0b11110000 };
                            }
                            case false: {
                              return { 0b11110000,
                                       0b00010000,
                                       0b00010000,
                                       0b01110000,
                                       0b00010000,
                                       0b00010000,
                                       0b00010000,
                                       0b11110000 };
                            }
                          }
                        }
                      }
                    }
                    case true: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01111110,
                                       0b00000110,
                                       0b00111110,
                                       0b00000110,
                                       0b00000110,
                                       0b01111110 };
                            }
                            case false: {
                              return { 0b01111110,
                                       0b00000010,
                                       0b00111110,
                                       0b00000010,
                                       0b00000010,
                                       0b01111110 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b11110000,
                                       0b00110000,
                                       0b11110000,
                                       0b00110000,
                                       0b00110000,
                                       0b11110000 };
                            }
                            case false: {
                              return { 0b11110000,
                                       0b00010000,
                                       0b01110000,
                                       0b00010000,
                                       0b00010000,
                                       0b11110000 };
                            }
                          }
                        }
                      }
                    }
                  }
                }
                case '4': {
                  switch( isProgress ) {
                    case false: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01100110,
                                       0b01100110,
                                       0b01100110,
                                       0b01100110,
                                       0b01111110,
                                       0b00000110,
                                       0b00000110,
                                       0b00000110 };
                            }
                            case false: {
                              return { 0b01000010,
                                       0b01000010,
                                       0b01000010,
                                       0b01000010,
                                       0b01111110,
                                       0b00000010,
                                       0b00000010,
                                       0b00000010 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b10110000,
                                       0b10110000,
                                       0b10110000,
                                       0b10110000,
                                       0b11110000,
                                       0b00110000,
                                       0b00110000,
                                       0b00110000 };
                            }
                            case false: {
                              return { 0b10010000,
                                       0b10010000,
                                       0b10010000,
                                       0b10010000,
                                       0b11110000,
                                       0b00010000,
                                       0b00010000,
                                       0b00010000 };
                            }
                          }
                        }
                      }
                    }
                    case true: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01100110,
                                       0b01100110,
                                       0b01100110,
                                       0b01111110,
                                       0b00000110,
                                       0b00000110 };
                            }
                            case false: {
                              return { 0b01000010,
                                       0b01000010,
                                       0b01000010,
                                       0b01111110,
                                       0b00000010,
                                       0b00000010 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b10110000,
                                       0b10110000,
                                       0b10110000,
                                       0b11110000,
                                       0b00110000,
                                       0b00110000 };
                            }
                            case false: {
                              return { 0b10010000,
                                       0b10010000,
                                       0b10010000,
                                       0b11110000,
                                       0b00010000,
                                       0b00010000 };
                            }
                          }
                        }
                      }
                    }
                  }
                }
                case '5': {
                  switch( isProgress ) {
                    case false: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01111110,
                                       0b01100000,
                                       0b01100000,
                                       0b01111110,
                                       0b00000110,
                                       0b00000110,
                                       0b00000110,
                                       0b01111110 };
                            }
                            case false: {
                              return { 0b01111110,
                                       0b01000000,
                                       0b01000000,
                                       0b01111110,
                                       0b00000010,
                                       0b00000010,
                                       0b00000010,
                                       0b01111110 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b11110000,
                                       0b11000000,
                                       0b11000000,
                                       0b11110000,
                                       0b00110000,
                                       0b00110000,
                                       0b00110000,
                                       0b11110000 };
                            }
                            case false: {
                              return { 0b11110000,
                                       0b10000000,
                                       0b10000000,
                                       0b11110000,
                                       0b00010000,
                                       0b00010000,
                                       0b00010000,
                                       0b11110000 };
                            }
                          }
                        }
                      }
                    }
                    case true: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01111110,
                                       0b01100000,
                                       0b01111110,
                                       0b00000110,
                                       0b00000110,
                                       0b01111110 };
                            }
                            case false: {
                              return { 0b01111110,
                                       0b01000000,
                                       0b01111110,
                                       0b00000010,
                                       0b00000010,
                                       0b01111110 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b11110000,
                                       0b11000000,
                                       0b11110000,
                                       0b00110000,
                                       0b00110000,
                                       0b11110000 };
                            }
                            case false: {
                              return { 0b11110000,
                                       0b10000000,
                                       0b11110000,
                                       0b00010000,
                                       0b00010000,
                                       0b11110000 };
                            }
                          }
                        }
                      }
                    }
                  }
                }
                case '6': {
                  switch( isProgress ) {
                    case false: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01111110,
                                       0b01100000,
                                       0b01100000,
                                       0b01111110,
                                       0b01100110,
                                       0b01100110,
                                       0b01100110,
                                       0b01111110 };
                            }
                            case false: {
                              return { 0b01111110,
                                       0b01000000,
                                       0b01000000,
                                       0b01111110,
                                       0b01000010,
                                       0b01000010,
                                       0b01000010,
                                       0b01111110 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b11110000,
                                       0b11000000,
                                       0b11000000,
                                       0b11110000,
                                       0b11010000,
                                       0b11010000,
                                       0b11010000,
                                       0b11110000 };
                            }
                            case false: {
                              return { 0b11110000,
                                       0b10000000,
                                       0b10000000,
                                       0b11110000,
                                       0b10010000,
                                       0b10010000,
                                       0b10010000,
                                       0b11110000 };
                            }
                          }
                        }
                      }
                    }
                    case true: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01111110,
                                       0b01100000,
                                       0b01111110,
                                       0b01100110,
                                       0b01100110,
                                       0b01111110 };
                            }
                            case false: {
                              return { 0b01111110,
                                       0b01000000,
                                       0b01111110,
                                       0b01000010,
                                       0b01000010,
                                       0b01111110 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b11110000,
                                       0b11000000,
                                       0b11110000,
                                       0b11010000,
                                       0b11010000,
                                       0b11110000 };
                            }
                            case false: {
                              return { 0b11110000,
                                       0b10000000,
                                       0b11110000,
                                       0b10010000,
                                       0b10010000,
                                       0b11110000 };
                            }
                          }
                        }
                      }
                    }
                  }
                }
                case '7': {
                  switch( isProgress ) {
                    case false: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01111110,
                                       0b00000110,
                                       0b00000110,
                                       0b00000110,
                                       0b00000110,
                                       0b00000110,
                                       0b00000110,
                                       0b00000110 };
                            }
                            case false: {
                              return { 0b01111110,
                                       0b00000010,
                                       0b00000010,
                                       0b00000010,
                                       0b00000010,
                                       0b00000010,
                                       0b00000010,
                                       0b00000010 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b11110000,
                                       0b00110000,
                                       0b00110000,
                                       0b00110000,
                                       0b00110000,
                                       0b00110000,
                                       0b00110000,
                                       0b00110000 };
                            }
                            case false: {
                              return { 0b11110000,
                                       0b00010000,
                                       0b00010000,
                                       0b00010000,
                                       0b00010000,
                                       0b00010000,
                                       0b00010000,
                                       0b00010000 };
                            }
                          }
                        }
                      }
                    }
                    case true: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01111110,
                                       0b00000110,
                                       0b00000110,
                                       0b00000110,
                                       0b00000110,
                                       0b00000110 };
                            }
                            case false: {
                              return { 0b01111110,
                                       0b00000010,
                                       0b00000010,
                                       0b00000010,
                                       0b00000010,
                                       0b00000010 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b11110000,
                                       0b00110000,
                                       0b00110000,
                                       0b00110000,
                                       0b00110000,
                                       0b00110000 };
                            }
                            case false: {
                              return { 0b11110000,
                                       0b00010000,
                                       0b00010000,
                                       0b00010000,
                                       0b00010000,
                                       0b00010000 };
                            }
                          }
                        }
                      }
                    }
                  }
                }
                case '8': {
                  switch( isProgress ) {
                    case false: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01111110,
                                       0b01100110,
                                       0b01100110,
                                       0b01111110,
                                       0b01100110,
                                       0b01100110,
                                       0b01100110,
                                       0b01111110 };
                            }
                            case false: {
                              return { 0b01111110,
                                       0b01000010,
                                       0b01000010,
                                       0b01111110,
                                       0b01000010,
                                       0b01000010,
                                       0b01000010,
                                       0b01111110 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b11110000,
                                       0b10110000,
                                       0b10110000,
                                       0b11110000,
                                       0b10110000,
                                       0b10110000,
                                       0b10110000,
                                       0b11110000 };
                            }
                            case false: {
                              return { 0b11110000,
                                       0b10010000,
                                       0b10010000,
                                       0b11110000,
                                       0b10010000,
                                       0b10010000,
                                       0b10010000,
                                       0b11110000 };
                            }
                          }
                        }
                      }
                    }
                    case true: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01111110,
                                       0b01100110,
                                       0b01111110,
                                       0b01100110,
                                       0b01100110,
                                       0b01111110 };
                            }
                            case false: {
                              return { 0b01111110,
                                       0b01000010,
                                       0b01111110,
                                       0b01000010,
                                       0b01000010,
                                       0b01111110 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b11110000,
                                       0b10110000,
                                       0b11110000,
                                       0b10110000,
                                       0b10110000,
                                       0b11110000 };
                            }
                            case false: {
                              return { 0b11110000,
                                       0b10010000,
                                       0b11110000,
                                       0b10010000,
                                       0b10010000,
                                       0b11110000 };
                            }
                          }
                        }
                      }
                    }
                  }
                }
                case '9': {
                  switch( isProgress ) {
                    case false: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01111110,
                                       0b01100110,
                                       0b01100110,
                                       0b01100110,
                                       0b01111110,
                                       0b00000110,
                                       0b00000110,
                                       0b01111110 };
                            }
                            case false: {
                              return { 0b01111110,
                                       0b01000010,
                                       0b01000010,
                                       0b01000010,
                                       0b01111110,
                                       0b00000010,
                                       0b00000010,
                                       0b01111110 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b11110000,
                                       0b10110000,
                                       0b10110000,
                                       0b10110000,
                                       0b11110000,
                                       0b00110000,
                                       0b00110000,
                                       0b11110000 };
                            }
                            case false: {
                              return { 0b11110000,
                                       0b10010000,
                                       0b10010000,
                                       0b10010000,
                                       0b11110000,
                                       0b00010000,
                                       0b00010000,
                                       0b11110000 };
                            }
                          }
                        }
                      }
                    }
                    case true: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01111110,
                                       0b01100110,
                                       0b01100110,
                                       0b01111110,
                                       0b00000110,
                                       0b01111110 };
                            }
                            case false: {
                              return { 0b01111110,
                                       0b01000010,
                                       0b01000010,
                                       0b01111110,
                                       0b00000010,
                                       0b01111110 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b11110000,
                                       0b10110000,
                                       0b10110000,
                                       0b11110000,
                                       0b00110000,
                                       0b11110000 };
                            }
                            case false: {
                              return { 0b11110000,
                                       0b10010000,
                                       0b10010000,
                                       0b11110000,
                                       0b00010000,
                                       0b11110000 };
                            }
                          }
                        }
                      }
                    }
                  }
                }
                case '0': {
                  switch( isProgress ) {
                    case false: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01111110,
                                       0b01100110,
                                       0b01100110,
                                       0b01100110,
                                       0b01100110,
                                       0b01100110,
                                       0b01100110,
                                       0b01111110 };
                            }
                            case false: {
                              return { 0b01111110,
                                       0b01000010,
                                       0b01000010,
                                       0b01000010,
                                       0b01000010,
                                       0b01000010,
                                       0b01000010,
                                       0b01111110 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b11110000,
                                       0b10110000,
                                       0b10110000,
                                       0b10110000,
                                       0b10110000,
                                       0b10110000,
                                       0b10110000,
                                       0b11110000 };
                            }
                            case false: {
                              return { 0b11110000,
                                       0b10010000,
                                       0b10010000,
                                       0b10010000,
                                       0b10010000,
                                       0b10010000,
                                       0b10010000,
                                       0b11110000 };
                            }
                          }
                        }
                      }
                    }
                    case true: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01111110,
                                       0b01100110,
                                       0b01100110,
                                       0b01100110,
                                       0b01100110,
                                       0b01111110 };
                            }
                            case false: {
                              return { 0b01111110,
                                       0b01000010,
                                       0b01000010,
                                       0b01000010,
                                       0b01000010,
                                       0b01111110 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b11110000,
                                       0b10110000,
                                       0b10110000,
                                       0b10110000,
                                       0b10110000,
                                       0b11110000 };
                            }
                            case false: {
                              return { 0b11110000,
                                       0b10010000,
                                       0b10010000,
                                       0b10010000,
                                       0b10010000,
                                       0b11110000 };
                            }
                          }
                        }
                      }
                    }
                  }
                }
                case '-': {
                  switch( isProgress ) {
                    case false: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00111100,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00111100,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b01100000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b01100000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                          }
                        }
                      }
                    }
                    case true: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00111100,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00111100,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b01100000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b01100000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                          }
                        }
                      }
                    }
                  }
                }
                case ':': {
                  switch( isProgress ) {
                    case false: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00000000,
                                       0b00100000,
                                       0b00100000,
                                       0b00000000,
                                       0b00000000,
                                       0b00100000,
                                       0b00100000,
                                       0b00000000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00100000,
                                       0b00000000,
                                       0b00000000,
                                       0b00100000,
                                       0b00000000,
                                       0b00000000 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00000000,
                                       0b01000000,
                                       0b01000000,
                                       0b00000000,
                                       0b00000000,
                                       0b01000000,
                                       0b01000000,
                                       0b00000000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b01000000,
                                       0b00000000,
                                       0b00000000,
                                       0b01000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                          }
                        }
                      }
                    }
                    case true: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00100000,
                                       0b00100000,
                                       0b00000000,
                                       0b00000000,
                                       0b00100000,
                                       0b00100000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b00100000,
                                       0b00000000,
                                       0b00000000,
                                       0b00100000,
                                       0b00000000 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01000000,
                                       0b01000000,
                                       0b00000000,
                                       0b00000000,
                                       0b01000000,
                                       0b01000000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b01000000,
                                       0b00000000,
                                       0b00000000,
                                       0b01000000,
                                       0b00000000 };
                            }
                          }
                        }
                      }
                    }
                  }
                }
                case '\b': {
                  switch( isProgress ) {
                    case false: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00100000,
                                       0b00100000,
                                       0b00000000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00100000,
                                       0b00000000,
                                       0b00000000 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b01000000,
                                       0b01000000,
                                       0b00000000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b01000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                          }
                        }
                      }
                    }
                    case true: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00100000,
                                       0b00100000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00100000,
                                       0b00000000 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b01000000,
                                       0b01000000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b01000000,
                                       0b00000000 };
                            }
                          }
                        }
                      }
                    }
                  }
                }
                case '\f': {
                  switch( isProgress ) {
                    case false: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00000000,
                                       0b00100000,
                                       0b00100000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b00100000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00000000,
                                       0b01000000,
                                       0b01000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b00000000,
                                       0b01000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                          }
                        }
                      }
                    }
                    case true: {
                      switch( isWide ) {
                        case true: {
                          switch( isBold ) {
                            case true: {
                              return { 0b00100000,
                                       0b00100000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b00100000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                          }
                        }
                        case false: {
                          switch( isBold ) {
                            case true: {
                              return { 0b01000000,
                                       0b01000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                            case false: {
                              return { 0b00000000,
                                       0b01000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000,
                                       0b00000000 };
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            case true: {
              switch( symbol ) {
                case '1': {
                  switch( isProgress ) {
                    case false: {
                      return { 0b00010000,
                               0b00110000,
                               0b00010000,
                               0b00010000,
                               0b00010000,
                               0b00010000 };
                    }
                    case true: {
                      return { 0b00010000,
                               0b00110000,
                               0b00010000,
                               0b00010000,
                               0b00010000 };
                    }
                  }
                }
                case '2': {
                  switch( isProgress ) {
                    case false: {
                      return { 0b01110000,
                               0b00010000,
                               0b01110000,
                               0b01000000,
                               0b01000000,
                               0b01110000 };
                    }
                    case true: {
                      return { 0b01110000,
                               0b00010000,
                               0b01110000,
                               0b01000000,
                               0b01110000 };
                    }
                  }
                }
                case '3': {
                  switch( isProgress ) {
                    case false: {
                      return { 0b01110000,
                               0b00010000,
                               0b00110000,
                               0b00010000,
                               0b00010000,
                               0b01110000 };
                    }
                    case true: {
                      return { 0b01110000,
                               0b00010000,
                               0b00110000,
                               0b00010000,
                               0b01110000 };
                    }
                  }
                }
                case '4': {
                  switch( isProgress ) {
                    case false: {
                      return { 0b01010000,
                               0b01010000,
                               0b01010000,
                               0b01110000,
                               0b00010000,
                               0b00010000 };
                    }
                    case true: {
                      return { 0b01010000,
                               0b01010000,
                               0b01110000,
                               0b00010000,
                               0b00010000 };
                    }
                  }
                }
                case '5': {
                  switch( isProgress ) {
                    case false: {
                      return { 0b01110000,
                               0b01000000,
                               0b01110000,
                               0b00010000,
                               0b00010000,
                               0b01110000 };
                    }
                    case true: {
                      return { 0b01110000,
                               0b01000000,
                               0b01110000,
                               0b00010000,
                               0b01110000 };
                    }
                  }
                }
                case '6': {
                  switch( isProgress ) {
                    case false: {
                      return { 0b01110000,
                               0b01000000,
                               0b01110000,
                               0b01010000,
                               0b01010000,
                               0b01110000 };
                    }
                    case true: {
                      return { 0b01110000,
                               0b01000000,
                               0b01110000,
                               0b01010000,
                               0b01110000 };
                    }
                  }
                }
                case '7': {
                  switch( isProgress ) {
                    case false: {
                      return { 0b01110000,
                               0b00010000,
                               0b00010000,
                               0b00010000,
                               0b00010000,
                               0b00010000 };
                    }
                    case true: {
                      return { 0b01110000,
                               0b00010000,
                               0b00010000,
                               0b00010000,
                               0b00010000 };
                    }
                  }
                }
                case '8': {
                  switch( isProgress ) {
                    case false: {
                      return { 0b01110000,
                               0b01010000,
                               0b01110000,
                               0b01010000,
                               0b01010000,
                               0b01110000 };
                    }
                    case true: {
                      return { 0b01110000,
                               0b01010000,
                               0b01110000,
                               0b01010000,
                               0b01110000 };
                    }
                  }
                }
                case '9': {
                  switch( isProgress ) {
                    case false: {
                      return { 0b01110000,
                               0b01010000,
                               0b01110000,
                               0b00010000,
                               0b00010000,
                               0b01110000 };
                    }
                    case true: {
                      return { 0b01110000,
                               0b01010000,
                               0b01110000,
                               0b00010000,
                               0b01110000 };
                    }
                  }
                }
                case '0': {
                  switch( isProgress ) {
                    case false: {
                      return { 0b01110000,
                               0b01010000,
                               0b01010000,
                               0b01010000,
                               0b01010000,
                               0b01110000 };
                    }
                    case true: {
                      return { 0b01110000,
                               0b01010000,
                               0b01010000,
                               0b01010000,
                               0b01110000 };
                    }
                  }
                }
                case '-': {
                  switch( isProgress ) {
                    case false: {
                      return { 0b00000000,
                               0b00000000,
                               0b01110000,
                               0b00000000,
                               0b00000000,
                               0b00000000 };
                    }
                    case true: {
                      return { 0b00000000,
                               0b00000000,
                               0b01110000,
                               0b00000000,
                               0b00000000 };
                    }
                  }
                }
              }
            }
          }
        }
      }
      return { 0, 0, 0, 0, 0, 0, 0, 0 };
    }

};
