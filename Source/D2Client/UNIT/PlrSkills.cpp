#include "D2SkillIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameTypes.h"
#include "D2Txt.h"
#include "D2LevelTxt.h"
#include "D2PlayerModes.h"
#include "D2MonModes.h"
#include "D2Path.h"
#include "D2UnitEventArgs.h"

#define UNIT_PLAYER 0
#define UNIT_MONSTER 1
#define UNIT_INVALID 6
#define STAT_MODIFIERLIST_SKILL 350
#define COLLISION_PATTERN_SMALL_UNIT_PRESENCE 1
#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))
#define STAT_UNIT_MODE 172
#define ITEMSTATCOSTFLAGINDEX_UPDATEANIMRATE 9

struct D2StaticPathStrc;
struct D2SkillsTxt;
union D2SeedStrc;
struct D2StatesTxt;
struct D2MissilesTxt;
struct D2MonStats2Txt;
struct D2MissileStrc;
struct D2UnitStrc;
struct D2DataTablesStrc;
struct D2ItemStatCostTxt;





extern D2DataTablesStrc* sgptDataTables; // 0x00744304
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill); // 0x006446A0
void __fastcall SKILLSBAR_RotateUnitDirection(D2UnitStrc* pUnit, int nArg, int bForward); // 0x004C9060


extern unsigned int gdwBitMasks_006CE268[]; // 0x006CE268
void __fastcall GFX_ResetGfx(D2UnitStrc* pUnit); // 0x0046F000
void __fastcall AUTOMAP_RemoveUnitOverlay(D2UnitStrc* pUnit, int nArg, int nValue); // 0x0046F0C0
void __fastcall GFX_AddUnitOverlay(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
void __fastcall GFX_RefreshUnitGfx(D2UnitStrc* pUnit, int nArg); // 0x00470610
void __fastcall UNITMODE_SetUnitMode(D2UnitStrc* pUnit, int nMode); // 0x00480E70
int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00
void __stdcall PLRSKILLS_UpdateStateColor(D2UnitStrc* pUnit); // 0x004D97F0
void __fastcall PLRSKILLS_StartStateOverlays(D2UnitStrc* pUnit, int nState); // 0x004D9920
unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0
void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill); // 0x00620210
int __stdcall UNITS_SetAnimStartFrame(D2UnitStrc* ptUnit); // 0x00624390
int __stdcall STATLIST_GetState(D2StatListStrc* pStatList); // 0x006252F0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00
void __stdcall STATLIST_SetStat(D2StatListStrc* pStatList, int nStatId, int nValue, unsigned short nLayer); // 0x00627150
void __stdcall STATLIST_RemoveAllStats(D2StatListStrc* pStatList); // 0x00627340
void __stdcall D2Common_10474(D2UnitStrc* pUnit, D2StatListStrc* pStatList); // 0x006277E0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
unsigned int __stdcall DATATBLS_Get1OfNFromOverlayTxt(int nOverlayId); // 0x00664740
void __stdcall UNITS_StoreOwnerTypeAndGUID(D2UnitStrc* pUnit, int nOwnerType, int nOwnerId); // 0x00621CC0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0
void __fastcall VIEW_StartTimedBox(int nFadeIn, int nHold, int nFadeOut, int nLevelId, int bForce); // 0x0046AE50
int __fastcall SPELLSEL_GetSkillMaxLevel(int nSkillId); // 0x004AA8B0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280
int __stdcall sub_K06_EmitGettier1(int nValue);
void __stdcall sub_K06_EmitPuttier1(int nValue, int nOther);
int __stdcall sub_K06_EmitGettier2(int nValue);
void __stdcall sub_K06_EmitPuttier2(int nValue, int nOther);
void __fastcall sub_004BA790_ReleaseUnitSfx(void* pUnitSfx, D2UnitStrc* pUnit, int bForce); // 0x004BA790
void* __fastcall UNITSND_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId); // 0x004CA900
void __stdcall PARTICLE_ResetGfxMotion(D2UnitStrc* pUnit); // 0x004DA000
void __stdcall GFXUTIL_SetMotionVectorA(D2UnitStrc* pUnit, int nX, int nY, int nZ); // 0x004DA1D0
int __stdcall STATES_CheckStateMaskAuraByStateId(int nState); // 0x0063A210
void __stdcall SKILLS_SetParam2(D2SkillStrc* pSkill, int nValue); // 0x006445A0
void __stdcall SKILLS_SetParam3(D2SkillStrc* pSkill, int nValue); // 0x006445E0
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740
void __fastcall NPCMENU_StateRequests(D2UnitStrc* pUnit); // 0x004ADCE0
void __fastcall GAME_SetSkillDelayUntil(int nValue); // 0x0044CE40



typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArg);


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern const unsigned char gabFrameDirections[8][9]; // 0x006DBA08
extern const unsigned char gabBaseDirections[8]; // 0x006DBA50
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2MonStats2Txt* __fastcall UNITS_GetMonStats2TxtRecordFromMonsterId(int nMonsterId); // 0x00451FE0
int __fastcall MONSTERREGION_CheckMonStats2Flag(int nMonsterId, int nFlag); // 0x004638A0
D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0
void __fastcall sub_00472C50(int nArg); // 0x00472C50
int __fastcall ITEM_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY); // 0x004C52E0
D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540
D2UnitStrc* __fastcall MISSILE_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0
void __stdcall GFXUTIL_SetMotionVectorB(D2UnitStrc* pUnit, int nX, int nY, int nZ, int bShift); // 0x004DA200
int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500
D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820
void __stdcall STATLIST_ExpireUnitStatlist(D2UnitStrc* pUnused, D2UnitStrc* pUnit); // 0x006277F0
void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0
unsigned char __stdcall INVENTORY_GetEightWayDirection(unsigned char nIndex); // 0x0063E7A0
int __stdcall MONSTERS_GetSpawnMode_XY(D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4, int* pMode, int* pX, int* pY); // 0x0063EA70
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10
void __stdcall D2Common_10216(D2DynamicPathStrc* pPath, int nX, int nY, int bSetBothDirections); // 0x00649EF0
void __stdcall MISSILE_SetTargetX(D2UnitStrc* pMissile, int nTargetX); // 0x0064A710


void __fastcall SCMD_HandleMonsterModeChange(D2UnitStrc* pUnit, unsigned char nOldMode, unsigned char nNewMode); // 0x00463C00
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10

int __fastcall SKILLS_CallClientStateEvent(void* pArg1, int nArg2, int nArg3, int nArg4, unsigned int nIndex, int nArg6, int nArg7); // 0x004C7C40

extern unsigned int gdwBitMasks[]; // 0x006CE268

typedef void (__fastcall* CLIENTSTATEFN)(D2UnitStrc* pUnit, int nState);

extern CLIENTSTATEFN gpfnClientStateSetFuncs[]; // 0x0072A690

void __fastcall CUNITEVENT_RemoveCltUnitEvents(D2UnitStrc* pUnit, int nParam4, int nParam5); // 0x004DC190

extern CLIENTSTATEFN gpfnClientStateRemFuncs[]; // 0x0072A710

