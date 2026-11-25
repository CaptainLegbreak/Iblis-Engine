#include "D2StateIds.h"
#include "D2Game.h"
#include "D2GameStrc.h"
#include "D2EventTimer.h"
#include "D2Structs.h"
#include "D2LanguageNames.h"
// build: symbol _gaszLanguageNames 0x00731448

#define EVENTROW_PLAYER 0

#define EVENTROW_MONSTER 1

#define EVENTROW_MISSILE 2

#define EVENTROW_OBJECT 3

#define EVENTROW_ITEM 4

struct D2EventTimerSlabListStrc;

struct D2EventTimerQueueStrc;

typedef char TimerSizeCheck[(sizeof(D2EventTimerStrc) == 0x30) ? 1 : -1];

typedef char SlabSizeCheck[(sizeof(D2EventTimerSlabListStrc) == 0x7088) ? 1 : -1];

typedef char QueueSizeCheck[(sizeof(D2EventTimerQueueStrc) == 0xA20) ? 1 : -1];

typedef void(__fastcall* EventDefault3)(D2GameStrc*, D2UnitStrc*, int);

D2EventTimerStrc* __fastcall SUNIT_GetTimerFromUnit(D2UnitStrc* pUnit); // 0x00553980

void __fastcall D2GAME_EVENTS_Callback_6FC81BD0(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent, int nCustomId, int nCustomParam); // 0x00581220

void __fastcall MONSTERMODE_EventHandler(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent, int nCustomId, int nCustomParam); // 0x005A7F80

void __fastcall D2GAME_OBJMODE_InvokeEventFunction_6FC75250(D2GameStrc* pGame, D2UnitStrc* pObject, int nEvent); // 0x00586AD0

void __fastcall MISSMODE_SrvDoEventCallback(D2GameStrc* pGame, D2UnitStrc* pMissile, int nEvent); // 0x005ADCC0

void __fastcall D2GAME_Items_EventsHandler_6FC4A460(D2GameStrc* pGame, D2UnitStrc* pItem, int nEvent); // 0x00562DA0

static void EVENT_FreeTimer(D2GameStrc* pGame, D2EventTimerStrc* pTimer); // 0x00540CD0

void __fastcall EVENT_FreeUnitTimers(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540EE0

extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0

extern void __fastcall SUNIT_SetUninterruptable(D2UnitStrc*, int); // 0x005544B0

static D2EventTimerSlabListStrc* EVENT_AllocTimerSlab(D2GameStrc* pGame);

static D2EventTimerStrc* __stdcall EVENT_AllocateTimer(D2GameStrc* pGame, D2EventTimerQueueStrc* pQueue);

void __fastcall EVENT_AllocEventQueue(D2GameStrc* pGame);

void __fastcall EVENT_SetRecurringEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nCustomId, int nCustomParam);

void __fastcall EVENT_SetRecurringEventWithCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, EventTimerCallback pCallback, int nCustomId, int nCustomParam);

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int nCustomId, int nCustomParam); // 0x005417D0

void __fastcall EVENT_SetEventWithCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, EventTimerCallback pCallback, int nCustomId, int nCustomParam);

struct D2Unk00540B70Obj;

struct D2Unk00540B70Owner;

struct D2Unk00540B70Obj
{
    char unk0x000[0x504];
    int f_504[1];
};

struct D2Unk00540B70Owner
{
    char unk0x00[0xB8];
    D2Unk00540B70Obj* pObj;
};

void __fastcall FOG_FreePool(void*,void*,const char*,int,int); // 0x0040B480

static void __stdcall EVENT_InsertInfiniteTimer(EventTimerCallback pCallback, int nCustomId, int nCustomParam, D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType);

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

static void __stdcall EVENT_ScheduleTimer(D2UnitStrc* pUnit, EventTimerCallback pCallback, int nCustomId, int nCustomParam, D2GameStrc* pGame, int nEventType, int nExpireFrame);

static void __stdcall EVENT_InsertInfiniteTimer(EventTimerCallback pCallback, int nCustomId, int nCustomParam, D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType);

