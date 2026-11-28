#include "Fog.h"
#include "FogApi.h"
#include "StormApi2.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2PoolSystemStrc;
struct AsyncDataEventSlot;
struct D2OverlappedStrc;
struct AsyncData;
struct AsyncDataLoadFileCallback;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct AsyncData
{
    void* hFile;
    D2PoolSystemStrc* pMemPool;
    D2OverlappedStrc tOverlapped;
    AsyncDataLoadFileCallback pAsyncOpDesc;
    AsyncDataEventSlot* pEventSlot;
    void* ptBuffer;
    unsigned int nFileSize;
    int nPriority;
    unsigned int dwFlags;
    int nPreviousPriority;
    AsyncData* pNextPostponedPriorityChange;
};

struct AsyncDataEventSlot
{
    void* hEvent;
    unsigned long bSlotAvailable;
    AsyncData* pAsyncOp;
};

extern "C" __declspec(dllimport) void* __stdcall CreateEventA(void* pAttributes, int bManualReset, int bInitialState, const char* szName); // 0x006CC228
extern "C" __declspec(dllimport) unsigned long __stdcall WaitForSingleObject(void* hHandle, unsigned long dwMilliseconds); // 0x006CC230
extern "C" __declspec(dllimport) int __stdcall CloseHandle(void* hObject); // 0x006CC134
void __fastcall ASYNCDATA_Finish(AsyncData* pAsyncData); // 0x0040A4C0
int __fastcall FOG_AsyncDataTestLoaded(AsyncData* pAsyncData); // 0x0040A7F0
void __fastcall FOG_AsyncDataWaitAndGetBuffer(AsyncData* pAsyncData); // 0x0040A960
extern AsyncData* gpAsyncDataPostponed; // 0x0075AF90
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);
extern "C" __declspec(dllimport) int __stdcall ResetEvent(void* hEvent); // 0x006CC22C
int __fastcall FOG_FCloseFile(void* pArg); // 0x004068F0

int gnAsyncDataPostponeCount; // 0x0075AF8C

AsyncData* gpAsyncDataPostponed; // 0x0075AF90

int __fastcall FOG_FreePool(D2PoolSystemStrc* pMemPool, void* pFree, const char* szFile, int nLine, int n0); // 0x0040B480

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

int __fastcall FOG_FSetFilePointer(void* hFile, long nOffset, long* pnOffsetHigh, int nMethod); // 0x00406940

void* __fastcall ERRORMANAGER_PoolAlloc(void* pPool, int nSize, const char* szFile, int nLine); // 0x0040A080

void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

// 0x0040A850
void __fastcall FOG_AsyncDataSetPriority(AsyncData* pAsyncData, int nPriority)
{
    D2_ASSERT(pAsyncData, 0x1DA);
    D2_ASSERT((pAsyncData->dwFlags & 0xFFFFFFF0) == 0x41737960, 0x1DB);
    D2_ASSERT(nPriority <= 0, 0x1DC);
    if (gnAsyncDataPostponeCount > 0)
    {
        if (pAsyncData->dwFlags & 8)
        {
            if (nPriority > pAsyncData->nPriority)
            {
                pAsyncData->nPriority = nPriority;
            }
        }
        else
        {
            pAsyncData->nPreviousPriority = pAsyncData->nPriority;
            pAsyncData->nPriority = nPriority;
            pAsyncData->dwFlags |= 8;
            pAsyncData->pNextPostponedPriorityChange = gpAsyncDataPostponed;
            gpAsyncDataPostponed = pAsyncData;
        }
    }
    else if (nPriority != pAsyncData->nPriority)
    {
        pAsyncData->nPriority = nPriority;
        SFilePrioritizeRequest(pAsyncData->ptBuffer, nPriority);
    }
}

// 0x0040A8E0
void __fastcall FOG_AsyncDataHandlePriorityChanges(int bPostpone)
{
    if (bPostpone)
    {
        ++gnAsyncDataPostponeCount;
        return;
    }
    D2_ASSERT(gnAsyncDataPostponeCount > 0, 0x211);
    if (--gnAsyncDataPostponeCount == 0)
    {
        AsyncData* pNext;
        for (AsyncData* p = gpAsyncDataPostponed; p; p = pNext)
        {
            pNext = p->pNextPostponedPriorityChange;
            if (p->nPriority != p->nPreviousPriority)
            {
                SFilePrioritizeRequest(p->ptBuffer, p->nPriority);
            }
            p->dwFlags &= ~8;
            p->nPreviousPriority = 0;
            p->pNextPostponedPriorityChange = 0;
        }
        gpAsyncDataPostponed = 0;
    }
}

