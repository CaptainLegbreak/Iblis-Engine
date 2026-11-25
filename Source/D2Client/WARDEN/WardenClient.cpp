#include "D2Client.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2CelContext.h"
#include "D2Records.h"
#include "D2ClientTypes.h"
#include "D2ClientUi.h"
#include "D2ClientGame.h"
#include "D2StormTypes.h"
#include "D2Win32Types.h"
#include "D2ItemsWorld.h"
#include "D2MultiTypes.h"
#include "D2Unicode.h"
#include "D2WinSplitText.h"
#include "D2WaypointActRange.h"
#include "D2MsgRecord.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define gnGlobal_007BCAA0 (gtPlayerInvRect.nLeft)

#define gnGlobal_007BCAA4 (gtPlayerInvRect.nRight)

#define gnGlobal_007BCAA8 (gtPlayerInvRect.nTop)

#define gnGlobal_007BCAAC (gtPlayerInvRect.nBottom)

struct D2MsgHandlerEntryStrc;

struct Unicode;

struct D2RectStrc;

struct D2TextBoxStrc;

struct D2WaypointMenuEntryStrc;

struct D2WaypointActRangeStrc;

struct D2SetItemsTxt;

struct D2SkillsTxt;

struct D2MonStatsTxt;

struct D2RequestStrc;

struct D2RosterPetStrc;

struct D2OptionHeaderStrc;

struct D2OptionEntryStrc;

struct D2EscMenuUIStateStrc;

struct D2InvRectStrc;

class WardenModule;


struct D2ClientSlotObjStrc;


extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

struct D2TextBoxStrc
{
    char unk0x00[0x16];
    char nScroll[4];
    char unk0x1A[0x12];
};


typedef int (__fastcall* AREASCANFN)(void* pArg, D2UnitStrc* pUnit);

struct D2RequestStrc
{
    int nType;
    D2UnitStrc* pUnit;
    int unk0x08[2];
    int nArg0;
    int nArg1;
    int nArg2;
    int unk0x1C[4];
    int nArg3;
    int nArg4;
    int unk0x34[10];
};

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

int __cdecl ROSTER_IsAnyoneHostile(); // 0x0047A560

int __cdecl CUNIT_IsTrading(); // 0x004B8A10

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

void __cdecl GAME_ResetMouseState(); // 0x0044DA40

int __cdecl sub_0045AE90(); // 0x0045AE90

extern "C" int __cdecl PLAYER_GetScreenOffsetX(); // 0x0045AFC0

extern "C" int __cdecl PLAYER_GetScreenOffsetY(); // 0x0045AFD0

int __cdecl GAME_IsExpansion(); // 0x0044DCC0

int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0

void __fastcall SCMD_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0

int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

D2UnitStrc* __fastcall CUNIT_GetOwnerUnit(D2UnitStrc* pUnit); // 0x004639D0

void* __fastcall sub_0046E570_GetGfxEntry(D2UnitStrc* pUnit, int nMode); // 0x0046E570

void* __fastcall sub_0046E5A0_FindGfxNode(D2UnitStrc* pUnit, int nWeaponClassId, int nArg); // 0x0046E5A0

void* __fastcall GFX_LoadUnitGfxNode(D2UnitStrc* pUnit, int nWeaponClassId, int nArg); // 0x0046FA80

int __fastcall GFX_IsUnitOnScreen(D2UnitStrc* pUnit, int nX, int nY, int nArg1, int nArg2); // 0x004709A0

D2UnitStrc* __fastcall CUNIT_GetPathTargetUnit(D2UnitStrc* pUnit); // 0x004648F0

D2UnitStrc* __fastcall sub_004CD540_HandleRequest(D2RequestStrc* pRequest); // 0x004CD540

void __fastcall MISSILE_AddMissileEffect(D2UnitStrc* pMissile, int nMissile, int nArg1, int nArg2, int nArg3); // 0x004CEFE0

int __fastcall GFXUTIL_GetCofLayerValue(void* pEntry, int nArg); // 0x004DB0D0

int __fastcall sub_004E60A0_AddSetPropText(D2UnitStrc* pItem, int nArg1, int nArg2, int nArg3, int nProp, int nArg5, int nArg6, int nArg7); // 0x004E60A0

int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit); // 0x006203B0

int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit); // 0x00620410

int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit); // 0x00620650

int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit); // 0x006206B0

int __stdcall ITEMS_GetItemQuality(D2UnitStrc* pItem); // 0x00627E70

unsigned int __stdcall ITEMS_GetSetItemsMask(D2UnitStrc* pPlayer, D2UnitStrc* pSetItem, int bDontIgnoreInputItem); // 0x0062A370

D2SetItemsTxt* __stdcall ITEMS_GetSetItemsTxtRecordFromItem(D2UnitStrc* pItem); // 0x0062A490

int __stdcall ITEMS_GetNoOfSetItemsFromItem(D2UnitStrc* pItem); // 0x0062B3A0

int __stdcall STATES_CheckStateMaskOnUnit(D2UnitStrc* pUnit, int nState); // 0x0063A7B0

int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int bUseConvertedMode); // 0x0064F380

void __cdecl SELECT_ClearSelection(); // 0x00466FE0

void __fastcall sub_00467430(D2RectStrc* pRect); // 0x00467430