static void __stdcall EVENT_ScheduleTimer(D2UnitStrc* pUnit, EventTimerCallback pCallback, int nCustomId, int nCustomParam, D2GameStrc* pGame, int nEventType, int nExpireFrame);

// 0x00540B20
static inline D2EventTimerQueueStrc* EVENT_GetTimerQueue(D2GameStrc* pGame)
{
    return pGame->pTimerQueue;
}

// 0x00540B30
static D2EventTimerStrc** __fastcall EVENT_GetQueuedTimerListHead(D2GameStrc* pGame, int nExpireFrame, int nUnitType)
{
// build: symbol ?gaSlotRows@* 0x006E0B9C
    const int nRow = gaSlotRows[nUnitType];
    D2EventTimerQueueStrc* pQueue = pGame->pTimerQueue;
    if (nExpireFrame == -1)
        return &pQueue->pInfinite[nRow];
    return &pQueue->pHead[nRow][nExpireFrame % 64];
}

D2EventTimerStrc** __fastcall sub_M400_Emit_00540B30(D2GameStrc* pGame, int nExpireFrame, int nUnitType)
{
    return EVENT_GetQueuedTimerListHead(pGame, nExpireFrame + 7, nUnitType);
}

// 0x00540B70
static int* __stdcall EVENT_GetTimerSlot(D2Unk00540B70Owner* pOwner, int nType, int nIndex)
{
    if (nIndex == -1)
    {
        return 0;
    }
    return &pOwner->pObj->f_504[gaSlotRows[nType] * 64 + nIndex % 64];
}

// 0x00540BB0
static D2EventTimerSlabListStrc* EVENT_AllocTimerSlab(D2GameStrc* pGame)
{
    D2EventTimerSlabListStrc* pSlab = (D2EventTimerSlabListStrc*)sub_0040B430_Alloc(pGame->pMemoryPool, sizeof(D2EventTimerSlabListStrc), ".\\GAME\\Event.cpp", 169, 0);
    if (!pSlab)
        return 0;
    memset(pSlab, 0, sizeof(D2EventTimerSlabListStrc));
    D2EventTimerStrc* pTimer = pSlab->tEventTimersStorage;
    pSlab->pFreeEventTimerListHead = pTimer;
    for (int i = 0; i < 599; ++i)
    {
        pTimer->pNextFreeEventTimer = pTimer + 1;
        ++pTimer;
    }
    pTimer->pNextFreeEventTimer = 0;
    return pSlab;
}

static D2EventTimerStrc* sub_00540DF0_InitializeTimer(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2EventTimerStrc* pTimer = EVENT_AllocateTimer(pGame, pGame->pTimerQueue);
    pTimer->pUnit = pUnit;
    pTimer->pNext = sub_00553980_GetTimer(pUnit);
    if (pTimer->pNext)
        pTimer->pNext->pPrevious = pTimer;
    pTimer->pPrevious = 0;
    sub_00553970_SetTimer(pUnit, pTimer);
    pTimer->nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    pTimer->nUnitGUID = pUnit ? pUnit->dwUnitId : -1;
    pTimer->nFlags &= ~2;
    return pTimer;
}

// 0x00540C10
static inline void EVENT_PushFreeTimer(D2EventTimerStrc* pTimer, D2EventTimerStrc** ppHead)
{
    D2EventTimerStrc* pHead = *ppHead;
    pTimer->pNextFreeEventTimer = pHead;
    pTimer->pPreviousQueuedTimer = 0;
    if (pHead)
        pHead->pPreviousQueuedTimer = pTimer;
    *ppHead = pTimer;
}

