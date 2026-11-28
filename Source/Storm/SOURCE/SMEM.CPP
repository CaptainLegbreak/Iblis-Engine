#include "D2GameTypes.h"
#include "D2StormTypes.h"
#include "D2Win32SystemInfo.h"
#include "StormApi.h"
#include "D2ClientApi.h"

enum D2SMemBlockFlags
{
    SMEM_BLOCK_SENTINEL = 0x01,
    SMEM_BLOCK_FREE = 0x02,
    SMEM_BLOCK_LARGE = 0x04,
    SMEM_BLOCK_INDIRECT = 0x08,
    SMEM_BLOCK_PREVFREE = 0x10,
    SMEM_BLOCK_NOREPORT = 0x40,
    SMEM_BLOCK_KEEP = 0x80,
};

extern "C" __declspec(dllimport) void* __stdcall VirtualAlloc(void* pAddress, unsigned long nSize, unsigned long dwAllocationType, unsigned long dwProtect); // 0x006CC21C
extern "C" __declspec(dllimport) int __stdcall VirtualFree(void* pAddress, unsigned long nSize, unsigned long dwFreeType); // 0x006CC220
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC218
extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock);         // 0x006CC214
extern "C" __declspec(dllimport) __declspec(noreturn) void __stdcall ExitProcess(unsigned int nExitCode);   // 0x006CC2E0
extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText);                     // 0x006CC200
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...);          // 0x006CC468

int __stdcall SErrDisplayError(unsigned int nErrorCode, const char* szFile, int nLine, const char* szDescription, int bRecoverable, unsigned int nExitCode); // 0x0041CAF0
void __stdcall SErrSetLastError(unsigned int dwErrCode);                                          // 0x0041C340
void __stdcall SMemFill(void* pLocation, unsigned int nLength, unsigned char nFillWith);                    // 0x0041D2C0
void __stdcall SMemZero(void* pDest, unsigned int nSize);                                                   // 0x0041D300
void __cdecl SMemInitialize();                                                                      // 0x00411CD0
void __cdecl InitPageSize();                                                                   // 0x00411A20
void __fastcall UnlinkAndFreeHeap(D2SMemHeapStrc** ppLink);                                         // 0x00411A80
extern int gbCallerFirst;                                                                          // 0x00708340
extern unsigned int gnHeapId;                                                                      // 0x00708344
unsigned int gdwCallerId;                                                                          // 0x007768A8
unsigned int gdwCallerWord;                                                                        // 0x007768AC
int gnCallerLine;                                                                                  // 0x007768B0
const char* gszCallerFile;                                                                         // 0x007768B4
extern D2SMemHeapStrc* gapFreeBlocks_007768B8[0x100];                                                       // 0x007768B8
static unsigned int gnPageSize;                                                                    // 0x00776CB8
extern unsigned long gnFlag2;                                                                                // 0x00776CBC
D2CriticalSectionStrc gaFreeBlockLocks_00776CC0[0x100];                                                     // 0x00776CC0
extern int gnFlag1;                                                                                // 0x007784C0
extern unsigned long gnFlag0;                                                                                // 0x007784C4
extern D2SMemHeapStrc* gpFreeBlockSweep;                                                           // 0x007788C8
int gnFlag3;                                                                                       // 0x007788CC
int gbHeapInitialized;                                                                             // 0x007788D0
extern int gnLeakReportMode;                                                                                 // 0x00779098

static void __stdcall ReportHeapError(const char* szFile, int nLine, unsigned int nError); // 0x004117A0
static void FreeBlock(D2SMemHeapStrc* pHeap, D2SMemBlockStrc* pBlock); // 0x00411AA0

struct SMEMHEAPDETAILS;
struct SMEMBLOCKDETAILS
{
    unsigned int size;
    void* pMemory;
    int bAllocated;
    int bValid;
    unsigned int nDataSize;
    unsigned int nHeaderSize;
    unsigned int unk_18;
};
extern "C" const char szSMemFindNextBlock[]; // 0x006CED04
extern "C" const char szSMemFindNextHeap[]; // 0x006CED18
extern "C" const char szSMemAlloc[]; // 0x006CEDCC
static inline D2SMemBlockStrc* SMemGetBlockHeader(void* pMemory)
{
    if (!pMemory)
        return 0;
    D2SMemBlockStrc* pBlock = &((D2SMemBlockStrc*)pMemory)[-1];
    if (pBlock->flags & SMEM_BLOCK_INDIRECT)
        pBlock = ((D2SMemBlockStrc**)pBlock)[-1];
    return pBlock;
}
static inline void* SMemGetBlockData(D2SMemBlockStrc* pBlock)
{
    if (!pBlock)
        return 0;
    void* pData = &pBlock[1];
    if (pBlock->flags & SMEM_BLOCK_LARGE)
        pData = *(void**)pData;
    return pData;
}

typedef void (__stdcall* SMEMDUMPCALLBACK)(void* pParam, const char* szText);

extern "C" __declspec(dllimport) void __stdcall InitializeCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC210

extern "C" __declspec(dllimport) void __stdcall DeleteCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC1FC
void __stdcall SErrReportResourceLeak(const char* szName); // 0x0041D1E0

// 0x00411620
static __declspec(noreturn) void FatalMemoryError(unsigned int nError, const char* szFile, int nLine)
{
    SErrDisplayError(nError, szFile, nLine, 0, 0, 1);
    ExitProcess(1);
}

// 0x00411670
static unsigned int GetCallerId(const char* szFile, int nLine)
{
    unsigned int dwWord = szFile ? *(const unsigned int*)szFile : 0;
    int bHit = 0;
    if (gbCallerFirst && szFile == gszCallerFile && nLine == gnCallerLine)
    {
        if (dwWord == gdwCallerWord)
            bHit = 1;
        else
            gbCallerFirst = 0;
    }
    if (!bHit)
    {
        unsigned int dwId = szFile ? SStrHash(szFile, 1, nLine) : 0;
        dwId &= 0x7FFFFFFF;
        if (!dwId)
            dwId = 1;
        gdwCallerWord = dwWord;
        gszCallerFile = szFile;
        gnCallerLine = nLine;
        gdwCallerId = dwId;
    }
    return gdwCallerId;
}

// 0x00411710
static D2SMemHeapStrc* __stdcall LockHeap(int* pLockIndex, D2SMemBlockStrc* pBlock)
{
    D2SMemHeapStrc* pHeap = (D2SMemHeapStrc*)(pBlock->tSig.wHeapHigh << 16);
    EnterCriticalSection(&gaFreeBlockLocks_00776CC0[pHeap->nLockIndex]);
    *pLockIndex = pHeap->nLockIndex;
    return pHeap;
}

// 0x004117A0
static void __stdcall ReportHeapError(const char* szFile, int nLine, unsigned int nError)
{
    SErrSetLastError(nError);
    if (gnFlag1)
    {
        SErrDisplayError(nError, szFile, nLine, 0, 1, 1);
    }
}

// 0x004117D0
static void ReleaseHeapLock(int* pLockIndex)
{
    if (*pLockIndex != -1)
    {
        LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[*pLockIndex]);
        *pLockIndex = -1;
    }
}

extern "C" void _ReadWriteBarrier(void);
#pragma intrinsic(_ReadWriteBarrier)

