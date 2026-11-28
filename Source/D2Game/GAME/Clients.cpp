#include "D2SkillIds.h"
#include "D2GameObjs.h"
#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2GameTypes.h"
#include "D2Drlg.h"
#include "D2GameServer.h"
#include "D2GameStrc.h"
#include "D2GameClient.h"
#include "D2GameRecords.h"
#include "D2ItemsWorld.h"
#include "D2PlayerModes.h"
#include "D2DataTbls.h"
#include "D2Constants.h"
#include "D2EventTimer.h"
#include "D2StateIds.h"
#include "D2MonsterIds.h"
#include "D2HotkeySkill.h"
#include "D2ItemTypes.h"
#include "D2LevelIds.h"
#include "D2QuestData.h"
#include "D2Primitives.h"
#include "D2DrlgRooms.h"
#include "D2LevelTxt.h"
#include "D2ItemModes.h"
#include "D2ObjModes.h"
#include "D2Unicode.h"
#include "D2StormLink.h"
#include "D2InactiveUnits.h"
#include "D2Packets.h"
#include "D2SaveHeader.h"
#include "D2LanguageNames.h"
#include "FogApi.h"
#include "StormApi.h"
#include "D2CommonApi.h"
#include "D2LangApi.h"
#include "FogApi.h"
// build: symbol _gaszLanguageNames 0x007312E0

#pragma intrinsic(strcpy)

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define CLIENTFLAGEX_PLAYER_UNIT_ALIVE 0x01
#define UNIT_PLAYER 0
#define UNIT_OBJECT 2
#define UNIT_ITEM 4
#define UNIT_TILE 5
#define UNIT_INVALID 6
#define CLIENTFLAGEX_ARENA_RELATED 0x04
#define PREVIEW_VERSION 0x0E
#define PREVIEW_COPY_SIZE 0x0B
#define PREVIEW_MAX_LEVEL_INDEX 98

#define CLIENTSAVEFLAG_HARDCORE 0x04
#define CLIENTSAVEFLAG_DEAD 0x08
#define CLIENTSAVEFLAG_INVALID_1 0x01
#define CLIENTSAVEFLAG_INVALID_2 0x02
#define CLIENTSAVEFLAG_INVALID_10 0x10
#define PREVIEW_STRING_LENGTH 0x21

struct D2CorpseStrc;
struct D2SkillListStrc;
struct D2ServerCallbackFunctions;
struct D2DrlgCoordsStrc;
struct D2ObjectControlStrc;
struct D2StaticPathStrc;
struct D2ClientUnitUpdateStrc;
struct D2ClientUnitUpdateSortStrc;
struct D2PacketDataStrc;
struct D2CharacterPreviewRecordStrc;
struct D2CriticalSectionStrc;
struct D2UnitStrc;
struct D2ClientStrc;
struct D2GameStrc;
struct D2ActiveRoomStrc;
struct D2BitBufferStrc;
struct D2ObjectsTxt;
struct D2MapAIStrc;
struct D2QuestDataStrc;
struct D2CoordStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09


extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214
extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218
extern D2ServerCallbackFunctions* gpD2EventCallbackTable; // 0x00883D50
// The same clients, hashed by name.
D2ClientStrc* gpClientListByName[256]; // 0x00883EA8
// The game server's clients, hashed by client id into 256 chains.
D2ClientStrc* gpClientList[256]; // 0x008842A8
extern D2CriticalSectionStrc gClientListLock; // 0x008846A8
int gbClientListInitialized; // 0x008846D8
extern D2CriticalSectionStrc gSrvClientListByNameLock; // 0x008846C0
D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0


typedef D2UnitStrc* (__fastcall* OBJECTPOPULATEFN)(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, unsigned char nDensity, unsigned int nObjectId, unsigned short nProbability);

extern OBJECTPOPULATEFN sgPopulateTable[10]; // 0x00731D00
void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790
int __stdcall sub_0063E510_InventoryGridQuery(D2UnitStrc* pUnit, unsigned char* pFirst, unsigned char* pSecond); // 0x0063E510
#include "D2GameFuncs.h"
#include "FogApi2.h"
#include "D2CommonApi2.h"

struct D2ClientUnitUpdateSortStrc
{
    D2UnitStrc* pUnit;
    unsigned int nDistance;
    int nNextIndex;
};

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20


D2ActiveRoomStrc* __fastcall SUNIT_GetRoom(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005545C0


void __fastcall PLAYER_PlaceCorpse(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nPlayerGUID, D2CoordStrc* pCoord); // 0x005352C0
void __fastcall D2GAME_PACKETS_SendPacket0x07(D2ClientStrc* pClient, int nAreaId, unsigned short nTileX, unsigned short nTileY); // 0x0053BC50
void __fastcall D2GAME_PACKETS_SendPacket0x7E(D2ClientStrc* pClient, int nUnused); // 0x0053DB70
void __fastcall SUNITNPC_UpdateHirelingPosition(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x005773D0
int __fastcall SKILLS_ExecuteSkill(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bApplyCosts, int bSkipSkillCheck, int bItemEffect); // 0x0056F7F0
#pragma pack(push, 1)
struct D2CharacterPreviewRecordStrc
{
    unsigned char pComponents[0x0B];
    unsigned char nClass;
    unsigned char pComponentColors[0x0B];
    unsigned char nLevel;
    unsigned char nClientFlags[2];
    unsigned char nGuildFlags[2];
    unsigned char nGuildBgColor;
    unsigned char nGuildFgColor;
    unsigned char nGuildEmblem;
    unsigned int dwGuildTag;
};

#pragma pack(pop)

void __stdcall sub_0063E510_FillInventoryTables(D2UnitStrc* pUnit, unsigned char* pTableA, unsigned char* pTableB);
extern "C" char* __cdecl strcpy(char*, const char*);


static void __stdcall CLIENTS_InsertPlayerUnitUpdate(D2UnitStrc* pRoomUnit, int nX, int nY, unsigned int* pMaxDistance, D2ClientStrc* pClient, unsigned int nUpdateSize, D2ClientUnitUpdateSortStrc* pSort);

static int CLIENTS_GetUnitX_Inlined(D2UnitStrc* pUnit);
static int CLIENTS_GetUnitY_Inlined(D2UnitStrc* pUnit);

D2CriticalSectionStrc gSrvClientListByNameLock; // 0x008846C0

// 0x005376C0
void __fastcall CLIENTS_Initialize()
{
    InitializeCriticalSection(&gClientListLock);

    EnterCriticalSection(&gClientListLock);
    for (int i = 0; i < 256; ++i)
    {
        gpClientList[i] = 0;
    }
    LeaveCriticalSection(&gClientListLock);

    InitializeCriticalSection(&gSrvClientListByNameLock);

    EnterCriticalSection(&gSrvClientListByNameLock);
    for (int i = 0; i < 256; ++i)
    {
        gpClientListByName[i] = 0;
    }
    LeaveCriticalSection(&gSrvClientListByNameLock);

    gbClientListInitialized = 1;
}

D2CriticalSectionStrc gClientListLock; // 0x008846A8

// 0x00537730
void __fastcall CLIENTS_Release()
{
    DeleteCriticalSection(&gClientListLock);
    DeleteCriticalSection(&gSrvClientListByNameLock);
    gbClientListInitialized = 0;
}

// 0x00537760
D2ClientStrc* __fastcall CLIENTS_GetLockedClientFromId(int nClientId)
{
    EnterCriticalSection(&gClientListLock);
    for (D2ClientStrc* pClient = gpClientList[nClientId & 0xFF]; pClient; pClient = pClient->pServerNext)
    {
        if (pClient->dwClientId == nClientId)
        {
            return pClient;
        }
    }
    LeaveCriticalSection(&gClientListLock);
    return 0;
}

// 0x005377A0
void __fastcall CLIENTS_UnlockClientList(int nClientId)
{
    LeaveCriticalSection(&gClientListLock);
}

// 0x005377B0
int __cdecl CLIENTS_GetExpansionClientCount()
{
    int nCount = 0;
    if (!gbClientListInitialized)
    {
        return 0;
    }
    EnterCriticalSection(&gClientListLock);
    for (int i = 0; i < 256; ++i)
    {
        for (D2ClientStrc* pClient = gpClientList[i]; pClient; pClient = pClient->pServerNext)
        {
            if (pClient->tSaveFlags.bExpansion)
            {
                ++nCount;
            }
        }
    }
    LeaveCriticalSection(&gClientListLock);
    return nCount;
}

static D2ClientStrc* __fastcall CLIENTS_GetClientFromClientListWithId(D2ClientStrc* pClientList, int nClientId)
{
    for (D2ClientStrc* pClient = pClientList; pClient != 0; pClient = pClient->pNext)
    {
        if (pClient->dwClientId == nClientId)
        {
            return pClient;
        }
    }

    return 0;
}

// 0x00537810
D2ClientStrc* __fastcall CLIENTS_GetClientFromClientId(D2GameStrc* ptGame, int nClientId)
{
    D2_ASSERT(ptGame, 0xE9);
    return CLIENTS_GetClientFromClientListWithId(ptGame->pClientList, nClientId);
}

// 0x00537860
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* ptClient, int bIgnoreDeath)
{
    D2_ASSERT(ptClient, 251);

    if (ptClient->dwFlags & CLIENTFLAGEX_PLAYER_UNIT_ALIVE)
    {
        return ptClient->pPlayer;
    }

    if (bIgnoreDeath)
    {
        return ptClient->pPlayer;
    }

    if (!ptClient->pPlayer)
    {
        return 0;
    }

    D2UnitStrc* pPlayer = SUNIT_GetServerUnit(ptClient->pGame, ptClient->dwUnitType, ptClient->dwUnitGUID);
    if (!pPlayer)
    {
        ptClient->pPlayer = 0;
    }

    return pPlayer;
}

// 0x005378E0
void __fastcall CLIENTS_SetPlayerInClient(D2ClientStrc* ptClient, D2UnitStrc* pUnit)
{
    D2_ASSERT(ptClient, 0x114);

    if (pUnit)
    {
        ptClient->dwUnitType = pUnit->dwUnitType;
        ptClient->dwUnitGUID = pUnit->dwUnitId;
        ptClient->pPlayer = pUnit;
    }
    else
    {
        ptClient->pPlayer = 0;
    }
}

struct D2InventoryStrc;

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304


void __fastcall D2GAME_PACKETS_SendPacketSize06(D2ClientStrc* pClient, unsigned char nHeader, int dwUnitType, int dwUnitId); // 0x0053B3D0


void __fastcall D2GAME_PACKETS_SendPacket0x7B(D2ClientStrc* pClient, unsigned char nIndex, int nSkill, int nHand, int nItemGUID); // 0x0053DB20


void __fastcall D2GAME_UpdateAttribute(D2UnitStrc* pUnit, unsigned short nStat, unsigned int nNewValue, D2UnitStrc* pPlayer); // 0x00548520

void __stdcall D2Common_10513(D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, void(__fastcall* pfCallback)(D2UnitStrc*, unsigned short, unsigned int, D2UnitStrc*)); // 0x006258D0

// 0x00463720
inline int __fastcall ITEMS_CheckUnitFlagEx(D2UnitStrc* pUnit, unsigned int dwMask)
{
    if (!pUnit)
    {
        return 0;
    }
    return (pUnit->dwFlagEx & dwMask) != 0;
}


// 0x00537930
static void __stdcall CLIENTS_SendPlayerAssign(D2ClientStrc* pClient, D2UnitStrc* pUnit)
{
    const int nUnitType = !pUnit ? UNIT_INVALID : pUnit->dwUnitType;
    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    D2GAME_PACKETS_SendPacketSize06(pClient, 0x0B, nUnitType, nUnitGUID);
}

struct D2StoredUnitRecordStrc
{
    char unk0x00[0x66];
    char szName[1];
};

struct ROSTER_SetCtrlState
{
    char unk0x00[0x5C];
    int nState;
};

struct D2SoundObjStrc_00515A30
{
    char unk0x00[0x40];
    int nValue40;
    int nValue44;
};

struct D2LinkStrc_004CA990
{
    void* pFirst;
};

struct D2OwnerStrc_004CA990
{
    char unk0x00[0x78];
    D2LinkStrc_004CA990* pLink;
};

typedef char check_ptr_width[(sizeof(void*) == 4) ? 1 : -1];

typedef char check_size_entry[(sizeof(D2StoredUnitRecordStrc) == 0x67) ? 1 : -1];

typedef char check_size_ctrl[(sizeof(ROSTER_SetCtrlState) == 0x60) ? 1 : -1];

typedef char check_size_sound[(sizeof(D2SoundObjStrc_00515A30) == 0x48) ? 1 : -1];

typedef char check_size_owner[(sizeof(D2OwnerStrc_004CA990) == 0x7C) ? 1 : -1];

// 0x004795C0
extern "C" const char* __fastcall ROSTER_GetEntryName(D2StoredUnitRecordStrc* pEntry)
{
    D2_ASSERT(pEntry, 372);
    return pEntry->szName;
}

// 0x004B8370
extern "C" void __fastcall ROSTER_SetCtrlState(ROSTER_SetCtrlState* pCtrl, int nState)
{
    D2_ASSERT(pCtrl, 1310);
    pCtrl->nState = nState;
}

// 0x004CA990
extern "C" void* __fastcall UNITSND_GetLinkFirst(D2OwnerStrc_004CA990* pOwner)
{
    D2_ASSERT(pOwner, 3171);
    D2LinkStrc_004CA990* pLink = pOwner->pLink;
    if (pLink)
    {
        return pLink->pFirst;
    }

    return 0;
}

// 0x00515A30
extern "C" void __fastcall D2SOUND_SetSoundNoLoop(D2SoundObjStrc_00515A30* pSound, int nValue)
{
    D2_ASSERT(pSound, 815);
    pSound->nValue40 = nValue;
}

// 0x00515A60
extern "C" void __fastcall D2SOUND_SetSoundLoopStart(D2SoundObjStrc_00515A30* pSound, int nValue)
{
    D2_ASSERT(pSound, 826);
    pSound->nValue44 = nValue;
}

// 0x00537970
extern "C" void __fastcall CLIENTS_SetPlayerUnitAlive(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 518);
    pClient->dwFlags |= 1;
}