// 0x00540C30
static D2EventTimerStrc* __stdcall EVENT_AllocateTimer(D2GameStrc* pGame, D2EventTimerQueueStrc* pQueue)
{
    D2EventTimerSlabListStrc* pSlab = pQueue->pSlabListHead;
    while (pSlab)
    {
        if (pSlab->pFreeEventTimerListHead)
            break;
        pSlab = pSlab->pNextSlab;
    }
    if (!pSlab)
    {
        pSlab = EVENT_AllocTimerSlab(pGame);
        pSlab->pNextSlab = pQueue->pSlabListHead->pNextSlab;
        pQueue->pSlabListHead->pNextSlab = pSlab;
    }
    D2EventTimerStrc* pTimer = pSlab->pFreeEventTimerListHead;
    pSlab->pFreeEventTimerListHead = pTimer->pNextFreeEventTimer;
    memset(pTimer, 0, sizeof(D2EventTimerStrc));
    return pTimer;
}

// 0x00540CA0
static inline void EVENT_ReleaseTimer(D2EventTimerQueueStrc* pQueue, D2EventTimerStrc* pTimer)
{
    D2EventTimerSlabListStrc* pSlab = pQueue->pSlabListHead;
    pTimer->pNextFreeEventTimer = pSlab->pFreeEventTimerListHead;
    pTimer->pPreviousQueuedTimer = 0;
    pSlab->pFreeEventTimerListHead = pTimer;
    pTimer->nFlags = 2;
}

static inline D2EventTimerStrc** sub_6FC353D0(D2GameStrc* pGame, int nUnitType, int nExpireFrame)
{
    if (nExpireFrame == -1)
    {
        return &pGame->pTimerQueue->pInfinite[gaSlotRows[nUnitType]];
    }
    return &pGame->pTimerQueue->pHead[gaSlotRows[nUnitType]][nExpireFrame % 64];
}

static inline D2EventTimerStrc** sub_6FC353D0_00540CD0(D2GameStrc* pGame, int nUnitType, int nExpireFrame)
{
    const int nRow = gaSlotRows[nUnitType];
    D2EventTimerQueueStrc* pTimerQueue = pGame->pTimerQueue;
    if (nExpireFrame == -1)
    {
        return &pTimerQueue->pInfinite[nRow];
    }
    return &pTimerQueue->pHead[nRow][nExpireFrame % 64];
}

// 0x00540CD0
static void EVENT_FreeTimer(D2GameStrc* pGame, D2EventTimerStrc* pTimer)
{
    D2EventTimerQueueStrc* pTimerQueue = pGame->pTimerQueue;
    if (pTimer->nFlags & EVENTFLAG_0x1)
    {
        pTimer->nFlags |= EVENTFLAG_0x8;
        return;
    }
    if (pTimer == pTimerQueue->pCurrent)
    {
        pTimerQueue->pCurrent = pTimer->pNextFreeEventTimer;
    }
    if (pTimer->pPreviousQueuedTimer)
    {
        pTimer->pPreviousQueuedTimer->pNextFreeEventTimer = pTimer->pNextFreeEventTimer;
    }
    else
    {
        D2EventTimerStrc** ppEventTimer = sub_6FC353D0_00540CD0(pGame, pTimer->nUnitType, pTimer->nExpireFrame);
        *ppEventTimer = pTimer->pNextFreeEventTimer;
    }
    if (pTimer->pNextFreeEventTimer)
    {
        pTimer->pNextFreeEventTimer->pPreviousQueuedTimer = pTimer->pPreviousQueuedTimer;
    }
    else if (pTimer->nExpireFrame != -1)
    {
        D2EventTimerStrc** ppEventTimer = &pGame->pTimerQueue->pTail[gaSlotRows[pTimer->nUnitType]][pTimer->nExpireFrame % 64];
        if (ppEventTimer && *ppEventTimer == pTimer)
        {
            *ppEventTimer = pTimer->pPreviousQueuedTimer;
        }
    }
    if (pTimer->pUnit)
    {
        if (pTimer->pNext)
        {
            pTimer->pNext->pPrevious = pTimer->pPrevious;
        }
        if (pTimer->pPrevious)
        {
            pTimer->pPrevious->pNext = pTimer->pNext;
        }
        else
        {
            SUNIT_SetTimerOnUnit(pTimer->pUnit, pTimer->pNext);
        }
    }
    D2EventTimerSlabListStrc* pEventTimerArray = pTimerQueue->pSlabListHead;
    pTimer->pNextFreeEventTimer = pEventTimerArray->pFreeEventTimerListHead;
    pTimer->pPreviousQueuedTimer = 0;
    pEventTimerArray->pFreeEventTimerListHead = pTimer;
    pTimer->nFlags = EVENTFLAG_0x2;
}

