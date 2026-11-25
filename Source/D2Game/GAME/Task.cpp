#include "D2Game.h"
#include "D2GameTypes.h"
#include "D2GameStrc.h"
#include "D2GameClient.h"
#include "D2LanguageNames.h"
// build: symbol _gaszLanguageNames 0x0073200C

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2LinkStrc;

struct D2TaskStrc;

struct D2LargeIntegerStrc;

struct D2TaskQueueStrc;

struct D2GameTaskStrc;

struct D2CriticalSectionStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214

extern "C" __declspec(dllimport) int __stdcall QueryPerformanceFrequency(D2LargeIntegerStrc* pFrequency); // 0x006CC254

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

int __fastcall TASK_GetClockTime(); // 0x00564340

D2LinkStrc* __fastcall TASK_LinkList_Remove(D2LinkStrc* pLink); // 0x005642E0

void __stdcall TASK_BalanceQueues(D2TaskStrc* pTask); // 0x00564460

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

D2TaskStrc* gtTaskSlots[32]; // 0x0088C708

unsigned int gnNumberOfTasksCreated; // 0x0088C798

static unsigned int gnGamesCount;        // 0x0088C79C

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC

// Fog's critical-section object; its constructor and destructor are out of line (0x0040EB50/0x0040EB60),
// so the array below is built and torn down by the CRT's vector constructor and destructor iterators.
class CCritSect : public D2CriticalSectionStrc
{
public:
    CCritSect();
    ~CCritSect();
};
// build: symbol ??0CCritSect@@QAE@XZ 0x0040EB50
// build: symbol ??1CCritSect@@QAE@XZ 0x0040EB60

// A critical section for the whole run whose constructor and destructor are inline:
// the initializer calls InitializeCriticalSection itself.
struct CStaticCritSect : D2CriticalSectionStrc
{
    CStaticCritSect() { InitializeCriticalSection(this); }
    ~CStaticCritSect() { DeleteCriticalSection(this); }
};

// build: symbol ??__EgtTaskQueuesCriticalSections@@YAXXZ 0x006CAF90
// build: symbol ??__FgtTaskQueuesCriticalSections@@YAXXZ 0x006CB4A0
CCritSect gtTaskQueuesCriticalSections[32]; // 0x0088C7A8

// build: symbol ??__EgTaskSlotsCriticalSection@@YAXXZ 0x006CAF70
// build: symbol ??__FgTaskSlotsCriticalSection@@YAXXZ 0x006CB490
CStaticCritSect gTaskSlotsCriticalSection; // 0x0088CAA8

struct D2TaskQueueStrc
{
    int nQueueIndex;
    int nGameCount;
    D2LinkStrc tGameTasks;
    D2LinkStrc tQueueLink;
};

struct D2GameTaskStrc
{
    int nScheduledTime;
    int nType;
    unsigned int nGameHashKey;
    D2LinkStrc tTaskLink;
};

int gbHasHighResolutionClock; // 0x0088C7A0

D2LargeIntegerStrc gPerformanceFrequency; // 0x0088C790

extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(D2LargeIntegerStrc* pCount); // 0x006CC25C

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260

extern D2TaskQueueStrc* gpTaskQueues_0088C708[32]; // 0x0088C708

static D2LinkStrc gpTaskQueueLink; // 0x0088C788

D2GameStrc* __fastcall GAME_LockGame(int nGameGUID);                                                        // 0x0052E860

void __fastcall GAME_UpdateProgress(D2GameStrc* pGame);                                                     // 0x0052D870

void __fastcall D2GAME_PACKETS_SendGameLeft(int nClientId);                                             // 0x0053B220

void __fastcall ClientRemoveFromGame(D2GameStrc* pGame, int nClientId, int bTriggerSave);          // 0x00539DA0

void __fastcall GAME_LeaveGamesCriticalSection(D2GameStrc* pGame);                                          // 0x0052DA90

void __fastcall GAME_CloseGame(int nGameGUID);                                                              // 0x0052E770

void __fastcall TASK_LinkList_PushFront(D2LinkStrc* pList, D2LinkStrc* pLink);                              // 0x00564250

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0



