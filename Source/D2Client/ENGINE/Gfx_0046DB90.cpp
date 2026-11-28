#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Drlg.h"
#include "D2ClientTypes.h"
#include "D2CelContext.h"
#include "D2ClientGfx.h"
#include "D2Txt.h"
#include "FogApi.h"
#include "StormApi.h"
#include "D2CommonApi.h"
#include "D2CommonApi2.h"
#include "D2HellApi.h"

#define UNIT_PLAYER 0

#define UNIT_MONSTER 1

#define UNIT_OBJECT 2

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2GfxLayerStrc;

struct D2HashedFileEntryStrc;

struct D2HashedFileStrc;

struct D2GfxListNodeStrc;

struct D2MonStatsTxt;

struct D2MonStats2Txt;

struct D2MonCofInfoStrc;

struct D2CofModeEntryStrc;

struct D2GfxNodeTargetStrc;

struct D2MonGfxCacheStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837



extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" size_t __cdecl strlen(const char* szString);

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount); // 0x00687330

extern "C" char* __cdecl _strlwr(char* szString); // 0x006864E1

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468




D2UnitGfxDataStrc* __fastcall CUNIT_GetGfxData(D2UnitStrc* pUnit); // 0x00463E10


int __fastcall GFX_GetNodeValue(D2UnitStrc* pUnit, int nMode); // 0x0046E570






D2GfxLayerHeaderStrc* __fastcall sub_004DB040_GetLayerHeader(void* pGfx); // 0x004DB040

int __fastcall GFXUTIL_InitMonsterCelContext(D2GfxDataStrc* pContext, int nA, int nB, int nLayer, int nMode, unsigned int dwCode, D2HashedFileEntryStrc* pEntry, D2MonCofInfoStrc* pInfo, D2MonStatsTxt* pMonStats, int nIndex); // 0x004DBCF0

int __stdcall D2CMPSpriteValidate(D2GfxDataStrc* pContext, int nArg2, int nArg3); // 0x006001F0



extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern D2CofModeEntryStrc gaCofModeCodes[]; // 0x00712B04

extern int gnCofMemoryUsed; // 0x007A8918

extern D2HashedFileStrc gtGlobalHashedFile; // 0x007A78F0

extern D2HashedFileStrc gtUnitGfxHashedFile; // 0x007A8100

static int __stdcall GFX_LoadGfxNode(int* pValue, int nIndex, D2UnitStrc* pUnit); // 0x0046E740

static int GFX_LoadGfxNodeSetByte(D2UnitStrc* pUnit, int nIndex); // 0x0046EA50

extern "C" const char gszPathFormat[]; // 0x006D4124

extern const char* gaszHashedFileNames[]; // 0x006D6C30

typedef unsigned long DWORD;

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260


void __fastcall GFXUTIL_GetLayerInfo(D2UnitStrc* pUnit, int nType, int nClass, int nMode, int* pDirection, int* pA, int* pB, int nArg, int nFlag); // 0x004DB2E0





D2MonGfxCacheStrc gaPlayerGfxCache[7]; // 0x007A7490

int gbPreloadForce; // 0x007A8920

extern int gbCharArchiveLoaded; // 0x007A8928

int gdwLastPreloadTick; // 0x007A8910

static void GFX_PreloadRoomUnits(int bAsync); // 0x00470070

static int __stdcall GFX_LoadUnitLayers(int bAsync, int nMode, D2UnitStrc* pUnit); // 0x0046FB60

static void __stdcall GFX_PreloadMonsterMode(int bAsync, D2UnitStrc* pUnit, int nMode); // 0x0046FDA0

static D2MonGfxCacheStrc* gpPoolBlock; // 0x007A80FC

void __fastcall GFX_ResetMonsterModeGfx(D2UnitStrc* pUnit); // 0x00470B70




extern "C" D2GfxLayerHeaderStrc* __fastcall GFXUTIL_identity(void* pGfx); // 0x004DB040

static void __stdcall GFX_BuildMonsterCofPath(int nMode, char* szPath, unsigned int* pCode, int nMonsterId); // 0x0046F490

static unsigned int GFX_HashName(const char* szName); // 0x0046DB90

static void __fastcall GFX_GetBaseName(char* szDest, const char* szPath); // 0x0046DBF0


static int GFX_RemoveGfxNode(D2UnitStrc* pUnit, D2HashedFileEntryStrc* pEntry); // 0x0046E610

static int __stdcall GFX_FindGfxNode(int nId, D2GfxListNodeStrc** ppNode, int* pValue, D2UnitStrc* pUnit, int nMode); // 0x0046E690

static int GFX_LoadMonsterGfx(D2UnitStrc* pUnit, int nIndex); // 0x0046E8D0

static int GFX_LoadObjectGfx(D2UnitStrc* pUnit, int nIndex); // 0x0046E980


static void __stdcall GFX_LoadMonsterCof(D2MonStatsTxt* pMonStatsTxtRecord, int nMode, int bLoadNow, D2MonCofInfoStrc* pInfo); // 0x0046F650




