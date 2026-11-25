#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2TxtTables.h"
#include "D2Packets.h"
#include "D2LanguageNames.h"
// build: symbol _gaszLanguageNames 0x0073BEE0

typedef void(__fastcall* MISSILEINITFUNC)(D2UnitStrc* pMissile, int nInitArg);

extern "C" D2DataTablesStrc* sgptDataTables;                                                                // 0x00744304

extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268

extern D2MissileUnitFindTableStrc gtMissileCollisionModes[];                                                // 0x0073C720

D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId);                                    // 0x0046ACE0

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY);              // 0x00463740

void __fastcall PLAYER_ApplyWeaponStatsForSkill(D2UnitStrc* pUnit, int a2);                                 // 0x00535D10

void __fastcall PLAYER_RestoreWeaponStats(D2UnitStrc* pUnit, int a2);                                       // 0x00535E20

D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char a7, int nMode, unsigned int a9); // 0x00555230

void __fastcall MONSTERUNIQUE_OwnerMissileHook(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pMissile); // 0x005A43B0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0

void __stdcall UNITS_StoreOwner(D2UnitStrc* pUnit, D2UnitStrc* pOwner);                                     // 0x00621CE0

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer);                        // 0x00625480

int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStat, int nLayer);           // 0x00625500

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState);              // 0x006256B0

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer);         // 0x00625D00

void __stdcall STATLIST_AllocStatListEx(D2UnitStrc* pUnit, int nFlags, void* pCallback, D2GameStrc* pGame); // 0x00626D40

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0

int __stdcall DRLG_GetDistanceToXY(D2UnitStrc* pUnit, int nX, int nY);                                           // 0x006417F0

void __stdcall PATH_SetVelocity(D2DynamicPathStrc* pDynamicPath, int nVelocity, const char* szFile, int nLine); // 0x00648690

void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY);                   // 0x00648AD0

void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nCollisionMask);         // 0x00648C30

void __stdcall PATH_SetMoveTestCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask);                   // 0x00648CE0

int __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown);               // 0x00649970

void __stdcall MISSILE_SetTotalFrames(D2UnitStrc* pMissile, int nTotalFrames);                              // 0x0064A2B0

void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame);                            // 0x0064A330

void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed);                                 // 0x00650E40

void __stdcall MISSILE_FreeMissileData(D2UnitStrc* pMissile); // 0x0064A150

void __fastcall EVENT_FreeUnitTimers(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540EE0

#define UNIT_MONSTER 1

struct D2MissilesTxt;

struct D2GSPacketSrv73;

struct D2MonUModTxt;

struct D2MonsterDataStrc;

union D2SeedStrc;

#pragma pack(push, 1)


#pragma pack(pop)

extern const unsigned char gnMissileFlag_006CE27C; // 0x006CE27C

D2UnitStrc* __fastcall SUNIT_GetOwner(D2GameStrc*, D2UnitStrc*); // 0x00552FD0

int __stdcall sub_0064A3E0_GetMissileId(D2UnitStrc*); // 0x0064A3E0

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc*); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc*); // 0x00648A10

int __stdcall sub_0064A380_GetRemainingFrames(D2UnitStrc*); // 0x0064A380

int __stdcall MISSILE_GetLevel(D2UnitStrc*); // 0x0064A210

void __fastcall D2GAME_PACKETS_SendPacket0x73(D2ClientStrc*, D2GSPacketSrv73*); // 0x0053DA10




static void __stdcall MISSILES_RollMissilePierce(D2UnitStrc* pMissile, D2UnitStrc* pOwner); // 0x0059F940

static inline unsigned int MISSILES_RollPierceSeed_Inline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline int GetUnitType(D2UnitStrc* pUnit)
{
    return !pUnit ? 6 : pUnit->dwUnitType;
}

D2UnitStrc* __fastcall SUNIT_GetNextUnitFromList(D2UnitStrc* pUnit); // 0x00552DB0

void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600