// 0x004117F0
static D2SMemHeapStrc* __stdcall CreateHeap(const char* szFile, int nLine, unsigned int dwId, int nLockIndex, unsigned int nPageSize, unsigned int nCommit, unsigned int nReserve)
{
    unsigned int nNameSize;
    unsigned int nHeaderSize;
    D2SMemBlockStrc tHeader;
    D2SMemHeapStrc* pHeap = (D2SMemHeapStrc*)VirtualAlloc(0, nReserve, 0x2000, 1);
    if (!pHeap)
        FatalMemoryError(8, szFile, nLine);
    if (!VirtualAlloc(pHeap, nCommit, 0x1000, 4))
        FatalMemoryError(8, szFile, nLine);
    nNameSize = (szFile ? SStrLen(szFile) : 0) + 1;
    nHeaderSize = nNameSize + 0x63;
    if (nHeaderSize & 3)
        nHeaderSize += 4 - (nHeaderSize & 3);
    pHeap->dwId = dwId;
    pHeap->pNext = gapFreeBlocks_007768B8[nLockIndex];
    _ReadWriteBarrier();
    pHeap->pFirst = (D2SMemBlockStrc*)((char*)pHeap + nHeaderSize);
    pHeap->pEnd = pHeap->pFirst;
    pHeap->nPageSize = nPageSize;
    pHeap->nCommitted = nCommit;
    pHeap->nLockIndex = nLockIndex;
    pHeap->bReportLeak = 1;
    pHeap->nFragments = 0;
    pHeap->nReserved = nReserve;
    pHeap->nLine = nLine;
    pHeap->apFree[0] = 0;
    pHeap->apFree[1] = 0;
    pHeap->apFree[2] = 0;
    pHeap->apFree[3] = 0;
    pHeap->apFree[4] = 0;
    pHeap->apFree[5] = 0;
    pHeap->apFree[6] = 0;
    pHeap->apFree[7] = 0;
    pHeap->apFree[8] = 0;
    if (szFile)
        SMemCopy(pHeap->szFile, szFile, nNameSize);
    else
        pHeap->szFile[0] = 0;
    tHeader.tSig.wHeapHigh = (unsigned short)((unsigned int)pHeap >> 16);
    tHeader.tSig.wMagic = 0x6F6D;
    pHeap->tSig = tHeader.tSig;
    gapFreeBlocks_007768B8[nLockIndex] = pHeap;
    return pHeap;
}

// 0x00411910
static int CheckPointer(void* pMemory, int bReport, const char* szFile, int nLine)
{
    if (!pMemory)
    {
        if (bReport)
            ReportHeapError(szFile, nLine, 0x85100081);
        return 0;
    }
    D2SMemBlockStrc* pBlock = &((D2SMemBlockStrc*)pMemory)[-1];
    if (pBlock->tSig.wMagic != 0x6F6D)
    {
        if (bReport)
            ReportHeapError(szFile, nLine, 0x8510007C);
        return 0;
    }
    if (pBlock->flags & SMEM_BLOCK_FREE)
    {
        if (bReport)
            ReportHeapError(szFile, nLine, 0x8510007A);
        return 0;
    }
    if ((pBlock->flags & SMEM_BLOCK_SENTINEL) && *(unsigned short*)((char*)pBlock + pBlock->bytes - pBlock->nPadding - 2) != 0x12B1 && bReport)
        ReportHeapError(szFile, nLine, 0x8510007B);
    return 1;
}

// 0x004119A0
static inline unsigned int GetFreeListIndex(unsigned int nSize)
{
    unsigned int nIndex = nSize >> 5;
    if (nIndex >= 8)
        nIndex = 8;
    return nIndex;
}

void __stdcall CalcBlockSize(unsigned int* pTotal, unsigned int* pPadding, int* pbLarge, int* pbSentinel, unsigned int nSize); // 0x004119B0

// 0x00411A50
static void __stdcall InitBlock(D2SMemHeapStrc* pHeap, D2SMemBlockStrc* pBlock, unsigned int nSize, unsigned int nPadding, unsigned char nFlags)
{
    pBlock->bytes = (unsigned short)nSize;
    pBlock->nPadding = (unsigned char)nPadding;
    pBlock->flags = nFlags;
    pBlock->tSig = pHeap->tSig;
    if (nFlags & SMEM_BLOCK_SENTINEL)
        *(unsigned short*)((char*)pBlock + nSize - nPadding - 2) = 0x12B1;
}

// 0x00411AA0
static void FreeBlock(D2SMemHeapStrc* pHeap, D2SMemBlockStrc* pBlock)
{
    unsigned int nSize;
    if (pBlock->flags & SMEM_BLOCK_LARGE)
    {
        D2SMemLargeHeaderStrc* pLarge = *(D2SMemLargeHeaderStrc**)&pBlock[1];
        if (pLarge)
        {
            nSize = pLarge[-1].nSize;
            pHeap->nLargeBytes -= nSize;
            VirtualFree((void*)((unsigned int)(pLarge - 1) & ~(gnPageSize - 1)), 0, 0x8000);
        }
        else
            nSize = 0;
    }
    else
    {
        nSize = pBlock->bytes - pBlock->nPadding - sizeof(D2SMemBlockStrc);
        if (pBlock->flags & SMEM_BLOCK_SENTINEL)
            nSize -= 2;
    }
    pHeap->nUsedBytes -= nSize;
    pHeap->nBlocks -= 1;
    pBlock->flags = (pBlock->flags & SMEM_BLOCK_PREVFREE) | SMEM_BLOCK_FREE;
    D2SMemBlockStrc* pNext = (D2SMemBlockStrc*)((char*)pBlock + pBlock->bytes);
    pBlock->nPadding = 0;
    if (pHeap->pEnd == pNext)
    {
        pBlock->pNextFree = 0;
        pHeap->pEnd = pBlock;
    }
    else
    {
        pNext->flags |= SMEM_BLOCK_PREVFREE;
        unsigned int nIndex = GetFreeListIndex(pBlock->bytes);
        pBlock->pNextFree = pHeap->apFree[nIndex];
        pHeap->apFree[nIndex] = pBlock;
        if ((pBlock->flags & SMEM_BLOCK_PREVFREE) || (pNext->flags & SMEM_BLOCK_FREE))
            pHeap->nFragments += 1;
    }
    if (!pHeap->nBlocks)
    {
        pHeap->pEnd = pHeap->pFirst;
        D2SMemBlockStrc** ppFree = pHeap->apFree;
        ppFree[0] = 0;
        ppFree[1] = 0;
        ppFree[2] = 0;
        ppFree[3] = 0;
        ppFree[4] = 0;
        ppFree[5] = 0;
        ppFree[6] = 0;
        ppFree[7] = 0;
        ppFree[8] = 0;
        pHeap->nFragments = 0;
        if (pHeap->dwId < 0x80000000)
        {
            gabFreeBlockDirty[pHeap->nLockIndex] = 1;
            gpFreeBlockSweep = pHeap;
        }
    }
}

// 0x00411B90
static void GetBlockSizes(D2SMemBlockStrc* pBlock, void* pMemory, unsigned int* pDataSize, unsigned int* pHeaderSize)
{
    if (pBlock->flags & SMEM_BLOCK_LARGE)
    {
        *pDataSize = ((D2SMemLargeHeaderStrc*)pMemory)[-1].nSize;
        *pHeaderSize = pBlock->nPadding + 0x1C;
        return;
    }
    *pHeaderSize = pBlock->nPadding + sizeof(D2SMemBlockStrc);
    if (pBlock->flags & SMEM_BLOCK_SENTINEL)
        *pHeaderSize += 2;
    *pDataSize = pBlock->bytes - *pHeaderSize;
}

// 0x00411BD0
static int CommitHeap(D2SMemHeapStrc* pHeap, unsigned int nNeeded)
{
    unsigned int nCommit = nNeeded - pHeap->nCommitted;
    if (nCommit & (pHeap->nPageSize - 1))
        nCommit += pHeap->nPageSize - (nCommit & (pHeap->nPageSize - 1));
    if (pHeap->nCommitted + nCommit > pHeap->nReserved)
        nCommit = pHeap->nReserved - pHeap->nCommitted;
    if (!VirtualAlloc((char*)pHeap + pHeap->nCommitted, nCommit, 0x1000, 4))
        return 0;
    pHeap->nCommitted += nCommit;
    return 1;
}

