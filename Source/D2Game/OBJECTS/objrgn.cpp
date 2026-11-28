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
#include "FogApi.h"
#include "StormApi.h"
#include "D2CommonApi.h"
#include "D2LangApi.h"
#include "D2CommonApi2.h"
#include "D2CommonApi3.h"
// build: symbol _gaszLanguageNames 0x0073192C

union D2SeedStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);
extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize);

extern D2DataTablesStrc* sgptDataTables; // 0x00744304
void* __fastcall FOG_AllocPool(void* pPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
#include "D2GameFuncs.h"
#include "FogApi2.h"
#include "D2NetApi.h"
#include "StormApi2.h"
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


extern char gszInfoText[]; // 0x00882028

extern int gdwGlobal_00882528; // 0x00882528

extern int gnLastStatus; // 0x0072FFA8

extern char gszReplyText[]; // 0x00882428

extern int gnCreateAccountResult; // 0x008822A4

extern int gnChangePasswordResult; // 0x008822A0

extern int gnLoginRetryCount; // 0x00882538

extern int gdwGlobal_00730190; // 0x00730190

extern int gdwGlobal_00882750; // 0x00882750

int __stdcall SBigDel(void* pArg); // 0x00424E40


extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0); // 0x0040B480

int __fastcall GAME_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50

void __fastcall GAME_SendUnitRemovalToClient(D2ClientStrc* pClient, void* pUnit); // 0x0052DFB0


D2CriticalSectionStrc gGameListLock; // 0x00882D18

D2GameStrc* gpGame; // 0x00882D34

int gnGamesGUIDs[1024];                                                                            // 0x00882D38



typedef int (__stdcall* FARPROC)();

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C


int __fastcall CCMD_IsStringZeroTerminated(const char* pData, int nDataSize); // 0x0053EFC0

D2ServerCallbackFunctions* gpD2EventCallbackTable;                                                 // 0x00883D50


extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize); // 0x006829C0

extern "C" size_t __cdecl strlen(const char* szString);

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD


void __fastcall ClientRemoveFromGame(D2GameStrc* pGame, int nClientId, int bTriggerSave); // 0x00539DA0

void __fastcall D2GAME_PACKETS_SendGameListEntry(void* pClientId, unsigned short nGameId, int nClients, const char* szGameName); // 0x0053B1B0


void __fastcall D2GAME_SetSkills(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove); // 0x0056DEB0


typedef int (__fastcall* D2NET_Unk_Callback)(int, int, int, int);


int __stdcall SERVER_SetRemoveClientCallback(D2NET_Unk_Callback pfCallback); // 0x0052B5C0


extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260


// build: symbol _gszD2NetSourceFile 0x006E0488
extern "C" const char gszD2NetSourceFile[];

// build: symbol ?gnConnectionMode@* 0x00882D10
extern int gnConnectionMode;

int gbD2ServerCallbackFunctionsInitialized;                                                        // 0x00883D54


typedef void(__fastcall* UnitDescriptionFunction)(char* szDescription, int nClassId);

extern UnitDescriptionFunction gpfnGetDescription[5]; // 0x0073107C

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430


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


extern "C" __declspec(dllimport) int __stdcall QueryPerformanceCounter(D2LargeIntegerUnion* pCount); // 0x006CC25C

extern "C" __declspec(dllimport) unsigned long __stdcall timeGetTime(void); // 0x006CC544


extern "C" void _ReadWriteBarrier(void);


void __fastcall CLIENTS_GetGuildEmblem(D2ClientStrc*, unsigned char*, unsigned char*, unsigned char*); // 0x00539190


int gdwGlobal_00882D14; // 0x00882D14


#define PATHTYPE_ASTAR 1

#define PATHTYPE_TOWARD 2

#define PATHTYPE_MON_CIRCLE_CW 5

#define PATHTYPE_MON_CIRCLE_CCW 6


static int GAME_CountUnitsInLists(D2UnitStrc** pUnitLists);

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


extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* lpThreadAttributes, unsigned long dwStackSize, unsigned long (__stdcall* lpStartAddress)(D2MessageThreadArgsStrc*), D2MessageThreadArgsStrc* lpParameter, unsigned long dwCreationFlags, unsigned long* lpThreadId); // 0x006CC250


int gnGlobal_00883D3C;                                                                                         // 0x00883D3C

int gnGlobal_00883D40;                                                                                         // 0x00883D40


int gnAct;                                                                                         // 0x00883D44

struct D2ClientInfoStrc;


void __fastcall GAME_ProcessAdminMessage(void* pData, int nSize);                                                       // 0x0052CC20




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

extern "C" int __cdecl strncmp(const char*,const char*,unsigned int);


enum { MODE_MASK = 15 };


struct HASHKEY_NONE;

struct D2GameHashLinkStrc;

struct D2GameHashListStrc;



D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

extern "C" const char gszGameSourceFile; // 0x006D5D1C

static unsigned int gnPeakMemoryUsageInLast10s; // 0x00883D48

static unsigned int gnPreviousMemUsageTick; // 0x00883D68


struct D2PoolSystemStrc;



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


D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540



typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

extern int gnVirtualPlayerCount; // 0x00883D70

void __fastcall D2GAME_SetSkills(int pUnit, int nSkillId, int nSkillLevel, int bRemove); // 0x0056DEB0