void __fastcall EVENTS_DeleteByType(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId)
{
    D2EventTimerStrc* pEventTimer = SUNIT_GetTimerFromUnit(pUnit);
    while (pEventTimer)
    {
        D2EventTimerStrc* pNextTimer = pEventTimer->pNext;
        if (pEventTimer->nEventType == nEventType && (!nEventCustomId || pEventTimer->dwEventCustomId == nEventCustomId))
        {
            EVENT_FreeTimer(pGame, pEventTimer);
        }
        pEventTimer = pNextTimer;
    }
}

void __fastcall EVENTS_DeleteByCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent, EventTimerCallback pCallback)
{
    D2EventTimerStrc* pEventTimer = SUNIT_GetTimerFromUnit(pUnit);
    while (pEventTimer)
    {
        D2EventTimerStrc* pNext = pEventTimer->pNext;
        if (pEventTimer->nEventType == nEvent)
        {
            if (pCallback == pEventTimer->pCallback)
            {
                EVENT_FreeTimer(pGame, pEventTimer);
            }
        }
        pEventTimer = pNext;
    }
}

void __fastcall EVENTS_DeleteAll(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2EventTimerStrc* pEventTimer = SUNIT_GetTimerFromUnit(pUnit);
    while (pEventTimer)
    {
        D2EventTimerStrc* pNext = pEventTimer->pNext;
        EVENT_FreeTimer(pGame, pEventTimer);
        pEventTimer->pUnit = 0;
        pEventTimer = pNext;
    }
    SUNIT_SetTimerOnUnit(pUnit, 0);
}

// 0x00540DF0
static D2EventTimerStrc* __stdcall EVENT_AllocateUnitTimer(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2EventTimerQueueStrc* pQueue = pGame->pTimerQueue;
    D2EventTimerStrc* pTimer = EVENT_AllocateTimer(pGame, pQueue);
    pTimer->pUnit = pUnit;
    pTimer->pNext = SUNIT_GetTimerFromUnit(pUnit);
    if (pTimer->pNext)
    {
        pTimer->pNext->pPrevious = pTimer;
    }
    pTimer->pPrevious = 0;
    SUNIT_SetTimerOnUnit(pUnit, pTimer);
    pTimer->nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
    pTimer->nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    pTimer->nFlags &= ~2;
    return pTimer;
}

void __stdcall sub_M113_Emit_00540B20(D2GameStrc* pGame, D2EventTimerStrc* pTimer, D2EventTimerStrc** ppHead)
{
    EVENT_PushFreeTimer(pTimer, ppHead);
    EVENT_ReleaseTimer(EVENT_GetTimerQueue(pGame), pTimer);
}

// 0x00540E60
void __fastcall D2GAME_EVENTS_Delete_6FC34840(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nEventCustomId)
{
    D2EventTimerStrc* pEventTimer = SUNIT_GetTimerFromUnit(pUnit);
    while (pEventTimer)
    {
        D2EventTimerStrc* pNextTimer = pEventTimer->pNext;
        if (pEventTimer->nEventType == nEventType && (!nEventCustomId || pEventTimer->dwEventCustomId == nEventCustomId))
        {
            EVENT_FreeTimer(pGame, pEventTimer);
        }
        pEventTimer = pNextTimer;
    }
}

// 0x00540EA0
void __fastcall EVENT_DeleteTimersByCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent, EventTimerCallback pCallback)
{
    D2EventTimerStrc* pEventTimer = SUNIT_GetTimerFromUnit(pUnit);
    while (pEventTimer)
    {
        D2EventTimerStrc* pNext = pEventTimer->pNext;
        if (pEventTimer->nEventType == nEvent)
        {
            if (pCallback == pEventTimer->pCallback)
            {
                EVENT_FreeTimer(pGame, pEventTimer);
            }
        }
        pEventTimer = pNext;
    }
}