// 0x005379A0
void __fastcall CLIENTS_SetGameData(D2ClientStrc* pClient)
{
    pClient->nValue_08C = 0;
    pClient->nValue_088 = 0;
    if (gpD2EventCallbackTable && gpD2EventCallbackTable->pfGetValue)
    {
        *(int*)&pClient->szAccount[3] = gpD2EventCallbackTable->pfGetValue();
    }
}

// 0x005379D0
int __fastcall CLIENTS_GetPlayerGfxComponents(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pGrid, unsigned int nSize)
{
    unsigned char abOther[16];
    D2_ASSERT(nSize >= 16 && pUnit, 0x3D4);
    memset(pGrid, 0xFF, 16);
    return sub_0063E510_InventoryGridQuery(pUnit, pGrid, abOther);
}

// 0x00537A40
int __fastcall CLIENTS_GetPlayerGfxColors(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned char* pGrid, unsigned int nSize)
{
    unsigned char abOther[16];
    D2_ASSERT(nSize >= 16 && pUnit, 0x3DF);
    memset(pGrid, 0xFF, 16);
    return sub_0063E510_InventoryGridQuery(pUnit, abOther, pGrid);
}

// 0x00537AB0
static inline void CLIENTS_MoveClientBetweenRooms(D2ActiveRoomStrc* pNewRoom, D2ActiveRoomStrc* pOldRoom)
{
    DUNGEON_ChangeClientRoom(pOldRoom, pNewRoom);
    D2Common_10077(pOldRoom, pNewRoom);
}

struct D2NpcRecordStrc;

struct D2ItemCacheStrc;

struct D2UnitProxyStrc;


struct D2NpcGambleStrc;


struct Pad40_00536B40;

struct Pad400_00536B40;

struct Obj00536B40;

struct D2ItemsTxt;

struct D2EventTimerSlabListStrc;

struct D2EventTimerQueueStrc;

struct D2QuestGUIDStrc;


D2UnitProxyStrc gaUnitProxyItemCache[17]; // 0x00883D78

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0


extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260











void __fastcall FOG_FreePool(void*,void*,const char*,int,int); // 0x0040B480

struct Pad40_00536B40 {
    unsigned int dw00;
    unsigned int dw04;
    unsigned int dw08;
    unsigned int f_C;
    unsigned int dw10;
    unsigned int dw14;
    unsigned int dw18;
    unsigned int dw1C;
    unsigned int dw20;
    unsigned int dw24;
    unsigned int dw28;
    unsigned int dw2C;
    unsigned int dw30;
    unsigned int dw34;
    unsigned int dw38;
    unsigned int dw3C;
};

struct Pad400_00536B40 {
    Pad40_00536B40 t000;
    Pad40_00536B40 t040;
    Pad40_00536B40 t080;
    Pad40_00536B40 t0C0;
    Pad40_00536B40 t100;
    Pad40_00536B40 t140;
    Pad40_00536B40 t180;
    Pad40_00536B40 t1C0;
    Pad40_00536B40 t200;
    Pad40_00536B40 t240;
    Pad40_00536B40 t280;
    Pad40_00536B40 t2C0;
    Pad40_00536B40 t300;
    Pad40_00536B40 t340;
    Pad40_00536B40 t380;
    Pad40_00536B40 t3C0;
};

struct Obj00536B40 {
    Pad400_00536B40 tPad0000;
    Pad400_00536B40 tPad0400;
    Pad400_00536B40 tPad0800;
    Pad400_00536B40 tPad0C00;
    Pad400_00536B40 tPad1000;
    Pad400_00536B40 tPad1400;
    Pad400_00536B40 tPad1800;
    Pad40_00536B40 tPad1C00;
    Pad40_00536B40 tPad1C40;
    Pad40_00536B40 tPad1C80;
    Pad40_00536B40 tPad1CC0;
    unsigned int dwUnknown1D00;
    unsigned int dwUnknown1D04;
    unsigned int dwUnknown1D08;
    unsigned int dwUnknown1D0C;
    unsigned int dwUnknown1D10;
    unsigned int dwUnknown1D14;
    unsigned int dwUnknown1D18;
    unsigned int dwUnknown1D1C;
    unsigned int dwUnknown1D20;
    unsigned int dwValue1D24;
};


unsigned char gbUnitProxyItemCacheInitialized[17]; // 0x00883E88


enum
{
    MAX_NPC_INVENTORY = 17,
    UNIT_ALIGNMENT_EVIL = 0,
    UNITFLAG_TARGETABLE = 0x00000002,
    UNITFLAG_ISMERC = 0x00000200,
    MONSTATS2FLAGINDEX_SOFT = 12,
};



#define MAX_NPC_INVENTORY 17

extern "C" const char szSUnitProxyCppFile[];                                                                // 0x006E0A30

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430



extern unsigned int gdwBitMasks[]; // 0x006CE268


extern int gnCrossbowQuiverItemId; // 0x00883E9C

extern int gnArrowQuiverItemId; // 0x00883EA0



#define UNIT_MONSTER 1

#define NPCREC_FIELD(type, cursor, offset) (*(type*)((cursor) + (offset) - 0x2C))

extern "C" const char szSUnitProxyCppFile[]; // 0x006E0A30






// 0x00537AC0
void __fastcall CLIENTS_FreeClientsFromGame(D2GameStrc* pGame)
{
    D2ClientStrc* pClient = pGame->pClientList;
    while (pClient)
    {
        D2ClientStrc* pCurrent = pClient;
        pClient = pClient->pNext;
        FOG_FreePool(pGame->pMemoryPool, pCurrent, ".\\GAME\\Clients.cpp", 0x617, 0);
    }
}

// 0x00537B00
static inline void CLIENTS_UpdatePlayerPortalFlags(D2ClientStrc* pClient)
{
    D2ActiveRoomStrc* pRoom = pClient->hRoom;
    if (pRoom && pClient->pPlayer)
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
        int nFlags = UNITS_GetPlayerPortalFlags(pClient->pPlayer);
        nFlags |= DUNGEON_GetPortalFlagFromLevelId(nLevelId);
        UNITS_SetPlayerPortalFlags(pClient->pPlayer, nFlags);
    }
}

#define STAT_LEVEL 12

#define EVENTTYPE_STATREGEN 3

#define EVENTTYPE_TRAP 4

#define EVENTTYPE_RESET 5

#define EVENTTYPE_REMOVESTATE 12

#define EVENTTYPE_COUNT 15

#define UNITEVENTFLAG_IN_CALLBACK 0x01

#define UNITEVENTFLAG_SHOULD_BE_FREED 0x02

#define MONSTER_COMPONENT_COUNT 16

#define OBJRGN_MAX_WELLS 4

#define OBJRGN_MAX_SHRINES 10

struct D2HotkeySkillStrc;

struct D2MonsterDataStrc;


void __fastcall sub_0055F4F0_Nop(D2GameStrc* pGame, D2UnitStrc* pUnit, int nUnused); // 0x0055F4F0


typedef int (__fastcall* D2UnitEventCallbackFunction)(D2GameStrc* pGame, int nUnitEvent, D2UnitStrc* pUnit, D2UnitStrc* pEventSourceUnit, D2DamageStrc* pDamage, int nGUID1, int nGUID2);


typedef void (__fastcall* PartyCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArgs);

typedef void (__fastcall* EventCallbackFunction)(D2GameStrc* pGame, D2UnitStrc* pUnit);

typedef void (__fastcall* MonEventFunc)(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, int nSkillLevel);

extern EventCallbackFunction gpfnItemEventFunctions[15]; // 0x006E117C

extern EventCallbackFunction gpfnObjectEventFunctions[15]; // 0x006E19B0

extern MonEventFunc const gpMonsterEventFunctions[16]; // 0x006E2490

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480


void __fastcall PARTY_IteratePartyMembersInSameLevel(D2GameStrc* pGame, D2UnitStrc* pUnit, PartyCallbackFunction pCallback, void* pArgs); // 0x005405A0


short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630


inline int M08_UNITS_GetXPositionInline(D2UnitStrc* pUnit)
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

inline int M08_UNITS_GetYPositionInline(D2UnitStrc* pUnit)
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

static inline D2UnitStrc* sub_M08_GetClientPlayerUnit(D2ClientStrc* pClient)
{
    if (pClient->dwFlags & CLIENTFLAGEX_PLAYER_UNIT_ALIVE)
    {
        return pClient->pPlayer;
    }
    if (!pClient->pPlayer)
    {
        return 0;
    }
    D2UnitStrc* pUnit = SUNIT_GetServerUnit(pClient->pGame, pClient->dwUnitType, pClient->dwUnitGUID);
    if (!pUnit)
    {
        pClient->pPlayer = 0;
    }
    return pUnit;
}

// 0x00537B50
static void __stdcall CLIENTS_ChangeRoom(D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient)
{
    if (!pClient || !pClient->pGame)
    {
        return;
    }
    D2ActiveRoomStrc* pClientRoom = pClient->hRoom;
    if (pClientRoom == pRoom)
    {
        return;
    }
    CLIENTS_MoveClientBetweenRooms(pRoom, pClientRoom);

    D2ActiveRoomStrc** ppAdjacentRooms = 0;
    int nAdjacentRooms = 0;
    if (pRoom)
    {
        DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppAdjacentRooms, (unsigned int*)&nAdjacentRooms);
    }

    D2ActiveRoomStrc** ppClientAdjacentRooms = 0;
    int nClientAdjacentRooms = 0;
    if (pClientRoom)
    {
        DUNGEON_GetAdjacentRoomsListFromRoom(pClientRoom, &ppClientAdjacentRooms, (unsigned int*)&nClientAdjacentRooms);
    }

    for (int i = 0; i < nAdjacentRooms; ++i)
    {
        int j = 0;
        while (j < nClientAdjacentRooms)
        {
            if (ppAdjacentRooms[i] == ppClientAdjacentRooms[j])
            {
                break;
            }
            ++j;
        }
        if (j >= nClientAdjacentRooms)
        {
            LEVEL_AddClient(pClient->pGame, ppAdjacentRooms[i], pClient);
        }
    }

    for (int i = 0; i < nClientAdjacentRooms; ++i)
    {
        int j = 0;
        while (j < nAdjacentRooms)
        {
            if (ppClientAdjacentRooms[i] == ppAdjacentRooms[j])
            {
                break;
            }
            ++j;
        }
        if (j >= nAdjacentRooms)
        {
            LEVEL_RemoveClient(pClient->pGame, ppClientAdjacentRooms[i], pClient);
            if (pClient->hRoom == ppClientAdjacentRooms[i])
            {
                PLRMODE_SendPlayerUpdates(pClient->pGame, sub_M08_GetClientPlayerUnit(pClient), pClient, 0);
            }
        }
    }

    pClient->hRoom = pRoom;
    CLIENTS_UpdatePlayerPortalFlags(pClient);
}

