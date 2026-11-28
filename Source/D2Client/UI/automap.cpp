#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2Drlg.h"
#include "D2TxtTables.h"
#include "D2Unicode.h"
#include "D2Win32Types.h"
#include "D2StormTypes.h"
#include "D2ClientTypes.h"
#include "D2ClientUi.h"
#include "D2Skills.h"
#include "D2LevelIds.h"
#include "D2DrlgTiles.h"
#include "D2DrlgMaps.h"
#include "D2StateIds.h"
#include "D2UnitData.h"
#include "D2CelContext.h"
#include "D2ClientUiRecords.h"
#include "D2WinSplitText.h"
#include "FogApi.h"
#include "StormApi.h"
#include "D2CommonApi.h"
#include "D2LangApi.h"
#include "FogApi.h"
#include "StormApi.h"
#include "D2GfxApi.h"
#include "D2CMPApi.h"
#include "StormApi2.h"
#include "D2WinApi2.h"

#define OFFSET(T, M) ((unsigned int)&(((T*)0)->M))

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2WardenIfaceStrc;

struct D2CriticalSectionStrc;

struct D2FogBlockStrc;

struct D2CharSaveIdStrc;

struct D2CharSaveHeaderStrc;

struct D2AutomapLayerStrc;

struct D2AutomapCellStrc;

struct D2AutomapCellBlockStrc;

struct PlayerNode;

struct PlayerListHead;

struct D2UnitTargetStrc;

struct D2SkillsTxt;

struct D2UnitOverlayStrc;

struct D2OverlayTxt;

struct D2AutomapPairStrc;

struct D2UiRectStrc;

struct D2UiRecordStrc;

struct D2ClientSlotObjStrc;

class WardenModule;

struct D2GfxLightStrc;

struct D2UnitStrc;

struct D2UnitGfxDataStrc;

struct D2DataTablesStrc;

struct SMSGHANDLER_PARAMS;

struct Unicode;

struct D2MsgHandlerEntryStrc;

struct D2StaticPathStrc;

struct D2SkillStrc;

struct D2SkillListStrc;

struct D2ActiveRoomStrc;

struct D2DrlgCoordsStrc;

struct D2PacketBufferStrc;

struct D2PacketTableEntryStrc;

struct D2MonStats2Txt;

typedef unsigned char BOOLEAN;

struct D2FogBlockStrc
{
    D2FogBlockStrc* pNext;
    unsigned int dwSize;
    int unk0x08[3];
    int bInUse;
};

struct D2CharSaveIdStrc
{
    unsigned char f_0[0x10];
};

struct D2CharSaveHeaderStrc
{
    unsigned int dwMagic;
    unsigned int dwVersion;
    unsigned int dwSize;
    char unk0x0C[0x08];
    char szName[0x10];
    unsigned int dwFlags;
    unsigned char nClass;
    unsigned char nUnk0x29;
    unsigned char nUnk0x2A;
    unsigned char nUnk0x2B;
    long nCreateTime;
    long nSaveTime;
    char unk0x34[0x54];
    D2CharSaveIdStrc tId;
    int anUnk0x98[4];
    char unk0xA8[0xA7];
};

struct D2AutomapLayerStrc
{
    unsigned int nLayerNo;
    unsigned int fSaved;
    D2AutomapCellStrc* pFloors;
    D2AutomapCellStrc* pWalls;
    D2AutomapCellStrc* pObjects;
    D2AutomapCellStrc* pExtras;
    D2AutomapLayerStrc* pNext;
};

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void); // 0x006CC260

extern "C" __declspec(dllimport) void __stdcall OutputDebugStringA(const char* szText); // 0x006CC200

































































































































































































































































































































































































































































































































































































































































































































































































































extern "C" __declspec(dllimport) void __stdcall EnterCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC218

extern "C" __declspec(dllimport) void __stdcall LeaveCriticalSection(D2CriticalSectionStrc* pLock); // 0x006CC214

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" long __cdecl _time32(long* pTime); // 0x006850E6


void __fastcall UnlinkAndFreeHeap(D2FogBlockStrc** ppLink); // 0x00411A80


void __stdcall FOG_Encode14BitsToString(unsigned char* pStream, unsigned short nValue); // 0x006BBF40

extern _iobuf* gapLogFiles[20]; // 0x0075E790

extern unsigned long gadwLogOpenTick[20]; // 0x0075E7E0

extern unsigned long gadwLogWriteTick[20]; // 0x0075D2F0

extern D2FogBlockStrc* gapFreeBlocks_007768B8[0x100]; // 0x007768B8

extern D2CriticalSectionStrc gaFreeBlockLocks_00776CC0[0x100]; // 0x00776CC0

extern D2CharSaveHeaderStrc gtCharSaveHeader; // 0x0077AC10

extern D2CharSaveIdStrc gtCharSaveId; // 0x0070CCC8

D2AutomapLayerStrc* gpAutomapNodes; // 0x007A5160

struct D2AutomapCellBlockStrc
{
    D2AutomapCellStrc cells[512];
    D2AutomapCellBlockStrc* pNext;
};


void __stdcall AUTOMAP_BalanceLeftHeavy(D2AutomapCellStrc** ppRoot); // 0x00457900

void __stdcall AUTOMAP_BalanceRightHeavy(D2AutomapCellStrc** ppRoot); // 0x004579E0

extern int gaAutomapCellTable[0x800]; // 0x007A3150

typedef char NodeFlags[(OFFSET(PlayerNode, flags) == 4) ? 1 : -1];

typedef char NodeNext[(OFFSET(PlayerNode, next) == 8) ? 1 : -1];

extern const char gPlayerListFile[];

extern const char gSoundFile[];

extern void* gAuxSoundRows;

extern int gAuxSoundCount;

extern void* gCacheRows;

extern int gCacheCount;

extern int gSoundMaxId;

extern int gSoundMinId;

extern int gTextY; // 0x007A51BC

extern int gTextRight; // 0x007A5220


void* __fastcall Allocate(unsigned int bytes, const char* file, int line, unsigned int flags);

int __fastcall Release(void* allocation, const char* file, int line, unsigned int flags);

void __fastcall SOUNDHDR_ReleaseCacheEntry(int index); // 0x004823E0


const Unicode* __fastcall UI_GetLevelName(int nLevelId); // 0x00453E70

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00



struct D2UnitOverlayStrc
{
    int nType;
    int nOverlay;
    int nUnk0x08;
    int f_C;
    int unk0x10[2];
    int nFrame;
    int nFrames;
    int nOffsetX;
    int nOffsetY;
    int unk0x28[3];
    int bFront;
    int unk0x38;
    int nUnk0x3C;
    char unk0x40[0x64];
    D2UnitOverlayStrc* pNext;
};

struct D2AutomapPairStrc
{
    int nIndex;
    int nValue;
};

struct D2ClientSlotObjStrc
{
    virtual void Slot0(int* pValue, int nSize);
    virtual void Slot1();
    virtual void Slot2(int nArg1, int nArg2, int* pOut);
};

class WardenModule
{
public:
    ~WardenModule();
    void operator delete(void* pMemory)
    {
        SMemFree(pMemory, ".\\WARDEN\\WardenClient.cpp", 0x117, 0);
    }

    void* pImage;
    int unk0x04;
    int nImports;
    D2ClientSlotObjStrc* pObj;
    D2ClientSlotObjStrc* (__fastcall* pfnCreate)(D2WardenIfaceStrc* pIface);
};

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern "C" const char gszEmptyAssertText; // 0x006CC837



extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09


void __cdecl AUTOMAP_ReloadAutomapCels(); // 0x0045A2B0

int __fastcall PLAYER_ApplyUnitCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget, int nArg); // 0x00461250


D2UnitGfxDataStrc* __fastcall CUNIT_GetGfxData(D2UnitStrc* pUnit); // 0x00463E10

void __stdcall GFX_RemoveStateOverlay(D2UnitStrc* pUnit, D2UnitOverlayStrc* pOverlay); // 0x0046E040

void __fastcall MONSTER_HandleMonsterCommand(int nCommand, D2UnitStrc* pUnit, D2UnitTargetStrc* pTarget); // 0x004AFF60






int __stdcall STATLIST_UnitGetItemStatOrSkillStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625500

unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0


int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc* pItem); // 0x0062BA80





D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill); // 0x00644140



void __stdcall DATATBLS_GetBeltsTxtRecord(int nIndex, int bHigherRes, D2BeltsTxt* pRecord); // 0x00660CB0

extern D2AutomapPairStrc gaAutomapPairs[49]; // 0x00711258

extern int gbAutomapPartyNames; // 0x007113E8



int gdwAutoMapFade; // 0x007A51A8

int gbAutomapLeft;                                                                                     // 0x007A51E0

int gbAutomapLeftPrev;                                                                                     // 0x007A51E4

extern int gbAutomapLeftSaved; // 0x007A51E8

extern int gnBeltUiRecordRow; // 0x007A5218

extern int gbUiRecordMode; // 0x007BEF98

extern int gnAutomapMode; // 0x007A5150



enum D2C_F06UiConstants
{
    BODYLOC_RARM = 4,
    BODYLOC_LARM = 5,
};

typedef void (__stdcall* SMSGHANDLER)(SMSGHANDLER_PARAMS* pMsg);


typedef void (__fastcall* D2PacketHandlerFn)(void* pArg, unsigned char* pPacket);

struct D2PacketTableEntryStrc
{
    void* pfnHandler;
    int nSize;
    D2PacketHandlerFn f_8;
};

void __fastcall SCMD_UnregisterMsgHandler(void* hWnd, int nType, int nId, SMSGHANDLER pfnHandler); // 0x00451D10







void __fastcall MONSTER_GetMonsterName(D2UnitStrc* pUnit, Unicode* wszName, int nLength, unsigned short nNameId); // 0x004ADEA0

D2AutomapCellStrc* __cdecl AUTOMAP_AllocAutomapCell(); // 0x00457C30

int __fastcall AUTOMAP_InsertAutomapCell(D2AutomapCellStrc* pCell, D2AutomapCellStrc** ppRoot); // 0x00457B00

void __stdcall DUNGEON_GameSubtileToClientCoords(int* pX, int* pY); // 0x00643260




void __stdcall D2GFX_DrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned char nColor, unsigned char nAlpha); // 0x004F6380


void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, unsigned int* pnNumRooms); // 0x00619790

int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit); // 0x00620650

int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit); // 0x006206B0






D2UnitStrc* __stdcall STATLIST_GetOwner(D2UnitStrc* pUnit, int* pStatNotDynamic); // 0x00625820


void __stdcall STATLIST_MergeStatLists(D2UnitStrc* pTarget, D2UnitStrc* pUnit, int bType); // 0x00627910



D2PacketBufferStrc* __fastcall CUNIT_GetPacketList(void* pArg); // 0x00464770



int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00


void __fastcall DLIGHTMAP_ResetLightSize(D2GfxLightStrc* pLight, int nRadius); // 0x004742D0

void __fastcall SCMD_SetLightColorBytes(D2GfxLightStrc* pLight, unsigned char nValue0, unsigned char nValue1, unsigned char nValue2); // 0x00474390

unsigned char __stdcall ITEMS_GetBodyLocation(D2UnitStrc* pItem); // 0x00627D40

unsigned char __stdcall ITEMS_GetComponent(D2UnitStrc* pItem); // 0x00628660


D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory); // 0x0063BEF0


extern Unicode gwszHoverName[]; // 0x007A2F38

extern int gnPanelSlideMode; // 0x007A5210

extern int gnPanelSlideOffsetX; // 0x007A5214

extern int gnPacketRecordSize; // 0x007A5230

extern D2PacketTableEntryStrc gaPacketTable[]; // 0x007114D0



extern int gbOkCancelAccepted; // 0x007A5258

extern int gbOkCancelCancelled; // 0x007A525C

int gabFreeBlockDirty[0x100]; // 0x007784C8

int gpFreeBlockSweep; // 0x007788C8

struct D2TileLibraryEntryStrc;

struct D2DrlgLevelStrc;

struct D2AutomapRoomStrc;

struct D2MonStatsTxt;

struct D2AutomapSaveStrc;

struct D2AutomapRecordStrc;


void __cdecl GFX_FreeHashedFiles(); // 0x00470290

int __cdecl VIEW_IsPetIconVisible(); // 0x00492C10

int gnAutomapMode;                                                                                     // 0x007A5150

static D2AutomapLayerStrc* gpAutomapContext; // 0x007A5164

int gnRevealSkip; // 0x007A51A4

int gnMiniMapY;                                                                                    // 0x007A51D8

struct D2AutomapRoomStrc
{
    char unk0x00[0x34];
    int nPosX;
    int nPosY;
    char unk0x3C[0x1C];
    D2DrlgLevelStrc* pLevel;
};

void* __stdcall DRLG_GetLevelTypeFromLevelId(int nLevelId); // 0x00642750

int __fastcall DATATBLS_GetAutomapCellId(void* pAutomapLevelType, int nAutomapTileType, int nStyle, int nSequence); // 0x0061FFF0

D2AutomapRoomStrc* __fastcall DUNGEON_GetRoomExFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061AAE0

D2DrlgTileDataStrc* __stdcall DUNGEON_GetWallTilesFromRoom(D2ActiveRoomStrc* pRoom, unsigned int* pCount); // 0x006196A0

void __stdcall AUTOMAP_RevealRoomObjects(D2ActiveRoomStrc* pRoom, D2AutomapCellStrc** ppRoot); // 0x00458DC0



int gbRevealAutomap; // 0x007A51A0

void* __cdecl AUTOMAP_OpenAutomapFile(); // 0x00457F40





void __fastcall AUTOMAP_CountCells(D2AutomapCellStrc* pCells, unsigned int* pCount); // 0x00458440

void __fastcall AUTOMAP_StoreCells(D2AutomapCellStrc* pCells); // 0x00458470

extern D2AutomapRecordStrc* gpAutomapRecord; // 0x007A0638

static void* gpAutomapSaveBuffer; // 0x007A5154

int gaAutomapCelFrames[4]; // 0x007A5178

void __stdcall AUTOMAP_RevealRoomTiles(D2ActiveRoomStrc* pActiveRoom, int bRevealAll, D2AutomapLayerStrc* pLayer); // 0x00458F40

int gdwAutoMapFadeSaved; // 0x007A51AC

unsigned char gabAutomapColors[12]; // 0x007A51B0

int gnMiniMapSavedX; // 0x007A51C0

int gnMiniMapSavedY; // 0x007A51C4

int gnAutomapClipLeft; // 0x007A51C8

int gnAutomapClipTop; // 0x007A51CC

int gnAutomapClipRight; // 0x007A51D0

int gnAutomapClipBottom; // 0x007A51D4

int gnMiniMapX; // 0x007A51DC

int gbLayoutAutomapLeft; // 0x007A51EC

int gbLayoutPetIconVisible; // 0x007A51F0

static D2AutomapLayerStrc* AUTOMAP_InitAutomapLayer(int nLayerNo); // 0x00458D40


int gnRevealPlayerX; // 0x007A5200

int gnRevealPlayerY; // 0x007A51F8

int gnRevealLastX; // 0x007A51FC

int gnRevealLastY; // 0x007A51F4

void __stdcall AUTOMAP_RevealRoomCallback(D2ActiveRoomStrc* pRoom); // 0x00459150


static D2AutomapCellBlockStrc* gpAutomapCellBlocks; // 0x007A5158

static int gnAutomapCellCount; // 0x007A515C