// 0x00540EE0
void __fastcall EVENT_FreeUnitTimers(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2EventTimerStrc* pEventTimer = SUNIT_GetTimerFromUnit(pUnit);
    while (pEventTimer)
    {
        D2EventTimerStrc* pNext = pEventTimer->pNext;
        EVENT_FreeTimer(pGame, pEventTimer);
        pEventTimer->pUnit = 0;
        pEventTimer = pNext;
    }
    SUNIT_SetTimerOnUnit(pUnit, 0);
}

// 0x00540F30
void __fastcall D2GAME_DeleteTimersOnUnit_6FC34A30(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (SUNIT_GetTimerFromUnit(pUnit))
    {
        EVENT_FreeUnitTimers(pGame, pUnit);
    }

    SUNIT_SetTimerOnUnit(pUnit, 0);
}

static __forceinline void EVENT_ExecuteEventsImpl5(EventTimerCallback pDefaultCallback, D2GameStrc* pGame, D2EventTimerQueueStrc* pTimerQueue, D2EventTimerStrc* pEventTimer, int a4)
{
    pTimerQueue->pCurrent = 0;
    D2EventTimerStrc* pTimer = pEventTimer;
    if (a4)
    {
        while (pTimer)
        {
            pTimerQueue->pCurrent = pTimer->pNextFreeEventTimer;
            if (pTimer->nExpireFrame == pGame->dwGameFrame)
            {
                pTimer->nFlags |= EVENTFLAG_0x1;
                if (pTimer->pCallback)
                {
                    pTimer->pCallback(pGame, pTimer->pUnit, pTimer->nEventType, pTimer->dwEventCustomId, pTimer->dwEventCustomParam);
                }
                else
                {
                    pDefaultCallback(pGame, pTimer->pUnit, pTimer->nEventType, pTimer->dwEventCustomId, pTimer->dwEventCustomParam);
                }
                pTimer->nFlags &= ~EVENTFLAG_0x1;
                EVENT_FreeTimer(pGame, pTimer);
            }
            pTimer = pTimerQueue->pCurrent;
        }
    }
    else
    {
        while (pTimer)
        {
            pTimerQueue->pCurrent = pTimer->pNextFreeEventTimer;
            pTimer->nFlags |= EVENTFLAG_0x1;
            if (pTimer->pCallback)
            {
                pTimer->pCallback(pGame, pTimer->pUnit, pTimer->nEventType, pTimer->dwEventCustomId, pTimer->dwEventCustomParam);
            }
            else
            {
                pDefaultCallback(pGame, pTimer->pUnit, pTimer->nEventType, pTimer->dwEventCustomId, pTimer->dwEventCustomParam);
            }
            pTimer->nFlags &= ~EVENTFLAG_0x1;
            if (pTimer->nFlags & EVENTFLAG_0x8)
            {
                EVENT_FreeTimer(pGame, pTimer);
            }
            pTimer = pTimerQueue->pCurrent;
        }
    }
}

static __forceinline void EVENT_ExecuteEventsImpl3(EventDefault3 pDefaultCallback, D2GameStrc* pGame, D2EventTimerQueueStrc* pTimerQueue, D2EventTimerStrc* pEventTimer, int a4)
{
    pTimerQueue->pCurrent = 0;
    D2EventTimerStrc* pTimer = pEventTimer;
    if (a4)
    {
        while (pTimer)
        {
            pTimerQueue->pCurrent = pTimer->pNextFreeEventTimer;
            if (pTimer->nExpireFrame == pGame->dwGameFrame)
            {
                pTimer->nFlags |= EVENTFLAG_0x1;
                if (pTimer->pCallback)
                {
                    pTimer->pCallback(pGame, pTimer->pUnit, pTimer->nEventType, pTimer->dwEventCustomId, pTimer->dwEventCustomParam);
                }
                else
                {
                    pDefaultCallback(pGame, pTimer->pUnit, pTimer->nEventType);
                }
                pTimer->nFlags &= ~EVENTFLAG_0x1;
                EVENT_FreeTimer(pGame, pTimer);
            }
            pTimer = pTimerQueue->pCurrent;
        }
    }
    else
    {
        while (pTimer)
        {
            pTimerQueue->pCurrent = pTimer->pNextFreeEventTimer;
            pTimer->nFlags |= EVENTFLAG_0x1;
            if (pTimer->pCallback)
            {
                pTimer->pCallback(pGame, pTimer->pUnit, pTimer->nEventType, pTimer->dwEventCustomId, pTimer->dwEventCustomParam);
            }
            else
            {
                pDefaultCallback(pGame, pTimer->pUnit, pTimer->nEventType);
            }
            pTimer->nFlags &= ~EVENTFLAG_0x1;
            if (pTimer->nFlags & EVENTFLAG_0x8)
            {
                EVENT_FreeTimer(pGame, pTimer);
            }
            pTimer = pTimerQueue->pCurrent;
        }
    }
}

