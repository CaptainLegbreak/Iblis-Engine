#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameServer.h"
#include "D2GameStrc.h"
#include "D2ItemsWorld.h"
#include "D2LevelTxt.h"
#include "D2TxtItems.h"
#include "D2MonsterIds.h"
#include "D2StatIds.h"
#include "D2PlayerModes.h"
#include "D2ObjModes.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Drlg.h"
#include "D2GameClient.h"
#include "D2Unicode.h"
#include "D2StormLink.h"
#include "D2Primitives.h"
#include "D2DrlgRooms.h"
#include "D2Constants.h"
#include "D2Path.h"
#include "D2UnitData.h"
#include "D2InactiveUnits.h"
#include "D2GameRecords.h"
#include "D2QuestData.h"
#include "D2ObjectIds.h"
#include "D2LevelIds.h"
#include "D2ItemModes.h"
#include "D2GameObjs.h"
#include "D2Packets.h"
#include "D2LanguageNames.h"
// build: symbol _gaszLanguageNames 0x0073192C

union D2SeedStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* text, const char* file, int line); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
void* __fastcall FOG_AllocPool(void* pPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
D2LevelsTxt* __stdcall DATATBLS_GetLevelsTxtRecord(int nLevelId); // 0x0061DB70
int __cdecl DATATBLS_GetShrinesTxtRecordCount(); // 0x00641500
void __fastcall SEED_InitSeed(D2SeedStrc* pSeed); // 0x00650E30
void __fastcall SEED_InitLowSeed(D2SeedStrc* pSeed, unsigned int nLowSeed); // 0x00650E40


void __fastcall D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(D2ClientStrc* pClient, D2GSPacketSrv26* pPacket); // 0x0053C750
extern "C" char* __cdecl strcpy(char* pDestination, const char* pSource);

typedef void (__fastcall* GAME_ForEachIngameClientCallbackPtr)(D2ClientStrc*, void*);

extern void __fastcall GAME_ForEachIngameClient(D2GameStrc* pGame, GAME_ForEachIngameClientCallbackPtr pFn, void* pContext); // 0x0052DED0
extern void __fastcall OBJRGN_SendServerMessageCallback(D2ClientStrc* pClient, void* pContext); // 0x00546FE0

inline unsigned __int64 OBJECTS_RollGameSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 seed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(seed >> 32);
    pSeed->nLowSeed = (unsigned int)seed;
    return seed;
}

// 0x00546C60
unsigned int __fastcall OBJRGN_AllocObjectControl(D2GameStrc* ptGame)
{
    if (!ptGame)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 41);
        exit(-1);
    }
    D2ObjectControlStrc* pControl = (D2ObjectControlStrc*)FOG_AllocPool(ptGame->pMemoryPool, sizeof(D2ObjectControlStrc), ".\\OBJECTS\\objrgn.cpp", 42, 0);
    ptGame->pObjectControl = pControl;
    SEED_InitSeed(&pControl->pSeed);
    const unsigned int nSeed = (unsigned int)OBJECTS_RollGameSeed(&ptGame->pGameSeed);
    SEED_InitLowSeed(&pControl->pSeed, nSeed);
    pControl->pObjectRegion[0] = 0;
    pControl->pObjectRoomCoord = 0;
    for (int i = 1; i < sgptDataTables->nLevelsTxtRecordCount; i += 1)
    {
        D2ObjectRegionStrc* pRegion = (D2ObjectRegionStrc*)FOG_AllocPool(ptGame->pMemoryPool, sizeof(D2ObjectRegionStrc), ".\\OBJECTS\\objrgn.cpp", 54, 0);
        D2LevelsTxt* pLevelsTxt = DATATBLS_GetLevelsTxtRecord(i);
        memset(pRegion, 0, sizeof(D2ObjectRegionStrc));
        pRegion->nTrapMonsterId = -1;
        pRegion->nAct = pLevelsTxt->nAct;
        pRegion->nPopulatedRooms = 0x7FFFFFFF;
        pControl->pObjectRegion[i] = pRegion;
    }
    const int nShrines = DATATBLS_GetShrinesTxtRecordCount();
    int nClassCounts[8] = {};
    for (int i = 0; i < nShrines; i += 1)
    {
        const unsigned char nClass = DATATBLS_GetShrinesTxtRecord(i)->nEffectClass;
        if (nClass < 8)
            ++nClassCounts[nClass];
    }
    memset(pControl->wGroupCount, 0, 0xC8);
    memset(pControl->pShrineSubTypeIds, 0, sizeof(pControl->pShrineSubTypeIds));
    for (int i = 0; i < 8; i += 1)
    {
        if (nClassCounts[i] > 0)
        {
            pControl->pShrineSubTypeIds[i] = (int*)FOG_AllocPool(ptGame->pMemoryPool, 4 * nClassCounts[i], ".\\OBJECTS\\objrgn.cpp", 84, 0);
            memset(pControl->pShrineSubTypeIds[i], 0, 4 * nClassCounts[i]);
        }
        pControl->nShrineCounts[i] = 0;
    }
    for (int i = 0; i < nShrines; i += 1)
    {
        const unsigned char nClass = DATATBLS_GetShrinesTxtRecord(i)->nEffectClass;
        if (nClass < 8)
        {
            pControl->pShrineSubTypeIds[nClass][pControl->nShrineCounts[nClass]] = i;
            pControl->nShrineCounts[nClass] += 1;
        }
    }
    return nSeed;
}

#pragma intrinsic(_ReadWriteBarrier)

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define MAX_MSG_SIZE 516

#define PCLASS_AMAZON 0

#define PCLASS_SORCERESS 1

#define PCLASS_NECROMANCER 2

#define PCLASS_BARBARIAN 4

#define PCLASS_DRUID 5

#define PCLASS_ASSASSIN 6

struct D2MonsterRegionStrc;

struct D2CorpseStrc;

struct D2SGameDataStrc;

struct D2ServerCallbackFunctions;


struct D2UnitDescriptionListStrc;

struct Unicode;

struct D2MonStatsTxt;

struct D2ItemsTxt;

struct D2StormLinkStrc;


struct D2HashKeyNoneStrc;

struct D2GameDataTableStrc;

union D2LargeIntegerUnion;

struct D2CriticalSectionStrc;

struct D2ActiveRoomStrc;

struct D2ClientStrc;

struct D2GameStrc;

struct D2UnitStrc;


struct D2ObjectsTxt;

struct D2DataTablesStrc;


struct D2FileTimeStrc;

struct D2StormSlotLink00530600Strc;


extern char gData_00882028[]; // 0x00882028

extern int gdwGlobal_00882528; // 0x00882528

extern int gnLastStatus; // 0x0072FFA8

extern char gszReplyText[]; // 0x00882428

extern int gnCreateAccountResult; // 0x008822A4

extern int gnChangePasswordResult; // 0x008822A0

extern int gnLoginRetryCount; // 0x00882538

extern int gdwGlobal_00730190; // 0x00730190

extern int gdwGlobal_00882750; // 0x00882750

int __stdcall sub_00424E40(void* pArg); // 0x00424E40

extern const char gszEmptyLoadComplete[184]; // 0x006E0498

extern const char gData_006E0550[24]; // 0x006E0550

extern const char gData_006E0568[272]; // 0x006E0568

extern int gdwGlobal_00731010; // 0x00731010

extern int gdwGlobal_00731008; // 0x00731008

void __stdcall GAME_SendGameList(void* pArg); // 0x0052E8E0

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214

void __cdecl FOG_DestroyMemoryPoolSystem(D2PoolSystemStrc* pSystem); // 0x00409C80

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0); // 0x0040B480

int __fastcall GAME_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50

void __fastcall GAME_SendUnitRemovalToClient(D2ClientStrc* pClient, void* pUnit); // 0x0052DFB0

void __fastcall SUNITPROXY_FreeNpcControl(D2GameStrc* pGame); // 0x00536640

D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath); // 0x00537860

void __fastcall CLIENTS_FreeClientsFromGame(D2GameStrc* pGame); // 0x00537AC0

void __fastcall LEVEL_RemoveAllUnits(D2GameStrc* pGame); // 0x0053AFD0

void __fastcall D2GAME_PACKETS_SendPacket0x5C_6FC3E090(D2ClientStrc* pClient, int nUnitGUID); // 0x0053CA90

void __fastcall ARENA_FreeArena(D2GameStrc* pGame); // 0x0053F500

void __fastcall PARTY_FreePartyControl(D2GameStrc* pGame); // 0x00540000

void __fastcall EVENT_FreeEventQueue(D2GameStrc* pGame); // 0x00541400

void __fastcall SUNITINACTIVE_FreeInactiveUnitLists(D2GameStrc* pGame); // 0x00543080

void __fastcall QUESTS_QuestFree(D2GameStrc* pGame); // 0x00543800

void __fastcall OBJRGN_FreeObjectControl(D2GameStrc* pGame); // 0x00546E90

void __fastcall MONSTERREGION_FreeAll(void* pMemPool, D2MonsterRegionStrc** ppMonsterRegion); // 0x00547B50