static int sgfAsyncDataEnabled; // 0x0075AF94

static unsigned int gnAsyncEventSlots; // 0x0075AF98

static AsyncDataEventSlot* sgptAsyncEventArray; // 0x0075AF9C

// 0x0040A390
void __fastcall FOG_AsyncDataInitialize(int bEnable, int nUnused)
{
    D2_ASSERT(!sgfAsyncDataEnabled, 123);
    SFileSetAsyncBudget(0x40000);
    SFileSetDataChunkSize(0x4000);
    if (bEnable)
    {
        sgptAsyncEventArray = (AsyncDataEventSlot*)FOG_Alloc(0x3000, ".\\Src\\AsyncData.cpp", 136, 0);
        D2_ASSERT(sgptAsyncEventArray, 137);
        for (int i = 0; i < 0x100; i++)
        {
            AsyncDataEventSlot* pSlot = &sgptAsyncEventArray[i];
            pSlot->hEvent = CreateEventA(0, 1, 0, 0);
            pSlot->bSlotAvailable = 1;
        }
        gnAsyncEventSlots = 0x100;
        sgfAsyncDataEnabled = 1;
    }
}

// 0x0040A440
void __cdecl FOG_AsyncDataDestroy()
{
    if (sgptAsyncEventArray)
    {
        for (unsigned int i = 0; i < gnAsyncEventSlots; i++)
        {
            AsyncDataEventSlot* pSlot = &sgptAsyncEventArray[i];
            if (pSlot && pSlot->hEvent)
            {
                CloseHandle(pSlot->hEvent);
                pSlot->hEvent = 0;
            }
        }
        FOG_Free(sgptAsyncEventArray, ".\\Src\\AsyncData.cpp", 174, 0);
        sgptAsyncEventArray = 0;
        gnAsyncEventSlots = 0;
    }
    sgfAsyncDataEnabled = 0;
}

// 0x0040A4C0
void __fastcall ASYNCDATA_Finish(AsyncData* pAsyncData)
{
    if (pAsyncData->dwFlags & 1)
    {
        return;
    }
    AsyncDataEventSlot* pSlot = pAsyncData->pEventSlot;
    if (pSlot)
    {
        ResetEvent(pSlot->hEvent);
        pSlot->bSlotAvailable = 1;
        pSlot->pAsyncOp = 0;
        pAsyncData->pEventSlot = 0;
    }
    if (pAsyncData->hFile)
    {
        FOG_FCloseFile(pAsyncData->hFile);
        pAsyncData->hFile = 0;
    }
    pAsyncData->dwFlags |= 1;
    if (pAsyncData->pAsyncOpDesc.pData)
    {
        FOG_FreeServerMemory(pAsyncData->pMemPool, pAsyncData->ptBuffer, ".\\Src\\AsyncData.cpp", 215, 0);
        pAsyncData->ptBuffer = pAsyncData->pAsyncOpDesc.pData;
        pAsyncData->nFileSize = pAsyncData->pAsyncOpDesc.nFileSize;
        memset(&pAsyncData->pAsyncOpDesc, 0, sizeof(pAsyncData->pAsyncOpDesc));
    }
}

// 0x0040A550
AsyncDataEventSlot* __cdecl ASYNCDATA_GetEventSlot()
{
    if (sgfAsyncDataEnabled)
    {
        for (unsigned int i = 0; i < gnAsyncEventSlots; i++)
        {
            AsyncDataEventSlot* pSlot = &sgptAsyncEventArray[i];
            if (pSlot->bSlotAvailable)
            {
                pSlot->bSlotAvailable = 0;
                return pSlot;
            }
        }
        for (unsigned int i = 0; i < gnAsyncEventSlots; i++)
        {
            AsyncDataEventSlot* pSlot = &sgptAsyncEventArray[i];
            if (!WaitForSingleObject(pSlot->hEvent, 0))
            {
                ASYNCDATA_Finish(pSlot->pAsyncOp);
                pSlot->bSlotAvailable = 0;
                return pSlot;
            }
        }
        if (gnAsyncEventSlots < 0x400)
        {
            AsyncDataEventSlot* pSlot = &sgptAsyncEventArray[gnAsyncEventSlots++];
            pSlot->hEvent = CreateEventA(0, 1, 0, 0);
            pSlot->bSlotAvailable = 0;
            return pSlot;
        }
    }
    return 0;
}

