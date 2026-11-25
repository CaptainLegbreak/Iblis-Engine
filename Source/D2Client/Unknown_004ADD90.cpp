#include "D2MissileIds.h"
#include "D2StateIds.h"
#include "D2MonsterIds.h"
#include "D2SkillIds.h"
#include "D2StatIds.h"
#include "D2Unicode.h"
#include "D2Structs.h"
#include "D2UnitData.h"
#include "D2Client.h"
#include "D2MonModes.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Constants.h"
#include "D2ClientTypes.h"
#include "D2ClientGame.h"

extern unsigned short gwUniqueModNameIds[];                                                       // 0x00725188

extern "C" { Unicode gwszNameSeparator[1]; }                                                                // 0x007C0C58

int __fastcall MONSTER_IsMinionMonster(D2UnitStrc* pUnit);                                             // 0x004AE380

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText);                                             // 0x00501820

int __fastcall D2Win_10127_SetFont(int nArg);                                                                      // 0x00502EF0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30

extern "C" unsigned short* __fastcall sub_005267E0(unsigned short* pDst, const unsigned short* pSrc);     // 0x005267E0

extern "C" int __fastcall sub_00526800(const unsigned short* pText);                                      // 0x00526800

typedef void (__fastcall* UMODCALLBACK)(void* pTarget, int nUMod, int bUnique);

struct D2UModCallbacksStrc
{
    UMODCALLBACK pCallbacks[5];
};

extern D2UModCallbacksStrc gaUModCallbacks[]; // 0x00724E28

static int sub_0044BE50(D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit)
        nType = pUnit->dwUnitType;
    return nType;
}

static int MONSTERS_CheckMonTypeFlag(D2UnitStrc* pUnit, unsigned short nFlag)
{
    D2MonsterDataStrc* pMonsterData = sub_0044BE50(pUnit) == 1 ? pUnit->pMonsterData : 0;
    if (!pMonsterData)
        return 0;
    if (pMonsterData->nTypeFlag & nFlag)
        return 1;
    return 0;
}

static unsigned char* MONSTERUNIQUE_GetUMods(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = sub_0044BE50(pUnit) == 1 ? pUnit->pMonsterData : 0;
    if (pMonsterData)
        return pMonsterData->nMonUmod;
    return 0;
}

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

int __fastcall MISSILE_SubmitMissileRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00

void __fastcall VIEW_SpawnAndarielDeath(D2UnitStrc* pUnit);                                               // 0x0046BA50

void __fastcall sub_0046B710_SpawnMissileAtObject173(D2UnitStrc* pUnit);                                                            // 0x0046B710

void __fastcall sub_0046BA90_PlayerRequestAtUnit15B(D2UnitStrc* pUnit);                                     // 0x0046BA90

void __fastcall sub_0046BB90_PlayerRequestAtUnit16B(D2UnitStrc* pUnit);                                     // 0x0046BB90

void __fastcall VIEW_SpawnMephistoDeath(D2UnitStrc* pUnit);                                          // 0x0046B9A0

int __fastcall UI_SetTimerUnitId(D2UnitStrc* pUnit);                                              // 0x0046BC70

void __fastcall VIEW_SpawnIzualDeath(D2UnitStrc* pUnit);                                             // 0x0046BC10

void __fastcall VIEW_SpawnMissileNearObject(D2UnitStrc* pUnit);                                                            // 0x0046B850

void __fastcall sub_0046BB10_PlayerRequestAtUnit161(D2UnitStrc* pUnit);                                     // 0x0046BB10

void __fastcall VIEW_SpawnBrDeathControl(D2UnitStrc* pUnit);                                           // 0x0046B680

void __fastcall sub_0046B3C0_UnitRequest25A(D2UnitStrc* pUnit);                                             // 0x0046B3C0

void __fastcall sub_0046BC90_RequestAtMonster220(D2UnitStrc* pUnit);                                        // 0x0046BC90