void __fastcall MONSTERREGION_TrySpawnWanderingMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x0054F060

void __fastcall OBJECTS_PopulationHandler(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x00552610

void __fastcall SUNIT_RemoveUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00555600

void __fastcall SUNIT_SpawnPresetUnitsInRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom); // 0x005559A0

void __stdcall DUNGEON_FreeAct(D2DrlgActStrc* pAct); // 0x0061AFD0

D2CriticalSectionStrc gGameListLock; // 0x00882D18

D2GameStrc* gpGame; // 0x00882D34

int gnGamesGUIDs[1024];                                                                            // 0x00882D38

void __fastcall SCMD_SendPlayerJoinAndPets(D2ClientStrc*, D2UnitStrc*, D2ClientStrc*); // 0x0053C940

D2CorpseStrc* __stdcall INVENTORY_GetFirstCorpse(D2InventoryStrc*); // 0x0063D570

D2CorpseStrc* __stdcall INVENTORY_GetNextCorpse(D2CorpseStrc*); // 0x0063D610

int __stdcall INVENTORY_GetUnitGUIDFromCorpse(D2CorpseStrc*); // 0x0063D630

void __fastcall D2GAME_PACKETS_SendPacket0x8E_6FC3FA20(D2ClientStrc*, int, int, unsigned char); // 0x0053DFB0

void __fastcall ARENA_SendScoresToClient(D2GameStrc*, D2ClientStrc*); // 0x0053FC70

int __fastcall CLIENTS_CheckState(int nClientId, int nState); // 0x00538930

int __fastcall CLIENTS_GetNameById(int nClientId, char* szName); // 0x00538B70

typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

int __fastcall GAME_GetGameGUIDFromGameId(unsigned short nGameId); // 0x0052C060

int __fastcall CLIENTS_GetCanonicalName(const char* szName, char* szGameName); // 0x00538C60

int __fastcall CCMD_IsStringZeroTerminated(const char* pData, int nDataSize); // 0x0053EFC0

D2ServerCallbackFunctions* gpD2EventCallbackTable;                                                 // 0x00883D50

void __fastcall D2GAME_PACKETS_SendGameLeft(int nClientId); // 0x0053B220


extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize); // 0x006829C0

extern "C" size_t __cdecl strlen(const char* szString);

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0

void __fastcall GAME_LeaveGamesCriticalSection(D2GameStrc* pGame); // 0x0052DA90

D2GameStrc* __fastcall GAME_LockGame(int nGameGUID); // 0x0052E860

int __fastcall GAME_IsGameNameUnused(const char* szGameName); // 0x0052F8B0

D2ClientStrc* __fastcall CLIENTS_GetClientFromClientId(D2GameStrc* pGame, int nClientId); // 0x00537810

int __fastcall CLIENTS_IsInGame(D2GameStrc* pGame, int nClientId); // 0x005381C0

int __fastcall CLIENTS_GetClientId(D2ClientStrc* pClient); // 0x00538590

int __fastcall CLIENTS_GetClassId(D2ClientStrc* pClient); // 0x005385F0

char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient); // 0x00538830

void __fastcall CLIENTS_CopyAccountNameToBuffer(D2ClientStrc* pClient, char* szBuffer); // 0x005392F0

void __fastcall ClientRemoveFromGame(D2GameStrc* pGame, int nClientId, int bTriggerSave); // 0x00539DA0

void __fastcall D2GAME_PACKETS_SendGameListEntry(void* pClientId, unsigned short nGameId, int nClients, const char* szGameName); // 0x0053B1B0

void __fastcall SCMD_SendSkillList(D2ClientStrc* pClient, D2UnitStrc* pUnit); // 0x0053C5D0

void __fastcall D2GAME_SetSkills_6FD14C60(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove); // 0x0056DEB0

unsigned int __fastcall CLIENT_IsGameOwner(D2ClientStrc* pClient); // 0x00539030

typedef int (__fastcall* D2NET_Unk_Callback)(int, int, int, int);

int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10

int __stdcall SERVER_SetRemoveClientCallback(D2NET_Unk_Callback pfCallback); // 0x0052B5C0

int __stdcall GAME_AbortClientById(int nClientId, int a2, int a3); // 0x005300F0

void __fastcall SUNITPROXY_FillGlobalItemCache(); // 0x00536F80

void __fastcall CLIENTS_Initialize(); // 0x005376C0

int __fastcall CLIENTS_AttachSaveFile(int nClientId, const void* pSaveData, int nSize, int nTotalSize, int bUnlockCharacter, int a6, int a7); // 0x00538CE0


extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0);

// build: symbol _gszD2NetSourceFile 0x006E0488
extern "C" const char gszD2NetSourceFile[];

// build: symbol ?gnConnectionMode@* 0x00882D10
extern int gnConnectionMode;

int gbD2ServerCallbackFunctionsInitialized;                                                        // 0x00883D54

D2UnitStrc* __fastcall SUNIT_GetNextUnitFromList(D2UnitStrc* pUnit); // 0x00552DB0

typedef void(__fastcall* UnitDescriptionFunction)(char* szDescription, int nClassId);

extern UnitDescriptionFunction gpfnGetDescription[5]; // 0x0073107C

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount); // 0x00526F70

D2ItemsTxt* __stdcall DATATBLS_GetItemsTxtRecord(int nItemId); // 0x006335F0

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90

struct D2StormOwnedLinkStrc : D2StormLinkStrc
{
    D2StormOwnedLinkStrc()
    {
        m_prevlink = 0;
        m_next = 0;
    }
    ~D2StormOwnedLinkStrc()
    {
        Unlink();
    }
};


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

void __fastcall SrvFreeGame(int nGameGUID, D2GameStrc* pGame); // 0x0052C7F0

int __stdcall SStrCmpI(const char* szString1, const char* szString2, unsigned int nMaxChars); // 0x00413590

extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(D2LargeIntegerUnion* pCount); // 0x006CC25C

extern "C" __declspec(dllimport) unsigned long __stdcall timeGetTime(void); // 0x006CC544

extern int gbFixedCpuTargetRatio; // 0x0073100C

void __fastcall GAME_UpdateProgress(D2GameStrc* pGame); // 0x0052D870

void __fastcall GAME_FindGameOwnerCallback(D2ClientStrc* client, void* context); // 0x0052CBB0

void __fastcall GAME_FindFirstClientCallback(D2ClientStrc* client, void* context); // 0x0052CBD0

void __fastcall SrvEndGame(int clientId, int flag); // 0x005303D0

extern "C" void _ReadWriteBarrier(void);


int __fastcall D2GAME_SAVE_WriteFile_6FC8A500(D2GameStrc* pGame, D2UnitStrc* pPlayer, const char* szName, unsigned int dwArg); // 0x00532400

int __fastcall CLIENTS_GetFlags(D2ClientStrc*); // 0x00538640

void __fastcall CLIENTS_GetGuildEmblem(D2ClientStrc*, unsigned char*, unsigned char*, unsigned char*); // 0x00539190

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc*, int, int); // 0x006253B0

struct D2StormSlotLink00530600Strc
{
    D2StormSlotLink00530600Strc* m_prevlink;
    char* m_next;

    inline char* Next()
    {
        char* const pNext = (int)m_next <= 0 ? 0 : m_next;
        return pNext;
    }
};


int gdwGlobal_00882D14; // 0x00882D14


#define PATHTYPE_ASTAR 1

#define PATHTYPE_TOWARD 2

#define PATHTYPE_MON_CIRCLE_CW 5

#define PATHTYPE_MON_CIRCLE_CCW 6

unsigned int __fastcall ARENA_GetFlags(D2GameStrc* pGame);                                                  // 0x0053FD40

static int GAME_CountUnitsInLists(D2UnitStrc** pUnitLists);

unsigned long gdwPlayerPos; // 0x00883D4C

D2GameDataTableStrc* gpGameDataTbl; // 0x00883D38

int gnLastGamesUpdateTimeMs; // 0x00883D58

int gnTargetMsPerFrame; // 0x00883D60

int __stdcall GAME_GetPlayerUnitsCount(unsigned short nGameId);

#define BUCKETS 128

#define INFO_DESCRIPTION_SIZE 16

#define GAME_ID_BIAS 1

#define UNLOCK_LINE 4196


void __fastcall SUNIT_FillUnitInfo(D2UnitStrc* pUnit, D2UnitInfoStrc* pUnitInfo);                           // 0x00553F30


static inline D2GameStrc* GAMELINK_Next(D2GameLinkStrc* pLink)
{
    return (int)pLink->pNext <= 0 ? 0 : pLink->pNext;
}


extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* lpThreadAttributes, unsigned long dwStackSize, unsigned long (__stdcall* lpStartAddress)(D2MessageThreadArgsStrc*), D2MessageThreadArgsStrc* lpParameter, unsigned long dwCreationFlags, unsigned long* lpThreadId); // 0x006CC250

int __stdcall SERVER_HackListClient(int nClientId, int a2, int a3);                                                  // 0x0052B4F0

void __stdcall GAME_SendMessageToAllClients(int a1, int nPacketParam, const char* szMessage);               // 0x0052F4C0