void __cdecl GFX_PreloadForce(); // 0x00470B10

static void GFX_LoadMonsterModeGfx(D2UnitStrc* pUnit, int nIndex); // 0x0046F9E0

static void GFX_LoadMonsterModeGfx(D2UnitStrc* pUnit, int nIndex); // 0x0046F9E0

static void __stdcall GFX_PreloadMonsterModes(int bAsync, D2UnitStrc* pUnit); // 0x0046FEB0

static void __stdcall GFX_PreloadPlayerMode(int bAsync, D2UnitStrc* pUnit, int nMode); // 0x0046FF50

inline int STATES_IsUnitShapeShiftedInl(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlagEx >> 3) & 1;
}

inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecordInl(int nMonsterId)
{
    return (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount) ? &sgptDataTables->pMonStatsTxt[nMonsterId] : 0;
}

inline D2MonStats2Txt* DATATBLS_GetMonStats2TxtRecordInl(int nRecordId)
{
    if (nRecordId >= 0 && nRecordId < sgptDataTables->nMonStats2TxtRecordCount)
    {
        return &sgptDataTables->pMonStats2Txt[nRecordId];
    }
    return 0;
}

// 0x0046DB90
static unsigned int GFX_HashName(const char* szName)
{
    D2_ASSERT(strlen(szName) < 8, 0x79);
    const unsigned int nHash = SStrHash(szName, 1, 0);
    unsigned int nBucket = (nHash >> 8) ^ nHash;
    nBucket = (nBucket >> 8) ^ nHash;
    nBucket = (nBucket >> 8) ^ nHash;
    return nBucket & 0x1FF;
}

// 0x0046DBF0
static void __fastcall GFX_GetBaseName(char* szDest, const char* szPath)
{
    const int nPathLength = strlen(szPath);
    if (szPath[nPathLength - 4] == 0x2E)
    {
        const char* pExt = szPath + nPathLength - 4;
        int nLength = 0;
        while (*pExt != 0x5C)
        {
            --pExt;
            ++nLength;
        }
        --nLength;
        strncpy(szDest, pExt + 1, nLength);
        szDest[nLength] = 0;
    }
}

// 0x0046DDF0
static void __stdcall GFX_LoadHashedFile(D2HashedFileStrc* pTable, const char* szFile)
{
    if (pTable->bLoaded)
    {
        return;
    }
    pTable->pData = (unsigned char*)ARCHIVE_AllocateBufferAndReadFile(D2Win_GetArchive(), szFile, &pTable->nSize, ".\\ENGINE\\Gfx.cpp", 267);
    D2_ASSERT(pTable->pData, 268);
    unsigned char* pCursor = pTable->pData;
    int nRemaining = pTable->nSize;
    gnCofMemoryUsed += nRemaining;
    while (nRemaining)
    {
        D2HashedFileEntryStrc* pEntry = (D2HashedFileEntryStrc*)pCursor;
        if (pEntry->nFlags)
        {
            pEntry->nFlags = 0;
        }
        D2_ASSERT(pEntry->nCheck <= 0x40, 294);
        pCursor += 0x18;
        pEntry->pData = pCursor;
        D2_ASSERT(strlen(pEntry->szName) < 8, 121);
        unsigned int nHash = SStrHash(pEntry->szName, 1, 0);
        unsigned int nBucket = nHash;
        for (int i = 0; i < 3; i++)
        {
            nBucket = (nBucket >> 8) ^ nHash;
        }
        nBucket &= 0x1FF;
        pEntry->pNext = pTable->pEntries[nBucket];
        pTable->pEntries[nBucket] = pEntry;
        pCursor += pEntry->nSize;
        nRemaining -= 0x18 + pEntry->nSize;
    }
    pTable->bLoaded = 1;
}

// 0x0046E8D0
static int GFX_LoadMonsterGfx(D2UnitStrc* pUnit, int nIndex)
{
    int nUnitType;
    int nMode;
    int nClassId;

    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }

    nUnitType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClassId = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nMode, ".\\ENGINE\\Gfx.cpp", 0x464);
    if (sub_0046C140_CheckMonStats2ModeFlag(nClassId, nIndex))
    {
        if (GFXUTIL_GetGfxEntryByte(pUnit, nIndex))
        {
            return 0;
        }
        return GFX_LoadGfxNodeSetByte(pUnit, nIndex);
    }
    D2_ASSERT(0, 0x486);
    return 0;
}

