#include "D2LanguageNames.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2ClientTypes.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"
#include "D2MonsterIds.h"
#include "D2Primitives.h"
#include "D2Path.h"
#include "D2ClientUi.h"
#include "D2CelContext.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2GameTypes.h"
#include "D2LevelTxt.h"
#include "D2StatIds.h"
#include "D2MsgRecord.h"
#include "D2ClientQuestLog.h"
#include "D2ClientStatButton.h"
#include "D2WinSplitText.h"
#include "D2ClientTextBox.h"
#include "D2ClientQuestText.h"
#include "D2ClientTextBox.h"
#include "D2ClientQuestText.h"
#include "D2ClientKeyConfig.h"

#define OFFSET(T,F) ((unsigned int)&(((T*)0)->F))

struct D2MsgHandlerEntryStrc;

struct Unicode;

struct D2ClientTabStrc;

struct D2TextListStrc;






struct D2GSPacketSrv26;

struct D2CommonChatIgnoreListStrc;

struct D2TextBoxStrc;

class D2ListBoxViewStrc;

struct D2ClientTextDataStrc;

struct D2UnitStrc;

struct D2CommonIgnoreListStrc;

struct D2SplittedTextStrc;

struct SMSGHANDLER_PARAMS;

struct ByteRecord;

struct PacketWords;

struct PacketShorts;

struct Digest;

struct HashState;

struct Member;

struct ClassRecord;

struct ClassTableView;

struct UnitView;

class ListBoxImplementation;

class UIWidget;

class ListBoxWrapper;

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10

int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0

void __stdcall INV_SelectItemPageTab(unsigned char nTab); // 0x00487A10

void __cdecl INV_SetupPanelButtons(); // 0x00487ED0

int __fastcall NPCMENU_GetInteractNpcId(int* pUnitId); // 0x004B3230

void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0

extern D2ClientTabStrc gaNpcTabStates[]; // 0x0072211A

extern int gnGlobal_007BCAF0; // 0x007BCAF0

extern int gbNpcTradeClicked; // 0x007BCBEC

extern int gnInvPanelMode; // 0x007BCBF0

extern int gdwNpcPanelDelayTick; // 0x007BCC08

extern int gnSelectedShopButton; // 0x007BCC40

extern int gbInvGoldButtonDown; // 0x007BCE30

extern int gnPetIconPopupState; // 0x007BEECC






int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0

int __cdecl WINDOW_GetWindow(); // 0x004F59A0

void __fastcall AUTOMAP_UnregisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10

void __fastcall SCMD_RegisterMsgHandlers(int hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0


extern D2MsgHandlerEntryStrc gaTextMsgHandlers[]; // 0x00722600

struct D2GSPacketSrv26
{
    unsigned char nHeader;
    unsigned char nMessageType;
    unsigned char nLang;
    unsigned char nUnitType;
    unsigned int dwUnitGUID;
    unsigned char nMessageColor;
    unsigned char nNameColor;
    char szName[16];
    char szMessage[256];
};

extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int nCodePage, unsigned long dwFlags, const char* szSource, int nSource, Unicode* wszDest, int nDest); // 0x006CC29C

extern "C" unsigned int __cdecl strlen(const char* szString);

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0

Unicode* __fastcall INV_PrefixColorCode(Unicode* pText, int nDigit); // 0x004521C0

Unicode* __fastcall SCMD_StripColorCodes(Unicode* pText); // 0x00452300

int __fastcall ROSTER_IsNotSquelched(int nUnitId); // 0x0047A170

void __fastcall INV_OpenRecipeScroll(const Unicode* wszName, int nUnused, int nArg); // 0x0048BBE0

void __fastcall TEXT_PrintChatLine(const Unicode* wszText, char nColor); // 0x0049E3A0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource); // 0x005267E0

void __cdecl sub_005269D0(int nBufferSize, Unicode* pDst, const Unicode* pFormat, ...); // 0x005269D0

char* __stdcall UNITS_GetPlayerName(D2UnitStrc* pUnit); // 0x00622150

void __stdcall CHAT_FreeHoverMsg(void* pMemoryPool, D2HoverTextStrc* pHoverText); // 0x006611A0

extern int gnGameFrame; // 0x007BF20E

static bool TEXT_IsLanguageCompatible(int nLangId);


class D2ListBoxViewStrc
{
public:
    virtual ~D2ListBoxViewStrc();
};

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