D2TextBoxStrc* __fastcall TEXT_CreateTextBox(const Unicode* wszText, int nMode); // 0x004A05E0

void __fastcall SKILLS_ScanArea(D2UnitStrc* pUnit, int nX, int nY, int nRange, int nFlags, AREASCANFN pfCallback, void* pArg, int bCheckType); // 0x004C5C40

int __fastcall SKILLS_ScanFindCallback(void* pArg, D2UnitStrc* pUnit); // 0x004C5E70

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00

void __fastcall SOUNDINST_ArmHint(int nKey, int nGroup, int nOffset, unsigned int nCount); // 0x004B9EF0

int __fastcall sub_004E0650_GetStringSound(unsigned short nStringId); // 0x004E0650

int __cdecl WINDOW_GetWindow(); // 0x004F59A0

int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

void __fastcall MSG_SendWord(unsigned char nCmd, unsigned short nArg); // 0x004785B0

void __stdcall INV_HandlePanelClick(SMSGHANDLER_PARAMS* pMsg); // 0x004912A0

int __stdcall HIREABLES_CanEquipHirelingItem(int nArg); // 0x004934D0

int __fastcall SPELLSEL_GetSkillIconCel(D2SkillsTxt* pSkillsTxt); // 0x004A8C80

int __fastcall SPELLSEL_GetSkillState(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x004A8D30

void __fastcall SPELLSEL_DrawSkillInfoBase(int nValue, D2SkillsTxt* pSkillsTxt, int nOwnerGUID, int nCharges, int nState, int nX, int nY, int nArg); // 0x004A9690

void __fastcall SPELLSEL_UpdateSkillButtonHover(short* pId, int nState, int nA, int nB, int nX, int nY); // 0x004A8D50

void __fastcall SPELLSEL_DrawSkillQuantity(short* pId, int nState, int nQuantity, int nX, int nY); // 0x004AA1F0

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

int __stdcall WAYPOINTS_GetLevelIdFromWaypointNo(unsigned short wWaypointNo, int* pLevelId); // 0x00660D90

int __stdcall WAYPOINTS_GetWaypointNoFromLevelId(int nLevelId, unsigned short* pWaypointNo); // 0x00660E00

int __stdcall WAYPOINTS_IsActivated(D2WaypointDataStrc* pData, unsigned short wField); // 0x00660E50

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill); // 0x00644140

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, int nFlags); // 0x00412650

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

int __fastcall CUNIT_GetBasePalShiftIndex(D2UnitStrc* pUnit); // 0x00463E50

int __fastcall CUNIT_GetPalShiftIndex(D2UnitStrc* pUnit); // 0x00463EB0

int __fastcall ROSTERPETS_IsOwnedByPlayer(D2UnitStrc* pUnit); // 0x004791B0

void __cdecl CHAT_RecallChatLine(); // 0x0047B9C0

void __stdcall CHAT_StepChatIndex(int nDelta); // 0x0047BA80

extern const int gdwBitMasks[]; // 0x006CE268

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern int gaSetPartialCounts_006DBD90[]; // 0x006DBD90

extern int gnScreenWidth; // 0x0071146C

extern D2OptionHeaderStrc gtMainOptionHeader; // 0x00713044

extern D2EscMenuUIStateStrc gaEscMenuUIState[38]; // 0x00713058

extern D2OptionEntryStrc gaMainOptionEntries[]; // 0x00713220

extern D2OptionHeaderStrc gtOptionsHeader; // 0x00714210

extern D2OptionHeaderStrc gtSoundOptionHeader; // 0x00714224

extern D2OptionEntryStrc gaOptionsEntries[]; // 0x00714238

extern D2OptionEntryStrc gaSoundOptionEntries[]; // 0x00715CC8

extern D2OptionHeaderStrc gtVideoOptionHeader; // 0x00718748

extern D2OptionHeaderStrc gtVideoResOptionHeader; // 0x0071875C

extern D2OptionEntryStrc gaVideoOptionEntries[]; // 0x00718770

extern D2OptionEntryStrc gaVideoResOptionEntries[]; // 0x0071ACA0

extern D2MsgHandlerEntryStrc gaTextMsgHandlers[]; // 0x00722600

extern D2WaypointActRangeStrc gaWaypointActRanges[]; // 0x007224AC

extern D2OptionHeaderStrc gtAutomapOptionHeader; // 0x0071D720

extern D2OptionHeaderStrc gtAutomapModeOptionHeader; // 0x0071D734

extern D2OptionEntryStrc gaAutomapOptionEntries[]; // 0x0071D748

extern D2OptionEntryStrc gaAutomapModeOptionEntries[]; // 0x0071F728

extern D2RosterPetStrc* gpRosterPets; // 0x007BB5BC

extern D2InvRectStrc gtPlayerInvRect; // 0x007BCAA0


extern int gnPanelOffsetX; // 0x007A2858

extern int gnPanelOffsetY; // 0x007A285C

extern char gbSent; // 0x007BF085

extern int gnWaypointCount; // 0x007BF08A

extern int gnWaypointEnabledCount; // 0x007BF08E

extern D2TextBoxStrc* gpTextBox; // 0x007BF0A4

extern int gbTextBoxDone; // 0x007BF1BC

extern int gnTextActive; // 0x007BF1C0