void __fastcall sub_0046B530_SpawnMissileAtObject(D2UnitStrc* pUnit);                                       // 0x0046B530

void __fastcall SKILLS_StartUnitEffect(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nEffect, int nArg4, int nArg5, int nStatValue, int nVelocity); // 0x004C70D0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

D2UnitStrc* __fastcall MISSILE_SubmitOwnerRequest(D2UnitStrc* pUnit, int nArg0, int nArg5, int nArg6, int nArg3, int nArg4); // 0x004CDBA0

void __fastcall GFX_RemoveOverlays(D2UnitStrc* pUnit); // 0x0046F170

void __fastcall GFX_AddUnitOverlay(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

static inline unsigned __int64 SEED_RollRandomNumberForceInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

void __fastcall sub_0046C320_SpawnAroundUnit(D2UnitStrc* pUnit, int nMonsterId, int nCount); // 0x0046C320

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

static int GetUnitPathX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
    }
}

static int GetUnitPathY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    default:
        return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
    }
}

D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540

D2UnitStrc* __fastcall CUNIT_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0

__forceinline D2MissilesTxt* SKILLS_GetMissilesTxtRecord(int nMissileId)
{
    if (nMissileId >= 0 && nMissileId < sgptDataTables->nMissilesTxtRecordCount)
    {
        return &sgptDataTables->pMissilesTxt[nMissileId];
    }

    return 0;
}

extern "C" int __fastcall sub_004AC7E0(D2UnitStrc* pUnit, unsigned short wMask); // 0x004AC7E0

D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pPath); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pPath); // 0x00648A10

void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40

extern "C" int __stdcall sub_0064A280(D2UnitStrc* pMissile); // 0x0064A280

extern "C" int __stdcall sub_0064A210(D2UnitStrc* pMissile); // 0x0064A210

static D2MonStatsTxt* GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

unsigned char __cdecl GAME_GetDifficulty(); // 0x0044DCD0

void __fastcall SKILLDESC_InitCappedChargedPath(D2UnitStrc* pMissile, int nArg); // 0x004E2ED0

extern const unsigned int gdwBitMasks[32]; // 0x006CE268

// 0x004AD0C0
void __fastcall NPCMENU_StateOverlayBurst(D2UnitStrc* pUnit, int nState, int bFlag)
{
    if (!bFlag)
    {
        return;
    }

    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &bFlag, &nFrameCount);
    if (pUnit && pUnit->dwAnimMode)
    {
        return;
    }
    if (bFlag != 4)
    {
        return;
    }

    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);
    MISSILE_SubmitMissileRequest(pUnit, 0x52, nX, nY, 0, 1);
    MISSILE_SubmitMissileRequest(pUnit, 0x52, nX + 1, nY + 1, 0, 1);
    MISSILE_SubmitMissileRequest(pUnit, 0x52, nX + 1, nY - 1, 0, 1);
    MISSILE_SubmitMissileRequest(pUnit, 0x52, nX - 1, nY + 1, 0, 1);
    MISSILE_SubmitMissileRequest(pUnit, 0x52, nX - 1, nY - 1, 0, 1);
    sub_004B9A00(0x99A, pUnit, 0, 0, 0);
}