void __fastcall MSG_SendTwoDwords(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0

void __stdcall TEXT_FreeTextList(void* pList); // 0x0049D4D0

void __cdecl TEXT_FreeTextPanelCels(); // 0x0049FE10

D2SplittedTextStrc* __stdcall TEXT_BuildTextLines(const Unicode* wszText, int* pLineCount, unsigned short* pMaxLines); // 0x004A0320

void __fastcall DIALOG_DestroyDialog(void* pRes); // 0x004B8020

void __fastcall SOUNDINST_ArmHint(int nKey, int nGroup, int nOffset, unsigned int nCount); // 0x004B9EF0

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820

D2SplittedTextStrc* __fastcall D2WINFONT_SplitText(const Unicode* pText, int* pLineCount, int nWidth); // 0x00502970

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

D2TextBoxStrc* __stdcall CHAT_GetUsedFromHoverMsg(D2HoverTextStrc* pHoverMsg); // 0x00661200

void __stdcall CHAT_SetUsedInHoverMsg(D2HoverTextStrc* pHoverMsg, int bUsed); // 0x00661210

void __stdcall TEXT_FreeTextHeader(int nHandle); // 0x006612A0



void* __stdcall SMemAlloc(size_t nSize, const char* szFile, int nLine, int nFlags); // 0x00413020

class UIWidget
{
public:
    static void* operator new(size_t nSize)
    {
// build: symbol ?gszNew@* 0x006CC82C
        return SMemAlloc(nSize, gszNew, -1, 0);
    }

    virtual ~UIWidget();
    virtual void Draw() = 0;
    virtual int OnMouseWheel(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int OnLButtonDown(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int OnLButtonUp(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot05(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int OnKeyDown(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot07(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int MsgSlot08(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int OnKeyRight(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int OnKeyLeft(SMSGHANDLER_PARAMS* pMsg) = 0;
    virtual int GetValue() = 0;

    int unk0x04;
};

class ListBoxWrapper : public UIWidget
{
public:
    ListBoxWrapper(int nX, int nY, int nWidth, int nHeight, int nArg10, int nArg14, int nArg18, int nArg1C,
        int nArg20);                                                                                        // 0x004BF8F0
    virtual ~ListBoxWrapper();
    virtual void Draw();
    virtual int OnMouseWheel(SMSGHANDLER_PARAMS* pMsg);
    virtual int OnLButtonDown(SMSGHANDLER_PARAMS* pMsg);
    virtual int OnLButtonUp(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot05(SMSGHANDLER_PARAMS* pMsg);
    virtual int OnKeyDown(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot07(SMSGHANDLER_PARAMS* pMsg);
    virtual int MsgSlot08(SMSGHANDLER_PARAMS* pMsg);
    virtual int OnKeyRight(SMSGHANDLER_PARAMS* pMsg);
    virtual int OnKeyLeft(SMSGHANDLER_PARAMS* pMsg);
    virtual int GetValue();
    virtual void sub_004BBFB0();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Refresh();

    ListBoxImplementation* pImpl;
};

extern ListBoxWrapper* gpListBox; // 0x007BF1B4

extern int gbTextBoxShown; // 0x007BF1C8


extern unsigned short gwTextStringId; // 0x007BF212

extern int gnHintId; // 0x007BF260

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

extern int gnScreenWidth; // 0x0071146C

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

void __cdecl GAME_ResetMouseState(); // 0x0044DA40

void __cdecl TEXT_DrawPanelFrame(); // 0x0049FA10

void __stdcall TEXT_OpenTextPanel(int bFlag); // 0x0049FBA0

extern D2ClientTextDataStrc* gpTextData; // 0x007BF228

extern int gbTextDataOpen; // 0x007BF254

struct ByteRecord
{
    char gap00[0x3E];
    unsigned char value;
    char tail[0x4F];
};

#pragma pack(push, 1)

struct PacketWords
{
    char prefix[1];
    unsigned short kind;
    unsigned short wSlots[6];
};

struct PacketShorts
{
    char prefix[1];
    unsigned short kind;
    unsigned short a;
    unsigned short b;
    unsigned short c;
};

#pragma pack(pop)

struct Digest
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned int e;
};

struct HashState
{
    unsigned int a;
    unsigned int b;
    unsigned int c;
    unsigned int d;
    unsigned int e;
    unsigned int lowCount;
    unsigned int highCount;
    char block[0x40];
};

struct Member
{
    short value;
};

struct ClassRecord
{
    char gap00[2];
    short relation;
    short next;
    char gapToMembers[0x16A];
    Member members[8];
    char tail[0x28];
};

struct ClassTableView
{
    char gap00[0xA78];
    ClassRecord* records;
    char gapAfterRecords[4];
    int count;
};

struct UnitView
{
    unsigned int type;
    int classId;
};

typedef char ByteRecord_value[OFFSET(ByteRecord,value)==0x3E?1:-1];

typedef char PacketWords_kind[OFFSET(PacketWords,kind)==0x1?1:-1];

typedef char PacketWords_wSlots[OFFSET(PacketWords,wSlots)==0x3?1:-1];

typedef char PacketShorts_kind[OFFSET(PacketShorts,kind)==0x1?1:-1];

typedef char PacketShorts_a[OFFSET(PacketShorts,a)==0x3?1:-1];

typedef char PacketShorts_b[OFFSET(PacketShorts,b)==0x5?1:-1];

typedef char PacketShorts_c[OFFSET(PacketShorts,c)==0x7?1:-1];

typedef char ClassRecord_relation[OFFSET(ClassRecord,relation)==0x2?1:-1];

typedef char ClassRecord_next[OFFSET(ClassRecord,next)==0x4?1:-1];

typedef char ClassRecord_members[OFFSET(ClassRecord,members)==0x170?1:-1];

typedef char ClassTableView_records[OFFSET(ClassTableView,records)==0xA78?1:-1];

typedef char ClassTableView_count[OFFSET(ClassTableView,count)==0xA80?1:-1];

typedef char UnitView_type[OFFSET(UnitView,type)==0x0?1:-1];

typedef char UnitView_classId[OFFSET(UnitView,classId)==0x4?1:-1];

typedef char Digest_a[OFFSET(Digest,a)==0x0?1:-1];

typedef char Digest_b[OFFSET(Digest,b)==0x4?1:-1];

typedef char Digest_c[OFFSET(Digest,c)==0x8?1:-1];

typedef char Digest_d[OFFSET(Digest,d)==0xC?1:-1];

typedef char Digest_e[OFFSET(Digest,e)==0x10?1:-1];

typedef char HashState_a[OFFSET(HashState,a)==0x0?1:-1];

typedef char HashState_b[OFFSET(HashState,b)==0x4?1:-1];

typedef char HashState_c[OFFSET(HashState,c)==0x8?1:-1];

typedef char HashState_d[OFFSET(HashState,d)==0xC?1:-1];

typedef char HashState_e[OFFSET(HashState,e)==0x10?1:-1];

typedef char HashState_lowCount[OFFSET(HashState,lowCount)==0x14?1:-1];

typedef char HashState_highCount[OFFSET(HashState,highCount)==0x18?1:-1];

typedef char ByteRecord_size[sizeof(ByteRecord)==0x8E?1:-1];

typedef char PacketWords_size[sizeof(PacketWords)==0xF?1:-1];

typedef char PacketShorts_size[sizeof(PacketShorts)==0x9?1:-1];

typedef char Digest_size[sizeof(Digest)==0x14?1:-1];

typedef char HashState_size[sizeof(HashState)==0x5C?1:-1];

typedef char Member_size[sizeof(Member)==0x2?1:-1];

typedef char ClassRecord_size[sizeof(ClassRecord)==0x1A8?1:-1];

// build: symbol _sgptSoundHeaderTable 0x007BC9A0
extern "C" ByteRecord* sgptSoundHeaderTable;

extern "C" int gRecordCount_007BC9A4;

extern "C" unsigned int gValue_007BF254; // 0x007BF254

extern "C" unsigned int gValue_007BF2A4; // 0x007BF2A4

extern "C" unsigned int gValue_007BF2AC; // 0x007BF2AC

extern "C" HashState gStates_00882760[];

extern "C" ClassTableView* gClassTable_00744304;

static bool TEXT_ConvertHoverText(int nLangId, Unicode* wszText, const char* szText); // 0x0049E280

static void __stdcall TEXT_SetHoverText(int nLangId, const char* szText, D2UnitStrc* pUnit); // 0x0049F410

int __cdecl TEXT_CloseMessageLogCallback(); // 0x004A0030

void __fastcall DIALOG_AddWidget(D2ClientDialogStrc* pDialog, void* pWidget, int nArg8, int nArgC); // 0x004B7C00

// build: symbol ?DIALOG_CreateDialog@* 0x004B7EB0
D2ClientDialogStrc* __fastcall DIALOG_CreateDialog(int nArg1, int nArg2, int nArg8, int nArgC, int nArg10, int nArg14,
    int nArg18, int nArg1C, int nArg20, int nArg24, int nArg28); // 0x004B7EB0

void __fastcall sub_004B82F0_Select(D2ClientDialogStrc* pDialog, int nIndex); // 0x004B82F0

void __fastcall sub_004B8370_SetField5C(D2ClientDialogStrc* pDialog, int nValue); // 0x004B8370

// build: symbol ?DIALOG_AddTextLine@* 0x004B85F0
void __fastcall DIALOG_AddTextLine(D2ClientDialogStrc* pDialog, const Unicode* wszText, int nArg8, int nArgC,
    int nArg10, int nArg14, int (__cdecl* pfnCallback)(), int nArg1C); // 0x004B85F0



extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize); // 0x00681EB0



extern D2TextBoxStrc* gpTextBox; // 0x007BF0A4








#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2TextNodeStrc;

struct D2RectStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

#pragma pack(push, 2)

struct D2TextNodeStrc
{
    Unicode* pLines[6];
    unsigned short nLines;
    int nColor;
    unsigned int dwEndTick;
    D2TextNodeStrc* pNext;
};

#pragma pack(pop)

class D2SquelchListStrc
{
public:
    virtual void Squelch(const char* szName);
    virtual void Unsquelch(const char* szName);
    virtual int IsNameSquelched(const char* szName);
    virtual void Unknown0C();
    virtual void Unknown10();
    virtual int IsTextSquelched(const char* szText);
    virtual void AddName(const char* szName, int nSize);
};

char* __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength); // 0x005263E0

Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount); // 0x00526790

int __fastcall sub_00526D30_IsLineBreak(const Unicode* pText, unsigned int nIndex); // 0x00526D30

int __fastcall D2Win_10123(const Unicode* wszText, int nLength); // 0x00501730

D2TextNodeStrc* __fastcall TEXT_CloneStringList(D2TextNodeStrc* pSource); // 0x0049DB10

extern D2TextListStrc gtOverheadTextList; // 0x007BF1EA

extern D2TextListStrc gtTextHistory; // 0x007BF1F0


extern "C" __declspec(dllimport) int __stdcall IntersectRect(D2RectStrc* pDest, const D2RectStrc* pSrc1, const D2RectStrc* pSrc2); // 0x006CC4C4

extern "C" int __cdecl atoi(const char* szString); // 0x00681EBB

int __cdecl sub_0045AE90(); // 0x0045AE90

void __fastcall TEXT_DrawTextList(D2TextBoxStrc* pTextBox, int nX, int nY); // 0x0049D8E0

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

void __stdcall UNITS_GetClientCoords(D2UnitStrc* pUnit, D2CoordStrc* pClientCoords); // 0x00620900

unsigned int __stdcall CHAT_GetTimeoutFromHoverMsg(D2HoverTextStrc* pHoverMsg); // 0x006611D0

unsigned char __stdcall CHAT_GetLangIdFromHoverMsg(D2HoverTextStrc* pHoverMsg); // 0x00661220

extern "C" const char gszTextSourceFile[]; // 0x006DA13C

extern int gaHoverDirs[]; // 0x00722654

extern int gnHoverDirCount; // 0x00722674

extern D2RectStrc gaHoverRects[16]; // 0x007BF0A8



bool __stdcall TEXT_PlaceHoverRect(int nCount, D2RectStrc* pRect); // 0x0049E070

void __fastcall TEXT_AddToHistory(D2TextNodeStrc* pSource); // 0x0049DBC0

struct D2CelFileStrc;



extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0

int __stdcall TEXTURE_CelDraw(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

extern D2ScrollPosStrc gaScrollPiecePos[5]; // 0x00722EB8

extern D2ScrollPosStrc gaScrollFadePos[5]; // 0x00722EE0

extern unsigned int gaScrollThresholds[5]; // 0x00722F08

extern "C" { unsigned short gawScrollSlots[6]; } // 0x007BF098

extern unsigned int gdwScrollTick; // 0x007BF243

extern unsigned int gnScrollCounter; // 0x007BF247

extern D2CelFileStrc* gpScroin3_007BF26C; // 0x007BF26C

extern D2CelFileStrc* gpScroin2_007BF270; // 0x007BF270

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szDest, const char* szFormat, ...); // 0x006CC468


int __cdecl sub_00525150();

#define UNIT_PLAYER 0

#define STAT_LEVEL 12

struct D2SliderButtonStrc;

struct D2Record42Strc;

struct D2QuestTextLineStrc;

struct D2QuestPanelEntryStrc;

struct D2QuestSlotRectStrc;

struct D2AiControlStrc;

struct D2AiTickParamStrc;

struct D2HotkeyActionStrc;

struct D2CharStatsTxt;

struct D2MonStatsTxt;

int __cdecl CUNIT_IsPlayerDeadOrMissing(); // 0x00463DF0

unsigned char __cdecl INV_IsCinematicBusy(); // 0x00483350

void __cdecl QUESTLOG_UpdateQuestPage(); // 0x004A2300

void __cdecl QUESTLOG_LoadQuestPanelCels(); // 0x004A23D0

int __stdcall QUESTLOG_OpenQuestPanel(int nArg); // 0x004A26B0

int __cdecl TEXT_Forward(); // 0x004A1760

void __stdcall sub_004A3220(int nPage, int nArg);

void __fastcall MSG_SendHeaderOnly(char nValue); // 0x00478590

#pragma pack(push, 2)

struct D2SliderButtonStrc
{
    unsigned short nStringId;
    void (__cdecl* pfnClick)();
    int unk0x06;
    int nLeft;
    int nRight;
    int nTop;
    int nBottom;
};

struct D2Record42Strc
{
    int aData[10];
    unsigned short wLast;
};

#pragma pack(pop)

extern unsigned char gbFlag_007BF2B0; // 0x007BF2B0

extern D2Record42Strc gtQuestRecord; // 0x007BF355

extern int gnPage_007C0255; // 0x007C0255

extern D2SliderButtonStrc gaKeyConfigButtons[3]; // 0x007246D8

extern int gaPressed[7]; // 0x007C0288

struct D2QuestTextLineStrc
{
    unsigned short wLead[9];
    Unicode wszText[300];
};


int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

void __fastcall QUESTLOG_ToggleQuestLog(int nMode); // 0x004A3FE0

void __cdecl GAME_ResetMouseButtons(); // 0x0044DA70

void __fastcall WARDENCLIENT_OpenTextPanel(unsigned short nStringId, int bSide, int bSound); // 0x004A1320

void __fastcall TEXT_SetTextCallback(D2TextCallback pfnCallback, void* pContext); // 0x0049E7E0

int __fastcall QUESTLOG_CloseQuestText(void* pContext, int nArg, int nValue); // 0x004A27B0

extern D2QuestSlotRectStrc gaQuestSlots[]; // 0x00723EB0

extern int gnQuestCount; // 0x007BF2A0

extern char gbGlobal_007BF2B0; // 0x007BF2B0

extern char gbQuestDescriptionOpen; // 0x007BF2B3

extern D2QuestPanelEntryStrc gaQuestEntries[]; // 0x007BF3AA

extern char gbGlobal_007C025D; // 0x007C025D

extern char gbGlobal_007C025E; // 0x007C025E

extern char gbGlobal_007C025F; // 0x007C025F

extern char gbGlobal_007C0260; // 0x007C0260

static int gnKeyConfigEntryCount; // 0x007C0274

int __cdecl TEXT_GetMaxFirstEntry(); // 0x004A44C0

extern int gnKeyConfigThumbScale; // 0x007C0278

static int gnKeyConfigFirstVisible; // 0x007C02AC

extern int gnAutomapHeight; // 0x007A521C

// build: symbol ??__EgnKeyConfigThumbY@@YAXXZ 0x006CACE0
int gnKeyConfigThumbY = (gnAutomapHeight - 420) / 2 + 47; // 0x007C02CC

#pragma pack(push, 2)

struct D2ClientListEntryStrc
{
    int nId;
    unsigned short nString;
    unsigned char unk0x06[4];
};

#pragma pack(pop)

int __cdecl GAME_IsExitPending(); // 0x0044DA30

extern "C" void __cdecl GAME_UnregisterMouseHandlers(); // 0x0044DCE0

extern "C" void __cdecl GAME_RegisterMouseHandlers(); // 0x0044DD20

void __cdecl SELECT_ClearSelection(); // 0x00466FE0

void __fastcall SELECT_RefreshHoverUnit(D2UnitStrc* pUnit); // 0x00467A70

void __cdecl CMDTBL_SaveHotkeys(); // 0x00469D20

void __cdecl TEXT_InitKeyConfigEntries(); // 0x004A43E0

extern int gbRedraw; // 0x007C0280

int gnKeyConfigSelected; // 0x007C02B0

int gbKeyCaptureActive; // 0x007C02B8

int gbKeyConfigPressRepeat; // 0x007C0284

int __fastcall CUNIT_HasHotkeyBinding(int nA, int nB); // 0x00469D90

int __stdcall sub_B05_Sink(int nA, int nB);

int __fastcall EXCEPTIONS_ReleaseSymbols(int nArg); // 0x0040C720

void __fastcall CMDTBL_ResetKeyConfig(int nArg); // 0x00469A60

extern "C" void __cdecl sub_00517ABB(void* pMemory); // 0x00517ABB

struct D2HotkeyActionStrc
{
    char unk0x00[0x0A];
    short nValue0A;
    char unk0x0C[0x0C];
    int nState18;
    int nState1C;
};

extern "C" int __stdcall sub_00420290_HandleMsg(void* pMessage); // 0x00420290

extern D2MsgHandlerEntryStrc gaKeyCaptureMButtonHandlers[]; // 0x0072472C

extern D2MsgHandlerEntryStrc gaKeyCaptureHandlers[]; // 0x00724738

extern D2MsgHandlerEntryStrc gaKeyCaptureXButtonHandlers[]; // 0x00724780

extern D2MsgHandlerEntryStrc gaKeyCaptureWheelHandlers[]; // 0x0072478C

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

unsigned char __cdecl GAME_GetDifficulty(); // 0x0044DCD0

int __cdecl SELECT_GetHoverMonClassId(); // 0x00466DC0

int __cdecl GAME_GetLadderFlag(); // 0x0044DCA0

static int TEXT_GetKeyConfigButtonAt(int nX, int nY);



int __stdcall TEXT_IsAbovePanelLine(int nX); // 0x004A4780

int gnThumbRange; // 0x007C027C

int gnDragThumbY; // 0x007C02A4

int gnDragMouseY; // 0x007C02A8

unsigned long gdwKeyConfigRepeatTick; // 0x007C02C0

int __fastcall TEXT_IsInPanelButton(int, int, int); // 0x004A6580

int __cdecl TEXT_IsMouseOnStatButton(); // 0x004A65E0

void __stdcall CURSOR_HandleButtonDown(SMSGHANDLER_PARAMS*); // 0x00467F20

int __cdecl NPCMENU_IsNpcTalkActive(); // 0x004B3470

int __fastcall TEXT_IsInRightPanelButton(int, int, int); // 0x004A6630

int __cdecl TEXT_IsMouseOnSkillButton(); // 0x004A6690

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80

D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit(); // 0x00463DE0

int __cdecl SELECT_GetHoverClassId(); // 0x00466DD0

void __fastcall D2Win_10132(const Unicode* wszText, int nX, int nY, unsigned int dwColor, int eDrawMode, int nColor); // 0x005023B0

int __stdcall UNITS_GetBlockRate(D2UnitStrc* pUnit, int nArg); // 0x00622720

int __stdcall ITEMSIsA(D2UnitStrc* pItem, int nItemType); // 0x00629BB0

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc* pInventory, int nBodyLoc); // 0x0063BDE0

int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int bUseConvertedMode); // 0x0064F380

void __fastcall TEXT_ScrollKeyConfigList(int nStep);

#define STAT_STATPTS 4

#define STAT_NEWSKILLS 5


void __cdecl CMDTBL_SaveAndBindHotkeys(); // 0x00469D40

void __fastcall sub_0047E200_CloseMenus(int bRestore); // 0x0047E200

void __fastcall WARDENCLIENT_ToggleEscMenuUIState(int bSaveState, int nMenu); // 0x0047E090

extern int global_00724728; // 0x00724728

enum { REPEAT_MASK = 0x40000000, UI_VARIABLE = 11 };

void* __fastcall GAME_LoadUiCelFile(const char* szPath); // 0x004520C0

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0

extern "C" int gnFlag_007C02EC; // 0x007C02EC

void __stdcall CURSOR_HandleButtonUp(SMSGHANDLER_PARAMS* pMsg); // 0x00467FA0

bool __stdcall TEXT_IsStatButtonHidden(int nArg); // 0x004A6A00

bool __stdcall TEXT_IsSkillButtonHidden(int nArg); // 0x004A6D50

void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280

D2CelStrc* __stdcall CelGetHandle(D2CelContextStrc* pContext); // 0x00601840

int __stdcall CelGetWidth(D2CelStrc* pCel); // 0x006018C0




extern int gbSkillButtonPressed; // 0x007C02E8

void __fastcall TEXT_MoveKeyConfigSelection(int nStep);

extern char gbGlobal_007BF2B2; // 0x007BF2B2

extern char gbGlobal_007BF2B4; // 0x007BF2B4

void* gpKeyConfigSliderCel; // 0x007C02BC

static int TEXT_GetKeyConfigLineAt(int nY);

static int TEXT_IsInKeyConfigList(int nX, int nY);

static int TEXT_IsOnUpArrow(int nX, int nY);

static int TEXT_IsOnDownArrow(int nX, int nY);

static int TEXT_IsAboveThumb(int nX, int nY);

static int TEXT_IsOnThumb(int nX, int nY);

static int TEXT_IsBelowThumb(int nX, int nY);


#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

static int TEXT_IsOnKeyConfigButton(int nX, int nY);

static int TEXT_IsOnPressedButton(int nX, int nY);

void __fastcall TEXT_DrawUnitHoverText(D2UnitStrc* pUnit); // 0x004A0B30

int __cdecl sub_0047F210_IsMouseInSlots();                                                                  // 0x0047F210

void __cdecl sub_0049C6C0_SendWaypointClose();                                                              // 0x0049C6C0

extern D2WaypointRowRectStrc gaWaypointRowRects[9];                                                // 0x007224F8

extern D2WaypointMenuEntryStrc gaWaypointEntries[9];                                               // 0x007BF03C




extern int gnPanelOffsetX;                                                                               // 0x007A2858

extern int gnPanelOffsetY;                                                                               // 0x007A285C

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00

typedef void (__fastcall* UNITFN)(D2UnitStrc* pUnit);

extern int gnQuestAct; // 0x007BF2A4


extern "C" void __cdecl GAME_ConfigureEnvironmentOrDefer(); // 0x0044C820

void __cdecl GAME_RequestExit(); // 0x0044D520

void __fastcall GAME_SetPlayCinematic(int nValue); // 0x0044D530

int __cdecl GAME_IsExpansion(); // 0x0044DCC0

void __cdecl GAME_SetDifficultyFlags(); // 0x0044EC80

int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0

void __fastcall CUNIT_ForEachMonster(UNITFN pfnCallback); // 0x00464990

void __fastcall sub_0046BFD0_StartTimer(int nDelay); // 0x0046BFD0

void __fastcall GFX_LoadMonsterCofs(int nMonsterId, int bLoadNow); // 0x0046F870

void __cdecl INV_StopCinematic(); // 0x00483300

void __cdecl INV_ChainCinematic(); // 0x00483340

void __fastcall QUESTLOG_SelectQuestPage(int nCondition); // 0x004A2C30

void __fastcall QUESTLOG_ClearCainFlag(D2UnitStrc* pUnit); // 0x004A2C70

void __fastcall QUESTLOG_ClearNihlathakFlag(D2UnitStrc* pUnit); // 0x004A2C90

D2BitBufferStrc* __cdecl MONSTER_GetQuestFlags(); // 0x004B32D0

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

static int TEXT_FindQuestIndex(int nKey);


void __fastcall sub_00600C60_CallFree(void* pMemory); // 0x00600C60

struct D2StringSoundStrc;

void __fastcall CUNIT_SetDialogState(int nState); // 0x004898D0

void __cdecl DIALOG_LoadDialogHotkeys(); // 0x004B7C60

void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode); // 0x004F6300

int __stdcall CelGetHeight(D2CelStrc* pCel); // 0x006018F0

D2BitBufferStrc* __stdcall QUESTRECORD_AllocRecord(void* pMemPool); // 0x0065C430

extern D2MsgHandlerEntryStrc gaDialogWheelHandlers[]; // 0x007273E4

extern D2MsgHandlerEntryStrc gaDialogHandlers[]; // 0x007273F0

extern const char* gaszDialogCels[]; // 0x007274AC

extern void* gpWaypointBackgroundCel; // 0x007BF071

extern void* gpWaypointActTabsCel; // 0x007BF075

extern void* gpWaypointIconCel; // 0x007BF079

extern void* gpGlobal_007C0D43; // 0x007C0D43

extern int gbWaitSoundPlayed; // 0x007C0DBC

extern int gbWaitSoundScheduled; // 0x007C0DC0

extern void* gpBuySellCel; // 0x007C0DC8

extern void* gpGoldBtnCel; // 0x007C0DCC



struct D2StringSoundStrc
{
    unsigned short wStringId;
    unsigned short wSoundId;
};

extern "C" const char gszFormatD[]; // 0x006D57BC

extern "C" const char gszFormatSound[]; // 0x006DA194

extern D2StringSoundStrc* gapClassStringSounds[]; // 0x00722F1C

extern D2StringSoundStrc gaMonStringSounds[]; // 0x00723750

static void __stdcall TEXT_ShowHoverText(const Unicode* wszText, D2UnitStrc* pUnit, D2HoverTextStrc* pHoverText, D2CoordStrc* pPos); // 0x004A0A00






D2WaypointDataStrc* __stdcall WAYPOINTS_AllocWaypointData(void* pMemPool); // 0x00660F30

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

void __stdcall WAYPOINTS_FreeWaypointData(void* pMemPool, D2WaypointDataStrc* pData); // 0x00660FD0

extern "C" void __cdecl TEXT_FreeWaypointCels(); // 0x0049C650

static int TEXT_DrawTextBoxAt(D2TextBoxStrc* pTextBox, D2RectStrc* pRect); // 0x0049D9A0

static void TEXT_FreeTextLines(D2SplittedTextStrc* pLine);

void __stdcall TEXT_FreeTextBox(D2TextBoxStrc* pTextBox); // 0x0049D410

static void TEXT_MeasureTextBox(D2TextBoxStrc* pBox);

struct D2ActiveRoomStrc;

struct D2StoredUnitRecordStrc;

struct D2GSPacketSrv5A;

struct D2SuperUniquesTxt;

void __fastcall sub_004E6410_BuildPropText(D2UnitStrc* pItem, Unicode* wszText, int nArg, int bFlag, int nArg2); // 0x004E6410

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

Unicode* __fastcall sub_00526700(Unicode* pDst, const Unicode* pSrc); // 0x00526700

void __stdcall D2Common_10474(D2UnitStrc* pUnused, D2StatListStrc* pStatList); // 0x006277E0

void __stdcall ITEMMODS_AssignProperty(int nPass, int nArg1, D2UnitStrc* pItem, int nArg, int nArg2, int nArg5); // 0x0065FEC0

extern Unicode gwszName_007C0E84[]; // 0x007C0E84

#pragma pack(push, 1)

struct D2GSPacketSrv5A
{
    unsigned char nHeader;
    unsigned char nType;
    unsigned char nColor;
    int dwParam;
    unsigned char nParam;
    union
    {
        char szText[32];
        char szTextData[2][16];
    };
};

#pragma pack(pop)

extern "C" char* __cdecl strcpy(char* szDst, const char* szSrc);

extern "C" int __cdecl strcmp(const char* sz1, const char* sz2);

extern "C" const char* __fastcall ROSTER_GetEntryName(D2StoredUnitRecordStrc* pEntry); // 0x004795C0

int __fastcall ROSTER_GetRecordUnitId(D2StoredUnitRecordStrc* pRecord); // 0x0047A0C0

D2ActiveRoomStrc* __cdecl CUNIT_GetPlayerRoom(); // 0x004646A0

unsigned int __fastcall GFXUTIL_TestRelationFlags(int nUnitId1, int nUnitId2, unsigned int nFlags); // 0x004DC440

void __fastcall TEXT_PrintPartyText(const Unicode* wszText, char nColor); // 0x0049E5C0

D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId); // 0x00640E90

D2SuperUniquesTxt* __stdcall DATATBLS_GetSuperUniquesTxtRecord(int nSuperUniqueId); // 0x006556E0

extern D2DrlgActStrc* gpGlobal_007A0634; // 0x007A0634

static int TEXT_FormatPartyEvent(Unicode* pOut, D2GSPacketSrv5A* pPacket); // 0x0049E8F0

void __fastcall sub_0049E3A0_ShowChatText(const Unicode* wszText, char nColor);


extern "C" __declspec(dllimport) int __stdcall SetRect(D2RectStrc* pRect, int nLeft, int nTop, int nRight, int nBottom);

void __cdecl UI_StartUIVarDelay(); // 0x00453AE0

void __fastcall CUNIT_ForEachPlayer(UNITFN pfnCallback); // 0x00464950

void __fastcall CUNIT_ForEachObject(UNITFN pfnCallback); // 0x004649D0

void __fastcall sub_00476070_GetViewRect(D2ViewStrc* pView, int* pLeft, int* pTop, int* pRight, int* pBottom); // 0x00476070

void __fastcall VIEW_GetViewOffset(D2ViewStrc* pView, int* pX, int* pY); // 0x004760C0

void __cdecl TEXT_DrawMessageList(); // 0x0049DC40

void __cdecl TEXT_DrawOverheadTextList(); // 0x0049DEE0

void __cdecl TEXT_FreeMainTextBox(); // 0x0049E300

void __cdecl TEXT_ResetTextBox(); // 0x0049F960

void __cdecl TEXT_CloseTextUnit(); // 0x004A0880

void __fastcall TEXT_DrawObjectHoverText(D2UnitStrc* pUnit); // 0x004A0D20

extern "C" void __fastcall NPCMENU_ClearNpcInventoryAndSound(int nUnitId); // 0x004B3830

void __fastcall DIALOG_DrawDialog(D2ClientDialogStrc* pDialog); // 0x004B8100

int __cdecl D2SOUND_GetMasterVolumeOption(); // 0x00514CC0

extern D2RectStrc gtTextRect_007BF1D0; // 0x007BF1D0

extern D2TextCallback gpfnTextCallback; // 0x007BF258

extern void* gpTextCallbackContext; // 0x007BF25C

extern int gnTextLeft; // 0x007BF278

static int __stdcall TEXT_AdvanceTextBox(int bIgnore, D2TextBoxStrc* pTextBox); // 0x004A0770


inline void* operator new(unsigned int, void* pWhere) { return pWhere; }

// build: symbol ??0D2QuestTextBufferStrc@@QAE@XZ 0x004A4260


extern int gbTextBoxDone; // 0x007BF1BC


#define gbUpPressed_007C028C (gaPressed[1])

#define gbDownPressed_007C0290 (gaPressed[2])

#define KEYCFG_X ((gnScreenWidth_0071146C - 620) / 2)

#define KEYCFG_Y ((gnAutomapHeight - 420) / 2)






void __fastcall UI_DrawRectangleBorder(D2RectStrc* pRect); // 0x00452E50

const Unicode* __fastcall CMDTBL_GetKeyText(int nKey, int nArg2); // 0x00469DE0

extern D2KeyConfigButtonStrc gaButtons_007246D8[3]; // 0x007246D8

extern unsigned int gdwMessageTick_007C02C8; // 0x007C02C8

int gnKeyConfigPressedButton; // 0x007C02B4

int gnMessage; // 0x007C02C4

unsigned int gnBlink; // 0x007C02D0

int gnLastMouseY; // 0x007C02D4

int gnLastMouseX; // 0x007C02D8

void __fastcall TEXT_HandleChatPacket(D2GSPacketSrv26* pPacket);

static int TEXT_GetKeyConfigEntryState(int nIndex, int nFlag);

typedef int(__fastcall* PANELCLOSEFN)(void* pArg, int a2, int a3);

extern int gnPending_007BF1C4; // 0x007BF1C4

extern void* gpHint_007BF202; // 0x007BF202

extern int gbHintActive_007BF20A; // 0x007BF20A

extern void* gpHint_007BF24B; // 0x007BF24B

extern PANELCLOSEFN gpfnClose_007BF258; // 0x007BF258

void __fastcall SELECT_SetSelectionRect(void* pRect); // 0x00467430

void __fastcall NPCMENU_CancelNpcAndFlag(void* pHint); // 0x004B3D10

struct D2MessageListStrc;

struct D2QuestTextMsgStrc;

struct D2QuestTextsStrc;

struct D2QuestPageRangeStrc;

struct D2QuestPosStrc;

struct D2QuestLogStateStrc;

void __fastcall TEXT_ShowTextBox(unsigned short nStringId); // 0x004A1510

D2TextHeaderStrc* __stdcall TEXT_AllocTextHeader(void* pMemPool); // 0x00661240

void __stdcall TEXT_CreateTextHeaderFromMessageList(D2TextHeaderStrc* pTextHeader, D2MessageListStrc* pMessageList); // 0x00661510

void __stdcall TEXT_SortTextNodeListByStringId(D2TextHeaderStrc* pTextHeader); // 0x006616E0


int __stdcall INV_GetTableByte(int nUnused, int nIndex); // 0x004B92E0

extern D2QuestTextsStrc gtQuestTextsSevenTombs; // 0x00723A64

extern D2QuestTextsStrc gtQuestTextsFallenAngel; // 0x00723C64

extern D2QuestTextsStrc gtQuestTextsSiege; // 0x00723D24

extern D2QuestPageRangeStrc gaQuestPageRanges[]; // 0x00723F08

extern void* gapQuestIconCels[]; // 0x007BF2E1

extern unsigned char gabQuestFlagsA[]; // 0x007BF356

void __stdcall TEXT_LoadQuestPage(int nPage, int bReset); // 0x004A3220

static void TEXT_BuildQuestText(D2QuestTextMsgStrc* pMsg); // 0x004A1950

void __fastcall MSG_SendWord(unsigned char nCmd, unsigned short nArg); // 0x004785B0

void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360

extern D2QuestPosStrc gaQuestPos[]; // 0x00723EA8


extern D2QuestLogStateStrc gtQuestLog_007BF298; // 0x007BF298


int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0







extern D2ClientListEntryStrc gaKeyConfigEntries[]; // 0x00724268

extern D2ClientListEntryStrc gaKeyConfigEntriesExp[]; // 0x00724468

static int TEXT_GetWeaponBlock(D2UnitStrc* pUnit); // 0x004A70C0

static int TEXT_AddToHitFactor(D2UnitStrc* pUnit, int nAttackRate); // 0x004A7300

static void TEXT_SetQuestPage(int nPageArg); // 0x004A2220

int __fastcall TEXT_TestQuestCondition(int nCondition);

void __stdcall TEXT_QuestLButtonDownMsg(SMSGHANDLER_PARAMS* pMsg);

void __cdecl QUESTLOG_DrawQuestPage(); // 0x004A34F0

void __stdcall TEXT_QuestLButtonUpMsg(SMSGHANDLER_PARAMS* pMsg);

int __stdcall TEXT_GetChanceToHit(int nAttackRate);

struct D2QuestTableStrc;

struct D2UiEntry10Strc;




extern D2QuestTableStrc gaQuestTable[]; // 0x00723F30

extern D2UiEntry10Strc gaQuestLookup[41]; // 0x00723F38

extern D2QuestUiFlagsStrc gtQuestUiFlags_007BF2B3; // 0x007BF2B3


Unicode* __fastcall strncpy(Unicode* pDest, const Unicode* pSource, int nCount); // 0x00526790


static void TEXT_FreeTextNode(D2TextNodeStrc* pNode); // 0x0049D490


static inline int sub_F08_ListTop()
{
    return (gnAutomapHeight - 0x1A4) / 2;
}

static inline int sub_KEYCFG_Rows()
{
    return ((sub_F08_ListTop() + 0x16C) - (sub_F08_ListTop() + 0x28)) / 0x12;
}

static inline int sub_KEYCFG_TrackCels()
{
    return ((KEYCFG_Y + 0x131) - (KEYCFG_Y + 0x2F)) / 0x0C;
}

static inline int sub_KEYCFG_RowTrackCels()
{
    return (sub_KEYCFG_Rows() * 0x12 - 0x4E) / 0x0C + 1;
}

static inline int sub_KEYCFG_VisibleLines()
{
    return ((KEYCFG_Y + 0x136) - (KEYCFG_Y + 0x28)) / 0x12;
}

static inline int sub_F08_VisibleLines()
{
    return sub_KEYCFG_Rows() - 3;
}

static inline int sub_F08_LinesTop()
{
    return sub_F08_ListTop() + 0x28;
}

static inline int sub_F08_LinesBottom()
{
    return sub_F08_ListTop() + 0x136;
}

static inline int sub_I18_ListTop()
{
    return (gnAutomapHeight - 0x1A4) / 2;
}

static inline int sub_I18_TrackTop()
{
    return sub_I18_ListTop() + 0x2F;
}

static inline int sub_I18_TrackBottom()
{
    return sub_I18_ListTop() + 0x125;
}

static inline int sub_I18_ThumbHeight()
{
    return gnKeyConfigThumbScale * 12;
}

static inline int sub_I18_TrackSpan()
{
    return sub_I18_TrackBottom() - sub_I18_TrackTop() - sub_I18_ThumbHeight();
}

static inline int sub_F08_PanelLeft()
{
    return (gnScreenWidth - 0x26C) / 2;
}

static inline int sub_F08_PanelRight()
{
    return sub_F08_PanelLeft() + (gnScreenWidth - sub_F08_PanelLeft() * 2);
}

static inline int sub_F08_TrackTop()
{
    return sub_F08_ListTop() + 0x2F;
}

static inline int sub_F08_TrackBottom()
{
    return sub_F08_ListTop() + 0x125;
}

static inline int sub_F08_ThumbHeight()
{
    return gnKeyConfigThumbScale * 12;
}

static __forceinline int sub_F08_TrackSpan()
{
    return sub_KEYCFG_Rows() * 0x12 - sub_F08_ThumbHeight() - 0x4E;
}

static inline int sub_F08_NoOtherPressed(int nIndex)
{
    for (int i = 0; i < 7; ++i)
    {
        if (gaPressed[i] && i != nIndex)
            return 0;
    }
    return 1;
}

static inline int sub_KEYCFG_ListTop()
{
    return (gnAutomapHeight - 0x1A4) / 2;
}

static inline int sub_KEYCFG_PanelRight()
{
    return KEYCFG_X + (gnScreenWidth_0071146C - KEYCFG_X * 2);
}

static inline int sub_KEYCFG_IsOnUpArrow(int nX, int nY)
{
    if (nX >= sub_KEYCFG_PanelRight() - 0x1F && nX <= sub_KEYCFG_PanelRight() - 0x12)
    {
        const int nTop = sub_KEYCFG_ListTop();
        if (nY >= nTop + 0x23 && nY <= nTop + 0x2F)
            return 1;
    }
    return 0;
}

static inline int sub_KEYCFG_IsOnDownArrow(int nX, int nY)
{
    if (nX >= sub_KEYCFG_PanelRight() - 0x1F && nX <= sub_KEYCFG_PanelRight() - 0x12)
    {
        const int nTop = sub_KEYCFG_ListTop();
        if (nY >= nTop + 0x125 && nY <= nTop + 0x131)
            return 1;
    }
    return 0;
}










static int sub_0049C510_GetWaypointRowAtPoint(int nX, int nY)
{
    for (int i = 0; i < 9; ++i)
    {
        if (gaWaypointEntries[i].bEnabled && nX > gaWaypointRowRects[i].nX && nX < gaWaypointRowRects[i].nX + 0x118
            && nY > gaWaypointRowRects[i].nY && nY < gaWaypointRowRects[i].nY + 0x1E)
            return i;
    }
    return -1;
}





struct D2BitBufferStrc;

void __stdcall sub_L04_EmitUse(const Unicode* pText);






















static __forceinline int sub_J06_IntersectsAnyHoverRect(const D2RectStrc* pRect, int nCount)
{
    for (int i = 0; i < nCount; ++i)
    {
        D2RectStrc tOverlap;
        if (IntersectRect(&tOverlap, &gaHoverRects[i], pRect))
            return 1;
    }
    return 0;
}




static inline int sub_F02_IntersectsAnyHoverRect(const D2RectStrc* pRect, int nCount)
{
    for (int i = 0; i < nCount; ++i)
    {
        D2RectStrc tOverlap;
        if (IntersectRect(&tOverlap, &gaHoverRects[i], pRect))
            return 1;
    }
    return 0;
}

























static __forceinline const unsigned short* TEXT_ReadLine(Unicode* pLine, const unsigned short* pText)
{
    int i = 0;
    memset(pLine, 0, 100 * sizeof(Unicode));
    for (; i < 100 && *pText != '\n'; ++i)
    {
        pLine[i] = *pText++;
    }
    if (i < 100 && *pText == '\n')
    {
        ++pText;
    }
    return pText;
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


static inline int sub_004A1950_GetActNumber(const D2QuestTextsStrc* pTexts)
{
    if (pTexts->awIds[0] == 0xE82)
    {
        return gnQuestAct;
    }
    return 0;
}



struct D2SetsTxt;





extern "C" { unsigned int gValue_007BF2A8; } // 0x007BF2A8






static void sub_004A2390_ResetQuestSelection()
{
// build: symbol ?gbQuestSlotDown@* 0x007BF2B1
    gbQuestSlotDown = 0;
    gbGlobal_007BF2B2 = 0;
    gbGlobal_007BF2B0 = 0;
    gnQuestPressedSlot = -1;
    gbGlobal_007BF2B4 = 0;
    gbGlobal_007C025D = 0;
    gbGlobal_007C025E = 0;
    gbGlobal_007C025F = 0;
    gbGlobal_007C0260 = 0;
}

// build: symbol ?TEXT_GetQuestTabAtPoint@* 0x004A26F0
static int __stdcall TEXT_GetQuestTabAtPoint(int nY, int nX)
{
    if (nY < 0 || nY > 0x1B || nX < 0 || nX > 0x13F)
    {
        return -1;
    }
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (FOG_IsExpansion() && GAME_IsExpansion())
    {
        int i = 0;
        for (int n = 0; n < 0x140; n += 0x40, ++i)
        {
            if (nX >= n && nX <= n + 0x40) return i;
        }
        return -1;
    }
    int i = 0;
    for (int n = 0; n < 0x140; n += 0x50, ++i)
    {
        if (nX >= n && nX <= n + 0x50) return i;
    }
    return -1;
}


static __forceinline void sub_004A3E40_ClickSlot_Inline(int nIndex)
{
    for (int i = 0; i < gnQuestCount; ++i)
    {
        if (nIndex == gaQuestEntries[i].nSlot && gaQuestEntries[i].bEnabled)
        {
            gbQuestSlotDown = 1;
            gnQuestPressedSlot = nIndex;
            sub_004B9A00(4, 0, 0, 0, 0);
        }
    }
}

// build: symbol ?TEXT_GetQuestSlotAtPoint@* 0x004A2630
static int TEXT_GetQuestSlotAtPoint(int nX, int nY)
{
    int nCount = gnQuestCount;
    D2_ASSERT((unsigned int)nCount <= 6, 0x738);
    for (int i = 0; i < nCount; ++i)
    {
        if (nX >= gaQuestSlots[i].nX && nX < gaQuestSlots[i].nX + 0x38 && nY >= gaQuestSlots[i].nY && nY < gaQuestSlots[i].nY + 0x34)
        {
            return i;
        }
    }
    return -1;
}

// build: symbol ?TEXT_HitTestQuestCloseButton@* 0x004A2690
static unsigned char TEXT_HitTestQuestCloseButton(int nX, int nY)
{
    if (nX >= 0x116 && nX <= 0x116 + 0x23 && nY >= 0x188 && nY <= 0x188 + 0x21)
    {
        return 1;
    }
    return 0;
}

// build: symbol ?TEXT_HitTestButtonA@* 0x004A2610
static unsigned char TEXT_HitTestButtonA(int nX, int nY)
{
    if (nX >= 0xE6 && nX <= 0xE6 + 0x1D && nY >= 0x187 && nY <= 0x187 + 0x20)
    {
        return 1;
    }
    return 0;
}






// build: symbol ?TEXT_OpenQuestDescription@* 0x004A27D0
static void TEXT_OpenQuestDescription(int nSlot)
{
    int nIndex = -1;
    for (int i = 0; i < gnQuestCount; ++i)
    {
        if (gaQuestEntries[i].nSlot == nSlot)
        {
            nIndex = i;
            break;
        }
    }
    if (nIndex == -1)
    {
        return;
    }
    unsigned short wTextId = gaQuestEntries[nIndex].wTextId;
    if (wTextId == 0xE8C || wTextId == 0xE8D)
    {
        return;
    }
    WARDENCLIENT_OpenTextPanel(wTextId, 1, 0);
    TEXT_SetTextCallback(QUESTLOG_CloseQuestText, 0);
    gbQuestDescriptionOpen = 1;
}


void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10

void __cdecl UI_RegisterKeyConfigHandlers(); // 0x00454980

void __fastcall CUNIT_ClearHotkeyBinding(int nId, int nB); // 0x00469D70

bool __stdcall sub_004A2970(int nX, int nY); // 0x004A2970

// 0x004A43E0
void __cdecl TEXT_InitKeyConfigEntries()
{
    if (GAME_IsExpansion())
    {
// build: symbol ?gpListEntries@* 0x00724264
        gpListEntries = gaKeyConfigEntriesExp;
        gnKeyConfigEntryCount = 62;
        gnKeyConfigThumbScale = sub_KEYCFG_RowTrackCels() * sub_F08_VisibleLines() / gnKeyConfigEntryCount;
        gnThumbRange = gnKeyConfigEntryCount - sub_F08_VisibleLines();
    }
    else
    {
        gpListEntries = gaKeyConfigEntries;
        gnKeyConfigEntryCount = 51;
        gnKeyConfigThumbScale = sub_KEYCFG_RowTrackCels() * sub_F08_VisibleLines() / gnKeyConfigEntryCount;
        gnThumbRange = gnKeyConfigEntryCount - sub_F08_VisibleLines();
    }
}

// 0x004A44C0
int __cdecl TEXT_GetMaxFirstEntry()
{
    int nCount = gnKeyConfigEntryCount;
    for (int i = 0; i < sub_F08_VisibleLines(); ++i)
    {
        if (--nCount <= 0)
            return 0;
    }
    return nCount;
}

// 0x004A4500
void __fastcall TEXT_ScrollKeyConfigList(int nStep)
{
    if (nStep < -1)
    {
        for (int i = nStep; i < 0; ++i)
            TEXT_ScrollKeyConfigList(-1);
        return;
    }
    if (nStep > 1)
    {
        for (int i = 0; i < nStep; ++i)
            TEXT_ScrollKeyConfigList(1);
        return;
    }

    const int nMax = TEXT_GetMaxFirstEntry();
    if (nStep < 0)
    {
        const int nPrev = gnKeyConfigFirstVisible <= 0 ? gnKeyConfigFirstVisible : gnKeyConfigFirstVisible - 1;
        if (nPrev >= 0)
            gnKeyConfigFirstVisible = nPrev;
    }
    else if (nStep > 0)
    {
        const int nNext = gnKeyConfigFirstVisible >= nMax ? gnKeyConfigFirstVisible : gnKeyConfigFirstVisible + 1;
        if (nNext <= nMax)
            gnKeyConfigFirstVisible = nNext;
    }
    gnKeyConfigThumbY = sub_I18_TrackSpan() * gnKeyConfigFirstVisible / nMax + sub_I18_TrackTop();
}

// 0x004A45C0
void __fastcall TEXT_MoveKeyConfigSelection(int nStep)
{
    if (!nStep)
        return;
    if (nStep < -1)
    {
        for (int i = nStep; i < 0; ++i)
            TEXT_MoveKeyConfigSelection(-1);
        return;
    }
    if (nStep > 1)
    {
        for (int i = 0; i < nStep; ++i)
            TEXT_MoveKeyConfigSelection(1);
        return;
    }

    const int nCount = gnKeyConfigEntryCount;
    if (nStep < 0)
    {
        const int nOld = gnKeyConfigSelected;
        const int nNew = nOld <= 0 ? nOld : nOld - 1;
        if (nNew >= 0)
            gnKeyConfigSelected = nNew;
    }
    else if (nStep > 0 && gnKeyConfigSelected < nCount)
    {
        const int nNew = gnKeyConfigSelected + 1;
        if (nNew < nCount)
            gnKeyConfigSelected = nNew;
    }

    const int nSelected = gnKeyConfigSelected;
    int nFirst = gnKeyConfigFirstVisible;
    if (nSelected < nFirst)
    {
        const int nTrackTop = sub_F08_TrackTop();
        gnKeyConfigFirstVisible = nSelected;
        gnKeyConfigThumbY = nSelected * sub_F08_TrackSpan() / TEXT_GetMaxFirstEntry() + nTrackTop;
        return;
    }

    for (;;)
    {
        int nLast = nFirst;
        for (int nLine = 0; nLast < nCount && nLine < 0x0F; ++nLine)
            ++nLast;
        if (gnKeyConfigSelected < nLast)
            break;

        const int nMax = TEXT_GetMaxFirstEntry();
        const int nNew = nFirst >= nMax ? nFirst : nFirst + 1;
        if (nNew <= nMax)
            nFirst = nNew;
        gnKeyConfigThumbY = sub_F08_TrackSpan() * nFirst / nMax + sub_F08_TrackTop();
    }
    gnKeyConfigFirstVisible = nFirst;
}

// 0x004A4720
static int TEXT_GetKeyConfigLineAt(int nY)
{
    int nIndex = gnKeyConfigFirstVisible;
    const int nCount = gnKeyConfigEntryCount;
    int nLine = 0;
    if (nIndex < nCount)
    {
        int nLineY = (gnAutomapHeight - 0x1A4) / 2 + 0x3A;
        do
        {
            if (nLine >= 0x0F)
                break;
            if (nY <= nLineY)
                return nIndex;
            ++nIndex;
            ++nLine;
            nLineY += 0x12;
        }
        while (nIndex < nCount);
        if (nIndex < nCount)
            return nIndex;
    }
    return nCount < 0 ? nCount : nCount - 1;
}

// 0x004A4780
int __stdcall TEXT_IsAbovePanelLine(int nY)
{
    int nHalf = (gnScreenWidth - 620) / 2;
    return nY < nHalf + (gnScreenWidth - nHalf * 2 - 49) / 3 * 2 + 18;
}



// build: symbol ??0UnicodeChar@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x004A47C0
static int TEXT_GetKeyConfigButtonAt(int nX, int nY)
{
    unsigned int i;
    for (i = 0; i < 3; ++i)
    {
        if (nX >= gaKeyConfigButtons[i].nLeft && nX <= gaKeyConfigButtons[i].nRight
            && nY >= gaKeyConfigButtons[i].nTop && nY <= gaKeyConfigButtons[i].nBottom)
            break;
    }
    return i;
}

static int __stdcall sub_E10_IsAbovePanelLineCopy(int nY)
{
    int nHalf = (gnScreenWidth - 620) / 2;
    return nY < nHalf + (gnScreenWidth - nHalf * 2 - 49) / 3 * 2 + 18;
}

// 0x004A47F0
static int TEXT_IsInKeyConfigList(int nX, int nY)
{
    const int nHalf = (gnScreenWidth - 0x26C) / 2;
    const int nLeft = nHalf + 0x12;
    const int nRight = nHalf + (gnScreenWidth - nHalf * 2 - 0x31) / 3 * 3 + 0x12;
    if (nX >= nLeft && nX <= nRight)
    {
        const int nTop = (gnAutomapHeight - 0x1A4) / 2;
        if (nY >= nTop + 0x28 && nY <= nTop + 0x136)
            return 1;
    }
    return 0;
}

// 0x004A4860
static int TEXT_IsOnUpArrow(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        const int nTop = sub_F08_ListTop();
        if (nY >= nTop + 0x23 && nY <= nTop + 0x2F)
            return 1;
    }
    return 0;
}

// 0x004A48B0
static int TEXT_IsOnDownArrow(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        const int nTop = sub_F08_ListTop();
        if (nY >= nTop + 0x125 && nY <= nTop + 0x131)
            return 1;
    }
    return 0;
}

// 0x004A4900
static int TEXT_IsAboveThumb(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        if (nY > sub_F08_ListTop() + 0x2F && nY < gnKeyConfigThumbY)
            return 1;
    }
    return 0;
}

// 0x004A4950
static int TEXT_IsOnThumb(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        if (nY >= gnKeyConfigThumbY && nY <= gnKeyConfigThumbY + sub_F08_ThumbHeight())
            return 1;
    }
    return 0;
}