void __fastcall SrvDisconnectClientById(int nClientId, int nEventType);                                   // 0x00530270

void __fastcall CLIENTS_UpdatePing(int nClientId, int a2, int a3, int a4);                                  // 0x005389A0

int __fastcall CLIENTS_GetClientIdByName(const char* szClientName);                                         // 0x00538BF0

void __fastcall SUNITINACTIVE_CompressUnitIfNeeded(D2GameStrc* pGame, D2UnitStrc* pUnit);                   // 0x005433F0

int __stdcall DUNGEON_TestRoomCanUnTile(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom);                      // 0x0061A3F0

int __stdcall D2Common_10081_GetTileCountFromRoom(D2ActiveRoomStrc* pRoom);                                 // 0x0061A790

void __stdcall DUNGEON_RemoveRoomFromAct(D2DrlgActStrc* pAct, D2ActiveRoomStrc* pRoom);                     // 0x0061A910

extern int nInitSeed_6FDC2CA08;                                                                             // 0x00731004

int dword_6FD4581C;                                                                                         // 0x00883D3C

int dword_6FD45820;                                                                                         // 0x00883D40

int gnPeakMemoryUsageInLast10s_6FD45828;                                                                    // 0x00883D48

extern int gnTargetFrameRate;                                                                      // 0x00731014

int gnAct;                                                                                         // 0x00883D44

struct D2ClientInfoStrc;

void __cdecl GAME_LogMessage(int nLevel, const char* szFormat, ...);                                        // 0x0052BE20

void __fastcall CLIENTS_EnableCharacterUnlock(D2ClientStrc* pClient);                                                        // 0x00538320

void __fastcall CLIENTS_SetClientState(D2ClientStrc* pClient, int nClientState);                            // 0x005386D0

D2ClientStrc* __fastcall ClientAddToGame(D2GameStrc* pGame, int nClientId, unsigned char nClassIdOrCharTemplate, const char* szClientName, const char* szAccount, int nCharSaveTransactionToken, unsigned char nLocale, int a8, int a9); // 0x00539A30

void __fastcall D2GAME_PACKETS_SendHeaderOnlyPacket(D2ClientStrc* pClient, unsigned char nHeader);          // 0x0053B320

void __fastcall D2GAME_PACKETS_SendPacket0x01_6FC3C7C0(D2ClientStrc* pClient, char nHeader, D2GameStrc* pGame); // 0x0053B340


extern int gbCheckHeartbeat;                                                                       // 0x00730FFC

int __stdcall SERVER_ReadGamePacket(unsigned char* pBuffer, int nSize);                              // 0x0052B2D0

int __stdcall SERVER_ReadSystemPacket(unsigned char* pBuffer, int nSize);                              // 0x0052B2F0

int __stdcall SERVER_ReadAdminPacket(unsigned char* pBuffer, int nSize);                              // 0x0052B310

void __fastcall GAME_ProcessAdminMessage(void* pData, int nSize);                                                       // 0x0052CC20

void __fastcall SrvDisconnectClient(D2GameStrc* pGame, D2ClientStrc* pClient, int nEventType);            // 0x0052CAF0

int __fastcall CLIENTS_CheckFlag(D2ClientStrc* pClient, unsigned short nFlag);                              // 0x00538670

void __fastcall CCMD_ProcessClientSystemMessage(void* pData, int nSize);                                    // 0x0053F100

void __fastcall ProcessClientMessage(void* pData, int nPacketSize);                                    // 0x0053F3D0

void __fastcall PLRMSG_BroadcastSystemMessage(D2GameStrc* pGame, const char* szMessage, unsigned char nColor);               // 0x0054A9B0

int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit);                                               // 0x00622E70

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x00627260

void __fastcall GAME_ClientEnterAct(D2GameStrc* pGame, D2ClientStrc* pClient);                      // 0x0052C210

void __fastcall CLIENTS_SpawnPlayer(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x005394A0

int __fastcall ClientAddPlayerToGame(D2ClientStrc* pClient, D2GameStrc* pGame, int a3, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00539760

void __fastcall D2GAME_PACKETS_SendSystemError(int nClientId, unsigned int nReason);           // 0x0053B260

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

#pragma pack(pop)

long gnAdminConnectionCount;         // 0x00883D64

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);  // 0x006CC208

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);  // 0x006CC204

int __stdcall CLIENT_ObjectCall_6BED90(int,int,int); // 0x0052B490

int __stdcall sub_0052B330(unsigned char,int,void*,int);  // 0x0052B330

void __stdcall D2NET_10016(int);  // 0x0052B570

extern "C" int __cdecl strncmp(const char*,const char*,unsigned int);

void __fastcall PLRMSG_BroadcastSystemMessage(D2GameStrc*,const char*,unsigned char);  // 0x0054A9B0

enum { MODE_MASK = 15 };


struct HASHKEY_NONE;

struct D2GameHashLinkStrc;

struct D2GameHashListStrc;

int __cdecl CLIENTS_GetExpansionClientCount(); // 0x005377B0

void __stdcall DUNGEON_UpdateAndFreeInactiveRooms(D2DrlgActStrc* pAct); // 0x0061AA20

extern int gnFrameRate; // 0x00731010

void __fastcall GAME_SynchronizePlayerWithClients(D2GameStrc* pGame, D2ClientStrc* pClient); // 0x0052C410

void __fastcall GAME_SaveAllPlayers(D2GameStrc* pGame); // 0x0052CA10

void __stdcall GAME_RemoveUntilableRooms(D2GameStrc* pGame); // 0x0052D240

void __stdcall GAME_CheckClientHeartbeats(D2GameStrc* pGame, int* pbDisconnected); // 0x0052D350

void __fastcall GAME_UpdateEnvironment(D2GameStrc* pGame); // 0x0052D7B0

void __fastcall CLIENTS_SynchronizePlayer(D2GameStrc* pGame, D2ClientStrc* pClient); // 0x005380D0

void __fastcall LEVEL_FreeDrlgDeletes(D2GameStrc* pGame); // 0x0053A820

void __fastcall LEVEL_UpdateQueuedUnitsInAllActs(D2GameStrc* pGame); // 0x0053B000

unsigned int __fastcall ARENA_NeedsClientUpdate(D2GameStrc* pGame); // 0x0053FCA0

void __fastcall EVENT_IterateEvents(D2GameStrc* pGame); // 0x005414D0

void __fastcall SUNITINACTIVE_DeleteExpiredItemNodes(D2GameStrc* pGame, int nAct); // 0x00542AC0

void __fastcall QUESTS_QuestUpdater(D2GameStrc* pGame); // 0x00543E10

void __fastcall ITEMS_DeleteInactiveItems(D2GameStrc* pGame, int nAct); // 0x00558B90

void __fastcall PLAYERLIST_InitializePlayerRelations(D2GameStrc* pGame, D2UnitStrc* pPlayer); // 0x0055B620

int __stdcall D2Common_10073(D2ActiveRoomStrc* pRoom); // 0x0061A460

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480


D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

extern "C" const char gszGameSourceFile; // 0x006D5D1C

static unsigned int gnPeakMemoryUsageInLast10s; // 0x00883D48

static unsigned int gnPreviousMemUsageTick; // 0x00883D68

void __stdcall GAME_GetUnitsDescriptions(unsigned short nGameId, D2UnitDescriptionListStrc* pUnitDescriptionsList, unsigned int eType);

struct D2PoolSystemStrc;

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0);                              // 0x0040B380

int __cdecl FOG_GetMemoryUsage(D2PoolSystemStrc* pSystem);                                     // 0x0040A040

void __fastcall SUNITINACTIVE_RestoreInactiveUnits(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom);            // 0x00542B40

void __fastcall sub_6FC84D40(D2GameStrc* pGame, D2GSPacketSrv5A* pPacket);                                 // 0x0054AA40

void __fastcall D2GAME_PopulateRoom_6FC67190(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom);                  // 0x0054EC90

void __fastcall D2GAME_ITEMS_UpdateInventoryItems(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3, int bRefresh); // 0x0055DF00

D2ActiveRoomStrc* __stdcall DUNGEON_GetRoomFromAct(D2DrlgActStrc* pAct);                                   // 0x0061A180

int __stdcall D2Common_10074(D2ActiveRoomStrc* pRoom);                                                      // 0x0061A4D0

void __stdcall D2Common_10075(D2ActiveRoomStrc* pRoom, int bSet);                                           // 0x0061A510

static void GAME_UpdatePendingRooms(D2GameStrc* pGame);

static void GAME_DeleteInactiveItems(D2GameStrc* pGame);

static void GAME_UpdateAllClients(D2GameStrc* pGame);

static void GAME_UpdateFrameRate(D2GameStrc* pGame);

#define EVENTTYPE_STATREGEN 3

#define EVENTTYPE_DELAYEDPORTAL 11

struct D2SaveHeaderStrc;

struct D2StaticPathStrc;

struct D2PartyNodeStrc;

struct D2PartyStrc;

struct D2PartyControlStrc;

struct D2InactiveItemNodeStrc;

struct D2InactiveUnitListStrc;

