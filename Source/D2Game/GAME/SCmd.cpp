#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2MonModes.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2Drlg.h"
#include "D2UnitData.h"
#include "D2GameRecords.h"
#include "D2Path.h"
#include "D2Primitives.h"
#include "D2GameObjs.h"
#include "D2GameClient.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Packets.h"
#include "D2LanguageNames.h"
#include "FogApi.h"
#include "StormApi.h"
#include "FogApi.h"
// build: symbol _gaszLanguageNames 0x00731358

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2MonsterDataStrc;


#include "D2GameFuncs.h"
#include "D2CommonApi.h"
#include "FogApi2.h"


extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09


int __stdcall SERVER_SendPacketToClient(unsigned char nFlags, int nClientId, void* pPacket, int nSize); // 0x0052B330


#define ITEMACTION_REMOVEFROMCONTAINER 5

#define ITEMACTION_EQUIP 6

#define ITEMACTION_INDIRECTLYSWAPBODYITEM 7

#define ITEMACTION_UNEQUIP 8

#define ITEMACTION_SWAPBODYITEM 9

#define ITEMACTION_AUTOUNEQUIP 0x11

#define ITEMACTION_UNKNOWN0x14 0x14

#define ITEMACTION_WEAPONSWITCH 0x17

#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))


#define ITEMACTION_ADDTOGROUND 0

#define ITEMACTION_GROUNDTOCURSOR 1

#define ITEMACTION_PUTINCONTAINER 4

#define ITEMACTION_ADDQUANTITY 10

#define ITEMACTION_ADDTOSHOP 11

#define ITEMACTION_REMOVEFROMSHOP 12

#define ITEMACTION_SWAPINCONTAINER 13

#define ITEMACTION_PUTINBELT 14

#define ITEMACTION_REMOVEFROMBELT 15

#define ITEMACTION_SWAPINBELT 16

#define ITEMACTION_TOCURSOR 18

#define ITEMACTION_ITEMINSOCKET 19

#define ITEMACTION_UPDATESTATS 21

#define ITEMACTION_UNKNOWN0x16 22

#define IFLAG_DELETED 0x00000008

#define IFLAG_IDENTIFIED 0x00000010

#define IFLAG_QUANTITY 0x00000020


struct D2PacketDataStrc;


struct D2StaticPathStrc;


struct D2PackedGuidStrc;

struct D2MessageStrc;

struct D2GSPacketSrv27;


struct D2LifeSyncStrc;

struct D2PlayerDataStrc;


struct D2ObjectDataStrc;


struct D2GSPacketSrv91;


void __fastcall D2GAME_SendPacket0x9D(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, char nAction, unsigned int dwFlag, int bGamble); // 0x0053CEF0


unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250

void __stdcall ITEMS_SetInvPage(D2UnitStrc* pItem, unsigned char nPage); // 0x00628280

unsigned char __stdcall ITEMS_GetItemCell(D2UnitStrc* pItem); // 0x006282F0


extern "C" void* __cdecl memset(void* pDest, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetTail(D2ClientStrc* pClient); // 0x005392D0

void __fastcall CLIENTS_PacketDataList_Append(D2ClientStrc* pClient, D2PacketDataStrc* pPacketData); // 0x00539240


D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc* pGame, int nUnitType, int nUnitGUID); // 0x00552F60

int __stdcall PATH_GetLastPointX(D2DynamicPathStrc* pPath); // 0x00648A40

int __stdcall PATH_GetLastPointY(D2DynamicPathStrc* pPath); // 0x00648A60


extern const char text_006CC837[]; // 0x006CC837

__declspec(noreturn) void __cdecl sub_00681E09(int); // 0x00681E09

extern "C" unsigned int __cdecl strlen(const char* szString);

struct D2GSPacketSrv27
{
    unsigned char nHeader;
    unsigned char nUnitType;
    D2PackedGuidStrc dwUnitGUID;
    unsigned char nCount;
    unsigned char pad0x07;
    D2MessageStrc pMessages[8];
};


unsigned short __fastcall PARTY_GetPartyIdForUnitOwner(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00540710

int __stdcall UNITS_GetCurrentLifePercentage(D2UnitStrc* pUnit); // 0x00621F20

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20


void __fastcall SCMD_WriteVariableValue(D2BitBufferStrc* pBuffer, unsigned int nValue); // 0x0053B0E0


int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile); // 0x006280A0

int __stdcall ITEMS_CheckIfSocketable(D2UnitStrc* pItem); // 0x00629900


short __fastcall SUNIT_GetPartyId(D2UnitStrc* pPlayer); // 0x00554630

unsigned short __fastcall PLAYERLIST_GetFlags(D2UnitStrc* pPlayer1, D2UnitStrc* pPlayer2); // 0x0055B350


int __fastcall SCMD_SendSocketedItems(D2ClientStrc* pClient, D2UnitStrc* pItem, int nFlags); // 0x0053EA50

D2PacketDataStrc* __fastcall CLIENTS_PacketDataList_GetHead(D2ClientStrc*); // 0x005392E0


static int __stdcall SCMD_ShouldSendMinionLifeUpdate(D2UnitStrc*, D2UnitStrc*, int);

static int __stdcall SCMD_ShouldSendPartyLifeUpdate(D2UnitStrc* pUnit, int nLifePercentage, int nLevelId, D2UnitStrc* pPlayer); // 0x0053CC90

static void __stdcall D2GAME_PACKETS_SendPacket(D2ClientStrc* pClient, const void* pPacket, int nPacketSize); // 0x0053B280

static int __stdcall SCMD_ShouldSendUnitLifeUpdate(D2UnitStrc* pPlayer, D2UnitStrc* pUnit, int nLifePercentage, int nLevelId);

static int SCMD_ShouldSendLifeUpdate(int nLifePercentage, D2LifeSyncStrc* pLifeSync);


void __fastcall D2GAME_PACKETS_SendPacketSize06(D2ClientStrc* pClient, unsigned char nHeader, int dwUnitType, int dwUnitId); // 0x0053B3D0


struct D2SkillListStrc;

void __fastcall FOG_FreePool(void*, void*, const char*, int, int); // 0x0040B480

extern "C" const char gszSCmdSourceFile[];                                                             // 0x006D69E4

#define offsetof(s, m) ((unsigned int)&(((s*)0)->m))


extern "C" unsigned short __fastcall CLIENTS_GetGuildFlags(D2ClientStrc* pClient);                                 // 0x00539110

extern "C" void __fastcall CLIENTS_GetGuildTag(D2ClientStrc* pClient, unsigned int* pOut);                       // 0x00539130

extern "C" void __fastcall CLIENTS_GetGuildName(D2ClientStrc* pClient, char* pDst);                               // 0x00539150

void __fastcall PLAYERPETS_SendPetsToClient(D2ClientStrc* pClient, D2UnitStrc* pPlayer);               // 0x00574F80

enum { HEADER = 0x40 };


#define MONTYPEFLAG_CHAMPION 4

#define MONTYPEFLAG_UNIQUE 8

#define MONTYPEFLAG_MINION 16

#define MONTYPEFLAG_GHOSTLY 64

#define UNITFLAG_ISMERC 0x200

#define ITEMSTATCOSTFLAGINDEX_SEND_OTHER 0


typedef void (__fastcall* SUNIT_IterateFn)(D2GameStrc* pGame, D2UnitStrc* pUnit, void* pArg);

void __fastcall SUNIT_IterateLivingPlayers(D2GameStrc* pGame, SUNIT_IterateFn pfIterate, void* pArg); // 0x005538D0

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern const unsigned int gdwBitMasks[32]; // 0x006CE268


unsigned char* __fastcall MONSTERUNIQUE_GetUMods(D2UnitStrc* pUnit); // 0x005A0120


int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc* pUnit, int nFlag); // 0x005A0180


int __fastcall MONSTERUNIQUE_HasMonsterFlag(D2UnitStrc* pUnit); // 0x005A0380

unsigned char __fastcall MONSTERMODE_GetHpPercent128(D2UnitStrc* pUnit); // 0x005A5650


void __fastcall D2GAME_PACKETS_SendPacket0x22(D2ClientStrc* pClient, unsigned char nUnitType, int nUnitGUID, int nSkillId, int nQuantity); // 0x0053C520


extern "C" char* __cdecl strcpy(char* pDst, const char* pSrc);

#pragma intrinsic(strcpy)

#define ITEMACTION_DROPTOGROUND 2

#define ITEMACTION_ONGROUND 3

// 0x0053B0E0
void __fastcall SCMD_WriteVariableValue(D2BitBufferStrc* pBuffer, unsigned int nValue)
{
    if (nValue < 0x100)
    {
        BITMANIP_Write(pBuffer, 0, 1);
        BITMANIP_Write(pBuffer, nValue, 8);
    }
    else
    {
        BITMANIP_Write(pBuffer, 1, 1);
        if (nValue < 0x10000)
        {
            BITMANIP_Write(pBuffer, 0, 1);
            BITMANIP_Write(pBuffer, nValue, 16);
        }
        else
        {
            BITMANIP_Write(pBuffer, 1, 1);
            BITMANIP_Write(pBuffer, nValue, 32);
        }
    }
}

// 0x0053B140
void __fastcall SCMD_WriteVariableWord(D2BitBufferStrc* pBuffer, unsigned short nValue)
{
    if (nValue < 0x100)
    {
        BITMANIP_Write(pBuffer, 0, 1);
        BITMANIP_Write(pBuffer, nValue, 8);
    }
    else
    {
        BITMANIP_Write(pBuffer, 1, 1);
        BITMANIP_Write(pBuffer, nValue, 16);
    }
}

// 0x0053B180
int* __fastcall SCMD_GetMonsterOwnerGuidPtr(D2UnitStrc* pUnit)
{
    if (!pUnit || pUnit->dwUnitType != UNIT_MONSTER)
    {
        return 0;
    }
    D2MonsterDataStrc* pMonsterData = pUnit->pMonsterData;
    if (!pMonsterData)
    {
        return 0;
    }
    return &pMonsterData->nOwnerGUID;
}

// 0x0053B1A0
static inline void SCMD_SendToClient(int nClientId, void* pPacket, int nSize)
{
    SERVER_SendPacketToClient(0, nClientId, pPacket, nSize);
}
void __stdcall sub_M121_Emit_0053B1A0(int nClientId, void* pPacket, int nSize) { SCMD_SendToClient(nClientId, pPacket, nSize); }

// 0x0053B1B0
int __fastcall D2GAME_PACKETS_SendGameListEntry(int nClientId, short nGameId, short nClientCount, const char* szGameName)
{
    D2GSPacketSrvB1 packetB1;

    packetB1.nHeader = 0xB2;
    packetB1.nGameId = nGameId;
    packetB1.nClientCount = nClientCount;

    SStrCopy(packetB1.szGameName, szGameName, 0x10);

    return SERVER_SendPacketToClient(0, nClientId, &packetB1, sizeof(packetB1));
}

// 0x0053B210
int __fastcall PLRMODE_ModeCheck_Death(D2GameStrc* pGame, D2UnitStrc* pPlayer, int nSkillId, int nSkillLevel)
{
    return 1;
}

// 0x0053B220
void __fastcall D2GAME_PACKETS_SendGameLeft(int nClientId)
{
    D2GSPacketSrvB0 packetB0;
    packetB0.nHeader = 0xB0;
    SERVER_SendPacketToClient(0, nClientId, &packetB0, sizeof(packetB0));
}

// 0x0053B240
void __fastcall D2GAME_PACKETS_SendGameExit(int nClientId)
{
    D2GSPacketSrv06 packet06;
    packet06.nHeader = 0x06;
    SERVER_SendPacketToClient(1, nClientId, &packet06, sizeof(packet06));
}

// 0x0053B260
void __fastcall D2GAME_PACKETS_SendSystemError(int nClientId, unsigned int nErrorCode)
{
    unsigned int packetB4[2];
    *(unsigned char*)packetB4 = 0xB4;
    *(unsigned int*)((unsigned char*)packetB4 + 1) = nErrorCode;
    SERVER_SendPacketToClient(0, nClientId, packetB4, 5);
}

// 0x0053B280
static void __stdcall D2GAME_PACKETS_SendPacket(D2ClientStrc* pClient, const void* pPacket, int nPacketSize)
{
    int nSize = 0;
    if (!pClient)
    {
        return;
    }

    D2PacketDataStrc* pPacketData = CLIENTS_PacketDataList_GetTail(pClient);
    if (pPacketData)
    {
        nSize = pPacketData->nPacketSize;
    }

    if (nPacketSize + nSize > 0x200 || !pPacketData)
    {
        pPacketData = pClient->pPacketDataPool;
        nSize = 0;
        if (pPacketData)
        {
            pClient->pPacketDataPool = pPacketData->pNext;
        }
        else
        {
            pPacketData = (D2PacketDataStrc*)FOG_AllocPool(0, sizeof(D2PacketDataStrc), ".\\GAME\\SCmd.cpp", 0xA0, 0);
        }

        memset(pPacketData, 0, sizeof(D2PacketDataStrc));
        CLIENTS_PacketDataList_Append(pClient, pPacketData);
    }

    memcpy(&pPacketData->packetData[nSize], pPacket, nPacketSize);
    pPacketData->nPacketSize += nPacketSize;
}