// 0x004A49A0
static int TEXT_IsBelowThumb(int nX, int nY)
{
    if (nX >= sub_F08_PanelRight() - 0x1F && nX <= sub_F08_PanelRight() - 0x12)
    {
        if (nY < sub_F08_ListTop() + 0x125 && nY > gnKeyConfigThumbY + sub_F08_ThumbHeight())
            return 1;
    }
    return 0;
}

// 0x004A4A00
static inline int TEXT_IsOnKeyConfigButton(int nX, int nY)
{
    return TEXT_GetKeyConfigButtonAt(nX, nY) != 3;
}

int __stdcall sub_M119_Emit_004A4A00(int nX, int nY)
{
    if (TEXT_IsOnKeyConfigButton(nX, nY))
    {
        return TEXT_IsOnPressedButton(nX + 1, nY);
    }
    return 2;
}

// 0x004A4A10
static int TEXT_IsOnSelectedLine(int nX, int nY)
{
    if (TEXT_IsInKeyConfigList(nX, nY) && TEXT_GetKeyConfigLineAt(nY) == gnKeyConfigSelected
// build: symbol ?gnKeyConfigColumn@* 0x007246D4
        && sub_E10_IsAbovePanelLineCopy(nX) == gnKeyConfigColumn)
        return 1;
    return 0;
}