// 0x004AD1A0
void __fastcall NPCMENU_StateOverlayCross(D2UnitStrc* pUnit, int nState, int bFlag)
{
    if (!bFlag)
    {
        return;
    }

    int nFrame;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);
    if (pUnit && pUnit->dwAnimMode)
    {
        return;
    }
    if (nFrame != 4)
    {
        return;
    }

    const int nX = CLIENTS_GetUnitX(pUnit);
    const int nY = CLIENTS_GetUnitY(pUnit);
    MISSILE_SubmitMissileRequest(pUnit, 0x75, nX, nY, 0, 1);
    const int nYPlus = nY + 1;
    const int nXPlus = nX + 1;
    MISSILE_SubmitMissileRequest(pUnit, 0x75, nXPlus, nYPlus, 0, 1);
    bFlag = nY - 1;
    MISSILE_SubmitMissileRequest(pUnit, 0x75, nXPlus, bFlag, 0, 1);
    const int nXMinus = nX - 1;
    MISSILE_SubmitMissileRequest(pUnit, 0x75, nXMinus, nYPlus, 0, 1);
    MISSILE_SubmitMissileRequest(pUnit, 0x75, nXMinus, bFlag, 0, 1);
    MISSILE_SubmitMissileRequest(pUnit, 0x52, nX, nY, 0, 1);
    MISSILE_SubmitMissileRequest(pUnit, 0x52, nXPlus, nYPlus, 0, 1);
    MISSILE_SubmitMissileRequest(pUnit, 0x52, nXPlus, bFlag, 0, 1);
    MISSILE_SubmitMissileRequest(pUnit, 0x52, nXMinus, nYPlus, 0, 1);
    MISSILE_SubmitMissileRequest(pUnit, 0x52, nXMinus, bFlag, 0, 1);
    sub_004B9A00(0x99A, pUnit, 0, 0, 0);
}

// 0x004AD2F0
void __fastcall NPCMENU_HandleUnitClassEvent(D2UnitStrc* pUnit, int nUnused, int nUnused2)
{
    if (!pUnit)
    {
        return;
    }

    switch ((unsigned int)pUnit->dwClassId)
    {
    case 0x9C:
        if (pUnit->dwAnimMode == 0)
        {
            VIEW_SpawnAndarielDeath(pUnit);
        }
        break;

    case 0x2D:
        if (pUnit->dwAnimMode == 0)
        {
            sub_0046B710_SpawnMissileAtObject173(pUnit);
        }
        break;

    case 0xE5:
        if (pUnit->dwAnimMode == 0)
        {
            sub_0046BA90_PlayerRequestAtUnit15B(pUnit);
        }
        break;

    case 0xD3:
        if (pUnit->dwAnimMode == 0)
        {
            sub_0046BB90_PlayerRequestAtUnit16B(pUnit);
        }
        break;

    case 0xF2:
        if (pUnit->dwAnimMode == 0)
        {
            VIEW_SpawnMephistoDeath(pUnit);
        }
        break;

    case 0xF3:
        if (pUnit->dwAnimMode == 0)
        {
            UI_SetTimerUnitId(pUnit);
        }
        break;

    case 0x100:
        if (pUnit->dwAnimMode == 0)
        {
            VIEW_SpawnIzualDeath(pUnit);
        }
        break;

    case 0x16E:
        if (pUnit->dwAnimMode == 0)
        {
            VIEW_SpawnMissileNearObject(pUnit);
        }
        break;

    case 0x11C:
        if (pUnit->dwAnimMode == 0x0E)
        {
            sub_0046BB10_PlayerRequestAtUnit161(pUnit);
        }
        break;

    case 0x10B:
        if (pUnit->dwAnimMode == 0)
        {
            VIEW_SpawnBrDeathControl(pUnit);
        }
        break;

    case 0x1DF:
        if (pUnit->dwAnimMode == 0)
        {
            sub_0046B3C0_UnitRequest25A(pUnit);
        }
        break;

    case 0x220:
        if (pUnit->dwAnimMode == 0)
        {
            sub_0046BC90_RequestAtMonster220(pUnit);
        }
        break;

    case 0x21C:
    case 0x21D:
    case 0x21E:
        if (pUnit->dwAnimMode == 0)
        {
            sub_0046B530_SpawnMissileAtObject(pUnit);
        }
        break;
    }
}

