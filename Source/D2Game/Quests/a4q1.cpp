#include "D2MonsterIds.h"
#include "D2StatIds.h"
#include "D2ObjModes.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2Drlg.h"
#include "D2GameServer.h"
#include "D2GameStrc.h"
#include "D2LevelTxt.h"
#include "D2GameObjs.h"
#include "D2DrlgMaps.h"
#include "D2QuestData.h"
#include "D2GameTypes.h"
#include "D2Win32Base.h"
#include "D2Packets.h"
#include "D2GameAux.h"
#include "D2LanguageNames.h"
#include "FogApi.h"
#include "D2CommonApi.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt("", sub_00408090(), line); exit(-1); }

struct D2PoolSystemStrc;
struct D2StaticPathStrc;

struct D2UnkMonCreateStrc3;

struct D2UnkMonCreateStrc;

union D2SeedStrc;

struct D2LevelsTxt;

struct D2MonStatsTxt;

struct D2PlayerDataStrc;

struct D2Act4Quest1Strc;

struct D2QuestGUIDStrc;

struct D2ObjOperateFnStrc;


struct D2Act4Quest2Strc;

struct D2Act4Quest3Strc;

struct D2Act3Quest1Strc;

struct D2Act3Quest3Strc;

struct D2Act3Quest4Strc;

struct D2Act3Quest5Strc;

struct D2Act3Quest6Strc;

struct D2Act3Quest7Strc;

struct D2UnkMonCreateStrc2
{
    int nRecordCount;
    int unk0x04;
    unsigned char unk0x08;
    unsigned char pad0x09[3];
    D2UnkMonCreateStrc3 records[4];
};


#include "D2GameFuncs.h"
#include "D2CMPApi.h"


void __fastcall AIGENERAL_AllocMinionList(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pMinion); // 0x0058F100


extern D2UnkMonCreateStrc2 gtBonePrisonSpawnInfo; // 0x0073D4F0


enum D2C_SpawnRandomConstants
{
    MONSTATSFLAGINDEX_ISSPAWN = 0,
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern const unsigned int gdwBitMasks[32]; // 0x006CE268

extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0


D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId); // 0x0061DB70

typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

typedef void(__fastcall* QUESTCALLBACK)(D2QuestDataStrc*, D2QuestArgStrc*);

typedef bool(__fastcall* QUESTSEQFILTER)(D2QuestDataStrc* pQuestData);

typedef int(__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

typedef bool(__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

typedef bool(__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0


D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640


void __fastcall QUESTS_UnitIterate(D2QuestDataStrc* pQuest, int nIterateState, D2UnitStrc* pUnit, QUESTUNITITERATE pfIterate, bool bIterate); // 0x00544300

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380


D2ActiveRoomStrc* __stdcall DUNGEON_FindRoomBySubtileCoordinates(D2DrlgActStrc* pAct, int nX, int nY); // 0x00619DA0

D2UnitStrc* __fastcall D2GAME_SpawnMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20


bool __fastcall ACT3Q7_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus); // 0x005B3740


void __fastcall QUESTS_StatusCyclerEx(D2GameStrc* game,D2UnitStrc* player,unsigned char id); // 0x00544190


void __stdcall QUESTRECORD_ClearQuestState(D2BitBufferStrc* pQuestRecord, int nQuest, int nState); // 0x0065C3A0

void __fastcall QUESTS_CreateTimer(D2QuestDataStrc* pQuest, QUESTUPDATE pfnCallback, int nTicks); // 0x00543F10


int __fastcall QUESTS_CheckPlayerGUID(D2QuestDataStrc* pQuest, int dwGUID); // 0x005452C0


D2UnitStrc* __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0


void __stdcall SUNIT_ResetInteractInfo(D2UnitStrc* pUnit); // 0x00554190


void __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180

int __stdcall MONSTERS_IsBoss(D2MonStatsTxt* pMonStatsTxtRecord, D2UnitStrc* pMonster); // 0x0063E9F0

void __fastcall PLAYER_CloseInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005351C0


typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630

void __fastcall PARTY_IteratePartyMembers(D2GameStrc* pGame, unsigned short nPartyId, PartyCallbackFunction pCallback, void* pArgs); // 0x00540510


#define CENTER 3

#define MASK_A 0x100

#define MASK_B 0x1c09

#define OFFSET_BASE (g_006E2D50_offsets)


struct D2TileLibraryEntryStrc;

extern D2CoordStrc g_006E2D50_offsets[4];  // 0x006E2D50


unsigned short __stdcall COLLISION_CheckMask(D2ActiveRoomStrc*,int,int,unsigned short); // 0x0064CB30

struct D2GameStrc;

#define MONSTATSFLAGINDEX_SETBOSS 4

#define MONSTATSFLAGINDEX_BOSSXFER 5

int __fastcall GAME_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50

int __fastcall PLAYER_GetBaseIdFromMonsterId(int nMonsterId); // 0x00463830

int __fastcall MISSILE_RollRange(D2SeedStrc* pSeed, int nMin, int nMax); // 0x004CC790


static void MONSTERSPAWN_SpawnMinionParty(D2UnkMonCreateStrc* pMonCreate, D2UnitStrc* pUnit); // 0x005B2830


int __fastcall GAME_GetUnitTypeOrInvalid(D2UnitStrc* pUnit); // 0x0044BE50




extern "C" __declspec(dllimport) int __stdcall PtInRect(const tagRECT*,tagPOINT);


D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc*,int,int); // 0x00463740



D2UnitStrc* __fastcall SUNIT_AllocUnitData(int,int,int,int,D2GameStrc*,D2ActiveRoomStrc*,char,int,unsigned int); // 0x00555230

void __fastcall MONSTERREGION_RegisterSpawnedMonster(D2MonsterRegionStrc**,D2ActiveRoomStrc*,D2UnitStrc*,int); // 0x00547D90


void __fastcall SUNIT_SetMonsterVision(D2UnitStrc*,D2RoomCoordListStrc*); // 0x00552D60


static void MONSTERSPAWN_SetupNormalMods(D2UnkMonCreateStrc*,D2UnitStrc*); // 0x005B21B0

static void MONSTERSPAWN_SetupBossMods(D2UnkMonCreateStrc*,D2UnitStrc*); // 0x005B1CF0

static void MONSTERSPAWN_EquipAncientBarbarians(D2UnitStrc*); // 0x005B1C50

void __fastcall D2GAME_BOSSES_AssignUMod(D2GameStrc*,D2UnitStrc*,int,int); // 0x005A4850


D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId);                // 0x00633640

