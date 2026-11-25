#include "D2StateIds.h"
#include "D2LevelIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2GameClient.h"
#include "D2Primitives.h"
#include "D2Constants.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Unicode.h"
#include "D2Structs.h"
#include "D2UnitData.h"
#include "D2StormTypes.h"
#include "D2Path.h"
#include "D2ClientMenus.h"
#include "D2ClientTypes.h"
#include "D2MsgRecord.h"
#include "D2MultiTypes.h"
#include "D2UnitDropPacket.h"
#include "D2Win32Message.h"

struct D2ActiveRoomStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define SKILLSFLAGINDEX_PROGRESSIVE 2

struct D2SkillsTxt;

struct D2GameStrc;

struct D2RunesTxt;

struct D2CinematicPacketStrc;

struct D2GSPacketSrv45;

struct D2GSPacketSrv4F;

struct D2GSPacketSrv54;

struct D2GSPacketSrv5E;

struct D2GSPacketSrv66;

struct D2GSPacketSrv77;

struct D2GSPacketSrv89;

struct D2GSPacketSrv8F;

struct Unicode;

struct D2WinMsgStrc;

struct D2UnitFlagsStrc;

struct D2GSPacketSrv0C;

struct D2GSPacketSrv0E;

struct D2GSPacketSrv0F;

struct D2GSPacketSrv17;

struct D2GSPacketSrv4C;

struct D2GSPacketSrv4D;

struct D2GSPacketSrv67;

struct D2GSPacketSrv68;

struct D2GSPacketSrv69;

struct D2GSPacketSrv6A;

struct D2GSPacketSrv6B;

struct D2GSPacketSrv6C;

struct D2ClientPacket7Strc;

struct D2ClientPacket6Strc;

struct D2SaveChunkPacketStrc;

struct D2ErrorPacketStrc;

struct D2GSPacketSrv01;

struct D2GSPacketSrv03;

struct D2PlayerDataStrc;

struct D2GSPacketSrv09;

struct D2GSPacketSrv0A;

struct D2GSPacketSrv0B;

struct D2GSPacketSrv51;

struct D2ItemStatCostTxt;

struct D2GSPacketSrv0D;

struct D2ClientUnitUpdateStrc;

struct D2GSPacketSrv16;

struct D2GSPacketSrv93;

struct D2GSPacketSrv27Strc;

struct D2GSPacketSrv3E;

struct D2GSPacketSrv42Strc;

struct D2GSPacketSrv74Strc;

struct D2GSPacketSrv7DStrc;

struct D2GSPacketSrv82;

struct D2GSPacketSrvA8;

struct D2GSPacketSrvAA;

struct D2GSPacketSrv10;

struct D2UnitDropItemsPacketStrc;

struct D2GSPacketSrv11;

struct D2GSPacketSrv28;

struct D2GSPacketSrv62;

struct D2GSPacketSrvA4;

struct D2GSPacketSrv21;

struct D2SkillLevelEntryStrc;

struct D2GSPacketSrv94;

struct D2GSPacketSrv22;

struct D2GSPacketSrv23;

struct D2GSPacketSrv99;

struct D2PacketRecord11Strc;

struct D2UnitStatPacketStrc;

struct D2PlayerStatPacketStrc;

struct D2UnitStatPacket2Strc;

struct D2SkillPacketStrc;

struct D2Packet18RecordStrc;

struct D2Packet95RecordStrc;

struct D2Packet96RecordStrc;

struct D2PacketBufferStrc;

struct D2PacketTableEntryStrc;

struct D2GSPacketCoordinateStrc;

struct D2GSPacketSrv2C;

struct D2GSPacketSrv59;

struct D2GSPacketSrv5B;

struct D2GSPacketSrv5C;

struct D2GSPacketSrv92;

struct D2GSPacketSrv5F;

struct D2GSPacketSrv61;

struct D2GSPacketSrv65;

struct D2GSPacketSrv75;

struct D2GSPacketSrv79;

struct D2GSPacketSrv7A;

struct D2GSPacketSrv7B;

struct D2GSPacketSrv7E;

struct D2GSPacketSrv7F;

struct D2GSPacketSrv90;

struct D2GSPacketSrv8B;

struct D2GSPacketSrv8C;

struct D2GSPacketSrv8D;

struct D2GSPacketSrv8E;

struct D2GSPacketSrv9B;

struct D2GSPacketSrv97;

struct D2GSPacketSrvA6;

struct D2GSPacketSrvA7;

struct D2GSPacketSrvA9;

union D2SeedStrc;

struct D2GSPacketSrv73;

struct D2MissileStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

typedef void (__stdcall* SMSGHANDLER)(SMSGHANDLER_PARAMS* pMsg);


struct D2UnitFlagsStrc
{
    char unk0x00[0xC8];
    unsigned int dwFlagEx;
};

struct D2GSPacketSrv0C
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char dwUnitGUID[4];
    unsigned char unk0x06;
    unsigned char nHitClass;
    unsigned char nLife;
};

struct D2GSPacketSrv0E
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char dwUnitGUID[4];
    unsigned char unk0x06;
    unsigned char unk0x07;
    unsigned char unk0x08[4];
};

struct D2GSPacketSrv0F
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char dwUnitGUID[4];
    unsigned char nFlags;
    unsigned char nDestPosX[2];
    unsigned char nDestPosY[2];
    unsigned char unk0x0B;
    unsigned char nCurrentPosX[2];
    unsigned char nCurrentPosY[2];
};

struct D2GSPacketSrv17
{
    unsigned char nHeader;
    unsigned char unk0x01[5];
    unsigned char unk0x06;
    unsigned char unk0x07;
    unsigned char unk0x08[2];
    unsigned char unk0x0A[2];
};

struct D2GSPacketSrv4C
{
    unsigned char nHeader;
    unsigned char unk0x01[5];
    unsigned char unk0x06[2];
    unsigned char unk0x08;
    unsigned char unk0x09;
    unsigned char unk0x0A[4];
};

struct D2GSPacketSrv4D
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned char unk0x02[4];
    unsigned char unk0x06[4];
    unsigned char unk0x0A;
    unsigned char unk0x0B[2];
    unsigned char unk0x0D[2];
};

struct D2GSPacketSrv67
{
    unsigned char nHeader;
    unsigned char nUnitGUID[4];
    unsigned char unk0x05;
    unsigned char nX[2];
    unsigned char nY[2];
    unsigned char unk0x0A;
    unsigned char unk0x0B;
    unsigned char nPathType;
    unsigned char nVelocity[2];
    unsigned char unk0x0F;
};

struct D2GSPacketSrv68
{
    unsigned char nHeader;
    unsigned char nUnitGUID[4];
    unsigned char unk0x05;
    unsigned char nX[2];
    unsigned char nY[2];
    unsigned char unk0x0A;
    unsigned char unk0x0B[4];
    unsigned char unk0x0F;
    unsigned char unk0x10;
    unsigned char nPathType;
    unsigned char nVelocity[2];
    unsigned char unk0x14;
};

struct D2GSPacketSrv69
{
    unsigned char nHeader;
    unsigned char unk0x01[4];
    unsigned char unk0x05;
    unsigned char unk0x06[2];
    unsigned char unk0x08[2];
    unsigned char unk0x0A;
    unsigned char unk0x0B;
};

struct D2GSPacketSrv6A
{
    unsigned char nHeader;
    unsigned char nUnitGUID[4];
    unsigned char unk0x05;
    unsigned char nTargetUnitType;
    unsigned char nTargetUnitGuid[4];
    unsigned char nDirection;
};

struct D2GSPacketSrv6B
{
    unsigned char nHeader;
    unsigned char unk0x01[4];
    unsigned char unk0x05;
    unsigned char unk0x06[2];
    unsigned char unk0x08[2];
    unsigned char unk0x0A;
    unsigned char unk0x0B;
    unsigned char unk0x0C[2];
    unsigned char unk0x0E[2];
};

struct D2GSPacketSrv6C
{
    unsigned char nHeader;
    unsigned char unk0x01[4];
    unsigned char unk0x05;
    unsigned char unk0x06;
    unsigned char unk0x07[4];
    unsigned char unk0x0B;
    unsigned char unk0x0C[2];
    unsigned char unk0x0E[2];
};

struct D2ClientPacket7Strc
{
    unsigned char nHeader;
    unsigned char nUnitGUID0;
    unsigned char nUnitGUID1;
    unsigned char nUnitGUID2;
    unsigned char nUnitGUID3;
    unsigned char nValue0;
    unsigned char nValue1;
};

struct D2ClientPacket6Strc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char nUnitGUID0;
    unsigned char nUnitGUID1;
    unsigned char nUnitGUID2;
    unsigned char nUnitGUID3;
};

extern "C" __declspec(dllimport) void __stdcall PostQuitMessage(int nExitCode); // 0x006CC4A4

extern "C" __declspec(dllimport) int __stdcall DefWindowProcA(void* hWnd, unsigned int uMsg, int wParam, int lParam); // 0x006CC488

extern "C" __declspec(dllimport) int __stdcall PeekMessageA(D2WinMsgStrc* pMsg, void* hWnd, unsigned int nMin, unsigned int nMax, unsigned int nRemove); // 0x006CC480

extern "C" __declspec(dllimport) int __stdcall GetMessageA(D2WinMsgStrc* pMsg, void* hWnd, unsigned int nMin, unsigned int nMax); // 0x006CC484

extern "C" __declspec(dllimport) int __stdcall TranslateAcceleratorA(void* hWnd, void* hAccTable, D2WinMsgStrc* pMsg); // 0x006CC4A8

extern "C" __declspec(dllimport) int __stdcall TranslateMessage(const D2WinMsgStrc* pMsg); // 0x006CC47C

extern "C" __declspec(dllimport) int __stdcall DispatchMessageA(const D2WinMsgStrc* pMsg); // 0x006CC478

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned int nMilliseconds); // 0x006CC258

extern "C" void* __cdecl memmove(void* pDst, const void* pSrc, unsigned int nSize); // 0x00683840

int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

void __cdecl SELECT_ClearSelection(); // 0x00466FE0

int __fastcall CUNIT_HasHotkeyBinding(int nA, int nB); // 0x00469D90

unsigned short __fastcall CUNIT_GetHotkeyBinding(int nA, int nB); // 0x00469AA0

void __cdecl GAME_ResetLeftClick(); // 0x0044C060

void __cdecl SELECT_UnlockHover(); // 0x00466FF0

void __cdecl TEXT_ClearListFlags(); // 0x004A01E0

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

int __cdecl WINDOW_GetWindow(); // 0x004F59A0

int __stdcall SMsgRegisterCommand(void* hWnd, int nId, SMSGHANDLER pfnHandler); // 0x00420BF0

int __stdcall SMsgRegisterKeyDown(void* hWnd, int nId, SMSGHANDLER pfnHandler); // 0x00420C10

int __stdcall SMsgRegisterKeyUp(void* hWnd, int nId, SMSGHANDLER pfnHandler); // 0x00420C30

int __stdcall SMsgRegisterMessage(void* hWnd, int nId, SMSGHANDLER pfnHandler); // 0x00420C50

int __stdcall SMsgUnregisterCommand(void* hWnd, int nId, SMSGHANDLER pfnHandler); // 0x00420C70

int __stdcall SMsgUnregisterKeyDown(void* hWnd, int nId, SMSGHANDLER pfnHandler); // 0x00420C90

int __stdcall SMsgUnregisterKeyUp(void* hWnd, int nId, SMSGHANDLER pfnHandler); // 0x00420CB0

int __stdcall SMsgUnregisterMessage(void* hWnd, int nId, SMSGHANDLER pfnHandler); // 0x00420CD0

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

Unicode* __fastcall sub_00526940_FindSubstring(const Unicode* pString, const Unicode* pPattern); // 0x00526940

void __stdcall D2Win_10130_DrawFramedTextEx(const Unicode* wszText, int nX, int nY, int nArg); // 0x005022F0

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

void __fastcall UNITMODE_SetPosition(D2UnitStrc* pUnit, unsigned short nX, unsigned short nY, int nA, int nB, int nC); // 0x004804E0

void __fastcall MONSTER_SetMinionSpawnClass(D2ClientPacket7Strc* pPacket); // 0x004B1240

void __fastcall sub_0049F8C0_UsePacket6(D2ClientPacket6Strc* pPacket); // 0x0049F8C0

extern int gbStandStillHeld; // 0x007A0664

extern int gbRunKeyHeld; // 0x007A065C

extern int gbRightButtonDown; // 0x007A0654

extern int gbRightClickConsumed; // 0x007A0670

extern int gbClickHandled; // 0x007A0658

extern void* ghAccelerators; // 0x007A0708

extern Unicode gwszPopUpText[80]; // 0x007A2C80

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

unsigned int __stdcall sub_00411020_ReadBits(D2BitBufferStrc* pBuffer, int nBits); // 0x00411020

D2ActiveRoomStrc* __cdecl CUNIT_GetPlayerRoom(); // 0x004646A0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

void __cdecl sub_00477DA0(); // 0x00477DA0

void __fastcall sub_004A40D0_StorePacket52(void* pPacket); // 0x004A40D0

#pragma pack(push, 1)
struct D2SaveChunkPacketStrc
{
    unsigned char f_0;
    unsigned char nLength;
    unsigned char bFirst;
    unsigned int nTotal;
    unsigned char aData[1];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2ErrorPacketStrc
{
    unsigned char f_0;
    int nCode;
};
#pragma pack(pop)

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

void __cdecl GAME_SaveCharFile(); // 0x0045C520

void __fastcall GAME_ShowLoadingMessage(int nError); // 0x0044E380

extern int gbGameServerReady; // 0x007A0618

#pragma pack(push, 1)
struct D2GSPacketSrv01
{
    unsigned char nHeader;
    unsigned char nDifficulty;
    unsigned int dwArenaFlags;
    unsigned char nExpansion;
    unsigned char nLadder;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv03
{
    unsigned char nHeader;
    unsigned char nAct;
    unsigned int dwGameSeed;
    unsigned short nTownLevelId;
    unsigned int nObjectSeed;
};
#pragma pack(pop)

void __fastcall GAME_SetDifficulty(unsigned char nDifficulty); // 0x0044DC70

void __fastcall GAME_SetExpansion(unsigned char nValue); // 0x0044DC80

void __fastcall GAME_SetLadderFlag(int nValue); // 0x0044DC90

void __fastcall CHAT_SetClientFlags(int nFlags); // 0x0047A9A0

void __cdecl UI_InitUI(); // 0x00456970

void __fastcall GAME_LoadAct(unsigned char nAct, unsigned int dwGameSeed, unsigned int dwObjectSeed, int nTownLevelId); // 0x0044E100

extern int gbPositionalSound; // 0x007A061C

extern int gbActUnloaded; // 0x007A0624

void __fastcall sub_00470B10_PreloadForceAct(int nAct); // 0x00470B10

#pragma pack(push, 1)
struct D2GSPacketSrv09
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned char unk0x06;
    unsigned short nPosX;
    unsigned short nPosY;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv0A
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv0B
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv51
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned short nObject;
    unsigned short nPosX;
    unsigned short nPosY;
    unsigned char unk0x0C;
    unsigned char nInteractType;
};
#pragma pack(pop)

void __cdecl GAME_FreeWeather(); // 0x0044C880

extern int gbLeavingGame; // 0x007A0620

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

int __cdecl GAME_IsCinematicExit(); // 0x0044C870

D2UnitStrc* __fastcall CUNIT_AllocClientUnit(unsigned int nUnitId, int nClassId, int nX, int nY, int nUnitType, int nArg5); // 0x004661C0

void __fastcall GFX_ResetMonsterModeGfx(D2UnitStrc* pUnit); // 0x00470B70

D2UnitStrc* __fastcall CUNIT_CreateObjectUnit(unsigned int nUnitId, int nClassId, int nX, int nY, int nUnitType, int nArg5, int nArg6, unsigned char nInteractType); // 0x00466300

int __fastcall ROSTERPETS_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int bAny); // 0x00478F20

void __fastcall CUNIT_RemoveClientSideUnit(unsigned int nUnitId, int nUnitType); // 0x00465EE0

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

void __fastcall sub_00463D90(int nArg); // 0x00463D90

void __cdecl sub_0046F360_Empty(); // 0x0046F360

enum D2C_F23Constants
{
    ITEMSTATCOSTFLAGINDEX_SIGNED = 1,
    STAT_ID_END = 0x1FF,
    STATE_ID_END = 0xFF,
};

struct D2GSPacketSrv0D
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char dwUnitGUID[4];
    unsigned char nHitClass;
    unsigned char nX[2];
    unsigned char nY[2];
    unsigned char nHitType;
    unsigned char nUnitLifePct;
};

struct D2GSPacketSrv16
{
    unsigned char nHeader;
    unsigned char nSize[2];
    unsigned char nNumUpdates;
    D2ClientUnitUpdateStrc unitUpdate[1];
};

struct D2GSPacketSrv93
{
    unsigned char nHeader;
    unsigned char nUnitGUID[4];
    unsigned char unk0x05;
    unsigned char unk0x06;
    unsigned char unk0x07;
};

struct D2GSPacketSrv27Strc
{
    int nData00;
    int nData04;
    int nData08;
    int nData0C;
    int nData10;
    int f_14;
    int nData18;
    int nData1C;
    int nData20;
    int nData24;
};

struct D2GSPacketSrv3E
{
    unsigned char nHeader;
    unsigned char nSize;
    unsigned char pBuffer[32];
};

struct D2GSPacketSrv42Strc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char nUnitGUID0;
    unsigned char nUnitGUID1;
    unsigned char nUnitGUID2;
    unsigned char nUnitGUID3;
};

struct D2GSPacketSrv74Strc
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned char unk0x02;
    unsigned char unk0x03;
    unsigned char unk0x04;
    unsigned char unk0x05;
    unsigned char unk0x06;
    unsigned char unk0x07;
    unsigned char unk0x08;
    unsigned char unk0x09;
};

struct D2GSPacketSrv7DStrc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char unk0x02;
    unsigned char unk0x03;
    unsigned char unk0x04;
    unsigned char unk0x05;
    unsigned char unk0x06;
    unsigned char unk0x07;
    unsigned char unk0x08;
    unsigned char unk0x09;
    unsigned char unk0x0A;
    unsigned char unk0x0B;
    unsigned char unk0x0C;
    unsigned char unk0x0D;
    unsigned char unk0x0E;
    unsigned char unk0x0F;
    unsigned char unk0x10;
    unsigned char unk0x11;
};

struct D2GSPacketSrv82
{
    unsigned char nHeader;
    unsigned char dwOwnerGUID[4];
    char szOwnerName[16];
    unsigned char dwPortalGUID0[4];
    unsigned char dwPortalGUID1[4];
};

struct D2GSPacketSrvA8
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char nUnitId[4];
    unsigned char nSize;
    unsigned char nState;
    unsigned char pStream[1];
};

struct D2GSPacketSrvAA
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char nUnitId[4];
    unsigned char nSize;
    unsigned char pStream[1];
};

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern void* gpBloodRemap; // 0x007BB384

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void __stdcall BITMANIP_Initialize(D2BitBufferStrc* pBuffer, unsigned char* pBitStream, int nSize); // 0x00410E40

int __stdcall BITMANIP_ReadSigned(D2BitBufferStrc* pBuffer, int nBits); // 0x00411030

int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10

int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0

int __cdecl GAME_IsExitPending(); // 0x0044DA30

int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0

int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20

