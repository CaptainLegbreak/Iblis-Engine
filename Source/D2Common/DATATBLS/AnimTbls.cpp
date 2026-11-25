#include "D2Structs.h"
#include "D2AnimData.h"
struct D2InventoryStrc;
struct D2UnitStrc;

struct D2AnimDataBucketStrc
{
    int nbEntries;
    D2AnimDataRecordStrc aEntries[1];
};

struct D2AnimDataTableStrc
{
    void* pBinaryData;
    D2AnimDataBucketStrc* pHashTableBucket[256];
    D2AnimDataRecordStrc tDefaultRecord;
};

extern "C" const char gszDataGlobalPath[];                                                                      // 0x006D4118
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...);           // 0x006CC468
void* __fastcall ARCHIVE_AllocateBufferAndReadFile(void* hArchive, const char* szFilePath, unsigned int* pdwBytesWritten, const char* szSrcPath, int nLine); // 0x00517079
void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);               // 0x0040B430
void __fastcall sub_0040B480(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0);             // 0x0040B480
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                  // 0x00681EF0
#pragma function(memset)
unsigned int __fastcall sub_006C9A38(const char* szString);                                                    // 0x006C9A38
D2AnimDataTableStrc* __fastcall DATATBLS_GetAnimData();                                                            // 0x00611D20
void __stdcall D2Common_10884_COMPOSIT_unk(D2UnitStrc* pUnit, int nClassId, int nMode, int nUnitType, void* pInventory, char* szPath, int* pWeaponClassCode, int a8, int a9);   // 0x0064F5B0
void __stdcall D2Common_10885_COMPOSIT_unk(D2UnitStrc* hUnit, char* szPath, int* pWeaponClassCode, int bAddPathPrefix, int a5, D2InventoryStrc* pInventory, int nAnimMode); // 0x0064FA00
extern "C" const char gszEmptyAssertText;                                                                         // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                              // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                  // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                                // 0x00681E09

#define ANIM_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

// 0x0066A770
D2AnimDataTableStrc* __fastcall DATATBLS_LoadAnimDataD2(void* hArchive)
{
    D2AnimDataTableStrc* pAnimDataTable = (D2AnimDataTableStrc*)sub_0040B430(0, sizeof(D2AnimDataTableStrc), ".\\DATATBLS\\AnimTbls.cpp", 131, 0);
    memset(pAnimDataTable, 0, sizeof(D2AnimDataTableStrc));

    char szPath[260];
    wsprintfA(szPath, "%s\\AnimData.d2", gszDataGlobalPath);
    pAnimDataTable->pBinaryData = ARCHIVE_AllocateBufferAndReadFile(hArchive, szPath, 0, ".\\DATATBLS\\AnimTbls.cpp", 138);

    D2AnimDataBucketStrc* pBucket = (D2AnimDataBucketStrc*)pAnimDataTable->pBinaryData;
    for (int i = 0; i < 256; ++i)
    {
        pAnimDataTable->pHashTableBucket[i] = pBucket;
        pBucket = (D2AnimDataBucketStrc*)((char*)pBucket + sizeof(pBucket->nbEntries) + sizeof(D2AnimDataRecordStrc) * pBucket->nbEntries);
    }

    pAnimDataTable->tDefaultRecord.dwFrames = 2048;
    pAnimDataTable->tDefaultRecord.dwAnimSpeed = 256;
    return pAnimDataTable;
}

// 0x0066A830
void __fastcall DATATBLS_UnloadAnimDataD2(D2AnimDataTableStrc* pAnimData)
{
    if (pAnimData)
    {
        FOG_Free(pAnimData->pBinaryData, ".\\DATATBLS\\AnimTbls.cpp", 190, 0);
        sub_0040B480(0, pAnimData, ".\\DATATBLS\\AnimTbls.cpp", 191, 0);
    }
}

// 0x0066A8F0
static D2AnimDataRecordStrc* DATATBLS_GetAnimDataRecordFromPath(char* szPath)
{
    for (char* pChar = szPath; *pChar; ++pChar)
    {
        if (*pChar >= 'a' && *pChar <= 'z')
        {
            *pChar -= ' ';
        }
    }

    D2AnimDataTableStrc* pAnimData = DATATBLS_GetAnimData();

    unsigned int nHash = 0;
    for (char* pChar = szPath; *pChar; ++pChar)
    {
        nHash += (unsigned char)*pChar;
    }

    D2AnimDataBucketStrc* pBucket = pAnimData->pHashTableBucket[nHash & 0xFF];
    D2AnimDataRecordStrc* pRecord = pBucket->aEntries;
    for (int nLeft = pBucket->nbEntries; nLeft > 0; --nLeft, ++pRecord)
    {
        ANIM_ASSERT(sub_006C9A38(szPath) <= 8, 217);
        ANIM_ASSERT(sub_006C9A38(pRecord->szAnimDataName) <= 8, 218);
        if (((int*)szPath)[0] == ((int*)pRecord->szAnimDataName)[0] && ((int*)szPath)[1] == ((int*)pRecord->szAnimDataName)[1])
        {
            return pRecord;
        }
    }

    return 0;
}

// 0x0066A9B0
const D2AnimDataRecordStrc* __fastcall DATATBLS_GetAnimDataRecord(D2UnitStrc* pUnit, int nClassId, int nMode, int nUnitType, void* pInventory)
{
    int nWeaponClassCode = 0;
    char szPath[8] = {};
    D2Common_10884_COMPOSIT_unk(pUnit, nClassId, nMode, nUnitType, pInventory, szPath, &nWeaponClassCode, 0, 1);
    if (D2AnimDataRecordStrc* pFound = DATATBLS_GetAnimDataRecordFromPath(szPath))
    {
        return pFound;
    }

    return &DATATBLS_GetAnimData()->tDefaultRecord;
}

// 0x0066AA20
void __stdcall DATATBLS_UnitAnimInfoDebugSet(D2UnitStrc* pUnit, int nAnimSpeed)
{
    int nWeaponClassCode = 0;
    char szPath[8] = {};
    D2Common_10885_COMPOSIT_unk(pUnit, szPath, &nWeaponClassCode, 0, 1, pUnit->pInventory, -1);
    if (D2AnimDataRecordStrc* pRecord = DATATBLS_GetAnimDataRecordFromPath(szPath))
    {
        pRecord->dwAnimSpeed = nAnimSpeed;
    }
}

// 0x0066AA80
int __stdcall DATATBLS_GetAnimDataInfo(char* szPath, int* pOutLength, int* pOutAnimSpeed, int* pOutFirstFrameTagged)
{
    if (D2AnimDataRecordStrc* pRecord = DATATBLS_GetAnimDataRecordFromPath(szPath))
    {
        *pOutLength = pRecord->dwFrames;
        *pOutAnimSpeed = pRecord->dwAnimSpeed;

        unsigned int i;
        for (i = 0; i < pRecord->dwFrames; ++i)
        {
            if (i >= 144 || pRecord->pFrameFlags[i])
            {
                break;
            }
        }

        *pOutFirstFrameTagged = i;
        return 1;
    }

    D2AnimDataTableStrc* pAnimData = DATATBLS_GetAnimData();
    *pOutLength = pAnimData->tDefaultRecord.dwFrames;
    *pOutAnimSpeed = pAnimData->tDefaultRecord.dwAnimSpeed;
    *pOutFirstFrameTagged = *pOutLength;
    return 0;
}

#include "gen/data/Source/D2Common/DATATBLS/AnimTbls.inc"