void __fastcall MONSTERAI_CreateAndEquipItem(D2GameStrc* pGame, D2UnitStrc* pUnit, struct D2MonsterEquipmentStrc* pItemInfo, int nLevel, unsigned int nFlags); // 0x00573B20


void __fastcall MONSTER_ToggleSummonerFlag(D2UnitStrc* pUnit, unsigned short nFlag, int bSet);                         // 0x00573570


int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0

void __fastcall QUESTS_WarrivSpawn(D2GameStrc* pGame, void* pRoom, int nXpos, int nYpos, int nWarrivId);    // 0x005447A0


extern const D2MonsterEquipmentStrc gtAncientEquipment[12]; // 0x006E2C90

void* __fastcall FOG_AllocPool(D2PoolSystemStrc* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

extern "C" const char gszAct4Q2SourceFile[]; // 0x006E2DA4


void __fastcall QUESTS_QuickRemovePlayerGUID(D2QuestDataStrc* pQuest, D2QuestArgStrc* pQuestArg); // 0x00545310


void __fastcall ACT4Q3_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg); // 0x005B3E30


void __fastcall QUESTS_SendLogUpdate(D2UnitStrc*, int); // 0x005458E0


extern "C" const char gszAct4Q3SourceFile[];

extern char gpAct4Q3NpcMessages[];

extern char gpAct4Q4NpcMessages[];

extern char gpAct3IntroNpcMessages[];


int __stdcall ITEMS_GetBaseCode(D2UnitStrc* pItem);


bool __fastcall ACT4Q4_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);


void __fastcall ACT3Intro_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg);


inline int CLIENTS_GetUnitX_Inline(D2UnitStrc* pUnit)
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

inline int CLIENTS_GetUnitY_Inline(D2UnitStrc* pUnit)
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


static inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord_Inline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    return 0;
}


static inline int MONSTERREGION_SanitizeMonsterId_Inline(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
        return -1;
    return nMonsterId;
}

static void MONSTERSPAWN_SetupNormalMods(D2UnkMonCreateStrc* pMonCreate, D2UnitStrc* pUnit)
{
    D2GameStrc* pGame = pMonCreate->pGame;
    const int nMonsterId = pMonCreate->nMonsterId;
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord_Inline(nMonsterId);
    const int nBaseId = !pMonStatsTxtRecord ? nMonsterId : pMonStatsTxtRecord->nBaseId;

    switch (MONSTERREGION_SanitizeMonsterId_Inline(nBaseId))
    {
    case 0x5B:
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0x14, 0);
        break;
    case 0x18:
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0xD, 0);
        break;
    case 0x60:
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0xA, 0);
        break;
    case 0x146:
    case 0x147:
    case 0x148:
    case 0x149:
    case 0x14A:
    case 0x162:
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0xE, 0);
        break;
    case 0x154:
    case 0x155:
    case 0x156:
    case 0x157:
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0xF, 0);
        break;
    case 0x1CD:
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0x21, 0);
        break;
    case 0x1B4:
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0x22, 0);
        break;
    case 0x1F5:
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0x23, 0);
        break;
    case 0xD3:
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0xB, 0);
    case 0x21C:
    case 0x21D:
    case 0x21E:
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0x16, 1);
        break;
    }
}

static void MONSTERSPAWN_EquipAncientBarbarians(D2UnitStrc* pUnit)
{
	const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
	D2GameStrc* pGame = SUNIT_GetGameFromUnit(pUnit);
	const int nLevel = STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
	const D2MonsterEquipmentStrc* pItemInfo = &gtAncientEquipment[nClassId - 540];

	int nItemId;
	int nCount = 4;
	do
	{
		D2MonsterEquipmentStrc itemInfo = *pItemInfo;
		D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemRecordFromItemCode(pItemInfo->nItemCode, &nItemId);
		switch (pGame->nDifficulty)
		{
		case 1:
			itemInfo.nItemCode = pItemsTxtRecord->dwUberCode;
			break;

		case 2:
			itemInfo.nItemCode = pItemsTxtRecord->dwUltraCode;
			break;
		}

		MONSTERAI_CreateAndEquipItem(pGame, pUnit, &itemInfo, nLevel, 4);
		pItemInfo += 3;
		--nCount;
	}
	while (nCount);
}