// 0x00537D10
static void __stdcall CLIENTS_InsertPlayerUnitUpdate(D2UnitStrc* pRoomUnit, int nX, int nY, unsigned int* pMaxDistance, D2ClientStrc* pClient, unsigned int nUpdateSize, D2ClientUnitUpdateSortStrc* pSort)
{
    const int nType = pRoomUnit ? pRoomUnit->dwUnitType : UNIT_INVALID;
    if (nType != UNIT_PLAYER)
    {
        return;
    }
    const int nDeltaX = nX - CLIENTS_GetUnitX_Inlined(pRoomUnit);
    const int nAbsX = nDeltaX < 0 ? -nDeltaX : nDeltaX;
    const int nDeltaY = nY - CLIENTS_GetUnitY_Inlined(pRoomUnit);
    const int nAbsY = nDeltaY < 0 ? -nDeltaY : nDeltaY;
    const unsigned int nDistance = nAbsY + nAbsX;
    if (pClient->nUnitUpdateIndex >= nUpdateSize && nDistance >= *pMaxDistance)
    {
        return;
    }
    int nPrevIndex = 0;
    while (pSort[nPrevIndex].nNextIndex)
    {
        if (nDistance <= pSort[pSort[nPrevIndex].nNextIndex].nDistance)
        {
            break;
        }
        nPrevIndex = pSort[nPrevIndex].nNextIndex;
    }
    int nNewIndex;
    if (pClient->nUnitUpdateIndex == nUpdateSize)
    {
        int nLastIndex = 0;
        int* const pHead = &pSort[0].nNextIndex;
        if (pSort[pSort[0].nNextIndex].nNextIndex)
        {
            int* p = pHead;
            do
            {
                nLastIndex = *p;
                p = &pSort[nLastIndex].nNextIndex;
            } while (pSort[pSort[nLastIndex].nNextIndex].nNextIndex);
        }
        D2ClientUnitUpdateSortStrc* pLast = &pSort[nLastIndex];
        nNewIndex = pLast->nNextIndex;
        if (pClient->nUnitUpdateIndex && nDistance >= pSort[nNewIndex].nDistance)
        {
            return;
        }
        if (pClient->nUnitUpdateIndex == 1)
        {
            *pMaxDistance = nDistance;
        }
        else
        {
            *pMaxDistance = pLast->nDistance;
        }
        pLast->nNextIndex = 0;
    }
    else
    {
        nNewIndex = pClient->nUnitUpdateIndex;
        pClient->nUnitUpdateIndex = nNewIndex + 1;
    }
    if (!nPrevIndex && nDistance < pSort[0].nDistance)
    {
        if (pClient->nUnitUpdateIndex - 1 != 0)
        {
            pSort[nNewIndex].nNextIndex = pSort[0].nNextIndex;
            pSort[nNewIndex].pUnit = pSort[0].pUnit;
            pSort[nNewIndex].nDistance = pSort[0].nDistance;
        }
        pSort[0].nNextIndex = nNewIndex;
        nNewIndex = 0;
    }
    else
    {
        pSort[nNewIndex].nNextIndex = pSort[nPrevIndex].nNextIndex;
        pSort[nPrevIndex].nNextIndex = nNewIndex;
    }
    pSort[nNewIndex].nDistance = nDistance;
    pSort[nNewIndex].pUnit = pRoomUnit;
    if (nDistance > *pMaxDistance)
    {
        *pMaxDistance = nDistance;
    }
}

static int CLIENTS_GetUnitX_Inlined(D2UnitStrc* pUnit)
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

static int CLIENTS_GetUnitY_Inlined(D2UnitStrc* pUnit)
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

// 0x00537EE0
static void __stdcall CLIENTS_SetUnitsUpdateList(D2ClientStrc* pClient, D2ClientUnitUpdateSortStrc* pSort)
{
    D2ClientUnitUpdateSortStrc* pCurrent = pSort;
    pClient->nUnitUpdateIndex = 0;
    do
    {
        pClient->unitUpdate[pClient->nUnitUpdateIndex].nUnitType = !pCurrent->pUnit ? UNIT_INVALID : pCurrent->pUnit->dwUnitType;
        pClient->unitUpdate[pClient->nUnitUpdateIndex].nUnitGUID = !pCurrent->pUnit ? -1 : pCurrent->pUnit->dwUnitId;
        pClient->unitUpdate[pClient->nUnitUpdateIndex].nX = CLIENTS_GetUnitX_Inlined(pCurrent->pUnit);
        pClient->unitUpdate[pClient->nUnitUpdateIndex].nY = CLIENTS_GetUnitY_Inlined(pCurrent->pUnit);
        ++pClient->nUnitUpdateIndex;
        pCurrent = &pSort[pCurrent->nNextIndex];
    }
    while (pCurrent->nNextIndex);
}

// 0x00537FD0
void __fastcall CLIENTS_RefreshUnitsUpdateList(D2ClientStrc* ptClient, unsigned int nUpdateSize)
{
    D2_ASSERT(ptClient->hRoom, 0x70B);
    D2ActiveRoomStrc** pAdjacentRoomsList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(ptClient->hRoom, &pAdjacentRoomsList, &nNumRooms);
    D2_ASSERT(pAdjacentRoomsList, 0x70D);
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(ptClient, 0);
    if (!pPlayer)
    {
        return;
    }
    const int nPlayerX = CLIENTS_GetUnitX(pPlayer);
    const int nPlayerY = CLIENTS_GetUnitY(pPlayer);
    unsigned int nCurrentMaxDistance = 0;
    D2ClientUnitUpdateSortStrc tUnitUpdatesSort[55];
    ptClient->nUnitUpdateIndex = 0;
    tUnitUpdatesSort[0].nNextIndex = 0;
    tUnitUpdatesSort[0].nDistance = 0;
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        for (D2UnitStrc* pRoomUnit = pAdjacentRoomsList[i]->pUnitFirst; pRoomUnit; pRoomUnit = pRoomUnit->ptRoomNext)
        {
            CLIENTS_InsertPlayerUnitUpdate(pRoomUnit, nPlayerX, nPlayerY, &nCurrentMaxDistance, ptClient, nUpdateSize, tUnitUpdatesSort);
        }
    }
    CLIENTS_SetUnitsUpdateList(ptClient, tUnitUpdatesSort);
}

inline int UNITS_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlagEx & nFlag) != 0;
    }

    return 0;
}

// 0x005380D0
void __fastcall CLIENTS_SynchronizePlayer(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    if (!pGame || !pClient)
    {
        return;
    }
    D2ActiveRoomStrc* pClientRoom = pClient->hRoom;
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (!pPlayer)
    {
        return;
    }
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    LEVEL_RemoveUnitsExceptClientPlayer(pClientRoom, pClient);
    LEVEL_UpdateUnitsInAdjacentRooms(pGame, pClientRoom, pClient);
    D2Common_10513(pPlayer, pPlayer, D2GAME_UpdateAttribute);
    if (UNITS_HasFlagEx(pPlayer, 0x200000))
    {
        D2GAME_ITEMS_UpdateInventoryItems(pGame, pPlayer, 1, 1);
        sub_0055F4F0_Nop(pGame, pPlayer, 1);
    }
    ++pClient->nPlayerSyncCount;
    if (pClientRoom != pRoom)
    {
        const int nSourceLevelId = DUNGEON_GetLevelIdFromRoom(pClientRoom);
        const int nDestinationLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
        if (nSourceLevelId != nDestinationLevelId)
        {
            QUESTS_ChangeLevel(pGame, nSourceLevelId, nDestinationLevelId, pPlayer);
            SUNITPROXY_UpdateNpcsOnActChange(pGame, pPlayer, nSourceLevelId, nDestinationLevelId);
        }
        CLIENTS_ChangeRoom(pRoom, pClient);
    }
    ARENA_SynchronizeWithClients(pGame, pClient);
    if (UNITS_GetRoom(pPlayer))
    {
        UNITROOM_RefreshUnit(pPlayer);
    }
}

struct D2SaveHeaderStrc;

struct D2ClientInfoStrc;

#define CLIENTFLAGEX_DEAD 0x02

#define CLIENTFLAGEX_SAVE_LOADED 0x10

#define CLIENTFLAGEX_0x20 0x20

#define CLIENT_SAVE_STEP 5

#define ACCOUNT_COPY_MAX 50

// 0x005381C0
int __fastcall CLIENTS_IsInGame(D2GameStrc* pGame, int nClientId)
{
    for (D2ClientStrc* pClient = pGame->pClientList; pClient; pClient = pClient->pNext)
    {
        if (pClient->dwClientId == nClientId)
        {
            return 1;
        }
    }

    return 0;
}

static inline int sub_M08_GetUnitFlagEx21(D2UnitStrc* pUnit)
{
    return (pUnit->dwFlagEx >> 21) & 1;
}

// 0x005381F0
void __fastcall CLIENTS_SetRoomInClient(D2ClientStrc* ptClient, D2ActiveRoomStrc* pRoom)
{
    D2_ASSERT(ptClient, 1951);
    if (pRoom != ptClient->hRoom)
    {
        CLIENTS_ChangeRoom(pRoom, ptClient);
    }
    ptClient->hRoom = pRoom;
}

// 0x00538230
D2ActiveRoomStrc* __fastcall CLIENTS_GetRoom(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 1966);

    return pClient->hRoom;
}

// 0x00538260
void __fastcall D2GAME_SetClientDead(D2ClientStrc* ptClient, const int* pDeathInfo)
{
    D2_ASSERT(ptClient, 1998);

    if (!pDeathInfo)
    {
        ptClient->dwFlags &= ~CLIENTFLAGEX_DEAD;
        return;
    }

    ptClient->nDeadTargetType = pDeathInfo[0];
    ptClient->nDeadTargetGUID = pDeathInfo[3];
    ptClient->dwFlags |= CLIENTFLAGEX_DEAD;
}

// 0x005382B0
unsigned char __fastcall CLIENTS_GetActNo(D2ClientStrc* ptClient)
{
    D2_ASSERT(ptClient, 2015);

    return ptClient->bAct;
}

// 0x005382E0
void __fastcall CLIENTS_SetActNo(D2ClientStrc* pClient, unsigned char nAct)
{
    D2_ASSERT(pClient, 2026);
    D2_ASSERT(nAct < NUM_ACTS, 2027);

    pClient->bAct = nAct;
}

// 0x00538320
void __fastcall CLIENTS_EnableCharacterUnlock(D2ClientStrc* ptClient)
{
    D2_ASSERT(ptClient, 2037);

    ptClient->bUnlockCharacter = 1;
}

// 0x00538350
unsigned int __fastcall D2GAME_GetSaveChecksumFromClient(D2ClientStrc* ptClient)
{
    D2_ASSERT(ptClient, 2047);

    return ptClient->nSaveChecksum;
}

// 0x00538380
void __fastcall D2GAME_SetSaveFileChecksum(D2ClientStrc* ptClient, unsigned int nChecksum)
{
    D2_ASSERT(ptClient, 2058);

    ptClient->nSaveChecksum = nChecksum;
}

// 0x005383B0
unsigned char __fastcall sub_005383B0_GetClientByte1AD(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 0x816);
    return pClient->nByte1AD;
}

// 0x005383E0
void __fastcall sub_005383E0_SetClientByte1AD(D2ClientStrc* pClient, unsigned char nValue)
{
    D2_ASSERT(pClient, 0x822);
    pClient->nByte1AD = nValue;
}

// 0x00538410
void __fastcall CLIENTS_SendUnitIfOutsideAdjacentRooms(D2ClientStrc* pClient, D2UnitStrc* pUnit)
{
    D2GameStrc* pGame = pClient->pGame;
    if (pUnit == CLIENTS_GetPlayerFromClient(pClient, 0))
        return;
    D2ActiveRoomStrc* pUnitRoom = SUNIT_GetRoom(pGame, pUnit);
    if (!pUnitRoom)
        return;
    D2ActiveRoomStrc* pClientRoom = pClient->hRoom;
    D2_ASSERT(pClientRoom, 2107);
    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pClientRoom, &ppRoomList, &nNumRooms);
    unsigned int i = 0;
    for (; i < nNumRooms; ++i)
    {
        D2ActiveRoomStrc* pRoom = ppRoomList[i];
        D2_ASSERT(pRoom, 2112);
        if (pUnitRoom == pRoom)
            break;
    }
    if (i >= nNumRooms)
        SUNITMSG_SendUnitToClient(pGame, pUnit, pClient);
}


// 0x005384E0
void __fastcall CLIENTS_RemoveUnitIfNotAdjacent(D2ClientStrc* pClient, D2UnitStrc* pUnit)
{
    D2_ASSERT(pClient, 2131);

    D2ActiveRoomStrc* pUnitRoom = UNITS_GetRoom(pUnit);
    D2ActiveRoomStrc* pClientRoom = pClient->hRoom;
    D2_ASSERT(pClientRoom, 2137);

    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pClientRoom, &ppRoomList, &nNumRooms);

    unsigned int i = 0;
    for (; i < nNumRooms; ++i)
    {
        D2ActiveRoomStrc* pRoom = ppRoomList[i];
        D2_ASSERT(pRoom, 2142);
        if (pUnitRoom == pRoom)
        {
            break;
        }
    }

    if (i >= nNumRooms)
    {
        SUNITMSG_SendRemoveObject(pUnit, pClient);
    }
}