static D2HashedFileEntryStrc* __stdcall GFX_LoadHashedEntry(D2HashedFileStrc* pTable, const char* szPath)
{
    char szName[0x104] = { 0 };
    char* pName = szName;
    GFX_GetBaseName(pName, szPath);
    _strlwr(pName);
    if (!GFX_FindHashedEntry(pTable, pName))
    {
        D2HashedFileEntryStrc* pEntry = (D2HashedFileEntryStrc*)FOG_Alloc(sizeof(D2HashedFileEntryStrc), ".\\ENGINE\\Gfx.cpp", 0xDC, 0);
        memset(pEntry, 0, sizeof(D2HashedFileEntryStrc));
        pEntry->nFlags |= 1;
        strcpy(pEntry->szName, szName);
        pEntry->pData = (unsigned char*)ARCHIVE_AllocateBufferAndReadFile(D2Win_GetArchive(), szPath, (unsigned int*)&pEntry->nSize, ".\\ENGINE\\Gfx.cpp", 0xE0);
        if (!pEntry->pData)
        {
            return 0;
        }

        D2_ASSERT(pEntry->pData[2] <= 0x40, 0xEC);
        const unsigned int nBucket = GFX_HashName(szName);
        pEntry->pNext = pTable->pEntries[nBucket];
        pTable->pEntries[nBucket] = pEntry;
        gnCofMemoryUsed += pEntry->nSize + sizeof(D2HashedFileEntryStrc);
        return pEntry;
    }
    return 0;
}

// 0x0046F650
static void __stdcall GFX_LoadMonsterCof(D2MonStatsTxt* pMonStatsTxtRecord, int nMode, int bLoadNow, D2MonCofInfoStrc* pInfo)
{
    char szPath[0x104] = { 0 };
    unsigned int dwCode;
    GFX_BuildMonsterCofPath(nMode, szPath, &dwCode, pInfo->nMonsterId);

    D2HashedFileEntryStrc* pEntry = GFX_FindHashedEntry(&gtGlobalHashedFile, szPath);
    if (!pEntry)
    {
        pEntry = GFX_LoadHashedEntry(&gtGlobalHashedFile, szPath);
        D2_ASSERT(pEntry, 0xEC3);
    }

    unsigned char* pData = pEntry->pData;
    D2_ASSERT(pData, 0xEC9);
    D2GfxLayerHeaderStrc* pHeader = sub_004DB040_GetLayerHeader(pData);
    D2_ASSERT(pHeader, 0xECB);
    unsigned char* pOrder = GFXUTIL_GetLayerOrder(pData, 0, 0);
    D2_ASSERT(pOrder, 0xED0);

    for (int i = 0; i < pHeader->nLayers; ++i)
    {
        const int nLayer = pOrder[i];
        D2_ASSERT(nLayer < 0x10, 0xED7);
        if (pInfo->nCount)
        {
            for (unsigned int j = 0; j < pInfo->nCount; ++j)
            {
                D2GfxDataStrc tContext;
                memset(&tContext, 0, sizeof(tContext));
                if (GFXUTIL_InitMonsterCelContext(&tContext, 0, 0, nLayer, nMode, dwCode, pEntry, pInfo, pMonStatsTxtRecord, j))
                {
                    if (bLoadNow)
                    {
                        if (!D2CMPSpriteValidate(&tContext, 1, 1))
                        {
                            tContext.nArg34 = 0;
                            D2CMPSpriteRequest(&tContext);
                        }
                    }
                    else
                    {
                        D2CMPSpriteValidate(&tContext, 0, 0);
                    }
                }
            }
        }
        else
        {
            D2GfxDataStrc tContext;
            memset(&tContext, 0, sizeof(tContext));
            if (GFXUTIL_InitMonsterCelContext(&tContext, 0, 0, nLayer, nMode, dwCode, pEntry, pInfo, pMonStatsTxtRecord, 0))
            {
                if (bLoadNow)
                {
                    if (!D2CMPSpriteValidate(&tContext, 1, 1))
                    {
                        tContext.nArg34 = 0;
                        D2CMPSpriteRequest(&tContext);
                    }
                }
                else
                {
                    D2CMPSpriteValidate(&tContext, 0, 0);
                }
            }
        }
    }
}

// 0x0046DC40
D2HashedFileEntryStrc* __stdcall GFX_FindHashedEntry(D2HashedFileStrc* pTable, const char* szPath)
{
    char szName[0x104] = { 0 };
    GFX_GetBaseName(szName, szPath);
    _strlwr(szName);
    for (D2HashedFileEntryStrc* pEntry = pTable->pEntries[GFX_HashName(szName)]; pEntry; pEntry = pEntry->pNext)
    {
        if (*(unsigned int*)&szName[0] == pEntry->dwName[0] && *(unsigned int*)&szName[4] == pEntry->dwName[1])
        {
            return pEntry;
        }
    }
    return 0;
}

// 0x0046E610
static int GFX_RemoveGfxNode(D2UnitStrc* pUnit, D2HashedFileEntryStrc* pEntry)
{
    D2UnitGfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
    D2_ASSERT(pGfxData, 0x3C8);

    D2GfxListNodeStrc* pPrev = 0;
    for (D2GfxListNodeStrc* pNode = pGfxData->pList; pNode; pNode = pNode->pNext)
    {
        if (pNode->pFileEntry == pEntry)
        {
            D2GfxListNodeStrc* pNext = pNode->pNext;
            FOG_Free(pNode, ".\\ENGINE\\Gfx.cpp", 0x3D0, 0);
            if (!pPrev)
            {
                pGfxData->pList = pNext;
            }
            else
            {
                pPrev->pNext = pNext;
            }
            return 1;
        }
        pPrev = pNode;
    }
    return 0;
}

