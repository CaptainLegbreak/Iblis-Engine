#include "D2MonsterIds.h"
#include "D2StatIds.h"
#include "D2PlayerModes.h"
#include "D2ObjModes.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Drlg.h"
#include "D2GameServer.h"
#include "D2GameClient.h"
#include "D2Unicode.h"
#include "D2GameStrc.h"
#include "D2StormLink.h"
#include "D2Primitives.h"
#include "D2DrlgRooms.h"
#include "D2Constants.h"
#include "D2Path.h"
#include "D2UnitData.h"
#include "D2InactiveUnits.h"
#include "D2GameRecords.h"
#include "D2ItemsWorld.h"
#include "D2QuestData.h"
#include "D2Packets.h"
#include "D2GameCallbackArgs.h"
#include "FogApi.h"
#include "StormApi.h"
#include "D2CommonApi.h"
#include "D2LangApi.h"

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


struct D2NetPacketRecStrc;


struct D2Net52BE10Strc;

struct D2UnitDescriptionListStrc;

struct Unicode;

struct D2MonStatsTxt;

struct D2ItemsTxt;

struct D2StormLinkStrc;

struct D2StormListAStrc;


struct D2StormListArrayStrc;

struct D2StormHashTableStrc;

struct D2StormListStrc;

struct D2Storm4167B0Strc;

struct D2Storm4168F0Strc;

struct D2Storm416A90Strc;

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

struct D2StormHashNodeStrc;

struct D2StormHashTable0052E650Strc;

struct D2FileTimeStrc;

struct D2StormSlotLink00530600Strc;

struct D2StormSlotList00530600Strc;

struct D2StormSlotArray00530600Strc;

struct D2StormHashTable00530600Strc;

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


#include "D2GameFuncs.h"
#include "D2NetApi.h"
#include "FogApi2.h"

extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

typedef void (__fastcall* GAME_ForEachIngameClientCallbackPtr)(D2ClientStrc*, void*);

extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0); // 0x0040B480

int __fastcall GAME_GetUnitGUID(D2UnitStrc* pUnit); // 0x00451F50

void __fastcall GAME_ForEachIngameClient(D2GameStrc* pGame, GAME_ForEachIngameClientCallbackPtr pFn, void* pContext); // 0x0052DED0

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


struct D2NetPacketRecStrc
{
    unsigned char data[MAX_MSG_SIZE];
    int nPacketSize;
    unsigned long dwTickCount;
    D2NetPacketRecStrc* pNext;
};


struct D2Net52BE10Strc
{
    char unk0x00[0xD0];
    char aData[4];
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260


extern "C" const char gszD2NetSourceFile[];

extern int gnConnectionMode;

int gbD2ServerCallbackFunctionsInitialized;                                                        // 0x00883D54


typedef void(__fastcall* UnitDescriptionFunction)(char* szDescription, int nClassId);

extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize); // 0x00681EF0

extern UnitDescriptionFunction gpfnGetDescription[5]; // 0x0073107C

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);


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

struct D2StormListAStrc
{
    int m_linkoffset;
    D2StormOwnedLinkStrc m_terminator;

    D2StormListAStrc()
    {
        m_linkoffset = 0xDDDDDDDD;
        InitializeTerminator();
    }
    ~D2StormListAStrc()
    {
        UnlinkAll();
    }
    D2StormLinkStrc* Link(char* pNode)
    {
        return pNode ? (D2StormLinkStrc*)(pNode + m_linkoffset) : &m_terminator;
    }
    char* Head()
    {
        return m_terminator.Next();
    }
    void InitializeTerminator()
    {
        m_terminator.m_prevlink = &m_terminator;
        m_terminator.m_next = (char*)~(unsigned int)&m_terminator;
    }
    void ChangeLinkOffset(int nLinkOffset)
    {
        if (nLinkOffset != m_linkoffset)
        {
            UnlinkAll();
            m_linkoffset = nLinkOffset;
            InitializeTerminator();
        }
    }
    void LinkNode(char* pNode, int nLinkType, char* pExistingNode)
    {
        D2StormLinkStrc* pLink = Link(pNode);
        pLink->Unlink();
        D2StormLinkStrc* pExistingLink = Link(pExistingNode);
        D2StormLinkStrc* pPrevLink;
        switch (nLinkType)
        {
        case 1:
            pLink->m_prevlink = pExistingLink;
            pLink->m_next = pExistingLink->m_next;
            pExistingLink->NextLink(m_linkoffset)->m_prevlink = pLink;
            pExistingLink->m_next = pNode;
            break;
        default:
            pPrevLink = pExistingLink->m_prevlink;
            pLink->m_prevlink = pPrevLink;
            pLink->m_next = pPrevLink->m_next;
            pPrevLink->m_next = pNode;
            pExistingLink->m_prevlink = pLink;
            break;
        }
    }
    void LinkToTail(char* pNode)
    {
        LinkNode(pNode, 2, 0);
    }
    void UnlinkAll();                                                                                       // 0x0044F8E0
    void sub_0044FC60_DeleteAll();                                                                          // 0x0044FC60
    char* RawNext(char* pNode)
    {
        return Link(pNode)->m_next;
    }
};


struct D2StormListArrayStrc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2StormListAStrc* m_data;
    unsigned int m_chunk;

    void sub_00450110_SetCount(unsigned int nCount);                                                        // 0x00450110
};

struct D2StormHashTableStrc
{
    virtual void InternalDelete(D2SGameDataStrc* pNode);
    virtual D2SGameDataStrc* InternalNew(D2StormListAStrc* pList, unsigned int nExtraBytes, unsigned int nFlags);
    virtual ~D2StormHashTableStrc();
    virtual void Destroy();
    D2StormListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormListArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    unsigned int MaskHash(unsigned int value); // 0x0052E0E0
    void sub_0044FA00_InternalClear(int bWarn);                                                             // 0x0044FA00
    void GrowListArray(); // 0x0052FF20
};

extern unsigned short gwValue_0077905C;

struct D2StormListStrc
{
    int m_linkoffset;
    D2StormLinkStrc m_terminator;
};

struct D2Storm4167B0Strc
{
    D2StormLinkStrc f_0;

    ~D2Storm4167B0Strc();
};

struct D2Storm4168F0Strc
{
    D2StormLinkStrc f_0;

    ~D2Storm4168F0Strc();
};

struct D2Storm416A90Strc
{
    char pad00[0x14C];
    int n14C;
    int n150;
};

struct D2GameListStrc;

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

struct D2StormHashNodeStrc
{
    unsigned int m_hashval;
    D2StormLinkStrc m_linktoslot;
    D2StormLinkStrc m_linktofull;
};

struct D2StormHashTable0052E650Strc
{
    void* m_vtable;
    D2StormListAStrc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormListArrayStrc m_slotlistarray;
    unsigned int m_slotmask;

    char* sub_0052E650_Ptr(unsigned int nHashVal, int nKey);
};


void __fastcall CLIENTS_GetGuildEmblem(D2ClientStrc*, unsigned char*, unsigned char*, unsigned char*); // 0x00539190

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

struct D2StormSlotList00530600Strc
{
    int m_linkoffset;
    D2StormSlotLink00530600Strc m_terminator;

};

struct D2StormSlotArray00530600Strc
{
    unsigned int m_alloc;
    unsigned int m_count;
    D2StormSlotList00530600Strc* m_data;
    unsigned int m_chunk;

};

struct D2StormHashTable00530600Strc
{
    void* m_vtable;
    D2StormSlotList00530600Strc m_fulllist;
    unsigned int m_fullnessIndicator;
    D2StormSlotArray00530600Strc m_slotlistarray;
    unsigned int m_slotmask;

    void GrowListArray();  // 0x0052FF20
    int MonitorFullness(unsigned int nSlot); // 0x00530600
};

int gdwGlobal_00882D14; // 0x00882D14

struct D2GameInfoStrc
{
    int nGameId;
    unsigned int nInitSeed;
    int nClients;
    int nPlayers;
    int nMonsters;
    int nObjects;
    int nItems;
    int nMissiles;
    int nUniqueItems;
    int nNPCs;
    unsigned int dwLastUsedUnitGUID[6];
    int nPathTowardPct;
    int nPathClockPct;
    int nPathCounterPct;
    int nPathAStarPct;
    int nPathFoWallPct;
    int nPathTotalCalls;
    int nFrames;
    int nTime;
    int nFrameRate;
    char szGameName[16];
    char szGamePassword[16];
    char szGameDescription[32];
    unsigned char nArenaTemplate;
    unsigned char nMaxLevelDifference;
    unsigned char nMaxPlayers;
    unsigned char padding0xA7;
    unsigned int nArenaFlags;
    void* pMemoryPool;
};

#define PATHTYPE_ASTAR 1

#define PATHTYPE_TOWARD 2

#define PATHTYPE_MON_CIRCLE_CW 5

#define PATHTYPE_MON_CIRCLE_CCW 6


static int GAME_CountUnitsInLists(D2UnitStrc** pUnitLists);

unsigned long gdwPlayerPos; // 0x00883D4C

D2GameDataTableStrc* gpGameDataTbl; // 0x00883D38

int gnLastGamesUpdateTimeMs; // 0x00883D58

int gnTargetMsPerFrame = 1000 / gnTargetFrameRate; // 0x00883D60


#define BUCKETS 128

#define INFO_DESCRIPTION_SIZE 16

#define GAME_ID_BIAS 1

#define UNLOCK_LINE 4196


struct D2GameNodeStrc
{
    ~D2GameNodeStrc();                                                                                      // 0x0044F820
};

static inline D2GameStrc* GAMELINK_Next(D2GameLinkStrc* pLink)
{
    return (int)pLink->pNext <= 0 ? 0 : pLink->pNext;
}

struct D2GameListStrc
{
    int nLinkOffset;
    D2GameLinkStrc tTerminator;

    D2GameLinkStrc* InlineLink(D2GameStrc* pGame)
    {
        return pGame ? (D2GameLinkStrc*)((char*)pGame + nLinkOffset) : &tTerminator;
    }

    D2GameStrc* InlineNext(D2GameStrc* pGame)
    {
        return GAMELINK_Next(InlineLink(pGame));
    }

    D2GameStrc* RawNext(D2GameStrc* pGame);
    D2GameStrc* Next(D2GameStrc* pGame);
    D2GameStrc* DeleteNode(D2GameStrc* pGame);
};


extern "C" __declspec(dllimport) void* __stdcall CreateThread(void* lpThreadAttributes, unsigned long dwStackSize, unsigned long (__stdcall* lpStartAddress)(D2MessageThreadArgsStrc*), D2MessageThreadArgsStrc* lpParameter, unsigned long dwCreationFlags, unsigned long* lpThreadId); // 0x006CC250

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);          // 0x0040B430


int gnGlobal_00883D3C;                                                                                         // 0x00883D3C

int gnGlobal_00883D40;                                                                                         // 0x00883D40


int gnAct;                                                                                         // 0x00883D44

struct D2ClientInfoStrc;


int __stdcall SERVER_ReadGamePacket(unsigned char* pBuffer, int nSize);                              // 0x0052B2D0

int __stdcall SERVER_ReadSystemPacket(unsigned char* pBuffer, int nSize);                              // 0x0052B2F0

int __stdcall SERVER_ReadAdminPacket(unsigned char* pBuffer, int nSize);                              // 0x0052B310

void __fastcall GAME_ProcessAdminMessage(void* pData, int nSize);                                                       // 0x0052CC20


int __stdcall UNITS_GetInventoryGoldLimit(D2UnitStrc* pUnit);                                               // 0x00622E70

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

struct ShortResponse
{
    unsigned char command;
    char payload[15];
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

extern long gnAdminConnectionCount; // 0x00883D64

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile*);  // 0x006CC208

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile*);  // 0x006CC204

int __stdcall sub_0052B330(unsigned char,int,void*,int);  // 0x0052B330


extern "C" int __cdecl strncmp(const char*,const char*,unsigned int);


enum { MODE_MASK = 15 };

struct D2GameStatisticsStrc;


struct HASHKEY_NONE;

struct D2GameHashLinkStrc;

struct D2GameHashListStrc;


struct D2GameStatisticsStrc
{
    int nGamesCount;
    int nActiveMonsters;
    int nInactiveMonsters;
    int nPlayersCount;
};

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

extern "C" const char gszGameSourceFile; // 0x006D5D1C

static unsigned int gnPeakMemoryUsageInLast10s; // 0x00883D48

static unsigned int gnPreviousMemUsageTick; // 0x00883D68


struct D2PoolSystemStrc;

static int gnFrameRate = 25;                                                                      // 0x00731010
#include "StormApi2.h"
#include "D2CommonApi3.h"




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

struct D2DrlgCoordsStrc;


struct D2ObjectControlStrc;


struct D2ObjInitFnStrc;

struct D2UnkPlrMsgStrc;

struct D2PlayerDataStrc;


struct D2NpcGambleStrc;

struct D2NpcRecordStrc;

struct D2ArenaStrc;

struct D2RosterIterateStrc;

struct D2UnitProxyArgStrc;


enum D2C_MonStatsTxtFlagIndices
{
    MONSTATSFLAGINDEX_INTERACT = 9,
};


extern unsigned int gdwBitMasks[]; // 0x006CE268

extern D2UnkPlrMsgStrc gaUnitModeMessages[20]; // 0x007319E8









typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

extern int gnVirtualPlayerCount; // 0x00883D70

void __fastcall D2GAME_SetSkills(int pUnit, int nSkillId, int nSkillLevel, int bRemove); // 0x0056DEB0




void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790


#define CLIENTS_MAX_UPDATES 55u

typedef int (__fastcall* QUESTUNITITERATE)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pData);

#pragma pack(push, 1)

struct D2SavePartPacketStrc
{
    unsigned char nHeader;
    unsigned char nPartDataSize;
    unsigned char bFirstPart;
    int nSaveHeaderSize;
    unsigned char aData[0x100];
};

#pragma pack(pop)

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds);                       // 0x006CC258

unsigned long gdwLastClientsUpdateTick;                                                                               // 0x00883D5C


D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetHead(D2ClientStrc* pClient);                         // 0x005392E0




extern "C" const char gszSGameDataTypeName[];                                                               // 0x0070F56C

void __cdecl FOG_CreateNewPoolSystem(void* pReserved, const char* szName, int nSize, int nBlockSize); // 0x00409DD0


unsigned short __cdecl sub_0052C170_AllocGameId();


int __fastcall OBJRGN_AllocObjectControl(D2GameStrc* pGame); // 0x00546C60


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

// 0x00520AE0
int __cdecl GAME_GetAbortFlag()
{
    return gdwGlobal_00882528;
}

// 0x00520AF0
int __cdecl GAME_GetLastStatus()
{
    return gnLastStatus;
}

// 0x00520B00
void* __cdecl GAME_GetReplyText()
{
    return gszReplyText;
}

// 0x00520B10
int __cdecl GAME_GetCreateAccountResult()
{
    return gnCreateAccountResult;
}

// 0x00520B20
int __cdecl GAME_GetChangePasswordResult()
{
    return gnChangePasswordResult;
}

// 0x0052A600
int __fastcall GAME_DeleteBigNum(void* pArg)
{
    return SBigDel(pArg);
}

// 0x0052BE20
void __cdecl GAME_LogMessage(int nLevel, const char* szFormat, ...)
{
}

// 0x0052BE30
void __stdcall GAME_DefaultCloseGame(int nUnused1, int nUnused2)
{
}

// 0x0052BE50
void __stdcall GAME_DefaultGetDatabaseCharacter(int nUnused1, int nUnused2)
{
}

// 0x0052BEA0
void __stdcall GAME_DefaultSaveDatabaseGuild(int nUnused1)
{
}

// 0x0052BEB0
void __stdcall GAME_DefaultUnlockDatabaseCharacter(int nUnused1)
{
}

// 0x0052BEC0
void __stdcall sub_0052BEC0_Nop(int nUnused1, int nUnused2)
{
}

// 0x0052BEE0
void __stdcall GAME_DefaultUpdateGameInformation(int nUnused1, int nUnused2)
{
}

// 0x0052BF00
int __cdecl GAME_DefaultGetValue()
{
    return 0;
}

// 0x0052BF10
void __stdcall GAME_DefaultRelockDatabaseCharacter(int nUnused1)
{
}

// 0x0052BF20
const char* __cdecl GAME_DefaultLoadComplete()
{
    return gszEmptyLoadComplete;
}

// 0x0052BF30
void __stdcall sub_0052BF30_Nop(int nUnused1, int nUnused2)
{
}

// 0x0052BF50
int __cdecl sub_0052BF50_Return0()
{
    return 0;
}

// 0x0052BF60
int __cdecl sub_0052BF60_Return0()
{
    return 0;
}

// 0x0052BF70
int __cdecl sub_0052BF70_Return0()
{
    return 0;
}

void __stdcall SMemZero(void* pDest, unsigned int nSize);                                                   // 0x0041D300

// 0x0052BF80
void __fastcall GAME_ZeroBlock8(void* pData)
{
    SMemZero(pData, 8);
}

// 0x0052BF90
const void* __cdecl sub_0052BF90_GetData6E0550()
{
    return gData_006E0550;
}