// 0x0053B320
void __fastcall D2GAME_PACKETS_SendHeaderOnlyPacket(D2ClientStrc* pClient, unsigned char nHeader)
{
    D2PacketHeaderOnlyStrc tPacket;
    tPacket.nHeader = nHeader;
    D2GAME_PACKETS_SendPacket(pClient, &tPacket, sizeof(tPacket));
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
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

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
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

static inline int SCMD_GetUnitGUID(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwUnitId;
}

// 0x0053B340
void __fastcall D2GAME_PACKETS_SendPacket0x01(D2ClientStrc* pClient, char nHeader, D2GameStrc* pGame)
{
    D2GSPacketSrv01 packet01;

    packet01.nHeader = nHeader;
    packet01.dwArenaFlags = ARENA_GetFlags(pGame);
    packet01.nDifficulty = pGame->nDifficulty;
    packet01.nExpansion = pGame->bExpansion != 0;
    packet01.nLadder = pGame->dwGameType != 0;

    D2GAME_PACKETS_SendPacket(pClient, &packet01, sizeof(packet01));
}

// 0x0053B390
void __fastcall D2GAME_PACKETS_SendPacket0x03(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nAct, unsigned int dwInitSeed, unsigned int dwObjSeed, int nTownLevelId)
{
    D2GSPacketSrv03Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.nAct = nAct;
    tPacket.dwGameSeed = dwInitSeed;
    tPacket.nObjectSeed = dwObjSeed;
    tPacket.nTownLevelId = nTownLevelId;
    D2GAME_PACKETS_SendPacket(pClient, &tPacket, sizeof(tPacket));
}

// 0x0053B3D0
void __fastcall D2GAME_PACKETS_SendPacketSize06(D2ClientStrc* pClient, unsigned char nHeader, int dwUnitType, int dwUnitId)
{
    D2PacketSize06Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.nUnitType = dwUnitType;
    tPacket.nUnitGUID = dwUnitId;
    D2GAME_PACKETS_SendPacket(pClient, &tPacket, sizeof(tPacket));
}

// 0x0053B400
void __fastcall D2GAME_SendPacketSize05(D2ClientStrc* pClient, unsigned char nHeader, int nValue)
{
    D2PacketSize05Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.nValue = nValue;
    D2GAME_PACKETS_SendPacket(pClient, &tPacket, sizeof(tPacket));
}

// 0x0053B430
void __fastcall D2GAME_PACKETS_SendPacket0x0C(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, unsigned char nMessage, unsigned char nHitClass, unsigned char nLifePct)
{
    D2GSPacketSrv0C packet0C;

    packet0C.nHeader = nHeader;
    packet0C.nUnitType = nUnitType;
    packet0C.dwUnitGUID = nUnitGUID;
    packet0C.nMessage = nMessage;
    packet0C.nHitClass = nHitClass;
    packet0C.nLife = nLifePct;

    D2GAME_PACKETS_SendPacket(pClient, &packet0C, sizeof(packet0C));
}

// 0x0053B470
void __fastcall D2GAME_PACKETS_SendPacket0x0E(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, unsigned char nEvent, unsigned char bTargetable, int nAnimMode)
{
    D2GSPacketSrv0EStrc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.nUnitType = nUnitType;
    tPacket.nUnitGUID = nUnitGUID;
    tPacket.nEvent = nEvent;
    tPacket.bTargetable = bTargetable;
    tPacket.nAnimMode = nAnimMode;
    D2GAME_PACKETS_SendPacket(pClient, &tPacket, sizeof(tPacket));
}

// 0x0053B4B0
void __fastcall D2GAME_PACKETS_SendPacket0x0D(D2ClientStrc* pClient, unsigned char nPacketId, unsigned char nUnitType, int nUnitId, unsigned char nHitClass, unsigned short nX, unsigned short nY, unsigned char nHitType, unsigned char nLife)
{
    D2GSPacketSrv0D packet0D;

    packet0D.nHeader = nPacketId;
    packet0D.nUnitType = nUnitType;
    packet0D.dwUnitGUID = nUnitId;
    packet0D.nHitClass = nHitClass;
    packet0D.nX = nX;
    packet0D.nY = nY;
    packet0D.nHitType = nHitType;
    packet0D.nUnitLifePct = nLife;

    D2_ASSERT(nUnitType < 6, 0x136);

    D2GAME_PACKETS_SendPacket(pClient, &packet0D, sizeof(packet0D));
}

// 0x0053B520
void __fastcall D2GAME_PACKETS_SendPacket0x10(D2ClientStrc* pClient, char nHeader, char nUnitType, int nUnitGUID, char nFlags, int nTargetType, int nTargetGUID, short nCurrentPosX, short nCurrentPosY)
{
    D2GSPacketSrv10Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.nUnitType = nUnitType;
    tPacket.nUnitGUID = nUnitGUID;
    tPacket.nFlags = nFlags;
    tPacket.nTargetType = nTargetType;
    tPacket.nTargetGUID = nTargetGUID;
    tPacket.nCurrentPosX = nCurrentPosX;
    tPacket.nCurrentPosY = nCurrentPosY;
    D2GAME_PACKETS_SendPacket(pClient, &tPacket, sizeof(tPacket));
}

// 0x0053B570
void __fastcall D2GAME_PACKETS_SendPacket0x0F(D2ClientStrc* pClient, char nHeader, unsigned char bTOU, int nUnitGUID, char nFlags, short nDestPosX, short nDestPosY, char nHitClass, short nCurrentPosX, short nCurrentPosY)
{
    D2GSPacketSrv0FStrc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.nUnitType = bTOU;
    tPacket.nUnitGUID = nUnitGUID;
    tPacket.nFlags = nFlags;
    tPacket.nDestPosX = nDestPosX;
    tPacket.nDestPosY = nDestPosY;
    tPacket.nHitClass = nHitClass;
    tPacket.nCurrentPosX = nCurrentPosX;
    tPacket.nCurrentPosY = nCurrentPosY;
    D2_ASSERT(bTOU < UNIT_TYPES_COUNT, 0x166);
    D2GAME_PACKETS_SendPacket(pClient, &tPacket, sizeof(tPacket));
}

// 0x0053B5F0
void __fastcall D2GAME_PACKETS_SendPacket0x68(D2ClientStrc* pClient, unsigned char nHeader, int nUnitGUID, char nMessage, char nTargetUnitType, int nTargetUnitGUID, char nUnitLife)
{
    D2GSPacketSrv68 packet68 = {};

    packet68.nHeader = nHeader;
    packet68.nUnitGUID = nUnitGUID;
    packet68.nMessage = nMessage;
    packet68.nTargetUnitType = nTargetUnitType;
    packet68.nTargetUnitGUID = nTargetUnitGUID;

    D2UnitStrc* pMonster = SUNIT_GetServerUnit(CLIENTS_GetGame(pClient), UNIT_MONSTER, nUnitGUID);
    D2DynamicPathStrc* pPath = pMonster->pDynamicPath;

    packet68.nX = CLIENTS_GetUnitXInline(pMonster);
    packet68.nY = CLIENTS_GetUnitYInline(pMonster);
    packet68.nUnitLife = nUnitLife;
    packet68.nPathType = PATH_GetType(pPath);
    if (packet68.nPathType >= 5)
    {
        if (packet68.nPathType > 6)
        {
            if (packet68.nPathType == 8)
            {
                packet68.nPathType = 11;
            }
        }
        else
        {
            packet68.nPathType = 2;
        }
    }

    int nVelocity = STATLIST_UnitGetStatValue(pMonster, STAT_VELOCITYPERCENT, 0);
    nVelocity = D2_MIN(D2_MAX(nVelocity, -32768), 32767);
    packet68.nVelocity = nVelocity;
    packet68.nMaxDistance = PATH_GetMaxDistance(pPath);
    D2GAME_PACKETS_SendPacket(pClient, &packet68, sizeof(packet68));
}

// 0x0053B710
void __fastcall D2GAME_PACKETS_SendPacket0x67(D2ClientStrc* pClient, unsigned char nHeader, int nUnitGUID, char nMessage, short nX, short nY, char nUnitLife)
{
    D2GSPacketSrv67 packet67 = {};

    packet67.nHeader = nHeader;
    packet67.nUnitGUID = nUnitGUID;
    packet67.nMessage = nMessage;
    packet67.nX = nX;
    packet67.nY = nY;

    D2UnitStrc* pMonster = SUNIT_GetServerUnit(CLIENTS_GetGame(pClient), UNIT_MONSTER, nUnitGUID);
    if (!pMonster)
    {
        return;
    }

    D2DynamicPathStrc* pPath = pMonster->pDynamicPath;
    packet67.nUnitLife = nUnitLife;
    packet67.nPathType = PATH_GetType(pPath);
    if (packet67.nPathType >= 5)
    {
        if (packet67.nPathType > 6)
        {
            if (packet67.nPathType == 8)
            {
                packet67.nPathType = 11;
            }
        }
        else
        {
            packet67.nPathType = 1;
            packet67.nX = PATH_GetLastPointX(pPath);
            packet67.nY = PATH_GetLastPointY(pPath);
        }
    }

    int nVelocity = STATLIST_UnitGetStatValue(pMonster, STAT_VELOCITYPERCENT, 0);
    nVelocity = D2_MIN(D2_MAX(nVelocity, -32768), 32767);
    packet67.nVelocity = nVelocity;
    packet67.nMaxDistance = PATH_GetMaxDistance(pPath);
    D2GAME_PACKETS_SendPacket(pClient, &packet67, sizeof(packet67));
}

// 0x0053B7F0
void __fastcall D2GAME_PACKETS_SendPacket0x68Ex(D2ClientStrc* pClient, unsigned char nHeader, int nUnitGUID, char nMessage, char nTargetUnitType, int nTargetUnitGUID, char nUnitLife, char nMaxDistance, char nHitClass)
{
    D2GSPacketSrv68 packet68 = {};

    packet68.nHeader = nHeader;
    packet68.nUnitGUID = nUnitGUID;
    packet68.nMessage = nMessage;
    packet68.nTargetUnitType = nTargetUnitType;
    packet68.nTargetUnitGUID = nTargetUnitGUID;

    D2UnitStrc* pMonster = SUNIT_GetServerUnit(CLIENTS_GetGame(pClient), UNIT_MONSTER, nUnitGUID);
    if (!pMonster)
    {
        return;
    }

    D2DynamicPathStrc* pPath = pMonster->pDynamicPath;
    packet68.nX = CLIENTS_GetUnitXInline(pMonster);
    packet68.nY = CLIENTS_GetUnitYInline(pMonster);
    packet68.nUnitLife = nUnitLife;
    packet68.nHitClass = nHitClass;
    packet68.nPathType = PATH_GetType(pPath);
    if (packet68.nPathType == 8)
    {
        packet68.nPathType = 11;
    }

    int nVelocity = STATLIST_UnitGetStatValue(pMonster, STAT_VELOCITYPERCENT, 0);
    nVelocity = D2_MIN(D2_MAX(nVelocity, -32768), 32767);
    packet68.nVelocity = nVelocity;
    packet68.nMaxDistance = nMaxDistance;
    D2GAME_PACKETS_SendPacket(pClient, &packet68, sizeof(packet68));
}

// 0x0053B910
void __fastcall D2GAME_PACKETS_SendPacket0x67Ex(D2ClientStrc* pClient, unsigned char nHeader, int nUnitGUID, char nMessage, short nX, short nY, char nUnitLife, char nMaxDistance, char nHitClass)
{
    D2GSPacketSrv67 packet67 = {};

    packet67.nHeader = nHeader;
    packet67.nUnitGUID = nUnitGUID;
    packet67.nMessage = nMessage;
    packet67.nX = nX;
    packet67.nY = nY;

    D2UnitStrc* pMonster = SUNIT_GetServerUnit(CLIENTS_GetGame(pClient), UNIT_MONSTER, nUnitGUID);
    if (!pMonster)
    {
        return;
    }

    D2DynamicPathStrc* pPath = pMonster->pDynamicPath;
    packet67.nUnitLife = nUnitLife;
    packet67.nHitClass = nHitClass;
    packet67.nPathType = PATH_GetType(pPath);
    if (packet67.nPathType >= 5)
    {
        if (packet67.nPathType > 6)
        {
            if (packet67.nPathType == 8)
            {
                packet67.nPathType = 11;
            }
        }
        else
        {
            packet67.nPathType = 1;
            packet67.nX = PATH_GetLastPointX(pPath);
            packet67.nY = PATH_GetLastPointY(pPath);
        }
    }

    int nVelocity = STATLIST_UnitGetStatValue(pMonster, STAT_VELOCITYPERCENT, 0);
    nVelocity = D2_MIN(D2_MAX(nVelocity, -32768), 32767);
    packet67.nVelocity = nVelocity;
    packet67.nMaxDistance = nMaxDistance;
    D2GAME_PACKETS_SendPacket(pClient, &packet67, sizeof(packet67));
}

// 0x0053B9F0
void __fastcall D2GAME_PACKETS_SendPacket0x6A(D2ClientStrc* pClient, char nHeader, int nUnitGUID, char nAction, char nTargetType, int nTargetGUID, char nDirection)
{
    D2GSPacketSrv6A packet6A = {};

    packet6A.nHeader = nHeader;
    packet6A.nUnitGUID = nUnitGUID;
    packet6A.nMessage = nAction;
    packet6A.nTargetUnitType = nTargetType;
    packet6A.nTargetUnitGuid = nTargetGUID;
    packet6A.nDirection = nDirection;

    D2GAME_PACKETS_SendPacket(pClient, &packet6A, sizeof(packet6A));
}

// 0x0053BA40
void __fastcall D2GAME_PACKETS_SendPacket0x69(D2ClientStrc* pClient, char nHeader, int nUnitGUID, char nAction, short nX, short nY, char nModeData, char nHitClass)
{
    D2GSPacketSrv69 packet69 = {};

    packet69.nHeader = nHeader;
    packet69.nUnitGUID = nUnitGUID;
    packet69.nMessage = nAction;
    packet69.nX = nX;
    packet69.nY = nY;
    packet69.nUnitLife = nModeData;
    packet69.nHitClass = nHitClass;

    D2GAME_PACKETS_SendPacket(pClient, &packet69, sizeof(packet69));
}

// 0x0053BAA0
void __fastcall D2GAME_PACKETS_SendPacket0x6C(D2ClientStrc* pClient, char nHeader, int nUnitGUID, char nAction, char nTargetType, int nTargetGUID, char nModeData, short nCurrentPosX, short nCurrentPosY)
{
    D2GSPacketSrv6C packet6C = {};

    packet6C.nHeader = nHeader;
    packet6C.nUnitGUID = nUnitGUID;
    packet6C.nMessage = nAction;
    packet6C.nTargetUnitType = nTargetType;
    packet6C.nTargetUnitGUID = nTargetGUID;
    packet6C.nUnitLife = nModeData;
    packet6C.nX = nCurrentPosX;
    packet6C.nY = nCurrentPosY;

    D2GAME_PACKETS_SendPacket(pClient, &packet6C, sizeof(packet6C));
}

// 0x0053BB00
void __fastcall D2GAME_PACKETS_SendPacket0x6B(D2ClientStrc* pClient, char nHeader, int nUnitGUID, char nAction, short nX, short nY, char nModeData, char nHitClass, short nCurrentPosX, short nCurrentPosY)
{
    D2GSPacketSrv6B packet6B = {};

    packet6B.nHeader = nHeader;
    packet6B.nUnitGUID = nUnitGUID;
    packet6B.nMessage = nAction;
    packet6B.nTargetX = nX;
    packet6B.nTargetY = nY;
    packet6B.nUnitLife = nModeData;
    packet6B.nHitClass = nHitClass;
    packet6B.nX = nCurrentPosX;
    packet6B.nY = nCurrentPosY;

    D2GAME_PACKETS_SendPacket(pClient, &packet6B, sizeof(packet6B));
}

// 0x0053BB70
void __fastcall D2GAME_PACKETS_SendPacket0x6D(D2ClientStrc* pClient, unsigned int dwUnitId, unsigned short nX, unsigned short nY, unsigned char nUnitLife)
{
    D2GSPacketSrv6D packet6D = {};

    packet6D.nHeader = 0x6D;
    packet6D.nUnitGUID = dwUnitId;
    packet6D.nX = nX;
    packet6D.nY = nY;
    packet6D.nLife = nUnitLife;

    D2GAME_PACKETS_SendPacket(pClient, &packet6D, sizeof(packet6D));
}

// 0x0053BBC0
void __stdcall sub_0053BBC0_Nop(int nUnused1, int nUnused2)
{
}

// 0x0053BBD0
void __stdcall sub_0053BBD0_Nop(int nUnused1, int nUnused2)
{
}

// 0x0053BBE0
void __stdcall sub_0053BBE0_Nop(int nUnused1, int nUnused2)
{
}

// 0x0053BBF0
void __stdcall sub_0053BBF0_Nop(int nUnused1, int nUnused2)
{
}

// 0x0053BC00
void __stdcall sub_0053BC00_Nop(int nUnused1, int nUnused2)
{
}

// 0x0053BC10
void __fastcall D2GAME_PACKETS_SendPacket0x15(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, unsigned short nPosX, unsigned short nPosY, unsigned char bReassign)
{
    D2GSPacketSrv15 packet15;

    packet15.nHeader = nHeader;
    packet15.nUnitType = nUnitType;
    packet15.dwUnitGUID = nUnitGUID;
    packet15.nPosX = nPosX;
    packet15.nPosY = nPosY;
    packet15.bReassign = bReassign;

    D2GAME_PACKETS_SendPacket(pClient, &packet15, sizeof(packet15));
}

// 0x0053BC50
void __fastcall D2GAME_PACKETS_SendPacket0x07(D2ClientStrc* pClient, unsigned char nAreaId, unsigned short nTileX, unsigned short nTileY)
{
    D2GSPacketSrv07 packet07;

    packet07.nHeader = 0x07;
    packet07.nX = nTileX;
    packet07.nY = nTileY;
    packet07.nLevelId = nAreaId;

    D2GAME_PACKETS_SendPacket(pClient, &packet07, sizeof(packet07));
}

// 0x0053BC90
void __fastcall D2GAME_PACKETS_SendPacket0x08(D2ClientStrc* pClient, unsigned char nAreaId, unsigned short nTileX, unsigned short nTileY)
{
    D2GSPacketSrv08 packet08;
    packet08.nHeader = 8;
    packet08.nX = nTileX;
    packet08.nY = nTileY;
    packet08.nLevelId = nAreaId;
    D2GAME_PACKETS_SendPacket(pClient, &packet08, sizeof(packet08));
}

// 0x0053BCD0
void __fastcall D2GAME_PACKETS_SendPacket0x09(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, unsigned int nUnitGUID, unsigned char nClassId, unsigned short nPosX, unsigned short nPosY)
{
    D2GSPacketSrv09 packet09;
    packet09.nHeader = nHeader;
    packet09.nUnitType = nUnitType;
    packet09.dwUnitGUID = nUnitGUID;
    packet09.nClassId = nClassId;
    packet09.nPosX = nPosX;
    packet09.nPosY = nPosY;
    D2GAME_PACKETS_SendPacket(pClient, &packet09, sizeof(packet09));
}

// 0x0053BD10
void __fastcall D2GAME_PACKETS_SendPacket0x51(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, unsigned short nObjectId, unsigned short nX, unsigned short nY, unsigned char nAnimMode, unsigned char nInteractType)
{
    D2_ASSERT(SUNIT_GetServerUnit(CLIENTS_GetGame(pClient), nUnitType, nUnitGUID), 0x341);

    D2GSPacketSrv51 packet51;
    packet51.nHeader = nHeader;
    packet51.nUnitType = nUnitType;
    packet51.dwUnitGUID = nUnitGUID;
    packet51.nObject = nObjectId;
    packet51.nPosX = nX;
    packet51.nPosY = nY;
    packet51.nObjectParam = nAnimMode;
    packet51.nInteractType = nInteractType;
    D2GAME_PACKETS_SendPacket(pClient, &packet51, sizeof(packet51));
}

// 0x0053BDA0
void __fastcall D2GAME_PACKETS_SendPacket0x0A_RemoveObject(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID)
{
    if (nUnitType == 3)
    {
        return;
    }

    D2PacketSize06Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.nUnitType = nUnitType;
    tPacket.nUnitGUID = nUnitGUID;
    D2GAME_PACKETS_SendPacket(pClient, &tPacket, sizeof(tPacket));
}

// 0x0053BDD0
void __fastcall D2GAME_PACKETS_SendPacket0x1A_B_C(D2ClientStrc* pClient, int nExperience, int nPreviousExperience)
{
    const int nDiff = nExperience - nPreviousExperience;

    if (nDiff >= 0 && nDiff < 0xFFFF)
    {
        if (nDiff < 0xFF)
        {
            D2GSPacketSrv1A packet1A;
            packet1A.nHeader = 0x1A;
            packet1A.nExperience = nDiff;
            D2GAME_PACKETS_SendPacket(pClient, &packet1A, sizeof(packet1A));
        }
        else
        {
            D2GSPacketSrv1B packet1B;
            packet1B.nHeader = 0x1B;
            packet1B.nExperience = nDiff;
            D2GAME_PACKETS_SendPacket(pClient, &packet1B, sizeof(packet1B));
        }
    }
    else
    {
        D2GSPacketSrv1C packet1C;
        packet1C.nHeader = 0x1C;
        packet1C.nExperience = nExperience;
        D2GAME_PACKETS_SendPacket(pClient, &packet1C, sizeof(packet1C));
    }
}

// 0x0053BE40
void __fastcall D2GAME_PACKETS_SendPacket0x1D_E_F(D2ClientStrc* pClient, unsigned short wStat, unsigned int nValue)
{
    D2_ASSERT(wStat < 0xFF, 971);

    if (nValue < 0xFF)
    {
        D2GSPacketSrv1D packet1D;
        packet1D.nHeader = 0x1D;
        packet1D.nStat = (unsigned char)wStat;
        packet1D.nValue = nValue;
        D2GAME_PACKETS_SendPacket(pClient, &packet1D, sizeof(packet1D));
    }
    else if (nValue < 0xFFFF)
    {
        D2GSPacketSrv1E packet1E;
        packet1E.nHeader = 0x1E;
        packet1E.nStat = (unsigned char)wStat;
        packet1E.nValue = nValue;
        D2GAME_PACKETS_SendPacket(pClient, &packet1E, sizeof(packet1E));
    }
    else
    {
        D2GSPacketSrv1F packet1F;
        packet1F.nHeader = 0x1F;
        packet1F.nStat = (unsigned char)wStat;
        packet1F.nValue = nValue;
        D2GAME_PACKETS_SendPacket(pClient, &packet1F, sizeof(packet1F));
    }
}

// 0x0053BEE0
void __fastcall D2GAME_PACKETS_SendPacket0x9E_9F_A0(D2ClientStrc* pClient, D2UnitStrc* pUnit, unsigned short wStat, unsigned int nValue)
{
    D2_ASSERT(wStat < 0xFF, 1013);

    const int bFitsWord = nValue < 0xFFFF;
    if (nValue < 0xFF)
    {
        D2GSPacketSrv9E packet9E;
        packet9E.nHeader = 0x9E;
        packet9E.nStat = (unsigned char)wStat;
        packet9E.dwGUID = SCMD_GetUnitGUID(pUnit);
        packet9E.nValue = nValue;
        D2GAME_PACKETS_SendPacket(pClient, &packet9E, sizeof(packet9E));
    }
    else if (bFitsWord)
    {
        D2GSPacketSrv9F packet9F;
        packet9F.nHeader = 0x9F;
        packet9F.nStat = (unsigned char)wStat;
        packet9F.dwGUID = SCMD_GetUnitGUID(pUnit);
        packet9F.nValue = nValue;
        D2GAME_PACKETS_SendPacket(pClient, &packet9F, sizeof(packet9F));
    }
    else
    {
        D2GSPacketSrvA0 packetA0;
        packetA0.nHeader = 0xA0;
        packetA0.nStat = (unsigned char)wStat;
        packetA0.dwGUID = SCMD_GetUnitGUID(pUnit);
        packetA0.nValue = nValue;
        D2GAME_PACKETS_SendPacket(pClient, &packetA0, sizeof(packetA0));
    }
}

// 0x0053BFD0
void __fastcall D2GAME_PACKETS_SendPacket0xA0_A1_A2(D2ClientStrc* client,D2UnitStrc* unit,unsigned short stat,unsigned int base,unsigned int full) {
 if(stat>=0xFF) {FOG_DisplayHalt(text_006CC837,sub_00408090(),1069);sub_00681E09(-1);}
 full-=base;
 const int fitsWord=full<0xFFFF;
 if(full<0xFF) {
  PacketA1 packet;packet.header=0xA1;packet.stat=(unsigned char)stat;
  packet.guid=SCMD_GetUnitGUID(unit);packet.value=full;
  D2GAME_PACKETS_SendPacket(client, &packet, sizeof(packet));
 } else if(fitsWord) {
  PacketA2 packet;packet.header=0xA2;packet.stat=(unsigned char)stat;
  packet.guid=SCMD_GetUnitGUID(unit);packet.value=full;
  D2GAME_PACKETS_SendPacket(client, &packet, sizeof(packet));
 } else {
  PacketA0 packet;packet.header=0xA0;packet.stat=(unsigned char)stat;
  packet.guid=SCMD_GetUnitGUID(unit);packet.value=base;
  D2GAME_PACKETS_SendPacket(client, &packet, sizeof(packet));
 }
}

// 0x0053C0E0
void __fastcall D2GAME_PACKETS_SendPacket0xA3(D2ClientStrc* pClient, unsigned char nSeed, unsigned short nSkillId, unsigned short nSkillLevel, int nUnitType, int nUnitGUID, int nTargetType, int nTargetGUID, int nX, int nY)
{
    D2GSPacketSrvA3 packetA3 = {};

    packetA3.nHeader = 0xA3;
    packetA3.nSeed = nSeed;
    packetA3.nSkillId = nSkillId;
    packetA3.nSkillLevel = nSkillLevel;
    packetA3.nUnitType = nUnitType;
    packetA3.nUnitGUID = nUnitGUID;
    packetA3.nTargetType = nTargetType;
    packetA3.nTargetGUID = nTargetGUID;
    packetA3.nX = nX;
    packetA3.nY = nY;

    D2GAME_PACKETS_SendPacket(pClient, &packetA3, sizeof(packetA3));
}

// 0x0053C150
void __fastcall D2GAME_PACKETS_SendPacket0xAB(D2ClientStrc* pClient, unsigned char nUnitType, int dwUnitId, unsigned char nUnitLife)
{
    D2GSPacketSrvAB packetAB = {};

    packetAB.nHeader = 0xAB;
    packetAB.nUnitType = nUnitType;
    packetAB.dwUnitGUID = dwUnitId;
    packetAB.nLife = nUnitLife;

    D2GAME_PACKETS_SendPacket(pClient, &packetAB, sizeof(packetAB));
}

// 0x0053C190
void __fastcall D2GAME_PACKETS_SendPacket0xA5(D2ClientStrc* pClient, unsigned char nUnitType, int nUnitGUID, unsigned short nSkillId)
{
    D2GSPacketSrvA5 packetA5 = {};

    packetA5.nHeader = 0xA5;
    packetA5.nUnitType = nUnitType;
    packetA5.nUnitGUID = nUnitGUID;
    packetA5.nSkillId = nSkillId;

    D2GAME_PACKETS_SendPacket(pClient, &packetA5, sizeof(packetA5));
}

// 0x0053C1D0
void __fastcall SCMD_SendUnitStat(D2ClientStrc* pClient, unsigned char nHeader, int nUnitGUID, unsigned short wStat, int nValue)
{
    D2_ASSERT(wStat < 0xFF, 0x4B8);
    D2GSPacketSrv20Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.dwUnitGUID = nUnitGUID;
    tPacket.nStat = wStat;
    tPacket.nValue = nValue;
    D2GAME_PACKETS_SendPacket(pClient, &tPacket, sizeof(tPacket));
}

// 0x0053C230
void __fastcall SCMD_SendVitalsAndPotionPrediction(D2ClientStrc* pClient, unsigned short nHitpoints, unsigned short nMana, unsigned short nStamina, unsigned char nPotionLifePercent, unsigned char nPotionManaPercent, unsigned short nPosX, unsigned short nPosY, unsigned char nTargetOffsetX, unsigned char nTargetOffsetY)
{
    unsigned char packet[15];
    D2BitBufferStrc bitBuffer;

    BITMANIP_Initialize(&bitBuffer, packet, sizeof(packet));
    BITMANIP_Write(&bitBuffer, 0x18, 8);
    BITMANIP_Write(&bitBuffer, nHitpoints, 15);
    BITMANIP_Write(&bitBuffer, nMana, 15);
    BITMANIP_Write(&bitBuffer, nStamina, 15);
    BITMANIP_Write(&bitBuffer, nPotionLifePercent, 7);
    BITMANIP_Write(&bitBuffer, nPotionManaPercent, 7);
    BITMANIP_Write(&bitBuffer, nPosX, 16);
    BITMANIP_Write(&bitBuffer, nPosY, 16);
    BITMANIP_Write(&bitBuffer, nTargetOffsetX, 8);
    BITMANIP_Write(&bitBuffer, nTargetOffsetY, 8);

    D2GAME_PACKETS_SendPacket(pClient, packet, BITMANIP_GetSize(&bitBuffer));
}

// 0x0053C320
void __fastcall SCMD_SendVitals(D2ClientStrc* pClient, unsigned short nHitpoints, unsigned short nMana, unsigned short nStamina, unsigned short nPosX, unsigned short nPosY, unsigned char nTargetOffsetX, unsigned char nTargetOffsetY)
{
    unsigned char packet[13];
    D2BitBufferStrc bitBuffer;

    BITMANIP_Initialize(&bitBuffer, packet, sizeof(packet));
    BITMANIP_Write(&bitBuffer, 0x95, 8);
    BITMANIP_Write(&bitBuffer, nHitpoints, 15);
    BITMANIP_Write(&bitBuffer, nMana, 15);
    BITMANIP_Write(&bitBuffer, nStamina, 15);
    BITMANIP_Write(&bitBuffer, nPosX, 16);
    BITMANIP_Write(&bitBuffer, nPosY, 16);
    BITMANIP_Write(&bitBuffer, nTargetOffsetX, 8);
    BITMANIP_Write(&bitBuffer, nTargetOffsetY, 8);

    D2GAME_PACKETS_SendPacket(pClient, packet, BITMANIP_GetSize(&bitBuffer));
}

// 0x0053C3F0
void __fastcall D2GAME_PACKETS_SendPacket0x96_WalkVerify(D2ClientStrc* pClient, unsigned short nStamina, unsigned short nPosX, unsigned short nPosY, unsigned char nTargetOffsetX, unsigned char nTargetOffsetY)
{
    unsigned char packet[9];
    D2BitBufferStrc bitBuffer;

    BITMANIP_Initialize(&bitBuffer, packet, sizeof(packet));
    BITMANIP_Write(&bitBuffer, 0x96, 8);
    BITMANIP_Write(&bitBuffer, nStamina, 15);
    BITMANIP_Write(&bitBuffer, nPosX, 16);
    BITMANIP_Write(&bitBuffer, nPosY, 16);
    BITMANIP_Write(&bitBuffer, nTargetOffsetX, 8);
    BITMANIP_Write(&bitBuffer, nTargetOffsetY, 8);

    D2GAME_PACKETS_SendPacket(pClient, packet, BITMANIP_GetSize(&bitBuffer));
}

static inline int sub_GetUnitType(D2UnitStrc* pUnit)
{
    int nUnitType = 6;
    if (pUnit)
    {
        nUnitType = pUnit->dwUnitType;
    }
    return nUnitType;
}

// 0x0053C4A0
void __fastcall D2GAME_PACKETS_SendPacket0x21_UpdateSkills(D2ClientStrc* pClient, D2UnitStrc* pUnit, unsigned short nSkillId, unsigned char nSkillLevel, unsigned char bRemove)
{
    if (!pUnit)
    {
        return;
    }

    if (!pClient && pUnit->dwUnitType == UNIT_MONSTER)
    {
        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
        if (!pOwner)
        {
            return;
        }

        pClient = UnitGetClient(pOwner, ".\\GAME\\SCmd.cpp", 1298);
    }

    if (pClient)
    {
        D2GSPacketSrv21 packet21;
        packet21.nHeader = 0x21;
        packet21.nUnitType = sub_GetUnitType(pUnit);
        packet21.bRemove = bRemove;
        packet21.nUnitGUID = pUnit->dwUnitId;
        packet21.nSkillId = nSkillId;
        packet21.nSkillLevel = nSkillLevel;
        packet21.nBonusSkillLevel = (unsigned char)SKILLS_GetBonusSkillLevelFromSkillId(pUnit, nSkillId);
        D2GAME_PACKETS_SendPacket(pClient, &packet21, sizeof(packet21));
    }
}

// 0x0053C520
void __fastcall D2GAME_PACKETS_SendPacket0x22(D2ClientStrc* pClient, unsigned char nUnitType, int nUnitGUID, int nSkillId, int nQuantity)
{
    D2GSPacketSrv22 packet22;

    packet22.nHeader = 0x22;
    packet22.nUnitType = nUnitType;
    packet22.nUnitGUID = nUnitGUID;
    packet22.nSkillId = nSkillId;
    packet22.nQuantity = nQuantity;

    D2UnitStrc* pUnit = SUNIT_GetServerUnit(CLIENTS_GetGame(pClient), nUnitType, nUnitGUID);
    packet22.bIsCorpse = pUnit && STATES_CheckState(pUnit, STATE_PLAYERBODY);

    D2GAME_PACKETS_SendPacket(pClient, &packet22, sizeof(packet22));
}

// 0x0053C590
void __fastcall D2GAME_PACKETS_SendPacket0x23(D2ClientStrc* pClient, unsigned char nUnitType, int nUnitGUID, unsigned char bLeftSkill, unsigned short nSkillId, int nSkillOwnerGUID)
{
    D2GSPacketSrv23Strc tPacket;
    tPacket.nPosition = bLeftSkill;
    tPacket.nUnitType = nUnitType;
    tPacket.nUnitGUID = nUnitGUID;
    tPacket.nSkill = nSkillId;
    tPacket.nHeader = 0x23;
    tPacket.nOwnerGUID = nSkillOwnerGUID;
    D2GAME_PACKETS_SendPacket(pClient, &tPacket, sizeof(tPacket));
}

// 0x0053C5D0
void __fastcall SCMD_SendSkillList(D2ClientStrc* pClient, D2UnitStrc* hUnit)
{
    D2_ASSERT(hUnit, 0x55A);
    D2SkillListStrc* hSkillInfo = hUnit->pSkills;
    D2_ASSERT(hSkillInfo, 0x55D);
    D2SkillStrc* pSkill = SKILLS_GetFirstSkillFromSkillList(hSkillInfo);
    int nCount = 0;
    while (pSkill)
    {
        pSkill = SKILLS_GetNextSkill(pSkill);
        ++nCount;
    }
    D2GameStrc* pGame = CLIENTS_GetGame(pClient);
    int nSize = 6 + 3 * nCount;
    D2GSPacketSrv94* pPacket = (D2GSPacketSrv94*)FOG_AllocPool(pGame->pMemoryPool, nSize, ".\\GAME\\SCmd.cpp", 0x568, 0);
    D2SkillPacketEntryStrc* pEntry = (D2SkillPacketEntryStrc*)(pPacket + 1);
    pPacket->nHeader = 0x94;
    D2_ASSERT(nCount < 256, 0x56E);
    pPacket->nCount = nCount;
    pPacket->nGUID = !hUnit ? -1 : hUnit->dwUnitId;
    for (pSkill = SKILLS_GetFirstSkillFromSkillList(hSkillInfo); pSkill;)
    {
        pEntry->nLevel = SKILLS_GetSkillLevel(hUnit, pSkill, 0);
        pEntry->nSkill = SKILLS_GetSkillIdFromSkill(pSkill, ".\\GAME\\SCmd.cpp", 0x576);
        pSkill = SKILLS_GetNextSkill(pSkill);
        ++pEntry;
    }
    D2GAME_PACKETS_SendPacket(pClient, pPacket, nSize);
    FOG_FreePool(pGame->pMemoryPool, pPacket, ".\\GAME\\SCmd.cpp", 0x57E, 0);
}

// 0x0053C6F0
void __fastcall SCMD_SendSkillTabBonus(D2ClientStrc* pClient, int nUnitGUID, unsigned char nBonus, unsigned char nCharClass, int bSkillTab, unsigned char nSkillTab)
{
    D2GSPacketSrv93Strc tPacket;
    tPacket.nHeader = 0x93;
    tPacket.dwUnitGUID = nUnitGUID;
    tPacket.nBonus = nBonus;
    tPacket.nCharClass = nCharClass;
    if (bSkillTab)
    {
        tPacket.nSkillTab = nSkillTab;
    }
    else
    {
        tPacket.nSkillTab = 4;
    }
    D2GAME_PACKETS_SendPacket(pClient, &tPacket, sizeof(tPacket));
}

// 0x0053C730
extern "C" void __stdcall sub_0053C730_Nop(unsigned arg0,unsigned arg1,unsigned arg2) {}

// 0x0053C740
void __stdcall sub_0053C740_Nop(int nUnused1)
{
}

// 0x0053C750
void __fastcall D2GAME_PACKETS_SendPacket0x26_ServerMessage(D2ClientStrc* pClient, D2GSPacketSrv26* pPacket)
{
    int nMessageLength = 0;
    if (strlen(pPacket->szMessage) >= 256)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x5BA);
        exit(-1);
    }
    if (pPacket->szMessage[255])
        pPacket->szMessage[255] = 0;
    D2GSPacketSrv26 packet;
    packet.nHeader = pPacket->nHeader;
    packet.nMessageType = pPacket->nMessageType;
    packet.nLang = pPacket->nLang;
    packet.nUnitType = pPacket->nUnitType;
    packet.dwUnitGUID = pPacket->dwUnitGUID;
    packet.nMessageColor = pPacket->nMessageColor;
    packet.nNameColor = pPacket->nNameColor;
    char* pText = packet.szName + SStrCopy(packet.szName, pPacket->szName, 16) + 1;
    nMessageLength = SStrCopy(pText, pPacket->szMessage, 256);
    nMessageLength += pText - (char*)&packet + 1;
    D2GAME_PACKETS_SendPacket(pClient, &packet, nMessageLength);
}