static inline D2MonStatsTxt* MONSTERS_GetMonStatsTxtRecord_Inline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

static inline int MONSTERS_ValidateMonsterId_Inline(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        return -1;
    }
    return nMonsterId;
}

static inline void MONSTERUNIQUE_ToggleUnitFlag_Inline(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        pUnit->dwFlags |= nFlag;
    }
}

static void MONSTERSPAWN_SetupBossMods(D2UnkMonCreateStrc* pMonCreate, D2UnitStrc* pUnit)
{
    D2GameStrc* pGame = pMonCreate->pGame;
    void* pRoom = pMonCreate->pRoom;
    const int nMonsterId = pMonCreate->nMonsterId;

    D2MonStatsTxt* pMonStatsTxtRecord = MONSTERS_GetMonStatsTxtRecord_Inline(nMonsterId);
    int nBaseId;
    if (!pMonStatsTxtRecord)
    {
        nBaseId = nMonsterId;
    }
    else
    {
        nBaseId = pMonStatsTxtRecord->nBaseId;
    }

    switch (MONSTERS_ValidateMonsterId_Inline(nBaseId))
    {
    case 0xD3:
        if (nMonsterId != MONSTER_UBERDURIEL)
        {
            QUESTS_CreateChainRecord(pGame, pUnit, 0xD);
            QUESTS_CreateChainRecord(pGame, pUnit, 9);
            return;
        }
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 6, 1);
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0x12, 1);
        return;
    case 0xAF:
    {
        const int nWarrivId = MONSTERS_ValidateMonsterId_Inline(MONSTER_WARRIV2);
        QUESTS_WarrivSpawn(pGame, pRoom, CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), nWarrivId);
        return;
    }
    case 0xFA:
        QUESTS_CreateChainRecord(pGame, pUnit, 0xC);
        MONSTERUNIQUE_ToggleUnitFlag_Inline(pUnit, 0x800);
        MONSTER_ToggleSummonerFlag(pUnit, 1, 1);
        return;
    case 0xF3:
        if (nMonsterId != MONSTER_UBERDIABLO)
        {
            D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0x16, 1);
            QUESTS_CreateChainRecord(pGame, pUnit, 0x17);
            return;
        }
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0x16, 1);
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 8, 1);
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 6, 1);
        return;
    case 0x16E:
        QUESTS_CreateChainRecord(pGame, pUnit, 0x13);
        MONSTERUNIQUE_ToggleUnitFlag_Inline(pUnit, 0x20000);
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0x16, 1);
        return;
    case 0x154:
    case 0x155:
    case 0x156:
    case 0x157:
        MONSTERUNIQUE_ToggleUnitFlag_Inline(pUnit, 0x20000);
        return;
    case 0xF2:
        if (nMonsterId != MONSTER_UBERMEPHISTO)
        {
            QUESTS_CreateChainRecord(pGame, pUnit, 0x14);
            D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0x16, 1);
            return;
        }
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0x16, 1);
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0x1E, 1);
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0x11, 1);
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 8, 1);
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 6, 1);
        return;
    case 0x9C:
        if (nMonsterId != MONSTER_UBERANDARIEL)
        {
            D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0x16, 1);
            QUESTS_CreateChainRecord(pGame, pUnit, 6);
            return;
        }
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0x17, 1);
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 6, 1);
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0x1D, 1);
        return;
    case 0x199:
        QUESTS_CreateChainRecord(pGame, pUnit, 0x18);
        return;
    case 0x100:
        if (nMonsterId != MONSTER_UBERIZUAL)
        {
            D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0x16, 1);
            QUESTS_CreateChainRecord(pGame, pUnit, 0x16);
            return;
        }
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 6, 1);
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0x12, 1);
        return;
    case 0x197:
        QUESTS_CreateChainRecord(pGame, pUnit, 0x11);
        return;
    case 0xE5:
        QUESTS_CreateChainRecord(pGame, pUnit, 8);
        return;
    case 0x10B:
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0xC, 1);
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0x16, 1);
        QUESTS_CreateChainRecord(pGame, pUnit, 2);
        STATES_ToggleState(pUnit, 0x76, 1);
        return;
    case 0x11C:
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0x17, 1);
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0x16, 1);
        return;
    case 0x124:
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0x1F, 0);
        return;
    case 0x192:
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0x16, 1);
        return;
    case 0x1B2:
        QUESTS_CreateChainRecord(pGame, pUnit, 0x20);
        return;
    case 0x20E:
        QUESTS_CreateChainRecord(pGame, pUnit, 0x22);
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0x16, 1);
        return;
    case 0x21C:
        MONSTERSPAWN_EquipAncientBarbarians(pUnit);
        return;
    case 0x220:
        if (nMonsterId != MONSTER_UBERBAAL)
        {
            QUESTS_CreateChainRecord(pGame, pUnit, 0x24);
            D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0x16, 1);
            return;
        }
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0x16, 1);
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 0x12, 1);
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 8, 1);
        D2GAME_BOSSES_AssignUMod(pGame, pUnit, 6, 1);
        return;
    }
}


static inline unsigned __int64 SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}


struct D2BitBufferStrc;

struct D2QuestDataStrc;

struct D2UnitStrc;


static inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}


