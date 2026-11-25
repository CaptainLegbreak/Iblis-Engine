#pragma once
// Game-logic records passed between the server's systems: damage, missile creation parameters, mode changes,
// AI control and commands, object and quest event arguments.

#include "D2Check.h"
#include "D2SysTypes.h"

struct D2UnitStrc;
struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2MonStatsTxt;
struct D2MonStats2Txt;
struct D2MinionListStrc;
struct D2MapAIStrc;
struct D2AiCmdStrc;
struct D2AiControlStrc;
struct D2TextHeaderStrc;
struct D2ObjectControlStrc;
struct D2ObjectsTxt;
struct D2PartyNodeStrc;

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArg);

struct D2DamageStrc
{
    unsigned int dwHitFlags; // 0x00
    unsigned short wResultFlags; // 0x04
    unsigned short wExtra; // 0x06
    int dwPhysDamage; // 0x08
    int dwEnDmgPct; // 0x0C
    int dwFireDamage; // 0x10
    int dwBurnDamage; // 0x14
    int dwBurnLen; // 0x18
    int dwLtngDamage; // 0x1C
    int dwMagDamage; // 0x20
    int dwColdDamage; // 0x24
    int dwPoisDamage; // 0x28
    int dwPoisLen; // 0x2C
    int dwColdLen; // 0x30
    int dwFrzLen; // 0x34
    int dwLifeLeech; // 0x38
    int dwManaLeech; // 0x3C
    int dwStamLeech; // 0x40
    int dwStunLen; // 0x44
    int dwAbsLife; // 0x48
    int dwDmgTotal; // 0x4C
    int unk0x50; // 0x50
    int dwPiercePct; // 0x54
    int dwDamageRate; // 0x58
    int unk0x5C; // 0x5C
    unsigned int dwHitClass; // 0x60
    unsigned char nHitClassActiveSet; // 0x64
    signed char nConvType; // 0x65
    unsigned short unk0x66; // 0x66
    int dwConvPct; // 0x68
    int nOverlay; // 0x6C
};

struct D2MissileStrc
{
    unsigned int dwFlags; // 0x00
    D2UnitStrc* pOwner; // 0x04
    D2UnitStrc* pOrigin; // 0x08
    D2UnitStrc* pTarget; // 0x0C
    int nMissile; // 0x10
    int nX; // 0x14
    int nY; // 0x18
    int nTargetX; // 0x1C
    int nTargetY; // 0x20
    int nGfxArg; // 0x24
    int nVelocity; // 0x28
    int nSkill; // 0x2C
    int nSkillLevel; // 0x30
    int nLoops; // 0x34
    unsigned int unk0x38; // 0x38
    unsigned int unk0x3C; // 0x3C
    int nFrame; // 0x40
    int nActivateFrame; // 0x44
    int nAttBonus; // 0x48
    int nRange; // 0x4C
    int nLightRadius; // 0x50
    MissileInitFunc pInitFunc; // 0x54
    int nInitArg; // 0x58
};

struct D2ModeChangeStrc
{
    int nMode; // 0x00
    D2UnitStrc* pUnit; // 0x04
    D2UnitStrc* pTargetUnit; // 0x08
    int nX; // 0x0C
    int nY; // 0x10
    unsigned char nDirection; // 0x14
    unsigned char nEventFlag; // 0x15
    unsigned short unk0x16; // 0x16
    int nVelocityPercent; // 0x18
    unsigned char nNewDist; // 0x1C
    unsigned char unk0x1D; // 0x1D
    unsigned short unk0x1E; // 0x1E
};

struct D2AiCmdStrc
{
    D2AiCmdStrc* pNextCmd; // 0x00
    D2AiCmdStrc* pPrevCmd; // 0x04
    int nCmdParam[5]; // 0x08
};