// 0x0052BFA0
const void* __cdecl sub_0052BFA0_GetData6E0568()
{
    return gData_006E0568;
}


void __fastcall CLIENTS_Release();                                                                          // 0x00537730

void __fastcall SUNITPROXY_ClearGlobalItemCache();                                                          // 0x00537120

extern unsigned short gwGameId;                                                                    // 0x00731000

// 0x0052C030
int __stdcall GAME_Shutdown()
{
    CLIENTS_Release();
    DeleteCriticalSection(&gGameListLock);
    SUNITPROXY_ClearGlobalItemCache();
    gwGameId = 1;
    gpGameDataTbl = 0;
    gnAct = 0;
    return 1;
}

// 0x0052C060
int __fastcall GAME_GetGameGUIDFromGameId(unsigned short nGameId)
{
    int nGUID = 0;
    EnterCriticalSection(&gGameListLock);
    if (gnGamesGUIDs[nGameId - 1] && gnGamesGUIDs[nGameId - 1] != D2GameReservedSlotHandle)
    {
        nGUID = gnGamesGUIDs[nGameId - 1];
    }
    LeaveCriticalSection(&gGameListLock);
    return nGUID;
}

// 0x0052C0A0
void __stdcall GAME_InitGameDataTable(D2GameDataTableStrc* pGameDataTbl, void* pGameList)
{
    D2_ASSERT(pGameDataTbl, 347);

    gpGameDataTbl = pGameDataTbl;

    D2_ASSERT(pGameList, 349);
}

// 0x0052C0E0
void __stdcall GAME_SetServerCallbackFunctions(D2ServerCallbackFunctions* pD2ServerCallbackFunctions)
{
    if (pD2ServerCallbackFunctions)
    {
        gpD2EventCallbackTable = pD2ServerCallbackFunctions;
        gbD2ServerCallbackFunctionsInitialized = 1;
    }
    else
    {
        gpD2EventCallbackTable = 0;
        gbD2ServerCallbackFunctionsInitialized = 0;
    }
}

// 0x0052C110
void __stdcall GAME_SetReservedGameGUID(int nGameGUID, unsigned short nGameId)
{
    EnterCriticalSection(&gGameListLock);
    if (gnGamesGUIDs[nGameId - 1] == D2GameReservedSlotHandle)
    {
        gnGamesGUIDs[nGameId - 1] = nGameGUID;
        LeaveCriticalSection(&gGameListLock);
        return;
    }

    D2_ASSERT(0, 394);
}


typedef void* HGAMEDATA;

extern HGAMEDATA ghGameArray[1024];                                                                 // 0x00882D38

// 0x0052C170
unsigned short __fastcall GAME_ReserveGameId()
{
    EnterCriticalSection(&gGameListLock);

    const unsigned short nBaseId = gwGameId;
    int nGameId = gwGameId++;
    if (gwGameId > 1024u)
    {
        gwGameId = 1;
    }

    if (ghGameArray[(unsigned short)nGameId - 1])
    {
        while (1)
        {
            nGameId = gwGameId++;
            if (gwGameId > 1024u)
            {
                gwGameId = 1;
            }

            if ((unsigned short)nGameId == (unsigned short)nBaseId)
            {
                LeaveCriticalSection(&gGameListLock);
                return 0;
            }

            if (!ghGameArray[(unsigned short)nGameId - 1])
            {
                break;
            }
        }
    }

    ghGameArray[(unsigned short)nGameId - 1] = (HGAMEDATA)-1;
    LeaveCriticalSection(&gGameListLock);
    return nGameId;
}

// 0x0052C210
void __fastcall GAME_ClientEnterAct(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    D2_ASSERT(pClient, 0x1C4);
    LEVEL_LoadAct(pGame, pClient->bAct);
    LEVEL_SynchronizeDayNightCycleWithClient(pGame, pClient);
    CLIENTS_SetClientState(pClient, 2);
}

// Out of line as in the original: it takes an argument in esi, a convention the compiler gives only a static whose callers are all in this object.
// 0x0052C260
static __declspec(noinline) void GAME_SendGameInit(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    D2GAME_PACKETS_SendPacket0x01(pClient, 1, pGame);
    D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 0);
    CLIENTS_SetClientState(pClient, 1);
}

static int gnInitSeed = -1;                                                                        // 0x00731004

// 0x0052C320
void __stdcall GAME_SetInitSeed(int nInitSeed)
{
    gnInitSeed = nInitSeed;
}

// 0x0052C330
int __fastcall SrvVerifyCreateNewGame(int nClientId, D2GSPacketClt66* pPacket)
{
    const char* szGameName = pPacket->szGameName;
    const unsigned char nPlayerClass = pPacket->nPlayerClass;
    const char* szClientName = pPacket->szClientName;
    const unsigned int nGameFlags = pPacket->nGameFlags;
    char szCurrentGame[16];

    if (gpD2EventCallbackTable && pPacket->nGameType)
    {
        return 0;
    }
    if (!CCMD_IsStringZeroTerminated(szClientName, 16))
    {
        return 0;
    }
    if (pPacket->nLocale > 14u)
    {
        return 0;
    }
    if (!CCMD_IsStringZeroTerminated(szGameName, 16))
    {
        return 0;
    }
    if (!(nGameFlags & 6))
    {
        return 0;
    }
    if (!CLIENTS_GetNameById(nClientId, szCurrentGame))
    {
        return 0;
    }
    if (!CLIENTS_GetCanonicalName(szClientName, szCurrentGame))
    {
        return 0;
    }
    return nPlayerClass < 7u;
}

// 0x0052C3E0
void __stdcall D2Game_10056(int nValue)
{
    gnGlobal_00883D3C = nValue;
    gnGlobal_00883D40 = 0;
}

// 0x0052C400
void __fastcall GAME_UpdatePing(int nClientId, int nTick, int nDelay, int nUnused)
{
    CLIENTS_UpdatePing(nClientId, nTick, nDelay, nUnused);
}

// 0x0052C410
void __fastcall GAME_SynchronizePlayerWithClients(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    D2UnitStrc* hNewUnit = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (!hNewUnit)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x5A1);
        exit(-1);
    }
    for (D2ClientStrc* pOtherClient = pGame->pClientList; pOtherClient; pOtherClient = pOtherClient->pNext)
    {
        if (pOtherClient != pClient)
        {
            D2UnitStrc* pOtherPlayer = CLIENTS_GetPlayerFromClient(pOtherClient, 0);
            if (pOtherPlayer)
            {
                SCMD_SendPlayerJoinAndPets(pClient, pOtherPlayer, pOtherClient);
                SCMD_SendPlayerJoinAndPets(pOtherClient, hNewUnit, pClient);
                if (pOtherPlayer->pInventory)
                {
                    for (D2CorpseStrc* pCorpse = INVENTORY_GetFirstCorpse(pOtherPlayer->pInventory); pCorpse; pCorpse = INVENTORY_GetNextCorpse(pCorpse))
                    {
                        const int nCorpseGUID = INVENTORY_GetUnitGUIDFromCorpse(pCorpse);
                        if (nCorpseGUID != -1)
                            D2GAME_PACKETS_SendPacket0x8E(pClient, GAME_GetUnitGUID(pOtherPlayer), nCorpseGUID, 1);
                    }
                }
            }
        }
    }
    SCMD_SendPlayerJoinAndPets(pClient, hNewUnit, pClient);
    ARENA_SendScoresToClient(pGame, pClient);
}

// 0x0052C500
void __fastcall GAME_SendPacket0x5CToAllConnectedClients(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (pPlayer)
    {
        for (D2ClientStrc* pClient = pGame->pClientList; pClient; pClient = pClient->pNext)
        {
            if (pClient->dwClientState == CLIENTSTATE_INGAME)
            {
                D2GAME_PACKETS_SendPacket0x5C(pClient, GAME_GetUnitGUID(pPlayer));
            }
        }
    }
}

// 0x0052C550
int __fastcall GAME_VerifyJoinAct(int nClientId)
{
    return CLIENTS_CheckState(nClientId, 1) != 0;
}

// 0x0052C570
int __fastcall GAME_AbortClient(D2GameStrc* pGame, int nClientId, int szFile, int nLine)
{
    if (pGame && CLIENTS_IsInGame(pGame, nClientId))
    {
        ClientRemoveFromGame(pGame, nClientId, 1);
    }

    return SERVER_HackListClient(nClientId, szFile, nLine);
}

// 0x0052C5B0
static int IsClientNameValid(const char* szClientName, int nLength)
{
    int bContainsSpecialCharacter = 0;
    for (int i = 0; i < nLength; ++i)
    {
        switch (*szClientName++)
        {
        case '\'':
        case '-':
        case '_':
            if (bContainsSpecialCharacter || i == 0 || *szClientName == '\0')
            {
                return 0;
            }
            bContainsSpecialCharacter = 1;
            break;
        case 'A': case 'B': case 'C': case 'D': case 'E': case 'F': case 'G': case 'H': case 'I':
        case 'J': case 'K': case 'L': case 'M': case 'N': case 'O': case 'P': case 'Q': case 'R':
        case 'S': case 'T': case 'U': case 'V': case 'W': case 'X': case 'Y': case 'Z':
        case 'a': case 'b': case 'c': case 'd': case 'e': case 'f': case 'g': case 'h': case 'i':
        case 'j': case 'k': case 'l': case 'm': case 'n': case 'o': case 'p': case 'q': case 'r':
        case 's': case 't': case 'u': case 'v': case 'w': case 'x': case 'y': case 'z':
            break;
        case '\0':
            return i != 0;
        default:
            return 0;
        }
    }
    return 0;
}

// 0x0052C690
int __fastcall SrvVerifyJoinGame(int nClientId, unsigned short nGameId, unsigned char nPlayerClass, const char* szClientName, int nTokenId, char* pszInOutAccountName, int* pOutCharSaveTransactionToken, unsigned char nLocale, int* a9, int* a10, int* a11, int* a12, int a13)
{
    if (!CCMD_IsStringZeroTerminated(szClientName, 16))
    {
        return 0;
    }
    if (nLocale >= 14)
    {
        return 0;
    }
    char szGameName[16];
    if (!CLIENTS_GetNameById(nClientId, szGameName))
    {
        return 0;
    }
    if (!CLIENTS_GetCanonicalName(szClientName, szGameName))
    {
        return 0;
    }
    if (!GAME_GetGameGUIDFromGameId(nGameId))
    {
        return 0;
    }
    if (nPlayerClass >= 7)
    {
        return 0;
    }
    if (!IsClientNameValid(szClientName, 16))
    {
        return 0;
    }
    if (gpD2EventCallbackTable)
    {
        D2_ASSERT(!IsBadCodePtr((FARPROC)gpD2EventCallbackTable->pfFindPlayerToken), 1883);
        if (!gpD2EventCallbackTable->pfFindPlayerToken(szClientName, nTokenId, nGameId, pszInOutAccountName, pOutCharSaveTransactionToken, a9, a10, a11, a12))
        {
            return 0;
        }
    }
    return 1;
}

// 0x0052C7C0
static inline void GAME_RemoveGameGUID(int nGameGUID)
{
    EnterCriticalSection(&gGameListLock);
    for (int i = 0; i < 1024; ++i)
    {
        if (gnGamesGUIDs[i] == nGameGUID)
        {
            gnGamesGUIDs[i] = 0;
        }
    }
    LeaveCriticalSection(&gGameListLock);
}

// 0x0052C7F0
void __fastcall SrvFreeGame(int nGameGUID, D2GameStrc* pGame)
{
    GAME_RemoveGameGUID(nGameGUID);

    MONSTERREGION_FreeAll(pGame->pMemoryPool, pGame->pMonReg);
    OBJRGN_FreeObjectControl(pGame);
    QUESTS_QuestFree(pGame);
    SUNITPROXY_FreeNpcControl(pGame);
    CLIENTS_FreeClientsFromGame(pGame);
    LEVEL_RemoveAllUnits(pGame);
    SUNITINACTIVE_FreeInactiveUnitLists(pGame);
    EVENT_FreeEventQueue(pGame);
    PARTY_FreePartyControl(pGame);
    ARENA_FreeArena(pGame);

    for (int i = 0; i < NUM_ACTS; ++i)
    {
        if (pGame->pAct[i])
        {
            DUNGEON_FreeAct(pGame->pAct[i]);
            pGame->pAct[i] = 0;
        }
    }

    if (pGame->pMemoryPool)
    {
        FOG_DestroyMemoryPoolSystem((D2PoolSystemStrc*)pGame->pMemoryPool);
    }

    D2CriticalSectionStrc* pCriticalSection = pGame->lpCriticalSection;
    pGame->lpCriticalSection = 0;
    LeaveCriticalSection(pCriticalSection);
    DeleteCriticalSection(pCriticalSection);
    FOG_FreePool(0, pCriticalSection, ".\\GAME\\Game.cpp", 0x8DA, 0);
}

// 0x0052C8E0
int __fastcall GAME_VerifyEndGame(int nClientId)
{
    return CLIENTS_CheckState(nClientId, 4) != 0;
}

// 0x0052C900
void __fastcall GAME_TriggerClientSave(D2ClientStrc* pClient, D2GameStrc* pGame)
{
    if (!pClient)
        return;
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (!pPlayer || !D2GAME_SAVE_WriteFile(pGame, pPlayer, CLIENTS_GetName(pClient), 1))
        return;
    D2ClientStrc* volatile pNext; // volatile only keeps pNext in its stack slot across the loop body, as the original does
    D2ClientStrc* i = pGame->pClientList;
    for (; i; i = pNext)
    {
        pNext = i->pNext;
        D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(i, 0);
        if (pPlayer)
        {
            if (i != pClient)
                D2GAME_SAVE_WriteFile(pGame, pPlayer, CLIENTS_GetName(i), 0);
            if (gpD2EventCallbackTable && gpD2EventCallbackTable->pfUpdateCharacterLadder && pGame->dwGameType)
            {
                unsigned char nBackgroundColor, nForegroundColor, nEmblemType;
                CLIENTS_GetGuildEmblem(i, &nBackgroundColor, &nForegroundColor, &nEmblemType);
                const int nClassId = pPlayer->dwClassId;
                gpD2EventCallbackTable->pfUpdateCharacterLadder(CLIENTS_GetName(i), nClassId, STATLIST_GetUnitBaseStat(pPlayer, STAT_LEVEL, 0), (unsigned int)STATLIST_GetUnitBaseStat(pPlayer, STAT_EXPERIENCE, 0), CLIENTS_GetFlags(i), &i->nSaveCreationTimestamp);
            }
        }
    }
}

// 0x0052CA10
void __fastcall GAME_SaveAllPlayers(D2GameStrc* pGame)
{
    D2ClientStrc* i = pGame->pClientList;
    while (i)
    {
        D2ClientStrc* pNext = i->pNext;
        D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(i, 0);
        if (pPlayer)
        {
            D2GAME_SAVE_WriteFile(pGame, pPlayer, CLIENTS_GetName(i), 0);
            if (gpD2EventCallbackTable && gpD2EventCallbackTable->pfUpdateCharacterLadder && pGame->dwGameType)
            {
                unsigned char nBackgroundColor, nForegroundColor, nEmblemType;
                CLIENTS_GetGuildEmblem(i, &nBackgroundColor, &nForegroundColor, &nEmblemType);
                const int nClassId = pPlayer->dwClassId;
                gpD2EventCallbackTable->pfUpdateCharacterLadder(CLIENTS_GetName(i), nClassId, STATLIST_GetUnitBaseStat(pPlayer, STAT_LEVEL, 0), (unsigned int)STATLIST_GetUnitBaseStat(pPlayer, STAT_EXPERIENCE, 0), CLIENTS_GetFlags(i), &i->nSaveCreationTimestamp);
            }
        }
        i = pNext;
    }
}

// 0x0052CAF0
void __fastcall SrvDisconnectClient(D2GameStrc* pGame, D2ClientStrc* pClient, int nEventType)
{
    if (!pClient)
        return;

    const int nClientId = CLIENTS_GetClientId(pClient);

    D2GSPacketSrv5A tPacket = {};
    tPacket.nHeader = 0x5A;
    tPacket.nType = nEventType;
    tPacket.nColor = 4;
    tPacket.dwParam = 0;
    CLIENTS_CopyAccountNameToBuffer(pClient, &tPacket.szText[16]);
    tPacket.szText[31] = '\0';
    SStrCopy(tPacket.szText, CLIENTS_GetName(pClient), 16);
    PLRMSG_BroadcastEventMessage(pGame, &tPacket);

    ClientRemoveFromGame(pGame, CLIENTS_GetClientId(pClient), 1);
    D2GAME_PACKETS_SendGameLeft(nClientId);
    D2NET_10016(nClientId);
}

// 0x0052CBB0
void __fastcall GAME_FindGameOwnerCallback(D2ClientStrc* pClient, void* pContext)
{
    D2ClientStrc** ppClient = (D2ClientStrc**)pContext;
    if (CLIENT_IsGameOwner(pClient))
    {
        *ppClient = pClient;
    }
}

// 0x0052CBD0
void __fastcall GAME_FindFirstClientCallback(D2ClientStrc* pClient, void* pContext)
{
    D2ClientStrc** ppClient = (D2ClientStrc**)pContext;
    if (!*ppClient)
    {
        *ppClient = pClient;
    }
}