// 0x005B36A0
void __fastcall ACT4Q0_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestArg->nNPCNo == 367 && pQuestArg->nMessageIndex == 664)
    {
        D2GameStrc* pGame = pQuestArg->pGame;
        D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
        QUESTRECORD_SetQuestState(pQuestFlags, 24, 0);
    }
}

// 0x005B36D0
void __fastcall ACT4Q0_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2UnitStrc* pTarget = pQuestArg->pTarget;
    if (!pTarget || pTarget->dwClassId != 367)
    {
        return;
    }

    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 24, 0))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, !pQuestArg->pTarget ? -1 : pQuestArg->pTarget->dwClassId, 0);
    }
}

// 0x005B3740
bool __fastcall ACT3Q7_StatusFilterCallback(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus)
{
    return false;
}

// 0x005B3750
bool __fastcall ACT4Q0_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    if (nNpcId == 367 && !QUESTRECORD_GetQuestState(pQuestFlags, 24, 0))
    {
        return true;
    }
    return false;
}

// 0x005B3780
void __fastcall ACT4Q0_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->pCallback[0] = ACT4Q0_Callback00_NpcActivate;
    pQuestData->pCallback[11] = ACT4Q0_Callback11_ScrollMessage;
    pQuestData->pNPCMessages = gpAct4Q0NpcMessages;
    pQuestData->bActive = 1;
    pQuestData->fState = 0;
    pQuestData->fLastState = 0;
    pQuestData->pQuestDataEx = 0;
    pQuestData->eFilter = 24;
    pQuestData->pfStatusFilter = ACT3Q7_StatusFilterCallback;
    pQuestData->pfActiveFilter = ACT4Q0_ActiveFilterCallback;
}

#define QUESTSTATEFLAG_A4Q1 25

#define QFLAG_REWARDGRANTED 0

#define QFLAG_REWARDPENDING 1

#define QFLAG_CUSTOM1 5

// 0x005B37F0
bool __fastcall ACT4Q1_ActiveFilterCallback(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC)
{
    const int nId = nNpcId;
    if (pQuest->bNotIntro && !QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q1, QFLAG_REWARDGRANTED))
    {
        if (nId == MONSTER_TYRAEL2)
        {
            if (QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q1, QFLAG_REWARDPENDING) == 1 || pQuest->fState == 1)
            {
                return true;
            }
        }
        else if (nId == MONSTER_IZUALGHOST)
        {
            if (!QUESTRECORD_GetQuestState(pQuestFlags, QUESTSTATEFLAG_A4Q1, QFLAG_CUSTOM1))
            {
                return true;
            }
        }
    }

    return false;
}

// 0x005B3860
int __fastcall ACT4Q1_UnitIterate_UpdateQuestStateFlags(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 25, 0) == 1)
    {
        return 0;
    }

    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 22);
    if (!pQuestData)
    {
        return 0;
    }

    D2Act4Quest1Strc* pQuestDataEx = (D2Act4Quest1Strc*)pQuestData->pQuestDataEx;
    if (pQuestData->fState == 2)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 25, 2);
        return 0;
    }

    if (pQuestData->fState == 3)
    {
        if (pQuestDataEx->bPlayerStartedGame)
        {
            QUESTRECORD_SetQuestState(pQuestFlags, 25, 4);
            return 0;
        }
        QUESTRECORD_SetQuestState(pQuestFlags, 25, 3);
    }

    return 0;
}

// 0x005B38E0
bool __fastcall ACT4Q1_SeqCallback(D2QuestDataStrc* pQuestData)
{
    if (pQuestData->fState != 5 && pQuestData->bNotIntro)
    {
        return true;
    }

    D2QuestDataStrc* pQuest = QUESTS_GetQuestData(pQuestData->pGame, pQuestData->nSeqId);
    if (pQuest)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)pQuest->pfSeqFilter), 0xA1);
        return pQuest->pfSeqFilter(pQuest);
    }

    return false;
}


// 0x005B3940
int __fastcall ACT4Q1_UnitIterate_StatusCyclerEx(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];

    if (!QUESTRECORD_GetQuestState(pQuestFlags, 25, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 25, 15)
        || QUESTRECORD_GetQuestState(pQuestFlags, 25, 13)
        || QUESTRECORD_GetQuestState(pQuestFlags, 25, 14))
    {
        QUESTS_StatusCyclerEx(pGame, pPlayer, 22);
    }

    return 0;
}