extern unsigned long gnStartTick; // 0x007BF22C

extern int gbTextSound; // 0x007BF230

extern int gbTextSide; // 0x007BF236

extern int gnGlobal_007BEEE8; // 0x007BEEE8

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);         // 0x00413020

int __fastcall MSG_SendWardenPacket(const void* pData, int nSize); // 0x00478830

struct D2ClientSlotObjStrc
{
    virtual void Slot0(int* pValue, int nSize);
    virtual void Slot1();
    virtual void Slot2(int nArg1, int nArg2, int* pOut);
    virtual void Slot3(int nArg);
};

namespace NWardenClient
{
struct Library;
}

typedef D2ClientSlotObjStrc* (__fastcall* WARDENCREATEFN)(NWardenClient::Library* pIface);

class WardenModule
{
public:
    WardenModule();
    ~WardenModule();                                                                // 0x004E06A0
    void* operator new(unsigned int nSize)
    {
        return SMemAlloc(nSize, ".\\WARDEN\\WardenClient.cpp", 0x10D, 0);
    }
    void operator delete(void* pMemory)
    {
        SMemFree(pMemory, ".\\WARDEN\\WardenClient.cpp", 0x117, 0);
    }
    bool sub_004E0730_Load(void* pData, int nSize);                         // 0x004E0730
    void* GetEntry(int nOrdinal);                                // 0x004E0700

    void* pImage;
    int unk0x04;
    int nImports;
    D2ClientSlotObjStrc* pObj;
    WARDENCREATEFN pfnCreate;
};

struct D2Warden47F930Strc
{
    int n00;
    int n04;
    int n08;

    D2Warden47F930Strc();
};

struct D2WardenModuleHolderAStrc
{
    WardenModule tModule;

    ~D2WardenModuleHolderAStrc();
};

struct D2WardenModuleHolderBStrc
{
    WardenModule tModule;

    ~D2WardenModuleHolderBStrc();
};

namespace NWardenClient
{
struct Library
{
    Library();
    virtual int WARDENCLIENT_SendWardenPacket(const void* pData, int nSize) = 0; // 0x00480000
    virtual bool WARDENCLIENT_ServiceLoadModule(const unsigned char* pModuleKey, const unsigned char* pRc4Key) = 0;
    virtual void WARDENCLIENT_CallServiceWithHashName(const unsigned char* pHash, int nArg2, int nArg3) = 0;
    virtual void* WARDENCLIENT_ServiceAlloc(int nSize) = 0;
    virtual void WARDENCLIENT_ServiceFree(void* pMemory) = 0;
    virtual void WARDENCLIENT_SetWardenBuffer(const void* pData, unsigned int nSize) = 0;
    virtual bool WARDENCLIENT_TakeWardenBuffer(void* pDst, unsigned int* pSize) = 0;
};
}

struct WardenClient : NWardenClient::Library
{
    WardenClient();
    int WARDENCLIENT_SendWardenPacket(const void* pData, int nSize);                                          // 0x00480000
    bool WARDENCLIENT_ServiceLoadModule(const unsigned char* pModuleKey, const unsigned char* pRc4Key); // 0x00480020
    void WARDENCLIENT_CallServiceWithHashName(const unsigned char* pHash, int nArg2, int nArg3);     // 0x00480040
    void* WARDENCLIENT_ServiceAlloc(int nSize);                                                      // 0x004800C0
    void WARDENCLIENT_ServiceFree(void* pMemory);                                                    // 0x004800E0
    void WARDENCLIENT_SetWardenBuffer(const void* pData, unsigned int nSize);                        // 0x00480100
    bool WARDENCLIENT_TakeWardenBuffer(void* pDst, unsigned int* pSize);                             // 0x00480150
};

struct D2StormHashCtxStrc;

struct D2RC4Strc;

struct D2WardenFindArgStrc;

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0

unsigned int __stdcall SStrLen(const char* szString); // 0x00413750

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

struct D2StormHashCtxStrc
{
    unsigned __int64 nBitCount;
    unsigned int nState[5];
    unsigned char pBlock[64];

    void Initialize();                                               // 0x00425D90
    void Append(const unsigned char* pData, unsigned int nLen); // 0x00425DD0
    void sub_00425F00_Final(unsigned char* pDigest);                        // 0x00425F00
};

struct D2RC4Strc
{
    unsigned char S[0x100];
    unsigned char i;
    unsigned char j;

    void sub_004E09B0_Init(const unsigned char* pKey, unsigned int nKeySize); // 0x004E09B0
    void ApplyKeystream(unsigned char* pData, unsigned int nSize);       // 0x0047F8C0
};

struct D2WardenFindArgStrc
{
    int unk0x00;
    int unk0x04;
};

struct D2ClientServiceStrc
{
    char unk0x00[0xC8];
    void (__fastcall* pfnFree)(void* pData, int nSize);
    int (__fastcall* pfnFind)(char* szName, int* pArg, void** ppData, int* pSize);
    int (__fastcall* pfnCall)(const char* szName, int nArg2, int nArg3, _FILETIME* pTime, int nArg5, int nArg6);
};

extern WardenModule* gpPendingWarden; // 0x007BC994

extern D2ClientServiceStrc* gpService; // 0x007BC998