void __fastcall sub_00462F60(D2GSPacketSrv74Strc* pPacket); // 0x00462F60

int __cdecl CUNIT_IsPlayerDeadOrMissing(); // 0x00463DF0

void __fastcall ROSTER_SetPortalIds(int nOwnerGUID, int nPortalGUID0, int nPortalGUID1); // 0x0047A270

void __fastcall ROSTER_SetPartyLife(int nUnitGUID, unsigned char nLifePct); // 0x0047A690

void __fastcall sub_004A1600(D2GSPacketSrv27Strc* pPacket); // 0x004A1600

void __fastcall OBJECT_SetObjectOwnerName(D2UnitStrc* pUnit, const char* szName); // 0x004BDFE0

void __fastcall ITEM_UpdateItemStat(unsigned int nA, unsigned char nB, unsigned int nC, unsigned int nD, unsigned short nE); // 0x004C1F30

void __fastcall ITEM_ClearCursorItemFromPacket(D2GSPacketSrv42Strc* pPacket); // 0x004C2050

void __fastcall ITEM_HandleItemStatePacket(D2GSPacketSrv7DStrc* pPacket); // 0x004C2270

void __fastcall SKILLS_ApplySkillLevelBonus(D2UnitStrc* pUnit, int nA, int nB, unsigned char nC); // 0x004C7990

int __fastcall MISSILE_SubmitMissileRequest(D2UnitStrc* pUnit, int nRequest, int nX, int nY, int nA, int nB); // 0x004CDB40

void __fastcall PLRSKILLS_BeginState(D2UnitStrc* pUnit, int nState); // 0x004D9B20

int __fastcall PLRSKILLS_SetStateStat(D2UnitStrc* pUnit, int nPrev, int nState, int nStatId, int nValue, int nLayer); // 0x004D9D70

void __fastcall PLRSKILLS_StartClientState(D2UnitStrc* pUnit, int nState); // 0x004D9E60

D2UnitStrc* __stdcall UNITFINDS_FindUnitInNeighboredRooms(D2ActiveRoomStrc* pRoom, int nUnitType, int nClassId); // 0x0065A620

struct D2GSPacketSrv10
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char dwUnitGUID[4];
    unsigned char nFlags;
    unsigned char nTargetType;
    unsigned char dwTargetGUID[4];
    unsigned char nCurrentPosX[2];
    unsigned char nCurrentPosY[2];
};


unsigned char __stdcall AUTOMAP_GetItemComponent(D2UnitStrc* pUnit, D2UnitStrc* pItem); // 0x00462EE0

int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820

void __fastcall GFX_ClearGfxBytes(D2UnitStrc* pUnit, int nComponent); // 0x0046F280

void __fastcall GFX_RefreshUnitGfx(D2UnitStrc* pUnit, int nArg); // 0x00470610

void __fastcall UNITMODE_SetUnitMode(D2UnitStrc* pUnit, int nArg); // 0x00480E70

void __fastcall ITEM_UpdateItemLink(D2UnitStrc* pItem, D2UnitStrc* pUnit, int bForce, int bClamp); // 0x004C0EC0

D2UnitStrc* __stdcall INVENTORY_GetFirstItem(D2InventoryStrc* pInventory); // 0x0063B2C0

D2UnitStrc* __stdcall INVENTORY_GetNextItem(D2UnitStrc* pItem); // 0x0063DFA0

int __stdcall INVENTORY_GetItemNodePage(D2UnitStrc* pItem); // 0x0063E020

D2UnitStrc* __stdcall INVENTORY_UnitIsItem(D2UnitStrc* pItem); // 0x0063DFD0

void __stdcall INVENTORY_UpdateWeaponGUIDOnRemoval(D2InventoryStrc* pInventory, D2UnitStrc* pItem); // 0x0063D2B0

unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40

unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pPath); // 0x006487F0

void __stdcall PATH_SetDirection(D2DynamicPathStrc* pPath, unsigned char nDirection); // 0x006488A0

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0

void __stdcall STATLIST_SetUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer); // 0x00627260

unsigned char* __fastcall MONUNIQUE_GetMonUmods(D2UnitStrc* pUnit); // 0x004AC740