// 0x0059F840
void __fastcall MISSILES_RemoveAll(D2GameStrc* pGame)
{
    for (int i = 0; i < 128; ++i)
    {
        D2UnitStrc* pUnit = pGame->pUnitList[4][i];
        while (pUnit)
        {
            D2UnitStrc* pCurrent = pUnit;
            pUnit = SUNIT_GetNextUnitFromList(pUnit);
            SUNIT_RemoveUnit(pGame, pCurrent);
        }
    }
}

#define UNITFLAG_TARGETABLE 0x00000002

#define UNITFLAG_ISVALIDTARGET 0x00000008

void __stdcall MISSILE_AllocMissileData(D2UnitStrc* pMissile); // 0x0064A100

void __fastcall D2GAME_DeleteTimersOnUnit_6FC34A30(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540F30

// 0x0059F8A0
void __fastcall MISSILES_Initialize(D2GameStrc* pGame, D2UnitStrc* pMissile, int nUnitGUID)
{
    if (!pMissile)
    {
        return;
    }

    MISSILE_AllocMissileData(pMissile);
    pMissile->dwUnitId = nUnitGUID;
    pMissile->dwFlags &= ~(UNITFLAG_TARGETABLE | UNITFLAG_ISVALIDTARGET);
    D2GAME_DeleteTimersOnUnit_6FC34A30(pGame, pMissile);
    sub_6FC35570(pGame, pMissile, 0, 0, 0);
}

// 0x0059F8E0
void __fastcall MISSILES_Free(D2GameStrc* pGame, D2UnitStrc* pMissile)
{
    if (!pMissile)
    {
        return;
    }

    MISSILE_FreeMissileData(pMissile);
    EVENT_FreeUnitTimers(pGame, pMissile);
}

// 0x0059F900
static void __stdcall MISSILES_ApplyMissileDamage(D2UnitStrc* pOrigin, D2UnitStrc* pMissile, int nLevel, D2UnitStrc* pOwner)
{
    D2MissileDamageDataStrc tDamage;

    PLAYER_ApplyWeaponStatsForSkill(pOwner, 0);
    MISSILE_CalculateDamageData(&tDamage, pOwner, pOrigin, pMissile, nLevel);
    MISSILE_SetDamageStats(pOwner, pMissile, &tDamage, nLevel);
    PLAYER_RestoreWeaponStats(pOwner, 0);
}

static void __stdcall MISSILES_ApplyMissileDamage(D2UnitStrc* pOrigin, D2UnitStrc* pMissile, D2UnitStrc* pOwner, int nLevel) // 0x0059F900
{
    D2MissileDamageDataStrc tDamage;

    PLAYER_ApplyWeaponStatsForSkill(pOwner, 0);
    MISSILE_CalculateDamageData(&tDamage, pOwner, pOrigin, pMissile, nLevel);
    MISSILE_SetDamageStats(pOwner, pMissile, &tDamage, nLevel);
    PLAYER_RestoreWeaponStats(pOwner, 0);
}

// 0x0059F940
static void __stdcall MISSILES_RollMissilePierce(D2UnitStrc* pMissile, D2UnitStrc* pOwner)
{
    if (!pOwner || !pMissile || pMissile->dwUnitType != UNIT_MISSILE)
    {
        return;
    }

    if (pOwner->dwUnitType != UNIT_PLAYER && pOwner->dwUnitType != UNIT_MONSTER)
    {
        return;
    }

    D2MissilesTxt* pMissilesTxtRecord = sub_0046ACE0(pMissile->dwClassId);
    if (!MISSILE_FLAGBIT(pMissilesTxtRecord, 2))
    {
        return;
    }

    const int nPierceValue = STATLIST_UnitGetStatValue(pOwner, STAT_SKILL_PIERCE, 0) + STATLIST_UnitGetItemStatOrSkillStatValue(pOwner, STAT_ITEM_PIERCE, 0);
    if (!nPierceValue)
    {
        return;
    }

    D2SeedStrc tSeed;
    SEED_InitLowSeed(&tSeed, STATLIST_GetUnitBaseStat(pOwner, STAT_PIERCE_IDX, 0));

    int nPierceIndex = 0;
    for (;;)
    {
        const int nRoll = nPierceIndex < 4 ? (int)(MISSILES_RollPierceSeed_Inline(&tSeed) % 100) : nPierceValue;
        if (nRoll >= nPierceValue)
        {
            break;
        }

        ++nPierceIndex;
    }

    STATLIST_SetUnitStat(pMissile, STAT_PIERCE_IDX, nPierceIndex, 0);
}

// 0x0059FA30
D2UnitStrc* __fastcall MISSILES_CreateMissileFromParams(D2GameStrc* pGame, D2MissileStrc* pMissileParams)
{
    int nY;
    int nX;

    if (!pMissileParams->pOwner)
    {
        return 0;
    }

    if (pMissileParams->nMissile < 0 || pMissileParams->nMissile >= sgptDataTables->nMissilesTxtRecordCount)
    {
        return 0;
    }

    if (GetUnitType(pMissileParams->pOwner) != 0 && GetUnitType(pMissileParams->pOwner) != 1)
    {
        return 0;
    }

    D2MissilesTxt* pMissilesTxtRecord = sub_0046ACE0(pMissileParams->nMissile);
    if (!pMissilesTxtRecord)
    {
        return 0;
    }

    if (pMissileParams->dwFlags & 1)
    {
        nX = pMissileParams->nX;
        nY = pMissileParams->nY;
    }
    else
    {
        if (!pMissileParams->pOrigin)
        {
            return 0;
        }

        nX = CLIENTS_GetUnitX(pMissileParams->pOrigin);
        nY = CLIENTS_GetUnitY(pMissileParams->pOrigin);
    }

    D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pMissileParams->pOwner), nX, nY);
    if (!pRoom)
    {
        return 0;
    }

    int nTargetX;
    int nTargetY;
    if (pMissileParams->dwFlags & 2)
    {
        nTargetX = pMissileParams->nTargetX + nX;
        nTargetY = pMissileParams->nTargetY + nY;
    }
    else if (pMissileParams->dwFlags & 0x20)
    {
        nTargetX = pMissileParams->nTargetX;
        nTargetY = pMissileParams->nTargetY;
    }
    else
    {
        nTargetX = nX;
        nTargetY = nY;
    }

    int nVelocity;
    if (pMissileParams->dwFlags & 4)
    {
        if (pMissileParams->dwFlags & 0x10)
        {
            nVelocity = pMissileParams->nVelocity;
        }
        else
        {
            nVelocity = pMissileParams->nVelocity << 8;
        }
    }
    else
    {
        nVelocity = (pMissilesTxtRecord->nVel + pMissileParams->nSkillLevel * pMissilesTxtRecord->nVelLev / 8) << 8;
    }

    if (MISSILE_FLAGBIT(pMissilesTxtRecord, 3) && STATES_CheckState(pMissileParams->pOwner, STATE_SLOWMISSILES))
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pMissileParams->pOwner, STATE_SLOWMISSILES);
        if (pStatList)
        {
            nVelocity = STATLIST_GetStatValue(pStatList, STAT_SKILL_HANDOFATHENA, 0) * nVelocity / 100;
        }
    }

    if (nVelocity)
    {
        nVelocity = 75 * nVelocity / 100;
    }

    D2UnitStrc* pTarget = pMissileParams->pTarget;
    if (nVelocity)
    {
        if (!pTarget)
        {
            if (nTargetX == nX && nTargetY == nY)
            {
                ++nTargetX;
                ++nTargetY;
            }
        }
        else if (pTarget != pMissileParams->pOwner)
        {
            const int nOwnerX = CLIENTS_GetUnitX(pMissileParams->pOwner);
            if (CLIENTS_GetUnitX(pTarget) == nOwnerX
                && CLIENTS_GetUnitY(pTarget) == CLIENTS_GetUnitY(pMissileParams->pOwner))
            {
                pTarget = 0;
                ++nTargetX;
                ++nTargetY;
            }
        }

        int nDestX = nTargetX;
        int nDestY = nTargetY;
        if (pTarget)
        {
            nDestX = CLIENTS_GetUnitX(pTarget);
            nDestY = CLIENTS_GetUnitY(pTarget);
        }

        int nXDiff = nDestX - nX;
        if (nXDiff < 0)
        {
            nXDiff = -nXDiff;
        }

        if (nXDiff >= 100)
        {
            return 0;
        }

        int nYDiff = nDestY - nY;
        if (nYDiff < 0)
        {
            nYDiff = -nYDiff;
        }

        if (nYDiff >= 100)
        {
            return 0;
        }
    }

    D2UnitStrc* pMissile = SUNIT_AllocUnitData(3, pMissileParams->nMissile, nX, nY, pGame, pRoom, 1, pMissilesTxtRecord->nCollideType, 0);
    if (!pMissile)
    {
        return 0;
    }

    int nRange;
    if (pMissileParams->dwFlags & 0x8000)
    {
        nRange = pMissileParams->nRange;
    }
    else
    {
        nRange = pMissilesTxtRecord->wRange + pMissileParams->nSkillLevel * pMissilesTxtRecord->wLevRange;
        if ((pMissileParams->dwFlags & 8) && pMissilesTxtRecord->nSubLoop)
        {
            nRange += pMissileParams->nLoops * (pMissilesTxtRecord->nSubStop - pMissilesTxtRecord->nSubStart);
        }
    }

    if (pMissileParams->dwFlags & 0x200)
    {
        nRange -= pMissileParams->nFrame;
        pMissile->nSeqCurrentFramePrecise = pMissileParams->nFrame << 8;
    }

    MISSILE_SetTotalFrames(pMissile, nRange);
    MISSILE_SetCurrentFrame(pMissile, nRange);

    if (pMissileParams->dwFlags & 0x800)
    {
        nRange -= pMissileParams->nActivateFrame;
    }
    else
    {
        nRange -= pMissilesTxtRecord->nActivate;
    }
    MISSILE_SetActivateFrame(pMissile, nRange);

    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    if (!pPath)
    {
        return 0;
    }