// 0x00538590
int __fastcall CLIENTS_GetClientId(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 2160);

    return pClient->dwClientId;
}

// 0x005385C0
int __fastcall CLIENTS_GetPlayTime()
{
    return -1;
}

// 0x005385D0
void __stdcall sub_005385D0_Nop(int nUnused)
{
}

// 0x005385E0
void __cdecl sub_005385E0_Nop()
{
}

static void sub_M08_RemoveUnitFromRoom(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    const int nUnitGUID = pUnit->dwUnitId;
    const int nUnitType = pUnit->dwUnitType;
    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pUnit), nUnitType, nUnitGUID);
    SUNIT_RemoveUnit(pGame, pUnit);
}

// 0x005385F0
int __fastcall CLIENTS_GetClassId(D2ClientStrc* ptClient)
{
    D2_ASSERT(ptClient, 2232);

    return ptClient->nClassId;
}

// 0x00538620
void __fastcall CLIENTS_SetClassId(D2ClientStrc* pClient, int nClass)
{
    pClient->nClassId = nClass;
}

// 0x00538630
void __fastcall CLIENTS_SetFlags(D2ClientStrc* pClient, int nFlags)
{
    pClient->nSaveFlags = nFlags;
}

// 0x00538640
int __fastcall CLIENTS_GetFlags(D2ClientStrc* pClient)
{
    return pClient->nSaveFlags;
}

// 0x005386D0
void __fastcall CLIENTS_SetClientState(D2ClientStrc* pClient, int nClientState)
{
    D2_ASSERT(pClient, 2419);

    pClient->dwClientState = nClientState;
}

// 0x00538700
void __fastcall CLIENTS_SetIronGolemItemGUID(D2ClientStrc* ptClient, int nIronGolemItemGUID)
{
    D2_ASSERT(ptClient, 2430);

    ptClient->nIronGolemItemGUID = nIronGolemItemGUID;
}

// 0x00538760
void __fastcall CLIENTS_SetCreateTime(D2ClientStrc* ptClient, unsigned int nCreateTime)
{
    D2_ASSERT(ptClient, 2452);

    ptClient->nCreateTime = nCreateTime;
}

// 0x00538790
int __fastcall CLIENTS_GetCreateTime(D2ClientStrc* ptClient)
{
    D2_ASSERT(ptClient, 2463);

    return ptClient->nCreateTime;
}

// 0x005387C0
D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc* ptClient)
{
    D2_ASSERT(ptClient, 2474);

    return ptClient->pGame;
}

// 0x005387F0
int __fastcall CLIENTS_IsInUnitsRoom(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (pRoom)
    {
        unsigned int nNumClients = pRoom->nNumClients;
        D2ClientStrc** ppClients = pRoom->ppClients;
        for (unsigned int i = 0; i < nNumClients; ++i)
        {
            if (ppClients[i] == pClient)
            {
                return 1;
            }
        }
    }

    return 0;
}

// 0x00538830
char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 2541);

    return pClient->szName;
}

void __fastcall D2GAME_PACKETS_SendPacket0x8F(D2ClientStrc* pClient,int tick); // 0x0053E020

// 0x005389A0
void __fastcall CLIENTS_UpdatePing(int nClientId, int nTick, int nDelay, int nUnused)
{
    D2GameStrc* pGame = GAME_GetGameByClientId(nClientId);
    if (pGame)
    {
        D2ClientStrc* pClient = pGame->pClientList;
        for (; pClient; pClient = pClient->pNext)
        {
            if (pClient->dwClientId == nClientId)
            {
                unsigned int nNow = GetTickCount();
                pClient->dwPings[pClient->dwPingsCount & 15] = nNow - nTick - nDelay;
                ++pClient->dwPingsCount;
                unsigned __int64 nSum = 0;
                int nCount = pClient->dwPingsCount > 16 ? 16 : pClient->dwPingsCount;
                for (int i = 0; i < nCount; ++i)
                    nSum += pClient->dwPings[i];
                pClient->nAveragePing = nSum / nCount;
                D2GAME_PACKETS_SendPacket0x8F(pClient, nTick);
                pClient->dwLastPacketTick = nNow;
                break;
            }
        }
        GAME_LeaveGamesCriticalSection(pGame);
    }
    else if (gbClientListInitialized)
    {
        EnterCriticalSection(&gClientListLock);
        D2ClientStrc* pClient = gpClientList[nClientId & 255];
        for (; pClient; pClient = pClient->pServerNext)
        {
            if (pClient->dwClientId == nClientId)
            {
                unsigned int nNow = GetTickCount();
                if (pClient->dwPingsCount < 10)
                {
                    __int64 nWeighted = pClient->dwPingsCount * pClient->nAveragePing;
                    int nDelta = nNow - nTick - nDelay;
                    ++pClient->dwPingsCount;
                    pClient->nAveragePing = (nWeighted + nDelta) / pClient->dwPingsCount;
                }
                D2GAME_PACKETS_SendPacket0x8F(pClient, nTick);
                ++pClient->dwPingsCount;
                pClient->dwLastPacketTick = nNow;
                break;
            }
        }
        LeaveCriticalSection(&gClientListLock);
    }
}

// 0x00538B70
int __fastcall CLIENTS_GetNameById(int nClientId, char* szName)
{
    if (!gbClientListInitialized)
    {
        return 1;
    }

    int nResult = 1;
    EnterCriticalSection(&gClientListLock);

    for (D2ClientStrc* pClient = gpClientList[nClientId & 0xFF]; pClient; pClient = pClient->pServerNext)
    {
        if (!nResult)
        {
            break;
        }

        if (pClient->dwClientId == nClientId)
        {
            if (szName)
            {
                SStrCopy(szName, pClient->szName, sizeof(pClient->szName));
            }

            nResult = 0;
        }
    }

    LeaveCriticalSection(&gClientListLock);
    return nResult;
}


#define STAT_GOLD 14

#define ITEMACTION_DROPTOGROUND 2

#define ITEMACTION_ONGROUND 3

#define ACT_II 1

#define ACT_III 2

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

#define CLIENTSAVEFLAG_EXPANSION 0x20

#define CLIENTSAVEFLAG_LADDER 0x40

#define GAMEFLAG_ARENA_HARDCORE 0x800

#define NUM_DIFFICULTIES 3

#define PLRSAVE2ERROR_BAD_PLAYERINTRO 11

union D2SeedStrc;

struct D2PlayerDataStrc;

struct D2SkillsTxt;

struct D2PartyNodeStrc;

struct D2PartyStrc;

struct D2PartyControlStrc;


struct D2LargeIntegerStrc;

struct D2FileTimeStrc;

struct D2UnitProxyArgStrc;

struct D2UnitFindArgStrc;

struct D2Act2Quest6Strc;

struct D2Act5Quest4Strc;

struct D2StatesTxt;


struct D2SavedItemStrc;


struct D2DrlgActStrc;

struct D2UnitFindDataStrc;

struct D2DataTablesStrc;

struct D2ItemDropStrc;

struct D2ItemSaveStrc;

struct D2HirelingTxt;

struct D2CharStatsTxt;







extern D2CriticalSectionStrc gSrvClientListByNameLock; // 0x008846C0


extern int gbHasHighResolutionClock; // 0x0088C7A0

extern D2LargeIntegerStrc gPerformanceFrequency; // 0x0088C790

extern int gbD2ServerCallbackFunctionsInitialized; // 0x00883D54






typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);















extern "C" const char gszSaveFormat_006D4230[]; // 0x006D4230

extern "C" const char gszFileModeWb[]; // 0x006D69E0

extern "C" const char gszSaveOpenError[]; // 0x006E09C4

extern "C" const char gszPlrSaveSourceFile[]; // 0x006E09AC

extern int gnUnchangedSaveCount; // 0x00883D6C







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
























extern "C" const char gszPlrSaveSourceFile[]; // 0x006E09AC




#define CLIENTFLAGEX_HAS_SAVE_CHECKSUM 0x08

// 0x00538CE0
int __fastcall CLIENTS_AttachSaveFile(int nClientId, const void* pSaveData, int nSize, int nTotalSize, int bUnlockCharacter, int nUnused1, int nUnused2)
{
    int nResult = 0;

    if (!gbClientListInitialized)
    {
        return 0;
    }

    EnterCriticalSection(&gClientListLock);

    D2ClientStrc* ptClient = gpClientList[nClientId & 0xFF];
    while (ptClient)
    {
        if (ptClient->dwClientId == nClientId)
        {
            break;
        }

        ptClient = ptClient->pServerNext;
    }

    if (ptClient)
    {
        void* pDestination = 0;
        if (!ptClient->nSaveHeaderSize)
        {
            ptClient->pSaveHeader = (D2SaveHeaderStrc*)sub_0040B430(ptClient->pGame->pMemoryPool, nTotalSize, ".\\GAME\\Clients.cpp", 2858, 0);
            pDestination = ptClient->pSaveHeader;
        }
        else
        {
            pDestination = (char*)ptClient->pSaveHeader + ptClient->nSaveHeaderSize;
        }

        D2_ASSERT(ptClient->nSaveHeaderSize + nSize <= nTotalSize, 2863);

        memcpy(pDestination, pSaveData, nSize);

        ptClient->nSaveHeaderSize += nSize;
        ptClient->bUnlockCharacter = bUnlockCharacter;

        if (ptClient->nSaveHeaderSize == nTotalSize)
        {
            ptClient->dwFlags |= CLIENTFLAGEX_HAS_SAVE_CHECKSUM;
            ptClient->nSaveChecksum = D2GAME_SAVE_CalculateChecksum(ptClient->pSaveHeader, ptClient->nSaveHeaderSize);
            nResult = 1;
        }
    }

    LeaveCriticalSection(&gClientListLock);
    return nResult;
}

// 0x00538E00
D2SaveHeaderStrc* __fastcall CLIENTS_GetSaveHeader(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 2901);

    return pClient->pSaveHeader;
}

// 0x00538E30
int __fastcall CLIENTS_GetSaveHeaderSize(D2ClientStrc* ptClient)
{
    D2_ASSERT(ptClient, 2911);

    return ptClient->nSaveHeaderSize;
}

#pragma intrinsic(_ReadWriteBarrier)

#define MAX_MSG_SIZE 516

#define PCLASS_AMAZON 0

#define PCLASS_SORCERESS 1

#define PCLASS_NECROMANCER 2

#define PCLASS_BARBARIAN 4

#define PCLASS_DRUID 5

#define PCLASS_ASSASSIN 6

struct D2MonsterRegionStrc;

struct D2SGameDataStrc;


struct D2UnitDescriptionListStrc;

struct Unicode;

struct D2MonStatsTxt;

struct D2StormLinkStrc;


struct D2HashKeyNoneStrc;

struct D2GameDataTableStrc;

union D2LargeIntegerUnion;


extern char gszInfoText[]; // 0x00882028

extern int gdwGlobal_00882528; // 0x00882528

extern int gnLastStatus; // 0x0072FFA8

extern char gszReplyText[]; // 0x00882428

extern int gnCreateAccountResult; // 0x008822A4

extern int gnChangePasswordResult; // 0x008822A0

extern int gnLoginRetryCount; // 0x00882538

extern int gdwGlobal_00730190; // 0x00730190

extern int gdwGlobal_00882750; // 0x00882750



typedef void (__fastcall* GAME_ForEachIngameClientCallbackPtr)(D2ClientStrc*, void*);






D2CriticalSectionStrc gGameListLock; // 0x00882D18

D2GameStrc* gpGame; // 0x00882D34

int gnGamesGUIDs[1024];                                                                            // 0x00882D38






void __fastcall ClientRemoveFromGame(D2GameStrc* pGame, int nClientId, int bTriggerSave); // 0x00539DA0



void __fastcall D2GAME_SetSkills(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove); // 0x0056DEB0


typedef int (__fastcall* D2NET_Unk_Callback)(int, int, int, int);




// build: symbol _gszD2NetSourceFile 0x006E0488
extern "C" const char gszD2NetSourceFile[];

// build: symbol ?gnConnectionMode@* 0x00882D10
extern int gnConnectionMode;

typedef void(__fastcall* UnitDescriptionFunction)(char* szDescription, int nClassId);

extern UnitDescriptionFunction gpfnGetDescription[5]; // 0x0073107C


extern unsigned short gwValue_0077905C;