// 0x00540F60
static void __stdcall EVENT_ExecutePlayerEvents(int a4, D2GameStrc* pGame, D2EventTimerQueueStrc* pTimerQueue, D2EventTimerStrc* pEventTimer)
{
    EVENT_ExecuteEventsImpl5(D2GAME_EVENTS_Callback_6FC81BD0, pGame, pTimerQueue, pEventTimer, a4);
}

// 0x00541060
static void __stdcall EVENT_ExecuteMonsterEvents(int a4, D2GameStrc* pGame, D2EventTimerQueueStrc* pTimerQueue, D2EventTimerStrc* pEventTimer)
{
    EVENT_ExecuteEventsImpl5(MONSTERMODE_EventHandler, pGame, pTimerQueue, pEventTimer, a4);
}

// 0x00541160
static void __stdcall EVENT_ExecuteObjectEvents(int a4, D2GameStrc* pGame, D2EventTimerQueueStrc* pTimerQueue, D2EventTimerStrc* pEventTimer)
{
    EVENT_ExecuteEventsImpl3(D2GAME_OBJMODE_InvokeEventFunction_6FC75250, pGame, pTimerQueue, pEventTimer, a4);
}

// 0x00541240
static void __stdcall EVENT_ExecuteMissileEvents(int a4, D2GameStrc* pGame, D2EventTimerQueueStrc* pTimerQueue, D2EventTimerStrc* pEventTimer)
{
    EVENT_ExecuteEventsImpl3(MISSMODE_SrvDoEventCallback, pGame, pTimerQueue, pEventTimer, a4);
}

// 0x00541320
static void __stdcall EVENT_ExecuteItemEvents(int a4, D2GameStrc* pGame, D2EventTimerQueueStrc* pTimerQueue, D2EventTimerStrc* pEventTimer)
{
    EVENT_ExecuteEventsImpl3(D2GAME_Items_EventsHandler_6FC4A460, pGame, pTimerQueue, pEventTimer, a4);
}

// 0x00541400
void __fastcall EVENT_FreeEventQueue(D2GameStrc* pGame)
{
    D2EventTimerQueueStrc* pTimerQueue = pGame->pTimerQueue;
    if (!pTimerQueue)
    {
        return;
    }

    D2EventTimerSlabListStrc* pTimerArray = pTimerQueue->pSlabListHead;
    while (pTimerArray)
    {
        D2EventTimerSlabListStrc* pNext = pTimerArray->pNextSlab;
        FOG_FreePool(pGame->pMemoryPool, pTimerArray, ".\\GAME\\Event.cpp", 0x314, 0);
        pTimerArray = pNext;
    }

    FOG_FreePool(pGame->pMemoryPool, pTimerQueue, ".\\GAME\\Event.cpp", 0x317, 0);
    pGame->pTimerQueue = 0;
}