// build: symbol ?gszMissilesSourceFile@* 0x006E2150
    PATH_SetVelocity(pPath, 0, gszMissilesSourceFile, 0x18E);

    if (pTarget)
    {
        PATH_SetTargetUnit(pPath, pTarget);
    }
    else
    {
        D2COMMON_10170_PathSetTargetPos(pPath, nTargetX, nTargetY);
    }

    if (pMissilesTxtRecord->nCollision)
    {
        PATH_SetFootprintCollisionMask(pPath, 0x40);
    }
    else
    {
        PATH_SetFootprintCollisionMask(pPath, 0);
    }
    PATH_SetMoveTestCollisionMask(pPath, gtMissileCollisionModes[pMissilesTxtRecord->nCollideType].nCollisionMask);

    if (MISSILE_FLAGBIT(pMissilesTxtRecord, 4))
    {
        pMissile->dwFlags |= 4;
    }

    if (nVelocity)
    {
        PATH_SetVelocity(pPath, nVelocity, gszMissilesSourceFile, 0x1AA);
        D2Common_10142(pPath, pMissile, 0);
    }

    MISSILE_SetOwner(pMissile, pMissileParams->pOwner);
    PATH_SetAcceleration(pPath, pMissilesTxtRecord->wAccel);
    PATH_SetMaxVelocity(pPath, pMissilesTxtRecord->nMaxVel << 8);

    if (pMissileParams->dwFlags & 0x400)
    {
        int nDistance = DRLG_GetDistanceToXY(pMissile, nTargetX, nTargetY);
        if (!nDistance)
        {
            nDistance = 1;
        }

        const unsigned int nStep = 16 * nVelocity;
        unsigned int nCurrentFrame = 0;
        if (nStep)
        {
            nCurrentFrame = (unsigned int)(nDistance << 16) / nStep;
        }

        MISSILE_SetCurrentFrame(pMissile, nCurrentFrame);
    }

    STATLIST_AllocStatListEx(pMissile, 0, 0, 0);

    if (pMissileParams->pInitFunc)
    {
        pMissileParams->pInitFunc(pMissile, pMissileParams->nInitArg);
    }

    MISSILE_SetSkill(pMissile, pMissileParams->nSkill);
    MISSILE_SetLevel(pMissile, pMissileParams->nSkillLevel);

    MISSILES_ApplyMissileDamage(pMissileParams->pOrigin, pMissile, pMissileParams->pOwner, pMissileParams->nSkillLevel);

    UNITS_StoreOwner(pMissile, pMissileParams->pOwner);
    pMissile->dwFlags &= ~8;

    MISSILES_RollMissilePierce(pMissile, pMissileParams->pOwner);

    if (pMissileParams->dwFlags & 0x1000)
    {
        STATLIST_SetUnitStat(pMissile, STAT_TOHIT, pMissileParams->nAttBonus, 0);
    }

    if (pMissileParams->dwFlags & 0x10000)
    {
        MISSILE_SetFlags(pMissile, MISSILE_GetFlags(pMissile) | 2);
    }

    MONSTERUNIQUE_OwnerMissileHook(pGame, pMissileParams->pOwner, pMissile);
    STATLIST_SetUnitStat(pMissile, STAT_DAMAGE_FRAMERATE, pMissilesTxtRecord->nMissileStatValue, 0);
    return pMissile;
}