// 0x0052CBE0
int __fastcall GAME_VerifyDisconnect(int nClientId)
{
    char szClientName[16];
    return CLIENTS_GetNameById(nClientId, szClientName) != 0;
}

// 0x0052CC10
void __fastcall GAME_SendHeaderAndRelease(int nClientId)
{
    D2GAME_PACKETS_SendGameLeft(nClientId);
    D2NET_10016(nClientId);
}

// 0x0052CC20
void __fastcall GAME_ProcessAdminMessage(void* pData,int nSize) {
 if (!gpD2EventCallbackTable) return;
 Request* request=(Request*)pData;
 int client=request->client;
 ShortResponse response;
 char received[16];
 switch(request->command) {
 case 0xFA:
  CLIENT_ObjectCall_6BED90(client,(int)received,16);
  InterlockedIncrement(&gnAdminConnectionCount);
  response.command=REPLY_FA;
  sub_0052B330(2,client,&response,16);
  break;
 case 0xFB:
  CLIENT_ObjectCall_6BED90(client,(int)received,16);
  response.command=REPLY_FB;
  sub_0052B330(2,client,&response,16);
  D2NET_10016(client);
  InterlockedDecrement(&gnAdminConnectionCount);
  break;
 case 0xFC:
  CLIENT_ObjectCall_6BED90(client,(int)received,16);
  response.command=REPLY_FC;
  sub_0052B330(2,client,&response,16);
  break;
 case 1:
 case 0xFD:
  if(gpD2EventCallbackTable->pfGetGameServerInfo && gpD2EventCallbackTable->pfServerLogMessage) {
   ServerInfo info;
   Reply reply;
   ((void (__fastcall*)(ServerInfo*))gpD2EventCallbackTable->pfGetGameServerInfo)(&info);
   reply.command=request->command;
   reply.a=info.a;reply.b=info.b;reply.c=info.c;reply.d=info.d;reply.e=info.e;
   reply.f=info.f;reply.g=info.g;reply.h=info.h;reply.i=info.i;reply.j=info.j;
   SStrCopy(reply.description,info.description,128);
   reply.a9=info.a8;
   reply.f10b=info.ac;
   reply.f10f=info.b0;
   reply.f113=info.b8-gnAdminConnectionCount;
   reply.f117=info.bc;
   reply.ad=reply.f10b+reply.f10f;
   reply.b1=info.b4;
   reply.b5=reply.f113+reply.f117;
   reply.b9=info.c0;
   reply.bd=info.ec;
   reply.c1=info.f0;
   reply.e1=info.f110;
   reply.e5=info.c4;reply.e9=info.c8;reply.ed=info.cc;reply.f1=info.d0;
   reply.f5=info.d4;reply.f7=info.d6;reply.fb=info.da;reply.ff=info.de;
   reply.f103=info.e2;reply.f107=info.e6;
   memset(reply.reserved,0,0x4A);
   int packetSize;
   switch(reply.command) {
   case 1: packetSize=0x165; break;
   default: packetSize=0xBD; break;
   }
   sub_0052B330(2,client,&reply,packetSize);
  }
  break;
 }
}

// 0x0052CFE0
void __fastcall GAME_ProcessNetworkMessages()
{
    unsigned char buffer[512];
    int nSize;

    do
    {
        nSize = SERVER_ReadSystemPacket(buffer, 512);
        if (nSize != -1)
        {
            CCMD_ProcessClientSystemMessage(buffer, nSize);
        }
    } while (nSize != -1);

    do
    {
        nSize = SERVER_ReadGamePacket(buffer, 512);
        if (nSize != -1)
        {
            ProcessClientMessage(buffer, nSize);
        }
    } while (nSize != -1);

    do
    {
        nSize = SERVER_ReadAdminPacket(buffer, 512);
        if (nSize != -1)
        {
            GAME_ProcessAdminMessage(buffer, nSize);
        }
    } while (nSize != -1);
}

// 0x0052D090
static inline void GAME_CompressRoomUnits(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    D2UnitStrc* pNextUnit = 0;
    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pNextUnit)
    {
        pNextUnit = pUnit->ptRoomNext;
        SUNITINACTIVE_CompressUnitIfNeeded(pGame, pUnit);
    }
}

// 0x0052D0C0
static inline void GAME_PopulateRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    SUNIT_SpawnPresetUnitsInRoom(pGame, pRoom);
    SUNITINACTIVE_RestoreInactiveUnits(pGame, pRoom);
    OBJECTS_PopulationHandler(pGame, pRoom);
    D2GAME_PopulateRoom(pGame, pRoom);
}

// 0x0052D0F0
void __fastcall GAME_ActivateRoom(D2GameStrc* pGame, D2ActiveRoomStrc* pRoom)
{
    MONSTERREGION_TrySpawnWanderingMonster(pGame, pRoom);

    if (!(pRoom->dwFlags & 1))
    {
        GAME_PopulateRoom(pGame, pRoom);
        pRoom->dwFlags |= 1;
        D2Common_10075(pRoom, 1);
    }
    else
    {
        if (!D2Common_10074(pRoom))
        {
            SUNITINACTIVE_RestoreInactiveUnits(pGame, pRoom);
            D2Common_10075(pRoom, 1);
        }
    }
}

// 0x0052D2E0
static inline void GAME_FreeInactiveRooms(D2GameStrc* pGame)
{
    for (int i = 0; i < 5; ++i)
    {
        if (pGame->pAct[i])
        {
            DUNGEON_UpdateAndFreeInactiveRooms(pGame->pAct[i]);
        }
    }
}

void __fastcall sub_M118_Emit_0052D000(D2GameStrc* pGame, int nAct)
{
    for (D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(pGame->pAct[nAct]); pRoom; pRoom = DUNGEON_GetRoomFromAct(pGame->pAct[nAct + 1]))
    {
        if (D2Common_10074(pRoom))
        {
            GAME_PopulateRoom(pGame, pRoom);
        }
        else
        {
            GAME_CompressRoomUnits(pGame, pRoom);
        }
    }
    GAME_FreeInactiveRooms(pGame);
}

// 0x0052D160
static void GAME_UpdatePendingRooms(D2GameStrc* pGame)
{
    D2_ASSERT(pGame, 0xC60);

    for (int i = 0; i < 5; ++i)
    {
        if (pGame->pAct[i] && pGame->pAct[i]->bHasPendingRoomsUpdates)
        {
            for (D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(pGame->pAct[i]); pRoom; pRoom = pRoom->pRoomNext)
            {
                MONSTERREGION_TrySpawnWanderingMonster(pGame, pRoom);

                if (!(pRoom->dwFlags & 1))
                {
                    SUNIT_SpawnPresetUnitsInRoom(pGame, pRoom);
                    SUNITINACTIVE_RestoreInactiveUnits(pGame, pRoom);
                    OBJECTS_PopulationHandler(pGame, pRoom);
                    D2GAME_PopulateRoom(pGame, pRoom);
                    pRoom->dwFlags |= 1;
                    D2Common_10075(pRoom, 1);
                }
                else if (!D2Common_10074(pRoom))
                {
                    SUNITINACTIVE_RestoreInactiveUnits(pGame, pRoom);
                    D2Common_10075(pRoom, 1);
                }
            }

            pGame->pAct[i]->bHasPendingRoomsUpdates = 0;
        }
    }
}

// 0x0052D870
void __fastcall GAME_UpdateProgress(D2GameStrc* pGame)
{
    const int nDebugBreakTrigger = pGame->nDebugBreakTrigger;
    ++pGame->dwGameFrame;

    if (nDebugBreakTrigger == 1)
    {
        *((unsigned char*)0) = 0;
    }
    else if (nDebugBreakTrigger == 2)
    {
        *((unsigned char*)0xC0000001) = 0;
    }
    else if (nDebugBreakTrigger == 3)
    {
        D2_ASSERT(0, 0xE1C);
    }
    else if (nDebugBreakTrigger == 4)
    {
        FOG_Alloc(0x70000000, ".\\GAME\\Game.cpp", 0xE20, 0);
    }

    GAME_UpdateEnvironment(pGame);
    GAME_UpdateFrameRate(pGame);
    GAME_UpdatePendingRooms(pGame);
    EVENT_IterateEvents(pGame);
    GAME_UpdateAllClients(pGame);
    LEVEL_UpdateQueuedUnitsInAllActs(pGame);
    LEVEL_FreeDrlgDeletes(pGame);

    if (!(pGame->dwGameFrame % 20))
    {
        QUESTS_QuestUpdater(pGame);
    }

    if (!(pGame->dwGameFrame % 12))
    {
        GAME_RemoveUntilableRooms(pGame);
    }

    if (!(pGame->dwGameFrame % 11))
    {
        for (int i = 0; i < 5; ++i)
        {
            if (pGame->pAct[i])
            {
                DUNGEON_UpdateAndFreeInactiveRooms(pGame->pAct[i]);
            }
        }
    }

    GAME_DeleteInactiveItems(pGame);
}

// 0x0052D240
void __stdcall GAME_RemoveUntilableRooms(D2GameStrc* pGame)
{
    for (int i = 0; i < NUM_ACTS; ++i)
    {
        if (pGame->pAct[i])
        {
            D2ActiveRoomStrc* pNextRoom = 0;
            for (D2ActiveRoomStrc* pRoom = DUNGEON_GetRoomFromAct(pGame->pAct[i]); pRoom; pRoom = pNextRoom)
            {
                pNextRoom = pRoom->pRoomNext;
                if (D2Common_10081_GetTileCountFromRoom(pRoom) > 10 && DUNGEON_TestRoomCanUnTile(pGame->pAct[i], pRoom))
                {
                    GAME_CompressRoomUnits(pGame, pRoom);

                    DUNGEON_RemoveRoomFromAct(pGame->pAct[i], pRoom);
                }
            }
        }
    }
}

// Out of line as in the original: it takes an argument in edi, a convention the compiler gives only a static whose callers are all in this object.
// 0x0052D310
static __declspec(noinline) void GAME_DeleteInactiveItems(D2GameStrc* pGame)
{
    if (!(pGame->dwGameFrame % 1500))
    {
        for (int i = 0; i < 5; ++i)
        {
            ITEMS_DeleteInactiveItems(pGame, i);
            SUNITINACTIVE_DeleteExpiredItemNodes(pGame, i);
        }
    }
}

// 0x0052D350
void __stdcall GAME_CheckClientHeartbeats(D2GameStrc* pGame, int* pbDisconnected)
{
    if (!gbCheckHeartbeat)
    {
        return;
    }

    *pbDisconnected = 0;
    const unsigned int nTickCount = GetTickCount();
    D2ClientStrc* pClient = pGame->pClientList;
    while (pClient)
    {
        D2ClientStrc* pNext = pClient->pNext;
        const int bHardcore = CLIENTS_CheckFlag(pClient, 4);
        if (nTickCount > pClient->dwLastPacketTick && (bHardcore && nTickCount - pClient->dwLastPacketTick > 10000 && pClient->dwPingsCount > 10 || nTickCount - pClient->dwLastPacketTick > 45000 || pClient->dw504) && gpD2EventCallbackTable)
        {
            D2GAME_SAVE_WriteFile(pGame, CLIENTS_GetPlayerFromClient(pClient, 0), CLIENTS_GetName(pClient), 0);
            *pbDisconnected = 1;
            SrvDisconnectClient(pGame, pClient, 0);
        }
        pClient = pNext;
    }

    if (*pbDisconnected)
    {
        GAME_SaveAllPlayers(pGame);
    }
}

// 0x0052D440
static void GAME_UpdateAllClients(D2GameStrc* pGame)
{
    {
        int bUpdateLadder = 0;
        int bPlayerDisconnected = 0;

        if (!(pGame->dwGameFrame % 8192))
        {
            bUpdateLadder = 1;
        }

        D2_ASSERT(ARENA_NeedsClientUpdate(pGame), 0xD31);

        GAME_CheckClientHeartbeats(pGame, &bPlayerDisconnected);

        if (bUpdateLadder && !bPlayerDisconnected)
        {
            GAME_SaveAllPlayers(pGame);
        }
    }

    D2ClientStrc* pClient = pGame->pClientList;
    while (pClient)
    {
        D2ClientStrc* pNext = pClient->pNext;

        switch (pClient->dwClientState)
        {
        case 3:
        {
            CLIENTS_SynchronizePlayer(pGame, pClient);

            if (D2Common_10073(pClient->hRoom) && CLIENTS_GetPlayerFromClient(pClient, 0))
            {
                GAME_LogMessage(6, "[JOIN 6] %d clientid, sUpdateClients: SCMD_STARTACT - Player(%s)", pClient->dwClientId, pClient->szName);
                D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 4);
                CLIENTS_SetClientState(pClient, 4);

                D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
                if (pPlayer)
                {
                    D2GAME_ITEMS_UpdateInventoryItems(pGame, pPlayer, 0, 1);
                }

                GAME_SynchronizePlayerWithClients(pGame, pClient);
                PLAYERLIST_InitializePlayerRelations(pGame, CLIENTS_GetPlayerFromClient(pClient, 1));

                if (gpD2EventCallbackTable)
                {
                    pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
                    if (pPlayer && gpD2EventCallbackTable->pfEnterGame)
                    {
                        const int nClassId = pPlayer->dwClassId;
                        gpD2EventCallbackTable->pfEnterGame(pGame->nGameId, pClient->szName, nClassId, STATLIST_UnitGetStatValue(pPlayer, STAT_LEVEL, 0), pClient->nSaveFlags);
                    }
                }

                D2GSPacketSrv5A packet5A = {};
                packet5A.nHeader = 0x5A;
                packet5A.nType = 2;
                packet5A.nColor = 4;
                packet5A.dwParam = 0;
                packet5A.szText[16] = '\0';

                char szAccountName[256];
                CLIENTS_CopyAccountNameToBuffer(pClient, szAccountName);
                if (strlen(szAccountName) != 0)
                {
                    SStrCopy(&packet5A.szText[16], szAccountName, 16);
                    packet5A.szText[31] = '\0';
                }

                SStrCopy(packet5A.szText, pClient->szName, 16);
                PLRMSG_BroadcastEventMessage(pGame, &packet5A);
            }
            break;
        }
        case 4:
        {
            CLIENTS_SynchronizePlayer(pGame, pClient);
            break;
        }
        case 5:
        {
            CLIENTS_SynchronizePlayer(pGame, pClient);

            if (D2Common_10073(pClient->hRoom))
            {
                D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 4);
                CLIENTS_SetClientState(pClient, 4);

                D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
                if (pPlayer)
                {
                    D2GAME_ITEMS_UpdateInventoryItems(pGame, pPlayer, 0, 1);
                }
            }
            break;
        }
        }

        pClient = pNext;
    }
}

// 0x0052D720
static void GAME_UpdateFrameRate(D2GameStrc* pGame)
{
    const unsigned int nTickCount = GetTickCount();
    const unsigned int nTickDiff = nTickCount - pGame->nPreviousUpdateTickCount;
    if (nTickDiff >= 1000)
    {
        pGame->nFrameRate = 1000 * pGame->nFramesSinceLastFrameRateUpdate / nTickDiff;
        pGame->nFramesSinceLastFrameRateUpdate = 0;
        pGame->nPreviousUpdateTickCount = nTickCount;
        gnFrameRate = pGame->nFrameRate;

        const unsigned int nMemoryUsage = FOG_GetMemoryUsage((D2PoolSystemStrc*)pGame->pMemoryPool);
        if (nTickCount - gnPreviousMemUsageTick > 10000)
        {
            gnPreviousMemUsageTick = nTickCount;
            gnPeakMemoryUsageInLast10s = nMemoryUsage;
        }
        else if (nMemoryUsage > gnPeakMemoryUsageInLast10s)
        {
            gnPeakMemoryUsageInLast10s = nMemoryUsage;
        }
    }

    ++pGame->nFramesSinceLastFrameRateUpdate;
}

// 0x00530690
int __stdcall GAME_Initialize()
{
    SRegLoadValue("Diablo II", "PlayerPos", 0, &gdwPlayerPos);
    for (int i = 0; i < 1024; ++i)
    {
        gnGamesGUIDs[i] = 0;
    }
    InitializeCriticalSection(&gGameListLock);
    CLIENTS_Initialize();
    SERVER_SetRemoveClientCallback((D2NET_Unk_Callback)GAME_AbortClientById);
    SUNITPROXY_FillGlobalItemCache();
    return 1;
}

// 0x005308C0
D2GameStrc* D2GameDataTableStrc::NewHandle(unsigned int* pHandle)
{
    const unsigned int nHandle = GenerateHandle();
    *pHandle = nHandle;
    return sub_00530820_New(nHandle, (HASHKEY_NONE*)&f_44, 0, 0);
}

// 0x005308F0
D2GameStrc* D2GameDataTableStrc::NewLock(unsigned int* pHandle, int* pLockedHandle)
{
    EnterCriticalSection(&f_50);
    *pLockedHandle = 1;
    const unsigned int nHandle = GenerateHandle();
    *pHandle = nHandle;
    return sub_00530820_New(nHandle, (HASHKEY_NONE*)&f_44, 0, 0);
}