struct D2QuestTimerStrc;

struct D2QuestInfoStrc;

struct D2DrlgCoordsStrc;


struct D2ObjectControlStrc;


struct D2ObjInitFnStrc;

struct D2UnkPlrMsgStrc;

struct D2PlayerDataStrc;


struct D2NpcGambleStrc;

struct D2NpcRecordStrc;


struct D2ArenaStrc;


struct D2UnitProxyArgStrc;


enum D2C_MonStatsTxtFlagIndices
{
    MONSTATSFLAGINDEX_INTERACT = 9,
};



struct D2QuestInfoStrc
{
    D2QuestDataStrc* pLastQuest;
    int bExecuting;
    int bPickedSet;
    D2BitBufferStrc* pQuestFlags;
    D2QuestTimerStrc* pTimer;
    unsigned int dwTick;
    D2SeedStrc pSeed;
    unsigned char unk0x20;
    unsigned char unk_21[0x3];
};



extern "C" const char gszQuestsSourceFile[]; // 0x006E0BE4

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern D2UnkPlrMsgStrc gaUnitModeMessages[20]; // 0x007319E8

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

void __stdcall SUNITPROXY_FillIGlobaltemCacheRecordForNpc(int nNpcId); // 0x00536D50

int __fastcall CLIENTS_IsInUnitsRoom(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x005387F0

void __fastcall D2GAME_PACKETS_SendPacket0x10_6FC3C9A0(D2ClientStrc* pClient, char nHeader, char a3, int a4, char a5, int a6, int a7, short a8, short a9); // 0x0053B520

void __fastcall D2GAME_PACKETS_SendPacket0x0F_6FC3CA00(D2ClientStrc* pClient, char nHeader, unsigned char bTOU, int a4, char a5, short a6, short a7, char a8, short a9, short a10); // 0x0053B570

void __fastcall D2GAME_SendPacket0x53_6FC3DF50(D2ClientStrc* pClient, D2GSPacketSrv53* pPacket); // 0x0053C900

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0

D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540

int __fastcall SUNIT_IsDead(D2UnitStrc* pUnit); // 0x005541B0

void __fastcall D2GAME_UpdatePlayerItems_6FC4BB90(D2GameStrc* pGame, D2UnitStrc* pUnit, int a3); // 0x0055FDE0

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

int __stdcall ENVIRONMENT_UpdateCycleIndex(D2DrlgActStrc* pAct, int nActNo); // 0x0061C040

void __stdcall ENVIRONMENT_GetCycleIndex_Ticks_EclipseFromAct(D2DrlgActStrc* pAct, int* pCycleIndex, int* pTicks, int* pEclipse); // 0x0061C330

int __stdcall UNITS_ChangeAnimMode(D2UnitStrc* pUnit, int nMode); // 0x00624690

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00

int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10

void __stdcall QUESTRECORD_FreeRecord(void* pMemPool, D2BitBufferStrc* pQuestRecord); // 0x0065C490


typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

extern int gnVirtualPlayerCount; // 0x00883D70

void __fastcall D2GAME_SetSkills_6FD14C60(int a1, int a2, int a3, int a4); // 0x0056DEB0

void __stdcall UNITS_SetTargetUnitForDynamicUnit(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit); // 0x00620C10

void __fastcall PLRMODE_ChangeModeToCoords(D2GameStrc* pGame, D2UnitStrc* pUnit, D2SkillStrc* pUsedSkill, int nMode, int nX, int nY, int a7); // 0x005809D0

D2ClientStrc* __fastcall UnitGetClient(D2UnitStrc* pPlayer, const char* szFile, int nLine); // 0x005531C0

void __fastcall CLIENTS_SetSkillHotKey(D2ClientStrc* pClient, int nHotkeyId, short nSkillId, unsigned char nHand, int nItemGUID); // 0x005390A0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0

int __fastcall PLAYERLIST_CheckFlag(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2, unsigned int nFlags); // 0x0055B300

void __fastcall ITEMS_RemoveFromAllPlayers(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00557FD0

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790

void __fastcall SUNITMSG_SendRemoveObject(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571600

unsigned char __fastcall CLIENTS_GetActNo(D2ClientStrc* pClient); // 0x005382B0

void __fastcall D2GAME_PACKETS_SendPacket0x03_6FC3C810(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nAct, unsigned int dwInitSeed, unsigned int dwObjSeed, int nTownLevelId); // 0x0053B390

void __stdcall UNITROOM_ClearUpdateQueue(D2ActiveRoomStrc* pRoom); // 0x0064C160

void __fastcall ARENA_ClearUpdateFlag(D2GameStrc* pGame); // 0x0053FAE0

void __fastcall SCMD_SendPlayerRelationshipCallback(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pPacket); // 0x0053DDF0

void __fastcall SCMD_SendCorpseAssignCallback(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pPacket); // 0x0053DF50

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

int __fastcall PLRMSG_InteractWithUnit(D2UnitStrc* pPlayer, int nUnitType, int nUnitGUID, int a4, D2GameStrc* pGame); // 0x00548B00

void __fastcall D2GAME_NPC_IdentifyAllItems_6FCC9C90(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcGUID); // 0x00578460

void __fastcall D2GAME_NPC_ResurrectMerc_6FCC9350(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcUnitId); // 0x00579C00

void __fastcall PLAYER_ResetBusyState(D2UnitStrc* pUnit); // 0x005350B0

void __fastcall PLRINTRO_MaskNpcIntroFlag(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nNpcId); // 0x005724C0

void __fastcall PLRMSG_SendWalkMode(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int nAnimMode);

#define CLIENTS_MAX_UPDATES 55u

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);                       // 0x006CC258

unsigned long gdwLastClientsUpdateTick;                                                                               // 0x00883D5C

int __cdecl sub_0052B910();                                                                                 // 0x0052B910

void __fastcall GAME_CloseGame(int nGameGUID);                                                              // 0x0052E770

void __fastcall CLIENTS_RefreshUnitsUpdateList(D2ClientStrc* pClient, unsigned int nUpdateSize);            // 0x00537FD0

void __fastcall CLIENTS_FreeSaveHeader(D2ClientStrc* pClient);                                              // 0x00538F10

int __fastcall CLIENTS_HasLoadedSave(D2ClientStrc* pClient);                                        // 0x00538FC0

void __fastcall CLIENTS_PacketDataList_Reset(D2ClientStrc* pClient, D2PacketDataStrc* pPacketData);         // 0x00539270

D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_PopHead(D2ClientStrc* pClient);                         // 0x005392A0

D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetHead(D2ClientStrc* pClient);                         // 0x005392E0

void __fastcall GAME_EndGameForConnectedClient(D2GameStrc* pGame, D2ClientStrc* pClient);                   // 0x00530590

void __fastcall SCMD_SendUnitUpdates(D2ClientStrc* pClient);                           // 0x0053E130

int __fastcall PLRMSG_SendPlayerStatUpdates(D2UnitStrc* pUnit, D2UnitStrc* pUnit2, int bSkipHpCheck);                       // 0x00548760

void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0

void __stdcall TASK_FreeAllQueueSlots();                                                                    // 0x00564890

int __fastcall ACT4Q2_UnitIterate_WarpToTownEndGame(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);    // 0x005B4A80

D2UnitStrc* __fastcall ACT4Q2_TrySpawnDiablo(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, D2Act4Quest2Strc* pQuestDataEx); // 0x005B4B60

void __fastcall D2GAME_PACKETS_SendPacket0x0A_RemoveObject(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID); // 0x0053BDA0

extern "C" const char gszSGameDataTypeName[];                                                               // 0x0070F56C

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int dwFlags);                  // 0x00412650

void __cdecl FOG_CreateNewPoolSystem(void* pReserved, const char* szName, int nSize, int nBlockSize); // 0x00409DD0

void __stdcall GAME_SetReservedGameGUID(int hGame, unsigned short nGameId);                            // 0x0052C110

unsigned short __cdecl sub_0052C170_AllocGameId();

void __fastcall GAME_ResolveGameNameConflict(D2GameStrc* pGame, const char* szGameName, unsigned int a3);                    // 0x0052F940

void __fastcall SUNITPROXY_InitializeNpcControl(D2GameStrc* pGame); // 0x00536070

void __fastcall CLIENTS_SetGameData(D2ClientStrc* pClient);                                            // 0x005379A0

void __fastcall ARENA_AllocArena(D2GameStrc* pGame, int a2, unsigned int nFlags, unsigned char a4);         // 0x0053F4B0

void __fastcall PARTY_AllocPartyControl(D2GameStrc* pGame);                                                 // 0x0053FF90

void __fastcall EVENT_AllocEventQueue(D2GameStrc* pGame);                                            // 0x00541470

void __fastcall QUESTS_QuestInit(D2GameStrc* pGame); // 0x00545D80

void __fastcall MONSTERREGION_InitializeForGame(D2GameStrc* pGame);                                         // 0x00547D20

void __fastcall TASK_QueueGame(void* pTask, int a2, unsigned int hGame); // 0x00564A00

void __fastcall CLIENTS_SetActNo(D2ClientStrc* pClient, unsigned char nAct);                                // 0x005382E0

void __fastcall CLIENTS_SetGameOwner(D2ClientStrc* pClient);                                       // 0x00539000

void __fastcall LEVEL_LoadAct(D2GameStrc* pGame, unsigned char nAct);                              // 0x0053AFB0

void __fastcall LEVEL_SynchronizeDayNightCycleWithClient(D2GameStrc* pGame, D2ClientStrc* pClient);                            // 0x0053ABE0

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

// 0x00546E90
void __fastcall OBJRGN_FreeObjectControl(D2GameStrc* ptGame)
{
    D2_ASSERT(ptGame, 0xB6);
    D2ObjectControlStrc* pObjectControl = ptGame->pObjectControl;
    if (!pObjectControl)
        return;
    D2ObjectRoomCoordStrc* pObjectRoomCoord = pObjectControl->pObjectRoomCoord;
    while (pObjectRoomCoord)
    {
        D2ObjectRoomCoordStrc* pNext = pObjectRoomCoord->pNext;
        FOG_FreeServerMemory(ptGame->pMemoryPool, pObjectRoomCoord, ".\\OBJECTS\\objrgn.cpp", 0xC1, 0);
        pObjectRoomCoord = pNext;
    }
    pObjectControl->pObjectRoomCoord = 0;
    for (int i = 1; i < sgptDataTables->nLevelsTxtRecordCount; ++i)
        FOG_FreeServerMemory(ptGame->pMemoryPool, pObjectControl->pObjectRegion[i], ".\\OBJECTS\\objrgn.cpp", 0xE2, 0);
    for (int i = 0; i < 8; ++i)
    {
        if (pObjectControl->pShrineSubTypeIds[i])
            FOG_FreeServerMemory(ptGame->pMemoryPool, pObjectControl->pShrineSubTypeIds[i], ".\\OBJECTS\\objrgn.cpp", 0xE8, 0);
    }
    FOG_FreeServerMemory(ptGame->pMemoryPool, ptGame->pObjectControl, ".\\OBJECTS\\objrgn.cpp", 0xEC, 0);
}

// 0x00546F90
D2ObjectRegionStrc* __fastcall OBJRGN_GetObjectRegionForLevel(D2GameStrc* pGame, int nLevelId)
{
    return pGame->pObjectControl->pObjectRegion[nLevelId];
}

// 0x00546FA0
extern "C" __declspec(dllexport) D2ObjectControlStrc* __fastcall OBJRGN_GetObjectControlFromGame(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    return pGame->pObjectControl;
}

// 0x00546FB0
extern "C" __declspec(dllexport) int* __fastcall OBJRGN_GetShrineDataFromGame(D2GameStrc* pGame)
{
    return pGame->pObjectControl->nShrineCounts;
}

// 0x00546FC0
void __fastcall OBJRGN_IncrementGroupCount(D2GameStrc* pGame, int nGroup)
{
    if ((unsigned int)nGroup < 100)
    {
        D2ObjectControlStrc* pObjectControl = pGame->pObjectControl;
        ++pObjectControl->wGroupCount[nGroup];
    }
}

// 0x00546FE0
void __fastcall OBJRGN_SendServerMessageCallback(D2ClientStrc* pClient, void* pContext)
{
    D2GAME_PACKETS_SendPacket0x26_ServerMessage_6FC3DDF0(pClient, *(D2GSPacketSrv26**)pContext);
}

// 0x00546FF0
void D2GameStrc::OBJRGN_BroadcastServerText(const char* szText)
{
    D2GSPacketSrv26 packet;
    packet.szName[0] = 0;
    packet.nNameColor = 0;
    strcpy(packet.szMessage, szText);
    packet.nMessageColor = 0;
    packet.nHeader = 0x26;
    packet.dwUnitGUID = 0;
    packet.nUnitType = 2;
    packet.nMessageType = 1;
    D2GSPacketSrv26* pPacket = &packet;
    GAME_ForEachIngameClient(this, OBJRGN_SendServerMessageCallback, &pPacket);
}

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szBuffer, const char* szFormat, ...); // 0x006CC468