typedef char check_pointer_width[sizeof(void*)==4?1:-1];

typedef char check_scalar_width[sizeof(unsigned int)==4?1:-1];

extern "C" int __stdcall SKILLS_GetUseState(D2UnitStrc* unit,D2SkillStrc* skill); // 0x00647960

D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0

int __cdecl sub_0044DA90(); // 0x0044DA90

int __cdecl GAME_GetSkillDelayUntil(); // 0x0044CE50

void __fastcall SCMD_SetLightColorBytes(D2GfxLightStrc* pLight, unsigned char nValue0, unsigned char nValue1, unsigned char nValue2); // 0x00474390

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900
void __stdcall D2COMMON_10160_PathUpdateDirection(D2DynamicPathStrc* pDynamicPath, unsigned char nDirection); // 0x00648820


int __fastcall sub_00480C10_DispatchUnitEvent(int nEvent, D2UnitStrc* pUnit, D2UnitEventArgsStrc* pArgs, int nArg); // 0x00480C10

// 0x004D84C0
static int PLRSKILLS_IsInSequenceMode(D2UnitStrc* pUnit)
{
    int nUnitType = UNIT_INVALID;
    if (pUnit)
        nUnitType = pUnit->dwUnitType;
    switch (nUnitType)
    {
    case UNIT_MONSTER:
        return (!pUnit ? 0 : pUnit->dwAnimMode) == MONMODE_SEQUENCE;
    case UNIT_PLAYER:
        return (!pUnit ? 0 : pUnit->dwAnimMode) == PLRMODE_SEQUENCE;
    }
    return 0;
}

// 0x004D8520
void __fastcall PLRSKILLS_SkillSeqDoForward(D2UnitStrc* pUnit, int nArg)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
        return;

    if (!PLRSKILLS_IsInSequenceMode(pUnit))
        return;

    const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\UNIT\\PlrSkills.cpp", 38);
    D2SkillsTxt* pSkillsTxtRecord = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
    if (!pSkillsTxtRecord)
        return;

    switch (pSkillsTxtRecord->wSrvDoFunc)
    {
    case 0x4C:
        SKILLSBAR_RotateUnitDirection(pUnit, nArg, 1);
        break;
    case 0x43:
        if (SKILLS_GetFlags(pSkill) & 1)
// build: symbol ?SKILLSPAL_DrawMotionTrail@* 0x004C9990
            SKILLSPAL_DrawMotionTrail(pUnit, nArg, 1);
        break;
    }
}

// 0x004D85B0
void __fastcall PLRSKILLS_CallSkillSeqDoForward(D2UnitStrc* pUnit, int nArg)
{
    PLRSKILLS_SkillSeqDoForward(pUnit, nArg);
}

// 0x004D85C0
void __fastcall PLRSKILLS_SkillSeqDoBackward(D2UnitStrc* pUnit, int nArg)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
        return;

    if (!PLRSKILLS_IsInSequenceMode(pUnit))
        return;

    const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\UNIT\\PlrSkills.cpp", 79);
    D2SkillsTxt* pSkillsTxtRecord = (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount) ? &sgptDataTables->pSkillsTxt[nSkillId] : 0;
    if (!pSkillsTxtRecord)
        return;

    switch (pSkillsTxtRecord->wSrvDoFunc)
    {
    case 0x4C:
        SKILLSBAR_RotateUnitDirection(pUnit, nArg, 0);
        break;
    case 0x43:
        if (SKILLS_GetFlags(pSkill) & 1)
            SKILLSPAL_DrawMotionTrail(pUnit, nArg, 0);
        break;
    }
}

static inline D2StatesTxt* GetStatesTxtRecord(int nState)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nState];
    }
    return 0;
}

static inline int GetOverlay(short nOverlay)
{
    return nOverlay >= 0 ? nOverlay : -1;
}

static inline int GetThirdsTier(int nValue, int nTotal)
{
    const int nThird = nTotal / 3;
    const int nTwoThirds = 2 * nThird;
    int nTier = 3;
    if (nValue < nThird)
        nTier = 2;
    if (nValue < nTwoThirds)
        nTier -= 1;
    return nTier;
}

// 0x004D8660
static void __stdcall PLRSKILLS_OverlayVariants(D2UnitStrc* pUnit, int nOverlay)
{
    if (nOverlay == -1)
        return;

    const int nCount = DATATBLS_Get1OfNFromOverlayTxt(nOverlay);
    for (int i = 0; i < nCount; ++i)
    {
        AUTOMAP_RemoveUnitOverlay(pUnit, 0, nOverlay + i);
    }
}

// 0x004D88A0
void __fastcall PLRSKILLS_StateSkillLevel(D2UnitStrc* pUnit, int nState)
{
    int nLevel;
    D2StatListStrc* pStatList;
    int nSkillId;

    if (pUnit == sub_00463DD0_GetPlayerUnit())
    {
        return;
    }

    pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (!pStatList)
    {
        return;
    }

    nSkillId = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
    nLevel = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_LEVEL, 0);
    D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, nSkillId, -1);
    int nCurrent = pSkill ? SKILLS_GetSkillLevel(pUnit, pSkill, 1) : 0;
    if (nCurrent == nLevel)
    {
        return;
    }

    int nMax = SPELLSEL_GetSkillMaxLevel(nSkillId);
    if (nLevel > nMax)
    {
        SKILLS_AssignSkill(pUnit, nSkillId, nMax, 0, ".\\UNIT\\PlrSkills.cpp", 0x11B);
        sub_00647AA0_SetSkillBonusLevel(pUnit, nSkillId, nLevel - nMax);
    }
    else
    {
        SKILLS_AssignSkill(pUnit, nSkillId, nLevel, 0, ".\\UNIT\\PlrSkills.cpp", 0x120);
    }
}

// 0x004D8960
void __fastcall PLRSKILLS_StateStoreOwner(D2UnitStrc* pUnit, int nState)
{
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (pStatList)
    {
        unsigned int nOwnerType = STATLIST_GetStatValue(pStatList, STAT_SOURCE_UNIT_TYPE, 0);
        if (nOwnerType < 6)
        {
            UNITS_StoreOwnerTypeAndGUID(pUnit, nOwnerType, STATLIST_GetStatValue(pStatList, STAT_SOURCE_UNIT_ID, 0));
        }
    }
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x004D89A0
void __fastcall PLRSKILLS_StateClearOwner(D2UnitStrc* pUnit, int nState)
{
    UNITS_StoreOwner(pUnit, 0);
}

// 0x004D89B0
void __fastcall PLRSKILLS_ApplyStateMonster(D2UnitStrc* pUnit, int nState)
{
    const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nUnitType != 1)
    {
        return;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (!pStatList)
    {
        return;
    }

    const int nValue = STATLIST_GetStatValue(pStatList, STAT_SHORTPARAM1, 0);
    const int nMode = pUnit->dwAnimMode;
    sub_004AEDD0(pUnit, nValue);
    if (nMode == 8)
    {
        UNITMODE_SetUnitMode(pUnit, 8);
    }
    else
    {
        UNITMODE_SetUnitMode(pUnit, 1);
    }

    if (nValue == 0x21F)
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        D2Common_10216(pPath, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit) + 10, 1);
    }
}