// 0x0052F8B0
int __fastcall GAME_IsGameNameUnused(const char* szGameName)
{
    for (int i = 0; i < 1024; ++i)
    {
        if (gnGamesGUIDs[i] && gnGamesGUIDs[i] != D2GameReservedSlotHandle)
        {
            D2GameStrc* pGame = GAME_LockGame(gnGamesGUIDs[i]);
            if (pGame)
            {
                if (!SStrCmpI(szGameName, pGame->szGameName, 16))
                {
                    D2_ASSERT(pGame->lpCriticalSection, 0x1064);
                    LeaveCriticalSection(pGame->lpCriticalSection);
                    return 0;
                }

                D2_ASSERT(pGame->lpCriticalSection, 0x1064);
                LeaveCriticalSection(pGame->lpCriticalSection);
            }
        }
    }
    return 1;
}

// 0x0052F940
void __fastcall GAME_ResolveGameNameConflict(D2GameStrc* pGame, const char* szGameName, unsigned int dwFlags)
{
    if (GAME_IsGameNameUnused(szGameName))
    {
        SStrCopy(pGame->szGameName, szGameName, 0x7FFFFFFF);
        return;
    }

    char szName[16];
    size_t nLength = strlen(szGameName);
    if (0xF - nLength < 3)
        nLength = 0xB;
    memcpy(szName, szGameName, nLength);
    sprintf(&szName[nLength], "~%d", szGameName, 0);

    int nCounter = 1;
    while (!GAME_IsGameNameUnused(szName) && nCounter < 100)
    {
        sprintf(szName, "%s~%d", szGameName, nCounter);
        nCounter += 1;
    }
    D2_ASSERT(nCounter < 100, 0x263);

    SStrCopy(pGame->szGameName, szName, 0x7FFFFFFF);
}

// 0x00530EA0
void __fastcall D2GAME_SetStatOrResetGold(D2UnitStrc* pUnit, int nStat, int nValue)
{
    if (!pUnit)
    {
        return;
    }

    if (nValue < 0)
    {
        STATLIST_SetUnitStat(pUnit, nStat, 0, 0);
        return;
    }

    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        switch (nStat)
        {
        case 14:
            if (nValue > UNITS_GetInventoryGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, STAT_GOLD, 0, 0);
                return;
            }
            break;
        case 15:
            if (nValue > UNITS_GetStashGoldLimit(pUnit))
            {
                STATLIST_SetUnitStat(pUnit, STAT_GOLDBANK, 0, 0);
                return;
            }
            break;
        }
    }

    STATLIST_SetUnitStat(pUnit, nStat, nValue, 0);
}


int __fastcall NET_IsSimulatedLagConnection();





unsigned int __fastcall NET_GetBits12(unsigned int nValue);

char* __fastcall NET_GetField0D0(D2Net52BE10Strc* pRecord);

void __stdcall NET_DefaultLeaveGame(int nUnused1, int nUnused2, int nUnused3, int nUnused4, int nUnused5, int nUnused6, int nUnused7, int nUnused8, int nUnused9, int nUnused10, int nUnused11, int nUnused12, int nUnused13, int nUnused14, int nUnused15, int nUnused16, int nUnused17, int nUnused18);

void __stdcall NET_DefaultSaveDatabaseCharacter(int nUnused1, int nUnused2, int nUnused3, int nUnused4);

void __cdecl NET_DefaultServerLogMessage();

void __stdcall NET_DefaultEnterGame(int nUnused1, int nUnused2, int nUnused3);

int __stdcall NET_DefaultFindPlayerToken(int nUnused1, int nUnused2, int nUnused3, int nUnused4, int nUnused5, int nUnused6, int nUnused7);

void __stdcall NET_DefaultUpdateCharacterLadder(int nUnused1, int nUnused2, int nUnused3, int nUnused4, int nUnused5);

// 0x0052BEF0
void __cdecl GAME_DefaultGetGameServerInfo()
{
}

// 0x0052BF40
void __stdcall sub_0052BF40_Stub(int nUnused1, int nUnused2, int nUnused3, int nUnused4)
{
}

// 0x0052BFB0
void __stdcall sub_0052BFB0_Stub(int nUnused1, int nUnused2, int nUnused3, int nUnused4)
{
}

// 0x0052BFC0
const char* __fastcall GAME_GetLoadCompleteString()
{
    if (!gbD2ServerCallbackFunctionsInitialized)
    {
        return gszEmptyLoadComplete;
    }
    return gpD2EventCallbackTable->pfLoadComplete();
}

// 0x005306E0
int __stdcall SrvRecvDatabaseCharacter(int nClientId, const unsigned char* pSaveData, unsigned short nSaveSize, unsigned short nTotalSize, int nResult, int nUnused, D2FileTimeStrc* pSaveCreationTimestamp, int nCharSaveTransactionToken)
{
    GAME_LogMessage(6, "[JOIN 3] %d clientid, %d csresult - Recv'ed char from CS", nClientId, nResult);

    if (nTotalSize && !CLIENTS_AttachSaveFile(nClientId, pSaveData, nSaveSize, nTotalSize, nResult == 0, 1, nUnused))
    {
        GAME_LogMessage(6, "[JOIN]  SrvRecvDatabaseCharacter: Didn't recv full char from db - CSResult(%d), ClientID(%d)", nResult, nClientId);
        return 1;
    }

    if (nResult)
    {
        GAME_LogMessage(6, "[JOIN]  SrvRecvDatabaseCharacter: Did not recv CSDATA_SUCCESS - CSResult(%d), ClientID(%d)", nResult, nClientId);
        GAME_AbortClientById(nClientId, (int)".\\GAME\\Game.cpp", 0x407);
        return 0;
    }

    if (!nTotalSize)
    {
        GAME_AbortClientById(nClientId, (int)".\\GAME\\Game.cpp", 0x414);
        return 0;
    }

    D2GameStrc* pGame = GAME_GetGameByClientId(nClientId);
    if (!pGame)
    {
        return 0;
    }

    D2ClientStrc* pClient = CLIENTS_GetClientFromClientId(pGame, nClientId);
    if (!pClient)
    {
        GAME_LeaveGamesCriticalSection(pGame);
        return 0;
    }

    if (pClient->nCharSaveTransactionToken != nCharSaveTransactionToken)
    {
        GAME_LeaveGamesCriticalSection(pGame);
        GAME_AbortClientById(nClientId, (int)".\\GAME\\Game.cpp", 0x479);
        return 0;
    }

    pClient->nSaveCreationTimestamp = *pSaveCreationTimestamp;
    GAME_LeaveGamesCriticalSection(pGame);
    D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 2);
    return nTotalSize;
}


static inline D2MonStatsTxt* DESC_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    return 0;
}











D2Storm4167B0Strc::~D2Storm4167B0Strc()
{
    f_0.Unlink();
}



// 0x00530190
void __fastcall SrvJoinAct(int nClientId)
{
    D2ClientStrc* pClient;
    const int nGameGUID = SERVER_GetClientGameGUID(nClientId);
    D2GameStrc* pGame = GAME_LockGame(nGameGUID);
    if (pGame)
    {
        if (!CLIENTS_IsInGame(pGame, nClientId))
        {
            GAME_LeaveGamesCriticalSection(pGame);
        }
        else
        {
            pClient = CLIENTS_GetClientFromClientId(pGame, nClientId);
            const int nErrorCode = ClientAddPlayerToGame(pClient, pGame, 1, 0, 0, 0);
            if (nErrorCode)
            {
                D2GAME_PACKETS_SendSystemError(nClientId, nErrorCode);
                ClientRemoveFromGame(pGame, nClientId, 1);
                SERVER_HackListClient(nClientId, (int)".\\GAME\\Game.cpp", 0x672);
                GAME_LeaveGamesCriticalSection(pGame);
                return;
            }

            GAME_ClientEnterAct(pGame, pClient);
            CLIENTS_SpawnPlayer(pClient, CLIENTS_GetPlayerFromClient(pClient, 1), pGame, 0, 0, 0);
            CLIENTS_SetClientState(pClient, 3);
            GAME_LeaveGamesCriticalSection(pGame);
            GAME_LogMessage(6, "[JOIN 5] %d clientid, SrvJoinAct: Added to game.", nClientId);
            return;
        }
    }

    GAME_LogMessage(6, "[JOIN]  SrvJoinAct: No game found for client(%d)", nClientId);
}

void D2GameDataTableStrc::Unlink(D2GameStrc* pGame)
{
    if (pGame->tLinkToSlot.pNext)
    {
        GAMELINK_Unlink(&pGame->tLinkToSlot);
        GAMELINK_Unlink(&pGame->tLinkToFull);
    }
}

D2GameStrc* D2GameListStrc::RawNext(D2GameStrc* pGame)
{
    D2GameLinkStrc* pLink = pGame ? (D2GameLinkStrc*)((char*)pGame + nLinkOffset) : &tTerminator;
    return pLink->pNext;
}

D2GameStrc* D2GameListStrc::Next(D2GameStrc* pGame)
{
    D2GameLinkStrc* pLink = pGame ? (D2GameLinkStrc*)((char*)pGame + nLinkOffset) : &tTerminator;
    D2GameStrc* pNext = pLink->pNext;
    return (int)pNext > 0 ? pNext : 0;
}

// 0x0052FA50
void __fastcall SrvJoinGame(int dwClientId, unsigned short nGameId, int nClass, const char* szClientName, int nUnused3, const char* szAccountName, int nCharSaveTransactionToken, int nLocale, int nUnused1, int nUnused2, int nUnused4, int nUnused5, int nUnused6)
{
    if (!gpGameDataTbl)
    {
        return;
    }

    int nGUID = 0;
    EnterCriticalSection(&gGameListLock);
    if (gnGamesGUIDs[nGameId - 1] && gnGamesGUIDs[nGameId - 1] != D2GameReservedSlotHandle)
    {
        nGUID = gnGamesGUIDs[nGameId - 1];
    }
    LeaveCriticalSection(&gGameListLock);

    if (!nGUID)
    {
        return;
    }

    D2GameStrc* pGame = GAME_LockGame(nGUID);
    if (!pGame)
    {
        GAME_LogMessage(6, "[JOIN]  SrvJoinGame: ERROR cannot loc game - Game(%d), ClientID(%d), Player(%s)", nGameId, dwClientId, szClientName);
        return;
    }

    SERVER_SetClientGameGUID(dwClientId, nGUID);

    D2ClientStrc* pClient = ClientAddToGame(pGame, dwClientId, nClass, szClientName, szAccountName, nCharSaveTransactionToken, nLocale, nUnused1, nUnused2);
    if (!pClient)
    {
        if (gpD2EventCallbackTable && gpD2EventCallbackTable->pfUnlockDatabaseCharacter)
        {
            D2_ASSERT(!IsBadCodePtr((FARPROC)gpD2EventCallbackTable->pfUnlockDatabaseCharacter), 1972);
            gpD2EventCallbackTable->pfUnlockDatabaseCharacter(&pGame->pClientInfo, szClientName, szAccountName);
        }
        GAME_LeaveGamesCriticalSection(pGame);
        D2GAME_PACKETS_SendGameLeft(dwClientId);
        D2NET_10016(dwClientId);
        GAME_LogMessage(6, "[JOIN]  SrvJoinGame: ERROR adding Client to game - Game(%d), ClientID(%d), Player(%s)", nGameId, dwClientId, szClientName);
        return;
    }

    GAME_SendGameInit(pGame, pClient);
    pClient->bAct = gnAct;
    GAME_LeaveGamesCriticalSection(pGame);

    if (gpD2EventCallbackTable && gpD2EventCallbackTable->pfGetDatabaseCharacter)
    {
        GAME_LogMessage(6, "[JOIN 2] %d clientid, %d game, Requesting char from db", dwClientId, nGameId);
        D2_ASSERT(!IsBadCodePtr((FARPROC)gpD2EventCallbackTable->pfGetDatabaseCharacter), 2023);
        gpD2EventCallbackTable->pfGetDatabaseCharacter(&pClient->pClientInfo, szClientName, dwClientId, szAccountName);
        CLIENTS_EnableCharacterUnlock(pClient);
    }
    else
    {
        D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 2);
    }
}

// 0x0052FC20
int __stdcall GAME_UpdateGamesProgress(int bLimitCatchUp)
{
    D2LargeIntegerUnion aCounter[2];
    int bQueryPerformance = 0;
    QueryPerformanceCounter(&aCounter[0]);

    const int nSysTimeMs = timeGetTime() & 0x7FFFFFFF;
    if (!gnLastGamesUpdateTimeMs)
    {
        gnLastGamesUpdateTimeMs = nSysTimeMs;
    }

    const int nElapsed = nSysTimeMs - gnLastGamesUpdateTimeMs;
    if (nElapsed < gnTargetMsPerFrame)
    {
        return 0;
    }

    unsigned int nLate = nElapsed - gnTargetMsPerFrame;
    if (bLimitCatchUp && nLate >= gnTargetMsPerFrame)
    {
        nLate = gnTargetMsPerFrame;
    }

    gnLastGamesUpdateTimeMs = nSysTimeMs - nLate;

    for (int i = 0; i < 1024; ++i)
    {
        const int nGUID = gnGamesGUIDs[i];
        if (nGUID && nGUID != -1)
        {
            if (D2GameStrc* ptGame = GAME_LockGame(nGUID))
            {
                bQueryPerformance = 1;

                if (!gbFixedCpuTargetRatio)
                {
                    if (ptGame->nLastUpdateSystemTimeMs)
                    {
                        ptGame->nCreationTimeMs_Or_CPUTargetRatioFP10 = ((nSysTimeMs - ptGame->nLastUpdateSystemTimeMs) << 10) / gnTargetMsPerFrame;
                        if (ptGame->nCreationTimeMs_Or_CPUTargetRatioFP10 < 10)
                        {
                            ptGame->nCreationTimeMs_Or_CPUTargetRatioFP10 = 10;
                        }
                        else if (ptGame->nCreationTimeMs_Or_CPUTargetRatioFP10 > 0x800)
                        {
                            ptGame->nCreationTimeMs_Or_CPUTargetRatioFP10 = 0x800;
                        }
                    }

                    ptGame->nLastUpdateSystemTimeMs = nSysTimeMs;
                }
                else
                {
                    ptGame->nCreationTimeMs_Or_CPUTargetRatioFP10 = 0x400;
                }

                GAME_UpdateProgress(ptGame);

                D2_ASSERT(ptGame->lpCriticalSection, 0x1064);
                LeaveCriticalSection(ptGame->lpCriticalSection);
            }
        }
    }

    if (bQueryPerformance)
    {
        QueryPerformanceCounter(&aCounter[1]);
        aCounter[0].QuadPart = aCounter[1].QuadPart - aCounter[0].QuadPart;
    }
    else
    {
        aCounter[0].QuadPart = 0;
    }
    return aCounter[0].LowPart;
}

// 0x0052D980
static void GAME_SyncPlayerStats(D2ClientStrc* pClient)
{
    D2PacketDataStrc* pPacketData = CLIENTS_PacketDataList_GetHead(pClient);
    int bSkipHpCheck = 0;
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (pPlayer)
    {
        if (pPacketData && pClient->nPlayerSyncCount >= 10)
        {
            bSkipHpCheck = 1;
        }

        if (pClient->nPlayerSyncCount >= 20)
        {
            bSkipHpCheck = 1;
        }

        D2_ASSERT(pPlayer->dwUnitType == UNIT_PLAYER, 0xF05);

        if (PLRMSG_SendPlayerStatUpdates(pPlayer, pPlayer, bSkipHpCheck))
        {
            pClient->nPlayerSyncCount = 0;
        }
    }
}

// 0x0052DA00
static void GAME_RefreshAndSendUnitUpdates(D2ClientStrc* pClient)
{
    D2PacketDataStrc* pPacketData = CLIENTS_PacketDataList_GetHead(pClient);
    if (pPacketData)
    {
        D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
        if (pPlayer && pClient->nPlayerSyncCount >= 10)
        {
            D2_ASSERT(pPlayer->dwUnitType == UNIT_PLAYER, 0xF19);

            const int nUpdateSize = (499 - pPacketData->nPacketSize) / 9;
            if (nUpdateSize > 0)
            {
                D2_ASSERT(nUpdateSize <= CLIENTS_MAX_UPDATES, 0xF23);
                CLIENTS_RefreshUnitsUpdateList(pClient, nUpdateSize);
                SCMD_SendUnitUpdates(pClient);
            }
        }
    }
}