extern "C" const char gszTaskSourceFile[];                                                                  // 0x006E11B8

static void TASK_QueueIncrement(D2TaskStrc*, int*, int);

struct D2TaskGameStrc
{
    int nTime;
    int nArg;
    unsigned int hGame;
    D2LinkStrc tLink;
};



// 0x005641C0
void __fastcall sub_005641C0_Init(D2LinkStrc* list)
{
    list->pPrev = list;
    list->pNext = list;
}

// 0x005641D0
int __fastcall TASK_LinkList_IsEmpty(D2LinkStrc* pList)
{
    return pList->pNext == pList;
}

struct D2IdentityView
{
    D2LinkStrc link;
};

// 0x005641E0
D2LinkStrc* __fastcall TASK_Identity(D2IdentityView* value)
{
    return &value->link;
}

// 0x005641F0
D2LinkStrc* __fastcall TASK_LinkList_GetFirst(D2LinkStrc* pList)
{
    D2LinkStrc* pNext = pList->pNext;
    return pNext != pList ? pNext : 0;
}

// 0x00564200
D2LinkStrc* __fastcall TASK_GetLastTaskFromListHead(D2LinkStrc* pList)
{
    if (pList->pNext == pList)
    {
        return 0;
    }

    return pList->pPrev;
}

// 0x00564210
void __fastcall TASK_LinkList_Insert(D2LinkStrc* pPrev, D2LinkStrc* pLink)
{
    D2_ASSERT(pPrev, 0x6C);
    D2_ASSERT(pLink, 0x6D);

    pLink->pPrev = pPrev;
    pLink->pNext = pPrev->pNext;
    pLink->pNext->pPrev = pLink;
    pPrev->pNext = pLink;
}

// 0x00564250
void __fastcall TASK_LinkList_PushFront(D2LinkStrc* pList, D2LinkStrc* pLink)
{
    D2_ASSERT(pList, 0x77);
    D2_ASSERT(pLink, 0x78);

    pLink->pPrev = pList;
    pLink->pNext = pList->pNext;
    pLink->pNext->pPrev = pLink;
    pList->pNext = pLink;
}

// 0x00564290
void __fastcall TASK_LinkList_PushBack(D2LinkStrc* pList, D2LinkStrc* pLink)
{
    D2_ASSERT(pList, 0x7F);
    D2_ASSERT(pLink, 0x80);

    TASK_LinkList_Insert(pList->pPrev, pLink);
}

// 0x005642E0
D2LinkStrc* __fastcall TASK_LinkList_Remove(D2LinkStrc* pLink)
{
    D2_ASSERT(pLink, 0x87);

    pLink->pPrev->pNext = pLink->pNext;
    pLink->pNext->pPrev = pLink->pPrev;
    return pLink;
}

// 0x00564320
void __stdcall TASK_InitializeClock()
{
    gbHasHighResolutionClock = QueryPerformanceFrequency(&gPerformanceFrequency);
}

// 0x00564340
int __fastcall TASK_GetClockTime()
{
    if (gbHasHighResolutionClock)
    {
        D2LargeIntegerStrc nQPC;
        QueryPerformanceCounter(&nQPC);
        return 1000 * nQPC.QuadPart / gPerformanceFrequency.QuadPart;
    }

    return GetTickCount();
}

// 0x00564390
static inline D2TaskStrc* TASK_LockTaskSlot(int nTaskNumber)
{
    const int nIndex = nTaskNumber & 0x1F;
    EnterCriticalSection(&gtTaskQueuesCriticalSections[nIndex]);
    D2TaskStrc* pTask = gtTaskSlots[nIndex];
    if (!pTask)
    {
        LeaveCriticalSection(&gtTaskQueuesCriticalSections[nIndex]);
    }
    return pTask;
}

// 0x005643C0
static inline void TASK_UnlockTaskSlot(D2TaskStrc* pTask)
{
    if (pTask)
    {
        D2_ASSERT((unsigned int)pTask->dwTaskQ < 32, 0x97);
        LeaveCriticalSection(&gtTaskQueuesCriticalSections[pTask->dwTaskQ]);
    }
}