// 0x004D8A30
static int __stdcall sub_004D8A30_GetThirdsTier(int nValue, int nTotal)
{
    const int nThird = nTotal / 3;
    const int nTwoThirds = 2 * nThird;
    int nTier = 3;
    if (nValue < nThird)
        nTier = 2;
    if (nValue < nTwoThirds)
        nTier -= 1;
    return nTier;
}

// 0x004D8A60
void __fastcall PLRSKILLS_StateOverlays(D2UnitStrc* pUnit, int nState)
{
    D2StatesTxt* pTxt = GetStatesTxtRecord(nState);
    if (!pTxt)
        return;

    const int nCast = GetOverlay((short)pTxt->wCastOverlay);
    const int nOverlay1 = GetOverlay(pTxt->wOverlay[0]);
    const int nOverlay2 = GetOverlay(pTxt->wOverlay[1]);
    const int nOverlay3 = GetOverlay(pTxt->wOverlay[2]);
    const int nOverlay4 = GetOverlay(pTxt->wOverlay[3]);
    if (nCast != -1)
    {
        PLRSKILLS_OverlayVariants(pUnit, nCast);
        PLRSKILLS_OverlayVariants(pUnit, nCast);
        PLRSKILLS_OverlayVariants(pUnit, nCast);
    }
    if (nOverlay1 != -1)
    {
        PLRSKILLS_OverlayVariants(pUnit, nOverlay1);
        PLRSKILLS_OverlayVariants(pUnit, nOverlay1);
        PLRSKILLS_OverlayVariants(pUnit, nOverlay1);
    }
    if (nOverlay2 != -1)
    {
        PLRSKILLS_OverlayVariants(pUnit, nOverlay2);
        PLRSKILLS_OverlayVariants(pUnit, nOverlay2);
        PLRSKILLS_OverlayVariants(pUnit, nOverlay2);
    }
    if (nOverlay3 != -1)
    {
        PLRSKILLS_OverlayVariants(pUnit, nOverlay3);
    }
    if (nOverlay4 != -1)
    {
        PLRSKILLS_OverlayVariants(pUnit, nOverlay4);
    }
}

// 0x004D8B90
void __fastcall PLRSKILLS_StateTieredOverlays(D2UnitStrc* pUnit, int nState)
{
    D2StatesTxt* pTxt = GetStatesTxtRecord(nState);
    if (!pTxt)
        return;

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (!pStatList)
        return;

    const int nValue = STATLIST_GetStatValue(pStatList, STAT_BONEARMOR, 0);
    const int nTotal = STATLIST_GetStatValue(pStatList, STAT_BONEARMORMAX, 0);
    const int nCast = GetOverlay((short)pTxt->wCastOverlay);
    const int nOverlay1 = GetOverlay(pTxt->wOverlay[0]);
    const int nOverlay2 = GetOverlay(pTxt->wOverlay[1]);
    const int nOverlay3 = GetOverlay(pTxt->wOverlay[2]);
    const int nOverlay4 = GetOverlay(pTxt->wOverlay[3]);
    const int nOldTier = STATLIST_GetStatValue(pStatList, STAT_SHORTPARAM1, 0);
    const int nTier = GetThirdsTier(nValue, nTotal);
    STATLIST_SetStat(pStatList, STAT_SHORTPARAM1, nTier, 0);
    if (nTier > nOldTier)
    {
        PLRSKILLS_StateOverlays(pUnit, nState);
        if (nOverlay3 != -1 && nTier >= 3)
        {
            GFX_AddUnitOverlay(pUnit, nOverlay3, 7, 0, 0, 0, 0, 0);
        }
        if (nOverlay4 != -1 && nTier >= 2)
        {
            GFX_AddUnitOverlay(pUnit, nOverlay4, 7, 0, 0, 0, 0, 0);
        }
        if (nCast != -1 && nOverlay1 != -1 && nOverlay2 != -1)
        {
            GFX_AddUnitOverlay(pUnit, nCast, 4, 0, nOverlay1, nOverlay2, 0, 0);
        }
    }
    else if (nTier < nOldTier)
    {
        for (int i = nTier; i < nOldTier; ++i)
        {
            PLRSKILLS_OverlayVariants(pUnit, nOverlay1);
            PLRSKILLS_OverlayVariants(pUnit, nOverlay2);
        }
    }
}

// 0x004D86A0
void __fastcall PLRSKILLS_StatePrgOverlayLevel(D2UnitStrc* pUnit, int nState)
{
    if (nState < 0 || nState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return;
    }

    D2StatesTxt* pStatesTxt = &sgptDataTables->pStatesTxt[nState];
    if (!pStatesTxt || !(pStatesTxt->nStateFlags[0] & gdwBitMasks_006CE268[4]))
    {
        return;
    }

    if (pStatesTxt->wPrgOverlay <= 0 || pStatesTxt->wPrgOverlay >= sgptDataTables->nOverlayTxtRecordCount
        || pStatesTxt->wStat < 0 || pStatesTxt->wStat > sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return;
    }

    for (int i = 0; i < 3; ++i)
    {
        AUTOMAP_RemoveUnitOverlay(pUnit, 0, pStatesTxt->wPrgOverlay + i);
    }

    const int nLevel = STATLIST_UnitGetStatValue(pUnit, pStatesTxt->wStat, 0);
    if (nLevel >= 1 && nLevel <= 3)
    {
        GFX_AddUnitOverlay(pUnit, pStatesTxt->wPrgOverlay + nLevel - 1, 3, 0, 0, 0, 0, 0);
    }
}

// 0x004D8760
void __fastcall PLRSKILLS_StatePrgOverlays(D2UnitStrc* pUnit, int nState)
{
    if (nState < 0 || nState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return;
    }

    D2StatesTxt* pStatesTxt = &sgptDataTables->pStatesTxt[nState];
    if (!pStatesTxt || !(pStatesTxt->nStateFlags[0] & gdwBitMasks_006CE268[4]))
    {
        return;
    }

    if (pStatesTxt->wPrgOverlay <= 0 || pStatesTxt->wPrgOverlay >= sgptDataTables->nOverlayTxtRecordCount
        || pStatesTxt->wStat < 0 || pStatesTxt->wStat > sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return;
    }

    for (int i = 0; i < 3; ++i)
    {
        AUTOMAP_RemoveUnitOverlay(pUnit, 0, pStatesTxt->wPrgOverlay + i);
    }
}

// 0x004D87E0
void __fastcall PLRSKILLS_StateAuraEffect(D2UnitStrc* pUnit, int nState)
{
    int nLevel;
    D2StatListStrc* pStatList;
    int nSkillId;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (!pStatList)
    {
        return;
    }

    nSkillId = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
    nLevel = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_LEVEL, 0);
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    int nValue = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraLenCalc, nSkillId, nLevel);
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    VIEW_StartTimedBox(5, nValue * 3 / 5, nValue * 2 / 5, nLevelId, 0);
}

