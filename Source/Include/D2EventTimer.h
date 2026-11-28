#pragma once
// Game event timers: the timer record, its slab allocator and the per-game timer queue

#include "D2Check.h"
#include "D2Structs.h"

struct D2UnitStrc;
struct D2GameStrc;
struct D2EventTimerStrc;
struct D2EventTimerSlabListStrc;
struct D2EventTimerQueueStrc;

typedef void(__fastcall* EventTimerCallback)(D2GameStrc*, D2UnitStrc*, int, int, int);

struct D2EventTimerStrc
{
    unsigned char nEventType; // 0x00
    unsigned char pad0x01; // 0x01
    unsigned short nFlags; // 0x02
    int nExpireFrame; // 0x04
    D2UnitStrc* pUnit; // 0x08
    int nUnitGUID; // 0x0C
    int nUnitType; // 0x10
    int dwEventCustomId; // 0x14
    int dwEventCustomParam; // 0x18
    D2EventTimerStrc* pNextFreeEventTimer; // 0x1C
    D2EventTimerStrc* pPreviousQueuedTimer; // 0x20
    D2EventTimerStrc* pNext; // 0x24
    D2EventTimerStrc* pPrevious; // 0x28
    EventTimerCallback pCallback; // 0x2C
};

struct D2EventTimerSlabListStrc
{
    D2EventTimerStrc tEventTimersStorage[600]; // 0x00
    D2EventTimerStrc* pFreeEventTimerListHead; // 0x7080
    D2EventTimerSlabListStrc* pNextSlab; // 0x7084
};

struct D2EventTimerQueueStrc
{
    int nArrayIndex; // 0x00
    D2EventTimerStrc* pHead[5][64]; // 0x04
    D2EventTimerStrc* pTail[5][64]; // 0x504
    D2EventTimerStrc* pInfinite[5]; // 0xA04
    D2EventTimerStrc* pCurrent; // 0xA18
    D2EventTimerSlabListStrc* pSlabListHead; // 0xA1C
};

D2_CHECK_SIZE(D2EventTimerStrc, 0x30);
D2_CHECK_SIZE(D2EventTimerSlabListStrc, 0x7088);
D2_CHECK_SIZE(D2EventTimerQueueStrc, 0xA20);
