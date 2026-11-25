#include "D2GameTypes.h"
#include "D2Game.h"
#include "D2GameStrc.h"
#include "D2GameClient.h"


extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214

static D2LinkStrc gpTaskQueueLink; // 0x0088C788

static unsigned int gnGamesCount;        // 0x0088C79C

extern D2CriticalSectionStrc gtTaskQueuesCriticalSections[32]; // 0x0088C7A8

struct D2LinkStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

D2GameStrc* __fastcall GAME_LockGame(int nGameGUID);                                                        // 0x0052E860

void __fastcall GAME_UpdateProgress(D2GameStrc* pGame);                                                     // 0x0052D870

void __fastcall D2GAME_PACKETS_SendGameLeft(int nClientId);                                             // 0x0053B220

void __fastcall ClientRemoveFromGame(D2GameStrc* pGame, int nClientId, int bTriggerSave);          // 0x00539DA0

void __fastcall GAME_LeaveGamesCriticalSection(D2GameStrc* pGame);                                          // 0x0052DA90

void __fastcall GAME_CloseGame(int nGameGUID);                                                              // 0x0052E770

void __fastcall TASK_LinkList_PushFront(D2LinkStrc* pList, D2LinkStrc* pLink);                              // 0x00564250

D2LinkStrc* __fastcall TASK_LinkList_Remove(D2LinkStrc* pLink); // 0x005642E0

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0

extern "C" const char gszTaskSourceFile[];                                                                  // 0x006E11B8

extern D2TaskStrc* gtTaskSlots[32];                                                          // 0x0088C708

extern D2CriticalSectionStrc gTaskSlotsCriticalSection;                                            // 0x0088CAA8

static void TASK_QueueIncrement(D2TaskStrc*, int*, int);


int __fastcall TASK_GetClockTime();                                                                         // 0x00564340

static D2TaskStrc* TASK_GetTaskFromTaskQueueLink(D2LinkStrc* pLink)
{
    return (D2TaskStrc*)((char*)pLink - 0x10);
}

static D2TaskStrc* TASK_GetTaskFromTaskType(int* pTaskType)
{
    return (D2TaskStrc*)((char*)pTaskType - 4);
}

static D2LinkStrc* TASK_GetLastTaskFromListHead(D2LinkStrc* pListHead)
{
    return pListHead->pNext != pListHead ? pListHead->pPrev : 0;
}

static void TASK_LinkList_Insert(D2LinkStrc* pPrev, D2LinkStrc* pLink)
{
    D2_ASSERT(pPrev, 0x6C);
    D2_ASSERT(pLink, 0x6D);
    pLink->pPrev = pPrev;
    pLink->pNext = pPrev->pNext;
    pLink->pNext->pPrev = pLink;
    pPrev->pNext = pLink;
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

static __forceinline void TASK_CloseGame(int nGameHashKey, int nTaskNumber, D2TaskStrc* ptTask)
{
    GAME_CloseGame(nGameHashKey);
    EnterCriticalSection(&gTaskSlotsCriticalSection);
    if (D2TaskStrc* pTaskSlot = gtTaskSlots[nTaskNumber & 0x1F])
    {
        D2LinkStrc* ptTaskQTailLink = TASK_GetLastTaskFromListHead(&gpTaskQueueLink);
        D2_ASSERT(ptTaskQTailLink, 0x2EC);
        const int nTaskSlotType = pTaskSlot->nType;
        D2TaskStrc* ptTaskQTail = TASK_GetTaskFromTaskQueueLink(gpTaskQueueLink.pPrev);
        D2LinkStrc* pNewTaskLink = 0;
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
            TASK_LinkList_Remove(ptTaskQTailLink);
            pNewTaskLink = ptTaskQTailLink;
        }
        else
        {
            pTaskSlot->nType = nTaskSlotType - 1;
            pNewTaskLink = &pTaskSlot->pTaskQueueLink;
            TASK_LinkList_Remove(pNewTaskLink);
        }
        TASK_LinkList_PushFront(&gpTaskQueueLink, pNewTaskLink);
        FOG_Free(ptTask, gszTaskSourceFile, 0x309, 0);
    }
    --gnGamesCount;
    LeaveCriticalSection(&gTaskSlotsCriticalSection);
}

static __forceinline int sub_005645E0_IsEmptyGameExpired(D2GameStrc* pGame)
{
    int bExpired = 0;
    const unsigned long nTick = GetTickCount();
    if (!pGame->nClients)
    {
        if (!pGame->nTickCountSinceNoClients)
            pGame->nTickCountSinceNoClients = nTick;
        if (nTick - pGame->nTickCountSinceNoClients > 300000 || pGame->dwGameFrame > 1500 && pGame->dwGameFrame < 7500)
            bExpired = 1;
    }
    else
    {
        pGame->nTickCountSinceNoClients = 0;
    }

    return bExpired;
}

// 0x005645E0
void __stdcall TASK_TASK_ProcessGame(int nTaskNumber, D2TaskStrc* ptTask)
{
    const int nGameHashKey = (int)ptTask->pTaskBalanceLink.pPrev;
    if (D2GameStrc* pGame = GAME_LockGame(nGameHashKey))
    {
        GAME_UpdateProgress(pGame);
        sub_6FC39270(pGame, 0);
// build: symbol ?SYSTEM_GetSyncTime@* 0x00410A80
        const unsigned int nSyncTime = SYSTEM_GetSyncTime();
        const unsigned int nSyncTimer = pGame->nSyncTimer;
        if (nSyncTimer == 1)
            goto IoTimeout;
        if (nSyncTime - nSyncTimer > 1800)
        {
IoTimeout:
            D2ClientStrc* pNextClient;
            for (D2ClientStrc* pCurrentClient = pGame->pClientList; pCurrentClient; pCurrentClient = pNextClient)
            {
                pNextClient = pCurrentClient->pNext;
                D2GAME_PACKETS_SendGameLeft(pCurrentClient->dwClientId);
                sub_0053B240_SendHeaderOnly0x06(pCurrentClient->dwClientId);
                ClientRemoveFromGame(pGame, pCurrentClient->dwClientId, 0);
            }
        }
        else if (!sub_005645E0_IsEmptyGameExpired(pGame))
        {
            GAME_LeaveGamesCriticalSection(pGame);
            const int nTaskSlotIdx = nTaskNumber & 0x1F;
            EnterCriticalSection(&gtTaskQueuesCriticalSections[nTaskSlotIdx]);
            D2TaskStrc* ptTaskQ = gtTaskSlots[nTaskSlotIdx];
            if (!ptTaskQ)
            {
                LeaveCriticalSection(&gtTaskQueuesCriticalSections[nTaskSlotIdx]);
            }
            else
            {
                TASK_QueueIncrement(ptTaskQ, &ptTask->dwTaskQ, 40);
                D2_ASSERT((unsigned int)ptTaskQ->dwTaskQ < 32, 0x97);
                LeaveCriticalSection(&gtTaskQueuesCriticalSections[ptTaskQ->dwTaskQ]);
            }
            return;
        }

        GAME_LeaveGamesCriticalSection(pGame);
        TASK_CloseGame(nGameHashKey, nTaskNumber, ptTask);
        return;
    }
}
