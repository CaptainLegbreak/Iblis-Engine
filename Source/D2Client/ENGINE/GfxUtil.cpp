#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2UnitData.h"
#include "D2Drlg.h"
#include "D2LevelTxt.h"
#include "D2CmpTypes.h"
#include "D2ClientGfx.h"
#include "D2ClientTypes.h"
#include "D2Txt.h"
#include "D2TxtTables.h"
#include "D2Records.h"
#include "D2CelContext.h"
#include "D2ItemsWorld.h"
#include "D2MonModes.h"
#include "D2WinSplitText.h"
#include "D2ClientBallistic.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_PLAYER 0

#define UNIT_MONSTER 1

#define UNIT_OBJECT 2

#define UNIT_ITEM 4

#define UNIT_INVALID 6

#define offsetof(s, m) ((unsigned int)&(((s*)0)->m))

struct D2MonsterDataStrc;

struct D2GfxEntryStrc;

struct D2GfxListNodeStrc;

struct D2CellBlockStrc;

struct D2OffsetTableStrc;

struct D2OffsetTableRefStrc;

struct D2RequestStrc;

struct D2KeyedNodeStrc;

struct D2CltUnitEventStrc;

struct D2RosterInfoStrc;

struct D2DrawBoundsArgStrc;

struct D2DrawBoundsStrc;

struct D2SkillsTxt;

struct D2MonStatsTxt;

struct D2OverlayTxt;

struct D2MonStats2Txt;

struct D2MissilesTxt;

struct D2MonGfxCacheStrc;

struct PartialSparseClear;

struct PartialTableRecord;

struct PartialTableView;

struct PartialLookupRecord;

struct PartialLookupHeader;

struct D2CofLayerStrc;

struct D2CofDataStrc;

struct D2UnitStrc;

struct D2ActiveRoomStrc;

struct D2GfxDataStrc;

struct D2GfxMotionStrc;

struct D2LevelsTxt;

struct D2DataTablesStrc;

struct D2TokRecord;

struct D2ObjectsTxt;

struct D2ItemsTxt;

struct D2CellBlockStrc
{
    unsigned char nCount;
    unsigned char nWidth;
    char unk0x02[0x1A];
    unsigned char pData[1];
};

struct D2OffsetTableStrc
{
    char unk0x00[0x10];
    int nOffsetsOffset;
    unsigned int nCount;
    int nFirstId;
};

struct D2OffsetTableRefStrc
{
    D2OffsetTableStrc* f_0;

    void* GetEntry(int nId); // 0x004E0700
};

struct D2RequestStrc
{
    int nType;
    D2UnitStrc* pUnit;
    int unk0x08[2];
    int nArg0;
    int nArg1;
    int nArg2;
    int unk0x1C[4];
    int nArg3;
    int nArg4;
    int unk0x34[10];
};

typedef int (__fastcall* UNITCALLBACKFN)(D2UnitStrc* pUnit, D2UnitStrc* pOther, void* pArg1, void* pArg2);

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize); // 0x00681EF0

D2GfxDataStrc* __fastcall CUNIT_GetGfxData(D2UnitStrc* pUnit); // 0x00463E10

D2GfxMotionStrc* __fastcall GFX_GetGfxMotion(D2UnitStrc* pUnit); // 0x0046F060

int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790

int __stdcall DRLG_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0

int __fastcall sub_004CD540_HandleRequest(D2RequestStrc* pRequest); // 0x004CD540

struct D2KeyedNodeStrc
{
    int nValue;
    int nKeyA;
    int nKeyB;
    D2KeyedNodeStrc* pNext;
};

struct D2RosterInfoStrc
{
    int dwUnitId;
    union
    {
        unsigned int dwPartyFlags;
        struct
        {
            unsigned short wPartyFlags;
            unsigned short wPartyFlagsHigh;
        };
    };
    D2RosterInfoStrc* pNext;
};

struct D2DrawBoundsArgStrc
{
    char unk0x00[0x14];
    unsigned int dwFlags;
};

struct D2DrawBoundsStrc
{
    char unk0x00[0x28];
    int bActive;
    int nMinX;
    int nMaxX;
    int nMinY;
    int nMaxY;

    void ExtendBounds(D2DrawBoundsArgStrc* pArg, int nX, int nY); // 0x004DDE80
};

extern "C" double __cdecl sqrt(double x); // 0x006879C0

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern int gnScreenWidth; // 0x0071146C

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

D2ActiveRoomStrc* __cdecl CUNIT_GetPlayerRoom(); // 0x004646A0

int __fastcall sub_004648F0_GetPathValue(D2UnitStrc* pUnit); // 0x004648F0

D2RosterInfoStrc** __fastcall ROSTER_GetRosterInfoList(int nUnitId); // 0x0047A310

D2UnitStrc* __fastcall AUTOMAP_RequestAtTarget(D2UnitStrc* pUnit, int nRequest, int nArg3, int nArg4); // 0x004C5420

D2UnitStrc* __fastcall SKILLDESC_CltDoRandomMissile(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x004E31C0

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

int __stdcall CelGetWidth(D2CelStrc* pCel); // 0x006018C0

int __stdcall CelGetHeight(D2CelStrc* pCel); // 0x006018F0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250

void __stdcall SKILLS_SetParam1(D2SkillStrc* pSkill, int nValue); // 0x00644560

void __stdcall SKILLS_SetFlags(D2SkillStrc* pSkill, int nValue); // 0x00644660

int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0

int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0

extern int gbCharArchiveLoaded; // 0x007A8928

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0

D2MonGfxCacheStrc* __fastcall GFX_GetMonGfxCache(int nMonsterId); // 0x0046F9D0

D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId); // 0x0046ACE0

int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit); // 0x00621190

void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270

void __stdcall sub_006488A0_SetDirection(D2DynamicPathStrc* pPath, int nDirection); // 0x006488A0

extern unsigned int gdwBitMasks[]; // 0x006CE268

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90

struct PartialSparseClear
{
    char unknown_00[0x38];
    unsigned int first;
    char unknown_3C[0xEA9C - 0x3C];
    unsigned int second;
    char unknown_EAA0[8];
    unsigned int third;
    char unknown_EAAC[4];
    unsigned int fourth;
};

struct PartialTableRecord
{
    char opaque[12];
};

struct PartialTableView
{
    char unknown_00[0xC34];
    int count;
    char unknown_C38[4];
    PartialTableRecord* records;
};

extern "C" PartialTableView* gTableView_00744304;

struct PartialLookupRecord
{
    unsigned char key;
    unsigned char first;
    unsigned char second;
    char unknown_03[6];
};

struct PartialLookupHeader
{
    unsigned char count;
    char unknown_01[0x1B];
    PartialLookupRecord records[1];
};

typedef char check_PartialSparseClear_size[sizeof(PartialSparseClear) == 0xEAB4 ? 1 : -1];

typedef char check_PartialSparseClear_first[offsetof(PartialSparseClear, first) == 0x38 ? 1 : -1];

typedef char check_PartialSparseClear_second[offsetof(PartialSparseClear, second) == 0xEA9C ? 1 : -1];

typedef char check_PartialSparseClear_third[offsetof(PartialSparseClear, third) == 0xEAA8 ? 1 : -1];

typedef char check_PartialSparseClear_fourth[offsetof(PartialSparseClear, fourth) == 0xEAB0 ? 1 : -1];

typedef char check_PartialTableRecord_size[sizeof(PartialTableRecord) == 12 ? 1 : -1];

typedef char check_PartialTableView_size[sizeof(PartialTableView) == 0xC40 ? 1 : -1];

typedef char check_PartialTableView_count[offsetof(PartialTableView, count) == 0xC34 ? 1 : -1];

typedef char check_PartialTableView_records[offsetof(PartialTableView, records) == 0xC3C ? 1 : -1];

typedef char check_PartialLookupRecord_size[sizeof(PartialLookupRecord) == 9 ? 1 : -1];

typedef char check_PartialLookupRecord_key[offsetof(PartialLookupRecord, key) == 0 ? 1 : -1];

typedef char check_PartialLookupRecord_first[offsetof(PartialLookupRecord, first) == 1 ? 1 : -1];

typedef char check_PartialLookupRecord_second[offsetof(PartialLookupRecord, second) == 2 ? 1 : -1];

typedef char check_PartialLookupHeader_records[offsetof(PartialLookupHeader, records) == 0x1C ? 1 : -1];

D2UnitStrc* __fastcall CUNIT_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0

int __fastcall GFX_GetConvertedUnitType(D2UnitStrc* pUnit); // 0x0046D9F0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480

extern "C" unsigned int __stdcall sub_006280A0(D2UnitStrc* pUnit, unsigned int dwMask, unsigned int dwUnused3, unsigned int dwUnused4); // 0x006280A0

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask); // 0x0063A7B0

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

D2UnitStrc* __stdcall INVENTORY_GetCompositItem(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063C050

static void GFXUTIL_ConvertDirection(int nSrcDirCount, int nDirCount, unsigned int* pDirection); // 0x004DB290

static int __stdcall GFXUTIL_GetUnitModeDirections(D2UnitStrc* pUnit, int nMode, int nClassId, int nUnitType); // 0x004DAF70

static void __stdcall GFXUTIL_SetDeathDirection(unsigned int nDirection, int bSet, D2UnitStrc* pUnit, int nDirCount, int nSrcDirCount); // 0x004DB1E0

struct D2CompEntryListStrc
{
    int unk0x00[5];
    D2CompEntryStrc* pEntry;
};

struct D2ArmorCompsStrc
{
    unsigned char n0;
    unsigned char n1;
    unsigned char n2;
    unsigned char n3;
    unsigned char n4;
    unsigned char n5;
    unsigned char n6;
    unsigned char n7;
};

unsigned int gaPlrModeTokens[20];                                                             // 0x007C88D0

unsigned int gaCompTokens[16];                                                                // 0x007C8920

unsigned int gaObjModeTokens[8];                                                            // 0x007C8960

unsigned int gaMonModeTokens[16];                                                             // 0x007C8980

unsigned int gaClassTokens[3];                                                              // 0x007C89C0

D2InventoryStrc* __fastcall GFX_GetCompInventory(D2UnitStrc* pUnit, int* pOut);                    // 0x0046DB30

int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int bUseConvertedMode); // 0x0064F380

D2GfxListNodeStrc* __fastcall GFXUTIL_FindGfxListNode(D2UnitStrc* pUnit, int nId, int nMode); // 0x0046E5A0

void* __fastcall GFX_LoadUnitGfxNode(D2UnitStrc* pUnit, int nWeaponClassId, int nArg);                 // 0x0046FA80

D2CompEntryStrc* __fastcall sub_0046E570_GetGfxEntry(D2UnitStrc* pUnit, int nMode);                         // 0x0046E570

int __fastcall GFXUTIL_GetModeArg(D2UnitStrc* pUnit, int nType, int nClass);                           // 0x004DAA00

unsigned char __fastcall GFXUTIL_GetMonComponentIndex(D2UnitStrc* pUnit, unsigned char nComponent);    // 0x004DA770

int __fastcall MONSTERREGION_CheckMonStats2Flag(int nMonsterId, int nFlag);                                  // 0x004638A0