// 0x0053C850
void __fastcall D2GAME_PACKETS_SendPacket0x5A(D2ClientStrc* pClient, D2GSPacketSrv5A* pPacket)
{
    D2_ASSERT(strlen(pPacket->szText) < 16, 1498);

    D2GSPacketSrv5A packet5A = *pPacket;
    D2GAME_PACKETS_SendPacket(pClient, &packet5A, sizeof(packet5A));
}

// 0x0053C8D0
void __fastcall D2GAME_PACKETS_SendPacket0x27(D2ClientStrc* pClient, D2GSPacketSrv27* pPacket)
{
    D2GSPacketSrv27 packet27 = *pPacket;
    D2GAME_PACKETS_SendPacket(pClient, &packet27, sizeof(packet27));
}

// 0x0053C900
void __fastcall D2GAME_SendPacket0x53(D2ClientStrc* pClient, D2GSPacketSrv53* pPacket)
{
    D2GSPacketSrv53 packet53 = *pPacket;
    D2GAME_PACKETS_SendPacket(pClient, &packet53, sizeof(packet53));
}

// 0x0053C930
void __fastcall D2GAME_PACKETS_SendPacketSize03(D2ClientStrc* pClient, const void* pPacket)
{
    D2GAME_PACKETS_SendPacket(pClient, pPacket, 3);
}