// 0x005B39A0
void __fastcall ACT4Q1_Callback11_ScrollMessage(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act4Quest1Strc* pQuestDataEx = (D2Act4Quest1Strc*)pQuestData->pQuestDataEx;
    D2GameStrc* pGame = pQuestData->pGame;
    unsigned short nNpcId = pQuestArg->nNPCNo;
    unsigned short nMessageId = pQuestArg->nMessageIndex;
    D2BitBufferStrc* pFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (nNpcId == 0x16F)
    {
        if (nMessageId == 0x29E)
        {
            pQuestDataEx->bTyraelActivated = 1;
            QUESTS_StateDebug(pQuestData, 2, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q1.cpp", 0xD3);
            SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT4Q1_UnitIterate_UpdateQuestStateFlags);
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
            return;
        }
        if (nMessageId == 0x2A4 && QUESTRECORD_GetQuestState(pFlags, pQuestData->eFilter, 1))
        {
            if (QUESTRECORD_GetQuestState(pFlags, pQuestData->eFilter, 13))
            {
                if (pQuestData->fState != 5)
                {
                    QUESTS_StateDebug(pQuestData, 5, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q1.cpp", 0xDE);
                    if (IsBadCodePtr((FARPROC)pQuestData->pfSeqFilter))
                    {
                        FOG_DisplayHalt("", sub_00408090(), 0xDF);
                        exit(-1);
                    }
                    pQuestData->pfSeqFilter(pQuestData);
                    pQuestData->nStatusFlags = 0;
                    QUESTS_UnitIterate(pQuestData, 13, 0, ACT4Q1_UnitIterate_StatusCyclerEx, 0);
                }
                pQuestData->pCallback[2] = 0;
                QUESTS_SetGlobalState(pQuestArg->pGame, pQuestData->eFilter, 13);
            }
            QUESTRECORD_SetQuestState(pFlags, pQuestData->eFilter, 0);
            QUESTRECORD_ClearQuestState(pFlags, pQuestData->eFilter, 1);
            QUESTRECORD_ResetIntermediateStateFlags(pFlags, pQuestData->eFilter);
            STATLIST_AddUnitStat(pQuestArg->pPlayer, STAT_SKILLPTS, 2, 0);
            QUESTS_SendLogUpdate(pQuestArg->pPlayer, 22);
            QUESTS_AddPlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
            QUESTS_NPCActivateSpeeches(pQuestArg->pGame, pQuestArg->pPlayer, pQuestArg->pTarget);
        }
    }
    else if (nNpcId == 0x196 && nMessageId == 0x2A3)
    {
        pQuestDataEx->bIzualGhostActivated = 1;
        pQuestDataEx->bGhostActivated = 1;
        QUESTRECORD_SetQuestState(pFlags, pQuestData->eFilter, 5);
        if (pQuestData->fLastState != 4)
        {
            pQuestData->nStatusFlags = 0;
            QUESTS_UnitIterate(pQuestData, 4, 0, ACT4Q1_UnitIterate_StatusCyclerEx, 1);
        }
    }
}

int gnAct4Q2NpcMessageIndices[] = // 0x0073D56C
{
    -1, 0, 1, -1, -1
};

#pragma pack(push, 1)
struct d2data_0073E5C0_t
{
    unsigned char b0[592];
};
#pragma pack(pop)

extern "C" struct d2data_0073E5C0_t gData_0073E5C0; // 0x0073E5C0

extern char gpAct4Q0NpcMessages[392] = {
    111, 1, 0, 0, -104, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, -1, -1, -1, -1, 0, 0, 0, 0, 2
}; // 0x0073D580

extern char gpAct4Q1NpcMessages[1176] = {
    111, 1, 0, 0, -98, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, 111, 1, 0, 0, -97, 2, 0, 0, 2, 0, 0, 0,
    -10, 0, 0, 0, -96, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 2, 0, 0, 0, 111, 1, 0, 0, -95, 2, 0, 0,
    2, 0, 0, 0, -10, 0, 0, 0, -94, 2, 0, 0, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 111, 1, 0, 0,
    -92, 2, 0, 0, 1, 0, 0, 0, -10, 0, 0, 0, -91, 2, 0, 0,
    2, 0, 0, 0, -106, 1, 0, 0, -93, 2, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0,
    111, 1, 0, 0, -92, 2, 0, 0, 2, 0, 0, 0, -10, 0, 0, 0,
    -91, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    2, 0, 0, 0, -1, -1, -1, -1, 0, 0, 0, 0, 2
}; // 0x0073D708

extern int gpAct4Q2NpcMessages[343] = {
    367, 681, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 367, 683, 2, 246, 682, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 2, 367, 684, 1, 246, 685, 1, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 2, 367, 684, 2, 246, 685, 2, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 2, 367, 20000, 1, 246, 20001, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 2, 367, 20000, 2, 246, 20001, 2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 2, -1, 0, 2
}; // 0x0073DBB8

extern char gpAct4Q3NpcMessages[980] = {
    -10, 0, 0, 0, -90, 2, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    1, 0, 0, 0, -10, 0, 0, 0, -89, 2, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0, -10, 0, 0, 0, -88, 2, 0, 0,
    1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, -10, 0, 0, 0,
    -88, 2, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
    -1, -1, -1, -1, 0, 0, 0, 0, 2
}; // 0x0073E140

extern "C" struct d2data_0073E5C0_t gData_0073E5C0 = {
    {
        0x98, 0x01, 0x00, 0x00, 0x9C, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x01, 0x00, 0x00, 0x00, 0x98, 0x01, 0x00, 0x00, 0x9D, 0x02, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00,
        0x02
    }
}; // 0x0073E5C0
#pragma comment(linker, "/alternatename:?gpAct4Q4NpcMessages@@3PADA=_gData_0073E5C0")

extern unsigned int gnHellforgeRunesNormal[11] = { 0x20313072, 0x20323072, 0x20333072, 0x20343072, 0x20353072, 0x20363072, 0x20373072, 0x20383072, 0x20393072, 0x20303172, 0x20313172 }; // 0x0073E114

extern unsigned int gnHellforgeRunesNightmare[11] = { 0x20323172, 0x20333172, 0x20343172, 0x20353172, 0x20363172, 0x20373172, 0x20383172, 0x20393172, 0x20303272, 0x20313272, 0x20323272 }; // 0x0073E514

extern unsigned int gnHellforgeRunesHell[11] = { 0x20353172, 0x20363172, 0x20373172, 0x20383172, 0x20393172, 0x20303272, 0x20313272, 0x20323272, 0x20333272, 0x20343272, 0x20353272 }; // 0x0073E540

extern unsigned int gnHellforgeGemsFirst[7] = { 0x20767067, 0x20727067, 0x20627067, 0x20797067, 0x20677067, 0x20777067, 0x207A6B73 }; // 0x0073E56C

extern unsigned int gnHellforgeGemsMiddle[7] = { 0x20767A67, 0x20726C67, 0x20626C67, 0x20796C67, 0x20676C67, 0x20776C67, 0x206C6B73 }; // 0x0073E588

extern unsigned int gnHellforgeGemsLast[7] = { 0x20767367, 0x20727367, 0x20627367, 0x20797367, 0x20677367, 0x20777367, 0x20756B73 }; // 0x0073E5A4

extern int gnAct4Q1NpcMessageIndices[6] = { -1, 0, 1, 2, 3, 4 }; // 0x0073DBA0

extern int gnAct4Q1NpcMessageIndices[]; // 0x0073DBA0

// 0x005B3BB0
void __fastcall ACT4Q1_Callback00_NpcActivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    const int bRewardGranted = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0);
    const int bPrimaryGoalDone = QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 13);

    int nNpcId;
    if (!pQuestArg->pTarget)
    {
        nNpcId = -1;
    }
    else
    {
        nNpcId = pQuestArg->pTarget->dwClassId;
        if (nNpcId == 406 && !QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 5))
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, 406, 3);
            return;
        }
    }

    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 1))
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 3);
    }
    else if (QUESTS_CheckPlayerGUID(pQuestData, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId) == 1)
    {
        QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, 4);
    }
    else if (bRewardGranted != 1 && (pQuestData->fState < 4 || bPrimaryGoalDone))
    {
        if (!pQuestData->bNotIntro)
        {
            return;
        }

        const int nIndex = gnAct4Q1NpcMessageIndices[pQuestData->fState];
        if (nIndex != -1 && (unsigned int)nIndex < 6)
        {
            QUESTS_InitScrollTextChain(pQuestData, pQuestArg->pTextControl, nNpcId, nIndex);
        }
    }
}