void __fastcall GFXUTIL_GetArmorComponents(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int bSkip, unsigned char* pComponents); // 0x004DAAB0

int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem);                                                     // 0x0062A4E0

void __fastcall GFXUTIL_ConvertItemMode(D2UnitStrc* pUnit, int* pMode);                                    // 0x004DAA70

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);   // 0x006280A0

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem);                                                      // 0x00627E70

int __stdcall ITEMS_GetFileIndex(D2UnitStrc* pItem);                                                        // 0x00629DA0

D2SetItemsTxt* __fastcall DATATBLS_GetSetItemsTxtRecord(int nIndex);                                    // 0x00483440

D2UniqueItemsTxt* __fastcall DATATBLS_GetUniqueItemsTxtRecord(int nIndex);                              // 0x00483470

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0

int __stdcall INVENTORY_GetEquippedShield(D2InventoryStrc* pInventory, D2UnitStrc** ppItem);                // 0x0063C8F0

int __stdcall sub_006001F0(D2CelContextStrc* pContext, int nArg2, int nArg3);                // 0x006001F0

extern "C" int __cdecl PLAYER_GetScreenOffsetY();                                                      // 0x0045AFD0

extern "C" int __cdecl PLAYER_GetScreenOffsetX();                                                          // 0x0045AFC0

int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit);                                                     // 0x006206B0

int __fastcall GFX_IsUnitOnScreen(D2UnitStrc* pUnit, int nX, int nY, int nArg1, int nArg2);            // 0x004709A0

struct D2GfxCodeRecordStrc;

struct D2GfxCodeTableStrc;

#pragma pack(push, 1)

struct D2GfxCodeRecordStrc
{
    unsigned char nCode;
    unsigned char unk0x01;
    unsigned char nValue;
    unsigned char unk0x03[6];
};

struct D2GfxCodeTableStrc
{
    unsigned char nCount;
    unsigned char unk0x01[0x1B];
    D2GfxCodeRecordStrc f_1C[1];
};

#pragma pack(pop)

static void GFXUTIL_CopyCompCode(D2CompCodeStrc* pDst, const char* pSrc); // 0x004DA720

static void __stdcall GFXUTIL_SetMissileCelName(D2UnitStrc* pUnit, D2CelContextStrc* pToken); // 0x004DA8E0

static void GFXUTIL_SetItemCelName(D2UnitStrc* pUnit, D2CelContextStrc* pToken); // 0x004DABC0

static unsigned int GFXUTIL_GetWeaponClassToken(D2UnitStrc* pUnit, int nComponent); // 0x004DAD80

static int __stdcall GFXUTIL_FillMonsterCelContext(D2CompEntryListStrc* pList, unsigned int dwCode0, D2CelContextStrc* pToken, int nMode, D2MonCompInfoStrc* pClassInfo, D2CompArgStrc* pArgRec, int nRow); // 0x004DBB80

struct D2CompRecordStrc;

struct D2CompEntryStrc;

struct D2CompEntryListStrc;

struct D2CompArgStrc;

struct D2MonCompInfoStrc;

struct D2ArmorCompsStrc;

struct D2OverlaySourceStrc;

struct D2SetItemsTxt;

struct D2UniqueItemsTxt;

union D2CompCodeStrc;

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

int __cdecl sub_0045AE90(); // 0x0045AE90

static int GFXUTIL_GetOverlayDirections(int nOverlay); // 0x004DAD50

int __fastcall GFXUTIL_InitUnitCelContext(D2CelContextStrc* pToken, D2UnitStrc* pUnit, int nArg34, int nArg40, int nArg0, int* pItemId, unsigned char nComponent, int nMode); // 0x004DBB50

int __fastcall GFXUTIL_GetComponentsMaxHeight(D2UnitStrc* pUnit, unsigned char* pList, unsigned char* pComponents, int* pMax, int nArg40, int nArg0); // 0x004DBD30

void __fastcall GFXUTIL_GetUnitCelSize(D2UnitStrc* pUnit, int nArg40, int nArg0, int* pWidth, int* pHeight); // 0x004DBEA0

static int __stdcall GFXUTIL_ResolveUnitCelContext(D2UnitStrc* pUnit, D2CelContextStrc* pToken, int nMode, int* pItemId); // 0x004DB7B0

static int __stdcall GFXUTIL_FillMonsterCelContext(D2CompEntryListStrc* pList, unsigned int dwCode0, D2CelContextStrc* pToken, int nMode, D2MonCompInfoStrc* pClassInfo, D2CompArgStrc* pArgRec, int nRow); // 0x004DBB80

int __fastcall GFXUTIL_InitMonsterCelContext(D2CelContextStrc* pToken, int nArg40, int nArg0, unsigned char nComponent, int nMode, unsigned int dwCode0, D2CompEntryListStrc* pList, D2MonCompInfoStrc* pClassInfo, D2CompArgStrc* pArgRec, int nRow); // 0x004DBCF0

int __fastcall GFXUTIL_GetOverlayFrameCount(D2UnitStrc* pUnit, D2OverlaySourceStrc* pSrc); // 0x004DBE20

int __fastcall GFXUTIL_HitTestUnitCel(D2UnitStrc* pUnit, int nX, int nY); // 0x004DBF20

unsigned int gdwFadeTick; // 0x007C89CC

struct D2GfxNodeStrc
{
    int unk0x00[3];
    D2GfxNodeStrc* pNext;
};
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);                                // 0x0040B3C0


D2BallisticStrc* __fastcall sub_0046F060(D2UnitStrc* pUnit); // 0x0046F060

D2TokRecord* __stdcall DATATBLS_GetCompositTxtRecord(int nComposit);                                        // 0x0065B5E0

D2TokRecord* __stdcall DATATBLS_GetMonModeTxtRecord(unsigned int nIndex, int bGetMode);                     // 0x0065B500

D2TokRecord* __stdcall DATATBLS_GetArmTypeTxtRecord(int nId);                                               // 0x0065B620



// 0x0046E5A0
D2GfxListNodeStrc* __fastcall GFXUTIL_FindGfxListNode(D2UnitStrc* pUnit, int nId, int nMode)
{
    D2GfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
    D2_ASSERT(pGfxData, 940);

    if (nMode == -1)
    {
        nMode = sub_0046DA60_GetUnitMode(pUnit);
    }

    for (D2GfxListNodeStrc* pNode = pGfxData->pList; pNode; pNode = pNode->pNext)
    {
        if (pNode->nMode == nMode && pNode->nId == nId)
        {
            return pNode;
        }
    }

    return 0;
}

// 0x00483360
int __fastcall DATATBLS_ApplyRatio(int nValue, int nMultiplier, int nDivisor)
{
    if (!nDivisor)
    {
        return 0;
    }

    if (nValue > 0x100000)
    {
        if (nDivisor <= (nValue >> 4))
        {
            return nMultiplier * (nValue / nDivisor);
        }
        return (int)(nValue * (__int64)nMultiplier / nDivisor);
    }

    if (nMultiplier > 0x10000)
    {
        if (nDivisor > (nMultiplier >> 4))
        {
            return (int)(nValue * (__int64)nMultiplier / nDivisor);
        }
        return nValue * (nMultiplier / nDivisor);
    }

    return nMultiplier * nValue / nDivisor;
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x004DA110
int __stdcall GFXUTIL_GetMotionAX(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = GFX_GetGfxMotion(pUnit);
    if (pMotion)
    {
        return pMotion->tA.nX >> 11;
    }

    return 0;
}

// 0x004DA130
int __stdcall GFXUTIL_GetMotionAY(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = GFX_GetGfxMotion(pUnit);
    if (pMotion)
    {
        return pMotion->tA.nY >> 11;
    }

    return 0;
}

void __fastcall GFX_GetUnitCelOffsets(D2UnitStrc* pUnit, int nComponent, int* pOffsetX, int* pOffsetY); // 0x004706E0

extern "C" int __stdcall PARTICLE_GetGfxOffsetX(D2UnitStrc* pUnit);                                     // 0x004DA0B0

void __stdcall DUNGEON_GameToClientCoords(int* pX, int* pY);                                                // 0x00643290

// 0x004DA340
void __fastcall GFXUTIL_ClearMotionFlagTwo(D2UnitStrc* pMissile)
{
    D2GfxMotionStrc* pMotion = GFX_GetGfxMotion(pMissile);
    if (pMotion)
        pMotion->dwFlags &= ~2;
}


// 0x004DA350
void __stdcall GFXUTIL_UpdateMotion(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = GFX_GetGfxMotion(pUnit);
    if (!pMotion || pMotion->dwFlags & 1)
    {
        return;
    }

    pMotion->tA.nX += pMotion->tB.nX;
    pMotion->tB.nX += pMotion->tD.nX;
    pMotion->tA.nY += pMotion->tB.nY;
    pMotion->tB.nY += pMotion->tD.nY;
    pMotion->tA.nZ += pMotion->tB.nZ;
    pMotion->tB.nZ += pMotion->tD.nZ;
    int* pX = &pMotion->tA.nX;
    int* pY = &pMotion->tA.nY;

    if (pMotion->dwFlags & 2)
    {
        if (pMotion->nFrames)
        {
            --pMotion->nFrames;
        }
        else
        {
            pMotion->dwFlags |= 1;
            pMotion->tA.nX = 0;
            pMotion->tA.nY = 0;
        }
    }

    unsigned int dwFlags = pMotion->dwFlags;
    if (dwFlags & 4)
    {
        if ((pMotion->tA.nZ >> 11) <= pMotion->tC.nZ)
        {
            pMotion->tB.nZ = pMotion->nParam1 * pMotion->tB.nZ / -100;
            pMotion->tA.nZ = pMotion->tC.nZ;
            if (pMotion->nParam0)
            {
                --pMotion->nParam0;
            }
            else
            {
                pMotion->dwFlags = dwFlags | 1;
            }
        }
    }
    else if (dwFlags & 0x10)
    {
        D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pUnit);
        if (pOwner)
        {
            int nOffsetX = 0;
            int nOffsetY = 0;
            int nComponent = 8;
            switch (!pUnit ? 6 : pUnit->dwUnitType)
            {
            case UNIT_MISSILE:
                D2_ASSERT(pOwner->dwUnitType == UNIT_MONSTER, 425);
                if (!pOwner->dwAnimMode || pOwner->dwAnimMode == MONMODE_DEAD)
                {
                    return;
                }
            case UNIT_MONSTER:
                nComponent = 14;
                break;
            }

            GFX_GetUnitCelOffsets(pOwner, nComponent, &nOffsetX, &nOffsetY);
            pMotion->nClientX = nOffsetX;
            pMotion->nClientZ = nOffsetY;
            if (pUnit && pUnit->dwUnitType == UNIT_MISSILE)
            {
                pMotion->nClientZ += 10;
            }
            pMotion->nClientX += PARTICLE_GetGfxOffsetX(pOwner);
            pMotion->nClientZ += sub_004DA0F0_GetUnitGfxOffsetZ(pOwner);
            pMotion->tA.nX = pMotion->nClientX;
            pMotion->tA.nY = pMotion->nClientY;
            DUNGEON_ClientToGameSubtileCoords(pX, pY);
            pMotion->tA.nZ = -(pMotion->nClientZ << 11);
        }
    }
    else if (!(dwFlags & 0x20) && (pMotion->tA.nX >> 11) <= pMotion->tC.nX && (pMotion->tA.nY >> 11) <= pMotion->tC.nY && (pMotion->tA.nZ >> 11) <= pMotion->tC.nZ)
    {
        pMotion->tA.nX = pMotion->tC.nX << 11;
        pMotion->tA.nY = pMotion->tC.nY << 11;
        pMotion->tA.nZ = pMotion->tC.nZ << 11;
        pMotion->dwFlags = dwFlags | 1;
    }
    else if ((dwFlags & 0x20) && (pMotion->tA.nX >> 11) >= pMotion->tC.nX && (pMotion->tA.nY >> 11) >= pMotion->tC.nY && (pMotion->tA.nZ >> 11) >= pMotion->tC.nZ)
    {
        pMotion->tA.nX = pMotion->tC.nX << 11;
        pMotion->tA.nY = pMotion->tC.nY << 11;
        pMotion->tA.nZ = pMotion->tC.nZ << 11;
        pMotion->dwFlags = dwFlags | 1;
    }

    if (!(pMotion->dwFlags & 0x10))
    {
        pMotion->nClientX = pMotion->tA.nX >> 11;
        pMotion->nClientY = pMotion->tA.nY >> 11;
        DUNGEON_GameToClientCoords(&pMotion->nClientX, &pMotion->nClientY);
        pMotion->nClientZ = -(pMotion->tA.nZ >> 11);
    }
}