struct D2GameHashLinkStrc
{
    D2GameHashLinkStrc* m_prevlink;
    D2GameStrc* m_next;

    D2GameHashLinkStrc* NextLink(int nLinkOffset)
    {
        if ((int)m_next < 0)
        {
            return (D2GameHashLinkStrc*)~(int)m_next;
        }
        if (nLinkOffset < 0)
        {
            nLinkOffset = (char*)this - (char*)m_prevlink->m_next;
        }
        return (D2GameHashLinkStrc*)((char*)m_next + nLinkOffset);
    }

    void Unlink()
    {
        if (m_prevlink)
        {
            NextLink(-1)->m_prevlink = m_prevlink;
            m_prevlink->m_next = m_next;
            m_prevlink = 0;
            m_next = 0;
        }
    }
};

struct D2GameHashListStrc
{
    int m_linkoffset;
    D2GameHashLinkStrc m_terminator;
};

struct D2GameDataTableStrc
{
    virtual void InternalDelete(D2GameStrc* pGame);
    virtual D2GameStrc* sub_NewNode(D2GameHashListStrc* pList, int nExtraBytes, int nFlags);
    int m_linkoffset;
    D2GameHashLinkStrc m_terminator;
    unsigned int m_fullnessIndicator;
    unsigned int f_14;
    unsigned int f_18;
    D2GameHashListStrc* m_slotlistarray;
    unsigned int f_20;
    unsigned int m_hashmask;
    char unk0x28[0x1C];
    D2HashKeyNoneStrc f_44;
    char unk0x45[0x3];
    unsigned int nSequence;
    int bWrapped;
    D2CriticalSectionStrc f_50;

    void SyncEnterLock(int* pLockHandle, int bForWriting);
    void SyncLeaveLock(int nLockHandle);
    void Unlock(int nLockHandle);
    void Unlink(D2GameStrc* pGame);                                                                         // 0x0052E490
    void Delete(D2GameStrc* pGame); // 0x0052E590
    void sub_0052E5B0(D2GameStrc* pGame);
    void DeleteUnlock(D2GameStrc* pGame, int nLockHandle);                                                  // 0x0052E5D0
    D2GameStrc* Ptr(unsigned int nHashValue, const D2HashKeyNoneStrc* pKey);                                // 0x0052E650
    D2GameStrc* sub_0052E6B0(unsigned int nHashValue);
    unsigned int GenerateHandle(); // 0x0052E6D0
    int MonitorFullness(unsigned int nSlot);                                                                   // 0x00530600
    D2GameStrc* sub_00530820_New(unsigned int nHashVal, HASHKEY_NONE* pKey, int nExtraBytes, int nFlags);
    D2GameStrc* NewHandle(unsigned int* pHandle); // 0x005308C0
    D2GameStrc* NewLock(unsigned int* pHandle, int* pLockedHandle); // 0x005308F0
    D2GameStrc* Lock(unsigned int nHashValue, int* pLockHandle, int bForWriting);

    D2GameStrc* LockInline(unsigned int nHashValue, int* pLockHandle, int bForWriting)
    {
        EnterCriticalSection(&f_50);
        *pLockHandle = bForWriting ? 1 : -1;
        D2GameStrc* pGame = Ptr(nHashValue, &f_44);
        if (!pGame)
        {
            if (*pLockHandle)
            {
                LeaveCriticalSection(&f_50);
            }
            *pLockHandle = 0;
        }
        return pGame;
    }
};




extern "C" void _ReadWriteBarrier(void);


int gdwGlobal_00882D14; // 0x00882D14


#define PATHTYPE_ASTAR 1

#define PATHTYPE_TOWARD 2

#define PATHTYPE_MON_CIRCLE_CW 5

#define PATHTYPE_MON_CIRCLE_CCW 6


unsigned long gdwPlayerPos; // 0x00883D4C

D2GameDataTableStrc* gpGameDataTbl; // 0x00883D38

int gnLastGamesUpdateTimeMs; // 0x00883D58

int gnTargetMsPerFrame; // 0x00883D60


#define BUCKETS 128

#define INFO_DESCRIPTION_SIZE 16

#define GAME_ID_BIAS 1

#define UNLOCK_LINE 4196


static inline D2GameStrc* GAMELINK_Next(D2GameLinkStrc* pLink)
{
    return (int)pLink->pNext <= 0 ? 0 : pLink->pNext;
}





int gnGlobal_00883D3C;                                                                                         // 0x00883D3C

int gnGlobal_00883D40;                                                                                         // 0x00883D40


int gnAct;                                                                                         // 0x00883D44







#define INPUT_PREFIX 0

#define REPLY_FA 0xFA

#define REPLY_FB 0xFB

#define REPLY_FC 0xFC

#pragma pack(push,1)

struct Request {
#if INPUT_PREFIX
 char movedPrefix[INPUT_PREFIX];
#endif
 int client; unsigned char unused,command;
};


struct Array8
{
    unsigned int values[8];
};

struct ServerInfo {
 unsigned int a,b,c,d,e,f,g,h,i,j;
 char description[128];
 unsigned int a8,ac,b0,b4,b8,bc,c0,c4,c8,cc,d0;
 unsigned short d4;
 unsigned int d6,da,de,e2,e6;
 unsigned short unusedEA;
 unsigned int ec;
 Array8 f0;
 unsigned int f110;
};

struct Reply {
 unsigned char command;
 unsigned int a,b,c,d,e,f,g,h,i,j;
 char description[128];
 unsigned int a9,ad,b1,b5,b9,bd;
 Array8 c1;
 unsigned int e1,e5,e9,ed,f1;
 unsigned short f5;
 unsigned int f7,fb,ff,f103,f107,f10b,f10f,f113,f117;
 char reserved[0x4A];
};

long gnAdminConnectionCount;         // 0x00883D64








enum { MODE_MASK = 15 };


struct HASHKEY_NONE;

struct D2GameHashLinkStrc;

struct D2GameHashListStrc;


extern "C" const char gszGameSourceFile; // 0x006D5D1C

static unsigned int gnPeakMemoryUsageInLast10s; // 0x00883D48

static unsigned int gnPreviousMemUsageTick; // 0x00883D68


struct D2PoolSystemStrc;








#define EVENTTYPE_DELAYEDPORTAL 11

struct D2InactiveItemNodeStrc;

struct D2InactiveUnitListStrc;


struct D2ObjInitFnStrc;

struct D2UnkPlrMsgStrc;

struct D2ArenaStrc;


enum D2C_MonStatsTxtFlagIndices
{
    MONSTATSFLAGINDEX_INTERACT = 9,
};


extern "C" const char gszQuestsSourceFile[]; // 0x006E0BE4

extern D2UnkPlrMsgStrc gaUnitModeMessages[20]; // 0x007319E8




extern int gnVirtualPlayerCount; // 0x00883D70

void __fastcall D2GAME_SetSkills(int pUnit, int nSkillId, int nSkillLevel, int bRemove); // 0x0056DEB0


#define CLIENTS_MAX_UPDATES 55u

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);



unsigned long gdwLastClientsUpdateTick;                                                                               // 0x00883D5C





extern "C" const char gszSGameDataTypeName[];                                                               // 0x0070F56C










static inline D2GameLinkStrc* GAMELINK_NextLink(D2GameLinkStrc* pLink, int nLinkOffset)
{
    if ((int)pLink->pNext < 0)
        return (D2GameLinkStrc*)~(unsigned int)pLink->pNext;
    if (nLinkOffset < 0)
        nLinkOffset = (char*)pLink - (char*)pLink->pPrevLink->pNext;
    return (D2GameLinkStrc*)((char*)pLink->pNext + nLinkOffset);
}

static inline void GAMELINK_Unlink(D2GameLinkStrc* pLink)
{
    if (pLink->pPrevLink)
    {
        GAMELINK_NextLink(pLink, -1)->pPrevLink = pLink->pPrevLink;
        pLink->pPrevLink->pNext = pLink->pNext;
        pLink->pPrevLink = 0;
        pLink->pNext = 0;
    }
}

// 0x00538E60
void __fastcall CLIENTS_CopySaveDataToClient(D2ClientStrc* ptClient, const void* pData, unsigned int nSize)
{
    D2_ASSERT(ptClient, 2921);

    if (ptClient->nSaveHeaderSize != nSize || ptClient->pSaveHeader)
    {
        if (ptClient->pSaveHeader)
        {
            FOG_FreeServerMemory(ptClient->pGame->pMemoryPool, ptClient->pSaveHeader, ".\\GAME\\Clients.cpp", 2926, 0);
        }

        ptClient->pSaveHeader = (D2SaveHeaderStrc*)sub_0040B430(ptClient->pGame->pMemoryPool, nSize, ".\\GAME\\Clients.cpp", 2928, 0);
        ptClient->nSaveHeaderSize = nSize;
    }

    memcpy(ptClient->pSaveHeader, pData, nSize);
}

#define WARP_ATTEMPT_EXPIRATION_FRAMES 0x8CA

#define NUM_WARP_ATTEMPT_SLOTS 5

static int CLIENTS_IsPlayerUnit_Inlined(D2UnitStrc* pUnit)
{
    return pUnit && pUnit->dwUnitType == UNIT_PLAYER;
}

// 0x00538F10
void __fastcall CLIENTS_FreeSaveHeader(D2ClientStrc* ptClient)
{
    D2_ASSERT(ptClient, 0xB7D);

    if (ptClient->pSaveHeader)
    {
        FOG_FreePool(ptClient->pGame->pMemoryPool, ptClient->pSaveHeader, ".\\GAME\\Clients.cpp", 0xB80, 0);
        ptClient->pSaveHeader = 0;
    }

    ptClient->nSaveHeaderSize = 0;
    ptClient->nSaveHeaderDataSentBytes = 0;
    ptClient->nSaveHeaderSendDelay = 0;
    ptClient->dwFlags &= ~CLIENTFLAGEX_SAVE_LOADED;
}

// 0x00538F80
void __fastcall D2GAME_SetSaveLoadComplete(D2ClientStrc* ptClient)
{
    D2_ASSERT(ptClient, 2961);

    ptClient->nSaveHeaderSendDelay = CLIENT_SAVE_STEP;
    ptClient->nSaveHeaderDataSentBytes = 0;
    ptClient->dwFlags |= CLIENTFLAGEX_SAVE_LOADED;
}

// 0x00538FC0
int __fastcall CLIENTS_HasLoadedSave(D2ClientStrc* ptClient)
{
    D2_ASSERT(ptClient, 2974);

    return (ptClient->dwFlags & CLIENTFLAGEX_SAVE_LOADED) && ptClient->pSaveHeader;
}

// 0x00539000
void __fastcall CLIENTS_SetGameOwner(D2ClientStrc* ptClient)
{
    D2_ASSERT(ptClient, 2991);

    ptClient->dwFlags |= CLIENTFLAGEX_0x20;
}

// 0x00539030
unsigned int __fastcall CLIENT_IsGameOwner(D2ClientStrc* ptClient)
{
    D2_ASSERT(ptClient, 0xBBA);

    return ptClient->bGameOwner;
}

// 0x005390A0
void __fastcall CLIENTS_SetSkillHotKey(D2ClientStrc* pClient, int nHotkeyId, short nSkillId, unsigned char nHand, int nItemGUID)
{
    if (pClient)
    {
        pClient->HotkeySkills[nHotkeyId].nSkill = nSkillId;
        pClient->HotkeySkills[nHotkeyId].nHand = nHand;
        pClient->HotkeySkills[nHotkeyId].nItemGUID = nItemGUID;
    }
}

// 0x005390D0
void __fastcall CLIENTS_GetSkillHotKey(D2ClientStrc* pClient, int nHotkey, int* pSkill, int* pHand, int* pItemGUID)
{
    if (pClient)
    {
        *pSkill = pClient->HotkeySkills[nHotkey].nSkill;
        *pHand = pClient->HotkeySkills[nHotkey].nHand;
        *pItemGUID = pClient->HotkeySkills[nHotkey].nItemGUID;
    }
}

// 0x005391E0
void __fastcall CLIENTS_SetExperienceLoss(D2ClientStrc* pClient, int nExpLoss)
{
    D2_ASSERT(nExpLoss >= 0, 3166);

    pClient->nExpLoss = nExpLoss;
}

// 0x005392A0
D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_PopHead(D2ClientStrc* pClient)
{
    D2PacketDataStrc* pPacketData = pClient->pPacketDataHead;

    if (pClient->pPacketDataTail == pPacketData)
    {
        pClient->pPacketDataTail = 0;
        pClient->pPacketDataHead = 0;
    }

    if (pPacketData)
    {
        pClient->pPacketDataHead = pPacketData->pNext;
    }

    return pPacketData;
}