void __fastcall QUESTS_ObjectEvents(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x005449E0

#pragma pack(push, 1)
struct D2GSPacketSrv11
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitId;
    unsigned short wOverlay;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv28
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitId;
    unsigned char nArg;
    unsigned char pBuffer[1];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv62
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitId;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrvA4
{
    unsigned char nHeader;
    unsigned short wMonsterId;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv21
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char bRemove;
    int nUnitId;
    unsigned short wSkillId;
    unsigned char nSkillLevel;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2SkillLevelEntryStrc
{
    unsigned short wSkillId;
    unsigned char nSkillLevel;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv94
{
    unsigned char nHeader;
    unsigned char nCount;
    int nUnitId;
    D2SkillLevelEntryStrc pEntries[1];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv22
{
    unsigned char nHeader;
    unsigned char unk0x01[2];
    int nUnitId;
    unsigned short wSkillId;
    unsigned char nQuantity;
    unsigned char unk0x0A;
    unsigned char bSkip;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv23
{
    unsigned char nHeader;
    unsigned char unk0x01;
    int nUnitId;
    unsigned char bLeft;
    unsigned short wSkillId;
    int nOwnerGUID;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv99
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitId;
    unsigned short f_6;
    unsigned char nArg3;
    unsigned char nTargetType;
    int f_A;
    unsigned short wArg5;
};
#pragma pack(pop)

void __fastcall CUNIT_SetOverlayWithSound(D2UnitStrc* pUnit, int nOverlay, int nArg); // 0x00464E50

void __fastcall NPCMENU_NpcInteractPacket(unsigned char nUnitType, int nUnitId, unsigned char* pBuffer, unsigned char nArg); // 0x004B6DD0

void __fastcall NPCMENU_OnUnitRemoved(unsigned char nUnitType, int nUnitId); // 0x004B5320

void __fastcall sub_004B2620(const unsigned char* pData); // 0x004B2620

void __fastcall GFX_LoadMonsterCofs(int nMonsterId, int bLoadNow); // 0x0046F870

void __stdcall SKILLS_AssignSkill(D2UnitStrc* pUnit, int nSkillId, int nSkillLevel, int bRemove, const char* szFile, int nLine); // 0x00647280

extern "C" void __cdecl INV_ClearSkillPointsHighlight(); // 0x004AA8F0

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0

void __stdcall SKILLS_SetQuantity(D2SkillStrc* pSkill, int nQuantity); // 0x00645120

void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643BC0

void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643C50

int __fastcall SKILLS_TriggerSkillOnUnit(void* pArg1, int nArg2, int nArg3, int nArg4, int nArg5); // 0x004CA200

void __fastcall CUNIT_SetUnitPosition(D2UnitStrc* pUnit, int nX, int nY, int nFlags); // 0x004654C0

int __stdcall MONSTERS_IsDead(D2UnitStrc* pUnit); // 0x0063EA40

void __stdcall PATH_SetFootprintCollisionMask(D2DynamicPathStrc* pDynamicPath, int nMask); // 0x00648C30

void __fastcall GAME_ExtendDelay(int nDelay); // 0x0044DB40

#pragma pack(push, 1)
struct D2PacketRecord11Strc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    unsigned char unk0x02;
    union
    {
        int nUnitId;
        unsigned long dwUnitId;
    };
    unsigned char unk0x07;
    unsigned char unk0x08;
    unsigned char unk0x09;
    unsigned char unk0x0A;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2UnitStatPacketStrc
{
    unsigned char nHeader;
    unsigned char nStat;
    int nUnitId;
    union
    {
        unsigned char nByte;
        unsigned short nWord;
        unsigned int nDword;
    };
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2PlayerStatPacketStrc
{
    unsigned char nHeader;
    union
    {
        unsigned char nByte;
        unsigned short nWord;
        unsigned int nDword;
        struct
        {
            unsigned char nStat;
            union
            {
                unsigned char nByte2;
                unsigned short nWord2;
                unsigned int nDword2;
            };
        };
    };
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2UnitStatPacket2Strc
{
    unsigned char nHeader;
    int nUnitId;
    unsigned char nStat;
    int nValue;
};
#pragma pack(pop)

void __fastcall ITEM_RefreshUnitItemsFromPacket(D2PacketRecord11Strc* pPacket, int nArg); // 0x004C1BC0

D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0

void __fastcall ITEM_RefreshUnitEquipment(D2UnitStrc* pUnit); // 0x004C1C10

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

#pragma pack(push, 1)
struct D2SkillPacketStrc
{
    unsigned char nHeader;
    unsigned char nMode;
    unsigned short wSkillId;
    unsigned short f_4;
    unsigned char nUnitType;
    unsigned int dwUnitId;
    unsigned char nTargetType;
    unsigned int dwTargetId;
    int nX;
    int nY;
};
#pragma pack(pop)

void __fastcall SKILLS_DoSkillPrgFunc(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel, int nX, int nY, unsigned char nMode); // 0x004C6930

void __fastcall SKILLS_DoSkill(D2UnitStrc* pUnit, D2UnitStrc* pTarget, int nSkillId, int nSkillLevel, int nX, int nY, int nMode); // 0x004C6AC0

#pragma pack(push, 1)
struct D2Packet18RecordStrc
{
    unsigned char nHeader;
    unsigned short nLife;
    unsigned short nMana;
    unsigned short nStamina;
    unsigned char nValue07;
    unsigned char nValue08;
    unsigned short nX;
    unsigned short nY;
    unsigned char nDeltaX;
    unsigned char nDeltaY;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2Packet95RecordStrc
{
    unsigned char nHeader;
    unsigned short nLife;
    unsigned short nMana;
    unsigned short nStamina;
    unsigned short nX;
    unsigned short nY;
    unsigned char nDeltaX;
    unsigned char nDeltaY;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2Packet96RecordStrc
{
    unsigned char nHeader;
    unsigned short nStamina;
    unsigned short nX;
    unsigned short nY;
    unsigned char nDeltaX;
    unsigned char nDeltaY;
};
#pragma pack(pop)

typedef void (__fastcall* D2PacketHandlerFn)(unsigned char* pPacket);

struct D2PacketTableEntryStrc
{
    D2PacketHandlerFn pfnHandler;
    int nSize;
    void* pfnAltHandler;
};

void __fastcall CUNIT_UpdateAttackableFlag(D2UnitStrc* pUnit); // 0x004647D0

D2PacketBufferStrc* __fastcall sub_00464770_GetPacketBuffer(D2UnitStrc* pUnit); // 0x00464770

void __fastcall sub_004647A0_SetPacketBuffer(D2UnitStrc* pUnit, D2PacketBufferStrc* pBuffer); // 0x004647A0

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

extern D2PacketTableEntryStrc gaPacketTable[]; // 0x007114D0

int gnPacketBytes; // 0x007A6AF4

int gnPacketBlocks; // 0x007A6AFC

int gnLargePacketBlocks; // 0x007A6B04

unsigned char gnLastPacketId; // 0x007A5234

// build: symbol _gszSCmdSourceFile 0x006D69E4
extern "C" const char gszSCmdSourceFile[];

int gnPacketRecordSize; // 0x007A5230

#pragma pack(push, 1)
struct D2GSPacketCoordinateStrc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitId;
    unsigned short f_6;
    unsigned char unk0x08[2];
    unsigned char nArg3;
    unsigned short wArg4;
    unsigned short wArg5;
    unsigned short wArg6;
};
#pragma pack(pop)

int __fastcall SKILLS_DoSkillAtPosition(void* pArg1, int nArg2, int nArg3, int nArg4, int nArg5, int nArg6); // 0x004CA230

extern "C" unsigned int __cdecl strlen(const char* szString);

#pragma pack(push, 1)
struct D2GSPacketSrv2C
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitGUID;
    unsigned short nSoundEvent;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv59
{
    unsigned char nHeader;
    unsigned int dwGUID;
    unsigned char nClass;
    char szName[16];
    unsigned short nPosX;
    unsigned short nPosY;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv5B
{
    unsigned char nHeader;
    unsigned short nPacketLen;
    int nUnitGUID;
    unsigned char nClass;
    char szName[16];
    unsigned short nLevel;
    unsigned short nPartyId;
    unsigned short unk0x1C;
    unsigned short nPartyFlags;
    unsigned short unk0x20;
    char szText[1];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv5C
{
    unsigned char nHeader;
    int dwPlayerGUID;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv92
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitGUID;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv5F
{
    unsigned char nHeader;
    int nPortalFlags;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv61
{
    unsigned char nHeader;
    unsigned char unk0x01;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv65
{
    unsigned char nHeader;
    int dwUnitId;
    unsigned short unk0x05;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv75
{
    unsigned char nHeader;
    int nUnitGUID;
    unsigned short nPartyId;
    unsigned short nLevel;
    unsigned short nFlags;
    unsigned short unk0x0B;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv79
{
    unsigned char nHeader;
    unsigned char nOwnerGUID;
    int dwGold;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv7A
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned char unk0x02;
    unsigned short unk0x03;
    int unk0x05;
    int unk0x09;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv7B
{
    unsigned char nHeader;
    unsigned char nSlot;
    unsigned short wSkill;
    int nItemGUID;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv7E
{
    unsigned char nHeader;
    unsigned char unk0x001[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv7F
{
    unsigned char nHeader;
    unsigned char bIsPlayer;
    unsigned short nLifePercentage;
    int nUnitGUID;
    unsigned short nLevelId;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv90
{
    unsigned char nHeader;
    int dwGUID;
    int dwPosX;
    int dwPosY;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv8B
{
    unsigned char nHeader;
    int nUnitGUID;
    unsigned char bParty;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv8C
{
    unsigned char nHeader;
    int dwPlayerGUID1;
    int dwPlayerGUID2;
    unsigned short nFlags;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv8D
{
    unsigned char nHeader;
    int dwPlayerGUID;
    unsigned short nPartyGUID;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv8E
{
    unsigned char nHeader;
    unsigned char nType;
    int dwPlayerGUID;
    int dwCorpseGUID;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv9B
{
    unsigned char nHeader;
    unsigned short unk0x01;
    unsigned short unk0x03;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrv97
{
    unsigned char nHeader;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrvA6
{
    unsigned char nHeader;
    unsigned char bSkip;
    unsigned char unk0x02[2];
    unsigned short nRecordId;
    unsigned char pRecord[1];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrvA7
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitId;
    unsigned char nState;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2GSPacketSrvA9
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitId;
    unsigned char nState;
};
#pragma pack(pop)

void __fastcall UNITSND_PlayEventSound(int nUnitId, unsigned char nUnitType, unsigned short nEvent); // 0x004CBDE0

D2UnitStrc* __fastcall CUNIT_CreatePlayerUnit(unsigned int nUnitId, int nClassId, int nX, int nY, char* szName); // 0x00466200

void __fastcall ROSTER_AddRosterUnit(int nUnitId, int nClassId, const char* szName, unsigned short wLevel, unsigned short wPartyId, int nUnused, int nPartyFlags, unsigned short wGuildFlags, const char* szGuildTag, const char* szGuildName); // 0x0047A6F0

void __fastcall ROSTER_RemoveRosterUnit(int nPlayerGUID); // 0x0047A8B0

void __fastcall ITEM_RemoveEquippedItems(D2UnitStrc* pUnit); // 0x004C23E0

void __stdcall UNITS_SetPlayerPortalFlags(D2UnitStrc* pUnit, int nPortalFlags); // 0x006221E0

void __fastcall sub_004B9320_PlayCinematicFromPacket(const D2CinematicPacketStrc* pPacket); // 0x004B9320

void __cdecl sub_0047F1D0_LoadResolution(); // 0x0047F1D0

void __fastcall ROSTER_SetKillCount(int nUnitId, unsigned short nValue); // 0x00479B10

void __fastcall ROSTER_UpdateRosterUnit(int nUnitId, unsigned short wPartyId, unsigned short wLevel, int nUnused, int nPartyFlags); // 0x0047A850

void __fastcall sub_004B90D0(int nGold, unsigned char nOwner); // 0x004B90D0

void __fastcall ROSTERPETS_SetRosterEntry(int nKey, int nArg, int nType, int nValue); // 0x00478B10

void __fastcall ROSTERPETS_DropPetEntry(int nKey); // 0x00478C90

void __fastcall SPELLSEL_SetHotkeySkillSlot(int nSlot, int nValueA, int nValueB, int nValueC); // 0x004AA0C0

void __fastcall GFX_LoadGlobalHashedFile(unsigned char nAct); // 0x0046F310

void __fastcall ROSTER_SetLifeAndLevel(int nUnitId, int nLife, unsigned short wLevelId); // 0x0047A0D0

void __fastcall VIEW_UpdatePetLife(int nUnitId, int nLifePercent, unsigned short nArg); // 0x00479010

void __fastcall ROSTER_SetPosition(int nUnitId, int nX, int nY); // 0x0047A100

void __fastcall ROSTER_SetPartyFlags(int nUnitId, unsigned char nFlags); // 0x0047A350

void __fastcall ROSTER_SetPvpFlags(int nUnitId1, int nUnitId2, unsigned short wFlags); // 0x0047A370

void __fastcall ROSTER_SetPartyId(int nUnitId, unsigned short wPartyId); // 0x0047A330

void __fastcall ROSTER_AddCorpse(int nUnitId, int nCorpseId); // 0x0047A3D0

void __fastcall ROSTER_DropCorpseEntry(int nUnitId, int nCorpseId); // 0x0047A490

void __fastcall NPCMENU_SetNpcMenuState(unsigned short wValue, int nValue); // 0x004B6980

extern "C" void __cdecl sub_0048A700(); // 0x0048A700

void __stdcall DATATBLS_AddOrChangeRunesTxtRecord(int nRecordId, D2RunesTxt* pRecord); // 0x00639CC0

void __fastcall PLRSKILLS_EndClientState(D2UnitStrc* pUnit, int nState); // 0x004D9F40

void __fastcall PLRSKILLS_EndState(D2UnitStrc* pUnit, int nState); // 0x004D9C30

void __cdecl sub_00473CA0_Empty(); // 0x00473CA0

void __cdecl NPCMENU_ResetSlots(); // 0x004B3290

void __fastcall sub_004B92B0_StorePacketText(const D2GSPacketSrv5E* pPacket); // 0x004B92B0

struct D2GSPacketSrv73
{
    unsigned char nHeader;
    unsigned char unk0x01[4];
    unsigned char nMissileId[2];
    unsigned char nX[4];
    unsigned char nY[4];
    unsigned char nFirstX[4];
    unsigned char nFirstY[4];
    unsigned char nCurrentFrame[2];
    unsigned char nUnitType;
    unsigned char nUnitGUID[4];
    unsigned char nLevel;
    unsigned char nPierce;
};

typedef void (__fastcall* MissileInitFunc)(D2UnitStrc* pMissile, int nArg);

D2UnitStrc* __fastcall MISSILE_CreateClientMissile(D2MissileStrc* pMissileParams); // 0x004CD540

void __stdcall UNITS_StoreOwnerTypeAndGUID(D2UnitStrc* pUnit, int nOwnerType, int nOwnerId); // 0x00621CC0

void __stdcall MISSILE_SetCurrentFrame(D2UnitStrc* pMissile, int nCurrentFrame); // 0x0064A330

unsigned int __fastcall ITEMS_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax); // 0x0045C3E0

void __fastcall sub_004B8CF0(const D2GSPacketSrv77* pPacket); // 0x004B8CF0

void __fastcall sub_004B9330_UniqueEvent(const D2GSPacketSrv89* pPacket); // 0x004B9330

void __fastcall GAME_StorePong(const D2GSPacketSrv8F* pPacket); // 0x0044CDB0

int gnPopUpTextX; // 0x007A2D20

int gnPopUpTextY; // 0x007A2D24

int gnPopUpTextMode; // 0x007A2D28

struct D2ClientSightPacketStrc;

struct D2GSPacketSrvAE;

void __fastcall sub_0044E380_SetConnectionError(int nError);

#pragma pack(push, 1)
struct D2ClientSightPacketStrc
{
    unsigned char unk0x00;
    unsigned short nX;
    unsigned short nY;
    unsigned char nLevelId;
};
#pragma pack(pop)

extern "C" void __stdcall DUNGEON_SetClientIsInSight(void* pAct, int nLevelId, int nX, int nY, void* pRoom); // 0x0061A070

extern "C" void __stdcall DUNGEON_UnsetClientIsInSight(void* pAct, int nLevelId, int nX, int nY, void* pRoom); // 0x0061A0C0

#pragma pack(push, 1)
struct D2GSPacketSrvAE
{
    unsigned char nHeader;
    unsigned short nLength;
    unsigned char pData[1];
};
#pragma pack(pop)

void __fastcall sub_004802E0(unsigned char* pData, int nLength); // 0x004802E0

int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0

void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080

extern int gnPanelOffsetX; // 0x007A2858

extern int gnScreenWidth; // 0x0071146C

extern int gnPanelOffsetY; // 0x007A285C

extern int gbPopupDismissed; // 0x007A5254

static void SCMD_ReceiveSaveChunk(D2SaveChunkPacketStrc* pPacket); // 0x0045C620

#define gnGlobal_007A7430 (gtTimedBox.nValue)

#define gnGlobal_007A7434 (gtTimedBox.nColor[0])

#define gnGlobal_007A7435 (gtTimedBox.nColor[1])

#define gnGlobal_007A7436 (gtTimedBox.nColor[2])

struct D2StaticPathStrc;

struct D2MonsterDataStrc;

struct D2UnitOverlayStrc;

struct D2HotkeyStrc;

struct D2HotkeyCommandStrc;

struct D2ByteRecordStrc;

struct D2PacketRecord6Strc;

struct D2PacketRecord7Strc;

struct D2PacketRecord8Strc;

struct D2PacketRecord13Strc;

struct D2PacketRecord15Strc;

struct D2PacketRecord21Strc;

struct D2GSPacket5AStrc;

struct D2GSPacket81Strc;

struct D2GSPacket91Strc;

struct D2Packet81ArgsStrc;

struct D2ClientTimedBoxStrc;

enum D2C_CA2Constants
{
    LEVEL_8 = 8,
    LEVEL_107 = 107,
    LEVEL_108 = 108,
    MODE_2 = 2,
    VK_MENU = 0x12,
    VK_F4 = 0x73,
    NUM_HOTKEYS = 114,
    NUM_HOTKEY_COMMANDS = 0x39,
    GRID_SIZE = 48,
};

struct D2UnitOverlayStrc
{
    int nType;
    int nId;
    int nValue;
    char unk0x0C[0x98];
    D2UnitOverlayStrc* pNext;
};




struct D2HotkeyCommandStrc
{
    void (__cdecl* pfnCommand)();
    int unk0x04;
    int nModeFlag;
};

struct D2ByteRecordStrc
{
    char unk0x00[0x25];
    unsigned char nValue0;
    unsigned char nValue1;
    unsigned char f_27;
};

struct D2GridCellStrc
{
    unsigned char unk0x00[4];
    unsigned char nValue0;
    unsigned char nValue1;
    unsigned char f_6;
    unsigned char nValue3;
};

struct D2PacketRecord6Strc
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned char unk0x02;
    unsigned char unk0x03;
    unsigned char unk0x04;
    unsigned char unk0x05;
};

struct D2PacketRecord7Strc
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned char unk0x02;
    unsigned char unk0x03;
    unsigned char unk0x04;
    unsigned char unk0x05;
    unsigned char unk0x06;
};

struct D2PacketRecord8Strc
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned char unk0x02;
    unsigned char unk0x03;
    unsigned char unk0x04;
    unsigned char unk0x05;
    unsigned char unk0x06;
    unsigned char unk0x07;
};

struct D2PacketRecord13Strc
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned char unk0x02;
    unsigned char unk0x03;
    unsigned char unk0x04;
    unsigned char unk0x05;
    unsigned char unk0x06;
    unsigned char unk0x07;
    unsigned char unk0x08;
    unsigned char unk0x09;
    unsigned char unk0x0A;
    unsigned char unk0x0B;
    unsigned char unk0x0C;
};

struct D2PacketRecord15Strc
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned char unk0x02;
    unsigned char unk0x03;
    unsigned char unk0x04;
    unsigned char unk0x05;
    unsigned char unk0x06;
    unsigned char unk0x07;
    unsigned char unk0x08;
    unsigned char unk0x09;
    unsigned char unk0x0A;
    unsigned char unk0x0B;
    unsigned char unk0x0C;
    unsigned char unk0x0D;
    unsigned char unk0x0E;
};

struct D2PacketRecord21Strc
{
    unsigned char nHeader;
    unsigned char unk0x01;
    unsigned char unk0x02;
    unsigned char unk0x03;
    unsigned char unk0x04;
    unsigned char unk0x05;
    unsigned char unk0x06;
    unsigned char unk0x07;
    unsigned char unk0x08;
    unsigned char unk0x09;
    unsigned char unk0x0A;
    unsigned char unk0x0B;
    unsigned char unk0x0C;
    unsigned char unk0x0D;
    unsigned char unk0x0E;
    unsigned char unk0x0F;
    unsigned char unk0x10;
    unsigned char unk0x11;
    unsigned char unk0x12;
    unsigned char unk0x13;
    unsigned char unk0x14;
};

struct D2GSPacket5AStrc
{
    int nData00;
    int nData04;
    int nData08;
    int nData0C;
    int nData10;
    int f_14;
    int nData18;
    int nData1C;
    int nData20;
    int nData24;
};

struct D2GSPacket81Strc
{
    unsigned char nHeader;
    unsigned char nByte01;
    unsigned short nWord02;
    int nArg04;
    int nArg08;
    int nArg0C;
    int nArg10;
};

struct D2GSPacket91Strc
{
    unsigned short nData00;
    unsigned short nData02;
    unsigned short nData04;
    unsigned short nData06;
    unsigned short nData08;
    unsigned short nData0A;
    unsigned short nData0C;
    unsigned short nData0E;
    unsigned short nData10;
    unsigned short nData12;
    unsigned short f_14;
    unsigned short nData16;
    unsigned short nData18;
};

extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(FARPROC lpfn); // 0x006CC34C

extern "C" __declspec(dllimport) short __stdcall GetKeyState(int nVirtKey); // 0x006CC45C

void __fastcall sub_0049EB10(D2GSPacket5AStrc* pPacket); // 0x0049EB10

void __fastcall NPCMENU_HandleNpcTransaction(D2PacketRecord15Strc* pPacket); // 0x004B6390

void __fastcall ITEM_HandleUseStackableItem(D2PacketRecord8Strc* pPacket); // 0x004C4620

void __fastcall ITEM_SetItemFlagFromPacket(D2PacketRecord13Strc* pPacket); // 0x004C2020

void __fastcall ITEM_RefreshUnitItemsFromRecord(D2PacketRecord11Strc* pPacket); // 0x004C1BF0

void __fastcall sub_004B9210(D2PacketRecord15Strc* pPacket); // 0x004B9210

void __fastcall sub_004B3240(D2PacketRecord7Strc* pPacket); // 0x004B3240

void __fastcall sub_004C0550(D2PacketRecord7Strc* pPacket); // 0x004C0550

void __fastcall TEXT_HandleQuestEvent(int nArg, D2PacketRecord6Strc* pPacket); // 0x004A2CB0

void __fastcall NPCMENU_FlagNpcEntries(D2GSPacket91Strc* pPacket); // 0x004B3510

void __fastcall sub_004BDF30(D2PacketRecord7Strc* pPacket); // 0x004BDF30

void __fastcall sub_0049CF90(D2PacketRecord21Strc* pPacket); // 0x0049CF90

void __fastcall sub_004B9010(D2PacketRecord21Strc* pPacket); // 0x004B9010

void __fastcall ROSTERPETS_AssignMercEntry(int nKey, int nArg, int nType, int nValue, D2Packet81ArgsStrc* pArgs); // 0x00478BB0

void __fastcall sub_004C51B0(D2PacketRecord6Strc* pPacket); // 0x004C51B0

void __fastcall NPCMENU_OnNpcWantsInteract(D2PacketRecord6Strc* pPacket); // 0x004B3380

void __cdecl GAME_ResetMouseButtons(); // 0x0044DA70

void __stdcall DUNGEON_IncreaseAlliedCountOfRoom(D2ActiveRoomStrc* pRoom); // 0x00619EE0

void __stdcall DUNGEON_DecreaseAlliedCountOfRoom(D2ActiveRoomStrc* pRoom); // 0x00619F20

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pPath); // 0x00648900

void __stdcall DUNGEON_GameSubtileToClientCoords(int* pX, int* pY); // 0x00643260

int __stdcall ROSTERPETS_GetPulseColor(unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue); // 0x0046BD50

D2GfxDataStrc* __fastcall CUNIT_GetGfxData(D2UnitStrc* pUnit); // 0x00463E10

void __stdcall ENVIRONMENT_GetLightColorFromAct(void* pAct, unsigned char* pRed, unsigned char* pGreen, unsigned char* pBlue); // 0x0061C0B0

int __stdcall ENVIRONMENT_GetIntensityFromAct(void* pAct); // 0x0061C0E0

extern int gbPopupMouseDown; // 0x007A5248

extern int gbOkCancelAccepted; // 0x007A5258

extern int gbCursorVisible; // 0x007A6B08

extern D2HotkeyStrc gtHotkeys_007A6F90[NUM_HOTKEYS]; // 0x007A6F90

extern D2HotkeyCommandStrc gaHotkeyCommands[]; // 0x00712698

extern int gnHotkeyMode; // 0x007A7418

extern int gbChaosLightEvent; // 0x007A7460

extern D2ClientTimedBoxStrc gtTimedBox; // 0x007A742C

extern D2GridCellStrc gtGridCells_007B0E68[]; // 0x007B0E68

extern unsigned char gabRowTable[][0x100]; // 0x007B5C10

extern int gdwViewEffectStartTick; // 0x007B8D10

extern int gnSentBytes; // 0x007A6AF8

extern int gnSentPackets; // 0x007A6B00

struct D2StatListStrc;

struct D2UnitStrc;

struct D2GSPacketSrv26;

struct D2EnvironmentPacketStrc;

struct D2GSPacketSrv9C;

struct D2GSPacketSrv9D;

struct D2PacketSpawnStrc;

struct D2MonStatsTxt;

struct D2MonStats2Txt;

struct D2UnitSpawnExtraStrc;

struct D2UnitSpawnStrc;

extern "C"
__declspec(noreturn)
void __cdecl exit(int nCode); // 0x00681E09

#pragma pack(push, 1)
struct D2SkillEndPacketStrc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int nUnitId;
    unsigned short nSkillId;
};
#pragma pack(pop)

void __fastcall SKILLS_EndCharge(D2UnitStrc* pUnit, int nSkillId); // 0x004CA000

void __fastcall SKILLSBAR_ResetLeapCollision(D2UnitStrc* pUnit); // 0x004C8B80

void __fastcall SKILLS_EndLoopSoundSkill(D2UnitStrc* pUnit, int nSkillId); // 0x004C9420

void __stdcall sub_00639DB0_ToggleState(D2UnitStrc* pUnit, int nState, int nEnable); // 0x00639DB0

struct D2GSPacketSrv26
{
    unsigned char nHeader;
    unsigned char nType;
    unsigned char nLang;
    unsigned char nUnitType;
    int nUnitId;
    unsigned char nColor;
    unsigned char nSubType;
    char szName[0x10];
};

struct D2ChatMessageStrc
{
    unsigned char nHeader;
    unsigned char nType;
    unsigned char f_2;
    unsigned char nUnitType;
    int nUnitId;
    unsigned char nColor;
    unsigned char nSubType;
    char szName[0x10];
    char szText[0x100];
};

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0

unsigned int __stdcall SStrLen(const char* szString); // 0x00413750

#pragma pack(push, 1)
struct D2EnvironmentPacketStrc
{
    unsigned char nHeader;
    int nIndex;
    int nTicks;
    unsigned char bEclipse;
};
#pragma pack(pop)

extern D2DrlgActStrc* gpDrlgAct_007A0634; // 0x007A0634

void __cdecl CUNIT_UpdateObjectsForPeriod(); // 0x004646C0

struct D2GSPacketSrv9C
{
    unsigned char nHeader;
    unsigned char nAction;
    unsigned char nPacketSize;
    unsigned char nComponent;
    int nItemId;
    unsigned char pBitstream[244];
};

struct D2GSPacketSrv9D
{
    unsigned char nHeader;
    unsigned char nAction;
    unsigned char nPacketSize;
    unsigned char nComponent;
    unsigned char pItemId[4];
    unsigned char nOwnerType;
    unsigned char nUnitId[4];
    unsigned char pBitstream[0xF4];
};

void __fastcall ITEM_HandleItemToCursor(D2GSPacketSrv9C* pPacket); // 0x004C20B0

void __fastcall ITEM_HandleOwnedItemToCursor(D2GSPacketSrv9D* pPacket); // 0x004C2340

void __fastcall sub_004C25B0(D2GSPacketSrv9C* pPacket); // 0x004C25B0

void __fastcall ITEM_HandleGroundToCursor(D2GSPacketSrv9C* pPacket); // 0x004C2650

void __fastcall ITEM_HandleDropToGround(D2GSPacketSrv9C* pPacket); // 0x004C26F0

void __fastcall ITEM_HandleItemOnGround(D2GSPacketSrv9C* pPacket); // 0x004C2810

void __fastcall ITEM_HandleItemToStorage(D2GSPacketSrv9C* pPacket); // 0x004C2AD0

void __fastcall ITEM_HandleItemFromStorage(D2GSPacketSrv9D* pPacket); // 0x004C2C80

void __fastcall ITEM_HandleEquipItem(D2GSPacketSrv9D* pPacket); // 0x004C2E90

void __fastcall ITEM_HandleIndirectSwapBodyItem(D2GSPacketSrv9D* pPacket); // 0x004C3070

void __fastcall ITEM_HandleUnequipItem(D2GSPacketSrv9D* pPacket); // 0x004C3380

void __fastcall ITEM_HandleSwapBodyItem(D2GSPacketSrv9D* pPacket); // 0x004C3920

void __fastcall ITEM_HandleWeaponSwitch(D2GSPacketSrv9D* pPacket); // 0x004C3B00

void __fastcall ITEM_UpdateItemFromPacket(D2GSPacketSrv9C* pPacket); // 0x004C3B30

void __fastcall ITEM_HandleShopItem(D2GSPacketSrv9C* pPacket); // 0x004C3C00

void __fastcall ITEM_HandleCursorBeltSwap(D2GSPacketSrv9C* pPacket); // 0x004C40D0

void __fastcall ITEM_HandlePutInBelt(D2GSPacketSrv9C* pPacket); // 0x004C4130

void __fastcall ITEM_HandleRemoveFromBelt(D2GSPacketSrv9C* pPacket); // 0x004C42A0

void __fastcall ITEM_HandleBeltSwap(D2GSPacketSrv9C* pPacket); // 0x004C45C0

void __fastcall ITEM_HandleAutoUnequip(D2GSPacketSrv9D* pPacket); // 0x004C4740

void __fastcall ITEM_HandleItemToSocket(D2GSPacketSrv9D* pPacket); // 0x004C4990

void __fastcall ITEM_HandleGridItemToBody(D2GSPacketSrv9D* pPacket); // 0x004C4AA0

D2UnitStrc* __fastcall ITEM_HandleBodyGridSwap(D2GSPacketSrv9D* pPacket); // 0x004C4C70

#pragma pack(push, 1)
struct D2PacketSpawnStrc
{
    unsigned char nHeader; unsigned int nUnitId; short nClassId;
    unsigned short nX, nY; unsigned char nLife, nLength; unsigned char aData[1];
};
#pragma pack(pop)

struct D2UnitSpawnExtraStrc { int nFlags, nUniqueId; };

struct D2UnitSpawnStrc { unsigned int nUnitId; int nClassId, nX, nY; D2UnitSpawnExtraStrc tExtra; int nMode; };

int __fastcall GAME_GetUnitTypeOrInvalid(D2UnitStrc*); // 0x0044BE50

int __fastcall GAME_GetUnitGUID(D2UnitStrc*); // 0x00451F50

D2UnitStrc* __fastcall CUNIT_AddClientMonster(D2UnitSpawnStrc*, unsigned char*, unsigned char*, unsigned short, int, int); // 0x00466360

void __fastcall PALSHIFT_LoadPalShift(int); // 0x00477170

D2StatListStrc* __stdcall STATLIST_AllocStatList(void* pMemPool, unsigned int fFilter, unsigned int dwTimeout, int nUnitType, int nUnitGUID); // 0x006251F0

void __stdcall STATLIST_SetState(D2StatListStrc*, int); // 0x006252D0

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitStateAndFlag(D2UnitStrc*, int, int); // 0x006257D0

void __stdcall D2COMMON_10475_PostStatToStatList(D2UnitStrc*, D2StatListStrc*, int); // 0x00626E10

void __stdcall STATLIST_SetStatIfListIsValid(D2StatListStrc*, int, int, int); // 0x00627150

int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc*); // 0x0063EE90

#pragma pack(push, 1)
#pragma pack(pop)

void __fastcall AUTOMAP_RefreshItemStats(D2UnitStrc* pUnit);                                                            // 0x0045D3E0

void __stdcall STATLIST_AddUnitStat(D2UnitStrc* pUnit, int nStatId, int nValue, int nLayer);                // 0x006272B0

static void SCMD_RefreshUnitItems(D2UnitStrc* pUnit); // 0x0045D3B0

static unsigned char* gpSaveBuffer; // 0x007A5224

static unsigned int gnSaveBufferSize; // 0x007A5228

static void SCMD_HandleServerError(D2ErrorPacketStrc* pPacket); // 0x0045C6D0

void __fastcall SCMD_HandleSystemPacket(unsigned char* pPacket, int nSize); // 0x0045C850

int gdwUnloadCompleteTick; // 0x007A0524

static void SCMD_RefreshUnitItems(D2UnitStrc* pUnit); // 0x0045D3B0

static void __stdcall SCMD_HandleStatChange(int nValue, int nStat, D2UnitStrc* pUnit); // 0x0045D4B0

void __fastcall SCMD_HandlePlayerStatUpdate(D2PlayerStatPacketStrc* pPacket); // 0x0045D780

void __fastcall SCMD_HandleAttributeUpdate(D2UnitStatPacket2Strc* pPacket); // 0x0045D880

void __fastcall SCMD_HandleMercStatUpdate(D2UnitStatPacketStrc* pPacket); // 0x0045D540

void __fastcall SCMD_ProcessPackets(unsigned char* pData, int nSize); // 0x0045F7B0

int gnViewEffectFadeIn; // 0x007B8D14

int gnViewEffectHold; // 0x007B8D18

int gnViewEffectFadeOut; // 0x007B8D1C

int gnViewEffectMagnitude; // 0x007B9534

static void SCMD_ReadVitalsUpdate(unsigned char* pData, D2Packet18RecordStrc* pRecord); // 0x0045D900

void __fastcall SCMD_HandleVitalsUpdate(unsigned char* pPacket); // 0x0045D9B0

static void SCMD_ReadVitalsAndPosition(unsigned char* pData, D2Packet95RecordStrc* pRecord); // 0x0045DA90

void __fastcall SCMD_HandleVitalsAndPosition(unsigned char* pPacket); // 0x0045DB20

static void SCMD_ReadWalkVerify(unsigned char* pData, D2Packet96RecordStrc* pRecord); // 0x0045DBE0

void __fastcall SCMD_HandleWalkVerify(unsigned char* pPacket); // 0x0045DC50

static D2PacketBufferStrc* SCMD_GrowPacketBuffer(D2UnitStrc* pUnit); // 0x0045F610

static void __stdcall SCMD_QueuePacket(unsigned char* pPacket, int nLength, D2UnitStrc* pUnit); // 0x0045F730

void __stdcall GAME_HandleActivateApp(SMSGHANDLER_PARAMS* pMsg); // 0x0044C5E0


enum { USE_RESULT = 0 };




class D2SquelchListStrc
{
public:
    virtual void Squelch(const char* szName);
    virtual void Unsquelch(const char* szName);
    virtual int IsSquelched(const char* szName);
    virtual void VirtSlot3();
    virtual void VirtSlot4();
    virtual int IsFiltered(const char* szText);
};

struct D2LaunchMsgStrc;


struct D2MsgRecordStrc;

struct D2MsgRecordChunkStrc;



int __stdcall SMsgDispatchMessage(void* hWnd, unsigned int uMessage, unsigned int wParam, int lParam, int* pUseResult, int* pResult); // 0x00420B00

int __cdecl RECORD_IsReplayActive(); // 0x00451990

void __fastcall RECORD_RecordInputMessage(unsigned int uMessage, unsigned int wParam, int lParam); // 0x004514B0



void __fastcall SCMD_RegisterMsgHandler(void* hWnd, int nType, int nId, SMSGHANDLER pfnHandler); // 0x00451C70


struct D2MsgHandlerEntryStrc;


// 0x00452090
void __stdcall SCMD_HandleResetMessage(SMSGHANDLER_PARAMS* pMsg)
{
    TEXT_ClearListFlags();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...);             // 0x006CC468

// 0x00452270
Unicode* __fastcall sub_00452270_AppendDigitText(Unicode* pText, int nValue)
{
    char szNumber[4];
    unsigned short wszNumberBuf[3];
    Unicode* wszNumber = (Unicode*)wszNumberBuf;
    D2_ASSERT(sub_00526800(pText) < 500, 0x36C);
    sub_00526700(pText, D2LANG_GetStringFromTblIndex(0xF9A));
    wszNumber[0].wChar = 0;
    wszNumber[1].wChar = 0;
    wszNumber[2].wChar = 0;
    wsprintfA(szNumber, "%c", (char)(nValue + '0'));
    Unicode::win2Unicode(wszNumber, szNumber, 2);
    sub_00526700(pText, wszNumber);
    return pText;
}

// 0x00452300
Unicode* __fastcall SCMD_StripColorCodes(Unicode* pString)
{
    D2_ASSERT(sub_00526800(pString) < 500, 0x37F);

    const Unicode* pPattern = D2LANG_GetStringFromTblIndex(0xF9A);
    const int nLength = sub_00526800(pPattern);
    Unicode* pFound = sub_00526940_FindSubstring(pString, pPattern);
    while (pFound && pFound[nLength].wChar)
    {
        memmove(pFound, &pFound[nLength + 1], sizeof(Unicode) * (sub_00526800(pFound) - nLength));
        pFound = sub_00526940_FindSubstring(pString, pPattern);
    }

    return pString;
}

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength);                  // 0x00526F20

// 0x004523A0
Unicode* __fastcall SCMD_FormatRangeText(Unicode* pText, int nFirst, int nSecond)
{
    if (pText->wChar)
    {
        D2_ASSERT(sub_00526800(pText) < 500, 0x39A);
        unsigned short wszBufferBuf[0x200];
        Unicode* wszBuffer = (Unicode*)wszBufferBuf;
        wszBuffer[0].wChar = 0;
        for (int i = 1; i < 0x200; i++)
        {
            wszBuffer[i].wChar = 0;
        }
        unsigned short wszDigitBuf[4];
        Unicode* wszDigit = (Unicode*)wszDigitBuf;
        wszDigit[0].wChar = 0;
        wszDigit[1].wChar = 0;
        wszDigit[2].wChar = 0;
        sub_005267E0(wszBuffer, D2LANG_GetStringFromTblIndex(0xF9A));
        char szDigit[4];
        wsprintfA(szDigit, "%c", (char)(nFirst + '0'));
        sub_00526F20_ToUnicode(wszDigit, szDigit, 2);
        sub_00526700(wszBuffer, wszDigit);
        sub_00526700(wszBuffer, pText);
        sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(0xF9A));
        wsprintfA(szDigit, "%c", (char)(nSecond + '0'));
        sub_00526F20_ToUnicode(wszDigit, szDigit, 2);
        sub_00526700(wszBuffer, wszDigit);
        sub_005267E0(pText, wszBuffer);
    }
    return pText;
}

// 0x004524D0
void __fastcall SCMD_SetPopUpText(const Unicode* wszText, int nA, int nB, int nC)
{
    gwszPopUpText[0].wChar = 0;
    if (wszText)
    {
        sub_005267E0(gwszPopUpText, wszText);
        gnPopUpTextX = nA;
        gnPopUpTextY = nB;
        gnPopUpTextMode = nC;
    }
}

// 0x00452510
void __stdcall SCMD_ShowPopUpText(const Unicode* wszText, int nX, int nY, int nArg)
{
    D2Win_10130_DrawFramedTextEx(wszText, nX, nY, nArg);
}

// 0x0045C300
unsigned int __fastcall SCMD_ReadVarUnsigned(D2BitBufferStrc* pBuffer)
{
    if (!sub_00411020_ReadBits(pBuffer, 1))
        return sub_00411020_ReadBits(pBuffer, 8);
    if (!sub_00411020_ReadBits(pBuffer, 1))
        return sub_00411020_ReadBits(pBuffer, 0x10);
    return sub_00411020_ReadBits(pBuffer, 0x20);
}

// 0x0045C340
unsigned int __fastcall SCMD_ReadVarUnsignedShort(D2BitBufferStrc* pBuffer)
{
    if (!sub_00411020_ReadBits(pBuffer, 1))
        return sub_00411020_ReadBits(pBuffer, 8);
    return sub_00411020_ReadBits(pBuffer, 0x10);
}

inline unsigned __int64 SEED_RollRandomNumberInline(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x0045C370
unsigned __int64 __fastcall SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = pSeed->nHighSeed + 0x6AC690C5i64 * pSeed->nLowSeed;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return lSeed;
}

// 0x0045C390
unsigned int __fastcall SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
        return 0;

    if ((nMax - 1) & nMax)
        return (unsigned int)SEED_RollRandomNumberInline(pSeed) % nMax;

    return SEED_RollRandomNumberInline(pSeed) & (nMax - 1);
}


// 0x0045C430
void __fastcall SCMD_SetUnitFlagEx(D2UnitFlagsStrc* pUnit, unsigned int dwFlag, int bSet)
{
    if (pUnit)
    {
        if (bSet)
            pUnit->dwFlagEx |= dwFlag;
        else
            pUnit->dwFlagEx &= ~dwFlag;
    }
}

// 0x0045C4E0
int __cdecl SCMD_GetSkillsTxtRecordCount()
{
    return sgptDataTables->nSkillsTxtRecordCount;
}

// 0x0045C620
static void SCMD_ReceiveSaveChunk(D2SaveChunkPacketStrc* pPacket)
{
    if (gpSaveBuffer && pPacket->bFirst)
    {
        FOG_Free(gpSaveBuffer, ".\\GAME\\SCmd.cpp", 0x5B, 0);
        gpSaveBuffer = 0;
        gnSaveBufferSize = 0;
    }

    if (!gpSaveBuffer)
        gpSaveBuffer = (unsigned char*)FOG_Alloc(pPacket->nTotal, ".\\GAME\\SCmd.cpp", 0x62, 0);

    unsigned int nSize = gnSaveBufferSize;
    unsigned char* pDest = gpSaveBuffer + nSize;
    const unsigned char* pSource = pPacket->aData;
    for (int i = 0; i < pPacket->nLength; i++)
        pDest[i] = pSource[i];

    gnSaveBufferSize += pPacket->nLength;
    if (pPacket->nTotal == gnSaveBufferSize)
    {
        GAME_SaveCharFile();
        FOG_Free(gpSaveBuffer, ".\\GAME\\SCmd.cpp", 0x71, 0);
        gpSaveBuffer = 0;
        gnSaveBufferSize = 0;
    }
}

// 0x0045C6D0
static void SCMD_HandleServerError(D2ErrorPacketStrc* pPacket)
{
    switch (pPacket->nCode)
    {
    case 1: sub_0044E380_SetConnectionError(0); return;
    case 2: sub_0044E380_SetConnectionError(1); return;
    case 3: sub_0044E380_SetConnectionError(2); return;
    case 4: sub_0044E380_SetConnectionError(3); return;
    case 5: sub_0044E380_SetConnectionError(4); return;
    case 6: sub_0044E380_SetConnectionError(5); return;
    case 7: sub_0044E380_SetConnectionError(0x0A); return;
    case 8: sub_0044E380_SetConnectionError(0x0B); return;
    case 9: sub_0044E380_SetConnectionError(0x0C); return;
    case 10: sub_0044E380_SetConnectionError(0x0D); return;
    case 11: sub_0044E380_SetConnectionError(0x0E); return;
    case 12: sub_0044E380_SetConnectionError(0x0F); return;
    case 13: sub_0044E380_SetConnectionError(0x10); return;
    case 14: sub_0044E380_SetConnectionError(0x11); return;
    case 15: sub_0044E380_SetConnectionError(0x12); return;
    case 16: sub_0044E380_SetConnectionError(0x13); return;
    case 17: sub_0044E380_SetConnectionError(0x14); return;
    case 18: sub_0044E380_SetConnectionError(0x15); return;
    case 19: sub_0044E380_SetConnectionError(0x16); return;
    case 20: sub_0044E380_SetConnectionError(0x17); return;
    case 21: sub_0044E380_SetConnectionError(0x18); return;
    case 24: sub_0044E380_SetConnectionError(0x1A); return;
    case 23: sub_0044E380_SetConnectionError(0x19); return;
    case 26: sub_0044E380_SetConnectionError(0x1C); return;
    case 25: sub_0044E380_SetConnectionError(0x1B); return;
    }
    sub_0044E380_SetConnectionError(9);
}

// 0x0045C850
void __fastcall SCMD_HandleSystemPacket(unsigned char* pPacket, int nSize)
{
    if (nSize == -1)
        return;

    switch (pPacket[0])
    {
    case 0xAF:
        gbGameServerReady = 1;
        return;
    case 0xB0:
        gbGameServerReady = 0;
        return;
    case 0xB3:
        SCMD_ReceiveSaveChunk((D2SaveChunkPacketStrc*)pPacket);
        return;
    case 0xB4:
        SCMD_HandleServerError((D2ErrorPacketStrc*)pPacket);
        return;
    }
}

// 0x0045C8B0
void __fastcall SCMD_HandleGameFlags(D2GSPacketSrv01* pPacket)
{
    const unsigned int dwArenaFlags = pPacket->dwArenaFlags;
    GAME_SetDifficulty(pPacket->nDifficulty);
    GAME_SetExpansion(pPacket->nExpansion);
    GAME_SetLadderFlag(pPacket->nLadder);
    CHAT_SetClientFlags(dwArenaFlags);
    UI_InitUI();
}

// 0x0045C920
int __cdecl SCMD_GetPlayerActNo()
{
    D2ActiveRoomStrc* pRoom = CUNIT_GetPlayerRoom();
    if (pRoom)
        return DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x527);
    exit(-1);
}

// 0x0045C960
int __fastcall SCMD_GetUnitActNo(D2UnitStrc* pUnit)
{
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (pRoom)
        return DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
    FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x538);
    exit(-1);
}

// 0x0045C9A0
void __fastcall SCMD_HandleLoadComplete(void* pPacket)
{
    gbPositionalSound = 1;
    gbActUnloaded = 0;
    D2ActiveRoomStrc* pRoom = CUNIT_GetPlayerRoom();
    if (pRoom)
    {
        sub_00470B10_PreloadForceAct(DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom)));
        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER && pPlayer->pPlayerData)
        {
            pPlayer->pPlayerData->nState = 0;
            pPlayer->pPlayerData->nMode = 0;
            pPlayer->pPlayerData->nArg1 = 0;
            pPlayer->pPlayerData->nArg2 = 0;
        }
    }
    else
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x527);
        exit(-1);
    }
}

// 0x0045CA30
void __fastcall SCMD_HandleUnloadComplete(void* pPacket)
{
    GAME_FreeWeather();
// build: symbol ?ERRORMANAGER_FreeUnusedPoolBlocks@* 0x00409B80
    ERRORMANAGER_FreeUnusedPoolBlocks(0);
    gbPositionalSound = 0;
    gbActUnloaded = 1;
    gdwUnloadCompleteTick = GetTickCount();
}

// 0x0045CA60
void __fastcall SCMD_HandleLogoutComplete(void* pPacket)
{
    if (gdwGlobal_007A0610 == 7 || gdwGlobal_007A0610 == 9)
    {
        if (!GAME_IsCinematicExit())
            GAME_ShowLoadingMessage(8);
    }
    if ((gdwGlobal_007A0610 == 2 || gdwGlobal_007A0610 == 3) && gbPositionalSound)
        GAME_ShowLoadingMessage(7);
    gbLeavingGame = 1;
}

// 0x0045CAB0
void __fastcall SCMD_HandleSetClientInSight(D2ClientSightPacketStrc* pPacket)
{
    unsigned short nX = pPacket->nX;
    unsigned short nY = pPacket->nY;
    if (!gpDrlgAct_007A0634)
    {
        FOG_DisplayHalt(&gszEmptyAssertText_006CC837, sub_00408090(), 0x58A);
        exit(-1);
    }
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    void* pRoom = pPlayer ? UNITS_GetRoom(pPlayer) : 0;
    DUNGEON_SetClientIsInSight(gpDrlgAct_007A0634, pPacket->nLevelId, nX, nY, pRoom);
}

// 0x0045CB20
void __fastcall SCMD_HandleUnsetClientInSight(D2ClientSightPacketStrc* pPacket)
{
    unsigned short nX = pPacket->nX;
    unsigned short nY = pPacket->nY;
    if (!gpDrlgAct_007A0634)
    {
        FOG_DisplayHalt(&gszEmptyAssertText_006CC837, sub_00408090(), 0x59E);
        exit(-1);
    }
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    void* pRoom = pPlayer ? UNITS_GetRoom(pPlayer) : 0;
    DUNGEON_UnsetClientIsInSight(gpDrlgAct_007A0634, pPacket->nLevelId, nX, nY, pRoom);
}

// 0x0045C8E0
void __fastcall SCMD_HandleLoadAct(D2GSPacketSrv03* pPacket)
{
    GAME_LoadAct(pPacket->nAct, pPacket->dwGameSeed, pPacket->nObjectSeed, pPacket->nTownLevelId);
}

// 0x0045C900
void __fastcall SCMD_IgnorePacket(void* pPacket)
{
}

// 0x0045C910
void __fastcall SCMD_HandleLoadSuccessful(void* pPacket)
{
    sub_00477DA0();
}

// 0x0045CB90
void __fastcall SCMD_HandleAssignWarp(D2GSPacketSrv09* pPacket)
{
    const int nUnitGUID = pPacket->dwUnitGUID;
    const unsigned short nX = pPacket->nPosX;
    const unsigned short nY = pPacket->nPosY;
    D2UnitStrc* pUnit = CUNIT_AllocClientUnit(nUnitGUID, pPacket->unk0x06, nX, nY, pPacket->nUnitType, 0);
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER)
        GFX_ResetMonsterModeGfx(pUnit);
}

// 0x0045CC50
void __fastcall SCMD_HandleGameHandshake(D2GSPacketSrv0B* pPacket)
{
    const int nUnitGUID = pPacket->dwUnitGUID;
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(nUnitGUID, pPacket->nUnitType);
    if (pUnit)
        sub_00463D90((int)pUnit);
    sub_0046F360_Empty();
}

// 0x0045CC70
void __fastcall SCMD_HandleUnitHit(D2UnitStrc* pUnit, const D2GSPacketSrv0C* pPacket)
{
    int args[7] = {};
    args[0] = pPacket->nHitClass;
    args[1] = pPacket->nLife;
    sub_00480C10_UnitEvent(pPacket->unk0x06, pUnit, args, 1);
}

// 0x0045CCC0
void __fastcall SCMD_HandlePlayerStop(D2UnitStrc* pUnit, const D2GSPacketSrv0D* pPacket)
{
    const int nUnitGUID = *(const int*)pPacket->dwUnitGUID;
    int args[7];
    args[0] = *(const unsigned short*)pPacket->nX;
    args[1] = *(const unsigned short*)pPacket->nY;
    args[2] = pPacket->nHitType;
    sub_00480C10_UnitEvent(pPacket->nHitClass, pUnit, args, 1);
    if (pPacket->nUnitType == UNIT_PLAYER)
    {
        ROSTER_SetPartyLife(nUnitGUID, pPacket->nUnitLifePct);
    }
}

// 0x0045CD10
void __fastcall SCMD_HandleObjectState(D2UnitStrc* pUnit, const D2GSPacketSrv0E* pPacket)
{
    int args[7];
    args[0] = pPacket->unk0x07;
    args[1] = *(const int*)pPacket->unk0x08;
    sub_00480C10_UnitEvent(pPacket->unk0x06, pUnit, args, 1);
}

// 0x0045CD40
void __fastcall SCMD_HandlePlayerMove(D2UnitStrc* pUnit, const D2GSPacketSrv0F* pPacket)
{
    int args[7];
    args[0] = *(const unsigned short*)pPacket->nDestPosX;
    args[1] = *(const unsigned short*)pPacket->nDestPosY;
    args[2] = pPacket->unk0x0B;
    UNITMODE_SetPosition(pUnit, *(const unsigned short*)pPacket->nCurrentPosX, *(const unsigned short*)pPacket->nCurrentPosY, 0, 0, 0);
    sub_00480C10_UnitEvent(pPacket->nFlags, pUnit, args, 1);
}

// 0x0045CD90
void __fastcall SCMD_HandlePlayerMoveToTarget(D2UnitStrc* pUnit, const D2GSPacketSrv10* pPacket)
{
    int args[7];
    args[0] = pPacket->nTargetType;
    args[1] = *(const int*)pPacket->dwTargetGUID;
    UNITMODE_SetPosition(pUnit, *(const unsigned short*)pPacket->nCurrentPosX, *(const unsigned short*)pPacket->nCurrentPosY, 0, 0, 0);
    sub_00480C10_UnitEvent(pPacket->nFlags, pUnit, args, 1);
}

// 0x0045CDE0
void __fastcall SCMD_HandleMonsterMove(D2UnitStrc* pUnit, const D2GSPacketSrv67* pPacket)
{
    int args[7];
    args[0] = *(const unsigned short*)pPacket->nX;
    args[1] = *(const unsigned short*)pPacket->nY;
    args[2] = pPacket->unk0x0A;
    args[3] = pPacket->nPathType;
    args[4] = *(const short*)pPacket->nVelocity;
    args[5] = pPacket->unk0x0F;
    args[6] = pPacket->unk0x0B;
    sub_00480C10_UnitEvent(pPacket->unk0x05, pUnit, args, 1);
}

// 0x0045CE30
void __fastcall SCMD_HandleMonsterMoveToTarget(D2UnitStrc* pUnit, const D2GSPacketSrv68* pPacket)
{
    int args[7];
    args[0] = pPacket->unk0x0A;
    args[1] = *(const int*)pPacket->unk0x0B;
    args[2] = pPacket->unk0x0F;
    args[3] = pPacket->nPathType;
    args[4] = *(const short*)pPacket->nVelocity;
    args[5] = pPacket->unk0x14;
    args[6] = pPacket->unk0x10;
    UNITMODE_SetPosition(pUnit, *(const unsigned short*)pPacket->nX, *(const unsigned short*)pPacket->nY, 0, 0, 0);
    sub_00480C10_UnitEvent(pPacket->unk0x05, pUnit, args, 1);
}

// 0x0045CEA0
void __fastcall SCMD_HandleMonsterState(D2UnitStrc* pUnit, const D2GSPacketSrv69* pPacket)
{
    int args[7];
    args[0] = *(const unsigned short*)pPacket->unk0x06;
    args[1] = *(const unsigned short*)pPacket->unk0x08;
    args[2] = pPacket->unk0x0A;
    args[3] = 2;
    args[4] = 0;
    args[5] = 4;
    args[6] = pPacket->unk0x0B;
    sub_00480C10_UnitEvent(pPacket->unk0x05, pUnit, args, 1);
}

// 0x0045CEF0
void __fastcall SCMD_HandleMonsterTargetEvent(D2UnitStrc* pUnit, const D2GSPacketSrv6A* pPacket)
{
    int args[7];
    args[0] = pPacket->nTargetUnitType;
    args[1] = *(const int*)pPacket->nTargetUnitGuid;
    args[2] = pPacket->nDirection;
    args[3] = 2;
    args[4] = 0;
    args[5] = 4;
    sub_00480C10_UnitEvent(pPacket->unk0x05, pUnit, args, 1);
}

// 0x0045CF40
void __fastcall SCMD_HandleMonsterAction(D2UnitStrc* pUnit, const D2GSPacketSrv6B* pPacket)
{
    int args[7];
    UNITMODE_SetPosition(pUnit, *(const unsigned short*)pPacket->unk0x0C, *(const unsigned short*)pPacket->unk0x0E, 0, 0, 0);
    args[0] = *(const unsigned short*)pPacket->unk0x06;
    args[1] = *(const unsigned short*)pPacket->unk0x08;
    args[2] = pPacket->unk0x0A;
    args[3] = 2;
    args[4] = 0;
    args[5] = 4;
    args[6] = pPacket->unk0x0B;
    sub_00480C10_UnitEvent(pPacket->unk0x05, pUnit, args, 1);
}

// 0x0045CFB0
void __fastcall SCMD_HandleMonsterAttack(D2UnitStrc* pUnit, const D2GSPacketSrv6C* pPacket)
{
    int args[7];
    UNITMODE_SetPosition(pUnit, *(const unsigned short*)pPacket->unk0x0C, *(const unsigned short*)pPacket->unk0x0E, 0, 0, 0);
    args[0] = pPacket->unk0x06;
    args[1] = *(const int*)pPacket->unk0x07;
    args[2] = pPacket->unk0x0B;
    args[3] = 2;
    args[4] = 0;
    args[5] = 4;
    sub_00480C10_UnitEvent(pPacket->unk0x05, pUnit, args, 1);
}

// 0x0045D0F0
void __fastcall SCMD_HandleSetOverlay(const D2GSPacketSrv11* pPacket)
{
    const int nUnitType = pPacket->nUnitType;
    const int nUnitId = pPacket->nUnitId;
    const unsigned short wOverlay = pPacket->wOverlay;
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(nUnitId, nUnitType);
    if (pUnit && wOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        CUNIT_SetOverlayWithSound(pUnit, wOverlay, 0);
    }
}

// 0x0045D130
void __fastcall sub_0045D130_PacketNop(const unsigned char* pPacket)
{
}

// 0x0045D140
void __fastcall sub_0045D140_PacketNop(const unsigned char* pPacket)
{
}

// 0x0045D150
void __fastcall sub_0045D150_PacketNop(const unsigned char* pPacket)
{
}

// 0x0045D160
void __fastcall SCMD_HandleReassignUnit(const unsigned char* pPacket)
{
    const unsigned short nX = *(const unsigned short*)(pPacket + 6);
    const unsigned short nY = *(const unsigned short*)(pPacket + 8);
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(*(const int*)(pPacket + 2), pPacket[1]);
    if (!pUnit)
        return;
    CUNIT_SetUnitPosition(pUnit, nX, nY, pPacket[0xA]);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (pRoom)
    {
        pUnit->nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
        pUnit->pDrlgAct = gpDrlgAct_007A0634;
        if (pUnit->pDynamicPath)
        {
            if (pUnit->dwUnitType == UNIT_PLAYER)
            {
                D2Common_10214(pUnit);
                PATH_SetMoveTestCollisionMask(pUnit->pDynamicPath, 0x1C09);
            }
            else if (pUnit->dwUnitType == UNIT_MONSTER && !MONSTERS_IsDead(pUnit))
            {
                PATH_SetFootprintCollisionMask(pUnit->pDynamicPath, 0x100);
            }
        }
        if (pUnit == sub_00463DD0_GetPlayerUnit())
        {
            D2_ASSERT(!DUNGEON_GetActNoFromRoom(UNITS_GetRoom(pUnit)), 0x81E);
            GAME_ExtendDelay(3000);
        }
    }
    else
    {
        D2_ASSERT(pRoom, 0x538);
    }
}

// 0x0045D2E0
void __fastcall SCMD_HandleUnitsUpdate(const D2GSPacketSrv16* pPacket)
{
    D2_ASSERT(pPacket->nNumUpdates, 2133);

    const D2ClientUnitUpdateStrc* pUpdate = pPacket->unitUpdate;
    for (int i = 0; i < pPacket->nNumUpdates; ++i)
    {
        unsigned short nX = pUpdate->nX;
        unsigned short nY = pUpdate->nY;
        D2UnitStrc* pUnit = CUNIT_FindClientUnit(pUpdate->nUnitGUID, pUpdate->nUnitType);
        if (pUnit)
        {
            UNITMODE_SetPosition(pUnit, nX, nY, 0, 0, 0);
        }
        ++pUpdate;
    }
}

// 0x0045D370
void __fastcall SCMD_HandleNpcInteract(const D2GSPacketSrv28* pPacket)
{
    NPCMENU_NpcInteractPacket(pPacket->nUnitType, pPacket->nUnitId, (unsigned char*)pPacket->pBuffer, pPacket->nArg);
}

// 0x0045D390
void __fastcall SCMD_HandleUnitRemoved(const D2GSPacketSrv62* pPacket)
{
    NPCMENU_OnUnitRemoved(pPacket->nUnitType, pPacket->nUnitId);
}

// 0x0045D3A0
void __fastcall SCMD_HandleGameQuestInfo(const unsigned char* pPacket)
{
    sub_004B2620(pPacket + 1);
}

void __fastcall OBJMODE_HandleQuestObjectEvent(D2GameStrc* pGame, D2UnitStrc* pObject)
{
    QUESTS_ObjectEvents(pGame, pObject);
}

// 0x0045D3B0
static void SCMD_RefreshUnitItems(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
        const int nUnitId = pUnit->dwUnitId;
        D2PacketRecord11Strc tPacket;
        tPacket.nHeader = 0x47;
        tPacket.nUnitType = (unsigned char)nUnitType;
        tPacket.nUnitId = nUnitId;
        ITEM_RefreshUnitItemsFromPacket(&tPacket, 0);
    }
}

// 0x0045D4B0
static void __stdcall SCMD_HandleStatChange(int nValue, int nStat, D2UnitStrc* pUnit)
{
    if (!pUnit)
        return;

    switch (nStat)
    {
    case 6:
        if (nValue && pUnit->dwAnimMode == 0x11)
        {
            UNITMODE_SetUnitMode(pUnit, 5);
            sub_004647D0(pUnit);
        }
        break;

    case 0xC:
        SCMD_RefreshUnitItems(sub_00463DD0_GetPlayerUnit());
        if (pUnit != sub_00463DD0_GetPlayerUnit())
            break;
        sub_0045D3E0(pUnit);

    case 0:
    case 2:
        ITEM_RefreshUnitEquipment(pUnit);
        break;
    }
}

// 0x0045D260
void __fastcall SCMD_HandleUnitEventAtPosition(D2UnitStrc* pUnit, const D2GSPacketSrv17* pPacket)
{
    if (pUnit != sub_00463DD0_GetPlayerUnit())
    {
        D2_ASSERT(pUnit, 0x841);

        int args[7];
        unsigned short pos[2];
        pos[0] = *(const unsigned short*)*(const unsigned short*)pPacket->unk0x08;
        pos[1] = *(const unsigned short*)*(const unsigned short*)pPacket->unk0x0A;
        args[0] = pPacket->unk0x06 >> 1;
        args[1] = (int)pos;
        sub_00480C10_UnitEvent(pPacket->unk0x07, pUnit, args, 1);
    }
}

// 0x0045D780
void __fastcall SCMD_HandlePlayerStatUpdate(D2PlayerStatPacketStrc* pPacket)
{
    const unsigned char nHeader = pPacket->nHeader;
    int nValue = 0;
    int nStat = -1;
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x9AA);

    switch (nHeader)
    {
    case 0x19:
        nStat = 0xE;
        nValue = STATLIST_UnitGetStatValue(pPlayer, nStat, 0) + pPacket->nByte;
        break;
    case 0x1A:
        nStat = 0xD;
        nValue = STATLIST_UnitGetStatValue(pPlayer, nStat, 0) + pPacket->nByte;
        break;
    case 0x1B:
        nStat = 0xD;
        nValue = STATLIST_UnitGetStatValue(pPlayer, nStat, 0) + pPacket->nWord;
        break;
    case 0x1C:
        nValue = pPacket->nDword;
        nStat = 0xD;
        break;
    case 0x1D:
        nValue = pPacket->nByte2;
        nStat = pPacket->nStat;
        break;
    case 0x1E:
        nValue = pPacket->nWord2;
        nStat = pPacket->nStat;
        break;
    case 0x1F:
        nValue = pPacket->nDword2;
        nStat = pPacket->nStat;
        break;
    }

    STATLIST_SetUnitStat(pPlayer, nStat, nValue, 0);
    SCMD_HandleStatChange(nValue, nStat, pPlayer);
}

// 0x0045D880
void __fastcall SCMD_HandleAttributeUpdate(D2UnitStatPacket2Strc* pPacket)
{
    const int nValue = pPacket->nValue;
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->nUnitId, 0);
    if (pUnit)
    {
        const int nStat = pPacket->nStat;
        STATLIST_SetUnitStat(pUnit, nStat, nValue, 0);
        SCMD_HandleStatChange(nValue, nStat, pUnit);
    }
}

// 0x0045D8C0
static void __stdcall SCMD_AddSignedByteOffsets(short nBaseY, short* pX, short* pY, short nBaseX, unsigned char nDY, unsigned char nDX)
{
    int nOffsetX = nDX;
    int nOffsetY = nDY;
    if (nOffsetX > 0x80)
        nOffsetX -= 0x100;

    if (nOffsetY > 0x80)
        nOffsetY -= 0x100;

    *pX = nBaseX + nOffsetX;
    *pY = nBaseY + nOffsetY;
}

// 0x0045CBD0
void __fastcall SCMD_HandleAssignObject(D2GSPacketSrv51* pPacket)
{
    CUNIT_CreateObjectUnit(pPacket->dwUnitGUID, pPacket->nObject, pPacket->nPosX, pPacket->nPosY, pPacket->nUnitType, 0, pPacket->unk0x0C, pPacket->nInteractType);
}

// 0x0045CC00
void __fastcall SCMD_HandleQuestLog(void* pPacket)
{
    sub_004A40D0_StorePacket52(pPacket);
}

// 0x0045CC10
void __fastcall SCMD_HandleRemoveObject(D2GSPacketSrv0A* pPacket)
{
    const int nUnitGUID = pPacket->dwUnitGUID;
    if (pPacket->nUnitType == 1 && nUnitGUID == ROSTERPETS_FindPetIdByOwner(sub_00463DD0_GetPlayerUnit(), 7, 1))
        return;
    CUNIT_RemoveClientSideUnit(nUnitGUID, pPacket->nUnitType);
}

// 0x0045D010
void __fastcall SCMD_HandleMonsterStop(D2UnitStrc* pUnit, const unsigned char* p)
{
    if (!pUnit)
        return;
    if (!p)
        return;

    const unsigned short nX = *(const unsigned short*)(p + 5);
    const unsigned short nY = *(const unsigned short*)(p + 7);
    int args[7] = { nX, nY, p[9], 2, 0, 4, 0 };
    UNITMODE_SetPosition(pUnit, nX, nY, 0, 0, 0);
    STATLIST_SetUnitStat(pUnit, STAT_PIERCE_IDX, STATLIST_GetUnitBaseStat(pUnit, STAT_PIERCE_IDX, 0) + 1, 0);
    sub_00480C10_UnitEvent(7, pUnit, args, 1);
}

// 0x0045D0A0
void __fastcall sub_0045D0A0_UnitPacketNop(D2UnitStrc* pUnit, const unsigned char* pPacket)
{
}

// 0x0045D0B0
void __fastcall sub_0045D0B0_UnitPacketNop(D2UnitStrc* pUnit, const unsigned char* pPacket)
{
}

// 0x0045D0C0
void __fastcall sub_0045D0C0_UnitPacketNop(D2UnitStrc* pUnit, const unsigned char* pPacket)
{
}

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

// 0x0045D0D0
void __fastcall sub_0045D0D0_UnitPacketNop(D2UnitStrc* pUnit, const unsigned char* pPacket)
{
}

static inline D2SkillsTxt* GetSkillRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

// 0x0045D0E0
void __fastcall sub_0045D0E0_UnitPacketNop(D2UnitStrc* pUnit, const unsigned char* pPacket)
{
}

// 0x0045D540
void __fastcall SCMD_HandleMercStatUpdate(D2UnitStatPacketStrc* pPacket)
{
    int bAdd = 0;
    int nValue;
    int nStat;
    switch (pPacket->nHeader)
    {
    case 0x9E:
        nValue = pPacket->nByte;
        nStat = pPacket->nStat;
        break;
    case 0xA0:
        nValue = pPacket->nDword;
        nStat = pPacket->nStat;
        break;
    case 0xA1:
        nValue = pPacket->nByte;
        bAdd = 1;
        nStat = pPacket->nStat;
        break;
    case 0xA2:
        bAdd = 1;

    case 0x9F:
        nValue = pPacket->nWord;
        nStat = pPacket->nStat;
        break;
    default:
        return;
    }

    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->nUnitId, 1);
    if (pUnit)
    {
        if (nStat == 0xC)
            SCMD_RefreshUnitItems(pUnit);

        if (bAdd)
            STATLIST_AddUnitStat(pUnit, nStat, nValue, 0);
        else
            STATLIST_SetUnitStat(pUnit, nStat, nValue, 0);
    }
}

// 0x0045D5E0
void __fastcall SCMD_HandleUnitSkill(D2SkillPacketStrc* pPacket)
{
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->dwUnitId, pPacket->nUnitType);
    if (!pUnit)
    {
        return;
    }

    D2UnitStrc* pTarget = CUNIT_FindClientUnit(pPacket->dwTargetId, pPacket->nTargetType);
    const int nX = pPacket->nX;
    const int nY = pPacket->nY;
    const short nSkillId = pPacket->wSkillId;
    const short nSkillLevel = pPacket->f_4;
    D2SkillsTxt* pSkillsTxtRecord = SKILLS_GetSkillsTxtRecord(nSkillId);
    if (!pSkillsTxtRecord)
    {
        return;
    }

    if (pSkillsTxtRecord->nFlags[SKILLSFLAGINDEX_PROGRESSIVE >> 3] & gdwBitMasks[SKILLSFLAGINDEX_PROGRESSIVE & 7])
    {
        SKILLS_DoSkill(pUnit, pTarget, nSkillId, nSkillLevel, nX, nY, pPacket->nMode);
    }
    else
    {
        SKILLS_DoSkillPrgFunc(pUnit, pTarget, nSkillId, nSkillLevel, nX, nY, pPacket->nMode);
    }
}

// 0x0045D6A0
void __fastcall SCMD_HandleSkillEnd(D2SkillEndPacketStrc* pPacket)
{
    D2UnitStrc* pUnit;
    const int nUnitType = pPacket->nUnitType;
    const int nUnitId = pPacket->nUnitId;
    const unsigned short nSkillId = pPacket->nSkillId;
    pUnit = CUNIT_FindClientUnit(nUnitId, nUnitType);
    if (!pUnit)
        return;
    D2SkillsTxt* pSkill = GetSkillRecord(nSkillId);
    if (!pSkill)
        return;
    switch (pSkill->wSrvDoFunc)
    {
    case 67:
        SKILLS_EndCharge(pUnit, nSkillId);
        break;
    case 77:
    case 78:
        SKILLSBAR_ResetLeapCollision(pUnit);
        break;
    case 76:
        SKILLS_EndLoopSoundSkill(pUnit, nSkillId);
        break;
    }
    sub_00639DB0_ToggleState(pUnit, 18, 0);
}

// 0x0045D760
void __fastcall SCMD_HandlePreloadMonster(const D2GSPacketSrvA4* pPacket)
{
    const unsigned short wMonsterId = pPacket->wMonsterId;
    if (wMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        GFX_LoadMonsterCofs(wMonsterId, 0);
    }
}

void __fastcall sub_U05_Emit_0045D8C0(unsigned char* pBytes, short* pBase, short* pOut)
{
    SCMD_AddSignedByteOffsets(pBase[1], &pOut[0], &pOut[1], pBase[0], pBytes[1], pBytes[0]);
    SCMD_AddSignedByteOffsets(pBase[3], &pOut[2], &pOut[3], pBase[2], pBytes[3], pBytes[2]);
}

// 0x0045D900
static void SCMD_ReadVitalsUpdate(unsigned char* pData, D2Packet18RecordStrc* pRecord)
{
    D2BitBufferStrc tBuffer;
    BITMANIP_Initialize(&tBuffer, pData, 0xF);
    pRecord->nHeader = sub_00411020_ReadBits(&tBuffer, 8);
    pRecord->nLife = sub_00411020_ReadBits(&tBuffer, 15);
    pRecord->nMana = sub_00411020_ReadBits(&tBuffer, 15);
    pRecord->nStamina = sub_00411020_ReadBits(&tBuffer, 15);
    pRecord->nValue07 = sub_00411020_ReadBits(&tBuffer, 7);
    pRecord->nValue08 = sub_00411020_ReadBits(&tBuffer, 7);
    pRecord->nX = sub_00411020_ReadBits(&tBuffer, 16);
    pRecord->nY = sub_00411020_ReadBits(&tBuffer, 16);
    pRecord->nDeltaX = sub_00411020_ReadBits(&tBuffer, 8);
    pRecord->nDeltaY = sub_00411020_ReadBits(&tBuffer, 8);
}

// 0x0045D9B0
void __fastcall SCMD_HandleVitalsUpdate(unsigned char* pPacket)
{
    D2Packet18RecordStrc tRecord;
    SCMD_ReadVitalsUpdate(pPacket, &tRecord);
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    if (!pPlayer)
    {
        return;
    }
    int nLife = tRecord.nLife << 8;
    STATLIST_SetUnitStat(pPlayer, STAT_HITPOINTS, nLife, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_MANA, tRecord.nMana << 8, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_STAMINA, tRecord.nStamina << 8, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_HPREGEN, tRecord.nValue07, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_MANARECOVERY, tRecord.nValue08, 0);
    int nDeltaX = tRecord.nDeltaX;
    int nDeltaY = tRecord.nDeltaY;
    if (nDeltaX > 0x80) nDeltaX -= 0x100;
    if (nDeltaY > 0x80) nDeltaY -= 0x100;
    UNITMODE_SetPosition(pPlayer, tRecord.nX, tRecord.nY, 0, (unsigned short)(tRecord.nX + nDeltaX), (unsigned short)(tRecord.nY + nDeltaY));
    if (nLife && pPlayer->dwAnimMode == 0x11)
    {
        UNITMODE_SetUnitMode(pPlayer, 5);
        CUNIT_UpdateAttackableFlag(pPlayer);
    }
}

// 0x0045DA90
static void SCMD_ReadVitalsAndPosition(unsigned char* pData, D2Packet95RecordStrc* pRecord)
{
    D2BitBufferStrc tBuffer;
    BITMANIP_Initialize(&tBuffer, pData, 0xD);
    pRecord->nHeader = sub_00411020_ReadBits(&tBuffer, 8);
    pRecord->nLife = sub_00411020_ReadBits(&tBuffer, 15);
    pRecord->nMana = sub_00411020_ReadBits(&tBuffer, 15);
    pRecord->nStamina = sub_00411020_ReadBits(&tBuffer, 15);
    pRecord->nX = sub_00411020_ReadBits(&tBuffer, 16);
    pRecord->nY = sub_00411020_ReadBits(&tBuffer, 16);
    pRecord->nDeltaX = sub_00411020_ReadBits(&tBuffer, 8);
    pRecord->nDeltaY = sub_00411020_ReadBits(&tBuffer, 8);
}

// 0x0045DB20
void __fastcall SCMD_HandleVitalsAndPosition(unsigned char* pPacket)
{
    D2Packet95RecordStrc tRecord;
    SCMD_ReadVitalsAndPosition(pPacket, &tRecord);
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    if (!pPlayer)
    {
        return;
    }
    int nLife = tRecord.nLife << 8;
    STATLIST_SetUnitStat(pPlayer, STAT_HITPOINTS, nLife, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_MANA, tRecord.nMana << 8, 0);
    STATLIST_SetUnitStat(pPlayer, STAT_STAMINA, tRecord.nStamina << 8, 0);
    int nDeltaX = tRecord.nDeltaX;
    int nDeltaY = tRecord.nDeltaY;
    if (nDeltaX > 0x80) nDeltaX -= 0x100;
    if (nDeltaY > 0x80) nDeltaY -= 0x100;
    UNITMODE_SetPosition(pPlayer, tRecord.nX, tRecord.nY, 0, (unsigned short)(tRecord.nX + nDeltaX), (unsigned short)(tRecord.nY + nDeltaY));
    if (nLife && pPlayer->dwAnimMode == 0x11)
    {
        UNITMODE_SetUnitMode(pPlayer, 5);
        CUNIT_UpdateAttackableFlag(pPlayer);
    }
}

// 0x0045DBE0
static void SCMD_ReadWalkVerify(unsigned char* pData, D2Packet96RecordStrc* pRecord)
{
    D2BitBufferStrc tBuffer;
    BITMANIP_Initialize(&tBuffer, pData, 9);
    pRecord->nHeader = sub_00411020_ReadBits(&tBuffer, 8);
    pRecord->nStamina = sub_00411020_ReadBits(&tBuffer, 15);
    pRecord->nX = sub_00411020_ReadBits(&tBuffer, 16);
    pRecord->nY = sub_00411020_ReadBits(&tBuffer, 16);
    pRecord->nDeltaX = sub_00411020_ReadBits(&tBuffer, 8);
    pRecord->nDeltaY = sub_00411020_ReadBits(&tBuffer, 8);
}

// 0x0045DC50
void __fastcall SCMD_HandleWalkVerify(unsigned char* pPacket)
{
    D2Packet96RecordStrc tRecord;
    SCMD_ReadWalkVerify(pPacket, &tRecord);
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    if (!pPlayer)
    {
        return;
    }
    STATLIST_SetUnitStat(pPlayer, STAT_STAMINA, tRecord.nStamina << 8, 0);
    int nDeltaX = tRecord.nDeltaX;
    int nDeltaY = tRecord.nDeltaY;
    if (nDeltaX > 0x80) nDeltaX -= 0x100;
    if (nDeltaY > 0x80) nDeltaY -= 0x100;
    UNITMODE_SetPosition(pPlayer, tRecord.nX, tRecord.nY, 0, (unsigned short)(tRecord.nX + nDeltaX), (unsigned short)(tRecord.nY + nDeltaY));
}

// 0x0045DCD0
void __fastcall SCMD_HandleAssignSkill(const D2GSPacketSrv21* pPacket)
{
    const unsigned short wSkillId = pPacket->wSkillId;
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->nUnitId, pPacket->nUnitType);
    if (pUnit)
    {
        SKILLS_AssignSkill(pUnit, wSkillId, pPacket->nSkillLevel, pPacket->bRemove, ".\\GAME\\SCmd.cpp", 2700);
        INV_ClearSkillPointsHighlight();
    }
}

// 0x0045F7A0
void __stdcall sub_0045F7A0(int nUnused1, int nUnused2)
{
}

// 0x0045F9F0
void __fastcall SCMD_FreePacketBuffer(D2UnitStrc* pUnit)
{
    D2PacketBufferStrc* pBuffer = sub_00464770_GetPacketBuffer(pUnit);
    if (pBuffer)
    {
        FOG_Free(pBuffer->pData, ".\\GAME\\SCmd.cpp", 0x1516, 0);
        FOG_Free(pBuffer, ".\\GAME\\SCmd.cpp", 0x1517, 0);
        sub_004647A0_SetPacketBuffer(pUnit, 0);
    }
}




// 0x00462F60
void __fastcall SCMD_DropUnitItems(D2UnitDropItemsPacketStrc* pPacket)
{
    if (!pPacket->bActive)
        return;
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(*(int*)pPacket->nUnitId, 0);
    if (!pUnit)
        return;
    if (!CUNIT_IsDeadOrDying(pUnit))
        UNITMODE_SetUnitMode(pUnit, 0);
    if (pUnit == sub_00463DD0_GetPlayerUnit())
    {
        D2UnitStrc* pOther = CUNIT_FindClientUnit(*(int*)pPacket->nOtherUnitId, 0);
        if (!pOther)
            return;
        D2DynamicPathStrc* pPath = pOther->pDynamicPath;
        PATH_SetMoveTestCollisionMask(pPath, 0);
        sub_00649190_SetPathMode(pOther, 5);
        D2_ASSERT(sub_00650BE0_PlaceUnit(pPath, pOther, UNITS_GetRoom(pUnit), CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit)), 0xABA);
        PATH_SetDirection(pOther->pDynamicPath, PATH_GetDirection(pUnit->pDynamicPath));
    }
    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pItem = INVENTORY_GetFirstItem(pInventory);
    while (pItem)
    {
        D2UnitStrc* pNext = INVENTORY_GetNextItem(pItem);
        if (INVENTORY_GetItemNodePage(pItem) == 3)
        {
            pItem = INVENTORY_UnitIsItem(pItem);
            INVENTORY_UpdateWeaponGUIDOnRemoval(pInventory, pItem);
            GFX_ClearGfxBytes(pUnit, AUTOMAP_GetItemComponent(pUnit, pItem));
            D2UnitStrc* pRemoved = INVENTORY_RemoveItemFromInventory(pInventory, pItem);
            D2_ASSERT(pRemoved, 0xAC8);
            D2_ASSERT(pRemoved == pItem, 0xAC9);
            ITEM_UpdateItemLink(pItem, pUnit, 0, 0);
            sub_0063BE30(pInventory, ITEMS_GetBodyLocation(pItem));
            GFX_RefreshUnitGfx(pUnit, 0);
            const int nUnitType = !pItem ? 6 : pItem->dwUnitType;
            const int nUnitId = !pItem ? -1 : pItem->dwUnitId;
            CUNIT_RemoveClientSideUnit(nUnitId, nUnitType);
        }
        pItem = pNext;
    }
}