// 0x0053C940
void __fastcall SCMD_SendPlayerJoinAndPets(D2ClientStrc* pClient1, D2UnitStrc* pPlayer, D2ClientStrc* pClient2)
{
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    D2GSPacketSrv5B packet5B;
    memset(&packet5B, 0, sizeof(packet5B));

    packet5B.nHeader = 0x5B;
    packet5B.nUnitGUID = SCMD_GetUnitGUID(pPlayer);
    const int nClass = !pPlayer ? -1 : pPlayer->dwClassId;
    packet5B.nClass = nClass;
    packet5B.nLevel = STATLIST_UnitGetStatValue(pPlayer, STAT_LEVEL, 0);
    packet5B.nPartyId = SUNIT_GetPartyId(pPlayer);
    packet5B.unused0x1C = 0;
    packet5B.nPartyFlags = 0;
    packet5B.nGuildFlags = CLIENTS_GetGuildFlags(pClient2);

    SStrCopy(packet5B.szName, pPlayerData->szName, 0x7FFFFFFF);

    CLIENTS_GetGuildTag(pClient2, (unsigned int*)packet5B.szGuildTag);

    const int nLength = strlen(packet5B.szGuildTag) + 1;

    char* szString = &packet5B.szGuildTag[nLength];
    CLIENTS_GetGuildName(pClient2, szString);

    const int nPacketLen = strlen(szString) + 1 + (szString - packet5B.szGuildTag) + offsetof(D2GSPacketSrv5B, szGuildTag);
    packet5B.nPacketLen = nPacketLen;
    D2GAME_PACKETS_SendPacket(pClient1, &packet5B, nPacketLen);

    if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
    {
        PLAYERPETS_SendPetsToClient(pClient1, pPlayer);
    }
}

// 0x0053CA90
void __fastcall D2GAME_PACKETS_SendPacket0x5C(D2ClientStrc* pClient, int nUnitGUID)
{
    D2GSPacketSrv5C packet5C;
    packet5C.nHeader = 0x5C;
    packet5C.dwPlayerGUID = nUnitGUID;
    D2GAME_PACKETS_SendPacket(pClient, &packet5C, sizeof(packet5C));
}

// 0x0053CAB0
void __fastcall D2GAME_PACKETS_SendPacket0x77_Ui(D2ClientStrc* pClient, unsigned char nUiNo)
{
    D2GSPacketSrv77 packet77;
    packet77.nHeader = 0x77;
    packet77.nAction = nUiNo;
    D2GAME_PACKETS_SendPacket(pClient, &packet77, sizeof(packet77));
}

// 0x0053CAD0
void __fastcall D2GAME_PACKETS_SendPacket0x63_WaypointMenu(D2ClientStrc* pClient, D2GSPacketSrv78* pPacket)
{
    D2GSPacketSrv78 packet78 = *pPacket;
    D2GAME_PACKETS_SendPacket(pClient, &packet78, sizeof(packet78));
}

// 0x0053CB30
void __fastcall D2GAME_PACKETS_SendPacket0x7A(D2ClientStrc* pClient, char bAdd, int nPetType, int nPetGUID, int nUnitGUID, unsigned short nPetClass)
{
    D2GSPacketSrv7A packet7A = {};

    packet7A.nHeader = 0x7A;
    packet7A.bAdd = bAdd;
    packet7A.nPetType = nPetType;
    packet7A.nPetClass = nPetClass;
    packet7A.nPetGUID = nPetGUID;
    packet7A.nUnitGUID = nUnitGUID;

    D2GAME_PACKETS_SendPacket(pClient, &packet7A, sizeof(packet7A));
}

// 0x0053CB80
void __fastcall D2GAME_PACKETS_SendPacket0x81(D2ClientStrc* pClient, char nUnused, int nPetType, int nPetGUID, int nUnitGUID, unsigned short nPetClass, int nSeed, int nName)
{
    D2GSPacketSrv81 packet81 = {};

    packet81.nHeader = 0x81;
    packet81.nPetType = nPetType;
    packet81.nPetGUID = nPetGUID;
    packet81.nUnitGUID = nUnitGUID;
    packet81.nPetClass = nPetClass;
    packet81.nSeed = nSeed;
    packet81.nName = nName;

    D2GAME_PACKETS_SendPacket(pClient, &packet81, sizeof(packet81));
}

// 0x0053CBE0
void __fastcall D2GAME_PACKETS_SendPacket0x79(D2ClientStrc* pClient, int nGold, char bOwnGold)
{
    D2GSPacketSrv79 packet79;
    packet79.nHeader = 0x79;
    packet79.bOwnGold = bOwnGold;
    packet79.dwGold = nGold;
    D2GAME_PACKETS_SendPacket(pClient, &packet79, sizeof(packet79));
}

// 0x0053CC10
static int SCMD_ShouldSendLifeUpdate(int nLifePercentage, D2LifeSyncStrc* pLifeSync)
{
    int nDiff = nLifePercentage - pLifeSync->nLifePercentage;
    if (nDiff)
    {
        if (nDiff < 0)
        {
            nDiff = -nDiff;
        }
        if (nDiff > 8)
        {
            pLifeSync->nUpdateCount = 0;
            pLifeSync->nLifePercentage = nLifePercentage;
            return 1;
        }
        if (++pLifeSync->nUpdateCount > 6)
        {
            pLifeSync->nUpdateCount = 0;
            pLifeSync->nLifePercentage = nLifePercentage;
            return 1;
        }
    }
    return 0;
}

// 0x0053CC40
static int __stdcall SCMD_ShouldSendMinionLifeUpdate(D2UnitStrc* pUnit, D2UnitStrc* pPlayer, int nLifePercentage)
{
    if (AIGENERAL_GetMinionOwner(pUnit) != pPlayer)
    {
        return 0;
    }
    const int bTest = !pUnit || pUnit->dwUnitType != UNIT_MONSTER;
    if (!bTest)
    {
        pUnit = (D2UnitStrc*)pUnit->pMonsterData;
    }
    if (bTest)
    {
        return 0;
    }
    D2LifeSyncStrc* pLifeSync = pUnit ? (D2LifeSyncStrc*)((D2MonsterDataStrc*)pUnit)->abLifeSync : 0;
    if (!pLifeSync)
    {
        return 0;
    }
    if (pLifeSync->nLifePercentage == nLifePercentage)
    {
        return 0;
    }
    return SCMD_ShouldSendLifeUpdate(nLifePercentage, pLifeSync);
}

