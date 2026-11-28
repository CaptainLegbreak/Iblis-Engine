#include "D2ItemTypes.h"
#include "D2StateIds.h"
#include "D2SkillIds.h"
#include "D2MonsterIds.h"
#include "D2LevelIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2GameRecords.h"
#include "D2QuestData.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Drlg.h"
#include "D2Primitives.h"
#include "D2DrlgRooms.h"
#include "D2GameServer.h"
#include "D2GameClient.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2ItemsWorld.h"
#include "D2LevelTxt.h"
#include "D2PlayerModes.h"
#include "D2ItemModes.h"
#include "D2SaveHeader.h"
#include "D2LanguageNames.h"
#include "D2GameCallbackArgs.h"
#include "D2DrlgDelete.h"
#include "D2NpcEvent.h"
#include "FogApi.h"
#include "StormApi.h"
#include "D2CommonApi.h"
#include "FogApi.h"
#include "D2ClientApi.h"

#pragma function(memset)

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_PLAYER 0

#define UNIT_OBJECT 2

#define UNIT_ITEM 4

#define UNIT_TILE 5

#define STAT_GOLD 14

#define ITEMACTION_DROPTOGROUND 2

#define ITEMACTION_ONGROUND 3

#define ACT_II 1

#define ACT_III 2

#define EVENTTYPE_REMOVESTATE 12

#define QUESTSTATEFLAG_A2Q6 14

#define QUESTSTATEFLAG_A5Q4 38

#define QUEST_A5Q4_NIHLATHAK 34

#define QFLAG_REWARDGRANTED 0

#define QFLAG_REWARDPENDING 1

#define QFLAG_LEAVETOWN 3

#define QFLAG_ENTERAREA 4

#define QFLAG_CUSTOM2 6

#define QFLAG_CUSTOM3 7

#define QFLAG_CUSTOM4 8

#define QFLAG_CUSTOM6 10

#define QFLAG_CUSTOM7 11

#define QFLAG_PRIMARYGOALDONE 13

#define QFLAG_COMPLETEDNOW 14

#define CLIENTSAVEFLAG_HARDCORE 0x4

#define CLIENTSAVEFLAG_DEAD 0x8

#define CLIENTSAVEFLAG_EXPANSION 0x20

#define CLIENTSAVEFLAG_LADDER 0x40

#define GAMEFLAG_ARENA_HARDCORE 0x800

#define NUM_DIFFICULTIES 3

#define PLRSAVE2ERROR_BAD_PLAYERINTRO 11

struct D2CorpseStrc;

struct D2SaveHeaderStrc;

struct D2ServerCallbackFunctions;

struct D2ClientInfoStrc;

union D2SeedStrc;

struct D2StaticPathStrc;

struct D2PlayerDataStrc;

struct D2SkillsTxt;

struct D2PartyNodeStrc;

struct D2PartyStrc;

struct D2PartyControlStrc;

struct D2CorpseSaveStrc;

struct D2LargeIntegerStrc;

struct D2FileTimeStrc;

struct D2UnitProxyArgStrc;

struct D2UnitFindArgStrc;

struct D2Act2Quest6Strc;

struct D2Act5Quest4Strc;

struct D2StatesTxt;

struct D2PlrIntroSaveStrc;

struct D2RosterIterateStrc;

struct D2SavedItemStrc;

struct D2ItemKeyStrc;

struct D2GameStrc;

struct D2InventoryStrc;

struct D2ActiveRoomStrc;

struct D2UnitStrc;

struct D2CoordStrc;

struct D2ClientStrc;

struct D2DrlgActStrc;

struct D2CriticalSectionStrc;

struct D2UnitFindDataStrc;

struct D2QuestDataStrc;

struct D2DataTablesStrc;

struct D2ItemDropStrc;

struct D2ItemSaveStrc;

struct D2HirelingTxt;

struct D2CharStatsTxt;

struct D2BitBufferStrc;

struct D2ItemsTxt;

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc*,int); // 0x00624690

unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc*); // 0x00627D40


#include "D2GameFuncs.h"
#include "D2HellApi.h"
#include "FogApi2.h"


typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09





int __stdcall SUNIT_GetInteractInfo(D2UnitStrc* pUnit, int* pUnitType, int* pUnitGUID); // 0x00554100


int __fastcall sub_00564CA0_Return1(D2UnitStrc* pItem); // 0x00564CA0



void __fastcall PLRSAVE_CountInventoryItems(int nCount); // 0x00531750

typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);


D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60





int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit); // 0x00622E70


struct D2CorpseSaveStrc
{
    unsigned int unk0x00;
    int nX;
    int nY;
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0



__declspec(noalias) int __fastcall PLRSAVE2_CreateSaveFile(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pData, unsigned int* pSize, unsigned int nMaxSize, int bUseTradeInventory, int nUnused); // 0x00569AD0


extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern D2CriticalSectionStrc gSrvClientListByNameLock; // 0x008846C0

extern D2ClientStrc* gpClientListByName[256]; // 0x00883EA8

extern int gbHasHighResolutionClock; // 0x0088C7A0

extern D2LargeIntegerStrc gPerformanceFrequency; // 0x0088C790

extern D2ServerCallbackFunctions* gpD2EventCallbackTable; // 0x00883D50

extern int gbD2ServerCallbackFunctionsInitialized; // 0x00883D54




extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260


extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0





void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0


void __stdcall SUNITPROXY_UpdateVendorInventory(D2GameStrc* pGame, unsigned char nAct, int bStale); // 0x00537230









extern "C" _iobuf* __cdecl fopen(const char* szFileName, const char* szMode); // 0x0068239A

extern "C" unsigned int __cdecl fwrite(const void* pBuffer, unsigned int nSize, unsigned int nCount, _iobuf* pFile);

extern "C" int __cdecl fclose(_iobuf* pFile); // 0x00681FDC


D2SaveHeaderStrc* __fastcall CLIENTS_GetSaveHeader(D2ClientStrc* pClient); // 0x00538E00


void __fastcall D2GAME_SetSaveLoadComplete(D2ClientStrc* pClient); // 0x00538F80

extern "C" int __stdcall sub_00554100(D2UnitStrc* pUnit, int* pUnitType, int* pUnitGUID); // 0x00554100

extern "C" void __fastcall CLIENTS_GetCharSaveTransactionToken(D2ClientStrc* pClient, unsigned int* pOut); // 0x00539300

extern "C" void __fastcall CLIENTS_GetClientInfo(D2ClientStrc* pClient, unsigned int* pOut); // 0x00539310


extern "C" const char gszSaveFormat_006D4230[]; // 0x006D4230

extern "C" const char gszFileModeWb[]; // 0x006D69E0

extern "C" const char gszSaveOpenError[]; // 0x006E09C4

extern "C" const char gszPlrSaveSourceFile[]; // 0x006E09AC

typedef int (__stdcall* FARPROC)();

extern int gnUnchangedSaveCount; // 0x00883D6C

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

unsigned int __fastcall D2GAME_GetSaveChecksumFromClient(D2ClientStrc* pClient); // 0x00538350


int __fastcall CLIENTS_GetSaveHeaderSize(D2ClientStrc* pClient); // 0x00538E30

void __fastcall CLIENTS_SetClientInfo(D2ClientStrc* pClient, unsigned int nClientInfo); // 0x00539320

void __fastcall D2GAME_SetSaveFileChecksum(D2ClientStrc* pClient, unsigned int nChecksum); // 0x00538380


struct D2PlrIntroSaveStrc
{
    unsigned short nHeader;
    unsigned short nLength;
    unsigned char nQuestIntroFlags[NUM_DIFFICULTIES][8];
    unsigned char nNpcIntroFlags[NUM_DIFFICULTIES][8];
};




D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0


extern "C" char* __cdecl strcpy(char* pDst, const char* pSrc);


#pragma pack(push, 1)

struct D2SavedItemStrc
{
    unsigned char nBodyLoc;
    unsigned char nSocketedItems;
    int nItemLevel;
    int nItemId;
    unsigned char nSpawnType;
    unsigned char nItemQuality;
    int nQuantity;
    int nMinDurability;
    int nMaxDurability;
    int nX;
    int nY;
    int nItemIndex;
    unsigned int nItemFlags;
    unsigned int nSeed;
    unsigned int nItemSeed;
    unsigned char nInvPage;
    unsigned char nEarLevel;
    char szName[16];
    unsigned short nItemFormat;
    unsigned int nItemCode;
};

#pragma pack(pop)

struct D2ItemKeyStrc
{
    unsigned int nCode;
    int nIndex;
    int nLevel;
    unsigned int nSeed;
    unsigned int nItemSeed;
};


void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280



int __stdcall INVENTORY_PlaceItemInBodyLoc(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nBodyLoc); // 0x0063BDB0


int __stdcall INVENTORY_PlaceItemInSocket(D2InventoryStrc* pInventory, D2UnitStrc* pItem, int nPage); // 0x0063B210


static int __stdcall PLRSAVE_PlaceCorpseItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2UnitStrc* pParent); // 0x00531520


D2UnitStrc* __fastcall ITEMS_CreateItemFromBitstream(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char* pBitstream, unsigned int nBufferSize, int bCheckForHeader, D2ItemSaveStrc* pItemSave, int* pSize, unsigned int dwVersion); // 0x00558CB0


static int PLRSAVE_ClearValue(int* pValue);

static D2UnitStrc* PLRSAVE_CreateItemFromSavedData(D2GameStrc* pGame, D2SavedItemStrc* pSavedItem); // 0x00530F40


D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char nAllocFlags, int nMode, unsigned int nOverrideUnitGUID); // 0x00555230


void __fastcall PLAYER_CreateStartItemsFromCharStatsTxt(D2UnitStrc* pPlayer, D2GameStrc* pGame, unsigned char nAct); // 0x00534F10


extern "C" unsigned int __stdcall ITEMS_CheckIfFlagIsSet(unsigned int dwA, unsigned int dwB); // 0x006287A0


struct D2QuestSaveSectionStrc;

#pragma pack(push, 1)

struct D2QuestSaveSectionStrc
{
    unsigned int dwHeaderMagic;
    unsigned int dwVersion;
    unsigned short nSize;
    unsigned char pQuestRecord[3][96];
};

#pragma pack(pop)


int __stdcall STATLIST_GetMaxManaFromUnit(D2UnitStrc*); // 0x00625D60

int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc*); // 0x00625DB0


extern "C" const char gszPlrSaveSourceFile[]; // 0x006E09AC

void __fastcall D2GAME_SendPacket0x8E_CorpseAssign_ToAllPlayers(D2GameStrc* pGame, int nUnitId, int nCorpseId, unsigned char bAssign); // 0x0053DF80


static int __stdcall PLRSAVE_ReadCorpse(D2UnitStrc* pPlayer, D2GameStrc* pGame, unsigned char* pData, unsigned int nVersion, int nSize, int* pReadSize);

// 0x00531520
static int __stdcall PLRSAVE_PlaceCorpseItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2UnitStrc* pParent)
{
    switch (!pItem ? 0 : pItem->dwAnimMode)
    {
    case 6:
        if (pParent)
        {
            UNITS_ChangeAnimMode(pItem, 4);
            const int nParentGUID = pParent->dwUnitId;
            const int nItemGUID = !pItem ? -1 : pItem->dwUnitId;
            int bPlaced;
            if (D2GAME_ITEMSOCKET_PlaceItem(pGame, pPlayer, nItemGUID, nParentGUID, &bPlaced, 0, 1, 0, 0))
                break;
        }
    default:
        return 13;
    case 1:
        {
            D2InventoryStrc* pInventory = pPlayer->pInventory;
            const int nBodyLoc = ITEMS_GetBodyLocation(pItem);
            if (!nBodyLoc || !INVENTORY_PlaceItemInBodyLoc(pInventory, pItem, nBodyLoc))
                return 13;
            int nPage = 3;
            if (nBodyLoc == 11 || nBodyLoc == 12)
                nPage = 4;
            if (!INVENTORY_PlaceItemInSocket(pInventory, pItem, nPage))
                return 13;
            ITEMS_SetBodyLocation(pItem, nBodyLoc);
            if (pItem)
                pItem->dwFlags &= ~2u;
            UNITS_ChangeAnimMode(pItem, 1);
            ITEMS_SetInvPage(pItem, 255);
            ITEMS_SetItemCMDFlag(pItem, 8, 1);
            if (pItem)
                pItem->dwFlags &= ~0x02000000u;
            INVENTORY_AddItemToTradeInventory(pInventory, pItem);
            UNITS_RefreshInventory(pPlayer, 1);
            QUESTS_ItemPickedUp(pGame, pPlayer, pItem);
            break;
        }
    case 0:
        {
            UNITS_ChangeAnimMode(pItem, 4);
            int nY;
            switch (pItem->dwUnitType)
            {
            case UNIT_OBJECT:
            case UNIT_ITEM:
            case UNIT_TILE:
                nY = pItem->pStaticPath->nYPos;
                break;
            default:
                nY = pItem->pDynamicPath ? PATH_GetYPosition(pItem->pDynamicPath) : 0;
                break;
            }
            int nX;
            switch (pItem->dwUnitType)
            {
            case UNIT_OBJECT:
            case UNIT_ITEM:
            case UNIT_TILE:
                nX = pItem->pStaticPath->nXPos;
                break;
            default:
                nX = pItem->pDynamicPath ? PATH_GetXPosition(pItem->pDynamicPath) : 0;
                break;
            }
            const int nItemGUID = pItem->dwUnitId;
            if (D2GAME_PlaceItem(".\\PLAYER\\PlrSave.cpp", 536, pGame, pPlayer, nItemGUID, nX, nY, 0, 0, 0))
                break;
            return 13;
        }
    }
    return 0;
}

#define WRITE_ITEM(pItem) { const int nSize = D2GAME_SAVE_SerializeItem(pGame, pUnit, pItem, pData, nBufferSize - (pData - pBuffer), bUseTradeInventory, nUnused, bSizing); if (nSize < 0) return -1; pData += nSize; if (!nSize && nItems > 0) --nItems; }

#define PREPARE_ITEM(pItem) (ITEMS_SerializeItemToBitstream(pItem, tempBuffer, sizeof(tempBuffer), 1, 1, 0))

#define UNIT_MONSTER 1

#define SYSERROR_BAD_WAYPOINT 3

#define WAYPOINT_MAGIC 0x5357