// 0x004AD510
void __fastcall NPCMENU_StateStartEffect(D2UnitStrc* pUnit, int nState, int bFlag)
{
    if (!bFlag && nState == 0x12)
    {
        return;
    }

    if (nState == 0x2A)
    {
        if (!pUnit || !pUnit->dwAnimMode)
        {
            SKILLS_StartUnitEffect(pUnit, pUnit, 0x5A, -1, 0, STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0), DATATBLS_GetMissileVelocityFromMissilesTxt(MISSILE_NOVA, 0));
        }
    }

    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &bFlag, &nFrameCount);
    if (pUnit && pUnit->dwAnimMode)
    {
        return;
    }
    if (bFlag != 4)
    {
        return;
    }

    if (nState == 0x0A)
    {
        MISSILE_SubmitOwnerRequest(pUnit, 0x9B, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0, STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0));
        return;
    }
    if (nState == 0x12)
    {
        SKILLS_StartUnitEffect(pUnit, pUnit, 0xC2, -1, 0, STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0), DATATBLS_GetMissileVelocityFromMissilesTxt(MISSILE_FROSTNOVA, 0));
    }
}

// 0x004AD5F0
void __fastcall NPCMENU_StateDurielDeath(D2UnitStrc* pUnit, int nState, int bFlag)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
        return;

    D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
    if (!pMonsterData)
        return;

    if (pUnit->dwAnimMode == MONMODE_DEATH)
    {
        int nFrame;
        int nFrameCount;
        UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);
        if (nFrame == 13)
        {
            GFX_RemoveOverlays(pUnit);
            GFX_AddUnitOverlay(pUnit, 0x34, 5, 0, 0, 0, 0, 0);
            GFX_AddUnitOverlay(pUnit, 0x9C, 5, 0, 0, 0, 0, 0);
            pUnit->nActionFrame = 0;
        }
    }
    else if (pUnit->dwAnimMode == MONMODE_DEAD)
    {
        if ((unsigned int)SEED_RollRandomNumberForceInline(&pUnit->pSeed) % 100 == 0 && (int)pMonsterData->dwDurielFlag < 100)
        {
            CLIENTS_GetUnitX(pUnit);
            CLIENTS_GetUnitY(pUnit);
            sub_0046C320_SpawnAroundUnit(pUnit, MONSTER_MAGGOT, 4);
            pMonsterData->dwDurielFlag += 4;
        }
    }
}

// 0x004AD6E0
static void __stdcall NPCMENU_StateMissileBurst(int nSkillLevel, D2UnitStrc* pUnit, int nMissile)
{
    if (!nSkillLevel)
        nSkillLevel = 1;
    if (nMissile == MISSILE_LIGHTUNIQUE)
    {
        if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER || !pUnit->pMonsterData || !(pUnit->pMonsterData->nTypeFlag & 0x100))
            return;
    }
    D2MissileStrc tMissile;
    memset(&tMissile, 0, sizeof(tMissile));
    tMissile.dwFlags = 0x21;
    tMissile.pOwner = pUnit;
    tMissile.nX = GetUnitPathX(pUnit);
    tMissile.nY = GetUnitPathY(pUnit);
    tMissile.nSkill = 0;
    tMissile.nSkillLevel = nSkillLevel;
    tMissile.nMissile = nMissile;
    if (nMissile != MISSILE_QUEENPOISONCLOUD)
        tMissile.pInitFunc = SKILLDESC_InitCappedChargedPath;
    int anDX[4] = { 0, 1, 0, -1 };
    int anDY[4] = { -1, 0, 1, 0 };
    for (int i = 0; i < 4; ++i)
    {
        const int nUnitX = GetUnitPathX(pUnit);
        const int nUnitY = GetUnitPathY(pUnit);
        const int nX = anDX[i] + nUnitX;
        const int nY = anDY[i] + nUnitY;
        for (int j = 0; j < 2; ++j)
        {
            tMissile.nInitArg = j;
            tMissile.nTargetX = nX;
            tMissile.nTargetY = nY;
            MISSILE_CreateClientMissile(&tMissile);
        }
    }
}

