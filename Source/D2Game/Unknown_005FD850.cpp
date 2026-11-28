#include "D2GameEvents.h"
#include "D2ObjectIds.h"
#include "D2ItemTypes.h"
#include "D2StateIds.h"
#include "D2MonsterIds.h"
#include "D2SkillIds.h"
#include "D2LevelIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2GameRecords.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameStrc.h"
#include "D2GameTypes.h"
#include "D2Txt.h"
#include "D2TxtTables.h"
#include "D2ItemsWorld.h"
#include "D2UnitData.h"
#include "D2LevelTxt.h"
#include "D2AnimData.h"
#include "D2Path.h"
#include "D2ItemModes.h"
#include "D2Records.h"
#include "D2GameAux.h"
#include "D2CommonApi.h"

struct D2ItemsTxt;

struct D2MonStatsTxt;

struct D2BooksTxt;


struct D2CurseStrc;

struct D2SkillsTxt;


union D2SeedStrc;

struct D2UnitStrc;

struct D2GameStrc;

struct D2DataTablesStrc;

struct D2DamageStrc;

struct D2AnimSeqTxt;

struct D2ItemStatCostTxt;

extern D2pSpellTblStrc gaPSpellTable[]; // 0x00741790

void __fastcall D2GAME_PACKETS_SendPacketSize06(D2ClientStrc* pClient, unsigned char nHeader, int dwUnitType, int dwUnitId); // 0x0053B3D0

typedef void(__fastcall* StatListRemoveCallback)(D2UnitStrc*, int, D2StatListStrc*);


extern D2DataTablesStrc* sgptDataTables; // 0x00744304


D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540

#include "D2GameFuncs.h"
#include "D2CommonApi2.h"


enum D2C_Y09SkillConstants
{
    SKILLSFLAGINDEX_AURA = 5,
    SKILLSFLAGINDEX_IMMEDIATE = 15,
};

extern unsigned int gdwBitMasks[]; // 0x006CE268

int __fastcall SKILLS_ExecuteSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bApplyCosts, int bSkipSkillCheck, int bItemEffect); // 0x0056F7F0

extern "C" const char gszEmptyAssertText; // 0x006CC837


typedef void (__fastcall* RemoveCallback)(D2UnitStrc*,int,D2StatListStrc*);

#define UNIT_ITEM 4

#define UNIT_INVALID 6

struct D2MonStats2Txt;

enum D2C_J10SkillItemConstants
{
    MONTYPEFLAG_UNIQUE_CHAMPION = 12,
    DAMAGERESULTFLAG_GETHIT = 4,
    DAMAGEHITFLAG_0x20 = 0x20,
    SKILLSFLAGINDEX_ITEMTGTDO = 29,
};

void __fastcall D2GAME_PACKETS_SendPacketSize06(D2ClientStrc* client,unsigned char code); // 0x0053B3D0

struct D2AiControlStrc;

struct D2ActiveRoomStrc;

struct D2DynamicPathStrc;

struct D2SkillStrc;

struct D2StatListStrc;


enum D2C_G4Constants
{
    AISPECIALSTATE_NONE = 0,
    AISPECIALSTATE_DIMVISION = 10,
    AISPECIALSTATE_TERROR = 11,
    AISPECIALSTATE_TAUNT = 12,
    UNITFLAG_SKSRVDOFUNC = 0x40,
    UNITFLAGEX_TELEPORTED = 0x10000,
    UNITEVENTFLAG_IN_CALLBACK = 1,
    UNITEVENTFLAG_SHOULD_BE_FREED = 2,
    ITEMDROPFLAG_STAFFMODUSEILVL = 0x20,
    COLLIDE_MASK_PLAYER_FLYING = 0x804,
};



struct D2ModeChangeStrc;

enum D2C_SkillItemConstants
{
    UNITEVENT_13 = 13,
};

struct D2AiCmdStrc;

struct D2StaticPathStrc;


struct D2MagicAffixTxt;


struct D2RareAffixIndexAndPtrStrc;

struct D2SetItemsTxt;


inline D2SkillsTxt* DATATBLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}


int __stdcall PATH_GetFootprintCollisionMask(D2DynamicPathStrc* pPath);                                     // 0x00648C10

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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