void __stdcall sub_K06_Emittier1(int a, int b)
{
    const int v = sub_K06_EmitGettier1(a);
    const int t = sub_K06_EmitGettier1(b);
    sub_K06_EmitPuttier1(sub_004D8A30_GetThirdsTier(v, t), v);
}

// 0x004D8D60
static int __stdcall sub_004D8D60_GetThirdsTier(int nValue, int nTotal)
{
    const int nThird = nTotal / 3;
    const int nTwoThirds = 2 * nThird;
    int nTier = 3;
    if (nValue < nThird)
        nTier = 2;
    if (nValue < nTwoThirds)
        nTier -= 1;
    return nTier;
}

// 0x004D8D90
void __fastcall PLRSKILLS_StateOverlayPairs(D2UnitStrc* pUnit, int nState)
{
    D2StatesTxt* pTxt = GetStatesTxtRecord(nState);
    if (!pTxt)
        return;

    const int nOverlay1 = GetOverlay(pTxt->wOverlay[0]);
    const int nOverlay2 = GetOverlay(pTxt->wOverlay[1]);
    const int nOverlay3 = GetOverlay(pTxt->wOverlay[2]);
    if (nOverlay1 != -1)
    {
        PLRSKILLS_OverlayVariants(pUnit, nOverlay1);
        PLRSKILLS_OverlayVariants(pUnit, nOverlay1 + 1);
    }
    if (nOverlay2 != -1)
    {
        PLRSKILLS_OverlayVariants(pUnit, nOverlay2);
        PLRSKILLS_OverlayVariants(pUnit, nOverlay2 + 1);
    }
    if (nOverlay3 != -1)
    {
        PLRSKILLS_OverlayVariants(pUnit, nOverlay3);
        PLRSKILLS_OverlayVariants(pUnit, nOverlay3 + 1);
    }
}

// 0x004D8E60
void __fastcall PLRSKILLS_StateTieredOverlayPairs(D2UnitStrc* pUnit, int nState)
{
    D2StatesTxt* pTxt = GetStatesTxtRecord(nState);
    if (!pTxt)
        return;

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (!pStatList)
        return;

    const int nValue = STATLIST_GetStatValue(pStatList, STAT_BONEARMOR, 0);
    const int nTotal = STATLIST_GetStatValue(pStatList, STAT_BONEARMORMAX, 0);
    const int nOverlay1 = GetOverlay(pTxt->wOverlay[0]);
    const int nOverlay2 = GetOverlay(pTxt->wOverlay[1]);
    const int nOverlay3 = GetOverlay(pTxt->wOverlay[2]);
    const int nOldTier = STATLIST_GetStatValue(pStatList, STAT_SHORTPARAM1, 0);
    const int nTier = GetThirdsTier(nValue, nTotal);
    STATLIST_SetStat(pStatList, STAT_SHORTPARAM1, nTier, 0);
    if (nTier > nOldTier)
    {
        PLRSKILLS_StateOverlayPairs(pUnit, nState);
        if (nOverlay3 != -1 && nTier >= 3)
        {
            GFX_AddUnitOverlay(pUnit, nOverlay3, 3, 0, 0, 0, 0, 0);
            GFX_AddUnitOverlay(pUnit, nOverlay3 + 1, 3, 0, 0, 0, 0, 0);
        }
        if (nOverlay2 != -1 && nTier >= 2)
        {
            GFX_AddUnitOverlay(pUnit, nOverlay2, 3, 0, 0, 0, 0, 0);
            GFX_AddUnitOverlay(pUnit, nOverlay2 + 1, 3, 0, 0, 0, 0, 0);
        }
        if (nOverlay1 != -1 && nTier >= 1)
        {
            GFX_AddUnitOverlay(pUnit, nOverlay1, 3, 0, 0, 0, 0, 0);
            GFX_AddUnitOverlay(pUnit, nOverlay1 + 1, 3, 0, 0, 0, 0, 0);
        }
    }
    else
    {
        if (nOverlay3 && nTier <= 2)
        {
            PLRSKILLS_OverlayVariants(pUnit, nOverlay3);
            PLRSKILLS_OverlayVariants(pUnit, nOverlay3 + 1);
        }
        if (nOverlay2 && nTier <= 1)
        {
            PLRSKILLS_OverlayVariants(pUnit, nOverlay2);
            PLRSKILLS_OverlayVariants(pUnit, nOverlay2 + 1);
        }
        if (nOverlay1 && nOverlay1 <= 1)
        {
            PLRSKILLS_OverlayVariants(pUnit, nOverlay1);
            PLRSKILLS_OverlayVariants(pUnit, nOverlay1 + 1);
        }
    }
}

void __stdcall sub_K06_Emittier2(int a, int b)
{
    const int v = sub_K06_EmitGettier2(a);
    const int t = sub_K06_EmitGettier2(b);
    sub_K06_EmitPuttier2(sub_004D8D60_GetThirdsTier(v, t), v);
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecordStd(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

inline D2StatesTxt* DATATBLS_GetStatesTxtRecordInline(int nStateId)
{
    if (nStateId >= 0 && nStateId < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nStateId];
    }

    return 0;
}

// 0x004D9090
void __fastcall PLRSKILLS_StatePlaySkillSound(D2UnitStrc* pUnit, int nState)
{
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (!pStatList)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecordStd(STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0));
    if (pSkillsTxtRecord && pSkillsTxtRecord->wPrgSound > 0)
    {
        sub_004B9A00(pSkillsTxtRecord->wPrgSound, pUnit, 0, 0, 0);
    }
}

// 0x004D90F0
void __fastcall PLRSKILLS_StateStopSkillSound(D2UnitStrc* pUnit, int nState)
{
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (!pStatList)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecordStd(STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0));
    if (pSkillsTxtRecord && pSkillsTxtRecord->wPrgSound > 0)
    {
        void* pUnitSfx = UNITSND_FindUnitSfxInRange(pUnit, pSkillsTxtRecord->wPrgSound);
        if (pUnitSfx)
        {
            sub_004BA790_ReleaseUnitSfx(pUnitSfx, pUnit, 1);
        }
    }
}

// 0x004D9260
void __fastcall PLRSKILLS_StateClearCollision(D2UnitStrc* pUnit, int nState)
{
    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_MONSTER)
    {
        return;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill || SKILLS_GetSkillIdFromSkill(pSkill, ".\\UNIT\\PlrSkills.cpp", 759) != SKILL_NEST)
    {
        return;
    }

    int nX = SKILLS_GetParam2(pSkill);
    int nY = SKILLS_GetParam3(pSkill);
    if (!nX && !nY)
    {
        return;
    }

    SKILLS_SetParam2(pSkill, 0);
    SKILLS_SetParam3(pSkill, 0);
    if (sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY))
    {
        D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY);
        COLLISION_ResetMaskWithPattern(pRoom, nX, nY, COLLISION_PATTERN_SMALL_UNIT_PRESENCE, 0x100);
    }
}