// 0x00411C20
static void __stdcall FillAndFreeBlock(void* pMemory, D2SMemHeapStrc* pHeap, D2SMemBlockStrc* pBlock)
{
    if (gnFlag3 && !(pBlock->flags & SMEM_BLOCK_LARGE))
        SMemFill(pMemory, pBlock->bytes - (pBlock->flags & SMEM_BLOCK_SENTINEL) * 2 - pBlock->nPadding - sizeof(D2SMemBlockStrc), 0xDD);
    FreeBlock(pHeap, pBlock);
}

// 0x00411C70
static void __stdcall SplitBlock(unsigned int* pPadding, D2SMemHeapStrc* pHeap, D2SMemBlockStrc* pBlock, unsigned int* pSize)
{
    D2SMemBlockStrc* pNext = (D2SMemBlockStrc*)((char*)pBlock + pBlock->bytes);
    unsigned int nRemain = pBlock->bytes - *pSize;
    if (pNext == pHeap->pEnd)
    {
        pHeap->pEnd = (D2SMemBlockStrc*)((char*)pBlock + *pSize);
        return;
    }
    if (nRemain >= 0x10)
    {
        D2SMemBlockStrc* pFree = (D2SMemBlockStrc*)((char*)pBlock + *pSize);
        pFree->bytes = (unsigned short)nRemain;
        pFree->nPadding = 0;
        pFree->flags = SMEM_BLOCK_FREE;
        unsigned int nIndex = GetFreeListIndex(pFree->bytes);
        pFree->pNextFree = pHeap->apFree[nIndex];
        pHeap->apFree[nIndex] = pFree;
        return;
    }
    pNext->flags &= ~SMEM_BLOCK_PREVFREE;
    *pSize += nRemain;
    *pPadding += nRemain;
}

void RebuildFreeLists(D2SMemHeapStrc* pHeap); // 0x00411DC0

// 0x00411F00
D2SMemHeapStrc** __fastcall FreeLeakedBlocks(D2SMemHeapStrc** ppLink)
{
    D2SMemHeapStrc* pHeap = *ppLink;
    int bKeep = 0;
    D2SMemBlockStrc* pBlock = pHeap->pFirst;
    while (pBlock < pHeap->pEnd)
    {
        D2SMemBlockStrc* pNext = (D2SMemBlockStrc*)((char*)pBlock + pBlock->bytes);
        if (pBlock->flags & (SMEM_BLOCK_KEEP | SMEM_BLOCK_FREE))
        {
            bKeep |= pBlock->flags & SMEM_BLOCK_KEEP;
            pBlock = pNext;
            continue;
        }
        if (!(pBlock->flags & SMEM_BLOCK_NOREPORT))
        {
            if (!gnLeakReportMode)
            {
                ReportHeapError(pHeap->szFile, pHeap->nLine, 0x8510007E);
            }
            else
            {
                char szBuffer[200];
                wsprintfA(szBuffer, "Storm Error : memory never released -- %s, %i\n", pHeap->szFile, pHeap->nLine);
                OutputDebugStringA(szBuffer);
            }
        }
        FreeBlock(pHeap, pBlock);
        pBlock = pNext;
    }
    if (!bKeep)
    {
        UnlinkAndFreeHeap(ppLink);
        return ppLink;
    }
    return &pHeap->pNext;
}

// 0x00412080
static int __stdcall GrowBlock(D2SMemBlockStrc* pBlock, unsigned int nOldSize, unsigned int nNewSize, D2SMemHeapStrc* pHeap)
{
    int bSentinel;
    int bLarge;
    unsigned int nTotal;
    unsigned int nPadding;
    CalcBlockSize(&nTotal, &nPadding, &bLarge, &bSentinel, nNewSize);
    if (nTotal > 0xFFFF || bLarge)
        return 0;
    if (nTotal <= pBlock->bytes)
    {
        unsigned int nExtra = pBlock->bytes - nTotal;
        nTotal += nExtra;
        nPadding += nExtra;
    }
    else
    {
        unsigned int nNeeded = nTotal - pBlock->bytes;
        D2SMemBlockStrc* pNewEnd = (D2SMemBlockStrc*)((char*)pBlock + nTotal);
        unsigned int nFound = 0;
        D2SMemBlockStrc* pNext = (D2SMemBlockStrc*)((char*)pBlock + pBlock->bytes);
        while (nFound < nNeeded)
        {
            if (pNext == pHeap->pEnd)
                break;
            if (!(pNext->flags & SMEM_BLOCK_FREE))
                return 0;
            nFound += pNext->bytes;
            pNext = (D2SMemBlockStrc*)((char*)pNext + pNext->bytes);
        }
        unsigned int nNewBlockSize = pBlock->bytes + (nFound > nNeeded ? nFound : nNeeded);
        if (nNewBlockSize > 0xFFFF)
            return 0;
        if (nFound < nNeeded)
        {
            unsigned int nEnd = (char*)pNewEnd - (char*)pHeap;
            if (nEnd > pHeap->nCommitted)
            {
                if (nEnd > pHeap->nReserved)
                    return 0;
                if (!CommitHeap(pHeap, nEnd))
                    return 0;
            }
            pHeap->pEnd = pNewEnd;
        }
        pBlock->bytes = (unsigned short)nNewBlockSize;
        SplitBlock(&nPadding, pHeap, pBlock, &nTotal);
        pBlock->bytes = (unsigned short)nTotal;
        if (pNewEnd != pHeap->pEnd)
        {
            pNewEnd->flags &= ~SMEM_BLOCK_PREVFREE;
            if ((pNewEnd->flags & SMEM_BLOCK_FREE) && pHeap->nFragments)
                pHeap->nFragments -= 1;
        }
        RebuildFreeLists(pHeap);
    }
    InitBlock(pHeap, pBlock, nTotal, nPadding, (pBlock->flags & ~SMEM_BLOCK_SENTINEL) | (bSentinel != 0));
    pHeap->nUsedBytes += nNewSize - nOldSize;
    return 1;
}

// 0x004121D0
static void __stdcall ShrinkBlock(D2SMemBlockStrc* pBlock, unsigned int nOldSize, unsigned int nNewSize, D2SMemHeapStrc* pHeap)
{
    int bLarge;
    int bSentinel;
    unsigned int nTotal;
    unsigned int nPadding;
    CalcBlockSize(&nTotal, &nPadding, &bLarge, &bSentinel, nNewSize);
    unsigned char nFlags = (pBlock->flags & ~SMEM_BLOCK_SENTINEL) | (bSentinel != 0);
    SplitBlock(&nPadding, pHeap, pBlock, &nTotal);
    InitBlock(pHeap, pBlock, nTotal, nPadding, nFlags);
    pHeap->nUsedBytes += nNewSize - nOldSize;
}

// 0x00412650
extern "C" int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int dwFlags)
{
    if (!gbHeapInitialized)
    {
        SMemInitialize();
        if (!gbHeapInitialized)
        {
            ReportHeapError("SMemFree()", -1, 0x8510007D);
            return 0;
        }
    }
    if (!CheckPointer(pMemory, 1, szFile, nLine))
        return 0;
    D2SMemBlockStrc* pBlock;
    if (!pMemory)
        pBlock = 0;
    else
    {
        pBlock = &((D2SMemBlockStrc*)pMemory)[-1];
        if (pBlock->flags & SMEM_BLOCK_INDIRECT)
            pBlock = ((D2SMemBlockStrc**)pBlock)[-1];
    }
    D2SMemHeapStrc* pHeap = (D2SMemHeapStrc*)(pBlock->tSig.wHeapHigh << 16);
    EnterCriticalSection(&gaFreeBlockLocks_00776CC0[pHeap->nLockIndex]);
    int nLockIndex = pHeap->nLockIndex;
    FillAndFreeBlock(pMemory, pHeap, pBlock);
    if (nLockIndex != -1)
        LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[nLockIndex]);
    return 1;
}