extern D2AutomapCellBlockStrc* gpCellBlocks_007A5158; // 0x007A5158

extern int gnAutomapCellCount; // 0x007A515C

void __stdcall AUTOMAP_AddAutomapCell(unsigned short nCellNo, unsigned short xPixel, unsigned short yPixel, D2AutomapCellStrc** ppRoot, unsigned int fSaved);

WardenModule* gpSlotHolder; // 0x007BC990

WardenModule* gpPendingWarden; // 0x007BC994

struct D2AutomapFileHeaderStrc;

struct D2AutomapPointStrc;

struct D2AutomapFileHeaderStrc
{
    int nVersion;
    int nNext;
    unsigned int nSeeds[4];
};

typedef char D2AutomapFileHeaderSizeCheck[sizeof(D2AutomapFileHeaderStrc) == 0x18 ? 1 : -1];

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...);





extern char gszClientCharName[]; // 0x007A05C4

extern "C" const char gszAutomapFile[]; // 0x006D66F0



Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

int __fastcall UNICODE_StrLen(const Unicode* pString); // 0x00526800



const char* __cdecl WINMAIN_GetGameName(); // 0x0044B7C0

const char* __cdecl WINMAIN_GetGamePassword(); // 0x0044B820

const char* __cdecl WINMAIN_GetGameDescription(); // 0x0044B7F0


int gnAutomapWidth = gnScreenWidth; // 0x007A5220

extern "C" __declspec(dllimport) int __stdcall wvsprintfA(char* szDest, const char* szFormat, va_list args); // 0x006CC4AC

D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0

extern "C" size_t __cdecl strlen(const char* szString);

extern const D2AutomapPointStrc gaAutomapCross[13]; // 0x006D6638

extern int gnAutomapScale; // 0x00711254

int gnAutomapOffsetX;                                                                              // 0x007A5198

int gnAutomapOffsetY;                                                                              // 0x007A519C


void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270

int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nStateMask); // 0x0063A7B0


short __fastcall CUNIT_GetPlayerPartyId(D2UnitStrc* pUnit); // 0x00465400

int __fastcall ROSTERPETS_GetPetRelation(int nUnitId); // 0x00478D90

int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc* pUnit, int nFlag); // 0x00451F30





const Unicode* __fastcall CUNIT_GetUnitName(D2UnitStrc* pUnit); // 0x00464A60

const char* __stdcall UNITS_GetPlayerName(D2UnitStrc* pUnit); // 0x006221A0





int __fastcall ROSTER_GetLevelId(D2StoredUnitRecordStrc* pEntry); // 0x0047A1E0

void __fastcall ROSTER_GetPosition(D2StoredUnitRecordStrc* pEntry, int* pX, int* pY); // 0x0047A1B0

extern "C" const char* __fastcall ROSTER_GetEntryName(D2StoredUnitRecordStrc* pEntry); // 0x004795C0

char gszRealm[32]; // 0x007A0500





int __fastcall MISSILE_SubmitMissileRequest(D2UnitStrc* pUnit, int nArg, int nX, int nY, int nArg3, int nArg4); // 0x004CDB40

int gnAutomapTextY; // 0x007A51BC

void __cdecl sub_0045B960_FilePrintf(void* hFile, const char* szFormat, ...); // 0x0045B960

struct D2AutomapDrawStrc
{
    D2CelFileStrc* pCelFile;
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
    int nXOffset;
    int nYOffset;
};

int __cdecl UI_GetAutomapOffsetX();                                                                                 // 0x0045AFA0

int __cdecl UI_GetAutomapOffsetY();                                                                                 // 0x0045AFB0

void __fastcall AUTOMAP_DrawAutomapCells(D2AutomapCellStrc* pCell, D2AutomapDrawStrc* pInfo);                  // 0x00459440

int gnAutomapHeight_007A521C = gnScreenHeight - 40; // 0x007A521C

int gnAutomapViewX;                                                                                // 0x007A5190

int gnAutomapViewY;                                                                                // 0x007A5194

extern int gnAutomapBaseX;                                                                         // 0x007A5188

extern int gnAutomapBaseY;                                                                         // 0x007A518C

D2CelFileStrc* gapAutomapCels[4];                                                                       // 0x007A5168

static int AUTOMAP_GetAutomapUnitColor(D2UnitStrc* pUnit, unsigned char* pColor); // 0x00459BC0

static void __stdcall AUTOMAP_DrawAutomapText(unsigned char nColor, const char* szText, int nX, int nY); // 0x0045A760

static void __stdcall AUTOMAP_DrawAutomapCross(unsigned char nColor, int nX, int nY); // 0x0045A7F0

static void AUTOMAP_DrawAutomapPartyMember(D2StoredUnitRecordStrc* pEntry); // 0x0045AB60

static inline int AUTOMAP_GetUnitType(D2UnitStrc* pUnit);

static inline int AUTOMAP_UnitHasFlag(D2UnitStrc* pUnit, unsigned int nFlag);

#define AUTOMAP_SIZE_MINI 1

#define TOWNCEL_LUTGHOLEIN_MINI 0

#define TOWNCEL_LUTGHOLEIN_ALT_MINI 0x14

#define TOWNCEL_LUTGHOLEIN_FULL 0

#define TOWNCEL_LUTGHOLEIN_ALT_FULL 0x14

#define TOWNCEL_PANDFORT_MINI 0

#define TOWNCEL_PANDFORT_FULL 0

#define TOWNCEL_HARROGATH_MINI 0

#define TOWNCEL_HARROGATH_FULL 0







struct D2CropRectStrc
{
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};



static void AUTOMAP_WriteAutomapLayer(D2AutomapSaveStrc* pSave); // 0x00458200


static void __stdcall AUTOMAP_AddUnitAutomapCell(int nCellNo, D2AutomapCellStrc** ppRoot, D2UnitStrc* pUnit); // 0x00457E80

void __stdcall AUTOMAP_AddTownCelsCallback(int nLevelId, int nPickedFile, int nX, int nY); // 0x004591A0

static void AUTOMAP_DrawAutomapUnit(D2UnitStrc* pUnit); // 0x0045A860

// 0x0040E850
unsigned __int64 __cdecl AUTOMAP_ReadTimeStampCounter()
{
    unsigned __int64 nTicks;
    __asm
    {
        rdtsc
        mov dword ptr nTicks[0], eax
        mov dword ptr nTicks[4], edx
    }
    return nTicks;
}

// 0x00412000
void __cdecl AUTOMAP_ReleaseFreeBlocks()
{
    int i = 0;
    gpFreeBlockSweep = 0;
    D2CriticalSectionStrc* pLock = gaFreeBlockLocks_00776CC0;
    int n = 0x100;
    do
    {
        if (gabFreeBlockDirty[i])
        {
            EnterCriticalSection(pLock);
            gabFreeBlockDirty[i] = 0;
            D2FogBlockStrc** ppLink = &gapFreeBlocks_007768B8[i];
            while (*ppLink)
            {
                D2FogBlockStrc* pBlock = *ppLink;
                if (!pBlock->bInUse && pBlock->dwSize < 0x80000000)
                    UnlinkAndFreeHeap(ppLink);
                else
                    ppLink = &pBlock->pNext;
            }
            LeaveCriticalSection(pLock);
        }
        ++i;
        ++pLock;
    } while (--n);
}

// 0x00414220
double __fastcall AUTOMAP_PowInt(double x, int nExp)
{
    const double one = 1.0;
    unsigned int nBits = nExp >= 0 ? (unsigned int)nExp : (unsigned int)-nExp;
    double z = one;
    for (;;)
    {
        if (nBits & 1)
            z *= x;
        nBits >>= 1;
        if (nBits == 0)
            break;
        x *= x;
    }
    return nExp < 0 ? one / z : z;
}

// 0x0043C540
void __fastcall AUTOMAP_InitCharSaveHeader(const char* szName, unsigned char nClass, unsigned char* pStream, unsigned short wFlags)
{
    memset(&gtCharSaveHeader, 0, 0x14F);
    gtCharSaveHeader.dwMagic = 0xAA55AA55;
    gtCharSaveHeader.dwVersion = 0x60;
    SStrCopy(gtCharSaveHeader.szName, szName, 0x7FFFFFFF);
    gtCharSaveHeader.nClass = nClass;
    gtCharSaveHeader.nUnk0x2B = 1;
    gtCharSaveHeader.dwFlags = wFlags | 1;
    gtCharSaveHeader.nCreateTime = _time32(0);
    gtCharSaveHeader.nSaveTime = gtCharSaveHeader.nCreateTime;
    gtCharSaveHeader.dwSize = 0x14F;
    gtCharSaveHeader.nUnk0x29 = 0x10;
    gtCharSaveHeader.nUnk0x2A = 0x1E;
    if (nClass == 6 || nClass == 5)
        gtCharSaveHeader.dwFlags |= 0x20;
    FOG_Encode14BitsToString(pStream, 0xE);
    pStream += 2;
    gtCharSaveHeader.tId = gtCharSaveId;
    for (int i = 0; i < 11; ++i)
        *pStream++ = gtCharSaveId.f_0[i];
    *pStream++ = nClass + 1;
    memset(gtCharSaveHeader.anUnk0x98, 0xFF, sizeof(gtCharSaveHeader.anUnk0x98));
    memset(pStream, -1, 11);
    pStream += 11;
    const unsigned short wSavedFlags = (unsigned short)gtCharSaveHeader.dwFlags;
    *pStream++ = 1;
    FOG_Encode14BitsToString(pStream, wSavedFlags);
    pStream += 2;
    FOG_Encode14BitsToString(pStream, 0);
    pStream += 2;
    *pStream++ = 0xFF;
    *pStream++ = 0xFF;
    *pStream++ = 0xFF;
    *pStream = 0;
}

inline int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
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

inline int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
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


// 0x00452580
int __fastcall AUTOMAP_GetHoverMonsterName(D2UnitStrc* pUnit, int nArg)
{
    int nTick;
    if (sub_0045AE90_GetPanelSlideMode() == 3)
    {
        return 0;
    }
    if (NPCMENU_GetInteractNpcId(&nTick))
    {
        return 0;
    }
    gwszHoverName[0].wChar = 0;
    if (!MONSTER_IsUniqueMonster(pUnit) && !MONSTER_IsMinionMonster(pUnit))
    {
        return 0;
    }
    MONSTER_GetMonsterName(pUnit, gwszHoverName, 0x100, nArg);
    return 1;
}

// 0x00457420
void __fastcall AUTOMAP_FreeCaches(int bFree)
{
    D2CMPTileCacheDestroy(bFree);
    D2CMPSpriteCacheDestroy(bFree);
    GFX_FreeHashedFiles();
}

// 0x00457440
void __fastcall sub_00457440_Nop(int nUnused)
{
}

struct AUTOMAP_SetUnitFlag;

struct Obj00457460;