// 0x004DA5B0
void __fastcall GFXUTIL_SetBallistic(D2UnitStrc* pUnit, int nSpeed, int nFrames)
{
    D2BallisticStrc* pBallistic = sub_0046F060(pUnit);
    if (!pBallistic)
    {
        return;
    }

    pBallistic->dwFlags |= 2;
    pBallistic->nFrames = nFrames;
    if (nFrames < 1)
    {
        pBallistic->nFrames = 1;
    }

    nSpeed <<= 0x0B;
    pBallistic->f_4 = 0;
    pBallistic->f_8 = 0;
    pBallistic->nVelocity = nSpeed;
    if (!pBallistic->nAcceleration)
    {
        pBallistic->nAcceleration = -0x1000;
    }

    pBallistic->nVelA = 0;
    pBallistic->nVelB = 0;
    pBallistic->nStartVelocity = (-nSpeed - pBallistic->nAcceleration * pBallistic->nFrames * pBallistic->nFrames / 2) / pBallistic->nFrames;
}


// 0x004DA620
void __fastcall GFXUTIL_SetMotionFlag10(D2UnitStrc* pUnit, int bSet)
{
    D2GfxMotionStrc* pMotion = GFX_GetGfxMotion(pUnit);
    if (pMotion)
    {
        if (bSet)
            pMotion->dwFlags |= 0x10;
        else
            pMotion->dwFlags &= ~0x10;
    }
}

// 0x004DA6E0
void __fastcall GFXUTIL_SetMotionFlagMask(D2UnitStrc* pUnit, int bSet)
{
    D2GfxMotionStrc* pMotion = GFX_GetGfxMotion(pUnit);
    if (pMotion)
    {
        if (bSet)
            pMotion->dwFlags |= 0x20;
        else
            pMotion->dwFlags &= ~0x20;
    }
}

// 0x004DA700
int __fastcall GFXUTIL_GetGfxMotionFlag5(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = GFX_GetGfxMotion(pUnit);
    if (pMotion)
    {
        return pMotion->bFlag5;
    }
    return 0;
}



D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

static int UNITS_GetClassIdInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwClassId;
}

// 0x004DAAB0
void __fastcall GFXUTIL_GetArmorComponents(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int bSkip, unsigned char* pComponents)
{
    if (!pInventory)
    {
        return;
    }

    D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, 3);
    if (!bSkip && ITEMS_CanBeEquipped(pItem))
    {
        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(UNITS_GetClassIdInline(pItem));
        if (!pItemsTxtRecord)
        {
            return;
        }

        pComponents[0] = pItemsTxtRecord->nArmorComp[0];
        pComponents[1] = pItemsTxtRecord->nArmorComp[1];
        pComponents[2] = pItemsTxtRecord->nArmorComp[2];
        pComponents[3] = pItemsTxtRecord->nArmorComp[3];
        pComponents[4] = pItemsTxtRecord->nArmorComp[4];
        pComponents[5] = pItemsTxtRecord->nArmorComp[5];
        return;
    }

    memset(pComponents, 0, 6);
}

// 0x004DB1A0
unsigned char __fastcall GFXUTIL_GetGfxEntryByte(D2UnitStrc* pUnit, int nIndex)
{
    D2GfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
    if (!pGfxData)
        return 0;
    return pGfxData->aEntries[nIndex][0];
}

struct Unicode;

void* __fastcall sub_0046E5A0_FindGfxNode(D2UnitStrc* pUnit, int nWeaponClassId, int nArg); // 0x0046E5A0

int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit); // 0x006203B0

int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit); // 0x00620410

int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit); // 0x00620650

class D2SquelchListStrc
{
public:
    virtual int Squelch(const char* szName);
    virtual int Unsquelch(const char* szName);
    virtual int IsSquelched(const char* szName);
    virtual int AddFilter(const char* szText);
    virtual int RemoveFilter(const char* szText);
    virtual int IsFiltered(const char* szText);
    virtual void VirtSlot6();
    virtual void VirtSlot7();
    virtual int IsPersistent();
    virtual void SetPersistent(int bPersistent);
};

int __fastcall GFXUTIL_GetCofLayerValue(const unsigned char* pData, int nCode); // 0x004DB0D0

// 0x004DB670
int __fastcall GFXUTIL_UpdateUnitGfx(D2UnitStrc* pUnit, int nArg)
{
    int nX = 0;
    int nY = 0;
    if (sub_004F51D0_IsPerspective())
    {
        sub_004F6760_PrecisionToScreen(UNITS_GetPrecisionX(pUnit), UNITS_GetPrecisionY(pUnit), 0, &nX, &nY);
        switch (sub_0045AE90())
        {
        case 1:
            nX -= gnScreenWidth / 4;
            break;

        case 2:
            nX += gnScreenWidth / 4;
            break;
        }
    }
    else
    {
        nX = UNITS_GetClientCoordX(pUnit) - PLAYER_GetScreenOffsetX();
        nY = UNITS_GetClientCoordY(pUnit) - PLAYER_GetScreenOffsetY();
    }

    if (!GFX_IsUnitOnScreen(pUnit, nX, nY, 0, 0))
    {
        return 0;
    }

    D2InventoryStrc* pInventory;
    D2UnitStrc* pOwner;
    int bShapeshifted = pUnit ? (pUnit->dwFlagEx >> 3) & 1 : 0;
    if (bShapeshifted && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && (pOwner = CUNIT_GetOwnerUnit(pUnit)) != 0)
    {
        pInventory = pOwner->pInventory;
    }
    else
    {
        pInventory = pUnit->pInventory;
    }

    int nWeaponClassId[2];
    const int nId = COMPOSIT_GetWeaponClassId(pUnit, pInventory, nWeaponClassId, -1, 1);
    if (!sub_0046E5A0_FindGfxNode(pUnit, nId, -1) && !GFX_LoadUnitGfxNode(pUnit, nId, -1))
    {
        return 0;
    }

    void* pEntry = sub_0046E570_GetGfxEntry(pUnit, sub_0046DA60_GetUnitMode(pUnit));
    if (!pEntry)
    {
        return 0;
    }

    return GFXUTIL_GetCofLayerValue((const unsigned char*)pEntry, nArg);
}

// 0x004DBEA0
void __fastcall GFXUTIL_GetUnitCelSize(D2UnitStrc* pUnit, int nArg40, int nArg0, int* pWidth, int* pHeight)
{
    D2CelContextStrc tToken;
    memset(&tToken, 0, sizeof(tToken));
    tToken.nFrame = nArg0;
    tToken.nArg34 = 0;
    tToken.nDirection = nArg40;
    tToken.nComponent = 1;
    if (GFXUTIL_ResolveUnitCelContext(pUnit, &tToken, -1, &nArg0) && sub_006001F0(&tToken, 0, 1) && tToken.pCel)
    {
        *pWidth = CelGetWidth(tToken.pCel);
        *pHeight = CelGetHeight(tToken.pCel);
    }
}

// 0x004DBF20
int __fastcall GFXUTIL_HitTestUnitCel(D2UnitStrc* pUnit, int nX, int nY)
{
    int nScreenY;
    int nFrameNo;
    int nFrameCount;
    const int nScreenX = nX - PLAYER_GetScreenOffsetX();
    nScreenY = nY - PLAYER_GetScreenOffsetY();
    if (GFX_IsUnitOnScreen(pUnit, nScreenX, nScreenY, 0, 0))
    {
        UNITS_GetShiftedFrameMetrics(pUnit, &nFrameNo, &nFrameCount);
        D2CelContextStrc tToken;
        memset(&tToken, 0, sizeof(tToken));
        if (GFXUTIL_InitUnitCelContext(&tToken, pUnit, 0, UNITS_GetDirection(pUnit), nFrameNo, &nY, 1, -1) && sub_006001F0(&tToken, 0, 1))
        {
            D2CelStrc* const pCel = tToken.pCel;
            if (pCel)
                return sub_004DAB40_CheckCel(pCel, nScreenX, nScreenY, 0);
        }
    }
    return 0;
}

// 0x004DBFE0
void __cdecl GFXUTIL_StartFadeTimer()
{
    gdwFadeTick = GetTickCount() + 500;
}

// 0x004DC000
void __cdecl GFXUTIL_DrawFadeBox()
{
    if (!gdwFadeTick)
    {
        return;
    }

    unsigned int dwNow = GetTickCount();
    if (dwNow > gdwFadeTick)
    {
        gdwFadeTick = 0;
        return;
    }

    int nRemaining = gdwFadeTick - dwNow;
    int nYEnd = gnScreenHeight - 47;
    int nXEnd = gnScreenWidth;
    int nXStart = 0;
    switch (sub_0045AE90())
    {
    case 1:
        nXEnd -= gnScreenWidth / 2;
        break;

    case 2:
        nXStart = gnScreenWidth / 2;
        break;
    }

    D2GFX_DrawBoxAlpha(nXStart, 0, nXEnd, nYEnd, 0, nRemaining * 255 / 500);
}

// 0x004DC0A0
void __cdecl GFXUTIL_ClearFadeTimer()
{
    gdwFadeTick = 0;
}

// 0x004DC0B0
D2RosterInfoStrc* __fastcall GFXUTIL_GetNextRosterInfo(D2RosterInfoStrc* pRosterInfo)
{
    if (!pRosterInfo)
    {
        return 0;
    }
    return pRosterInfo->pNext;
}


// 0x004DC3E0
void __fastcall GFXUTIL_SetRelationFlag(int nUnitId1, int nUnitId2, unsigned int nFlags, int bSet)
{
    D2RosterInfoStrc** ppRosterInfo = ROSTER_GetRosterInfoList(nUnitId1);
    if (!ppRosterInfo || nUnitId1 == nUnitId2)
    {
        return;
    }

    for (D2RosterInfoStrc* pRosterInfo = *ppRosterInfo; pRosterInfo; pRosterInfo = pRosterInfo->pNext)
    {
        if (pRosterInfo->dwUnitId == nUnitId2)
        {
            if (bSet)
            {
                pRosterInfo->dwPartyFlags |= nFlags;
            }
            else
            {
                pRosterInfo->dwPartyFlags &= ~nFlags;
            }
            return;
        }
    }
}