// 0x0052E110
static void __stdcall GAME_SendSaveFilePart(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    if (!CLIENTS_HasLoadedSave(pClient))
    {
        return;
    }

    if (pClient->nSaveHeaderSendDelay)
    {
        --pClient->nSaveHeaderSendDelay;
        return;
    }

    const unsigned char* pSaveData = (const unsigned char*)pClient->pSaveHeader;
    pClient->nSaveHeaderSendDelay = 5;
    if (!pSaveData)
    {
        return;
    }

    const unsigned char* pData = &pSaveData[pClient->nSaveHeaderDataSentBytes];
    int nDataSize = pClient->nSaveHeaderSize - pClient->nSaveHeaderDataSentBytes;
    if (nDataSize >= 255)
    {
        nDataSize = 255;
    }

    D2SavePartPacketStrc* pPacket = (D2SavePartPacketStrc*)sub_0040B430(pClient->pGame->pMemoryPool, sizeof(D2SavePartPacketStrc), ".\\GAME\\Game.cpp", 0x904, 0);
    pPacket->nHeader = 0xB3;
    pPacket->nPartDataSize = nDataSize;
    pPacket->bFirstPart = pClient->nSaveHeaderDataSentBytes == 0;
    pPacket->nSaveHeaderSize = pClient->nSaveHeaderSize;
    unsigned char* pPacketData = pPacket->aData;

    for (int i = 0; i < nDataSize; ++i)
    {
        *pPacketData++ = *pData++;
    }

    if (sub_0052B330(0, pClient->dwClientId, pPacket, nDataSize + 0x7))
    {
        pClient->nSaveHeaderDataSentBytes += nDataSize;

        if (pClient->nSaveHeaderDataSentBytes == pClient->nSaveHeaderSize)
        {
            CLIENTS_FreeSaveHeader(pClient);
        }

        pClient->nSaveHeaderSendFailures = 0;
    }
    else
    {
        ++pClient->nSaveHeaderSendFailures;
    }

    sub_0040B480(pClient->pGame->pMemoryPool, pPacket, ".\\GAME\\Game.cpp", 0x92A, 0);

    if (pClient->nSaveHeaderSendFailures >= 3)
    {
        CLIENTS_FreeSaveHeader(pClient);
        SrvDisconnectClient(pGame, pClient, 0);
    }
}

// 0x0052E320
static void __stdcall GAME_SendClientPackets(D2GameStrc* ptGame, int bSyncPlayer, D2ClientStrc* ptClient)
{
    D2_ASSERT(ptGame, 0xF37);
    D2_ASSERT(ptClient, 0xF38);

    if (bSyncPlayer && ptClient->dwClientState == CLIENTSTATE_INGAME)
    {
        if (gdwPlayerPos)
        {
            GAME_RefreshAndSendUnitUpdates(ptClient);
        }

        GAME_SyncPlayerStats(ptClient);
    }

    if (ptGame->nGameType == 1 || ptGame->nGameType == 2)
    {
        GAME_SendSaveFilePart(ptGame, ptClient);
    }

    int nCounter = 0;
    int bError = 0;
    do
    {
        D2PacketDataStrc* pPacketData = CLIENTS_PacketDataList_PopHead(ptClient);
        if (!pPacketData || !pPacketData->nPacketSize)
        {
            break;
        }

        if ((unsigned int)sub_0052B330(1, ptClient->dwClientId, pPacketData->packetData, pPacketData->nPacketSize) > 0)
        {
            ++nCounter;
            pPacketData->nPacketSize = 0;
            pPacketData->pNext = ptClient->pPacketDataPool;
            ptClient->pPacketDataPool = pPacketData;
            ptClient->nSaveHeaderSendFailures = 0;
        }
        else
        {
            sub_0052B910_GetLastError();
            bError = 1;
            ++ptClient->nSaveHeaderSendFailures;
            CLIENTS_PacketDataList_Reset(ptClient, pPacketData);
            if (ptClient->nSaveHeaderSendFailures >= 3)
            {
                SrvDisconnectClient(ptGame, ptClient, 0);
                return;
            }
        }
    }
    while ((ptGame->nGameType != 1 && ptGame->nGameType != 2 || nCounter < 3) && !bError);
}

// 0x0052FD90
int __stdcall GAME_UpdateClients(int bForceUpdate1, int bForceUpdate2)
{
    D2LargeIntegerUnion aCounter[2];
    int bQueryPerformance = 0;
    QueryPerformanceCounter(&aCounter[0]);

    const unsigned long nTickCount = GetTickCount();
    if (!bForceUpdate1 && !bForceUpdate2)
    {
        if (nTickCount - gdwLastClientsUpdateTick < 40)
        {
            return 0;
        }

        gdwLastClientsUpdateTick = nTickCount;
    }

    for (int i = 0; i < 1024; ++i)
    {
        const int nGUID = gnGamesGUIDs[i];
        if (nGUID && nGUID != D2GameReservedSlotHandle)
        {
            D2GameStrc* pGame = GAME_LockGame(nGUID);
            if (pGame)
            {
                D2ClientStrc* pClient = pGame->pClientList;
                bQueryPerformance = 1;
                while (pClient)
                {
                    D2ClientStrc* pNextClient = pClient->pNext;
                    GAME_SendClientPackets(pGame, 1, pClient);
                    pClient = pNextClient;
                }

                if (!pGame->nClients)
                {
                    if (!pGame->nTickCountSinceNoClients)
                    {
                        pGame->nTickCountSinceNoClients = nTickCount;
                    }

                    if (nTickCount - pGame->nTickCountSinceNoClients > 300000 || pGame->dwGameFrame > 1500 && pGame->dwGameFrame < 7500)
                    {
                        GAME_LeaveGamesCriticalSection(pGame);
                        GAME_CloseGame(nGUID);
                    }
                    else
                    {
                        GAME_LeaveGamesCriticalSection(pGame);
                    }
                }
                else
                {
                    pGame->nTickCountSinceNoClients = 0;
                    GAME_LeaveGamesCriticalSection(pGame);
                }
            }
        }
    }

    if (bQueryPerformance)
    {
        QueryPerformanceCounter(&aCounter[1]);
        aCounter[0].QuadPart = aCounter[1].QuadPart - aCounter[0].QuadPart;
    }
    else
    {
        aCounter[0].QuadPart = 0;
    }
    return aCounter[0].LowPart;
}







D2Storm4168F0Strc::~D2Storm4168F0Strc()
{
    f_0.Unlink();
}








// 0x00530820
D2GameStrc* D2GameDataTableStrc::sub_00530820_New(unsigned int nHashVal, HASHKEY_NONE* pKey, int nExtraBytes, int nFlags)
{
    unsigned int nSlot = nHashVal & m_hashmask;
    if (MonitorFullness(nSlot))
    {
        nSlot = nHashVal & m_hashmask;
    }

    D2GameHashListStrc* pList = &m_slotlistarray[nSlot];
    D2GameStrc* pNode = sub_NewNode(pList, nExtraBytes, nFlags);

    D2GameHashLinkStrc* pLink;
    if (pNode)
    {
        pLink = (D2GameHashLinkStrc*)((char*)pNode + m_linkoffset);
    }
    else
    {
        pLink = &m_terminator;
    }

    pLink->Unlink();

    D2GameHashLinkStrc* pPrev = m_terminator.m_prevlink;
    pLink->m_prevlink = pPrev;
    pLink->m_next = pPrev->m_next;
    pPrev->m_next = pNode;
    m_terminator.m_prevlink = pLink;

    pNode->dwHashValue = nHashVal;
    return pNode;
}

// 0x0052FEE0
D2GameStrc* __fastcall GAME_GetGameByClientId(int nClientId)
{
    const int nGameGUID = SERVER_GetClientGameGUID(nClientId);

    D2GameStrc* pGame = GAME_LockGame(nGameGUID);
    if (!pGame)
    {
        return 0;
    }

    if (CLIENTS_IsInGame(pGame, nClientId))
    {
        return pGame;
    }

    GAME_LeaveGamesCriticalSection(pGame);

    return 0;
}

// 0x0052FF20
void D2StormHashTableStrc::GrowListArray()
{
    unsigned int nOldCount = m_slotmask + 1;
    unsigned int nNewCount = 2 * nOldCount;
    D2StormListAStrc tTempList;
    tTempList.ChangeLinkOffset(4);

    for (unsigned int i = 0; i < nOldCount; i++)
    {
        char* pNode;
        while ((pNode = m_slotlistarray.m_data[i].Head()) != 0)
            tTempList.LinkToTail(pNode);
    }

    m_slotlistarray.sub_00450110_SetCount(nNewCount);
    for (unsigned int i = 0; i < nNewCount; i++)
        m_slotlistarray.m_data[i].ChangeLinkOffset(4);
    m_slotmask = nNewCount - 1;

    char* pNode;
    while ((pNode = tTempList.Head()) != 0)
        m_slotlistarray.m_data[((D2StormHashNodeStrc*)pNode)->m_hashval & m_slotmask].LinkToTail(pNode);
}

// 0x005300F0
int __stdcall GAME_AbortClientById(int nClientId, int szFile, int nLine)
{
    D2GameStrc* pGame = GAME_LockGame(SERVER_GetClientGameGUID(nClientId));
    if (pGame)
    {
        if (!CLIENTS_IsInGame(pGame, nClientId))
        {
            GAME_LeaveGamesCriticalSection(pGame);
        }
        else
        {
            if (CLIENTS_IsInGame(pGame, nClientId))
            {
                ClientRemoveFromGame(pGame, nClientId, 1);
            }

            D2_ASSERT(pGame->lpCriticalSection, 4196);
            LeaveCriticalSection(pGame->lpCriticalSection);
        }
    }
    return SERVER_HackListClient(nClientId, szFile, nLine);
}

// 0x00530270
void __fastcall SrvDisconnectClientById(int nClientId, int nEventType)
{
    if (!nClientId)
    {
        return;
    }

    D2GameStrc* pGame = GAME_LockGame(SERVER_GetClientGameGUID(nClientId));
    if (!pGame)
    {
        return;
    }

    if (!CLIENTS_IsInGame(pGame, nClientId))
    {
        GAME_LeaveGamesCriticalSection(pGame);
        return;
    }

    D2ClientStrc* pClient = CLIENTS_GetClientFromClientId(pGame, nClientId);
    SrvDisconnectClient(pGame, pClient, nEventType);
    GAME_LeaveGamesCriticalSection(pGame);
}

// 0x005302D0
int __stdcall GAME_DisconnectClientByName(const char* szClientName, int nEventType)
{
    const int nClientId = CLIENTS_GetClientIdByName(szClientName);
    if (!nClientId)
    {
        return 0;
    }

    SrvDisconnectClientById(nClientId, nEventType);
    return 1;
}

// 0x00530300
void __stdcall GAME_RemoveClientById(int nClientId)
{
    if (!nClientId)
        return;

    const int nGUID = SERVER_GetClientGameGUID(nClientId);
    D2GameStrc* pGame = GAME_LockGame(nGUID);
    if (!pGame)
        return;

    if (!CLIENTS_IsInGame(pGame, nClientId))
    {
        GAME_LeaveGamesCriticalSection(pGame);
        return;
    }

    D2ClientStrc* pClient = CLIENTS_GetClientFromClientId(pGame, nClientId);
    D2GSPacketSrv5A tPacket = {};
    tPacket.nHeader = 0x5A;
    tPacket.nType = 0;
    tPacket.nColor = 4;
    tPacket.dwParam = 0;
    tPacket.szText[16] = 0;
    SStrCopy(tPacket.szText, CLIENTS_GetName(pClient), 16);
    PLRMSG_BroadcastEventMessage(pGame, &tPacket);
    ClientRemoveFromGame(pGame, CLIENTS_GetClientId(pClient), 1);
    GAME_LeaveGamesCriticalSection(pGame);
}

// 0x0052E260
static void GAME_SendRemainingSaveParts(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    if (pGame->nGameType == 1 || pGame->nGameType == 2)
    {
        while (CLIENTS_HasLoadedSave(pClient))
        {
            GAME_SendSaveFilePart(pGame, pClient);
        }
    }
}

// 0x005303D0
void __fastcall SrvEndGame(int nClientId, int bSendLeaveMessage)
{
    D2GameStrc* pGame = GAME_LockGame(SERVER_GetClientGameGUID(nClientId));
    if (!pGame)
    {
        return;
    }

    if (!CLIENTS_IsInGame(pGame, nClientId))
    {
        GAME_LeaveGamesCriticalSection(pGame);
        return;
    }

    D2ClientStrc* pClient = CLIENTS_GetClientFromClientId(pGame, nClientId);
    const unsigned int bOwner = CLIENT_IsGameOwner(pClient);
    if (bOwner || pGame->nGameType)
    {
        GAME_SaveAllPlayers(pGame);
    }

    if (pClient)
    {
        while (1)
        {
            D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 5);
            GAME_SendRemainingSaveParts(pGame, pClient);
            D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 6);
            D2GAME_PACKETS_SendGameLeft(nClientId);
            GAME_SendClientPackets(pGame, 0, pClient);

            D2GSPacketSrv5A packet5A = {};
            packet5A.nHeader = 0x5A;
            packet5A.nType = 3;
            packet5A.nColor = 4;
            packet5A.dwParam = 0;
            CLIENTS_CopyAccountNameToBuffer(pClient, &packet5A.szText[16]);
            packet5A.szText[31] = '\0';
            SStrCopy(packet5A.szText, CLIENTS_GetName(pClient), 16);
            ClientRemoveFromGame(pGame, nClientId, !bOwner);

            if (bSendLeaveMessage)
            {
                PLRMSG_BroadcastEventMessage(pGame, &packet5A);
            }

            if (!bOwner)
            {
                break;
            }

            pClient = sub_00539070_GetClientList(pGame);
            if (!pClient)
            {
                break;
            }

            nClientId = CLIENTS_GetClientId(pClient);
        }
    }

    D2_ASSERT(pGame->lpCriticalSection, 0x1064);
    LeaveCriticalSection(pGame->lpCriticalSection);

    if (pGame->nGameType == 1 || pGame->nGameType == 2)
    {
        Sleep(100);
    }

    D2NET_10016(nClientId);
}

// 0x0052E2A0
void __fastcall GAME_SaveAndSendClientSaves(D2GameStrc* pGame)
{
    if (pGame->nGameType == 1 || pGame->nGameType == 2)
    {
        D2ClientStrc* pClient = pGame->pClientList;
        while (pClient)
        {
            D2ClientStrc* pNextClient = pClient->pNext;

            D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
            if (pPlayer)
            {
                D2GAME_SAVE_WriteFile(pGame, pPlayer, CLIENTS_GetName(pClient), 0);
                GAME_SendRemainingSaveParts(pGame, pClient);
            }

            pClient = pNextClient;
        }
    }
}

// 0x0052E440
void __fastcall GAME_SendAllClientPackets(D2GameStrc* pGame)
{
    D2ClientStrc* pClient = pGame->pClientList;
    while (pClient)
    {
        D2ClientStrc* pNextClient = pClient->pNext;
        GAME_SendClientPackets(pGame, 1, pClient);
        pClient = pNextClient;
    }
}

// 0x0052E470
void D2GameDataTableStrc::SyncLeaveLock(int nLockHandle)
{
    if (nLockHandle)
    {
        LeaveCriticalSection(&f_50);
    }
}

// 0x0052E570
void D2GameDataTableStrc::Unlock(int nLockHandle)
{
    if (nLockHandle)
    {
        LeaveCriticalSection(&f_50);
    }
}

// 0x0052E590
void D2GameDataTableStrc::Delete(D2GameStrc* pGame)
{
    Unlink(pGame);
    InternalDelete(pGame);
}

// 0x0052E5B0
void D2GameDataTableStrc::sub_0052E5B0(D2GameStrc* pGame)
{
    Unlink(pGame);
    InternalDelete(pGame);
}

// 0x0052E5D0
void D2GameDataTableStrc::DeleteUnlock(D2GameStrc* pGame, int nLockHandle)
{
    Unlink(pGame);
    InternalDelete(pGame);
    if (nLockHandle)
    {
        LeaveCriticalSection(&f_50);
    }
}

// 0x0052E600
D2GameStrc* D2GameListStrc::DeleteNode(D2GameStrc* pGame)
{
    D2GameStrc* pNext = InlineNext(pGame);
    ((D2GameNodeStrc*)pGame)->~D2GameNodeStrc();
    SMemFree(pGame, gszSGameDataTypeName, -2, 0);
    return pNext;
}

// 0x0052E650
char* D2StormHashTable0052E650Strc::sub_0052E650_Ptr(unsigned int nHashVal, int nKey)
{
    for (char* pNode = m_slotlistarray.m_data[nHashVal & m_slotmask].Head(); _ReadWriteBarrier(), (int)pNode > 0; pNode = m_slotlistarray.m_data[nHashVal & m_slotmask].RawNext(pNode))
    {
        if (((D2StormHashNodeStrc*)pNode)->m_hashval == nHashVal)
        {
            return pNode;
        }
    }
    return 0;
}

// 0x0052E6B0
D2GameStrc* D2GameDataTableStrc::sub_0052E6B0(unsigned int nHashValue)
{
    return Ptr(nHashValue, &f_44);
}

// 0x0052E6D0
unsigned int D2GameDataTableStrc::GenerateHandle()
{
    while (1)
    {
        nSequence += 1;
        if (!nSequence)
        {
            bWrapped = 1;
            continue;
        }

        if (!bWrapped)
        {
            return nSequence;
        }

        if (!Ptr(nSequence, &f_44))
        {
            return nSequence;
        }
    }
}

// 0x0052E710
D2GameStrc* D2GameDataTableStrc::Lock(unsigned int nHashValue, int* pLockHandle, int bForWriting)
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