// 0x0053CC90
static int __stdcall SCMD_ShouldSendPartyLifeUpdate(D2UnitStrc* pUnit, int nLifePercentage, int nLevelId, D2UnitStrc* pPlayer)
{
    D2GameStrc* pGame = SUNIT_GetGameFromUnit(pPlayer);
    if (!pGame)
    {
        return 0;
    }
    const unsigned short nPartyId = PARTY_GetPartyIdForUnitOwner(pGame, pPlayer);
    if (nPartyId == 0xFFFF || nPartyId != PARTY_GetPartyIdForUnitOwner(pGame, pUnit))
    {
        return 0;
    }
    D2PlayerDataStrc* pPlayerData = UNITS_GetPlayerData(pPlayer);
    if (!pPlayerData)
    {
        return 0;
    }
    D2LifeSyncStrc* pLifeSync = pPlayerData->pPartyLifeList;
    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    int bFound = 0;
    while (!bFound)
    {
        if (!pLifeSync)
        {
            pLifeSync = (D2LifeSyncStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2LifeSyncStrc), ".\\GAME\\SCmd.cpp", 0x6FA, 0);
            if (!pLifeSync)
            {
                return 0;
            }
            *pLifeSync = D2LifeSyncStrc();
            pLifeSync->pNext = pPlayerData->pPartyLifeList;
            pPlayerData->pPartyLifeList = pLifeSync;
            pLifeSync->nUnitGUID = nUnitGUID;
            bFound = 1;
        }
        else if (nUnitGUID == pLifeSync->nUnitGUID)
        {
            bFound = 1;
        }
        else
        {
            pLifeSync = pLifeSync->pNext;
        }
    }

    if (pLifeSync->nLevelId != nLevelId)
    {
        pLifeSync->nLifePercentage = nLifePercentage;
        pLifeSync->nLevelId = nLevelId;
        return 1;
    }
    return SCMD_ShouldSendLifeUpdate(nLifePercentage, pLifeSync);
}

// 0x0053CD80
static int __stdcall SCMD_ShouldSendUnitLifeUpdate(D2UnitStrc* pPlayer, D2UnitStrc* pUnit, int nLifePercentage, int nLevelId)
{
    D2_ASSERT(pPlayer, 0x712);
    D2_ASSERT(pUnit, 0x713);

    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        return SCMD_ShouldSendPartyLifeUpdate(pUnit, nLifePercentage, nLevelId, pPlayer);

    case UNIT_MONSTER:
        return SCMD_ShouldSendMinionLifeUpdate(pUnit, pPlayer, nLifePercentage);

    default:
        return 0;
    }
}

// 0x0053CDF0
void __fastcall SCMD_SendUnitLifeAndPositionUpdate(D2ClientStrc* pClient, D2UnitStrc* hUnit)
{
    D2_ASSERT(hUnit, 0x72A);

    const int nLifePercentage = UNITS_GetCurrentLifePercentage(hUnit);
    D2GSPacketSrv7F90 tPacket;
    const D2GSPacketSrv7F tZero7F = {};
    tPacket.packet7F = tZero7F;
    tPacket.packet7F.nHeader = 0x7F;

    if (hUnit->dwUnitType == UNIT_PLAYER)
    {
        tPacket.packet7F.bIsPlayer = 1;
    }

    tPacket.packet7F.nUnitGUID = hUnit->dwUnitId;
    tPacket.packet7F.nLifePercentage = nLifePercentage;
    if (nLifePercentage >= 0xFFFF)
    {
        tPacket.packet7F.nLifePercentage = 0xFFFF;
    }

    tPacket.packet7F.nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(hUnit));

    if (SCMD_ShouldSendUnitLifeUpdate(CLIENTS_GetPlayerFromClient(pClient, 0), hUnit, nLifePercentage, tPacket.packet7F.nLevelId))
    {
        D2GAME_PACKETS_SendPacket(pClient, &tPacket.packet7F, sizeof(tPacket.packet7F));
    }

    if (tPacket.packet7F.bIsPlayer)
    {
        D2UnitStrc* pClientPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
        if (DRLG_UnitEdgeDistance(pClientPlayer, hUnit) > 50)
        {
            const D2GSPacketSrv90 tZero90 = {};
            tPacket.packet90 = tZero90;
            tPacket.packet90.nHeader = 0x90;
            tPacket.packet90.dwGUID = hUnit->dwUnitId;
            tPacket.packet90.dwPosX = CLIENTS_GetUnitX(hUnit);
            tPacket.packet90.dwPosY = CLIENTS_GetUnitY(hUnit);
            D2GAME_PACKETS_SendPacket(pClient, &tPacket.packet90, sizeof(tPacket.packet90));

        }
    }
}

// 0x0053EC00
void __fastcall D2GAME_SendP0x9C_ItemAction_AddToGround(D2ClientStrc* pClient, D2UnitStrc* pItem, unsigned int dwFlag)
{
    D2GAME_SendPacket0x9C(pClient, pItem, ITEMACTION_ADDTOGROUND, dwFlag, 0);
}

// 0x0053EC20
void __fastcall D2GAME_SendP0x9C_ItemAction_GroundToCursor(D2ClientStrc* hClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2_ASSERT(UnitGetClient(pPlayer, ".\\GAME\\SCmd.cpp", 2002) == hClient, 2002);

    UNITS_SetXForStaticUnit(pItem, 0);
    UNITS_SetYForStaticUnit(pItem, 0);
    D2GAME_SendPacket0x9C(hClient, pItem, ITEMACTION_GROUNDTOCURSOR, dwFlags, 0);
}

// 0x0053EC90
void __fastcall D2GAME_SendP0x9C_ItemAction_DropToGround(D2ClientStrc* hClient, D2UnitStrc* hUnit, D2UnitStrc* pItem, int dwFlags)
{
    D2_ASSERT(UnitGetClient(hUnit, ".\\GAME\\SCmd.cpp", 2013) == hClient, 2013);
    D2GAME_SendPacket0x9C(hClient, pItem, ITEMACTION_DROPTOGROUND, dwFlags, 0);
}

// 0x0053ECF0
void __fastcall D2GAME_SendP0x9C_ItemAction_OnGround(D2ClientStrc* pClient, D2UnitStrc* hUnit, D2UnitStrc* pItem, int dwFlags)
{
    D2_ASSERT(UnitGetClient(hUnit, ".\\GAME\\SCmd.cpp", 2022) == pClient, 2022);
    D2GAME_SendPacket0x9C(pClient, pItem, ITEMACTION_ONGROUND, dwFlags, 0);
}

// 0x0053ED50
void __fastcall D2GAME_SendP0x9C_ItemAction_PutInContainer(D2ClientStrc* hClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2_ASSERT(UnitGetClient(pPlayer, ".\\GAME\\SCmd.cpp", 2031) == hClient, 2031);

    D2GAME_SendPacket0x9C(hClient, pItem, ITEMACTION_PUTINCONTAINER, dwFlags, 0);
}

// 0x0053D010
void __fastcall D2GAME_UpdateClientItem(D2ClientStrc* hClient, D2UnitStrc* hUnit, D2UnitStrc* pItem, unsigned int dwCmdFlag)
{
    D2_ASSERT(UnitGetClient(hUnit, ".\\GAME\\SCmd.cpp", 2050) == hClient, 2050);

    const unsigned char nPage = ITEMS_GetInvPage(pItem);
    ITEMS_SetInvPage(pItem, ITEMS_GetItemCell(pItem));
    D2GAME_SendPacket0x9D(hClient, hUnit, pItem, ITEMACTION_REMOVEFROMCONTAINER, dwCmdFlag, 0);
    ITEMS_SetInvPage(pItem, nPage);
}

// 0x0053D090
void __fastcall D2GAME_SendP0x9D_ItemAction_Equip(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D(pClient, pUnit, pItem, ITEMACTION_EQUIP, dwFlags, 0);
}

static D2LifeSyncStrc* GetMonsterLifeSync(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return (D2LifeSyncStrc*)pUnit->pMonsterData->abLifeSync;
    }
    return 0;
}


// 0x0053E8F0
void __fastcall SCMD_SendPlayerSpawnAndPartyRoster(D2ClientStrc* pClient, int nUnitGUID, unsigned char nClassId, const char* szName, short nX, short nY)
{
    D2GSPacketSrv59 packet59 = {};

    packet59.nHeader = 0x59;
    packet59.dwGUID = nUnitGUID;
    packet59.nClass = nClassId;
    memset(packet59.szName, 0, sizeof(packet59.szName));
    SStrCopy(packet59.szName, szName, 0x7FFFFFFF);
    packet59.nPosX = nX;
    packet59.nPosY = nY;
    D2GAME_PACKETS_SendPacket(pClient, &packet59, sizeof(packet59));

    D2UnitStrc* pLocalPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    D2UnitStrc* pOtherPlayer = SUNIT_GetServerUnit(CLIENTS_GetGame(pClient), UNIT_PLAYER, nUnitGUID);
    if (pOtherPlayer)
    {
        SCMD_Send0x75_PartyRosterUpdate(pLocalPlayer, pOtherPlayer);
    }
}

// 0x0053EAE0
void __fastcall D2GAME_SendPacket0x9C(D2ClientStrc* pClient, D2UnitStrc* pItem, char nAction, unsigned int dwFlag, int bGamble)
{
    D2UnitStrc* hUnit = CLIENTS_GetPlayerFromClient(pClient, 0);

    D2_ASSERT(hUnit, 1915);

    D2GSPacketSrv9C packet9C;

    packet9C.nHeader = 0x9C;
    packet9C.nAction = nAction;
    packet9C.nItemId = SCMD_GetUnitGUID(pItem);
    packet9C.nComponent = UNITS_GetItemComponentId(hUnit, pItem);

    const unsigned int nOldItemFlags = ITEMS_GetItemFlags(pItem);
    ITEMS_SetItemFlag(pItem, dwFlag, 1);

    memset(packet9C.pBitstream, 0, sizeof(packet9C.pBitstream));

    const unsigned int nLength = ITEMS_SerializeItemToBitstream(pItem, packet9C.pBitstream, sizeof(packet9C.pBitstream), 0, 0, bGamble) + 8;

    D2_ASSERT(nLength <= 0xFC, 1932);

    packet9C.nPacketSize = nLength;
    ITEMS_SetItemFlag(pItem, 0xFFFFFFFF, 0);
    ITEMS_SetItemFlag(pItem, nOldItemFlags, 1);

    D2GAME_PACKETS_SendPacket(pClient, &packet9C, packet9C.nPacketSize);

    SCMD_SendSocketedItems(pClient, pItem, dwFlag);
}

// 0x0053EA50
int __fastcall SCMD_SendSocketedItems(D2ClientStrc* pClient, D2UnitStrc* pItem, int nFlags)
{
    if (ITEMS_CheckIfSocketable(pItem) && !sub_006287A0_TestFlags(nFlags, IFLAG_QUANTITY) && pItem->pInventory)
    {
        for (D2UnitStrc* i = INVENTORY_GetFirstItem(pItem->pInventory); i; i = INVENTORY_GetNextItem(i))
        {
            D2UnitStrc* pSocketed = INVENTORY_UnitIsItem(i);
            ITEMS_SetOrRemoveFlag(&nFlags, IFLAG_DELETED, 1);
            D2GAME_SendPacket0x9D(pClient, pItem, pSocketed, ITEMACTION_ITEMINSOCKET, nFlags, 0);
        }
        return 1;
    }
    return 0;
}

// 0x0053CEF0
void __fastcall D2GAME_SendPacket0x9D(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, char nAction, unsigned int dwFlag, int bGamble)
{
    D2GSPacketSrv9D packet;
    packet.nHeader = 0x9D;
    packet.nAction = nAction;
    packet.nComponent = UNITS_GetItemComponentId(pUnit, pItem);
    packet.nItemId = SCMD_GetUnitGUID(pItem);
    int nUnitType = 6;
    if (pUnit)
        nUnitType = pUnit->dwUnitType;
    packet.nUnitType = nUnitType;
    packet.nUnitId = SCMD_GetUnitGUID(pUnit);
    const unsigned int nOldItemFlags = ITEMS_GetItemFlags(pItem);
    ITEMS_SetItemFlag(pItem, dwFlag, 1);
    const unsigned int nLength = ITEMS_SerializeItemToBitstream(pItem, packet.pBitstream, sizeof(packet.pBitstream), 0, 0, bGamble) + 13;
    D2_ASSERT(nLength <= 0xFC, 0x7B4);
    ITEMS_SetItemFlag(pItem, 0xFFFFFFFF, 0);
    ITEMS_SetItemFlag(pItem, nOldItemFlags, 1);
    packet.nPacketSize = nLength;
    D2GAME_PACKETS_SendPacket(pClient, &packet, packet.nPacketSize);
    SCMD_SendSocketedItems(pClient, pItem, dwFlag);
}

static inline int SCMD_GetUnitTypeOr6(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return 6;
    return pUnit->dwUnitType;
}

// 0x0053D0B0
void __fastcall D2GAME_SendP0x9D_ItemAction_IndirectlySwapBodyItem(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D(pClient, pUnit, pItem, ITEMACTION_INDIRECTLYSWAPBODYITEM, dwFlags, 0);
}

// 0x0053D0D0
void __fastcall D2GAME_SendP0x9D_ItemAction_Unequip(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D(pClient, pUnit, pItem, ITEMACTION_UNEQUIP, dwFlags, 0);
}

// 0x0053D0F0
void __fastcall D2GAME_SendP0x9D_ItemAction_SwapBodyItem(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D(pClient, pUnit, pItem, ITEMACTION_SWAPBODYITEM, dwFlags, 0);
}

// 0x0053D110
void __fastcall D2GAME_SendP0x9D_ItemAction_WeaponSwitch(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D(pClient, pUnit, pItem, ITEMACTION_WEAPONSWITCH, dwFlags, 0);
}

// 0x0053EDB0
void __fastcall D2GAME_SendP0x9C_ItemAction_AddQuantity(D2ClientStrc* hClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2_ASSERT(UnitGetClient(pPlayer, ".\\GAME\\SCmd.cpp", 2121) == hClient, 2121);

    D2GAME_SendPacket0x9C(hClient, pItem, ITEMACTION_ADDQUANTITY, dwFlags, 0);
}

// 0x0053EE10
void __fastcall D2GAME_SendP0x9C_ItemAction_SwapInContainer(D2ClientStrc* hClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2_ASSERT(UnitGetClient(pPlayer, ".\\GAME\\SCmd.cpp", 2131) == hClient, 2131);

    D2GAME_SendPacket0x9C(hClient, pItem, ITEMACTION_SWAPINCONTAINER, dwFlags, 0);
}

// 0x0053EE70
void __fastcall D2GAME_SendP0x9C_ItemAction_PutInBelt(D2ClientStrc* hClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2_ASSERT(UnitGetClient(pPlayer, ".\\GAME\\SCmd.cpp", 2140) == hClient, 2140);

    D2GAME_SendPacket0x9C(hClient, pItem, ITEMACTION_PUTINBELT, dwFlags, 0);
}

// 0x0053EED0
void __fastcall D2GAME_SendP0x9C_ItemAction_RemoveFromBelt(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlag)
{
    D2GAME_SendPacket0x9C(pClient, pItem, ITEMACTION_REMOVEFROMBELT, dwFlag, 0);
}

// 0x0053EEF0
void __fastcall D2GAME_SendP0x9C_ItemAction_SwapInBelt(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9C(pClient, pItem, ITEMACTION_SWAPINBELT, dwFlags, 0);
}

// 0x0053EF10
void __fastcall D2GAME_SendP0x9C_ItemAction_ToCursor(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem)
{
    D2GAME_SendPacket0x9C(pClient, pItem, ITEMACTION_TOCURSOR, 0, 0);
}