// 0x005392F0
void __fastcall CLIENTS_CopyAccountNameToBuffer(D2ClientStrc* pClient, char* szAccount)
{
    SStrCopy(szAccount, pClient->szAccount, ACCOUNT_COPY_MAX);
}

// 0x00539320
void __fastcall CLIENTS_SetClientInfo(D2ClientStrc* pClient, D2ClientInfoStrc* pClientInfo)
{
    pClient->pClientInfo = pClientInfo;
}

// 0x00539330
void* __fastcall CLIENTS_GetClientPlayerData(D2ClientStrc* hClient)
{
    D2_ASSERT(hClient, 3344);

    return hClient->clientPlayerData;
}

// 0x00539360
void __fastcall CLIENTS_NotifyWarpAttempt(D2GameStrc* pGame, D2UnitStrc* hUnit)
{
    D2_ASSERT(CLIENTS_IsPlayerUnit_Inlined(hUnit), 0xD1B);

    D2ClientStrc* ptClient = UnitGetClient(hUnit, ".\\GAME\\Clients.cpp", 0xD1D);
    D2_ASSERT(ptClient, 0xD1E);

    for (int i = 0; i < NUM_WARP_ATTEMPT_SLOTS; ++i)
    {
        const int nLastWarpFrame = ptClient->aLastWarpAttemptsFrame[i];
        if (!nLastWarpFrame || (unsigned int)pGame->dwGameFrame - nLastWarpFrame > WARP_ATTEMPT_EXPIRATION_FRAMES)
        {
            ptClient->aLastWarpAttemptsFrame[i] = pGame->dwGameFrame;
            return;
        }
    }
}

// 0x005393F0
int __fastcall CLIENTS_ShouldDelayWarpAttempt(D2GameStrc* pGame, D2UnitStrc* hUnit)
{
    D2_ASSERT(CLIENTS_IsPlayerUnit_Inlined(hUnit), 0xD2D);

    D2ClientStrc* pClient = UnitGetClient(hUnit, ".\\GAME\\Clients.cpp", 0xD2F);
    D2_ASSERT(pClient, 0xD30);

    for (int i = 0; i < NUM_WARP_ATTEMPT_SLOTS; ++i)
    {
        const int nLastWarpFrame = pClient->aLastWarpAttemptsFrame[i];
        if (!nLastWarpFrame || (unsigned int)pGame->dwGameFrame - nLastWarpFrame > WARP_ATTEMPT_EXPIRATION_FRAMES)
        {
            return 0;
        }
    }

    return 1;
}

// 0x00539470
int __fastcall CLIENTS_GetLocale(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 3392);

    return pClient->dwLocale;
}

// 0x005394A0
void __fastcall CLIENTS_SpawnPlayer(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2GameStrc* pGame, D2ActiveRoomStrc* hRoom, int nXArg, int nYArg)
{
    if (!pGame || !pPlayer || !pClient)
    {
        return;
    }

    const unsigned char nAct = CLIENTS_GetActNo(pClient);
    int nX;
    int nY;
    if (!hRoom)
    {
        const int nTownLevelId = DUNGEON_GetTownLevelIdFromAct(pGame->pAct[nAct]);
        hRoom = DUNGEON_FindActSpawnLocationEx(pGame->pAct[nAct], nTownLevelId, 0, &nX, &nY, UNITS_GetUnitSizeX(pPlayer));
        D2_ASSERT(hRoom, 0x1A1);

        D2DrlgCoordsStrc tDrlgCoords;
        DUNGEON_GetRoomCoordinates(hRoom, &tDrlgCoords);
        D2GAME_PACKETS_SendPacket0x07(pClient, DUNGEON_GetLevelIdFromRoom(hRoom), tDrlgCoords.nTileXPos, tDrlgCoords.nTileYPos);
    }
    else
    {
        nX = nXArg;
        nY = nYArg;
    }

    CLIENTS_SetRoomInClient(pClient, hRoom);
    SUNIT_Add(pPlayer, nX, nY, pGame, hRoom, 0);
    pClient->dwFlags &= ~1;
    const int nUnitGUID = pPlayer->dwUnitId;
    const int nUnitType = (pPlayer ? pPlayer->dwUnitType : UNIT_INVALID);
    D2GAME_PACKETS_SendPacket0x15(pClient, 0x15, nUnitType, nUnitGUID, nX, nY, 1);
    D2GAME_PACKETS_SendPacket0x7E(pClient, pGame->dwMonSeed);

    D2CorpseStrc* pCorpse = INVENTORY_GetFirstCorpse(pPlayer->pInventory);
    while (pCorpse)
    {
        const int nCorpseGUID = INVENTORY_GetUnitGUIDFromCorpse(pCorpse);
        if (!INVENTORY_IsPlayerCorpse(pCorpse))
        {
            const unsigned short wName = INVENTORY_GetCorpseMercNameId(pCorpse);
            pCorpse = INVENTORY_GetNextCorpse(pCorpse);
            INVENTORY_FreeCorpse(pPlayer->pInventory, nCorpseGUID, 0);
            if (nCorpseGUID && wName)
            {
                D2GAME_MERCS_Create(pGame, pPlayer, wName, nCorpseGUID, 0xFFFF, 0, 0);
            }
        }
        else
        {
            D2UnitStrc* pCorpsePlayer = SUNIT_GetServerUnit(pGame, 0, nCorpseGUID);
            if (pCorpsePlayer)
            {
                const int nTownLevelId = DUNGEON_GetTownLevelIdFromActNo(nAct);
                int nCorpseX = 0;
                int nCorpseY = 0;
                D2ActiveRoomStrc* pSpawnRoom = DUNGEON_FindActSpawnLocationEx(pGame->pAct[nAct], nTownLevelId, 0, &nCorpseX, &nCorpseY, UNITS_GetUnitSizeX(pCorpsePlayer));
                D2CoordStrc tCoord;
                tCoord.nX = nCorpseX;
                tCoord.nY = nCorpseY;
                PLAYER_PlaceCorpse(pGame, pSpawnRoom, nCorpseGUID, &tCoord);
            }

            pCorpse = INVENTORY_GetNextCorpse(pCorpse);
        }
    }

    SUNITNPC_UpdateHirelingPosition(pGame, pPlayer);

    const int nIronGolemItemGUID = pClient->nIronGolemItemGUID;
    if (nIronGolemItemGUID && nIronGolemItemGUID != -1)
    {
        D2UnitStrc* pIronGolemItem = SUNIT_GetServerUnit(pGame, 4, nIronGolemItemGUID);
        if (pIronGolemItem)
        {
            D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pPlayer, SKILL_IRONGOLEM);
            if (pSkill)
            {
                const int nSkillLevel = SKILLS_GetSkillLevel(pPlayer, pSkill, 1);
                UNITS_SetXForStaticUnit(pIronGolemItem, CLIENTS_GetUnitX(pPlayer));
                UNITS_SetYForStaticUnit(pIronGolemItem, CLIENTS_GetUnitY(pPlayer));
                UNITS_SetTargetUnitForDynamicUnit(pPlayer, pIronGolemItem);
                SKILLS_ExecuteSkill(pGame, pPlayer, SKILL_IRONGOLEM, nSkillLevel, 1, 0, 0);
            }
        }

        pClient->nIronGolemItemGUID = -1;
    }
}

// 0x00538670
int __fastcall CLIENTS_CheckFlag(D2ClientStrc* pClient, unsigned short nFlag)
{
    return pClient->nSaveFlags & nFlag;
}


// 0x00539760
int __fastcall ClientAddPlayerToGame(D2ClientStrc* ptClient, D2GameStrc* ptGame, int bLoadFromSave, D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    D2UnitStrc* pPlayer = 0;
    D2_ASSERT(ptGame, 0x23F);
    D2_ASSERT(ptClient, 0x242);
    ptClient->dwFlags |= 1;
    if (!ptGame->bExpansion && ptClient->nClassId >= 5)
    {
        LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "[PLAYER CREATE]  ClientAddPlayerToGame()  Error Creating:%s  Error:%d=%s", CLIENTS_GetName(ptClient), 0x18, "nError");
        ptClient->pPlayer = 0;
        return 0x18;
    }
    const int nError = D2GAME_SAVE_GetUnitDataFromFile(ptGame, ptClient, ptClient->szName, bLoadFromSave, &pPlayer, pRoom, nX, nY);
    if (nError)
    {
        LOGMANAGER_LogWritePrefixedLine(&gszEmptyAssertText, "[PLAYER LOAD]  ClientAddPlayerToGame()  Error Loading:%s  Error:%d=%s", CLIENTS_GetName(ptClient), nError, "nError");
        ptClient->pPlayer = 0;
        return nError;
    }
    if (ptClient->nSaveFlags & 0x20)
    {
        if (!ptGame->bExpansion)
        {
            ptClient->pPlayer = 0;
            return 0x18;
        }
    }
    else if (ptGame->bExpansion)
    {
        ptClient->pPlayer = 0;
        return 0x17;
    }
    if (ptClient->nSaveFlags & 4)
    {
        if (ptClient->nSaveFlags & 8)
        {
            ptClient->pPlayer = 0;
            return 0x15;
        }
        if (!(ARENA_GetFlags(ptGame) & 0x800))
        {
            ptClient->pPlayer = 0;
            return 0x14;
        }
    }
    else if (ARENA_GetFlags(ptGame) & 0x800)
    {
        ptClient->pPlayer = 0;
        return 0x13;
    }
    CLIENTS_SendPlayerAssign(ptClient, pPlayer);
    D2GAME_SendPacketSize05(ptClient, 0x5F, UNITS_GetPlayerPortalFlags(pPlayer));
    D2Common_10513(pPlayer, pPlayer, D2GAME_UpdateAttribute);
    if (ITEMS_CheckUnitFlagEx(pPlayer, 1))
    {
        D2GAME_INVMODE_First(ptGame, pPlayer, ptClient, 0);
        if (pPlayer)
        {
            pPlayer->dwFlagEx |= 0x200000;
        }
    }
    for (int i = 0; i < 16; ++i)
    {
        if (ptClient->HotkeySkills[i].nSkill >= 0 && ptClient->HotkeySkills[i].nSkill < sgptDataTables->nSkillsTxtRecordCount)
        {
            D2GAME_PACKETS_SendPacket0x7B(ptClient, i, ptClient->HotkeySkills[i].nSkill, ptClient->HotkeySkills[i].nHand, ptClient->HotkeySkills[i].nItemGUID);
        }
    }
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (pPlayerData)
    {
        D2GAME_PACKETS_SendPacket0x23(ptClient, !pPlayer ? UNIT_INVALID : pPlayer->dwUnitType, !pPlayer ? -1 : pPlayer->dwUnitId, 1, (unsigned short)pPlayerData->nLeftSkillId, pPlayerData->nLeftSkillFlags);
        D2GAME_PACKETS_SendPacket0x23(ptClient, !pPlayer ? UNIT_INVALID : pPlayer->dwUnitType, !pPlayer ? 0xFFFFFFFFu : (unsigned int)pPlayer->dwUnitId, 0, (unsigned short)pPlayerData->nRightSkillId, pPlayerData->nRightSkillFlags);
    }
    D2Common_10513(pPlayer, pPlayer, D2GAME_UpdateAttribute);
    PLRMSG_SendPlayerStatUpdates(pPlayer, pPlayer, 1);
    D2GAME_INVMODE_Last(ptGame, pPlayer);
    if (ptGame->bExpansion)
    {
        ACT5Q3_ApplyResistanceReward(ptGame, pPlayer);
    }
    return 0;
}