// 0x004DC440
unsigned int __fastcall GFXUTIL_TestRelationFlags(int nUnitId1, int nUnitId2, unsigned int nFlags)
{
    D2RosterInfoStrc** ppRosterInfo = ROSTER_GetRosterInfoList(nUnitId1);
    if (!ppRosterInfo || nUnitId1 == nUnitId2)
    {
        return 0;
    }

    for (D2RosterInfoStrc* pRosterInfo = *ppRosterInfo; pRosterInfo; pRosterInfo = pRosterInfo->pNext)
    {
        if (pRosterInfo->dwUnitId == nUnitId2)
        {
            return pRosterInfo->dwPartyFlags & nFlags;
        }
    }

    return 0;
}

// 0x004DC480
unsigned short __fastcall GFXUTIL_GetRelationFlagWord(int nUnitId1, int nUnitId2)
{
    D2RosterInfoStrc** ppRosterInfo = ROSTER_GetRosterInfoList(nUnitId1);
    if (!ppRosterInfo || nUnitId1 == nUnitId2)
    {
        return 0;
    }
    for (D2RosterInfoStrc* pRosterInfo = *ppRosterInfo; pRosterInfo; pRosterInfo = pRosterInfo->pNext)
    {
        if (pRosterInfo->dwUnitId == nUnitId2)
        {
            return pRosterInfo->wPartyFlags;
        }
    }
    return 0;
}

// 0x004DC4C0
void __fastcall GFXUTIL_SetRelationFlags(int nUnitId1, int nUnitId2, unsigned int nFlags)
{
    D2RosterInfoStrc** ppRosterInfo = ROSTER_GetRosterInfoList(nUnitId1);
    if (!ppRosterInfo || nUnitId1 == nUnitId2)
    {
        return;
    }

    for (D2RosterInfoStrc* pRosterInfo = *ppRosterInfo; pRosterInfo; pRosterInfo = pRosterInfo->pNext)
    {
        if (pRosterInfo->dwUnitId == nUnitId2)
        {
            pRosterInfo->dwPartyFlags &= 0xFFFF0000;
            pRosterInfo->dwPartyFlags |= nFlags;
            return;
        }
    }
}

// 0x004DDE00
int __stdcall GFXUTIL_TestLevelDrawEdges(int bArg)
{
    D2ActiveRoomStrc* pRoom = CUNIT_GetPlayerRoom();
    if (pRoom)
    {
        D2LevelsTxt* pLevelsTxtRecord = DATATBLS_GetLevelsTxtRecord(DUNGEON_GetLevelIdFromRoom(pRoom));
        if (pLevelsTxtRecord->nDrawEdges && !bArg && D2GFX_GetResolutionMode() == 2)
        {
            return 1;
        }
    }

    return 0;
}

// 0x004DDE80
void D2DrawBoundsStrc::ExtendBounds(D2DrawBoundsArgStrc* pArg, int nX, int nY)
{
    pArg->dwFlags |= 0x20000;
    if (bActive)
    {
        if (nX < nMinX)
        {
            nMinX = nX;
        }
        if (nX > nMaxX)
        {
            nMaxX = nX;
        }
        if (nY < nMinY)
        {
            nMinY = nY;
        }
        if (nY > nMaxY)
        {
            nMaxY = nY;
        }
    }
}

// 0x004E0700
void* D2OffsetTableRefStrc::GetEntry(int nId)
{
    D2OffsetTableStrc* pTable = this->f_0;
    if (!pTable)
    {
        return 0;
    }

    unsigned int nIndex = nId - pTable->nFirstId;
    if (nIndex >= pTable->nCount)
    {
        return 0;
    }

    return (char*)pTable + *(int*)((char*)pTable + pTable->nOffsetsOffset + nIndex * 4);
}

struct D2CoordStrc;

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

int __stdcall UNITS_SetAnimStartFrame(D2UnitStrc* ptUnit); // 0x00624390

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

int __stdcall UNITS_GetUnitSizeX(D2UnitStrc* pUnit); // 0x00620510

D2ActiveRoomStrc* __stdcall COLLISION_GetFreeCoordinates(D2ActiveRoomStrc* pRoom, D2CoordStrc* pSpawnPoint, int nUnitSize, unsigned int nMask, int bAllowNeighboringRooms); // 0x0064E7B0

int __stdcall D2Common_10231(D2DynamicPathStrc* pDynamicPath, D2UnitStrc* pUnit_unused, D2ActiveRoomStrc* pRooms, unsigned short nX, unsigned short nY); // 0x00650C20

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecordStd(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

static int UNITS_GetUnitXPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }

    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static int UNITS_GetUnitYPosition(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }

    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

D2UnitStrc* __fastcall MISSILE_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0

// 0x004E0A40
int __fastcall GFXUTIL_SkillStartPlace(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecordStd(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    UNITS_SetAnimStartFrame(pUnit);
    if (pUnit)
    {
        pUnit->dwFlags |= 0xE;
    }

    int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile > 0 && nMissile < sgptDataTables->nMissilesTxtRecordCount)
    {
        if (DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit))) == 1 && pSkillsTxtRecord->wCltMissileB > 0 && pSkillsTxtRecord->wCltMissileB < sgptDataTables->nMissilesTxtRecordCount)
        {
            nMissile = pSkillsTxtRecord->wCltMissileB;
        }

        MISSILE_SubmitOwnerRequest(pUnit, nMissile, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), nSkillId, nSkillLevel);
    }

    D2CoordStrc tCoord;
    tCoord.nX = UNITS_GetUnitXPosition(pUnit);
    tCoord.nY = UNITS_GetUnitYPosition(pUnit);
    D2ActiveRoomStrc* pRoom = COLLISION_GetFreeCoordinates(UNITS_GetRoom(pUnit), &tCoord, UNITS_GetUnitSizeX(pUnit), 0x1C09, 1);
    if (!pRoom)
    {
        return 0;
    }

    if (!pUnit->pDynamicPath)
    {
        return 0;
    }

    if (!D2Common_10231(pUnit->pDynamicPath, pUnit, pRoom, tCoord.nX, tCoord.nY))
    {
        return 0;
    }

    COLLISION_SetMaskWithPattern(UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 1, 0x1000);
    return 1;
}

// 0x004E0C60
int __fastcall GFXUTIL_CltDoResetActionFrame(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    int nFrameNo;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrameNo, &nFrameCount);
    pUnit->nActionFrame = 0;
    if (nFrameNo <= 0)
    {
        pUnit->dwSeqSpeed = 0;
    }

    return 1;
}

extern const unsigned char gabFrameDirections[8][9]; // 0x006DBA08

extern const unsigned char gabBaseDirections[8]; // 0x006DBA50

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

int __fastcall ITEM_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0

D2UnitStrc* __fastcall MISSILE_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0

unsigned char __stdcall INVENTORY_GetEightWayDirection(unsigned char nIndex); // 0x0063E7A0

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x004E0D40
int __fastcall GFXUTIL_SkillDoFrameOffset(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    int nX = SKILLS_GetParam1(pSkill);
    int nY = SKILLS_GetParam2(pSkill);
    if ((!nX || !nY) && !ITEM_GetTargetPosition(pUnit, &nX, &nY))
    {
        return 0;
    }

    unsigned char nDirection = (unsigned char)UNITS_GetDirectionToCoords(pUnit, nX, nY);
    unsigned char nIndex = INVENTORY_GetEightWayDirection(nDirection) & 7;
    nX = CLIENTS_GetUnitX(pUnit);
    nY = CLIENTS_GetUnitY(pUnit);

    int nOffsetX;
    int nOffsetY;
    INVENTORY_GetDirectionDelta(gabBaseDirections[nIndex], &nOffsetX, &nOffsetY);
    nX += nOffsetX;
    nY += nOffsetY;

    int nFrame;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);
    nFrame -= 4;
    int nClamp = nFrame > 0 ? nFrame : 0;
    nFrame = nClamp < 8 ? nClamp : 8;

    unsigned char nDir = gabFrameDirections[nIndex][nFrame];
    if (nDir != 99)
    {
        INVENTORY_GetDirectionDelta(nDir, &nOffsetX, &nOffsetY);
        nX += nOffsetX;
        nY += nOffsetY;
    }

    MISSILE_SubmitOwnerRequest(pUnit, nMissile, nX, nY, nSkillId, nSkillLevel);
    return 1;
}

// 0x004E0F40
int __fastcall GFXUTIL_CltDoSetAnimFrameFromCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        pSkillsTxtRecord = &sgptDataTables->pSkillsTxt[nSkillId];
    }

    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    if (SKILLS_GetFlags(pSkill) & 2)
    {
        SKILLS_SetFlags(pSkill, 0);
        UNITS_SetAnimationFrame(pUnit, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel));
    }
    else
    {
        UNITS_SetAnimationFrame(pUnit, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel));
    }

    return 1;
}

// 0x004E12F0
int __fastcall GFXUTIL_CltDoResetActionFrame2(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    int nFrameNo;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrameNo, &nFrameCount);
    pUnit->nActionFrame = 0;
    if (nFrameNo <= 0)
    {
        pUnit->dwSeqSpeed = 0;
    }

    return 1;
}

// 0x004E24D0
int __fastcall GFXUTIL_CltDoMissileA(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wCltMissileA;
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        AUTOMAP_RequestAtTarget(pUnit, nMissileId, nSkillId, nSkillLevel);
        return 1;
    }

    return 0;
}

// 0x004E3330
int __fastcall GFXUTIL_CltDoTest(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    return SKILLDESC_CltDoRandomMissile(pUnit, nSkillId, nSkillLevel) != 0;
}

// 0x004E4060
float __stdcall GFXUTIL_SqrtF(float fValue)
{
    return (float)sqrt(fValue);
}

// 0x004E4080
float __cdecl GFXUTIL_SqrtFCdecl(float fValue)
{
    return (float)sqrt(fValue);
}

// 0x004E4130
float __stdcall GFXUTIL_VectorLength(float fX, float fY)
{
    float fLengthSquared = fX * fX + fY * fY;
    return (float)sqrt(fLengthSquared);
}

static inline D2MonStatsTxt* GFXUTIL_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}


// 0x004E4160
float __stdcall GFXUTIL_VectorLengthSquared(float fX, float fY)
{
    return (float)(fX * fX + fY * fY);
}

// 0x004F20C0
int __fastcall GFXUTIL_CltDoSetParamFromCalc(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = 0;
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        pSkillsTxtRecord = &sgptDataTables->pSkillsTxt[nSkillId];
    }

    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nValue = sub_004648F0_GetPathValue(pUnit);
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    if (!nValue)
    {
        SKILLS_SetParam1(pSkill, 0);
    }
    else
    {
        SKILLS_SetParam1(pSkill, SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel));
    }

    return 1;
}

// 0x004F34D0
int __fastcall GFXUTIL_CltDoMissileC(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissileId = pSkillsTxtRecord->wCltMissileC;
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        AUTOMAP_RequestAtTarget(pUnit, nMissileId, nSkillId, nSkillLevel);
    }

    return 1;
}