// 0x004AD890
void __fastcall NPCMENU_StateBurstOnFrame(D2UnitStrc* pUnit, int nState, int bSet)
{
    if (!bSet)
        return;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &bSet, &nFrameCount);
    if (!pUnit || pUnit->dwAnimMode != 3 || bSet != 2)
        return;
    const int nLevel = STATLIST_UnitGetStatValue(pUnit, 0xC, 0) >> 1;
    NPCMENU_StateMissileBurst(nLevel, pUnit, MISSILE_LIGHTUNIQUE);
}

// 0x004AD8E0
void __fastcall NPCMENU_StateBurst(D2UnitStrc* pUnit, int nState, int bSet)
{
    if (!bSet)
        return;
    if (pUnit && pUnit->dwAnimMode == 3)
        return;
    const int nLevel = STATLIST_UnitGetStatValue(pUnit, 0xC, 0) >> 1;
    NPCMENU_StateMissileBurst(nLevel, pUnit, MISSILE_LIGHTUNIQUE);
}

// 0x004AD920
void __fastcall NPCMENU_StateBurstNeutral(D2UnitStrc* pUnit, int nState, int bSet)
{
    int nFrameNo;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrameNo, &nFrameCount);
    if (pUnit && pUnit->dwAnimMode != 3 && pUnit->dwAnimMode)
        return;
    if (nFrameNo != 2)
        return;
    const int nLevel = STATLIST_UnitGetStatValue(pUnit, 0xC, 0);
    NPCMENU_StateMissileBurst(nLevel, pUnit, MISSILE_BUGLIGHTNING);
}

// 0x004AD970
void __fastcall NPCMENU_StateMissileSplit(D2UnitStrc* pUnit, int nState, int bFlag)
{
    if (!bFlag || !pUnit || pUnit->dwUnitType != UNIT_MISSILE)
    {
        return;
    }

    const int nMissileId = pUnit->dwClassId;
    D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pUnit);
    if (!pOwner)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = SKILLS_GetMissilesTxtRecord(nMissileId);
    if (!pMissilesTxtRecord || pMissilesTxtRecord->nMissileFlags[12 >> 3] & gdwBitMasks[12 & 7])
    {
        return;
    }

    if (sub_004AC7E0(pOwner, 0x80))
    {
        return;
    }

    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pOwner);
    int nX;

    if (!pTarget)
    {
        nX = D2COMMON_10175_PathGetFirstPointX(pPath);
        bFlag = D2COMMON_10176_PathGetFirstPointY(pPath);
    }
    else
    {
        nX = CLIENTS_GetUnitX(pTarget);
        bFlag = CLIENTS_GetUnitY(pTarget);
    }

    D2SeedStrc tSeed;
    SEED_InitSeed(&tSeed);
    SEED_InitLowSeed(&tSeed, 'SEIS');
    tSeed.nHighSeed = pOwner->dwUnitId;

    int nDX = CLIENTS_GetUnitX(pOwner) - nX;
    int nDY = CLIENTS_GetUnitY(pOwner) - bFlag;

    if (nDX < 0)
    {
        nDX = -1;
    }
    else if (nDX > 0)
    {
        nDX = 1;
    }

    if (nDY < 0)
    {
        nDY = -1;
    }
    else if (nDY > 0)
    {
        nDY = 1;
    }

    switch (nMissileId)
    {
    case MISSILE_MUMMY1:
    case 63 + 1:
    case 63 + 2:
    case MISSILE_MUMMY4:
        nDY = 0;
        nDX = 0;
        break;
    }

    if (pOwner->dwUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = pOwner->pMonsterData;
        if (pMonsterData)
        {
            pMonsterData->nTypeFlag |= 0x80;
        }
    }

    MISSILE_SubmitOwnerRequest(pOwner, nMissileId, nX - nDY, bFlag + nDX, sub_0064A280(pUnit), sub_0064A210(pUnit));
    MISSILE_SubmitOwnerRequest(pOwner, nMissileId, nX + nDY, bFlag - nDX, sub_0064A280(pUnit), sub_0064A210(pUnit));

    if (pOwner->dwUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = pOwner->pMonsterData;
        if (pMonsterData)
        {
            pMonsterData->nTypeFlag &= ~0x80;
        }
    }
}