struct AUTOMAP_SetUnitFlag {
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

struct Obj00457460 {
    AUTOMAP_SetUnitFlag tPad000;
    AUTOMAP_SetUnitFlag tPad040;
    AUTOMAP_SetUnitFlag tPad080;
    unsigned int dwUnknownC0;
    unsigned int dwFlagsC4;
};

void __fastcall AUTOMAP_SetUnitFlag(D2UnitStrc* pUnit, int nArg, int nValue);                                      // 0x00457460

// 0x00457460
extern "C" __declspec(dllexport) void __fastcall AUTOMAP_SetUnitFlag(Obj00457460* pObj, unsigned int dwMask, int bSet) {
    if (pObj) {
        if (bSet) {
            pObj->dwFlagsC4 |= dwMask;
        } else {
            pObj->dwFlagsC4 &= ~dwMask;
        }
    }
}

extern unsigned int gdwBitMasks[]; // 0x006CE268

inline D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecordInline(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// 0x00457490
int __fastcall MONSTERUNIQUE_CheckMonStatsFlag(int nMonsterId, int nFlag)
{
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInline(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }
    return pMonStatsTxtRecord->nMonStatsFlags[nFlag >> 3] & gdwBitMasks[nFlag & 7];
}

// 0x004574D0
void __stdcall AUTOMAP_IncreaseBaseY(int nUnused)
{
    gnAutomapBaseY += 0x10;
}

// 0x004574E0
void __stdcall AUTOMAP_DecreaseBaseY(int nUnused)
{
    gnAutomapBaseY -= 0x10;
}

// 0x004574F0
void __stdcall AUTOMAP_DecreaseBaseX(int nUnused)
{
    gnAutomapBaseX -= 0x10;
}

// 0x00457500
void __stdcall AUTOMAP_IncreaseBaseX(int nUnused)
{
    gnAutomapBaseX += 0x10;
}

// 0x00457510
void __stdcall sub_00457510_Nop(int nUnused1)
{
}

// 0x00457520
void __cdecl AUTOMAP_UpdateAutomapLayout()
{
    if (gbLayoutPetIconVisible != VIEW_IsPetIconVisible() && gnAutomapMode == 1)
    {
        gbLayoutPetIconVisible = VIEW_IsPetIconVisible();
        AUTOMAP_ResetBaseOffset(1);
        return;
    }
    if (gbLayoutAutomapLeft != gbAutomapLeft && gnAutomapMode == 1)
    {
        gbLayoutAutomapLeft = gbAutomapLeft;
        AUTOMAP_ResetBaseOffset(1);
        return;
    }
    if (gbAutomapLeft)
    {
        gnMiniMapX = 0;
        gnMiniMapY = VIEW_IsPetIconVisible() ? 0x60 : 0;
    }
    else
    {
        gnMiniMapX = gnScreenWidth * 2 / 3;
        gnMiniMapY = 0x4E;
    }
    gnMiniMapSavedX = gnMiniMapX;
    gnMiniMapSavedY = gnMiniMapY;
    switch (gnAutomapMode)
    {
    case 1:
        gnAutomapClipLeft = gnMiniMapX - 8;
        gnAutomapClipRight = gnScreenWidth / 3 + gnMiniMapX;
        gnAutomapClipTop = gnMiniMapY;
        gnAutomapClipBottom = gnScreenHeight / 3 + gnMiniMapY;
        break;
    default:
        gnAutomapClipRight = gnScreenWidth;
        gnAutomapClipLeft = -16;
        gnAutomapClipTop = -16;
        gnAutomapClipBottom = gnScreenHeight;
        break;
    }
}

// 0x00457640
void __fastcall AUTOMAP_ResetBaseOffset(int bForce)
{
    if (!gbAutomapCenter && !bForce)
    {
        return;
    }

    AUTOMAP_UpdateAutomapLayout();
    switch (gnAutomapMode)
    {
    case 1:
        gnAutomapBaseX = gnScreenWidth / 3 - gnMiniMapX - 0x10;
        gnAutomapBaseY = gnScreenHeight / 3 - gnMiniMapY - 0x10;
        break;
    default:
        gnAutomapBaseX = 0;
        gnAutomapBaseY = 0;
        break;
    }
}

// 0x004576C0
int __cdecl AUTOMAP_GetAutomapFade()
{
    if (gnAutomapMode == 1 && gdwAutoMapFade == 1)
    {
        gdwAutoMapFade = gdwAutoMapFadeSaved ? 0 : 2;
    }
    return gdwAutoMapFade;
}

// 0x004576F0
int __fastcall AUTOMAP_SetAutomapFade(int nFade)
{
    if (gnAutomapMode == 1 && nFade == 1)
    {
        nFade = gdwAutoMapFadeSaved ? 0 : 2;
        gdwAutoMapFade = 1;
    }
    SRegSaveValue("Diablo II", "AutoMapFade", 0, nFade);
    gdwAutoMapFadeSaved = nFade;
    gdwAutoMapFade = nFade;
    return nFade;
}


// 0x00457740
int __cdecl AUTOMAP_GetAutomapCenters()
{
    return gbAutomapCenter;
}

// 0x00457750
int __fastcall AUTOMAP_SaveAutomapCenters(int nValue)
{
    SRegSaveValue("Diablo II", "AutoMap Centers", 0, nValue);
    gbAutomapCenter = nValue;
    return nValue;
}

// 0x00457770
int __cdecl AUTOMAP_GetAutomapLeft()
{
    return gbAutomapLeft;
}

// 0x00457780
int __fastcall AUTOMAP_SaveAutomapLeft(int nValue)
{
    SRegSaveValue("Diablo II", "AutoMap Left", 0, nValue);
    gbAutomapLeftPrev = nValue;
    gbAutomapLeftSaved = nValue;
    gbAutomapLeft = nValue;
    return nValue;
}

// 0x004577B0
int __cdecl AUTOMAP_GetAutomapParty()
{
    return gbAutomapParty;
}

// 0x004577C0
int __fastcall AUTOMAP_SaveAutomapParty(int nValue)
{
    SRegSaveValue("Diablo II", "AutoMap Party", 0, nValue);
    gbAutomapParty = nValue;
    return nValue;
}

// 0x004577E0
int __cdecl AUTOMAP_GetAutomapPartyNames()
{
    return gbAutomapPartyNames;
}

// 0x004577F0
int __fastcall AUTOMAP_SaveAutomapPartyNames(int nValue)
{
    SRegSaveValue("Diablo II", "AutoMap Party Names", 0, nValue);
    gbAutomapPartyNames = nValue;
    return nValue;
}

static void AUTOMAP_RotateCellLeft(D2AutomapCellStrc** ppNode); // 0x00457860

// 0x00457860
static void AUTOMAP_RotateCellLeft(D2AutomapCellStrc** ppNode)
{
    D2AutomapCellStrc* pNode = *ppNode;
    D2_ASSERT(pNode, 0x233);
    D2AutomapCellStrc* pNext = pNode->pNext;
    D2_ASSERT(pNext, 0x234);
    pNode->pNext = pNext->pPrev;
    pNext->pPrev = pNode;
    *ppNode = pNext;
}

// 0x004578B0
static void AUTOMAP_RotateCellRight(D2AutomapCellStrc** ppNode)
{
    D2AutomapCellStrc* pNode = *ppNode;
    D2_ASSERT(pNode, 0x244);
    D2AutomapCellStrc* pPrev = pNode->pPrev;
    D2_ASSERT(pPrev, 0x245);
    pNode->pPrev = pPrev->pNext;
    pPrev->pNext = pNode;
    *ppNode = pPrev;
}

// 0x00457900
void __stdcall AUTOMAP_BalanceLeftHeavy(D2AutomapCellStrc** ppRoot)
{
    D2AutomapCellStrc* pNode = *ppRoot;
    D2AutomapCellStrc* pPrev = pNode->pPrev;
    D2_ASSERT(pPrev->wWeight == -1 || pPrev->wWeight == 1, 0x259);
    if (pPrev->wWeight == -1)
    {
        pNode->wWeight = 0;
        pPrev->wWeight = 0;
        AUTOMAP_RotateCellRight(&pNode);
    }
    else
    {
        D2AutomapCellStrc* pPrevNext = pPrev->pNext;
        switch (pPrevNext->wWeight)
        {
        case -1:
            pNode->wWeight = 1;
            pPrev->wWeight = 0;
            break;
        case 0:
            pNode->wWeight = 0;
            pPrev->wWeight = 0;
            break;
        case 1:
            pNode->wWeight = 0;
            pPrev->wWeight = -1;
            break;
        }
        pPrevNext->wWeight = 0;
        AUTOMAP_RotateCellLeft(&pNode->pPrev);
        AUTOMAP_RotateCellRight(&pNode);
    }
    *ppRoot = pNode;
}

// 0x004579E0
void __stdcall AUTOMAP_BalanceRightHeavy(D2AutomapCellStrc** ppRoot)
{
    D2AutomapCellStrc* pNode = *ppRoot;
    D2AutomapCellStrc* pNext = pNode->pNext;
    D2_ASSERT(pNext->wWeight == -1 || pNext->wWeight == 1, 0x294);
    if (pNext->wWeight == 1)
    {
        pNode->wWeight = 0;
        pNext->wWeight = 0;
        AUTOMAP_RotateCellLeft(&pNode);
    }
    else
    {
        D2AutomapCellStrc* pNextPrev = pNext->pPrev;
        switch (pNextPrev->wWeight)
        {
        case -1:
            pNode->wWeight = 0;
            pNext->wWeight = 1;
            break;
        case 0:
            pNode->wWeight = 0;
            pNext->wWeight = 0;
            break;
        case 1:
            pNode->wWeight = -1;
            pNext->wWeight = 0;
            break;
        }
        pNextPrev->wWeight = 0;
        AUTOMAP_RotateCellRight(&pNode->pNext);
        AUTOMAP_RotateCellLeft(&pNode);
    }
    *ppRoot = pNode;
}

// 0x00457AC0
int __fastcall AUTOMAP_CompareAutomapCells(const D2AutomapCellStrc* pA, const D2AutomapCellStrc* pB)
{
    int nResult = pA->yPixel - pB->yPixel;
    if (!nResult)
    {
        nResult = pA->xPixel - pB->xPixel;
        if (!nResult)
        {
            const int nCellA = pA->nCellNo;
            if (gaAutomapCellTable[nCellA] != -1)
            {
                const int nCellB = pB->nCellNo;
                if (gaAutomapCellTable[nCellA] != gaAutomapCellTable[nCellB])
                {
                    nResult = nCellA - nCellB;
                }
            }
        }
    }

    return nResult;
}

// 0x00457B00
int __fastcall AUTOMAP_InsertAutomapCell(D2AutomapCellStrc* pCell, D2AutomapCellStrc** ppRoot)
{
    D2AutomapCellStrc* pRoot = *ppRoot;
    D2AutomapCellStrc* pRotate = pRoot;
    int nResult;
    if (pRoot)
    {
        int nDiff = pCell->yPixel - pRoot->yPixel;
        if (!nDiff)
        {
            nDiff = pCell->xPixel - pRoot->xPixel;
            if (!nDiff)
            {
                const int nValue = gaAutomapCellTable[pCell->nCellNo];
                if (nValue != -1 && nValue != gaAutomapCellTable[pRoot->nCellNo])
                    nDiff = pCell->nCellNo - pRoot->nCellNo;
            }
        }
        if (nDiff < 0)
        {
            nResult = AUTOMAP_InsertAutomapCell(pCell, &pRoot->pPrev);
            if (nResult)
            {
                switch (pRoot->wWeight)
                {
                case -1:
                    AUTOMAP_BalanceLeftHeavy(&pRotate);
                    pRoot = pRotate;
                    nResult = 0;
                    break;
                case 0:
                    pRoot->wWeight = -1;
                    break;
                case 1:
                    pRoot->wWeight = 0;
                    nResult = 0;
                    break;
                }
            }
        }
        else if (nDiff > 0)
        {
            nResult = AUTOMAP_InsertAutomapCell(pCell, &pRoot->pNext);
            if (nResult)
            {
                switch (pRoot->wWeight)
                {
                case -1:
                    pRoot->wWeight = 0;
                    nResult = 0;
                    break;
                case 0:
                    pRoot->wWeight = 1;
                    break;
                case 1:
                    AUTOMAP_BalanceRightHeavy(&pRotate);
                    pRoot = pRotate;
                    nResult = 0;
                    break;
                }
            }
        }
        else
        {
            nResult = 0;
        }
    }
    else
    {
        pCell->pPrev = 0;
        pCell->pNext = 0;
        pRoot = pCell;
        pCell->wWeight = 0;
        nResult = 1;
    }
    *ppRoot = pRoot;
    return nResult;
}


// 0x00457C30
D2AutomapCellStrc* __cdecl AUTOMAP_AllocAutomapCell()
{
    D2AutomapCellBlockStrc* current = gpCellBlocks_007A5158;
    D2AutomapCellBlockStrc* previous = 0;
    int blockIndex = gnAutomapCellCount / 512;
    int cellIndex = gnAutomapCellCount % 512;
    int i = 0;
    ++gnAutomapCellCount;
    if (gpCellBlocks_007A5158)
    {
        for (; current && i < blockIndex; ++i)
        {
            previous = current;
            current = current->pNext;
        }
    }
    else
    {
        current = 0;
    }
    if (!current)
    {
        current = (D2AutomapCellBlockStrc*)FOG_Alloc(sizeof(D2AutomapCellBlockStrc), ".\\UI\\automap.cpp", 0x35D, 0);
        memset(current, 0, sizeof(D2AutomapCellBlockStrc));
        if (previous)
            previous->pNext = current;
        else
            gpCellBlocks_007A5158 = current;
    }
    D2AutomapCellStrc* cell = &current->cells[cellIndex];
    memset(cell, 0, sizeof(D2AutomapCellStrc));
    return cell;
}

// 0x00457CF0
static void __stdcall AUTOMAP_RevealAutomapTile(D2DrlgTileDataStrc* pTileData, D2AutomapRoomStrc* pRoom, D2AutomapCellStrc** ppRoot)
{
    if (pTileData->dwFlags & 0x40000)
    {
        return;
    }
    pTileData->dwFlags |= 0x40000;
    void* pLevelType = DRLG_GetLevelTypeFromLevelId(pRoom->pLevel->eLevelId);
    const int nType = TileGetType(pTileData->pTile);
    const int nStyle = TileGetStyle(pTileData->pTile);
    const int nSequence = TileGetSequence(pTileData->pTile);
    const int nCell = DATATBLS_GetAutomapCellId(pLevelType, nType, nStyle, nSequence);
    if (nCell == -1)
    {
        return;
    }
    D2AutomapCellStrc* pCell = AUTOMAP_AllocAutomapCell();
    int nX = pRoom->nPosX + pTileData->nPosX;
    int nY = pRoom->nPosY + pTileData->nPosY;
    DUNGEON_GameTileToClientCoords(&nX, &nY);
    nX /= 10;
    nY /= 10;
    D2_ASSERT(nX >= -0x8000 && nX <= 0x7FFF, 913);
    D2_ASSERT(nY >= -0x8000 && nY <= 0x7FFF, 914);
    D2_ASSERT(nCell >= -0x8000 && nCell <= 0x7FFF, 915);
    if (pTileData->nTileType >= 0x10)
    {
        nY += 0x18;
    }
    pCell->nCellNo = nCell;
    pCell->xPixel = nX;
    pCell->yPixel = nY;
    AUTOMAP_InsertAutomapCell(pCell, ppRoot);
}

// 0x00457E40
void __stdcall AUTOMAP_AddAutomapCell(unsigned short nCellNo, unsigned short xPixel, unsigned short yPixel, D2AutomapCellStrc** ppRoot, unsigned int fSaved)
{
    D2AutomapCellStrc* pCell = AUTOMAP_AllocAutomapCell();
    pCell->fSaved = fSaved;
    pCell->nCellNo = nCellNo;
    pCell->xPixel = xPixel;
    pCell->yPixel = yPixel;
    AUTOMAP_InsertAutomapCell(pCell, ppRoot);
}

// 0x00457E80
static void __stdcall AUTOMAP_AddUnitAutomapCell(int nCellNo, D2AutomapCellStrc** ppRoot, D2UnitStrc* pUnit)
{
    D2AutomapCellStrc* pCell = AUTOMAP_AllocAutomapCell();
    const int nX = UNITS_GetClientCoordX(pUnit) / 10 + 1;
    const int nY = UNITS_GetClientCoordY(pUnit) / 10 - 3;
    D2_ASSERT(nX >= -0x8000 && nX <= 0x7FFF, 0x3C5);
    D2_ASSERT(nY >= -0x8000 && nY <= 0x7FFF, 0x3C6);
    D2_ASSERT(nCellNo >= -0x8000 && nCellNo <= 0x7FFF, 0x3C7);
    pCell->nCellNo = nCellNo;
    pCell->xPixel = nX;
    pCell->yPixel = nY;
    AUTOMAP_InsertAutomapCell(pCell, ppRoot);
}

// 0x00457F40
void* __cdecl AUTOMAP_OpenAutomapFile()
{
    char szSavePath[0x104] = { 0 };
    char szFileName[0x104] = { 0 };
    char szAccountPath[0x104] = { 0 };

    FOG_GetSavePath(szSavePath, sizeof(szSavePath));

    void* hFile = (void*)-1;
    if (gszRealm[0])
    {
        SStrPrintf(szAccountPath, sizeof(szAccountPath), "%s%s\\", szSavePath, gszRealm);
        FOG_CreatePathHierarchy(szAccountPath);
        SStrPrintf(szFileName, sizeof(szFileName), "%s%s.map", szAccountPath, gszClientCharName);
        hFile = FOG_CreateFileA(szFileName, 0xC0000000, 0, 0, 4, 0x80, 0);
        if (hFile != (void*)-1)
        {
            SStrCopy(szSavePath, szAccountPath, sizeof(szSavePath));
        }
    }

    if (hFile == (void*)-1)
    {
        sprintf(szFileName, "%s%s.map", szSavePath, gszClientCharName);
        hFile = FOG_CreateFileA(szFileName, 0xC0000000, 0, 0, 4, 0x80, 0);
        if (hFile == (void*)-1)
        {
            return hFile;
        }
    }

    D2AutomapFileHeaderStrc tHeader = { 0 };
    unsigned long nBytes = 0;
    FOG_ReadFile(hFile, &tHeader, sizeof(tHeader), &nBytes, 0);

    int bInvalid = 1;
    if (nBytes == sizeof(tHeader))
    {
        bInvalid = tHeader.nVersion != 12;
    }

    int nIndex;
    if (bInvalid)
    {
        tHeader.nVersion = 12;
        tHeader.nNext = 1;
        tHeader.nSeeds[0] = gpAutomapRecord->nGameSeed;
        for (int i = 0; i < 4; ++i)
        {
            sprintf(szFileName, "%s%s.ma%d", szSavePath, gszClientCharName, i);
            FOG_DeleteFileA(szFileName);
        }
        nIndex = 0;
    }
    else
    {
        for (nIndex = 0; nIndex < 4; ++nIndex)
        {
            if (tHeader.nSeeds[nIndex] == gpAutomapRecord->nGameSeed)
            {
                break;
            }
        }

        if (nIndex != 4)
        {
            goto reopen;
        }

        nIndex = tHeader.nNext;
        tHeader.nNext = (nIndex + 1) % 4;
        tHeader.nSeeds[nIndex] = gpAutomapRecord->nGameSeed;
        sprintf(szFileName, "%s%s.ma%d", szSavePath, gszClientCharName, nIndex);
        FOG_DeleteFileA(szFileName);
    }

    FOG_SetFilePointer(hFile, 0, 0, 0);
    FOG_WriteFile(hFile, &tHeader, sizeof(tHeader), &nBytes, 0);

reopen:
    FOG_CloseFile(hFile);
    sprintf(szFileName, "%s%s.ma%d", szSavePath, gszClientCharName, nIndex);
    return FOG_CreateFileA(szFileName, 0xC0000000, 0, 0, 4, 0x80, 0);
}

// 0x00458200
static void AUTOMAP_WriteAutomapLayer(D2AutomapSaveStrc* pSave)
{
    void* hFile = AUTOMAP_OpenAutomapFile();
    if (hFile == (void*)-1)
    {
        return;
    }
    unsigned int anOffsets[100] = { 0 };
    unsigned long nCount = 0;
    FOG_ReadFile(hFile, anOffsets, sizeof(anOffsets), &nCount, 0);
    if (nCount != sizeof(anOffsets))
    {
        memset(anOffsets, 0, sizeof(anOffsets));
        FOG_SetFilePointer(hFile, 0, 0, 0);
        FOG_WriteFile(hFile, anOffsets, sizeof(anOffsets), &nCount, 0);
    }
    unsigned int nOffset = anOffsets[pSave->nLayerNo];
    unsigned int nEnd = GetFileSize(hFile, 0);
    if (nOffset)
    {
        unsigned int nPrev;
        do
        {
            FOG_SetFilePointer(hFile, nOffset, 0, 0);
            nPrev = nOffset;
            FOG_ReadFile(hFile, &nOffset, 4, &nCount, 0);
        }
        while (nOffset);
        FOG_SetFilePointer(hFile, nPrev, 0, 0);
        FOG_WriteFile(hFile, &nEnd, 4, &nCount, 0);
    }
    else
    {
        anOffsets[pSave->nLayerNo] = nEnd;
    }
    FOG_SetFilePointer(hFile, 0, 0, 0);
    FOG_WriteFile(hFile, anOffsets, sizeof(anOffsets), &nCount, 0);
    FOG_SetFilePointer(hFile, nEnd, 0, 0);
    nEnd = 0;
    FOG_WriteFile(hFile, &nEnd, 4, &nCount, 0);
    FOG_WriteFile(hFile, &pSave->nLayerNo, 4, &nCount, 0);
    FOG_WriteFile(hFile, &pSave->fSaved, 4, &nCount, 0);
    FOG_WriteFile(hFile, &pSave->nObjectSeed, 4, &nCount, 0);
    FOG_WriteFile(hFile, &pSave->dwFloorSize, 4, &nCount, 0);
    FOG_WriteFile(hFile, &pSave->dwWallsSize, 4, &nCount, 0);
    FOG_WriteFile(hFile, &pSave->nObjects, 4, &nCount, 0);
    FOG_WriteFile(hFile, &pSave->dwExtraSize, 4, &nCount, 0);
    if (pSave->dwFloorSize)
        FOG_WriteFile(hFile, pSave->pFloors, pSave->dwFloorSize, &nCount, 0);
    if (pSave->dwWallsSize)
        FOG_WriteFile(hFile, pSave->pWalls, pSave->dwWallsSize, &nCount, 0);
    if (pSave->nObjects)
        FOG_WriteFile(hFile, pSave->pObjects, pSave->nObjects, &nCount, 0);
    if (pSave->dwExtraSize)
        FOG_WriteFile(hFile, pSave->pExtras, pSave->dwExtraSize, &nCount, 0);
    FOG_CloseFile(hFile);
}

// 0x00458440
void __fastcall AUTOMAP_CountCells(D2AutomapCellStrc* pCells, unsigned int* pCount)
{
    if (!pCells)
    {
        return;
    }
    AUTOMAP_CountCells(pCells->pPrev, pCount);
    if (!pCells->fSaved)
    {
        *pCount += 6;
    }
    AUTOMAP_CountCells(pCells->pNext, pCount);
}

// 0x00458470
void __fastcall AUTOMAP_StoreCells(D2AutomapCellStrc* pCells)
{
    if (!pCells)
    {
        return;
    }
    AUTOMAP_StoreCells(pCells->pPrev);
    if (!pCells->fSaved)
    {
        unsigned short* pBuffer = (unsigned short*)gpAutomapSaveBuffer;
        *pBuffer = pCells->nCellNo;
        ++pBuffer;
        *pBuffer = pCells->xPixel;
        ++pBuffer;
        *pBuffer = pCells->yPixel;
        ++pBuffer;
        gpAutomapSaveBuffer = pBuffer;
    }
    AUTOMAP_StoreCells(pCells->pNext);
}

// 0x004584C0
void __cdecl AUTOMAP_SaveAutomapLayer()
{
    D2AutomapLayerStrc* pLayer = gpAutomapContext;
    if (!pLayer)
    {
        return;
    }
    D2AutomapSaveStrc tSave;
    memset(&tSave.fSaved, 0, sizeof(tSave) - sizeof(tSave.nLayerNo));
    tSave.nLayerNo = pLayer->nLayerNo;
    tSave.fSaved = pLayer->fSaved;
    tSave.nObjectSeed = gpAutomapRecord->nValue;
    AUTOMAP_CountCells(pLayer->pFloors, &tSave.dwFloorSize);
    AUTOMAP_CountCells(pLayer->pWalls, &tSave.dwWallsSize);
    AUTOMAP_CountCells(pLayer->pObjects, &tSave.nObjects);
    AUTOMAP_CountCells(pLayer->pExtras, &tSave.dwExtraSize);
    if (!tSave.dwFloorSize && !tSave.dwWallsSize && !tSave.nObjects && !tSave.dwExtraSize)
    {
        return;
    }
    if (tSave.dwFloorSize)
    {
        tSave.pFloors = FOG_Alloc(tSave.dwFloorSize, gszAutomapFile, 0x4EA, 0);
        gpAutomapSaveBuffer = tSave.pFloors;
        AUTOMAP_StoreCells(gpAutomapContext->pFloors);
    }
    if (tSave.dwWallsSize)
    {
        tSave.pWalls = FOG_Alloc(tSave.dwWallsSize, gszAutomapFile, 0x4F1, 0);
        gpAutomapSaveBuffer = tSave.pWalls;
        AUTOMAP_StoreCells(gpAutomapContext->pWalls);
    }
    if (tSave.nObjects)
    {
        tSave.pObjects = FOG_Alloc(tSave.nObjects, gszAutomapFile, 0x4F8, 0);
        gpAutomapSaveBuffer = tSave.pObjects;
        AUTOMAP_StoreCells(gpAutomapContext->pObjects);
    }
    if (tSave.dwExtraSize)
    {
        tSave.pExtras = FOG_Alloc(tSave.dwExtraSize, gszAutomapFile, 0x4FF, 0);
        gpAutomapSaveBuffer = tSave.pExtras;
        AUTOMAP_StoreCells(gpAutomapContext->pExtras);
    }
    AUTOMAP_WriteAutomapLayer(&tSave);
    if (tSave.pFloors)
        FOG_Free(tSave.pFloors, gszAutomapFile, 0x509, 0);
    if (tSave.pWalls)
        FOG_Free(tSave.pWalls, gszAutomapFile, 0x50A, 0);
    if (tSave.pObjects)
        FOG_Free(tSave.pObjects, gszAutomapFile, 0x50B, 0);
    if (tSave.pExtras)
        FOG_Free(tSave.pExtras, gszAutomapFile, 0x50C, 0);
}

// 0x00458680
void __cdecl AUTOMAP_ResetAutomapCells()
{
    if (gpAutomapContext)
    {
        D2AutomapCellBlockStrc* pBlock = gpAutomapCellBlocks;
        while (pBlock)
        {
            D2AutomapCellBlockStrc* pFree = pBlock;
            pBlock = pBlock->pNext;
            FOG_Free(pFree, ".\\UI\\automap.cpp", 0x51E, 0);
        }
        gpAutomapCellBlocks = 0;
        gnAutomapCellCount = 0;
        gpAutomapContext->pFloors = 0;
        gpAutomapContext->pWalls = 0;
        gpAutomapContext->pObjects = 0;
        gpAutomapContext->pExtras = 0;
    }
}

// 0x004586E0
static void __stdcall AUTOMAP_UnlinkAutomapLayer(void* hFile, unsigned int* pOffsets, unsigned int nPrev)
{
    unsigned long nCount = 0;
    if (nPrev)
    {
        FOG_SetFilePointer(hFile, nPrev, 0, 0);
        nPrev = 0;
        FOG_WriteFile(hFile, &nPrev, 4, &nCount, 0);
    }
    else
    {
        pOffsets[gpAutomapContext->nLayerNo] = 0;
        FOG_SetFilePointer(hFile, 0, 0, 0);
        FOG_WriteFile(hFile, pOffsets, 0x190, &nCount, 0);
    }
}

// 0x00458750
void __cdecl AUTOMAP_LoadAutomapLayer()
{
    if (!gpAutomapContext)
    {
        return;
    }
    void* hFile = AUTOMAP_OpenAutomapFile();
    if (hFile == (void*)-1)
    {
        return;
    }
    unsigned int anOffsets[100] = { 0 };
    unsigned long nCount = 0;
    FOG_ReadFile(hFile, anOffsets, sizeof(anOffsets), &nCount, 0);
    if (nCount == sizeof(anOffsets))
    {
        unsigned int nRecord = 0;
        unsigned int nLink = anOffsets[gpAutomapContext->nLayerNo];
        unsigned short* pData;
        unsigned int nWords;
        unsigned int i;
        while (nLink)
        {
            D2AutomapSaveStrc tSave = { 0 };
            FOG_SetFilePointer(hFile, nLink, 0, 0);
            FOG_ReadFile(hFile, &nLink, 4, &nCount, 0);
            FOG_ReadFile(hFile, &tSave.nLayerNo, 4, &nCount, 0);
            FOG_ReadFile(hFile, &tSave.fSaved, 4, &nCount, 0);
            FOG_ReadFile(hFile, &tSave.nObjectSeed, 4, &nCount, 0);
            FOG_ReadFile(hFile, &tSave.dwFloorSize, 4, &nCount, 0);
            FOG_ReadFile(hFile, &tSave.dwWallsSize, 4, &nCount, 0);
            FOG_ReadFile(hFile, &tSave.nObjects, 4, &nCount, 0);
            FOG_ReadFile(hFile, &tSave.dwExtraSize, 4, &nCount, 0);
            if (tSave.nLayerNo != gpAutomapContext->nLayerNo)
            {
                AUTOMAP_UnlinkAutomapLayer(hFile, anOffsets, nRecord);
                break;
            }
            if (tSave.dwFloorSize)
            {
                pData = (unsigned short*)FOG_Alloc(tSave.dwFloorSize, ".\\UI\\automap.cpp", 0x575, 0);
                nWords = tSave.dwFloorSize / 2;
                FOG_ReadFile(hFile, pData, tSave.dwFloorSize, &nCount, 0);
                D2_ASSERT(nCount == tSave.dwFloorSize, 0x57A);
                for (i = 0; i < nWords; i += 3)
                {
                    if ((short)pData[i] >= gaAutomapCelFrames[0])
                    {
                        AUTOMAP_UnlinkAutomapLayer(hFile, anOffsets, nRecord);
                        break;
                    }
                    AUTOMAP_AddAutomapCell(pData[i], pData[i + 1], pData[i + 2], &gpAutomapContext->pFloors, 1);
                }
                FOG_Free(pData, ".\\UI\\automap.cpp", 0x586, 0);
            }
            if (tSave.dwWallsSize)
            {
                pData = (unsigned short*)FOG_Alloc(tSave.dwWallsSize, ".\\UI\\automap.cpp", 0x58A, 0);
                nWords = tSave.dwWallsSize / 2;
                FOG_ReadFile(hFile, pData, tSave.dwWallsSize, &nCount, 0);
                D2_ASSERT(nCount == tSave.dwWallsSize, 0x58F);
                for (i = 0; i < nWords; i += 3)
                {
                    if ((short)pData[i] >= gaAutomapCelFrames[0])
                    {
                        AUTOMAP_UnlinkAutomapLayer(hFile, anOffsets, nRecord);
                        break;
                    }
                    AUTOMAP_AddAutomapCell(pData[i], pData[i + 1], pData[i + 2], &gpAutomapContext->pWalls, 1);
                }
                FOG_Free(pData, ".\\UI\\automap.cpp", 0x59B, 0);
            }
            if (tSave.nObjects)
            {
                if (tSave.nObjectSeed == gpAutomapRecord->nValue)
                {
                    pData = (unsigned short*)FOG_Alloc(tSave.nObjects, ".\\UI\\automap.cpp", 0x5A2, 0);
                    nWords = tSave.nObjects / 2;
                    FOG_ReadFile(hFile, pData, tSave.nObjects, &nCount, 0);
                    D2_ASSERT(nCount == tSave.nObjects, 0x5A7);
                    for (i = 0; i < nWords; i += 3)
                    {
                        if ((short)pData[i] >= gaAutomapCelFrames[0])
                        {
                            AUTOMAP_UnlinkAutomapLayer(hFile, anOffsets, nRecord);
                            break;
                        }
                        AUTOMAP_AddAutomapCell(pData[i], pData[i + 1], pData[i + 2], &gpAutomapContext->pObjects, 1);
                    }
                    FOG_Free(pData, ".\\UI\\automap.cpp", 0x5B3, 0);
                }
                else
                {
                    FOG_SetFilePointer(hFile, tSave.nObjects, 0, 1);
                }
            }
            if (tSave.dwExtraSize)
            {
                pData = (unsigned short*)FOG_Alloc(tSave.dwExtraSize, ".\\UI\\automap.cpp", 0x5BD, 0);
                nWords = tSave.dwExtraSize / 2;
                FOG_ReadFile(hFile, pData, tSave.dwExtraSize, &nCount, 0);
                D2_ASSERT(nCount == tSave.dwExtraSize, 0x5C2);
                for (i = 0; i < nWords; i += 3)
                {
                    if ((short)pData[i] >= gaAutomapCelFrames[tSave.fSaved])
                    {
                        AUTOMAP_UnlinkAutomapLayer(hFile, anOffsets, nRecord);
                        break;
                    }
                    AUTOMAP_AddAutomapCell(pData[i], pData[i + 1], pData[i + 2], &gpAutomapContext->pExtras, 1);
                }
                FOG_Free(pData, ".\\UI\\automap.cpp", 0x5CE, 0);
            }
            nRecord = nLink;
        }
    }
    FOG_CloseFile(hFile);
}



// 0x00458CD0
void __stdcall AUTOMAP_SetAutomapContext(D2AutomapLayerStrc* pContext)
{
    AUTOMAP_SaveAutomapLayer();
    AUTOMAP_ResetAutomapCells();
    gpAutomapContext = pContext;
    AUTOMAP_LoadAutomapLayer();
}

// 0x00458CF0
void __stdcall AUTOMAP_PushAutomapLayer(int nValue)
{
    D2AutomapLayerStrc* pNode = (D2AutomapLayerStrc*)FOG_Alloc(sizeof(D2AutomapLayerStrc), ".\\UI\\automap.cpp", 0x5ED, 0);
    D2AutomapLayerStrc* pHead = gpAutomapNodes;
    memset(&pNode->fSaved, 0, sizeof(pNode->fSaved) + 4 * sizeof(D2AutomapCellStrc*));
    pNode->nLayerNo = nValue;
    pNode->pNext = pHead;
    gpAutomapNodes = pNode;
}

// 0x00458D40
static D2AutomapLayerStrc* AUTOMAP_InitAutomapLayer(int nLayerNo)
{
    D2AutomapLayerStrc* pLayer;
    for (pLayer = gpAutomapNodes; pLayer; pLayer = pLayer->pNext)
    {
        if (pLayer->nLayerNo == nLayerNo)
            break;
    }

    if (!pLayer)
    {
        D2AutomapLayerStrc* pNew = (D2AutomapLayerStrc*)FOG_Alloc(sizeof(D2AutomapLayerStrc), ".\\UI\\automap.cpp", 0x5ED, 0);
        memset(&pNew->fSaved, 0, 5 * sizeof(int));
        D2AutomapLayerStrc* pHead = gpAutomapNodes;
        pNew->nLayerNo = nLayerNo;
        pNew->pNext = pHead;
        gpAutomapNodes = pNew;
        pLayer = pNew;
    }

    if (pLayer != gpAutomapContext)
    {
        AUTOMAP_SaveAutomapLayer();
        AUTOMAP_ResetAutomapCells();
        gpAutomapContext = pLayer;
        AUTOMAP_LoadAutomapLayer();
    }

    return pLayer;
}

static inline int AUTOMAP_CheckFlagEx(D2UnitStrc* pUnit, int nBit)
{
    if (!pUnit)
    {
        return 0;
    }
    return (pUnit->dwFlags >> nBit) & 1;
}

static inline D2MonStats2Txt* AUTOMAP_GetMonStats2TxtRecord(int nMonStatsEx)
{
    if (nMonStatsEx >= 0 && nMonStatsEx < sgptDataTables->nMonStats2TxtRecordCount)
    {
        return &sgptDataTables->pMonStats2Txt[nMonStatsEx];
    }
    return 0;
}

// 0x00458DC0
void __stdcall AUTOMAP_RevealRoomObjects(D2ActiveRoomStrc* pRoom, D2AutomapCellStrc** ppRoot)
{
    for (D2UnitStrc* pUnit = pRoom->pUnitFirst; pUnit; pUnit = pUnit->ptRoomNext)
    {
        const int nFlag = AUTOMAP_CheckFlagEx(pUnit, 28);
        const int nUnitType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
        if (!gbRevealAutomap)
        {
            if (!nFlag)
                continue;

            if (AUTOMAP_CheckFlagEx(pUnit, 29))
                continue;
        }

        if (pUnit)
            pUnit->dwFlags |= 0x20000000;

        switch (nUnitType)
        {
        case UNIT_MONSTER:
            if (pUnit)
            {
                const int nClassId = pUnit->dwClassId;
                if (nClassId >= 0 && nClassId < sgptDataTables->nMonStatsTxtRecordCount)
                {
                    const int nMonStatsEx = sgptDataTables->pMonStatsTxt[nClassId].wMonStatsEx;
                    D2MonStats2Txt* pMonStats2Txt = AUTOMAP_GetMonStats2TxtRecord(nMonStatsEx);
                    if (pMonStats2Txt && pMonStats2Txt->dwAutomapCel)
                        AUTOMAP_AddUnitAutomapCell(pMonStats2Txt->dwAutomapCel, ppRoot, pUnit);
                }
            }
            break;

        case UNIT_OBJECT:
        {
            const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
            D2ObjectsTxt* pObjectsTxt = DATATBLS_GetObjectsTxtRecord(nClassId);
            const unsigned int nAutomap = pObjectsTxt->dwAutomap;
            if (!nAutomap)
                break;

            switch (nClassId)
            {
            default:
                AUTOMAP_AddUnitAutomapCell(nAutomap, ppRoot, pUnit);
                break;

            case 0x192:
                if (DUNGEON_GetLevelIdFromRoom(pRoom) == LEVEL_ARCANESANCTUARY)
                    AUTOMAP_AddUnitAutomapCell(pObjectsTxt->dwAutomap, ppRoot, pUnit);
                break;

            case 0x16E:
                if ((!pUnit ? 0 : pUnit->dwAnimMode) == 2)
                    AUTOMAP_AddUnitAutomapCell(nAutomap, ppRoot, pUnit);
                break;

            case 0x10B:
            {
                const unsigned char nAct = DRLG_GetActNoFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom));
                if (nAct == 2 || nAct == 3)
                    AUTOMAP_AddUnitAutomapCell(pObjectsTxt->dwAutomap, ppRoot, pUnit);
                break;
            }
            }
            break;
        }
        }
    }
}