// 0x00539A30
D2ClientStrc* __fastcall ClientAddToGame(D2GameStrc* pGame, int nClientId, unsigned char nClassIdOrCharTemplate, const char* szClientName, const char* szAccount, int nCharSaveTransactionToken, unsigned char nLocale, int nUnused1, int nUnused2)
{
    if (!gbClientListInitialized || !pGame)
    {
        return 0;
    }

    if (pGame->nClients >= 8)
    {
        return 0;
    }

    D2ClientStrc* pClient = (D2ClientStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2ClientStrc), ".\\GAME\\Clients.cpp", 0x347, 0);
    memset(pClient, 0, sizeof(D2ClientStrc));

    pClient->dwClientId = nClientId;
    pClient->dwLastPacketTick = GetTickCount() + 180000;
    pClient->pGame = pGame;

    if (ARENA_ShouldTreatClassIdAsTemplateId(pGame))
    {
        pClient->nCharTemplate = nClassIdOrCharTemplate;
        pClient->nClassId = DATATBLS_GetClassFromCharTemplateTxtRecord(nClassIdOrCharTemplate, ARENA_GetTemplateType(pGame));
    }
    else
    {
        pClient->nClassId = nClassIdOrCharTemplate;
    }

    SStrCopy(pClient->szName, szClientName, 0x7FFFFFFF);
    SStrCopy(pClient->szAccount, szAccount, 0x7FFFFFFF);

    pClient->nCharSaveTransactionToken = nCharSaveTransactionToken;
    pClient->pClientInfo = 0;
    pClient->dwLocale = nLocale;
    pClient->dwClientState = 0;
    pClient->pPacketDataHead = 0;
    pClient->pPacketDataTail = 0;
    pClient->pPacketDataPool = 0;

    for (int i = 0; i < 16; ++i)
    {
        pClient->HotkeySkills[i].nSkill = -1;
        pClient->HotkeySkills[i].nHand = 0;
        pClient->HotkeySkills[i].nItemGUID = -1;
    }

    pClient->pNext = pGame->pClientList;
    pGame->pClientList = pClient;

    const int nClientIndex = nClientId & 0xFF;
    EnterCriticalSection(&gClientListLock);
    pClient->pServerNext = gpClientList[nClientIndex];
    gpClientList[nClientIndex] = pClient;
    LeaveCriticalSection(&gClientListLock);

    const int nIndex = FOG_ComputeStringCRC16(szClientName) & 0xFF;

    EnterCriticalSection(&gSrvClientListByNameLock);
    pClient->pServerNextByName = gpClientListByName[nIndex];
    gpClientListByName[nIndex] = pClient;
    LeaveCriticalSection(&gSrvClientListByNameLock);

    ++pGame->nClients;

    return pClient;
}

// 0x00539BE0
void __fastcall CLIENTS_FillCharacterPreviewInfo(D2ClientStrc* pClient, char* szInfo)
{
    FOG_Encode14BitsToString((unsigned char*)szInfo, PREVIEW_VERSION);
    D2CharacterPreviewRecordStrc* pPreview = (D2CharacterPreviewRecordStrc*)(szInfo + 2);
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (pPlayer)
    {
        unsigned char aColors[16];
        unsigned char aComponents[16];
        unsigned char aGfx[16];
        const unsigned char nLevel = (unsigned char)STATLIST_UnitGetStatValue(pPlayer, STAT_LEVEL, 0);
        const unsigned int nClassId = pPlayer->dwClassId;

        memset(aComponents, 0xFF, sizeof(aComponents));
        sub_0063E510_FillInventoryTables(pPlayer, aComponents, aGfx);
        SMemCopy(pPreview->pComponents, aComponents, PREVIEW_COPY_SIZE);
        pPreview->nClass = (unsigned char)nClassId < NUMBER_OF_PLAYERCLASSES ? (unsigned char)nClassId + 1 : 1;

        memset(aColors, 0xFF, sizeof(aColors));
        sub_0063E510_FillInventoryTables(pPlayer, aGfx, aColors);
        for (int i = 0; i < 16; ++i)
        {
            if (!aColors[i])
            {
                aColors[i] = 0xFF;
            }
        }
        SMemCopy(pPreview->pComponentColors, aColors, PREVIEW_COPY_SIZE);

        const unsigned char nLevelIndex = nLevel - 1;
        pPreview->nLevel = nLevelIndex <= PREVIEW_MAX_LEVEL_INDEX ? nLevel : 1;

        const unsigned int nMode = pPlayer->dwAnimMode;
        const unsigned short wSaveFlags = pClient->nSaveFlags;
        unsigned int nFlags = wSaveFlags;
        if ((nMode == PLRMODE_DEAD || nMode == PLRMODE_DEATH) && (wSaveFlags & CLIENTSAVEFLAG_HARDCORE))
        {
            nFlags |= CLIENTSAVEFLAG_DEAD;
        }
        else
        {
            nFlags &= 0xFFF7;
        }
        FOG_Encode14BitsToString(pPreview->nClientFlags, nFlags);
        FOG_Encode14BitsToString(pPreview->nGuildFlags, pClient->nGuildFlags);

        unsigned char nBgColor = pClient->nGuildBgColor;
        unsigned char nFgColor = pClient->nGuildFgColor;
        unsigned char nEmblem = pClient->nGuildEmblem;
        if (!nBgColor)
        {
            nBgColor = 0xFF;
        }
        if (!nFgColor)
        {
            nFgColor = 0xFF;
        }
        if (!nEmblem)
        {
            nEmblem = 0xFF;
        }
        pPreview->nGuildBgColor = nBgColor;
        pPreview->nGuildFgColor = nFgColor;
        pPreview->nGuildEmblem = nEmblem;
        pPreview->dwGuildTag = pClient->dwGuildTag;

        const int bBadLevel = nLevelIndex > PREVIEW_MAX_LEVEL_INDEX;
        const int bBadClass = (unsigned char)nClassId >= NUMBER_OF_PLAYERCLASSES;
        const int bBadFlags = (nFlags & CLIENTSAVEFLAG_INVALID_1) || (nFlags & CLIENTSAVEFLAG_INVALID_2) || (nFlags & CLIENTSAVEFLAG_INVALID_10);
        const int bBadLength = SStrLen(szInfo) != PREVIEW_STRING_LENGTH;
        if (bBadLevel || bBadClass || bBadFlags || bBadLength)
        {
            *szInfo = 0;
        }
    }
}

extern const char szClientsCppFile[]; // 0x006E0A48

void __fastcall GAME_TriggerClientSave(D2ClientStrc*,D2GameStrc*); // 0x0052C900

void __fastcall GAME_SendPacket0x5CToAllConnectedClients(D2GameStrc*,D2ClientStrc*); // 0x0052C500


void __fastcall SUNITPROXY_OnClientRemovedFromGame(D2GameStrc*,D2UnitStrc*); // 0x00537580


static __forceinline void CLIENTS_UnlinkId(int nClientId,char* szName)
{
 const int nIndex=nClientId & 0xFF;
 if(gbClientListInitialized) {
  EnterCriticalSection(&gClientListLock);
  D2ClientStrc* pCurrent=gpClientList[nIndex];
  if(pCurrent) {
   if(pCurrent->dwClientId==nClientId) { strcpy(szName,pCurrent->szName);gpClientList[nIndex]=pCurrent->pServerNext; }
   else {
    D2ClientStrc* pPrevious=gpClientList[nIndex];
    while(pPrevious->pServerNext->dwClientId!=nClientId) pPrevious=pPrevious->pServerNext;
    D2_ASSERT(pPrevious->pServerNext,0x4EF);
    strcpy(szName,pPrevious->pServerNext->szName);
    pPrevious->pServerNext=pPrevious->pServerNext->pServerNext;
   }
  }
  LeaveCriticalSection(&gClientListLock);
 }
}

static __forceinline void CLIENTS_UnlinkName(char* szName)
{
 if(gbClientListInitialized) {
  const int nNameIndex=FOG_ComputeStringCRC16(szName)&0xFF;
  EnterCriticalSection(&gSrvClientListByNameLock);
  if(gpClientListByName[nNameIndex]) {
   if(!SStrCmpI(gpClientListByName[nNameIndex]->szName,szName,16)) gpClientListByName[nNameIndex]=gpClientListByName[nNameIndex]->pServerNextByName;
   else {
    D2ClientStrc* pName=gpClientListByName[nNameIndex];
    D2_ASSERT(pName->pServerNextByName,0x526);
    while(SStrCmpI(pName->pServerNextByName->szName,szName,16)) { pName=pName->pServerNextByName; if(!pName->pServerNextByName) break; }
    if(pName->pServerNextByName) pName->pServerNextByName=pName->pServerNextByName->pServerNextByName;
   }
  }
  LeaveCriticalSection(&gSrvClientListByNameLock);
 }
}

// 0x00539DA0
void __fastcall ClientRemoveFromGame(D2GameStrc* ptGame,void* hClientId,int bTriggerSave)
{
 D2_ASSERT(ptGame,0x49F);
 D2ClientStrc* pClient=CLIENTS_GetClientFromClientId(ptGame,(int)hClientId);
 if(pClient) CLIENTS_FillCharacterPreviewInfo(pClient,pClient->szPreview);
 if(bTriggerSave==1) GAME_TriggerClientSave(CLIENTS_GetClientFromClientId(ptGame,(int)hClientId),ptGame);
 char szName[16]; szName[0]=0;
 CLIENTS_UnlinkId((int)hClientId,szName);
 pClient=0;
 D2ClientStrc* pCurrent=ptGame->pClientList;
 if(pCurrent) {
  if(pCurrent->dwClientId==(int)hClientId) { pClient=pCurrent;ptGame->pClientList=pCurrent->pNext; }
  else {
   while(pCurrent->pNext && pCurrent->pNext->dwClientId!=(int)hClientId) pCurrent=pCurrent->pNext;
   if(pCurrent->pNext) { pClient=pCurrent->pNext;pCurrent->pNext=pClient->pNext; }
  }
 }
 CLIENTS_UnlinkName(szName);
 if(!pClient) return;
 GAME_SendPacket0x5CToAllConnectedClients(ptGame,pClient);
 D2UnitStrc* pPlayer=CLIENTS_GetPlayerFromClient(pClient,0);
 if(pPlayer) {
  const __int64 nExperience=STATLIST_GetUnitBaseStat(pPlayer,STAT_EXPERIENCE,0);
  const int nClassId=pPlayer->dwClassId;
  const int nLevel=(unsigned short)STATLIST_GetUnitBaseStat(pPlayer,STAT_LEVEL,0);
  PARTY_LeaveParty(ptGame,pPlayer);
  PLAYERPETS_FreePetsFromPlayerData(ptGame,pPlayer);
  SUNITPROXY_OnClientRemovedFromGame(ptGame,pPlayer);
  QUESTS_PlayerDroppedWithQuestItem(ptGame,pPlayer);
  PLRTRADE_StopAllPlayerInteractions(ptGame,pPlayer);
  D2ActiveRoomStrc* pRoom=UNITS_GetRoom(pPlayer);
  if(pRoom) DUNGEON_AllocDrlgDelete(pRoom,!pPlayer ? 6 : pPlayer->dwUnitType,!pPlayer ? -1 : pPlayer->dwUnitId);
  SUNIT_RemoveUnit(pClient->pGame,pPlayer);
  DUNGEON_ChangeClientRoom(pRoom,0);
  D2Common_10077(pRoom,0);
  if(gpD2EventCallbackTable) {
   D2_ASSERT(!IsBadCodePtr((FARPROC)gpD2EventCallbackTable->pfLeaveGame),0x5A6);
   if(gpD2EventCallbackTable->pfLeaveGame) gpD2EventCallbackTable->pfLeaveGame(&pClient->pClientInfo,ptGame->nGameId,nClassId,nLevel,nExperience,pClient->nSaveFlags,pClient->szName,pClient->szPreview,pClient->bUnlockCharacter,0,0,pClient->szAccount,pClient->nCharSaveTransactionToken,0,0,0,0,0,&pClient->nSaveCreationTimestamp);
  }
 } else if(gpD2EventCallbackTable) {
  pClient->szPreview[0]=0;
  D2_ASSERT(!IsBadCodePtr((FARPROC)gpD2EventCallbackTable->pfLeaveGame),0x5CE);
  if(gpD2EventCallbackTable->pfLeaveGame) gpD2EventCallbackTable->pfLeaveGame(&pClient->pClientInfo,ptGame->nGameId,0,0,0,0,pClient->szName,pClient->szPreview,pClient->bUnlockCharacter,0,0,pClient->szAccount,pClient->nCharSaveTransactionToken,0,0,0,0,0,&pClient->nSaveCreationTimestamp);
 }
 if(pClient->hRoom) LEVEL_RemoveClientFromAdjacentRooms(pClient->hRoom,pClient);
 if(pClient->pSaveHeader) {
  FOG_FreePool(pClient->pGame->pMemoryPool,pClient->pSaveHeader,szClientsCppFile,0x5F5,0);
  pClient->pSaveHeader=0;
 }
 while(pClient->pPacketDataPool) {
  D2PacketDataStrc* pPacket=pClient->pPacketDataPool;
  pClient->pPacketDataPool=pPacket->pNext;
  FOG_FreePool(0,pPacket,szClientsCppFile,0x605,0);
 }
 FOG_FreePool(pClient->pGame->pMemoryPool,pClient,szClientsCppFile,0x608,0);
 --ptGame->nClients;
}

// 0x0053A280
D2UnitStrc* __fastcall CLIENTS_GetDeadTargetUnit(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 0x7B9);

    if (!(pClient->dwFlags & 2))
    {
        return 0;
    }

    D2UnitStrc* pUnit = SUNIT_GetServerUnit(pGame, pClient->nDeadTargetType, pClient->nDeadTargetGUID);
    if (pUnit)
    {
        if (CLIENTS_IsInUnitsRoom(pUnit, pClient))
        {
            return pUnit;
        }
        pUnit = 0;
    }
    pClient->dwFlags &= ~2;
    return pUnit;
}