// 0x004A4A80
static inline int TEXT_IsOnPressedButton(int nX, int nY)
{
    const int nButton = gnKeyConfigPressedButton;
    if (nButton != 3 && TEXT_GetKeyConfigButtonAt(nX, nY) == nButton)
    {
        return 1;
    }
    return 0;
}

// 0x004A4AA0
int __fastcall TEXT_IsOnlyPressed(int nIndex)
{
    for (int i = 0; i < 7; i++)
    {
        if (gaPressed[i] && i != nIndex)
        {
            return 0;
        }
    }
    return 1;
}

void __stdcall sub_004A4AD0_Press(int nX, int nY)
{
    gnKeyConfigPressedButton = 3;
    if (gbKeyConfigPressRepeat)
        return;

    const int bInList = TEXT_IsInKeyConfigList(nX, nY);
    const int bUp = TEXT_IsOnUpArrow(nX, nY);
    const int bDown = TEXT_IsOnDownArrow(nX, nY);
    const int bPageUp = TEXT_IsAboveThumb(nX, nY);
    const int bThumb = TEXT_IsOnThumb(nX, nY);
    const int bPageDown = TEXT_IsBelowThumb(nX, nY);
    const int bButton = TEXT_GetKeyConfigButtonAt(nX, nY) != 3;

    if (sub_F08_NoOtherPressed(7) && !bInList && !bUp && !bDown && !bPageUp && !bThumb && !bPageDown && !bButton)
    {
        gbKeyConfigPressRepeat = gbRedraw;
        return;
    }

    if (sub_F08_NoOtherPressed(0) && (bInList || gaPressed[0]))
    {
        gaPressed[0] = gbRedraw;
        if (gbRedraw)
        {
            const int nTop = sub_F08_ListTop();
            if (nY < nTop + 0x28)
                TEXT_MoveKeyConfigSelection(-1);
            if (nY > nTop + 0x136)
                TEXT_MoveKeyConfigSelection(1);

            const int nOldD4 = gnKeyConfigColumn;
            const int nOldSelected = gnKeyConfigSelected;
            const int nLine = TEXT_GetKeyConfigLineAt(nY);
            gnKeyConfigSelected = nLine;
            gnKeyConfigColumn = TEXT_IsAbovePanelLine(nX);
            if (gpListEntries[nLine].nId == 0x39)
            {
                gnKeyConfigColumn = nOldD4;
                gnKeyConfigSelected = nOldSelected;
            }
        }
    }

    if (sub_F08_NoOtherPressed(1) && bUp)
    {
        gaPressed[1] = gbRedraw;
        if (gbRedraw && GetTickCount() > gdwKeyConfigRepeatTick + 0x32)
        {
            gdwKeyConfigRepeatTick = GetTickCount();
            TEXT_ScrollKeyConfigList(-1);
        }
    }

    if (sub_F08_NoOtherPressed(2) && bDown)
    {
        gaPressed[2] = gbRedraw;
        if (gbRedraw && GetTickCount() > gdwKeyConfigRepeatTick + 0x32)
        {
            gdwKeyConfigRepeatTick = GetTickCount();
            TEXT_ScrollKeyConfigList(1);
        }
    }

    if (sub_F08_NoOtherPressed(3) && bPageUp)
    {
        gaPressed[3] = gbRedraw;
        if (gbRedraw && GetTickCount() > gdwKeyConfigRepeatTick + 0x32)
        {
            gdwKeyConfigRepeatTick = GetTickCount();
            TEXT_ScrollKeyConfigList(1 - sub_F08_VisibleLines());
        }
    }

    if (sub_F08_NoOtherPressed(4) && (bThumb || gaPressed[4]))
    {
        if (bThumb && !gaPressed[4] && gbRedraw)
        {
            gnDragThumbY = gnKeyConfigThumbY;
            gnDragMouseY = nY;
        }
        gaPressed[4] = gbRedraw;
        if (gbRedraw)
        {
            const int nTop = sub_F08_ListTop();
            TEXT_ScrollKeyConfigList((gnDragThumbY - nTop - gnDragMouseY + nY - 0x2F)
                * (gnThumbRange + 1) / sub_F08_TrackSpan() - gnKeyConfigFirstVisible);
        }
    }

    if (sub_F08_NoOtherPressed(5) && bPageDown)
    {
        gaPressed[5] = gbRedraw;
        if (gbRedraw && GetTickCount() > gdwKeyConfigRepeatTick + 0x32)
        {
            gdwKeyConfigRepeatTick = GetTickCount();
            TEXT_ScrollKeyConfigList(sub_F08_VisibleLines() - 1);
        }
    }

    if (sub_F08_NoOtherPressed(6) && bButton)
    {
        gaPressed[6] = gbRedraw;
        gnKeyConfigPressedButton = TEXT_GetKeyConfigButtonAt(nX, nY);
    }
}