// 0x00458F40
void __stdcall AUTOMAP_RevealRoomTiles(D2ActiveRoomStrc* pActiveRoom, int bRevealAll, D2AutomapLayerStrc* pLayer)
{
    unsigned int nCount = 0;
    D2AutomapRoomStrc* pRoom = DUNGEON_GetRoomExFromRoom(pActiveRoom);
    D2DrlgTileDataStrc* pTiles = DUNGEON_GetFloorTilesFromRoom(pActiveRoom, &nCount);
    for (unsigned int i = 0; i < nCount; i++)
    {
        D2DrlgTileDataStrc* pTileData = &pTiles[i];
        if (!(pTileData->dwFlags & 8) && ((pTileData->dwFlags & 0x20000) || gbRevealAutomap || bRevealAll))
        {
            AUTOMAP_RevealAutomapTile(pTileData, pRoom, &pLayer->pFloors);
        }
    }
    pTiles = DUNGEON_GetWallTilesFromRoom(pActiveRoom, &nCount);
    for (unsigned int i = 0; i < nCount; i++)
    {
        D2DrlgTileDataStrc* pTileData = &pTiles[i];
        if (!(pTileData->dwFlags & 8) && ((pTileData->dwFlags & 0x20000) || gbRevealAutomap || bRevealAll))
        {
            AUTOMAP_RevealAutomapTile(pTileData, pRoom, &pLayer->pWalls);
        }
    }
    AUTOMAP_RevealRoomObjects(pActiveRoom, &pLayer->pObjects);
}