#define UNITFLAG_TARGETABLE 0x02

#define UNITFLAG_CANBEATTACKED 0x04

#define UNITFLAG_ISVALIDTARGET 0x08

#define UNITFLAG_INITSEEDSET 0x10

#define EVENTTYPE_FREEHOVER 3

#define EVENTTYPE_STATREGEN 4

#define EVENTTYPE_TRAP 6

#define COLLIDE_MASK_CORPSE 0x9C19

#define CLIENTFLAGEX_HAS_SAVE_CHECKSUM 0x08

struct D2SkillListStrc;

struct D2WaypointSaveRecordStrc;

struct D2WaypointSaveSectionStrc;

struct D2CharItemStrc;

struct D2DrlgDeleteStrc;

static unsigned short PLRSAVE_CountInventoryItems(D2InventoryStrc* pInventory); // 0x00531750


int __fastcall D2GAME_SAVE_SerializeItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned char* pBitstream, unsigned int nSize, int bUseTradeInventory, int nUnused, int bSizing); // 0x005316D0

static void __stdcall PLRSAVE_SaveToLocalFile(int bInteractsWithPlayer, unsigned int dwArg, D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName);

struct D2WaypointSaveRecordStrc
{
    unsigned short nFlags;
    unsigned short unk0x02;
    int unk0x04[5];
};

struct D2WaypointSaveSectionStrc
{
    unsigned short nMagic;
    unsigned short unk0x02;
    int unk0x04;
    D2WaypointSaveRecordStrc pRecords[3];
};


typedef void (__fastcall* STATLIST_CallbackFn)(D2GameStrc* pGame, D2UnitStrc* pOwner, D2UnitStrc* pOther, int nLayer_StatId, int nPreviousValue, int nNewValue);

extern int gbClientListInitialized; // 0x008846D8

extern D2CriticalSectionStrc gClientListLock; // 0x008846A8

extern D2ClientStrc* gpClientList[256]; // 0x008842A8


void __fastcall QUESTS_UpdateNPCIntros(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char nAct); // 0x00545100





void __fastcall PLRTRADE_StopInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00568760


void __fastcall ACT5Q5_OnPlayerDied(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058D560




void __stdcall UNITS_SetSwitchLeftSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00623300

void __stdcall UNITS_SetSwitchRightSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00623350


D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner); // 0x0063ABD0



void __stdcall WAYPOINTS_CopyAndValidateWaypointData(D2WaypointDataStrc* pDest, const D2WaypointSaveRecordStrc* pSource); // 0x00661030

static int __stdcall PLRSAVE_CreateNewPlayer(D2GameStrc* pGame, D2ClientStrc* pClient, D2UnitStrc** ppPlayer); // 0x00532590

static int __stdcall D2GAME_SAVE_ReadFile(D2GameStrc* pGame, D2ClientStrc* pClient, const char* szName, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoomArg, int nXArg, int nYArg); // 0x005343A0

static int __stdcall PLRSAVE_ReadSaveFromDisk(D2GameStrc* pGame, D2ClientStrc* pClient, const char* szName, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoomArg, int nXArg, int nYArg); // 0x005344B0

static int __stdcall PLRSAVE_ReadSaveFromClient(D2GameStrc* pGame, D2ClientStrc* pClient, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoomArg, int nXArg, int nYArg); // 0x00534520


#pragma pack(push, 1)

struct D2LegacySaveHeaderStrc
{
 unsigned int dwMagic;
 unsigned int dwVersion;
 char szName[16];
 unsigned int dwFlags;
 unsigned short nSkills;
 unsigned short nStats;
 unsigned short nHeaderSize;
 unsigned short nClass;
 char unk24[0x22];
 unsigned char hotkeys[8][2];
 unsigned char nLeftSkill;
 unsigned char nRightSkill;
 unsigned char nLocation;
 unsigned char guildFlags[2];
 char guildTag[4];
 char guildName[28];
 unsigned char guildColors[3];
 unsigned int nMapSeed;
};

#pragma pack(pop)

typedef char LegacyHeaderSizeCheck[sizeof(D2LegacySaveHeaderStrc)==130?1:-1];

extern "C" int __cdecl _stricmp(const char*,const char*); // 0x006841E9

void __fastcall sub_00538630(D2ClientStrc*,unsigned short); // 0x00538630


void __fastcall CLIENTS_SetGuildFlags(D2ClientStrc*,int); // 0x00539120

void __fastcall CLIENTS_SetGuildTag(D2ClientStrc*,char*); // 0x00539140

void __fastcall CLIENTS_SetGuildName(D2ClientStrc*,char*); // 0x00539170

void __fastcall CLIENTS_SetGuildEmblem(D2ClientStrc*,unsigned char,int,int); // 0x005391C0

void __fastcall sub_00539230_SetFlag(D2ClientStrc*,unsigned char); // 0x00539230


#define SYSERROR_CORPSES 6

struct _iobuf;

#define ACT_I 0

#define GAMETYPE_1 1

#define GAMETYPE_2 2

#define SYSERROR_UNK_14 14





#pragma pack(push, 1)

struct D2LegacyMercSaveStrc
{
    unsigned short wMagic;
    unsigned int dwFlags;
    unsigned int dwSeed;
    unsigned short wName;
    unsigned short wHirelingId;
    unsigned int dwExperience;
};

#pragma pack(pop)


unsigned int __fastcall PLRSAVE_ConvertLegacyHirelingExperience(D2GameStrc*, unsigned short, unsigned int); // 0x00533BF0


void __fastcall sub_0055F4F0_Nop(D2GameStrc*, D2UnitStrc*, int); // 0x0055F4F0


int __fastcall PLRSAVE_ReadLegacyQuests(D2UnitStrc*, unsigned char*, int, int*); // 0x00532BE0

int __fastcall D2GAME_SAVE_ReadWaypointData(D2UnitStrc* pUnit, const unsigned char* pSection, int nUnused, int* pSize); // 0x00532C70

int __fastcall PLRSAVE_ReadLegacyPlayerIntro(D2UnitStrc*, unsigned char*, int, int*); // 0x00532D00

int __fastcall PLRSAVE_ReadLegacyStats(D2GameStrc*, D2UnitStrc*, unsigned char*, int, int, int*); // 0x00532DA0

int __fastcall PLRSAVE_ReadLegacySkills(D2GameStrc*, D2ClientStrc*, D2UnitStrc*, unsigned char*, int, int, int*); // 0x00532E90


void __fastcall sub_00568DB0_Return0(D2GameStrc*, D2UnitStrc*); // 0x00568DB0

int __fastcall PLRSAVE_ReadCorpseSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pSection, unsigned int dwVersion, int nRemainingSize, int* pSize); // 0x005339A0

int __stdcall PLRSAVE_ReadHotkeySection(D2UnitStrc* pPlayer, const unsigned char* pSection, unsigned int nSize, int* pSize); // 0x00533F70


unsigned char __fastcall CLIENTS_GetWeaponSwitch(D2ClientStrc*); // 0x00539220


static int __stdcall PLRSAVE_ReadLegacyMerc(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pSection, unsigned int nVersion, unsigned int nSize, int* pSize);

static void __stdcall PLRSAVE_SaveToClient(int bInteractsWithPlayer, D2GameStrc* pGame, D2UnitStrc* pPlayer, D2ClientStrc* pClient);


int __fastcall PLRSAVE_ReadLegacyHeader(D2GameStrc* pGame,D2ClientStrc* pClient,D2LegacySaveHeaderStrc* pSave,D2UnitStrc** ppPlayer,int* pNewPlayer,unsigned int* pVersion,int* pStats,int* pSkills,int* pLeft,int* pRight,int* pHeaderSize);

int __fastcall D2GAME_SAVE_ProcessSaveFile(D2GameStrc* pGame, D2ClientStrc* pClient, unsigned char* pSaveFile, unsigned int nSize, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoomArg, int nXArg, int nYArg); // 0x00534020


struct D2NpcControlStrc
{
    int nArraySize;
    D2NpcRecordStrc* pFirstRecord;
};


D2MonsterInteractStrc* __fastcall sub_00535E80_GetMonInteract(D2UnitStrc* pUnit);                           // 0x00535E80

struct D2NpcVendorStateStrc
{
    unsigned char bVendorInit;
    unsigned char unk0x01;
    unsigned char nAct;
    unsigned char bTrader;
    char unk0x04[3];
    unsigned char bRefreshInventory;
    unsigned int dwTicks;
};

static inline int sub_00451F50(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwUnitId;
}

// 0x00530F30
void __fastcall PLRSAVE_EnableSaveFileWriting(int nValue)
{
    gbWriteSaveFile = nValue;
}

// 0x00530F40
static D2UnitStrc* PLRSAVE_CreateItemFromSavedData(D2GameStrc* pGame, D2SavedItemStrc* pSavedItem)
{
    D2ItemDropStrc itemDrop;
    memset(&itemDrop, 0, sizeof(itemDrop));

    itemDrop.wItemFormat = pSavedItem->nItemFormat;
    itemDrop.nItemLvl = pSavedItem->nItemLevel;
    itemDrop.nId = pSavedItem->nItemId;
    itemDrop.nSpawnType = pSavedItem->nSpawnType;
    itemDrop.nX = pSavedItem->nX;
    itemDrop.nY = pSavedItem->nY;
    itemDrop.nQuality = pSavedItem->nItemQuality;
    itemDrop.nQuantity = pSavedItem->nQuantity;
    itemDrop.nMinDur = pSavedItem->nMinDurability;
    itemDrop.nMaxDur = pSavedItem->nMaxDurability;
    itemDrop.dwSeed = pSavedItem->nSeed;
    itemDrop.pGame = pGame;
    itemDrop.pRoom = 0;
    itemDrop.wUnitInitFlags = 1;
    itemDrop.dwItemSeed = pSavedItem->nItemSeed;
    itemDrop.dwFlags1 = pSavedItem->nItemFlags;
    itemDrop.bForce = 1;
    itemDrop.nItemIndex = pSavedItem->nItemIndex;

    strcpy(itemDrop.szName, pSavedItem->szName);

    *(unsigned char*)&itemDrop.eEarLvl = pSavedItem->nEarLevel;

    D2UnitStrc* pItem = D2GAME_CreateItemEx(pGame, &itemDrop, 0);
    if (!pItem)
        return 0;

    ITEMS_SetFileIndex(pItem, pSavedItem->nItemIndex);
    ITEMS_SetInvPage(pItem, pSavedItem->nInvPage);
    return pItem;
}

// 0x00531040
int __fastcall PLRSAVE_CreateAndPlaceLegacyPlayerItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2SavedItemStrc* pSavedItem, D2UnitStrc** ppItem, int* pSocketedItemCount)
{
    if (pSocketedItemCount)
    {
        *pSocketedItemCount = 0;
    }

    D2UnitStrc* pItem = PLRSAVE_CreateItemFromSavedData(pGame, pSavedItem);
    if (!pItem)
    {
        return 12;
    }

    switch (pItem->dwAnimMode)
    {
    case IMODE_STORED:
    {
        UNITS_ChangeAnimMode(pItem, 4);
        const int nX = pSavedItem->nX;
        const int nY = pSavedItem->nY;
        unsigned char nWidth;
        unsigned char nHeight;
        ITEMS_GetDimensions(pItem, &nWidth, &nHeight, ".\\PLAYER\\PlrSave.cpp", 0xE1);
        UNITS_SetXForStaticUnit(pItem, nX);
        UNITS_SetYForStaticUnit(pItem, nY);
        const int nItemId = pItem->dwUnitId;
        if (!D2GAME_PlaceItem(".\\PLAYER\\PlrSave.cpp", 0xEA, pGame, pPlayer, nItemId, CLIENTS_GetUnitX(pItem), CLIENTS_GetUnitY(pItem), 0, 1, 0))
        {
            return 12;
        }

        break;
    }
    case IMODE_EQUIP:
    {
        UNITS_ChangeAnimMode(pItem, 4);
        int nUnused;
        if (!ITEMMODE_EquipCursorItem(pGame, pPlayer, sub_00451F50(pItem), pSavedItem->nBodyLoc, 1, &nUnused))
        {
            return 12;
        }

        break;
    }
    case IMODE_INBELT:
    {
        UNITS_ChangeAnimMode(pItem, 4);
        UNITS_SetXForStaticUnit(pItem, pSavedItem->nX);
        UNITS_SetYForStaticUnit(pItem, pSavedItem->nY);
        int nUnused;
        if (!ITEMMODE_PlaceCursorItemInBelt(pGame, pPlayer, sub_00451F50(pItem), pSavedItem->nX, 0, &nUnused))
        {
            return 12;
        }

        break;
    }
    case IMODE_ONCURSOR:
    {
        UNITS_ChangeAnimMode(pItem, 4);
        INVENTORY_SetCursorItem(pPlayer->pInventory, pItem);
        if (!ITEMMODE_MarkItemOnCursor(pGame, pPlayer, pItem))
        {
            return 12;
        }

        break;
    }
    case IMODE_SOCKETED:
    {
        UNITS_ChangeAnimMode(pItem, 4);
        int nUnused;
        if (!*ppItem || !D2GAME_ITEMSOCKET_PlaceItem(pGame, pPlayer, sub_00451F50(pItem), sub_00451F50(*ppItem), &nUnused, 0, 1, 0, 0))
        {
            return 12;
        }

        break;
    }
    default:
        return 12;
    }

    if (pSavedItem->nSocketedItems > 0)
    {
        *ppItem = pItem;
    }

    if (pSocketedItemCount)
    {
        *pSocketedItemCount = pSavedItem->nSocketedItems;
    }

    return 0;
}

static inline unsigned int GetMode(D2UnitStrc* pUnit) { if (!pUnit) return 0; return pUnit->dwAnimMode; }

static inline int GetId(D2UnitStrc* pUnit) { if (!pUnit) return -1; return pUnit->dwUnitId; }