struct D2AiControlStrc
{
    int nAiSpecialState; // 0x00
    void* pAiParamFn; // 0x04
    unsigned short nAiFlags; // 0x08
    unsigned short unk0x0A; // 0x0A
    int dwOwnerGUID; // 0x0C
    unsigned int dwOwnerType; // 0x10
    int dwAiParam[3]; // 0x14
    D2AiCmdStrc* pCurrentCmd; // 0x20
    D2AiCmdStrc* pLastCmd; // 0x24
    D2GameStrc* pGame; // 0x28
    int dwOwnerGUIDEx; // 0x2C
    int dwOwnerTypeEx; // 0x30
    D2MinionListStrc* pMinionList; // 0x34
    D2MapAIStrc* pMapAi; // 0x38
    int nMinionSpawnClassId; // 0x3C
};

struct D2AiTickParamStrc
{
    D2AiControlStrc* pAiControl; // 0x00
    int unk0x04; // 0x04
    D2UnitStrc* pTarget; // 0x08
    int unk0x0C; // 0x0C
    int unk0x10; // 0x10
    int nTargetDistance; // 0x14
    int bCombat; // 0x18
    D2MonStatsTxt* pMonstatsTxt; // 0x1C
    D2MonStats2Txt* pMonstats2Txt; // 0x20
};

struct D2ObjInitFnStrc
{
    D2GameStrc* pGame; // 0x00
    D2UnitStrc* pObject; // 0x04
    D2ActiveRoomStrc* pRoom; // 0x08
    D2ObjectControlStrc* pObjectregion; // 0x0C
    D2ObjectsTxt* pObjectTxt; // 0x10
    int nX; // 0x14
    int nY; // 0x18
};

struct D2QuestArgStrc
{
    D2GameStrc* pGame; // 0x00
    int nEvent; // 0x04
    D2UnitStrc* pTarget; // 0x08
    D2UnitStrc* pPlayer; // 0x0C
    unsigned int unk0x10; // 0x10
    union
    {
        int nOldLevel; // 0x14
        unsigned short nNPCNo; // 0x14
        D2TextHeaderStrc* pTextControl; // 0x14
    };
    union
    {
        int nNewLevel; // 0x18
        unsigned short nMessageIndex; // 0x18
    };
};

struct D2PartyStrc
{
    short nPartyId; // 0x00
    short unk0x02; // 0x02
    D2PartyNodeStrc* pPartyNodes; // 0x04
    D2PartyStrc* pNext; // 0x08
};

struct D2PartyControlStrc
{
    short nNextPartyId; // 0x00
    short unk0x02; // 0x02
    D2PartyStrc* pParties; // 0x04
};

D2_CHECK_SIZE(D2DamageStrc, 0x70);
D2_CHECK_OFFSET(D2DamageStrc, dwHitClass, 0x60);
D2_CHECK_SIZE(D2MissileStrc, 0x5C);
D2_CHECK_OFFSET(D2MissileStrc, pInitFunc, 0x54);
D2_CHECK_SIZE(D2ModeChangeStrc, 0x20);
D2_CHECK_SIZE(D2AiCmdStrc, 0x1C);
D2_CHECK_SIZE(D2AiControlStrc, 0x40);
D2_CHECK_SIZE(D2AiTickParamStrc, 0x24);
D2_CHECK_SIZE(D2ObjInitFnStrc, 0x1C);
D2_CHECK_SIZE(D2QuestArgStrc, 0x1C);
D2_CHECK_SIZE(D2PartyStrc, 0x0C);
D2_CHECK_SIZE(D2PartyControlStrc, 0x08);

// MONSTER_GetPlayerCountBonus's result: the bonuses a monster gets for the players in its game.
struct D2PlayerCountBonusStrc
{
    int nHp; // 0x00
    int nExperience; // 0x04
    int nMonsterSkillBonus; // 0x08
    int nDifficulty; // 0x0C
    int nPlayerCount; // 0x10
};
D2_CHECK_SIZE(D2PlayerCountBonusStrc, 0x14);