// 0x004689D0
void __cdecl SCMD_ShowHelpOnce()
{
    if (GAME_IsExitPending())
        return;
    if (CUNIT_IsPlayerDeadOrMissing())
        return;

    UI_SetUIVar(0x21, 2, 0);
    unsigned long dwValue;
    if (!SRegLoadValue("Diablo II", "Help Menu", 1, &dwValue) || !dwValue)
    {
        dwValue = 1;
        SRegSaveValue("Diablo II", "Help Menu", 1, dwValue);
    }
}



// 0x0045DDB0
void __fastcall SCMD_HandleSetSkillQuantity(const D2GSPacketSrv22* pPacket)
{
    if (pPacket->bSkip)
    {
        return;
    }
    const unsigned short wSkillId = pPacket->wSkillId;
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->nUnitId, 0);
    if (pUnit)
    {
        D2SkillStrc* pSkill = SKILLS_GetSkillById(pUnit, wSkillId, -1);
        D2_ASSERT(pSkill, 2774);
        SKILLS_SetQuantity(pSkill, pPacket->nQuantity);
    }
}

// 0x0045DE10
void __fastcall SCMD_HandleSetActiveSkill(const D2GSPacketSrv23* pPacket)
{
    const unsigned short wSkillId = pPacket->wSkillId;
    const int nOwnerGUID = pPacket->nOwnerGUID;
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->nUnitId, 0);
    if (pUnit)
    {
        if (pPacket->bLeft)
        {
            SKILLS_SetLeftActiveSkill(pUnit, wSkillId, nOwnerGUID);
        }
        else
        {
            SKILLS_SetRightActiveSkill(pUnit, wSkillId, nOwnerGUID);
        }
    }
}

