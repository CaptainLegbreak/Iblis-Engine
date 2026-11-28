#include "D2SkillIds.h"
#include "D2LevelIds.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2QuestData.h"
#include "D2Primitives.h"
#include "D2GameStrc.h"
#include "D2GameRecords.h"
#include "D2ItemsWorld.h"
#include "D2LevelTxt.h"
#include "D2PlayerModes.h"
#include "D2ObjModes.h"
#include "D2ItemModes.h"
#include "D2GameServer.h"
#include "D2GameClient.h"
#include "D2SaveHeader.h"
#include "D2LanguageNames.h"
#include "FogApi.h"
#include "StormApi.h"
#include "D2CommonApi.h"
#include "FogApi.h"
// build: symbol _gaszLanguageNames 0x00732084

struct D2ClientStrc;

struct D2InventoryStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define PLRSAVE2_WAYPOINT_HEADER 0x5357

#define PLRSAVE2ERROR_BAD_WAYPOINT 0x10

#define PLRSAVE2_SKILLS_MARKER 0x6669

#define PLRSAVE2ERROR_BAD_PLAYERINTRO 17

#define PLRSAVE2ERROR_BAD_PET 22

#define STAT_HITPOINTS 6

#define PLRSAVE2ERROR_BAD_SKILLS 0x13

#define UNITFLAG_SKSRVDOFUNC 0x00000040

#define UNITFLAG_HASEVENTSOUND 0x00000400

#define UNITFLAG_HASTXTMSG 0x00000100

#define UNITFLAG_DOUPDATE 0x00000001

#define UNIT_PLAYER 0

#define STAT_MANA 8

#define STAT_STAMINA 10

#define STAT_LEVEL 12

#define STAT_GOLD 14

#define STAT_ATTACKRATE 68

struct D2RunesTxt;

struct D2SaveSkillKeyStrc;

struct D2SaveHeaderStrc;

struct D2PlayerDataStrc;

struct D2WaypointSaveFlagStrc;

struct D2WaypointSaveDataStrc;

struct D2PlrIntroSaveStrc;

struct D2SaveSkillLevelStrc;

struct D2Act5Quest3Strc;

struct D2GameStrc;

struct D2DataTablesStrc;

struct D2UnitStrc;

struct D2WaypointDataStrc;

struct D2BitBufferStrc;

struct D2ItemStatCostTxt;

struct D2QuestDataStrc;

struct D2ItemSaveStrc;


extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);

extern "C" long __cdecl _time32(long* pTime); // 0x006850E6

extern D2DataTablesStrc* sgptDataTables; // 0x00744304


void __fastcall CLIENTS_GetGuildEmblem(D2ClientStrc* pClient, unsigned char* pBackgroundColor, unsigned char* pForegroundColor, unsigned char* pEmblemType); // 0x00539190

#include "D2GameFuncs.h"
#include "FogApi2.h"

int __fastcall CLIENTS_GetPlayTime(D2ClientStrc* pClient); // 0x005385C0


int __fastcall CLIENTS_GetCreateTime(D2ClientStrc* pClient); // 0x00538790


void __fastcall CLIENTS_GetSkillHotKey(D2ClientStrc* pClient, int nId, int* pSkillId, int* pHand, int* pItemGUID); // 0x005390D0

unsigned char __fastcall CLIENTS_GetWeaponSwitch(D2ClientStrc* pClient); // 0x00539220


unsigned short __fastcall PLRSAVE2_GetItemIndex(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nGUID); // 0x00568DC0

void __fastcall PLRSAVE2_WriteMercData(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2SaveHeaderStrc* pSaveHeader); // 0x00568E60

D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190

D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0

void __stdcall UNITS_GetSwitchLeftSkillData(D2UnitStrc* pUnit, int* pSwitchLeftSkillId, int* pSwitchLeftSkillFlags); // 0x00623220

void __stdcall UNITS_GetSwitchRightSkillData(D2UnitStrc* pUnit, int* pSwitchRightSkillId, int* pSwitchRightSkillFlags); // 0x00623290

void __stdcall INVENTORY_GetItemSaveGfxInfo(D2UnitStrc* pUnit, unsigned char* pComponents, unsigned char* pColors); // 0x0063E510


struct D2WaypointDataStrc
{
    unsigned short nFlag0;
    unsigned short unk0x02;
    int unk0x04[3];
};

#pragma pack(push, 1)

struct D2WaypointSaveFlagStrc
{
    D2WaypointDataStrc flags;
    unsigned int unk0x10;
    unsigned int unk0x14;
};

struct D2WaypointSaveDataStrc
{
    unsigned short nHeader;
    int unk0x02;
    unsigned short nRecordSize;
    D2WaypointSaveFlagStrc waypoints[3];
};

#pragma pack(pop)


int __fastcall PLRSAVE2_WriteSaveHeader(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd); // 0x00568F20

int __fastcall PLRSAVE2_WriteQuestSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd); // 0x00569320

int __fastcall PLRSAVE2_WriteWaypointData(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd); // 0x005693E0

int __fastcall PLRSAVE2_WritePlrIntroSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd); // 0x00569490

int __fastcall PLRSAVE2_WritePlayerStats(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd); // 0x00569540

int __fastcall PLRSAVE2_WriteSkillSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd); // 0x005696F0

int __fastcall PLRSAVE2_WriteItemSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd, int nArg5, int nArg6, int bSizing); // 0x005697B0

int __fastcall PLRSAVE2_WriteCorpsesSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd, int nArg6, int bSizing); // 0x005697F0

int __fastcall PLRSAVE2_WriteMercSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd, int nArg6, int bSizing); // 0x005699A0

int __fastcall PLRSAVE2_WriteIronGolemSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd, int nUnused, int bSizing); // 0x00569A00

struct D2PlrIntroSaveStrc
{
    unsigned short nHeader;
    unsigned short nLength;
    unsigned char nQuestIntroFlags[3][8];
    unsigned char nNpcIntroFlags[3][8];
};


void __fastcall sub_0055F4F0_Nop(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnused); // 0x0055F4F0



extern const unsigned int gdwBitMasks[32]; // 0x006CE268


void __fastcall D2GAME_SetSkills(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove); // 0x0056DEB0


struct D2SaveSkillLevelStrc { unsigned char value; };

void __fastcall D2GAME_SetSkills(D2UnitStrc*,int,int,int); // 0x0056DEB0

enum { REMOVE_SKILL = 1 };


void __stdcall UNITS_SetUsedSkill(D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill); // 0x00620210






int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690


D2UnitStrc* __fastcall ITEMS_CreateItemFromBitstream(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char* pBitstream, unsigned int nBufferSize, int bCheckForHeader, D2ItemSaveStrc* pItemSave, unsigned int* pSize, unsigned int dwVersion); // 0x00558CB0


int __fastcall GAME_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50


int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit); // 0x00622E70

int __stdcall STATLIST_GetMaxStaminaFromUnit(D2UnitStrc* pUnit); // 0x00625DB0


int __fastcall PLRSAVE2_GetItemGUIDFromIndex(D2GameStrc* pGame, D2UnitStrc* pUnit, int nIndex); // 0x0056AF20



D2UnitStrc* __fastcall SUNIT_AllocUnitData(int nUnitType, int nClassId, int nX, int nY, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, char nAllocFlags, int nMode, unsigned int nOverrideUnitGUID); // 0x00555230


void __fastcall D2GAME_SendPacket0x8E_CorpseAssign_ToAllPlayers(D2GameStrc* pGame, int nUnitId, int nCorpseId, unsigned char bAssign); // 0x0053DF80

struct D2StatListStrc;

struct D2StatStrc;

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

#define D2_MIN(a, b) (((a) < (b)) ? (a) : (b))

struct D2StatListExStrc;

struct D2QuestSaveStrc;

struct D2PackedWordStrc;

#pragma pack(push, 2)

struct D2QuestSaveStrc
{
    unsigned int dwHeaderMagic;
    unsigned int dwVersion;
    unsigned short wSize;
    unsigned char aQuestData[3][0x60];
};

#pragma pack(pop)

void __fastcall PLRINTRO_CopyQuestIntroFlagsToBuffer(D2PlrIntroStrc* pPlayerIntro, unsigned char* pBuffer); // 0x00572520

void __fastcall PLRINTRO_CopyNpcIntroFlagsToBuffer(D2PlrIntroStrc* pPlayerIntro, unsigned char* pBuffer); // 0x00572530


void __fastcall CLIENTS_SetFlags(D2ClientStrc*, unsigned short); // 0x00538630


extern "C" int __cdecl _stricmp(const char*, const char*); // 0x006841E9

int __fastcall PLRSAVE2_CheckPlayerFlags(D2GameStrc*, unsigned short, D2ClientStrc*); // 0x00569D80

void __fastcall CLIENTS_SetCreateTime(D2ClientStrc*, unsigned int); // 0x00538760


void __fastcall PLRSAVE2_UnpackWord(unsigned int* pRaw, int* pId, int* pFlag, int* pCount); // 0x00569EC0

void __fastcall CLIENTS_SetGuildEmblem(D2ClientStrc*, unsigned char, unsigned char, unsigned char); // 0x005391C0

struct D2CorpseStrc;

struct D2CorpseSaveStrc
{
    unsigned int nUnk;
    int nX;
    int nY;
};

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit);                                                         // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit);                                                         // 0x0045AE20

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID);                // 0x00552F60


unsigned int __stdcall INVENTORY_GetItemCount(D2InventoryStrc* pInventory);                                 // 0x0063CD60



struct D2SkillStrc;