static D2TaskStrc* TASK_GetTaskFromTaskQueueLink(D2LinkStrc* pLink)
{
    return (D2TaskStrc*)((char*)pLink - 0x10);
}

static D2TaskStrc* TASK_GetTaskFromTaskType(int* pTaskType)
{
    return (D2TaskStrc*)((char*)pTaskType - 4);
}

static inline D2GameTaskStrc* TASK_GetGameTaskFromLink(D2LinkStrc* pLink)
{
    return (D2GameTaskStrc*)((char*)pLink - 0x0C);
}

// 0x00564400
static void TASK_QueueIncrement(D2TaskStrc* ptTaskQueue, int* pTaskType, int nTaskTypeIncrement)
{
    D2LinkStrc* ptTaskBalanceLink = &ptTaskQueue->pTaskBalanceLink;
    *pTaskType += nTaskTypeIncrement;
    D2LinkStrc* ptPrev;
    for (ptPrev = ptTaskBalanceLink->pPrev; ptPrev != ptTaskBalanceLink; ptPrev = ptPrev->pPrev)
    {
        if (TASK_GetTaskFromTaskQueueLink(ptPrev)->nType - *pTaskType <= 0)
        {
            break;
        }
    }
    TASK_LinkList_Insert(ptPrev, &TASK_GetTaskFromTaskType(pTaskType)->pTaskQueueLink);
}

static inline D2TaskQueueStrc* TASK_GetTaskQueueFromLink(D2LinkStrc* pLink)
{
    return (D2TaskQueueStrc*)((char*)pLink - 0x10);
}

static inline int TASK_GetScheduledTimeDelta(D2LinkStrc* pTaskLink, D2LinkStrc* pOtherTaskLink)
{
    return (int)((unsigned int)TASK_GetGameTaskFromLink(pTaskLink)->nScheduledTime
        - (unsigned int)TASK_GetGameTaskFromLink(pOtherTaskLink)->nScheduledTime);
}

// 0x00564460
void __stdcall TASK_BalanceQueues(D2TaskQueueStrc* pNewQueue)
{
    const unsigned int nGamesPerQueue = gnGamesCount / gnNumberOfTasksCreated;
    const unsigned int nExtraGames = gnGamesCount % gnNumberOfTasksCreated;
    unsigned int nOtherQueueCount = gnNumberOfTasksCreated - 1;
    if (nOtherQueueCount >= 32)
    {
        nOtherQueueCount = 32;
    }
    int nQueuesWithExtraGame = (int)(nOtherQueueCount - nExtraGames);

    for (D2LinkStrc* pQueueLink = gpTaskQueueLink.pNext; pQueueLink != &gpTaskQueueLink; pQueueLink = pQueueLink->pNext)
    {
        D2TaskQueueStrc* pQueue = TASK_GetTaskQueueFromLink(pQueueLink);
        const bool bExtraGame = --nQueuesWithExtraGame >= 0;
        const unsigned int nQueueShare = nGamesPerQueue + (bExtraGame ? 1 : 0);
        int nWalkSteps = pQueue->nGameCount - (nQueueShare == 0 ? 1 : 0);

        EnterCriticalSection(&gtTaskQueuesCriticalSections[pQueue->nQueueIndex]);
        D2LinkStrc* pLastMoved = pQueue->tGameTasks.pPrev;
        D2LinkStrc* pGameTasks = &pQueue->tGameTasks;
        D2LinkStrc* pLastKept = pLastMoved;
        for (; nWalkSteps; pLastKept = pLastKept->pNext)
        {
            --nWalkSteps;
            if (pLastKept == pGameTasks)
            {
                break;
            }
        }
        D2LinkStrc* pMoved = pLastKept->pNext;
        pLastKept->pNext = pGameTasks;
        pGameTasks->pPrev = pLastKept;
        LeaveCriticalSection(&gtTaskQueuesCriticalSections[pQueue->nQueueIndex]);
        if (pMoved == pGameTasks)
        {
            continue;
        }

        D2LinkStrc* pNewGameTasks = &pNewQueue->tGameTasks;
        pLastMoved->pNext = 0;
        D2LinkStrc* pInsertAfter = pNewGameTasks->pPrev;
        while (pInsertAfter != pNewGameTasks && TASK_GetScheduledTimeDelta(pMoved, pInsertAfter) < 0)
        {
            pInsertAfter = pInsertAfter->pPrev;
        }

        while (pInsertAfter->pNext != pNewGameTasks)
        {
            D2LinkStrc* pNextMoved = pMoved->pNext;
            pMoved->pPrev = pInsertAfter;
            pMoved->pNext = pInsertAfter->pNext;
            pMoved->pNext->pPrev = pMoved;
            pInsertAfter->pNext = pMoved;
            if (!pNextMoved)
            {
                goto next_queue;
            }
            pInsertAfter = pMoved;
            pMoved = pNextMoved;
            while (pInsertAfter->pNext != pNewGameTasks && TASK_GetScheduledTimeDelta(pMoved, pInsertAfter->pNext) > 0)
            {
                pInsertAfter = pInsertAfter->pNext;
            }
        }

        pMoved->pPrev = pInsertAfter;
        pLastMoved->pNext = pNewGameTasks;
        pInsertAfter->pNext = pMoved;
        pNewGameTasks->pPrev = pLastMoved;
next_queue:
        ;
    }

    D2LinkStrc* pLink = &pNewQueue->tQueueLink;
    if (!pLink)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x78);
        exit(-1);
    }
    pLink->pPrev = &gpTaskQueueLink;
    pLink->pNext = gpTaskQueueLink.pNext;
    gpTaskQueueLink.pNext->pPrev = pLink;
    gpTaskQueueLink.pNext = pLink;
}

