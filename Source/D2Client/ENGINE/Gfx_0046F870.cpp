#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2CelContext.h"
#include "D2ClientGfx.h"
#include "D2Txt.h"
#include "D2ClientTypes.h"
struct D2UnitStrc;

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_OBJECT 2
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
struct D2HashedFileEntryStrc;
struct D2HashedFileStrc;
struct D2GfxListNodeStrc;
struct D2MonStatsTxt;
struct D2MonStats2Txt;
struct D2MonCofInfoStrc;
struct D2CofModeEntryStrc;
struct D2GfxHeaderStrc;









extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" size_t __cdecl strlen(const char* szString);
extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount); // 0x00687330
extern "C" char* __cdecl _strlwr(char* szString); // 0x006864E1
extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468
unsigned int __stdcall SStrHash(const char* szString, unsigned int nFlags, unsigned int nSeed); // 0x00413CE0
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
void* __fastcall ARCHIVE_AllocateBufferAndReadFile(void* hArchive, const char* szFileName, unsigned int* pnSize, const char* szFile, int nLine); // 0x00517079
D2GfxDataStrc* __fastcall CUNIT_GetGfxData(D2UnitStrc* pUnit); // 0x00463E10
D2UnitStrc* __fastcall CUNIT_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0
int __fastcall sub_0046C140_TestMonModeFlag(int nMonsterId, int nMode); // 0x0046C140
int __fastcall GFX_GetConvertedUnitType(D2UnitStrc* pUnit); // 0x0046D9F0
int __fastcall GFX_GetNodeValue(D2UnitStrc* pUnit, int nMode); // 0x0046E570
D2GfxListNodeStrc* __fastcall GFXUTIL_FindGfxListNode(D2UnitStrc* pUnit, int nId, int nMode); // 0x0046E5A0
void __fastcall GFX_FreeGfxNodes(D2UnitStrc* pUnit); // 0x0046EC80
void __fastcall GFX_FillGfxEntries(D2UnitStrc* pUnit, unsigned char nValue); // 0x0046F020
int __fastcall GFXUTIL_IsPlayerMonsterOrObject(D2UnitStrc* pUnit); // 0x004DB180
unsigned char __fastcall GFXUTIL_GetGfxEntryByte(D2UnitStrc* pUnit, int nIndex); // 0x004DB1A0
void __fastcall GFXUTIL_SetGfxEntryByte(D2UnitStrc* pUnit, int nIndex, unsigned char nValue); // 0x004DB1C0
extern "C" D2GfxLayerHeaderStrc* __fastcall GFXUTIL_identity(void* pGfx); // 0x004DB040
int __fastcall GFXUTIL_InitMonsterCelContext(D2CelContextStrc* pContext, int nA, int nB, unsigned char nLayer, int nMode, unsigned int dwCode, D2HashedFileEntryStrc* pEntry, D2MonCofInfoStrc* pInfo, D2MonStatsTxt* pMonStats, int nIndex); // 0x004DBCF0
int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3); // 0x006001F0
int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask); // 0x0063A7B0
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90
void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270
void __stdcall D2Common_10885_COMPOSIT_unk(D2UnitStrc* pUnit, char* szPath, int* pWeaponClassCode, int bAddPathPrefix, int a5, D2InventoryStrc* pInventory, int nAnimMode); // 0x0064FA00
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit); // 0x00621190
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern unsigned int gdwBitMasks[]; // 0x006CE268
extern D2CofModeEntryStrc gaCofModeCodes[]; // 0x00712B04
extern int gnCofMemoryUsed; // 0x007A8918
extern D2HashedFileStrc gtGlobalHashedFile; // 0x007A78F0
extern D2HashedFileStrc gtUnitGfxHashedFile; // 0x007A8100
static int __stdcall GFX_LoadGfxNode(int* pValue, int nIndex, D2UnitStrc* pUnit); // 0x0046E740
static int GFX_LoadGfxNodeSetByte(D2UnitStrc* pUnit, int nIndex); // 0x0046EA50

struct D2GfxHeaderStrc { int unknown00[2],left,right,top,bottom; };