// 0x0045DE50
void __fastcall SCMD_HandleSetMinionClass(const D2ClientPacket7Strc* pPacket)
{
    D2ClientPacket7Strc tPacket = *pPacket;
    MONSTER_SetMinionSpawnClass(&tPacket);
}

// 0x0045DE80
void __fastcall SCMD_HandleTriggerSkillOnUnit(const D2GSPacketSrv99* pPacket)
{
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->nUnitId, pPacket->nUnitType);
    if (pUnit)
    {
        D2UnitStrc* pTarget = CUNIT_FindClientUnit(pPacket->f_A, pPacket->nTargetType);
        if (pTarget)
        {
            SKILLS_TriggerSkillOnUnit(pUnit, pPacket->f_6, pPacket->nArg3, (int)pTarget, pPacket->wArg5);
        }
    }
}

// 0x0045DEC0
void __fastcall SCMD_HandleTriggerSkillAtPosition(const D2GSPacketCoordinateStrc* pPacket)
{
    D2UnitStrc* pUnit=CUNIT_FindClientUnit(pPacket->nUnitId,pPacket->nUnitType);
    if(pUnit)
        SKILLS_DoSkillAtPosition(pUnit,pPacket->f_6,pPacket->nArg3,pPacket->wArg4,pPacket->wArg5,pPacket->wArg6);
}