// 0x004ADB20
void __fastcall NPCMENU_StateOverlayAtPath(D2UnitStrc* pUnit, int nState, int bFlag)
{
    int nFrame;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);
    if (pUnit && pUnit->dwAnimMode)
    {
        return;
    }
    if (nFrame != 4)
    {
        return;
    }
    MISSILE_SubmitOwnerRequest(pUnit, 0x2A, GetUnitPathX(pUnit), GetUnitPathY(pUnit), 0, 1);
}

// 0x004ADBC0
void __fastcall NPCMENU_StateMonOverlay(D2UnitStrc* pUnit, int nState, int bFlag)
{
    D2MonStatsTxt* pMonStatsTxtRecord = pUnit ? GetMonStatsTxtRecord(pUnit->dwClassId) : 0;
    const int nLevel = pMonStatsTxtRecord->wAiParam[0][GAME_GetDifficulty()];

    int nFrame;
    int nFrameCount;
    UNITS_GetShiftedFrameMetrics(pUnit, &nFrame, &nFrameCount);
    if (pUnit && pUnit->dwAnimMode)
    {
        return;
    }
    if (nFrame != 4)
    {
        return;
    }

    if (nLevel == 1)
    {
        MISSILE_SubmitOwnerRequest(pUnit, 0x1AB, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0, 1);
    }
    else if (nLevel >= 2)
    {
        MISSILE_SubmitOwnerRequest(pUnit, 0x1AC, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), 0, 1);
    }
    MISSILE_SubmitOwnerRequest(pUnit, 0x1AA, GetUnitPathX(pUnit), GetUnitPathY(pUnit), 0, 1);
}

// 0x004ADCE0
void __fastcall NPCMENU_StateRequests(D2UnitStrc* pUnit)
{
    int nX = GetUnitPathX(pUnit);
    int nY = GetUnitPathY(pUnit);
    MISSILE_SubmitMissileRequest(pUnit, 0x75, nX, nY, 0, 1);
    MISSILE_SubmitMissileRequest(pUnit, 0x221, nX, nY, 0, 1);
    sub_004B9A00(0x99A, pUnit, 0, 0, 0);
}

// 0x004ADD80
void __fastcall NPCMENU_StateRequestsCallback(D2UnitStrc* pUnit, int nState, int bFlag)
{
    NPCMENU_StateRequests(pUnit);
}

// 0x004ADD90
void __stdcall MONSTER_RunUModCallbacks(D2UnitStrc* pUnit, void* pArgument, int nMode)
{
    unsigned char* pUMods = MONSTERUNIQUE_GetUMods(pUnit);
    if (!pUMods)
    {
        return;
    }

    const int bUnique = MONSTERS_CheckMonTypeFlag(pUnit, 8);
    if (nMode != 4)
    {
        for (int i = 0; i < 9; ++i)
        {
            const int nUMod = pUMods[i];
            UMODCALLBACK pfnCallback = gaUModCallbacks[nUMod].pCallbacks[nMode];
            if (pfnCallback)
            {
                pfnCallback(pUnit, nUMod, bUnique);
            }
        }
    }
    else
    {
        for (int i = 0; i < 9; ++i)
        {
            const int nUMod = pUMods[i];
            UMODCALLBACK pfnCallback = gaUModCallbacks[nUMod].pCallbacks[nMode];
            if (pfnCallback)
            {
                pfnCallback(pArgument, nUMod, bUnique);
            }
        }
    }
}

// 0x004ADE40
void __fastcall MONSTER_RunUModCommandCallbacks(D2UnitStrc* pUnit)
{
    MONSTER_RunUModCallbacks(pUnit, 0, 0);
}

// 0x004ADE50
void __fastcall MONSTER_RunUModUpdateCallbacks(D2UnitStrc* pUnit)
{
    MONSTER_RunUModCallbacks(pUnit, 0, 1);
}