// 0x00531210
int __fastcall PLRSAVE_PlacePlayerItem(D2GameStrc* pGame,D2UnitStrc* pPlayer,D2UnitStrc* pItem,D2UnitStrc* pSocketItem)
{
    switch (GetMode(pItem))
    {
    case 0:
        {
            UNITS_ChangeAnimMode(pItem,4);
            int nId=GetId(pItem);
            if (!D2GAME_PlaceItem(".\\PLAYER\\PlrSave.cpp",319,pGame,pPlayer,nId,CLIENTS_GetUnitX(pItem),CLIENTS_GetUnitY(pItem),0,1,0))
                return 12;
            break;
        }
    case 1:
        {
            UNITS_ChangeAnimMode(pItem,4);
            int nId=GetId(pItem);
            int nResult;
            if (!ITEMMODE_EquipCursorItem(pGame,pPlayer,nId,ITEMS_GetBodyLocation(pItem),1,&nResult))
                return 12;
            break;
        }
    case 2:
        {
            UNITS_ChangeAnimMode(pItem,4);
            int nId=GetId(pItem);
            int nResult;
            if (!ITEMMODE_PlaceCursorItemInBelt(pGame,pPlayer,nId,CLIENTS_GetUnitX(pItem),0,&nResult))
                return 12;
            break;
        }
    case 4:
        UNITS_ChangeAnimMode(pItem,4);
        INVENTORY_SetCursorItem(pPlayer->pInventory,pItem);
        if (!ITEMMODE_MarkItemOnCursor(pGame,pPlayer,pItem))
            return 12;
        break;
    case 6:
        {
            UNITS_ChangeAnimMode(pItem,4);
            if (!pSocketItem) return 12;
            const int nSocketId = pSocketItem->dwUnitId;
            int nResult;
            if (!D2GAME_ITEMSOCKET_PlaceItem(pGame,pPlayer,GetId(pItem),nSocketId,&nResult,0,0,0,0))
                return 12;
            break;
        }
    default: return 12;
    }
    return 0;
}

// 0x00531390
static int __stdcall PLRSAVE_CreateAndPlaceLegacyCorpseItem(D2GameStrc* pGame, D2SavedItemStrc* pSavedItem, D2UnitStrc** ppItem, int* pSocketedItemCount, D2UnitStrc* pUnit)
{
    D2UnitStrc* pItem = PLRSAVE_CreateItemFromSavedData(pGame, pSavedItem);
    if (!pItem)
        return 13;

    switch (pItem->dwAnimMode)
    {
    case IMODE_STORED:
    {
        UNITS_ChangeAnimMode(pItem, 4);
        const int nX = pSavedItem->nX;
        const int nY = pSavedItem->nY;
        UNITS_SetXForStaticUnit(pItem, nX);
        UNITS_SetYForStaticUnit(pItem, nY);
        const int nItemId = pItem->dwUnitId;
        if (!D2GAME_PlaceItem(".\\PLAYER\\PlrSave.cpp", 0x1C2, pGame, pUnit, nItemId, CLIENTS_GetUnitX(pItem), CLIENTS_GetUnitY(pItem), 0, 0, 0))
            return 13;
        break;
    }
    case IMODE_EQUIP:
    {
        D2InventoryStrc* pInventory = pUnit->pInventory;
        const int nBodyLoc = ITEMS_GetBodyLocation(pItem);
        if (!nBodyLoc || !INVENTORY_PlaceItemInBodyLoc(pInventory, pItem, nBodyLoc))
            return 13;

        int nPage = 3;
        if (nBodyLoc == 11 || nBodyLoc == 12)
            nPage = 4;

        if (!INVENTORY_PlaceItemInSocket(pInventory, pItem, nPage))
            return 13;

        ITEMS_SetBodyLocation(pItem, nBodyLoc);
        pItem->dwFlags &= 0xFFFFFFFDu;
        UNITS_ChangeAnimMode(pItem, 1);
        ITEMS_SetInvPage(pItem, 0xFF);
        ITEMS_SetItemCMDFlag(pItem, 8, 1);
        pItem->dwFlags &= 0xFDFFFFFFu;
        INVENTORY_AddItemToTradeInventory(pInventory, pItem);
        UNITS_RefreshInventory(pUnit, 1);
        QUESTS_ItemPickedUp(pGame, pUnit, pItem);
        break;
    }
    case IMODE_SOCKETED:
    {
        if (!*ppItem)
            return 13;

        UNITS_ChangeAnimMode(pItem, 4);
        int nUnused;
        if (!D2GAME_ITEMSOCKET_PlaceItem(pGame, pUnit, sub_00451F50(pItem), sub_00451F50(*ppItem), &nUnused, 0, 1, 0, 0))
            return 13;
        break;
    }
    default:
        return 13;
    }

    if (pSavedItem->nSocketedItems > 0)
        *ppItem = pItem;

    *pSocketedItemCount = pSavedItem->nSocketedItems;
    return 0;
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
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
        return pUnit->pStaticPath->tGameCoords.nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x005316D0
int __stdcall D2GAME_SAVE_SerializeItem(D2UnitStrc* pItem, unsigned char* pBitstream, unsigned int nBitstreamSize, int bUseTradeInventory, int nUnused, int bSizing)
{
    if (pItem)
    {
        const int bFlag = (pItem->dwFlagEx >> 15) & 1;
        if (!bFlag && (bUseTradeInventory != bFlag || nUnused == bFlag || bSizing != bFlag || sub_00564CA0_Return1(pItem)))
        {
            const int nBits = ITEMS_SerializeItemToBitstream(pItem, pBitstream, nBitstreamSize, 1, 1, 0);
            D2_ASSERT(nBits, 1884);
            return nBits;
        }
    }
    return 0;
}

struct D2RunesTxt;

struct D2SkillStrc;

// 0x00531750
static unsigned short PLRSAVE_CountInventoryItems(D2InventoryStrc* pInventory)
{
    int nCount = 0;
    if (!pInventory)
        return 0;
    if (INVENTORY_GetCursorItem(pInventory))
        nCount = 1;
    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory);
    while (pItem)
    {
        D2UnitStrc* pIsItem = INVENTORY_UnitIsItem(pItem);
        pItem = INVENTORY_GetNextItem(pItem);
        if (pIsItem)
            ++nCount;
    }
    return (unsigned short)nCount;
}

// 0x005317B0
int __fastcall PLRSAVE_WriteItems(D2GameStrc* pGame, D2UnitStrc* pUnit, D2InventoryStrc* pInventory, unsigned char* pData, int nBufferSize, int bUseTradeInventory, int nUnused, int bSizing)
{
    unsigned char tempBuffer[8192];
    unsigned char* pBuffer = pData;
    if (nBufferSize < 2) return 0;
    *(unsigned short*)pData = 0x4D4A;
    pData += 2;
    unsigned short nItems = PLRSAVE_CountInventoryItems(pInventory);
    if (nBufferSize < pData - pBuffer + 2) return pData - pBuffer;
    unsigned short* pItemCount = (unsigned short*)pData;
    *pItemCount = nItems;
    pData += 2;
    if (pInventory)
    {
        D2UnitStrc* pLeft = INVENTORY_GetLeftHandWeapon(pInventory);
        D2UnitStrc* pRight = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        D2UnitStrc* pOther = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
        D2UnitStrc* pCursor = INVENTORY_GetCursorItem(pInventory);
        if (pLeft)
        {
            if (pRight == pLeft)
            {
                if (PREPARE_ITEM(pRight) < 0) return -1;
                if (pOther && PREPARE_ITEM(pOther) < 0) return -1;
            }
            else
            {
                if (PREPARE_ITEM(pOther) < 0) return -1;
                if (pRight && PREPARE_ITEM(pRight) < 0) return -1;
            }
        }
        else
        {
            if (pRight && PREPARE_ITEM(pRight) < 0) return -1;
            if (pOther && PREPARE_ITEM(pOther) < 0) return -1;
        }
        if (pCursor && pCursor->dwUnitType == UNIT_ITEM && PREPARE_ITEM(pCursor) < 0) return -1;
        D2UnitStrc* pListItem = INVENTORY_GetFirstItem(pInventory);
        while (pListItem)
        {
            D2UnitStrc* pItem = INVENTORY_UnitIsItem(pListItem);
            unsigned char nBodyLoc = ITEMS_GetBodyLocation(pItem);
            if (INVENTORY_GetItemNodePage(pListItem) != 3 || (nBodyLoc != 4 && nBodyLoc != 5))
            {
                WRITE_ITEM(pItem);
            }
            pListItem = INVENTORY_GetNextItem(pListItem);
        }
        if (pLeft)
        {
            if (pRight == pLeft)
            {
                WRITE_ITEM(pRight);
                if (pOther) { WRITE_ITEM(pOther); }
            }
            else
            {
                WRITE_ITEM(pOther);
                if (pRight) { WRITE_ITEM(pRight); }
            }
        }
        else
        {
            if (pRight) { WRITE_ITEM(pRight); }
            if (pOther) { WRITE_ITEM(pOther); }
        }
        if (pCursor && pCursor->dwUnitType == UNIT_ITEM) { WRITE_ITEM(pCursor); }
        *pItemCount = nItems;
    }
    return pData - pBuffer;
}

// 0x00531BB0
int __fastcall PLRSAVE_WriteUnitItems(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pBuffer, int nBufferSize, int nArg5, int nArg6, int nArg7)
{
    if (nArg5 && pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        const int nResult = PLRTRADE_CopyTradeSaveDataToBuffer(pUnit, pBuffer, nBufferSize);
        if (nResult != 0)
        {
            return nResult;
        }
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    return PLRSAVE_WriteItems(pGame, pUnit, pInventory, pBuffer, nBufferSize, nArg5, nArg6, nArg7);
}

static inline int sub_00531C10_GetUnitX(D2UnitStrc* pUnit)
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

static inline int sub_00531C10_GetUnitY(D2UnitStrc* pUnit)
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

// 0x00531C10
int __fastcall PLRSAVE_WriteCorpseSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pData, unsigned int nSize, int nUnused)
{
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2UnitStrc* pCorpse = 0;
    unsigned short nCorpses = 0;
    D2CorpseStrc* pCorpseNode = INVENTORY_GetFirstCorpse(pInventory);
    if (pCorpseNode)
    {
        pCorpse = SUNIT_GetServerUnit(pGame, 0, INVENTORY_GetUnitGUIDFromCorpse(pCorpseNode));
        if (pCorpse)
        {
            nCorpses = 1;
        }
    }

    *(unsigned short*)pData = 0x4D4A;
    pData += 2;
    nSize -= 4;
    *(unsigned short*)pData = nCorpses;
    pData += 2;

    if (!pCorpse)
    {
        return 4;
    }

    D2CorpseSaveStrc tCorpse;
    const int nX = sub_00531C10_GetUnitX(pCorpse);
    const int nY = sub_00531C10_GetUnitY(pCorpse);

    D2_ASSERT(nSize >= sizeof(tCorpse), 0x97A);
    tCorpse.nX = nX;
    tCorpse.nY = nY;
    memcpy(pData, &tCorpse, sizeof(tCorpse));
    pData += sizeof(tCorpse);
    nSize -= sizeof(tCorpse);

    D2InventoryStrc* const tArg3 = pCorpse->pInventory;
    const int nWritten = PLRSAVE_WriteItems(pGame, pCorpse, tArg3, pData, nSize, 0, nUnused, 0);
    D2_ASSERT(nWritten > 0, 0x984);
    return nWritten + 16;
}

// 0x00531D30
static unsigned int __stdcall PLRSAVE_GetSaveFileSize(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pData, unsigned int nMaxSize, int bUseTradeInventory, int nUnused)
{
    unsigned int nSize = 0;
    PLRSAVE2_CreateSaveFile(pGame, pPlayer, pData, &nSize, nMaxSize, bUseTradeInventory, nUnused);
    return nSize;
}