// 0x00412710
unsigned int __stdcall SMemGetHeapByCaller(const char* szFile, int nLine)
{
    if (!gbHeapInitialized)
    {
        SMemInitialize();
        if (!gbHeapInitialized)
        {
            ReportHeapError("SMemGetHeapByCaller()", -1, 0x8510007D);
            return 0;
        }
    }
    return GetCallerId(szFile, nLine);
}

// 0x00412760
unsigned int __stdcall SMemGetHeapByPtr(void* pMemory)
{
    if (!gbHeapInitialized)
    {
        SMemInitialize();
        if (!gbHeapInitialized)
        {
            ReportHeapError("SMemGetHeapByPtr()", -1, 0x8510007D);
            return 0;
        }
    }
    if (!CheckPointer(pMemory, 0, 0, 0))
        return 0;
    D2SMemBlockStrc* pBlock;
    if (!pMemory)
        pBlock = 0;
    else
    {
        pBlock = &((D2SMemBlockStrc*)pMemory)[-1];
        if (pBlock->flags & SMEM_BLOCK_INDIRECT)
            pBlock = ((D2SMemBlockStrc**)pBlock)[-1];
    }
    return ((D2SMemHeapStrc*)(pBlock->tSig.wHeapHigh << 16))->dwId;
}

// 0x004127E0
unsigned int __stdcall SMemGetSize(void* pMemory, const char* szFile, int nLine)
{
    if (!gbHeapInitialized)
    {
        SMemInitialize();
        if (!gbHeapInitialized)
        {
            ReportHeapError("SMemGetSize()", -1, 0x8510007D);
            return -1;
        }
    }
    if (!CheckPointer(pMemory, 1, szFile, nLine))
        return -1;
    D2SMemBlockStrc* pBlock;
    if (!pMemory)
        pBlock = 0;
    else
    {
        pBlock = &((D2SMemBlockStrc*)pMemory)[-1];
        if (pBlock->flags & SMEM_BLOCK_INDIRECT)
            pBlock = ((D2SMemBlockStrc**)pBlock)[-1];
    }
    unsigned int nHeaderSize;
    unsigned int nDataSize;
    GetBlockSizes(pBlock, pMemory, &nDataSize, &nHeaderSize);
    return nDataSize;
}

static inline int sub_A21_HeapIdInUse(unsigned int dwId)
{
    int nLockIndex = (unsigned char)dwId;
    EnterCriticalSection(&gaFreeBlockLocks_00776CC0[nLockIndex]);
    for (D2SMemHeapStrc* pHeap = gapFreeBlocks_007768B8[nLockIndex]; pHeap; pHeap = pHeap->pNext)
    {
        if (pHeap->dwId == dwId)
        {
            if (nLockIndex != -1)
                LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[nLockIndex]);
            return 1;
        }
    }
    LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[nLockIndex]);
    return 0;
}

// 0x00412870
unsigned int __stdcall SMemHeapCreate(unsigned int dwOptions, unsigned int nInitialSize, unsigned int nMaximumSize)
{
    if (!gbHeapInitialized)
    {
        SMemInitialize();
        if (!gbHeapInitialized)
        {
            ReportHeapError("SMemHeapCreate()", -1, 0x8510007D);
            return 0;
        }
    }
    if (dwOptions)
    {
        ReportHeapError("SMemHeapCreate()", -1, 0x57);
        return 0;
    }
    if (nInitialSize & 0xFFF)
        nInitialSize += 0x1000 - (nInitialSize & 0xFFF);
    if (nInitialSize <= 0x1000)
        nInitialSize = 0x1000;
    do
    {
        if (!++gnHeapId)
            gnHeapId = 0x80000000;
    } while (sub_A21_HeapIdInUse(gnHeapId));
    int nLockIndex = (unsigned char)gnHeapId;
    EnterCriticalSection(&gaFreeBlockLocks_00776CC0[nLockIndex]);
    CreateHeap(0, 0, gnHeapId, nLockIndex, 0x1000, nInitialSize, 0x10000);
    LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[nLockIndex]);
    if (!gnHeapId)
        ReportHeapError("SMemHeapCreate()", -1, 8);
    return gnHeapId;
}

// 0x00412A60
int __stdcall SMemHeapFree(unsigned int hHeap, unsigned int dwFlags, void* pMemory)
{
    if (!gbHeapInitialized)
    {
        SMemInitialize();
        if (!gbHeapInitialized)
        {
            ReportHeapError("SMemHeapFree()", -1, 0x8510007D);
            return 0;
        }
    }
    if (!CheckPointer(pMemory, 1, 0, 0))
        return 0;
    D2SMemBlockStrc* pBlock;
    if (!pMemory)
        pBlock = 0;
    else
    {
        pBlock = &((D2SMemBlockStrc*)pMemory)[-1];
        if (pBlock->flags & SMEM_BLOCK_INDIRECT)
            pBlock = ((D2SMemBlockStrc**)pBlock)[-1];
    }
    if (((D2SMemHeapStrc*)(pBlock->tSig.wHeapHigh << 16))->dwId != hHeap)
        return 0;
    int nLockIndex;
    D2SMemHeapStrc* pHeap = LockHeap(&nLockIndex, pBlock);
    FillAndFreeBlock(pMemory, pHeap, pBlock);
    if (nLockIndex != -1)
        LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[nLockIndex]);
    return pHeap != 0;
}

// 0x00412B10
unsigned int __stdcall SMemHeapSize(unsigned int hHeap, unsigned int dwFlags, void* pMemory)
{
    if (!gbHeapInitialized)
    {
        SMemInitialize();
        if (!gbHeapInitialized)
        {
            ReportHeapError("SMemHeapSize()", -1, 0x8510007D);
            return -1;
        }
    }
    if (!CheckPointer(pMemory, 1, 0, 0))
        return -1;
    D2SMemBlockStrc* pBlock;
    if (!pMemory)
        pBlock = 0;
    else
    {
        pBlock = &((D2SMemBlockStrc*)pMemory)[-1];
        if (pBlock->flags & SMEM_BLOCK_INDIRECT)
            pBlock = ((D2SMemBlockStrc**)pBlock)[-1];
    }
    if (((D2SMemHeapStrc*)(pBlock->tSig.wHeapHigh << 16))->dwId != hHeap)
        return -1;
    unsigned int nHeaderSize;
    unsigned int nDataSize;
    GetBlockSizes(pBlock, pMemory, &nDataSize, &nHeaderSize);
    return nDataSize;
}