// 0x0052E770
void __fastcall GAME_CloseGame(int nGameGUID)
{
    if (gpGameDataTbl)
    {
        int hLock;
        D2GameStrc* pGame = gpGameDataTbl->LockInline(nGameGUID, &hLock, 0);
        if (pGame)
        {
            if (gpD2EventCallbackTable && gpD2EventCallbackTable->pfCloseGame)
            {
                D2_ASSERT(!IsBadCodePtr((FARPROC)gpD2EventCallbackTable->pfCloseGame), 0x107C);
                gpD2EventCallbackTable->pfCloseGame(pGame->nGameId, pGame->bExpansion ? 0x44325850 : 0x44324456, pGame->dwLastUsedUnitGUID[UNIT_PLAYER], pGame->dwGameFrame / 25);
            }

            D2_ASSERT(pGame->lpCriticalSection, 0x108D);
            EnterCriticalSection(pGame->lpCriticalSection);

            SrvFreeGame(nGameGUID, pGame);

            gpGameDataTbl->DeleteUnlock(pGame, hLock);
        }
    }
}

// 0x0052E860
D2GameStrc* __fastcall GAME_LockGame(int nGameGUID)
{
    if (!gpGameDataTbl)
    {
        return 0;
    }

    int hLock;
    D2GameStrc* pGame = gpGameDataTbl->LockInline(nGameGUID, &hLock, 1);
    if (pGame)
    {
        D2_ASSERT(pGame->lpCriticalSection, 0x1181);
        EnterCriticalSection(pGame->lpCriticalSection);
        if (hLock)
        {
            LeaveCriticalSection(&gpGameDataTbl->f_50);
        }
    }
    return pGame;
}

// 0x00530590
void __fastcall GAME_EndGameForConnectedClient(D2GameStrc* game, D2ClientStrc* client)
{
    D2ClientStrc* owner = 0;
    GAME_ForEachIngameClient(game, GAME_FindGameOwnerCallback, &owner);
    if (!owner)
    {
        if (!client)
        {
            D2ClientStrc* first = 0;
            GAME_ForEachIngameClient(game, GAME_FindFirstClientCallback, &first);
            if (first)
            {
                SrvEndGame(CLIENTS_GetClientId(first), 0);
            }
            return;
        }
        SrvEndGame(CLIENTS_GetClientId(client), 0);
        return;
    }
    SrvEndGame(CLIENTS_GetClientId(owner), 0);
}

// 0x00530600
int D2StormHashTable00530600Strc::MonitorFullness(unsigned int nSlot)
{
    D2StormSlotList00530600Strc* const& pSlotLists = m_slotlistarray.m_data;
    if (m_slotmask >= 0x3FF)
    {
        return 0;
    }

    if (m_fullnessIndicator > 3)
    {
        m_fullnessIndicator -= 3;
    }
    else
    {
        m_fullnessIndicator = 0;
    }

    for (char* pNode = pSlotLists[nSlot].m_terminator.Next(); (int)pNode > 0; )
    {
        ++m_fullnessIndicator;
        if (m_fullnessIndicator > 13)
        {
            m_fullnessIndicator = 0;
            GrowListArray();
            return 1;
        }

        D2StormSlotList00530600Strc* pList = &pSlotLists[nSlot];
        D2StormSlotLink00530600Strc* pLink = pNode ? (D2StormSlotLink00530600Strc*)(pNode + pList->m_linkoffset) : &pList->m_terminator;
        pNode = pLink->m_next;
    }

    return 0;
}

// 0x0052D7B0
void __fastcall GAME_UpdateEnvironment(D2GameStrc* pGame)
{
    for (int i = 0; i < 5; ++i)
    {
        if (pGame->pAct[i] && ENVIRONMENT_UpdateCycleIndex(pGame->pAct[i], i))
        {
            int nCycleIndex;
            int nTicks;
            int nEclipse;
            ENVIRONMENT_GetCycleIndex_Ticks_EclipseFromAct(pGame->pAct[i], &nCycleIndex, &nTicks, &nEclipse);
            D2GSPacketSrv53 packet53;
            packet53.nHeader = 0x53;
            packet53.nCycleIndex = nCycleIndex;
            packet53.nTicks = nTicks;
            packet53.nEclipse = nEclipse;
            for (D2ClientStrc* pClient = pGame->pClientList; pClient; pClient = pClient->pNext)
            {
                D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
                if (pPlayer)
                {
                    D2GAME_UpdatePlayerItems(pGame, pPlayer, 1);
                    if (pClient->dwClientState == 4 && pClient->bAct == i)
                        D2GAME_SendPacket0x53(pClient, &packet53);
                }
            }
        }
    }
}

// 0x0052DA90
void __fastcall GAME_LeaveGamesCriticalSection(D2GameStrc* pGame)
{
    D2_ASSERT(pGame, 0x1063);
    D2_ASSERT(pGame->lpCriticalSection, 0x1064);
    LeaveCriticalSection(pGame->lpCriticalSection);
}

// 0x0052DAD0
void __cdecl GAME_AssertFail()
{
    D2_ASSERT(0, 0x1165);
}

// 0x0052DAF0
extern "C" __declspec(dllexport) int __cdecl sub_0052DAF0() {
    return 1;
}

// 0x0052DB00
extern "C" __declspec(dllexport) int __cdecl GAME_VerifyReceiveSaveFilePart() {
    return 1;
}

// 0x0052DB10
int __fastcall GAME_ReceiveSaveFilePart(int nClientId, D2GSPacketClt6B* pPacket)
{
    return CLIENTS_AttachSaveFile(nClientId, pPacket->saveData, pPacket->nSize, pPacket->dwTotalSize, 0, 0, 0);
}

// 0x0052DB30
int __fastcall GAME_GetGamesCount()
{
    int nResult = 0;
    for (int i = 0; i < 1024; ++i)
    {
        if (gnGamesGUIDs[i] != 0 && gnGamesGUIDs[i] != -1)
        {
            ++nResult;
        }
    }
    return nResult;
}

// 0x0052DB80
int __cdecl GAME_GetExpansionClientsCount()
{
    return CLIENTS_GetExpansionClientCount();
}

// 0x0052DB90
int __cdecl GAME_GetFrameRate()
{
    return gdwGlobal_00731010;
}

// 0x0052DBA0
void __stdcall GAME_GetMemoryUsage(int* pCurrentMemoryUsage, int* pPeakMemoryUsageInLast10s)
{
    *pCurrentMemoryUsage = FOG_GetMemoryUsage(0);
    *pPeakMemoryUsageInLast10s = gnPeakMemoryUsageInLast10s;
}

// 0x0052DBC0
static int GAME_CountUnitsInLists(D2UnitStrc** pUnitLists)
{
    int nUnits = 0;
    for (int i = 0; i < 128; ++i)
    {
        if (D2UnitStrc* pFirstUnit = pUnitLists[i])
        {
            ++nUnits;
            for (D2UnitStrc* pUnit = SUNIT_GetNextUnitFromList(pFirstUnit); pUnit; pUnit = SUNIT_GetNextUnitFromList(pUnit))
            {
                ++nUnits;
            }
        }
    }
    return nUnits;
}

// 0x0052DC00
int __stdcall GAME_ReturnArgument(int nValue)
{
    return nValue;
}

// 0x0052DC10
int __cdecl sub_0052DC10_GetGlobal731008()
{
    return gdwGlobal_00731008;
}

// 0x0052DC20
static void __stdcall GAME_AddUnitDescription(int bCount, int nClassId, D2UnitDescriptionListStrc* pList)
{
    D2UnitDescriptionListStrc* pHead = pList;
    D2_ASSERT(pList, 0x139E);
    do
    {
        if (pList->nClassId == nClassId)
        {
            if (bCount)
            {
                ++pList->nCount;
            }
            else
            {
                ++pList->nDefaultCount;
            }
            return;
        }
        pList = pList->pNext;
    }
    while (pList);

    D2UnitDescriptionListStrc* pNew = (D2UnitDescriptionListStrc*)sub_0040B430(0, sizeof(D2UnitDescriptionListStrc), ".\\GAME\\Game.cpp", 0x13AF, 0);
    if (pNew)
    {
        memset(pNew, 0, sizeof(D2UnitDescriptionListStrc));
        pNew->nClassId = nClassId;
        pNew->nCount = 0;
        pNew->nDefaultCount = 0;
        if (bCount)
        {
            pNew->nCount = 1;
        }
        else
        {
            pNew->nDefaultCount = 1;
        }
        pNew->pNext = pHead->pNext;
        pHead->pNext = pNew;
    }
}

// 0x0052DCF0
void __fastcall GAME_GetPlayerDescription(char* szDescription, int nClassId)
{
    switch (nClassId)
    {
    case PCLASS_AMAZON: strcpy(szDescription, "Amazon"); break;
    case PCLASS_SORCERESS: strcpy(szDescription, "Sorceress"); break;
    case PCLASS_NECROMANCER: strcpy(szDescription, "Necromancer"); break;
    case PCLASS_PALADIN: strcpy(szDescription, "Paladin"); break;
    case PCLASS_BARBARIAN: strcpy(szDescription, "Barbarian"); break;
    case PCLASS_DRUID: strcpy(szDescription, "Druid"); break;
    case PCLASS_ASSASSIN: strcpy(szDescription, "Assassin"); break;
    default: strcpy(szDescription, "Invalid Class"); break;
    }
}

// 0x0052DDF0
void __fastcall GAME_GetMonsterDescription(char* szDescription, int nClassId)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DESC_GetMonStatsTxtRecord(nClassId);
    if (pMonStatsTxtRecord)
    {
        const Unicode* pName = D2LANG_GetStringFromTblIndex(pMonStatsTxtRecord->wNameStr);
        UNICODE_ToAscii(szDescription, pName, 64);
    }
    else
        sprintf(szDescription, "Monster %d", nClassId);
}

// 0x0052DE40
void __fastcall GAME_GetObjectDescription(char* szDescription, int nClassId)
{
    D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(nClassId);
    if (pObjectsTxtRecord)
        strcpy(szDescription, pObjectsTxtRecord->szName);
    else
        sprintf(szDescription, "Object %d", nClassId);
}

// 0x0052DE80
void __fastcall GAME_GetItemDescription(char* szDescription, int nClassId)
{
    D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(nClassId);
    if (pItemsTxtRecord)
    {
        const Unicode* pName = D2LANG_GetStringFromTblIndex(pItemsTxtRecord->wNameStr);
        UNICODE_ToAscii(szDescription, pName, 64);
    }
    else
        sprintf(szDescription, "Item %d", nClassId);
}

// 0x0052DEC0
void __fastcall GAME_GetMissileDescription(char* szDescription, int nClassId)
{
    sprintf(szDescription, "Missile %d", nClassId);
}

inline unsigned __int64 sub_I08_RollGameSeed(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x0052C280
static void GAME_InitGameSeed(D2GameStrc* pGame)
{
    if (gnInitSeed == -1)
    {
        pGame->InitSeed = 0;
        D2LargeIntegerUnion tCount;
        QueryPerformanceCounter(&tCount);
        SEED_InitSeed(&pGame->pGameSeed);
        SEED_InitLowSeed(&pGame->pGameSeed, SEED_GetRandomValue(tCount.LowPart));
        pGame->dwInitSeed = SEED_GetRandomValue((int)sub_I08_RollGameSeed(&pGame->pGameSeed));
    }
    else
    {
        pGame->InitSeed = 1;
        pGame->dwInitSeed = gnInitSeed;
        SEED_InitSeed(&pGame->pGameSeed);
        SEED_InitLowSeed(&pGame->pGameSeed, gnInitSeed);
    }
}

// 0x00530930
int __stdcall SrvCreateNewEmptyGame(char* szGameName, const char* szPassword, const char* szGameDescription, unsigned int nFlags, unsigned char nArenaTemplate, unsigned char nMaxLevelDifference, unsigned char nMaxPlayers, unsigned short* pGameId)
{
    if (!gpGameDataTbl)
    {
        return 0;
    }

    const unsigned short nGameId = sub_0052C170_AllocGameId();
    if (!nGameId)
    {
        return 0;
    }

    D2GameDataTableStrc* pGameDataTbl = gpGameDataTbl;
    EnterCriticalSection(&pGameDataTbl->f_50);
    const unsigned int hGame = pGameDataTbl->GenerateHandle();
    D2GameStrc* pGame = pGameDataTbl->sub_00530820_New(hGame, (HASHKEY_NONE*)&pGameDataTbl->f_44, 0, 0);
    LeaveCriticalSection(&gpGameDataTbl->f_50);

    D2_ASSERT(pGame, 793);
    pGame->lpCriticalSection = (D2CriticalSectionStrc*)FOG_AllocPool(0, sizeof(D2CriticalSectionStrc), ".\\GAME\\Game.cpp", 796, 0);
    InitializeCriticalSection(pGame->lpCriticalSection);

    FOG_CreateNewPoolSystem(&pGame->pMemoryPool, szGameName, 0x8000, 0x1000);

    memset(pGame->pUnitList[0], 0, sizeof(pGame->pUnitList[0]));
    memset(pGame->pUnitList[1], 0, sizeof(pGame->pUnitList[1]));
    memset(pGame->pUnitList[2], 0, sizeof(pGame->pUnitList[2]));
    memset(pGame->pUnitList[3], 0, sizeof(pGame->pUnitList[3]));
    memset(pGame->pUnitList[4], 0, sizeof(pGame->pUnitList[4]));
    memset(pGame->dwUniqueFlags, 0, sizeof(pGame->dwUniqueFlags));

    pGame->nGameId = nGameId;
    pGame->unk0x24 = 1;

    GAME_ResolveGameNameConflict(pGame, szGameName, 0);
    SStrCopy(pGame->szGamePassword, szPassword, 16);
    SStrCopy(pGame->szGameDesc, szGameDescription, 32);

    pGame->nArenaTemplate = nArenaTemplate;
    pGame->nMaxLevelDifference = nMaxLevelDifference;
    pGame->nMaxPlayers = nMaxPlayers;

    if (nFlags & 0x100000)
    {
        pGame->bExpansion = 1;
    }
    else
    {
        pGame->bExpansion = 0;
    }

    pGame->wItemFormat = pGame->bExpansion != 0 ? 101 : 2;
    pGame->dwGameType = (nFlags & 0x200000) != 0;

    pGame->dwLastUsedUnitGUID[0] = 0;
    pGame->dwLastUsedUnitGUID[1] = 0;
    pGame->dwLastUsedUnitGUID[2] = 0;
    pGame->dwLastUsedUnitGUID[3] = 0;
    pGame->dwLastUsedUnitGUID[4] = 0;
    pGame->dwLastUsedUnitGUID[5] = 0;
    pGame->nUberFields[0] = 0;
    pGame->nUberFields[1] = 0;
    pGame->nUberFields[2] = 0;
    pGame->nUberFields[3] = 0;
    pGame->nUberFields[4] = 0;
    pGame->nUberFields[5] = 0;
    pGame->nUberFields[6] = 0;
    pGame->nUberFields[7] = 0;

    pGame->nDifficulty = (nFlags >> 12) & 7;

    GAME_InitGameSeed(pGame);
    EVENT_AllocEventQueue(pGame);
    ARENA_AllocArena(pGame, 0, nFlags, 0);
    CLIENTS_SetGameData((D2ClientStrc*)pGame);
    PARTY_AllocPartyControl(pGame);
    MONSTERREGION_InitializeForGame(pGame);
    pGame->dwObjSeed = OBJRGN_AllocObjectControl(pGame);
    SUNITPROXY_InitializeNpcControl(pGame);
    QUESTS_QuestInit(pGame);

    GAME_SetReservedGameGUID(hGame, nGameId);

    pGame->nSyncTimer = SYSTEM_GetSyncTime();
    if (pGame->nSyncTimer <= 1)
    {
        pGame->nSyncTimer = 2;
    }

    void* pTask = FOG_Alloc(0x14, ".\\GAME\\Game.cpp", 922, 0);
    TASK_QueueGame(pTask, 0, hGame);
    pGame->nCreationTimeMs_Or_CPUTargetRatioFP10 = GetTickCount();
    *pGameId = pGame->nGameId;
    return 1;
}

// 0x00530BF0
void __fastcall sSrvSendGameInit(int nClientId, char* szGameName, unsigned char nGameType, unsigned char nCharTemplate, const char* szClientName, int nArena, unsigned int nFlags, int nArenaTemplate, int nUnused1, int nUnused2, unsigned char nDifficulty, unsigned char nLocale, int nUnused3, int nUnused4)
{
    if (!gpGameDataTbl)
    {
        return;
    }

    D2GameDataTableStrc* pGameDataTbl = gpGameDataTbl;
    EnterCriticalSection(&pGameDataTbl->f_50);
    const unsigned int hGame = pGameDataTbl->GenerateHandle();
    D2GameStrc* pGame = pGameDataTbl->sub_00530820_New(hGame, (HASHKEY_NONE*)&pGameDataTbl->f_44, 0, 0);
    LeaveCriticalSection(&gpGameDataTbl->f_50);

    if (!pGame)
    {
        return;
    }

    pGame->lpCriticalSection = (D2CriticalSectionStrc*)FOG_AllocPool(0, sizeof(D2CriticalSectionStrc), ".\\GAME\\Game.cpp", 1241, 0);
    InitializeCriticalSection(pGame->lpCriticalSection);

    pGame->pMemoryPool = 0;

    memset(pGame->pUnitList[0], 0, sizeof(pGame->pUnitList[0]));
    memset(pGame->pUnitList[1], 0, sizeof(pGame->pUnitList[1]));
    memset(pGame->pUnitList[2], 0, sizeof(pGame->pUnitList[2]));
    memset(pGame->pUnitList[3], 0, sizeof(pGame->pUnitList[3]));
    memset(pGame->pUnitList[4], 0, sizeof(pGame->pUnitList[4]));
    memset(pGame->dwUniqueFlags, 0, sizeof(pGame->dwUniqueFlags));

    pGame->unk0x24 = 1;

    pGame->nGameId = sub_0052C170_AllocGameId();
    GAME_ResolveGameNameConflict(pGame, szGameName, nClientId);
    pGame->nGameType = nGameType;
    pGame->dwLastUsedUnitGUID[0] = 0;
    pGame->dwLastUsedUnitGUID[1] = 0;
    pGame->dwLastUsedUnitGUID[2] = 0;
    pGame->dwLastUsedUnitGUID[3] = 0;
    pGame->dwLastUsedUnitGUID[4] = 0;
    pGame->dwLastUsedUnitGUID[5] = 0;
    pGame->nDifficulty = nDifficulty;
    pGame->nArenaTemplate = nArenaTemplate;

    if (nFlags & 0x100000)
    {
        pGame->bExpansion = 1;
    }
    else
    {
        pGame->bExpansion = 0;
    }

    pGame->wItemFormat = pGame->bExpansion != 0 ? 101 : 2;
    pGame->dwGameType = (nFlags & 0x200000) != 0;

    GAME_InitGameSeed(pGame);
    EVENT_AllocEventQueue(pGame);
    ARENA_AllocArena(pGame, nArena, nFlags, nArenaTemplate);
    CLIENTS_SetGameData((D2ClientStrc*)pGame);

    D2ClientStrc* pClient = ClientAddToGame(pGame, nClientId, nCharTemplate, szClientName, &gszEmptyAssertText, 0, nLocale, nUnused3, nUnused4);
    SERVER_SetClientGameGUID(nClientId, hGame);

    if (pGame->nGameType == 1)
    {
        CLIENTS_SetGameOwner(pClient);
    }

    PARTY_AllocPartyControl(pGame);
    MONSTERREGION_InitializeForGame(pGame);
    pGame->dwObjSeed = OBJRGN_AllocObjectControl(pGame);
    SUNITPROXY_InitializeNpcControl(pGame);
    QUESTS_QuestInit(pGame);

    GAME_SetReservedGameGUID(hGame, pGame->nGameId);

    D2GAME_PACKETS_SendPacket0x01(pClient, 1, pGame);
    D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 0);
    CLIENTS_SetClientState(pClient, 1);
    CLIENTS_SetActNo(pClient, gnAct);

    pGame->nSyncTimer = SYSTEM_GetSyncTime();
    if (pGame->nSyncTimer <= 1)
    {
        pGame->nSyncTimer = 2;
    }

    void* pTask = FOG_Alloc(0x14, ".\\GAME\\Game.cpp", 1371, 0);
    TASK_QueueGame(pTask, 0, hGame);

    D2_ASSERT(!gpD2EventCallbackTable || !gpD2EventCallbackTable->pfGetDatabaseCharacter, 1378);

    D2GAME_PACKETS_SendHeaderOnlyPacket(pClient, 2);
}