static void __stdcall WARDENCLIENT_HashModule(const char* szName, unsigned char* pDigest, const unsigned char* pData, unsigned int nSkip, unsigned int nSize); // 0x0047F990

static int __stdcall WARDENCLIENT_LoadModuleByKey(const unsigned char* pRc4Key, const unsigned char* pModuleKey); // 0x0047FEE0

static void __stdcall WARDENCLIENT_HashModule(const char* szName, unsigned char* pDigest, unsigned int nSkip, const unsigned char* pData, unsigned int nSize); // 0x0047F990

static int __stdcall WARDENCLIENT_VerifyModuleSignature(const char* szName, unsigned char* pData, const unsigned char* pModulus, const unsigned char* pExponent, unsigned int nExponentSize, unsigned int nSkip, unsigned int nSize, unsigned int nSignatureSize); // 0x0047FA20

void __cdecl WARDENCLIENT_ActivatePendingModule(); // 0x00480230

extern WardenModule* gpSlotHolder; // 0x007BC990



static int gnPetIconPopupState; // 0x007BEECC

D2WaypointMenuEntryStrc gaWaypointEntries[9]; // 0x007BF03C

unsigned short gwTextStringId; // 0x007BF212

int gnHintId; // 0x007BF260

int gnTextLeft; // 0x007BF278

static int gbTextHandlersRegistered; // 0x007BF27C

int gnGlobal_007BEED4; // 0x007BEED4

void* gpWardenBuffer; // 0x007BC988

unsigned int gnWardenBufferSize; // 0x007BC98C

static int __stdcall WARDENCLIENT_LoadModule(const unsigned char* pData, const unsigned char* pKey, unsigned int nSize); // 0x0047FC70

int __fastcall WARDENCLIENT_InitWarden(int nValue); // 0x004803C0




// build: symbol ?gtWardenIface@* 0x00721C98
WardenClient gtWardenIface; // 0x00721C98



class D2SquelchListStrc
{
public:
    virtual int Squelch(const char* szName);
    virtual int Unsquelch(const char* szName);
    virtual int IsSquelched(const char* szName);
    virtual int AddFilter(const char* szText);
    virtual int RemoveFilter(const char* szText);
    virtual int IsFiltered(const char* szText);
    virtual void VirtSlot6();
    virtual void VirtSlot7();
    virtual int IsPersistent();
    virtual void SetPersistent(int bPersistent);
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);                         // 0x006829C0

extern "C" size_t __cdecl strlen(const char* sz);

extern "C" int __cdecl atoi(const char* szString);                                                          // 0x00681EBB

int __stdcall SStrCmpI(const char* szString1, const char* szString2, unsigned int nMaxChars); // 0x00413590


void __cdecl sub_00477C60_CheckCacheStats();                                                                // 0x00477C60

void __cdecl VIEW_ToggleCacheStats();                                                               // 0x00477C00

int __cdecl GAME_GetConnectionType();                                                                                 // 0x0044DB30

void __cdecl SOUNDINST_ToggleHints();                                                                    // 0x004BABC0

bool __fastcall CHAT_IsNarrowText(const Unicode* pText);                                            // 0x0047BD00

int __stdcall CHAT_ParseChatCommand(char** ppText, char* pCode, char* szArgument);                  // 0x0047BAD0

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700

void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);               // 0x005269D0

int __fastcall sub_00526800(const Unicode* pString);                                                      // 0x00526800

void __fastcall TEXT_PrintChatLine(const Unicode* pText, char nColor);                              // 0x0049E3A0

void __fastcall MSG_SendStrings(const unsigned char* pData);                                       // 0x004787B0

unsigned int __fastcall D2Win_10128(unsigned char nChar);                                                   // 0x00502550

D2SplittedTextStrc* __fastcall D2WINFONT_SplitText(Unicode* pText, unsigned int* pLineCount, int nWidth);    // 0x00502970

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText);                                             // 0x00501820

extern int gnLanguageId;                                                                           // 0x007BB5DC

extern unsigned char gbChatInputOpen;                                                              // 0x007BB5E1


extern int gnChatDrawCount;                                                                              // 0x007BB5EC

extern int gbNoPickup;                                                                             // 0x007A6A90

extern unsigned short gwChatHistoryCount;                                                          // 0x007BB5E4

extern Unicode gawszChatHistory_007BB840[8][257];                                                           // 0x007BB840

extern Unicode gwszChatLine_007BB638[];                                                                     // 0x007BB638

int __stdcall CHAT_HandleWhisperCommand(int bCheckStored, char* szInput, const char* szCommand); // 0x0047C1F0

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280

unsigned short __fastcall CUNIT_GetHotkeyBinding(int nA, int nB); // 0x00469AA0

const Unicode* __fastcall CMDTBL_GetKeyText(int nKey, int nArg2); // 0x00469DE0

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

void __stdcall sub_0047E9A0_DrawSlots(int bDraw); // 0x0047E9A0

int __cdecl sub_0047EA60_IsAnyPanelOpen(); // 0x0047EA60

int __cdecl sub_0047EB50_IsAnyLeftPanelOpen(); // 0x0047EB50

extern void* gpMiniPanelCel; // 0x007BC960

extern int gbSlotBarBlocked; // 0x007BC970

extern int gaSlotX[]; // 0x007BC898