// 0x004D9310
void __fastcall PLRSKILLS_StateSetFlagEx(D2UnitStrc* pUnit, int nState)
{
    if (pUnit)
    {
        pUnit->dwFlagEx |= 0x40000;
    }
}

// 0x004D9320
void __fastcall PLRSKILLS_StateSetFlags(D2UnitStrc* pUnit, int nState)
{
    if (pUnit)
    {
        pUnit->dwFlagEx |= 0x40000;
        pUnit->dwFlags |= 0x20;
    }
}

// 0x004D9340
void __fastcall PLRSKILLS_StateClearFlags(D2UnitStrc* pUnit, int nState)
{
    if (pUnit)
    {
        pUnit->dwFlagEx &= ~0x40000;
        pUnit->dwFlags &= ~0x20;
    }
}

// 0x004D9360
void __fastcall PLRSKILLS_StateResetGfxMotion(D2UnitStrc* pUnit, int nState)
{
    PARTICLE_ResetGfxMotion(pUnit);
    sub_004DA620(pUnit, 1);
}

// 0x004D9380
void __fastcall PLRSKILLS_StateClearMotion(D2UnitStrc* pUnit, int nState)
{
    sub_004DA620(pUnit, 0);
    GFXUTIL_SetMotionVectorA(pUnit, 0, 0, 0);
}

// 0x004D93A0
void __fastcall PLRSKILLS_StateEndRequests(D2UnitStrc* pUnit, int nState)
{
    NPCMENU_StateRequests(pUnit);
}

// 0x004D9450
void __fastcall PLRSKILLS_StateSetMode(D2UnitStrc* pUnit, int nState)
{
    UNITMODE_SetUnitMode(pUnit, 1);
    if (pUnit)
    {
        pUnit->dwFlags |= 0x80000000;
    }
    D2Common_10214(pUnit);
}

inline D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x004D9480
void __fastcall PLRSKILLS_StateOverlaySpread(D2UnitStrc* pUnit, int nState)
{
    D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecordInline(nState);
    if (!pStatesTxtRecord)
    {
        return;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (!pStatList)
    {
        return;
    }

    int nSelect = STATLIST_GetStatValue(pStatList, STAT_SKILL_FRENZY, 0);
    int nSkillId = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
    int nSkillLevel = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_LEVEL, 0);
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    int nCount = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[1], nSkillId, nSkillLevel);
    if (nCount <= 0)
    {
        return;
    }

    int nEnd = pStatesTxtRecord->wOverlay[1];
    int nStart = pStatesTxtRecord->wOverlay[0];
    nCount = D2_MIN(nCount, nEnd - nStart + 1);
    nSelect = D2_MIN(nSelect, nEnd - nStart + 1);
    if (nStart >= 0 && nEnd >= nStart)
    {
        int nIndex = (nSelect - 1) * (nEnd - nStart + 1) / nCount;
        for (int i = 0; i < nEnd - nStart + 1; ++i)
        {
            if (i != nIndex)
            {
                AUTOMAP_RemoveUnitOverlay(pUnit, 0, nStart + i);
            }
            else if (!sub_0046E100(pUnit, nStart + i))
            {
                GFX_AddUnitOverlay(pUnit, nStart + i, 3, 0, 0, 0, 0, 0);
            }
        }
    }

    nStart = pStatesTxtRecord->wOverlay[2];
    nEnd = pStatesTxtRecord->wOverlay[3];
    if (nStart >= 0 && nEnd >= nStart)
    {
        int nRange = nEnd - nStart + 1;
        int nIndex = (nSelect - 1) * nRange / nCount;
        for (int i = 0; i < nRange; ++i, ++nStart)
        {
            if (i != nIndex)
            {
                AUTOMAP_RemoveUnitOverlay(pUnit, 0, nStart);
            }
            else if (!sub_0046E100(pUnit, nStart))
            {
                GFX_AddUnitOverlay(pUnit, nStart, 3, 0, 0, 0, 0, 0);
            }
        }
    }
}

inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecordInline(int nSkillId)
{
    if (nSkillId < sgptDataTables->nSkillsTxtRecordCount && nSkillId >= 0)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}

// 0x004D9180
void __fastcall PLRSKILLS_StateStartMissile(D2UnitStrc* pUnit, int nState)
{
    D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecordInline(nState);
    if (!pStatesTxtRecord || pStatesTxtRecord->wSkill < 0)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecordInline(pStatesTxtRecord->wSkill);
    if (!pSkillsTxtRecord || pSkillsTxtRecord->wCltMissileA < 0 || pSkillsTxtRecord->wCltMissileA >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return;
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.pOwner = pUnit;
    missileParams.pOrigin = pUnit;
    missileParams.nMissile = pSkillsTxtRecord->wCltMissileA;
    missileParams.nSkill = pStatesTxtRecord->wSkill;
    missileParams.nSkillLevel = 1;
    MISSILE_CreateClientMissile(&missileParams);

    if (pUnit)
    {
        pUnit->dwFlagEx |= 0x40000;
        pUnit->dwFlags |= 0x20;
    }
}

// 0x004D96B0
void __fastcall PLRSKILLS_StateMissile(D2UnitStrc* pUnit, int nState)
{
    D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecordInline(nState);
    if (!pStatesTxtRecord || pStatesTxtRecord->wMissile < 0 || pStatesTxtRecord->wMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return;
    }

    D2MissileStrc missileParams;
    memset(&missileParams, 0, sizeof(missileParams));
    missileParams.pOwner = pUnit;
    missileParams.pOrigin = pUnit;
    missileParams.nMissile = pStatesTxtRecord->wMissile;
    missileParams.nSkill = pStatesTxtRecord->wSkill >= 0 ? pStatesTxtRecord->wSkill : 0;
    missileParams.nSkillLevel = 1;
    MISSILE_CreateClientMissile(&missileParams);
}

// 0x004D9E60
void __fastcall PLRSKILLS_StartClientState(D2UnitStrc* pUnit, int nState)
{
    if (!pUnit || nState < 0 || nState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return;
    }

    D2StatesTxt* pStatesTxt = &sgptDataTables->pStatesTxt[nState];
    if (!pStatesTxt)
    {
        return;
    }

    if (pStatesTxt->nStateFlags[4] & gdwBitMasks[7])
    {
        if (pUnit->dwUnitType == UNIT_MONSTER && pUnit->dwAnimMode == MONMODE_DEAD)
        {
            return;
        }

        if (pUnit->dwUnitType == UNIT_PLAYER && pUnit->dwAnimMode == PLRMODE_DEAD)
        {
            return;
        }
    }

    if (pStatesTxt->wSetFunc >= 0 && pStatesTxt->wSetFunc < 31 && gpfnClientStateSetFuncs[pStatesTxt->wSetFunc])
    {
        gpfnClientStateSetFuncs[pStatesTxt->wSetFunc](pUnit, nState);
    }

    if (pStatesTxt->wCltEvent < 0)
    {
        return;
    }

    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
    if (!pStatList)
    {
        return;
    }

    const int nValue1 = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
    const int nValue2 = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_LEVEL, 0);
    SKILLS_CallClientStateEvent(pUnit, pStatesTxt->wCltEvent, nValue1, nValue2, pStatesTxt->wCltEventFunc, 1, nState);
}

