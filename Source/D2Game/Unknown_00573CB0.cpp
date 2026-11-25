#include "D2StatIds.h"
#include "D2Game.h"
#include "D2GameTypes.h"
struct D2MonsterInteractStrc;
struct D2MonsterModeDataStrc;
struct D2PropertyStrc { int nProperty,nLayer,nMin,nMax; };
struct D2SkillStrc;
struct D2StatListStrc;

extern "C" void* __cdecl memset(void*,int,unsigned int);
extern "C" __declspec(noreturn) void __cdecl exit(int);
struct D2SeedStrc { unsigned int nLowSeed, nHighSeed; };
struct D2SkillsStrc;
struct D2MonStatsTxt {
    char unk00[0xC]; unsigned char nFlags[4]; char unk10[8]; short nStatsEx; char unk1A[0x89];
    unsigned char nBlock[3]; char unkA6[4]; short nLevel[3]; char unkB0[0x94];
    short nResist[6][3]; char unk168[8]; short nSkill[8]; signed char nSkillMode[8];
    char unk188[0x10]; signed char nSkillLevel[8]; int nDamageRegen; char unk1A4[4];
};
struct D2MonsterDataStrc { D2MonStatsTxt* pMonstatsTxt; unsigned char nComponent[16]; char unk14[0x14]; D2AiControlStrc* pAiControl; void* pMonsterAi; void* pModeData; char unk34[0x24]; int nLevelId; };
struct D2UnitStrc { int dwUnitType; int dwClassId; void* pMemoryPool; int dwUnitId; int dwAnimMode; D2MonsterDataStrc* pMonsterData; char unk18[8]; D2SeedStrc pSeed; char unk28[0x38]; D2InventoryStrc* pInventory; char unk64[0x44]; D2SkillsStrc* pSkills; char unkAC[0x18]; unsigned int dwFlags; };
struct D2GameStrc { char unk00[0x1C]; void* pMemoryPool; char unk20[0x4A]; unsigned char nGameTypeByte; char unk6B[2]; unsigned char nDifficulty; char unk6E[2]; int bExpansion; int nGameType; char unk78[0x78]; D2SeedStrc pSeed; };
struct D2MonStatsExTxt { char unk00[5]; unsigned char nFlags; char unk06[0x12E]; };
struct D2DataTablesStrc { char unk00[0xA78]; D2MonStatsTxt* pMonStats; int unkA7C; int nMonStats; char unkA84[12]; D2MonStatsExTxt* pMonStatsEx; int unkA94; int nMonStatsEx; };
struct D2MonsterStatsStrc { int nMinHp,nMaxHp,nArmor,nToHit,nExperience; int unk14[9]; };
struct D2MonsterPropertyStrc { int unk00; D2PropertyStrc pProperties[3][6]; unsigned char nChance[3][6]; };
extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[]; // 0x006CE268
extern const char gszAssertFormat[]; // 0x006CC837
const char* __cdecl sub_00408090_GetAssertText(int); // 0x00408090
void __cdecl FOG_DisplayHalt(const char*,...); // 0x00408A60
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C390
unsigned int __fastcall sub_0045C3E0(D2SeedStrc*,int); // 0x0045C3E0
int __fastcall CUNIT_ValidateMonsterId(int); // 0x00463900
int __fastcall DATATBLS_ApplyRatio(int,int,int); // 0x00483360
D2InventoryStrc* __fastcall SUNITPROXY_GetNpcInventory(D2GameStrc*,int); // 0x00536B20
void __fastcall D2GAME_ITEMMODE_ServerStatlistCallback_6FC41910(D2UnitStrc*,int,int,int,void*); // 0x0055B800
void __fastcall D2GAME_SetSkills_6FD14C60(D2UnitStrc*,int,int,int); // 0x0056DEB0
D2MonsterPropertyStrc* __fastcall sub_00573470_GetMonsterProperties(int); // 0x00573470
void __fastcall MONSTER_GetPlayerCountBonus(D2GameStrc*,D2PlayerCountBonusStrc*,D2ActiveRoomStrc*,D2UnitStrc*); // 0x00573930
void __fastcall MONSTER_SetComponents(int,D2UnitStrc*); // 0x005739D0
void __fastcall SKILLS_EquipMonsterFromTable(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPet, int nSkillId, int nSkillLevel, int nItemLevel, int bCheckOnInit); // 0x005D6B60
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc*); // 0x0061A1B0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall STATLIST_AllocStatListEx(D2UnitStrc*,int,void(__fastcall*)(D2UnitStrc*,int,int,int,void*),D2GameStrc*); // 0x00626D40
void __stdcall sub_00626E10(D2UnitStrc*,D2StatListStrc*,int); // 0x00626E10
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*,int,int,int); // 0x00627260
D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void*,D2UnitStrc*); // 0x0063ABD0
void __stdcall sub_0063EBC0_SetSkillBonus(D2UnitStrc*,int); // 0x0063EBC0
void __stdcall MONSTERS_ApplyClassicScaling(D2UnitStrc*,int,unsigned char); // 0x0063EEF0
D2SkillsStrc* __stdcall SKILLS_AllocSkillList(void*); // 0x006438B0
D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0
void __stdcall SKILLS_SetSkillMode(void*,int); // 0x00644340
void __stdcall DATATBLS_CalculateMonsterStatsByLevel(int,int,int,int,int,D2MonsterStatsStrc*); // 0x006538A0
void __stdcall D2COMMON_11292_ItemAssignProperty(int nType, D2UnitStrc* pUnit, D2UnitStrc* pItem, const void* pMods, int nIndex, int nPropSet, const D2PropertyStrc* pProperty, int nState, int fStatlist, D2UnitStrc* a10); // 0x0065FD70
void __fastcall D2GAME_DeleteTimersOnUnit_6FC34A30(D2GameStrc*,D2UnitStrc*); // 0x00540F30
D2AiControlStrc* __fastcall AIGENERAL_AllocAiControl(D2GameStrc*); // 0x0058EBC0
D2MonsterModeDataStrc* __fastcall MONSTERMODE_AllocParams(D2GameStrc* pGame); // 0x005A6490
D2MonsterInteractStrc* __fastcall MONSTERAI_AllocMonsterInteract(D2GameStrc* pGame); // 0x00572BA0
int __fastcall MONSTERREGION_GetMonsterComponentData(D2SeedStrc*,D2ActiveRoomStrc*,D2UnitStrc*); // 0x00547BC0
void __fastcall AITHINK_ExecuteAiFn(D2GameStrc*,D2UnitStrc*,D2AiControlStrc*,int); // 0x005B0E00
void __fastcall QUESTS_AttachLevelChainRecord(D2GameStrc*,D2UnitStrc*,D2ActiveRoomStrc*,int); // 0x00545CD0
void __fastcall SUNIT_InitializeAnimation(D2UnitStrc*); // 0x005533D0
void __fastcall SUNIT_SetCombatMode(D2GameStrc*,D2UnitStrc*,int); // 0x00553570
static inline void MONSTER_SetComponent(D2UnitStrc* pUnit,int nComponent,unsigned char nValue)
{
    if (pUnit && pUnit->dwUnitType==1 && pUnit->pMonsterData) pUnit->pMonsterData->nComponent[nComponent]=nValue;
}
static __forceinline D2MonStatsExTxt* MONSTER_GetMonStatsEx(int nClass)
{
    if (nClass>=0 && nClass<sgptDataTables->nMonStats)
    {
        int nEx=sgptDataTables->pMonStats[nClass].nStatsEx;
        if (nEx>=0 && nEx<sgptDataTables->nMonStatsEx) return &sgptDataTables->pMonStatsEx[nEx];
    }
    return 0;
}
static __forceinline int MONSTER_Regeneration(int nLife,int nRegen)
{
    if (nRegen<0) { FOG_DisplayHalt(gszAssertFormat,sub_00408090_GetAssertText(222)); exit(-1); }
    if (nRegen&0xFFFFF000) { FOG_DisplayHalt(gszAssertFormat,sub_00408090_GetAssertText(223)); exit(-1); }
    int nResult=0;
    if (nRegen)
    {
        if (nLife>0x7FFFFFFF/nRegen) nResult=(nLife>>12)*nRegen;
        else nResult=(nLife*nRegen)>>12;
    }
    return nResult;
}
static inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    const unsigned __int64 nSeed=pSeed->nHighSeed+0x6AC690C5i64*pSeed->nLowSeed;
    pSeed->nHighSeed=(unsigned int)(nSeed>>32);
    pSeed->nLowSeed=(unsigned int)nSeed;
    return nSeed;
}
static
// 0x00573CB0
void __stdcall sub_00573CB0_InitializeStats(D2GameStrc* pGame,D2ActiveRoomStrc* pRoom,int nSeed,D2UnitStrc* pMonster)
{
    if (!pMonster) return;
    const int nType=!pMonster ? 6:pMonster->dwUnitType;
    int nClass=pMonster->dwClassId;
    if (nType!=1) return;
    D2MonsterDataStrc* pData=pMonster->pMonsterData;
    if (!pData) return;
    D2MonStatsTxt* pStats=pData->pMonstatsTxt;
    if (!pStats) return;
    D2MonStatsExTxt* pEx=MONSTER_GetMonStatsEx(pMonster->dwClassId);
    if (!pEx) return;
    MONSTER_SetComponents(nSeed,pMonster);
    switch(nClass<sgptDataTables->nMonStats ? nClass:-1)
    {
    case 311: MONSTER_SetComponent(pMonster,10,(unsigned char)SEED_RollLimitedRandomNumber(&pMonster->pSeed,4)); break;
    case 312:
    {
        unsigned char nValue=(unsigned char)SEED_RollLimitedRandomNumber(&pMonster->pSeed,4);
        MONSTER_SetComponent(pMonster,10,nValue);MONSTER_SetComponent(pMonster,11,nValue);break;
    }
    }
    D2PlayerCountBonusStrc tBonus;
    MONSTER_GetPlayerCountBonus(pGame,&tBonus,pRoom,pMonster);
    #define MON_MAX(a,b) ((a)>(b)?(a):(b))
    #define MON_MIN(a,b) ((a)<(b)?(a):(b))
    int nDifficulty=MON_MIN(MON_MAX(pGame->nDifficulty,0),2);
    if (sub_0063EE90_IsHireling(pMonster)) nDifficulty=0;
    int nCount=1;
    if (tBonus.nPlayerCount>=1) nCount=tBonus.nPlayerCount;
    int nLevel=pStats->nLevel[nDifficulty];
    if (pGame->bExpansion && nDifficulty>0 && !(pStats->nFlags[0]&gdwBitMasks[2]) && !(pStats->nFlags[0]&gdwBitMasks[6]))
    {
        nLevel=DATATBLS_GetMonsterLevelInArea(DUNGEON_GetLevelIdFromRoom(pRoom),nDifficulty,pGame->bExpansion);
    }
    STATLIST_AllocStatListEx(pMonster,0,D2GAME_ITEMMODE_ServerStatlistCallback_6FC41910,pGame);
    STATLIST_SetUnitStat(pMonster,STAT_LEVEL,nLevel,0);
    STATLIST_SetUnitStat(pMonster,STAT_MONSTER_PLAYERCOUNT,nCount,0);
    STATLIST_SetUnitStat(pMonster,STAT_DAMAGERESIST,pStats->nResist[0][nDifficulty],0);
    STATLIST_SetUnitStat(pMonster,STAT_MAGICRESIST,pStats->nResist[1][nDifficulty],0);
    STATLIST_SetUnitStat(pMonster,STAT_FIRERESIST,pStats->nResist[2][nDifficulty],0);
    STATLIST_SetUnitStat(pMonster,STAT_LIGHTRESIST,pStats->nResist[3][nDifficulty],0);
    STATLIST_SetUnitStat(pMonster,STAT_COLDRESIST,pStats->nResist[4][nDifficulty],0);
    STATLIST_SetUnitStat(pMonster,STAT_POISONRESIST,pStats->nResist[5][nDifficulty],0);
    STATLIST_SetUnitStat(pMonster,STAT_TOBLOCK,pStats->nBlock[nDifficulty],0);
    STATLIST_SetUnitStat(pMonster,STAT_ATTACKRATE,100,0); STATLIST_SetUnitStat(pMonster,STAT_VELOCITYPERCENT,75,0);
    STATLIST_SetUnitStat(pMonster,STAT_OTHER_ANIMRATE,100,0); STATLIST_SetUnitStat(pMonster,STAT_LAST_SENT_HP_PCT,128,0);
    const int bGameType=pGame->nGameTypeByte || pGame->nGameType;
    D2MonsterStatsStrc tStats;
    memset(&tStats,0,sizeof(tStats));
    DATATBLS_CalculateMonsterStatsByLevel(!pMonster ? -1 : pMonster->dwClassId,bGameType,nDifficulty,nLevel,7,&tStats);
    int nLife=sub_0045C3E0(&pMonster->pSeed,tStats.nMaxHp-tStats.nMinHp+1)+tStats.nMinHp;
    nLife+=DATATBLS_ApplyRatio(nLife,tBonus.nHp,100);
    if (nLife>=0x800000) nLife=0x7FFFFF;
    const int nShiftedHp=nLife<<8;
    STATLIST_SetUnitStat(pMonster,STAT_MAXHP,nShiftedHp,0);STATLIST_SetUnitStat(pMonster,STAT_HITPOINTS,nShiftedHp,0);
    STATLIST_SetUnitStat(pMonster,STAT_ARMORCLASS,tStats.nArmor,0);
    STATLIST_SetUnitStat(pMonster,STAT_EXPERIENCE,tStats.nExperience+DATATBLS_ApplyRatio(tStats.nExperience,tBonus.nExperience,100),0);
    STATLIST_SetUnitStat(pMonster,STAT_HPREGEN,MONSTER_Regeneration(nShiftedHp,pStats->nDamageRegen),0);
    MONSTERS_ApplyClassicScaling(pMonster,pGame->bExpansion,pGame->nDifficulty);
    D2StatListStrc* pStatList=STATLIST_AllocStatList(pGame->pMemoryPool,1,0,1,!pMonster ? -1 : pMonster->dwUnitId);
    sub_00626E10(pMonster,pStatList,1);
    if(pStats->nFlags[3]&(unsigned char)gdwBitMasks[0])
    {
        if(pStats->nFlags[1]&(unsigned char)gdwBitMasks[1])
            pMonster->pInventory=SUNITPROXY_GetNpcInventory(pGame,CUNIT_ValidateMonsterId(nClass));
        else INVENTORY_AllocInventory(0,pMonster);
    }
    pMonster->pSkills=SKILLS_AllocSkillList(pGame->pMemoryPool);
    for(int i=0;i<8;++i)
    {
        if (pStats->nSkill[i]>=0)
        {
            const signed char nSkillLevel=pStats->nSkillLevel[i];
            if (nSkillLevel>0)
            {
                D2GAME_SetSkills_6FD14C60(pMonster,pStats->nSkill[i],tBonus.nMonsterSkillBonus+nSkillLevel,0);
                const signed char nSkillMode=pStats->nSkillMode[i];
                if(nSkillMode>=0) SKILLS_SetSkillMode(SKILLS_GetHighestLevelSkillFromUnitAndId(pMonster,pStats->nSkill[i]),nSkillMode);
            }
        }
    }
    sub_0063EBC0_SetSkillBonus(pMonster,tBonus.nMonsterSkillBonus);
    if(pEx->nFlags&(unsigned char)gdwBitMasks[1]) pMonster->dwFlags|=4;
    if(pStats->nFlags[2]&(unsigned char)gdwBitMasks[3]) pMonster->dwFlags|=0x40000000;
    D2MonsterPropertyStrc* pProperties=sub_00573470_GetMonsterProperties(pMonster->dwClassId);
    if(pProperties)
    {
        for(int i=0;i<6;++i)
        {
            D2PropertyStrc* pProperty=&pProperties->pProperties[nDifficulty][i];
            if(pProperty->nProperty<0) break;
            if(pProperties->nChance[nDifficulty][i]<=0 || (int)((unsigned int)SEED_RollRandomNumber(&pMonster->pSeed)%100)<pProperties->nChance[nDifficulty][i])
                D2COMMON_11292_ItemAssignProperty(0,0,pMonster,0,0,0,pProperty,0,64,0);
        }
    }
    SKILLS_EquipMonsterFromTable(pGame,0,pMonster,-1,nLevel,nLevel,1);
}
static inline D2MonsterDataStrc* MONSTER_GetMonsterData(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == 1)
    {
        return pUnit->pMonsterData;
    }
    return 0;
}
static inline D2MonStatsTxt* MONSTER_GetMonStatsTxtRecord(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwClassId >= 0 && pUnit->dwClassId < sgptDataTables->nMonStats)
    {
        return &sgptDataTables->pMonStats[pUnit->dwClassId];
    }
    return 0;
}
static inline D2AiControlStrc* MONSTER_GetAiControl(D2UnitStrc* pUnit)
{
    D2MonsterDataStrc* pMonsterData = MONSTER_GetMonsterData(pUnit);
    if (pMonsterData)
    {
        return pMonsterData->pAiControl;
    }
    return 0;
}