extern int gaSlotY[]; // 0x007BC8B8

extern int gaSlotKind[]; // 0x007BC8D8

extern int gaSlotFrame[]; // 0x007BC918

int gaSlotX[8]; // 0x007BC898

int gaSlotY[8]; // 0x007BC8B8

int gaSlotKind[8]; // 0x007BC8D8

int gaSlotFrame[8]; // 0x007BC918

int gbSlotBarBlocked; // 0x007BC970


// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040


// build: symbol ??_7Library@NWardenClient@@6B@ 0x006D8E38
// build: symbol ??_7WardenClient@@6B@ 0x006D8E68
// build: symbol ??_R0?AUWardenClient@@@8 0x00721CC0
// 0x0047F8B0
void __fastcall WARDENCLIENT_SwapBytes(unsigned char* pA, unsigned char* pB)
{
    unsigned char nTemp = *pA;
    *pA = *pB;
    *pB = nTemp;
}

// 0x0047F8C0
void D2RC4Strc::ApplyKeystream(unsigned char* pData, unsigned int nSize)
{
    for (unsigned int n = 0; n < nSize; ++n)
    {
        ++i;
        j += S[i];
        unsigned char* pA = &S[i];
        unsigned char* pB = &S[j];
        unsigned char t = *pA;
        *pA = *pB;
        *pB = t;
        pData[n] ^= S[(unsigned char)(S[j] + S[i])];
    }
}

// 0x0047F930
D2Warden47F930Strc::D2Warden47F930Strc()
{
    n00 = 0;
    n04 = 0;
    n08 = 0;
}

// 0x0047F940
D2WardenModuleHolderAStrc::~D2WardenModuleHolderAStrc()
{
}

void __cdecl sub_K04_EmitUse(int* pValue);

// 0x0047F950
static int __stdcall WARDENCLIENT_CheckBlockSignature(const char* pEnd, const char* pBegin, int* pSize, const char* pBase)
{
    *pSize = pEnd - pBegin - 4;
    if (pEnd >= pBegin + 4)
    {
        unsigned int dwTag;
        SMemCopy(&dwTag, pBase + *pSize, 4);
        return dwTag == 0x5349474E;
    }
    return 0;
}

int __cdecl sub_K04_EmitCheckBlockSignature(const char* pBegin, const char* pEnd, const char* pBase)
{
    int nSize;
    const int bOk = WARDENCLIENT_CheckBlockSignature(pEnd, pBegin, &nSize, pBase);
    sub_K04_EmitUse(&nSize);
    return bOk;
}

// 0x0047F990
static void __stdcall WARDENCLIENT_HashModule(const char* szName, unsigned char* pDigest, const unsigned char* pData, unsigned int nSkip, unsigned int nSize)
{
    D2StormHashCtxStrc tCtx;
    char szBuffer[0x400];
    tCtx.Initialize();
    if (nSkip)
    {
        tCtx.Append(pData + nSkip, nSize - nSkip);
        tCtx.Append(pData, nSkip);
    }
    else
    {
        tCtx.Append(pData, nSize);
    }
    SStrCopy(szBuffer, szName, 0x400);
    SStrUpper(szBuffer);
    tCtx.Append((const unsigned char*)szBuffer, SStrLen(szBuffer));
    tCtx.sub_00425F00_Final(pDigest);
}

static inline int WardenReadTag(const unsigned char* pSource)
{
    int nTag;
    SMemCopy(&nTag, pSource, 4);
    return nTag;
}

// 0x0047FA20
static int __stdcall WARDENCLIENT_VerifyModuleSignature(const char* szName, unsigned char* pData, const unsigned char* pModulus, const unsigned char* pExponent, unsigned int nExponentSize, unsigned int nSkip, unsigned int nSize, unsigned int nSignatureSize)
{
    D2_ASSERT(nSkip <= nSize, 0xA3);
    unsigned int nDataSize = nSize - nSignatureSize - 4;
    unsigned char* pSignature;
    if (nSize < nSignatureSize + 4)
    {
        goto fail;
    }
    pSignature = pData + nDataSize;
    if (WardenReadTag(pSignature) != 0x5349474E)
    {
fail:
        return 0;
    }
    unsigned char* pExpected = (unsigned char*)SMemAlloc(nSignatureSize, ".\\WARDEN\\WardenClient.cpp", 0xAB, 0);
    SMemFill(pExpected, nSignatureSize, 0xBB);
    pExpected[nSignatureSize - 1] = 0x0B;
    WARDENCLIENT_HashModule(szName, pExpected, pData, nSkip, nDataSize);
    unsigned char* pDecrypted = (unsigned char*)SMemAlloc(nSignatureSize, ".\\WARDEN\\WardenClient.cpp", 0xB5, 0);
    SMemCopy(pDecrypted, pSignature + 4, nSignatureSize);
    void* hResult;
    void* hSignature;
    void* hExponent;
    void* hModulus;
    SBigNew(&hResult);
    SBigNew(&hSignature);
    SBigNew(&hExponent);
    SBigNew(&hModulus);
    SBigFromBinary(hSignature, pDecrypted, nSignatureSize);
    SBigFromBinary(hExponent, pExponent, nExponentSize);
    SBigFromBinary(hModulus, pModulus, nSignatureSize);
    SBigPowMod(hResult, hSignature, hExponent, hModulus);
    SBigToBinaryBuffer(hResult, pDecrypted, nSignatureSize, 0);
    int bValid = !SMemCmp(pDecrypted, pExpected, nSignatureSize);
    SMemFree(pExpected, ".\\WARDEN\\WardenClient.cpp", 0xCC, 0);
    SMemFree(pDecrypted, ".\\WARDEN\\WardenClient.cpp", 0xCD, 0);
    SBigDel(hResult);
    SBigDel(hSignature);
    SBigDel(hExponent);
    SBigDel(hModulus);
    return bValid;
}