struct D2CharStatsTxt;

extern const int gnPlrSave2ErrorRemap[PLRSAVE2ERROR_COUNT]; // 0x006E1208

void __fastcall sub_005385D0_Nop(D2ClientStrc* pClient, int nUnused1, int nUnused2); // 0x005385D0


void __fastcall PLAYER_CreateStartItemsFromCharStatsTxt(D2UnitStrc* pPlayer, D2GameStrc* pGame, unsigned char nAct); // 0x00534F10


void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270


int __fastcall PLRSAVE2_ReadStatsEx(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion); // 0x0056A4F0

void __fastcall CLIENTS_SetIronGolemItemGUID(D2ClientStrc* pClient, int nIronGolemItemGUID);                // 0x00538700

int __fastcall PLRSAVE2_CreateItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc** ppItem, unsigned char** ppSection, unsigned char* pEnd, unsigned int dwVersion); // 0x0056ACE0

#define PLRSAVE2ERROR_BAD_IRONGOLEM 23

#pragma intrinsic(memcpy)

struct D2MercSaveDataStrc
{
    unsigned int nFlags;
    unsigned int nSeed;
    unsigned short wName;
    unsigned short nHirelingId;
    unsigned int nExperience;
    unsigned int unk0x10[4];
};


D2InventoryStrc* __stdcall INVENTORY_AllocInventory(void* pMemPool, D2UnitStrc* pOwner); // 0x0063ABD0


// build: symbol ?PLRTRADE_FindTerminator@* 0x00568D80
int __fastcall PLRTRADE_FindTerminator(const char* szText, int nSize)
{
    const char* pStart = szText;
    const char* pEnd = szText + nSize;
    while (szText < pEnd && *szText)
    {
        ++szText;
    }

    if (szText >= pEnd)
    {
        return -1;
    }

    return szText - pStart;
}

// 0x00568DC0
unsigned short __fastcall PLRSAVE2_GetItemIndex(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nGUID)
{
    if (nGUID == -1)
    {
        return 0;
    }

    if (!pPlayer->pInventory)
    {
        return 0;
    }

    int nIdx = 1;
    D2UnitStrc* pNode = INVENTORY_GetFirstItem(pPlayer->pInventory);
    while (pNode)
    {
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pNode);
        pNode = INVENTORY_GetNextItem(pNode);
        if ((!pCheckedItem ? -1 : pCheckedItem->dwUnitId) == nGUID)
        {
            D2_ASSERT(nIdx < 0x7FFF, 0x185);
            return nIdx;
        }

        ++nIdx;
    }

    return 0;
}


// 0x00568E60
void __fastcall PLRSAVE2_WriteMercData(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2SaveHeaderStrc* pSaveHeader)
{
    D2UnitStrc* pHireling = PLAYERPETS_GetFirstPetByType(pGame, pPlayer, 7, 1);
    if (!pHireling)
    {
        return;
    }

    D2PetInfoStrc* pPetInfo = PLAYERPETS_GetPetInfoFromPetGUID(pPlayer, pHireling->dwUnitId);
    const int nLevel = STATLIST_UnitGetStatValue(pHireling, STAT_LEVEL, 0);

    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, pPetInfo->nHirelingId, nLevel);
    if (!pHirelingTxtRecord)
    {
        return;
    }

    D2MercSaveDataStrc* pMercData = (D2MercSaveDataStrc*)pSaveHeader->MercSaveData;
    pMercData->nSeed = pPetInfo->nSeed;
    pMercData->wName = *(unsigned short*)&pPetInfo->nName;
    pMercData->nHirelingId = pPetInfo->nHirelingId;
    pMercData->nExperience = STATLIST_UnitGetStatValue(pHireling, STAT_EXPERIENCE, 0);
    pMercData->nFlags = 0;
    pMercData->wName -= pHirelingTxtRecord->wNameFirst;

    if (SUNIT_IsDead(pHireling))
    {
        pMercData->nFlags |= 0x10000;
    }
}

// 0x00568F20
int __fastcall PLRSAVE2_WriteSaveHeader(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd)
{
    D2ClientStrc* pClient;
    unsigned char* pSection = *ppSection;
    pClient = UnitGetClient(pPlayer, ".\\PLAYER\\PlrSave2.cpp", 0x1B4);
    if (!pClient)
    {
        return 2;
    }

    const char* szName = CLIENTS_GetName(pClient);
    if (!szName)
    {
        return 2;
    }

    if (PLRTRADE_FindTerminator(szName, 16) < 1)
    {
        return 2;
    }

    if (pSection + sizeof(D2SaveHeaderStrc) > pEnd)
    {
        return 1;
    }

    D2SaveHeaderStrc saveHeader;
    memset(&saveHeader, 0, sizeof(D2SaveHeaderStrc));
    saveHeader.dwHeaderMagic = 0xAA55AA55;
    saveHeader.dwVersion = 0x60;
    SStrCopy(saveHeader.szName, szName, 0x7FFFFFFF);
    saveHeader.dwSaveFlags = CLIENTS_GetFlags(pClient);
    if (pGame->bExpansion)
    {
        saveHeader.dwSaveFlags |= 0x20;
    }

    if (pGame->dwGameType)
    {
        saveHeader.dwSaveFlags |= 0x40;
    }

    saveHeader.nClass = CLIENTS_GetClassId(pClient);
    saveHeader.nLevel = STATLIST_UnitGetStatValue(pPlayer, STAT_LEVEL, 0);
    saveHeader.dwCreateTime = CLIENTS_GetCreateTime(pClient);
    saveHeader.dwLasTime = _time32(0);
    saveHeader.dwPlayTime = CLIENTS_GetPlayTime(pClient);
    saveHeader.dwMapSeed = pGame->dwInitSeed;
    saveHeader.nStats = 16;
    saveHeader.nSkills = (unsigned char)sgptDataTables->nHighestClassSkillCount;
    if (CLIENTS_GetWeaponSwitch(UnitGetClient(pPlayer, ".\\PLAYER\\PlrSave2.cpp", 0x1DD)))
    {
        saveHeader.dwWeaponSwitch |= 1;
    }

    int nGUID;
    int nSkill;
    for (int i = 0; i < 16; ++i)
    {
        int nParam;
        CLIENTS_GetSkillHotKey(pClient, i, &nSkill, &nParam, &nGUID);
        D2_ASSERT(nSkill < 0x8000, 0x1EB);
        saveHeader.SkillKeys[i].nSkill = (unsigned short)nSkill | (nParam != 0 ? 0x8000 : 0);
        saveHeader.SkillKeys[i].nKey = PLRSAVE2_GetItemIndex(pGame, pPlayer, nGUID);
    }

    D2SkillStrc* pSkill = UNITS_GetLeftSkill(pPlayer);
    if (pSkill)
    {
        saveHeader.nLeftSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\PLAYER\\PlrSave2.cpp", 0x1F5);
        saveHeader.nLeftSkillItemIndex = PLRSAVE2_GetItemIndex(pGame, pPlayer, SKILLS_GetOwnerGUIDFromSkill(pSkill));
    }

    pSkill = UNITS_GetRightSkill(pPlayer);
    saveHeader.nRightSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\PLAYER\\PlrSave2.cpp", 0x1FC);
    saveHeader.nRightSkillItemIndex = PLRSAVE2_GetItemIndex(pGame, pPlayer, SKILLS_GetOwnerGUIDFromSkill(pSkill));

    int nSkillId;
    UNITS_GetSwitchLeftSkillData(pPlayer, &nSkillId, &nGUID);
    saveHeader.nSwitchLeftSkillId = nSkillId;
    saveHeader.nSwitchLeftSkillItemIndex = PLRSAVE2_GetItemIndex(pGame, pPlayer, nGUID);

    UNITS_GetSwitchRightSkillData(pPlayer, &nSkillId, &nGUID);
    saveHeader.nSwitchRightSkillId = nSkillId;
    saveHeader.nSwitchRightSkillItemIndex = PLRSAVE2_GetItemIndex(pGame, pPlayer, nGUID);

    saveHeader.nTown[pGame->nDifficulty] = CLIENTS_GetActNo(pClient) | 0x80;

    memset(saveHeader.nComponent, 0xFF, 16);
    memset(saveHeader.nCompColor, 0xFF, 16);
    INVENTORY_GetItemSaveGfxInfo(pPlayer, saveHeader.nComponent, saveHeader.nCompColor);
    PLRSAVE2_WriteMercData(pGame, pPlayer, &saveHeader);

    unsigned char nSaveField;
    unsigned char nUnused1;
    unsigned char nUnused2;
    CLIENTS_GetGuildEmblem(pClient, &nSaveField, &nUnused1, &nUnused2);
    saveHeader.nGuildEmblemBgColor = nSaveField;

    memcpy(pSection, &saveHeader, sizeof(D2SaveHeaderStrc));
    *ppSection = pSection + sizeof(D2SaveHeaderStrc);
    return 0;
}