// 0x0052DED0
void __fastcall GAME_ForEachIngameClient(D2GameStrc* pGame, GAME_ForEachIngameClientCallbackPtr pFn, void* pContext)
{
    D2_ASSERT(pGame, 5496);
    D2_ASSERT(!IsBadCodePtr((FARPROC)pFn), 5497);

    for (D2ClientStrc* pClient = pGame->pClientList; pClient; pClient = pClient->pNext)
    {
        if (pClient->dwClientState == CLIENTSTATE_INGAME)
        {
            pFn(pClient, pContext);
        }
    }
}

// 0x0052DF40
void __fastcall GAME_UnlockDebugGame()
{
    GAME_LeaveGamesCriticalSection(gpGame);
}

// 0x0052DF80
void __stdcall GAME_SetTargetFrameRate(int nFrameRate)
{
    gnTargetFrameRate = nFrameRate;
    gnTargetMsPerFrame = 1000 / nFrameRate;
}

// 0x0052DFA0
void __stdcall GAME_SetGlobalAct(int nAct)
{
    gnAct = nAct;
}

// 0x0052E050
void __fastcall GAME_RemoveUnit(D2UnitStrc* pUnit, D2GameStrc* pGame)
{
    GAME_ForEachIngameClient(pGame, GAME_SendUnitRemovalToClient, pUnit);
    SUNIT_RemoveUnit(pGame, pUnit);
}

// 0x0052DFB0
void __fastcall GAME_SendUnitRemovalToClient(D2ClientStrc* pClient, D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return;
    }

    D2ActiveRoomStrc* pUnitRoom = UNITS_GetRoom(pUnit);
    D2ActiveRoomStrc* pClientRoom = pClient->hRoom;
    D2_ASSERT(pClientRoom, 5566);

    D2ActiveRoomStrc** ppRoomList;
    unsigned int nNumRooms;
    DUNGEON_GetAdjacentRoomsListFromRoom(pClientRoom, &ppRoomList, &nNumRooms);

    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        D2ActiveRoomStrc* pRoom = ppRoomList[i];
        D2_ASSERT(pRoom, 5571);

        if (pUnitRoom == pRoom)
        {
            D2GAME_PACKETS_SendPacket0x0A_RemoveObject(pClient, 0x0A, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
            return;
        }
    }
}

// 0x0052E8E0
void __stdcall GAME_SendGameList(void* pArg)
{
    for (int i = 0; i < 1024; ++i)
    {
        const int nGUID = gnGamesGUIDs[i];
        if (nGUID && nGUID != -1)
        {
            if (D2GameStrc* ptGame = GAME_LockGame(nGUID))
            {
                const unsigned int nClients = (unsigned short)ptGame->nClients;
                const unsigned short nGameId = ptGame->nGameId;
                char szGameName[16];
                SStrCopy(szGameName, ptGame->szGameName, 0x7FFFFFFF);

                D2_ASSERT(ptGame->lpCriticalSection, 0x1064);
                LeaveCriticalSection(ptGame->lpCriticalSection);

                D2GAME_PACKETS_SendGameListEntry(pArg, nGameId, nClients, szGameName);
            }
        }
    }

    D2GAME_PACKETS_SendGameListEntry(pArg, 0xFFFF, 0, &gszEmptyAssertText);
}

// 0x0052E9B0
void __fastcall GAME_HandleGameListRequest(void* pArg)
{
    GAME_SendGameList(pArg);
}

// 0x0052E9C0
void __stdcall GAME_CloseAllGames()
{
    TASK_FreeAllQueueSlots();

    for (int i = 0; i < 1024; ++i)
    {
        const int nGUID = gnGamesGUIDs[i];
        if (nGUID && nGUID != D2GameReservedSlotHandle)
        {
            D2GameStrc* ptGame = GAME_LockGame(nGUID);
            D2_ASSERT(ptGame, 0x1206);

            D2ClientStrc* pClient = ptGame->pClientList;
            while (pClient)
            {
                D2ClientStrc* pNextClient = pClient->pNext;

                D2GAME_PACKETS_SendGameLeft(pClient->dwClientId);
                D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
                D2GAME_SAVE_WriteFile(ptGame, pPlayer, CLIENTS_GetName(pClient), 1);
                GAME_SendRemainingSaveParts(ptGame, pClient);
                D2GAME_PACKETS_SendGameExit(pClient->dwClientId);
                ClientRemoveFromGame(ptGame, pClient->dwClientId, 0);

                pClient = pNextClient;
            }

            D2_ASSERT(ptGame->lpCriticalSection, 0x1064);
            LeaveCriticalSection(ptGame->lpCriticalSection);

            GAME_CloseGame(nGUID);
        }
    }
}

// 0x0052EAE0
int __stdcall GAME_GetExpansionGamesCount()
{
    int nExpansionGames = 0;
    for (int i = 0; i < 1024; ++i)
    {
        if (gnGamesGUIDs[i] && gnGamesGUIDs[i] != D2GameReservedSlotHandle)
        {
            if (D2GameStrc* pGame = GAME_LockGame(gnGamesGUIDs[i]))
            {
                if (pGame->bExpansion)
                {
                    ++nExpansionGames;
                }
                D2_ASSERT(pGame->lpCriticalSection, 4196);
                LeaveCriticalSection(pGame->lpCriticalSection);
            }
        }
    }
    return nExpansionGames;
}

// 0x0052EB50
void __stdcall GAME_GetClientCountHistogram(short* pCount, int nArraySize)
{
    memset(pCount, 0, 2 * nArraySize + 2);

    for (int i = 0; i < 1024; ++i)
    {
        const int nGameGuid = gnGamesGUIDs[i];
        if (nGameGuid && nGameGuid != D2GameReservedSlotHandle)
        {
            D2GameStrc* ptGame = GAME_LockGame(nGameGuid);
            if (ptGame)
            {
                int nIndex = ptGame->nClients;
                D2_ASSERT(ptGame->lpCriticalSection, 4196);
                LeaveCriticalSection(ptGame->lpCriticalSection);

                if (nIndex > nArraySize)
                {
                    nIndex = nArraySize;
                }

                ++pCount[nIndex];
            }
        }
    }
}

// 0x0052EBE0
void __stdcall GAME_GetGameAgeHistogram(unsigned short* pCount, int nMaxCount)
{
    memset(pCount, 0, sizeof(*pCount) * nMaxCount);

    for (int i = 0; i < 1024; ++i)
    {
        if (gnGamesGUIDs[i] && gnGamesGUIDs[i] != -1)
        {
            if (D2GameStrc* ptGame = GAME_LockGame(gnGamesGUIDs[i]))
            {
                const int nSecondsPassed = ptGame->dwGameFrame / 25;

                D2_ASSERT(ptGame->lpCriticalSection, 0x1064);
                LeaveCriticalSection(ptGame->lpCriticalSection);

                int nIndex = nSecondsPassed / 300;
                if (nIndex >= nMaxCount)
                {
                    nIndex = nMaxCount - 1;
                }

                ++pCount[nIndex];
            }
        }
    }
}

// 0x0052EC90
int __stdcall GAME_GetClientsCount(unsigned short nGameId)
{
    int nGUID = 0;
    EnterCriticalSection(&gGameListLock);
    if (gnGamesGUIDs[nGameId - 1] && gnGamesGUIDs[nGameId - 1] != D2GameReservedSlotHandle)
    {
        nGUID = gnGamesGUIDs[nGameId - 1];
    }
    LeaveCriticalSection(&gGameListLock);

    D2GameStrc* pGame = GAME_LockGame(nGUID);
    D2_ASSERT(pGame, 4806);
    const int nClients = pGame->nClients;
    D2_ASSERT(pGame->lpCriticalSection, 4196);
    LeaveCriticalSection(pGame->lpCriticalSection);
    return nClients;
}

// 0x0052ED10
int __stdcall GAME_GetGameInformation(unsigned short nGameId, D2GameInfoStrc* pGameInfo)
{
    int nGUID = 0;
    EnterCriticalSection(&gGameListLock);
    if (gnGamesGUIDs[nGameId - 1] && gnGamesGUIDs[nGameId - 1] != D2GameReservedSlotHandle)
    {
        nGUID = gnGamesGUIDs[nGameId - 1];
    }
    LeaveCriticalSection(&gGameListLock);

    D2GameStrc* ptGame = GAME_LockGame(nGUID);
    if (!ptGame)
    {
        return 0;
    }

    pGameInfo->nGameId = ptGame->nGameId;
    pGameInfo->nInitSeed = ptGame->dwInitSeed;
    pGameInfo->nClients = ptGame->nClients;
    pGameInfo->dwLastUsedUnitGUID[0] = ptGame->dwLastUsedUnitGUID[0];
    pGameInfo->dwLastUsedUnitGUID[1] = ptGame->dwLastUsedUnitGUID[1];
    pGameInfo->dwLastUsedUnitGUID[2] = ptGame->dwLastUsedUnitGUID[2];
    pGameInfo->dwLastUsedUnitGUID[3] = ptGame->dwLastUsedUnitGUID[3];
    pGameInfo->dwLastUsedUnitGUID[4] = ptGame->dwLastUsedUnitGUID[4];
    pGameInfo->dwLastUsedUnitGUID[5] = ptGame->dwLastUsedUnitGUID[5];

    pGameInfo->nPlayers = GAME_CountUnitsInLists(ptGame->pUnitList[0]);
    pGameInfo->nMonsters = GAME_CountUnitsInLists(ptGame->pUnitList[1]);
    pGameInfo->nObjects = GAME_CountUnitsInLists(ptGame->pUnitList[2]);
    pGameInfo->nItems = GAME_CountUnitsInLists(ptGame->pUnitList[3]);
    pGameInfo->nMissiles = GAME_CountUnitsInLists(ptGame->pUnitList[4]);

    if (ptGame->nTotalPathTypesCount)
    {
        pGameInfo->nPathTowardPct = 100 * (unsigned int)ptGame->dwPathTypesCount[PATHTYPE_TOWARD] / (unsigned int)ptGame->nTotalPathTypesCount;
        pGameInfo->nPathClockPct = 100 * (unsigned int)ptGame->dwPathTypesCount[PATHTYPE_MON_CIRCLE_CW] / (unsigned int)ptGame->nTotalPathTypesCount;
        pGameInfo->nPathCounterPct = 100 * (unsigned int)ptGame->dwPathTypesCount[PATHTYPE_MON_CIRCLE_CCW] / (unsigned int)ptGame->nTotalPathTypesCount;
        pGameInfo->nPathAStarPct = 100 * (unsigned int)ptGame->dwPathTypesCount[PATHTYPE_ASTAR] / (unsigned int)ptGame->nTotalPathTypesCount;
        pGameInfo->nPathFoWallPct = 100 * (unsigned int)ptGame->dwPathTypesCount[PATHTYPE_WALL_FOLLOW] / (unsigned int)ptGame->nTotalPathTypesCount;
        pGameInfo->nPathTotalCalls = ptGame->nTotalPathTypesCount;
        if ((unsigned int)ptGame->nTotalPathTypesCount > 200 && pGameInfo->nPathTotalCalls)
        {
            memset(ptGame->dwPathTypesCount, 0, sizeof(ptGame->dwPathTypesCount) + sizeof(ptGame->nTotalPathTypesCount));
        }
    }

    SStrCopy(pGameInfo->szGameName, ptGame->szGameName, 16);
    pGameInfo->nTime = (GetTickCount() - ptGame->nCreationTimeMs_Or_CPUTargetRatioFP10) / 1000 / 60;
    pGameInfo->nFrames = ptGame->dwGameFrame / 100;
    pGameInfo->nFrameRate = ptGame->nFrameRate;
    pGameInfo->nArenaTemplate = ptGame->nArenaTemplate;
    pGameInfo->nMaxLevelDifference = ptGame->nMaxLevelDifference;
    pGameInfo->nMaxPlayers = ptGame->nMaxPlayers;
    SStrCopy(pGameInfo->szGamePassword, ptGame->szGamePassword, 16);
    SStrCopy(pGameInfo->szGameDescription, ptGame->szGameDesc, 32);
    pGameInfo->nArenaFlags = ARENA_GetFlags(ptGame);
    pGameInfo->pMemoryPool = ptGame->pMemoryPool;

    D2_ASSERT(ptGame->lpCriticalSection, 4196);
    LeaveCriticalSection(ptGame->lpCriticalSection);
    return 1;
}

// 0x0052EF70
int __stdcall GAME_GetGameServerGameIds(unsigned short* pServerToken, int nMaxCount)
{
    int nServerTokenCount = 0;
    for (int i = 0; i < 1024; ++i)
    {
        if (nServerTokenCount >= nMaxCount)
        {
            break;
        }

        if (gnGamesGUIDs[i] && gnGamesGUIDs[i] != D2GameReservedSlotHandle)
        {
            D2GameStrc* pGame = GAME_LockGame(gnGamesGUIDs[i]);
            if (pGame)
            {
                pServerToken[nServerTokenCount] = pGame->nGameId;
                ++nServerTokenCount;
                D2_ASSERT(pGame->lpCriticalSection, 4196);
                LeaveCriticalSection(pGame->lpCriticalSection);
            }
        }
    }
    return nServerTokenCount;
}

// 0x0052EFF0
int __stdcall GAME_GetPlayerUnitsCount(unsigned short nGameId)
{
    int nGUID = 0;
    EnterCriticalSection(&gGameListLock);
    if (gnGamesGUIDs[nGameId - 1] && gnGamesGUIDs[nGameId - 1] != D2GameReservedSlotHandle)
    {
        nGUID = gnGamesGUIDs[nGameId - 1];
    }
    LeaveCriticalSection(&gGameListLock);

    D2GameStrc* pGame = GAME_LockGame(nGUID);
    int nUnits = 0;
    if (pGame)
    {
        nUnits = GAME_CountUnitsInLists(pGame->pUnitList[0]);
        D2_ASSERT(pGame->lpCriticalSection, 4196);
        LeaveCriticalSection(pGame->lpCriticalSection);
    }
    return nUnits;
}