extern int gnScreenWidth; // 0x0071146C
D2GfxListNodeStrc* __fastcall GFXUTIL_FindGfxListNode(D2UnitStrc* pUnit, int nId, int nMode); // 0x0046E5A0
void* __fastcall GFX_LoadUnitGfxNode(D2UnitStrc*,int,int); // 0x0046FA80
D2GfxHeaderStrc* __fastcall sub_004DB040_GetLayerHeader(void*); // 0x004DB040
int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc*,D2InventoryStrc*,int*,int,int); // 0x0064F380

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

void __fastcall GFX_GetBaseName(const char* szPath, char* szDest); // 0x0046DBF0

D2HashedFileEntryStrc* __stdcall GFX_FindHashedEntry(D2HashedFileStrc* pTable, const char* szPath); // 0x0046DC40

D2HashedFileEntryStrc* __stdcall GFX_LoadHashedEntry(D2HashedFileStrc* pTable, const char* szPath); // 0x0046DCC0

int GFX_RemoveGfxNode(D2UnitStrc* pUnit, D2HashedFileEntryStrc* pEntry); // 0x0046E610

int __stdcall GFX_FindGfxNode(int nId, D2GfxListNodeStrc** ppNode, int* pValue, D2UnitStrc* pUnit, int nMode); // 0x0046E690

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

    D2GfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
    if (!pGfxData)
    {
        return 0;
    }

    D2GfxListNodeStrc* pNode;
    if (GFX_FindGfxNode(nId, &pNode, pValue, pUnit, nIndex))
    {
// build: symbol ?gszGfxFile@* 0x006D6C1C
        D2GfxListNodeStrc* pNewNode = (D2GfxListNodeStrc*)FOG_Alloc(sizeof(D2GfxListNodeStrc), gszGfxFile, 0x434, 0);
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
        pNewNode->nId = nId;
        pNewNode->pFileEntry = pEntry;
        pNewNode->pNext = pGfxData->pList;
        pGfxData->pList = pNewNode;
    }

    return GFX_GetNodeValue(pUnit, nIndex);
}

int GFX_LoadMonsterGfx(D2UnitStrc* pUnit, int nIndex); // 0x0046E8D0

int GFX_LoadObjectGfx(D2UnitStrc* pUnit, int nIndex); // 0x0046E980

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

void __stdcall GFX_BuildMonsterCofPath(int nMode, char* szPath, unsigned int* pCode, int nMonsterId); // 0x0046F490

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
    D2GfxLayerHeaderStrc* pHeader = GFXUTIL_identity(pData);
    D2_ASSERT(pHeader, 0xECB);
    unsigned char* pOrder = sub_004DB110_GetLayerOrder(pData, 0, 0);
    D2_ASSERT(pOrder, 0xED0);

    for (int i = 0; i < pHeader->nLayers; ++i)
    {
        const int nLayer = pOrder[i];
        D2_ASSERT(nLayer < 0x10, 0xED7);
        if (pInfo->nCount)
        {
            for (unsigned int j = 0; j < pInfo->nCount; ++j)
            {
                D2CelContextStrc tContext;
                memset(&tContext, 0, sizeof(tContext));
                if (GFXUTIL_InitMonsterCelContext(&tContext, 0, 0, nLayer, nMode, dwCode, pEntry, pInfo, pMonStatsTxtRecord, j))
                {
                    if (bLoadNow)
                    {
                        if (!sub_006001F0(&tContext, 1, 1))
                        {
                            tContext.nArg34 = 0;
                            sub_006004E0_LoadSprite(&tContext);
                        }
                    }
                    else
                    {
                        sub_006001F0(&tContext, 0, 0);
                    }
                }
            }
        }
        else
        {
            D2CelContextStrc tContext;
            memset(&tContext, 0, sizeof(tContext));
            if (GFXUTIL_InitMonsterCelContext(&tContext, 0, 0, nLayer, nMode, dwCode, pEntry, pInfo, pMonStatsTxtRecord, 0))
            {
                if (bLoadNow)
                {
                    if (!sub_006001F0(&tContext, 1, 1))
                    {
                        tContext.nArg34 = 0;
                        sub_006004E0_LoadSprite(&tContext);
                    }
                }
                else
                {
                    sub_006001F0(&tContext, 0, 0);
                }
            }
        }
    }
}