void __stdcall TASK_TASK_ProcessGame(int nTaskNumber, D2TaskStrc* ptTask); // 0x005645E0

// 0x00564870
void __stdcall TASK_TASK_InitializeClock()
{
    gbHasHighResolutionClock = QueryPerformanceFrequency(&gPerformanceFrequency);
}

// 0x00564890
void __stdcall TASK_FreeAllQueueSlots()
{
    EnterCriticalSection(&gTaskSlotsCriticalSection);

    for (unsigned int i = 0; i < 32; ++i)
    {
        EnterCriticalSection(&gtTaskQueuesCriticalSections[i]);

        if (D2TaskStrc* pTask = gtTaskSlots[i])
        {
            TASK_LinkList_Remove(&pTask->pTaskQueueLink);
            FOG_FreeServerMemory(0, gtTaskSlots[i], ".\\GAME\\Task.cpp", 0x330, 0);
            gtTaskSlots[i] = 0;
        }

        LeaveCriticalSection(&gtTaskQueuesCriticalSections[i]);
    }

    gnNumberOfTasksCreated = 0;
    gnGamesCount = 0;
    LeaveCriticalSection(&gTaskSlotsCriticalSection);
}

// 0x00564940
void __stdcall TASK_Return()
{
}

// 0x00564950
void __fastcall TASK_ClearValue(void* pUnused, int* pValue)
{
    *pValue = 0;
}

// 0x00564960
int __cdecl TASK_CreateQueue()
{
    EnterCriticalSection(&gTaskSlotsCriticalSection);
    if (!gpTaskQueueLink.pPrev)
    {
        gpTaskQueueLink.pPrev = &gpTaskQueueLink;
        gpTaskQueueLink.pNext = &gpTaskQueueLink;
    }

    const int nIndex = gnNumberOfTasksCreated++ & 0x1F;
    EnterCriticalSection(&gtTaskQueuesCriticalSections[nIndex]);
    if (!gtTaskSlots[nIndex])
    {
        D2TaskStrc* pTask = (D2TaskStrc*)sub_0040B430(0, sizeof(D2TaskStrc), ".\\GAME\\Task.cpp", 0x3FB, 0);
        pTask->dwTaskQ = nIndex;
        pTask->nType = 0;
        D2LinkStrc* pBalanceLink = &pTask->pTaskBalanceLink;
        pBalanceLink->pPrev = pBalanceLink;
        pBalanceLink->pNext = pBalanceLink;
        gtTaskSlots[nIndex] = pTask;
        TASK_BalanceQueues(pTask);
    }
    LeaveCriticalSection(&gtTaskQueuesCriticalSections[nIndex]);
    LeaveCriticalSection(&gTaskSlotsCriticalSection);
    return nIndex;
}