// 0x0053D130
void __fastcall D2GAME_PACKETS_SendPacket0x3E(D2ClientStrc* pClient, D2UnitStrc* pItem, unsigned char a3, int nStatId, unsigned int nValue, unsigned short nStatLayer)
{
    D2BitBufferStrc tBitBuffer;
    D2GSPacketSrv3E tPacket = {};

    tPacket.nHeader = 0x3E;
    BITMANIP_Initialize(&tBitBuffer, tPacket.pBuffer, sizeof(tPacket.pBuffer));
    SCMD_WriteVariableValue(&tBitBuffer, !pItem ? -1 : pItem->dwUnitId);
    BITMANIP_Write(&tBitBuffer, a3 != 0, 1);
    BITMANIP_Write(&tBitBuffer, nStatId, 9);
    SCMD_WriteVariableValue(&tBitBuffer, nValue);
    if (nStatLayer < 0x100)
    {
        BITMANIP_Write(&tBitBuffer, 0, 1);
        BITMANIP_Write(&tBitBuffer, nStatLayer, 8);
    }
    else
    {
        BITMANIP_Write(&tBitBuffer, 1, 1);
        BITMANIP_Write(&tBitBuffer, nStatLayer, 16);
    }
    tPacket.nSize = BITMANIP_GetSize(&tBitBuffer) + 2;
    D2GAME_PACKETS_SendPacket(pClient, &tPacket, sizeof(tPacket));
}

// 0x0053D220
void __fastcall D2GAME_PACKETS_SendPacket0x3F(D2ClientStrc* pClient, D2UnitStrc* pUnit,
    unsigned char nType, int bClear, int nUnused, unsigned short nValue)
{
    D2PacketTarget3FStrc packet = {};
    packet.nHeader = 0x3F;
    if (bClear)
    {
        if (!pUnit)
        {
            packet.nType = 0xFF;
            packet.nUnitGUID = 0;
            goto send;
        }
        packet.nType = 0xFF;
    }
    else
    {
        packet.nType = nType;
        if (!pUnit)
            goto send;
    }
    packet.nUnitGUID = pUnit->dwUnitId;
send:
    packet.nValue = nValue;
    D2GAME_PACKETS_SendPacket(pClient, &packet, sizeof(packet));
}

// 0x0053D270
void __fastcall D2GAME_PACKETS_SendPacket0x40(D2ClientStrc* client,D2UnitStrc* unit,int x,int y)
{
    Packet40 packet = {};
    packet.header = HEADER;
    packet.guid = SCMD_GetUnitGUID(unit);
    packet.x = x;
    packet.y = y;
    D2GAME_PACKETS_SendPacket(client, &packet, sizeof(packet));
}

// 0x0053D2C0
void __fastcall D2GAME_SendP0x9D_ItemAction_AutoUnequip(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D(pClient, pUnit, pItem, ITEMACTION_AUTOUNEQUIP, dwFlags, 0);
}

// 0x0053D2E0
void __fastcall D2GAME_PACKETS_SendPacket0x42(D2ClientStrc* pClient, D2UnitStrc* pUnit)
{
    D2GSPacketSrv42 packet42 = {};

    packet42.nHeader = 0x42u;
    int nUnitType;
    if (!pUnit)
        nUnitType = 6;
    else
        nUnitType = pUnit->dwUnitType;
    packet42.nUnitType = nUnitType;
    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    packet42.dwUnitGUID = nUnitGUID;

    D2GAME_PACKETS_SendPacket(pClient, &packet42, sizeof(packet42));
}

// 0x0053D330
void __fastcall D2GAME_SendP0x9D_ItemAction_ItemInSocket(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlag)
{
    D2GAME_SendPacket0x9D(pClient, pUnit, pItem, 0x13, dwFlag, 0);
}

// 0x0053D350
void __fastcall D2GAME_SendP0x9D_ItemAction_Unknown0x14(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D(pClient, pUnit, pItem, ITEMACTION_UNKNOWN0x14, dwFlags, 0);
}

// 0x0053D370
void __fastcall D2GAME_SendPacket0x47(D2ClientStrc* pClient, D2UnitStrc* pUnit)
{
    D2GSPacketSrv47 packet47 = {};

    packet47.nHeader = 0x47;
    int nUnitType;
    if (!pUnit)
        nUnitType = 6;
    else
        nUnitType = pUnit->dwUnitType;
    packet47.nUnitType = nUnitType;
    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    packet47.nUnitGUID = nUnitGUID;

    D2GAME_PACKETS_SendPacket(pClient, &packet47, sizeof(packet47));
}

// 0x0053D3C0
void __fastcall D2GAME_SendPacket0x48(D2ClientStrc* pClient, D2UnitStrc* pUnit, int nUnused)
{
    D2GSPacketSrv48 packet48 = {};

    packet48.unused0x02 = nUnused;
    packet48.nHeader = 0x48;
    packet48.nUnitType = SCMD_GetUnitTypeOr6(pUnit);
    const int nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    packet48.nUnitGUID = nUnitGUID;

    D2GAME_PACKETS_SendPacket(pClient, &packet48, sizeof(packet48));
}

// 0x0053D420
void __fastcall D2GAME_SendP0x9D_ItemAction_UpdateStats(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D(pClient, pUnit, pItem, ITEMACTION_UPDATESTATS, dwFlags, 0);
}

// 0x0053D440
void __fastcall SCMD_SendItemFlagUpdate(D2ClientStrc* pClient, D2UnitStrc* pUnit1, D2UnitStrc* pUnit2, int dwFlag, int bSet)
{
    D2GSPacketSrv7D packet7D = {};

    packet7D.nHeader = 0x7D;
    int nUnitType;
    if (!pUnit1)
        nUnitType = 6;
    else
        nUnitType = pUnit1->dwUnitType;
    packet7D.nUnitType = nUnitType;
    const int nUnitGUID1 = !pUnit1 ? -1 : pUnit1->dwUnitId;
    packet7D.nUnitGUID1 = nUnitGUID1;
    const int nUnitGUID2 = !pUnit2 ? -1 : pUnit2->dwUnitId;
    packet7D.nUnitGUID2 = nUnitGUID2;
    packet7D.nItemFlag = dwFlag;
    packet7D.bSet = bSet;

    D2GAME_PACKETS_SendPacket(pClient, &packet7D, sizeof(packet7D));
}

// 0x0053D4B0
void __fastcall D2GAME_SendP0x9D_ItemAction_Unknown0x16(D2ClientStrc* pClient, D2UnitStrc* pUnit, D2UnitStrc* pItem, unsigned int dwFlags)
{
    D2GAME_SendPacket0x9D(pClient, pUnit, pItem, ITEMACTION_UNKNOWN0x16, dwFlags, 0);
}

// 0x0053D4D0
void __fastcall SCMD_SendUnitActionAtPosition(D2ClientStrc* pClient, unsigned char nSourceUnitType, int nSourceUnitGUID, unsigned short nX, unsigned short nY, int nActionId, unsigned short nSkillParam, unsigned char nActionParam, int bQueued)
{
    D2GSPacketSrv4D packet;

    packet.nHeader = bQueued != 0 ? 0x9Au : 0x4Du;
    packet.nUnitType = nSourceUnitType;
    packet.nUnitGUID = nSourceUnitGUID;
    packet.nX = nX;
    packet.nY = nY;
    packet.nSkillId = nActionId;
    packet.nSkillLevel = nActionParam;
    packet.nItemEffect = nSkillParam;

    D2GAME_PACKETS_SendPacket(pClient, &packet, sizeof(packet));
}

// 0x0053D530
void __fastcall SCMD_SendSkillUseOnUnit(D2ClientStrc* pClient, unsigned char nSourceUnitType, int nSourceUnitGUID, unsigned char nUnitType, int nUnitGUID, unsigned short nSkillId, unsigned short nSkillParam, unsigned char nSkillLevel, int bQueued)
{
    D2UnitStrc* pUnit = SUNIT_GetServerUnit(CLIENTS_GetGame(pClient), nUnitType, nUnitGUID);
    if (!pUnit)
    {
        D2GSPacketSrv4C packet4C;

        packet4C.nHeader = bQueued != 0 ? 0x99u : 0x4Cu;
        packet4C.nUnitType = nSourceUnitType;
        packet4C.dwUnitGUID = nSourceUnitGUID;
        packet4C.nTargetType = nUnitType;
        packet4C.dwTargetGUID = nUnitGUID;
        packet4C.wSkill = nSkillId;
        packet4C.nSkillLevel = nSkillLevel;
        packet4C.nItemEffect = nSkillParam;

        D2GAME_PACKETS_SendPacket(pClient, &packet4C, sizeof(packet4C));
        return;
    }

    D2ActiveRoomStrc* pClientRoom = UNITS_GetRoom(CLIENTS_GetPlayerFromClient(pClient, 0));
    if (pClientRoom)
    {
        D2ActiveRoomStrc** ppRoomList;
        int nNumRooms;
        DUNGEON_GetAdjacentRoomsListFromRoom(pClientRoom, &ppRoomList, &nNumRooms);

        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        for (int i = 0; i < nNumRooms; ++i)
        {
            if (pRoom == ppRoomList[i])
            {
                D2GSPacketSrv4C packet4C;

                packet4C.nHeader = bQueued != 0 ? 0x99u : 0x4Cu;
                packet4C.nUnitType = nSourceUnitType;
                packet4C.dwUnitGUID = nSourceUnitGUID;
                packet4C.nTargetType = nUnitType;
                packet4C.dwTargetGUID = nUnitGUID;
                packet4C.wSkill = nSkillId;
                packet4C.nSkillLevel = nSkillLevel;
                packet4C.nItemEffect = nSkillParam;

                D2GAME_PACKETS_SendPacket(pClient, &packet4C, sizeof(packet4C));
                return;
            }
        }
    }

    SCMD_SendUnitActionAtPosition(pClient, nSourceUnitType, nSourceUnitGUID, D2COMMON_10175_PathGetFirstPointX(pUnit->pDynamicPath), D2COMMON_10176_PathGetFirstPointY(pUnit->pDynamicPath), nSkillId, nSkillParam, nSkillLevel, bQueued);
}

// 0x0053EF30
void __fastcall D2GAME_SendP0x9C_ItemAction_AddOrRemoveFromShop(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pItem, unsigned char nShopAction)
{
    switch (nShopAction)
    {
    case 56:
    {
        int bIdentified = 0;
        if (ITEMS_IsMagSetRarUniCrfOrTmp(pItem) && !ITEMS_CheckItemFlag(pItem, IFLAG_IDENTIFIED, 2498, ".\\GAME\\SCmd.cpp"))
        {
            bIdentified = 1;
        }
        D2GAME_SendPacket0x9C(pClient, pItem, ITEMACTION_ADDTOSHOP, 0, bIdentified);
        break;
    }
    case 57:
    {
        const unsigned char nPage = ITEMS_GetInvPage(pItem);
        ITEMS_SetInvPage(pItem, ITEMS_GetItemCell(pItem));
        D2GAME_SendPacket0x9C(pClient, pItem, ITEMACTION_REMOVEFROMSHOP, 0, 0);
        ITEMS_SetInvPage(pItem, nPage);
        break;
    }
    }
}

// 0x00568DB0
int __cdecl sub_00568DB0_Return0()
{
    return 0;
}

// 0x00570680
int __cdecl sub_00570680_Return5()
{
    return 5;
}

// 0x00570690
void __stdcall sub_00570690_Nop(int nUnused1)
{
}

// 0x0053D670
void __fastcall D2GAME_SendPacket0x28(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, D2BitBufferStrc* pQuestRecord, unsigned char nQuestFlags)
{
    D2GSPacketSrv28 packet28;

    packet28.nHeader = nHeader;
    packet28.nUnitType = nUnitType;
    packet28.nUnitGUID = nUnitGUID;
    packet28.nTerminateType = nQuestFlags;

    QUESTRECORD_CopyRecordToBuffer(pQuestRecord, packet28.pData, 0x60, 0);

    D2GAME_PACKETS_SendPacket(pClient, &packet28, sizeof(packet28));
}

// 0x0053D6D0
void __fastcall SCMD_SendInteractionTarget(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitId, int nUnused)
{
    D2PacketInteractStrc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.nUnitType = nUnitType;
    tPacket.nUnitGUID = nUnitId;
    D2GAME_PACKETS_SendPacket(pClient, &tPacket, sizeof(tPacket));
}

// 0x0053D700
void __fastcall D2GAME_PACKETS_SendPacket0x29(D2ClientStrc* pClient, D2GSPacketSrv29* pPacket)
{
    D2GAME_PACKETS_SendPacket(pClient, pPacket, sizeof(*pPacket));
}

// 0x0053D710
void __fastcall SCMD_SendPacket0x5D(D2ClientStrc* pClient, D2GSPacketSrv5D* pPacket)
{
    D2GSPacketSrv5D packet5D = *pPacket;
    D2GAME_PACKETS_SendPacket(pClient, &packet5D, sizeof(packet5D));
}

// 0x0053D740
void __fastcall D2GAME_SendPacket0x2A(D2ClientStrc* pClient, char nHeader, char nResult, int nGold, int nUnitGUID, char nTransactionType)
{
    D2PacketSrv2AStrc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.nResult = nResult;
    tPacket.nGold = nGold;
    tPacket.nUnitGUID = nUnitGUID;
    tPacket.nTransactionType = nTransactionType;
    D2GAME_PACKETS_SendPacket(pClient, &tPacket, sizeof(tPacket));
}

// 0x0053D780
void __fastcall SCMD_SendPacket0x2C(D2ClientStrc* pClient, D2GSPacketSrv2C* pPacket)
{
    D2GSPacketSrv2C packet2C = *pPacket;
    D2GAME_PACKETS_SendPacket(pClient, &packet2C, sizeof(packet2C));
}

// 0x0053D7B0
void __fastcall D2GAME_SendPacket0x4E(D2ClientStrc* pClient, D2GSPacketSrv4E* pPacket)
{
    D2GSPacketSrv4E packet4E = *pPacket;
    D2GAME_PACKETS_SendPacket(pClient, &packet4E, sizeof(packet4E));
}

// 0x0053D7E0
void __fastcall D2GAME_SendPacket0x50(D2ClientStrc* pClient, D2GSPacketSrv50* pPacket)
{
    D2GSPacketSrv50 packet50 = *pPacket;
    D2GAME_PACKETS_SendPacket(pClient, &packet50, sizeof(packet50));
}

// 0x0053D830
void __fastcall D2GAME_PACKETS_SendPacket0x5E(D2ClientStrc* pClient, D2GSPacketSrv5E* pPacket)
{
    D2GAME_PACKETS_SendPacket(pClient, pPacket, sizeof(*pPacket));
}

// 0x0053D840
void __fastcall D2GAME_SendPacket0x52(D2ClientStrc* pClient, D2GSPacketSrv52* pPacket)
{
    D2GAME_PACKETS_SendPacket(pClient, pPacket, sizeof(*pPacket));
}

// 0x0053D850
void __fastcall D2GAME_PACKETS_SendPacket0x11(D2ClientStrc* pClient, int nUnitType, int nUnitGUID, int nOverlay)
{
    D2GSPacketSrv11 packet11;

    packet11.nHeader = 0x11;
    packet11.nUnitType = nUnitType;
    packet11.dwUnitGUID = nUnitGUID;
    packet11.wOverlay = nOverlay;

    D2GAME_PACKETS_SendPacket(pClient, &packet11, sizeof(packet11));
}