// 0x00459020
void __cdecl AUTOMAP_UpdateAutomapReveal()
{
    if (gnRevealSkip)
    {
        gnRevealSkip -= 1;
        return;
    }

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(pPlayer, 0x696);
    gnRevealPlayerX = UNITS_GetClientCoordX(pPlayer);
    gnRevealPlayerY = UNITS_GetClientCoordY(pPlayer);

    int nDiffX = gnRevealLastX - gnRevealPlayerX;
    if (nDiffX < 0)
        nDiffX = -nDiffX;

    int nDiffY = gnRevealLastY - gnRevealPlayerY;
    if (nDiffY < 0)
        nDiffY = -nDiffY;

    const int nDistance = (nDiffX > nDiffY ? nDiffY + 2 * nDiffX : nDiffX + 2 * nDiffY) / 2;
    if (nDistance < 0x50)
        return;

    gnRevealLastX = gnRevealPlayerX;
    gnRevealLastY = gnRevealPlayerY;

    D2ActiveRoomStrc* pRoom = CUNIT_GetPlayerRoom();
    if (!pRoom)
        return;

    D2ActiveRoomStrc** ppRoomList = 0;
    unsigned int nNumRooms = 0;
    DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRoomList, &nNumRooms);
    const int nLayerNo = DATATBLS_GetLevelDefRecord(DUNGEON_GetLevelIdFromRoom(pRoom))->dwLayer;
    D2AutomapLayerStrc* pLayer = AUTOMAP_InitAutomapLayer(nLayerNo);
    for (unsigned int i = 0; i < nNumRooms; ++i)
    {
        if (nLayerNo == DATATBLS_GetLevelDefRecord(DUNGEON_GetLevelIdFromRoom(ppRoomList[i]))->dwLayer)
            AUTOMAP_RevealRoomTiles(ppRoomList[i], 0, pLayer);
    }
}

// 0x00459140
void __cdecl AUTOMAP_SkipAutomapReveal()
{
    gnRevealSkip = 2;
}

// 0x00459150
void __stdcall AUTOMAP_RevealRoomCallback(D2ActiveRoomStrc* pRoom)
{
    const int nPrevLayerNo = gpAutomapContext ? gpAutomapContext->nLayerNo : -1;
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    D2AutomapLayerStrc* pLayer = AUTOMAP_InitAutomapLayer(DATATBLS_GetLevelDefRecord(nLevelId)->dwLayer);
    AUTOMAP_RevealRoomTiles(pRoom, 1, pLayer);
    if (nPrevLayerNo != -1)
        AUTOMAP_InitAutomapLayer(nPrevLayerNo);
}

// 0x004591A0
void __stdcall AUTOMAP_AddTownCelsCallback(int nLevelId, int nPickedFile, int nX, int nY)
{
    const int nPrevLayerNo = gpAutomapContext ? gpAutomapContext->nLayerNo : -1;
    D2AutomapLayerStrc* pLayer = AUTOMAP_InitAutomapLayer(DATATBLS_GetLevelDefRecord(nLevelId)->dwLayer);
    int nStepX;
    int nStepY;
    int nRows;
    const int* pSkip;
    int nColumns;
    int nOffsetX;
    int nOffsetY;
    int nCelNo;
    switch (nLevelId)
    {
    case LEVEL_LUTGHOLEIN:
        pLayer->fSaved = 1;
        switch (gnAutomapMode)
        {
        case AUTOMAP_SIZE_MINI:
            nCelNo = nPickedFile != 1 ? TOWNCEL_LUTGHOLEIN_ALT_MINI : TOWNCEL_LUTGHOLEIN_MINI;
            break;
        default:
            nCelNo = nPickedFile != 1 ? TOWNCEL_LUTGHOLEIN_ALT_FULL : TOWNCEL_LUTGHOLEIN_FULL;
            break;
        }
        pSkip = gaTownSkipCels;
        nColumns = 5;
        nRows = 4;
        nOffsetX = 0x35;
        nOffsetY = -0x51;
        nStepX = 0xA0;
        nStepY = 0x64;
        nPickedFile = nCelNo;
        break;

    case LEVEL_THEPANDEMONIUMFORTRESS:
        pLayer->fSaved = 2;
        pSkip = 0;
        nColumns = 2;
        nRows = 2;
        nOffsetX = -3;
        nOffsetY = -0x32;
        nStepX = 0x88;
        nStepY = 0x5A;
        switch (gnAutomapMode)
        {
        case AUTOMAP_SIZE_MINI:
            nCelNo = TOWNCEL_PANDFORT_MINI;
            break;
        default:
            nCelNo = TOWNCEL_PANDFORT_FULL;
            break;
        }
        nPickedFile = nCelNo;
        break;

    case LEVEL_HARROGATH:
        pLayer->fSaved = 3;
        pSkip = 0;
        nColumns = 3;
        nRows = 2;
        nOffsetX = -0x14;
        nOffsetY = -0x9B;
        nStepX = 0xB4;
        nStepY = 0xAA;
        switch (gnAutomapMode)
        {
        case AUTOMAP_SIZE_MINI:
            nCelNo = TOWNCEL_HARROGATH_MINI;
            break;
        default:
            nCelNo = TOWNCEL_HARROGATH_FULL;
            break;
        }
        nPickedFile = nCelNo;
        break;

    default:
        D2_ASSERT(0, 0x751);
    }

    DUNGEON_GameTileToClientCoords(&nX, &nY);
    nX /= 10;
    nY /= 10;
    const int nHalfWidth = nStepX * nColumns / 2 + nOffsetX;
    int nPosY = nY - nStepY * nRows / 2 - nOffsetY;
    for (int nRow = 0; nRow < nRows; ++nRow)
    {
        int nPosX = nX - nHalfWidth;
        for (int nColumn = 0; nColumn < nColumns; ++nColumn)
        {
            {
                const int* p = pSkip;
                int nSkipCel;
                int bMore;
                if (p)
                {
                    nSkipCel = *p;
                    bMore = 1;
                }
                else
                {
                    bMore = 0;
                }
                while (bMore)
                {
                    if (nSkipCel == -1)
                        bMore = 0;
                    else if (nSkipCel == nPickedFile)
                        goto next;
                    else
                    {
                        ++p;
                        nSkipCel = *p;
                    }
                }
            }

            D2_ASSERT(nPosX >= -0x8000 && nPosX <= 0x7FFF, 0x777);
            D2_ASSERT(nPosY >= -0x8000 && nPosY <= 0x7FFF, 0x778);
            D2_ASSERT(nPickedFile >= -0x8000 && nPickedFile <= 0x7FFF, 0x779);
            {
                D2AutomapCellStrc* pCell = AUTOMAP_AllocAutomapCell();
                pCell->fSaved = 0;
                pCell->nCellNo = nPickedFile;
                pCell->xPixel = nPosX;
                pCell->yPixel = nPosY;
                AUTOMAP_InsertAutomapCell(pCell, &pLayer->pExtras);
            }
next:
            ++nPickedFile;
            nPosX += nStepX;
        }
        nPosY += nStepY;
    }

    if (nPrevLayerNo != -1)
        AUTOMAP_InitAutomapLayer(nPrevLayerNo);
}

// 0x00457450
int __fastcall AUTOMAP_GetAbsValue(int nValue)
{
    return nValue < 0 ? -nValue : nValue;
}

// 0x00459440
void __fastcall AUTOMAP_DrawAutomapCells(D2AutomapCellStrc* pCell, D2AutomapDrawStrc* pInfo)
{
    if (!pCell)
    {
        return;
    }

    int nShift = 0;
    switch (sub_0045AE90_GetPanelSlideMode())
    {
    case 1:
        nShift = -(gnScreenWidth / 4);
        break;
    case 2:
        nShift = gnScreenWidth / 4;
        break;
    }

    int nX = pCell->xPixel * 10 / gnAutomapScale;
    int nY = pCell->yPixel * 10 / gnAutomapScale;
    nX -= gnAutomapOffsetX;
    nY -= gnAutomapOffsetY;

    if (nY >= pInfo->nTop)
    {
        AUTOMAP_DrawAutomapCells(pCell->pPrev, pInfo);
    }

    if (nY >= pInfo->nTop && nY <= pInfo->nBottom && nX >= pInfo->nLeft && nX <= pInfo->nRight)
    {
        int nDrawMode = 5;
        D2GfxDataStrc tData;
        memset(&tData, 0, sizeof(tData));
        tData.nFrame = pCell->nCellNo;
        tData.pCelFile = pInfo->pCelFile;
        tData.nDirection = 0;

        switch (AUTOMAP_GetAutomapFade())
        {
        case 1:
            if (pInfo->pCelFile == gapAutomapCels[0] && !gnAutomapMode)
            {
                const int nPosX = pInfo->nXOffset + nX;
                const int nPosY = pInfo->nYOffset + nY;
                const int nHalfHeight = gnAutomapHeight_007A521C / 2;
                const int nCenterY = nHalfHeight - 10;
                const int nHalfWidth = gnAutomapWidth / 2;
                if (nPosX >= nHalfWidth + nShift - 0x8C && nPosX <= nHalfWidth + nShift + 0x8C && nPosY >= nHalfHeight - 0x96 && nPosY <= nHalfHeight + 0x82)
                {
                    const int nDistX = AUTOMAP_GetAbsValue(nHalfWidth - nPosX + nShift);
                    const int nDistY = AUTOMAP_GetAbsValue(nCenterY - nPosY);
                    const int nDist = (nDistX > nDistY ? nDistY + 2 * nDistX : nDistX + 2 * nDistY) / 2;
                    if (nDist < 0x96)
                    {
                        nDrawMode = AUTOMAP_GetAutomapFade() == 2 ? 1 : 2;
                        if (nDist < 0x64)
                        {
                            nDrawMode = 1;
                            if (nDist < 0x32)
                            {
                                nDrawMode = 0;
                            }
                        }
                    }
                }
            }
            break;
        case 2:
            nDrawMode = 1;
            break;
        case 3:
            switch (sub_00463DD0_GetPlayerUnit()->nAct)
            {
            case 0:
            case 2:
                switch (gnAutomapMode)
                {
                case 1:
                    nDrawMode = 1;
                    break;
                default:
                    nDrawMode = 2;
                    break;
                }
                break;
            }
            break;
        }

        D2CropRectStrc tRect;
        switch (gnAutomapMode)
        {
        case 1:
            if (gbAutomapLeft)
            {
                tRect.nLeft = 0;
                tRect.nTop = (VIEW_IsPetIconVisible() ? 0x60 : 0) - 0x15;
            }
            else
            {
                tRect.nLeft = gnScreenWidth - 0x119;
                tRect.nTop = 0x39;
            }
            tRect.nRight = tRect.nLeft + 0x117;
            tRect.nBottom = tRect.nTop + 0xE1;
            break;
        default:
            tRect.nLeft = 0;
            tRect.nRight = gnScreenWidth - 1;
            tRect.nTop = 0;
            tRect.nBottom = gnScreenHeight - 1;
            break;
        }
        TEXTURE_CelDrawClipped(&tData, nX, nY, &tRect, nDrawMode);
    }

    if (nY <= pInfo->nBottom)
    {
        AUTOMAP_DrawAutomapCells(pCell->pNext, pInfo);
    }
}