void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0



#define CLIENTS_MAX_UPDATES 55u

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);                       // 0x006CC258

unsigned long gdwLastClientsUpdateTick;                                                                               // 0x00883D5C


D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetHead(D2ClientStrc* pClient);                         // 0x005392E0


void __fastcall SUNIT_IterateUnitsOfType(D2GameStrc* pGame, int nType, void* pArg, QUESTUNITITERATE pfIterate); // 0x005537D0


extern "C" const char gszSGameDataTypeName[];                                                               // 0x0070F56C

void __cdecl FOG_CreateNewPoolSystem(void* pReserved, const char* szName, int nSize, int nBlockSize); // 0x00409DD0


unsigned short __cdecl sub_0052C170_AllocGameId();


void __fastcall TASK_QueueGame(void* pTask, int nArg, unsigned int hGame); // 0x00564A00


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
extern "C" __declspec(dllexport) D2ShrineDataStrc* __fastcall OBJRGN_GetShrineDataFromGame(D2GameStrc* pGame)
{
    return (D2ShrineDataStrc*)pGame->pObjectControl->nShrineCounts;
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
    D2GAME_PACKETS_SendPacket0x26_ServerMessage(pClient, *(D2GSPacketSrv26**)pContext);
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


int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180


struct D2GSPacketSrv27
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitGUID;
    D2MessageListStrc tMessageList;
};


extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468

int gbQuestDebug; // 0x008846DC


D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nSubtileX, int nSubtileY); // 0x00463740


void __fastcall MONSTER_SetLevelId(D2UnitStrc* pUnit, int nLevelId); // 0x00573500


void __fastcall sub_0059B6C0_JerhynSpawnHook(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY); // 0x0059B6C0

void __fastcall sub_0059B6D0_Act2Guard2SpawnHook(D2GameStrc* pGame, D2UnitStrc* pUnit, int nX, int nY); // 0x0059B6D0


unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250


extern "C" const char gszObjRgnSourceFile[]; // 0x006E0C40

extern "C" const char gszPlrMsgSourceFile[]; // 0x006E1050


void __fastcall QUESTS_SendCurrentFlags(D2GameStrc* pGame, D2ClientStrc* pClient); // 0x00544520


extern D2QuestInitTableStrc sgQuestInit[]; // 0x00731510


void __fastcall sub_0058CFD0(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x0058CFD0


void __fastcall ACT5Q3_RemoveNihlathakFromTown(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00589540



void __fastcall SUNIT_AttachSound(D2UnitStrc* pUnit, int nUpdateType, D2UnitStrc* pUpdateUnit); // 0x00553380


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


void __fastcall ACT2Q1_OnRadamentCreated(D2GameStrc* pGame, D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x005991B0

void __fastcall ACT2Q5_OnSummonerCreated(D2GameStrc* pGame, D2QuestDataStrc* pQuestData, D2UnitStrc* pUnit); // 0x0059C3B0


unsigned short __fastcall ACT1Q1_GetMonstersToBeKilled(D2QuestDataStrc* pQuestData); // 0x005901E0


void __fastcall ACT3Q6_SetObjectModes(D2GameStrc* pGame, D2UnitStrc* pObject); // 0x005BCFD0

struct D2MessageListStrc;


static void __stdcall QUESTS_StatusCycler(bool bForceActive, D2QuestArgStrc* pArgs);

static void __stdcall QUESTS_EventCallback(bool bCheckActive, unsigned char bCheckAct, D2QuestArgStrc* pArgs);


struct D2RoomStrc;


D2UnitStrc* __fastcall D2GAME_SpawnMonster(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom, int nX, int nY, int nMonsterId, int nAnimMode, int nMaxSearchRings, short nFlags); // 0x005B2F20

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


extern D2QuestIntroTableStrc sgQuestIntro[];                                                  // 0x0073188C


#define QUESTS_SEED_STEP_HIGH_FIRST(pSeed, nOut) { const unsigned __int64 lSeed_ = (unsigned __int64)(pSeed)->nHighSeed + (unsigned __int64)(pSeed)->nLowSeed * 0x6AC690C5; (pSeed)->nHighSeed = (unsigned int)(lSeed_ >> 32); (pSeed)->nLowSeed = (unsigned int)lSeed_; nOut = (unsigned int)lSeed_; }

extern "C" void __fastcall __security_check_cookie(unsigned int); // 0x00681A48

static void QUESTS_ClearQuestIntroState(D2GameStrc* pGame, int nChainNo);

struct D2CoordStrc;


void __fastcall D2GAME_DropItem(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pItem, D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00558AA0


int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0


static void __stdcall QUESTS_DeleteItemEx(D2InventoryStrc* pInventory, D2GameStrc* pGame, D2UnitStrc* pPlayer, D2UnitStrc* pItem);


static void QUESTS_SetActNpcIntroFlags(D2GameStrc* pGame, D2UnitStrc* pPlayer, unsigned char nAct);

#define SUMMONER_FLAG 2


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

struct D2MonRegDataStrc;


// 0x00547390
extern "C" __declspec(dllexport) void __fastcall OBJRGN_IncreaseHealingShrineCount(D2GameStrc* pGame, int nLevelId)
{
    ++pGame->pObjectControl->pObjectRegion[nLevelId]->nHealingShrines;
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