// 0x0047FBC0
WardenModule::WardenModule()
{
    pImage = 0;
    unk0x04 = 0;
    nImports = 0;
    pObj = 0;
    pfnCreate = 0;
}

// 0x0047FBE0
D2WardenModuleHolderBStrc::~D2WardenModuleHolderBStrc()
{
}

// 0x0047FBF0
void* __fastcall WARDENCLIENT_AllocLoaderMemory(unsigned int nSize)
{
    return SMemAlloc(nSize, ".\\WARDEN\\WardenClient.cpp", 0x10D, 0);
}

// 0x0047FC10
void __fastcall WARDENCLIENT_FreeLoaderMemory(void* pMemory)
{
    SMemFree(pMemory, ".\\WARDEN\\WardenClient.cpp", 0x117, 0);
}

// 0x0047FC30
NWardenClient::Library::Library()
{
}

// build: symbol ??1WardenModule@@QAE@XZ 0x004E06A0
// build: symbol ??_GWardenModule@@QAEPAXI@Z 0x0047FC40
// 0x0047FC40

// 0x0047FC70
static int __stdcall WARDENCLIENT_LoadModule(const unsigned char* pData, const unsigned char* pKey, unsigned int nSize)
{
    char szName[10];
    szName[0] = (char)0x5F;
    szName[1] = (char)0x7B;
    szName[2] = (char)0x53;
    szName[3] = (char)0xE7;
    szName[4] = (char)0xF2;
    szName[5] = (char)0x5A;
    szName[6] = (char)0xBF;
    szName[7] = (char)0x75;
    szName[8] = (char)0x8C;
    szName[9] = 0;
    for (unsigned int i = 0; i < 10; ++i)
    {
        szName[i] *= 0xD3;
    }
    if (gpPendingWarden)
    {
        gpPendingWarden->~WardenModule();
        delete gpPendingWarden;
        gpPendingWarden = 0;
    }
    unsigned char* pBuffer = (unsigned char*)SMemAlloc(nSize, ".\\WARDEN\\WardenClient.cpp", 0x16E, 0);
    SMemCopy(pBuffer, pData, nSize);
    if (!pBuffer)
    {
        return 0;
    }
    D2RC4Strc tRc4;
    tRc4.sub_004E09B0_Init(pKey, 0x10);
    tRc4.ApplyKeystream(pBuffer, nSize);
// build: symbol ?gabExponent@* 0x006D8D14
// build: symbol ?gabModulus@* 0x006D8D18
    if (!WARDENCLIENT_VerifyModuleSignature(szName, pBuffer, gabModulus, gabExponent, 4, 0, nSize, 0x100))
    {
        SMemFree(pBuffer, ".\\WARDEN\\WardenClient.cpp", 0x17C, 0);
        return 0;
    }
    unsigned int nModuleSize = *(unsigned int*)pBuffer;
    unsigned char* pModule = (unsigned char*)SMemAlloc(nModuleSize, ".\\WARDEN\\WardenClient.cpp", 0x182, 0);
    if (!pModule)
    {
        SMemFree(pBuffer, ".\\WARDEN\\WardenClient.cpp", 0x185, 0);
        return 0;
    }
    if (sub_006C79C0_Decompress(pModule, &nModuleSize, pBuffer + 4, nSize - 4))
    {
        SMemFree(pBuffer, ".\\WARDEN\\WardenClient.cpp", 0x18D, 0);
        SMemFree(pModule, ".\\WARDEN\\WardenClient.cpp", 0x18E, 0);
        return 0;
    }
    SMemFree(pBuffer, ".\\WARDEN\\WardenClient.cpp", 0x193, 0);
    WardenModule* pWarden = new WardenModule;
    if (!pWarden)
    {
        SMemFree(pModule, ".\\WARDEN\\WardenClient.cpp", 0x199, 0);
        return 0;
    }
    if (!pWarden->sub_004E0730_Load(pModule, nModuleSize))
    {
        SMemFree(pModule, ".\\WARDEN\\WardenClient.cpp", 0x1A0, 0);
        delete pWarden;
        return 0;
    }
    pWarden->pfnCreate = (WARDENCREATEFN)pWarden->GetEntry(1);
    if (!pWarden->pfnCreate)
    {
        pWarden->~WardenModule();
        SMemFree(pModule, ".\\WARDEN\\WardenClient.cpp", 0x1AA, 0);
        delete pWarden;
        return 0;
    }
    SMemFree(pModule, ".\\WARDEN\\WardenClient.cpp", 0x1B0, 0);
    gpPendingWarden = pWarden;
    return 1;
}