// 0x004A4FA0
static int TEXT_GetKeyConfigEntryState(int nIndex, int nFlag)
{
    if (nIndex == gnKeyConfigSelected && (gbKeyCaptureActive || nFlag == gnKeyConfigColumn))
    {
        return 3;
    }

// build: symbol ?gpListEntries@* 0x00724264
    if (!CUNIT_HasHotkeyBinding(gpListEntries[nIndex].nId, 1) && !CUNIT_HasHotkeyBinding(gpListEntries[nIndex].nId, 0))
    {
        return 1;
    }

    return CUNIT_HasHotkeyBinding(gpListEntries[nIndex].nId, nFlag) ? 4 : 5;
}



// 0x004A5010
void __cdecl TEXT_ResetKeyConfigDefaults()
{
    CMDTBL_ResetKeyConfig(0);
}

// 0x004A5020
void __cdecl TEXT_AcceptKeyConfig()
{
    CMDTBL_SaveAndBindHotkeys();
    UI_SetUIVar(11, 1, 0);
    sub_0047E200_CloseMenus(1);
}

// 0x004A5040
void __cdecl TEXT_CancelKeyConfig()
{
    sub_00469D50();
    UI_SetUIVar(11, 1, 0);
    WARDENCLIENT_ToggleEscMenuUIState(0, 1);
}