// 0x0046E690
static int __stdcall GFX_FindGfxNode(int nId, D2GfxListNodeStrc** ppNode, int* pValue, D2UnitStrc* pUnit, int nMode)
{
    D2UnitGfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
    D2_ASSERT(pGfxData, 0x3F0);

    if (nMode == -1)
    {
        nMode = GFX_GetConvertedUnitMode(pUnit);
    }

    for (D2GfxListNodeStrc* pNode = pGfxData->pList; pNode; pNode = pNode->pNext)
    {
        if (pNode->nMode == nMode)
        {
            if (pNode->nId == nId)
            {
                *ppNode = pNode;
                return 0;
            }

            *ppNode = 0;
            *pValue = GFX_GetNodeValue(pUnit, nMode);
            D2_ASSERT(GFX_RemoveGfxNode(pUnit, pNode->pFileEntry), 0x406);
            return 1;
        }
    }
    return 1;
}

// 0x0046E740
static int __stdcall GFX_LoadGfxNode(int* pValue, int nIndex, D2UnitStrc* pUnit)
{
    int nId = 0;
    char szPath[0x104] = { 0 };
    if (!GFXUTIL_IsPlayerMonsterOrObject(pUnit))
    {
        return 0;
    }

    D2UnitStrc* pOwner;
    D2InventoryStrc* pInventory;
    if (STATES_IsUnitShapeShiftedInl(pUnit) && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && (pOwner = CUNIT_GetOwnerUnit(pUnit)) != 0)
    {
        pInventory = pOwner->pInventory;
    }
    else
    {
        pInventory = pUnit->pInventory;
    }

    D2Common_10885_COMPOSIT_unk(pUnit, szPath, &nId, 1, 1, pInventory, nIndex);
    if (!szPath[0])
    {
        return 0;
    }

    D2UnitGfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
    if (!pGfxData)
    {
        return 0;
    }

    if (GFX_FindGfxNode(nId, (D2GfxListNodeStrc**)&pValue, pValue, pUnit, nIndex))
    {
        D2GfxListNodeStrc* pNewNode = (D2GfxListNodeStrc*)FOG_Alloc(sizeof(D2GfxListNodeStrc), ".\\ENGINE\\Gfx.cpp", 0x434, 0);
        D2_ASSERT(pNewNode, 0x435);
        memset(pNewNode, 0, sizeof(D2GfxListNodeStrc));

        D2HashedFileStrc* pTable = !GFX_GetConvertedUnitType(pUnit) ? &gtUnitGfxHashedFile : &gtGlobalHashedFile;
        D2HashedFileEntryStrc* pEntry = GFX_FindHashedEntry(pTable, szPath);
        if (!pEntry)
        {
            pEntry = GFX_LoadHashedEntry(pTable, szPath);
            if (!pEntry)
            {
                return 0;
            }
        }

        pNewNode->nMode = nIndex;
        int& nNodeId = pNewNode->nId;
        nNodeId = nId;
        pNewNode->pFileEntry = pEntry;
        pNewNode->pNext = pGfxData->pList;
        pGfxData->pList = pNewNode;
    }

    return GFX_GetNodeValue(pUnit, nIndex);
}

// 0x0046E980
static int GFX_LoadObjectGfx(D2UnitStrc* pUnit, int nIndex)
{
    int nValue;
    int nUnitType;
    int nMode;
    int nClassId;

    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }

    nUnitType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClassId = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nMode, ".\\ENGINE\\Gfx.cpp", 0x4BE);
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClassId);
    D2_ASSERT(pObjectsTxtRecord, 0x4C2);
    if (pObjectsTxtRecord->nMode[nIndex] == 1)
    {
        if (GFXUTIL_GetGfxEntryByte(pUnit, nIndex))
        {
            return 0;
        }
        D2_ASSERT(GFX_LoadGfxNode(&nValue, nIndex, pUnit), 0x4D4);
        GFXUTIL_SetGfxEntryByte(pUnit, nIndex, 1);
        return 1;
    }
    D2_ASSERT(0, 0x4DC);
    return 0;
}

// 0x0046EA50
static int GFX_LoadGfxNodeSetByte(D2UnitStrc* pUnit, int nIndex)
{
    int nValue;
    if (!GFX_LoadGfxNode(&nValue, nIndex, pUnit))
    {
        return 0;
    }
    GFXUTIL_SetGfxEntryByte(pUnit, nIndex, 1);
    return 1;
}

// 0x0046F310
void __fastcall GFX_LoadGlobalHashedFile(unsigned char nIndex)
{
    char szPath[0x104];
    wsprintfA(szPath, gszPathFormat, gszDataGlobal, gaszHashedFileNames[nIndex]);
    GFX_LoadHashedFile(&gtGlobalHashedFile, szPath);
}