// 0x00569320
int __fastcall PLRSAVE2_WriteQuestSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd)
{
    unsigned char* pSection = *ppSection;
    unsigned char* pSectionEnd = pSection + sizeof(D2QuestSaveStrc);
    if (pSectionEnd > pEnd)
    {
        return 1;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (!pPlayerData)
    {
        return 2;
    }

    D2QuestSaveStrc tQuestSave;
    memset(&tQuestSave, 0, sizeof(tQuestSave));
    tQuestSave.dwHeaderMagic = 0x216F6F57;
    tQuestSave.dwVersion = 6;
    tQuestSave.wSize = sizeof(tQuestSave);
    for (int i = 0; i < 3; ++i)
    {
        QUESTRECORD_CopyRecordToBuffer(pPlayerData->pQuestData[i], tQuestSave.aQuestData[i], 0x60, 1);
    }

    memcpy(pSection, &tQuestSave, sizeof(tQuestSave));
    *ppSection = pSectionEnd;
    return 0;
}

// 0x005693E0
int __fastcall PLRSAVE2_WriteWaypointData(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd)
{
    unsigned char* pSection = *ppSection;
    unsigned char* pNext = pSection + sizeof(D2WaypointSaveDataStrc);
    if (pNext > pEnd)
    {
        return 1;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (!pPlayerData)
    {
        return 2;
    }

    D2WaypointSaveDataStrc waypointSaveData = {};
    waypointSaveData.nHeader = PLRSAVE2_WAYPOINT_HEADER;
    waypointSaveData.unk0x02 = 1;
    waypointSaveData.nRecordSize = sizeof(D2WaypointSaveDataStrc);

    for (int i = 0; i < 3; ++i)
    {
        WAYPOINTS_ValidateAndCopyWaypointData(pPlayerData->pWaypointData[i], &waypointSaveData.waypoints[i].flags);
    }

    memcpy(pSection, &waypointSaveData, sizeof(D2WaypointSaveDataStrc));
    *ppSection = pNext;
    return 0;
}

// 0x00569490
int __fastcall PLRSAVE2_WritePlrIntroSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd)
{
    unsigned char* pSection = *ppSection;
    unsigned char* pSectionEnd = pSection + sizeof(D2PlrIntroSaveStrc);
    if (pSectionEnd > pEnd)
    {
        return 1;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (!pPlayerData)
    {
        return 2;
    }

    D2PlrIntroSaveStrc tPlrIntroSave;
    memset(&tPlrIntroSave, 0, sizeof(tPlrIntroSave));
    tPlrIntroSave.nHeader = 0x7701;
    tPlrIntroSave.nLength = sizeof(tPlrIntroSave);
    for (int i = 0; i < 3; ++i)
    {
        PLRINTRO_CopyQuestIntroFlagsToBuffer(pPlayerData->pPlayerIntro[i], tPlrIntroSave.nQuestIntroFlags[i]);
        PLRINTRO_CopyNpcIntroFlagsToBuffer(pPlayerData->pPlayerIntro[i], tPlrIntroSave.nNpcIntroFlags[i]);
    }

    memcpy(pSection, &tPlrIntroSave, sizeof(tPlrIntroSave));
    *ppSection = pSectionEnd;
    return 0;
}

inline D2ItemStatCostTxt* SKILLS_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }
    return 0;
}

// 0x00569540
int __fastcall PLRSAVE2_WritePlayerStats(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, unsigned char* pEnd)
{
    D2StatStrc aStatBuffer[512];
    D2BitBufferStrc bitBuffer;

    unsigned char* pSection = *ppSection;
    unsigned char* pData = pSection + 2;
    if (pData > pEnd)
    {
        return 1;
    }

    *(unsigned short*)pSection = 0x6667;
    BITMANIP_Initialize(&bitBuffer, pData, pEnd - pData);

    if (pPlayer->pStatListEx)
    {
        const int nStats = STATLIST_GetBaseStatsData(pPlayer->pStatListEx, aStatBuffer, 512);
        if (nStats > 0)
        {
            for (int i = 0; i < nStats; ++i)
            {
                const int nStatId = (unsigned int)aStatBuffer[i].nPackedValue >> 16;
                const unsigned short nLayer = aStatBuffer[i].nLayer;
                int nValue = aStatBuffer[i].nValue;
                D2ItemStatCostTxt* pItemStatCostTxtRecord = SKILLS_GetItemStatCostTxtRecord(nStatId);
                if (pItemStatCostTxtRecord && pItemStatCostTxtRecord->nCsvBits > 0)
                {
                    if (pItemStatCostTxtRecord->nCsvBits < 32)
                    {
                        if (pItemStatCostTxtRecord->nItemStatFlags[ITEMSTATCOSTFLAGINDEX_CSVSIGNED >> 3] & gdwBitMasks[ITEMSTATCOSTFLAGINDEX_CSVSIGNED & 7])
                        {
                            const int nMin = -1 << (pItemStatCostTxtRecord->nCsvBits - 1);
                            nValue = D2_MIN(D2_MAX(nValue, nMin), (1 << (pItemStatCostTxtRecord->nCsvBits - 1)) - 1);
                        }
                        else
                        {
                            nValue = D2_MIN(D2_MAX(nValue, 0), (1 << pItemStatCostTxtRecord->nCsvBits) - 1);
                        }
                    }

                    BITMANIP_Write(&bitBuffer, nStatId, 9);
                    if (pItemStatCostTxtRecord->nCsvParam)
                    {
                        BITMANIP_Write(&bitBuffer, nLayer, pItemStatCostTxtRecord->nCsvParam);
                    }
                    BITMANIP_Write(&bitBuffer, nValue, pItemStatCostTxtRecord->nCsvBits);
                }
            }
        }
    }

    BITMANIP_Write(&bitBuffer, 0x1FF, 9);
    *ppSection = &pData[BITMANIP_GetSize(&bitBuffer)];
    return 0;
}

// 0x005696F0
int __fastcall PLRSAVE2_WriteSkillSection(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char** ppSection, unsigned char* pEnd)
{
    unsigned char* pData = *ppSection;
    if (pData + sgptDataTables->nHighestClassSkillCount + 2 > pEnd)
    {
        return 1;
    }

    *(unsigned short*)pData = PLRSAVE2_SKILLS_MARKER;
    pData += 2;

    const int nClassId = CLIENTS_GetClassId(UnitGetClient(pUnit, ".\\PLAYER\\PlrSave2.cpp", 775));
    if (nClassId >= NUMBER_OF_PLAYERCLASSES)
    {
        return 2;
    }

    for (int i = 0; i < SKILLS_GetPlayerSkillCount(nClassId); ++i)
    {
        const int nSkillId = SKILLS_GetClassSkillId(nClassId, i);
        *pData = SKILLS_GetSkillLevel(pUnit, SKILLS_GetSkillById(pUnit, nSkillId, -1), 0);
        ++pData;
    }

    *ppSection = pData;
    return 0;
}

// noinline: PLRSAVE2_WriteCorpsesSection (0x005697F0) and PLRSAVE2_CreateSaveFile (0x00569AD0) call PLRSAVE2_WriteItemSection (0x005697B0); the image calls it out of line there.
// 0x005697B0
__declspec(noinline) int __fastcall PLRSAVE2_WriteItemSection(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char** ppCursor, const unsigned char* pEnd, int nArg5, int nArg6, int nArg7)
{
    unsigned char* pCursor = *ppCursor;
    const int nWritten = PLRSAVE_WriteUnitItems(pGame, pUnit, pCursor, pEnd - pCursor, nArg5, nArg6, nArg7);
    if (nWritten < 0)
    {
        return 3;
    }

    *ppCursor = pCursor + nWritten;
    return 0;
}

// 0x005697F0
int __fastcall PLRSAVE2_WriteCorpsesSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd, int nArg6, int bSizing)
{
    unsigned char* pSection = *ppSection;
    unsigned short bHasCorpseWithItems = 0;
    D2UnitStrc* pBestUnit = 0;
    unsigned int nBestValue = 0;

    if (!pPlayer->pInventory)
    {
        return 2;
    }

    for (D2CorpseStrc* pCorpse = INVENTORY_GetFirstCorpse(pPlayer->pInventory); pCorpse; pCorpse = INVENTORY_GetNextCorpse(pCorpse))
    {
        D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, 0, INVENTORY_GetUnitGUIDFromCorpse(pCorpse));
        D2InventoryStrc* pInventory;
        if (pUnit && (pInventory = pUnit->pInventory) != 0 && INVENTORY_GetItemCount(pInventory) > 0)
        {
            D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory);
            unsigned int nValue = 1;
            for (; pItem; pItem = INVENTORY_GetNextItem(pItem))
            {
                D2UnitStrc* pInvItem = INVENTORY_UnitIsItem(pItem);
                if (!ITEMSIsA(pInvItem, 4))
                {
                    D2BitBufferStrc* pQuestFlags = UNITS_GetPlayerData(pPlayer)->pQuestData[pGame->nDifficulty];
                    nValue += ITEMS_GetTransactionCost(pPlayer, pInvItem, 3, pQuestFlags, 0x201, 0);
                }
            }

            if (nValue >= nBestValue)
            {
                nBestValue = nValue;
                pBestUnit = pUnit;
            }
        }
    }

    D2UnitStrc* pUnit = 0;
    if (pBestUnit)
    {
        bHasCorpseWithItems = 1;
        pUnit = pBestUnit;
    }

    if (pSection + 4 > pEnd)
    {
        return 1;
    }

    *(unsigned short*)pSection = 'MJ';
    pSection += 2;

    *(unsigned short*)pSection = bHasCorpseWithItems;
    pSection += 2;

    if (pUnit && bHasCorpseWithItems)
    {
        if (pSection + 12 > pEnd)
        {
            return 1;
        }

        D2CorpseSaveStrc tCorpse;
        tCorpse.nX = CLIENTS_GetUnitX(pUnit);
        tCorpse.nY = CLIENTS_GetUnitY(pUnit);
        *(D2CorpseSaveStrc*)pSection = tCorpse;

        pSection += 12;
        if (PLRSAVE2_WriteItemSection(pGame, pUnit, &pSection, pEnd, 0, nArg6, bSizing))
        {
            return 4;
        }
    }

    *ppSection = pSection;
    return 0;
}