// 0x004A5060
void __cdecl TEXT_LayoutSlider()
{
    const int nOldFont = sub_00502EF0_SetFont(13);
    for (unsigned int i = 0; i < 3; ++i)
    {
        const int nWidth = D2Win_10121_GetTextWidth(D2LANG_GetStringFromTblIndex(gaKeyConfigButtons[i].nStringId));
        const int nThird = (sub_F08_PanelRight() - sub_F08_PanelLeft()) / (sizeof(gaKeyConfigButtons) / sizeof(gaKeyConfigButtons[0]));
        gaKeyConfigButtons[i].nLeft = nThird * i + sub_F08_PanelLeft() + nThird / 2 - nWidth / 2 - 10;
        gaKeyConfigButtons[i].nRight = nThird * i + sub_F08_PanelLeft() + nThird / 2 + nWidth / 2 + 10;
        gaKeyConfigButtons[i].nTop = sub_F08_ListTop() + 0x149;
        gaKeyConfigButtons[i].nBottom = sub_F08_ListTop() + 0x16F;
    }
    sub_00502EF0_SetFont(nOldFont);

    gnKeyConfigThumbY = sub_F08_TrackSpan() * gnKeyConfigFirstVisible / TEXT_GetMaxFirstEntry() + sub_F08_TrackTop();
}