// 0x00412BA0
static void* __stdcall AllocBlock(unsigned int nSize, unsigned char nUserFlags, D2SMemHeapStrc* pHeap)
{
    int bSentinel;
    int bLarge;
    unsigned int nPadding;
    unsigned int nTotal;
    CalcBlockSize(&nTotal, &nPadding, &bLarge, &bSentinel, nSize);
    const unsigned int nShifted = nTotal >> 5;
    unsigned int nIndex = nShifted < 8 ? nShifted : 8;
    if (pHeap->nFragments >= 4 && !pHeap->apFree[nIndex])
        RebuildFreeLists(pHeap);
    D2SMemBlockStrc** ppBest = 0;
    D2SMemBlockStrc** ppLink;
    D2SMemBlockStrc* pFree;
    unsigned int nBestDiff = 0x7FFFFFFF;
    if (!pHeap->apFree[nIndex])
    {
        unsigned int i = nIndex + 1;
        ppLink = &pHeap->apFree[nIndex];
        do
        {
            if (i >= 9)
                break;
            ++ppLink;
            ++i;
        } while (!*ppLink);
        pFree = *ppLink;
    }
    else
    {
        ppLink = &pHeap->apFree[nIndex];
        pFree = *ppLink;
    }
    if (pFree)
    {
        unsigned int nThreshold = 0x10;
        do
        {
            unsigned int nDiff = pFree->bytes - nTotal;
            if (nDiff < nBestDiff)
            {
                nBestDiff = nDiff;
                ppBest = ppLink;
                if (nDiff < nThreshold)
                    break;
                nThreshold += 4;
            }
            ppLink = &(*ppLink)->pNextFree;
            pFree = *ppLink;
        } while (pFree);
    }
    int bPrevFree = 0;
    D2SMemBlockStrc* pResult;
    if (ppBest)
    {
        pResult = *ppBest;
        bPrevFree = ((pResult->flags) & SMEM_BLOCK_PREVFREE) != 0;
        *ppBest = pResult->pNextFree;
        D2SMemBlockStrc* pNext = (D2SMemBlockStrc*)((char*)pResult + pResult->bytes);
        if (pHeap->nFragments && (bPrevFree || (pNext != pHeap->pEnd && (pNext->flags & SMEM_BLOCK_FREE))))
            pHeap->nFragments -= 1;
        SplitBlock(&nPadding, pHeap, pResult, &nTotal);
    }
    else
    {
        D2SMemBlockStrc** ppEnd = &pHeap->pEnd;
        unsigned int nEnd = (char*)*ppEnd - (char*)pHeap + nTotal;
        unsigned int const tNReserved = pHeap->nReserved;
        if (nEnd > tNReserved)
        {
            unsigned int nReserve = tNReserved < 0x10000000 ? tNReserved * 2 : tNReserved;
            D2SMemHeapStrc* pNewHeap = CreateHeap(pHeap->szFile, pHeap->nLine, pHeap->dwId, pHeap->nLockIndex, nReserve >> 3, nReserve >> 3, nReserve);
            if (!pNewHeap)
                return 0;
            pHeap->bReportLeak = 0;
            pHeap = pNewHeap;
            ppEnd = &pHeap->pEnd;
            nEnd = (char*)pHeap->pEnd - (char*)pHeap + nTotal;
        }
        if (nEnd > pHeap->nCommitted && !CommitHeap(pHeap, nEnd))
            return 0;
        pResult = *ppEnd;
        *ppEnd = (D2SMemBlockStrc*)((char*)pResult + nTotal);
    }
    pHeap->nUsedBytes += nSize;
    pHeap->nBlocks += 1;
    unsigned char nFlags = (bPrevFree ? SMEM_BLOCK_PREVFREE : 0) | (bLarge ? SMEM_BLOCK_LARGE : 0) | (bSentinel != 0) | nUserFlags;
    InitBlock(pHeap, pResult, nTotal, nPadding, nFlags);
    if (bLarge)
    {
        unsigned int nPageSize = gnPageSize;
        *(D2SMemLargeHeaderStrc**)&pResult[1] = 0;
        if (!nPageSize)
        {
            InitPageSize();
            nPageSize = gnPageSize;
        }
        unsigned int nAlloc = nSize + sizeof(D2SMemLargeHeaderStrc);
        char* pBase = 0;
        unsigned int nOffset = 0;
        if (gnFlag0 || gnFlag2)
        {
            nOffset = nPageSize - (nAlloc & (nPageSize - 1));
            int bReserve;
            if (gnFlag2)
            {
                nOffset &= nPageSize - 1;
                bReserve = 1;
            }
            else
            {
                nOffset &= gnPageSize - 4;
                bReserve = 0;
            }
            if (bReserve)
                pBase = (char*)VirtualAlloc(0, nOffset + nAlloc + 4, 0x2000, 1);
        }
        pBase = (char*)VirtualAlloc(pBase, nOffset + nAlloc, 0x1000, 4);
        if (!pBase)
        {
            FreeBlock(pHeap, pResult);
            return 0;
        }
        pBase += nOffset;
        D2SMemLargeHeaderStrc* pLarge = (D2SMemLargeHeaderStrc*)pBase;
        pLarge->nSize = nSize;
        pLarge->pBlock = pResult;
        D2SMemBlockStrc* pHdr = &pLarge->tBlock;
        pHdr->bytes = (unsigned short)((nSize + 0xFFFF) >> 16);
        pHdr->nPadding = 0;
        pHdr->flags = SMEM_BLOCK_LARGE | SMEM_BLOCK_INDIRECT;
        pHdr->tSig = pHeap->tSig;
        ++pLarge;
        *(D2SMemLargeHeaderStrc**)&pResult[1] = pLarge;
        pHeap->nLargeBytes += nSize;
        return pLarge;
    }
    return &pResult[1];
}

// 0x00412E40
static void* __stdcall AllocFromHeap(D2SMemHeapStrc* pHeap, unsigned int dwFlags, int* pLockIndex, unsigned int nSize)
{
    if (nSize > 0x7FFFFFFF)
    {
        if (*pLockIndex != -1)
        {
            LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[*pLockIndex]);
            *pLockIndex = -1;
        }
        FatalMemoryError(8, pHeap->szFile, pHeap->nLine);
    }
    void* pResult = 0;
    if (pHeap)
    {
        unsigned char nBlockFlags = 0;
        if (dwFlags & 0x4000000)
            nBlockFlags = SMEM_BLOCK_NOREPORT;
        if (dwFlags & 0x8000000)
            nBlockFlags |= SMEM_BLOCK_KEEP;
        pResult = AllocBlock(nSize, nBlockFlags, pHeap);
    }
    if (!pResult)
    {
        if (*pLockIndex != -1)
        {
            LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[*pLockIndex]);
            *pLockIndex = -1;
        }
        if (pHeap->szFile[0])
            FatalMemoryError(8, pHeap->szFile, pHeap->nLine);
        FatalMemoryError(8, "SMemHeapAlloc()", -1);
    }
    if (dwFlags & 8)
    {
        SMemZero(pResult, nSize);
        return pResult;
    }
    if (gnFlag3)
        SMemFill(pResult, nSize, 0xEE);
    return pResult;
}

// 0x00412F30
static void* __stdcall ReallocBlock(int* pLockIndex, D2SMemHeapStrc* pHeap, void* pMemory, D2SMemBlockStrc* pBlock, unsigned int dwFlags, unsigned int nNewSize)
{
    unsigned int nHeaderSize;
    unsigned int nOldSize;
    GetBlockSizes(pBlock, pMemory, &nOldSize, &nHeaderSize);
    void* pResult = 0;
    if (!(pBlock->flags & SMEM_BLOCK_LARGE))
    {
        if (nNewSize < nOldSize)
        {
            ShrinkBlock(pBlock, nOldSize, nNewSize, pHeap);
            pResult = pMemory;
        }
        else if (nNewSize > nOldSize && GrowBlock(pBlock, nOldSize, nNewSize, pHeap))
            pResult = pMemory;
    }
    if (!pResult)
    {
        if (dwFlags & 0x10)
            return 0;
        pResult = AllocFromHeap(pHeap, 0, pLockIndex, nNewSize);
        if (pResult && nOldSize && nNewSize)
            SMemCopy(pResult, pMemory, nOldSize < nNewSize ? nOldSize : nNewSize);
        FillAndFreeBlock(pMemory, pHeap, pBlock);
        if (!pResult)
            return 0;
    }
    if (nNewSize > nOldSize)
    {
        if (dwFlags & 8)
        {
            SMemZero((char*)pResult + nOldSize, nNewSize - nOldSize);
            return pResult;
        }
        if (gnFlag3)
            SMemFill((char*)pResult + nOldSize, nNewSize - nOldSize, 0xEE);
    }
    return pResult;
}

extern "C" void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int dwFlags); // 0x00413020