// 0x004D9F40
void __fastcall PLRSKILLS_EndClientState(D2UnitStrc* pUnit, int nState)
{
    if (!pUnit || nState < 0 || nState >= sgptDataTables->nStatesTxtRecordCount)
    {
        return;
    }

    D2StatesTxt* pStatesTxt = &sgptDataTables->pStatesTxt[nState];
    if (!pStatesTxt)
    {
        return;
    }

    if (pStatesTxt->wRemFunc >= 0 && pStatesTxt->wRemFunc < 30 && gpfnClientStateRemFuncs[pStatesTxt->wRemFunc])
    {
        gpfnClientStateRemFuncs[pStatesTxt->wRemFunc](pUnit, nState);
    }

    if (pStatesTxt->wCltEvent < 0)
    {
        return;
    }

    if (!STATLIST_GetStatListFromUnitAndState(pUnit, nState))
    {
        return;
    }

    CUNITEVENT_RemoveCltUnitEvents(pUnit, 1, nState);
}



void __fastcall PLRSKILLS_StateCreateMissile(D2UnitStrc* pUnit, int nState); // 0x004D9740
void __fastcall PLRSKILLS_StateResetValue(D2UnitStrc* pUnit, int nState); // 0x004D97E0

// 0x004D8650
void __fastcall PLRSKILLS_CallSkillSeqDoBackward(D2UnitStrc* pUnit, int nArg)
{
    PLRSKILLS_SkillSeqDoBackward(pUnit, nArg);
}

// 0x004D9630
void __fastcall PLRSKILLS_StateOverlayRanges(D2UnitStrc* pUnit, int nState)
{
    D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecordInline(nState);
    if (!pStatesTxtRecord)
    {
        return;
    }

    int nEnd = pStatesTxtRecord->wOverlay[1];
    int nStart = pStatesTxtRecord->wOverlay[0];
    if (nStart >= 0)
    {
        for (int i = nStart; i <= nEnd; ++i)
        {
            AUTOMAP_RemoveUnitOverlay(pUnit, 0, i);
        }
    }

    nStart = pStatesTxtRecord->wOverlay[2];
    nEnd = pStatesTxtRecord->wOverlay[3];
    if (nStart >= 0)
    {
        for (int i = nStart; i <= nEnd; ++i)
        {
            AUTOMAP_RemoveUnitOverlay(pUnit, 0, i);
        }
    }
}

// 0x004D97F0
void __stdcall PLRSKILLS_UpdateStateColor(D2UnitStrc* pUnit)
{
    int nBestState = -1;
    unsigned char nBestPri = 0;
    for (int i = 0; i < sgptDataTables->nStatesTxtRecordCount; ++i)
    {
        D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecordInline(i);
        if (pStatesTxtRecord && STATES_CheckState(pUnit, i) && pStatesTxtRecord->nColorPri > nBestPri)
        {
            nBestState = i;
            nBestPri = pStatesTxtRecord->nColorPri;
        }
    }

    if (nBestState > 0)
    {
        D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecordInline(nBestState);
        if (!pStatesTxtRecord)
        {
            return;
        }

// build: symbol ?D2GFX_IsHardwareRenderMode@* 0x004F51C0
        if (pStatesTxtRecord->nColorShift == 0x68 && pUnit == sub_00463DD0_GetPlayerUnit() && D2GFX_IsHardwareRenderMode())
        {
            pUnit->nPaletteIndex = 0;
        }
        else
        {
            pUnit->nPaletteIndex = pStatesTxtRecord->nColorShift;
        }

        if (pUnit == sub_00463DD0_GetPlayerUnit() && pUnit->pLight)
        {
            SCMD_SetLightColorBytes(pUnit->pLight, pStatesTxtRecord->nLightRGB[0], pStatesTxtRecord->nLightRGB[1], pStatesTxtRecord->nLightRGB[2]);
        }
    }
    else
    {
        pUnit->nPaletteIndex = 0;
        if (pUnit == sub_00463DD0_GetPlayerUnit() && pUnit->pLight)
        {
            SCMD_SetLightColorBytes(pUnit->pLight, 0xFF, 0xFF, 0xFF);
        }
    }
}

// 0x004D9160
void __fastcall sub_004D9160(D2UnitStrc* pArg)
{
    SKILLS_RefreshPassiveSkills(pArg);
}

// 0x004D9170
void __fastcall sub_004D9170(D2UnitStrc* pArg)
{
    SKILLS_RefreshPassiveSkills(pArg);
}

// 0x004D93B0
void __fastcall PLRSKILLS_SendPositionEvent(D2UnitStrc* pUnit)
{
    D2UnitEventArgsStrc tArgs = {};

    int nX;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nX = pUnit->pStaticPath->tGameCoords.nX;
        break;

    default:
        if (pUnit->pDynamicPath)
        {
            nX = PATH_GetXPosition(pUnit->pDynamicPath);
        }
        else
        {
            nX = 0;
        }
        break;
    }
    tArgs.nX = nX;

    int nY;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nY = pUnit->pStaticPath->tGameCoords.nY;
        break;

    default:
        if (pUnit->pDynamicPath)
        {
            nY = PATH_GetYPosition(pUnit->pDynamicPath);
        }
        else
        {
            nY = 0;
        }
        break;
    }
    tArgs.nY = nY;

    sub_00480C10_DispatchUnitEvent(0x19, pUnit, &tArgs, 0);
    D2COMMON_10160_PathUpdateDirection(pUnit->pDynamicPath, 0);
}




#include "gen/data/Source/D2Client/UNIT/PlrSkills.inc"

static D2StatesTxt* STATES_GetStatesTxtRecord_J03(int nState)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nState];
    }

    return 0;
}

// 0x004D9740
void __fastcall PLRSKILLS_StateCreateMissile(D2UnitStrc* pUnit, int nState)
{
    sub_004AF890(pUnit, 5, 0);

    D2StatesTxt* pStatesTxt = STATES_GetStatesTxtRecord_J03(nState);
    if (!pStatesTxt)
    {
        return;
    }

    if (pStatesTxt->wMissile < 0 || pStatesTxt->wMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return;
    }

    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.pOwner = pUnit;
    tMissile.pOrigin = pUnit;
    tMissile.nMissile = pStatesTxt->wMissile;
    tMissile.nSkill = pStatesTxt->wSkill >= 0 ? pStatesTxt->wSkill : 0;
    tMissile.nSkillLevel = 1;
    MISSILE_CreateClientMissile(&tMissile);
}

// 0x004D97E0
void __fastcall PLRSKILLS_StateResetValue(D2UnitStrc* pUnit, int nState)
{
    GAME_SetSkillDelayUntil(0);
}