#define SKILLITEM_ROLL_SEED(pSeed, lSeed) \
    (lSeed = (pSeed)->nHighSeed + 0x6AC690C5i64 * (pSeed)->nLowSeed, \
     (pSeed)->nHighSeed = (unsigned int)(lSeed >> 32), \
     (pSeed)->nLowSeed = (unsigned int)lSeed, \
     (unsigned int)lSeed)

void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0

// 0x005FD850
int __fastcall SKILLITEM_FindTargetPosition(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return 0;
    }

    const int nUnitX = CLIENTS_GetUnitXInline(pUnit);
    const int nUnitY = CLIENTS_GetUnitYInline(pUnit);
    D2SeedStrc* pSeed = &pUnit->pSeed;
    if (!pSeed)
    {
        return 0;
    }

    const int nCollisionPattern = PATH_GetUnitCollisionPattern(pUnit);
    const int nMask = PATH_GetFootprintCollisionMask(pUnit->pDynamicPath);
    for (int i = 0; i < 10; ++i)
    {
        unsigned __int64 lSeed;
        const int nX = nUnitX + SKILLITEM_ROLL_SEED(pSeed, lSeed) % 40 - 20;
        const int nY = nUnitY + SKILLITEM_ROLL_SEED(pSeed, lSeed) % 40 - 20;
        if (!COLLISION_CheckMaskWithPattern(pRoom, nX, nY, nCollisionPattern, nMask))
        {
            D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, nX, nY);
            return 1;
        }
    }

    return 0;
}

// 0x005FD9C0
int __fastcall SKILLITEM_FindCorpseTarget(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int* pUnitType, int* pUnitGUID)
{
    D2UnitStrc* pCurrentTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    D2UnitStrc* pTarget = SKILLS_FindCorpseNearTarget(pUnit, pCurrentTarget, nSkillId, nSkillLevel);
    if (!pTarget)
    {
        return 0;
    }

    UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
    if (pUnitType)
    {
        *pUnitType = pTarget->dwUnitType;
        *pUnitGUID = pTarget->dwUnitId;
    }
    return 1;
}

// 0x005FDA10
int __fastcall SKILLITEM_TargetLastAttacker(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnused1, int nUnused2, int* pTargetType, int* pTargetGUID)
{
    if (!SUNIT_GetTargetUnit(pGame, pUnit))
    {
        D2UnitStrc* pTarget = SUNIT_GetLastAttacker(pGame, pUnit);
        UNITS_SetTargetUnitForDynamicUnit(pUnit, pTarget);
        if (pTargetType)
        {
            int nTargetType = 6;
            if (pTarget)
            {
                nTargetType = pTarget->dwUnitType;
            }
            *pTargetType = nTargetType;
            unsigned int nTargetGUID;
            if (!pTarget)
            {
                nTargetGUID = 0xFFFFFFFFu;
            }
            else
            {
                nTargetGUID = pTarget->dwUnitId;
            }
            *pTargetGUID = nTargetGUID;
        }
    }
    return 1;
}

#define INVALID_UNIT 6

struct D2InventoryStrc;


int __fastcall SKILLITEM_FindTargetPosition(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel); // 0x005FD850

