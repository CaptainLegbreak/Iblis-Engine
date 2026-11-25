#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Constants.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2MonModes.h"

#include "D2Primitives.h"
#include "D2LevelTxt.h"
#include "D2Packets.h"
#define MONTYPEFLAG_UNIQUE 8
#define EVENTTYPE_REMOVESTATE 0x0C

#define UNITFLAG_DOUPDATE 1
#define D2_MIN(a,b) ((a)<(b)?(a):(b))
#define D2_MAX(a,b) ((a)>(b)?(a):(b))
struct D2ModeChangeStrc;
struct D2SkillsTxt;
struct D2CharStatsTxt;
struct D2ServerCallbacks;
struct D2StatesTxt;
struct D2GSPacketSrvAA;

typedef void (__fastcall* StatListRemoveCallback)(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList);

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180
int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster); // 0x0063E9F0
D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0
D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0
void __stdcall D2COMMON_10476(D2StatListStrc* pStatList, int nExpireFrame); // 0x006260B0
void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0
void __stdcall STATLIST_SetState(D2StatListStrc* pStatList, int nState); // 0x006252D0
void __stdcall STATLIST_SetStatRemoveCallback(D2StatListStrc* pStatList, StatListRemoveCallback pfStatRemove); // 0x00625CE0
void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, int bResetFlag); // 0x00626E10
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet); // 0x00639DB0
void __fastcall SKILLS_RemoveStateAndRefreshPassives(D2UnitStrc* pUnit, int nState, D2StatListStrc* pStatList); // 0x0056E900
void __stdcall MONSTERMODE_GetModeChangeInfo(D2UnitStrc* pUnit, int nMode, D2ModeChangeStrc* pModeChange); // 0x005A7E60
int __stdcall D2GAME_ModeChange_6FC65220(D2GameStrc* pGame, D2ModeChangeStrc* pModeChange, int a3); // 0x005A7C20

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
int __stdcall SKILLS_EvaluateSkillFormula(D2UnitStrc* pUnit, unsigned int nCalc, int nSkillId, int nSkillLevel); // 0x00646CA0
void __fastcall SKILLS_ApplyAuraStatsToStatList(D2UnitStrc* pUnit, D2StatListStrc* pStatList, D2SkillsTxt* pSkillsTxtRecord, int nSkillId, int nSkillLevel); // 0x005C6CC0

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0
void __fastcall PLAYERSTATS_OnPlayerLeveledUp(void* pUnused, D2UnitStrc* pUnit, int nArg); // 0x00570850

typedef void (__fastcall* LevelCallback)(unsigned int, int);

struct D2ServerCallbacks { char unk_00[44]; LevelCallback levelUp; };

extern D2ServerCallbacks* gpServerCallbacks; // 0x00883D50
int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc*, int, int); // 0x006253B0
int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*, int, int); // 0x00625480
unsigned int __stdcall DATATBLS_GetCurrentLevelFromExp(int nClass, unsigned int dwExperience); // 0x00611860
unsigned int __stdcall DATATBLS_GetLevelThreshold(int nClass, unsigned int dwLevel); // 0x00611800
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*, int, int, int); // 0x00627260
void __stdcall STATLIST_AddUnitStat(D2UnitStrc*, int, int, int); // 0x006272B0
int __stdcall STATLIST_GetMaxLifeFromUnit(D2UnitStrc*); // 0x00625D10
int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc*); // 0x00625D60
int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc*); // 0x00625DB0
void __fastcall sub_00536850_UpdateLevel(D2GameStrc*,D2UnitStrc*,int); // 0x00536850
void __fastcall SUNIT_AttachSound(D2UnitStrc*,int,D2UnitStrc*); // 0x00553380
void __fastcall D2GAME_UpdatePlayerVitals(D2GameStrc*,D2UnitStrc*); // 0x0055F500
void __fastcall D2GAME_UpdatePlayerItems_6FC4BB90(D2GameStrc*,D2UnitStrc*,int); // 0x0055FDE0
int __stdcall UNITS_GetPlayerName(D2UnitStrc*,int,int); // 0x00622150
void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040
static void sub_00570A50_SpendStatPointsOnStrength(D2UnitStrc* pUnit, int nValue);
static void sub_00570B30_SpendStatPointsOnDexterity(D2UnitStrc* pUnit, int nValue);

#pragma pack(push, 1)

#pragma pack(pop)

extern const unsigned int gdwBitMasks[]; // 0x006CE268
extern const unsigned int gdwInvBitMasks[]; // 0x006CE2E8
extern "C" void* __cdecl memcpy(void*, const void*, unsigned int);
void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize); // 0x00410E40
int __stdcall BITMANIP_GetSize(D2BitBufferStrc*); // 0x00410E90
void __stdcall BITMANIP_Write(D2BitBufferStrc* pBuffer, int nValue, int nBits); // 0x00410EB0
int __stdcall sub_004111A0_GetLowestSetBit(unsigned int); // 0x004111A0
unsigned int* __stdcall D2COMMON_10494_STATES_GetStatFlags(D2UnitStrc*); // 0x0063A100
int __stdcall STATLIST_GetBaseStatsData(D2StatListStrc*, D2StatStrc*, int); // 0x00625C90
void __fastcall SCMD_SendRawPacket(D2ClientStrc*, const void*, int); // 0x0053E8D0

#define STAT_ENERGY 1

#define STAT_DEXTERITY 2

#define STAT_VITALITY 3

#define STAT_TOHIT 19

#define STAT_TOBLOCK 20

#define STAT_ATTACKRATE 68

