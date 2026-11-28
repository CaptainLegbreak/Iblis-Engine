#pragma once
// Game server state: arena settings, gamble inventories, object populating regions, monster spawn arguments and the server callback table

#include "D2Check.h"
#include "D2Structs.h"
#include "D2Path.h"

struct D2ActiveRoomStrc;
struct D2ClientInfoStrc;
struct D2ClientStrc;
struct D2FileTimeStrc;
struct D2GameStrc;
struct D2InventoryStrc;
struct D2RoomCoordListStrc;
struct D2ArenaStrc;
struct D2NpcGambleStrc;
struct D2ObjectRegionStrc;
struct D2UnkMonCreateStrc;
struct D2ServerCallbackFunctions;

typedef void (__fastcall* PlrMsgFunc)(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int nAnimMode);

struct D2UnkPlrMsgStrc
{
    PlrMsgFunc pfSendMode; // 0x00
    int nLocationMode; // 0x04
    int nTargetMode; // 0x08
};

struct D2ArenaStrc
{
    int nAlternateStartTown; // 0x00
    int nType; // 0x04
    union
    {
        unsigned int fFlags; // 0x08
        struct
        {
            unsigned char bFlag0 : 1;
            unsigned char bArenaMode : 1;
            unsigned char bUpdateClients : 1;
            unsigned char bFlag3 : 1;
            unsigned char bFlag4 : 1;
            unsigned char bTemplate : 1;
            unsigned char bFlag40 : 1;
            unsigned char bFlag80 : 1;
        };
    };
    unsigned char nTemplate; // 0x0C
    unsigned char pad0x0D; // 0x0D
    unsigned short pad0x0E; // 0x0E
};

struct D2NpcGambleStrc
{
    D2InventoryStrc* pInventory; // 0x00
    int dwGUID; // 0x04
    D2NpcGambleStrc* pNext; // 0x08
};

struct D2ObjectRegionStrc
{
    unsigned char nAct; // 0x00
    unsigned char pad0x01; // 0x01
    unsigned short pad0x02; // 0x02
    int nProcessedRooms; // 0x04
    int nPopulatedRooms; // 0x08
    int nThemedRooms; // 0x0C
    int nHealingShrines; // 0x10
    int nShrines; // 0x14
    int nWells; // 0x18
    int nTrapMonsterId; // 0x1C
    D2CoordStrc wellCoordinates[4]; // 0x20
    D2CoordStrc shrineCoordinates[10]; // 0x40
};

struct D2UnkMonCreateStrc
{
    D2GameStrc* pGame; // 0x00
    D2ActiveRoomStrc* pRoom; // 0x04
    D2RoomCoordListStrc* pRoomCoordList; // 0x08
    int nMonsterId; // 0x0C
    int nAnimMode; // 0x10
    int nUnitGUID; // 0x14
    int nX; // 0x18
    int nY; // 0x1C
    int nMaxSearchRings; // 0x20
    short nFlags; // 0x24
    unsigned short pad0x26; // 0x26
};

typedef void (__fastcall* D2EnterGameFn)(int nGameId, char* szName, int nClass, int nLevel, int nSaveFlags);
typedef void (__fastcall* FnUpdateCharacterLadder)(const char* szCharName, int nClassId, int nLevel, unsigned __int64 nExperience, unsigned int nFlags, D2FileTimeStrc* pSaveCreationTimestamp);
typedef const char* (__stdcall* FnLoadComplete)();
typedef void (__fastcall* D2LeaveGameFn)(D2ClientInfoStrc** ppClientInfo, int nGameId, int nClassId, int nLevel, __int64 nExperience, int nSaveFlags, const char* szCharName, const char* szPreview, int bUnlockCharacter, int, int, const char* szAccountName, int nCharSaveTransactionToken, int, int, int, int, int, D2FileTimeStrc* pSaveCreationTimestamp);
typedef void (__fastcall* RealmSaveCallback)(unsigned int*, const char*, char*, void*, int, unsigned int);
typedef void (__fastcall* RealmUpdateCallback)(unsigned int*, const char*, char*);