static __forceinline void TASK_LinkList_InsertInline(D2LinkStrc* pPrev, D2LinkStrc* pLink)
{
    D2_ASSERT(pPrev, 0x6C);
    D2_ASSERT(pLink, 0x6D);
    pLink->pPrev = pPrev;
    pLink->pNext = pPrev->pNext;
    pLink->pNext->pPrev = pLink;
    pPrev->pNext = pLink;
}

static __forceinline void TASK_LinkList_PushFrontInline(D2LinkStrc* pList, D2LinkStrc* pLink)
{
    D2_ASSERT(pList, 0x77);
    D2_ASSERT(pLink, 0x78);
    TASK_LinkList_InsertInline(pList, pLink);
}

static inline void TASK_LinkList_RemoveInline(D2LinkStrc* pLink)
{
    pLink->pPrev->pNext = pLink->pNext;
    pLink->pNext->pPrev = pLink->pPrev;
}

// 0x00564A00
int __fastcall TASK_QueueGame(D2TaskGameStrc* pTaskGame, int nArg, unsigned int hGame)
{
    int bResult = 0;
    pTaskGame->nTime = TASK_GetClockTime();
    pTaskGame->nArg = nArg;
    pTaskGame->hGame = hGame;

    EnterCriticalSection(&gTaskSlotsCriticalSection);
    if (!gpTaskQueueLink.pPrev)
    {
        gpTaskQueueLink.pPrev = &gpTaskQueueLink;
        gpTaskQueueLink.pNext = &gpTaskQueueLink;
    }
    else
    {
        D2LinkStrc* pLink = gpTaskQueueLink.pNext;
        if (pLink != &gpTaskQueueLink && pLink)
        {
            D2TaskStrc* pTask = TASK_GetTaskFromTaskQueueLink(gpTaskQueueLink.pNext);
            EnterCriticalSection(&gtTaskQueuesCriticalSections[pTask->dwTaskQ]);
            TASK_LinkList_PushFrontInline(&pTask->pTaskBalanceLink, &pTaskGame->tLink);
            LeaveCriticalSection(&gtTaskQueuesCriticalSections[pTask->dwTaskQ]);
            ++pTask->nType;
            ++gnGamesCount;
            TASK_LinkList_RemoveInline(pLink);
            TASK_LinkList_InsertInline(gpTaskQueueLink.pPrev, pLink);
            bResult = 1;
        }
    }

    LeaveCriticalSection(&gTaskSlotsCriticalSection);
    return bResult;
}


static inline D2TaskQueueStrc* TASK_LockQueueSlot(int nTaskNumber)
{
    const int nIndex = nTaskNumber & 0x1F;
    EnterCriticalSection(&gtTaskQueuesCriticalSections[nIndex]);
    D2TaskQueueStrc* pQueue = gpTaskQueues_0088C708[nIndex];
    if (!pQueue)
    {
        LeaveCriticalSection(&gtTaskQueuesCriticalSections[nIndex]);
    }
    return pQueue;
}

static inline void TASK_UnlockQueueSlot(D2TaskQueueStrc* pQueue)
{
    if (pQueue)
    {
        D2_ASSERT((unsigned int)pQueue->nQueueIndex < 32, 0x97);
        LeaveCriticalSection(&gtTaskQueuesCriticalSections[pQueue->nQueueIndex]);
    }
}

