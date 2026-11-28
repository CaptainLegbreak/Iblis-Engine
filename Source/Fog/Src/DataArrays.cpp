#include "Fog.h"
#include "FogApi.h"

struct D2DataArrayStrc
{
    char szName[0x100];             // 0x000
    int nCount;                     // 0x100
    int nStride;                    // 0x104
    int bInitialized;               // 0x108
    int nFirstFree;                 // 0x10C
    int nLastUsed;                  // 0x110
    int nUsed;                      // 0x114
    unsigned short nSequence;       // 0x118
    unsigned short unk_11A;         // 0x11A
    unsigned char* pEntries;        // 0x11C
};

extern "C" void* __cdecl memset(void*, int, unsigned int); // 0x00681EF0

extern "C" char* __cdecl strncpy(char*, const char*, unsigned int); // 0x00687330

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" __declspec(noreturn) void __cdecl exit(int code); // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

unsigned short* __fastcall DATAARRAYS_GetEntry(D2DataArrayStrc* pTable, int nHandle); // 0x006BCC10

void __fastcall DATAARRAYS_Reset(D2DataArrayStrc* pOwner); // 0x006BCAC0

// 0x006BCA10
D2DataArrayStrc* __fastcall DATAARRAYS_Create(const char* name, int count, int stride)
{
    D2DataArrayStrc* array = (D2DataArrayStrc*)FOG_Alloc(sizeof(D2DataArrayStrc) + count * stride, ".\\Src\\DataArrays.cpp", 0x34, 0);
    if (array) {
        memset(array, 0, sizeof(D2DataArrayStrc));
        strncpy(array->szName, name, 256);
        array->nStride = stride;
        array->nCount = count;
        array->pEntries = (unsigned char*)(array + 1);
        array->bInitialized = 0;
    }
    return array;
}

// 0x006BCA90
void __fastcall DATAARRAYS_Destroy(void* pBlock)
{
    memset(pBlock, 0, 0x120);
    FOG_Free(pBlock, ".\\Src\\DataArrays.cpp", 0x4C, 0);
}

// 0x006BCAC0
void __fastcall DATAARRAYS_Reset(D2DataArrayStrc* array)
{
    if (!array->bInitialized) {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x68);
        exit(-1);
    }
    array->nLastUsed = -1;
    array->nUsed = 0;
    array->nFirstFree = 0;
    array->nSequence = 0x8000;
    for (int i = 0; i < array->nCount; ++i)
        *(unsigned short*)(array->pEntries + i * array->nStride) = 0;
}

// 0x006BCB40
unsigned int __fastcall DATAARRAYS_AllocateHandle(D2DataArrayStrc* pPool)
{
    unsigned int nHandle = -1;
    if (!pPool->bInitialized)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x87);
        exit(-1);
    }
    unsigned short* pEntry = (unsigned short*)(pPool->pEntries + pPool->nStride * pPool->nFirstFree);
    for (int nIndex = pPool->nFirstFree; nIndex < pPool->nCount; ++nIndex)
    {
        if (!*pEntry)
        {
            memset(pEntry, 0, pPool->nStride);
            *pEntry = pPool->nSequence;
            ++pPool->nSequence;
            if (!pPool->nSequence)
                pPool->nSequence = 0x8000;
            ++pPool->nUsed;
            pPool->nFirstFree = nIndex + 1;
            if (pPool->nLastUsed < nIndex)
            {
                pPool->nLastUsed = nIndex;
                nHandle = *pEntry;
            }
            else
            {
                nHandle = *pEntry;
            }
            nHandle |= nIndex << 16;
            break;
        }
        pEntry = (unsigned short*)((char*)pEntry + pPool->nStride);
    }
    return nHandle;
}

// 0x006BCC90
short* __fastcall DATAARRAYS_GetEntryOrHalt(void* pDataArray, int nHandle)
{
    short* pEntry = (short*)DATAARRAYS_GetEntry((D2DataArrayStrc*)pDataArray, nHandle);
    if (!pEntry)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 253);
        exit(-1);
    }
    return pEntry;
}

// 0x006BCCC0
void __fastcall DATAARRAYS_Initialize(D2DataArrayStrc* pOwner)
{
    pOwner->bInitialized = 1;
    DATAARRAYS_Reset(pOwner);
}

// 0x006BCCD0
void __fastcall DATAARRAYS_FreeEntry(D2DataArrayStrc* pTable, int nHandle)
{
    unsigned short* pEntry = DATAARRAYS_GetEntry(pTable, nHandle);
    D2_ASSERT(pEntry, 0xFD);
    const short nIndex = (short)(nHandle >> 16);
    unsigned short* pScan = pEntry;
    *pScan = 0;
    if (nIndex < pTable->nFirstFree)
        pTable->nFirstFree = nIndex;
    if (nIndex == pTable->nLastUsed)
    {
        do
        {
            pScan = (unsigned short*)((unsigned char*)pScan - pTable->nStride);
            --pTable->nLastUsed;
        } while (pTable->nLastUsed >= 0 && !*pScan);
    }
    --pTable->nUsed;
}

// 0x006BCC10
unsigned short* __fastcall DATAARRAYS_GetEntry(D2DataArrayStrc* pTable, int nHandle)
{
    unsigned short* pResult = 0;
    if (nHandle != -1)
    {
        const short nIndex = (short)(nHandle >> 16);
        D2_ASSERT(nIndex >= 0 && nIndex < pTable->nCount, 0xDB);
        D2_ASSERT(pTable->bInitialized, 0xDE);
        unsigned short* pEntry = (unsigned short*)(pTable->pEntries + pTable->nStride * nIndex);
        const unsigned short nTag = (unsigned short)nHandle;
        if (*pEntry && (!nTag || *pEntry == nTag))
        {
            pResult = pEntry;
        }
    }
    return pResult;
}