// 0x00531D60
void __fastcall PLRSAVE_ByteToHex(char* szOut, unsigned char nByte)
{
    char szHex[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f' };
    szOut[0] = szHex[nByte >> 4];
    szOut[1] = szHex[nByte & 0xF];
}

// 0x00531DE0
char* __fastcall PLRSAVE_BytesToHexString(char* szOut, const unsigned char* pData, int nLength)
{
    if (nLength <= 0)
    {
        return 0;
    }

    *szOut = '0';
    ++szOut;
    *szOut = 'x';
    ++szOut;
    do
    {
        PLRSAVE_ByteToHex(szOut, *pData);
        szOut += 2;
        ++pData;
        --nLength;
    }
    while (nLength);

    *szOut = 0;
    return szOut;
}

// 0x00531E30
int __fastcall D2GAME_SAVE_CalculateChecksum(D2SaveHeaderStrc* pSaveHeader, int nSize)
{
    int nCheckSum = 0;
    int nLastTime = 0;
    int nPlayTime = 0;
    int nMapSeed = 0;
    const unsigned int nVersion = pSaveHeader->dwVersion;
    if (nVersion > 91)
    {
        nCheckSum = pSaveHeader->dwChecksum;
        nLastTime = pSaveHeader->dwLasTime;
        nPlayTime = pSaveHeader->dwPlayTime;
        nMapSeed = pSaveHeader->dwMapSeed;

        pSaveHeader->dwChecksum = 0;
        pSaveHeader->dwLasTime = 0;
        pSaveHeader->dwPlayTime = 0;
        pSaveHeader->dwMapSeed = 0;
    }

    const int result = CRC32_Compute(pSaveHeader, nSize);

    if (nVersion > 91)
    {
        pSaveHeader->dwChecksum = nCheckSum;
        pSaveHeader->dwLasTime = nLastTime;
        pSaveHeader->dwPlayTime = nPlayTime;
        pSaveHeader->dwMapSeed = nMapSeed;
    }

    return result;
}

// 0x00531EB0
static int __stdcall D2GAME_SAVE_WriteFileOnRealm(D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName, char* szAccountName, int bInteractsWithPlayer, unsigned int nToken, unsigned int dwArg, unsigned int nClientInfo)
{
    unsigned char pData[0x2000];
    if (!gbWriteSaveFile) return 0;
    unsigned int nTotalSize;
    {
        const unsigned int nSize = PLRSAVE_GetSaveFileSize(pGame, pPlayer, pData + 2, 0x2000, bInteractsWithPlayer, dwArg);
        if ((int)nSize <= 0) return 0;
        nTotalSize = nSize + 2;
        }
    *(unsigned short*)pData = (unsigned short)nTotalSize;
    D2ClientStrc* pClient = UnitGetClient(pPlayer, gszPlrSaveSourceFile, 0xA3B);
    unsigned int nOldChecksum = D2GAME_GetSaveChecksumFromClient(pClient);
    unsigned int nChecksum = D2GAME_SAVE_CalculateChecksum((D2SaveHeaderStrc*)(pData + 2), nTotalSize - 2);
    int bMatching = nChecksum == nOldChecksum;
    if (bMatching)
    {
        D2SaveHeaderStrc* pOldHeader = CLIENTS_GetSaveHeader(pClient);
        int nOldSize = CLIENTS_GetSaveHeaderSize(pClient);
        D2_ASSERT(pOldHeader, 0xA46);
        bMatching = 1;
        if (nOldSize == nTotalSize - 2)
        {
            const unsigned int nOldVersion = pOldHeader->dwVersion;
            int nOldCheck = 0;
            int nOldLast = 0;
            int nOldPlay = 0;
            int nOldMap = 0;
            if (nOldVersion > 91)
            {
                nOldCheck = pOldHeader->dwChecksum;
                nOldLast = pOldHeader->dwLasTime;
                nOldPlay = pOldHeader->dwPlayTime;
                nOldMap = pOldHeader->dwMapSeed;
                pOldHeader->dwChecksum = 0;
                pOldHeader->dwLasTime = 0;
                pOldHeader->dwPlayTime = 0;
                pOldHeader->dwMapSeed = 0;
            }
            D2SaveHeaderStrc* pNewHeader = (D2SaveHeaderStrc*)(pData + 2);
            const unsigned int nNewVersion = pNewHeader->dwVersion;
            int nNewCheck = 0;
            int nNewLast = 0;
            int nNewPlay = 0;
            int nNewMap = 0;
            if (nNewVersion > 91)
            {
                nNewCheck = pNewHeader->dwChecksum;
                nNewLast = pNewHeader->dwLasTime;
                nNewPlay = pNewHeader->dwPlayTime;
                nNewMap = pNewHeader->dwMapSeed;
                pNewHeader->dwChecksum = 0;
                pNewHeader->dwLasTime = 0;
                pNewHeader->dwPlayTime = 0;
                pNewHeader->dwMapSeed = 0;
            }
            for (int i = 0; i < nOldSize; ++i)
            {
                if (((unsigned char*)pOldHeader)[i] != pData[i + 2])
                {
                    bMatching = 0;
                    break;
                }
            }
            if (nOldVersion > 91)
            {
                pOldHeader->dwChecksum = nOldCheck;
                pOldHeader->dwLasTime = nOldLast;
                pOldHeader->dwPlayTime = nOldPlay;
                pOldHeader->dwMapSeed = nOldMap;
            }
            if (nNewVersion > 91)
            {
                pNewHeader->dwChecksum = nNewCheck;
                pNewHeader->dwLasTime = nNewLast;
                pNewHeader->dwPlayTime = nNewPlay;
                pNewHeader->dwMapSeed = nNewMap;
            }
        }
        else bMatching = 0;
    }
    if (bMatching)
    {
        ++gnUnchangedSaveCount;
        if (gpD2EventCallbackTable && gpD2EventCallbackTable->pfUpdate)
        {
            gpD2EventCallbackTable->pfUpdate(&nClientInfo, szName, szAccountName);
        }
        CLIENTS_SetClientInfo(pClient, nClientInfo);
        return 0;
    }
    CLIENTS_SetClientInfo(pClient, nClientInfo);
    D2GAME_SetSaveFileChecksum(pClient, nChecksum);
    if (gpD2EventCallbackTable && gpD2EventCallbackTable->pfSaveDatabaseCharacter)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)gpD2EventCallbackTable->pfSaveDatabaseCharacter), 0xADC);
        gpD2EventCallbackTable->pfSaveDatabaseCharacter(&nClientInfo, szName, szAccountName, pData, nTotalSize, nToken);
        CLIENTS_CopySaveDataToClient(pClient, pData + 2, nTotalSize - 2);
    }
    return 1;
}

// 0x00532240
static void __stdcall PLRSAVE_SaveToLocalFile(int bInteractsWithPlayer, unsigned int dwArg, D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName)
{
    if (!gbWriteSaveFile)
    {
        return;
    }

    char szPath[0x400];
    char szFile[0x1F4];
    unsigned char pData[0x2000];
    unsigned int nSize;

    FOG_GetSavePath(szPath, sizeof(szPath));
    sprintf(szFile, gszSaveFormat_006D4230, szPath, szName);
    nSize = 0;
    PLRSAVE2_CreateSaveFile(pGame, pPlayer, pData, &nSize, sizeof(pData), bInteractsWithPlayer, dwArg);
    if ((int)nSize <= 0)
    {
        return;
    }

    _iobuf* pFile = fopen(szFile, gszFileModeWb);
    if (pFile)
    {
        fwrite(pData, nSize, 1, pFile);
        fclose(pFile);
    }
    else
    {
        LOGMANAGER_WriteLogLine(gszSaveOpenError, szFile);
    }
}

// 0x00532340
static void __stdcall PLRSAVE_SaveToClient(int bInteractsWithPlayer, D2GameStrc* pGame, D2UnitStrc* pPlayer, D2ClientStrc* pClient)
{
    unsigned char pData[0x2000];
    unsigned int nSize;

    if (CLIENTS_GetSaveHeader(pClient))
    {
        CLIENTS_FreeSaveHeader(pClient);
    }

    nSize = 0;
    PLRSAVE2_CreateSaveFile(pGame, pPlayer, pData, &nSize, sizeof(pData), bInteractsWithPlayer, 0);
    const int nFileSize = nSize;
    D2_ASSERT(nFileSize > 0, 2866);
    const int nClientId = CLIENTS_GetClientId(pClient);
    CLIENTS_AttachSaveFile(nClientId, pData, nFileSize, nFileSize, 0, 0, 0);
    D2GAME_SetSaveLoadComplete(pClient);
}

// 0x00532400
int __fastcall D2GAME_SAVE_WriteFile(D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName, unsigned int dwArg)
{
    if (!pPlayer)
    {
        return 0;
    }

    pPlayer->dwFlagEx &= ~2;

    int bInteractsWithPlayer = 0;
    int nUnitType = 6;
    int nUnitGUID;
    if (sub_00554100(pPlayer, &nUnitType, &nUnitGUID) && nUnitType == 0)
    {
        bInteractsWithPlayer = 1;
    }

    D2ClientStrc* pClient = UnitGetClient(pPlayer, gszPlrSaveSourceFile, 2919);
    char szAccountName[50];
    CLIENTS_CopyAccountNameToBuffer(pClient, szAccountName);
    unsigned int nToken;
    CLIENTS_GetCharSaveTransactionToken(pClient, &nToken);
    unsigned int nClientInfo;
    CLIENTS_GetClientInfo(pClient, &nClientInfo);

    int nResult = 1;
    if (pGame->nGameType == 1 || pGame->nGameType == 2)
    {
        PLRSAVE_SaveToClient(bInteractsWithPlayer, pGame, pPlayer, pClient);
    }
    else if (gpD2EventCallbackTable)
    {
        nResult = D2GAME_SAVE_WriteFileOnRealm(pGame, pPlayer, szName, szAccountName, bInteractsWithPlayer, nToken, dwArg, nClientInfo);
    }
    else
    {
        PLRSAVE_SaveToLocalFile(bInteractsWithPlayer, (dwArg), pGame, pPlayer, szName);
    }

    return nResult;
}

static inline D2CharStatsTxt* PLRSAVE_GetCharStatsTxtRecordInline(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }
    return 0;
}

// 0x00532520
static void __stdcall PLRSAVE_AttachPlayerToClient(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2ClientStrc* pClient)
{
    CLIENTS_SetPlayerInClient(pClient, pPlayer);
    SUNIT_InitClientInPlayerData(pPlayer, pClient);
    UNITS_SetNameInPlayerData(pPlayer, CLIENTS_GetName(pClient));
    SUNIT_InitSeed(pPlayer, &pGame->pGameSeed);
    UNITS_ChangeAnimMode(pPlayer, PLRMODE_NEUTRAL);

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    pPlayerData->hTrade = 0;
    pPlayerData->dwTradeState = 0;
    pPlayerData->dwAcceptTradeTick = 0;
    *(int*)pPlayerData->dwLastTradeTick = 0;
}

// 0x00532580
void __cdecl sub_00532580_Empty()
{
}

// 0x00532590
static int __stdcall PLRSAVE_CreateNewPlayer(D2GameStrc* pGame, D2ClientStrc* pClient, D2UnitStrc** ppPlayer)
{
    CLIENTS_SetPlayerUnitAlive(pClient);
    const int nClassId = CLIENTS_GetClassId(pClient);
    D2UnitStrc* pPlayer = SUNIT_AllocUnitData(UNIT_PLAYER, nClassId, 0, 0, pGame, 0, 0, 0, 0);
    PLRSAVE_AttachPlayerToClient(pGame, pPlayer, pClient);
    SUNITMSG_SendUnitToClient(pGame, pPlayer, pClient);

    const unsigned char nAct = CLIENTS_GetActNo(pClient);
    PLAYERSTATS_SetStatsForStartingAct(pGame, pPlayer, nAct);
    PLAYER_CreateStartItemsFromCharStatsTxt(pPlayer, pGame, nAct);

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    pPlayerData->nLeftSkillId = 0;
    pPlayerData->nRightSkillId = 0;

    if (nAct == ACT_I && pPlayer)
    {
        D2CharStatsTxt* pCharStatsTxtRecord = PLRSAVE_GetCharStatsTxtRecordInline(pPlayer->dwClassId);
        if (pCharStatsTxtRecord && pCharStatsTxtRecord->wStartSkill && SKILLS_GetHighestLevelSkillFromUnitAndId(pPlayer, pCharStatsTxtRecord->wStartSkill))
        {
            D2GAME_AssignSkill(pPlayer, 0, pCharStatsTxtRecord->wStartSkill, -1);
            pPlayerData->nRightSkillId = pCharStatsTxtRecord->wStartSkill;
        }
    }

    QUESTS_SequenceCycler(pGame, pPlayer, 1);
    *ppPlayer = pPlayer;
    return 0;
}

static __forceinline int PLRSAVE_ConvertLegacySkill(unsigned char nSkill)
{
 int nId=nSkill;
 if(nId>=156 && nId<=216) nId+=65;
 else if(nId==255) nId=-1;
 return nId;
}

// 0x00532690
int __fastcall PLRSAVE_ReadLegacyHeader(D2GameStrc* pGame,D2ClientStrc* pClient,D2LegacySaveHeaderStrc* pSave,D2UnitStrc** ppPlayer,int* pNewPlayer,unsigned int* pVersion,int* pStats,int* pSkills,int* pLeft,int* pRight,int* pHeaderSize)
{
 char szGuildTag[4];
 *pHeaderSize=0;
 D2LegacySaveHeaderStrc header=*pSave;
 sub_00538630(pClient,0);
 if(header.dwMagic!=0xAA55AA55) {
  if(gpD2EventCallbackTable) { *pNewPlayer=1;return 0; }
  return 1;
 }
 if(header.nHeaderSize!=130) {
  if(gpD2EventCallbackTable) { *pNewPlayer=1;return 0; }
  return 14;
 }
 const unsigned int nVersion=header.dwVersion;
 *pVersion=nVersion;
 if(nVersion<71 || nVersion>96) goto invalidVersion;
 {
 header.szName[15]=0;
 char* szName=CLIENTS_GetName(pClient);
 szName[15]=0;
 if(_stricmp(szName,header.szName)) { *pNewPlayer=0;return 1; }
 const unsigned short nSaveFlags=(unsigned short)header.dwFlags;
 unsigned short bExpansion=(unsigned short)header.dwFlags;
 bExpansion &= 0x20;
 if(bExpansion) { if(!pGame->bExpansion) return 24; }
 else if(pGame->bExpansion) return 23;
 if(header.dwFlags & 4) {
  if(header.dwFlags & 8) return 21;
  if(!(ARENA_GetFlags(pGame)&0x800)) return 20;
 } else if(ARENA_GetFlags(pGame)&0x800) return 19;
 const int nProgress=(nSaveFlags>>8)&31;
 if(nProgress<8 && pGame->nDifficulty>1) return 18;
 if((nSaveFlags & 0x20) && nProgress<5 && pGame->nDifficulty>0) return 17;
 if(nProgress<4 && pGame->nDifficulty>0) return 17;
 CLIENTS_SetGuildFlags(pClient,*(int*)header.guildFlags);
 char szGuildName[28];
 memcpy(szGuildTag,header.guildTag,4);
 memcpy(szGuildName,header.guildName,28);
 szGuildTag[3]=0;szGuildName[27]=0;
 CLIENTS_SetGuildTag(pClient,szGuildTag);
 CLIENTS_SetGuildName(pClient,szGuildName);
 CLIENTS_SetGuildEmblem(pClient,header.guildColors[0],*(int*)&header.guildColors[1],*(int*)&header.guildColors[2]);
 if(header.dwFlags & 1) {
  *pNewPlayer=1;header.dwFlags &= ~1;
  sub_00538630(pClient,header.dwFlags);
  return 0;
 }
 sub_00539230_SetFlag(pClient,(header.dwFlags>>13)&1);
 const int nClass=header.nClass;
 *pNewPlayer=0;
 CLIENTS_SetClassId(pClient,nClass);
 sub_00538630(pClient,nSaveFlags);
 unsigned char nAct=header.nLocation & 15;
 const unsigned char nDifficulty=header.nLocation>>4;
 if(nAct>=5 || nDifficulty>=3) return 9;
 if(pGame->nGameType==3 && !pGame->InitSeed && pGame->nDifficulty==nDifficulty) pGame->dwInitSeed=header.nMapSeed;
 if(pGame->nDifficulty!=nDifficulty) nAct=0;
 CLIENTS_SetActNo(pClient,nAct);
 *ppPlayer=SUNIT_AllocUnitData(0,nClass,0,0,pGame,0,0,0,0);
 PLRSAVE_AttachPlayerToClient(pGame, *ppPlayer, pClient);
 SUNITMSG_SendUnitToClient(CLIENTS_GetGame(pClient),*ppPlayer,pClient);
 *pStats=16;
 *pSkills=sgptDataTables->nSkillsTxtRecordCount;
 if(header.nStats>16 || header.nSkills>sgptDataTables->nSkillsTxtRecordCount) {
  if(gpD2EventCallbackTable) { *pNewPlayer=1;return 0; }
  return 1;
 }
 if(header.nStats!=16) *pStats=header.nStats;
 if(header.nSkills!=sgptDataTables->nSkillsTxtRecordCount) *pSkills=header.nSkills;
 unsigned char* pHotkey;
 int i;
 for(i=0,pHotkey=&header.hotkeys[0][1];i<8;++i,pHotkey+=2) CLIENTS_SetSkillHotKey(pClient,i,PLRSAVE_ConvertLegacySkill(pHotkey[-1]),*pHotkey,-1);
 *pLeft=PLRSAVE_ConvertLegacySkill(header.nLeftSkill);
 *pRight=PLRSAVE_ConvertLegacySkill(header.nRightSkill);
 *pHeaderSize=header.nHeaderSize;
 return 0;
 }
invalidVersion:
 if(gpD2EventCallbackTable) { *pNewPlayer=1;return 9; }
 return 1;
}