// 0x0052F080
int __stdcall GAME_GetPlayerUnitsInfo(unsigned short nGameId, D2UnitInfoStrc* pUnitInfo, int nMaxCount)
{
    int nGUID = 0;
    EnterCriticalSection(&gGameListLock);
    if (gnGamesGUIDs[nGameId - GAME_ID_BIAS] && gnGamesGUIDs[nGameId - GAME_ID_BIAS] != -1)
        nGUID = gnGamesGUIDs[nGameId - GAME_ID_BIAS];
    LeaveCriticalSection(&gGameListLock);
    D2GameStrc* ptGame = GAME_LockGame(nGUID);
    int nCount = 0;
    if (ptGame)
    {
        for (int i = 0; i < BUCKETS; ++i)
        {
            if (nCount >= nMaxCount) break;
            for (D2UnitStrc* pUnit = ptGame->pUnitList[0][i]; pUnit; pUnit = SUNIT_GetNextUnitFromList(pUnit))
            {
                if (nCount >= nMaxCount) break;
                SUNIT_FillUnitInfo(pUnit, &pUnitInfo[nCount]);
                ++nCount;
            }
        }
        D2_ASSERT(ptGame->lpCriticalSection, UNLOCK_LINE);
        LeaveCriticalSection(ptGame->lpCriticalSection);
    }
    return nCount;
}

// 0x0052F160
void __stdcall GAME_GetUnitsDescriptions(unsigned short nGameId, D2UnitDescriptionListStrc* pUnitDescriptionsList, unsigned int eType)
{
    int nGUID = 0;
    EnterCriticalSection(&gGameListLock);
    if (gnGamesGUIDs[nGameId - 1] && gnGamesGUIDs[nGameId - 1] != D2GameReservedSlotHandle)
    {
        nGUID = gnGamesGUIDs[nGameId - 1];
    }
    LeaveCriticalSection(&gGameListLock);

    D2GameStrc* ptGame = GAME_LockGame(nGUID);
    D2UnitStrc** pUnitList = 0;
    if (ptGame)
    {
        switch (eType)
        {
        case 0:
            pUnitList = ptGame->pUnitList[0];
            break;
        case 1:
            pUnitList = ptGame->pUnitList[1];
            break;
        case 2:
            pUnitList = ptGame->pUnitList[2];
            break;
        case 3:
            pUnitList = ptGame->pUnitList[3];
            break;
        case 4:
            pUnitList = ptGame->pUnitList[4];
            break;
        }

        D2UnitDescriptionListStrc* pList = pUnitDescriptionsList;
        for (int i = 0; i < 128; ++i)
        {
            for (D2UnitStrc* pUnit = pUnitList[i]; pUnit; pUnit = SUNIT_GetNextUnitFromList(pUnit))
            {
                const int v_dwClassId_147 = pUnit ? pUnit->dwClassId : -1;
                GAME_AddUnitDescription(1, v_dwClassId_147, pList);
            }
        }

        D2_ASSERT(ptGame->lpCriticalSection, 4196);
        LeaveCriticalSection(ptGame->lpCriticalSection);

        const unsigned int nType = eType;
        D2_ASSERT(!IsBadCodePtr((FARPROC)gpfnGetDescription[nType]), 0x1450);
        for (D2UnitDescriptionListStrc* pNode = pList->pNext; pNode; pNode = pNode->pNext)
        {
            gpfnGetDescription[nType](pNode->szDescription, pNode->nClassId);
        }
    }
}

static D2MonStatsTxt* SUNITPROXY_GetMonStatsTxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    return 0;
}

// 0x0052F2C0
int __stdcall GAME_GetUnitsInfoById(unsigned short nGameId, int nMaxCount, D2UnitInfoStrc* pUnitInfo, int* pUnitType, int* pUnitGUID)
{
    int nGUID = 0;
    EnterCriticalSection(&gGameListLock);
    if (gnGamesGUIDs[nGameId - 1] && gnGamesGUIDs[nGameId - 1] != D2GameReservedSlotHandle)
    {
        nGUID = gnGamesGUIDs[nGameId - 1];
    }
    LeaveCriticalSection(&gGameListLock);

    D2GameStrc* ptGame = GAME_LockGame(nGUID);
    int nUnitInfoCount = 0;
    if (!ptGame)
    {
        return 0;
    }

    {
        for (int i = 0; i < nMaxCount; ++i)
        {
            D2UnitStrc* pUnit = SUNIT_GetServerUnit(ptGame, pUnitType[i], pUnitGUID[i]);
            if (pUnit)
            {
                SUNIT_FillUnitInfo(pUnit, &pUnitInfo[nUnitInfoCount]);

                if (pUnitType[i])
                {
                    D2_ASSERT(!IsBadCodePtr((FARPROC)gpfnGetDescription[pUnitType[i]]), 0x1472);
                    gpfnGetDescription[pUnitType[i]](pUnitInfo[nUnitInfoCount].szDescription, pUnit->dwClassId);
                }

                ++nUnitInfoCount;
            }
        }

        D2_ASSERT(ptGame->lpCriticalSection, 4196);
        LeaveCriticalSection(ptGame->lpCriticalSection);
    }

    return nUnitInfoCount;
}

// 0x0052F3E0
void __stdcall GAME_GetStatistics(D2GameStatisticsStrc* pStats)
{
    pStats->nGamesCount = 0;
    pStats->nActiveMonsters = 0;
    pStats->nInactiveMonsters = 0;
    pStats->nPlayersCount = 0;

    for (int i = 0; i < 1024; ++i)
    {
        if (gnGamesGUIDs[i] && gnGamesGUIDs[i] != D2GameReservedSlotHandle)
        {
            if (D2GameStrc* ptGame = GAME_LockGame(gnGamesGUIDs[i]))
            {
                for (int j = 0; j < 128; ++j)
                {
                    for (D2UnitStrc* k = ptGame->pUnitList[UNIT_MONSTER][j]; k; k = SUNIT_GetNextUnitFromList(k))
                    {
                        ++pStats->nActiveMonsters;
                    }

                    for (D2UnitStrc* k = ptGame->pUnitList[UNIT_PLAYER][j]; k; k = SUNIT_GetNextUnitFromList(k))
                    {
                        ++pStats->nPlayersCount;
                    }
                }

                D2_ASSERT(ptGame->lpCriticalSection, 4196);
                LeaveCriticalSection(ptGame->lpCriticalSection);

                ++pStats->nGamesCount;
            }
        }
    }
}

// 0x0052F4C0
void __stdcall GAME_SendMessageToAllClients(int nMessageType, int nPacketParam, const char* szMessage)
{
    for (int i = 0; i < 1024; ++i)
    {
        if (gnGamesGUIDs[i] && gnGamesGUIDs[i] != -1)
        {
            D2GameStrc* ptGame = GAME_LockGame(gnGamesGUIDs[i]);
            D2_ASSERT(ptGame, 0x1063);
            switch (nMessageType)
            {
            case 1:
            {
                D2GSPacketSrv5A packet5A = {};
                packet5A.nHeader = 0x5A;
                packet5A.nType = 0x0F;
                packet5A.nColor = 4;
                packet5A.dwParam = nPacketParam;
                packet5A.szText[16] = 0;
                PLRMSG_BroadcastEventMessage(ptGame, &packet5A);
                break;
            }
            default:
                if (strlen(szMessage) > 255)
                {
                    char szCopy[256];
                    strncpy(szCopy, szMessage, 255);
                    szCopy[255] = '\0';
                    PLRMSG_BroadcastSystemMessage(ptGame, szCopy, 1);
                }
                else
                {
                    PLRMSG_BroadcastSystemMessage(ptGame, szMessage, 1);
                }
                break;
            }

            D2_ASSERT(ptGame->lpCriticalSection, 0x1064);
            LeaveCriticalSection(ptGame->lpCriticalSection);
        }
    }
}

// 0x0052F630
void __stdcall GAME_SendMessageToGameClients(unsigned short gameId,unsigned char* message)
{
    int guid = 0;
    EnterCriticalSection(&gGameListLock);
    if (gnGamesGUIDs[gameId-1] && gnGamesGUIDs[gameId-1] != -1) guid = gnGamesGUIDs[gameId-1];
    LeaveCriticalSection(&gGameListLock);
    D2GameStrc* ptGame = GAME_LockGame(guid);
    D2_ASSERT(ptGame,0x1564);
    message[255] = 0;
    if (!strncmp("<ABEND> ",(const char*)message,8)) ptGame->nDebugBreakTrigger = message[8] & MODE_MASK;
    PLRMSG_BroadcastSystemMessage(ptGame,(const char*)message,1);
    D2_ASSERT(ptGame->lpCriticalSection,0x1064);
    LeaveCriticalSection(ptGame->lpCriticalSection);
}

// 0x0052F6E0
D2GameStrc* __fastcall GAME_LockDebugGame()
{
    int nGUID = 0;
    EnterCriticalSection(&gGameListLock);

    if (*gnGamesGUIDs && *gnGamesGUIDs != D2GameReservedSlotHandle)
    {
        nGUID = *gnGamesGUIDs;
    }

    LeaveCriticalSection(&gGameListLock);

    gpGame = GAME_LockGame(nGUID);
    return gpGame;
}

// 0x0052F720
unsigned long __stdcall GAME_SendMessageThreadProc(D2MessageThreadArgsStrc* pArgs)
{
    GAME_SendMessageToAllClients(pArgs->nParam1, pArgs->nParam2, pArgs->szMessage);
    return 1;
}

// 0x0052F740
void __fastcall GAME_SendMessageToAllClientsAsync(int nParam1, int nPacketParam, const char* szMessage)
{
    unsigned long nThreadId;
    D2MessageThreadArgsStrc* pArgs = (D2MessageThreadArgsStrc*)FOG_AllocPool(0, sizeof(D2MessageThreadArgsStrc), ".\\GAME\\Game.cpp", 5665, 0);
    if (pArgs)
    {
        pArgs->nParam1 = nParam1;
        pArgs->nParam2 = nPacketParam;
        strncpy(pArgs->szMessage, szMessage, 0xFF);
        pArgs->szMessage[0xFF] = 0;
        CreateThread(0, 0, GAME_SendMessageThreadProc, pArgs, 0, &nThreadId);
    }
}

// 0x0052F7B0
int __fastcall GAME_FindGameWithName(const char* szGameName)
{
    for (int i = 0; i < 1024; ++i)
    {
        const int nGameGUID = gnGamesGUIDs[i];
        if (nGameGUID)
        {
            D2GameStrc* pGame = GAME_LockGame(nGameGUID);
            if (pGame)
            {
                if (!SStrCmpI(pGame->szGameName, szGameName, 0x7FFFFFFF))
                {
                    D2_ASSERT(pGame->lpCriticalSection, 4196);
                    LeaveCriticalSection(pGame->lpCriticalSection);
                    return nGameGUID;
                }
                D2_ASSERT(pGame->lpCriticalSection, 4196);
                LeaveCriticalSection(pGame->lpCriticalSection);
            }
        }
    }
    return 0;
}

// 0x0052F840
unsigned int __fastcall GAME_GetFirstGameInitSeed()
{
    int nGUID = 0;
    EnterCriticalSection(&gGameListLock);
    if (*gnGamesGUIDs && *gnGamesGUIDs != D2GameReservedSlotHandle)
    {
        nGUID = *gnGamesGUIDs;
    }
    LeaveCriticalSection(&gGameListLock);

    D2GameStrc* pGame = GAME_LockGame(nGUID);
    gpGame = pGame;
    if (!pGame)
    {
        return 0;
    }

    const unsigned int nInitSeed = pGame->dwInitSeed;
    D2_ASSERT(pGame->lpCriticalSection, 4196);
    LeaveCriticalSection(pGame->lpCriticalSection);
    return nInitSeed;
}

// 0x0052E070
int __cdecl sub_0052E070_Return0()
{
    return 0;
}

// 0x0052E080
int __cdecl sub_0052E080_Return0()
{
    return 0;
}

// 0x0052E090
int __stdcall SKILLS_Return0(int nUnused)
{
    return 0;
}

// 0x0052E0A0
void D2GameDataTableStrc::SyncEnterLock(int* pLockHandle, int bForWriting)
{
    EnterCriticalSection(&f_50);
    *pLockHandle = bForWriting ? 1 : -1;
}

// 0x0052E0D0
int __stdcall GAME_IsValueOne(int nValue)
{
    return nValue == 1;
}

// 0x0052E0E0
unsigned int D2StormHashTableStrc::MaskHash(unsigned int value) {return m_slotmask & value;}

// 0x0052E100
char* __fastcall DRLGPRESET_GetLinkRawNext(D2StormLinkStrc* pLink)
{
    return pLink->m_next;
}

struct R0052E0F0
{
    void* pUnk0x00;
    void* m_pFile;
    bool sub_0052E0F0_IsOpen();
};

// 0x0052E0F0
bool R0052E0F0::sub_0052E0F0_IsOpen()
{
    return m_pFile != 0;
}

extern "C" void __cdecl sub_00548090(); // 0x00548090
extern "C" void __cdecl sub_005482A0(); // 0x005482A0
extern "C" void __cdecl sub_00548350(); // 0x00548350
extern "C" void __cdecl sub_00548400(); // 0x00548400
extern "C" void __cdecl sub_0054DA10(); // 0x0054DA10

#pragma pack(push, 1)
struct d2data_00731018_t
{
    const void* p0;
    const void* p1;
    const void* p2;
    const void* p3;
    const void* p4;
    const void* p5;
    const void* p6;
    const void* p7;
    const void* p8;
    const void* p9;
    const void* p10;
    const void* p11;
    const void* p12;
    const void* p13;
    const void* p14;
    const void* p15;
    const void* p16;
    const void* p17;
    const void* p18;
    const void* p19;
    const void* p20;
    const void* p21;
    const void* p22;
    const void* p23;
    const void* p24;
};
#pragma pack(pop)

extern "C" struct d2data_00731018_t gtDefaultServerCallbackFunctions; // 0x00731018

extern int gdwGlobal_00731008 = 100; // 0x00731008

extern int gdwGlobal_00731010 = 25; // 0x00731010

extern int gbFixedCpuTargetRatio = 1; // 0x0073100C

extern unsigned short gwGameId = 1; // 0x00731000

extern int gnTargetFrameRate = 25; // 0x00731014

extern "C" struct d2data_00731018_t gtDefaultServerCallbackFunctions = {
    (const void*)(unsigned int)&GAME_DefaultCloseGame,
    (const void*)(unsigned int)&NET_DefaultLeaveGame,
    (const void*)(unsigned int)&GAME_DefaultGetDatabaseCharacter,
    (const void*)(unsigned int)&NET_DefaultSaveDatabaseCharacter,
    (const void*)(unsigned int)&NET_DefaultServerLogMessage,
    (const void*)(unsigned int)&NET_DefaultEnterGame,
    (const void*)(unsigned int)&NET_DefaultFindPlayerToken,
    (const void*)(unsigned int)&GAME_DefaultSaveDatabaseGuild,
    (const void*)(unsigned int)&GAME_DefaultUnlockDatabaseCharacter,
    (const void*)(unsigned int)&sub_0052BEC0_Nop,
    (const void*)(unsigned int)&NET_DefaultUpdateCharacterLadder,
    (const void*)(unsigned int)&GAME_DefaultUpdateGameInformation,
    (const void*)(unsigned int)&GAME_DefaultGetGameServerInfo,
    (const void*)(unsigned int)&GAME_DefaultGetValue,
    (const void*)(unsigned int)&GAME_DefaultRelockDatabaseCharacter,
    (const void*)(unsigned int)&GAME_DefaultLoadComplete,
    (const void*)(unsigned int)&sub_0052BF30_Nop,
    (const void*)(unsigned int)&sub_0052BF40_Stub,
    (const void*)(unsigned int)&sub_0052BF50_Return0,
    (const void*)(unsigned int)&sub_0052BF60_Return0,
    (const void*)(unsigned int)&sub_0052BF70_Return0,
    (const void*)(unsigned int)&GAME_ZeroBlock8,
    (const void*)(unsigned int)&sub_0052BF90_GetData6E0550,
    (const void*)(unsigned int)&sub_0052BFA0_GetData6E0568,
    (const void*)(unsigned int)&sub_0052BFB0_Stub
}; // 0x00731018

extern int gbCheckHeartbeat = 1; // 0x00730FFC

extern UnitDescriptionFunction gpfnGetDescription[5] = { (UnitDescriptionFunction)&GAME_GetPlayerDescription, (UnitDescriptionFunction)&GAME_GetMonsterDescription, (UnitDescriptionFunction)&GAME_GetObjectDescription, (UnitDescriptionFunction)&GAME_GetItemDescription, (UnitDescriptionFunction)&GAME_GetMissileDescription }; // 0x0073107C

extern const char gszEmptyLoadComplete[184] = { 0 }; // 0x006E0498

extern const char gData_006E0550[24] = { 0 }; // 0x006E0550

extern const char gData_006E0568[272] = { 0 }; // 0x006E0568