// 0x0045DF00
void __fastcall SCMD_HandleUnitCastOnTarget(D2UnitStrc* pUnit, const D2GSPacketSrv4C* pPacket)
{
    if (pUnit)
    {
        int args[7] = {};
        args[0] = *(const unsigned short*)pPacket->unk0x06;
        args[2] = pPacket->unk0x09;
        args[3] = *(const int*)pPacket->unk0x0A;
        args[4] = pPacket->unk0x08;
        args[1] = -1;
        sub_00480C10_UnitEvent(0x16, pUnit, args, 1);
    }
}

// 0x0045DF60
void __fastcall SCMD_HandleUnitCastAtPosition(D2UnitStrc* pUnit, const D2GSPacketSrv4D* pPacket)
{
    if (pUnit)
    {
        int args[7] = {};
        args[0] = *(const int*)pPacket->unk0x06;
        args[2] = *(const unsigned short*)pPacket->unk0x0B;
        args[3] = *(const unsigned short*)pPacket->unk0x0D;
        args[4] = pPacket->unk0x0A;
        args[1] = -1;
        sub_00480C10_UnitEvent(0x15, pUnit, args, 1);
    }
}

// 0x0045DFC0
void __fastcall SCMD_HandleChatMessage(const D2GSPacketSrv26* pPacket)
{
    D2ChatMessageStrc tMessage;
    const char* szName = pPacket->szName;
    tMessage.nHeader = pPacket->nHeader;
    tMessage.nType = pPacket->nType;
    tMessage.f_2 = pPacket->nLang;
    tMessage.nUnitType = pPacket->nUnitType;
    tMessage.nUnitId = pPacket->nUnitId;
    tMessage.nColor = pPacket->nColor;
    tMessage.nSubType = pPacket->nSubType;
    SStrCopy(tMessage.szName, szName, 0x10);
    szName += SStrLen(szName) + 1;
    SStrCopy(tMessage.szText, szName, 0x100);
    sub_0049F490_PrintChatMessage(&tMessage);
}

// 0x0045E0A0
void __fastcall SCMD_HandleHoverText(const D2GSPacketSrv27Strc* pPacket)
{
    D2GSPacketSrv27Strc tPacket = *pPacket;
    sub_004A1600(&tPacket);
}

// 0x0045E0D0
void __fastcall SCMD_HandleNpcTransaction(const D2PacketRecord15Strc* pPacket)
{
    D2PacketRecord15Strc tPacket = *pPacket;
    NPCMENU_HandleNpcTransaction(&tPacket);
}

// 0x0045E110
void __fastcall SCMD_HandlePlaySound(const D2GSPacketSrv2C* pPacket)
{
    UNITSND_PlayEventSound(pPacket->dwUnitGUID, pPacket->nUnitType, pPacket->nSoundEvent);
}

// 0x0045E130
void __fastcall SCMD_HandleItemStatUpdate(D2GSPacketSrv3E* pPacket)
{
    D2BitBufferStrc tBuffer;
    BITMANIP_Initialize(&tBuffer, pPacket->pBuffer, pPacket->nSize - 2);

    unsigned int nA;
    if (!sub_00411020_ReadBits(&tBuffer, 1))
        nA = sub_00411020_ReadBits(&tBuffer, 8);
    else if (!sub_00411020_ReadBits(&tBuffer, 1))
        nA = sub_00411020_ReadBits(&tBuffer, 16);
    else
        nA = sub_00411020_ReadBits(&tBuffer, 32);

    const unsigned char nB = sub_00411020_ReadBits(&tBuffer, 1);
    const unsigned int nC = sub_00411020_ReadBits(&tBuffer, 9);

    unsigned int nD;
    if (!sub_00411020_ReadBits(&tBuffer, 1))
        nD = sub_00411020_ReadBits(&tBuffer, 8);
    else if (!sub_00411020_ReadBits(&tBuffer, 1))
        nD = sub_00411020_ReadBits(&tBuffer, 16);
    else
        nD = sub_00411020_ReadBits(&tBuffer, 32);

    unsigned short nE;
    if (!sub_00411020_ReadBits(&tBuffer, 1))
        nE = sub_00411020_ReadBits(&tBuffer, 8);
    else
        nE = sub_00411020_ReadBits(&tBuffer, 16);

    ITEM_UpdateItemStat(nA, nB, nC, nD, nE);
}

// 0x0045E220
void __fastcall SCMD_HandleUseStackableItem(const D2PacketRecord8Strc* pPacket)
{
    D2PacketRecord8Strc tPacket = *pPacket;
    ITEM_HandleUseStackableItem(&tPacket);
}

// 0x0045E240
void __fastcall SCMD_HandleSetItemFlag(const D2PacketRecord13Strc* pPacket)
{
    D2PacketRecord13Strc tPacket = *pPacket;
    ITEM_SetItemFlagFromPacket(&tPacket);
}

// 0x0045E270
void __fastcall SCMD_HandleClearCursor(const D2GSPacketSrv42Strc* pPacket)
{
    D2GSPacketSrv42Strc tPacket = *pPacket;
    ITEM_ClearCursorItemFromPacket(&tPacket);
}

// 0x0045E290
void __fastcall SCMD_Packet45(const D2GSPacketSrv45* pPacket)
{
}

// 0x0045E2A0
void __fastcall SCMD_HandleRefreshItems(const D2PacketRecord11Strc* pPacket)
{
    D2PacketRecord11Strc tPacket = *pPacket;
    ITEM_RefreshUnitItemsFromPacket(&tPacket, 1);
}

// 0x0045E2D0
void __fastcall SCMD_HandleRefreshItemsRecord(const D2PacketRecord11Strc* pPacket)
{
    D2PacketRecord11Strc tPacket = *pPacket;
    ITEM_RefreshUnitItemsFromRecord(&tPacket);
}

// 0x0045E300
void __fastcall SCMD_HandleInitEnvironment(D2EnvironmentPacketStrc* pPacket)
{
    const int nIndex = pPacket->nIndex;
    const int nTicks = pPacket->nTicks;
    if (gpDrlgAct_007A0634 == sub_00463DD0_GetPlayerUnit()->pDrlgAct)
    {
        ENVIRONMENT_InitializeEnvironment(gpDrlgAct_007A0634, CUNIT_GetPlayerRoom(), nIndex, nTicks, pPacket->bEclipse);
        CUNIT_UpdateObjectsForPeriod();

        D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
        if (pPlayer)
        {
            D2PacketRecord11Strc tPacket;
            const int nUnitType = !pPlayer ? 6 : pPlayer->dwUnitType;
            tPacket.nUnitType = (unsigned char)nUnitType;
            tPacket.dwUnitId = !pPlayer ? -1 : pPlayer->dwUnitId;
            tPacket.nHeader = 0x47;
            ITEM_RefreshUnitItemsFromPacket(&tPacket, 0);
        }
    }
}

// 0x0045E370
void __fastcall SCMD_HandleUiPacket(const D2PacketRecord15Strc* pPacket)
{
    D2PacketRecord15Strc tPacket = *pPacket;
    sub_004B9210(&tPacket);
}

// 0x0045E3B0
void __fastcall SCMD_Packet54(const D2GSPacketSrv54* pPacket)
{
    sub_00473CA0_Empty();
}

// 0x0045E3C0
void __fastcall SCMD_HandleClearMercList(const D2GSPacketSrv4F* pPacket)
{
    NPCMENU_ResetSlots();
}

// 0x0045E3D0
void __fastcall SCMD_HandleMercForHire(const D2PacketRecord7Strc* pPacket)
{
    D2PacketRecord7Strc tPacket = *pPacket;
    sub_004B3240(&tPacket);
}