// 0x004A5190
void __cdecl TEXT_InitTextSlider()
{
    char szPath[0x104];
    TEXT_InitKeyConfigEntries();
    sprintf(szPath, "%s\\UI\\Menu\\TextSlid", gszDataGlobal);
    gpKeyConfigSliderCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    sub_004A5060();
    gnKeyConfigFirstVisible = 0;
    gnKeyConfigSelected = 0;
}

// 0x004A51E0
void __cdecl TEXT_FreeTextSliderCel()
{
    if (gpKeyConfigSliderCel)
    {
        ARCHIVE_FreeClientCellFile(gpKeyConfigSliderCel);
        gpKeyConfigSliderCel = 0;
    }
}

// 0x004A5200
void __fastcall TEXT_ToggleKeyConfigPanel(int nArg)
{
    TEXT_InitKeyConfigEntries();
    if (nArg)
    {
        if (gbKeyCaptureActive == 0)
        {
            CMDTBL_SaveHotkeys();
            sub_0046AA20(0, 0);
            GAME_UnregisterMouseHandlers();
            SELECT_RefreshHoverUnit(0);
        }
        gnKeyConfigFirstVisible = 0;
        gnKeyConfigSelected = 0;
    }
    else if (gbKeyCaptureActive == 0)
    {
        sub_0046AA20(1, 0);
        GAME_RegisterMouseHandlers();
        SELECT_ClearSelection();
    }
    sub_004A5060();
}

// 0x004A5270
void __cdecl TEXT_DrawKeyConfigPanel()
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    TEXT_InitKeyConfigEntries();
    if (gnLastMouseX != nMouseX || gnLastMouseY != nMouseY || gbRedraw)
    {
        gnLastMouseX = nMouseX;
        gnLastMouseY = nMouseY;
        sub_004A4AD0_Press(nMouseX, nMouseY);
    }

    const int nOldFont = sub_00502EF0_SetFont(13);
    AUTOMAP_DrawFramedBox(KEYCFG_X, KEYCFG_Y, gnScreenWidth_0071146C - 2 * KEYCFG_X, (KEYCFG_Y + 0x171) - KEYCFG_Y, 0, 1);

    D2RectStrc tRect;
    tRect.nLeft = KEYCFG_X;
    tRect.nTop = KEYCFG_Y + 3;
    tRect.nRight = gnScreenWidth_0071146C - KEYCFG_X - 3;
    tRect.nBottom = KEYCFG_Y + 0x170;
    UI_DrawRectangleBorder(&tRect);
    tRect.nTop = KEYCFG_Y + 0x143;
    UI_DrawRectangleBorder(&tRect);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0xF51), KEYCFG_X + 0x12, KEYCFG_Y + 0x1E, 4, 0);
    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0xF52), KEYCFG_X + 0x12 + (gnScreenWidth_0071146C - 2 * KEYCFG_X - 0x31) / 3, KEYCFG_Y + 0x1E, 4, 0);
    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0xF53), KEYCFG_X + 0x12 + 2 * ((gnScreenWidth_0071146C - 2 * KEYCFG_X - 0x31) / 3), KEYCFG_Y + 0x1E, 4, 0);

    int i = 0;
    while (i < sub_KEYCFG_VisibleLines() && i < gnKeyConfigEntryCount)
    {
        int nY = i * 0x12 + KEYCFG_Y + 0x22;
        int nIndex = gnKeyConfigFirstVisible + i;
        int bVisible;
        if (gbKeyCaptureActive && nIndex == gnKeyConfigSelected && (gnBlink & 0xF) <= 4)
            bVisible = 0;
        else
            bVisible = 1;

        ++i;

        if (gpListEntries[nIndex].nId == 0x39)
            continue;

        if (nIndex == gnKeyConfigSelected)
        {
            AUTOMAP_DrawFramedBox(KEYCFG_X + 0x12, nY + 1, 3 * ((gnScreenWidth_0071146C - 2 * KEYCFG_X - 0x31) / 3), 0x12, 0, 1);
            D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(gpListEntries[nIndex].nString), KEYCFG_X + 0x1E, nY + 0x12, gbKeyCaptureActive ? 3 : 0, 0);
        }
        else
        {
            D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(gpListEntries[nIndex].nString), KEYCFG_X + 0x1E, nY + 0x12, 0, 0);
        }

        if (bVisible || !gnKeyConfigColumn)
        {
            D2Win_10117_DrawText(CMDTBL_GetKeyText(gpListEntries[nIndex].nId, 1), KEYCFG_X + 0x1E + (gnScreenWidth_0071146C - 2 * KEYCFG_X - 0x31) / 3, nY + 0x12, TEXT_GetKeyConfigEntryState(nIndex, 1), 0);
        }

        if (bVisible || gnKeyConfigColumn)
        {
            D2Win_10117_DrawText(CMDTBL_GetKeyText(gpListEntries[nIndex].nId, 0), KEYCFG_X + 0x1E + 2 * ((gnScreenWidth_0071146C - 2 * KEYCFG_X - 0x31) / 3), nY + 0x12, TEXT_GetKeyConfigEntryState(nIndex, 0), 0);
        }
    }

    D2CelContextStrc tCel;
    memset(&tCel, 0, sizeof(tCel));
    tCel.pCellFile = gpKeyConfigSliderCel;
    tCel.nFrame = 13;
    for (int j = 0; j < sub_KEYCFG_TrackCels(); ++j)
        TEXTURE_CelDraw(&tCel, sub_KEYCFG_PanelRight() - 0x1F, KEYCFG_Y + 0x3B + j * 0x0C, -1, 5, 0);

    tCel.nFrame = 14;
    for (int k = 0; k < gnKeyConfigThumbScale; ++k)
        TEXTURE_CelDraw(&tCel, sub_KEYCFG_PanelRight() - 0x20, gnKeyConfigThumbY + 0x0C + k * 0x0C, -1, 5, 0);

    if (gbUpPressed_007C028C && sub_KEYCFG_IsOnUpArrow(nMouseX, nMouseY))
        tCel.nFrame = 9;
    else
        tCel.nFrame = 11;
    TEXTURE_CelDraw(&tCel, sub_KEYCFG_PanelRight() - 0x1F, KEYCFG_Y + 0x2F, -1, 5, 0);

    if (gbDownPressed_007C0290 && sub_KEYCFG_IsOnDownArrow(nMouseX, nMouseY))
        tCel.nFrame = 8;
    else
        tCel.nFrame = 10;
    TEXTURE_CelDraw(&tCel, sub_KEYCFG_PanelRight() - 0x1F, KEYCFG_Y + ((KEYCFG_Y + 0x171) - KEYCFG_Y) - 0x40, -1, 5, 0);

    for (unsigned int m = 0; m < 3; ++m)
    {
        int nColor;
        if (m == gnKeyConfigPressedButton)
            nColor = gaButtons_007246D8[m].nColor;
        else
            nColor = 4;
        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(gaButtons_007246D8[m].nString), gaButtons_007246D8[m].nX + 10, KEYCFG_Y + ((KEYCFG_Y + 0x171) - KEYCFG_Y) - 0x12, nColor, 0);
    }

    if (GetTickCount() < gdwMessageTick_007C02C8 + 2000)
    {
        const int nCenterX = gnScreenWidth_0071146C / 2;
        const int nTextY = KEYCFG_Y + ((KEYCFG_Y + 0x171) - KEYCFG_Y) + 0x1E;
        const int nTextX = nCenterX - D2Win_10121_GetTextWidth(D2LANG_GetStringFromTblIndex(gnMessage)) / 2;
        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(gnMessage), nTextX, nTextY, 1, 1);
    }

    sub_00502EF0_SetFont(nOldFont);
    ++gnBlink;
}


// 0x004A59D0
int __stdcall TEXT_KeyConfigWheelMsg(D2HotkeyActionStrc* pAction)
{
    if (GAME_IsExitPending())
    {
        pAction->nState18 = 0;
        return (int)pAction;
    }

    int nDuration = pAction->nValue0A / 120;
    if (nDuration)
    {
        TEXT_ScrollKeyConfigList(-nDuration * 2);
        sub_004B9A00(1, 0, 0, 0, 0);
    }
    pAction->nState18 = 1;
    pAction->nState1C = 0;
    return sub_00420290_HandleMsg(pAction);
}

// 0x004A5A40
void __stdcall TEXT_PrevEntryMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending())
    {
        pMsg->bReturn = 0;
        return;
    }