// 0x005699A0
int __fastcall PLRSAVE2_WriteMercSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd, int nArg6, int bSizing)
{
    unsigned char* pData = *ppSection;
    if (pGame->bExpansion)
    {
        *(unsigned short*)pData = 0x666A;
        pData += 2;

        D2UnitStrc* pPet = PLAYERPETS_GetFirstPetByType(pGame, pPlayer, 7, 1);
        if (pPet)
        {
            const int nLength = PLRSAVE_WriteUnitItems(pGame, pPet, pData, pEnd - pData, 0, nArg6, bSizing);
            if (nLength >= 0)
            {
                pData += nLength;
            }
            else
            {
                return 5;
            }
        }

        *ppSection = pData;
    }

    return 0;
}

int __fastcall D2GAME_SAVE_SerializeItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned char* pBitstream, unsigned int nSize, int bUseTradeInventory, int nUnused, int bSizing); // 0x005316D0

// 0x00569A00
int __fastcall PLRSAVE2_WriteIronGolemSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, const unsigned char* pEnd, int nUnused, int bSizing)
{
    unsigned char* pData = *ppSection;
    int bHasIronGolem = 0;
    if (!pGame->bExpansion)
    {
        return 0;
    }

    *(unsigned short*)pData = 'fk';
    pData += 2;

    D2UnitStrc* pIronGolem = PLAYERPETS_GetFirstPetByType(pGame, pPlayer, 3, 1);
    D2UnitStrc* pGolemItem = 0;
    D2UnitStrc* pFirst;
    if (pIronGolem && pIronGolem->dwClassId == 0x123 && SKILLS_GetSkillById(pPlayer, SKILL_IRONGOLEM, -1) && pIronGolem->pInventory
        && (pFirst = INVENTORY_GetFirstItem(pIronGolem->pInventory)) != 0 && (pGolemItem = INVENTORY_UnitIsItem(pFirst)) != 0)
    {
        bHasIronGolem = 1;
    }

    unsigned char* pFlag = pData;
    *pData = bHasIronGolem;
    ++pData;
    if (bHasIronGolem)
    {
        const int nLength = D2GAME_SAVE_SerializeItem(pGame, pPlayer, pGolemItem, pData, pEnd - pData, 0, nUnused, bSizing);
        if (nLength <= 0)
        {
            *pFlag = 0;
        }

        pData += nLength;
    }

    *ppSection = pData;
    return 0;
}

// 0x00569AD0
int __fastcall PLRSAVE2_CreateSaveFile(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char* pData, unsigned int* pSize, unsigned int nMaxSize, int bUseTradeInventory, int nUnused)
{
    unsigned char aBuffer[0x8000];
    const unsigned char* pEnd = &pData[nMaxSize];
    unsigned char* pSection = pData;
    unsigned char* pBuffer = aBuffer;
    *pSize = 0;

    int nResult;
    if (!pPlayer || pPlayer->dwUnitType != UNIT_PLAYER)
    {
        nResult = 2;
        goto Failed;
    }

    nResult = PLRSAVE2_WriteSaveHeader(pGame, pPlayer, &pSection, pEnd);
    if (nResult) goto Failed;
    nResult = PLRSAVE2_WriteQuestSection(pGame, pPlayer, &pSection, pEnd);
    if (nResult) goto Failed;
    nResult = PLRSAVE2_WriteWaypointData(pGame, pPlayer, &pSection, pEnd);
    if (nResult) goto Failed;
    nResult = PLRSAVE2_WritePlrIntroSection(pGame, pPlayer, &pSection, pEnd);
    if (nResult) goto Failed;
    nResult = PLRSAVE2_WritePlayerStats(pGame, pPlayer, &pSection, pEnd);
    if (nResult) goto Failed;
    nResult = PLRSAVE2_WriteSkillSection(pGame, pPlayer, &pSection, pEnd);
    if (nResult) goto Failed;

    {
        const int nRemaining = pEnd - pSection;
        nResult = PLRSAVE2_WriteItemSection(pGame, pPlayer, &pBuffer, &aBuffer[sizeof(aBuffer)], bUseTradeInventory, nUnused, 1);
        if (nResult) goto Failed;
        const int nItemsSize = pBuffer - aBuffer;
        nResult = PLRSAVE2_WriteCorpsesSection(pGame, pPlayer, &pBuffer, &aBuffer[sizeof(aBuffer)], nUnused, 1);
        if (nResult) goto Failed;
        if (pGame->bExpansion)
        {
            nResult = PLRSAVE2_WriteMercSection(pGame, pPlayer, &pBuffer, &aBuffer[sizeof(aBuffer)], nUnused, 1);
            if (nResult) goto Failed;
            nResult = PLRSAVE2_WriteIronGolemSection(pGame, pPlayer, &pBuffer, &aBuffer[sizeof(aBuffer)], nUnused, 1);
            if (nResult) goto Failed;
        }

        const int nBufferSize = pBuffer - aBuffer;
        const unsigned char* pItemsEnd = nBufferSize <= nRemaining ? pEnd : pSection + (nItemsSize - nBufferSize + nRemaining);
        nResult = PLRSAVE2_WriteItemSection(pGame, pPlayer, &pSection, pItemsEnd, bUseTradeInventory, nUnused, 0);
        if (nResult) goto Failed;
        nResult = PLRSAVE2_WriteCorpsesSection(pGame, pPlayer, &pSection, pEnd, nUnused, 0);
        if (nResult) goto Failed;
        if (pGame->bExpansion)
        {
            nResult = PLRSAVE2_WriteMercSection(pGame, pPlayer, &pSection, pEnd, nUnused, 0);
            if (nResult) goto Failed;
            nResult = PLRSAVE2_WriteIronGolemSection(pGame, pPlayer, &pSection, pEnd, nUnused, 0);
            if (nResult) goto Failed;
        }
    }

    {
        const unsigned int nSize = pSection - pData;
        *pSize = nSize;
        *(unsigned int*)(pData + 8) = nSize;
        *(unsigned int*)(pData + 0xC) = FOG_ComputeChecksum(pData, nSize);
    }
    return 0;

Failed:
    *pSize = 0;
    return nResult;
}

#define CLIENTSAVEFLAG_HARDCORE 0x4

#define CLIENTSAVEFLAG_DEAD 0x8

#define CLIENTSAVEFLAG_EXPANSION 0x20

#define CLIENTSAVEFLAG_LADDER 0x40

#define GAMEFLAG_ARENA_HARDCORE 0x800

struct D2ServerCallbackFunctions;

struct D2FileTimeStrc;

extern D2ServerCallbackFunctions* gpD2EventCallbackTable; // 0x00883D50

extern int gbD2ServerCallbackFunctionsInitialized; // 0x00883D54


extern "C" __declspec(dllimport) long __stdcall CompareFileTime(const D2FileTimeStrc* pFileTime1, const D2FileTimeStrc* pFileTime2); // 0x006CC390

// 0x00569D80
int __fastcall PLRSAVE2_CheckPlayerFlags(D2GameStrc* pGame, unsigned short nFlags, D2ClientStrc* pClient)
{
    if (nFlags & CLIENTSAVEFLAG_EXPANSION)
    {
        if (!pGame->bExpansion)
        {
            return 8;
        }
    }
    else
    {
        if (pGame->bExpansion)
        {
            return 9;
        }
    }

    if (gbD2ServerCallbackFunctionsInitialized)
    {
        D2FileTimeStrc tNow;
        gpD2EventCallbackTable->pfGetTime(&tNow);
        if ((nFlags & CLIENTSAVEFLAG_LADDER) && CompareFileTime(&pClient->nSaveCreationTimestamp, &tNow) > 0)
        {
            if (!pGame->dwGameType)
            {
                return 25;
            }
        }
        else
        {
            if (pGame->dwGameType)
            {
                return 26;
            }
        }
    }

    if (nFlags & CLIENTSAVEFLAG_HARDCORE)
    {
        if (nFlags & CLIENTSAVEFLAG_DEAD)
        {
            return 10;
        }

        if (!(ARENA_GetFlags(pGame) & GAMEFLAG_ARENA_HARDCORE))
        {
            return 11;
        }
    }
    else
    {
        if (ARENA_GetFlags(pGame) & GAMEFLAG_ARENA_HARDCORE)
        {
            return 12;
        }
    }

    const int nProgression = (nFlags >> 8) & 0x1F;
    if (pGame->nDifficulty > 1)
    {
        if (((nFlags & CLIENTSAVEFLAG_EXPANSION) && nProgression < 10) || nProgression < 8)
        {
            return 14;
        }
    }
    else if (pGame->nDifficulty > 0)
    {
        if (((nFlags & CLIENTSAVEFLAG_EXPANSION) && nProgression < 5) || nProgression < 4)
        {
            return 13;
        }
    }

    return 0;
}

// 0x00569F20
void __fastcall PLRSAVE2_InitPlayerFromClient(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2ClientStrc* pClient)
{
    CLIENTS_SetPlayerInClient(pClient, pPlayer);
    SUNIT_InitClientInPlayerData(pPlayer, pClient);
    UNITS_SetNameInPlayerData(pPlayer, CLIENTS_GetName(pClient));
    SUNIT_InitSeed(pPlayer, &pGame->pGameSeed);
    UNITS_ChangeAnimMode(pPlayer, 1);

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    pPlayerData->hTrade = 0;
    pPlayerData->dwTradeState = 0;
    pPlayerData->dwAcceptTradeTick = 0;
    *(int*)pPlayerData->dwLastTradeTick = 0;
}

