#pragma once
// Graphics: the cel context through which client code requests a unit's or an object's animation frames.

#include "D2Check.h"
#include "D2Structs.h"

struct D2CelStrc;
struct D2CelContextStrc;

struct D2CelContextStrc
{
    int nFrame; // 0x00
    unsigned char nFlags; // 0x04
    unsigned char nComponent; // 0x05
    unsigned short unk0x06; // 0x06
    int nType; // 0x08
    int nClass; // 0x0C
    int nMode; // 0x10
    int nOverlay; // 0x14
    int nArg18; // 0x18
    int nArg1C; // 0x1C
    unsigned int dwToken; // 0x20
    unsigned int dwModeToken; // 0x24
    unsigned int dwCode; // 0x28
    const char* szName; // 0x2C
    int nFrames; // 0x30
    union
    {
        void* pCellFile; // 0x34
        int nArg34; // 0x34
    };
    int unk0x38; // 0x38
    D2CelStrc* pCel; // 0x3C
    int nDirection; // 0x40
    int nFlags44; // 0x44
};

D2_CHECK_SIZE(D2CelContextStrc, 0x48);