// 0x0053D880
void __fastcall SCMD_SendUniqueMonsterInfo(D2ClientStrc* pClient, int dwUnitGUID, unsigned char nUnitType, unsigned short nNameSeed, unsigned short nUMods01, unsigned short nUMods23, unsigned short bChampion)
{
    D2GSPacketSrv57 packet57;

    packet57.nHeader = 0x57;
    packet57.dwUnitGUID = dwUnitGUID;
    packet57.nUnitType = nUnitType;
    packet57.nNameSeed = nNameSeed;
    packet57.nUMods01 = nUMods01;
    packet57.nUMods23 = nUMods23;
    packet57.bChampion = bChampion;

    D2GAME_PACKETS_SendPacket(pClient, &packet57, sizeof(packet57));
}

// 0x0053D8D0
void __fastcall D2GAME_SendPacket0x58(D2ClientStrc* pClient, D2GSPacketSrv58* pPacket)
{
    D2GSPacketSrv58 packet58 = *pPacket;
    D2GAME_PACKETS_SendPacket(pClient, &packet58, sizeof(packet58));
}

// 0x0053D900
void __fastcall SCMD_SendPortalState(D2ClientStrc* pClient, D2UnitStrc* pUnit)
{
    D2GSPacketSrv60 packet60;

    packet60.nHeader = 0x60;
    packet60.nFlags = UNITS_GetObjectPortalFlags(pUnit);
    packet60.nLevel = pUnit->pObjectData->InteractType;
    packet60.dwUnitGUID = pUnit->dwUnitId;

    D2GAME_PACKETS_SendPacket(pClient, &packet60, sizeof(packet60));
}

// 0x0053D940
void __fastcall D2GAME_PACKETS_SendPacket0x61(D2ClientStrc* pClient, unsigned char nValue)
{
    D2GSPacketSrv61 packet61;

    packet61.nHeader = 0x61;
    packet61.nCinematic = nValue;

    D2GAME_PACKETS_SendPacket(pClient, &packet61, sizeof(packet61));
}

// 0x0053D960
void __fastcall sub_0053D960_SendPacket0x78(D2ClientStrc* pClient, D2GSPacketSrv78* pPacket)
{
    D2GSPacketSrv78 packet78 = *pPacket;
    D2GAME_PACKETS_SendPacket(pClient, &packet78, sizeof(packet78));
}

// build: symbol ?ERRORMANAGER_GetBitWidth@* 0x00409000
int __fastcall ERRORMANAGER_GetBitWidth(unsigned int nValue)
{
    if (!nValue)
    {
        return 0;
    }
    __asm
    {
        bsr eax, nValue
        inc eax
        mov nValue, eax
    }
    return nValue;
}

static inline int Log2Ceil(int nValue)
{
    return nValue < 3 ? 1 : ERRORMANAGER_GetBitWidth(nValue - 1);
}

static inline int sub_0044BE50(D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
    }
    return nType;
}

// build: symbol ?UNITS_GetWeaponClass@* 0x00623C60
static inline int UNITS_GetWeaponClass(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwClassId;
}

static inline int sub_00451F50(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwUnitId;
}

static inline int UNITS_IsMerc(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlags >> 9) & 1;
}

static inline int UNITS_HasStoredOwnerInfo(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlagEx >> 10) & 1;
}

static inline int CLIENTS_GetUnitXByType(D2UnitStrc* pUnit)
{
    switch (sub_0044BE50(pUnit))
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nX;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

static inline int CLIENTS_GetUnitYByType(D2UnitStrc* pUnit)
{
    switch (sub_0044BE50(pUnit))
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->tGameCoords.nY;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

static inline unsigned char* MONSTER_GetComponents(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        return pUnit->pMonsterData->nComponent;
    }
    return 0;
}

static inline D2ItemStatCostTxt* SKILLS_GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }
    return 0;
}

// 0x0053D9C0
void __fastcall D2GAME_PACKETS_SendPacket0x65(D2ClientStrc* pClient, unsigned int dwPlayerId, unsigned short nCount)
{
    D2GSPacketSrv65Strc tPacket;
    tPacket.nHeader = 0x65;
    tPacket.dwUnitId = dwPlayerId;
    tPacket.nKillCount = nCount;
    D2GAME_PACKETS_SendPacket(pClient, &tPacket, sizeof(tPacket));
}

// 0x0053D9F0
void __cdecl SCMD_AssertFail()
{
    D2_ASSERT(0, 0xAB4);
}

// 0x0053DA10
void __fastcall D2GAME_PACKETS_SendPacket0x73(D2ClientStrc* pClient, D2GSPacketSrv73* pPacket)
{
    D2GSPacketSrv73 packet73 = *pPacket;
    D2GAME_PACKETS_SendPacket(pClient, &packet73, sizeof(packet73));
}

// 0x0053DA40
void __fastcall D2GAME_PACKETS_SendPacket0x74(D2ClientStrc* pClient, D2UnitStrc* pPlayer, D2UnitStrc* pCorpse, unsigned char bAssign)
{
    D2GSPacketSrv74 packet74;
    packet74.nHeader = 0x74;
    packet74.bAssign = bAssign;
    const int nPlayerGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
    packet74.nPlayerGUID = nPlayerGUID;
    const int nCorpseGUID = !pCorpse ? -1 : pCorpse->dwUnitId;
    packet74.nCorpseGUID = nCorpseGUID;
    D2GAME_PACKETS_SendPacket(pClient, &packet74, sizeof(packet74));
}

static __forceinline void __fastcall SCMD_SendGoldStat(D2ClientStrc* pClient, unsigned short nStatId, unsigned int nValue)
{
    const unsigned char nPacketStatId = (unsigned char)nStatId;
    if (nValue < 0xFF)
    {
        D2GSPacketSrv1D packet1D;
        packet1D.nHeader = 0x1D;
        packet1D.nStat = nPacketStatId;
        packet1D.nValue = nValue;

        D2GAME_PACKETS_SendPacket(pClient, &packet1D, sizeof(packet1D));
    }
    else if (nValue < 0xFFFF)
    {
        D2GSPacketSrv1E packet1E;
        packet1E.nHeader = 0x1E;
        packet1E.nStat = nPacketStatId;
        packet1E.nValue = nValue;

        D2GAME_PACKETS_SendPacket(pClient, &packet1E, sizeof(packet1E));
    }
    else
    {
        D2GSPacketSrv1F packet1F;
        packet1F.nHeader = 0x1F;
        packet1F.nStat = nPacketStatId;
        packet1F.nValue = nValue;

        D2GAME_PACKETS_SendPacket(pClient, &packet1F, sizeof(packet1F));
    }
}

// 0x0053E9B0
void __fastcall D2GAME_PACKETS_SendPacket0x19(D2ClientStrc* pClient, int nValue, int nPreviousGold)
{
    const int nDiff = nValue - nPreviousGold;
    if (nDiff <= 0 || nDiff >= 0xFF)
    {
        SCMD_SendGoldStat(pClient, STAT_GOLD, nValue);
    }
    else
    {
        D2GSPacketSrv19 packet19;
        packet19.nHeader = 0x19;
        packet19.nGold = nDiff;

        D2GAME_PACKETS_SendPacket(pClient, &packet19, sizeof(packet19));
    }
}

// 0x0053DA90
void __fastcall SCMD_Send0x75_PartyRosterUpdate(D2UnitStrc* pLocalPlayer, D2UnitStrc* pOtherPlayer)
{
    D2ClientStrc* pClient = UnitGetClient(pLocalPlayer, ".\\GAME\\SCmd.cpp", 0xAFA);

    D2GSPacketSrv75 packet75 = {};

    packet75.nHeader = 0x75u;
    const int nUnitGUID = !pOtherPlayer ? -1 : pOtherPlayer->dwUnitId;
    packet75.nUnitGUID = nUnitGUID;
    packet75.nLevel = STATLIST_UnitGetStatValue(pOtherPlayer, STAT_LEVEL, 0);
    packet75.nPartyId = SUNIT_GetPartyId(pOtherPlayer);
    packet75.nFlags = PLAYERLIST_GetFlags(pLocalPlayer, pOtherPlayer);
    packet75.nPartyFlags = PLAYERLIST_GetPartyState(pLocalPlayer, pOtherPlayer);

    D2GAME_PACKETS_SendPacket(pClient, &packet75, sizeof(packet75));
}

// 0x0053DB20
void __fastcall D2GAME_PACKETS_SendPacket0x7B(D2ClientStrc* pClient, unsigned char nIndex, int nSkill, int nHand, int nItemGUID)
{
    D2GSPacketSrv7B packet7B;

    packet7B.nHeader = 0x7Bu;
    packet7B.nSlot = nIndex;
    packet7B.nSkill = nSkill & 0xFFF;
    packet7B.nItemGUID = nItemGUID;
    if (nHand)
        packet7B.nSkill |= 0x8000;

    D2GAME_PACKETS_SendPacket(pClient, &packet7B, sizeof(packet7B));
}

// 0x0053DB70
void __fastcall D2GAME_PACKETS_SendPacket0x7E(D2ClientStrc* pClient)
{
    D2GSPacketSrv7E packet7E;

    packet7E.nHeader = 0x7E;

    D2GAME_PACKETS_SendPacket(pClient, &packet7E, sizeof(packet7E));
}

// 0x0053DB90
void __fastcall D2GAME_PACKETS_SendPacket0x82(D2GameStrc* pGame, D2ClientStrc* pClient, int nPortalGUID, int nPortalOwnerGUID)
{
    D2GSPacketSrv82 packet82;

    packet82.nHeader = 0x82u;
    D2UnitStrc* pPortal = SUNIT_GetServerUnit(pGame, 2, nPortalGUID);
    packet82.szOwnerName[0] = 0;
    if (pPortal)
    {
        D2UnitStrc* pPlayer = SUNIT_GetServerUnit(pGame, 0, OBJECTS_GetUnitIdFromTimerArg(pPortal));
        if (pPlayer)
        {
            SStrCopy(packet82.szOwnerName, UNITS_GetPlayerData(pPlayer)->szName, sizeof(packet82.szOwnerName));

            packet82.dwOwnerGUID = pPlayer->dwUnitId;
            packet82.dwPortalGUID0 = nPortalGUID;
            packet82.dwPortalGUID1 = nPortalOwnerGUID;

            D2GAME_PACKETS_SendPacket(pClient, &packet82, sizeof(packet82));
        }
    }
}

// 0x0053DC20
void __fastcall D2GAME_PACKETS_SendPacket0x83(D2ClientStrc* pClient, const char* szName, unsigned short wSize, unsigned short wArg1, unsigned short wArg2, const void* pData)
{
    D2GSPacketSrv83 packet;
    packet.nHeader = 0x83;
    strcpy(packet.szName, szName);
    packet.f_5 = wArg1;
    packet.wSize = wSize;
    packet.f_9 = wArg2;
    memcpy(packet.pData, pData, wSize);
    D2GAME_PACKETS_SendPacket(pClient, &packet, wSize + 0x0B);
}

// 0x0053DCC0
void __fastcall D2GAME_PACKETS_SendPacket0x84(D2ClientStrc* pClient, unsigned char nArg, unsigned short wSize, const void* pData)
{
    D2GSPacketSrv84 packet;
    packet.nHeader = 0x84;
    packet.nArg = nArg;
    memcpy(packet.pData, pData, wSize);
    D2GAME_PACKETS_SendPacket(pClient, &packet, wSize + 2);
}

// 0x0053DD20
void __fastcall D2GAME_PACKETS_SendPacket0x88(D2ClientStrc* pClient, const char* szName, unsigned short wSize, unsigned short wArg1, unsigned short wArg2, const void* pData)
{
    D2GSPacketSrv83 packet;
    packet.nHeader = 0x88;
    strcpy(packet.szName, szName);
    packet.f_5 = wArg1;
    packet.wSize = wSize;
    packet.f_9 = wArg2;
    memcpy(packet.pData, pData, wSize);
    D2GAME_PACKETS_SendPacket(pClient, &packet, wSize + 0x0B);
}

// 0x0053DDC0
void __fastcall D2GAME_PACKETS_SendPacket0x8B(D2ClientStrc* pClient, int nUnitGUID, unsigned char nPartyState)
{
    D2GSPacketSrv8BStrc tPacket;
    tPacket.nHeader = 0x8B;
    tPacket.nUnitGUID = nUnitGUID;
    tPacket.bParty = nPartyState;
    D2GAME_PACKETS_SendPacket(pClient, &tPacket, sizeof(tPacket));
}

// 0x0053DDF0
void __fastcall SCMD_SendPlayerRelationshipCallback(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pPacket)
{
    D2GAME_PACKETS_SendPacket(UnitGetClient(pPlayer, ".\\GAME\\SCmd.cpp", 0xBAE), pPacket, sizeof(D2GSPacketSrv8C));
}

// 0x0053DE20
void __fastcall SCMD_BroadcastPlayerRelationship(D2GameStrc* pGame, int dwPlayerId1, int dwPlayerId2, short wRelationState)
{
    D2GSPacketSrv8C packet8C;
    packet8C.nHeader = 0x8C;
    packet8C.dwPlayerGUID1 = dwPlayerId1;
    packet8C.dwPlayerGUID2 = dwPlayerId2;
    packet8C.nFlags = wRelationState;
    SUNIT_IterateLivingPlayers(pGame, SCMD_SendPlayerRelationshipCallback, &packet8C);
}

// 0x0053DE50
void __fastcall D2GAME_PACKETS_SendPacket0x8C(D2UnitStrc* pUnit, int dwPlayerId1, int dwPlayerId2, unsigned short wRelationState)
{
    D2GSPacketSrv8C packet8C;

    packet8C.nHeader = 0x8C;
    packet8C.dwPlayerGUID1 = dwPlayerId1;
    packet8C.dwPlayerGUID2 = dwPlayerId2;
    packet8C.nFlags = wRelationState;

    D2GAME_PACKETS_SendPacket(UnitGetClient(pUnit, ".\\GAME\\SCmd.cpp", 0xBD0), &packet8C, sizeof(packet8C));
}

// 0x0053DE90
void __fastcall SCMD_SendPlayerPartyCallback(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pPacket)
{
    D2GAME_PACKETS_SendPacket(UnitGetClient(pPlayer, ".\\GAME\\SCmd.cpp", 0xBD8), pPacket, sizeof(D2GSPacketSrv8D));
}

// 0x0053DEC0
void __fastcall SCMD_BroadcastPlayerParty(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2GSPacketSrv8D packet8D;

    packet8D.nHeader = 0x8D;
    const int nUnitGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
    packet8D.dwPlayerGUID = nUnitGUID;
    packet8D.nPartyGUID = SUNIT_GetPartyId(pPlayer);

    SUNIT_IterateLivingPlayers(pGame, SCMD_SendPlayerPartyCallback, &packet8D);
}

// 0x0053DF00
void __fastcall D2GAME_PACKETS_SendPacket0x8D(D2UnitStrc* pUnit, D2UnitStrc* pPlayer)
{
    D2GSPacketSrv8D packet8D;

    packet8D.nHeader = 0x8D;
    const int nUnitGUID = !pPlayer ? -1 : pPlayer->dwUnitId;
    packet8D.dwPlayerGUID = nUnitGUID;
    packet8D.nPartyGUID = SUNIT_GetPartyId(pPlayer);

    D2GAME_PACKETS_SendPacket(UnitGetClient(pUnit, ".\\GAME\\SCmd.cpp", 0xBF6), &packet8D, sizeof(packet8D));
}