// 0x00532BE0
int __fastcall PLRSAVE_ReadLegacyQuests(D2UnitStrc* pPlayer, const D2QuestSaveSectionStrc* pSection, int nUnused, int* pSize)
{
    *pSize = 0;

    D2QuestSaveSectionStrc tSection = *pSection;
    D2QuestSaveSectionStrc* pQuestSection = &tSection;
    if (pQuestSection->dwHeaderMagic != '!ooW')
    {
        return 2;
    }

    if (pQuestSection->dwVersion != 6)
    {
        return 2;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    for (int i = 0; i < 3; ++i)
    {
        QUESTRECORD_CopyBufferToRecord(pPlayerData->pQuestData[i], pQuestSection->pQuestRecord[i], 96, 1);
    }

    *pSize = sizeof(D2QuestSaveSectionStrc);
    return 0;
}

// 0x00532C70
int __fastcall D2GAME_SAVE_ReadWaypointData(D2UnitStrc* pUnit, const unsigned char* pSection, int nUnused, int* pSize)
{
    *pSize = 0;

    D2WaypointSaveSectionStrc tSection = *(const D2WaypointSaveSectionStrc*)pSection;
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
    if (tSection.nMagic != WAYPOINT_MAGIC)
    {
        return SYSERROR_BAD_WAYPOINT;
    }

    int i = 0;
    D2WaypointDataStrc** ppWaypointData = pPlayerData->pWaypointData;
    const D2WaypointSaveRecordStrc* pRecord = tSection.pRecords;
    for (; i < 3; ++i, ++ppWaypointData, ++pRecord)
    {
        if (pRecord->nFlags != 0x102 && pRecord->nFlags != 0x101 && pRecord->nFlags != 0)
        {
            return SYSERROR_BAD_WAYPOINT;
        }

        WAYPOINTS_CopyAndValidateWaypointData(*ppWaypointData, pRecord);
    }

    *pSize = sizeof(D2WaypointSaveSectionStrc);
    return 0;
}

int __fastcall sub_M107_Emit_00532D90(int* pValue, int bClear)
{
    if (bClear)
        return PLRSAVE_ClearValue(pValue);
    return bClear + 1;
}

// 0x00532D00
int __fastcall PLRSAVE_ReadLegacyPlayerIntro(D2UnitStrc* pUnit, const D2PlrIntroSaveStrc* pSection, int nUnused, int* pSize)
{
    *pSize = 0;
    D2PlrIntroSaveStrc plrIntro = *pSection;
    if (plrIntro.nHeader != 0x7701)
    {
        return PLRSAVE2ERROR_BAD_PLAYERINTRO;
    }

    for (int i = 0; i < NUM_DIFFICULTIES; ++i)
    {
        PLRINTRO_CopyBufferToQuestIntroFlags(UNITS_GetPlayerData(pUnit)->pPlayerIntro[i], plrIntro.nQuestIntroFlags[i]);
        PLRINTRO_CopyBufferToNpcIntroFlags(UNITS_GetPlayerData(pUnit)->pPlayerIntro[i], plrIntro.nNpcIntroFlags[i]);
    }

    *pSize = sizeof(D2PlrIntroSaveStrc);
    return 0;
}

// 0x00532D90
static int PLRSAVE_ClearValue(int* pValue)
{
    *pValue = 0;
    return 0;
}

// 0x00532DA0
int __fastcall PLRSAVE_ReadLegacyStats(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pData, int nStatCount, int nUnused, int* pSize)
{
    *pSize = 0;
    if (*(unsigned short*)pData != 0x6667) return 4;
    pData += 2;
    struct { int i; int nPresent; } tLoop;
    tLoop.nPresent = 0;
    tLoop.i = 0;
    if (nStatCount > 0) do
    {
        if (pData[(unsigned int)tLoop.i >> 3] & (1 << (tLoop.i & 7)))
        {
            const int nValue = *(int*)&pData[4 * tLoop.nPresent + 3];
            ++tLoop.nPresent;
            STATLIST_SetUnitStat(pUnit, tLoop.i, nValue, 0);
        }
        else
        {
            STATLIST_SetUnitStat(pUnit, tLoop.i, 0, 0);
        }
        ++tLoop.i;
    } while (tLoop.i < nStatCount);
    const int nSize = tLoop.nPresent * 4 + 5;
    if (ARENA_IsInArenaMode(pGame))
    {
        const int nLife = STATLIST_GetMaxLifeFromUnit(pUnit);
        STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nLife, 0);
        const int nMana = STATLIST_GetMaxManaFromUnit(pUnit);
        STATLIST_SetUnitStat(pUnit, STAT_MANA, nMana, 0);
    }
    const int nStamina = STATLIST_GetMaxStaminaFromUnit(pUnit);
    STATLIST_SetUnitStat(pUnit, STAT_STAMINA, nStamina, 0);
    *pSize = nSize;
    return 0;
}

void __fastcall D2GAME_SetSkills(int pUnit, int nSkillId, int nSkillLevel, int bRemove); // 0x0056DEB0

// 0x00532E70
void __stdcall PLRSAVE_SetSkillIfLevelSet(int pUnit, int nSkillId, unsigned char nSkillLevel)
{
    if (nSkillLevel)
    {
        D2GAME_SetSkills(pUnit, nSkillId, nSkillLevel, 1);
    }
}


void __fastcall D2GAME_SetSkills(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove); // 0x0056DEB0

// 0x00532E90
int __fastcall PLRSAVE_ReadLegacySkills(D2GameStrc* pGame, D2ClientStrc* pClient, D2UnitStrc* pUnit, unsigned char* pSection, int nUnused1, int nUnused2, int* pSkillCount)
{
    *pSkillCount = 0;

    if (*(unsigned short*)pSection != 0x6669)
        return 5;

    const unsigned char* pData = pSection + 2;
    const int nClassId = CLIENTS_GetClassId(pClient);
    for (int i = 0; i < SKILLS_GetPlayerSkillCount(nClassId); ++i)
    {
        const int nSkillId = SKILLS_GetClassSkillId(nClassId, i);
        if (pData[i])
        {
            D2GAME_SetSkills(pUnit, nSkillId, pData[i], 1);
        }
    }

    SCMD_SendSkillList(pClient, pUnit);

    const int nCount = SKILLS_GetPlayerSkillCount(nClassId) + 2;
    SKILLS_RefreshPassivesAndPetLimits(pUnit);
    *pSkillCount = nCount;
    return 0;
}

// 0x00532F30
int __fastcall PLRSAVE_ReadLegacyItemData(D2SavedItemStrc* pSavedItem, unsigned char* pData)
{
    memset(pSavedItem, 0, sizeof(D2SavedItemStrc));

    D2BitBufferStrc tBitBuffer;
    BITMANIP_Initialize(&tBitBuffer, pData, 0x40);

    pSavedItem->nItemFlags = sub_00411020_ReadBits(&tBitBuffer, 32);

    if (ITEMS_CheckIfFlagIsSet(pSavedItem->nItemFlags, 0x100000))
    {
        if (ITEMS_CheckIfFlagIsSet(pSavedItem->nItemFlags, 0x200000))
        {
            pSavedItem->nItemFormat = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 10);
            pSavedItem->nBodyLoc = sub_00411020_ReadBits(&tBitBuffer, 5);
            pSavedItem->nItemLevel = 1;
            pSavedItem->nSpawnType = sub_00411020_ReadBits(&tBitBuffer, 3);
            pSavedItem->nX = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 5);
            pSavedItem->nY = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 3);
            pSavedItem->nInvPage = sub_00411020_ReadBits(&tBitBuffer, 8);

            if (ITEMS_CheckIfFlagIsSet(pSavedItem->nItemFlags, 0x10000))
            {
                pSavedItem->nItemCode = 0x20726165;
                pSavedItem->nItemIndex = sub_00411020_ReadBits(&tBitBuffer, 3);
                pSavedItem->nEarLevel = sub_00411020_ReadBits(&tBitBuffer, 8);

                for (unsigned int i = 0; i < 16; ++i)
                {
                    pSavedItem->szName[i] = sub_00411020_ReadBits(&tBitBuffer, 7);
                }
            }
            else
            {
                pSavedItem->nItemCode = sub_00411020_ReadBits(&tBitBuffer, 32);
            }
        }
        else
        {
            pSavedItem->nItemFormat = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 10);
            pSavedItem->nItemCode = sub_00411020_ReadBits(&tBitBuffer, 32);
            pSavedItem->nBodyLoc = sub_00411020_ReadBits(&tBitBuffer, 5);
            pSavedItem->nSocketedItems = sub_00411020_ReadBits(&tBitBuffer, 3);
            pSavedItem->nItemLevel = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 12);
            pSavedItem->nSpawnType = sub_00411020_ReadBits(&tBitBuffer, 3);
            pSavedItem->nItemQuality = sub_00411020_ReadBits(&tBitBuffer, 4);
            pSavedItem->nQuantity = BITMANIP_ReadSigned(&tBitBuffer, 20);
            pSavedItem->nMinDurability = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 8);
            pSavedItem->nMaxDurability = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 8);
            pSavedItem->nX = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 5);
            pSavedItem->nY = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 3);
            pSavedItem->nItemIndex = BITMANIP_ReadSigned(&tBitBuffer, 10);
            pSavedItem->nSeed = sub_00411020_ReadBits(&tBitBuffer, 32);
            pSavedItem->nItemSeed = sub_00411020_ReadBits(&tBitBuffer, 32);
            pSavedItem->nInvPage = sub_00411020_ReadBits(&tBitBuffer, 8);
        }

        pSavedItem->nItemId = DATATBLS_GetItemIdFromItemCode(pSavedItem->nItemCode);
        return BITMANIP_GetSize(&tBitBuffer);
    }

    pSavedItem->nItemFormat = 0;

    if (ITEMS_CheckIfFlagIsSet(pSavedItem->nItemFlags, 0x10000))
    {
        pSavedItem->nBodyLoc = sub_00411020_ReadBits(&tBitBuffer, 5);
        pSavedItem->nItemLevel = 1;
        BITMANIP_ReadSigned(&tBitBuffer, 10);
        pSavedItem->nItemId = DATATBLS_GetItemIdFromItemCode(0x20726165);
        pSavedItem->nSpawnType = sub_00411020_ReadBits(&tBitBuffer, 3);
        pSavedItem->nX = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 5);
        pSavedItem->nY = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 3);
        pSavedItem->nItemIndex = BITMANIP_ReadSigned(&tBitBuffer, 10);
        pSavedItem->nInvPage = sub_00411020_ReadBits(&tBitBuffer, 8);
        pSavedItem->nEarLevel = sub_00411020_ReadBits(&tBitBuffer, 8);

        for (unsigned int i = 0; i < 16; ++i)
        {
            pSavedItem->szName[i] = sub_00411020_ReadBits(&tBitBuffer, 7);
            if (!pSavedItem->szName[i])
            {
                break;
            }
        }

        pSavedItem->nItemCode = 0x20726165;
        return 25;
    }

    pSavedItem->nBodyLoc = sub_00411020_ReadBits(&tBitBuffer, 5);
    pSavedItem->nSocketedItems = sub_00411020_ReadBits(&tBitBuffer, 3);
    pSavedItem->nItemLevel = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 12);
    const int nItemId = BITMANIP_ReadSigned(&tBitBuffer, 10);
    pSavedItem->nSpawnType = sub_00411020_ReadBits(&tBitBuffer, 3);
    pSavedItem->nItemQuality = sub_00411020_ReadBits(&tBitBuffer, 4);
    pSavedItem->nQuantity = BITMANIP_ReadSigned(&tBitBuffer, 20);
    pSavedItem->nMinDurability = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 8);
    pSavedItem->nMaxDurability = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 8);
    pSavedItem->nX = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 5);
    pSavedItem->nY = (unsigned char)sub_00411020_ReadBits(&tBitBuffer, 3);
    pSavedItem->nItemIndex = BITMANIP_ReadSigned(&tBitBuffer, 10);
    pSavedItem->nSeed = sub_00411020_ReadBits(&tBitBuffer, 32);
    pSavedItem->nItemSeed = sub_00411020_ReadBits(&tBitBuffer, 32);
    pSavedItem->nInvPage = sub_00411020_ReadBits(&tBitBuffer, 8);

    if (nItemId >= 0)
    {
        pSavedItem->nItemId = DATATBLS_MapOldItemIndexToCurrent(nItemId);

        D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(pSavedItem->nItemId);
        if (pItemsTxtRecord)
        {
            pSavedItem->nItemCode = pItemsTxtRecord->dwCode;
            return 25;
        }
    }

    pSavedItem->nItemCode = 0;
    pSavedItem->nItemId = -1;
    return 25;
}