// 0x00413250
void* __stdcall SMemHeapAlloc(unsigned int hHeap, unsigned int dwFlags, unsigned int nSize)
{
    if (!gbHeapInitialized)
    {
        SMemInitialize();
        if (!gbHeapInitialized)
            FatalMemoryError(0x8510007D, "SMemHeapAlloc()", -1);
    }
    int nIndex = (unsigned char)hHeap;
    EnterCriticalSection(&gaFreeBlockLocks_00776CC0[nIndex]);
    int nLockIndex = nIndex;
    D2SMemHeapStrc* pHeap;
    for (pHeap = gapFreeBlocks_007768B8[nIndex]; pHeap; pHeap = pHeap->pNext)
    {
        if (pHeap->dwId == hHeap)
            break;
    }
    if (!pHeap)
    {
        LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[nIndex]);
        FatalMemoryError(6, "SMemHeapAlloc()", -1);
    }
    void* pResult = AllocFromHeap(pHeap, dwFlags, &nLockIndex, nSize);
    if (nLockIndex != -1)
        LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[nLockIndex]);
    if (gpFreeBlockSweep && gpFreeBlockSweep != pHeap)
        AUTOMAP_ReleaseFreeBlocks();
    return pResult;
}

// 0x00413310
void* __stdcall SMemHeapReAlloc(unsigned int hHeap, unsigned int dwFlags, void* pMemory, unsigned int nSize)
{
    if (!gbHeapInitialized)
    {
        SMemInitialize();
        if (!gbHeapInitialized)
            FatalMemoryError(0x8510007D, "SMemHeapReAlloc()", -1);
    }
    if (!pMemory || !CheckPointer(pMemory, 1, 0, 0))
        return SMemHeapAlloc(hHeap, dwFlags, nSize);
    D2SMemBlockStrc* pBlock = &((D2SMemBlockStrc*)pMemory)[-1];
    if (pBlock->flags & SMEM_BLOCK_INDIRECT)
        pBlock = ((D2SMemBlockStrc**)pBlock)[-1];
    if (((D2SMemHeapStrc*)(pBlock->tSig.wHeapHigh << 16))->dwId != hHeap)
        return 0;
    int nLockIndex;
    D2SMemHeapStrc* pHeap = LockHeap(&nLockIndex, pBlock);
    void* pResult = ReallocBlock(&nLockIndex, pHeap, pMemory, pBlock, dwFlags, nSize);
    ReleaseHeapLock(&nLockIndex);
    return pResult;
}

// 0x004133D0
extern "C" void* __stdcall SMemReAlloc(void* pMemory, unsigned int nSize, const char* szFile, int nLine, unsigned int dwFlags)
{
    if (!gbHeapInitialized)
    {
        SMemInitialize();
        if (!gbHeapInitialized)
            FatalMemoryError(0x8510007D, "SMemReAlloc()", -1);
    }
    if (!pMemory || !CheckPointer(pMemory, 1, szFile, nLine))
        return SMemAlloc(nSize, szFile, nLine, dwFlags);
    D2SMemBlockStrc* pBlock = &((D2SMemBlockStrc*)pMemory)[-1];
    if (pBlock->flags & SMEM_BLOCK_INDIRECT)
        pBlock = ((D2SMemBlockStrc**)pBlock)[-1];
    int nLockIndex;
    D2SMemHeapStrc* pHeap = LockHeap(&nLockIndex, pBlock);
    void* pResult = ReallocBlock(&nLockIndex, pHeap, pMemory, pBlock, dwFlags, nSize);
    if (nLockIndex != -1)
        LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[nLockIndex]);
    return pResult;
}


#include "Storm.h"
#include "D2SFileTypes.h"
#include "D2GameTypes.h"
#include "D2StormTypes.h"
#include "D2StormLink.h"


extern "C" __declspec(dllimport) void __stdcall GetSystemInfo(D2SystemInfoStrc* pInfo); // 0x006CC1F0
extern int gnFlag3; // 0x007788CC

extern int (__stdcall* gpfnReadErrorCallback_00779030)(const char* szName, unsigned long dwError, int nRetry); // 0x00779030

enum { NO_NODE = 0 };

unsigned long gnFlag0; // 0x007784C4
unsigned long gnFlag2; // 0x00776CBC
int gnFlag1; // 0x007784C0

// 0x00411700
int __stdcall sub_00411700_ToByte(unsigned char nValue)
{
    return nValue;
}

// 0x00411A20
void __cdecl InitPageSize()
{
    D2SystemInfoStrc systemInfo;
    GetSystemInfo(&systemInfo);
    gnPageSize = 1;
    while (gnPageSize < systemInfo.dwPageSize)
        gnPageSize *= 2;
}

// 0x00411D40
void __stdcall SMemSetDebugFlags(unsigned int dwValues, unsigned int dwMask)
{
    if (dwMask & 1)
        gnFlag0 = dwValues & 1;
    if (dwMask & 8)
        gnFlag3 = (dwValues >> 3) & 1;
    if (dwMask & 4)
        gnFlag2 = (dwValues >> 2) & 1;
    if (dwMask & 2)
        gnFlag1 = (dwValues >> 1) & 1;
}

// 0x00411DC0
static void RebuildFreeLists(D2SMemHeapStrc* pHeap)
{
    D2SMemBlockStrc** apTail[9];
    apTail[0] = &pHeap->apFree[0];
    apTail[1] = &pHeap->apFree[1];
    apTail[2] = &pHeap->apFree[2];
    apTail[3] = &pHeap->apFree[3];
    apTail[4] = &pHeap->apFree[4];
    apTail[5] = &pHeap->apFree[5];
    apTail[6] = &pHeap->apFree[6];
    apTail[7] = &pHeap->apFree[7];
    apTail[8] = &pHeap->apFree[8];
    D2SMemBlockStrc* pPrev = 0;
    for (D2SMemBlockStrc* pBlock = pHeap->pFirst; pBlock != pHeap->pEnd; pBlock = (D2SMemBlockStrc*)((char*)pBlock + pBlock->bytes))
    {
        if (!(pBlock->flags & SMEM_BLOCK_FREE))
            continue;
        pBlock->pNextFree = 0;
        if (pPrev)
        {
            unsigned short wPrevSize = pPrev->bytes;
            unsigned int nPrevSize = wPrevSize;
            if (pBlock == (D2SMemBlockStrc*)((char*)pPrev + nPrevSize))
            {
                unsigned short wSize = pBlock->bytes;
                unsigned int nMerged = wSize + nPrevSize;
                if (nMerged <= 0xFFFF)
                {
                    pPrev->bytes = pBlock->bytes + pPrev->bytes;
                    continue;
                }
            }
            unsigned int nIndex = GetFreeListIndex(nPrevSize);
            *apTail[nIndex] = pPrev;
            apTail[nIndex] = &pPrev->pNextFree;
        }
        pPrev = pBlock;
    }
    if (pPrev)
    {
        unsigned int nIndex = GetFreeListIndex(pPrev->bytes);
        *apTail[nIndex] = pPrev;
        apTail[nIndex] = &pPrev->pNextFree;
    }
    *apTail[0] = 0;
    *apTail[1] = 0;
    *apTail[2] = 0;
    *apTail[3] = 0;
    *apTail[4] = 0;
    *apTail[5] = 0;
    *apTail[6] = 0;
    *apTail[7] = 0;
    *apTail[8] = 0;
    pHeap->nFragments = 0;
}

// 0x004119B0
static void __stdcall CalcBlockSize(unsigned int* pTotal, unsigned int* pPadding, int* pbLarge, int* pbSentinel, unsigned int nSize)
{
    *pbLarge = gnFlag2 || nSize > 0xFE87;
    *pbSentinel = gnFlag0 && !*pbLarge;
    nSize = (*pbLarge ? 4 : nSize) + (*pbSentinel ? 2 : 0) + sizeof(D2SMemBlockStrc);
    *pTotal = nSize + ((0 - nSize) & 7);
    *pPadding = *pTotal - nSize;
}