// 0x005B3CD0
int __fastcall ACT4Q1_UnitIterate_SetCompletionFlag(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 25, 0) != 1 && QUESTRECORD_GetQuestState(pQuestFlags, 25, 1) != 1)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 25, 14);
        QUESTS_SendLogUpdateEx(pUnit, 22, 0);
    }

    return 0;
}

// 0x005B3D30
int __fastcall ACT4Q1_UnitIterate_AttachCompletionSound(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 25, 13))
    {
        SUNIT_AttachSound(pUnit, 74, pUnit);
    }

    return 0;
}

// 0x005B3D70
void __fastcall ACT4Q1_UnitIterate_SetPrimaryGoalDone(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, 25, 0) == 1 || QUESTRECORD_GetQuestState(pQuestFlags, 25, 1))
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (!nLevelId || DRLG_GetActNoFromLevelId(nLevelId) != 3)
    {
        return;
    }

    QUESTRECORD_SetQuestState(pQuestFlags, 25, 13);
    QUESTRECORD_SetQuestState(pQuestFlags, 25, 1);
    QUESTRECORD_ResetIntermediateStateFlags(pQuestFlags, 25);
}

// 0x005B3DE0
int __fastcall ACT4Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 25, 13))
    {
        return 0;
    }
    const unsigned short nPartyId = SUNIT_GetPartyId(pUnit);
    if (nPartyId != 0xFFFF)
    {
        PARTY_IteratePartyMembers(pGame, nPartyId, ACT4Q1_UnitIterate_SetPrimaryGoalDone, 0);
    }
    return 0;
}

inline D2BitBufferStrc* sub_00543520(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    return UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
}

// 0x005B3E30
void __fastcall ACT4Q3_Callback10_PlayerLeavesGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    QUESTS_FastRemovePlayerGUID(&pQuestData->tPlayerGUIDs, !pQuestArg->pPlayer ? -1 : pQuestArg->pPlayer->dwUnitId);
}

// 0x005B3E60
bool __fastcall ACT4Q1_SpawnIzualGhost(D2GameStrc* pGame, D2QuestDataStrc* pQuest)
{
    D2Act4Quest1Strc* pQuestDataEx = (D2Act4Quest1Strc*)pQuest->pQuestDataEx;
    if (pQuest->fState == 4 && pQuest->fLastState != 4 && pQuest->fLastState != 13)
    {
        pQuest->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuest, 3, 0, ACT4Q1_UnitIterate_StatusCyclerEx, 1);
    }

    if (pQuestDataEx->bNeedToSpawnIzualGhost)
    {
        pQuestDataEx->bNeedToSpawnIzualGhost = 0;

        D2ActiveRoomStrc* pRoom = DUNGEON_FindRoomBySubtileCoordinates(pGame->pAct[3], pQuestDataEx->pCoords.nX, pQuestDataEx->pCoords.nY);
        if (pRoom)
        {
            if (!D2GAME_SpawnMonster(pGame, pRoom, pQuestDataEx->pCoords.nX, pQuestDataEx->pCoords.nY, MONSTER_IZUALGHOST, 8, -1, 0)
                && !D2GAME_SpawnMonster(pGame, pRoom, pQuestDataEx->pCoords.nX, pQuestDataEx->pCoords.nY, MONSTER_IZUALGHOST, 8, 3, 0))
            {
                D2GAME_SpawnMonster(pGame, pRoom, pQuestDataEx->pCoords.nX, pQuestDataEx->pCoords.nY, MONSTER_IZUALGHOST, 8, 5, 0);
            }
        }
    }

    pQuestDataEx->bIzualGhostIsSpawning = 0;
    return 1;
}