// 0x00574250
void __fastcall MONSTER_Initialize(D2GameStrc* pGame,D2ActiveRoomStrc* pRoom,D2UnitStrc* pMonster,int nUnitGUID)
{
    if (pMonster)
    {
        pMonster->dwUnitId = nUnitGUID;
        pMonster->dwFlags |= 0x0A;
    }

    D2GAME_DeleteTimersOnUnit_6FC34A30(pGame, pMonster);

    D2MonsterDataStrc* pMonsterData = MONSTER_GetMonsterData(pMonster);
    pMonsterData->pAiControl = AIGENERAL_AllocAiControl(pGame);
    pMonsterData->pMonsterAi = MONSTERMODE_AllocParams(pGame);
    pMonsterData->pModeData = MONSTERAI_AllocMonsterInteract(pGame);
    pMonsterData->pMonstatsTxt = MONSTER_GetMonStatsTxtRecord(pMonster);

    sub_00573CB0_InitializeStats(pGame, pRoom, MONSTERREGION_GetMonsterComponentData(&pGame->pSeed, pRoom, pMonster), pMonster);
    AITHINK_ExecuteAiFn(pGame, pMonster, MONSTER_GetAiControl(pMonster), 0);

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    int nAnimMode;
    if (pMonster)
    {
        D2MonsterDataStrc* pData = MONSTER_GetMonsterData(pMonster);
        if (pData)
        {
            pData->nLevelId = nLevelId;
        }

        nAnimMode = pMonster->dwAnimMode;
        if (nAnimMode != 0 && nAnimMode != 12)
        {
            QUESTS_AttachLevelChainRecord(pGame, pMonster, pRoom, 1);
            SUNIT_InitializeAnimation(pMonster);
            return;
        }
    }
    else
    {
        nAnimMode = 0;
    }

    SUNIT_SetCombatMode(pGame, pMonster, nAnimMode);
    SUNIT_InitializeAnimation(pMonster);
}