// 0x0053A2F0
void __fastcall CLIENTS_ResetClientInAct(D2ClientStrc* pClient, int nAct)
{
    D2_ASSERT(pClient, 2386);
    pClient->nClassId = nAct;
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    pClient->nClassId = nAct;
    const int nX = M08_UNITS_GetXPositionInline(pPlayer);
    const int nY = M08_UNITS_GetYPositionInline(pPlayer);
    D2GameStrc* pGame = pClient->pGame;
    sub_M08_RemoveUnitFromRoom(pGame, pPlayer);
    ClientAddPlayerToGame(pClient, pGame, 0, pRoom, nX, nY);
    CLIENTS_SpawnPlayer(pClient, pClient->pPlayer, pGame, pRoom, nX, nY);
    pClient->dwFlags &= ~CLIENTFLAGEX_PLAYER_UNIT_ALIVE;
    if (pRoom != pClient->hRoom)
    {
        CLIENTS_ChangeRoom(pRoom, pClient);
    }
    pClient->hRoom = pRoom;
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

// 0x0053A420
void __fastcall CLIENTS_RebuildPlayerWithClass(D2GameStrc* pGame, D2ClientStrc* pClient, unsigned char nClassId)
{
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    pClient->nClassId = nClassId;
    const int nX = CLIENTS_GetUnitXInline(pPlayer);
    const int nY = CLIENTS_GetUnitYInline(pPlayer);
    const int nUnitId = pPlayer->dwUnitId;
    const int nUnitType = pPlayer->dwUnitType;
    DUNGEON_AllocDrlgDelete(UNITS_GetRoom(pPlayer), nUnitType, nUnitId);
    SUNIT_RemoveUnit(pGame, pPlayer);
    ClientAddPlayerToGame(pClient, pGame, 0, pRoom, nX, nY);
    D2UnitStrc* pClientPlayer = pClient->pPlayer;
    CLIENTS_SpawnPlayer(pClient, pClientPlayer, pGame, pRoom, nX, nY);
}

// 0x00540890
int __fastcall CLIENTS_SumLivingPartyLevelsInSameLevel(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    int nLevelSum = 0;
    if (SUNIT_GetPartyId(pUnit) == -1)
    {
        return STATLIST_UnitGetStatValue(pUnit, STAT_LEVEL, 0);
    }

    PARTY_IteratePartyMembersInSameLevel(pGame, pUnit, PARTY_AddLivingMemberLevelCallback, &nLevelSum);
    return nLevelSum;
}

// 0x00541830
void __fastcall SKILLS_SetMonsterComponent(D2UnitStrc* pUnit, unsigned char nComponent, unsigned char nValue)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && nComponent < MONSTER_COMPONENT_COUNT && pUnit->pMonsterData)
    {
        pUnit->pMonsterData->nComponent[nComponent] = nValue;
    }
}

// 0x00538650
extern "C" __declspec(dllexport) void __fastcall CLIENTS_ToggleFlag(D2ClientStrc* pClient, unsigned short wMask, int bSet)
{
    if (bSet)
    {
        pClient->nSaveFlags |= wMask;
    }
    else
    {
        pClient->nSaveFlags &= ~wMask;
    }
}

// 0x00538680
void __fastcall CLIENTS_UpdateCharacterProgression(D2ClientStrc* pClient, int nAct, int nDifficulty)
{
    int nActsPerDifficulty;
    if (pClient->tSaveFlags.bExpansion)
    {
        nActsPerDifficulty = 5;
    }
    else
    {
        nActsPerDifficulty = 4;
    }

    const int nNewActDifficulty = nAct + nDifficulty * nActsPerDifficulty;
    if (nNewActDifficulty >= pClient->tSaveFlags.nProgression)
    {
        unsigned short* pPackedValue = &pClient->nSaveFlags;
        *pPackedValue = (*pPackedValue & 0xE0FF) | ((unsigned short)(nDifficulty * nActsPerDifficulty + nAct) << 8);
    }
}

// 0x00538730
int __fastcall CLIENTS_GetIronGolemItemGUID(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 0x989);
    return pClient->nIronGolemItemGUID;
}

// 0x00538860
void __fastcall CLIENTS_SetArenaFlag(D2ClientStrc* pClient, int bSet)
{
    D2_ASSERT(pClient, 0x9F7);
    if (bSet)
    {
        if (!(pClient->dwFlags & CLIENTFLAGEX_ARENA_RELATED))
            ARENA_SendScoresToClient(pClient->pGame, pClient);
        pClient->dwFlags |= CLIENTFLAGEX_ARENA_RELATED;
    }
    else
    {
        pClient->dwFlags &= ~CLIENTFLAGEX_ARENA_RELATED;
    }
}

// 0x005388C0
unsigned int __fastcall CLIENTS_HasArenaFlag(D2ClientStrc* ptClient)
{
    D2_ASSERT(ptClient, 0xA05);
    return ptClient->bArena;
}

// 0x00538900
unsigned char __fastcall CLIENTS_GetCharTemplate(D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 0xA11);
    return pClient->nCharTemplate;
}

// 0x00538930
int __fastcall CLIENTS_CheckState(int nClientId, int nExpectedClientState)
{
    if (!gbClientListInitialized)
    {
        return 0;
    }

    int bResult = 0;
    EnterCriticalSection(&gClientListLock);
    for (D2ClientStrc* pClient = gpClientList[nClientId & 0xFF]; pClient; pClient = pClient->pServerNext)
    {
        if (pClient->dwClientId == nClientId)
        {
            bResult = pClient->dwClientState == nExpectedClientState;
            break;
        }
    }
    LeaveCriticalSection(&gClientListLock);
    return bResult;
}

// 0x00538BF0
int __fastcall CLIENTS_GetClientIdByName(const char* szName)
{
    int nClientId = 0;
    const int nIndex = FOG_ComputeStringCRC16(szName) & 0xFF;

    EnterCriticalSection(&gSrvClientListByNameLock);

    for (D2ClientStrc* pClient = gpClientListByName[nIndex]; pClient; pClient = pClient->pServerNextByName)
    {
        if (nClientId)
        {
            break;
        }

        if (!SStrCmpI(pClient->szName, szName, 16))
        {
            nClientId = pClient->dwClientId;
        }
    }

    LeaveCriticalSection(&gSrvClientListByNameLock);
    return nClientId;
}

// 0x00538C60
int __fastcall CLIENTS_GetCanonicalName(const char* szName, char* szGameName)
{
    int result = 1;
    const int nIndex = FOG_ComputeStringCRC16(szName) & 0xFF;
    EnterCriticalSection(&gSrvClientListByNameLock);

    for (D2ClientStrc* pClient = gpClientListByName[nIndex]; pClient; pClient = pClient->pServerNextByName)
    {
        if (!SStrCmpI(pClient->szName, szName, sizeof(pClient->szName)))
        {
            if (szGameName)
            {
                SStrCopy(szGameName, pClient->szName, sizeof(pClient->szName));
            }

            result = 0;
            break;
        }
    }

    LeaveCriticalSection(&gSrvClientListByNameLock);
    return result;
}

// 0x00539070
extern "C" __declspec(dllexport) D2ClientStrc* __fastcall CLIENTS_GetFirstClient(D2GameStrc* pGame)
{
    return pGame->pClientList;
}

// 0x00539080
extern "C" __declspec(dllexport) D2ClientStrc* __fastcall CLIENTS_GetNext(D2ClientStrc* pClient)
{
    return pClient->pNext;
}

// 0x00539090
int __fastcall CLIENTS_GetClientState(D2ClientStrc* pClient)
{
    return pClient->dwClientState;
}

// 0x00539110
extern "C" __declspec(dllexport) unsigned short __fastcall CLIENTS_GetGuildFlags(D2ClientStrc* pClient)
{
    return pClient->nGuildFlags;
}

// 0x00539120
extern "C" __declspec(dllexport) void __fastcall CLIENTS_SetGuildFlags(D2ClientStrc* pClient, unsigned short nGuildFlags)
{
    pClient->nGuildFlags = nGuildFlags;
}

// 0x00539130
extern "C" __declspec(dllexport) void __fastcall CLIENTS_GetGuildTag(D2ClientStrc* pClient, unsigned int* pGuildTag)
{
    *pGuildTag = pClient->dwGuildTag;
}

// 0x00539140
extern "C" __declspec(dllexport) void __fastcall CLIENTS_SetGuildTag(D2ClientStrc* pClient, const unsigned int* pGuildTag)
{
    pClient->dwGuildTag = *pGuildTag;
}

// 0x00539150
extern "C" __declspec(dllexport) void __fastcall CLIENTS_GetGuildName(D2ClientStrc* pClient, char* szGuildName)
{
    strcpy(szGuildName, pClient->szGuildName);
}

// 0x00539170
extern "C" __declspec(dllexport) void __fastcall CLIENTS_SetGuildName(D2ClientStrc* pClient, const char* szGuildName)
{
    strcpy(pClient->szGuildName, szGuildName);
}

// 0x00539190
extern "C" __declspec(dllexport) void __fastcall CLIENTS_GetGuildEmblem(D2ClientStrc* pClient, unsigned char* pBgColor, unsigned char* pFgColor, unsigned char* pEmblem)
{
    *pBgColor = pClient->nGuildBgColor;
    *pFgColor = pClient->nGuildFgColor;
    *pEmblem = pClient->nGuildEmblem;
}

// 0x005391C0
extern "C" __declspec(dllexport) void __fastcall CLIENTS_SetGuildEmblem(D2ClientStrc* pClient, unsigned char nBgColor, unsigned char nFgColor, unsigned char nEmblem)
{
    pClient->nGuildBgColor = nBgColor;
    pClient->nGuildFgColor = nFgColor;
    pClient->nGuildEmblem = nEmblem;
}

// 0x00539210
extern "C" __declspec(dllexport) int __fastcall CLIENTS_GetExperienceLoss(D2ClientStrc* pClient)
{
    return pClient->nExpLoss;
}

// 0x00539220
extern "C" __declspec(dllexport) unsigned char __fastcall CLIENTS_GetWeaponSwitch(D2ClientStrc* pClient)
{
    return pClient->bSwitchWeapon;
}

inline void W11_InlineFixRoomUnits(D2ActiveRoomStrc* pRoom, D2ClientStrc* pClient)
{
    D2_ASSERT(pRoom, 0x62);
    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->ptRoomNext)
        SUNIT_UpdateClientIfRoomInvalid(pUnit, pClient);
}

// 0x00539230
extern "C" __declspec(dllexport) void __fastcall CLIENTS_SetWeaponSwitch(D2ClientStrc* pClient, unsigned char bSwitchWeapon)
{
    pClient->bSwitchWeapon = bSwitchWeapon;
}

// 0x00539240
void __fastcall CLIENTS_PacketDataList_Append(D2ClientStrc* pClient, D2PacketDataStrc* pPacketData)
{
    pPacketData->pNext = 0;

    if (!pClient->pPacketDataTail)
    {
        pClient->pPacketDataHead = pPacketData;
        pClient->pPacketDataTail = pPacketData;
    }
    else
    {
        pClient->pPacketDataTail->pNext = pPacketData;
        pClient->pPacketDataTail = pPacketData;
    }
}

// 0x00539270
void __fastcall CLIENTS_PacketDataList_Reset(D2ClientStrc* pClient, D2PacketDataStrc* pSinglePacketData)
{
    pSinglePacketData->pNext = 0;

    if (!pClient->pPacketDataHead)
    {
        pSinglePacketData->pNext = 0;
        pClient->pPacketDataHead = pSinglePacketData;
    }
    else
    {
        pClient->pPacketDataTail = pSinglePacketData;
        pClient->pPacketDataHead = pSinglePacketData;
    }
}

// 0x005392D0
extern "C" __declspec(dllexport) D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetTail(D2ClientStrc* pClient)
{
    return pClient->pPacketDataTail;
}

// 0x005392E0
extern "C" __declspec(dllexport) D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetHead(D2ClientStrc* pClient)
{
    return pClient->pPacketDataHead;
}

// 0x00539300
extern "C" __declspec(dllexport) void __fastcall CLIENTS_GetCharSaveTransactionToken(D2ClientStrc* pClient, int* pToken)
{
    *pToken = pClient->nCharSaveTransactionToken;
}

// 0x00539310
extern "C" __declspec(dllexport) void __fastcall CLIENTS_GetClientInfo(D2ClientStrc* pClient, D2ClientInfoStrc** ppClientInfo)
{
    *ppClientInfo = pClient->pClientInfo;
}