// 0x0046F490
static void __stdcall GFX_BuildMonsterCofPath(int nMode, char* szPath, unsigned int* pCode, int nMonsterId)
{
    if (!((nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount) ? (D2MonStatsTxt*)((char*)sgptDataTables->pMonStatsTxt + nMonsterId * sizeof(D2MonStatsTxt)) : 0))
    {
        return;
    }

    D2MonStats2Txt* pMonStats2TxtRecord = DATATBLS_GetMonStats2TxtRecordInl(((nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount) ? (D2MonStatsTxt*)((char*)sgptDataTables->pMonStatsTxt + nMonsterId * sizeof(D2MonStatsTxt)) : 0)->wMonStatsEx);
    if (!pMonStats2TxtRecord)
    {
        return;
    }

    unsigned int dwMonCode = ((nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount) ? (D2MonStatsTxt*)((char*)sgptDataTables->pMonStatsTxt + nMonsterId * sizeof(D2MonStatsTxt)) : 0)->dwCode;
    D2MonModeTxt* pModeTxtRecord = DATATBLS_GetMonModeTxtRecord(nMode, 1);
    D2_ASSERT(pModeTxtRecord, 0xE86);

    unsigned int dwToken = pModeTxtRecord->dwToken;
    if (nMode && nMode != 0xC)
    {
        *pCode = pMonStats2TxtRecord->dwBaseW;
    }
    else if (pMonStats2TxtRecord->nFlags[2] & gdwBitMasks[0])
    {
        *pCode = pMonStats2TxtRecord->dwBaseW;
    }
    else
    {
        *pCode = 0x20687468;
    }

    for (unsigned int i = 0; i < gnCofModeCodeCount; ++i)
    {
        if (nMode == gaCofModeCodes[i].nMode)
        {
            dwToken = gaCofModeCodes[i].dwCode;
        }
    }

    char szToken[4];
    char szWeapon[4];
    char szMonster[4];
    const unsigned char* pCodeBytes = (const unsigned char*)pCode;
    const unsigned char* pMonBytes = (const unsigned char*)&dwMonCode;
    szWeapon[0] = pCodeBytes[0] == 0x20 ? 0 : pCodeBytes[0];
    szWeapon[1] = pCodeBytes[1] == 0x20 ? 0 : pCodeBytes[1];
    szWeapon[2] = pCodeBytes[2] == 0x20 ? 0 : pCodeBytes[2];
    szWeapon[3] = 0;
    szMonster[0] = pMonBytes[0] == 0x20 ? 0 : pMonBytes[0];
    szMonster[1] = pMonBytes[1] == 0x20 ? 0 : pMonBytes[1];
    szMonster[2] = pMonBytes[2] == 0x20 ? 0 : pMonBytes[2];
    szMonster[3] = 0;
    szToken[0] = (unsigned char)dwToken == 0x20 ? 0 : (unsigned char)dwToken;
    szToken[1] = (unsigned char)(dwToken >> 8) == 0x20 ? 0 : (unsigned char)(dwToken >> 8);
    szToken[2] = (unsigned char)(dwToken >> 16) == 0x20 ? 0 : (unsigned char)(dwToken >> 16);
    szToken[3] = 0;
    wsprintfA(szPath, gszCofPathFormat, gszMonstersDir, szMonster, szMonster, szToken, szWeapon);
}

static inline D2MonStats2Txt* CLIENT_GetMonStats2TxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        const int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
        if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
        {
            return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
        }
    }
    return 0;
}

int __fastcall MONSTERUNIQUE_TestMonModeFlag(int nMonsterId, int nMode)
{
    D2MonStats2Txt* pMonStats2TxtRecord = CLIENT_GetMonStats2TxtRecord(nMonsterId);
    if (!pMonStats2TxtRecord)
    {
        return 0;
    }
    return pMonStats2TxtRecord->nModeFlags[nMode >> 3] & gdwBitMasks[nMode & 7];
}

// 0x0046F9E0
static void GFX_LoadMonsterModeGfx(D2UnitStrc* pUnit, int nIndex)
{
    int nUnitType;
    int nClassId;
    int nMode;

    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }

    nUnitType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClassId = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nMode, ".\\ENGINE\\Gfx.cpp", 0x498);
    const int nConvertedMode = nMode;
    if (nIndex == 0xE)
    {
        nIndex = nConvertedMode;
    }

    if (!MONSTERUNIQUE_TestMonModeFlag(nClassId, nIndex))
    {
        return;
    }

    if (nIndex == 0xC)
    {
        GFX_FreeGfxNodes(pUnit);
        GFX_FillGfxEntries(pUnit, 0);
        GFX_LoadMonsterGfx(pUnit, nIndex);
        return;
    }

    if (nIndex == 0xE)
    {
        nIndex = nConvertedMode;
    }
    GFX_LoadMonsterGfx(pUnit, nIndex);
}