// 0x00459700
void __cdecl AUTOMAP_PaintAutomap()
{
    if (!gpAutomapContext)
        return;
    int nShift = 0;
    switch (sub_0045AE90_GetPanelSlideMode())
    {
    case 1:
        if (gnAutomapMode != 1)
            nShift = -(gnScreenWidth / 4);
        if (!gbAutomapLeft)
        {
            gbAutomapLeftPrev = 0;
            gbAutomapLeft = 1;
        }
        break;
    case 2:
        if (gnAutomapMode != 1)
            nShift = gnScreenWidth / 4;
        if (gbAutomapLeft)
        {
            gbAutomapLeftPrev = gbAutomapLeft;
            gbAutomapLeft = 0;
        }
        break;
    default:
        if (gbAutomapLeft != gbAutomapLeftPrev)
            gbAutomapLeft = gbAutomapLeftPrev;
        if (gbAutomapLeft != gbAutomapLeftSaved)
            gbAutomapLeft = gbAutomapLeftSaved;
        break;
    }

    const int nX = UI_GetAutomapOffsetX() / gnAutomapScale - gnAutomapWidth / 2 - nShift;
    const int nY = UI_GetAutomapOffsetY() / gnAutomapScale - gnAutomapHeight_007A521C / 2;
    gnAutomapViewX = nX;
    gnAutomapViewY = nY;
    gnAutomapOffsetX = gnAutomapBaseX + nX + 0x28;
    gnAutomapOffsetY = gnAutomapBaseY + nY + 0xF;

    D2AutomapDrawStrc tInfo;
    switch (gnAutomapMode)
    {
    case 1:
        tInfo.pCelFile = gapAutomapCels[0];
        tInfo.nLeft = gnMiniMapX - 8;
        tInfo.nTop = gnMiniMapY - 0x10;
        tInfo.nRight = gnMiniMapX + gnAutomapWidth / 3 + 8;
        tInfo.nBottom = gnMiniMapY + gnAutomapHeight_007A521C / 3 + 0x10;
        tInfo.nXOffset = 4;
        tInfo.nYOffset = 8;
        gnAutomapScale = 0x14;
        break;
    default:
        tInfo.pCelFile = gapAutomapCels[0];
        tInfo.nLeft = -0x10;
        tInfo.nTop = -0x20;
        tInfo.nRight = gnAutomapWidth + 0x10;
        tInfo.nBottom = gnAutomapHeight_007A521C + 0x20;
        tInfo.nXOffset = 8;
        tInfo.nYOffset = 0x10;
        gnAutomapScale = 0xA;
        break;
    }
    AUTOMAP_DrawAutomapCells(gpAutomapContext->pFloors, &tInfo);
    AUTOMAP_DrawAutomapCells(gpAutomapContext->pWalls, &tInfo);
    AUTOMAP_DrawAutomapCells(gpAutomapContext->pObjects, &tInfo);

    switch (gnAutomapMode)
    {
    case 1:
        switch (gpAutomapContext->fSaved)
        {
        case 1:
            tInfo.pCelFile = gapAutomapCels[1];
            tInfo.nLeft = gnMiniMapX - 0xA0;
            tInfo.nTop = gnMiniMapY - 0x64;
            tInfo.nRight = gnMiniMapX + gnAutomapWidth / 3 + 0xA0;
            tInfo.nBottom = gnMiniMapY + gnAutomapHeight_007A521C / 3 + 0x64;
            tInfo.nXOffset = 0x50;
            tInfo.nYOffset = 0x32;
            break;
        case 2:
            tInfo.pCelFile = gapAutomapCels[2];
            tInfo.nLeft = gnMiniMapX - 0x88;
            tInfo.nTop = gnMiniMapY - 0x5A;
            tInfo.nRight = gnMiniMapX + gnAutomapWidth / 3 + 0x88;
            tInfo.nBottom = gnMiniMapY + gnAutomapHeight_007A521C / 3 + 0x5A;
            tInfo.nXOffset = 0x44;
            tInfo.nYOffset = 0x2D;
            break;
        case 3:
            tInfo.pCelFile = gapAutomapCels[3];
            tInfo.nLeft = gnMiniMapX - 0xB4;
            tInfo.nTop = gnMiniMapY - 0xAA;
            tInfo.nRight = gnMiniMapX + gnAutomapWidth / 3 + 0xB4;
            tInfo.nBottom = gnMiniMapY + gnAutomapHeight_007A521C / 3 + 0xAA;
            tInfo.nXOffset = 0x5A;
            tInfo.nYOffset = 0x55;
            break;
        default:
            tInfo.pCelFile = gapAutomapCels[0];
            tInfo.nLeft = gnMiniMapX - 8;
            tInfo.nTop = gnMiniMapY - 0x10;
            tInfo.nRight = gnMiniMapX + gnAutomapWidth / 3 + 8;
            tInfo.nBottom = gnMiniMapY + gnAutomapHeight_007A521C / 3 + 0x10;
            tInfo.nXOffset = 4;
            tInfo.nYOffset = 8;
            break;
        }
        gnAutomapScale = 0x14;
        break;
    default:
        switch (gpAutomapContext->fSaved)
        {
        case 1:
            tInfo.pCelFile = gapAutomapCels[1];
            tInfo.nLeft = -0xA0;
            tInfo.nTop = -0x64;
            tInfo.nRight = gnAutomapWidth + 0xA0;
            tInfo.nBottom = gnAutomapHeight_007A521C + 0x64;
            tInfo.nXOffset = 0x50;
            tInfo.nYOffset = 0x32;
            break;
        case 2:
            tInfo.pCelFile = gapAutomapCels[2];
            tInfo.nLeft = -0x88;
            tInfo.nTop = -0x5A;
            tInfo.nRight = gnAutomapWidth + 0x88;
            tInfo.nBottom = gnAutomapHeight_007A521C + 0x5A;
            tInfo.nXOffset = 0x44;
            tInfo.nYOffset = 0x2D;
            break;
        case 3:
            tInfo.pCelFile = gapAutomapCels[3];
            tInfo.nLeft = -0xB4;
            tInfo.nTop = -0xAA;
            tInfo.nRight = gnAutomapWidth + 0xB4;
            tInfo.nBottom = gnAutomapHeight_007A521C + 0xAA;
            tInfo.nXOffset = 0x5A;
            tInfo.nYOffset = 0x55;
            break;
        default:
            tInfo.pCelFile = gapAutomapCels[0];
            tInfo.nLeft = -0x10;
            tInfo.nTop = -0x20;
            tInfo.nRight = gnAutomapWidth + 0x10;
            tInfo.nBottom = gnAutomapHeight_007A521C + 0x20;
            tInfo.nXOffset = 8;
            tInfo.nYOffset = 0x10;
            break;
        }
        gnAutomapScale = 0xA;
        break;
    }
    AUTOMAP_DrawAutomapCells(gpAutomapContext->pExtras, &tInfo);
}

static inline int AUTOMAP_GetUnitClassId(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwClassId;
}

static inline int AUTOMAP_GetUnitClassIdR(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return -1;
    }
    return pUnit->dwClassId;
}

static inline int AUTOMAP_GetUnitAnimModeR(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }
    return pUnit->dwAnimMode;
}

// 0x00459BC0
static int AUTOMAP_GetAutomapUnitColor(D2UnitStrc* pUnit, unsigned char* pColor)
{
    switch (AUTOMAP_GetUnitType(pUnit))
    {
    case 0:
        if (pUnit && pUnit->dwAnimMode == 0x11)
        {
            D2InventoryStrc* pInventory = pUnit->pInventory;
            if (!pInventory || INVENTORY_GetOwnerId(pInventory) != pUnit->dwUnitId)
            {
                return 0;
            }

            *pColor = gabAutomapColors[2];
            return 1;
        }

        if (pUnit == sub_00463DD0_GetPlayerUnit())
        {
            *pColor = gabAutomapColors[0];
            return 1;
        }

        {
            const unsigned short nPlayerRoster = CUNIT_GetPlayerPartyId(sub_00463DD0_GetPlayerUnit());
            if (nPlayerRoster != 0xFFFF && nPlayerRoster == (unsigned short)CUNIT_GetPlayerPartyId(pUnit))
            {
                *pColor = gabAutomapColors[3];
                return 1;
            }
        }

        *pColor = gabAutomapColors[1];
        return 1;

    case 1:
    {
        if (pUnit)
        {
            if (pUnit->dwAnimMode == 0xC)
            {
                return 0;
            }

            if (AUTOMAP_UnitHasFlag(pUnit, 0x200000))
            {
                return 0;
            }
        }

        if (MONSTERUNIQUE_CheckMonStatsFlag(AUTOMAP_GetUnitClassId(pUnit), 9))
        {
            if (pUnit)
            {
                const int nClassId = pUnit->dwClassId;
                if (nClassId == 0x219 || nClassId == 0x21A || nClassId == 0x21B)
                {
                    return 0;
                }
            }

            *pColor = gabAutomapColors[6];
            return 1;
        }

        int nClass;
        int nMode;
        int nType = AUTOMAP_GetUnitType(pUnit);
        nClass = AUTOMAP_GetUnitClassIdR(pUnit);
        nMode = AUTOMAP_GetUnitAnimModeR(pUnit);
        D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\UI\\automap.cpp", 0x92D);
        if (!nType && STATES_CheckStateMaskOnUnit(pUnit, 0x25) && CUNIT_GetOwnerUnit(pUnit))
        {
            const unsigned short nPlayerRoster = CUNIT_GetPlayerPartyId(sub_00463DD0_GetPlayerUnit());
            if (nPlayerRoster != 0xFFFF && nPlayerRoster == (unsigned short)CUNIT_GetPlayerPartyId(pUnit))
            {
                *pColor = gabAutomapColors[4];
                return 1;
            }

            *pColor = gabAutomapColors[1];
            return 1;
        }

        switch (ROSTERPETS_GetPetRelation(!pUnit ? -1 : pUnit->dwUnitId))
        {
        case 0:
        case 3:
            return 0;

        case 1:
            if (sub_00451F30_TestUnitFlag(pUnit, 0x200))
            {
                *pColor = gabAutomapColors[4];
                return 1;
            }
            *pColor = gabAutomapColors[4];
            return 1;

        case 2:
            if (!gbAutomapParty)
            {
                return 0;
            }
            *pColor = gabAutomapColors[5];
            return 1;
        }

        return 1;
    }

    case 2:
        switch (AUTOMAP_GetUnitClassId(pUnit))
        {
        case 0x3B:
            *pColor = gabAutomapColors[8];
            return 1;

        case 0x3C:
        {
            const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(pUnit));
            if (nLevelId == LEVEL_HELL1 || nLevelId == LEVEL_HELL2 || nLevelId == LEVEL_HELL3 || nLevelId == LEVEL_ID_ACT5_BARRICADE_1
                || nLevelId == LEVEL_ARREATPLATEAU || nLevelId == LEVEL_TUNDRAWASTELANDS)
            {
                return 0;
            }
        }
            *pColor = gabAutomapColors[8];
            return 1;

        case 0x10B:
            *pColor = 0;
            return 1;
        }
        break;
    }

    return 0;
}

// 0x00459E90
void __cdecl AUTOMAP_DrawGameInfoLines()
{
    Unicode wszName[25];
    char szText[28];
    Unicode wszLine[50];
    for (int i = 0; i < 25; ++i)
        wszName[i].wChar = 0;
    for (int i = 0; i < 50; ++i)
        wszLine[i].wChar = 0;
    const char* szFirst = WINMAIN_GetGameName();
    const char* szSecond = WINMAIN_GetGamePassword();
    if (!szFirst)
    {
        if (!szSecond)
            return;
    }
    else
    {
        sprintf(szText, gszStringFormat, szFirst);
        sub_00526320_ToUnicode(wszName, szText, 25);
        sub_005267E0(wszLine, D2LANG_GetStringFromTblIndex(0x1055));
        sub_00526700(wszLine, wszName);
        D2Win_10117_DrawText(wszLine, gnAutomapWidth - D2Win_10121_GetTextWidth(wszLine) - 0x10, gnAutomapTextY, 4, 0);
        gnAutomapTextY += 0x10;
    }
    const char* szThird = WINMAIN_GetGameDescription();
    if (!szThird)
        return;
    sprintf(szText, gszStringFormat, szThird);
    sub_00526320_ToUnicode(wszName, szText, 25);
    sub_005267E0(wszLine, D2LANG_GetStringFromTblIndex(0x1056));
    sub_00526700(wszLine, wszName);
    D2Win_10117_DrawText(wszLine, gnAutomapWidth - D2Win_10121_GetTextWidth(wszLine) - 0x10, gnAutomapTextY, 4, 0);
    gnAutomapTextY += 0x10;
}

// 0x00459FF0
void __cdecl AUTOMAP_DrawStringLine()
{
    Unicode wszText[50];
    for (int i = 0; i < 50; ++i)
        wszText[i].wChar = 0;
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x58CA));
    D2Win_10117_DrawText(wszText, gnAutomapWidth - D2Win_10121_GetTextWidth(wszText) - 0x10, gnAutomapTextY, 4, 0);
    gnAutomapTextY += 0x10;
}

// 0x0045A050
void __cdecl AUTOMAP_DrawLevelName()
{
    D2ActiveRoomStrc* room = CUNIT_GetPlayerRoom();
    if (room)
    {
        const Unicode* text = UI_GetLevelName(DUNGEON_GetLevelIdFromRoom(room));
        D2Win_10117_DrawText(text, gTextRight - D2Win_10121_GetTextWidth(text) - 16, gTextY, 4, 0);
        gTextY += 16;
    }
}

// 0x0045A0A0
void __cdecl AUTOMAP_DrawVersionLine()
{
    Unicode wszText[100];
    char szText[100];
    for (int i = 0; i < 100; ++i)
        wszText[i].wChar = 0;
    SStrPrintf(szText, 100, "v %d.%d%c", 1, 14, 100);
    sub_00526320_ToUnicode(wszText, szText, 100);
    const int nWidth = D2Win_10121_GetTextWidth(wszText);
    D2Win_10117_DrawText(wszText, gnAutomapWidth - nWidth - 0x10, gnAutomapTextY, 4, 0);
    gnAutomapTextY += 0x10;
}