// 0x004DAF70
static int __stdcall GFXUTIL_GetUnitModeDirections(D2UnitStrc* pUnit, int nMode, int nClassId, int nUnitType)
{
    if (nMode < 0)
    {
        return 1;
    }

    int nDirections = 1;
    switch (nUnitType)
    {
    case 0:
        if (!gbCharArchiveLoaded && pUnit == sub_00463DD0_GetPlayerUnit())
        {
            nDirections = 16;
        }
        else
        {
            nDirections = 8;
        }
        break;

    case 1:
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(nClassId);
        if (pMonStats2TxtRecord)
        {
            nDirections = pMonStats2TxtRecord->nModeDirections[nMode];
            if (nDirections == 8)
            {
                D2MonGfxCacheStrc* pCache = GFX_GetMonGfxCache(nClassId);
                if (pCache && !pCache->nModeFlags[nMode])
                {
                    nDirections = 4;
                }
            }
        }
        break;
    }

    case 3:
    {
        D2MissilesTxt* pMissilesTxtRecord = sub_0046ACE0(nClassId);
        if (pMissilesTxtRecord)
        {
            nDirections = pMissilesTxtRecord->nNumDirections;
        }
        break;
    }

    case 6:
        nDirections = GFXUTIL_GetOverlayDirections(nClassId);
        break;
    }

    return nDirections;
}

// 0x004DB040
extern "C" void* __fastcall GFXUTIL_identity(void* pointer)
{
    return pointer;
}

static D2OverlayTxt* DATATBLS_GetOverlayTxtRecordInline(int nOverlay)
{
    if (nOverlay >= 0 && nOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        return &sgptDataTables->pOverlayTxt[nOverlay];
    }

    return 0;
}

// 0x004DB050
int __fastcall GFXUTIL_GetCofLayerOverrideTransLvl(unsigned char* pData, int nComponent)
{
    int nResult = 0;
    if (pData && nComponent < 0x10)
    {
        const D2CofDataStrc* pHeader = (const D2CofDataStrc*)pData;
        pData += 0x1C;
        for (int i = 0; i < pHeader->nLayers; ++i, pData += sizeof(D2CofLayerStrc))
        {
            if (((D2CofLayerStrc*)pData)->nComponent == nComponent)
            {
                nResult = ((D2CofLayerStrc*)pData)->nOverrideTransLvl;
                break;
            }
        }
    }
    return nResult;
}

inline int STATES_IsUnitShapeShiftedInline(D2UnitStrc* pUnit)
{
    int bResult = 0;
    if (pUnit)
        bResult = (pUnit->dwFlagEx >> 3) & 1;
    return bResult;
}

// 0x004DAE60
int __fastcall GFXUTIL_UnitSupportsMode(D2UnitStrc* pUnit, int nMode)
{
    if (nMode >= 16)
    {
        return 0;
    }

    int nCurrentMode;
    int nUnitType;
    int nClassId;

    int nTypeValue = UNIT_INVALID;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }

    nUnitType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClassId = nClassValue;
    nCurrentMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nCurrentMode, ".\\ENGINE\\GfxUtil.cpp", 603);

    switch (nUnitType)
    {
    case UNIT_PLAYER:
        switch (nMode)
        {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 8:
        case 9:
            return 1;
        }
        break;

    case UNIT_MONSTER:
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(nClassId);
        if (pMonStats2TxtRecord && (pMonStats2TxtRecord->nComponentFlags[nMode >> 3] & gdwBitMasks[nMode & 7]))
        {
            return 1;
        }
        break;
    }

    case UNIT_OBJECT:
    {
        D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClassId);
        if (pObjectsTxtRecord && pObjectsTxtRecord->nModeEnabled[nMode] == 1)
        {
            return 1;
        }
        break;
    }

    case UNIT_ITEM:
        if (nMode == 1)
        {
            return 1;
        }
        break;
    }

    return 0;
}

void __fastcall sub_004DB2E0_GetUnitDirection(D2UnitStrc* pUnit, int nUnitType, int nClassId, int nMode, unsigned int* pDirection, int* pIndex, int* pDirCount, int nSrcDirCount, int bSet)
{
    if (*pDirection >= 64)
    {
        *pDirCount = 1;
        *pIndex = 0;
        return;
    }

    *pDirCount = GFXUTIL_GetUnitModeDirections(pUnit, nMode, nClassId, nUnitType);
    if (bSet)
    {
        GFXUTIL_ConvertDirection(nSrcDirCount, *pDirCount, pDirection);
        GFXUTIL_SetDeathDirection(*pDirection, bSet, pUnit, *pDirCount, nSrcDirCount);
    }

    *pIndex = CelGameDirToNormalDir(*pDirection, nSrcDirCount);
}

// 0x004DB090
int __fastcall GFXUTIL_GetCofLayerShadow(void* pCof, int nComponent)
{
    int nResult = 0;
    if (pCof && nComponent < 0x10)
    {
        const D2CofDataStrc* pHeader = (const D2CofDataStrc*)pCof;
        pCof = ((D2CofDataStrc*)pCof)->pLayers;
        for (int i = 0; i < pHeader->nLayers; ++i)
        {
            D2CofLayerStrc* pLayer = (D2CofLayerStrc*)pCof;
            if (pLayer->nComponent == nComponent)
            {
                nResult = pLayer->bShadow;
                break;
            }
            pCof = pLayer + 1;
        }
    }
    return nResult;
}

// 0x004DB0D0
int __fastcall GFXUTIL_GetCofLayerValue(const unsigned char* pData, int nCode)
{
    int nResult = 0;
    if (pData && nCode < 0x10)
    {
        const D2GfxCodeTableStrc* pTable = (const D2GfxCodeTableStrc*)pData;
        pData += 0x1C;
        for (int i = 0; i < pTable->nCount; ++i)
        {
            if (((const D2GfxCodeRecordStrc*)pData)->nCode == nCode)
            {
                nResult = ((const D2GfxCodeRecordStrc*)pData)->nValue;
                break;
            }
            pData += sizeof(D2GfxCodeRecordStrc);
        }
    }
    return nResult;
}

// 0x004DB110
unsigned char* __fastcall GFXUTIL_GetLayerOrder(D2CellBlockStrc* pBlock, int nX, int nY)
{
    if (!pBlock)
    {
        return 0;
    }

    return &pBlock->pData[(pBlock->nWidth * nX + nY + 9) * pBlock->nCount + pBlock->nWidth];
}

extern "C" int __fastcall sub_004DB180_range(const int* record)
{
    if (record && *record >= 0 && *record <= 2)
        return 1;
    return 0;
}

extern "C" PartialTableRecord* __fastcall sub_004E4640_boundedTable(int index)
{
    if (index >= 0 && index < gTableView_00744304->count)
        return &gTableView_00744304->records[index];
    return gTableView_00744304->records;
}

// 0x004DB140
int __fastcall GFXUTIL_GetCofLayerNewTransLvl(unsigned char* pData, int nComponent)
{
    if (!pData)
    {
        return 5;
    }
    if (nComponent >= 0x10)
    {
        return 5;
    }
    const D2CofDataStrc* pHeader = (const D2CofDataStrc*)pData;
    pData += 0x1C;
    for (int i = 0; i < pHeader->nLayers; ++i, pData += sizeof(D2CofLayerStrc))
    {
        if (((D2CofLayerStrc*)pData)->nComponent == nComponent)
        {
            return ((D2CofLayerStrc*)pData)->nNewTransLvl;
        }
    }
    return 5;
}

// 0x004DB180
int __fastcall GFXUTIL_IsPlayerMonsterOrObject(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType >= 0 && pUnit->dwUnitType <= 2)
    {
        return 1;
    }

    return 0;
}

// 0x004DB1C0
void __fastcall GFXUTIL_SetGfxEntryByte(D2UnitStrc* pUnit, int nIndex, unsigned char nValue)
{
    D2GfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
    if (pGfxData)
    {
        pGfxData->aEntries[nIndex][0] = nValue;
    }
}

// 0x004DB290
static void GFXUTIL_ConvertDirection(int nSrcDirCount, int nDirCount, unsigned int* pDirection)
{
    if (nSrcDirCount == 8)
    {
        if (nDirCount == 4)
        {
            const unsigned int nIndex = *(unsigned int*)pDirection * 8 >> 6;
            *pDirection = (unsigned int)CelConvertDir(nIndex, 8, nDirCount, 0) * 64 / 8;
        }
    }
    else if (nSrcDirCount == 16 && nDirCount == 8)
    {
        const unsigned int nIndex = *(unsigned int*)pDirection * 16 >> 6;
        *pDirection = (unsigned int)CelConvertDir(nIndex, 16, nDirCount, 0) * 64 / 16;
    }
}

// 0x004DB2E0
void __fastcall GFXUTIL_GetLayerInfo(D2UnitStrc* pUnit, int nUnitType, int nClassId, int nMode, unsigned int* pDirection, int* pIndex, int* pDirCount, int nSrcDirCount, int bSet)
{
    if (*pDirection >= 64)
    {
        *pDirCount = 1;
        *pIndex = 0;
        return;
    }

    *pDirCount = GFXUTIL_GetUnitModeDirections(pUnit, nMode, nClassId, nUnitType);
    if (bSet)
    {
        GFXUTIL_ConvertDirection(nSrcDirCount, *pDirCount, pDirection);
        GFXUTIL_SetDeathDirection(*pDirection, bSet, pUnit, *pDirCount, nSrcDirCount);
    }
    *pIndex = CelGameDirToNormalDir(*pDirection, nSrcDirCount);
}

// 0x004DB360
int __fastcall GFXUTIL_GetCompTransparency(D2UnitStrc* pUnit, int nComponent, int* pOut, int nItemId)
{
    const int nType = GFX_GetConvertedUnitType(pUnit);
    switch (nType)
    {
    case 1:
    {
        const int nStat = STATLIST_UnitGetStatValue(pUnit, STAT_FADE, 0);
        if (nStat <= 0)
            break;
        if (nStat > 0xF)
        {
            D2InventoryStrc* pInventory = pUnit->pInventory;
            if (!pInventory)
                return 0;
            for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory); pItem; pItem = INVENTORY_GetNextItem(pItem))
            {
                D2UnitStrc* pChecked = INVENTORY_UnitIsItem(pItem);
                if (pChecked && sub_006280A0(pChecked, 0x400000, 0x5E6, (unsigned int)".\\ENGINE\\GfxUtil.cpp"))
                {
                    *pOut = 1;
                    return 1;
                }
            }
            return 0;
        }
        *pOut = 1;
        return 1;
    }
    case 0:
        if (STATLIST_UnitGetStatValue(pUnit, STAT_FADE, 0))
        {
            *pOut = 1;
            return 1;
        }
        break;
    }

    if (nItemId != -1)
    {
        D2ItemsTxt* pTxt = DATATBLS_GetItemsTxtRecord(nItemId);
        if (pTxt && pTxt->nTransparent)
        {
            *pOut = pTxt->nTransTbl;
            return 1;
        }
    }

    if (nType)
        return 0;

    D2InventoryStrc* pInventory;
    D2UnitStrc* pOwner;
    if (STATES_IsUnitShapeShiftedInline(pUnit) && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && (pOwner = CUNIT_GetOwnerUnit(pUnit)) != 0)
    {
        pInventory = pOwner->pInventory;
    }
    else
    {
        pInventory = pUnit->pInventory;
    }

    if (!pInventory)
        return 0;

    switch (nComponent)
    {
    case 7:
    {
        D2UnitStrc* pItem = INVENTORY_GetCompositItem(pInventory, 7);
        if (pItem && sub_006280A0(pItem, 0x400000, 0x627, (unsigned int)".\\ENGINE\\GfxUtil.cpp"))
        {
            *pOut = 2;
            return 1;
        }
        break;
    }
    case 6:
    {
        D2UnitStrc* pItem = INVENTORY_GetCompositItem(pInventory, 6);
        if (pItem && sub_006280A0(pItem, 0x400000, 0x61C, (unsigned int)".\\ENGINE\\GfxUtil.cpp"))
        {
            *pOut = 1;
            return 1;
        }
        break;
    }
    case 5:
    {
        D2UnitStrc* pItem = INVENTORY_GetCompositItem(pInventory, 5);
        if (pItem && sub_006280A0(pItem, 0x400000, 0x611, (unsigned int)".\\ENGINE\\GfxUtil.cpp"))
        {
            *pOut = 1;
            return 1;
        }
        break;
    }
    }

    return 0;
}