// build: symbol ?gpListEntries@* 0x00724264
    D2ClientListEntryStrc* pEntries = gpListEntries;
    int nOldIndex = gnKeyConfigSelected;
    do
    {
        TEXT_MoveKeyConfigSelection(-1);
    }
    while (pEntries[gnKeyConfigSelected].nId == 0x39);

    if (nOldIndex != gnKeyConfigSelected)
    {
        sub_004B9A00(1, 0, 0, 0, 0);
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A5AB0
void __stdcall TEXT_NextEntryMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending())
    {
        pMsg->bReturn = 0;
        return;
    }

    D2ClientListEntryStrc* pEntries = gpListEntries;
    int nOldIndex = gnKeyConfigSelected;
    do
    {
        TEXT_MoveKeyConfigSelection(1);
    }
    while (pEntries[gnKeyConfigSelected].nId == 0x39);

    if (nOldIndex != gnKeyConfigSelected)
    {
        sub_004B9A00(1, 0, 0, 0, 0);
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A5B30
void __stdcall TEXT_SelectSecondaryColumnMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending())
    {
        pMsg->bReturn = 0;
        return;
    }

// build: symbol ?gnKeyConfigColumn@* 0x007246D4
    if (gnKeyConfigColumn == 0)
    {
        gnKeyConfigColumn = 1;
        sub_004B9A00(1, 0, 0, 0, 0);
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A5B90
void __stdcall TEXT_SelectPrimaryColumnMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending())
    {
        pMsg->bReturn = 0;
        return;
    }

    if (gnKeyConfigColumn == 1)
    {
        gnKeyConfigColumn = 0;
        sub_004B9A00(1, 0, 0, 0, 0);
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A5BF0
void __stdcall TEXT_ClearEntryKeyMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending())
    {
        pMsg->bReturn = 0;
        return;
    }

// build: symbol ?gbKeyConfigReady@* 0x00724728
    if (gbKeyConfigReady)
    {
        if (!(pMsg->lParam & 0x40000000))
        {
            CUNIT_ClearHotkeyBinding(gpListEntries[gnKeyConfigSelected].nId, gnKeyConfigColumn);
            sub_004B9A00(2, 0, 0, 0, 0);
        }
    }
    else
    {
        gbKeyConfigReady = 1;
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}


// 0x004A5C70
void __stdcall TEXT_CancelKeyConfigMsg(SMSGHANDLER_PARAMS* message)
{
    if (GAME_IsExitPending()) { message->bReturn = 0; return; }
    if (global_00724728) {
        if (!(message->lParam & REPEAT_MASK)) {
            sub_00469D50();
            UI_SetUIVar(UI_VARIABLE, 1, 0);
            WARDENCLIENT_ToggleEscMenuUIState(0, 1);
            sub_004B9A00(1, 0, 0, 0, 0);
        }
    } else global_00724728 = 1;
    message->bReturn = 1;
    message->lResult = 0;
    sub_00420290_BreakHandlerChain(message);
}

// 0x004A5D00
void __cdecl TEXT_RegisterKeyCaptureHandlers()
{
    gbKeyCaptureActive = 1;
    sub_00455AE0_CloseUIVar(0xB);
    SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaKeyCaptureHandlers, 6);
    SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaKeyCaptureMButtonHandlers, 1);
    SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaKeyCaptureXButtonHandlers, 1);
    SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaKeyCaptureWheelHandlers, 1);
}

// 0x004A5D70
void __stdcall TEXT_UnregisterKeyConfigHandlers(int bReset)
{
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaKeyCaptureHandlers, 6);
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaKeyCaptureWheelHandlers, 1);
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaKeyCaptureXButtonHandlers, 1);
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaKeyCaptureMButtonHandlers, 1);
    if (bReset)
    {
        UI_RegisterKeyConfigHandlers();
        gbKeyCaptureActive = 0;
    }
}


// 0x004A5DE0
void __cdecl TEXT_CloseKeyCaptureHandlers()
{
    if (gbKeyCaptureActive)
    {
        AUTOMAP_UnregisterHandlerTable(WINDOW_GetWindow(), gaKeyCaptureHandlers, 6);
        AUTOMAP_UnregisterHandlerTable(WINDOW_GetWindow(), gaKeyCaptureWheelHandlers, 1);
        AUTOMAP_UnregisterHandlerTable(WINDOW_GetWindow(), gaKeyCaptureXButtonHandlers, 1);
        AUTOMAP_UnregisterHandlerTable(WINDOW_GetWindow(), gaKeyCaptureMButtonHandlers, 1);
        sub_00469D50();
        sub_0046AA20(1, 0);
        GAME_RegisterMouseHandlers();
        SELECT_ClearSelection();
        gbKeyCaptureActive = 0;
    }
}

// 0x004A5E60
static void TEXT_ReleaseKeyConfigPress(int nX, int nY)
{
    if (gaPressed[0])
    {
        if (TEXT_IsOnSelectedLine(nX, nY) && gpListEntries[gnKeyConfigSelected].nId != 0x39)
        {
            sub_004A5D00();
            sub_004B9A00(2, 0, 0, 0, 0);
        }
    }
    if (gaPressed[6])
    {
        const int nButton = gnKeyConfigPressedButton;
        if (nButton != 3 && TEXT_GetKeyConfigButtonAt(nX, nY) == nButton)
        {
            gaKeyConfigButtons[nButton].pfnClick();
            sub_004B9A00(2, 0, 0, 0, 0);
        }
    }
    gbKeyConfigPressRepeat = 0;
    gaPressed[0] = 0;
    gaPressed[1] = 0;
    gaPressed[2] = 0;
    gaPressed[3] = 0;
    gaPressed[4] = 0;
    gaPressed[5] = 0;
    gaPressed[6] = 0;
}

// 0x004A5F10
void __stdcall TEXT_KeyConfigButtonUpMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending())
    {
        pMsg->bReturn = 0;
        return;
    }

    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    TEXT_ReleaseKeyConfigPress(nX, nY);
    gbRedraw = 0;
    sub_004A4AD0_Press(nX, nY);
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A5F70
void __stdcall TEXT_ApplyEntryMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending())
    {
        pMsg->bReturn = 0;
        return;
    }

    if (gbKeyConfigReady)
    {
        if (!(pMsg->lParam & 0x40000000) && gpListEntries[gnKeyConfigSelected].nId != 0x39)
        {
            sub_004A5D00();
            sub_004B9A00(2, 0, 0, 0, 0);
            gbKeyConfigReady = 0;
        }
    }
    else
    {
        gbKeyConfigReady = 1;
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A6000
void __stdcall sub_004A6000_RegisterPressMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending())
    {
        pMsg->bReturn = 0;
        return;
    }

    int nX = pMsg->nXpos;
    int nY = pMsg->nYpos;
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaKeyCaptureHandlers, 6);
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaKeyCaptureWheelHandlers, 1);
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaKeyCaptureXButtonHandlers, 1);
    sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaKeyCaptureMButtonHandlers, 1);
    UI_RegisterKeyConfigHandlers();
    gbKeyCaptureActive = 0;
    gbRedraw = 1;
    sub_004A4AD0_Press(nX, nY);
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}



int __fastcall CMDTBL_QueryKey(int nId, int nMode, int nCommand, unsigned short* pKey);               // 0x00469C20

void __stdcall TEXT_UnregisterKeyConfigHandlers(int bReset);                                                // 0x004A5D70

unsigned long gdwMessageTick;                                                                            // 0x007C02C8

// 0x004A60B0
void __stdcall sub_004A60B0_KeyDownMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending())
    {
        pMsg->bReturn = 0;
        return;
    }

    unsigned short wKey = 0;
    if (!(pMsg->lParam & 0x40000000))
    {
        if (pMsg->wParam == 0x1B)
        {
            TEXT_UnregisterKeyConfigHandlers(1);
            sub_004B9A00(1, 0, 0, 0, 0);
// build: symbol ?gbKeyConfigReady@* 0x00724728
            gbKeyConfigReady = 0;
        }
        else
        {
// build: symbol ?gpListEntries@* 0x00724264
// build: symbol ?gnKeyConfigColumn@* 0x007246D4
            if (CMDTBL_QueryKey(gpListEntries[gnKeyConfigSelected].nId, gnKeyConfigColumn, (unsigned short)pMsg->wParam, &wKey))
            {
                TEXT_UnregisterKeyConfigHandlers(1);
                sub_004B9A00(2, 0, 0, 0, 0);
                if (pMsg->wParam == 0x0D || pMsg->wParam == 0x2E || pMsg->wParam == 0x08 || pMsg->wParam == 0x20)
                {
                    gbKeyConfigReady = 0;
                    goto store_key;
                }
            }
            gbKeyConfigReady = 1;
        }
store_key:
        if (wKey)
        {
            gwGlobal_007C02C4 = wKey;
            gdwMessageTick = GetTickCount();
        }
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004A61A0
void __stdcall sub_004A61A0_KeyUpMsgHandler(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending())
    {
        pMsg->bReturn = 0;
        return;
    }

    unsigned short wKey = 0;
    if (gbKeyConfigReady)
    {
        if (CMDTBL_QueryKey(gpListEntries[gnKeyConfigSelected].nId, gnKeyConfigColumn, (unsigned short)pMsg->wParam, &wKey))
        {
            TEXT_UnregisterKeyConfigHandlers(1);
            sub_004B9A00(2, 0, 0, 0, 0);
        }
    }
    else
    {
        gbKeyConfigReady = 1;
    }

    if (wKey)
    {
        gwGlobal_007C02C4 = wKey;
        gdwMessageTick = GetTickCount();
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}









static inline void MarkRightButtonPressed()
{
    gbSkillButtonPressed = 1;
    const int nClickSound = 4;
    sub_004B9A00(nClickSound, 0, 0, 0, 0);
}


static int __fastcall CLIENT_HitPanelButton(int nMode, int nX, int nY)
{
    return TEXT_IsInPanelButton(nMode, nX, nY);
}


static int __fastcall CLIENT_HitRightPanelButton(int nMode, int nX, int nY)
{
    return TEXT_IsInRightPanelButton(nMode, nX, nY);
}









static inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecord_Inl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

static inline D2CharStatsTxt* DATATBLS_GetCharStatsTxtRecord_Inl(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }

    return 0;
}



inline D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}


#define STAT_ARMORCLASS_VS_HTH 33





extern D2BeltSlotStrc gaStatButtons[4];                                                                  // 0x00724A48

int __fastcall sub_00498DC0(SMSGHANDLER_PARAMS* pMsg);

int __cdecl sub_00468830();

void __cdecl UI_CancelCursorItemUse();

static int sub_004A76C0_ClaimLeftPanelClick(SMSGHANDLER_PARAMS* pMsg)
{
    if (D2GFX_GetResolutionMode() == 2 && !sub_00498DC0(pMsg) && pMsg->nXpos <= gnScreenWidth / 2 && pMsg->nYpos < gnScreenHeight - 0x2F)
    {
        if (sub_00468830() == 6)
            UI_CancelCursorItemUse();
        pMsg->bReturn = 1;
        sub_00420290_BreakHandlerChain(pMsg);
        return 1;
    }
    return 0;
}



extern "C" __declspec(dllimport) short __stdcall GetKeyState(int nVirtKey);












#include "gen/data/Source/D2Client/Unknown_004A43E0.inc"