// 0x00533350
int __fastcall PLRSAVE_ReadLegacyItems(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pSection, unsigned int dwVersion, int nSize, int bCorpseItems, int* pSize)
{
    D2ItemKeyStrc keys[0x400];
    struct D2ReadStateStrc { int* pSize; int nUnused; } state;
    D2ReadStateStrc* pState = &state;
    unsigned short nTotal16;
    pState->pSize = pSize;

    if (*(unsigned short*)pSection != 0x4D4A)
        return 14;

    unsigned char* pData = pSection + 2;
    nTotal16 = *(unsigned short*)pData;
    pData += 2;
    int nTotalSize = 4;
    nSize -= 4;
    int nKeys = 0;
    for (unsigned int j = 0; j < nTotal16; ++j)
    {
        D2SavedItemStrc savedItem;
        memset(&savedItem, 0, sizeof(savedItem));
        if (*(unsigned short*)pData != 0x4D4A)
            return 14;

        pData += 2;
        int nDataSize = PLRSAVE_ReadLegacyItemData(&savedItem, pData);
        nSize -= nDataSize + 2;
        pData += nDataSize;
        nTotalSize += nDataSize + 2;

        for (int k = 0; k < nKeys; ++k)
        {
            if (savedItem.nItemCode == keys[k].nCode && savedItem.nItemIndex == keys[k].nIndex && savedItem.nItemLevel == keys[k].nLevel
                && savedItem.nSeed == keys[k].nSeed && savedItem.nItemSeed == keys[k].nItemSeed)
            {
                for (int s = 0; s < savedItem.nSocketedItems; ++s)
                {
                    memset(&savedItem, 0, sizeof(savedItem));
                    if (*(unsigned short*)pData != 0x4D4A)
                        return 14;

                    pData += 2;
                    nDataSize = PLRSAVE_ReadLegacyItemData(&savedItem, pData);
                    nSize -= nDataSize + 2;
                    pData += nDataSize;
                    nTotalSize += nDataSize + 2;
                }
                goto next_item;
            }

            keys[nKeys].nCode = savedItem.nItemCode;
            keys[nKeys].nIndex = savedItem.nItemIndex;
            keys[nKeys].nLevel = savedItem.nItemLevel;
            keys[nKeys].nSeed = savedItem.nSeed;
            keys[nKeys].nItemSeed = savedItem.nItemSeed;
            ++nKeys;
        }

        {
            int nCount = 0;
            D2UnitStrc* pItem = 0;
            if (bCorpseItems)
            {
                const int nResult = PLRSAVE_CreateAndPlaceLegacyCorpseItem(pGame, &savedItem, &pItem, &nCount, pPlayer);
                if (nResult)
                    return nResult;
            }
            else
            {
                if (PLRSAVE_CreateAndPlaceLegacyPlayerItem(pGame, pPlayer, &savedItem, &pItem, &nCount))
                    continue;
            }

            for (int i = 0; i < nCount; ++i)
            {
                memset(&savedItem, 0, sizeof(savedItem));
                if (*(unsigned short*)pData != 0x4D4A)
                    return 14;

                pData += 2;
                nDataSize = PLRSAVE_ReadLegacyItemData(&savedItem, pData);
                nSize -= nDataSize + 2;
                pData += nDataSize;
                nTotalSize += nDataSize + 2;

                int nResult;
                if (bCorpseItems)
                    nResult = PLRSAVE_CreateAndPlaceLegacyCorpseItem(pGame, &savedItem, &pItem, &pState->nUnused, pPlayer);
                else
                    nResult = PLRSAVE_CreateAndPlaceLegacyPlayerItem(pGame, pPlayer, &savedItem, &pItem, &pState->nUnused);

                if (nResult)
                    return nResult;
            }
        }
next_item:
        ;
    }

    *pState->pSize = nTotalSize;
    return 0;
}

// 0x005335E0
int __fastcall PLRSAVE_ReadItems(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pSection, unsigned int dwVersion, int nSize, int bCorpseItems, int* pSize)
{
    unsigned char* pBegin = pSection;
    if (*(unsigned short*)pSection != 0x4D4A)
    {
        return 14;
    }

    pSection += 2;
    const int nItems = *(unsigned short*)pSection;
    pSection += 2;
    for (int i = 0; i < nItems; ++i)
    {
        D2ItemSaveStrc tItemSave;
        int nItemSize;
        int nResult = 0;
        ITEMS_GetCompactItemDataFromBitstream(pSection, nSize - (pSection - pBegin), 1, &tItemSave, dwVersion);
        if (tItemSave.nClassId == -1)
        {
            return 14;
        }

        D2UnitStrc* pItem = ITEMS_CreateItemFromBitstream(pGame, 0, pSection, nSize - (pSection - pBegin), 1, &tItemSave, &nItemSize, dwVersion);
        if (!pItem && nItemSize <= 0)
        {
            return 14;
        }

        pSection += nItemSize;
        if (pItem)
        {
            sub_00564CB0_Nop(pItem);
            if (bCorpseItems)
            {
                nResult = PLRSAVE_PlaceCorpseItem(pGame, pPlayer, pItem, 0);
            }
            else
            {
                nResult = PLRSAVE_PlacePlayerItem(pGame, pPlayer, pItem, 0);
            }
        }

        const int nSockets = tItemSave.nItemFileIndex;
        D2UnitStrc* pParent = pItem;
        if (nResult)
        {
            if (pItem)
            {
                SUNIT_RemoveUnit(pGame, pItem);
            }
            pParent = 0;
        }

        for (int j = 0; j < nSockets; ++j)
        {
            ITEMS_GetCompactItemDataFromBitstream(pSection, nSize - (pSection - pBegin), 1, &tItemSave, dwVersion);
            D2UnitStrc* pSocketed = ITEMS_CreateItemFromBitstream(pGame, 0, pSection, nSize - (pSection - pBegin), 1, &tItemSave, &nItemSize, dwVersion);
            if (!pSocketed && nItemSize <= 0)
            {
                return 14;
            }

            pSection += nItemSize;
            if (!pParent)
            {
                if (pSocketed)
                {
                    SUNIT_RemoveUnit(pGame, pSocketed);
                }
            }
            else if (pSocketed)
            {
                sub_00564CB0_Nop(pSocketed);
                if (bCorpseItems)
                {
                    PLRSAVE_PlaceCorpseItem(pGame, pPlayer, pSocketed, pParent);
                }
                else
                {
                    PLRSAVE_PlacePlayerItem(pGame, pPlayer, pSocketed, pParent);
                }
            }
        }

        if (pParent && (ITEMS_GetItemFlags(pParent) & 0x4000000) && !ITEMS_GetRunesTxtRecordFromItem(pParent))
        {
            ITEMMODE_DetachItemFromOwner(pGame, pPlayer, pParent);
        }
    }

    if (pSize)
    {
        *pSize = pSection - pBegin;
    }

    return 0;
}

// 0x005337F0
int __fastcall PLRSAVE_ReadItemSection(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pSection, int nVersion, int nSize, int nUnused, int* pReadSize)
{
    int nResult;
    if (nVersion == 0x47)
        nResult = PLRSAVE_ReadLegacyItems(pGame, pUnit, pSection, 0x47, nSize, nUnused, pReadSize);
    else if (nVersion < 0x48 || nVersion > 0x60)
        return 1;
    else
        nResult = PLRSAVE_ReadItems(pGame, pUnit, pSection, nVersion, nSize, nUnused, pReadSize);
    return nResult;
}

// 0x00533850
static int __stdcall PLRSAVE_ReadCorpse(D2UnitStrc* pUnit, D2GameStrc* pGame, unsigned char* pData, unsigned int nVersion, int nSize, int* pReadSize)
{
    *pReadSize = 0;
    pData += 12;
    nSize -= 12;

    D2UnitStrc* pPlayer = pUnit;
    pUnit = SUNIT_AllocUnitData(0, !pPlayer ? -1 : pPlayer->dwClassId, 0, 0, pGame, 0, 1, 0x11, 0);
    if (!pUnit)
    {
        return 8;
    }

    pUnit->dwFlags &= ~4;
    {
        D2ClientStrc* pClient = UnitGetClient(pPlayer, gszPlrSaveSourceFile, 0x1511);
        SUNIT_InitClientInPlayerData(pUnit, pClient);
        char* const szName = CLIENTS_GetName(pClient);
        UNITS_SetNameInPlayerData(pUnit, szName);
    }
    SUNIT_InitSeed(pUnit, &pGame->pGameSeed);
    STATES_ToggleState(pUnit, 7, 1);
    pUnit->dwFlags &= ~0x10;
    INVENTORY_SetOwnerId(pUnit->pInventory, !pPlayer ? -1 : pPlayer->dwUnitId);

    {
        int nRead = 0;
        const int nResult = PLRSAVE_ReadItemSection(pGame, pUnit, pData, nVersion, nSize, 1, &nRead);
        if (nResult)
        {
            return nResult;
        }

        nSize = nRead + 12;
        INVENTORY_CreateCorpseForPlayer(pPlayer->pInventory, !pUnit ? -1 : pUnit->dwUnitId, 0, 1);
        const int nCorpseId = !pUnit ? -1 : pUnit->dwUnitId;
        const int nPlayerId = !pPlayer ? -1 : pPlayer->dwUnitId;
        D2GAME_SendPacket0x8E_CorpseAssign_ToAllPlayers(pGame, nPlayerId, nCorpseId, 1);
        *pReadSize = nSize;
        return 0;
    }
}

// 0x00533A70
int __fastcall PLRSAVE_GetLegacyHirelingExpFactor(unsigned short nHirelingId, int nLevel)
{
    switch (nHirelingId)
    {
    case 0:
    case 1:
        if (nLevel >= 49)
            return 400;
        return (((nLevel < 25) - 1) & 100) + 100;
    case 2:
    case 3:
        return (((nLevel < 49) - 1) & 220) + 220;
    case 4:
    case 5:
    case 12:
    case 13:
    case 14:
    case 21:
    case 23:
        return 480;
    case 6:
    case 7:
    case 8:
        if (nLevel >= 55)
            return 420;
        return (((nLevel < 31) - 1) & 105) + 105;
    case 9:
    case 10:
    case 11:
        return (((nLevel < 55) - 1) & 230) + 230;
    case 15:
    case 17:
        if (nLevel >= 61)
            return 440;
        return (((nLevel < 37) - 1) & 110) + 110;
    case 16:
        if (nLevel >= 61)
            return 260;
        return (((nLevel < 37) - 1) & 115) + 115;
    case 18:
    case 20:
        return (((nLevel < 61) - 1) & 230) + 230;
    case 19:
        return (((nLevel < 61) - 1) & 240) + 240;
    case 22:
        return 500;
    case 24:
    case 25:
        if (nLevel >= 75)
            return 880;
        return (((nLevel < 42) - 1) & 220) + 220;
    case 26:
    case 27:
        return (((nLevel < 75) - 1) & 460) + 460;
    default:
        return 960;
    }
}

// 0x00533BF0
unsigned int __fastcall PLRSAVE_ConvertLegacyHirelingExperience(D2GameStrc* pGame, unsigned short nHirelingId, unsigned int nSavedExperience)
{
    int nLevel = 1;
    while ((unsigned int)((nLevel + 2) * (nLevel + 1) * PLRSAVE_GetLegacyHirelingExpFactor(nHirelingId, nLevel + 1) * 3) <= nSavedExperience && nLevel + 1 < 99)
        ++nLevel;

    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, nHirelingId, nLevel);
    if (!pHirelingTxtRecord)
        return nSavedExperience;

    const unsigned int nExperience = MONSTERS_GetHirelingExpForNextLevel(nLevel, pHirelingTxtRecord->dwExpPerLvl);
    if (nExperience <= nSavedExperience)
        return nSavedExperience;

    return nExperience;
}

// 0x00533C70
static int __stdcall PLRSAVE_ReadLegacyMerc(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pSection, unsigned int nVersion, unsigned int nSize, int* pSize)
{
    *pSize = 0;
    if (nVersion == 71)
    {
        if (*(unsigned short*)pSection != 0x4D4A)
            return 14;
        const unsigned int nSeed = *(unsigned int*)(pSection + 2);
        if (nSeed)
        {
            const unsigned short nName = *(unsigned short*)(pSection + 6);
            if (nName)
                D2GAME_MERCS_Create(pGame, pPlayer, nName, nSeed, 0xFFFF, 0, 0);
        }
        *pSize = 8;
        goto Done;
    }
    if (nSize < 1)
    {
        LOGMANAGER_WriteLogLine("Premature end of save data.");
        return 14;
    }
    if (!*pSection)
    {
        *pSize = 1;
        return 0;
    }
    {
        unsigned char* pStart = pSection;
        *pSize = 0;
        if (nSize < sizeof(D2LegacyMercSaveStrc))
        {
            LOGMANAGER_WriteLogLine("Premature end of save data.");
            return 14;
        }
        D2LegacyMercSaveStrc* pMercSave = (D2LegacyMercSaveStrc*)pSection;
        pSection += sizeof(D2LegacyMercSaveStrc);
        int bDead = pMercSave->dwFlags & 0x10000;
        D2HirelingTxt* pHirelingTxt = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, pMercSave->wHirelingId, 1);
        if (!pHirelingTxt)
        {
            LOGMANAGER_WriteLogLine("Unable to load merc.");
            return 14;
        }
        if (nVersion <= 89)
            pMercSave->dwExperience = PLRSAVE_ConvertLegacyHirelingExperience(pGame, pMercSave->wHirelingId, pMercSave->dwExperience);
        pMercSave->wName += pHirelingTxt->wNameFirst;
        if (pMercSave->wName > pHirelingTxt->wNameLast)
            pMercSave->wName = pHirelingTxt->wNameFirst;
        D2UnitStrc* pMerc = D2GAME_MERCS_Create(pGame, pPlayer, pMercSave->wName, pMercSave->dwSeed, pMercSave->wHirelingId, pHirelingTxt->dwClass, bDead);
        int nRead;
        D2PetInfoStrc petInfo;
        if (!pMerc)
        {
            *pSize = pSection - pStart;
            goto Done;
        }
        else
        {
            petInfo.nSeed = pMercSave->dwSeed;
            petInfo.nName = pMercSave->wName;
            petInfo.nHirelingId = pMercSave->wHirelingId;
            PLAYERPETS_UpdatePetInfo(pPlayer, 7, !pMerc ? -1 : pMerc->dwUnitId, &petInfo);
            STATLIST_UnitGetStatValue(pPlayer, STAT_LEVEL, 0);
            const int nMaxLevel = DATATBLS_GetMaxLevel(0);
            int nLevel = 1;
            const unsigned int nExperience = pMercSave->dwExperience;
            if ((unsigned int)STATLIST_UnitGetStatValue(pMerc, STAT_EXPERIENCE, 0) < nExperience)
                STATLIST_SetUnitStat(pMerc, STAT_EXPERIENCE, nExperience, 0);
            D2GAME_MERCS_SendStat(pMerc, 13, nExperience);
            for (;;)
            {
                D2HirelingTxt* pMercStats = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, pMercSave->wHirelingId, nLevel);
                if (!pMercStats)
                {
                    FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x1660);
                    exit(-1);
                }
                const int nNextLevel = nLevel + 1;
                if (nNextLevel > nMaxLevel)
                    break;
                if (nExperience < MONSTERS_GetHirelingExpForNextLevel(nNextLevel, pMercStats->dwExpPerLvl))
                    break;
                nLevel = nNextLevel;
            }
            MONSTERAI_UpdateMercStatsAndSkills(pGame, pPlayer, pMerc, nLevel);
            if (!pMerc->pInventory)
                INVENTORY_AllocInventory(0, pMerc);
            if (bDead)
            {
                PLAYERPETS_HandlePetDeath(pGame, pPlayer, pMerc);
                pMerc->dwFlags |= 0x10000;
                SUNIT_SetCombatMode(pGame, pMerc, 12);
                MONSTER_DeleteEvents(pGame, pMerc);
            }
            unsigned char* pItems = pSection;
            {
            int nItemsRead;
            int nResult = PLRSAVE_ReadItemSection(pGame, pMerc, pItems, nVersion, pStart + nSize - pItems, 0, &nItemsRead);
            if (nResult)
                return nResult;
            D2GAME_ITEMS_UpdateInventoryItems(pGame, pMerc, 0, 0);
            sub_0055F4F0_Nop(pGame, pMerc, 0);
            STATLIST_SetUnitStat(pMerc, STAT_HITPOINTS, STATLIST_GetMaxLifeFromUnit(pMerc), 0);
            MONSTERAI_SendMercStats(pGame, pPlayer, 1);
            nRead = pItems + nItemsRead - pStart;
            }
        }
    *pSize = nRead;
    }