// 0x0047FEE0
static int __stdcall WARDENCLIENT_LoadModuleByKey(const unsigned char* pRc4Key, const unsigned char* pModuleKey)
{
// build: symbol ?gabBuiltinModuleKey@* 0x006D8768
    if (!SMemCmp(pModuleKey, gabBuiltinModuleKey, 0x10))
    {
// build: symbol ?gabBuiltinModule@* 0x006D74B0
// build: symbol ?gabBuiltinModuleRc4Key@* 0x006D8778
        return WARDENCLIENT_LoadModule(gabBuiltinModule, gabBuiltinModuleRc4Key, 0x12B2);
    }
    char szName[0x28];
    for (unsigned int i = 0; i < 0x10; ++i)
    {
        sprintf(&szName[i * 2], "%02x", pModuleKey[i]);
    }
    SStrCopy(&szName[0x20], ".mod", 5);
    if (!gpService)
    {
        return 0;
    }
    D2WardenFindArgStrc tFindArg;
    void* pModule;
    int nModuleSize;
    if (!gpService->pfnFind(szName, &tFindArg.unk0x00, &pModule, &nModuleSize))
    {
        return 0;
    }
    int nResult = WARDENCLIENT_LoadModule((const unsigned char*)pModule, pRc4Key, nModuleSize);
    gpService->pfnFree(pModule, nModuleSize);
    return nResult;
}

// 0x0047FFB0
int __stdcall WARDENCLIENT_CallServiceWithTime(const char* szName, int nArg2, int nArg3)
{
    if (!gpService)
        return 0;
    _FILETIME tTime;
    GetSystemTimeAsFileTime(&tTime);
    return gpService->pfnCall(szName, nArg2, nArg3, &tTime, -1, -1);
}

// 0x00480000
int WardenClient::WARDENCLIENT_SendWardenPacket(const void* pData, int nSize)
{
    return MSG_SendWardenPacket(pData, nSize);
}

// 0x00480020
bool WardenClient::WARDENCLIENT_ServiceLoadModule(const unsigned char* pModuleKey, const unsigned char* pRc4Key)
{
    return WARDENCLIENT_LoadModuleByKey(pRc4Key, pModuleKey);
}

// 0x00480040
void WardenClient::WARDENCLIENT_CallServiceWithHashName(const unsigned char* pHash, int nArg2, int nArg3)
{
    char szName[40];
    for (unsigned int i = 0; i < 16; ++i)
        sprintf(&szName[i * 2], "%02x", pHash[i]);
    SStrCopy(&szName[32], ".mod", 5);
    if (!gpService)
        return;
    _FILETIME tTime;
    GetSystemTimeAsFileTime(&tTime);
    gpService->pfnCall(szName, nArg2, nArg3, &tTime, -1, -1);
}


// 0x004800C0
void* WardenClient::WARDENCLIENT_ServiceAlloc(int nSize)
{
    return SMemAlloc(nSize, ".\\WARDEN\\WardenClient.cpp", 0x274, 0);
}


// 0x004800E0
void WardenClient::WARDENCLIENT_ServiceFree(void* pMemory)
{
    SMemFree(pMemory, ".\\WARDEN\\WardenClient.cpp", 0x27B, 0);
}


// 0x00480100
void WardenClient::WARDENCLIENT_SetWardenBuffer(const void* pData, unsigned int nSize)
{
    if (gpWardenBuffer)
    {
        SMemFree(gpWardenBuffer, ".\\WARDEN\\WardenClient.cpp", 0x283, 0);
    }
    gpWardenBuffer = SMemAlloc(nSize, ".\\WARDEN\\WardenClient.cpp", 0x284, 0);
    gnWardenBufferSize = nSize;
    sub_0041D2A0_MemCopy(gpWardenBuffer, pData, nSize);
}

// 0x00480150
bool WardenClient::WARDENCLIENT_TakeWardenBuffer(void* pDst, unsigned int* pSize)
{
    void* pBuffer = gpWardenBuffer;
    if (!pBuffer)
    {
        return false;
    }
    unsigned int nSize = *pSize < gnWardenBufferSize ? *pSize : gnWardenBufferSize;
    *pSize = nSize;
    sub_0041D2A0_MemCopy(pDst, pBuffer, nSize);
    SMemFree(gpWardenBuffer, ".\\WARDEN\\WardenClient.cpp", 0x292, 0);
    gpWardenBuffer = 0;
    gnWardenBufferSize = 0;
    return true;
}

// 0x004801C0
WardenClient::WardenClient()
{
}

struct D2UnitStrc;

void WardenModule_EmitDelete(WardenModule* pModule)
{
    delete pModule;
}

// 0x004801D0
void __cdecl WARDENCLIENT_UnloadWarden()
{
    if (gpSlotHolder)
    {
        gpSlotHolder->pObj->Slot1();
        gpSlotHolder->~WardenModule();
        delete gpSlotHolder;
    }
    gpSlotHolder = 0;
}


// 0x00480230
void __cdecl WARDENCLIENT_ActivatePendingModule()
{
    while (gpPendingWarden)
    {
        if (gpSlotHolder)
        {
            gpSlotHolder->pObj->Slot1();
            gpSlotHolder->~WardenModule();
            delete gpSlotHolder;
        }
        gpSlotHolder = gpPendingWarden;
        gpPendingWarden = 0;
        gpSlotHolder->pObj = gpSlotHolder->pfnCreate(&gtWardenIface);
// build: symbol ?gnWardenIfaceValue@* 0x00721C94
        int nValue = gnWardenIfaceValue;
        gpSlotHolder->pObj->Slot0(&nValue, 4);
    }
}