// 0x004DBB50
int __fastcall GFXUTIL_InitUnitCelContext(D2CelContextStrc* pToken, D2UnitStrc* pUnit, int nArg34, int nArg40, int nArg0, int* pItemId, unsigned char nComponent, int nMode)
{
    pToken->nArg34 = nArg34;
    pToken->nDirection = nArg40;
    pToken->nFrame = nArg0;
    pToken->nComponent = nComponent;
    return GFXUTIL_ResolveUnitCelContext(pUnit, pToken, nMode, pItemId);
}

static int UNITS_GetUnitTypeInline(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 6;
    }

    return pUnit->dwUnitType;
}


// 0x004DB1E0
static void __stdcall GFXUTIL_SetDeathDirection(unsigned int nDirection, int bSet, D2UnitStrc* pUnit, int nDirCount, int nSrcDirCount)
{
    if (!bSet)
    {
        return;
    }

    int nUnitType = UNITS_GetUnitTypeInline(pUnit);
    int nClassId = UNITS_GetClassIdInline(pUnit);
    int nMode = UNITS_GetAnimOrSeqMode(pUnit);
    D2COMMON_11013_ConvertMode(pUnit, &nUnitType, &nClassId, &nMode, ".\\ENGINE\\GfxUtil.cpp", 0x53C);
    switch (nUnitType)
    {
    case 0:
        if ((nMode == 0 || nMode == 17) && nDirCount != nSrcDirCount)
        {
            sub_006488A0_SetDirection(pUnit->pDynamicPath, nDirection);
        }
        break;

    case 1:
        if ((nMode == 0 || nMode == 12) && nDirCount != nSrcDirCount)
        {
            sub_006488A0_SetDirection(pUnit->pDynamicPath, nDirection);
        }
        break;
    }
}

// 0x004DBB80
static int __stdcall GFXUTIL_FillMonsterCelContext(D2CompEntryListStrc* pList, unsigned int dwCode0, D2CelContextStrc* pToken, int nMode, D2MonCompInfoStrc* pClassInfo, D2CompArgStrc* pArgRec, int nRow)
{
    D2_ASSERT(dwCode0, 0x3E2);
    D2_ASSERT(pList, 0x3E3);

    pToken->nClass = pClassInfo->nClass;
    pToken->nMode = nMode;
    const unsigned char nComponent = pToken->nComponent;
    pToken->nType = 1;
    pToken->nArg1C = gaCompTokens[nComponent];
    pToken->dwCode = dwCode0;
    pToken->dwToken = 0x2074696C;
    pToken->nArg18 = pArgRec->nArg18;

    D2CompEntryStrc* pListEntry = pList->pEntry;
    D2_ASSERT(pListEntry, 0x3F0);

    D2CompRecordStrc* pComp = pListEntry->aComps;
    for (unsigned int i = 0; i < pListEntry->nCount; ++i, ++pComp)
    {
        D2_ASSERT(pComp->nComponent < 0x10, 0x3FB);
        if (pComp->nComponent == nComponent)
            goto found;
    }
    return 0;

found:

    pToken->dwModeToken = gaMonModeTokens[nMode];
    const int nClass = pToken->nClass;
    const unsigned int nComponentId = pToken->nComponent;
    const unsigned char nIndex = pClassInfo->aComp[nRow][nComponentId];
    if (nMode != 0 && nMode != 0xC)
        pToken->dwToken = sub_00664930_GetMonComponentToken(nClass, nComponentId, nIndex);
    else if (MONSTERREGION_CheckMonStats2Flag(nClass, 0x10))
        pToken->dwToken = sub_00664930_GetMonComponentToken(nClass, nComponentId, nIndex);

    D2CompCodeStrc tCode;
    tCode.dwCode = 0;
    GFXUTIL_CopyCompCode(&tCode, pComp->szCode);
    pToken->dwCode = tCode.dwCode;
    D2_ASSERT(pToken->nArg1C, 0x425);
    D2_ASSERT(pToken->nArg18, 0x426);
    D2_ASSERT(tCode.dwCode, 0x427);
    if (!pToken->dwToken)
        pToken->dwToken = 0x20787878;
    if (!pToken->dwModeToken)
        pToken->dwModeToken = 0x20787878;
    return 1;
}

// 0x004DBCF0
int __fastcall GFXUTIL_InitMonsterCelContext(D2CelContextStrc* pToken, int nArg40, int nArg0, unsigned char nComponent, int nMode, unsigned int dwCode0, D2CompEntryListStrc* pList, D2MonCompInfoStrc* pClassInfo, D2CompArgStrc* pArgRec, int nRow)
{
    pToken->nDirection = nArg40;
    pToken->nFrame = nArg0;
    pToken->nComponent = nComponent;
    return GFXUTIL_FillMonsterCelContext(pList, dwCode0, pToken, nMode, pClassInfo, pArgRec, nRow);
}


// 0x004DBD30
int __fastcall GFXUTIL_GetComponentsMaxHeight(D2UnitStrc* pUnit, unsigned char* pList, unsigned char* pComponents, int* pMax, int nArg40, int nArg0)
{
    int nCount = 0;
    for (int i = 0; i < pList[0]; ++i)
    {
        const int nComponent = pComponents[i];
        D2_ASSERT(nComponent < 0x10, 0x59D);
        D2CelContextStrc tToken;
        memset(&tToken, 0, sizeof(tToken));
        tToken.nDirection = nArg40;
        tToken.nFrame = nArg0;
        tToken.nArg34 = 0;
        tToken.nComponent = nComponent;
        int nItemId;
        if (GFXUTIL_ResolveUnitCelContext(pUnit, &tToken, -1, &nItemId) && sub_006001F0(&tToken, 0, 1) && tToken.pCel)
        {
            const int nHeight = CelGetOffsetY(tToken.pCel) - PLAYER_GetScreenOffsetY() + UNITS_GetClientCoordY(pUnit);
            if (nHeight > *pMax)
                *pMax = nHeight;
            ++nCount;
        }
    }
    return nCount;
}

inline D2InventoryStrc* __fastcall GFX_GetCompInventory(D2UnitStrc* pUnit, int* pOut)
{
    if (STATES_IsUnitShapeShiftedInline(pUnit))
    {
        if (STATES_CheckStateMaskOnUnit(pUnit, 0x25))
        {
            D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pUnit);
            if (pOwner)
            {
                if (pOut)
                    *pOut = 1;
                return pOwner->pInventory;
            }

            if (pOut)
                *pOut = 0;
            return pUnit->pInventory;
        }

        if (pOut)
            *pOut = 0;
        return pUnit->pInventory;
    }

    if (pOut)
        *pOut = 0;
    return pUnit->pInventory;
}

static inline D2InventoryStrc* GetCompInventoryInline(D2UnitStrc* pUnit)
{
    int nOut;
    return GFX_GetCompInventory(pUnit, &nOut);
}


// 0x004DB570
int __fastcall GFXUTIL_GetBodyLocItemShift(D2UnitStrc* pUnit, int nBodyLoc, int nDefault)
{
    if (nBodyLoc >= 16)
    {
        return nDefault;
    }

    if (pUnit && !sub_0046D9F0_TestUnit(pUnit))
    {
        D2InventoryStrc* pInventory;
        D2UnitStrc* pOwner;
        if (STATES_IsUnitShapeShiftedInline(pUnit) && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && (pOwner = CUNIT_GetOwnerUnit(pUnit)) != 0)
        {
            pInventory = pOwner->pInventory;
        }
        else
        {
            pInventory = pUnit->pInventory;
        }

        if (pInventory)
        {
            D2UnitStrc* pItem = INVENTORY_GetCompositItem(pInventory, nBodyLoc);
            if (!pItem && nBodyLoc != 1 && sub_0064F420_HasBodyLocFallback(nBodyLoc))
            {
                pItem = INVENTORY_GetCompositItem(pInventory, 1);
            }

            if (pItem && !ITEMS_CheckItemFlag(pItem, 0x100, 0x656, ".\\ENGINE\\GfxUtil.cpp") && !ITEMS_CheckItemFlag(pItem, 0x4000, 0x657, ".\\ENGINE\\GfxUtil.cpp"))
            {
                if (ITEMS_GetAltGfx(pItem) == 0x2074696C)
                {
                    return 0;
                }

                unsigned char nShift;
                const int nResult = sub_0062C100(pUnit, pItem, &nShift, 0);
                if (nResult)
                {
                    return nResult;
                }
            }
        }
    }

    return nDefault;
}