// 0x005B3F20
int __fastcall ACT4Q1_UnitIterate_SetRewardPending(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 22);
    D2_ASSERT(pQuestData, 452);

    D2Act4Quest1Strc* pQuestDataEx = (D2Act4Quest1Strc*)pQuestData->pQuestDataEx;
    D2ActiveRoomStrc* pTargetRoom = UNITS_GetRoom(pQuestDataEx->pTargetUnit);
    if (!pRoom)
    {
        return 0;
    }

    int bFound = 0;
    if (pRoom == pTargetRoom)
    {
        bFound = 1;
    }
    else
    {
        D2ActiveRoomStrc* pUnitRoom = UNITS_GetRoom(pUnit);
        D2_ASSERT(pUnitRoom, 473);

        D2ActiveRoomStrc** ppRoomList;
        int nNumRooms;
        DUNGEON_GetAdjacentRoomsListFromRoom(pUnitRoom, &ppRoomList, &nNumRooms);
        for (unsigned int i = 0; i < nNumRooms; ++i)
        {
            if (ppRoomList[i] == pTargetRoom)
            {
                bFound = 1;
                break;
            }
        }
    }

    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pUnit)->pQuestData[pGame->nDifficulty];
    if (!QUESTRECORD_GetQuestState(pQuestFlags, 25, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 25, 1) && bFound)
    {
        QUESTRECORD_SetQuestState(pQuestFlags, 25, 13);
        QUESTRECORD_SetQuestState(pQuestFlags, 25, 1);
    }
    return 0;
}

// 0x005B4020
void __fastcall ACT4Q1_Callback08_MonsterKilled(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2Act4Quest1Strc* pQuestDataEx = (D2Act4Quest1Strc*)pQuestData->pQuestDataEx;
    QUESTS_DebugOutput(pQuestData->pGame, "Finished quest", "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q1.cpp", 511);

    pQuestData->pCallback[2] = 0;

    QUESTS_StateDebug(pQuestData, 4, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q1.cpp", 513);

    pQuestData->pCallback[8] = 0;

    pQuestDataEx->pTargetUnit = pQuestArg->pTarget;
    if (pQuestData->bNotIntro)
    {
        if (pQuestArg->pPlayer)
        {
            D2GameStrc* pGame = pQuestArg->pGame;
            D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
            if (!QUESTRECORD_GetQuestState(pQuestFlags, 25, 0) && !QUESTRECORD_GetQuestState(pQuestFlags, 25, 1))
            {
                QUESTRECORD_SetQuestState(pQuestFlags, 25, 13);
                QUESTRECORD_SetQuestState(pQuestFlags, 25, 1);
                QUESTRECORD_ResetIntermediateStateFlags(pQuestFlags, pQuestData->eFilter);
            }
        }
        pQuestDataEx->bNeedToSpawnIzualGhost = 1;
        UNITS_GetCoords(pQuestArg->pTarget, &pQuestDataEx->pCoords);

        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT4Q1_UnitIterate_SetRewardPending);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT4Q1_UnitIterate_SetPrimaryGoalDoneForPartyMembers);
        SUNIT_IterateUnitsOfType(pQuestArg->pGame, 0, pQuestArg->pTarget, ACT4Q1_UnitIterate_SetCompletionFlag);
    }

    if (!pQuestDataEx->bIzualGhostIsSpawning)
    {
        pQuestDataEx->bIzualGhostIsSpawning = 1;
        QUESTS_CreateTimer(pQuestData, ACT4Q1_SpawnIzualGhost, 3);
    }
}

// 0x005B4140
void __fastcall ACT4Q1_Callback03_ChangedLevel(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (pQuestArg->nOldLevel != 103)
    {
        return;
    }
    QUESTS_QuickRemovePlayerGUID(pQuestData, pQuestArg);
    if (pQuestData->fState != 2)
    {
        return;
    }
    D2UnitStrc* pPlayer = pQuestArg->pPlayer;
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) == 1)
    {
        return;
    }
    QUESTS_StateDebug(pQuestData, 3, "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q1.cpp", 571);
    SUNIT_IterateUnitsOfType(pQuestData->pGame, 0, 0, ACT4Q1_UnitIterate_UpdateQuestStateFlags);
    if (!pQuestData->fLastState)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 1, 0, ACT4Q1_UnitIterate_StatusCyclerEx, 0);
    }
}

// 0x005B41D0
void __fastcall ACT4Q1_Callback02_NpcDeactivate(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    if (!pQuestArg->pTarget || (unsigned short)pQuestArg->pTarget->dwClassId != 367)
    {
        return;
    }
    D2Act4Quest1Strc* pQuestDataEx = (D2Act4Quest1Strc*)pQuestData->pQuestDataEx;
    if (pQuestDataEx->bTyraelActivated != 1)
    {
        return;
    }
    pQuestData->nStatusFlags = 0;
    QUESTS_UnitIterate(pQuestData, 1, 0, ACT4Q1_UnitIterate_StatusCyclerEx, 1);
    pQuestDataEx->bTyraelActivated = 0;
    pQuestData->pCallback[2] = 0;
}