// 0x00564B20
int __fastcall TASK_DequeueGame(int nTaskNumber, D2GameTaskStrc** ppTask)
{
    int nResult = 100;
    *ppTask = 0;

    D2TaskQueueStrc* pQueue = TASK_LockQueueSlot(nTaskNumber);
    if (!pQueue)
    {
        return nResult;
    }

    D2LinkStrc* const pHead = &pQueue->tGameTasks;
    D2LinkStrc* pLink = pHead->pNext;
    if (pLink != pHead && pLink)
    {
        D2GameTaskStrc* pGameTask = TASK_GetGameTaskFromLink(pLink);
        const int nTickCount = TASK_GetClockTime();
        nResult = pGameTask->nScheduledTime - nTickCount;
        if (nResult <= 0)
        {
            TASK_LinkList_Remove(pLink);
            *ppTask = pGameTask;
        }
    }

    TASK_UnlockQueueSlot(pQueue);
    return nResult;
}

// 0x00564BE0
int __fastcall TASK_GetQueueDelay(int nTaskNumber)
{
    int nResult = 100;

    D2TaskQueueStrc* pQueue = TASK_LockQueueSlot(nTaskNumber);
    if (!pQueue)
    {
        return nResult;
    }

    D2LinkStrc* const pHead = &pQueue->tGameTasks;
    D2LinkStrc* pLink = pHead->pNext;
    if (pLink != pHead && pLink)
    {
        const int nTickCount = TASK_GetClockTime();
        nResult = TASK_GetGameTaskFromLink(pLink)->nScheduledTime - nTickCount;
    }

    TASK_UnlockQueueSlot(pQueue);
    return nResult;
}

int __fastcall sub_00564B20(int nTaskNumber, int** ppTaskType)
{
    int nResult = 100;
    *ppTaskType = 0;

    D2TaskStrc* pTask = TASK_LockTaskSlot(nTaskNumber);
    if (!pTask)
    {
        return nResult;
    }

    D2LinkStrc* pLink = pTask->pTaskBalanceLink.pNext;
    if (pLink != &pTask->pTaskBalanceLink && pLink)
    {
        int* pTaskType = &((D2TaskStrc*)((char*)pLink - 0x10))->nType;
        const int nTickCount = TASK_GetClockTime();
        nResult = *pTaskType - nTickCount;
        if (nResult <= 0)
        {
            TASK_LinkList_Remove(pLink);
            *ppTaskType = pTaskType;
        }
    }

    TASK_UnlockTaskSlot(pTask);
    return nResult;
}

int __fastcall sub_00564BE0(int nTaskNumber)
{
    int nResult = 100;

    D2TaskStrc* pTask = TASK_LockTaskSlot(nTaskNumber);
    if (!pTask)
    {
        return nResult;
    }

    D2LinkStrc* pLink = pTask->pTaskBalanceLink.pNext;
    if (pLink != &pTask->pTaskBalanceLink && pLink)
    {
        const int nTickCount = TASK_GetClockTime();
        nResult = ((D2TaskStrc*)((char*)pLink - 0x10))->nType - nTickCount;
    }

    TASK_UnlockTaskSlot(pTask);
    return nResult;
}

// 0x00564C70
void __fastcall TASK_ProcessGame(int nTaskNumber, D2TaskStrc* ptTask)
{
    D2_ASSERT(ptTask->nType == 0, 0x463);

    TASK_TASK_ProcessGame(nTaskNumber, ptTask);
}