__forceinline D2MissilesTxt* GetMissilesTxtRecord(int nId)
{
    if (nId >= 0 && nId < sgptDataTables->nMissilesTxtRecordCount)
        return &sgptDataTables->pMissilesTxt[nId];
    return 0;
}

// 0x0059FEE0
void __fastcall MISSILES_SyncToClient(D2ClientStrc* pClient, D2GameStrc* pGame, D2UnitStrc* pMissile, int bSendPath)
{
    if (!pMissile || pMissile->dwUnitType != UNIT_MISSILE)
        return;
    D2UnitStrc* pOwner = SUNIT_GetOwner(pGame, pMissile);
    if (!pOwner)
        return;
    D2MissilesTxt* pMissilesTxt = GetMissilesTxtRecord(pMissile->dwClassId);
    if (!pMissilesTxt || !(pMissilesTxt->nMissileFlags[0] & gnMissileFlag_006CE27C))
        return;
    D2GSPacketSrv73 packet = {};
    packet.nHeader = 0x73;
    packet.nMissileId = sub_0064A3E0_GetMissileId(pMissile);
    packet.nX = CLIENTS_GetUnitX(pMissile);
    packet.nY = CLIENTS_GetUnitY(pMissile);
    if (bSendPath)
    {
        packet.nFirstX = D2COMMON_10175_PathGetFirstPointX(pMissile->pDynamicPath);
        packet.nFirstY = D2COMMON_10176_PathGetFirstPointY(pMissile->pDynamicPath);
    }
    packet.nCurrentFrame = sub_0064A380_GetRemainingFrames(pMissile);
    const int nOwnerType = pOwner ? pOwner->dwUnitType : UNIT_INVALID;
    packet.nUnitType = nOwnerType;
    packet.nUnitGUID = pOwner->dwUnitId;
    packet.nLevel = MISSILE_GetLevel(pMissile);
    packet.nPierce = STATLIST_UnitGetStatValue(pMissile, STAT_PIERCE_IDX, 0);
    D2GAME_PACKETS_SendPacket0x73(pClient, &packet);
}

// 0x0059FFF0
unsigned short __fastcall MISSILES_ToWord(unsigned short nValue)
{
    return nValue;
}

// 0x005A0000
extern "C" D2MonLvlTxt* __fastcall MISSILES_GetMonLvlTxtRecord(int nLevel)
{
    if (nLevel >= 0 && nLevel < sgptDataTables->nMonLvlTxtRecordCount)
    {
        return &sgptDataTables->pMonLvlTxt[nLevel];
    }

    return 0;
}

#include "gen/data/Source/D2Game/MISSILES/Missiles.inc"