// 0x004122F0
int __stdcall SMemFindNextBlock(unsigned int hHeap, void* pMemory, void** ppBlock, SMEMBLOCKDETAILS* pInfo)
{
    if (!gbHeapInitialized)
    {
        SMemInitialize();
        if (!gbHeapInitialized)
        {
            ReportHeapError(szSMemFindNextBlock, -1, 0x8510007D);
            return 0;
        }
    }

    int nValid = -1;
    VALIDATE(hHeap);
    VALIDATE(ppBlock);
    VALIDATE(pInfo);
    VALIDATE(pInfo->size == sizeof(SMEMBLOCKDETAILS));
    if (!nValid)
    {
        SErrSetLastError(0x57);
        return 0;
    }

    SMemZero(&pInfo->pMemory, pInfo->size - sizeof(pInfo->size));
    const unsigned int nIndex = (unsigned char)hHeap;
    D2CriticalSectionStrc* pLock = &gaFreeBlockLocks_00776CC0[nIndex];
    EnterCriticalSection(pLock);

    D2SMemBlockStrc* pAfter = SMemGetBlockHeader(pMemory);
    D2SMemBlockStrc* pPrevious = 0;
    D2SMemBlockStrc* pBlock = 0;
    int bFound = 0;
    D2SMemHeapStrc* pHeap = (gapFreeBlocks_007768B8[nIndex]);
    while (pHeap)
    {
        if (!pHeap->pNext)
            break;
        pHeap = pHeap->pNext;
    }

    while (pHeap)
    {
        if (bFound)
            break;
        if (pHeap->dwId == hHeap)
        {
            for (pBlock = pHeap->pFirst; pBlock != pHeap->pEnd;
                 pBlock = (D2SMemBlockStrc*)((char*)pBlock + pBlock->bytes))
            {
                if (pPrevious == pAfter)
                {
                    bFound = 1;
                    break;
                }
                pPrevious = pBlock;
            }
        }
        if (pHeap == (gapFreeBlocks_007768B8[nIndex]))
            break;
        D2SMemHeapStrc* pNext = pHeap;
        pHeap = (gapFreeBlocks_007768B8[nIndex]);
        while (pHeap->pNext != pNext)
            pHeap = pHeap->pNext;
    }

    if (!bFound)
    {
        *ppBlock = 0;
        LeaveCriticalSection(pLock);
        return 0;
    }

    void* pResult = SMemGetBlockData(pBlock);
    *ppBlock = pResult;
    pInfo->pMemory = pResult;
    pInfo->bAllocated = !(pBlock->flags & SMEM_BLOCK_FREE);
    pInfo->bValid = CheckPointer(pResult, 0, 0, 0);
    GetBlockSizes(pBlock, pResult, &pInfo->nDataSize, &pInfo->nHeaderSize);
    LeaveCriticalSection(pLock);
    return 1;
}

// 0x004124B0
int __stdcall SMemFindNextHeap(unsigned int hPrev, unsigned int* phNext, SMEMHEAPDETAILS* pInfo)
{
    if (!gbHeapInitialized)
    {
        SMemInitialize();
        if (!gbHeapInitialized)
        {
            ReportHeapError(szSMemFindNextHeap, -1, 0x8510007D);
            return 0;
        }
    }
    VALIDATEBEGIN;
    VALIDATE(phNext);
    VALIDATE(pInfo);
    VALIDATE(pInfo->size == 0x128);
    VALIDATEEND;

    SMemZero(&pInfo->hHeap, pInfo->size - 4);

    unsigned int i = 0;
    if (hPrev)
        i = (unsigned char)hPrev;
    unsigned int dwLastId = 0;
    D2SMemHeapStrc* pHeap = 0;
    for (; i < 0x100; ++i)
    {
        EnterCriticalSection(&gaFreeBlockLocks_00776CC0[i]);
        for (pHeap = gapFreeBlocks_007768B8[i]; pHeap; pHeap = pHeap->pNext)
        {
            if (pHeap->bReportLeak)
            {
                if (dwLastId == hPrev && pHeap->dwId != hPrev)
                    break;
                dwLastId = pHeap->dwId;
            }
        }
        if (pHeap)
            break;
        LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[i]);
    }

    if (!pHeap)
    {
        *phNext = 0;
        return 0;
    }

    *phNext = pHeap->dwId;
    pInfo->hHeap = pHeap->dwId;
    pInfo->nLine = pHeap->nLine;
    pInfo->dwUnk11C = 0x7FFFFFFF;
    SStrCopy(pInfo->szName, pHeap->szFile, 0x104);
    for (; pHeap; pHeap = pHeap->pNext)
    {
        if (pHeap->dwId == *phNext)
        {
            pInfo->dwSizeA += pHeap->nCommitted + pHeap->nLargeBytes;
            pInfo->dwSizeB += pHeap->nReserved + pHeap->nLargeBytes;
            pInfo->nBlocks += pHeap->nBlocks;
            pInfo->dwSizeC += pHeap->nUsedBytes;
        }
    }
    LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[i]);
    return 1;
}

// 0x00413020
extern "C" void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int dwFlags)
{
    if (!gbHeapInitialized)
    {
        SMemInitialize();
        if (!gbHeapInitialized)
            FatalMemoryError(0x8510007D, szSMemAlloc, -1);
    }
    unsigned int dwId = GetCallerId(szFile, nLine);
    EnterCriticalSection(&gaFreeBlockLocks_00776CC0[dwId & 0xFF]);
    int nLockIndex = dwId & 0xFF;
    D2SMemHeapStrc* pFound;
    for (pFound = gapFreeBlocks_007768B8[nLockIndex]; pFound; pFound = pFound->pNext)
    {
        if (pFound->dwId == dwId)
            break;
    }
    D2SMemHeapStrc* pHeap = pFound ? pFound : CreateHeap(szFile, nLine, dwId, nLockIndex, 0x1000, 0x1000, 0x10000);
    void* pResult = AllocFromHeap(pHeap, dwFlags, &nLockIndex, nSize);
    if (nLockIndex != -1)
        LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[nLockIndex]);
    if (gpFreeBlockSweep && gpFreeBlockSweep != pHeap)
        AUTOMAP_ReleaseFreeBlocks();
    return pResult;
}

// 0x004129D0
int __stdcall SMemHeapDestroy(unsigned int hHeap)
{
    if (!gbHeapInitialized)
    {
        SMemInitialize();
        if (!gbHeapInitialized)
        {
            ReportHeapError("SMemHeapDestroy()", -1, 0x8510007D);
            return 0;
        }
    }
    int nLockIndex = (unsigned char)hHeap;
    EnterCriticalSection(&gaFreeBlockLocks_00776CC0[nLockIndex]);
    int bResult = 0;
    D2SMemHeapStrc** ppLink = &gapFreeBlocks_007768B8[nLockIndex];
    while (*ppLink)
    {
        if ((*ppLink)->dwId == hHeap)
        {
            bResult = 1;
            ppLink = FreeLeakedBlocks(ppLink);
        }
        else
        {
            ppLink = &(*ppLink)->pNext;
        }
    }
    LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[nLockIndex]);
    return bResult;
}

// 0x00413100
int __stdcall SMemDumpState(SMEMDUMPCALLBACK pfnCallback, void* pParam)
{
    if (!gbHeapInitialized)
    {
        SMemInitialize();
        if (!gbHeapInitialized)
        {
            ReportHeapError("SMemDumpState()", -1, 0x8510007D);
            return 0;
        }
    }
    VALIDATEBEGIN;
    VALIDATE(pfnCallback);
    VALIDATEEND;
    SMEMHEAPDETAILS tInfo;
    tInfo.size = 0x128;
    unsigned int hHeap = 0;
    if (SMemFindNextHeap(0, &hHeap, &tInfo))
    {
        do
        {
            char szText[0x100];
            wsprintfA(szText, "%s:%d  blocks=%u  %uk/%uk/%uk", tInfo.szName, tInfo.nLine, tInfo.nBlocks,
                (tInfo.dwSizeC + 0x200) >> 10, (tInfo.dwSizeA + 0x200) >> 10, (tInfo.dwSizeB + 0x200) >> 10);
            pfnCallback(pParam, szText);
        } while (SMemFindNextHeap(hHeap, &hHeap, &tInfo));
    }
    return nValid ? 1 : 0;
}