static inline D2CharStatsTxt* PLRSAVE2_GetCharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }
    return 0;
}

// 0x00569F80
static int __stdcall PLRSAVE2_CreateNewbiePlayer(D2GameStrc* pGame, D2ClientStrc* pClient, D2UnitStrc** ppPlayer)
{
    CLIENTS_SetPlayerUnitAlive(pClient);
    const int nClassId = CLIENTS_GetClassId(pClient);
    D2UnitStrc* pPlayer = SUNIT_AllocUnitData(UNIT_PLAYER, nClassId, 0, 0, pGame, 0, 0, 0, 0);
    PLRSAVE2_InitPlayerFromClient(pGame, pPlayer, pClient);
    sub_005385D0_Nop(pClient, 0, 1);
    SUNITMSG_SendUnitToClient(pGame, pPlayer, pClient);

    const unsigned char nAct = CLIENTS_GetActNo(pClient);
    PLAYERSTATS_SetStatsForStartingAct(pGame, pPlayer, nAct);
    PLAYER_CreateStartItemsFromCharStatsTxt(pPlayer, pGame, nAct);

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    pPlayerData->nLeftSkillId = 0;
    pPlayerData->nRightSkillId = 0;

    if (nAct == ACT_I && pPlayer)
    {
        D2CharStatsTxt* pCharStatsTxtRecord = PLRSAVE2_GetCharStatsTxtRecord(pPlayer->dwClassId);
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

// 0x00569EC0
void __fastcall PLRSAVE2_UnpackWord(unsigned int* pRaw, int* pId, int* pFlag, int* pCount)
{
    D2PackedWordStrc* pPacked = (D2PackedWordStrc*)pRaw;
    if (pPacked->wRaw == 0xFFFF)
    {
        *pId = -1;
        *pFlag = 0;
        *pCount = -1;
        return;
    }

    *pId = pPacked->nId;
    *pFlag = pPacked->bFlag;
    *pCount = pPacked->nCount;
    if (!*pCount)
    {
        *pCount = -1;
    }
}

static inline unsigned char GetSavedAct(unsigned char nAct)
{
    nAct &= 0x7F;
    if (nAct >= 5)
        nAct = 0;
    return nAct;
}

static inline void StoreSkillPair(int* pSkill, int* pOwner, int nSkill, int nOwner)
{
    *pSkill = nSkill;
    *pOwner = nOwner;
}

// 0x0056A090
int __fastcall PLRSAVE2_ReadSaveHeader(D2GameStrc* pGame, D2ClientStrc* pClient, unsigned char** ppSection, unsigned char* pEnd, D2UnitStrc** ppPlayer)
{
    int& nSkillId = reinterpret_cast<int&>(pEnd);
    int nHand;
    int nOwner;
    D2SaveHeaderStrc* pHeader = (D2SaveHeaderStrc*)*ppSection;
    *ppPlayer = 0;
    CLIENTS_SetFlags(pClient, 0);
    unsigned char* pNext = (unsigned char*)(pHeader + 1);
    if (pNext > pEnd)
        return 4;
    unsigned int nSize = pEnd - (unsigned char*)pHeader;
    unsigned int& nChecksum = reinterpret_cast<unsigned int&>(pEnd);
    nChecksum = pHeader->dwChecksum;
    pHeader->dwChecksum = 0;
    if (FOG_ComputeChecksum((unsigned char*)pHeader, nSize) != nChecksum)
        return 6;
    if (nSize != pHeader->dwSize)
        return 5;
    if (pHeader->dwVersion <= 91 || pHeader->dwVersion > 96)
        return 7;
    pHeader->szName[15] = 0;
    const char* pName = CLIENTS_GetName(pClient);
    if (!pName)
        return 3;
    if (_stricmp(pName, pHeader->szName))
        return 7;
    int nError = PLRSAVE2_CheckPlayerFlags(pGame, (unsigned short)pHeader->dwSaveFlags, pClient);
    if (nError)
        return nError;
    if (pHeader->nClass > 7)
        return 4;
    int nClass = pHeader->nClass;
    CLIENTS_SetClassId(pClient, nClass);
    if (pHeader->dwSaveFlags & 1)
    {
        pHeader->dwSaveFlags &= ~1;
        CLIENTS_SetFlags(pClient, (unsigned short)pHeader->dwSaveFlags);
        *ppSection = pNext;
        return 2;
    }
    sub_00539230_SetWeaponSwitch(pClient, pHeader->dwWeaponSwitch & 1);
    CLIENTS_SetFlags(pClient, (unsigned short)pHeader->dwSaveFlags);
    CLIENTS_SetCreateTime(pClient, pHeader->dwCreateTime);
    unsigned char nAct = pHeader->nTown[pGame->nDifficulty];
    int& bUseSeed = nSkillId;
    bUseSeed = nAct & 0x80;
    CLIENTS_SetActNo(pClient, GetSavedAct(nAct));
    if (pGame->nGameType == 3 && !pGame->InitSeed && bUseSeed)
        pGame->dwInitSeed = pHeader->dwMapSeed;
    *ppPlayer = SUNIT_AllocUnitData(0, nClass, 0, 0, pGame, 0, 0, 0, 0);
    PLRSAVE2_InitPlayerFromClient(pGame, *ppPlayer, pClient);
    SUNITMSG_SendUnitToClient(CLIENTS_GetGame(pClient), *ppPlayer, pClient);
    for (int i = 0; i < 16; ++i)
    {
        PLRSAVE2_UnpackWord((unsigned int*)&pHeader->SkillKeys[i], &nSkillId, &nHand, &nOwner);
        CLIENTS_SetSkillHotKey(pClient, i, nSkillId, nHand, nOwner);
    }
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(*ppPlayer);
    if (!pPlayerData)
        return 4;
    PLRSAVE2_UnpackWord((unsigned int*)&pHeader->nLeftSkillId, &nSkillId, &nHand, &nOwner);
    StoreSkillPair(&pPlayerData->nLeftSkillId, &pPlayerData->nLeftSkillFlags, nSkillId, nOwner);
    PLRSAVE2_UnpackWord((unsigned int*)&pHeader->nRightSkillId, &nSkillId, &nHand, &nOwner);
    StoreSkillPair(&pPlayerData->nRightSkillId, &pPlayerData->nRightSkillFlags, nSkillId, nOwner);
    PLRSAVE2_UnpackWord((unsigned int*)&pHeader->nSwitchLeftSkillId, &nSkillId, &nHand, &nOwner);
    StoreSkillPair(&pPlayerData->nSwitchLeftSkillId, &pPlayerData->nSwitchLeftSkillFlags, nSkillId, nOwner);
    PLRSAVE2_UnpackWord((unsigned int*)&pHeader->nSwitchRightSkillId, &nSkillId, &nHand, &nOwner);
    StoreSkillPair(&pPlayerData->nSwitchRightSkillId, &pPlayerData->nSwitchRightSkillFlags, nSkillId, nOwner);
    CLIENTS_SetGuildEmblem(pClient, pHeader->nGuildEmblemBgColor, 0, 0);
    *ppSection = pNext;
    return 0;
}

// 0x0056A370
int __fastcall PLRSAVE2_ReadQuestSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion)
{
    unsigned char* pSection = *ppSection;
    unsigned char* pSectionEnd = pSection + 298;
    if (pSectionEnd > pEnd)
    {
        return 15;
    }

    const D2SaveHeaderStrc* pQuestHeader = (const D2SaveHeaderStrc*)pSection;
    if (pQuestHeader->dwHeaderMagic != 0x216F6F57)
    {
        return 15;
    }

    if (pQuestHeader->dwVersion != 6)
    {
        return 15;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    for (int i = 0; i < 3; ++i)
    {
        QUESTRECORD_CopyBufferToRecord(pPlayerData->pQuestData[i], &pSection[10 + 96 * i], 96, 1);
    }

    *ppSection = pSectionEnd;
    return 0;
}

// 0x0056A3E0
int __fastcall PLRSAVE2_ReadWaypointData(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion)
{
    unsigned char* pSection = *ppSection;
    unsigned char* pNext = pSection + sizeof(D2WaypointSaveDataStrc);
    if (pNext > pEnd)
    {
        return PLRSAVE2ERROR_BAD_WAYPOINT;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);
    D2WaypointSaveDataStrc* pWaypointSaveData = (D2WaypointSaveDataStrc*)pSection;
    if (pWaypointSaveData->nHeader != PLRSAVE2_WAYPOINT_HEADER)
    {
        return PLRSAVE2ERROR_BAD_WAYPOINT;
    }

    for (int i = 0; i < 3; ++i)
    {
        D2WaypointDataStrc* pSavedData = &pWaypointSaveData->waypoints[i].flags;
        if (pSavedData->nFlag0 != 0x102 && pSavedData->nFlag0 != 0x101 && pSavedData->nFlag0)
        {
            return PLRSAVE2ERROR_BAD_WAYPOINT;
        }

        WAYPOINTS_CopyAndValidateWaypointData(pPlayerData->pWaypointData[i], pSavedData);
    }

    *ppSection = pNext;
    return 0;
}

// 0x0056A470
int __fastcall PLRSAVE2_ReadPlrIntroSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion)
{
    D2PlrIntroSaveStrc* pPlrIntro = (D2PlrIntroSaveStrc*)*ppSection;
    unsigned char* pSectionEnd = *ppSection + sizeof(D2PlrIntroSaveStrc);
    if (pSectionEnd > pEnd)
    {
        return PLRSAVE2ERROR_BAD_PLAYERINTRO;
    }

    if (pPlrIntro->nHeader != 0x7701)
    {
        return PLRSAVE2ERROR_BAD_PLAYERINTRO;
    }

    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    for (int i = 0; i < 3; ++i)
    {
        PLRINTRO_CopyBufferToQuestIntroFlags(pPlayerData->pPlayerIntro[i], pPlrIntro->nQuestIntroFlags[i]);
        PLRINTRO_CopyBufferToNpcIntroFlags(pPlayerData->pPlayerIntro[i], pPlrIntro->nNpcIntroFlags[i]);
    }

    *ppSection = pSectionEnd;
    return 0;
}

// 0x0056A4F0
int __fastcall PLRSAVE2_ReadStatsEx(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion)
{
    unsigned char* pData = *ppSection;
    if (&pData[2] > pEnd)
    {
        return PLRSAVE2ERROR_BAD_STATS;
    }

    const unsigned short nHeader = *(unsigned short*)pData;
    pData += 2;
    if (nHeader != 0x6667)
    {
        return PLRSAVE2ERROR_BAD_STATS;
    }

    D2BitBufferStrc bitBuffer;
    BITMANIP_Initialize(&bitBuffer, pData, pEnd - pData);

    for (int nStatId = sub_00411020_ReadBits(&bitBuffer, 9); nStatId < 511; nStatId = sub_00411020_ReadBits(&bitBuffer, 9))
    {
        D2ItemStatCostTxt* pItemStatCostTxtRecord = SKILLS_GetItemStatCostTxtRecord(nStatId);
        if (!pItemStatCostTxtRecord || pItemStatCostTxtRecord->nCsvBits <= 0)
        {
            return PLRSAVE2ERROR_BAD_STATS;
        }

        int nLayer = 0;
        if (pItemStatCostTxtRecord->nCsvParam > 0)
        {
            nLayer = (unsigned short)BITMANIP_ReadSigned(&bitBuffer, pItemStatCostTxtRecord->nCsvParam);
        }

        int nValue = 0;
        if (pItemStatCostTxtRecord->nCsvBits < 32 && pItemStatCostTxtRecord->nItemStatFlags[ITEMSTATCOSTFLAGINDEX_CSVSIGNED >> 3] & gdwBitMasks[ITEMSTATCOSTFLAGINDEX_CSVSIGNED & 7])
        {
            nValue = BITMANIP_ReadSigned(&bitBuffer, pItemStatCostTxtRecord->nCsvBits);
        }
        else
        {
            nValue = sub_00411020_ReadBits(&bitBuffer, pItemStatCostTxtRecord->nCsvBits);
        }

        STATLIST_SetUnitStat(pUnit, nStatId, nValue, nLayer);
    }

    *ppSection = &pData[BITMANIP_GetSize(&bitBuffer)];
    return 0;
}

// 0x0056B180
int __fastcall PlayerCreate(D2GameStrc* pGame, D2ClientStrc* pClient, unsigned char* pSaveFile, unsigned int nSize, D2UnitStrc** ppPlayer, D2ActiveRoomStrc* pRoomArg, int nXArg, int nYArg)
{
    D2SaveHeaderStrc* pSaveHeader = (D2SaveHeaderStrc*)pSaveFile;
    unsigned char* pSection = pSaveFile;
    unsigned char* pSaveFileEnd = &pSaveFile[nSize];
    D2UnitStrc* pPlayer = 0;
    int nHitpoints;
    int nMana;
    int nErrorCode;
    int bLoaded = 0;

    *ppPlayer = 0;

    if (!pClient)
    {
        nErrorCode = PLRSAVE2ERROR_NO_CLIENT;
    }
    else
    {
        nErrorCode = PLRSAVE2_ReadSaveHeader(pGame, pClient, &pSection, pSaveFileEnd, ppPlayer);
        if (nErrorCode)
        {
            if (nErrorCode == PLRSAVE2ERROR_NEWBIE_SAVE && pSection == pSaveFileEnd)
            {
                return PLRSAVE2_CreateNewbiePlayer(pGame, pClient, ppPlayer);
            }
        }
        else
        {
            pPlayer = *ppPlayer;
            const unsigned int nVersion = pSaveHeader->dwVersion;
            nErrorCode = PLRSAVE2_ReadQuestSection(pGame, pPlayer, &pSection, pSaveFileEnd, nVersion);
            if (!nErrorCode)
            {
                nErrorCode = PLRSAVE2_ReadWaypointData(pGame, pPlayer, &pSection, pSaveFileEnd, nVersion);
                if (!nErrorCode)
                {
                    nErrorCode = PLRSAVE2_ReadPlrIntroSection(pGame, pPlayer, &pSection, pSaveFileEnd, nVersion);
                    if (!nErrorCode)
                    {
                        nErrorCode = PLRSAVE2_ReadStats(pGame, pPlayer, &pSection, pSaveFileEnd, nVersion, pSaveHeader->nStats);
                        if (!nErrorCode)
                        {
                            nHitpoints = STATLIST_UnitGetStatValue(pPlayer, STAT_HITPOINTS, 0);
                            nMana = STATLIST_UnitGetStatValue(pPlayer, STAT_MANA, 0);

                            nErrorCode = PLRSAVE2_ReadSkills(pGame, pPlayer, &pSection, pSaveFileEnd, nVersion, pSaveHeader->nSkills);
                            if (!nErrorCode)
                            {
                                int nItemSize;
                                nErrorCode = PLRSAVE2_ReadItemSection(pGame, pPlayer, &pSection, pSaveFileEnd, nVersion, 0, &nItemSize);
                                if (!nErrorCode)
                                {
                                    nErrorCode = PLRSAVE2_ReadCorpses(pGame, pPlayer, &pSection, pSaveFileEnd, nVersion, &nItemSize);
                                    if (!nErrorCode)
                                    {
                                        D2UnitStrc* pMerc = PLRSAVE2_ReadMercData(pGame, pPlayer, (D2MercSaveDataStrc*)pSaveHeader->MercSaveData, nVersion);
                                        nErrorCode = PLRSAVE2_ReadPetSection(pGame, pPlayer, pMerc, &pSection, pSaveFileEnd, nVersion, &nItemSize);
                                        if (!nErrorCode)
                                        {
                                            if (pMerc)
                                            {
                                                MONSTERAI_SendMercStats(pGame, pPlayer, 1);
                                            }

                                            nErrorCode = PLRSAVE2_ReadIronGolemSection(pGame, pPlayer, &pSection, pSaveFileEnd, nVersion);
                                            if (!nErrorCode)
                                            {
                                                bLoaded = 1;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    if (!bLoaded)
    {
        if (nErrorCode < 0 || nErrorCode >= PLRSAVE2ERROR_COUNT)
        {
            nErrorCode = PLRSAVE2ERROR_UNKNOWN;
        }

        if (pPlayer)
        {
            if (UNITS_GetRoom(pPlayer))
            {
                const int nUnitGUID = pPlayer->dwUnitId;
                const int nUnitType = pPlayer->dwUnitType;
                DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pPlayer), nUnitType, nUnitGUID);
            }

            SUNIT_RemoveUnit(pGame, pPlayer);
        }

        CLIENTS_SetPlayerInClient(pClient, 0);
        return gnPlrSave2ErrorRemap[nErrorCode];
    }

    PLRSAVE2_InitializeStats(pGame, pPlayer, nHitpoints, nMana);
    return 0;
}

// 0x0056A620
int __fastcall PLRSAVE2_ReadStats(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion, int nStats)
{
    if (nVersion > 0x5E)
    {
        return PLRSAVE2_ReadStatsEx(pGame, pUnit, ppSection, pEnd, nVersion);
    }

    const int nHeaderSectionLength = (nStats + 7) / 8;
    unsigned char* pData = *ppSection;
    if (&pData[nHeaderSectionLength + 2] > pEnd)
    {
        return PLRSAVE2ERROR_BAD_STATS;
    }

    const unsigned short nHeader = *(unsigned short*)pData;
    pData += 2;
    if (nHeader != 0x6667)
    {
        return PLRSAVE2ERROR_BAD_STATS;
    }

    unsigned char* pHeaderData = pData;
    pData += nHeaderSectionLength;
    if (&pData[4 * sub_00411170_SumByteTable(pHeaderData, nHeaderSectionLength)] > pEnd)
    {
        return PLRSAVE2ERROR_BAD_STATS;
    }

    int nCounter = 0;
    for (int i = 0; i < nStats; ++i)
    {
        if (pHeaderData[i >> 3] & gdwBitMasks[i & 7])
        {
            const int nValue = *(int*)&pData[4 * nCounter];
            ++nCounter;
            STATLIST_SetUnitStat(pUnit, i, nValue, 0);
        }
        else
        {
            STATLIST_SetUnitStat(pUnit, i, 0, 0);
        }
    }

    *ppSection = &pData[4 * nCounter];
    return 0;
}

// 0x0056A6F0
void __fastcall PLRSAVE2_SetSkillIfLevelSet(Game* unused,D2UnitStrc* unit,int skill,D2SaveSkillLevelStrc level)
{
    if(level.value) D2GAME_SetSkills(unit,skill,level.value,REMOVE_SKILL);
}

// 0x0056A710
int __fastcall PLRSAVE2_ReadSkills(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion, int nSkills)
{
    unsigned char* pData = *ppSection;
    if (&pData[2] > pEnd)
    {
        return PLRSAVE2ERROR_BAD_SKILLS;
    }

    const unsigned short nHeader = *(unsigned short*)pData;
    pData += 2;
    if (nHeader != 0x6669)
    {
        return PLRSAVE2ERROR_BAD_SKILLS;
    }

    D2ClientStrc* pClient = UnitGetClient(pPlayer, ".\\PLAYER\\PlrSave2.cpp", 1773);
    if (!pClient)
    {
        return PLRSAVE2ERROR_BAD_SKILLS;
    }

    const int nClassId = CLIENTS_GetClassId(pClient);
    for (int i = 0; i < nSkills; ++i)
    {
        const int nSkillId = SKILLS_GetClassSkillId(nClassId, i);
        if (i > SKILLS_GetPlayerSkillCount(nClassId))
        {
            break;
        }

        if (pData[i])
        {
            D2GAME_SetSkills(pPlayer, nSkillId, pData[i], 1);
        }
    }

    SCMD_SendSkillList(pClient, pPlayer);
    SKILLS_RefreshPassivesAndPetLimits(pPlayer);

    *ppSection = &pData[nSkills];
    return 0;
}

inline int UNIT_HasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }

    return 0;
}

inline int UNIT_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & nFlag) != 0;
    }

    return 0;
}

// 0x0056A7E0
int __fastcall PLRSAVE2_ReadItemSection(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char** ppSection, unsigned char* pEnd, int nVersion, int nUnused, int* pError)
{
    unsigned char* pSection = *ppSection;
    int nSize = 0;
    const int nError = PLRSAVE_ReadItemSection(pGame, pUnit, pSection, nVersion, pEnd - pSection, 0, &nSize);
    if (nError)
    {
        if (pError)
        {
            *pError = nError;
        }
        return 0x14;
    }

    *ppSection = pSection + nSize;
    return 0;
}

// 0x0056A830
int __fastcall PLRSAVE2_ReadCorpses(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, unsigned char* pEnd, unsigned int nVersion, int* pDetailError)
{
    struct
    {
        int nCount;
        int nErrorCode;
        int i;
        D2ClientStrc* pClient;
        unsigned char* pData;
    } t;
    unsigned char* pDataStart = *ppSection;
    t.pClient = UnitGetClient(pPlayer, ".\\PLAYER\\PlrSave2.cpp", 0x733);

    if (!t.pClient)
    {
        if (pDetailError)
        {
            *pDetailError = 101;
        }

        return 21;
    }

    if (pDataStart + 4 > pEnd)
    {
        if (pDetailError)
        {
            *pDetailError = 102;
        }

        return 21;
    }

    if (*(unsigned short*)pDataStart != 'MJ')
    {
        if (pDetailError)
        {
            *pDetailError = 103;
        }

        return 21;
    }

    pDataStart += 2;
    const unsigned short nCount = *(unsigned short*)pDataStart;
    pDataStart += 2;
    if (nCount > 1)
    {
        if (pDetailError)
        {
            *pDetailError = 104;
        }

        return 21;
    }

    for (t.i = 0, t.nCount = nCount; t.i < t.nCount; ++t.i)
    {
        if (pDataStart + 12 > pEnd)
        {
            if (pDetailError)
            {
                *pDetailError = 105;
            }

            return 21;
        }

        t.pData = pDataStart + 12;
// build: symbol ?GAME_GetUnitClassId@* 0x00451F60
        D2UnitStrc* pPlayerBody = SUNIT_AllocUnitData(0, GAME_GetUnitClassId(pPlayer), 0, 0, pGame, 0, 1, 17, 0);
        if (!pPlayerBody)
        {
            if (pDetailError)
            {
                *pDetailError = 106;
            }

            return 21;
        }

        D2ClientStrc* const pBodyClient = t.pClient;
        pPlayerBody->dwFlags &= 0xFFFFFFFBu;

        SUNIT_InitClientInPlayerData(pPlayerBody, pBodyClient);
        UNITS_SetNameInPlayerData(pPlayerBody, CLIENTS_GetName(t.pClient));
        SUNIT_InitSeed(pPlayerBody, &pGame->pGameSeed);
        STATES_ToggleState(pPlayerBody, 7, 1);

        pPlayerBody->dwFlags &= 0xFFFFFFEFu;

        INVENTORY_SetOwnerId(pPlayerBody->pInventory, GAME_GetUnitGUID(pPlayer));

        t.nErrorCode = 0;
        if (PLRSAVE2_ReadItemSection(pGame, pPlayerBody, &t.pData, pEnd, nVersion, 1, &t.nErrorCode))
        {
            if (pDetailError)
            {
                *pDetailError = t.nErrorCode;
            }

            return 21;
        }

        INVENTORY_CreateCorpseForPlayer(pPlayer->pInventory, !pPlayerBody ? -1 : pPlayerBody->dwUnitId, 0, 1);
        const int nPlayerBodyId = pPlayerBody->dwUnitId;
        D2GAME_SendPacket0x8E_CorpseAssign_ToAllPlayers(pGame, GAME_GetUnitGUID(pPlayer), nPlayerBodyId, 1);
        pDataStart = t.pData;
    }

    *ppSection = pDataStart;
    return 0;
}

// 0x0056AA50
D2UnitStrc* __fastcall PLRSAVE2_ReadMercData(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2MercSaveDataStrc* pData, unsigned int dwVersion)
{
    if (!pData->nExperience && !pData->nSeed && !pData->wName)
    {
        return 0;
    }

    D2MercSaveDataStrc hirelingData;
    void* const tArg1 = &hirelingData;
    memcpy(tArg1, pData, sizeof(hirelingData));

    D2HirelingTxt* pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, hirelingData.nHirelingId, 1);
    if (!pHirelingTxtRecord)
    {
        return 0;
    }

    hirelingData.wName += pHirelingTxtRecord->wNameFirst;
    if (hirelingData.wName > pHirelingTxtRecord->wNameLast)
    {
        hirelingData.wName = pHirelingTxtRecord->wNameFirst;
    }

    const unsigned int bDead = hirelingData.nFlags & 0x10000;
    D2UnitStrc* pMerc = D2GAME_MERCS_Create(pGame, pPlayer, hirelingData.wName, hirelingData.nSeed, hirelingData.nHirelingId, pHirelingTxtRecord->dwClass, bDead);
    if (!pMerc)
    {
        return 0;
    }

    D2PetInfoStrc petInfo;
    petInfo.nSeed = hirelingData.nSeed;
    petInfo.nName = hirelingData.wName;
    petInfo.nHirelingId = hirelingData.nHirelingId;
    PLAYERPETS_UpdatePetInfo(pPlayer, 7, !pMerc ? -1 : pMerc->dwUnitId, &petInfo);

    STATLIST_UnitGetStatValue(pPlayer, STAT_LEVEL, 0);
    const int nMaxLevel = DATATBLS_GetMaxLevel(0);
    int nLevel = 1;

    if ((unsigned int)STATLIST_UnitGetStatValue(pMerc, STAT_EXPERIENCE, 0) < hirelingData.nExperience)
    {
        STATLIST_SetUnitStat(pMerc, STAT_EXPERIENCE, hirelingData.nExperience, 0);
    }

    D2GAME_MERCS_SendStat(pMerc, 13, hirelingData.nExperience);

    pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, hirelingData.nHirelingId, 1);
    while (pHirelingTxtRecord)
    {
        const int nNextLevel = nLevel + 1;
        if (nNextLevel > nMaxLevel || hirelingData.nExperience < MONSTERS_GetHirelingExpForNextLevel(nNextLevel, pHirelingTxtRecord->dwExpPerLvl))
        {
            MONSTERAI_UpdateMercStatsAndSkills(pGame, pPlayer, pMerc, nLevel);

            if (bDead)
            {
                PLAYERPETS_HandlePetDeath(pGame, pPlayer, pMerc);
                pMerc->dwFlags |= 0x10000;
                SUNIT_SetCombatMode(pGame, pMerc, 12);
                MONSTER_DeleteEvents(pGame, pMerc);
            }

            if (!pMerc->pInventory)
            {
                INVENTORY_AllocInventory(0, pMerc);
            }

            return pMerc;
        }

        nLevel = nNextLevel;
        pHirelingTxtRecord = DATATBLS_GetHirelingTxtRecordFromIdAndLevel(pGame->bExpansion, hirelingData.nHirelingId, nLevel);
    }

    SUNIT_RemoveUnit(pGame, pMerc);
    return 0;
}

// 0x0056AC10
int __fastcall PLRSAVE2_ReadPetSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pMerc, unsigned char** ppSection, unsigned char* pEnd, unsigned int dwVersion, int* pDetailError)
{
    unsigned char* pSection = *ppSection;
    if (!pGame->bExpansion)
    {
        return 0;
    }

    if (pSection + 2 > pEnd)
    {
        return 0;
    }

    if (*(unsigned short*)pSection != 0x666A)
    {
        if (pDetailError)
        {
            *pDetailError = 101;
        }

        return PLRSAVE2ERROR_BAD_PET;
    }

    unsigned char* pData = pSection + 2;
    if (pMerc)
    {
        int nError = 0;
        if (PLRSAVE2_ReadItemSection(pGame, pMerc, &pData, pEnd, dwVersion, 0, &nError))
        {
            if (pDetailError)
            {
                *pDetailError = nError;
            }

            return PLRSAVE2ERROR_BAD_PET;
        }

        D2GAME_ITEMS_UpdateInventoryItems(pGame, pMerc, 0, 0);
        sub_0055F4F0_Nop(pGame, pMerc, 0);
        if (!SUNIT_IsDead(pMerc))
        {
            STATLIST_SetUnitStat(pMerc, STAT_HITPOINTS, STATLIST_GetMaxLifeFromUnit(pMerc), 0);
        }
    }

    *ppSection = pData;
    return 0;
}

// 0x0056ACE0
int __fastcall PLRSAVE2_CreateItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc** ppItem, unsigned char** ppSection, unsigned char* pEnd, unsigned int dwVersion)
{
    unsigned char* pSection = *ppSection;
    *ppItem = 0;

    unsigned int nSize = pEnd - pSection;

    D2ItemSaveStrc tItemSave;
    ITEMS_GetCompactItemDataFromBitstream(pSection, nSize, 1, &tItemSave, dwVersion);
    if (tItemSave.nClassId == -1)
    {
        return 0;
    }

    D2UnitStrc* pItem = ITEMS_CreateItemFromBitstream(pGame, 0, pSection, nSize, 1, &tItemSave, &nSize, dwVersion);
    if (!pItem)
    {
        return 0;
    }

    pSection += nSize;
    sub_00564CB0_Nop(pItem);

    const int nSockets = tItemSave.nItemFileIndex;
    D2UnitStrc* pParentItem = pItem;
    for (int i = 0; i < nSockets; ++i)
    {
        nSize = pEnd - pSection;
        ITEMS_GetCompactItemDataFromBitstream(pSection, nSize, 1, &tItemSave, dwVersion);

        pItem = ITEMS_CreateItemFromBitstream(pGame, 0, pSection, nSize, 1, &tItemSave, &nSize, dwVersion);
        if (!pItem)
        {
            SUNIT_RemoveUnit(pGame, pParentItem);
            return 0;
        }

        pSection += nSize;
        sub_00564CB0_Nop(pItem);
        UNITS_ChangeAnimMode(pItem, 4);

        const int nSocketableGUID = pItem->dwUnitId;
        int bPlaced;
        if (!D2GAME_ITEMSOCKET_PlaceItem(pGame, pPlayer, nSocketableGUID, GAME_GetUnitGUID(pParentItem), &bPlaced, 0, 1, 0, 0))
        {
            SUNIT_RemoveUnit(pGame, pParentItem);
            return 0;
        }
    }

    if (ITEMS_GetItemFlags(pParentItem) & 0x4000000 && !ITEMS_GetRunesTxtRecordFromItem(pParentItem))
    {
        ITEMMODE_DetachItemFromOwner(pGame, pPlayer, pParentItem);
        pParentItem = 0;
    }

    *ppSection = pSection;
    *ppItem = pParentItem;
    return 1;
}

// 0x0056AE50
int __fastcall PLRSAVE2_ReadIronGolemSection(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char** ppSection, unsigned char* pEnd, unsigned int dwVersion)
{
    unsigned char* pSection = *ppSection;
    if (!pGame->bExpansion)
    {
        return 0;
    }

    unsigned char* pData = pSection + 2;
    if (pData > pEnd)
    {
        return 0;
    }

    if (*(unsigned short*)pSection != 'fk')
    {
        return PLRSAVE2ERROR_BAD_IRONGOLEM;
    }

    const unsigned char bHasGolem = *pData++;
    unsigned char* pSectionEnd = pData;
    unsigned char* pNext = pData;
    if (bHasGolem)
    {
        D2UnitStrc* pItem = 0;
        D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pPlayer, SKILL_IRONGOLEM);
        if (!pSkill)
        {
            return PLRSAVE2ERROR_BAD_IRONGOLEM;
        }

        UNITS_SetUsedSkill(pPlayer, pSkill);

        if (!PLRSAVE2_CreateItem(pGame, pPlayer, &pItem, &pSectionEnd, pEnd, dwVersion))
        {
            return PLRSAVE2ERROR_BAD_IRONGOLEM;
        }

        D2UnitStrc* pGolemItem = pItem;
        UNITS_ChangeAnimMode(pGolemItem, IMODE_ONGROUND);
        CLIENTS_SetIronGolemItemGUID(UnitGetClient(pPlayer, ".\\PLAYER\\PlrSave2.cpp", 2185), !pGolemItem ? -1 : pGolemItem->dwUnitId);
        pNext = pSectionEnd;
    }

    *ppSection = pNext;
    return 0;
}