// 0x00547080
void __fastcall OBJRGN_PrintObjectPlacementStats(D2GameStrc* pGame)
{
    char szText[0x80];
    D2ObjectControlStrc* pObjectControl = pGame->pObjectControl;
    for (int i = 1; i < 0x61; ++i)
    {
        if (pObjectControl->wGroupCount[i])
        {
            wsprintfA(szText, "Attempted to place group %d %d times\n", i, pObjectControl->wGroupCount[i]);
            pGame->OBJRGN_BroadcastServerText(szText);
        }
    }
    wsprintfA(szText, "%d Rooms where we wanted to place - no group beat the odds\n", pObjectControl->wRoomsNoGroup);
    pGame->OBJRGN_BroadcastServerText(szText);
    wsprintfA(szText, "%d rooms tried to place 1+ group(s); %d rooms w/no objs\n", pObjectControl->wRoomsTried, pObjectControl->wGroupCount[0]);
    pGame->OBJRGN_BroadcastServerText(szText);
}
#define QUEST_A2Q3_TAINTEDSUN 10

#define QUEST_A2Q4_HORAZONTOME 11

#define QUEST_A3Q1_LAMESENTOME 15

#define STRCOLOR_DARK_GOLD 4

#define OBJRGN_WELL_DISTANCE 100

#define OBJRGN_SHRINE_DISTANCE 50

#define UNIT_ALIGNMENT_EVIL 0

#define UNIT_ALIGNMENT_NEUTRAL 1

#define UNIT_ALIGNMENT_GOOD 2

#define MONTYPEFLAG_OTHER 1

#define ACT_III 2

#define MONSTATSFLAGINDEX_FLYING 14

#define NUM_QUEST_PLAYER_GUIDS 32

#define LEVEL_FIRST_COUNCIL_LIMIT 108

#define QUEST_LOG_FLAGS 2

#define QFLAG_REWARDGRANTED 0

#define QFLAG_REWARDPENDING 1

#define QFLAG_PRIMARYGOALDONE 13

#define UNITFLAG_TARGETABLE 0x00000002


struct D2SuperUniquesTxt;


struct D2LevelsTxt;


struct D2PackedGuidStrc;

struct D2MessageStrc;

struct D2GSPacketSrv27;


struct D2QuestGUIDStrc;

struct D2QuestInitTableStrc;


struct D2GSPacketSrv91;


struct D2ObjOperateFnStrc;


void __fastcall ACT2Q4_InitializeJerhynStartObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp); // 0x0059F380

void __fastcall ACT2Q4_InitializeJerhynPalaceObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp); // 0x0059F440

void __fastcall ACT2Q3_InitAltarObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp); // 0x0059A3F0

void __fastcall ACT3Q1_InitTomeObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp); // 0x005B7310


void __stdcall TEXT_AddNodeToTextList(D2TextHeaderStrc* pTextHeader, short nStringId, int nMenu); // 0x006612F0

void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

void __fastcall AIGENERAL_GetOwnerData(D2UnitStrc* pUnit, int* pOwnerGUID, int* pOwnerType); // 0x0058F090

int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180

short __fastcall MONSTERUNIQUE_GetBossHcIdx(D2UnitStrc* pUnit); // 0x005A01E0


struct D2GSPacketSrv27
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitGUID;
    D2MessageListStrc tMessageList;
};


extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468

int dword_6FD4DC34; // 0x008846DC

void __fastcall PLRMSG_BroadcastChatMessage(D2GameStrc* pGame, const char* szMessage, unsigned char nColor); // 0x0054A930

void __fastcall D2GAME_PACKETS_SendPacket0x29_6FC3F370(D2ClientStrc* pClient, D2GSPacketSrv29* pPacket); // 0x0053D700

int __fastcall ITEMS_IsInPlayersInventory(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2InventoryStrc* pInventory); // 0x00557FF0