// 0x00411A80
void __fastcall UnlinkAndFreeHeap(D2SMemHeapStrc** ppLink)
{
    D2SMemHeapStrc* pBlock = *ppLink;
    *ppLink = pBlock->pNext;
    VirtualFree(pBlock, 0, 0x8000);
}

// 0x00411CD0
void __cdecl SMemInitialize()
{
    if (!gbHeapInitialized)
    {
        SRegLoadValue("Internal", "Debug Memory", 0, &gnFlag0);
        SRegLoadValue("Internal", "Protect Memory", 0, &gnFlag2);
        D2CriticalSectionStrc* pLock = gaFreeBlockLocks_00776CC0;
        int n = 0x100;
        do
        {
            InitializeCriticalSection(pLock);
            ++pLock;
        }
        while (--n);
        gbHeapInitialized = 1;
    }
}

// 0x00412240
int __cdecl DestroyHeaps()
{
    int i = 0;
    if (gbHeapInitialized)
    {
        gbHeapInitialized = 0;
        D2CriticalSectionStrc* pLock = gaFreeBlockLocks_00776CC0;
        int n = 0x100;
        do
        {
            EnterCriticalSection(pLock);
            D2SMemHeapStrc** ppLink = &gapFreeBlocks_007768B8[i];
            gabFreeBlockDirty[i] = 0;
            while (*ppLink)
            {
                D2SMemHeapStrc* pBlock = *ppLink;
                if (pBlock->nBlocks)
                {
                    ppLink = FreeLeakedBlocks(ppLink);
                }
                else
                {
                    if (pBlock->bReportLeak && pBlock->dwId >= 0x80000000)
                        SErrReportResourceLeak("HSHEAP");
                    UnlinkAndFreeHeap(ppLink);
                }
            }
            LeaveCriticalSection(pLock);
            DeleteCriticalSection(pLock);
            ++i;
            ++pLock;
        } while (--n);
    }
    return 1;
}

// 0x00411640
static inline char* GetBlockHeader(char* pMemory)
{
    if (!pMemory)
    {
        return pMemory;
    }
    char* pHeader = pMemory - 8;
    if (pHeader[3] & 8)
    {
        pHeader = *(char**)(pHeader - 4);
    }
    return pHeader;
}

// 0x00411660
static inline int sub_00411660_GetSegmentField(char* pBlock)
{
    return *(int*)((*(unsigned short*)(pBlock + 4) << 16) + 4);
}

int __stdcall sub_M114_Emit_00411640(char* p, char* q)
{
    return (int)GetBlockHeader(p) + sub_00411660_GetSegmentField(q);
}

// 0x004116E0
char* __fastcall GetBlockData(char* pHeader)
{
    if (!pHeader)
    {
        return 0;
    }
    char* pData = pHeader + 8;
    if (pHeader[3] & 4)
    {
        pData = *(char**)pData;
    }
    return pData;
}

// 0x00411740
static D2SMemHeapStrc* __stdcall FindFreeBlock(unsigned int dwSize, unsigned int* pHash, int bLeaveIfMissing)
{
    const unsigned int nHash = (unsigned char)dwSize;
    EnterCriticalSection(&gaFreeBlockLocks_00776CC0[nHash]);
    *pHash = nHash;
    for (D2SMemHeapStrc* pBlock = gapFreeBlocks_007768B8[nHash]; pBlock; pBlock = pBlock->pNext)
    {
        if (pBlock->dwId == dwSize)
        {
            return pBlock;
        }
    }
    if (bLeaveIfMissing)
    {
        LeaveCriticalSection(&gaFreeBlockLocks_00776CC0[nHash]);
        *pHash = -1;
    }
    return 0;
}

D2SMemHeapStrc* __stdcall sub_K01_Emit_00411740(unsigned int dwSize, unsigned int* pHash, int bLeaveIfMissing)
{
    return FindFreeBlock(dwSize, pHash, bLeaveIfMissing);
}

// 0x00411DA0
int __cdecl EnsureHeapInitialized()
{
    if (!gbHeapInitialized)
    {
        SMemInitialize();
    }
    return gbHeapInitialized;
}

extern "C" int __cdecl memcmp(const void* pBuf1, const void* pBuf2, unsigned int nSize);
extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

// 0x0041D200
int __stdcall SMemCmp(void* pLocation1, void* pLocation2, unsigned int nSize)
{
    return memcmp(pLocation1, pLocation2, nSize);
}

// 0x0041D2A0
void __stdcall SMemCopy(void* pDest, const void* pSource, unsigned int nSize)
{
    memcpy(pDest, pSource, nSize);
}

// 0x0041D2C0
void __stdcall SMemFill(void* pLocation, unsigned int nLength, unsigned char nFillWith)
{
    memset(pLocation, nFillWith, nLength);
}

// 0x0041D2E0
void __stdcall SMemMove(void* pDest, const void* pSource, unsigned int nSize)
{
    memmove(pDest, pSource, nSize);
}

// 0x0041D300
void __stdcall SMemZero(void* pLocation, unsigned int nLength)
{
    memset(pLocation, 0, nLength);
}

extern "C" const unsigned char gData_006CED03[1] = { 0 }; // 0x006CED03

extern "C" const char gData_006CED04[20] = "SMemFindNextBlock\050)"; // 0x006CED04
#pragma comment(linker, "/alternatename:_szSMemFindNextBlock_006CED04=_gData_006CED04")

extern "C" const char gData_006CED18[20] = "SMemFindNextHeap\050)"; // 0x006CED18
#pragma comment(linker, "/alternatename:_szSMemFindNextHeap_006CED18=_gData_006CED18")

extern "C" const char gData_006CEDCC[12] = "SMemAlloc()"; // 0x006CEDCC
#pragma comment(linker, "/alternatename:_szSMemAlloc_006CEDCC=_gData_006CEDCC")

extern "C" const unsigned int gData_006CEE30[16] = { // 0x006CEE30
    0x486E26EE, 0xDCAA16B3, 0xE1918EEF, 0x202DAFDB, 0x341C7DC7, 0x1C365303, 0x40EF2D37, 0x65FD5E49,
    0xD6057177, 0x904ECE93, 0x1C38024F, 0x98FD323B, 0xE3061AE7, 0xA39B0FA1, 0x9797F25F, 0xE4444563
};
#pragma comment(linker, "/alternatename:_gdwSStrHashTable_006CEE30=_gData_006CEE30")

extern "C" const unsigned __int64 gData_006CEE70[16] = { // 0x006CEE70
    0x486E26EEDCAA16B3ui64, 0xE1918EEF202DAFDBui64, 0x341C7DC71C365303ui64, 0x40EF2D3765FD5E49ui64,
    0xD6057177904ECE93ui64, 0x1C38024F98FD323Bui64, 0xE3061AE7A39B0FA1ui64, 0x9797F25FE4444563ui64,
    0xCD2EC20C8DC1B898ui64, 0x31759633799A306Dui64, 0x8C2063852E6E9627ui64, 0x79237D9973922C66ui64,
    0x8728628D28628824ui64, 0x8F1F7E9625887795ui64, 0x296E3281389C0D60ui64, 0x6F4893CA61636542ui64
};
#pragma comment(linker, "/alternatename:_gqwSStrHash64Table_006CEE70=_gData_006CEE70")

unsigned int gnHeapId = 0x80000000; // 0x00708344