static inline D2CharStatsTxt* PLRSAVE2_GetCharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }

    return 0;
}

static void __stdcall sub_005706A0_UseActEntry(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nAct)
{
    if (nAct >= 5)
    {
        nAct = 4;
    }
// build: symbol ?gnActCount@* 0x007326B4
    if (nAct >= gnActCount)
    {
        nAct = 0;
    }
// build: symbol ?gnStartingActTargetLevels@* 0x006E1520
    sub_0057EB10(pGame, pUnit, gnStartingActTargetLevels[nAct]);
}

// 0x005706D0
void __fastcall PLAYERSTATS_SetStatsForStartingAct(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char nAct)
{
    if (nAct >= 5)
    {
        nAct = 4;
    }

    if (!pPlayer)
    {
        return;
    }

    D2CharStatsTxt* pCharStatsTxtRecord = PLRSAVE2_GetCharStatsTxtRecord(pPlayer->dwClassId);
    if (!pCharStatsTxtRecord)
    {
        return;
    }

    STATLIST_SetUnitStat(pPlayer, STAT_STRENGTH, pCharStatsTxtRecord->nStr, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_ENERGY, pCharStatsTxtRecord->nInt, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_DEXTERITY, pCharStatsTxtRecord->nDex, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_VITALITY, pCharStatsTxtRecord->nVit, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_TOHIT, 0, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_TOBLOCK, 0, 0);
    const int nLife = (pCharStatsTxtRecord->nVit + pCharStatsTxtRecord->nLifeAdd) << 8;
    STATLIST_SetUnitStat(pPlayer, STAT_HITPOINTS, nLife, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_MAXHP, nLife, 0);
    const int nMana = pCharStatsTxtRecord->nInt << 8;
    STATLIST_SetUnitStat(pPlayer, STAT_MANA, nMana, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_MAXMANA, nMana, 0);
    const int nStamina = pCharStatsTxtRecord->nStamina << 8;
    STATLIST_SetUnitStat(pPlayer, STAT_STAMINA, nStamina, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_MAXSTAMINA, nStamina, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_LEVEL, 1, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_NEXTEXP, DATATBLS_GetLevelThreshold(!pPlayer ? -1 : pPlayer->dwClassId, 1), 0);
    STATLIST_SetUnitStat(pPlayer, STAT_ATTACKRATE, 100, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_VELOCITYPERCENT, 100, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_OTHER_ANIMRATE, 100, 0);

    if (nAct > 0)
    {
        sub_005706A0_UseActEntry(pGame, pPlayer, nAct);
    }
}

// 0x00570880
void __fastcall PLAYERSTATS_LevelUp(D2GameStrc* game,D2UnitStrc* unit)
{
 int classId;
 if(!unit) classId=-1; else classId=unit->dwClassId;
 int previousLevel=STATLIST_GetUnitBaseStat(unit,STAT_LEVEL,0);
 int level=DATATBLS_GetCurrentLevelFromExp(classId,STATLIST_UnitGetStatValue(unit,STAT_EXPERIENCE,0));
 STATLIST_SetUnitStat(unit,STAT_LEVEL,level,0);
 STATLIST_SetUnitStat(unit,STAT_NEXTEXP,DATATBLS_GetLevelThreshold(classId,level),0);
 int gained=level-previousLevel;
 if(gained>0) {
  D2CharStatsTxt* record=(classId>=0 && classId<sgptDataTables->nCharStatsTxtRecordCount)?&sgptDataTables->pCharStatsTxt[classId]:0;
  int life=STATLIST_GetUnitBaseStat(unit,STAT_MAXHP,0)+((record->lifePerLevel*gained)<<6);
  STATLIST_SetUnitStat(unit,STAT_MAXHP,life,0);
  int maxLife=STATLIST_GetMaxLifeFromUnit(unit);
  if(STATLIST_UnitGetStatValue(unit,STAT_HITPOINTS,0)>0) STATLIST_SetUnitStat(unit,STAT_HITPOINTS,maxLife,0);
  int mana=STATLIST_GetUnitBaseStat(unit,STAT_MAXMANA,0)+((record->manaPerLevel*gained)<<6);
  STATLIST_SetUnitStat(unit,STAT_MAXMANA,mana,0);
  int maxMana=STATLIST_GetMaxManaFromUnit(unit);
  STATLIST_SetUnitStat(unit,STAT_MANA,maxMana,0);
  int stamina=STATLIST_GetUnitBaseStat(unit,STAT_MAXSTAMINA,0)+((record->staminaPerLevel*gained)<<6);
  STATLIST_SetUnitStat(unit,STAT_MAXSTAMINA,stamina,0);
  int maxStamina=STATLIST_GetMaxStaminaFromUnit(unit);
  STATLIST_SetUnitStat(unit,STAT_STAMINA,maxStamina,0);
  STATLIST_AddUnitStat(unit,STAT_STATPTS,record->statPerLevel*gained,0);
  STATLIST_AddUnitStat(unit,STAT_SKILLPTS,gained,0);
  sub_00536850_UpdateLevel(game,unit,level);
  SUNIT_AttachSound(unit,2,unit);
  SUNIT_IterateLivingPlayers(game,(SUNIT_IterateFn)PLAYERSTATS_OnPlayerLeveledUp,unit);
  D2GAME_UpdatePlayerVitals(game,unit);
  D2GAME_UpdatePlayerItems_6FC4BB90(game,unit,1);
  if(gpServerCallbacks && gpServerCallbacks->levelUp) gpServerCallbacks->levelUp(game->nGameId,UNITS_GetPlayerName(unit,classId,level));
 }
}