// 0x00541470
void __fastcall EVENT_AllocEventQueue(D2GameStrc* pGame)
{
    if (pGame->pTimerQueue)
        sub_00541400_FreeQueue(pGame);
    D2EventTimerQueueStrc* pQueue = (D2EventTimerQueueStrc*)sub_0040B430_Alloc(pGame->pMemoryPool, sizeof(D2EventTimerQueueStrc), ".\\GAME\\Event.cpp", 807, 0);
    memset(pQueue, 0, sizeof(D2EventTimerQueueStrc));
    pQueue->pSlabListHead = EVENT_AllocTimerSlab(pGame);
    pGame->pTimerQueue = pQueue;
}

// 0x005414D0
void __fastcall EVENT_IterateEvents(D2GameStrc* pGame)
{
    D2EventTimerQueueStrc* pTimerQueue = pGame->pTimerQueue;
    pTimerQueue->nArrayIndex = pGame->dwGameFrame % 64;
    EVENT_ExecuteMissileEvents(0, pGame, pTimerQueue, pTimerQueue->pInfinite[EVENTROW_MISSILE]);
    EVENT_ExecuteMissileEvents(1, pGame, pTimerQueue, pTimerQueue->pHead[EVENTROW_MISSILE][pTimerQueue->nArrayIndex]);
    EVENT_ExecutePlayerEvents(0, pGame, pTimerQueue, pTimerQueue->pInfinite[EVENTROW_PLAYER]);
    EVENT_ExecutePlayerEvents(1, pGame, pTimerQueue, pTimerQueue->pHead[EVENTROW_PLAYER][pTimerQueue->nArrayIndex]);
    EVENT_ExecuteMonsterEvents(0, pGame, pTimerQueue, pTimerQueue->pInfinite[EVENTROW_MONSTER]);
    EVENT_ExecuteMonsterEvents(1, pGame, pTimerQueue, pTimerQueue->pHead[EVENTROW_MONSTER][pTimerQueue->nArrayIndex]);
    EVENT_ExecuteObjectEvents(0, pGame, pTimerQueue, pTimerQueue->pInfinite[EVENTROW_OBJECT]);
    EVENT_ExecuteObjectEvents(1, pGame, pTimerQueue, pTimerQueue->pHead[EVENTROW_OBJECT][pTimerQueue->nArrayIndex]);
    EVENT_ExecuteItemEvents(0, pGame, pTimerQueue, pTimerQueue->pInfinite[EVENTROW_ITEM]);
    EVENT_ExecuteItemEvents(1, pGame, pTimerQueue, pTimerQueue->pHead[EVENTROW_ITEM][pTimerQueue->nArrayIndex]);
}


struct Data00541860;

struct Unit00541860;

// 0x005415A0
int __fastcall EVENT_GetEventFrame(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEvent)
{
    D2EventTimerStrc* pEventTimer = SUNIT_GetTimerFromUnit(pUnit);
    int nEventFrame = 0;
    while (pEventTimer)
    {
        D2EventTimerStrc* pNext = pEventTimer->pNext;
        if (pEventTimer->nEventType == nEvent)
        {
            const int nFrame = pEventTimer->nExpireFrame;
            if (nFrame > 0 && (nFrame < nEventFrame || !nEventFrame))
            {
                nEventFrame = nFrame;
            }
        }
        pEventTimer = pNext;
    }
    return nEventFrame;
}

// 0x005415E0
static void __stdcall EVENT_InsertInfiniteTimer(EventTimerCallback pCallback, int nCustomId, int nCustomParam, D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType)
{
    if (nEventType >= 15)
    {
        return;
    }

    D2EventTimerStrc* pTimer = EVENT_AllocateUnitTimer(pGame, pUnit);
    pTimer->nFlags |= 4;
    pTimer->dwEventCustomId = nCustomId;
    pTimer->nEventType = (unsigned char)nEventType;
    pTimer->nExpireFrame = -1;
    pTimer->dwEventCustomParam = nCustomParam;
    pTimer->pCallback = pCallback;
    const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
    D2EventTimerStrc** ppFirst = &pGame->pTimerQueue->pInfinite[gaSlotRows[nUnitType]];
    pTimer->pNextFreeEventTimer = *ppFirst;
    pTimer->pPreviousQueuedTimer = 0;
    if (pTimer->pNextFreeEventTimer)
    {
        pTimer->pNextFreeEventTimer->pPreviousQueuedTimer = pTimer;
    }
    *ppFirst = pTimer;
}

