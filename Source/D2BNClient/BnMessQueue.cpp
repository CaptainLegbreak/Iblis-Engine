#include "D2BNClient.h"
#include "FogApi.h"
#include "StormApi.h"

#pragma intrinsic(strlen)

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2CriticalSectionStrc;

struct D2BnStateStrc;

struct D2BnMessageStrc;

struct D2BnMessage00520440Strc;

extern "C" size_t __cdecl strlen(const char* szString);


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0


extern "C" const char gszBnMessQueueFile[]; // 0x006DF78C

extern void* gpBnStateArg; // 0x00882000

extern D2CriticalSectionStrc gtMessageLock; // 0x00882004

extern int gnBnState; // 0x0088201C

struct D2BnMessage00520440Strc
{
    unsigned char unk_000[0x128];
    D2BnMessage00520440Strc* pNext128;
};

extern D2BnMessage00520440Strc* gpMessQueueHead_00882020; // 0x00882020

char gszEmptyStateText[128]; // 0x00881F80

D2BnMessageStrc* gpMessageHead; // 0x00882020

D2BnMessageStrc* gpMessageTail; // 0x00882024

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210
extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC
extern int ganSlotArrayB[94]; // 0x008822A8
extern void* gpBnStateArg; // 0x00882000
extern D2CriticalSectionStrc gtMessageLock; // 0x00882004
extern int gnBnState; // 0x0088201C

// 0x005201E0
void __cdecl BNMESSQUEUE_InitMessageQueue()
{
// build: symbol ?gpMessageHead@* 0x00882020
    gpMessageHead = 0;
// build: symbol ?gpMessageTail@* 0x00882024
    gpMessageTail = 0;
    gnBnState = 0;
    InitializeCriticalSection(&gtMessageLock);
}

// 0x00520200
void __cdecl BNMESSQUEUE_DeleteQueueLock()
{
    DeleteCriticalSection(&gtMessageLock);
}

// 0x00520210
int __fastcall BNMESSQUEUE_QueueMessage(int nId, const void* pData, unsigned int nLength)
{
    D2BnMessageStrc* pMessage = (D2BnMessageStrc*)FOG_Alloc(sizeof(D2BnMessageStrc), gszBnMessQueueFile, 0x37, 0);
    if (nLength > 0x120)
        nLength = 0x120;
    if (nLength)
        memcpy(pMessage->szText, pData, nLength);
    else
        pMessage->szText[0] = 0;
    pMessage->nLength = nLength;
    pMessage->nId = nId;
    pMessage->pNext = 0;
    D2_ASSERT(nLength <= 0x120, 0x44);
    EnterCriticalSection(&gtMessageLock);
    if (!gpMessageHead)
        gpMessageHead = pMessage;
    else
        gpMessageTail->pNext = pMessage;
    gpMessageTail = pMessage;
    LeaveCriticalSection(&gtMessageLock);
    return 1;
}

// 0x005202F0
int __fastcall BNMESSQUEUE_QueueText(int nId, const char* szText)
{
    D2BnMessageStrc* pMessage = (D2BnMessageStrc*)FOG_Alloc(sizeof(D2BnMessageStrc), gszBnMessQueueFile, 0x5C, 0);
    SStrCopy(pMessage->szText, szText, 0x120);
    unsigned int nLength = strlen(pMessage->szText) + 1;
    pMessage->nLength = nLength;
    pMessage->nId = nId;
    pMessage->pNext = 0;
    D2_ASSERT(nLength <= 0x120, 0x62);
    EnterCriticalSection(&gtMessageLock);
    if (!gpMessageHead)
        gpMessageHead = pMessage;
    else
        gpMessageTail->pNext = pMessage;
    gpMessageTail = pMessage;
    LeaveCriticalSection(&gtMessageLock);
    return 1;
}

// 0x005203B0
unsigned int __fastcall BNMESSQUEUE_TakeMessage(int* pId, void* pBuffer)
{
    unsigned int nLength;
    EnterCriticalSection(&gtMessageLock);
    D2BnMessageStrc* pMessage = gpMessageHead;
    if (pMessage)
    {
        memcpy(pBuffer, pMessage->szText, pMessage->nLength);
        *pId = pMessage->nId;
        nLength = pMessage->nLength;
        D2BnMessageStrc* pNext = pMessage->pNext;
        FOG_Free(gpMessageHead, gszBnMessQueueFile, 0x86, 0);
        gpMessageHead = pNext;
    }
    else
    {
        nLength = 0;
    }
    LeaveCriticalSection(&gtMessageLock);
    return nLength;
}

// 0x00520440
int __cdecl BNMESSQUEUE_FreeAllMessages()
{
    EnterCriticalSection(&gtMessageLock);
    D2BnMessage00520440Strc* pMessage = gpMessQueueHead_00882020;
    while (gpMessQueueHead_00882020)
    {
        pMessage = pMessage->pNext128;
        FOG_Free(gpMessQueueHead_00882020, ".\\BnMessQueue.cpp", 0x9F, 0);
        gpMessQueueHead_00882020 = pMessage;
    }
    LeaveCriticalSection(&gtMessageLock);
    return 1;
}

// 0x005204A0
int __fastcall BNMESSQUEUE_SetError(int nError)
{
    EnterCriticalSection(&gtMessageLock);
    if (!gnBnState)
        gnBnState = nError;
    LeaveCriticalSection(&gtMessageLock);
    return 1;
}

// 0x00520520
int __fastcall BNMESSQUEUE_SetState(int nState)
{
    EnterCriticalSection(&gtMessageLock);
    gnBnState = nState;
    LeaveCriticalSection(&gtMessageLock);
    return 1;
}

// 0x00520550
int __fastcall BNMESSQUEUE_SetStateArg(void* pArg)
{
    EnterCriticalSection(&gtMessageLock);
    gpBnStateArg = pArg;
    LeaveCriticalSection(&gtMessageLock);
    return 1;
}

// 0x00520580
int __fastcall BNMESSQUEUE_TakeState(D2BnStateStrc* pState)
{
    D2_ASSERT(pState, 0xE2);
    EnterCriticalSection(&gtMessageLock);
    pState->nState = gnBnState;
    pState->pArg = gpBnStateArg;
    if (gnBnState == 0x1B)
        pState->pArg = gszEmptyStateText;
    gnBnState = 0;
    LeaveCriticalSection(&gtMessageLock);
    return 1;
}

// 0x005205F0
int __fastcall BNMESSQUEUE_GetState(D2BnStateStrc* pState)
{
    EnterCriticalSection(&gtMessageLock);
    pState->nState = gnBnState;
    pState->pArg = gpBnStateArg;
    if (gnBnState == 0x1B)
// build: symbol ?gszEmptyStateText@* 0x00881F80
        pState->pArg = gszEmptyStateText;
    LeaveCriticalSection(&gtMessageLock);
    return 1;
}

// 0x00520C30
void __fastcall BNMESSQUEUE_SetSlot(unsigned char nIndex, int nValue)
{
    ganSlotArrayB[nIndex] = nValue;
}