// 0x0056AF20
int __fastcall PLRSAVE2_GetItemGUIDFromIndex(D2GameStrc* pGame, D2UnitStrc* pUnit, int nIndex)
{
    if (!pUnit->pInventory)
    {
        return -1;
    }

    int nCounter = 1;
    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pUnit->pInventory);
    while (pItem)
    {
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pItem);
        pItem = INVENTORY_GetNextItem(pItem);
        if (nCounter == nIndex)
        {
            if (pCheckedItem)
            {
                return pCheckedItem->dwUnitId;
            }

            break;
        }

        ++nCounter;
    }

    return -1;
}

inline void UNITS_SetInventoryGold(D2UnitStrc* pUnit, unsigned int nGold)
{
    if (pUnit)
    {
        if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            const unsigned int nLimit = UNITS_GetInventoryGoldLimit(pUnit);
            if (nGold > nLimit)
            {
                nGold = nLimit;
            }
        }

        STATLIST_SetUnitStat(pUnit, STAT_GOLD, nGold, 0);
    }
}

inline void UNITS_SetStashGold(D2UnitStrc* pUnit, unsigned int nGold)
{
    if (pUnit)
    {
        if (pUnit->dwUnitType == UNIT_PLAYER)
        {
            const unsigned int nLimit = UNITS_GetStashGoldLimit(pUnit);
            if (nGold > nLimit)
            {
                nGold = nLimit;
            }
        }

        STATLIST_SetUnitStat(pUnit, STAT_GOLDBANK, nGold, 0);
    }
}