Done:
    return 0;
}

// 0x00533F70
int __stdcall PLRSAVE_ReadHotkeySection(D2UnitStrc* pPlayer, const unsigned char* pSection, unsigned int nSize, int* pSize)
{
    *pSize = 0;

    D2ClientStrc* pClient = UnitGetClient(pPlayer, ".\\PLAYER\\PlrSave.cpp", 5793);
    if (!pClient)
    {
        return 0;
    }

    *pSize = 0x30;
    if (nSize <= 0x48)
    {
        return 0;
    }

    const unsigned char* pKey = pSection;
    for (int i = 8; i < 16; ++i)
    {
        int nSkillId = pKey[0];
        if (nSkillId >= 156 && nSkillId <= 216)
        {
            nSkillId += 65;
        }
        else if (nSkillId == SKILL_DRAGONTALON)
        {
            nSkillId = -1;
        }

        CLIENTS_SetSkillHotKey(pClient, i, nSkillId, pKey[1], -1);
        pKey += 6;
    }

    if (nSize > 0x51)
    {
        const int* pSwitch = (const int*)(pSection + *pSize);
        const int nRightSkillId = pSwitch[1];
        UNITS_SetSwitchLeftSkill(pPlayer, pSwitch[0], -1);
        UNITS_SetSwitchRightSkill(pPlayer, nRightSkillId, -1);
        *pSize += 8;
    }

    return 0;
}

// 0x00534020
int __fastcall D2GAME_SAVE_ProcessSaveFile(D2GameStrc* pGame, D2ClientStrc* pClient, unsigned char* pSaveFile, unsigned int nSize, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoomArg, int nXArg, int nYArg)
{
    D2UnitStrc* pLoadedPlayer = 0;
    *ppPlayer = 0;
    if (nSize < 130)
        return 9;
    int bCreateNew, nVersion, nStatCount, nSkillCount, nLeftSkillId, nRightSkillId, nRead;
    int nResult = PLRSAVE_ReadLegacyHeader(pGame, pClient, (D2LegacySaveHeaderStrc*)pSaveFile, &pLoadedPlayer, &bCreateNew, (unsigned int*)&nVersion, &nStatCount, &nSkillCount, &nLeftSkillId, &nRightSkillId, &nRead);
    if (nResult)
        return nResult;
    if (bCreateNew)
        return PLRSAVE_CreateNewPlayer(pGame, pClient, ppPlayer);
    D2UnitStrc* pPlayer = pLoadedPlayer;
    *ppPlayer = pPlayer;
    unsigned char* pSection = pSaveFile + nRead;
    nSize -= nRead;
    nResult = PLRSAVE_ReadLegacyQuests(pPlayer, pSection, nVersion, &nRead);
    if (nResult)
        return nResult;
    pSection += nRead;
    nSize -= nRead;
    nResult = D2GAME_SAVE_ReadWaypointData(pPlayer, pSection, nVersion, &nRead);
    if (nResult)
        return nResult;
    pSection += nRead;
    nSize -= nRead;
    nResult = PLRSAVE_ReadLegacyPlayerIntro(pPlayer, pSection, nVersion, &nRead);
    if (nResult)
        return nResult;
    pSection += nRead;
    nSize -= nRead;
    nResult = PLRSAVE_ReadLegacyStats(pGame, pPlayer, pSection, 16, nVersion, &nRead);
    if (nResult)
        return nResult;
    int nHitpoints = STATLIST_UnitGetStatValue(pPlayer, STAT_HITPOINTS, 0);
    int nMana = STATLIST_UnitGetStatValue(pPlayer, STAT_MANA, 0);
    int nGold = STATLIST_UnitGetStatValue(pPlayer, STAT_GOLD, 0);
    if (nGold < 0 || nGold > UNITS_GetInventoryGoldLimit(pPlayer))
    {
        if (pPlayer)
        {
            if (pPlayer->dwUnitType == UNIT_PLAYER)
                UNITS_GetInventoryGoldLimit(pPlayer);
            STATLIST_SetUnitStat(pPlayer, STAT_GOLD, 0, 0);
        }
    }
    nGold = STATLIST_UnitGetStatValue(pPlayer, STAT_GOLDBANK, 0);
    if (nGold < 0 || nGold > UNITS_GetStashGoldLimit(pPlayer))
    {
        if (pPlayer)
        {
            if (pPlayer->dwUnitType == UNIT_PLAYER)
                UNITS_GetStashGoldLimit(pPlayer);
            STATLIST_SetUnitStat(pPlayer, STAT_GOLDBANK, 0, 0);
        }
    }
    pSection += nRead;
    nSize -= nRead;
    nResult = PLRSAVE_ReadLegacySkills(pGame, pClient, pPlayer, pSection, nSkillCount, nVersion, &nRead);
    if (nResult)
        return nResult;
    sub_00568DB0_Return0(pGame, pPlayer);
    if (nLeftSkillId)
        D2GAME_AssignSkill(pPlayer, 1, nLeftSkillId, -1);
    if (nRightSkillId)
        D2GAME_AssignSkill(pPlayer, 0, nRightSkillId, -1);
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    pPlayerData->nLeftSkillId = nLeftSkillId;
    pPlayerData->nRightSkillId = nRightSkillId;
    nSize -= nRead;
    pSection += nRead;
    nResult = PLRSAVE_ReadItemSection(pGame, pPlayer, pSection, nVersion, nSize, 0, &nRead);
    if (!nResult)
    {
        nSize -= nRead;
        pSection += nRead;
        nResult = PLRSAVE_ReadCorpseSection(pGame, pPlayer, pSection, nVersion, nSize, &nRead);
        if (!nResult)
        {
            nSize -= nRead;
            pSection += nRead;
            nResult = PLRSAVE_ReadLegacyMerc(pGame, pPlayer, pSection, nVersion, nSize, &nRead);
            if (!nResult)
            {
                pSection += nRead;
                nRead = 0;
                PLRSAVE_ReadHotkeySection(pPlayer, pSection, nVersion, &nRead);
            }
        }
    }
    STATLIST_SetUnitStat(pPlayer, STAT_HITPOINTS, nHitpoints, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_MANA, nMana, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_ATTACKRATE, 100, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_VELOCITYPERCENT, 100, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_OTHER_ANIMRATE, 100, 0);
    int nClass;
    if (!pPlayer)
        nClass = -1;
    else
        nClass = pPlayer->dwClassId;
    const int nLevel = STATLIST_GetUnitBaseStat(pPlayer, STAT_LEVEL, 0);
    const int nNextExperience = DATATBLS_GetLevelThreshold(nClass, nLevel);
    STATLIST_SetUnitStat(pPlayer, STAT_NEXTEXP, nNextExperience, 0);
    if (CLIENTS_GetWeaponSwitch(pClient))
        D2GAME_PACKETS_SendPacket0x97(pClient);
    return 0;
}

struct D2SaveFileTagStrc
{
    unsigned int dwHeaderMagic;
    unsigned int dwVersion;
};

int __fastcall PlayerCreate(D2GameStrc* pGame, D2ClientStrc* pClient, unsigned char* pSaveFile, unsigned int nSize, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoomArg, int nXArg, int nYArg); // 0x0056B180

// 0x00534330
int __fastcall PLRSAVE_ReadSaveData(D2GameStrc* pGame, D2ClientStrc* pClient, D2SaveHeaderStrc* pSave, unsigned int nSize, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    if (nSize < 8)
    {
        return 9;
    }

    const D2SaveFileTagStrc tTag = *(D2SaveFileTagStrc*)pSave;
    if (tTag.dwHeaderMagic != 0xAA55AA55)
    {
        return 9;
    }

    if (tTag.dwVersion <= 0x5B)
    {
        return D2GAME_SAVE_ProcessSaveFile(pGame, pClient, (unsigned char*)pSave, nSize, ppPlayer, pRoom, nX, nY);
    }

    return PlayerCreate(pGame, pClient, (unsigned char*)pSave, nSize, ppPlayer, pRoom, nX, nY);
}

// 0x005343A0
static int __stdcall D2GAME_SAVE_ReadFile(D2GameStrc* pGame, D2ClientStrc* pClient, const char* szName, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoomArg, int nXArg, int nYArg)
{
    char szPath[1024];
    char szFileName[500];
    unsigned char saveFile[0x2000];
    D2UnitStrc* pPlayer = 0;
    int nResult = 0;

    *ppPlayer = 0;
    FOG_GetSavePath(szPath, sizeof(szPath));
    sprintf(szFileName, gszSaveFormat_006D4230, szPath, szName);

    _iobuf* pSaveFile = fopen(szFileName, gszFileModeRb);
    if (pSaveFile)
    {
        const unsigned int nFileSize = fread(saveFile, 1, sizeof(saveFile), pSaveFile);
        fclose(pSaveFile);
        if (nFileSize)
        {
            nResult = PLRSAVE_ReadSaveData(pGame, pClient, (D2SaveHeaderStrc*)saveFile, nFileSize, &pPlayer, pRoomArg, nXArg, nYArg);
            if (nResult)
            {
                return nResult;
            }
        }
    }

    *ppPlayer = pPlayer;
    if (!pPlayer)
    {
        nResult = SYSERROR_UNK_14;
    }

    return nResult;
}

// 0x005344B0
static int __stdcall PLRSAVE_ReadSaveFromDisk(D2GameStrc* pGame, D2ClientStrc* pClient, const char* szName, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoomArg, int nXArg, int nYArg)
{
    int nErrorCode = SYSERROR_UNK_14;
    D2UnitStrc* pPlayer = 0;
    if (!gpD2EventCallbackTable)
    {
        nErrorCode = D2GAME_SAVE_ReadFile(pGame, pClient, szName, &pPlayer, pRoomArg, nXArg, nYArg);
        if (pPlayer)
        {
            QUESTS_SequenceCycler(pGame, pPlayer, 0);
        }
    }

    *ppPlayer = pPlayer;
    return nErrorCode;
}

// 0x00534520
static int __stdcall PLRSAVE_ReadSaveFromClient(D2GameStrc* pGame, D2ClientStrc* pClient, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoomArg, int nXArg, int nYArg)
{
    *ppPlayer = 0;
    D2SaveHeaderStrc* pSaveHeader = CLIENTS_GetSaveHeader(pClient);
    const int nSaveHeaderSize = CLIENTS_GetSaveHeaderSize(pClient);
    if (!nSaveHeaderSize)
    {
        return SYSERROR_UNK_14;
    }

    const int nErrorCode = PLRSAVE_ReadSaveData(pGame, pClient, pSaveHeader, nSaveHeaderSize, ppPlayer, pRoomArg, nXArg, nYArg);
    if (nErrorCode)
    {
        *ppPlayer = 0;
        return nErrorCode;
    }

    if (*ppPlayer)
    {
        if (pGame->nGameType == GAMETYPE_1 || pGame->nGameType == GAMETYPE_2)
        {
            CLIENTS_FreeSaveHeader(pClient);
        }

        QUESTS_SequenceCycler(pGame, *ppPlayer, 0);
    }

    return 0;
}

// 0x005345A0
int __fastcall D2GAME_SAVE_GetUnitDataFromFile(D2GameStrc* pGame, D2ClientStrc* pClient, const char* szName, int bLoadSave, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoomArg, int nXArg, int nYArg)
{
    int nErrorCode;
    if (pGame->nGameType != GAMETYPE_1 && pGame->nGameType != GAMETYPE_2 && !gpD2EventCallbackTable)
    {
        if (bLoadSave)
        {
            nErrorCode = PLRSAVE_ReadSaveFromDisk(pGame, pClient, szName, ppPlayer, pRoomArg, nXArg, nYArg);
        }
        else
        {
            nErrorCode = PLRSAVE_CreateNewPlayer(pGame, pClient, ppPlayer);
        }
    }
    else
    {
        if (bLoadSave)
        {
            nErrorCode = PLRSAVE_ReadSaveFromClient(pGame, pClient, ppPlayer, pRoomArg, nXArg, nYArg);
        }
        else
        {
            nErrorCode = PLRSAVE_CreateNewPlayer(pGame, pClient, ppPlayer);
        }
    }

    if (nErrorCode)
    {
        return nErrorCode;
    }

    if (!*ppPlayer)
    {
        return SYSERROR_UNK_14;
    }

    SKILLS_RefreshPassivesAndPetLimits(*ppPlayer);
    return 0;
}

// 0x00534630
int __stdcall D2GAME_10029_SAVE_WriteFileInterface(D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName)
{
    return D2GAME_SAVE_WriteFile(pGame, pPlayer, szName, 0);
}

static inline D2CharStatsTxt* PLRSAVE2_GetCharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }

    return 0;
}

void __fastcall PLAYER_CreateStartItemsFromCharStatsTxt(D2UnitStrc* pPlayer, D2GameStrc* pGame, void* pUnused); // 0x00534F10

