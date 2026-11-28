#pragma once
// Graphics: the cel context (D2Gfx's D2GfxDataStrc) through which client code requests a unit's or an object's
// animation frames and D2Gfx draws them.

#include "D2Check.h"
#include "D2Structs.h"

struct D2CelStrc;
struct D2GfxDataStrc;

struct D2GfxDataStrc
{
    int nFrame; // 0x00
    unsigned char nFlags; // 0x04
    unsigned char nComponent; // 0x05
    unsigned short pad0x06; // 0x06
    int nUnitType; // 0x08
    int nUnitIndex; // 0x0C
    int nMode; // 0x10
    int nOverlay; // 0x14
    unsigned int dwUnitToken; // 0x18
    unsigned int dwComponentToken; // 0x1C
    unsigned int dwArmorType; // 0x20
    unsigned int dwModeToken; // 0x24
    unsigned int dwWClassToken; // 0x28
    const char* szName; // 0x2C
    int nFrames; // 0x30
    union
    {
        void* pCelFile; // 0x34
        int nArg34; // 0x34
    };
    int nDrawFlag; // 0x38
    D2CelStrc* pCel; // 0x3C
    int nDirection; // 0x40
    unsigned int dwFlags; // 0x44
};

D2_CHECK_SIZE(D2GfxDataStrc, 0x48);