// 0x0045A120
void __cdecl AUTOMAP_DrawLocalIpLine()
{
    Unicode wszText[300];
    for (int i = 0; i < 300; ++i)
        wszText[i].wChar = 0;
    sub_00526320_ToUnicode(wszText, FOG_GetHostIPAddress(), 300);
    D2Win_10117_DrawText(wszText, gnAutomapWidth - D2Win_10121_GetTextWidth(wszText) - 0x10, gnAutomapTextY, 4, 0);
    gnAutomapTextY += 0x10;
}

// 0x0045A190
void __cdecl AUTOMAP_DrawDifficultyLine()
{
    unsigned short nString;
    switch (GAME_GetDifficulty())
    {
    case 1:
        nString = 0x1423;
        break;
    case 2:
        nString = 0x1422;
        break;
    default:
        return;
    }
    Unicode wszText[300];
    for (int i = 0; i < 300; ++i)
        wszText[i].wChar = 0;
    D2_ASSERT(UNICODE_StrLen(D2LANG_GetStringFromTblIndex(nString)) + UNICODE_StrLen(D2LANG_GetStringFromTblIndex(0x1057)) + 3 < 300, 0xB2A);
    sub_005269D0_FormatText(300, wszText, D2LANG_GetStringFromTblIndex(0x1057), D2LANG_GetStringFromTblIndex(nString));
    D2Win_10117_DrawText(wszText, gnAutomapWidth - D2Win_10121_GetTextWidth(wszText) - 0x10, gnAutomapTextY, 4, 0);
    gnAutomapTextY += 0x10;
}

// 0x0045A280
void __cdecl AUTOMAP_FreeAutomapCels()
{
    for (int i = 0; i < 4; ++i)
    {
        if (gapAutomapCels[i])
        {
            ARCHIVE_FreeClientCellFile(gapAutomapCels[i]);
        }
        gapAutomapCels[i] = 0;
    }
}

// 0x0045A2B0
void __cdecl AUTOMAP_ReloadAutomapCels()
{
    char szPath[260] = {0};
    for (int i = 0; i < 4; ++i)
    {
        if (gapAutomapCels[i])
            ARCHIVE_FreeClientCellFile(gapAutomapCels[i]);
        gapAutomapCels[i] = 0;
    }
    switch (gnAutomapMode)
    {
    case 1:
        sprintf(szPath, "%s\\UI\\AutoMap\\MaxiMapS", gszDataGlobal);
        gapAutomapCels[0] = ARCHIVE_LoadClientCellFile(szPath, 0);
        gaAutomapCelFrames[0] = CelFileGetCelsPerDirection(gapAutomapCels[0]);
        sprintf(szPath, "%s\\UI\\AutoMap\\Act2MapS", gszDataGlobal);
        gapAutomapCels[1] = ARCHIVE_LoadClientCellFile(szPath, 0);
        gaAutomapCelFrames[1] = CelFileGetCelsPerDirection(gapAutomapCels[1]);
        sprintf(szPath, "%s\\UI\\AutoMap\\Act4MapS", gszDataGlobal);
        gapAutomapCels[2] = ARCHIVE_LoadClientCellFile(szPath, 0);
        gaAutomapCelFrames[2] = CelFileGetCelsPerDirection(gapAutomapCels[2]);
        sprintf(szPath, "%s\\UI\\AutoMap\\ExTnMapS", gszDataGlobal);
        gapAutomapCels[3] = ARCHIVE_LoadClientCellFile(szPath, 0);
        gaAutomapCelFrames[3] = CelFileGetCelsPerDirection(gapAutomapCels[3]);
        break;
    default:
        sprintf(szPath, "%s\\UI\\AutoMap\\MaxiMap", gszDataGlobal);
        gapAutomapCels[0] = ARCHIVE_LoadClientCellFile(szPath, 0);
        gaAutomapCelFrames[0] = CelFileGetCelsPerDirection(gapAutomapCels[0]);
        sprintf(szPath, "%s\\UI\\AutoMap\\Act2Map", gszDataGlobal);
        gapAutomapCels[1] = ARCHIVE_LoadClientCellFile(szPath, 0);
        gaAutomapCelFrames[1] = CelFileGetCelsPerDirection(gapAutomapCels[1]);
        sprintf(szPath, "%s\\UI\\AutoMap\\Act4Map", gszDataGlobal);
        gapAutomapCels[2] = ARCHIVE_LoadClientCellFile(szPath, 0);
        gaAutomapCelFrames[2] = CelFileGetCelsPerDirection(gapAutomapCels[2]);
        if (FOG_IsExpansion())
        {
            sprintf(szPath, "%s\\UI\\AutoMap\\ExTnMap", gszDataGlobal);
            gapAutomapCels[3] = ARCHIVE_LoadClientCellFile(szPath, 0);
            gaAutomapCelFrames[3] = CelFileGetCelsPerDirection(gapAutomapCels[3]);
        }
        else
        {
            gapAutomapCels[3] = 0;
            gaAutomapCelFrames[3] = 0;
        }
        break;
    }
}

// 0x0045A4C0
void __cdecl AUTOMAP_InitAutomap()
{
    unsigned long dwValue = 0;
    AUTOMAP_ReloadAutomapCels();
    for (int i = 0; i < 0x800; i++)
    {
        gaAutomapCellTable[i] = -1;
    }
    for (int i = 0; i < 49; i++)
    {
        gaAutomapCellTable[gaAutomapPairs[i].nIndex] = gaAutomapPairs[i].nValue;
    }
    dwValue = 0;
    SRegLoadValue("Diablo II", "AutoMapFade", 0, &dwValue);
    gdwAutoMapFade = dwValue;
    dwValue = 1;
    SRegLoadValue("Diablo II", "AutoMap Centers", 0, &dwValue);
    gbAutomapCenter = dwValue;
    dwValue = 1;
    SRegLoadValue("Diablo II", "AutoMap Party", 0, &dwValue);
    gbAutomapParty = dwValue;
    dwValue = 1;
    SRegLoadValue("Diablo II", "AutoMap Party Names", 0, &dwValue);
    gbAutomapPartyNames = dwValue;
    dwValue = 1;
    SRegLoadValue("Diablo II", "AutoMap Left", 0, &dwValue);
    gbAutomapLeft = dwValue;
    gbAutomapLeftPrev = dwValue;
    gbAutomapLeftSaved = dwValue;
}

// 0x0045A5C0
void __cdecl AUTOMAP_FreeAutomap()
{
    AUTOMAP_SaveAutomapLayer();
    AUTOMAP_ResetAutomapCells();
    for (int i = 0; i < 4; ++i)
    {
        if (gapAutomapCels[i])
        {
            ARCHIVE_FreeClientCellFile(gapAutomapCels[i]);
        }
        gapAutomapCels[i] = 0;
    }
    D2AutomapLayerStrc* pLayer = gpAutomapNodes;
    while (pLayer)
    {
        D2AutomapLayerStrc* pFree = pLayer;
        pLayer = pLayer->pNext;
        FOG_Free(pFree, ".\\UI\\automap.cpp", 0xC06, 0);
    }
    gpAutomapNodes = 0;
    gpAutomapContext = 0;
}

// 0x0045A620
void __cdecl AUTOMAP_InitAutomapColors()
{
    gabAutomapColors[0] = D2Win_10034_MixRGB(0, 0, 0xFF);
    gabAutomapColors[1] = D2Win_10034_MixRGB(0xFF, 0, 0);
    gabAutomapColors[2] = D2Win_10034_MixRGB(0xFF, 0, 0xFF);
    gabAutomapColors[3] = D2Win_10034_MixRGB(0, 0xFF, 0);
    gabAutomapColors[4] = D2Win_10034_MixRGB(0x44, 0x70, 0x74);
    gabAutomapColors[5] = D2Win_10034_MixRGB(0x48, 0xA0, 0x34);
    gabAutomapColors[6] = D2Win_10034_MixRGB(0xF4, 0xF4, 0xF4);
    gabAutomapColors[7] = D2Win_10034_MixRGB(0x80, 0x80, 0x80);
    gabAutomapColors[8] = D2Win_10034_MixRGB(0xF4, 0xF4, 0);
    gabAutomapColors[9] = D2Win_10034_MixRGB(0, 0, 0xFF);
    gabAutomapColors[10] = D2Win_10034_MixRGB(0, 0xFF, 0);
}

// 0x0045A710
int __cdecl UI_GetAutomapMode()
{
    return gnAutomapMode;
}

// 0x0045A720
void __fastcall AUTOMAP_SetAutomapMode(int mode)
{
    if (mode != gnAutomapMode)
    {
        gnAutomapMode = mode;
        gnAutomapScale = 10;
        switch (mode)
        {
        case 1:
            gnAutomapScale = 20;
            break;
        }
        AUTOMAP_ReloadAutomapCels();
        AUTOMAP_ResetBaseOffset(1);
    }
}

static inline int AUTOMAP_GetUnitType(D2UnitStrc* pUnit)
{
    int nType = 6;
    if (pUnit)
    {
        nType = pUnit->dwUnitType;
    }
    return nType;
}

static inline int AUTOMAP_UnitHasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }
    return 0;
}

// 0x0045A760
static void __stdcall AUTOMAP_DrawAutomapText(unsigned char nColor, const char* szText, int nX, int nY)
{
    if (!strlen(szText))
    {
        return;
    }

    if (nColor >= 0xD)
    {
        nColor = 0;
    }

    const int nOldFont = D2Win_10127_SetFont(6);
    Unicode wszText[0x17];
    memset(wszText, 0, sizeof(wszText));
    sub_00526320_ToUnicode(wszText, szText, 0x17);
    D2Win_10117_DrawText(wszText, nX - D2Win_10121_GetTextWidth(wszText) / 2, nY - 10, nColor, 0);
    D2Win_10127_SetFont(nOldFont);
}

// 0x0045A7F0
static void __stdcall AUTOMAP_DrawAutomapCross(unsigned char nColor, int nX, int nY)
{
    if (gnAutomapMode == 1)
    {
        nX -= 1;
        nY += 5;
    }

    for (unsigned int i = 0; i < 12; ++i)
    {
        D2GFX_DrawLine(nX + gaAutomapCross[i].nX * 2, nY + gaAutomapCross[i].nY * 2,
            nX + gaAutomapCross[i + 1].nX * 2, nY + gaAutomapCross[i + 1].nY * 2, nColor, 0xFF);
    }
}

// 0x0045A860
static void AUTOMAP_DrawAutomapUnit(D2UnitStrc* pUnit)
{
    int nUnitType;
    if (!pUnit)
    {
        nUnitType = 6;
    }
    else
    {
        nUnitType = pUnit->dwUnitType;
    }
    unsigned char nColor = 0;
    if (nUnitType == 0 && CUNIT_IsDeadOrDying(pUnit) && !STATES_CheckState(pUnit, STATE_PLAYERBODY))
    {
        return;
    }

    if (!AUTOMAP_GetAutomapUnitColor(pUnit, &nColor))
    {
        return;
    }

    const int nClientX = UNITS_GetClientCoordX(pUnit);
    const int nClientY = UNITS_GetClientCoordY(pUnit);
    const int nX = nClientX / gnAutomapScale - gnAutomapOffsetX + 8;
    const int nY = nClientY / gnAutomapScale - gnAutomapOffsetY - 8;
    if (nX < gnAutomapClipLeft || nX > gnAutomapClipRight || nY < gnAutomapClipTop || nY > gnAutomapClipBottom)
    {
        return;
    }

    switch (nUnitType)
    {
    case 0:
        if (gbAutomapParty || nColor != gabAutomapColors[3])
        {
            AUTOMAP_DrawAutomapCross(nColor, nX, nY);
        }

        if (gbAutomapPartyNames && gbAutomapParty && pUnit != sub_00463DD0_GetPlayerUnit())
        {
            if (nColor == gabAutomapColors[3])
            {
                if (gbAutomapParty)
                {
                    AUTOMAP_DrawAutomapText(2, UNITS_GetPlayerData(pUnit)->szName, nX, nY);
                }
            }
            else
            {
                AUTOMAP_DrawAutomapText(1, UNITS_GetPlayerData(pUnit)->szName, nX, nY);
            }
        }
        break;

    case 1:
    {
        AUTOMAP_DrawAutomapCross(nColor, nX, nY);
        if (!gbAutomapPartyNames)
        {
            break;
        }

        if (MONSTERUNIQUE_CheckMonStatsFlag(AUTOMAP_GetUnitClassId(pUnit), 9))
        {
            const int nOldFont = D2Win_10127_SetFont(6);
            const Unicode* wszName = CUNIT_GetUnitName(pUnit);
            D2Win_10117_DrawText(wszName, nX - D2Win_10121_GetTextWidth(wszName) / 2, nY - 10, 4, 0);
            D2Win_10127_SetFont(nOldFont);
        }

        if (!gbAutomapPartyNames || !gbAutomapParty)
        {
            break;
        }

        {
            int nType = AUTOMAP_GetUnitType(pUnit);
            int nClass = AUTOMAP_GetUnitClassIdR(pUnit);
            int nMode = AUTOMAP_GetUnitAnimModeR(pUnit);
            D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\UI\\automap.cpp", 0xA15);
            if (nType || !STATES_CheckStateMaskOnUnit(pUnit, 0x25))
            {
                break;
            }

            D2UnitStrc* pOwner = CUNIT_GetOwnerUnit(pUnit);
            if (!pOwner || pOwner->dwUnitType != UNIT_PLAYER)
            {
                break;
            }

            const unsigned short nPlayerRoster = CUNIT_GetPlayerPartyId(sub_00463DD0_GetPlayerUnit());
            if (nPlayerRoster != 0xFFFF && nPlayerRoster == (unsigned short)CUNIT_GetPlayerPartyId(pUnit))
            {
                break;
            }

            AUTOMAP_DrawAutomapText(1, UNITS_GetPlayerData(pOwner)->szName, nX, nY);
        }
        break;
    }

    case 2:
        if (gbAutomapPartyNames && pUnit && pUnit->dwClassId == 0x10B)
        {
            const int nOldFont = D2Win_10127_SetFont(6);
            const Unicode* wszText = D2LANG_GetStringFromTblIndex(0xCF3);
            D2Win_10117_DrawText(wszText, nX - D2Win_10121_GetTextWidth(wszText) / 2, nY - 10, nColor, 0);
            D2Win_10127_SetFont(nOldFont);
        }
        else
        {
            AUTOMAP_DrawAutomapCross(nColor, nX, nY);
        }
        break;
    }
}

// 0x0045AB60
static void AUTOMAP_DrawAutomapPartyMember(D2StoredUnitRecordStrc* pEntry)
{
    int nX = 0;
    int nY = 0;
    const int nLevelId = DUNGEON_GetLevelIdFromRoom(UNITS_GetRoom(sub_00463DD0_GetPlayerUnit()));
    const unsigned char nEntryAct = DRLG_GetActNoFromLevelId(ROSTER_GetLevelId(pEntry));
    if (DRLG_GetActNoFromLevelId(nLevelId) != nEntryAct)
    {
        return;
    }

    ROSTER_GetPosition(pEntry, &nX, &nY);
    DUNGEON_GameSubtileToClientCoords(&nX, &nY);
    nX = nX / gnAutomapScale - gnAutomapOffsetX + 8;
    nY = nY / gnAutomapScale - gnAutomapOffsetY - 8;
    if (nX < gnAutomapClipLeft || nX > gnAutomapClipRight || nY < gnAutomapClipTop || nY > gnAutomapClipBottom)
    {
        return;
    }

    for (unsigned int i = 0; i < 12; ++i)
    {
        D2GFX_DrawLine(nX + gaAutomapCross[i].nX * 2, nY + gaAutomapCross[i].nY * 2,
            nX + gaAutomapCross[i + 1].nX * 2, nY + gaAutomapCross[i + 1].nY * 2, gabAutomapColors[3], 0xFF);
    }

    if (gbAutomapPartyNames)
    {
        AUTOMAP_DrawAutomapText(2, ROSTER_GetEntryName(pEntry), nX, nY);
    }
}