// 0x0040A620
AsyncData* __fastcall FOG_AsyncDataLoadFileEx(D2PoolSystemStrc* pMemPool, const char* szFileName, int bAllowAsync, long nFileOffset, int nFileSize, void* pBuffer, AsyncDataLoadFileCallback* pAsyncOpDesc, int nPriority, const char* szFile, int nLine)
{
    AsyncData* pAsync = (AsyncData*)FOG_AllocPool(pMemPool, sizeof(AsyncData), ".\\Src\\AsyncData.cpp", 296, 0);
    memset(pAsync, 0, sizeof(AsyncData));
    pAsync->dwFlags = 0x41737960;
    if (!FOG_FOpenFile(szFileName, &pAsync->hFile))
    {
        FOG_FreeServerMemory(pMemPool, pAsync, ".\\Src\\AsyncData.cpp", 309, 0);
        return 0;
    }
    pAsync->pMemPool = pMemPool;
    pAsync->nPriority = nPriority;
    if (nFileOffset)
    {
        D2_ASSERT(FOG_FSetFilePointer(pAsync->hFile, nFileOffset, 0, 0) != -1, 322);
    }
    if (nFileSize <= 0)
    {
        pAsync->nFileSize = FOG_FGetFileSize(pAsync->hFile, 0);
    }
    else
    {
        pAsync->nFileSize = nFileSize;
    }
    if (pBuffer)
    {
        pAsync->dwFlags &= ~2;
    }
    else
    {
        pBuffer = ERRORMANAGER_PoolAlloc(pMemPool, pAsync->nFileSize, szFile, nLine);
        pAsync->dwFlags |= 2;
    }
    pAsync->ptBuffer = pBuffer;
    if (pAsyncOpDesc)
    {
        pAsyncOpDesc = (AsyncDataLoadFileCallback*)memcpy(&pAsync->pAsyncOpDesc, pAsyncOpDesc, sizeof(*pAsyncOpDesc));
    }
    if (bAllowAsync && sgfAsyncDataEnabled)
    {
        pAsync->pEventSlot = ASYNCDATA_GetEventSlot();
        if (!pAsync->pEventSlot)
        {
            if (pAsync->hFile)
            {
                FOG_FCloseFile(pAsync->hFile);
                pAsync->hFile = 0;
            }
            if (pAsync->dwFlags & 2)
            {
                FOG_FreeServerMemory(pMemPool, pAsync->ptBuffer, ".\\Src\\AsyncData.cpp", 388, 0);
            }
            FOG_FreeServerMemory(pMemPool, pAsync, ".\\Src\\AsyncData.cpp", 390, 0);
            return 0;
        }
        pAsync->pEventSlot->pAsyncOp = pAsync;
        pAsync->tOverlapped.hEvent = pAsync->pEventSlot->hEvent;
        pAsync->tOverlapped.Offset = nFileOffset;
        FOG_FReadFile(pAsync->hFile, pAsync->ptBuffer, pAsync->nFileSize, 0, &pAsync->tOverlapped, (int)pAsyncOpDesc, nPriority);
        return pAsync;
    }
    FOG_FReadFile(pAsync->hFile, pAsync->ptBuffer, pAsync->nFileSize, 0, 0, 0, nPriority);
    if (pAsyncOpDesc && pAsyncOpDesc->callback)
    {
        pAsyncOpDesc->callback(pAsync->ptBuffer, pAsync->nFileSize, pAsyncOpDesc);
    }
    ASYNCDATA_Finish(pAsync);
    return pAsync;
}