// 0x004DB7B0
static int __stdcall GFXUTIL_ResolveUnitCelContext(D2UnitStrc* pUnit, D2CelContextStrc* pToken, int nMode, int* pItemId)
{
    int nType = 6;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
        int nClass = pUnit->dwClassId;
        int nAnimMode = UNITS_GetAnimOrSeqMode(pUnit);
// build: symbol ?gszGfxUtilCpp@* 0x006DB974
        D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nAnimMode, gszGfxUtilCpp, 0x2F0);
        pToken->nType = nType;
        pToken->nClass = nClass;
        if (nMode == -1)
            nMode = nAnimMode;
        pToken->nMode = nMode;
    }
    else
    {
        pToken->nType = nType;
    }

    switch (nType)
    {
    case 0:
    case 1:
    case 2:
    {
        *pItemId = -1;
        D2InventoryStrc* pInventory = GetCompInventoryInline(pUnit);
        pToken->nArg1C = gaCompTokens[pToken->nComponent];
        int nWeaponClassId;
        pToken->dwCode = COMPOSIT_GetWeaponClassId(pUnit, pInventory, &nWeaponClassId, pToken->nMode, 0);
        if (!GFXUTIL_FindGfxListNode(pUnit, pToken->dwCode, pToken->nMode) && !GFX_LoadUnitGfxNode(pUnit, pToken->dwCode, pToken->nMode))
            return 0;

        D2CompEntryStrc* pEntry = sub_0046E570_GetGfxEntry(pUnit, pToken->nMode);
        if (!pEntry)
            return 0;

        if (!CUNIT_GetGfxData(pUnit))
            return 0;

        pToken->dwToken = 0x2074696C;
        pToken->nArg18 = GFXUTIL_GetModeArg(pUnit, pToken->nType, pToken->nClass);

        D2CompRecordStrc* pComp = pEntry->aComps;
        for (int i = 0; i < pEntry->nCount; ++i, ++pComp)
        {
            if (pComp->nComponent >= 0x10)
                return 0;
            if (pComp->nComponent == pToken->nComponent)
                goto found;
        }
        return 0;

found:

        switch (nType)
        {
        case 0:
        {
            if (pUnit == sub_00463DD0_GetPlayerUnit())
                pToken->nFlags |= 8;

            if (!pInventory)
            {
                pToken->dwToken = 0x2074696C;
                return 0;
            }

            pToken->dwModeToken = gaPlrModeTokens[pToken->nMode];
            D2ArmorCompsStrc tComps;
            GFXUTIL_GetArmorComponents(pUnit, pInventory, nType, &tComps.n0);
            D2UnitStrc* pItem = INVENTORY_GetCompositItem(pInventory, pToken->nComponent);
            if (sub_0064F420_HasBodyLocFallback(pToken->nComponent))
            {
                if (pToken->nMode != 0x11 && pToken->nMode != 0)
                    pToken->dwToken = gaClassTokens[sub_0064F500_GetFallbackIndex(pToken->nComponent, &tComps.n0)];
                else
                    pToken->dwToken = 0x2074696C;
            }
            else
            {
                pToken->dwToken = GFXUTIL_GetWeaponClassToken(pUnit, pToken->nComponent);
                if (pItem && !pToken->dwToken && ITEMS_CanBeEquipped(pItem))
                    pToken->dwToken = ITEMS_GetAltGfx(pItem);
                else if (!pToken->dwToken)
                    pToken->dwToken = 0x2074696C;
            }

            if (!pToken->dwToken)
                return 0;
            break;
        }
        case 1:
        {
            const int nMonMode = pToken->nMode;
            pToken->dwModeToken = gaMonModeTokens[nMonMode];
            const unsigned char nComp = pComp->nComponent;
            const unsigned char nIndex = GFXUTIL_GetMonComponentIndex(pUnit, nComp);
            if (nMonMode != 0 && nMonMode != 0xC)
                pToken->dwToken = D2Common_11069(pUnit, nComp, nIndex);
            else if (MONSTERREGION_CheckMonStats2Flag(pToken->nClass, 0x10))
                pToken->dwToken = D2Common_11069(pUnit, nComp, nIndex);
            break;
        }
        case 2:
            pToken->dwModeToken = gaObjModeTokens[pToken->nMode];
            break;
        }

        D2CompCodeStrc tCode;
        tCode.dwCode = 0;
        GFXUTIL_CopyCompCode(&tCode, pComp->szCode);
        pToken->dwCode = tCode.dwCode;
        if (!pToken->nArg1C || !pToken->nArg18 || !tCode.dwCode)
            return 0;

        if (!pToken->dwModeToken)
            pToken->dwModeToken = 0x20787878;
        if (!pToken->dwToken)
            pToken->dwToken = 0x2074696C;

        int nItemId;
        if (DATATBLS_GetItemRecordFromItemCode(pToken->dwToken, &nItemId))
            *pItemId = nItemId;
        return 1;
    }
    case 4:
        GFXUTIL_ConvertItemMode(pUnit, &pToken->nMode);
        GFXUTIL_SetItemCelName(pUnit, pToken);
        return 1;
    case 3:
        GFXUTIL_SetMissileCelName(pUnit, pToken);
        return 1;
    case 6:
    {
        const int nOverlay = pToken->nOverlay;
        pToken->nFlags |= 2;
        D2OverlayTxt* pRecord = (nOverlay >= 0 && nOverlay < sgptDataTables->nOverlayTxtRecordCount) ? &sgptDataTables->pOverlayTxt[nOverlay] : 0;
        if (pRecord)
            pToken->szName = pRecord->szFilename;
        return 1;
    }
    }

    return 0;
}

// 0x004DBE20
int __fastcall GFXUTIL_GetOverlayFrameCount(D2UnitStrc* pUnit, D2OverlaySourceStrc* pSrc)
{
    int nItemId;
    D2CelContextStrc tToken;
    memset(&tToken, 0, sizeof(tToken));
    tToken.nOverlay = pSrc->nOverlay;
    if (!GFXUTIL_InitUnitCelContext(&tToken, 0, 0, UNITS_GetDirection(pUnit), pSrc->nArg0, &nItemId, 1, -1))
        return 1;
    if (!sub_006001F0(&tToken, 0, 1))
        return 1;
    return tToken.nFrames << 8;
}

// 0x004DA150
int __stdcall GFXUTIL_GetMotionAZ(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = GFX_GetGfxMotion(pUnit);
    if (pMotion)
    {
        return pMotion->tA.nZ >> 11;
    }

    return 0;
}


// 0x004DA170
int __stdcall GFXUTIL_GetMotionRawAX(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = GFX_GetGfxMotion(pUnit);
    if (pMotion)
    {
        return pMotion->tA.nX;
    }

    return 0;
}

// 0x004DA190
int __stdcall GFXUTIL_GetMotionRawAY(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = GFX_GetGfxMotion(pUnit);
    if (pMotion)
    {
        return pMotion->tA.nY;
    }

    return 0;
}

// 0x004DA1B0
int __stdcall GFXUTIL_GetMotionRawAZ(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = GFX_GetGfxMotion(pUnit);
    if (pMotion)
    {
        return pMotion->tA.nZ;
    }

    return 0;
}

// 0x004DA1D0
void __stdcall GFXUTIL_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ)
{
    D2GfxMotionStrc* pMotion = GFX_GetGfxMotion(pUnit);
    if (pMotion)
    {
        pMotion->tA.nX = nX << 11;
        pMotion->tA.nY = nY << 11;
        pMotion->tA.nZ = nZ << 11;
    }
}

// 0x004DA200
void __stdcall GFXUTIL_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift)
{
    D2GfxMotionStrc* pMotion = GFX_GetGfxMotion(pUnit);
    if (pMotion)
    {
        if (bShift)
        {
            pMotion->tB.nX = nX << 11;
            pMotion->tB.nY = nY << 11;
            pMotion->tB.nZ = nZ << 11;
        }
        else
        {
            pMotion->tB.nX = nX;
            pMotion->tB.nY = nY;
            pMotion->tB.nZ = nZ;
        }
    }
}

// 0x004DA250
void __stdcall GFXUTIL_SetMotionVectorD(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift)
{
    D2GfxMotionStrc* pMotion = GFX_GetGfxMotion(pUnit);
    if (pMotion)
    {
        if (bShift)
        {
            pMotion->tD.nX = nX << 11;
            pMotion->tD.nY = nY << 11;
            pMotion->tD.nZ = nZ << 11;
        }
        else
        {
            pMotion->tD.nX = nX;
            pMotion->tD.nY = nY;
            pMotion->tD.nZ = nZ;
        }
    }
}

// 0x004DA2A0
void __stdcall GFXUTIL_SetMotionVectorC(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift)
{
    D2GfxMotionStrc* pMotion = GFX_GetGfxMotion(pUnit);
    if (pMotion)
    {
        if (bShift)
        {
            pMotion->tC.nX = nX << 11;
            pMotion->tC.nY = nY << 11;
            pMotion->tC.nZ = nZ << 11;
        }
        else
        {
            pMotion->tC.nX = nX;
            pMotion->tC.nY = nY;
            pMotion->tC.nZ = nZ;
        }
    }
}

// 0x004DA2F0
void __stdcall GFXUTIL_SetMotionParams(D2UnitStrc* pUnit, int nParam0, int nParam1)
{
    D2GfxMotionStrc* pMotion = GFX_GetGfxMotion(pUnit);
    if (pMotion)
    {
        pMotion->dwFlags |= 4;
        pMotion->nParam0 = nParam0;
        pMotion->nParam1 = nParam1;
    }
}

// 0x004DA320
int __stdcall GFXUTIL_GetMotionFirstParam(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = GFX_GetGfxMotion(pUnit);
    if (pMotion)
    {
        return pMotion->nParam0;
    }

    return 0;
}

// 0x004DA640
void __stdcall GFXUTIL_SetMotionFlag1(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = GFX_GetGfxMotion(pUnit);
    if (pMotion)
    {
        pMotion->dwFlags |= 1;
    }
}

// 0x004DA660
int __stdcall GFXUTIL_TestMotionFlag1(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = GFX_GetGfxMotion(pUnit);
    if (pMotion && (pMotion->dwFlags & 1))
    {
        return 1;
    }

    return 0;
}

// 0x004DA690
void __stdcall GFXUTIL_ReplaceMotionFlag1With8(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = GFX_GetGfxMotion(pUnit);
    if (pMotion)
    {
        pMotion->dwFlags = pMotion->dwFlags & ~1 | 8;
    }
}

// 0x004DA6B0
int __stdcall GFXUTIL_TestMotionFlags(D2UnitStrc* pUnit)
{
    D2GfxMotionStrc* pMotion = GFX_GetGfxMotion(pUnit);
    if (pMotion && (pMotion->dwFlags & 1) && !(pMotion->dwFlags & 8))
    {
        return 0;
    }

    return 1;
}

// 0x004DA720
static void GFXUTIL_CopyCompCode(D2CompCodeStrc* pDst, const char* pSrc)
{
    if (!pSrc[0])
    {
        const char c = 0x20;
        pDst->c0 = c;
        pDst->c1 = c;
        pDst->c2 = c;
        pDst->c3 = c;
        return;
    }
    pDst->c0 = pSrc[0];
    if (!pSrc[1])
    {
        const char c = 0x20;
        pDst->c1 = c;
        pDst->c2 = c;
        pDst->c3 = c;
        return;
    }
    pDst->c1 = pSrc[1];
    if (!pSrc[2])
    {
        const char c = 0x20;
        pDst->c2 = c;
        pDst->c3 = c;
        return;
    }
    pDst->c2 = pSrc[2];
    pDst->c3 = 0x20;
}

// 0x004DA770
unsigned char __fastcall GFXUTIL_GetMonComponentIndex(D2UnitStrc* pUnit, unsigned char nComponent)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && nComponent < 16 && pUnit->pMonsterData)
        return pUnit->pMonsterData->nComponent[nComponent];
    return 0;
}