struct D2ServerCallbackFunctions
{
    void (__fastcall* pfCloseGame)(int nGameId, int nProgramId, int nLastUnitGUID, int nSeconds); // 0x00
    D2LeaveGameFn pfLeaveGame; // 0x04
    void (__fastcall* pfGetDatabaseCharacter)(D2ClientInfoStrc** ppClientInfo, const char* szCharName, int dwClientId, const char* szAccountName); // 0x08
    RealmSaveCallback pfSaveDatabaseCharacter; // 0x0C
    void* pfServerLogMessage; // 0x10
    D2EnterGameFn pfEnterGame; // 0x14
    int (__fastcall* pfFindPlayerToken)(const char* szClientName, int nTokenId, int nGameId, char* pszInOutAccountName, int* pOutCharSaveTransactionToken, int*, int*, int*, int*); // 0x18
    void* pfSaveDatabaseGuild; // 0x1C
    void (__fastcall* pfUnlockDatabaseCharacter)(D2ClientInfoStrc** ppClientInfo, const char* szCharName, const char* szAccountName); // 0x20
    void* unused0x24; // 0x24
    FnUpdateCharacterLadder pfUpdateCharacterLadder; // 0x28
    void* pfUpdateGameInformation; // 0x2C
    void* pfGetGameServerInfo; // 0x30
    int (__stdcall* pfGetValue)(); // 0x34
    RealmUpdateCallback pfUpdate; // 0x38
    FnLoadComplete pfLoadComplete; // 0x3C
    void* unused0x40; // 0x40
    void* unused0x44; // 0x44
    void* unused0x48; // 0x48
    void* unused0x4C; // 0x4C
    void* unused0x50; // 0x50
    void (__fastcall* pfGetTime)(D2FileTimeStrc* pTime); // 0x54
};

D2_CHECK_SIZE(D2ArenaStrc, 0x10);
D2_CHECK_SIZE(D2NpcGambleStrc, 0x0C);
D2_CHECK_SIZE(D2ObjectRegionStrc, 0x90);
D2_CHECK_SIZE(D2UnkMonCreateStrc, 0x28);
D2_CHECK_SIZE(D2ServerCallbackFunctions, 0x58);

struct D2UnitInfoStrc
{
    int nUnitType; // 0x00
    int nClassId; // 0x04
    int nUnitGUID; // 0x08
    int nAnimMode; // 0x0C
    int nX; // 0x10
    int nY; // 0x14
    int nOwnerType; // 0x18
    int nOwnerGUID; // 0x1C
    int unused0x20; // 0x20
    char szDescription[16]; // 0x24
};

struct D2MessageThreadArgsStrc
{
    int nParam1; // 0x00
    int nParam2; // 0x04
    char szMessage[0x100]; // 0x08
};

struct D2NPCMessageStrc
{
    int nNPCNo; // 0x00
    unsigned short nStringIndex; // 0x04
    unsigned short nPad; // 0x06
    int nMenu; // 0x08
};

struct D2ObjectRoomCoordStrc
{
    D2ActiveRoomStrc* pRoom; // 0x00
    int nX; // 0x04
    int nY; // 0x08
    D2ObjectRoomCoordStrc* pNext; // 0x0C
};

struct D2NpcConfigStrc
{
    int nClassId; // 0x00
    unsigned char bTrader; // 0x04
    unsigned char nAct; // 0x05
    unsigned char unknown06; // 0x06
    unsigned char unknown07; // 0x07
};

struct D2NpcConfigTableStrc
{
    int nCount; // 0x00
    D2NpcConfigStrc entries[64]; // 0x04
};

D2_CHECK_SIZE(D2UnitInfoStrc, 0x34);
D2_CHECK_SIZE(D2MessageThreadArgsStrc, 0x108);
D2_CHECK_SIZE(D2NPCMessageStrc, 0xC);
D2_CHECK_SIZE(D2ObjectRoomCoordStrc, 0x10);
D2_CHECK_SIZE(D2NpcConfigStrc, 0x8);
D2_CHECK_SIZE(D2NpcConfigTableStrc, 0x204);
