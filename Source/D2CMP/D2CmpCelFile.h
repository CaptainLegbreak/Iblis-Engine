#pragma once
// D2CMP cel files (CelCmp*.cpp): one cel and the file that holds them.

struct D2CelBlockStrc;
struct D2CelStrc;

struct D2CelStrc
{
    int bFlip;                                              // 0x00
    int nWidth;                                             // 0x04
    int nHeight;                                            // 0x08
    int nXOffset;                                           // 0x0C
    int nYOffset;                                           // 0x10
    unsigned int nDataSize;                                 // 0x14
    D2CelBlockStrc* pBlockPixelData;                        // 0x18
    unsigned int nLength;                                   // 0x1C
    char data[1];                                           // 0x20
};

struct D2CelFileStrc
{
    int dwVersion;                                          // 0x00
    unsigned int dwFlags;                                   // 0x04
    int nFormat;                                            // 0x08
    int nTermination;                                       // 0x0C
    union
    {
        int nDirections;                                    // 0x10
        unsigned int nDirectionCount;
    };
    union
    {
        int nCelsPerDirection;                              // 0x14
        unsigned int nFrames;
    };
    D2CelStrc* pCels[1];                                    // 0x18
};