// 0x0053DF50
void __fastcall SCMD_SendCorpseAssignCallback(D2GameStrc* pGame, D2UnitStrc* pPlayer, void* pPacket)
{
    D2GAME_PACKETS_SendPacket(UnitGetClient(pPlayer, ".\\GAME\\SCmd.cpp", 0xBFF), pPacket, 0xA);
}

// 0x0053DF80
void __fastcall D2GAME_SendPacket0x8E_CorpseAssign_ToAllPlayers(D2GameStrc* pGame, int nUnitId, int nCorpseId, unsigned char bAssign)
{
    D2GSPacketSrv8E packet8E;
    packet8E.nHeader = 0x8E;
    packet8E.dwPlayerGUID = nUnitId;
    packet8E.dwCorpseGUID = nCorpseId;
    packet8E.nType = bAssign;
    SUNIT_IterateLivingPlayers(pGame, SCMD_SendCorpseAssignCallback, &packet8E);
}

// 0x0053DFB0
void __fastcall D2GAME_PACKETS_SendPacket0x8E(D2ClientStrc* pClient, int nUnitId, int nCorpseId, unsigned char bAssign)
{
    D2GSPacketSrv8E packet8E;

    packet8E.nHeader = 0x8E;
    packet8E.dwPlayerGUID = nUnitId;
    packet8E.dwCorpseGUID = nCorpseId;
    packet8E.nType = bAssign;

    D2GAME_PACKETS_SendPacket(pClient, &packet8E, sizeof(packet8E));
}

// 0x0053DFE0
void __fastcall D2GAME_PACKETS_SendPacket0x89(D2ClientStrc* pClient, D2GSPacketSrv89* pPacket)
{
    D2GAME_PACKETS_SendPacket(pClient, pPacket, sizeof(*pPacket));
}

// 0x0053DFF0
void __fastcall D2GAME_SendPacket0x8A(D2ClientStrc* pClient, D2GSPacketSrv8A* pPacket)
{
    D2GSPacketSrv8A packet8A = *pPacket;
    D2GAME_PACKETS_SendPacket(pClient, &packet8A, sizeof(packet8A));
}

// 0x0053E020
void __fastcall D2GAME_PACKETS_SendPacket0x8F(D2ClientStrc* pClient)
{
    D2GSPacketSrv8F packet8F = { 0x8F };
    D2GAME_PACKETS_SendPacket(pClient, &packet8F, sizeof(packet8F));
}

// 0x0053E060
void __fastcall D2GAME_PACKETS_SendPacket0x91(D2ClientStrc* pClient, D2GSPacketSrv91* pPacket)
{
    D2GSPacketSrv91 packet91 = *pPacket;
    D2GAME_PACKETS_SendPacket(pClient, &packet91, sizeof(packet91));
}

// 0x0053E0A0
void __fastcall D2GAME_PACKETS_SendPacket0x98(D2ClientStrc* pClient, unsigned int nUnitGUID, unsigned short nMinionSpawnClassId)
{
    D2GSPacketSrv98 packet98 = {};

    packet98.nHeader = 0x98;
    packet98.nUnitGUID = nUnitGUID;
    packet98.nMinionSpawnClassId = nMinionSpawnClassId;

    D2GAME_PACKETS_SendPacket(pClient, &packet98, sizeof(packet98));
}

// 0x0053E0E0
void __fastcall D2GAME_PACKETS_SendPacket0x9B(D2ClientStrc* pClient, unsigned short nUnitGUID, int nReviveCost)
{
    D2GSPacketSrv9B packet9B;

    packet9B.nHeader = 0x9B;
    packet9B.nMercNameStringId = nUnitGUID;
    packet9B.nReviveCost = nReviveCost;

    D2GAME_PACKETS_SendPacket(pClient, &packet9B, sizeof(packet9B));
}

// 0x0053E110
void __fastcall D2GAME_PACKETS_SendPacket0x97(D2ClientStrc* pClient)
{
    D2GSPacketSrv97 packet97 = {};

    packet97.nHeader = 0x97;

    D2GAME_PACKETS_SendPacket(pClient, &packet97, sizeof(packet97));
}

// 0x0053E130
void __fastcall SCMD_SendUnitUpdates(D2ClientStrc* pClient)
{
    int nCount = pClient->nUnitUpdateIndex;
    if (nCount)
    {
        D2PacketDataStrc* pData = CLIENTS_PacketDataList_GetHead(pClient);
        unsigned short nSize = (unsigned short)(sizeof(D2GSPacketSrv16) + sizeof(D2UnitUpdateEntry) * nCount);
        D2GSPacketSrv16* pPacket = (D2GSPacketSrv16*)(pData->packetData + pData->nPacketSize);
        pPacket->nHeader = 0x16;
        pPacket->nCount = (unsigned char)nCount;
        pPacket->nSize = nSize;
        D2UnitUpdateEntry* pOut = pPacket->entries;
        for (int i = 0; i < nCount; ++i)
        {
            *pOut++ = *(D2UnitUpdateEntry*)&pClient->unitUpdate[i];
        }
        pData->nPacketSize += nSize;
    }
}

// 0x0053E1A0
void __fastcall D2GAME_PACKETS_SendPacket0xA4(D2ClientStrc* pClient, short nMonStatsId)
{
    D2GSPacketSrvA4 packetA4;

    packetA4.nHeader = 0xA4;
    packetA4.nMonStatsId = nMonStatsId;

    D2GAME_PACKETS_SendPacket(pClient, &packetA4, sizeof(packetA4));
}

// 0x0053E1C0
void __fastcall D2GAME_PACKETS_SendPacket0xA6(D2ClientStrc* pClient, unsigned char nType, short wArg, int nSize, const void* pData)
{
    D2GSPacketSrvA6 packet;
    packet.nHeader = 0xA6;
    packet.nType = nType;
    packet.wArg = wArg;
    const int nPacketSize = nSize + 6;
    D2_ASSERT(nPacketSize < 0xFFFF, 0xD0D);
    packet.nPacketSize = nPacketSize;
    memcpy(packet.data, pData, nSize);
    D2GAME_PACKETS_SendPacket(pClient, &packet, nPacketSize);
}

// 0x0053E260
void __fastcall D2GAME_PACKETS_SendPacket0xA7_StateOn(D2ClientStrc* pClient, unsigned char nUnitType, unsigned long dwUnitId, unsigned char nState)
{
    D2GSPacketSrvA7 packetA7;

    packetA7.nHeader = 0xA7;
    packetA7.nUnitType = nUnitType;
    packetA7.nUnitId = dwUnitId;
    packetA7.nState = nState;

    D2GAME_PACKETS_SendPacket(pClient, &packetA7, sizeof(packetA7));
}

// 0x0053E290
void __fastcall D2GAME_PACKETS_SendPacket0xA9_StateOff(D2ClientStrc* pClient, unsigned char nUnitType, unsigned long dwUnitId, unsigned char nState)
{
    D2GSPacketSrvA9 packetA9;

    packetA9.nHeader = 0xA9;
    packetA9.nUnitType = nUnitType;
    packetA9.nUnitId = dwUnitId;
    packetA9.nState = nState;

    D2GAME_PACKETS_SendPacket(pClient, &packetA9, sizeof(packetA9));
}

// 0x0053E2E0
void __fastcall SCMD_SendMonsterAssign(D2ClientStrc* pClient, D2UnitStrc* pUnit)
{
    if (sub_0044BE50(pUnit) != UNIT_MONSTER)
    {
        return;
    }

    D2GSPacketSrvAC packetAC;
    packetAC.nHeader = 0xAC;
    packetAC.dwUnitGUID = pUnit->dwUnitId;
    packetAC.nUnitIndex = UNITS_GetWeaponClass(pUnit);
    packetAC.nPosX = CLIENTS_GetUnitXByType(pUnit);
    packetAC.nPosY = CLIENTS_GetUnitYByType(pUnit);
    packetAC.nLifePct = MONSTERMODE_GetHpPercent128(pUnit);

    D2BitBufferStrc bitBuffer;
    BITMANIP_Initialize(&bitBuffer, packetAC.bitstream, sizeof(packetAC.bitstream));

    if (pUnit->dwAnimMode == MONMODE_SKILL1)
    {
        BITMANIP_Write(&bitBuffer, pUnit->dwAnimMode, 4);
    }
    else if (pUnit->dwAnimMode == MONMODE_SKILL2)
    {
        BITMANIP_Write(&bitBuffer, pUnit->dwAnimMode, 4);
    }
    else if (pUnit->dwAnimMode == MONMODE_DEAD || pUnit->dwAnimMode == MONMODE_DEATH)
    {
        BITMANIP_Write(&bitBuffer, pUnit->dwAnimMode, 4);
    }
    else
    {
        BITMANIP_Write(&bitBuffer, MONMODE_NEUTRAL, 4);
    }

    if (MONSTER_HasComponents(pUnit))
    {
        BITMANIP_Write(&bitBuffer, 1, 1);

        unsigned char* pComponents = MONSTER_GetComponents(pUnit);
        if (pComponents)
        {
            for (int i = 0; i < 16; ++i)
            {
                const unsigned char nComponent = pComponents[i];
                BITMANIP_Write(&bitBuffer, nComponent, Log2Ceil(D2COMMON_11068_GetCompInfo(pUnit, i)));
            }
        }
    }
    else
    {
        BITMANIP_Write(&bitBuffer, 0, 1);
    }

    if (!MONSTERUNIQUE_HasMonsterFlag(pUnit) && !UNITS_IsMerc(pUnit))
    {
        BITMANIP_Write(&bitBuffer, 0, 1);
    }
    else
    {
        BITMANIP_Write(&bitBuffer, 1, 1);

        const int nChampion = MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_CHAMPION);
        BITMANIP_Write(&bitBuffer, nChampion != 0, 1);
        const int nUnique = MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_UNIQUE);
        BITMANIP_Write(&bitBuffer, nUnique != 0, 1);
        const int nSuperUnique = MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_SUPERUNIQUE);
        BITMANIP_Write(&bitBuffer, nSuperUnique != 0, 1);
        const int nMinion = MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_MINION);
        BITMANIP_Write(&bitBuffer, nMinion != 0, 1);
        const int nGhostly = MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_GHOSTLY);
        BITMANIP_Write(&bitBuffer, nGhostly != 0, 1);

        if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, MONTYPEFLAG_SUPERUNIQUE))
        {
            BITMANIP_Write(&bitBuffer, MONSTERUNIQUE_GetBossHcIdx(pUnit), 16);
        }

        const unsigned char* pUMods = MONSTERUNIQUE_GetUMods(pUnit);
        if (pUMods)
        {
            for (int i = 0; i < 9 && pUMods[i]; ++i)
            {
                BITMANIP_Write(&bitBuffer, pUMods[i], 8);
            }
        }

        BITMANIP_Write(&bitBuffer, 0, 8);

        BITMANIP_Write(&bitBuffer, MONSTERUNIQUE_GetNameSeed(pUnit), 16);

        D2UnitStrc* pOwner = AIGENERAL_GetMinionOwner(pUnit);
        if (pOwner && pOwner->dwUnitType == UNIT_PLAYER && PLAYERPETS_GetPetTypeFromPetGUID(pOwner, packetAC.dwUnitGUID) == PETTYPE_HIREABLE)
        {
            BITMANIP_Write(&bitBuffer, 1, 1);
            BITMANIP_Write(&bitBuffer, sub_00451F50(pOwner), 32);
        }
        else
        {
            BITMANIP_Write(&bitBuffer, 0, 1);
        }
    }

    if (UNITS_HasStoredOwnerInfo(pUnit) && pUnit->dwOwnerType == UNIT_PLAYER)
    {
        BITMANIP_Write(&bitBuffer, 1, 1);
        BITMANIP_Write(&bitBuffer, pUnit->dwOwnerGUID & 0x8FFFFFFF, 31);
    }
    else
    {
        BITMANIP_Write(&bitBuffer, 0, 1);
    }

    int bStatsSent = 0;
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitStateAndFlag(pUnit, 0, 0x40);
    if (pStatList)
    {
        D2StatStrc stats[16];
        const int nStatCount = STATLIST_GetBaseStatsData(pStatList, stats, 16);
        if (nStatCount > 0)
        {
            for (int i = 0; i < nStatCount; ++i)
            {
                const unsigned short nLayer = stats[i].nLayer;
                const int nStat = stats[i].nStat;
                const int nValue = stats[i].nValue;
                D2ItemStatCostTxt* pItemStatCostTxtRecord = SKILLS_GetItemStatCostTxtRecord(stats[i].nStat);
                if (pItemStatCostTxtRecord)
                {
                    if (pItemStatCostTxtRecord->nItemStatFlags[ITEMSTATCOSTFLAGINDEX_SEND_OTHER >> 3] & gdwBitMasks[ITEMSTATCOSTFLAGINDEX_SEND_OTHER & 7] && pItemStatCostTxtRecord->nSendBits > 0)
                    {
                        if (!bStatsSent)
                        {
                            bStatsSent = 1;
                            BITMANIP_Write(&bitBuffer, 1, 1);
                        }

                        BITMANIP_Write(&bitBuffer, nStat, 9);

                        if (pItemStatCostTxtRecord->nSendParamBits)
                        {
                            BITMANIP_Write(&bitBuffer, nLayer, pItemStatCostTxtRecord->nSendParamBits);
                        }

                        BITMANIP_Write(&bitBuffer, nValue, pItemStatCostTxtRecord->nSendBits);
                    }
                }
            }

            if (bStatsSent)
            {
                BITMANIP_Write(&bitBuffer, 511, 9);
                goto Send;
            }
            BITMANIP_Write(&bitBuffer, 0, 1);
        }
        else
        {
            BITMANIP_Write(&bitBuffer, 0, 1);
        }
    }

    BITMANIP_Write(&bitBuffer, 0, 1);

Send:
    const int nPacketSize = BITMANIP_GetSize(&bitBuffer) + 13;
    packetAC.nPacketLength = nPacketSize;
    D2GAME_PACKETS_SendPacket(pClient, &packetAC, nPacketSize);
}

// 0x0053E840
int __fastcall D2GAME_PACKETS_SendPacket0xAE(D2ClientStrc* pClient, const void* pData, unsigned int nSize)
{
    D2GSPacketSrvAE packet;
    if (nSize <= 0x1FD)
    {
        packet.nHeader = 0xAE;
        packet.nSize = nSize;
        memcpy(packet.data, pData, nSize);
        D2GAME_PACKETS_SendPacket(pClient, &packet, nSize + 3);
        return 1;
    }
    D2_ASSERT(nSize <= 0x1FD, 0xE38);
}

int __cdecl sub_005A0110()
{
    return 0;
}

// 0x0053E8D0
void __fastcall SCMD_SendRawPacket(D2ClientStrc* pClient, const void* pPacket, int nPacketSize)
{
    D2GAME_PACKETS_SendPacket(pClient, pPacket, nPacketSize);
}

