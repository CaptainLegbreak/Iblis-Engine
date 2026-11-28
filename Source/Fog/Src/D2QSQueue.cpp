#include "Fog.h"
#include "D2SysTypes.h"
#include "FogApi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2QSMessageStrc;
struct D2QSQueueStrc;

struct D2QSMessageStrc
{
    unsigned short nLength;
    unsigned char unk_02[2];
    D2QSMessageStrc* pNext;
    unsigned char pData[1];
};

struct D2QSQueueStrc
{
    int bOverflow;
    D2CriticalSectionStrc tLock;
    D2QSMessageStrc* pHead;
    D2QSMessageStrc* pTail;

    void Destroy();
};

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pCriticalSection);

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pCriticalSection); // 0x006CC1FC

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pCriticalSection);

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pCriticalSection);

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

// 0x006C1F60
void __fastcall D2QSQUEUE_InitQueue(D2QSQueueStrc* pQueue)
{
    pQueue->pHead = 0;
    pQueue->pTail = 0;
    pQueue->bOverflow = 0;
    InitializeCriticalSection(&pQueue->tLock);
}

// 0x006C1F80
void D2QSQueueStrc::Destroy()
{
    D2QSMessageStrc* pMessage = pHead;
    while (pHead)
    {
        pMessage = pMessage->pNext;
        FOG_Free(pHead, ".\\Src\\D2QSQueue.cpp", 0x27, 0);
        pHead = pMessage;
    }
    pTail = 0;
    pHead = 0;
    DeleteCriticalSection(&tLock);
}

// 0x006C1FD0
int __fastcall D2QSQUEUE_GetOverflow(D2QSQueueStrc* pQueue)
{
    EnterCriticalSection(&pQueue->tLock);
    int bOverflow = pQueue->bOverflow;
    LeaveCriticalSection(&pQueue->tLock);
    return bOverflow;
}

// 0x006C1FF0
void __fastcall D2QSQUEUE_Push(D2QSQueueStrc* pQueue, const void* pSource, unsigned short nLength)
{
    D2_ASSERT(nLength > 0, 0x4A);

    EnterCriticalSection(&pQueue->tLock);
    D2QSMessageStrc* pMessage = (D2QSMessageStrc*)FOG_Alloc(nLength + 8, ".\\Src\\D2QSQueue.cpp", 0x4E, 0);
    pMessage->nLength = nLength;
    pMessage->pNext = 0;
    memcpy(pMessage->pData, pSource, nLength);
    if (!pQueue->pHead)
    {
        pQueue->pHead = pMessage;
    }
    else
    {
        pQueue->pTail->pNext = pMessage;
    }
    pQueue->pTail = pMessage;
    LeaveCriticalSection(&pQueue->tLock);
}

// 0x006C2090
int __fastcall D2QSQUEUE_Pop(D2QSQueueStrc* pQueue, void* pDest, unsigned short nMaxLength)
{
    int nLength;
    EnterCriticalSection(&pQueue->tLock);
    D2QSMessageStrc* pMessage = pQueue->pHead;
    if (pMessage)
    {
        if (pMessage->nLength > nMaxLength)
        {
            pQueue->bOverflow = 1;
            nLength = 0;
        }
        else
        {
            memcpy(pDest, pMessage->pData, pMessage->nLength);
            nLength = pMessage->nLength;
        }
        D2QSMessageStrc* pNext = pMessage->pNext;
        FOG_Free(pQueue->pHead, ".\\Src\\D2QSQueue.cpp", 0x78, 0);
        pQueue->pHead = pNext;
        if (!pNext)
        {
            pQueue->pTail = 0;
        }
    }
    else
    {
        nLength = 0;
    }
    LeaveCriticalSection(&pQueue->tLock);
    return nLength;
}