void __stdcall AUTOMAP_DrawUnitTileRect(D2UnitStrc* pUnit); // 0x0045B1E0




// 0x0045D3E0
void __fastcall AUTOMAP_RefreshItemStats(D2UnitStrc* pUnit)
{
    if (!pUnit || !pUnit->pInventory)
    {
        return;
    }
    int nLeftSkillId = pUnit->pSkills->pLeftSkill ? pUnit->pSkills->pLeftSkill->pSkillsTxt->nSkillId : 0;
    int nRightSkillId = pUnit->pSkills->pRightSkill ? pUnit->pSkills->pRightSkill->pSkillsTxt->nSkillId : 0;
    D2UnitStrc* pNext;
    for (D2UnitStrc* pItem = INVENTORY_GetFirstItem(pUnit->pInventory); pItem; pItem = pNext)
    {
        pNext = INVENTORY_GetNextItem(pItem);
        D2UnitStrc* pCheckedItem = INVENTORY_UnitIsItem(pItem);
        int bStatNotDynamic = 0;
        if (pCheckedItem && pCheckedItem->dwUnitType == UNIT_ITEM && STATLIST_GetOwner(pCheckedItem, &bStatNotDynamic))
        {
            STATLIST_ExpireUnitStatlist(pUnit, pCheckedItem);
            STATLIST_MergeStatLists(pUnit, pCheckedItem, bStatNotDynamic);
        }
    }
    SKILLS_SetLeftActiveSkill(pUnit, nLeftSkillId, -1);
    SKILLS_SetRightActiveSkill(pUnit, nRightSkillId, -1);
}

// 0x0045FA40
void __fastcall AUTOMAP_ProcessUnitPacketBuffer(void* pArg)
{
    D2PacketBufferStrc* pBuffer = CUNIT_GetPacketList(pArg);
    if (!pBuffer)
    {
        return;
    }
    D2_ASSERT(pBuffer->nCount <= pBuffer->nMax, 0x1525);
    for (int i = 0; i < pBuffer->nCount; ++i)
    {
        unsigned char* pPacket = pBuffer->pData + gnPacketRecordSize * i;
        int nSize;
        if (!SERVER_GetServerPacketSize(pPacket, gnPacketRecordSize, &nSize))
        {
            return;
        }
        D2_ASSERT(pPacket[0] < 0xAF, 0x1531);
        D2PacketTableEntryStrc* pEntry = &gaPacketTable[pPacket[0]];
        if (pEntry->nSize != -1)
        {
            D2_ASSERT((unsigned short)nSize == pEntry->nSize, 0x1534);
        }
        D2_ASSERT(pEntry->f_8, 0x1536);
        pEntry->f_8(pArg, pPacket);
    }
    if (pBuffer->nCount)
    {
        memset(pBuffer->pData, 0, pBuffer->nCount * gnPacketRecordSize);
    }
    pBuffer->nCount = 0;
}



void __cdecl UI_DrawCenteredStrings();                                                            // 0x0045FFC0

void __stdcall VIEW_DrawPanelCels(int nFrame1, int nFrame2);                                        // 0x00460060

void __cdecl UI_DrawCenteredStringPair();                                                         // 0x004600F0





// 0x00460930
void __fastcall AUTOMAP_SetUnitLightRadius(D2UnitStrc* pUnit, int nDelta)
{
    if (!pUnit || (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER))
    {
        return;
    }
    D2GfxLightStrc* pLight = pUnit->pLight;
    if (!pLight)
    {
        return;
    }
    int nRadius;
    if (pUnit->dwUnitType == UNIT_PLAYER)
    {
        nRadius = 0xD;
    }
    else
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(pUnit->dwClassId);
        if (!pMonStats2TxtRecord)
        {
            return;
        }
        nRadius = MONSTERS_GetMaximalLightRadius(pUnit);
        if (nRadius < pMonStats2TxtRecord->nLightRadius)
        {
            nRadius = pMonStats2TxtRecord->nLightRadius;
        }
    }
    nRadius += nDelta;
    DLIGHTMAP_ResetLightSize(pLight, nRadius > 0 ? nRadius : 0);
}

// 0x004609A0
void __fastcall AUTOMAP_SetUnitLightColor(D2UnitStrc* pUnit, int nColor)
{
    if (!pUnit || (pUnit->dwUnitType != UNIT_PLAYER && pUnit->dwUnitType != UNIT_MONSTER))
    {
        return;
    }
    D2GfxLightStrc* pLight = pUnit->pLight;
    if (!pLight)
    {
        return;
    }
    unsigned char nRed = 0xFF;
    unsigned char nGreen = 0xFF;
    unsigned char nBlue = 0xFF;
    if (nColor)
    {
        nRed = (unsigned char)(nColor >> 16);
        nGreen = (unsigned char)(nColor >> 8);
        nBlue = (unsigned char)nColor;
    }
    SCMD_SetLightColorBytes(pLight, nRed, nGreen, nBlue);
}

// 0x00462EE0
unsigned char __stdcall AUTOMAP_GetItemComponent(D2UnitStrc* pUnit, D2UnitStrc* pItem)
{
    int nBodyLoc = ITEMS_GetBodyLocation(pItem);
    if (nBodyLoc == BODYLOC_LARM || nBodyLoc == BODYLOC_RARM)
    {
        D2InventoryStrc* pInventory = pUnit->pInventory;
        D2UnitStrc* pRightArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_RARM);
        D2UnitStrc* pLeftArmItem = INVENTORY_GetItemFromBodyLoc(pInventory, BODYLOC_LARM);
        if (pRightArmItem && pLeftArmItem && !ITEMS_CheckWeaponIfTwoHanded(pRightArmItem)
            && !ITEMS_CheckWeaponIfTwoHanded(pLeftArmItem) && pItem != INVENTORY_GetLeftHandWeapon(pInventory))
        {
            return 6;
        }
    }
    return ITEMS_GetComponent(pItem);
}

// 0x0046EFD0
void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6)
{
    D2GFX_DrawBox(nX, nY, nX + nWidth, nY + nHeight, nArg5, nArg6);
}

inline D2OverlayTxt* DATATBLS_GetOverlayTxtRecordInline(int nOverlay)
{
    if (nOverlay >= 0 && nOverlay < sgptDataTables->nOverlayTxtRecordCount)
    {
        return &sgptDataTables->pOverlayTxt[nOverlay];
    }
    return 0;
}

// 0x0046F0C0
void __fastcall AUTOMAP_RemoveUnitOverlay(D2UnitStrc* pUnit, int nArg, int nValue)
{
    if (!pUnit)
    {
        return;
    }
    D2UnitGfxDataStrc* pGfxData = CUNIT_GetGfxData(pUnit);
    if (!pGfxData)
    {
        return;
    }
    D2_ASSERT(DATATBLS_GetOverlayTxtRecordInline(nValue), 0xCA9);
    D2UnitOverlayStrc* pOverlay = pGfxData->pOverlays;
    while (pOverlay)
    {
        D2UnitOverlayStrc* pNext = pOverlay->pNext;
        if (pOverlay->nOverlay == nValue)
        {
            GFX_RemoveStateOverlay(pUnit, pOverlay);
            return;
        }
        const int nType = pOverlay->nType;
        if ((nType == 4 || nType == 9) && (pOverlay->nUnk0x08 == nValue || pOverlay->f_C == nValue))
        {
            GFX_RemoveStateOverlay(pUnit, pOverlay);
            return;
        }
        pOverlay = pNext;
    }
}


// 0x004C5420
D2UnitStrc* __fastcall AUTOMAP_RequestAtTarget(D2UnitStrc* pUnit, int nRequest, int nArg3, int nArg4)
{
    int nX;
    int nY;
    if (!ITEM_GetTargetPosition(pUnit, &nX, &nY) || !nX || !nY)
    {
        return 0;
    }
    return MISSILE_SubmitOwnerRequest(pUnit, nRequest, nX, nY, nArg3, nArg4);
}

// 0x0045AC90
void __cdecl AUTOMAP_DrawAutomapUnits()
{
    D2StoredUnitRecordStrc* pEntry = ROSTER_GetNextStoredUnit(0);
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2ActiveRoomStrc** ppRooms = 0;
    unsigned int nRooms = 0;
    DUNGEON_GetAdjacentRoomsListFromRoom(UNITS_GetRoom(pPlayer), &ppRooms, &nRooms);
    const int nCount = nRooms;
    for (int i = 0; i < nCount; ++i)
    {
        for (D2UnitStrc* pUnit = ppRooms[i]->pUnitFirst; pUnit; pUnit = pUnit->ptRoomNext)
        {
            AUTOMAP_DrawAutomapUnit(pUnit);
        }
    }

    const unsigned short nIndex = ROSTER_GetEntryIndex(pEntry);
    if (nIndex == 0xFFFF || !gbAutomapParty)
    {
        return;
    }

    for (pEntry = ROSTER_GetNextStoredUnit(pEntry); pEntry; pEntry = ROSTER_GetNextStoredUnit(pEntry))
    {
        if (!CUNIT_FindClientUnit(ROSTER_GetRecordUnitId(pEntry), 0) && nIndex == ROSTER_GetEntryIndex(pEntry))
        {
            AUTOMAP_DrawAutomapPartyMember(pEntry);
        }
    }
}

struct D2StoredUnitRecordStrc;

void __fastcall ITEM_GetAdjacentPosition(D2UnitStrc* pUnit, int* pX, int* pY)
{
    const int nDirection = UNITS_GetDirection(pUnit) >> 3;
    int aOffsetX[8] = { 0, -1, -2, -1, 0, 1, 2, 1 };
    int aOffsetY[8] = { 2, 1, 0, -1, -2, -1, 0, 1 };

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
    *pX = aOffsetX[nDirection] + nX;

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
    *pY = aOffsetY[nDirection] + nY;
}

int __fastcall ITEM_GetTargetPosition(D2UnitStrc* pUnit, int* pX, int* pY)
{
    int nY;
    D2UnitStrc* pTarget = CUNIT_GetPathTargetUnit(pUnit);
    if (pTarget)
    {
        int nX;
        switch (pTarget->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
        case UNIT_TILE:
            nX = pTarget->pStaticPath->tGameCoords.nX;
            break;

        default:
            if (pTarget->pDynamicPath)
            {
                nX = PATH_GetXPosition(pTarget->pDynamicPath);
            }
            else
            {
                nX = 0;
            }
            break;
        }
        *pX = nX;

        switch (pTarget->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
        case UNIT_TILE:
            nY = pTarget->pStaticPath->tGameCoords.nY;
            break;

        default:
            if (pTarget->pDynamicPath)
            {
                nY = PATH_GetYPosition(pTarget->pDynamicPath);
            }
            else
            {
                nY = 0;
            }
            break;
        }
    }
    else
    {
        D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
        *pX = D2COMMON_10175_PathGetFirstPointX(pPath);
        nY = D2COMMON_10176_PathGetFirstPointY(pPath);
    }
    *pY = nY;

    if (!*pX || !nY)
    {
        ITEM_GetAdjacentPosition(pUnit, pX, pY);
    }
    return 1;
}

// 0x004C5470
int __fastcall AUTOMAP_RequestAtNearTarget(D2UnitStrc* pUnit, int nArg, int nArg3, int nArg4)
{
    int nTargetY;
    int nTargetX;
    if (!ITEM_GetTargetPosition(pUnit, &nTargetX, &nTargetY))
    {
        return 0;
    }

    if (!nTargetX || !nTargetY)
    {
        return 0;
    }

    if (PATH_ComputeSquaredDistance(CLIENTS_GetUnitX(pUnit), CLIENTS_GetUnitY(pUnit), nTargetX, nTargetY) > 10000)
    {
        return 0;
    }

    return MISSILE_SubmitMissileRequest(pUnit, nArg, nTargetX, nTargetY, nArg3, nArg4);
}

#pragma pack(push, 1)
struct d2data_00711218_t
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
};
#pragma pack(pop)

extern "C" struct d2data_00711218_t gData_00711218; // 0x00711218

extern D2CharSaveIdStrc gtCharSaveId = { { 1, 1, 1, 1, 1, 0xFF, 0xFF, 0xFF, 1, 1, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF } }; // 0x0070CCC8

extern D2AutomapPairStrc gaAutomapPairs[49] = {
    { 0 },
    { 1 },
    { 2 },
    { 3 },
    { 6, 1 },
    { 7, 1 },
    { 8, 1 },
    { 11, 2 },
    { 12, 2 },
    { 13, 3 },
    { 14, 3 },
    { 20, 4 },
    { 38, 4 },
    { 21, 5 },
    { 39, 5 },
    { 46, 6 },
    { 47, 6 },
    { 48, 6 },
    { 49, 6 },
    { 51, 7 },
    { 52, 7 },
    { 53, 7 },
    { 54, 7 },
    { 60, 8 },
    { 70, 8 },
    { 61, 9 },
    { 71, 9 },
    { 120, 10 },
    { 169, 10 },
    { 171, 10 },
    { 121, 11 },
    { 170, 11 },
    { 172, 11 },
    { 257, 12 },
    { 258, 12 },
    { 259, 12 },
    { 266, 13 },
    { 267, 13 },
    { 337, 14 },
    { 338, 14 },
    { 472, 15 },
    { 473, 15 },
    { 474, 15 },
    { 475, 15 },
    { 520, 16 },
    { 521, 16 },
    { 522, 16 },
    { 533, 17 },
    { 534, 17 }
}; // 0x00711258

extern int gbAutomapCenter = 1; // 0x007113E0

extern const int gaTownSkipCels[12] = { 0, 10, 15, 16, 19, 20, 25, 30, 35, 36, 39, -1 }; // 0x006D6608

extern const D2AutomapPointStrc gaAutomapCross[13] = {
    { 0, -1 },
    { 2, -2 },
    { 4, -1 },
    { 2 },
    { 4, 1 },
    { 2, 2 },
    { 0, 1 },
    { -2, 2 },
    { -4, 1 },
    { -2 },
    { -4, -1 },
    { -2, -2 },
    { 0, -1 }
}; // 0x006D6638

extern int gbAutomapParty = 1; // 0x007113E4

extern int gbAutomapPartyNames = 1; // 0x007113E8

extern int gnAutomapScale = 10; // 0x00711254

extern "C" struct d2data_00711218_t gData_00711218 = {
    (const void*)"English",
    (const void*)"Spanish",
    (const void*)"German",
    (const void*)"French",
    (const void*)"Portuguese",
    (const void*)"Italian",
    (const void*)"Japanese",
    (const void*)"Korean",
    (const void*)"Simplified Chinese",
    (const void*)"Traditional Chinese",
    (const void*)"Polish",
    (const void*)"Russian",
    (const void*)"English with Korean Chat",
    (const void*)"Unknown",
    (const void*)"14"
}; // 0x00711218