void __fastcall GFX_LoadMonsterCofs(int nMonsterId, int bLoadNow)
{
    D2MonCofInfoStrc tInfo;
    int i;
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInl(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return;
    }

    D2MonStats2Txt* pMonStats2TxtRecord = DATATBLS_GetMonStats2TxtRecordInl(pMonStatsTxtRecord->wMonStatsEx);
    if (!pMonStats2TxtRecord)
    {
        return;
    }

    for (i = 0; i < gnCofModeCount; ++i)
    {
        const int nMode = gaCofModes[i];
        if (pMonStats2TxtRecord->nModeFlags[nMode >> 3] & gdwBitMasks[nMode & 7])
        {
            memset(&tInfo, 0, sizeof(tInfo));
            tInfo.nMonsterId = nMonsterId;
            GFX_LoadMonsterCof(pMonStatsTxtRecord, nMode, bLoadNow, &tInfo);
        }
    }
}

// 0x0046FA80
void* __fastcall GFX_LoadUnitGfxNode(D2UnitStrc* pUnit, int nWeaponClassId, int nIndex)
{
    int nClassId;
    int nUnitType;
    int nMode;

    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }

    nUnitType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClassId = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nMode, ".\\ENGINE\\Gfx.cpp", 0x502);
    if (nIndex == -1)
    {
        nIndex = nMode;
    }

    if (nUnitType == 1)
    {
        GFX_LoadMonsterModeGfx(pUnit, nIndex);
        return GFXUTIL_FindGfxListNode(pUnit, nWeaponClassId, nIndex);
    }

    if (nUnitType == UNIT_PLAYER)
    {
        GFX_LoadGfxNodeSetByte(pUnit, nIndex);
        return GFXUTIL_FindGfxListNode(pUnit, nWeaponClassId, -1);
    }

    if (nUnitType == 2)
    {
        GFX_LoadObjectGfx(pUnit, nIndex);
        return GFXUTIL_FindGfxListNode(pUnit, nWeaponClassId, -1);
    }

    return 0;
}

struct D2InventoryStrc;

struct D2UnitStrc;

inline int IsShapeShifted(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
        bResult = (pUnit->dwFlagEx >> 3) & 1;
    return bResult;
}

static inline D2GfxLayerStrc* GetNodeLayer(D2UnitStrc* pUnit, int nMode)
{
    D2UnitGfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
    if (pGfxData)
    {
        for (D2GfxListNodeStrc* pNode = pGfxData->pList; pNode; pNode = pNode->pNext)
        {
            if (pNode->nMode == nMode)
            {
                return pNode->pTarget->pLayer;
            }
        }
    }
    return 0;
}

// 0x0046FB60
static int __stdcall GFX_LoadUnitLayers(int bAsync, int nMode, D2UnitStrc* pUnit)
{
    int nResult = 1;
    D2InventoryStrc* pInventory;
    D2UnitStrc* pOwner;
    if (IsShapeShifted(pUnit) && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && (pOwner = CUNIT_GetOwnerUnit(pUnit)) != 0)
    {
        pInventory = pOwner->pInventory;
    }
    else
    {
        pInventory = pUnit->pInventory;
    }
    int nWeaponClass;
    const int nToken = COMPOSIT_GetWeaponClassId(pUnit, pInventory, &nWeaponClass, nMode, 0);
    void* pGfxNode = GFXUTIL_FindGfxListNode(pUnit, nToken, nMode);
    if (!pGfxNode)
    {
        pGfxNode = GFX_LoadUnitGfxNode(pUnit, nToken, nMode);
    }
    if (!pGfxNode)
    {
        char szBuffer[256];
        const int nClassArg = pUnit->dwClassId;
        const int nTypeArg = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
        sprintf(szBuffer, gszAsyncLoadFailed, bAsync, nTypeArg, nClassArg, nMode, nWeaponClass, nToken);
        return 0;
    }

    D2GfxLayerStrc* pLayer = GetNodeLayer(pUnit, nMode);
    if (!pLayer)
    {
        return 0;
    }

    D2GfxLayerHeaderStrc* pHeader = sub_004DB040_GetLayerHeader(pLayer);
    D2_ASSERT(pHeader, 0x6C3);
    int nA;
    const int nArg = pHeader->nArg;
    nA = 0;
    int nDirection = UNITS_GetDirection(pUnit);
    int nType = pUnit->dwUnitType;
    int nClass = pUnit->dwClassId;
    int nAnimMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nAnimMode, gszGfxFile, 0x6CD);
    int nB;
    GFXUTIL_GetLayerInfo(pUnit, nType, nClass, nMode, &nDirection, &nA, &nB, nArg, 0);
    unsigned char* pOrder = GFXUTIL_GetLayerOrder(pLayer, nA, 0);
    D2_ASSERT(pOrder, 0x6D6);
    for (int i = 0; i < pHeader->nLayers; ++i)
    {
        const int nLayer = pOrder[i];
        D2_ASSERT(nLayer < 0x10, 0x6DD);
        D2GfxDataStrc tContext;
        memset(&tContext, 0, sizeof(tContext));
        int nItemId;
        if (GFXUTIL_InitUnitCelContext(&tContext, pUnit, 0, UNITS_GetDirection(pUnit), 0, &nItemId, nLayer, nMode))
        {
            if (!D2CMPSpriteValidate(&tContext, bAsync, bAsync))
            {
                tContext.nArg34 = 0;
                if (!D2CMPSpriteRequest(&tContext))
                {
                    return -1;
                }
                if (!(tContext.dwFlags & 4))
                {
                    nResult = 0;
                }
            }
        }
    }
    return nResult;
}