// 0x005B4220
void __fastcall ACT4Q1_Callback13_PlayerStartedGame(D2QuestDataStrc* pQuestData, D2QuestArgStrc* pQuestArg)
{
    D2GameStrc* pGame = pQuestArg->pGame;
    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pQuestArg->pPlayer)->pQuestData[pGame->nDifficulty];
    if (QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 0) || QUESTRECORD_GetQuestState(pQuestFlags, pQuestData->eFilter, 15))
    {
        return;
    }
    if (QUESTRECORD_GetQuestState(pQuestFlags, 25, 4) == 1)
    {
        D2Act4Quest1Strc* pQuestDataEx = (D2Act4Quest1Strc*)pQuestData->pQuestDataEx;
        pQuestDataEx->bPlayerStartedGame = 1;
        pQuestData->fLastState = 2;
        pQuestData->fState = 3;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 25, 3) == 1)
    {
        pQuestData->fState = 3;
        pQuestData->fLastState = 1;
    }
    else if (QUESTRECORD_GetQuestState(pQuestFlags, 25, 2) == 1)
    {
        pQuestData->fState = 2;
        pQuestData->fLastState = 1;
    }
}

// 0x005B42B0
void __fastcall ACT4Q1_InitQuestData(D2QuestDataStrc* pQuestData)
{
    memset(pQuestData->pCallback, 0x00, sizeof(pQuestData->pCallback));
    pQuestData->bActive = 1;
    pQuestData->fState = 1;
    pQuestData->pNPCMessages = gpAct4Q1NpcMessages;
    pQuestData->pCallback[10] = ACT4Q3_Callback10_PlayerLeavesGame;
    pQuestData->pCallback[3] = ACT4Q1_Callback03_ChangedLevel;
    pQuestData->pCallback[8] = ACT4Q1_Callback08_MonsterKilled;
    pQuestData->pCallback[0] = ACT4Q1_Callback00_NpcActivate;
    pQuestData->pCallback[2] = ACT4Q1_Callback02_NpcDeactivate;
    pQuestData->pCallback[11] = ACT4Q1_Callback11_ScrollMessage;
    pQuestData->pCallback[13] = ACT4Q1_Callback13_PlayerStartedGame;
    pQuestData->eFilter = 25;
    pQuestData->nInitNo = 4;
    pQuestData->pfStatusFilter = 0;
    pQuestData->pfActiveFilter = ACT4Q1_ActiveFilterCallback;
    D2Act4Quest1Strc* pQuestDataEx = (D2Act4Quest1Strc*)FOG_AllocPool(pQuestData->pGame->pMemoryPool, sizeof(D2Act4Quest1Strc), "d:\\diablo2\\Diablo2\\Source\\D2Game/Quests/a4q1.cpp", 672, 0);
    pQuestData->pQuestDataEx = pQuestDataEx;
    pQuestData->pfSeqFilter = ACT4Q1_SeqCallback;
    pQuestData->nSeqId = 24;
    memset(pQuestDataEx, 0x00, sizeof(D2Act4Quest1Strc));
}

// 0x005B4390
void __fastcall ACT4Q1_OnIzualActivated(D2GameStrc* pGame)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 22);

    if (pQuestData && pQuestData->bNotIntro && pQuestData->fLastState < 2)
    {
        pQuestData->nStatusFlags = 0;
        QUESTS_UnitIterate(pQuestData, 2, 0, ACT4Q1_UnitIterate_StatusCyclerEx, 1);
    }
}


// 0x005B43D0
void __fastcall ACT4Q1_UnitIterate_CheckDistanceToIzualGhost(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData)
{
    D2Act4Quest1Strc* pQuestDataEx = (D2Act4Quest1Strc*)pData;
    if (DRLG_UnitEdgeDistance(pUnit, pQuestDataEx->pTargetUnit) < 5)
    {
        pQuestDataEx->bCloseToIzualGhost = 1;
    }
}

typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0

// 0x005B43F0
int __fastcall ACT4Q1_IsAnyPlayerInRangeOfIzualGhost(D2GameStrc* pGame, D2UnitStrc* pTargetUnit)
{
    D2QuestDataStrc* pQuestData = QUESTS_GetQuestData(pGame, 22);
    if (pQuestData)
    {
        D2Act4Quest1Strc* pQuestDataEx = (D2Act4Quest1Strc*)pQuestData->pQuestDataEx;
        if (pQuestDataEx->bIzualGhostActivated)
        {
            pQuestDataEx->bCloseToIzualGhost = 0;
            pQuestDataEx->pTargetUnit = pTargetUnit;
            SUNIT_IterateLivingPlayers(pGame, ACT4Q1_UnitIterate_CheckDistanceToIzualGhost, pQuestDataEx);

            return !pQuestDataEx->bCloseToIzualGhost;
        }
    }

    return 0;
}

// 0x005B4440
void __fastcall ACT4Q1_AttachCompletionSoundToPlayers(D2GameStrc* pGame)
{
    SUNIT_IterateUnitsOfType(pGame, 0, 0, ACT4Q1_UnitIterate_AttachCompletionSound);
}


int __fastcall OBJECTS_OperateFunction28_LamEsenTome(D2ObjOperateFnStrc* pOp, int nOperate);