// 0x005417D0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int nCustomId, int nCustomParam)
{
    EVENT_ScheduleTimer(pUnit, 0, nCustomId, nCustomParam, pGame, nEventType, nExpireFrame);
}

// 0x00541650
void __fastcall EVENT_SetRecurringEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nCustomId, int nCustomParam)
{
    EVENT_InsertInfiniteTimer(0, nCustomId, nCustomParam, pGame, pUnit, nEventType);
}

static inline D2EventTimerStrc** EVENT_GetTimerListHead(D2GameStrc* pGame, int nUnitType, int nExpireFrame)
{
    const int nIndex = gaSlotRows[nUnitType];
    D2EventTimerQueueStrc* pQueue = pGame->pTimerQueue;
    if (nExpireFrame == -1)
    {
        return &pQueue->pInfinite[nIndex];
    }

    return &pQueue->pHead[nIndex][nExpireFrame % 64];
}

static inline D2EventTimerStrc** EVENT_GetTimerListTail(D2GameStrc* pGame, int nUnitType, int nExpireFrame)
{
    if (nExpireFrame == -1)
    {
        return 0;
    }

    return &pGame->pTimerQueue->pTail[gaSlotRows[nUnitType]][nExpireFrame % 64];
}

// 0x00541680
void __fastcall EVENT_SetRecurringEventWithCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, EventTimerCallback pCallback, int nCustomId, int nCustomParam)
{
    EVENT_InsertInfiniteTimer(pCallback, nCustomId, nCustomParam, pGame, pUnit, nEventType);
}

// 0x005416B0
static void __stdcall EVENT_ScheduleTimer(D2UnitStrc* pUnit, EventTimerCallback pCallback, int nCustomId, int nCustomParam, D2GameStrc* pGame, int nEventType, int nExpireFrame)
{
    if (nEventType >= 15)
    {
        return;
    }

    if (nExpireFrame == -1)
    {
        EVENT_InsertInfiniteTimer(0, nCustomId, nCustomParam, pGame, pUnit, nEventType);
        return;
    }

    if (nExpireFrame <= pGame->dwGameFrame)
    {
        nExpireFrame = pGame->dwGameFrame + 1;
    }

    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && nEventType == 2)
    {
        if (STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
        {
            SUNIT_SetUninterruptable(pUnit, 0);
        }
    }

    D2EventTimerStrc* pTimer = EVENT_AllocateUnitTimer(pGame, pUnit);
    pTimer->dwEventCustomId = nCustomId;
    pTimer->nEventType = (unsigned char)nEventType;
    pTimer->nExpireFrame = nExpireFrame;
    pTimer->dwEventCustomParam = nCustomParam;
    pTimer->pCallback = pCallback;

    D2EventTimerStrc** ppTail = EVENT_GetTimerListTail(pGame, pTimer->nUnitType, nExpireFrame);
    pTimer->pNextFreeEventTimer = 0;
    pTimer->pPreviousQueuedTimer = *ppTail;
    if (pTimer->pPreviousQueuedTimer)
    {
        pTimer->pPreviousQueuedTimer->pNextFreeEventTimer = pTimer;
    }
    *ppTail = pTimer;

    D2EventTimerStrc** ppHead = EVENT_GetTimerListHead(pGame, pTimer->nUnitType, pTimer->nExpireFrame);

    if (!*ppHead)
    {
        *ppHead = pTimer;
    }
}

// 0x00541800
void __fastcall EVENT_SetEventWithCallback(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, EventTimerCallback pCallback, int nCustomId, int nCustomParam)
{
    EVENT_ScheduleTimer(pUnit, pCallback, nCustomId, nCustomParam, pGame, nEventType, nExpireFrame);
}

int* __fastcall sub_K10_EmitGetSlot(D2Unk00540B70Owner* pOwner, int nType)
{
    return EVENT_GetTimerSlot(pOwner, nType, nType + 1);
}

#include "gen/data/Source/D2Game/GAME/Event.inc"