static inline void TASK_CloseGame(int nGameHashKey, int nTaskNumber, D2TaskStrc* ptTask)
{
    GAME_CloseGame(nGameHashKey);
    EnterCriticalSection(&gTaskSlotsCriticalSection);
    if (D2TaskStrc* pTaskSlot = gtTaskSlots[nTaskNumber & 0x1F])
    {
        D2LinkStrc* ptTaskQTailLink = TASK_GetLastTaskFromListHead(&gpTaskQueueLink);
        D2_ASSERT(ptTaskQTailLink, 0x2EC);
        const int nTaskSlotType = pTaskSlot->nType;
        D2TaskStrc* ptTaskQTail = TASK_GetTaskFromTaskQueueLink(ptTaskQTailLink);
        D2LinkStrc* pNewTaskLink;
        if (ptTaskQTail->nType == nTaskSlotType + 1)
        {
            EnterCriticalSection(&gtTaskQueuesCriticalSections[ptTaskQTail->dwTaskQ]);
            D2LinkStrc* ptTaskBalanceLink = TASK_GetLastTaskFromListHead(&ptTaskQTail->pTaskBalanceLink);
            D2_ASSERT(ptTaskBalanceLink, 0x2F5);
            TASK_LinkList_Remove(ptTaskBalanceLink);
            LeaveCriticalSection(&gtTaskQueuesCriticalSections[ptTaskQTail->dwTaskQ]);
            EnterCriticalSection(&gtTaskQueuesCriticalSections[pTaskSlot->dwTaskQ]);
            TASK_QueueIncrement(pTaskSlot, &TASK_GetTaskFromTaskQueueLink(ptTaskBalanceLink)->nType, 0);
            LeaveCriticalSection(&gtTaskQueuesCriticalSections[pTaskSlot->dwTaskQ]);
            --ptTaskQTail->nType;
            pNewTaskLink = ptTaskQTailLink;
        }
        else
        {
            pTaskSlot->nType = nTaskSlotType - 1;
            pNewTaskLink = &pTaskSlot->pTaskQueueLink;
        }
        TASK_LinkList_Remove(pNewTaskLink);
        TASK_LinkList_PushFront(&gpTaskQueueLink, pNewTaskLink);
        FOG_Free(ptTask, ".\\GAME\\Task.cpp", 0x309, 0);
    }
    --gnGamesCount;
    LeaveCriticalSection(&gTaskSlotsCriticalSection);
}

void __stdcall TASK_TASK_ProcessGame(int nTaskNumber, D2TaskStrc* ptTask)
{
    const int nGameHashKey = (int)ptTask->pTaskBalanceLink.pPrev;
    D2GameStrc* pGame = GAME_LockGame(nGameHashKey);
    if (!pGame)
    {
        return;
    }
    GAME_UpdateProgress(pGame);
    sub_6FC39270(pGame, 0);
// build: symbol ?SYSTEM_GetSyncTime@* 0x00410A80
    const int nTime = SYSTEM_GetSyncTime();
    const unsigned int nSyncTimer = pGame->nSyncTimer;
    if (nSyncTimer == 1 || nTime - nSyncTimer > 1800)
    {
        D2ClientStrc* pNext;
        for (D2ClientStrc* pClient = pGame->pClientList; pClient; pClient = pNext)
        {
            pNext = pClient->pNext;
            D2GAME_PACKETS_SendGameLeft(pClient->dwClientId);
            sub_0053B240_SendHeaderOnly0x06(pClient->dwClientId);
            ClientRemoveFromGame(pGame, pClient->dwClientId, 0);
        }
    }
    else
    {
        const unsigned long nTick = GetTickCount();
        if (pGame->nClients)
        {
            pGame->nTickCountSinceNoClients = 0;
        }
        else
        {
            if (!pGame->nTickCountSinceNoClients)
            {
                pGame->nTickCountSinceNoClients = nTick;
            }
            if (nTick - pGame->nTickCountSinceNoClients > 300000 || pGame->dwGameFrame > 1500 && pGame->dwGameFrame < 7500)
            {
                goto close_game;
            }
        }
        GAME_LeaveGamesCriticalSection(pGame);
        const int nTaskSlotIdx = nTaskNumber & 0x1F;
        EnterCriticalSection(&gtTaskQueuesCriticalSections[nTaskSlotIdx]);
        if (D2TaskStrc* ptTaskQ = gtTaskSlots[nTaskSlotIdx])
        {
            TASK_QueueIncrement(ptTaskQ, &ptTask->dwTaskQ, 40);
            D2_ASSERT(ptTaskQ->dwTaskQ < 32, 0x97);
            LeaveCriticalSection(&gtTaskQueuesCriticalSections[ptTaskQ->dwTaskQ]);
        }
        else
        {
            LeaveCriticalSection(&gtTaskQueuesCriticalSections[nTaskSlotIdx]);
        }
        return;
    }
close_game:
    GAME_LeaveGamesCriticalSection(pGame);
    TASK_CloseGame(nGameHashKey, nTaskNumber, ptTask);
}