// 0x0045E400
void __fastcall SCMD_HandleMonsterEnchants(const unsigned char* p)
{
    const int nId = *(const int*)(p + 1);
    const unsigned short n6 = *(const unsigned short*)(p + 6);
    const unsigned short n8 = *(const unsigned short*)(p + 8);
    const unsigned short nA = *(const unsigned short*)(p + 0xA);
    const unsigned short nC = *(const unsigned short*)(p + 0xC);
    if (p[5] == 1)
    {
        D2UnitStrc* pUnit = CUNIT_FindClientUnit(nId, 1);
        if (pUnit)
        {
            sub_004AC780_SetMonsterWord(pUnit, n6);
            unsigned char* pBytes = MONUNIQUE_GetMonUmods(pUnit);
            pBytes[0] = (unsigned char)n8;
            pBytes[1] = (unsigned char)(n8 >> 8);
            pBytes[2] = (unsigned char)nA;
            if (nC)
            {
                sub_004AC810_ToggleMonsterFlag(pUnit, 4, 1);
            }
            sub_004AC810_ToggleMonsterFlag(pUnit, 8, 1);
            sub_004AD020_RefreshMonster(pUnit);
        }
    }
}

// 0x0045E490
void __fastcall SCMD_HandleOpenPanel(const D2PacketRecord7Strc* pPacket)
{
    D2PacketRecord7Strc tPacket = *pPacket;
    sub_004C0550(&tPacket);
}

// 0x0045E4C0
void __fastcall SCMD_HandleAssignPlayer(const D2GSPacketSrv59* pPacket)
{
    CUNIT_CreatePlayerUnit(pPacket->dwGUID, pPacket->nClass, pPacket->nPosX, pPacket->nPosY, (char*)pPacket->szName);
}

// 0x0045E070
void __fastcall SCMD_HandleEventMessage(const D2GSPacket5AStrc* pPacket)
{
    D2GSPacket5AStrc tPacket = *pPacket;
    sub_0049EB10(&tPacket);
}

// 0x0045E4E0
void __fastcall SCMD_HandlePlayerJoined(const D2GSPacketSrv5B* pPacket)
{
    const char* szText = pPacket->szText;
    ROSTER_AddRosterUnit(pPacket->nUnitGUID, pPacket->nClass, pPacket->szName, pPacket->nLevel, pPacket->nPartyId, pPacket->unk0x1C,
                 pPacket->nPartyFlags, pPacket->unk0x20, szText, szText + strlen(szText) + 1);
}

// 0x0045E530
void __fastcall SCMD_HandlePlayerLeft(const D2GSPacketSrv5C* pPacket)
{
    ROSTER_RemoveRosterUnit(pPacket->dwPlayerGUID);
}

// 0x0045E540
void __fastcall SCMD_HandleQuestEvent(const D2PacketRecord6Strc* pPacket)
{
    D2PacketRecord6Strc tPacket = *pPacket;
    TEXT_HandleQuestEvent(1, &tPacket);
}

// 0x0045E570
void __fastcall SCMD_HandleStoreText(const D2GSPacketSrv5E* pPacket)
{
    sub_004B92B0_StorePacketText(pPacket);
}

// 0x0045E580
void __fastcall SCMD_HandleNpcGossipList(const D2GSPacket91Strc* pPacket)
{
    D2GSPacket91Strc tPacket = *pPacket;
    NPCMENU_FlagNpcEntries(&tPacket);
}

// 0x0045E5B0
void __fastcall SCMD_HandleRemoveEquippedItems(const D2GSPacketSrv92* pPacket)
{
    const int nUnitGUID = pPacket->nUnitGUID;
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(nUnitGUID, pPacket->nUnitType);
    if (pUnit)
    {
        ITEM_RemoveEquippedItems(pUnit);
    }
}

// 0x0045E5D0
void __fastcall SCMD_HandleSetPortalFlags(const D2GSPacketSrv5F* pPacket)
{
    const int nPortalFlags = pPacket->nPortalFlags;
    D2UnitStrc* pPlayer = sub_00463DE0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 3349);
    UNITS_SetPlayerPortalFlags(pPlayer, nPortalFlags);
}

// 0x0045E610
void __fastcall SCMD_HandleTownPortalState(const D2PacketRecord7Strc* pPacket)
{
    D2PacketRecord7Strc tPacket = *pPacket;
    D2_ASSERT(sub_00463DE0_GetPlayerUnit(), 3361);
    sub_004BDF30(&tPacket);
}

// 0x0045E660
void __fastcall SCMD_HandlePlayCinematic(const D2GSPacketSrv61* pPacket)
{
    sub_004B9320_PlayCinematicFromPacket((const D2CinematicPacketStrc*)pPacket);
    sub_0047F1D0_LoadResolution();
}

// 0x0045E670
void __fastcall SCMD_HandleWaypointMenu(const D2PacketRecord21Strc* pPacket)
{
    D2PacketRecord21Strc tPacket = *pPacket;
    sub_0049CF90(&tPacket);
}

// 0x0045E6B0
void __fastcall SCMD_HandleKillCount(const D2GSPacketSrv65* pPacket)
{
    ROSTER_SetKillCount(pPacket->dwUnitId, pPacket->unk0x05);
}

// 0x0045E6C0
void __fastcall SCMD_Packet66(const D2GSPacketSrv66* pPacket)
{
}

// 0x0045E6D0
void __fastcall SCMD_HandleCreateMissile(const D2GSPacketSrv73* pPacket)
{
    const int nX = *(const int*)pPacket->nX;
    const int nY = *(const int*)pPacket->nY;
    const int nFirstX = *(const int*)pPacket->nFirstX;
    const int nFirstY = *(const int*)pPacket->nFirstY;
    const unsigned short nCurrentFrame = *(const unsigned short*)pPacket->nCurrentFrame;
    const unsigned short nMissileId = *(const unsigned short*)pPacket->nMissileId;
    const int nUnitGUID = *(const int*)pPacket->nUnitGUID;

    D2UnitStrc* pOwner = sub_00463DE0_GetPlayerUnit();
    D2MissileStrc tMissileParams;
    memset(&tMissileParams, 0, sizeof(tMissileParams));
    tMissileParams.pOwner = pOwner;
    tMissileParams.dwFlags = 0x40000001;
    tMissileParams.nX = nX;
    tMissileParams.nY = nY;
    tMissileParams.nSkillLevel = pPacket->nLevel;
    tMissileParams.nMissile = nMissileId;
    if (nFirstX && nFirstY)
    {
        tMissileParams.dwFlags = 0x40000021;
        tMissileParams.nTargetX = nFirstX;
        tMissileParams.nTargetY = nFirstY;
    }

    D2UnitStrc* pMissile = MISSILE_CreateClientMissile(&tMissileParams);
    if (pMissile)
    {
        UNITS_StoreOwnerTypeAndGUID(pMissile, pPacket->nUnitType, nUnitGUID);
        if (pPacket->nPierce)
            STATLIST_SetUnitStat(pMissile, STAT_PIERCE_IDX, pPacket->nPierce, 0);

        MISSILE_SetCurrentFrame(pMissile, nCurrentFrame);
        pMissile->nSeqCurrentFramePrecise = ITEMS_RollLimitedRandomNumber(&pMissile->pSeed, pMissile->dwFrameCountPrecise >> 8) << 8;
    }
}

// 0x0045E7B0
void __fastcall SCMD_HandlePlayerCorpse(const D2GSPacketSrv74Strc* pPacket)
{
    D2GSPacketSrv74Strc tPacket = *pPacket;
    sub_00462F60(&tPacket);
}

// 0x0045E7E0
void __fastcall SCMD_HandleRosterUpdate(const D2GSPacketSrv75* pPacket)
{
    ROSTER_UpdateRosterUnit(pPacket->nUnitGUID, pPacket->nPartyId, pPacket->nLevel, pPacket->nFlags, pPacket->unk0x0B);
}

// 0x0045E800
void __fastcall SCMD_HandleTradeAction(const D2GSPacketSrv77* pPacket)
{
    sub_004B8CF0(pPacket);
}

// 0x0045E810
void __fastcall SCMD_HandleTradePartnerName(const D2PacketRecord21Strc* pPacket)
{
    D2PacketRecord21Strc tPacket = *pPacket;
    sub_004B9010(&tPacket);
}

// 0x0045E850
void __fastcall SCMD_HandleGoldInTrade(const D2GSPacketSrv79* pPacket)
{
    sub_004B90D0(pPacket->dwGold, pPacket->nOwnerGUID);
}

// 0x0045E050
void __fastcall SCMD_HandleClearHoverText(const D2ClientPacket6Strc* pPacket)
{
    D2ClientPacket6Strc tPacket = *pPacket;
    sub_0049F8C0_UsePacket6(&tPacket);
}

// 0x0045E860
void __fastcall SCMD_HandlePetAction(const D2GSPacketSrv7A* pPacket)
{
    const int nKey = pPacket->unk0x09;
    if (pPacket->unk0x01)
    {
        ROSTERPETS_SetRosterEntry(nKey, pPacket->unk0x05, pPacket->unk0x02, pPacket->unk0x03);
    }
    else
    {
        ROSTERPETS_DropPetEntry(nKey);
    }
}

// 0x0045E930
void __fastcall SCMD_HandleSetItemState(const D2GSPacketSrv7DStrc* pPacket)
{
    D2GSPacketSrv7DStrc tPacket = *pPacket;
    ITEM_HandleItemStatePacket(&tPacket);
}

// 0x0045E970
void __fastcall SCMD_HandleLoadCommonCof(const D2GSPacketSrv7E* pPacket)
{
    GFX_LoadGlobalHashedFile(DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(sub_00463DD0_GetPlayerUnit()))));
}

// 0x0045E990
void __fastcall SCMD_HandleAllyInfo(const D2GSPacketSrv7F* pPacket)
{
    const int nUnitGUID = pPacket->nUnitGUID;
    const unsigned short nLife = pPacket->nLifePercentage;
    const unsigned short nLevelId = pPacket->nLevelId;
    if (pPacket->bIsPlayer)
    {
        ROSTER_SetLifeAndLevel(nUnitGUID, nLife, nLevelId);
    }
    else
    {
        VIEW_UpdatePetLife(nUnitGUID, nLife, nLevelId);
    }
}

// 0x0045E9C0
void __fastcall SCMD_HandlePartyPosition(const D2GSPacketSrv90* pPacket)
{
    ROSTER_SetPosition(pPacket->dwGUID, pPacket->dwPosX, pPacket->dwPosY);
}

// 0x0045E9D0
void __fastcall SCMD_HandlePortalOwnership(const D2GSPacketSrv82* pPacket)
{
    const int nOwnerGUID = *(const int*)pPacket->dwOwnerGUID;
    const int nPortalGUID0 = *(const int*)pPacket->dwPortalGUID0;
    const int nPortalGUID1 = *(const int*)pPacket->dwPortalGUID1;

    D2UnitStrc* pPortal = CUNIT_FindClientUnit(nPortalGUID0, UNIT_OBJECT);
    if (pPortal)
    {
        OBJECT_SetObjectOwnerName(pPortal, pPacket->szOwnerName);
    }

    if (nPortalGUID1 != -1)
    {
        pPortal = CUNIT_FindClientUnit(nPortalGUID1, UNIT_OBJECT);
        if (pPortal)
        {
            OBJECT_SetObjectOwnerName(pPortal, pPacket->szOwnerName);
        }
        ROSTER_SetPortalIds(nOwnerGUID, nPortalGUID0, nPortalGUID1);
    }
}

// 0x0045EA30
void __fastcall SCMD_HandleUniqueEvent(const D2GSPacketSrv89* pPacket)
{
    sub_004B9330_UniqueEvent(pPacket);
}

// 0x0045E890
void __fastcall SCMD_HandleAssignMerc(const D2GSPacket81Strc* pPacket)
{
    D2Packet81ArgsStrc tArgs;
    tArgs.nArg0C = pPacket->nArg0C;
    tArgs.nArg10 = pPacket->nArg10;
    tArgs.nZero = 0;
    ROSTERPETS_AssignMercEntry(pPacket->nArg08, pPacket->nArg04, pPacket->nByte01, pPacket->nWord02, &tArgs);
}

// 0x0045E8D0
void __fastcall SCMD_HandleAssignHotkey(const D2GSPacketSrv7B* pPacket)
{
    const unsigned short wSkill = pPacket->wSkill;
    const int nHand = wSkill & 0x8000;
    int nSkillId = wSkill & 0xFFF;
    if (nSkillId > sgptDataTables->nSkillsTxtRecordCount)
    {
        nSkillId = -1;
    }
    SPELLSEL_SetHotkeySkillSlot(pPacket->nSlot, nSkillId, nHand != 0, pPacket->nItemGUID);
}

// 0x0045E910
void __fastcall SCMD_HandleUseScroll(const D2PacketRecord6Strc* pPacket)
{
    D2PacketRecord6Strc tPacket = *pPacket;
    sub_004C51B0(&tPacket);
}

// 0x0045EA40
void __fastcall SCMD_HandleNpcWantsInteract(const D2PacketRecord6Strc* pPacket)
{
    D2PacketRecord6Strc tPacket = *pPacket;
    NPCMENU_OnNpcWantsInteract(&tPacket);
}

// 0x0045EA60
void __fastcall SCMD_HandlePartyRelationship(const D2GSPacketSrv8B* pPacket)
{
    ROSTER_SetPartyFlags(pPacket->nUnitGUID, pPacket->bParty);
}

// 0x0045EA70
void __fastcall SCMD_HandlePvpRelationship(const D2GSPacketSrv8C* pPacket)
{
    ROSTER_SetPvpFlags(pPacket->dwPlayerGUID1, pPacket->dwPlayerGUID2, pPacket->nFlags);
}

// 0x0045EA90
void __fastcall SCMD_HandleAssignParty(const D2GSPacketSrv8D* pPacket)
{
    ROSTER_SetPartyId(pPacket->dwPlayerGUID, pPacket->nPartyGUID);
}

// 0x0045EAA0
void __fastcall SCMD_HandleCorpseAssign(const D2GSPacketSrv8E* pPacket)
{
    const int nPlayerGUID = pPacket->dwPlayerGUID;
    const int nCorpseGUID = pPacket->dwCorpseGUID;
    if (pPacket->nType)
    {
        ROSTER_AddCorpse(nPlayerGUID, nCorpseGUID);
    }
    else
    {
        ROSTER_DropCorpseEntry(nPlayerGUID, nCorpseGUID);
    }
}

// 0x0045EAC0
void __fastcall SCMD_HandleNpcMenuState(const D2GSPacketSrv9B* pPacket)
{
    NPCMENU_SetNpcMenuState(pPacket->unk0x01, pPacket->unk0x03);
}

// 0x0045EAD0
void __fastcall SCMD_HandleWeaponSwitch(const D2GSPacketSrv97* pPacket)
{
    D2_ASSERT(pPacket->nHeader == 0x97, 3910);
    sub_0048A700();
}

// 0x0045EB00
void __fastcall SCMD_HandlePong(const D2GSPacketSrv8F* pPacket)
{
    GAME_StorePong(pPacket);
}

// 0x0045DD10
void __fastcall SCMD_HandleSkillLevelBonus(const D2GSPacketSrv93* pPacket)
{
    const int nUnitGUID = *(const int*)pPacket->nUnitGUID;
    int nValue = pPacket->unk0x05;
    if (nValue > 0x80)
        nValue -= 0x100;
    const int nB = pPacket->unk0x06;
    const char nC = pPacket->unk0x07;

    D2UnitStrc* pUnit = CUNIT_FindClientUnit(nUnitGUID, UNIT_PLAYER);
    if (pUnit)
    {
        SKILLS_ApplySkillLevelBonus(pUnit, nValue, nB, nC);
    }
}

// 0x0045DD60
void __fastcall SCMD_HandleAssignSkills(const D2GSPacketSrv94* pPacket)
{
    const int nUnitId = pPacket->nUnitId;
    const unsigned char nCount = pPacket->nCount;
    const D2SkillLevelEntryStrc* pEntry = pPacket->pEntries;
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(nUnitId, 0);
    if (pUnit)
    {
        for (int i = 0; i < nCount; ++i)
        {
            SKILLS_AssignSkill(pUnit, pEntry->wSkillId, pEntry->nSkillLevel, 0, ".\\GAME\\SCmd.cpp", 2743);
            ++pEntry;
        }
    }
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

static inline D2MonStats2Txt* GetMonStats2TxtRecordFromMonsterId(int nMonsterId)
{
    if (nMonsterId < 0 || nMonsterId >= sgptDataTables->nMonStatsTxtRecordCount) return 0;
    int nMonStatsEx = sgptDataTables->pMonStatsTxt[nMonsterId].wMonStatsEx;
    if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
    {
        return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
    }
    return 0;
}

static inline D2ItemStatCostTxt* GetItemStatCostTxtRecord(int nStatId)
{
    if (nStatId >= 0 && nStatId < sgptDataTables->nItemStatCostTxtRecordCount)
    {
        return &sgptDataTables->pItemStatCostTxt[nStatId];
    }
    return 0;
}

// 0x0045EB10
void __fastcall SCMD_HandleItemActionWorld(const D2GSPacketSrv9C* pPacket)
{
    D2GSPacketSrv9C tPacket = *pPacket;
    D2GSPacketSrv9C* pCopy = &tPacket;
    switch (pCopy->nAction)
    {
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
    case 0x11:
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x16:
    case 0x17:
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0xF6D);
        exit(-1);
    case 0:
        sub_004C25B0(pCopy);
        break;
    case 1:
        ITEM_HandleGroundToCursor(pCopy);
        break;
    case 2:
        ITEM_HandleDropToGround(pCopy);
        break;
    case 3:
        ITEM_HandleItemOnGround(pCopy);
        break;
    case 4:
        ITEM_HandleItemToStorage(pCopy);
        break;
    case 0xA:
        ITEM_UpdateItemFromPacket(pCopy);
        break;
    case 0xD:
        ITEM_HandleCursorBeltSwap(pCopy);
        break;
    case 0xE:
        ITEM_HandlePutInBelt(pCopy);
        break;
    case 0xF:
        ITEM_HandleRemoveFromBelt(pCopy);
        break;
    case 0x10:
        ITEM_HandleBeltSwap(pCopy);
        break;
    case 0x12:
        ITEM_HandleItemToCursor(pCopy);
        break;
    case 0xB:
    case 0xC:
        ITEM_HandleShopItem(pCopy);
        break;
    }
}

// 0x0045EC70
void __fastcall SCMD_HandleItemActionOwned(const D2GSPacketSrv9D* pPacket)
{
    D2GSPacketSrv9D tPacket = *pPacket;
    D2GSPacketSrv9D* pCopy = &tPacket;
    switch (pCopy->nAction)
    {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
    case 0xA:
    case 0xB:
    case 0xC:
    case 0xD:
    case 0xE:
    case 0xF:
    case 0x10:
    case 0x12:
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0xFB7);
        exit(-1);
    case 5:
        ITEM_HandleItemFromStorage(pCopy);
        break;
    case 6:
        ITEM_HandleEquipItem(pCopy);
        break;
    case 7:
        ITEM_HandleIndirectSwapBodyItem(pCopy);
        break;
    case 8:
        ITEM_HandleUnequipItem(pCopy);
        break;
    case 9:
        ITEM_HandleSwapBodyItem(pCopy);
        break;
    case 0x17:
        ITEM_HandleWeaponSwitch(pCopy);
        break;
    case 0x11:
        ITEM_HandleAutoUnequip(pCopy);
        break;
    case 0x13:
        ITEM_HandleItemToSocket(pCopy);
        break;
    case 0x14:
        ITEM_HandleGridItemToBody(pCopy);
        break;
    case 0x15:
        ITEM_HandleBodyGridSwap(pCopy);
        break;
    case 0x16:
        ITEM_HandleOwnedItemToCursor(pCopy);
        break;
    }
}