// 0x004DA790
void __cdecl GFXUTIL_InitModeTokens()
{
    memset(gaCompTokens, 0, sizeof(gaCompTokens));
    for (unsigned int i = 0; i < 16; ++i)
    {
        D2TokRecord* pRecord = DATATBLS_GetCompositTxtRecord(i);
        D2_ASSERT(pRecord, 0x36);
        gaCompTokens[i] = pRecord->dwCode;
    }

    memset(gaPlrModeTokens, 0, sizeof(gaPlrModeTokens));
    for (unsigned int i = 0; i < 20; ++i)
    {
        D2TokRecord* pRecord = DATATBLS_GetPlrModeTypeTxtRecord(i, 1);
        D2_ASSERT(pRecord, 0x3F);
        gaPlrModeTokens[i] = pRecord->dwCode;
    }

    memset(gaMonModeTokens, 0, sizeof(gaMonModeTokens));
    for (unsigned int i = 0; i < 16; ++i)
    {
        D2TokRecord* pRecord = DATATBLS_GetMonModeTxtRecord(i, 1);
        D2_ASSERT(pRecord, 0x48);
        gaMonModeTokens[i] = pRecord->dwCode;
    }

    memset(gaObjModeTokens, 0, sizeof(gaObjModeTokens));
    for (unsigned int i = 0; i < 8; ++i)
    {
        D2TokRecord* pRecord = DATATBLS_GetObjModeTypeTxtRecord(i, 1);
        D2_ASSERT(pRecord, 0x51);
        gaObjModeTokens[i] = pRecord->dwCode;
    }

    memset(gaClassTokens, 0, sizeof(gaClassTokens));
    for (unsigned int i = 0; i < 3; ++i)
    {
        D2TokRecord* pRecord = DATATBLS_GetArmTypeTxtRecord(i);
        D2_ASSERT(pRecord, 0x5A);
        gaClassTokens[i] = pRecord->dwCode;
    }
}



// 0x004DA8E0
static void __stdcall GFXUTIL_SetMissileCelName(D2UnitStrc* pUnit, D2CelContextStrc* pToken)
{
    if (!pUnit)
        return;

    const int nClassId = pUnit->dwClassId;
    D2MissilesTxt* pRecord = (nClassId >= 0 && nClassId < sgptDataTables->nMissilesTxtRecordCount) ? &sgptDataTables->pMissilesTxt[nClassId] : 0;
    if (pRecord)
        pToken->szName = pRecord->szCelFile;
}

// 0x004DA920
void __fastcall GFXUTIL_AddKeyedNode(D2KeyedNodeStrc** ppList, int nValue, int nKeyA, int nKeyB, int* pnCount, int* pnBytes)
{
    D2KeyedNodeStrc* pNode = (D2KeyedNodeStrc*)FOG_Alloc(sizeof(D2KeyedNodeStrc), ".\\ENGINE\\GfxUtil.cpp", 128, 0);
    D2_ASSERT(pNode, 129);

    *pnBytes += sizeof(D2KeyedNodeStrc);
    memset(pNode, 0, sizeof(D2KeyedNodeStrc));
    pNode->nValue = nValue;
    pNode->nKeyA = nKeyA;
    pNode->nKeyB = nKeyB;
    pNode->pNext = *ppList;
    *ppList = pNode;
    ++*pnCount;
}

// 0x004DA990
D2KeyedNodeStrc* __fastcall GFXUTIL_FindKeyedNode(D2KeyedNodeStrc* pList, int nKeyA, int nKeyB)
{
    for (D2KeyedNodeStrc* pNode = pList; pNode; pNode = pNode->pNext)
    {
        if (pNode->nKeyB == nKeyB && pNode->nKeyA == nKeyA)
        {
            return pNode;
        }
    }

    return 0;
}

// 0x004DA9C0
void __fastcall GFXUTIL_FreeNodeList(D2GfxNodeStrc** ppHead, int* pBytes)
{
    D2GfxNodeStrc* pNode = *ppHead;
    while (pNode)
    {
        D2GfxNodeStrc* pNext = pNode->pNext;
        FOG_Free(pNode, ".\\ENGINE\\GfxUtil.cpp", 0xA8, 0);
        *pBytes -= sizeof(D2GfxNodeStrc);
        pNode = pNext;
    }
    *ppHead = 0;
}

// 0x004DAA00
int __fastcall GFXUTIL_GetModeArg(D2UnitStrc* pUnit, int nType, int nClass)
{
    switch (nType)
    {
    case 2:
    {
        D2TokRecord* pRecord = DATATBLS_GetObjModeTypeTxtRecord(nClass, 0);
        if (!pRecord)
        {
            return 0;
        }
        return pRecord->dwCode;
    }
    case 1:
    {
        D2MonStatsTxt* pMonStatsTxtRecord = GFXUTIL_GetMonStatsTxtRecord(nClass);
        if (!pMonStatsTxtRecord)
        {
            return 0;
        }
        return pMonStatsTxtRecord->dwCode;
    }
    case 0:
    {
        D2TokRecord* pRecord = DATATBLS_GetPlrModeTypeTxtRecord(nClass, 0);
        if (!pRecord)
        {
            return 0;
        }
        return pRecord->dwCode;
    }
    default:
        return 0;
    }
}

// 0x004DAA70
void __fastcall GFXUTIL_ConvertItemMode(D2UnitStrc* pUnit, int* pMode)
{
    switch (*pMode)
    {
    case 0:
    case 1:
    case 2:
    case 4:
    case 6:
        *pMode = 4;
        break;

    case 3:
    case 5:
        *pMode = 3;
        break;
    }
}

// 0x004DAB40
int __fastcall GFXUTIL_IsCelOnScreen(D2CelStrc* pCel, int nX, int nY, int bFlag)
{
    int nHeight = CelGetHeight(pCel);
    int nBottom = CelGetOffsetY(pCel) + nY;
    int nLeft = CelGetOffsetX(pCel) + nX;
    int nWidth = CelGetWidth(pCel);
    if (bFlag)
    {
        nLeft -= nHeight;
        nWidth += nHeight;
    }

    if (nLeft > gnScreenWidth)
    {
        return 0;
    }

    if (nLeft + nWidth < 0)
    {
        return 0;
    }

    if (nBottom - nHeight > gnScreenHeight)
    {
        return 0;
    }

    return nBottom + nHeight >= 0;
}

// 0x004DABC0
static void GFXUTIL_SetItemCelName(D2UnitStrc* pUnit, D2CelContextStrc* pToken)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(sub_0046DAC0_GetItemClassId(pUnit));
    if (!pItemsTxtRecord)
        return;

    if (pToken->nMode == 4)
    {
        const unsigned char nInvGfx = sub_006283F0_GetInvGfxIndex(pUnit);
        if (ITEMS_CheckItemFlag(pUnit, 0x10, 0x196, ".\\ENGINE\\GfxUtil.cpp") && ITEMS_GetItemQuality(pUnit) == ITEMQUAL_SET)
        {
            D2SetItemsTxt* pSet = DATATBLS_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pUnit));
            if (pSet && pSet->szInvFile[0])
            {
                pToken->nFlags |= 0x10;
                pToken->szName = pSet->szInvFile;
                return;
            }

            if (pItemsTxtRecord->szSetInvFile[0])
            {
                pToken->nFlags |= 0x10;
                pToken->szName = pItemsTxtRecord->szSetInvFile;
                return;
            }
        }

        if (ITEMS_CheckItemFlag(pUnit, 0x10, 0x1AE, ".\\ENGINE\\GfxUtil.cpp") && ITEMS_GetItemQuality(pUnit) == ITEMQUAL_UNIQUE)
        {
            const int nIndex = ITEMS_GetFileIndex(pUnit);
            if (nIndex > 0)
            {
                D2UniqueItemsTxt* pUnique = DATATBLS_GetUniqueItemsTxtRecord(nIndex);
                if (pUnique && pUnique->szInvFile[0])
                {
                    pToken->nFlags |= 1;
                    pToken->szName = pUnique->szInvFile;
                    return;
                }
            }

            if (pItemsTxtRecord->szUniqueInvFile[0])
            {
                pToken->nFlags |= 1;
                pToken->szName = pItemsTxtRecord->szUniqueInvFile;
                return;
            }
        }

        if (sub_0062E8D0_HasAltInvGfx(pUnit))
        {
            pToken->szName = sub_0062E920_GetAltInvGfxName(pUnit, nInvGfx);
            return;
        }

        pToken->szName = pItemsTxtRecord->szInvFile;
        return;
    }

    if (pToken->nMode == 3)
    {
        pToken->szName = pItemsTxtRecord->szFlippyFile;
        if (ITEMS_GetItemQuality(pUnit) == ITEMQUAL_UNIQUE)
        {
            if (ITEMS_GetFileIndex(pUnit) >= 0)
            {
                D2UniqueItemsTxt* pUnique = DATATBLS_GetUniqueItemsTxtRecord(ITEMS_GetFileIndex(pUnit));
                if (pUnique && pUnique->szFlippyFile[0])
                    pToken->szName = pUnique->szFlippyFile;
            }
        }
        else if (ITEMS_GetItemQuality(pUnit) == ITEMQUAL_SET)
        {
            D2SetItemsTxt* pSet = DATATBLS_GetSetItemsTxtRecord(ITEMS_GetFileIndex(pUnit));
            if (pSet && pSet->szFlippyFile[0])
                pToken->szName = pSet->szFlippyFile;
        }
    }
}

// 0x004DAD20
void __fastcall GFXUTIL_SetOverlayCelName(D2UnitStrc* pUnit, D2CelContextStrc* pToken)
{
    const int nOverlay = pToken->nOverlay;
    D2OverlayTxt* pRecord = (nOverlay >= 0 && nOverlay < sgptDataTables->nOverlayTxtRecordCount) ? &sgptDataTables->pOverlayTxt[nOverlay] : 0;
    if (pRecord)
        pToken->szName = pRecord->szFilename;
}


// 0x004DAD50
static int GFXUTIL_GetOverlayDirections(int nOverlay)
{
    D2OverlayTxt* pOverlayTxt = DATATBLS_GetOverlayTxtRecordInline(nOverlay);
    if (!pOverlayTxt)
    {
        return 1;
    }

    return pOverlayTxt->nNumDirections;
}

// 0x004DAD80
static unsigned int GFXUTIL_GetWeaponClassToken(D2UnitStrc* pUnit, int nComponent)
{
    if (nComponent >= 0x10)
        return 0x2074696C;

    D2InventoryStrc* pInventory;
    D2UnitStrc* pOwner;
    if (STATES_IsUnitShapeShiftedInline(pUnit) && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && (pOwner = CUNIT_GetOwnerUnit(pUnit)) != 0)
        pInventory = pOwner->pInventory;
    else
        pInventory = pUnit->pInventory;

    int nWeaponClassId;
    const int nWeaponClass = COMPOSIT_GetWeaponClassId(pUnit, pInventory, &nWeaponClassId, -1, 1);
    if (nWeaponClass == 0x20776278)
    {
        if (nComponent == 5 || nComponent == 6)
        {
            D2UnitStrc* pItem = INVENTORY_GetCompositItem(pInventory, 5);
            if (!pItem)
                return 0x2074696C;
            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(UNITS_GetClassIdInline(pItem));
            if (!pItemsTxtRecord)
                return 0x2074696C;
            if (pItemsTxtRecord->dwAltCode2)
                return pItemsTxtRecord->dwAltCode2;
            return pItemsTxtRecord->dwCode;
        }
    }
    else if (nWeaponClass == 0x20776F62 && nComponent == 5)
    {
        return 0x2074696C;
    }

    if (nComponent == 7 && STATES_CheckState(pUnit, STATE_HOLYSHIELD) && INVENTORY_GetEquippedShield(pInventory, 0))
        return 0x20687368;

    return 0;
}

#include "gen/data/Source/D2Client/ENGINE/GfxUtil.inc"
