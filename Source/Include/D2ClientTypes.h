#pragma once
// Client: a unit's graphics data, inventory screen rectangles and window message handler entries.

#include "D2Check.h"
#include "D2Structs.h"

struct D2CelFileStrc;
struct D2CelStrc;
struct D2GfxListNodeStrc;
struct D2GfxMotionStrc;
struct D2UnitOverlayStrc;
struct D2UnitGfxDataStrc;
struct D2InvRectStrc;
struct D2MsgHandlerEntryStrc;
struct D2GfxLayerStrc;
struct D2GfxNodeTargetStrc;

struct D2UnitGfxDataStrc
{
    unsigned char aEntries[20][2]; // 0x00 (two bytes per component; the first is its value)
    D2GfxListNodeStrc* pList; // 0x28
    D2UnitOverlayStrc* pOverlays; // 0x2C
    D2GfxMotionStrc* pMotion; // 0x30
    int nBasePalShift; // 0x34
    int nPalShift; // 0x38
};

struct D2InvRectStrc
{
    int nLeft; // 0x00
    int nRight; // 0x04
    int nTop; // 0x08
    int nBottom; // 0x0C
};

struct D2MsgHandlerEntryStrc
{
    int nType; // 0x00
    int nId; // 0x04
    void* pfnHandler; // 0x08
};

struct D2GfxNodeTargetStrc
{
    int unk0x00[5]; // 0x00
    union
    {
        int nValue;
        D2GfxLayerStrc* pLayer;
    }; // 0x14
};

D2_CHECK_SIZE(D2UnitGfxDataStrc, 0x3C);
D2_CHECK_SIZE(D2InvRectStrc, 0x10);
D2_CHECK_SIZE(D2MsgHandlerEntryStrc, 0xC);
D2_CHECK_SIZE(D2GfxNodeTargetStrc, 0x18);

struct D2UnitTargetStrc
{
    int nParam1; // 0x00
    int nParam2; // 0x04
    int nParam3; // 0x08
    int unk0x0C[4]; // 0x0C
};

struct D2ClientEntryStrc
{
    unsigned int dwValue; // 0x00
    unsigned short wValue; // 0x04
    unsigned short unk0x06; // 0x06
    int nValue; // 0x08
};

D2_CHECK_SIZE(D2UnitTargetStrc, 0x1C);
D2_CHECK_SIZE(D2ClientEntryStrc, 0xC);