// 0x0045EDC0
void __fastcall SCMD_HandleRunesRecord(const D2GSPacketSrvA6* pPacket)
{
    if (!pPacket->bSkip)
    {
        DATATBLS_AddOrChangeRunesTxtRecord(pPacket->nRecordId, (D2RunesTxt*)pPacket->pRecord);
    }
}

// 0x0045EDE0
void __fastcall SCMD_HandleDelayedState(const D2GSPacketSrvA7* pPacket)
{
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->nUnitId, pPacket->nUnitType);
    if (pUnit)
    {
        const int nState = pPacket->nState;
        PLRSKILLS_BeginState(pUnit, nState);
        PLRSKILLS_StartClientState(pUnit, nState);
    }
}

static inline void sub_0045F7B0_FindStoppedPlayer(const unsigned char* pPacket)
{
    const int nUnitId = *(const int*)(pPacket + 2);
    __assume((nUnitId | 1) != 0);
    if (pPacket[1] == 1)
    {
        CUNIT_FindClientUnit(nUnitId, 1);
    }
}

// 0x0045EE20
void __fastcall SCMD_HandleSetState(D2GSPacketSrvA8* pPacket)
{
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(*(const int*)pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
        return;

    const int nState = pPacket->nState;
    PLRSKILLS_BeginState(pUnit, nState);

    D2BitBufferStrc tBuffer;
    BITMANIP_Initialize(&tBuffer, pPacket->pStream, pPacket->nSize - 8);
    int nPrev = 0;
    int nStatId = sub_00411020_ReadBits(&tBuffer, 9);
    while (nStatId < STAT_ID_END)
    {
        if (nStatId < 0 || nStatId >= sgptDataTables->nItemStatCostTxtRecordCount)
            return;
        D2ItemStatCostTxt* pItemStatCostTxtRecord = &sgptDataTables->pItemStatCostTxt[nStatId];
        if (!pItemStatCostTxtRecord)
            return;
        if (pItemStatCostTxtRecord->nSendBits <= 0)
            return;

        int nLayer = 0;
        if (pItemStatCostTxtRecord->nSendParamBits > 0)
            nLayer = (unsigned short)BITMANIP_ReadSigned(&tBuffer, pItemStatCostTxtRecord->nSendParamBits);

        int nValue;
        if (pItemStatCostTxtRecord->nSendBits < 32 && pItemStatCostTxtRecord->nItemStatFlags[ITEMSTATCOSTFLAGINDEX_SIGNED >> 3] & gdwBitMasks[ITEMSTATCOSTFLAGINDEX_SIGNED & 7])
            nValue = BITMANIP_ReadSigned(&tBuffer, pItemStatCostTxtRecord->nSendBits);
        else
            nValue = sub_00411020_ReadBits(&tBuffer, pItemStatCostTxtRecord->nSendBits);

        nPrev = PLRSKILLS_SetStateStat(pUnit, nPrev, nState, nStatId, nValue, nLayer);
        nStatId = sub_00411020_ReadBits(&tBuffer, 9);
    }

    PLRSKILLS_StartClientState(pUnit, nState);
}

// 0x0045EF60
void __fastcall SCMD_HandleEndState(const D2GSPacketSrvA9* pPacket)
{
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->nUnitId, pPacket->nUnitType);
    if (pUnit)
    {
        const int nState = pPacket->nState;
        PLRSKILLS_EndClientState(pUnit, nState);
        PLRSKILLS_EndState(pUnit, nState);
    }
}


// 0x00460730
void __fastcall SCMD_SetMonsterClientFlags(D2UnitStrc* pUnit, unsigned short nFlags, int bSet)
{
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData)
    {
        if (bSet)
        {
            pUnit->pMonsterData->nClientFlags |= nFlags;
        }
        else
        {
            pUnit->pMonsterData->nClientFlags &= ~nFlags;
        }
    }
}

// 0x00463C00
void __fastcall SCMD_HandleMonsterModeChange(D2UnitStrc* pUnit, unsigned char nOldMode, unsigned char nNewMode)
{
    int nOld = nOldMode;
    int nNew = nNewMode;
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && nOld != nNew)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        if (pRoom)
        {
            if (nNew == MODE_2)
            {
                DUNGEON_IncreaseAlliedCountOfRoom(pRoom);
            }
            else if (nOld == MODE_2)
            {
                DUNGEON_DecreaseAlliedCountOfRoom(pRoom);
            }
            D2Common_10214(pUnit);
        }
    }
}

// 0x0045EFA0
void __fastcall SCMD_HandleAddUnitStates(D2GSPacketSrvAA* pPacket)
{
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(*(const int*)pPacket->nUnitId, pPacket->nUnitType);
    if (!pUnit)
        return;

    D2BitBufferStrc tBuffer;
    BITMANIP_Initialize(&tBuffer, pPacket->pStream, pPacket->nSize - 7);
    int nState = sub_00411020_ReadBits(&tBuffer, 8);
    while (nState < STATE_ID_END)
    {
        PLRSKILLS_BeginState(pUnit, nState);
        if (sub_00411020_ReadBits(&tBuffer, 1))
        {
            int nPrev = 0;
            int nStatId = sub_00411020_ReadBits(&tBuffer, 9);
            while (nStatId < STAT_ID_END)
            {
                if (nStatId < 0 || nStatId >= sgptDataTables->nItemStatCostTxtRecordCount)
                    return;
                D2ItemStatCostTxt* pItemStatCostTxtRecord = &sgptDataTables->pItemStatCostTxt[nStatId];
                if (!pItemStatCostTxtRecord)
                    return;
                if (pItemStatCostTxtRecord->nSendBits <= 0)
                    return;

                int nLayer = 0;
                if (pItemStatCostTxtRecord->nSendParamBits > 0)
                    nLayer = (unsigned short)BITMANIP_ReadSigned(&tBuffer, pItemStatCostTxtRecord->nSendParamBits);

                int nValue;
                if (pItemStatCostTxtRecord->nSendBits < 32 && pItemStatCostTxtRecord->nItemStatFlags[ITEMSTATCOSTFLAGINDEX_SIGNED >> 3] & gdwBitMasks[ITEMSTATCOSTFLAGINDEX_SIGNED & 7])
                    nValue = BITMANIP_ReadSigned(&tBuffer, pItemStatCostTxtRecord->nSendBits);
                else
                    nValue = sub_00411020_ReadBits(&tBuffer, pItemStatCostTxtRecord->nSendBits);

                nPrev = PLRSKILLS_SetStateStat(pUnit, nPrev, nState, nStatId, nValue, nLayer);
                nStatId = sub_00411020_ReadBits(&tBuffer, 9);
            }
        }
        PLRSKILLS_StartClientState(pUnit, nState);
        nState = sub_00411020_ReadBits(&tBuffer, 8);
    }
}

// 0x0045F120
void __fastcall SCMD_HandleUnitLife(unsigned char* pPacket)
{
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(*(int*)(pPacket + 2), pPacket[1]);
    if (!pUnit)
        return;
    if (pUnit == sub_00463DE0_GetPlayerUnit())
        return;
    const int bFlag = (pUnit->dwFlags >> 9) & 1;
    if (bFlag)
        return;
    if (pUnit->dwUnitType == UNIT_MONSTER)
        STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, pPacket[6] << 8, bFlag);
    else
        ROSTER_SetPartyLife(*(int*)(pPacket + 2), pPacket[6] * 100 / 128);
}

// 0x0045F190
void __fastcall SCMD_HandleAssignMonster(D2PacketSpawnStrc* pPacket)
{
    unsigned int nUnitId = pPacket->nUnitId;
    unsigned short nX = pPacket->nX;
    unsigned short nY = pPacket->nY;
    short nClassId = pPacket->nClassId;
    D2BitBufferStrc tBuffer;
    unsigned char aComponents[16];
    unsigned char aMods[9];
    BITMANIP_Initialize(&tBuffer, pPacket->aData, pPacket->nLength - 13);
    unsigned char nMode = (unsigned char)sub_00411020_ReadBits(&tBuffer, 4);
    unsigned char* pComponents = 0;
    if (sub_00411020_ReadBits(&tBuffer, 1))
    {
        D2MonStats2Txt* pRecord = GetMonStats2TxtRecordFromMonsterId(nClassId);
        if (!pRecord) return;
        pComponents = aComponents;
        for (int i = 0; i < 16; ++i)
            aComponents[i] = (unsigned char)sub_00411020_ReadBits(&tBuffer, Log2Ceil(pRecord->nComponentChoiceCounts[i]));
    }
    unsigned char* pMods = 0;
    unsigned short nFlags = 0;
    int nUniqueId = -1;
    int nSpecial = 0;
    unsigned short nPalette = 0;
    if (sub_00411020_ReadBits(&tBuffer, 1))
    {
        nFlags = sub_00411020_ReadBits(&tBuffer, 1) ? 4 : 0;
        nFlags |= sub_00411020_ReadBits(&tBuffer, 1) ? 8 : 0;
        nFlags |= sub_00411020_ReadBits(&tBuffer, 1) ? 2 : 0;
        nFlags |= sub_00411020_ReadBits(&tBuffer, 1) ? 16 : 0;
        nFlags |= sub_00411020_ReadBits(&tBuffer, 1) ? 64 : 0;
        if (nFlags & 2) nSpecial = (unsigned short)BITMANIP_ReadSigned(&tBuffer, 16);
        for (int i = 0; i < 9; ++i) aMods[i] = 0;
        pMods = aMods;
        int nModIndex = 0;
        for (unsigned char nMod = (unsigned char)sub_00411020_ReadBits(&tBuffer, 8); nMod; nMod = (unsigned char)sub_00411020_ReadBits(&tBuffer, 8))
            aMods[nModIndex++] = nMod;
        nPalette = (unsigned char)sub_00411020_ReadBits(&tBuffer, 16);
        if (sub_00411020_ReadBits(&tBuffer, 1)) nUniqueId = sub_00411020_ReadBits(&tBuffer, 32);
    }
    D2UnitSpawnStrc tSpawn;
    memset(&tSpawn, 0, sizeof(tSpawn));
    tSpawn.nUnitId = nUnitId;
    tSpawn.nClassId = nClassId;
    tSpawn.nX = nX;
    tSpawn.nY = nY;
    tSpawn.tExtra.nFlags = nFlags;
    tSpawn.tExtra.nUniqueId = nUniqueId;
    tSpawn.nMode = nMode;
    PALSHIFT_LoadPalShift(nClassId);
    D2UnitStrc* pUnit = CUNIT_AddClientMonster(&tSpawn, pComponents, pMods, nPalette, nSpecial, 0);
    if (!pUnit) return;
    GFX_ResetMonsterModeGfx(pUnit);
    if (!MONSTERS_GetHirelingTypeId(pUnit) || nUnitId != ROSTERPETS_FindPetIdByOwner(sub_00463DD0_GetPlayerUnit(), 7, 1))
    {
        STATLIST_SetUnitStat(pUnit, STAT_MAXHP, 0x8000, 0);
        STATLIST_SetUnitStat(pUnit, STAT_HITPOINTS, pPacket->nLife << 8, 0);
    }
    if (MONSTERS_GetHirelingTypeId(pUnit) && nMode == 1) pUnit->dwFlagEx &= ~0x40000;
    STATLIST_SetUnitStat(pUnit, STAT_PIERCE_IDX, (unsigned short)(nX + nY), 0);
    if (sub_00411020_ReadBits(&tBuffer, 1)) UNITS_StoreOwnerTypeAndGUID(pUnit, 0, sub_00411020_ReadBits(&tBuffer, 31));
    if (sub_00411020_ReadBits(&tBuffer, 1))
    {
        D2StatListStrc* pStatList = 0;
        for (int nStat = sub_00411020_ReadBits(&tBuffer, 9); nStat < 511; nStat = sub_00411020_ReadBits(&tBuffer, 9))
        {
            D2ItemStatCostTxt* pRecord = GetItemStatCostTxtRecord(nStat);
            if (!pRecord || pRecord->nSendBits <= 0) return;
            int nLayer = 0;
            if (pRecord->nSendParamBits > 0) nLayer = (unsigned short)BITMANIP_ReadSigned(&tBuffer, pRecord->nSendParamBits);
            int nValue;
            if (pRecord->nSendBits < 32 && (pRecord->nItemStatFlags[0] & (unsigned char)gdwBitMasks[1]))
                nValue = BITMANIP_ReadSigned(&tBuffer, pRecord->nSendBits);
            else
                nValue = sub_00411020_ReadBits(&tBuffer, pRecord->nSendBits);
            if (!pStatList)
            {
                pStatList = STATLIST_GetStatListFromUnitStateAndFlag(pUnit, 0, 0x40);
                if (!pStatList)
                {
                    pStatList = STATLIST_AllocStatList(0, 0x40, 0, GAME_GetUnitTypeOrInvalid(pUnit), GAME_GetUnitGUID(pUnit));
                    STATLIST_SetState(pStatList, 0);
                    D2COMMON_10475_PostStatToStatList(pUnit, pStatList, 1);
                }
            }
            if (pStatList) STATLIST_SetStatIfListIsValid(pStatList, nStat, nValue, nLayer);
        }
    }
}

// 0x0045F5F0
void __fastcall SCMD_HandleWardenRequest(D2GSPacketSrvAE* pPacket)
{
    if (gdwGlobal_007A0610 == 2 || gdwGlobal_007A0610 == 3)
        sub_004802E0(pPacket->pData, pPacket->nLength);
}

inline int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
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

inline int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
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

// 0x0045F610
static D2PacketBufferStrc* SCMD_GrowPacketBuffer(D2UnitStrc* pUnit)
{
    if (!gnPacketRecordSize)
    {
        for (int i = 0; i < 0xAF; ++i)
        {
            if (gaPacketTable[i].pfnAltHandler && gaPacketTable[i].nSize > gnPacketRecordSize)
            {
                gnPacketRecordSize = gaPacketTable[i].nSize;
            }
        }
        gnPacketRecordSize += 5;
    }
    D2PacketBufferStrc* pBuffer = sub_00464770_GetPacketBuffer(pUnit);
    if (!pBuffer)
    {
        pBuffer = (D2PacketBufferStrc*)FOG_Alloc(0x10, ".\\GAME\\SCmd.cpp", 0x1266, 0);
        memset(pBuffer, 0, 0x10);
        sub_004647A0_SetPacketBuffer(pUnit, pBuffer);
    }
    int nNewMax = pBuffer->nMax + 5;
    unsigned char* pData = (unsigned char*)FOG_Alloc(gnPacketRecordSize * nNewMax, ".\\GAME\\SCmd.cpp", 0x126B, 0);
    memset(pData, 0, gnPacketRecordSize * nNewMax);
    if (pBuffer->pData)
    {
        memcpy(pData, pBuffer->pData, pBuffer->nMax * gnPacketRecordSize);
        FOG_Free(pBuffer->pData, ".\\GAME\\SCmd.cpp", 0x126F, 0);
    }
    pBuffer->nMax = nNewMax;
    pBuffer->pData = pData;
    return pBuffer;
}

void __stdcall CURSOR_MsgHandler(SMSGHANDLER_PARAMS* pMsg); // 0x00467EF0

// 0x0045F730
static void __stdcall SCMD_QueuePacket(unsigned char* pPacket, int nLength, D2UnitStrc* pUnit)
{
    D2PacketBufferStrc* pBuffer = sub_00464770_GetPacketBuffer(pUnit);
    if (!pBuffer || pBuffer->nCount + 1 == pBuffer->nMax)
    {
        pBuffer = SCMD_GrowPacketBuffer(pUnit);
    }
    D2_ASSERT(nLength <= gnPacketRecordSize, 0x127F);
    memcpy(pBuffer->pData + pBuffer->nCount * gnPacketRecordSize, pPacket, nLength);
    ++pBuffer->nCount;
}

// 0x0045F7B0
void __fastcall SCMD_ProcessPackets(unsigned char* pData, int nSize)
{
    if (nSize == -1)
    {
        return;
    }

    int nRemaining = nSize;
    unsigned char* pPacket = pData;
    GetTickCount();
    if (nSize > 500)
    {
        ++gnLargePacketBlocks;
    }

    while (nRemaining > 0)
    {
        unsigned char nId = *pPacket;
        int nPacketSize;
        int nUnitId;
        int nUnitType;
        if (!sub_0052B920(pPacket, nSize, &nPacketSize))
        {
            return;
        }

        unsigned short nLength = (unsigned short)nPacketSize;
        D2_ASSERT(nId < 0xAF, 0x1449);
        D2PacketTableEntryStrc* pEntry = &gaPacketTable[nId];
        if (pEntry->nSize != -1)
        {
            D2_ASSERT(nLength == pEntry->nSize, 0x1450);
        }

        if (pEntry->nSize == -1 || nLength == pEntry->nSize)
        {
            if (pEntry->pfnAltHandler)
            {
                switch (nId)
                {
                case 0x67: case 0x68: case 0x69: case 0x6A: case 0x6B: case 0x6C: case 0x6D:
                    nUnitId = *(int*)(pPacket + 1);
                    nUnitType = 1;
                    break;
                default:
                    nUnitId = *(int*)(pPacket + 2);
                    nUnitType = pPacket[1];
                    break;
                }

                D2UnitStrc* pUnit = CUNIT_FindClientUnit(nUnitId, nUnitType);
                if (pUnit)
                {
                    SCMD_QueuePacket(pPacket, nLength, pUnit);
                }
            }

            switch (nId)
            {
            case 0x18:
            {
                D2Packet18RecordStrc tRecord;
                SCMD_ReadVitalsUpdate(pPacket, &tRecord);
                break;
            }
            case 0x95:
            {
                D2Packet95RecordStrc tRecord;
                SCMD_ReadVitalsAndPosition(pPacket, &tRecord);
                break;
            }
            case 0x96:
            {
                D2Packet96RecordStrc tRecord;
                SCMD_ReadWalkVerify(pPacket, &tRecord);
                break;
            }
            case 0x0D:
                sub_0045F7B0_FindStoppedPlayer(pPacket);
                break;
            }

            if (pEntry->pfnHandler)
            {
                pEntry->pfnHandler(pPacket);
            }
        }

        gnPacketBytes += nLength;
        nRemaining -= nLength;
        pPacket += nLength;
        gnLastPacketId = nId;
    }

    ++gnPacketBlocks;
}




// 0x0046E150
void __fastcall SCMD_SetGfxNodeValue(D2UnitStrc* pUnit, int nId, int nValue)
{
    D2GfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
    D2_ASSERT(pGfxData, 510);

    for (D2UnitOverlayStrc* pNode = pGfxData->pOverlays; pNode; pNode = pNode->pNext)
    {
        if (pNode->nId == nId)
        {
            D2_ASSERT(pNode->nType == 1, 517);
            pNode->nValue = nValue;
        }
    }
}

// 0x00474390
void __fastcall SCMD_SetLightColorBytes(D2ByteRecordStrc* pRecord, unsigned char nValue0, unsigned char nValue1, unsigned char nValue2)
{
    D2_ASSERT(pRecord, 359);
    pRecord->nValue0 = nValue0;
    pRecord->nValue1 = nValue1;
    pRecord->f_27 = nValue2;
}





#include "gen/data/Source/D2Client/GAME/SCmd.inc"