// 0x0046FDA0
static void __stdcall GFX_PreloadMonsterMode(int bAsync, D2UnitStrc* pUnit, int nMode)
{
    int nAnimMode;
    int nType;
    int nClass;

    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }

    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nAnimMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nAnimMode, gszGfxFile, 0x70A);
    if (nClass >= sgptDataTables->nMonStatsTxtRecordCount || gpPoolBlock[nClass].nModeFlags[nMode])
    {
        return;
    }
    if (!gpPoolBlock[nClass].aPending[nMode])
    {
        if (GFX_LoadUnitLayers(bAsync, nMode, pUnit) != 1)
        {
            gpPoolBlock[nClass].aPending[nMode] = 0;
            gpPoolBlock[nClass].nModeFlags[nMode] = 0;
        }
        else
        {
            gpPoolBlock[nClass].aPending[nMode] = 1;
        }
    }
    else if (!D2CMPSpriteFindAsynchSiblings(nType, nMode, nClass))
    {
        gpPoolBlock[nClass].nModeFlags[nMode] = 1;
    }
}

// 0x0046FEB0
static void __stdcall GFX_PreloadMonsterModes(int bAsync, D2UnitStrc* pUnit)
{
    const int nId = GFX_GetConvertedClassId(pUnit);
    if (nId < 0 || nId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return;
    }
    const int nIndex = sgptDataTables->pMonStatsTxt[nId].wMonStatsEx;
    if (nIndex < 0 || nIndex >= sgptDataTables->nMonStats2TxtRecordCount)
    {
        return;
    }
    D2MonStats2Txt* pMonStats2 = &sgptDataTables->pMonStats2Txt[nIndex];
    if (!pMonStats2)
    {
        return;
    }
    for (unsigned int i = 0; i < gnCofModeCount; ++i)
    {
        const unsigned int nMode = gaCofModes[i];
        if (pMonStats2->nModeFlags[nMode >> 3] & gdwBitMasks[nMode & 7])
        {
            GFX_PreloadMonsterMode(bAsync, pUnit, nMode);
        }
    }
}

// 0x0046FF50
static void __stdcall GFX_PreloadPlayerMode(int bAsync, D2UnitStrc* pUnit, int nMode)
{
    int nAnimMode;
    int nType;
    int nClass;

    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }

    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nAnimMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nAnimMode, ".\\ENGINE\\Gfx.cpp", 0x751);
    if (gaPlayerGfxCache[nClass].nModeFlags[nMode])
    {
        return;
    }
    if (!gaPlayerGfxCache[nClass].aPending[nMode])
    {
        if (GFX_LoadUnitLayers(bAsync, nMode, pUnit) != 1)
        {
            gaPlayerGfxCache[nClass].aPending[nMode] = 0;
            gaPlayerGfxCache[nClass].nModeFlags[nMode] = 0;
        }
        else
        {
            gaPlayerGfxCache[nClass].aPending[nMode] = 1;
        }
    }
    else if (!D2CMPSpriteFindAsynchSiblings(nType, nMode, nClass))
    {
        gaPlayerGfxCache[nClass].nModeFlags[nMode] = 1;
    }
}

// 0x00470070
static void GFX_PreloadRoomUnits(int bAsync)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(sub_00463DD0_GetPlayerUnit());
    if (!pRoom)
    {
        return;
    }

    D2ActiveRoomStrc** ppRooms;
    int nRooms;
    int nAnimMode;
    int nClass;
    int nType;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRooms, &nRooms);
    int nCounter = 0;
    for (unsigned int i = 0; i < nRooms; ++i)
    {
        if (gbPreloadForce)
        {
            if (!bAsync || gbCharArchiveLoaded)
            {
                if ((nCounter++ & 0x1F) != 0)
                {
                    UI_DrawLoadingScreen(1);
                }
            }
        }

        if (!gbPreloadForce && D2CMPSpriteNumAsyncLoads() >= 0x1E)
        {
            return;
        }

        for (D2UnitStrc* pUnit = ppRooms[i]->pUnitFirst; pUnit; pUnit = pUnit->ptRoomNext)
        {
          {
            int nTypeValue;
            if (!pUnit)
            {
                nTypeValue = 6;
            }
            else
            {
                nTypeValue = pUnit->dwUnitType;
            }

            nType = nTypeValue;
            const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
            nClass = nClassValue;
            nAnimMode = UNITS_GetAnimOrSeqMode(pUnit);
            D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nAnimMode, gszGfxFile, 0x7AA);
            if (nType == 1)
            {
                if (nClass < sgptDataTables->nMonStatsTxtRecordCount && (nAnimMode != 0xC || !gpPoolBlock[nClass].nModeFlags[0xC]))
                {
                    GFX_PreloadMonsterModes(bAsync, pUnit);
                }
            }
            else if (nType == 0)
            {
                if (gbCharArchiveLoaded)
                {
                    bAsync = 0;
                }

                for (unsigned int j = 0; j < gnPlayerModeCount; ++j)
                {
                    GFX_PreloadPlayerMode(bAsync, pUnit, gaPlayerModes[j]);
                }
            }

            if (!gbPreloadForce && D2CMPSpriteNumAsyncLoads() >= 0x1E)
            {
                return;
            }
          }
        }
    }
}