// 0x005FDA80
int __fastcall SKILLITEM_HandleItemEffectSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, D2UnitStrc* pTargetUnit, int nX, int nY, int* pUnitType, int* pUnitGUID, int* pX, int* pY, int nItemEffectParam)
{
    D2SkillsTxt* pSkillsTxtRecord = DATATBLS_GetSkillsTxtRecord(nSkillId);
    if (!nSkillId) return 0;
    if (!pSkillsTxtRecord->wItemEffect) return 0;
    D2UnitStrc* pOldTarget = SUNIT_GetTargetUnit(pGame, pUnit);
    int nOldX = D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath);
    int nOldY = D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath);
    int bOldFlag = (pUnit->dwFlags >> 6) & 1;
    if (pTargetUnit) UNITS_SetTargetUnitForDynamicUnit(pUnit, pTargetUnit);
    else D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, nX, nY);
    if (pUnitType) { *pUnitType = INVALID_UNIT; *pUnitGUID = -1; }
    if (pX) { *pX = 0; *pY = 0; }
    int nResult = 0;
    switch (pSkillsTxtRecord->nItemTarget) {
    case 1:
        UNITS_SetTargetUnitForDynamicUnit(pUnit, pUnit);
        if (pUnitType) { *pUnitType = pUnit->dwUnitType; *pUnitGUID = pUnit->dwUnitId; }
        break;
    case 2:
        if (!SKILLITEM_FindTargetPosition(pGame, pUnit, nSkillId, nSkillLevel)) goto restore;
        if (pX) *pX = D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath);
        if (pY) *pY = D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath);
        break;
    case 3:
        if (!SKILLITEM_FindCorpseTarget(pGame, pUnit, nSkillId, nSkillLevel, pUnitType, pUnitGUID)) goto restore;
        break;
    case 4:
        if (!SKILLITEM_TargetLastAttacker(pGame, pUnit, nSkillId, nSkillLevel, pUnitType, pUnitGUID)) goto restore;
        break;
    }
    if ((pSkillsTxtRecord->nFlags[4] & gdwBitMasks[1]) && !SKILLS_StartSkill(pGame, pUnit, nSkillId, nSkillLevel, 1)) goto restore;
    nResult = SKILLS_ExecuteSkill(pGame, pUnit, nSkillId, nSkillLevel, 0, 1, nItemEffectParam);
restore:
    if (pOldTarget) UNITS_SetTargetUnitForDynamicUnit(pUnit, pOldTarget);
    else D2COMMON_10170_PathSetTargetPos(pUnit->pDynamicPath, nOldX, nOldY);
    if (bOldFlag) pUnit->dwFlags |= 0x40;
    else pUnit->dwFlags &= ~0x40;
    return nResult;
}

// 0x005FDCA0
int __fastcall SKILLITEM_CastSkillOnTarget(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, D2UnitStrc* pTargetUnit, int nItemEffectParam)
{
    if (!pUnit || !pTargetUnit)
    {
        return 0;
    }

    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return 0;
    }

    if (STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
    {
        return 0;
    }

    int nTargetUnitType = UNIT_INVALID;
    int nTargetUnitGUID = -1;
    int nTargetX;
    int nTargetY;
    if (!SKILLITEM_HandleItemEffectSkill(pGame, pUnit, nSkillId, nSkillLevel, pTargetUnit, 0, 0, &nTargetUnitType, &nTargetUnitGUID, &nTargetX, &nTargetY, nItemEffectParam))
    {
        return 0;
    }

    int nUnitType;
    int nUnitGUID;
    if (nTargetUnitType == UNIT_INVALID)
    {
        nUnitType = pTargetUnit->dwUnitType;
        nUnitGUID = pTargetUnit->dwUnitId;
    }
    else
    {
        nUnitType = nTargetUnitType;
        nUnitGUID = nTargetUnitGUID;
    }

    SUNITMSG_QueueItemSkillOnUnit(pUnit, nSkillId, nSkillLevel, nUnitType, nUnitGUID, nItemEffectParam);
    return 1;
}

void __fastcall SUNITMSG_QueueItemSkillOnPosition(D2UnitStrc* pUnit, int nSkillId, unsigned char nSkillLevel, short nX, short nY, unsigned char nSkillParam); // 0x00571840

// 0x005FDD60
int __fastcall SKILLITEM_CastSkillOnPosition(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int nX, int nY, int nItemEffectParam)
{
    if (!pUnit)
        return 0;
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
    if (!pGame)
    {
        return 0;
    }
    if (STATES_CheckState(pUnit, STATE_UNINTERRUPTABLE))
    {
        return 0;
    }
    int nUnitType;
    int nUnitGUID;
    int nNewX = 0;
    int nNewY = 0;
    if (!SKILLITEM_HandleItemEffectSkill(pGame, pUnit, nSkillId, nSkillLevel, 0, nX, nY, &nUnitType, &nUnitGUID, &nNewX, &nNewY, nItemEffectParam))
        return 0;
    int nFinalX = nNewX;
    int nFinalY;
    if (!nFinalX)
    {
        nFinalX = nX;
        nFinalY = nY;
    }
    else
    {
        nFinalY = nNewY;
    }
    SUNITMSG_QueueItemSkillOnPosition(pUnit, nSkillId, nSkillLevel, nFinalX, nFinalY, nItemEffectParam);
    return 1;
}