// 0x004D9920
void __fastcall PLRSKILLS_StartStateOverlays(D2UnitStrc* pUnit, int nState)
{
    D2StatesTxt* pStatesTxtRecord = DATATBLS_GetStatesTxtRecordInline(nState);
    if (!pStatesTxtRecord || (pStatesTxtRecord->nStateFlags[4] & gdwBitMasks_006CE268[3]))
    {
        return;
    }

    int nCastOverlay = (short)pStatesTxtRecord->wCastOverlay >= 0 ? (short)pStatesTxtRecord->wCastOverlay : -1;
    int nOverlay1 = pStatesTxtRecord->wOverlay[0] >= 0 ? pStatesTxtRecord->wOverlay[0] : -1;
    int nOverlay2 = pStatesTxtRecord->wOverlay[1] >= 0 ? pStatesTxtRecord->wOverlay[1] : -1;
    const int bMask = STATES_CheckStateMaskAuraByStateId(nState);

    if (nCastOverlay != -1)
    {
        nCastOverlay += ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, DATATBLS_Get1OfNFromOverlayTxt(nCastOverlay));
    }

    if (nOverlay1 != -1)
    {
        nOverlay1 += ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, DATATBLS_Get1OfNFromOverlayTxt(nOverlay1));
    }

    if (nOverlay2 != -1)
    {
        nOverlay2 += ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, DATATBLS_Get1OfNFromOverlayTxt(nOverlay2));
    }

    if (bMask)
    {
        STATES_ToggleState(pUnit, nState, 0);
        if (sub_0063A250(pUnit))
        {
            nCastOverlay = -1;
        }
        STATES_ToggleState(pUnit, nState, 1);
    }

    if (nCastOverlay != -1)
    {
        if (bMask)
        {
            GFX_AddUnitOverlay(pUnit, nCastOverlay, 9, 0, nOverlay1, nOverlay2, nState, 0);
        }
        else
        {
            GFX_AddUnitOverlay(pUnit, nCastOverlay, 4, 0, nOverlay1, nOverlay2, 0, 0);
        }
        return;
    }

    if (nOverlay1 != -1)
    {
        if (bMask)
        {
            GFX_AddUnitOverlay(pUnit, nOverlay1, 8, 0, nState, 0, 0, 0);
        }
        else
        {
            GFX_AddUnitOverlay(pUnit, nOverlay1, 3, 0, 0, 0, 0, 0);
        }
    }

    if (nOverlay2 != -1)
    {
        if (bMask)
        {
            GFX_AddUnitOverlay(pUnit, nOverlay2, 8, 0, nState, 0, 0, 0);
        }
        else
        {
            GFX_AddUnitOverlay(pUnit, nOverlay2, 3, 0, 0, 0, 0, 0);
        }
    }
}

// 0x004D9AD0
static void PLRSKILLS_ResetTransform(D2UnitStrc* pUnit)
{
    GFX_ResetGfx(pUnit);
    if (pUnit)
    {
        if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            if (pUnit->dwAnimMode == 0x12)
                return;
            UNITMODE_SetUnitMode(pUnit, 1);
        }
        else if (pUnit->dwUnitType == UNIT_MONSTER)
        {
            UNITMODE_SetUnitMode(pUnit, 1);
        }
    }
    GFX_RefreshUnitGfx(pUnit, 1);
    UNITS_SetAnimStartFrame(pUnit);
    pUnit->nSeqCurrentFramePrecise = 0;
    UNITS_SetUsedSkill(pUnit, 0);
}

// 0x004D9B20
void __fastcall PLRSKILLS_BeginState(D2UnitStrc* pUnit, int nState)
{
    if (!pUnit)
        return;

    D2StatesTxt* pTxt = GetStatesTxtRecord(nState);
    if (!pTxt)
        return;

    if (pTxt->nStateFlags[39 >> 3] & gdwBitMasks_006CE268[39 & 7])
    {
        if ((pUnit->dwUnitType == UNIT_MONSTER && pUnit->dwAnimMode == 0xC) || (pUnit->dwUnitType == UNIT_PLAYER && pUnit->dwAnimMode == 0x11))
        {
            STATES_ToggleState(pUnit, nState, 1);
            return;
        }
    }

    if (STATES_CheckState(pUnit, nState))
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
        if (!(pTxt->nStateFlags[36 >> 3] & gdwBitMasks_006CE268[36 & 7]))
        {
            STATLIST_RemoveAllStats(pStatList);
        }
    }
    else if (pTxt->wOnSound >= 0)
    {
        sub_004B9A00(pTxt->wOnSound, pUnit, 0, 0, 0);
    }

    STATES_ToggleState(pUnit, nState, 1);
    if (pTxt->nColorShift)
    {
        PLRSKILLS_UpdateStateColor(pUnit);
    }
    PLRSKILLS_StartStateOverlays(pUnit, nState);
    if (CUNIT_IsDeadOrDying(pUnit) && STATES_CheckStateMaskHideOnUnit(pUnit))
    {
        pUnit->dwFlagEx |= 0x40000;
        pUnit->dwFlags &= ~2;
        pUnit->dwFlags |= 0x20;
    }
    if (pTxt->nStateFlags[3 >> 3] & gdwBitMasks_006CE268[3 & 7])
    {
        PLRSKILLS_ResetTransform(pUnit);
    }
}

// 0x004D9C30
void __fastcall PLRSKILLS_EndState(D2UnitStrc* pUnit, int nState)
{
    if (!pUnit)
        return;

    D2StatesTxt* pTxt = GetStatesTxtRecord(nState);
    if (!pTxt)
        return;

    if (STATES_CheckState(pUnit, nState))
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
        if (pStatList && nState == STATLIST_GetState(pStatList))
        {
            D2Common_10474(pUnit, pStatList);
            STATLIST_FreeStatList(pStatList);
        }
        if (pTxt->wOffSound >= 0)
        {
            sub_004B9A00(pTxt->wOffSound, pUnit, 0, 0, 0);
        }
    }

    STATES_ToggleState(pUnit, nState, 0);
    if (pTxt->nColorShift)
    {
        PLRSKILLS_UpdateStateColor(pUnit);
    }
    if ((short)pTxt->wRemoveOverlay >= 0)
    {
        int nOverlay = (short)pTxt->wRemoveOverlay;
        if (nOverlay != -1)
        {
            nOverlay += ITEMS_RollLimitedRandomNumber(&pUnit->pSeed, DATATBLS_Get1OfNFromOverlayTxt(nOverlay));
        }
        GFX_AddUnitOverlay(pUnit, nOverlay, 4, 0, -1, -1, 0, 0);
    }
    if (pTxt->wOverlay[0] >= 0)
    {
        PLRSKILLS_OverlayVariants(pUnit, pTxt->wOverlay[0]);
    }
    if (pTxt->wOverlay[1] >= 0)
    {
        PLRSKILLS_OverlayVariants(pUnit, pTxt->wOverlay[1]);
    }
    if (pTxt->nStateFlags[3 >> 3] & gdwBitMasks_006CE268[3 & 7])
    {
        PLRSKILLS_ResetTransform(pUnit);
    }
    UnitUpdateAnimRateAndVel(pUnit, ".\\UNIT\\PlrSkills.cpp", 0x59C);
}

inline D2ItemStatCostTxt* DATATBLS_GetItemStatCostTxtRecordInline(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }

    return 0;
}