// 0x004802E0
void __fastcall WARDENCLIENT_ProcessWardenRequest(int nArg1, int nArg2)
{
    if (gpSlotHolder)
    {
        int nOut = 0;
        gpSlotHolder->pObj->Slot2(nArg1, nArg2, &nOut);
        WARDENCLIENT_ActivatePendingModule();
    }
}

// 0x00480320
void __fastcall WARDENCLIENT_TickModule(int nArg)
{
    if (gpSlotHolder)
    {
        gpSlotHolder->pObj->Slot3(nArg);
        WARDENCLIENT_ActivatePendingModule();
    }
}


// 0x00480340
void __cdecl WARDENCLIENT_ResetWarden()
{
    if (gpPendingWarden)
    {
        gpPendingWarden->~WardenModule();
        delete gpPendingWarden;
        gpPendingWarden = 0;
    }
    WARDENCLIENT_UnloadWarden();
    gnWardenIfaceValue = -1;
    gpService = 0;
    if (gpWardenBuffer)
        SMemFree(gpWardenBuffer, ".\\WARDEN\\WardenClient.cpp", 0x24F, 0);
    gpWardenBuffer = 0;
    gnWardenBufferSize = 0;
}

// 0x004803C0
int __fastcall WARDENCLIENT_InitWarden(int nValue)
{
    sub_00480340();
    gnWardenIfaceValue = nValue;
// build: symbol ?BNCLIENT_GetInterfaceTable@* 0x00518C10
    gpService = BNCLIENT_GetInterfaceTable();
    if (!gpService)
    {
        return 0;
    }
    WARDENCLIENT_LoadModuleByKey(gabBuiltinModuleRc4Key, gabBuiltinModuleKey);
    WARDENCLIENT_ActivatePendingModule();
    return 1;
}


static inline int InBox(int nX, int nY, int nLeft, int nRight, int nTop, int nBottom)
{
    return nX >= nLeft && nX <= nRight && nY >= nTop && nY <= nBottom;
}





// 0x004A1320
void __fastcall WARDENCLIENT_OpenTextPanel(unsigned short nStringId, int bSide, int bSound)
{
    if (!bSide)
    {
        gbTextSide = 0;
// build: symbol ?gnTextTop@* 0x007225FC
        gnTextTop = 0x0C;
        gnTextLeft = (gnScreenWidth - 0x145) / 2;
    }
    else
    {
        gbTextSide = 1;
        gnTextTop = 0x105 - gnPanelOffsetY;
        gnTextLeft = gnPanelOffsetX;
    }

    GAME_ResetMouseState();

    if (gnHintId)
    {
        const int nHint = sub_004B9610_FindHint(gnHintId);
        if (nHint)
        {
            SOUNDINST_ArmHint(nHint, 0, 0, 4);
        }
        gnHintId = 0;
    }

// build: symbol ?ghHintSound@* 0x007BF24B
    ghHintSound = 0;
// build: symbol ?gbTextFromObject@* 0x007BF20A
    gbTextFromObject = 0;

    D2RectStrc tRect;
    const int nScreenBottom = gnScreenHeight - 0x35;
    tRect.nTop = gnTextTop;
    tRect.nBottom = gnTextTop + 0xB6;
    if (tRect.nBottom >= nScreenBottom)
    {
        tRect.nBottom = nScreenBottom;
    }
    tRect.nLeft = gnTextLeft - 10;
    tRect.nRight = gnTextLeft + 0x14F;
    sub_00467430(&tRect);
    SELECT_ClearSelection();

    gwTextStringId = nStringId;
    if (gpTextBox)
    {
        return;
    }

    gbTextBoxDone = 0;
    const int nOldFont = D2Win_10127_SetFont(8);
    gpTextBox = TEXT_CreateTextBox(D2LANG_GetStringFromTblIndex(nStringId), 2);
    D2_ASSERT(gpTextBox, 0x1063);
    D2Win_10127_SetFont(nOldFont);

    *(int*)gpTextBox->nScroll = 0;
    gnTextActive = 1;
// build: symbol ?gbTextPanelOpen@* 0x007BF1FA
    gbTextPanelOpen = 1;
    if (!gbTextHandlersRegistered)
    {
        gbTextHandlersRegistered = 1;
        gnStartTick = GetTickCount();
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaTextMsgHandlers, 7);
    }

    const int nSoundId = sub_004E0650_GetStringSound(nStringId);
    if (nSoundId)
    {
        ghHintSound = sub_004B9A00(nSoundId, sub_00463DD0_GetPlayerUnit(), 5, 0, 0);
        gnHintId = nSoundId;
    }

    if ((nStringId == 0x7F || nStringId == 0x4E22 || nStringId == 0x4EC9 || nStringId == 0x4EA3 || nStringId == 0x18C) && bSound)
    {
        gbTextSound = 1;
    }
}



static D2MonStatsTxt* MONSTATS_GetTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static D2SkillsTxt* SKILLS_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }

    return 0;
}


#include "gen/data/Source/D2Client/WARDEN/WardenClient.inc"