// 0x0046F870
void __fastcall GFX_LoadMonsterCofs(int nMonsterId, int bLoadNow)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInl(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return;
    }

    D2MonStats2Txt* pMonStats2TxtRecord = DATATBLS_GetMonStats2TxtRecordInl(DATATBLS_GetMonStatsTxtRecordInl(nMonsterId)->wMonStatsEx);
    if (!pMonStats2TxtRecord)
    {
        return;
    }

// build: symbol ?gnCofModeCount@* 0x00712B00
    for (int i = 0; i < gnCofModeCount; ++i)
    {
// build: symbol ?gaCofModes@* 0x00712AC4
        const int nMode = gaCofModes[i];
        if (pMonStats2TxtRecord->nModeFlags[nMode >> 3] & gdwBitMasks[nMode & 7])
        {
            D2MonCofInfoStrc tInfo;
            memset(&tInfo, 0, sizeof(tInfo));
            tInfo.nMonsterId = nMonsterId;
            GFX_LoadMonsterCof(pMonStatsTxtRecord, nMode, bLoadNow, &tInfo);
        }
    }
}

void GFX_LoadMonsterModeGfx(D2UnitStrc* pUnit, int nIndex); // 0x0046F9E0

void* __fastcall GFX_LoadUnitGfxNode(D2UnitStrc* pUnit, int nWeaponClassId, int nIndex); // 0x0046FA80

void __fastcall GFX_RefreshUnitGfx(D2UnitStrc* pUnit, int nArg); // 0x00470610

static inline int IsShapeShifted(D2UnitStrc* unit) { if(!unit) return 0; return (unit->dwFlagEx>>3)&1; }

static inline D2InventoryStrc* GetInventory(D2UnitStrc* unit) {
 if(IsShapeShifted(unit) && STATES_CheckStateMaskOnUnit(unit,37)) {
  D2UnitStrc* owner=CUNIT_GetOwnerUnit(unit);
  if(owner) return owner->pInventory;
 }
 return unit->pInventory;
}

static inline void* GetModeGfx(D2UnitStrc* unit,int mode) {
 D2GfxDataStrc* data=CUNIT_GetGfxData(unit);
 if(!data) return 0;
 D2GfxListNodeStrc* node=data->pList;
 if(!node) return 0;
 do {
  if(node->nMode==mode) return node->pTarget->pLayer;
  node=node->pNext;
 } while(node);
 return 0;
}

// 0x004709A0
int __fastcall GFX_IsUnitOnScreen(D2UnitStrc* unit,int x,int y,int unused,int centered)
{
 int weapon;
 int weaponClass=COMPOSIT_GetWeaponClassId(unit,GetInventory(unit),&weapon,-1,1);
 if(!GFXUTIL_FindGfxListNode(unit,weaponClass,-1)) GFX_LoadUnitGfxNode(unit,weaponClass,-1);
 int type=unit->dwUnitType;
 int classId=unit->dwClassId;
 int mode=UNITS_GetAnimOrSeqMode(unit);
 D2COMMON_11013_ConvertMode(unit,&type,&classId,&mode,".\\ENGINE\\Gfx.cpp",3522);
 void* gfx=GetModeGfx(unit,mode);
 if(!gfx) return 0;
 D2GfxHeaderStrc* header=sub_004DB040_GetLayerHeader(gfx);
 if(!header) { FOG_DisplayHalt(&gszEmptyAssertText,sub_00408090(),3539); exit(-1); }
 int width=gnScreenWidth;
 int height=gnScreenHeight;
 int left=header->left+x;
 if(centered) left-=(header->bottom-header->top)/2;
 if(left>=width-1) return 0;
 if(header->right+x<0) return 0;
 if(header->bottom+y<0) return 0;
 return header->top+y<height-1;
}