// 0x0040AA80
void __fastcall ASYNCDATA_ReplaceBuffer(AsyncData* ptAsyncData, int nUnused, void* pBuffer, unsigned int nBufferSize)
{
    D2_ASSERT(ptAsyncData, 638);
    D2_ASSERT((ptAsyncData->dwFlags & 0xFFFFFFF0) == 0x41737960, 639);
    D2_ASSERT(ptAsyncData->dwFlags & 1, 641);
    FOG_FreePool(ptAsyncData->pMemPool, ptAsyncData->ptBuffer, ".\\Src\\AsyncData.cpp", 644, 0);
    ptAsyncData->ptBuffer = pBuffer;
    ptAsyncData->nFileSize = nBufferSize;
}

// 0x0040A7F0
int __fastcall FOG_AsyncDataTestLoaded(AsyncData* ptAsyncData)
{
    if (!ptAsyncData)
    {
        return 0;
    }
    D2_ASSERT((ptAsyncData->dwFlags & 0xFFFFFFF0) == 0x41737960, 452);
    if (!(ptAsyncData->dwFlags & 1))
    {
        if (!WaitForSingleObject(ptAsyncData->pEventSlot->hEvent, 0))
        {
            ASYNCDATA_Finish(ptAsyncData);
        }
    }
    return ptAsyncData->dwFlags & 1;
}

// 0x0040A960
void __fastcall FOG_AsyncDataWaitAndGetBuffer(AsyncData* pAsyncData)
{
    D2_ASSERT(pAsyncData, 562);
    D2_ASSERT((pAsyncData->dwFlags & 0xFFFFFFF0) == 0x41737960, 563);

    if (!FOG_AsyncDataTestLoaded(pAsyncData))
    {
        SFilePrioritizeRequest(pAsyncData->ptBuffer, 1);
        D2_ASSERT(!WaitForSingleObject(pAsyncData->pEventSlot->hEvent, 0xFFFFFFFF), 584);
        ASYNCDATA_Finish(pAsyncData);
    }
}

// 0x0040A9E0
void* __fastcall FOG_AsyncDataGetBuffer(AsyncData* pAsyncData)
{
    D2_ASSERT(pAsyncData, 607);
    D2_ASSERT((pAsyncData->dwFlags & 0xFFFFFFF0) == 0x41737960, 608);
    if (!(pAsyncData->dwFlags & 1))
    {
        FOG_AsyncDataWaitAndGetBuffer(pAsyncData);
    }
    D2_ASSERT(pAsyncData->dwFlags & 1, 614);
    return pAsyncData->ptBuffer;
}

// 0x0040AA40
unsigned int __fastcall FOG_AsyncDataGetBufferSize(AsyncData* pAsyncData)
{
    D2_ASSERT(pAsyncData, 625);
    D2_ASSERT((pAsyncData->dwFlags & 0xFFFFFFF0) == 0x41737960, 626);
    return pAsyncData->nFileSize;
}

// 0x0040AB00
void __fastcall FOG_AsyncDataFree(AsyncData* ptAsyncData)
{
    D2_ASSERT(ptAsyncData, 656);
    D2_ASSERT((ptAsyncData->dwFlags & 0xFFFFFFF0) == 0x41737960, 657);
    if (ptAsyncData->dwFlags & 8)
    {
        for (AsyncData** ppLink = &gpAsyncDataPostponed; ppLink; ppLink = &(*ppLink)->pNextPostponedPriorityChange)
        {
            if (*ppLink == ptAsyncData)
            {
                *ppLink = ptAsyncData->pNextPostponedPriorityChange;
                break;
            }
        }
    }
    if (!FOG_AsyncDataTestLoaded(ptAsyncData))
    {
        SFileCancelRequest(ptAsyncData->ptBuffer);
        WaitForSingleObject(ptAsyncData->pEventSlot->hEvent, (unsigned long)-1);
        ASYNCDATA_Finish(ptAsyncData);
    }
    if (ptAsyncData->dwFlags & 2)
    {
        D2_ASSERT(ptAsyncData->ptBuffer, 707);
        FOG_FreeServerMemory(ptAsyncData->pMemPool, ptAsyncData->ptBuffer, ".\\Src\\AsyncData.cpp", 710, 0);
        ptAsyncData->dwFlags &= 0xF;
        ptAsyncData->ptBuffer = 0;
    }
    FOG_FreeServerMemory(ptAsyncData->pMemPool, ptAsyncData, ".\\Src\\AsyncData.cpp", 717, 0);
}

// 0x0040ABE0
int __cdecl sub_0040ABE0()
{
    return 0;
}