// 0x005350F0
void __fastcall PLAYER_CloseInteraction(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nUnitType;
    int nUnitGUID;
    if (SUNIT_GetInteractInfo(pUnit, &nUnitType, &nUnitGUID))
    {
        D2UnitStrc* pInteractUnit = SUNIT_GetServerUnit(pGame, nUnitType, nUnitGUID);
        if (pInteractUnit)
        {
            switch (nUnitType)
            {
            case UNIT_MONSTER:
                D2GAME_NPC_ResetInteract(pGame, pUnit, pInteractUnit);
                break;

            case UNIT_OBJECT:
                OBJMODE_CloseObjectInteraction(pGame, pUnit, pInteractUnit);
                break;

            case UNIT_PLAYER:
                PLRTRADE_StopInteraction(pGame, pUnit);
                break;

            case UNIT_ITEM:
                if (DATATBLS_GetItemsTxtRecord(pInteractUnit->dwClassId)->dwCode == ' xob')
                {
                    PLRTRADE_CloseCubeInteraction(pGame, pUnit);
                }
                break;
            }
        }
    }

    ACT5Q5_OnPlayerDied(pGame, pUnit);
}


void __stdcall SUNITPROXY_RemoveInventoryItems(D2GameStrc* pGame, D2InventoryStrc* pInventory); // 0x00536510
// 0x00536580
static void __stdcall SUNITPROXY_ClearNpcRecordData(D2NpcRecordStrc* pNpcRecord, D2GameStrc* pGame)
{
    if (pNpcRecord->bGambleInit)
    {
        D2NpcGambleStrc* pGamble = pNpcRecord->pGamble;
        while (pGamble)
        {
            D2NpcGambleStrc* pNextGamble = pGamble->pNext;
            if (pGamble->pInventory)
            {
                SUNITPROXY_RemoveInventoryItems(pGame, pGamble->pInventory);
                INVENTORY_FreeInventory(pGamble->pInventory);
                pGamble->pInventory = 0;
            }
            sub_0040B480(pGame->pMemoryPool, pGamble, ".\\UNIT\\sunitproxy.cpp", 0x1E6, 0);
            pGamble = pNextGamble;
        }
        pNpcRecord->pGamble = 0;
    }

    SUNITPROXY_RemoveInventoryItems(pGame, pNpcRecord->pInventory);
    INVENTORY_FreeInventory(pNpcRecord->pInventory);
    pNpcRecord->pInventory = 0;

    D2NpcEventStrc* pNpcEvent = pNpcRecord->pEvent;
    while (pNpcEvent)
    {
        D2NpcEventStrc* pNextEvent = pNpcEvent->pNext;
        if (pNpcEvent->field_C == 1 && pNpcEvent->pUnit)
        {
            ITEMS_RemoveFromAllPlayers(pGame, pNpcEvent->pUnit);
        }
        sub_0040B480(pGame->pMemoryPool, pNpcEvent, ".\\UNIT\\sunitproxy.cpp", 0x204, 0);
        pNpcEvent = pNextEvent;
    }
    pNpcRecord->pEvent = 0;
}

static D2NpcRecordStrc* D10_GetNpcRecordFromUnit(D2GameStrc* pGame, D2UnitStrc* pNpc)
{
    int nIndex;
    return SUNITPROXY_GetNpcRecordFromClassId(pGame, !pNpc ? -1 : pNpc->dwClassId, &nIndex);
}

// 0x00536D10
void __fastcall SUNITPROXY_AllocNpcInventory(D2GameStrc* pGame, D2NpcRecordStrc* pNpcRecord, D2UnitStrc* pNpc)
{
    SUNITPROXY_ClearNpcRecordData(pNpcRecord, pGame);

    pNpcRecord->bVendorInit = 0;
    pNpcRecord->dwTicks = 0;
    pNpcRecord->pInventory = INVENTORY_AllocInventory(pGame->pMemoryPool, 0);

    if (pNpc)
    {
        pNpc->pInventory = pNpcRecord->pInventory;
    }
}

// 0x00537190
void __fastcall SUNITPROXY_FreeNpcGamble(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pPlayer)
{
    int nIndex;
    D2NpcRecordStrc* pNpcRecord = SUNITPROXY_GetNpcRecordFromClassId(pGame, !pNpc ? -1 : pNpc->dwClassId, &nIndex);
    const int nPlayerGUID = !pPlayer ? -1 : pPlayer->dwUnitId;

    if (pNpcRecord && pNpcRecord->bGambleInit)
    {
        D2NpcGambleStrc* pPreviousGamble = 0;
        for (D2NpcGambleStrc* pGamble = pNpcRecord->pGamble; pGamble; pGamble = pGamble->pNext)
        {
            if (pGamble->dwGUID == nPlayerGUID)
            {
                if (pPreviousGamble)
                {
                    pPreviousGamble->pNext = pGamble->pNext;
                }
                else
                {
                    pNpcRecord->pGamble = pGamble->pNext;
                }

                if (pGamble->pInventory)
                {
                    SUNITPROXY_RemoveInventoryItems(pGame, pGamble->pInventory);
                    INVENTORY_FreeInventory(pGamble->pInventory);
                    pGamble->pInventory = 0;
                }

                sub_0040B480(pGame->pMemoryPool, pGamble, ".\\UNIT\\sunitproxy.cpp", 0x5D0, 0);
                return;
            }

            pPreviousGamble = pGamble;
        }
    }
}


// 0x00537340
void __fastcall SUNITPROXY_UpdateNpcsOnActChange(D2GameStrc* pGame, D2UnitStrc* pUnit, int nCurrentLevelId, int nDestLevelId)
{
    D2UnitProxyArgStrc unitProxyArg;
    unitProxyArg.nLevelId = nCurrentLevelId;
    unitProxyArg.nCounter = 0;

    switch (nCurrentLevelId)
    {
    case LEVEL_ROGUEENCAMPMENT:
        SUNIT_IterateLivingPlayers(pGame, SUNITPROXY_CountPlayersInLevel, &unitProxyArg);
        SUNITPROXY_UpdateVendorInventory(pGame, 0, unitProxyArg.nCounter == 0);
        break;

    case LEVEL_LUTGHOLEIN:
        SUNIT_IterateLivingPlayers(pGame, SUNITPROXY_CountPlayersInLevel, &unitProxyArg);
        SUNITPROXY_UpdateVendorInventory(pGame, 1, unitProxyArg.nCounter == 0);
        break;

    case LEVEL_KURASTDOCKTOWN:
        SUNIT_IterateLivingPlayers(pGame, SUNITPROXY_CountPlayersInLevel, &unitProxyArg);
        SUNITPROXY_UpdateVendorInventory(pGame, 2, unitProxyArg.nCounter == 0);
        break;

    case LEVEL_THEPANDEMONIUMFORTRESS:
        SUNIT_IterateLivingPlayers(pGame, SUNITPROXY_CountPlayersInLevel, &unitProxyArg);
        SUNITPROXY_UpdateVendorInventory(pGame, 3, unitProxyArg.nCounter == 0);
        break;

    case LEVEL_HARROGATH:
        SUNIT_IterateLivingPlayers(pGame, SUNITPROXY_CountPlayersInLevel, &unitProxyArg);
        SUNITPROXY_UpdateVendorInventory(pGame, 4, unitProxyArg.nCounter == 0);
        break;

    default:
        break;
    }

    switch (nDestLevelId)
    {
    case LEVEL_ROGUEENCAMPMENT:
        QUESTS_UpdateNPCIntros(pGame, pUnit, 0);
        break;

    case LEVEL_LUTGHOLEIN:
        QUESTS_UpdateNPCIntros(pGame, pUnit, 1);
        ACT1Q4_UpdateQuestStateOnActChange(pGame, pUnit);
        break;

    case LEVEL_KURASTDOCKTOWN:
        QUESTS_UpdateNPCIntros(pGame, pUnit, 2);
        break;

    case LEVEL_HARROGATH:
        QUESTS_UpdateNPCIntros(pGame, pUnit, 4);
        break;

    default:
        return;
    }
}

// 0x00537580
void __fastcall SUNITPROXY_OnClientRemovedFromGame(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    if (pGame->nGameType == 3)
    {
        return;
    }

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
    {
        return;
    }

    unsigned char nAct = 0;

    D2UnitProxyArgStrc unitProxyArg;
    unitProxyArg.nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    unitProxyArg.nCounter = 0;

    switch (unitProxyArg.nLevelId)
    {
    case LEVEL_ROGUEENCAMPMENT:
        nAct = ACT_I;
        break;

    case LEVEL_LUTGHOLEIN:
        nAct = ACT_II;
        break;

    case LEVEL_KURASTDOCKTOWN:
        nAct = ACT_III;
        break;

    case LEVEL_THEPANDEMONIUMFORTRESS:
        nAct = ACT_IV;
        break;

    default:
        return;
    }

    SUNIT_IterateLivingPlayers(pGame, SUNITPROXY_CountPlayersInLevel, &unitProxyArg);
    --unitProxyArg.nCounter;
    SUNITPROXY_UpdateVendorInventory(pGame, nAct, unitProxyArg.nCounter == 0);
}

static inline D2NpcVendorStateStrc* SUNITPROXY_GetVendorState(D2NpcRecordStrc* pNpcRecord)
{
    return (D2NpcVendorStateStrc*)&pNpcRecord->bVendorInit;
}

// 0x00537230
void __stdcall SUNITPROXY_UpdateVendorInventory(D2GameStrc* pGame, unsigned char nAct, int bNoMorePlayersInLevel)
{
    D2NpcControlStrc* pNpcControl = pGame->pNpcControl;
    D2NpcRecordStrc* pRecords = pNpcControl->pFirstRecord;
    int i = 0;
    const unsigned int nTickCount = GetTickCount();
    for (; i < pNpcControl->nArraySize; ++i)
    {
        D2NpcRecordStrc* pNpcRecord = &pRecords[i];
        D2NpcVendorStateStrc* pVendor = SUNITPROXY_GetVendorState(pNpcRecord);
        if (pVendor && pVendor->nAct == nAct && pVendor->bTrader == 1 && pNpcRecord->bTrading == 1 && pVendor->bVendorInit == 1)
        {
            if (bNoMorePlayersInLevel)
            {
                D2UnitStrc* pNpc = SUNIT_GetServerUnit(pGame, UNIT_MONSTER, pNpcRecord->dwNPCGUID);
                if (pNpc && (!pNpc ? -1 : pNpc->dwClassId) == pNpcRecord->nNPC)
                {
                    if (!MONSTERAI_GetInteractUnitCount(sub_00535E80_GetMonInteract(pNpc)))
                    {
                        SUNITPROXY_AllocNpcInventory(pGame, pNpcRecord, pNpc);
                    }
                    else
                    {
                        pVendor->bRefreshInventory = 1;
                    }
                }
                else
                {
                    SUNITPROXY_AllocNpcInventory(pGame, pNpcRecord, 0);
                }
            }
            else
            {
                if (nTickCount > pVendor->dwTicks + 240000)
                {
                    pVendor->bRefreshInventory = 1;
                    pVendor->dwTicks = nTickCount;
                }
            }
        }
    }
}

// 0x00537680
void __fastcall SUNITPROXY_UpdateGambleInventory(D2GameStrc* pGame, D2UnitStrc* pNpc, D2UnitStrc* pPlayer, D2ClientStrc* pClient)
{
    D2GAME_INVMODE_First(pGame, pNpc, pClient, 0);

    D2InventoryStrc* pGambleInventory = SUNITPROXY_GetGambleInventory(pGame, pPlayer, pNpc);
    if (pGambleInventory)
    {
        D2GAME_INVMODE_First(pGame, pNpc, pClient, pGambleInventory);
    }
}


// 0x0053FF00
void __fastcall PLRTRADE_AddGold(D2UnitStrc* pUnit, int nStat, int nValue)
{
    if (!pUnit)
    {
        return;
    }

    const int nNewValue = nValue + STATLIST_UnitGetStatValue(pUnit, nStat, 0);
    if (nNewValue < 0)
    {
        STATLIST_SetUnitStat(pUnit, nStat, 0, 0);
        return;
    }

    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        switch (nStat)
        {
        case STAT_GOLD:
            if (nNewValue > UNITS_GetInventoryGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, STAT_GOLD, 0, 0);
                return;
            }
            break;
        case STAT_GOLDBANK:
            if (nNewValue > UNITS_GetStashGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, STAT_GOLDBANK, 0, 0);
                return;
            }
            break;
        }
    }

    STATLIST_AddUnitStat(pUnit, nStat, nValue, 0);
}

void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* ptGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0


// 0x005339A0
int __fastcall PLRSAVE_ReadCorpseSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pSection, unsigned int dwVersion, int nRemainingSize, int* pSize)
{
    *pSize = 0;

    if (dwVersion < 71 || dwVersion > 96)
    {
        return 1;
    }

    if (*(unsigned short*)pSection != 'MJ')
    {
        return SYSERROR_UNK_14;
    }

    pSection += 2;
    const unsigned short nCount = *(unsigned short*)pSection;
    pSection += 2;
    nRemainingSize -= 4;
    int nSize = 4;

    for (unsigned int i = 0; i < nCount; ++i)
    {
        int nSectionSize;
        const int nErrorCode = PLRSAVE_ReadCorpse(pPlayer, pGame, pSection, dwVersion, nRemainingSize, &nSectionSize);
        if (nErrorCode)
        {
            return nErrorCode;
        }

        nSize += nSectionSize;
        pSection += nSectionSize;
        nRemainingSize -= nSectionSize;
    }

    *pSize = nSize;
    return 0;
}

// 0x00533A60
int __fastcall PLRSAVE_CalcValue(int nA, int nB)
{
    return (nA + 1) * nA * nB * 3;
}

static inline D2StatesTxt* STATES_GetStatesTxtRecordInline(int nStateId)
{
    if (nStateId >= 0 && nStateId < sgptDataTables->nStatesTxtRecordCount)
    {
        return &sgptDataTables->pStatesTxt[nStateId];
    }

    return 0;
}

extern "C" const char gData_006E09C4[36]; // 0x006E09C4

extern int gbWriteSaveFile = 1; // 0x007310CC

extern "C" const char gData_006E09C4[36] = "Unable to open player save file %s"; // 0x006E09C4
#pragma comment(linker, "/alternatename:_gszSaveOpenError=_gData_006E09C4")