static void GFX_PreloadPlayerModes(int bAsync, D2UnitStrc* pUnit)
{
    for (unsigned int i = 0; i < gnPlayerModeCount; ++i)
    {
        GFX_PreloadPlayerMode(bAsync, pUnit, gaPlayerModes[i]);
    }
}

// 0x00470350
void __fastcall GFX_PreloadTick(int bAsync)
{
    if (gbPreloadForce || GetTickCount() >= gdwLastPreloadTick + 0x258)
    {
        GFX_PreloadRoomUnits(bAsync);
        gdwLastPreloadTick = GetTickCount();
    }
}

// 0x00470610
void __fastcall GFX_RefreshUnitGfx(D2UnitStrc* pUnit, int nArg)
{
    int nClassId;
    int nUnitType;
    int nMode;

    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }

    nUnitType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClassId = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nMode, ".\\ENGINE\\Gfx.cpp", 0xD17);
    switch (nUnitType)
    {
    case UNIT_PLAYER:
        GFX_LoadGfxNodeSetByte(pUnit, nMode);
        return;

    case UNIT_MONSTER:
        GFX_LoadMonsterModeGfx(pUnit, nMode);
        return;

    case UNIT_OBJECT:
        GFX_LoadObjectGfx(pUnit, nMode);
        return;

    default:
        D2_ASSERT(0, 0xD26);
        return;
    }
}

// 0x00470B10
void __cdecl GFX_PreloadForce()
{
    gbPreloadForce = 1;
    GFX_PreloadRoomUnits(0);
    gdwLastPreloadTick = GetTickCount();
    GFX_PreloadTick(1);
    gbPreloadForce = 0;
}

// 0x00470B70
void __fastcall GFX_ResetMonsterModeGfx(D2UnitStrc* pUnit)
{
    int nAnimMode;
    int nType;
    int nClass;

    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }

    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nAnimMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nAnimMode, ".\\ENGINE\\Gfx.cpp", 0x1072);
    switch (nType)
    {
    case 1:
        if (nClass < sgptDataTables->nMonStatsTxtRecordCount)
        {
            gpPoolBlock[nClass].nModeFlags[nAnimMode] = 0;
            gpPoolBlock[nClass].aPending[nAnimMode] = 0;

            int bAsync = 1;
            if (!UNITS_GetRoom(pUnit) || WINDOW_GetState() || UI_IsLoadingScreenActive())
            {
                bAsync = 0;
            }

            GFX_PreloadMonsterModes(bAsync, pUnit);
        }
        break;
    }
}


void __fastcall sub_00470B70_ResetMonsterMode(D2UnitStrc* pUnit)
{
    int nType;
    int nAnimMode;
    int nClass;

    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }

    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nAnimMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nAnimMode, ".\\ENGINE\\Gfx.cpp", 0x1072);
    switch (nType)
    {
    case 1:
        if (nClass < sgptDataTables->nMonStatsTxtRecordCount)
        {
            gpPoolBlock[nClass].nModeFlags[nAnimMode] = 0;
            gpPoolBlock[nClass].aPending[nAnimMode] = 0;
            int bAsync = 1;
            if (!UNITS_GetRoom(pUnit) || WINDOW_GetState() || UI_IsLoadingScreenActive())
            {
                bAsync = 0;
            }
            GFX_PreloadMonsterModes(bAsync, pUnit);
        }
        break;
    }
}


extern "C" const char* const gData_006D6C30[5]; // 0x006D6C30

extern "C" const char* const gData_006D6C30[5] = { "cmncof_a1.d2", "cmncof_a2.d2", "cmncof_a3.d2", "cmncof_a4.d2", "cmncof_a6.d2" }; // 0x006D6C30
#pragma comment(linker, "/alternatename:?gaszHashedFileNames@@3PAPBDA=_gData_006D6C30")

extern D2CofModeEntryStrc gaCofModeCodes[1] = { { 0x20206867, 13 } }; // 0x00712B04

extern unsigned int gnCofModeCodeCount = 1; // 0x00712B0C

extern "C" const char gszAsyncLoadFailed[100] = "sAsyncLoadBlock failed on async:%d unittype:%d unitclass:%d unitmode:%d weaponclass:%d wclass:%d\n"; // 0x006D6CC8

extern int gaCofModes[15] = { 12, 0, 1, 2, 15, 4, 3, 5, 7, 6, 13, 8, 9, 10, 11 }; // 0x00712AC4

extern int gnCofModeCount = 15; // 0x00712B00