void __fastcall ACT1Q4_SendStoneOrderToClient(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00593CB0

void __fastcall ACT2Q6_SendTombIdToClient(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0059D6A0

void __fastcall D2GAME_PACKETS_SendPacket0x27_6FC3DF20(D2ClientStrc* pClient, D2GSPacketSrv27* pPacket); // 0x0053C8D0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

void __fastcall SCMD_SendPacket0x5D(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket); // 0x0053D710

int __fastcall ACT2Q6_IsDurielsLairClosed(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0059DB20

int __fastcall ACT3Q5_IsDuranceOfHateClosed(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005BBFA0

int __fastcall ACT5Q5_IsArreatSummitClosed(D2GameStrc* pGame, D2UnitStrc* pUnit, int nTargetLevel); // 0x0058D090

int __fastcall ACT5Q6_IsWorldStoneChamberClosed(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058E640

D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740

D2UnitStrc* __fastcall D2GAME_SpawnPresetMonster_6FC66560(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nClassId, int nX, int nY, int nMode); // 0x0054E600

void __fastcall ACT5Q3_ChangeDrehyaMapAI(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAi); // 0x0058AD80

void __fastcall ACT5Q3_ChangeNihlathakMapAI(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAi); // 0x0058AE10

void __fastcall ACT5Q1_ChangeLarzukMapAI(D2GameStrc* pGame, D2UnitStrc* pUnit, D2MapAIStrc* pMapAi); // 0x00587950

int __fastcall QUESTS_CreateChainRecord(D2GameStrc* pGame, D2UnitStrc* pUnit, int nQuestId); // 0x005436B0

void __fastcall MONSTER_SetLevelId(D2UnitStrc* pUnit, int nLevelId); // 0x00573500

int __stdcall STATLIST_GetUnitAlignment(D2UnitStrc* pUnit); // 0x006259B0

void __fastcall D2GAME_PACKETS_SendPacket0x1D_E_F_6FC3D480(D2ClientStrc* pClient, unsigned short nStatId, unsigned int nValue); // 0x0053BE40

void __fastcall SCMD_SendUnitStat(D2ClientStrc* pClient, unsigned char nHeader, int nUnitGUID, unsigned short nStatId, int nValue); // 0x0053C1D0

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

int __stdcall INVENTORY_CompareWithItemsParentInventory(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063AD50

void __fastcall sub_0059B6C0_JerhynSpawnHook(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY); // 0x0059B6C0

void __fastcall sub_0059B6D0_Act2Guard2SpawnHook(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY); // 0x0059B6D0

int __fastcall ACT3Q4_UnitIterate_SetGoldenBirdBoss(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005BAC70

void __fastcall ACT3Q4_CheckGoldenBirdBoss(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005BACF0

void __stdcall ITEMS_SetOrRemoveFlag(int* pFlags, int nFlag, int bSet); // 0x006287B0

unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250

void __stdcall ITEMS_SetItemCell(D2UnitStrc* pItem, unsigned char nItemCell); // 0x00628320

void __fastcall D2GAME_UpdateClientItem_6FC3E9D0(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwCmdFlag); // 0x0053D010

void __fastcall D2GAME_RemoveItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, int bSendPacket); // 0x0055DF10

int __stdcall INVENTORY_GetItemsXPosition(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C150

int __fastcall ITEMMODE_UnequipBodyItem(D2GameStrc* ptGame, D2UnitStrc* pUnit, unsigned char nBodyLoc, int bSetQuantityFlag, int* pItemStatus); // 0x00560CD0

int __fastcall D2GAME_RemoveItemIfOnCursor_6FC49760(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x0055EEA0

void __stdcall INVENTORY_SetCursorItem(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063C180

D2UnitStrc* __fastcall ITEMS_FindQuestItem(D2GameStrc* pGame, D2UnitStrc* pUnit, unsigned int dwItemCode); // 0x00558110

extern "C" const char gszObjRgnSourceFile[]; // 0x006E0C40

extern "C" const char gszPlrMsgSourceFile[]; // 0x006E1050


void __fastcall D2GAME_PACKETS_SendPacket0x5E(D2ClientStrc* pClient, D2GSPacketSrv5E* pPacket); // 0x0053D830

void __fastcall D2GAME_SendPacket0x28_6FC3F2F0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char a3, int a4, D2BitBufferStrc* a5, unsigned char a6); // 0x0053D670

void __fastcall QUESTS_SendCurrentFlags(D2GameStrc* pGame, D2ClientStrc* pClient); // 0x00544520

void __fastcall D2GAME_PACKETS_SendPacket0x89(D2ClientStrc* pClient, D2GSPacketSrv89* pPacket); // 0x0053DFE0

extern D2QuestInitTableStrc sgQuestInit[]; // 0x00731510

int __fastcall QUESTS_FXIterate(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg); // 0x005456F0

int __fastcall ACT2Q6_ActivateTomb(D2GameStrc* pGame, D2CoordStrc* pCoord, D2ActiveRoomStrc** ppRoom); // 0x0059DFD0

void __fastcall ACT3Q5_SpawnCouncil(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005BB550

void __fastcall sub_0058CFD0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058CFD0

void __fastcall ACT1Q3_ACT1Q3_InitMalusObject(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp); // 0x00592090

void __fastcall ACT1Q4_InitCainGibbet(D2QuestDataStrc* pQuestData, D2ObjInitFnStrc* pOp); // 0x00594060

void __fastcall ACT5Q2_UpdatePortalMode(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x00588CA0

void __fastcall ACT5Q3_RemoveNihlathakFromTown(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00589540

void __fastcall ACT5Q3_SpawnFrozenDrehya(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058A500

void __fastcall ACT5Q3_UpdateDrehyaPortalMode(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x0058A730

void __fastcall ACT5Q4_RetryDrehyaPortal(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058B940

void __fastcall ACT5Q5_SpawnAncientMonsters(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x0058C0E0

void __fastcall ACT1Q4_SpawnCainInTristram(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00593290

void __fastcall ACT1Q4_UpdatePortalInTown(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005942C0

void __fastcall ACT1Q4_DropWirtsBodyGold(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x00594630

void __fastcall ACT1Q5_SpawnChestMissilesAndEvent(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005956C0

void __fastcall ACT2Q4_InitializeHaremBlockerObject(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x0059B710

D2UnitStrc* __fastcall MONSTERSPAWN_SpawnAtUnit(D2GameStrc* pGame, D2UnitStrc* pUnit, int nMonsterId, int nAnimMode, int a5, short nFlags); // 0x005B23C0

void __fastcall ACT4Q2_SpawnSealBoss(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005B5750

void __fastcall ACT4Q3_CreateReward(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005B6710

void __fastcall ACT3Q2_OpenSewerStairs(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005B85E0

void __fastcall ACT3Q6_UpdateHellGatePortal(D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005BCAC0

void __fastcall PLRINTRO_SetNpcIntroFlag(D2PlrIntroStrc* pPlayerIntro, int nNpcId); // 0x00572420

int __fastcall PLRINTRO_GetNpcIntroFlag(D2PlrIntroStrc* pPlayerIntro, int nNpcId); // 0x00572470

void __fastcall D2GAME_PACKETS_SendPacket0x91(D2ClientStrc* pClient, D2GSPacketSrv91* pPacket); // 0x0053E060


void __stdcall DUNGEON_AllocDrlgDelete(D2ActiveRoomStrc* pRoom, int nUnitType, int nUnitGUID); // 0x0061A270

void __stdcall UNITS_FreeCollisionPath(D2UnitStrc* pUnit); // 0x00623830

void __stdcall UNITROOM_RemoveUnitFromRoom(D2UnitStrc* pUnit); // 0x0064C370

int __fastcall QUESTS_FastRemovePlayerGUID(D2QuestGUIDStrc* pGUIDs, int dwGUID); // 0x00545240

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730

unsigned short __stdcall COLLISION_CheckMaskWithSizeXY(D2ActiveRoomStrc* pRoom, int nX, int nY, unsigned int nSizeX, unsigned int nSizeY, unsigned short nMask); // 0x0064D800

void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380

void __stdcall UNITS_GetCoords(D2UnitStrc* pUnit, D2CoordStrc* pCoord); // 0x00620870

void __fastcall EVENT_SetEvent(D2GameStrc* pGame, D2UnitStrc* pUnit, int nEventType, int nExpireFrame, int dwEventCustomId, int dwEventCustomParam); // 0x005417D0


void __fastcall QUESTS_UpdatePlayerFlags(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005455B0

struct D2QuestDataStrc;

#define QUEST_A1Q4_CAIN 4

#define QUEST_A2Q1_RADAMENT 8

#define QUEST_A2Q5_SUMMONER 12

#define MAX_QUEST_STATUS 41

#define QUESTSTATEFLAG_A1Q1 1

#define QUESTSTATEFLAG_A2Q4 12

#define QUEST_A1Q1_DENOFEVIL 1

#define ACT_II 1

#define PACKET_QUESTSTATUS 0x52

#define PACKET_QUESTPROGRESS 0x50

#define LINE_UPDATEFLAGS_CLIENT 0xCA7

#define LINE_STATUS_CLIENT 0x49A

#define LINE_STATUS_QUESTNO 0x4B3

#define LINE_STATUS_FILTER 0x4CB


typedef bool(__fastcall* QUESTSTATUSFILTER)(D2QuestDataStrc* pQuest, D2UnitStrc* pPlayer, D2BitBufferStrc* pGlobalFlags, D2BitBufferStrc* pFlags, unsigned char* pStatus);

typedef bool (__fastcall* QUESTACTIVEFILTER)(D2QuestDataStrc* pQuest, int nNpcId, D2UnitStrc* pPlayer, D2BitBufferStrc* pQuestFlags, D2UnitStrc* pNPC);

D2QuestDataStrc* __fastcall QUESTS_GetQuestData(D2GameStrc* pGame, int nId); // 0x00543640

void __fastcall ACT1Q4_SetInvisibleObjectGUID(D2GameStrc* pGame, D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x00592F80

void __fastcall ACT2Q1_OnRadamentCreated(D2GameStrc* pGame, D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005991B0

void __fastcall ACT2Q5_OnSummonerCreated(D2GameStrc* pGame, D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x0059C3B0

int __fastcall ACT1Q6_IsAndarielKilled(D2QuestDataStrc* pQuestData); // 0x005968C0


void __fastcall D2GAME_SendPacket0x8A_6FC3FA60(D2ClientStrc* pClient, D2GSPacketSrv8A* pPacket); // 0x0053DFF0

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0


void __fastcall D2GAME_SendPacket0x50_6FC3F440(D2ClientStrc* pClient, D2GSPacketSrv50* pPacket); // 0x0053D7E0

void __fastcall D2GAME_SendPacket0x52(D2ClientStrc* pClient, D2GSPacketSrv52* pPacket); // 0x0053D840

void __fastcall QUESTS_RefreshStatus(D2QuestDataStrc* pQuest, unsigned char* pQuestList, D2BitBufferStrc* pQuestFlags); // 0x00543F90

int __fastcall ACT5Q2_GetBarbsToBeRescued(D2QuestDataStrc* pQuestData); // 0x00588C50

unsigned short __fastcall ACT1Q1_GetMonstersToBeKilled(D2QuestDataStrc* pQuestData); // 0x005901E0

void __fastcall D2GAME_PACKETS_SendPacket0x61(D2ClientStrc* pClient, unsigned char nValue); // 0x0053D940

void __fastcall ACT1Q4_UpdateQuestStateOnActChange(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00597310

void __fastcall ACT3Q6_SetObjectModes(D2GameStrc* pGame, D2UnitStrc* pObject); // 0x005BCFD0

struct D2MessageListStrc;

D2GameStrc* __fastcall CLIENTS_GetGame(D2ClientStrc* pClient); // 0x005387C0

void __stdcall TEXT_CreateMessageListFromTextHeader(D2TextHeaderStrc* pTextHeader, D2MessageListStrc* pMessageList); // 0x00661480

static void __stdcall QUESTS_StatusCycler(bool bForceActive, D2QuestArgStrc* pArgs);

static void __stdcall QUESTS_EventCallback(bool bCheckActive, unsigned char bCheckAct, D2QuestArgStrc* pArgs);

void __fastcall QUESTS_ChangeLevel(D2GameStrc* pGame, int nOldLevelId, int nTargetLevelId, D2UnitStrc* pUnit);

struct D2RoomStrc;

void __fastcall QUESTS_GetFreePosition(D2ActiveRoomStrc* pRoom, D2CoordStrc* pCoord, unsigned int nSize, unsigned short fCollision, D2ActiveRoomStrc** ppRoom, int nId, int nRadius); // 0x00545340

D2UnitStrc* __fastcall D2GAME_SpawnMonster_6FC69F10(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20

struct D2BitBufferStrc;

typedef char QUESTINIT_check_data[sizeof(D2QuestDataStrc) == 0xF8 ? 1 : -1];

typedef char QUESTINIT_check_info[sizeof(D2QuestInfoStrc) == 0x24 ? 1 : -1];

typedef void (__fastcall* QUESTINIT)(D2QuestDataStrc* pQuestData);

struct D2QuestIntroTableStrc
{
    QUESTINIT pfInit;
    unsigned char nAct;
    unsigned char pad0x05[3];
};

extern int gnQuestInitTableCount;                                                                  // 0x00731888

extern D2QuestIntroTableStrc sgQuestIntro[];                                                  // 0x0073188C

extern int gnQuestIntroTableCount;                                                                 // 0x007318AC

D2BitBufferStrc* __stdcall QUESTRECORD_AllocRecord(void* pMemPool);                                         // 0x0065C430

#define QUESTS_SEED_STEP_HIGH_FIRST(pSeed, nOut) { const unsigned __int64 lSeed_ = (unsigned __int64)(pSeed)->nHighSeed + (unsigned __int64)(pSeed)->nLowSeed * 0x6AC690C5; (pSeed)->nHighSeed = (unsigned int)(lSeed_ >> 32); (pSeed)->nLowSeed = (unsigned int)lSeed_; nOut = (unsigned int)lSeed_; }

extern "C" void __fastcall __security_check_cookie(unsigned int); // 0x00681A48

static void QUESTS_ClearQuestIntroState(D2GameStrc* pGame, int nChainNo);

struct D2CoordStrc;

int __fastcall ITEMS_GetItemLevelForNewItem(D2UnitStrc* pUnit, int nLevelId); // 0x00558200

void __fastcall D2GAME_DropItem_6FC52260(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00558AA0

D2UnitStrc* __fastcall D2GAME_CreateItemUnit_6FC501A0(D2UnitStrc* pPlayer, int nItemId, D2GameStrc* pGame, int nSpawnTarget, int nQuality, int bNoSockets, int bNoEthereal, int nItemLevel, int bUseSeed, int dwSeed, int dwItemSeed); // 0x00559CE0

int __fastcall D2GAME_PlaceItem_6FC44410(const char* szFile, int nLine, D2GameStrc* pGame, D2UnitStrc* pPlayer, int nUnitId, int nX, int nY, int a8, int a9, D2InventoryStrc* pInventory); // 0x00560200

void __fastcall D2GAME_ITEMS_Identify_6FC49670(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem); // 0x00562590

int __stdcall STATLIST_GetMaxDurabilityFromUnit(D2UnitStrc* pUnit); // 0x00625E00

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280

D2ItemsTxt* __stdcall DATATBLS_GetItemRecordFromItemCode(unsigned int dwCode, int* pItemId); // 0x00633640

void __fastcall QUESTS_StatusCycleNpcActivate(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget);

void __fastcall QUESTS_ItemPickedUp(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem);

void __fastcall QUESTS_ItemDropped(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem);

void __fastcall QUESTS_StatusCycleObjectReset(D2GameStrc* pGame, D2UnitStrc* pTarget);

void __fastcall QUESTS_NPCActivate(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pTarget, D2TextHeaderStrc* pTextControl);

void __fastcall QUESTS_NPCDeactivate(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pNPC);

void __fastcall QUESTS_NPCMessage(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwNPCGUID, unsigned short nMessage);

void __fastcall QUESTS_NPCActivateSpeeches(D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pTarget);

void __fastcall QUESTS_ParseKill(D2GameStrc* pGame, D2UnitStrc* pDefender, D2UnitStrc* pAttacker);

void __fastcall QUESTS_PlayerDroppedWithQuestItem(D2GameStrc* pGame, D2UnitStrc* pPlayer);

void __fastcall QUESTS_SequenceCycler(D2GameStrc* pGame, D2UnitStrc* pPlayer, int bGameEnter);

static void __stdcall QUESTS_DeleteItemEx(D2InventoryStrc* pInventory, D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem);

void __fastcall QUESTS_DeleteItem(D2GameStrc* pGame, D2UnitStrc* pPlayer, int dwCode);

static void QUESTS_SetActNpcIntroFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char nAct);

#define SUMMONER_FLAG 2

void __fastcall MONSTERREGION_InitializeAll(void* pool,D2MonsterRegionStrc** regions,D2SeedStrc* seed,unsigned int lowSeed,unsigned char difficulty,int expansion); // 0x005479C0

void __fastcall MONSTER_ToggleSummonerFlag(D2UnitStrc* pUnit, int nFlag, int bSet); // 0x00573570

void __stdcall MONSTERCHOOSE_GenerateComponentVariants(D2SeedStrc* pSeed, D2MonRegDataStrc* pMonRegData, int nCount); // 0x005BDB20

// 0x00547170
void __fastcall OBJRGN_AllocObjectRoomCoords(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom)
{
    D2ObjectControlStrc* pObjectControl = pGame->pObjectControl;
    D2ObjectRoomCoordStrc* pObjectRoomCoord = (D2ObjectRoomCoordStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2ObjectRoomCoordStrc), ".\\OBJECTS\\objrgn.cpp", 375, 0);

    int nX;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nX = pUnit->pStaticPath->tGameCoords.nX;
        break;

    default:
        if (pUnit->pDynamicPath)
        {
            nX = PATH_GetXPosition(pUnit->pDynamicPath);
        }
        else
        {
            nX = 0;
        }
        break;
    }
    pObjectRoomCoord->nX = nX;

    int nY;
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        nY = pUnit->pStaticPath->tGameCoords.nY;
        break;

    default:
        if (pUnit->pDynamicPath)
        {
            nY = PATH_GetYPosition(pUnit->pDynamicPath);
        }
        else
        {
            nY = 0;
        }
        break;
    }
    pObjectRoomCoord->nY = nY;

    pObjectRoomCoord->pRoom = pRoom;
    pObjectRoomCoord->pNext = pObjectControl->pObjectRoomCoord;
    pObjectControl->pObjectRoomCoord = pObjectRoomCoord;
}

// 0x00547210
void __fastcall OBJECTS_InitFunction17_Waypoint(D2ObjInitFnStrc* pOp)
{
    D2ObjectControlStrc* pObjectControl = pOp->pGame->pObjectControl;
    D2ObjectRoomCoordStrc* pObjectRoomCoord = pObjectControl->pObjectRoomCoord;
    while (pObjectRoomCoord)
    {
        if (pObjectRoomCoord->pRoom == pOp->pRoom
            || (pOp->pRoom && pObjectRoomCoord->nX >= pOp->pRoom->tCoords.nSubtileX && pObjectRoomCoord->nX < pOp->pRoom->tCoords.nSubtileX + pOp->pRoom->tCoords.nSubtileWidth
                && pObjectRoomCoord->nY >= pOp->pRoom->tCoords.nSubtileY && pObjectRoomCoord->nY < pOp->pRoom->tCoords.nSubtileY + pOp->pRoom->tCoords.nSubtileHeight))
        {
            if (!pOp->pObject || pOp->pObject->dwAnimMode == OBJMODE_NEUTRAL)
            {
                UNITS_ChangeAnimMode(pOp->pObject, 1);
                D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(!pOp->pObject ? -1 : pOp->pObject->dwClassId);
                EVENT_SetEvent(pOp->pGame, pOp->pObject, 1, pOp->pGame->dwGameFrame + (pObjectsTxtRecord->dwFrameCnt[1] >> 8), 0, 0);
            }
            FOG_FreeServerMemory(pOp->pGame->pMemoryPool, pObjectRoomCoord, ".\\OBJECTS\\objrgn.cpp", 0x19B, 0);
            pObjectControl->pObjectRoomCoord = 0;
            return;
        }
        pObjectRoomCoord = pObjectRoomCoord->pNext;
    }
    if (DUNGEON_IsRoomInTown(pOp->pRoom))
        UNITS_ChangeAnimMode(pOp->pObject, 2);
}

// 0x00547300
bool __fastcall OBJRGN_CanNotSpawnMoreWells(D2GameStrc* pGame, int nLevelId)
{
    D2ObjectRegionStrc* pObjectRegion = pGame->pObjectControl->pObjectRegion[nLevelId];
    if (pObjectRegion->nWells == 4 || pObjectRegion->nWells > pObjectRegion->nPopulatedRooms / 8)
    {
        return true;
    }
    return false;
}

// 0x00547330
bool __fastcall OBJRGN_ShouldSpawnHealingShrineOrWell(D2GameStrc* pGame, int nLevelId)
{
    D2ObjectRegionStrc* pObjectRegion = pGame->pObjectControl->pObjectRegion[nLevelId];
    if (pObjectRegion->nPopulatedRooms > 0 && (pObjectRegion->nProcessedRooms << 7) / pObjectRegion->nPopulatedRooms > 96 && !pObjectRegion->nHealingShrines)
    {
        return true;
    }
    return false;
}

// 0x00547360
bool __fastcall OBJRGN_CanNotSpawnMoreShrines(D2GameStrc* pGame, int nLevelId)
{
    D2ObjectRegionStrc* pObjectRegion = pGame->pObjectControl->pObjectRegion[nLevelId];
    if (pObjectRegion->nShrines == 10 || pObjectRegion->nShrines > pObjectRegion->nPopulatedRooms / 8)
    {
        return true;
    }
    return false;
}




struct Entry00547390;

struct Sub00547390;

struct Obj00547390;

struct D2MonRegDataStrc;

struct Entry00547390 { unsigned int dwUnknown00[4]; int nCount10; };

struct Sub00547390 { unsigned char bUnknown00[0x48]; Entry00547390* pEntries48[1]; };

struct Obj00547390 { unsigned char bUnknown00[0x10F0]; Sub00547390* pSub10F0; };

D2MonsterRegionStrc* __fastcall MONSTERREGION_GetMonsterRegionFromLevelId(D2MonsterRegionStrc** ppMonsterRegion, int nLevelId); // 0x00547BB0

// 0x00547390
extern "C" __declspec(dllexport) void __fastcall OBJRGN_IncreaseHealingShrineCount(Obj00547390* pObj, int nIndex) {
    pObj->pSub10F0->pEntries48[nIndex]->nCount10++;
}

// 0x005473A0
bool __fastcall OBJRGN_CanSpawnWell(D2GameStrc* pGame, int nLevelId, int nX, int nY)
{
    D2ObjectRegionStrc* pObjectRegion = pGame->pObjectControl->pObjectRegion[nLevelId];
    for (int i = 0; i < pObjectRegion->nWells; ++i)
    {
        int nDistance = pObjectRegion->wellCoordinates[i].nX - nX;
        if (nDistance < 0)
        {
            nDistance = -nDistance;
        }
        if (nDistance < OBJRGN_WELL_DISTANCE)
        {
            return false;
        }

        nDistance = pObjectRegion->wellCoordinates[i].nY - nY;
        if (nDistance < 0)
        {
            nDistance = -nDistance;
        }
        if (nDistance < OBJRGN_WELL_DISTANCE)
        {
            return false;
        }
    }

    return true;
}

#define OBJRGN_MAX_WELLS 4

// 0x00547400
void __fastcall OBJRGN_SetWellCoordinates(D2GameStrc* pGame, int nLevelId, int nX, int nY)
{
    D2ObjectRegionStrc* pObjectRegion = pGame->pObjectControl->pObjectRegion[nLevelId];
    if (pObjectRegion->nWells >= OBJRGN_MAX_WELLS)
    {
        return;
    }

    pObjectRegion->wellCoordinates[pObjectRegion->nWells].nX = nX;
    pObjectRegion->wellCoordinates[pObjectRegion->nWells].nY = nY;
    ++pObjectRegion->nWells;
}

// 0x00547430
bool __fastcall OBJRGN_CanSpawnShrine(D2GameStrc* pGame, int nLevelId, int nX, int nY)
{
    D2ObjectRegionStrc* pObjectRegion = pGame->pObjectControl->pObjectRegion[nLevelId];
    for (int i = 0; i < pObjectRegion->nShrines; ++i)
    {
        int nDistance = pObjectRegion->shrineCoordinates[i].nX - nX;
        if (nDistance < 0)
        {
            nDistance = -nDistance;
        }
        if (nDistance < OBJRGN_SHRINE_DISTANCE)
        {
            return false;
        }

        nDistance = pObjectRegion->shrineCoordinates[i].nY - nY;
        if (nDistance < 0)
        {
            nDistance = -nDistance;
        }
        if (nDistance < OBJRGN_SHRINE_DISTANCE)
        {
            return false;
        }
    }

    return true;
}

#define OBJRGN_MAX_SHRINES 10

// 0x00547490
void __fastcall OBJRGN_SetShrineCoordinates(D2GameStrc* pGame, int nLevelId, int nX, int nY)
{
    D2ObjectRegionStrc* pObjectRegion = pGame->pObjectControl->pObjectRegion[nLevelId];
    if (pObjectRegion->nShrines >= OBJRGN_MAX_SHRINES)
    {
        return;
    }

    pObjectRegion->shrineCoordinates[pObjectRegion->nShrines].nX = nX;
    pObjectRegion->shrineCoordinates[pObjectRegion->nShrines].nY = nY;
    ++pObjectRegion->nShrines;
}

// 0x005474C0
int __fastcall OBJRGN_GetTrapMonsterId(D2ObjOperateFnStrc* pOp)
{
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pOp->hObject));
    const unsigned char nAct = DRLG_GetActNoFromLevelId(nLevelId);
    D2ObjectRegionStrc* pObjectRegion = pOp->pGame->pObjectControl->pObjectRegion[nLevelId];
    if (pObjectRegion->nTrapMonsterId < 0 || pObjectRegion->nTrapMonsterId >= sgptDataTables->nMonStatsTxtRecordCount)
    {
        int nTrapMonsterIds1[] = { MONSTER_ZOMBIE1 };
        int nTrapMonsterIds2[] = { MONSTER_MUMMY1 };
        int nTrapMonsterIds3[] = { MONSTER_SKELETON1, MONSTER_SK_ARCHER1, MONSTER_SKMAGE_POIS1, MONSTER_SKMAGE_COLD1, MONSTER_SKMAGE_FIRE1, MONSTER_SKMAGE_LTNG1 };

        const int* pTrapMonsterIds = nTrapMonsterIds1;
        if (nAct == ACT_II)
        {
            pTrapMonsterIds = nTrapMonsterIds2;
        }

        D2MonsterRegionStrc* pMonsterRegion = MONSTERREGION_GetMonsterRegionFromLevelId(pOp->pGame->pMonReg, nLevelId);
        pObjectRegion->nTrapMonsterId = MONSTER_FLYINGSCIMITAR;

        for (int j = 0; j < pMonsterRegion->nMonCount; ++j)
        {
            const int nMonsterId = pMonsterRegion->pMonData[j].nMonHcIdx;
            for (int i = 0; i < 1; ++i)
            {
                if (nMonsterId >= pTrapMonsterIds[i] && nMonsterId < pTrapMonsterIds[i] + 5)
                {
                    pObjectRegion->nTrapMonsterId = pTrapMonsterIds[i];
                    return pTrapMonsterIds[i];
                }
            }

            for (int i = 0; i < 6; ++i)
            {
                if (nMonsterId >= nTrapMonsterIds3[i] && nMonsterId < nTrapMonsterIds3[i] + 4)
                {
                    pObjectRegion->nTrapMonsterId = nTrapMonsterIds3[i];
                    return nTrapMonsterIds3[i];
                }
            }
        }
    }

    return pObjectRegion->nTrapMonsterId;
}