// 0x0056AF80
void __fastcall PLRSAVE2_InitializeStats(D2GameStrc* pGame, D2UnitStrc* pUnit, int nHitpoints, int nMana)
{
    D2ClientStrc* pClient = UnitGetClient(pUnit, ".\\PLAYER\\PlrSave2.cpp", 2222);
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pUnit);

    const int nGold = STATLIST_UnitGetStatValue(pUnit, STAT_GOLD, 0);
    if (nGold < 0 || nGold > UNITS_GetInventoryGoldLimit(pUnit))
    {
        UNITS_SetInventoryGold(pUnit, 0);
    }

    const int nGoldBank = STATLIST_UnitGetStatValue(pUnit, STAT_GOLDBANK, 0);
    if (nGoldBank < 0 || nGoldBank > UNITS_GetStashGoldLimit(pUnit))
    {
        UNITS_SetStashGold(pUnit, 0);
    }

    const int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pUnit);
    STATLIST_SetUnitStat(pUnit, STAT_STAMINA, nMaxStamina, 0);

    for (int i = 0; i < 16; ++i)
    {
        int nSkillId;
        int nHand;
        int nItemIndex;
        CLIENTS_GetSkillHotKey(pClient, i, &nSkillId, &nHand, &nItemIndex);
        if (nItemIndex)
        {
            nItemIndex = PLRSAVE2_GetItemGUIDFromIndex(pGame, pUnit, nItemIndex);
            CLIENTS_SetSkillHotKey(pClient, i, nSkillId, nHand, nItemIndex);
        }
    }

    if (pPlayerData->nLeftSkillFlags)
    {
        pPlayerData->nLeftSkillFlags = PLRSAVE2_GetItemGUIDFromIndex(pGame, pUnit, pPlayerData->nLeftSkillFlags);
    }

    if (pPlayerData->nRightSkillFlags)
    {
        pPlayerData->nRightSkillFlags = PLRSAVE2_GetItemGUIDFromIndex(pGame, pUnit, pPlayerData->nRightSkillFlags);
    }

    if (pPlayerData->nSwitchLeftSkillFlags)
    {
        pPlayerData->nSwitchLeftSkillFlags = PLRSAVE2_GetItemGUIDFromIndex(pGame, pUnit, pPlayerData->nSwitchLeftSkillFlags);
    }

    if (pPlayerData->nSwitchRightSkillFlags)
    {
        pPlayerData->nSwitchRightSkillFlags = PLRSAVE2_GetItemGUIDFromIndex(pGame, pUnit, pPlayerData->nSwitchRightSkillFlags);
    }

    if (pPlayerData->nLeftSkillId)
    {
        D2GAME_AssignSkill(pUnit, 1, pPlayerData->nLeftSkillId, pPlayerData->nLeftSkillFlags);
    }

    if (pPlayerData->nRightSkillId)
    {
        D2GAME_AssignSkill(pUnit, 0, pPlayerData->nRightSkillId, pPlayerData->nRightSkillFlags);
    }

    STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, nHitpoints, 0);
    STATLIST_SetUnitStat(pUnit, STAT_MANA, nMana, 0);
    STATLIST_SetUnitStat(pUnit, STAT_ATTACKRATE, 100, 0);
    STATLIST_SetUnitStat(pUnit, STAT_VELOCITYPERCENT, 100, 0);
    STATLIST_SetUnitStat(pUnit, STAT_OTHER_ANIMRATE, 100, 0);
    const int nNextExp = DATATBLS_GetLevelThreshold(!pUnit ? -1 : pUnit->dwClassId, STATLIST_GetUnitBaseStat(pUnit, STAT_LEVEL, 0));
    STATLIST_SetUnitStat(pUnit, STAT_NEXTEXP, nNextExp, 0);

    if (CLIENTS_GetWeaponSwitch(pClient))
    {
        D2GAME_PACKETS_SendPacket0x97(pClient);
    }
}