// 0x004ADE60
void __fastcall MONSTER_RunUModFrameCallbacks(D2UnitStrc* pUnit)
{
    MONSTER_RunUModCallbacks(pUnit, 0, 2);
}

// 0x004ADE70
void __fastcall MONSTER_RunUModHitCallbacks(D2UnitStrc* pUnit)
{
    MONSTER_RunUModCallbacks(pUnit, 0, 3);
}

// 0x004ADE80
void __fastcall MONSTER_RunUModMissileCallbacks(D2UnitStrc* pUnit, void* pArg)
{
    if (pUnit && pArg && pUnit->dwUnitType == UNIT_MONSTER)
    {
        MONSTER_RunUModCallbacks(pUnit, pArg, 4);
    }
}

// 0x004ADEA0
void __fastcall MONSTER_GetMonsterName(D2UnitStrc* pUnit, Unicode* wszName, int nLength, unsigned short nNameId)
{
    wszName->wChar = 0;

    const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
    if (nType != 1)
    {
        return;
    }

    D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
    if (!pMonsterData)
    {
        return;
    }

    unsigned char* pUniqueMods = pMonsterData->nMonUmod;
    if (!pUniqueMods)
    {
        return;
    }

    if (MONSTER_IsMinionMonster(pUnit))
    {
        if (nNameId)
        {
            sub_005267E0((unsigned short*)wszName, (const unsigned short*)D2LANG_GetStringFromTblIndex(nNameId));
            Unicode::strcat(wszName, D2LANG_GetStringFromTblIndex(3995));
            Unicode::strcat(wszName, D2LANG_GetStringFromTblIndex(3221));
        }
        else
        {
            sub_005267E0((unsigned short*)wszName, (const unsigned short*)D2LANG_GetStringFromTblIndex(3221));
        }
        return;
    }

    const int nOldFont = D2Win_10127_SetFont(6);
    int nWidth = 0;
    int nCount = 0;
    int nTextLength = 0;
    if (nNameId)
    {
        nCount = 1;
        Unicode::strcat(wszName, D2LANG_GetStringFromTblIndex(nNameId));
        nTextLength = sub_00526800((const unsigned short*)D2LANG_GetStringFromTblIndex(nNameId));
        nWidth = D2Win_10121_GetTextWidth(D2LANG_GetStringFromTblIndex(nNameId));
    }

    switch (pUnit->dwClassId)
    {
    case 704:
    case 704 + 1:
    case 704 + 2:
    case 704 + 3:
    case 704 + 4:
    case 704 + 5:
        return;
    }

    for (int i = 0; i < 9; ++i)
    {
        const int nMod = pUniqueMods[i];
        if (!gwUniqueModNameIds[nMod])
        {
            continue;
        }

        if (nCount && nTextLength + 1 < nLength - 1)
        {
            Unicode::strcat(wszName, gwszNameSeparator);
            ++nTextLength;
            nWidth += D2Win_10121_GetTextWidth(gwszNameSeparator);
        }

        if (nTextLength < nLength - 1)
        {
            const Unicode* wszMod = D2LANG_GetStringFromTblIndex(gwUniqueModNameIds[nMod]);
            if (sub_00526800((const unsigned short*)wszMod) + nTextLength < nLength - 1)
            {
                nTextLength += sub_00526800((const unsigned short*)wszMod);
                nWidth += D2Win_10121_GetTextWidth(wszMod);
                Unicode::strcat(wszName, wszMod);
                ++nCount;
            }
        }

        if (nWidth > 480)
        {
            D2Win_10127_SetFont(nOldFont);
            return;
        }
    }

    D2Win_10127_SetFont(nOldFont);
}

// 0x004AE080
extern "C" int __fastcall NPCMENU_GetMonsterTypeFlags(D2UnitStrc* pUnit, unsigned short nMask)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
        if (pMonsterData)
            return pMonsterData->nClientFlags & nMask;
    }
    return 0;
}



#include "gen/data/Source/D2Client/Unknown_004ADD90.inc"
