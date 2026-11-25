#pragma once
// Bit buffers, file times and bounding boxes shared across modules

#include "D2Check.h"
#include "D2Structs.h"
#include "D2Win32Base.h"

struct D2BitBufferStrc;
struct D2BoundingBoxStrc;

struct D2BitBufferStrc
{
    unsigned char* pBuffer; // 0x00
    int nBits; // 0x04
    int nPos; // 0x08
    int nPosBits; // 0x0C
    int bFull; // 0x10
};

struct D2BoundingBoxStrc
{
    int nLeft; // 0x00
    int nBottom; // 0x04
    int nRight; // 0x08
    int nTop; // 0x0C
};

D2_CHECK_SIZE(D2BitBufferStrc, 0x14);
D2_CHECK_SIZE(D2FileTimeStrc, 0x8);
D2_CHECK_SIZE(D2BoundingBoxStrc, 0x10);