// 0x004D9D70
D2StatListStrc* __fastcall PLRSKILLS_SetStateStat(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int nState, int nStatId, int nValue, int nLayer)
{
    if (!pUnit)
    {
        return 0;
    }

    int nOldValue = 0;
    if (nStatId == STAT_UNIT_MODE)
    {
        nOldValue = 4;
    }

    if (!pStatList)
    {
        pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
        if (!pStatList)
        {
            pStatList = STATLIST_AllocStatList(pStatList, (unsigned int)pStatList, (unsigned int)pStatList, (!pUnit ? 6 : pUnit->dwUnitType), (!pUnit ? -1 : pUnit->dwUnitId));
            STATLIST_SetState(pStatList, nState);
            D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
        }
        else
        {
            nOldValue = STATLIST_GetStatValue(pStatList, nStatId, nLayer);
        }
    }

    STATLIST_SetStat(pStatList, nStatId, nValue, nLayer);

    if (nStatId == STAT_UNIT_MODE)
    {
        SCMD_HandleMonsterModeChange(pUnit, nOldValue, nValue);
    }

    D2ItemStatCostTxt* pItemStatCostTxtRecord = DATATBLS_GetItemStatCostTxtRecordInline(nStatId);
    if (pItemStatCostTxtRecord && pItemStatCostTxtRecord->nItemStatFlags[ITEMSTATCOSTFLAGINDEX_UPDATEANIMRATE >> 3] & gdwBitMasks_006CE268[ITEMSTATCOSTFLAGINDEX_UPDATEANIMRATE & 7])
    {
        UnitUpdateAnimRateAndVel(pUnit, ".\\UNIT\\PlrSkills.cpp", 1490);
    }

    return pStatList;
}


// 0x004E0FD0
int __fastcall PLRSKILLS_SkillStartMarkTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    if (!SKILLS_GetSkillsTxtRecord(nSkillId))
    {
        return 0;
    }

    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pUnit);
    if (!pSkill)
    {
        return 0;
    }

    int nMode;
    int nY;
    int nX;
    if (MONSTERS_GetSpawnMode_XY(pUnit, 1, nSkillId, nSkillLevel, &nMode, &nX, &nY) < 0)
    {
        return 0;
    }

    SKILLS_SetParam2(pSkill, nX);
    SKILLS_SetParam3(pSkill, nY);
    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY);
    COLLISION_SetMaskWithPattern(pRoom, nX, nY, 1, 0x100);
    return 1;
}

// 0x004E1B10
int __fastcall PLRSKILLS_FireAtTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    const int nMissile = pSkillsTxtRecord->wCltMissileA;
    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2MissilesTxt* pMissilesTxtRecord = &sgptDataTables->pMissilesTxt[nMissile];
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    if (pUnit)
    {
        pUnit->dwFlags |= 0x40;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.nMissile = nMissile;
    tMissileParams.dwFlags = 3;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pUnit;
    tMissileParams.nX = CLIENTS_GetUnitX(pUnit);
    tMissileParams.nY = CLIENTS_GetUnitY(pUnit);
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nLoops = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCalc[0], nSkillId, nSkillLevel);

    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (pTarget)
    {
        D2Common_10216(pUnit->pDynamicPath, CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget), 0);
        tMissileParams.nTargetX = CLIENTS_GetUnitX(pTarget) - CLIENTS_GetUnitX(pUnit);
        tMissileParams.nTargetY = CLIENTS_GetUnitY(pTarget) - CLIENTS_GetUnitY(pUnit);
    }
    else
    {
        tMissileParams.nTargetX = D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath) - CLIENTS_GetUnitX(pUnit);
        tMissileParams.nTargetY = D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath) - CLIENTS_GetUnitY(pUnit);
    }

    D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissileParams);
    if (pMissile)
    {
        MISSILE_SetTargetX(pMissile, nSkillLevel);
    }

    return pMissilesTxtRecord ? 1 : 0;
}



// 0x004F1D80
int __fastcall PLRSKILLS_MotionMissiles(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    if (SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwAuraRangeCalc, nSkillId, nSkillLevel) <= 0)
    {
        return 0;
    }

    const int nA = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[0], nSkillId, nSkillLevel);
    if (nA <= 0)
    {
        return 0;
    }

    const int nB = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[1], nSkillId, nSkillLevel);
    if (nB <= 0)
    {
        return 0;
    }

    const int nC = SKILLS_EvaluateSkillFormula(pUnit, pSkillsTxtRecord->dwCltCalc[2], nSkillId, nSkillLevel);
    if (nC <= 0)
    {
        return 0;
    }

    const int nZ = nB * nA;
    const int nX = nC * nA;
    int nTargetX;
    int nTargetY;
    if (!ITEM_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.pOwner = pUnit;
    tMissileParams.dwFlags = 1;
    tMissileParams.nX = nTargetX;
    tMissileParams.nY = nTargetY;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;

    const short nMissileA = pSkillsTxtRecord->wCltMissileA;
    if (nMissileA >= 0)
    {
        tMissileParams.nMissile = nMissileA;
        D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissileParams);
        if (pMissile)
        {
            GFXUTIL_SetMotionVectorA(pMissile, nX, 0, nZ);
            GFXUTIL_SetMotionVectorB(pMissile, -nC, 0, -nB, 1);
        }
    }

    const short nMissileB = pSkillsTxtRecord->wCltMissileB;
    if (nMissileB >= 0)
    {
        tMissileParams.nMissile = nMissileB;
        D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissileParams);
        if (pMissile)
        {
            GFXUTIL_SetMotionVectorA(pMissile, nX, 0, nZ);
            GFXUTIL_SetMotionVectorB(pMissile, -nC, 0, -nB, 1);
        }
    }

    return 1;
}

// 0x004F4000
int __fastcall PLRSKILLS_MissileByOverlay(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return 0;
    }

    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (!pTarget)
    {
        return 0;
    }

    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;
    if (nType != 1)
    {
        return 0;
    }

    if (!MONSTERREGION_CheckMonStats2Flag(pTarget->dwClassId, 8))
    {
        return 0;
    }

    if (!D2COMMON_11017_CheckUnitIfConsumeable(pTarget, 0))
    {
        return 0;
    }

    if (!sub_004B11F0(pTarget))
    {
        return 0;
    }

    D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pTarget->dwClassId);
    if (!pMonStats2TxtRecord)
    {
        return 0;
    }

    int nMissile = pSkillsTxtRecord->wCltMissileA;
    switch (pMonStats2TxtRecord->nOverlayHeight)
    {
    case 1:
        nMissile = pSkillsTxtRecord->wCltMissileB;
        break;

    case 3:
        nMissile = pSkillsTxtRecord->wCltMissileC;
        break;
    }

    if (nMissile < 0 || nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.dwFlags = 0x2000;
    tMissileParams.pOwner = pUnit;
    tMissileParams.pOrigin = pTarget;
    tMissileParams.nSkill = nSkillId;
    tMissileParams.nSkillLevel = nSkillLevel;
    tMissileParams.nMissile = nMissile;
    return MISSILE_CreateClientMissile(&tMissileParams) != 0;
}
