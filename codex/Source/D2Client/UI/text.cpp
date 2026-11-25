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
#include "D2TextIdEntry.h"
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

int gbTextHandlersRegistered; // 0x007BF27C

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

void __stdcall TEXT_FreeTextList(D2TextListStrc* pList); // 0x0049D4D0

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

unsigned long gdwTextEndTick; // 0x007BF1AC

D2ClientDialogStrc* gpListDialog; // 0x007BF1B0

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

D2TextListStrc gtMessageTextList; // 0x007BF1E4

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

unsigned char gnSelectedTab; // 0x007BCC04

unsigned char gbOpenMercInvPending; // 0x007BEEE4


struct D2ClientStringListStrc
{
    Unicode* pStrings[6];
    unsigned short nCount;
    unsigned char f_1A[4];
    unsigned char unk0x1E[8];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize); // 0x00681EB0

unsigned long gnStartTick; // 0x007BF22C

unsigned char gbTextHoverSet; // 0x007BF23A

D2TextBoxStrc* gpTextBox; // 0x007BF0A4

D2TextBoxStrc* gpMainTextBox; // 0x007BF1A8

int gnTextBoxX; // 0x007BF1D0

int gnTextBoxY; // 0x007BF1D4

int gbTextSound; // 0x007BF230

void* gpScroin3Cel; // 0x007BF26C

void* gpScroin2Cel; // 0x007BF270

void* gpTextPanelFrameCel; // 0x007BF274

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

D2RectStrc gaHoverRects[16]; // 0x007BF0A8

D2RectStrc gtHoverOffset; // 0x007BF214

int gnHoverRectCount; // 0x007BF224

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

int gaPressed[7]; // 0x007C0288

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


int __cdecl TEXT_GetMaxFirstEntry(); // 0x004A44C0

int gnKeyConfigThumbScale; // 0x007C0278


extern int gnAutomapHeight; // 0x007A521C


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




int __fastcall CUNIT_HasHotkeyBinding(int nA, int nB); // 0x00469D90

int __stdcall sub_B05_Sink(int nA, int nB);

int __fastcall EXCEPTIONS_ReleaseSymbols(int nArg); // 0x0040C720

void __fastcall CMDTBL_ResetKeyConfig(int nArg); // 0x00469A60

extern "C" void __cdecl sub_00517ABB(void* pMemory); // 0x00517ABB


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

int gtQuestLog; // 0x007BF298


int __stdcall TEXT_IsAbovePanelLine(int nX); // 0x004A4780





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




int gbSkillButtonPressed; // 0x007C02E8

void __fastcall TEXT_MoveKeyConfigSelection(int nStep);

char gbGlobal_007BF2B2; // 0x007BF2B2

char gbGlobal_007BF2B4; // 0x007BF2B4


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

static bool gbWaypointClosePressed;                                                                        // 0x007BF06C

static int gnWaypointSelected;                                                                       // 0x007BF06D

char gbSent; // 0x007BF085

extern int gnPanelOffsetX;                                                                               // 0x007A2858

extern int gnPanelOffsetY;                                                                               // 0x007A285C

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00

typedef void (__fastcall* UNITFN)(D2UnitStrc* pUnit);

int gnQuestAct; // 0x007BF2A4

int gnQuestParam; // 0x007BF2AC

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

int gaQuestPageDefault[5]; // 0x007BF280

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

char gabNpcMenuState[1]; // 0x007C0C68

static int gnDialogHandlerRegCount; // 0x007C0E4C

static D2ClientDialogStrc* gpDialogList; // 0x007C0E54

static int gbDialogHandlersRegistered; // 0x007C0E58

static int gnDialogCount; // 0x007C0E5C

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

static __declspec(noinline) int __cdecl sub_0049D5A0_UpdateTextBox(D2TextBoxStrc* pTextBox);

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

int gnTradePartnerUnitId; // 0x007C0E60

inline void* operator new(unsigned int, void* pWhere) { return pWhere; }

// build: symbol ??0D2QuestTextBufferStrc@@QAE@XZ 0x004A4260

int gbTextBoxDone; // 0x007BF1BC

int gnTextActive; // 0x007BF1C0

#define gbUpPressed_007C028C (gaPressed[1])

#define gbDownPressed_007C0290 (gaPressed[2])

#define KEYCFG_X ((gnScreenWidth_0071146C - 620) / 2)

#define KEYCFG_Y ((gnAutomapHeight - 420) / 2)






void __fastcall UI_DrawRectangleBorder(D2RectStrc* pRect); // 0x00452E50

const Unicode* __fastcall CMDTBL_GetKeyText(int nKey, int nArg2); // 0x00469DE0

extern D2KeyConfigButtonStrc gaButtons_007246D8[3]; // 0x007246D8

extern unsigned int gdwMessageTick_007C02C8; // 0x007C02C8






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

struct D2HoverTextPacketStrc;

struct D2QuestTextMsgStrc;

struct D2QuestTextsStrc;

struct D2QuestPageRangeStrc;

struct D2QuestPosStrc;

struct D2QuestLogStateStrc;

#pragma pack(push, 1)

struct D2HoverTextPacketStrc
{
    unsigned char nHeader;
    unsigned char nType;
    unsigned int dwUnitId;
    unsigned char nArg;
    unsigned char unk0x07;
    unsigned char nMode;
    unsigned char unk0x09;
    unsigned short wStringId;
};

#pragma pack(pop)

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

unsigned char gabQuestFlagsB[41]; // 0x007BF380

unsigned short gwTextPanelClassId; // 0x007BF234

D2TextHeaderStrc* gpTextHeader; // 0x007BF250




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

struct D2PacketRecord6Strc;

struct D2QuestTableStrc;

struct D2UiEntry10Strc;


struct D2PacketRecord6Strc
{
    unsigned char nHeader;
    unsigned char nId;
    unsigned char nFlags;
    unsigned char nValue;
    short nParam;
};



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

void __fastcall TEXT_HandleQuestEvent(int nArg, D2PacketRecord6Strc* pPacket); // 0x004A2CB0



// 0x00491940
void __cdecl TEXT_ResetNpcPanel()
{
    gbInvGoldButtonDown = 0;
    gnSelectedShopButton = -1;
    gnSelectedTab = 0;
    gnGlobal_007BCAF0 = 0;
// build: symbol ?gnNpcTabCount@* 0x00722158
    for (int i = 0; i < gnNpcTabCount; ++i)
    {
        *(int*)gaNpcTabStates[i].bSelected = 0;
        *(int*)gaNpcTabStates[i].bEnabled = 0;
    }
    gbNpcTradeClicked = 0;
    gnInvPanelMode = 1;
    INV_SetupPanelButtons();

    int nNpcId;
    if (NPCMENU_GetInteractNpcId(&nNpcId))
    {
        D2UnitStrc* pNpc = CUNIT_FindClientUnit(nNpcId, 1);
        int bMatched = 0;
        if (pNpc)
        {
            switch ((unsigned int)pNpc->dwClassId)
            {
            case 0x9A:
            case 0x1FF:
                gnSelectedTab = 1;
                bMatched = 1;
                break;
            case 0x94:
            case 0xB1:
            case 0xB2:
            case 0xCA:
            case 0xFC:
            case 0xFD:
            case 0xFF:
            case 0x101:
            case 0x195:
            case 0x201:
                gnSelectedTab = 3;
                bMatched = 1;
                break;
            case 0x93:
            case 0x200:
                gnSelectedTab = 0;
                bMatched = 1;
                break;
            }
        }
        INV_SelectItemPageTab(gnSelectedTab);
        if (bMatched)
        {
            gdwNpcPanelDelayTick = GetTickCount() + 500;
        }
    }
}




extern "C" void __cdecl TEXT_FreeWaypointCels(); // 0x0049C650


void __cdecl sub_0049C6C0_SendWaypointClose(); // 0x0049C6C0



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

// 0x0049D010
void __stdcall TEXT_OnWaypointMouseUp(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = (unsigned short)pMsg->lParam;
    int nY = (unsigned short)((unsigned int)pMsg->lParam >> 16);
    if (sub_0047F210_IsMouseInSlots())
        return;

    if (nX <= gnScreenWidth && nY <= gnScreenHeight - 0x31)
    {
        nX -= gnPanelOffsetX;
        nY += gnPanelOffsetY;
        if (gbWaypointClosePressed)
        {
            if (nX >= 0x111 && nX <= 0x111 + 0x23 && nY >= 0x183 && nY <= 0x183 + 0x21)
            {
                UI_SetUIVar(0x14, 1, 0);
                sub_0049C6C0_SendWaypointClose();
            }
        }
        else if (gnWaypointSelected != -1 && gnWaypointSelected == sub_0049C510_GetWaypointRowAtPoint(nX, nY))
        {
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            MSG_SendTwoDwords(0x49, gnWaypointId, gaWaypointEntries[gnWaypointSelected].nLevelId);
            gbSent = 1;
            sub_0049C6C0_SendWaypointClose();
            gbWaypointClosePressed = false;
            gnWaypointSelected = -1;
            UI_SetUIVar(0x14, 1, 0);
            sub_004B9A00(0x8B7, 0, 0, 0, 0);
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }

        gbWaypointClosePressed = false;
        gnWaypointSelected = -1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
    else
    {
        gbWaypointClosePressed = false;
        gnWaypointSelected = -1;
    }
}

// 0x0049D2E0
int __fastcall TEXT_IsAsciiChar(const unsigned short* pChar)
{
    return *pChar < 0x80;
}

// 0x0049D2F0
void __fastcall TEXT_SetFieldA4(D2TextFieldA4Strc* pRecord, int nValue)
{
    if (pRecord)
        pRecord->nFieldA4 = nValue;
}

// 0x0049D300
int __fastcall TEXT_GetFieldA4(D2TextFieldA4Strc* pRecord)
{
    if (!pRecord)
        return 0;
    return pRecord->nFieldA4;
}

struct D2BitBufferStrc;

void __stdcall sub_L04_EmitUse(const Unicode* pText);

// 0x0049D310
static void __stdcall TEXT_CopyTextLine(Unicode* pDest, int nMax, const Unicode** ppSrc)
{
    int i = 0;
    memset(pDest, 0, nMax * sizeof(Unicode));
    for (; i < nMax; ++i)
    {
        if ((*ppSrc)->wChar == 0x0A)
            break;
        pDest[i].wChar = (*ppSrc)->wChar;
        ++*ppSrc;
    }
    if (i < nMax)
    {
        const Unicode* pNext = *ppSrc;
        if (pNext->wChar == 0x0A)
            *ppSrc = pNext + 1;
    }
}

void __stdcall sub_L04_EmitCopyTextLine(const Unicode* pText)
{
    const Unicode* p = pText;
    while (p->wChar)
    {
        Unicode wszLine[0x20];
        TEXT_CopyTextLine(wszLine, 0x20, &p);
        sub_L04_EmitUse(wszLine);
    }
}

// build: symbol ??0Unicode@@QAE@XZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0049D370
static void TEXT_FreeTextLines(D2SplittedTextStrc* pLine)
{
    while (pLine)
    {
        D2SplittedTextStrc* pNext = pLine->pNextLine;
        FOG_Free(pLine->wszLine, ".\\UI\\text.cpp", 0x60F, 0);
        FOG_Free(pLine, ".\\UI\\text.cpp", 0x610, 0);
        pLine = pNext;
    }
}

// 0x0049D3B0
static inline void TEXT_SetWidthFromWord(D2TextWidthStrc* pRecord)
{
    pRecord->nWidth = pRecord->wWidth;
}

// 0x0049D3C0
static void TEXT_MeasureTextBox(D2TextBoxStrc* pBox)
{
    int nMaxWidth = 0;
    pBox->nTextTop = 0;
    pBox->nTextBottom = pBox->f_14;
    for (D2SplittedTextStrc* pLine = pBox->pFirst; pLine; pLine = pLine->pNextLine)
    {
        nMaxWidth = nMaxWidth > D2Win_10121_GetTextWidth(pLine->wszLine) ? nMaxWidth : D2Win_10121_GetTextWidth(pLine->wszLine);
    }
    pBox->nWidth = nMaxWidth + 0x14;
    pBox->nHeight = pBox->nLines * 0x0F + 6;
}

// 0x0049D410
void __stdcall TEXT_FreeTextBox(D2TextBoxStrc* pTextBox)
{
    if (pTextBox)
    {
        TEXT_FreeTextLines(pTextBox->pFirst);
        FOG_Free(pTextBox, ".\\UI\\text.cpp", 0x68E, 0);
    }
}

void __fastcall sub_00467430(D2RectStrc* pRect); // 0x00467430

extern char gData_007BF1B0[]; // 0x007BF1B0

// 0x0049D440
void __cdecl TEXT_LoadTextSettings()
{
    memset(gData_007BF1B0, 0, 0x9F);
    unsigned long nValue;
    if (!SRegLoadValue("Diablo II", "Text Display Beta", 0, &nValue))
    {
// build: symbol ?gnTextDisplaySetting@* 0x007BF1F6
        gnTextDisplaySetting = 1;
    }
    else
    {
        gnTextDisplaySetting = nValue;
    }
}

// 0x0049D490
static void TEXT_FreeTextNode(D2TextNodeStrc* pNode)
{
    for (int i = 0; i < 6; i++)
    {
        if (pNode->pLines[i])
            FOG_Free(pNode->pLines[i], ".\\UI\\text.cpp", 0x6B3, 0);
    }
    FOG_Free(pNode, ".\\UI\\text.cpp", 0x6B6, 0);
}

void __fastcall sub_M111_Emit_0049D3B0(D2TextWidthStrc* pRecord, int* pDone)
{
    TEXT_SetWidthFromWord(pRecord);
    *pDone = 1;
}

// 0x0049D4D0
void __stdcall TEXT_FreeTextList(D2TextListStrc* pList)
{
    int nCount = 0;
    D2TextNodeStrc* pNode = pList->pFirst;
    if (pNode)
    {
        do
        {
            D2TextNodeStrc* pCurrent = pNode;
            pNode = pNode->pNext;
            for (int i = 0; i < 6; ++i)
            {
                if (pCurrent->pLines[i])
                {
                    FOG_Free(pCurrent->pLines[i], ".\\UI\\text.cpp", 1715, 0);
                }
            }

            FOG_Free(pCurrent, ".\\UI\\text.cpp", 1718, 0);
            ++nCount;
        }
        while (pNode);

        pList->pFirst = pNode;
    }

    D2_ASSERT((unsigned short)nCount == pList->wCount, 1741);
    pList->wCount = 0;
}

// 0x0049D570
void __fastcall TEXT_SaveTextDisplaySetting(unsigned long nValue)
{
// build: symbol ?gnTextDisplaySetting@* 0x007BF1F6
    gnTextDisplaySetting = nValue;
    SRegSaveValue("Diablo II", "Text Display Beta", 0, nValue);
}

// 0x0049D590
unsigned int __fastcall TEXT_CalcTextOffset(unsigned int nValue)
{
    return 0x70 - (nValue >> 10);
}

// 0x0049D8E0
void __fastcall TEXT_DrawTextList(D2TextBoxStrc* pTextBox, int nX, int nY)
{
    int nLines = (unsigned int)pTextBox->nLines > 10 ? 10 : pTextBox->nLines;

    D2SplittedTextStrc* pNode = pTextBox->pFirst;
    if (!nLines || !pNode || nY < 0)
    {
        return;
    }

    const int nHeight = pTextBox->nHeight;
    if (nHeight + nY >= gnScreenHeight)
    {
        return;
    }

    AUTOMAP_DrawFramedBox(nX, nY + 4, pTextBox->nWidth, nHeight - 5, 0, 1);
    int i = 0;
    const int nOldFont = D2Win_10127_SetFont(13);
    for (; i < nLines && pNode; ++i)
    {
        D2Win_10117_DrawText(pNode->wszLine, nX + 10, nY + 18 + 15 * (i - nLines + pTextBox->nLines), 0, 0);
        pNode = pNode->pNextLine;
    }
    D2Win_10127_SetFont(nOldFont);
}

// 0x0049D9A0
static int TEXT_DrawTextBoxAt(D2TextBoxStrc* pTextBox, D2RectStrc* pRect)
{
    if (!pTextBox->nScroll)
        pTextBox->nScroll = 1;
    else if (pTextBox->nScroll == 3)
        return 1;

    switch (sub_0045AE90())
    {
    case 1:
        if (pRect->nLeft > gnScreenWidth / 2 - 10)
            return 1;
        break;
    case 2:
        if (pRect->nLeft < gnScreenWidth / 2 + 10)
            return 1;
        break;
    case 3:
        return 1;
    }
    TEXT_DrawTextList(pTextBox, pRect->nLeft, pRect->nTop);
    return 1;
}

// 0x0049DA10
void __stdcall TEXT_EatMsg(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x0049DA30
void __fastcall TEXT_SetHoverUnit(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
// build: symbol ?gnTextHoverUnitId@* 0x007BF23B
        gnTextHoverUnitId = pUnit->dwUnitId;
        gbTextHoverSet = 1;
    }
    else
    {
        gbTextHoverSet = 0;
    }
}

struct D2TextIdEntryStrc;


void __fastcall MSG_SendDword(char nHeader, int nArg); // 0x00478680

extern D2TextIdEntryStrc gaTextIds[]; // 0x00722678

extern int gnTextIdCount; // 0x00722EB4

int gnGlobal_007BF1E0; // 0x007BF1E0

// 0x0049DA50
void __cdecl TEXT_ClearHoverUnit()
{
    gbTextHoverSet = 0;
}

// 0x0049DA60
void __fastcall TEXT_ToggleTextHandlers(int nMode)
{
    if (nMode == 0)
    {
        if (gbTextHandlersRegistered == 1)
        {
            gbTextHandlersRegistered = 0;
            AUTOMAP_UnregisterHandlerTable(WINDOW_GetWindow(), gaTextMsgHandlers, 7);
        }
    }
    else if (nMode == 1 && gbTextHandlersRegistered == 0)
    {
        gbTextHandlersRegistered = 1;
        gnStartTick = GetTickCount();
        SCMD_RegisterMsgHandlers(WINDOW_GetWindow(), gaTextMsgHandlers, 7);
    }
}

// 0x0049DAC0
int __fastcall TEXT_IsStateZeroOrOne(D2TextStateStrc* pRecord)
{
    if (!pRecord)
        return 0;
    int nState = pRecord->nState;
    if (nState == 1 || nState == 0)
        return 1;
    return 0;
}

// 0x0049DAE0
void __fastcall TEXT_AdjustTextPos(D2TextBoxPosStrc* pBox, D2TextPointStrc* pPoint)
{
    pPoint->nX -= pBox->wWidth / 2;
    pPoint->nY -= 50;
    pPoint->nY -= pBox->nRows * 15 + 3;
}

// 0x0049DB10
D2ClientStringListStrc* __fastcall TEXT_CloneStringList(D2ClientStringListStrc* pSource)
{
    D2ClientStringListStrc* pCopy = (D2ClientStringListStrc*)FOG_Alloc(0x26, ".\\UI\\text.cpp", 0x9D0, 0);
    memset(pCopy, 0, 0x26);
    for (int i = 0; i < pSource->nCount; ++i)
    {
        pCopy->pStrings[i] = (Unicode*)FOG_Alloc((sub_00526800(pSource->pStrings[i]) + 1) * sizeof(Unicode), ".\\UI\\text.cpp", 0x9D4, 0);
        sub_005267E0(pCopy->pStrings[i], pSource->pStrings[i]);
    }
    pCopy->nCount = pSource->nCount;
    *(int*)pCopy->f_1A = *(int*)pSource->f_1A;
    return pCopy;
}

// 0x0049DC40
void __cdecl TEXT_DrawMessageList()
{
    int i;
    int nLine;
    D2TextNodeStrc* pNode;
    D2SplittedTextStrc* pNextLine;
    int nBaseY;
    int bSplit;
    int nOldFont;
    int nLineCount;
    int nX;
    int nWidth;
    int nY;
    D2SplittedTextStrc* pTextLine;

    if (!gtMessageTextList.wCount)
    {
        return;
    }

    nOldFont = D2Win_10127_SetFont(0xD);
    pNode = gtMessageTextList.pFirst;
    nBaseY = 0x14;
    if (GAME_GetUIVarState(0x13))
    {
        nBaseY = 0x5F;
    }

    nX = 0xF;
    nLine = 0;
    bSplit = 0;
    switch (sub_0045AE90())
    {
    case 1:
        bSplit = 1;
        break;

    case 2:
        nX = gnScreenWidth / 2 + 0xF;
        bSplit = 1;
        break;
    }

    for (; pNode; pNode = pNode->pNext)
    {
        for (i = 0; i < 6; ++i)
        {
            if (!pNode->pLines[i])
            {
                continue;
            }

            if (bSplit)
            {
                Unicode wszText[0x190];
                sub_005267E0(wszText, pNode->pLines[i]);
                pTextLine = D2WINFONT_SplitText(wszText, &nLineCount, 0x12C);
                if (pTextLine)
                {
                    nY = 15 * nLine + nBaseY;
                    do
                    {
                        pNextLine = pTextLine->pNextLine;
                        nWidth = D2Win_10123(pTextLine->wszLine, sub_00526800(pTextLine->wszLine));
                        if (nWidth)
                        {
                            AUTOMAP_DrawFramedBox(nX - 5, nY - 0xE, nWidth + 0xA, 0x10, 0, 1);
                            D2Win_10117_DrawText(pTextLine->wszLine, nX, nY, pNode->nColor, 0);
                            ++nLine;
                            nY += 0xF;
                        }
                        FOG_Free(pTextLine->wszLine, ".\\UI\\text.cpp", 0xA47, 0);
                        FOG_Free(pTextLine, ".\\UI\\text.cpp", 0xA48, 0);
                        pTextLine = pNextLine;
                    }
                    while (pTextLine);
                }
            }
            else
            {
                nWidth = D2Win_10123(pNode->pLines[i], sub_00526800(pNode->pLines[i]));
                if (nWidth)
                {
                    AUTOMAP_DrawFramedBox(nX - 4, 15 * nLine + nBaseY - 0xE, nWidth + 8, 0x10, 0, 1);
                    D2Win_10117_DrawText(pNode->pLines[i], nX, 15 * nLine + nBaseY, pNode->nColor, 0);
                    ++nLine;
                }
            }
        }
    }

    pNode = gtMessageTextList.pFirst;
    D2TextNodeStrc* pPrevious = 0;
    const unsigned long dwTick = GetTickCount();
    while (pNode)
    {
        if (pNode->dwEndTick < dwTick)
        {
            --gtMessageTextList.wCount;
            D2TextNodeStrc* pNext = pNode->pNext;
            if (gtMessageTextList.pFirst == pNode)
            {
                gtMessageTextList.pFirst = pNext;
            }
            for (int j = 0; j < 6; ++j)
            {
                if (pNode->pLines[j])
                {
                    FOG_Free(pNode->pLines[j], ".\\UI\\text.cpp", 0x6B3, 0);
                }
            }
            FOG_Free(pNode, ".\\UI\\text.cpp", 0x6B6, 0);
            if (pPrevious)
            {
                pPrevious->pNext = pNext;
            }
            pNode = pNext;
        }
        else
        {
            pPrevious = pNode;
            pNode = pNode->pNext;
        }
    }

    D2Win_10127_SetFont(nOldFont);
}

// 0x0049DEE0
void __cdecl TEXT_DrawOverheadTextList()
{
    if (!gtOverheadTextList.wCount)
    {
        return;
    }

    int nOldFont = D2Win_10127_SetFont(13);
    D2TextNodeStrc* pNode = gtOverheadTextList.pFirst;
    int nX = 15;
    if (GAME_GetUIVarState(6) || GAME_GetUIVarState(0x11))
    {
        nX = 100;
    }

    if (pNode)
    {
        int nBoxRow = 0;
        int nTextRow = 0;
        do
        {
            for (int i = 0; i < 6; ++i)
            {
                if (pNode->pLines[i])
                {
                    AUTOMAP_DrawFramedBox(nX - 5, gnScreenHeight - 25 * nBoxRow - i * 25 / 2 - 0x81,
                                               D2Win_10123(pNode->pLines[i], sub_00526800(pNode->pLines[i])) + 10, 0x10, 0, 1);
                    D2Win_10117_DrawText(pNode->pLines[i], nX, gnScreenHeight + 25 * nTextRow - i * 25 / 2 - 0x73, pNode->nColor, 0);
                }
            }
            pNode = pNode->pNext;
            ++nBoxRow;
            --nTextRow;
        }
        while (pNode);
    }

    pNode = gtOverheadTextList.pFirst;
    D2TextNodeStrc* pPrev = 0;
    unsigned int dwNow = GetTickCount();
    while (pNode)
    {
        if (pNode->dwEndTick < dwNow)
        {
            --gtOverheadTextList.wCount;
            D2TextNodeStrc* pNext = pNode->pNext;
            if (gtOverheadTextList.pFirst == pNode)
            {
                gtOverheadTextList.pFirst = pNext;
            }

            for (int j = 0; j < 6; ++j)
            {
                if (pNode->pLines[j])
                {
                    FOG_Free(pNode->pLines[j], ".\\UI\\text.cpp", 0x6B3, 0);
                }
            }
            FOG_Free(pNode, ".\\UI\\text.cpp", 0x6B6, 0);

            if (pPrev)
            {
                pPrev->pNext = pNext;
            }
            pNode = pNext;
        }
        else
        {
            pPrev = pNode;
            pNode = pNode->pNext;
        }
    }

    D2Win_10127_SetFont(nOldFont);
}

// 0x0049DBC0
void __fastcall TEXT_AddToHistory(D2TextNodeStrc* pSource)
{
    D2TextNodeStrc* pClone = TEXT_CloneStringList(pSource);
    D2TextNodeStrc* pNode;
    if (gtTextHistory.wCount >= 0x80)
    {
        pNode = gtTextHistory.pFirst;
        if (!pNode)
        {
            goto link;
        }

        D2TextNodeStrc* pPrevious = 0;
        while (pNode->pNext)
        {
            pPrevious = pNode;
            pNode = pNode->pNext;
        }
        TEXT_FreeTextNode(pNode);
        if (pPrevious)
            pPrevious->pNext = 0;
        if (gtTextHistory.wCount >= 1)
            gtTextHistory.wCount--;
    }
    pNode = gtTextHistory.pFirst;
link:
    pClone->pNext = pNode;
    gtTextHistory.wCount++;
    gtTextHistory.pFirst = pClone;
}

void __fastcall sub_0049E5C0_PrintWrappedLine(const Unicode* wszText, char nColor)
{
    const int nOldFont = D2Win_10127_SetFont(0xD);
    D2TextNodeStrc* pNode = (D2TextNodeStrc*)FOG_Alloc(sizeof(D2TextNodeStrc), ".\\UI\\text.cpp", 0xDAD, 0);
    memset(pNode, 0, sizeof(D2TextNodeStrc));
    pNode->pNext = 0;
    pNode->dwEndTick = GetTickCount() + 10000;

    int nCount = sub_00526800(wszText);
    const int nTotal = nCount;
    int nStart = 0;
    pNode->nLines = 0;
    while (nCount > 0)
    {
        while (D2Win_10123(&wszText[nStart], nCount) > gnScreenWidth - 0x46)
        {
            nCount--;
            if (nCount <= 0)
                break;
        }
        if (nStart + nCount != nTotal)
        {
            while (nCount > 0 && !sub_00526D30_IsLineBreak(&wszText[nStart], nCount + 1))
                nCount--;
        }
        if (!nCount)
            break;

        const Unicode* pSource = &wszText[nStart];
        char szLine[0x400];
        sub_005263E0(szLine, pSource, nCount);
        if (pNode->nLines >= 6)
            break;

        const int nSize = nCount * 2 + 2;
        pNode->pLines[pNode->nLines] = (Unicode*)FOG_Alloc(nSize, ".\\UI\\text.cpp", 0xDD7, 0);
        memset(pNode->pLines[pNode->nLines], 0, nSize);
        sub_00526790(pNode->pLines[pNode->nLines], pSource, nCount);
        pNode->nLines++;
        nStart = nCount;
        nCount = nTotal - nCount;
    }
    pNode->nColor = (unsigned char)nColor;

    if (gtOverheadTextList.pFirst)
    {
        D2TextNodeStrc* pLast = gtOverheadTextList.pFirst;
        unsigned short nNodes = 0;
        while (pLast->pNext)
        {
            pLast = pLast->pNext;
            nNodes++;
        }
        D2_ASSERT(nNodes == gtOverheadTextList.wCount - 1, 0xDF1);
        pLast->pNext = pNode;
    }
    else
    {
        gtOverheadTextList.pFirst = pNode;
    }
    gtOverheadTextList.wCount++;
    TEXT_AddToHistory(pNode);

    if (gtOverheadTextList.wCount > 2)
    {
        D2TextNodeStrc* pFirst = gtOverheadTextList.pFirst;
        gtOverheadTextList.pFirst = pFirst->pNext;
        TEXT_FreeTextNode(pFirst);
        gtOverheadTextList.wCount--;
    }

    if (GAME_GetUIVarState(0x18) && gpListBox)
    {
        gpListBox->Refresh();
        sub_0049E340();
    }
    D2Win_10127_SetFont(nOldFont);
    sub_004B9A00(6, 0, 0, 0, 0);
}

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

// 0x0049E070
static bool __stdcall TEXT_PlaceHoverRect(int nCount, D2RectStrc* pRect)
{
    if (nCount >= 0x10)
        return false;

    if (!nCount)
    {
        gaHoverRects[0] = *pRect;
        return true;
    }

    if (!sub_J06_IntersectsAnyHoverRect(pRect, nCount))
    {
        gaHoverRects[nCount] = *pRect;
        return true;
    }

    int nDir;
    for (int nDX = 0x32; nDX < 0x190; nDX += 0x32)
    {
        for (int nDY = 0x23; nDY < 0x118; nDY += 0x23)
        {

            for (nDir = 0; nDir < gnHoverDirCount; ++nDir)
            {
                D2RectStrc tRect = *pRect;
                tRect.nLeft += gaHoverDirs[nDir] * nDX;
                tRect.nRight = tRect.nLeft + 0x190;
                tRect.nTop += gaHoverDirs[nDir] * nDY;
                tRect.nBottom = tRect.nTop + 0x118;
                if (tRect.nLeft < 0 || tRect.nRight > gnScreenWidth || tRect.nTop < 0 || tRect.nBottom > gnScreenHeight)
                    continue;

                bool bOverlap = false;
                for (int j = 0; j < nCount; ++j)
                {
                    D2RectStrc tTest;
                    if (IntersectRect(&tTest, &gaHoverRects[j], &tRect))
                        bOverlap = true;
                }
                if (!bOverlap)
                {
                    gaHoverRects[nCount] = tRect;
                    *pRect = tRect;
                    return true;
                }
            }
        }
    }
    return false;
}

// 0x0049E250
static bool TEXT_IsLanguageCompatible(int nLangId)
{
    const int nCurrentLangId = STRTABLE_GetLanguage();
    if (!(nCurrentLangId == nLangId))
    {
        if (nCurrentLangId == 7)
        {
            if (nLangId == 0xC)
                return true;
        }
        else if (nCurrentLangId == 0xC)
        {
            if (nLangId == 7)
                return true;
        }
        return false;
    }
    return true;
}

int __fastcall sub_T49_Emit_0049E250(int nLangId)
{
    return TEXT_IsLanguageCompatible(nLangId);
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

// 0x0049E280
static bool TEXT_ConvertHoverText(int nLangId, Unicode* wszText, const char* szText)
{
    if (nLangId != 7 && nLangId != 0xC && nLangId != 6 && nLangId != 9)
    {
        sub_00526F20_ToUnicode(wszText, szText, 0x100);
        return true;
    }

    MultiByteToWideChar(0, 1, szText, 0x100, wszText, 0x100);
    const int nCurrentLangId = STRTABLE_GetLanguage();
    if (nCurrentLangId == nLangId)
        return true;
    if (nCurrentLangId == 7)
    {
        if (nLangId == 0xC)
            return true;
    }
    else if (nCurrentLangId == 0xC && nLangId == 7)
    {
        return true;
    }

    for (; wszText->wChar; ++wszText)
    {
        if (wszText->wChar >= 0x80)
            return false;
    }
    return true;
}

// 0x0049E300
void __cdecl TEXT_FreeMainTextBox()
{
    if (gpMainTextBox)
    {
        TEXT_FreeTextBox(gpMainTextBox);
        gpMainTextBox = 0;
    }
}

// 0x0049E390
unsigned long __cdecl TEXT_GetTimeoutTick()
{
    return GetTickCount() + 10000;
}

// 0x0049E3A0
void __fastcall TEXT_PrintChatLine(const Unicode* wszText, char nColor)
{
    D2TextNodeStrc* pNode = (D2TextNodeStrc*)FOG_Alloc(sizeof(D2TextNodeStrc), ".\\UI\\text.cpp", 0xD46, 0);
    memset(pNode, 0, sizeof(D2TextNodeStrc));
    pNode->pNext = 0;
    pNode->dwEndTick = GetTickCount() + 10000;
    int nOldFont = D2Win_10127_SetFont(0xD);

    int nLines;
    D2SplittedTextStrc* pLine = D2WINFONT_SplitText(wszText, &nLines, gnScreenWidth - 0x46);
    pNode->nLines = (unsigned int)nLines > 6 ? 6 : nLines;
    for (int i = 0; i < nLines; i++)
    {
        if (i < pNode->nLines)
            pNode->pLines[i] = pLine->wszLine;
        else
            FOG_Free(pLine->wszLine, ".\\UI\\text.cpp", 0xD5A, 0);
        D2SplittedTextStrc* pNext = pLine->pNextLine;
        FOG_Free(pLine, ".\\UI\\text.cpp", 0xD5D, 0);
        pLine = pNext;
    }
    pNode->nColor = (unsigned char)nColor;

    if (gtMessageTextList.pFirst)
    {
        D2TextNodeStrc* pLast = gtMessageTextList.pFirst;
        unsigned short wCount = 0;
        D2TextNodeStrc** ppNext = &pLast->pNext;
        if (pLast->pNext)
        {
            do
            {
                pLast = *ppNext;
                ppNext = &pLast->pNext;
                wCount++;
            }
            while (*ppNext);
        }
        D2_ASSERT(wCount == gtMessageTextList.wCount - 1, 0xD6C);
        pLast->pNext = pNode;
    }
    else
    {
        gtMessageTextList.pFirst = pNode;
    }

    if (pNode->nColor == 4 && pNode->nLines == 1)
    {
        char szName[0x100] = {0};
        sub_005263E0(szName, pNode->pLines[0], 0x100);
        sub_00611560_GetSquelchList()->AddName(szName, 0x100);
    }

    TEXT_AddToHistory(pNode);
    gtMessageTextList.wCount++;

    int nTotal = 0;
    D2TextNodeStrc* p = gtMessageTextList.pFirst;
    if (gtMessageTextList.pFirst)
    {
        do
        {
            nTotal += p->nLines;
            p = p->pNext;
        }
        while (p);
    }
    if (nTotal > 0x12)
    {
        D2TextNodeStrc* pOld = gtMessageTextList.pFirst;
        gtMessageTextList.pFirst = gtMessageTextList.pFirst->pNext;
        gtMessageTextList.wCount--;
        TEXT_FreeTextNode(pOld);
    }

    sub_004B9A00(6, 0, 0, 0, 0);
    if (GAME_GetUIVarState(0x18) && gpListBox)
    {
        gpListBox->Refresh();
        sub_0049E340();
    }
    D2Win_10127_SetFont(nOldFont);
}

// 0x0049E5C0
void __fastcall TEXT_PrintPartyText(const Unicode* wszText, char nColor)
{
    const int nOldFont = D2Win_10127_SetFont(0xD);
    D2TextNodeStrc* pNode = (D2TextNodeStrc*)FOG_Alloc(sizeof(D2TextNodeStrc), ".\\UI\\text.cpp", 0xDAD, 0);
    memset(pNode, 0, 0x24);
    pNode->pNext = 0;
    pNode->dwEndTick = GetTickCount() + 10000;

    int nCount = sub_00526800(wszText);
    const int nTotal = nCount;
    int nStart = 0;
    pNode->nLines = 0;
    for (;;)
    {
        while (nCount > 0 && D2Win_10123(&wszText[nStart], nCount) > gnScreenWidth - 0x46)
            nCount--;

        if (nStart + nCount != nTotal)
        {
            while (nCount > 0 && !sub_00526D30_IsLineBreak(&wszText[nStart], nCount + 1))
                nCount--;
        }

        if (!nCount)
            break;

        const Unicode* pSource = &wszText[nStart];
        int aLine[0x100];
        sub_005263E0((char*)aLine, pSource, nCount);
        if (pNode->nLines >= 6)
            break;

        const int nSize = nCount * 2 + 2;
        pNode->pLines[pNode->nLines] = (Unicode*)FOG_Alloc(nSize, ".\\UI\\text.cpp", 0xDD7, 0);
        memset(pNode->pLines[pNode->nLines], 0, nSize);
        strncpy(pNode->pLines[pNode->nLines], pSource, nCount);
        pNode->nLines++;
        nStart = nCount;
        nCount = nTotal - nCount;
    }
    pNode->nColor = (unsigned char)nColor;

    if (gtOverheadTextList.pFirst)
    {
        D2TextNodeStrc* pLast = gtOverheadTextList.pFirst;
        unsigned short nNodes = 0;
        D2TextNodeStrc** ppNext = &pLast->pNext;
        if (*ppNext)
        {
            do
            {
                pLast = *ppNext;
                ppNext = &pLast->pNext;
                nNodes++;
            } while (*ppNext);
        }
        D2_ASSERT(nNodes == gtOverheadTextList.wCount - 1, 0xDF1);
        pLast->pNext = pNode;
    }
    else
    {
        gtOverheadTextList.pFirst = pNode;
    }
    gtOverheadTextList.wCount++;
    TEXT_AddToHistory(pNode);

    if (gtOverheadTextList.wCount > 2)
    {
        D2TextNodeStrc* pFirst = gtOverheadTextList.pFirst;
        gtOverheadTextList.pFirst = gtOverheadTextList.pFirst->pNext;
        TEXT_FreeTextNode(pFirst);
        gtOverheadTextList.wCount--;
    }

    if (GAME_GetUIVarState(0x18) && gpListBox)
    {
        gpListBox->Refresh();
        sub_0049E340();
    }
    D2Win_10127_SetFont(nOldFont);
    sub_004B9A00(6, 0, 0, 0, 0);
}

// 0x0049E7E0
void __fastcall TEXT_SetTextCallback(D2TextCallback pfnCallback, void* pContext)
{
    gpfnTextCallback = pfnCallback;
    gpTextCallbackContext = pContext;
}

// 0x0049E7F0
void __stdcall sub_0049E7F0_Nop()
{
}

// 0x0049E800
void __stdcall sub_0049E800_Nop()
{
}

// 0x0049E810
void __cdecl TEXT_SetPanelRect()
{
    D2RectStrc tRect;
// build: symbol ?gnTextTop@* 0x007225FC
    tRect.nTop = gnTextTop;
    tRect.nBottom = (gnTextTop + 182 < gnScreenHeight - 53) ? gnTextTop + 182 : gnScreenHeight - 53;
    tRect.nLeft = gnTextLeft - 10;
    tRect.nRight = gnTextLeft + 335;
    sub_00467430(&tRect);
    SELECT_ClearSelection();
}

// 0x0049E860
void __cdecl TEXT_ClearHint()
{
    if (gnHintId)
    {
        const int nHint = sub_004B9610_FindHint(gnHintId);
        if (nHint)
            SOUNDINST_ArmHint(nHint, 0, 0, 4);
        gnHintId = 0;
    }
    ghHintSound = 0;
}

// 0x0049E8B0
D2UnitStrc* __cdecl TEXT_GetTextUnit()
{
// build: symbol ?gbTextFromObject@* 0x007BF20A
    if (gbTextFromObject)
// build: symbol ?gnTextNpcId@* 0x007BF202
        return CUNIT_FindClientUnit(gnTextNpcId, 1);
    if (gnTextActive)
// build: symbol ?gnTextObjectId@* 0x007BF206
        return CUNIT_FindClientUnit(gnTextObjectId, 2);
    return 0;
}

// 0x0049E8F0
static int TEXT_FormatPartyEvent(Unicode* pOut, D2GSPacketSrv5A* pPacket)
{
    D2StoredUnitRecordStrc* pRecord = sub_00479BB0_FindRecord(pPacket->dwParam);
    Unicode wszName[16];
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    char szName[16];
    if (pRecord)
        strcpy(szName, ROSTER_GetEntryName(pRecord));
    else
        szName[0] = 0;
    sub_00526F20_ToUnicode(wszName, szName, 16);
    switch (pPacket->nParam)
    {
    case 1:
        sub_005269D0(0x132, pOut, D2LANG_GetStringFromTblIndex(0x277A), wszName);
        break;
    case 2:
        sub_005269D0(0x132, pOut, D2LANG_GetStringFromTblIndex(0x277B), wszName);
        break;
    case 3:
        sub_005267E0(pOut, wszName);
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0xFBA));
        sub_004B9A00(16, 0, 0, 0, 0);
        return 1;
    case 4:
        sub_005267E0(pOut, wszName);
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0xFBB));
        return 1;
    case 5:
        sub_005267E0(pOut, wszName);
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0xFBC));
        break;
    case 6:
        sub_005267E0(pOut, wszName);
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0xFBD));
        break;
    case 7:
        sub_005267E0(pOut, wszName);
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0xFBE));
        break;
    case 8:
        sub_005267E0(pOut, D2LANG_GetStringFromTblIndex(0xFBF));
        sub_00526700(pOut, wszName);
        break;
    case 9:
        sub_005267E0(pOut, wszName);
        sub_00526700(pOut, D2LANG_GetStringFromTblIndex(0xFC0));
        break;
    case 10:
        sub_005269D0(0x132, pOut, D2LANG_GetStringFromTblIndex(0x277C), wszName);
        break;
    case 11:
        sub_005269D0(0x132, pOut, D2LANG_GetStringFromTblIndex(0x277D), wszName);
        break;
    }
    if (pPlayer)
    {
        const int nPlayerId = pPlayer->dwUnitId;
        if (GFXUTIL_TestRelationFlags(nPlayerId, ROSTER_GetRecordUnitId(pRecord), 4))
            return 0;
    }
    return 1;
}

// build: symbol ??_FUnicode@@QAEXXZ 0x0042F530
// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x0049EB10
void __fastcall TEXT_HandleEventMessage(D2GSPacketSrv5A* pPacket)
{
    Unicode wszBuffer[0x132];
    Unicode wszName[16];
    Unicode wszName2[16];
    if (strlen(pPacket->szTextData[0]) >= 15)
        pPacket->szTextData[0][15] = 0;
    switch (pPacket->nType)
    {
    case 10:
        if (pPacket->szTextData[0][0])
        {
            sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
            sub_005267E0(wszBuffer, wszName);
            sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(0x1026));
            break;
        }
        sub_005267E0(wszBuffer, D2LANG_GetStringFromTblIndex(0x1027));
        break;
    case 16:
        sub_005267E0(wszBuffer, D2LANG_GetStringFromTblIndex(0x2A38));
        break;
    case 9:
        sub_005267E0(wszBuffer, D2LANG_GetStringFromTblIndex(0xFCF));
        break;
    case 8:
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        sub_005267E0(wszBuffer, wszName);
        sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(0xFCC));
        break;
    case 0:
        D2_ASSERT(sub_00526800(D2LANG_GetStringFromTblIndex(0xE37)) < 0x104, 0x114C);
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        sub_005267E0(wszBuffer, wszName);
        sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(0xE37));
        break;
    case 1:
        D2_ASSERT(sub_00526800(D2LANG_GetStringFromTblIndex(0xE38)) < 0x104, 0x1152);
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        sub_005267E0(wszBuffer, wszName);
        sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(0xE38));
        break;
    case 2:
        if (sub_00463DD0_GetPlayerUnit() && !strcmp(pPacket->szTextData[0], sub_0047A210(sub_00463DD0_GetPlayerUnit())))
            break;
        D2_ASSERT(sub_00526800(D2LANG_GetStringFromTblIndex(0xE39)) < 0x104, 0x115C);
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        if (strlen(pPacket->szTextData[1]))
        {
            Unicode wszAccount[16];
            sub_00526F20_ToUnicode(wszAccount, pPacket->szTextData[1], 16);
            sub_005269D0(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0xE3B), wszName, wszAccount);
            break;
        }
        sub_005269D0(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0xE39), wszName);
        break;
    case 3:
        D2_ASSERT(sub_00526800(D2LANG_GetStringFromTblIndex(0xE3A)) < 0x104, 0x116A);
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        if (strlen(pPacket->szTextData[1]))
        {
            Unicode wszAccount[16];
            sub_00526F20_ToUnicode(wszAccount, pPacket->szTextData[1], 16);
            sub_005269D0(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0xE3C), wszName, wszAccount);
            break;
        }
        sub_005269D0(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0xE3A), wszName);
        break;
    case 4:
        D2_ASSERT(sub_00526800(D2LANG_GetStringFromTblIndex(0xE3D)) < 0x104, 0x1178);
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        sub_005267E0(wszBuffer, wszName);
        sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(0xE3D));
        break;
    case 13:
        D2_ASSERT(sub_00526800(D2LANG_GetStringFromTblIndex(0xE44)) < 0x104, 0x117E);
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        sub_005267E0(wszBuffer, wszName);
        sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(0xE44));
        break;
    case 5:
        D2_ASSERT(sub_00526800(D2LANG_GetStringFromTblIndex(0xE3E)) < 0x104, 0x1184);
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        sub_005267E0(wszBuffer, wszName);
        sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(0xE3E));
        break;
    case 6:
    {
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        const Unicode* pKiller;
        int nStringId;
        int bFound = 0;
        switch (pPacket->nParam)
        {
        case 0:
            if (strlen(pPacket->szTextData[1]))
            {
                sub_00526F20_ToUnicode(wszName2, pPacket->szTextData[1], 16);
                nStringId = 0xE40;
                pKiller = wszName2;
                bFound = 1;
            }
            break;
        case 1:
            if (!pPacket->szTextData[1][0])
            {
                D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pPacket->dwParam);
                if (pMonStatsTxtRecord)
                {
                    nStringId = 0xE3F;
                    pKiller = D2LANG_GetStringFromTblIndex(pMonStatsTxtRecord->wNameStr);
                    bFound = 1;
                }
            }
            else
            {
                unsigned short wSuperUnique = *(unsigned short*)pPacket->szTextData[1];
                nStringId = 0xE40;
                D2SuperUniquesTxt* pSuperUniquesTxtRecord = DATATBLS_GetSuperUniquesTxtRecord(wSuperUnique);
                if (pSuperUniquesTxtRecord)
                {
                    pKiller = D2LANG_GetStringFromTblIndex(pSuperUniquesTxtRecord->wNameStr);
                    bFound = 1;
                }
            }
            break;
        case 2:
        {
            D2ObjectsTxt* pObjectsTxtRecord = DATATBLS_GetObjectsTxtRecord(pPacket->dwParam);
            if (pObjectsTxtRecord)
            {
                nStringId = 0xE3F;
                if (pPacket->dwParam == 11)
                    pKiller = D2LANG_GetStringFromTblIndex(0xC98);
                else
                    pKiller = (const Unicode*)pObjectsTxtRecord->wszName;
                bFound = 1;
            }
            break;
        }
        }
        if (!bFound)
        {
            sub_005267E0(wszBuffer, wszName);
            sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(0xE41));
            break;
        }
        if (sub_00526800(D2LANG_GetStringFromTblIndex(nStringId)) + sub_00526800(pKiller) + 16 >= 0x132)
            return;
        sub_005267E0(wszBuffer, wszName);
        sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(nStringId));
        sub_00526700(wszBuffer, pKiller);
        break;
    }
    case 7:
        if (TEXT_FormatPartyEvent(wszBuffer, pPacket))
            TEXT_PrintPartyText(wszBuffer, pPacket->nColor);
        return;
    case 11:
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        sub_005269D0(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0x69B), wszName);
        break;
    case 15:
        sub_005269D0(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0xE43), pPacket->dwParam);
        break;
    case 17:
        sub_005269D0(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0x2AFC), pPacket->dwParam);
        break;
    case 18:
        sub_005269D0(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0x2AFD));
        if (gpGlobal_007A0634)
            ENVIRONMENT_InitializeEnvironment(gpGlobal_007A0634, CUNIT_GetPlayerRoom(), 5, 0, 1);
        sub_00476A80_StartTiming(6, 0xFA0, 0x2710, 0xFA0);
        sub_004B9A00(0x1220, 0, 0, 0, 0);
        break;
    default:
        return;
    }
    TEXT_PrintChatLine(wszBuffer, pPacket->nColor);
}

// 0x0049F3D0
void __fastcall TEXT_FreeHoverText(D2HoverTextStrc* pHoverText)
{
    D2TextBoxStrc* pTextBox = CHAT_GetUsedFromHoverMsg(pHoverText);
    if (pTextBox)
    {
        TEXT_FreeTextBox(pTextBox);
        CHAT_SetUsedInHoverMsg(pHoverText, 0);
    }
    CHAT_FreeHoverMsg(0, pHoverText);
}

// 0x0049F410
static void __stdcall TEXT_SetHoverText(int nLangId, const char* szText, D2UnitStrc* pUnit)
{
    if (!pUnit)
        return;

    if (!strlen(szText))
    {
        if (pUnit->pHoverText)
            CHAT_FreeHoverMsg(0, pUnit->pHoverText);
        pUnit->pHoverText = 0;
        return;
    }

    D2HoverTextStrc* pHoverText = CHAT_AllocHoverMsg(0, szText, gnGameFrame);
    CHAT_SetLangIdInHoverMsg(pHoverText, nLangId);
    if (pUnit->pHoverText)
        CHAT_FreeHoverMsg(0, pUnit->pHoverText);
    pUnit->pHoverText = pHoverText;
}

// 0x0049F490
void __fastcall TEXT_HandleChatPacket(D2GSPacketSrv26* pPacket)
{
    if (pPacket->nUnitType == 0 && !ROSTER_IsNotSquelched(pPacket->dwUnitGUID))
        return;

    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->dwUnitGUID, pPacket->nUnitType);
    char szName[0x11] = { 0 };
    if ((pUnit && pUnit->dwUnitType == UNIT_PLAYER) || pPacket->szName[0])
    {
        if (pUnit)
            SStrCopy(szName, UNITS_GetPlayerName(pUnit), 0x11);
        else
            SStrCopy(szName, pPacket->szName, 0x11);

        if (IGNORELIST_GetOrCreateIgnoreList()->IGNORELIST_IsListed(szName))
            return;
        if (IGNORELIST_GetOrCreateIgnoreList()->sub_0060FC40_IsTextFiltered(pPacket->szMessage))
            return;
    }

    Unicode wszText[0x100];
    if (!TEXT_ConvertHoverText(pPacket->nLang, wszText, pPacket->szMessage))
        return;
    wszText[0xFF].wChar = 0;

    if (pPacket->nMessageType == 4)
    {
        sub_0049E3A0_ShowChatText(wszText, pPacket->nMessageColor);
        return;
    }

    Unicode wszA[0x264];
    Unicode wszB[0x264];
    Unicode wszC[0x10];
    if (pPacket->nMessageType == 6)
    {
        Unicode::win2Unicode(wszB, pPacket->szMessage, 0x100);
        Unicode::win2Unicode(wszC, pPacket->szName, 0x10);
        sub_005269D0(0x264, wszA, D2LANG_GetStringFromTblIndex(0xE4A), wszC, wszB);
        SCMD_StripColorCodes(wszA);
        sub_0049E3A0_ShowChatText(wszA, 2);
    }
    else if (pPacket->nMessageType == 2)
    {
        const int nNameLen = strlen(pPacket->szName);
        const int nTextLen = strlen(pPacket->szMessage);
        if (nNameLen >= 1 && nNameLen <= 15)
        {
            Unicode::win2Unicode(wszC, pPacket->szName, 0x10);
            sub_005267E0(wszA, wszC);
            Unicode::strcat(wszA, D2LANG_GetStringFromTblIndex(0xE46));
            sub_005267E0(wszB, wszText);
            Unicode::strcat(wszA, wszB);
            sub_0049E3A0_ShowChatText(wszA, 2);
            return;
        }
        if (nTextLen > 0x131)
            return;
        sub_005267E0(wszA, wszText);
        sub_0049E3A0_ShowChatText(wszA, 2);
    }
    else if (pPacket->nMessageType == 1)
    {
        if (pPacket->nUnitType == 0 || pPacket->nUnitType == 1)
        {
            sub_0049E3A0_ShowChatText(wszText, pPacket->nMessageColor);
            return;
        }
        const int nNameLen = strlen(pPacket->szName);
        const int nTextLen = strlen(pPacket->szMessage);
        if (nNameLen >= 1 && nNameLen <= 15)
        {
            Unicode wszD[0x10];
            Unicode::win2Unicode(wszD, pPacket->szName, 0x10);
            sub_005267E0(wszA, wszD);
            INV_PrefixColorCode(wszA, 4);
            sub_005267E0(wszB, D2LANG_GetStringFromTblIndex(0xFD0));
            Unicode::strcat(wszB, wszText);
            INV_PrefixColorCode(wszB, 0);
            Unicode::strcat(wszA, wszB);
            sub_0049E3A0_ShowChatText(wszA, pPacket->nMessageColor);
            return;
        }
        if (nTextLen > 0x131)
            return;
        sub_005267E0(wszA, wszText);
        sub_0049E3A0_ShowChatText(wszA, pPacket->nMessageColor);
    }
    else if (pPacket->nMessageType == 5)
    {
        if (pUnit)
            TEXT_SetHoverText(pPacket->nLang, pPacket->szMessage, pUnit);
    }
    else if (pPacket->nMessageType == 7)
    {
        Unicode wszE[0x100];
        MultiByteToWideChar(0, 1, pPacket->szMessage, 0x100, wszE, 0x100);
        const int nLang = pPacket->nLang;
        if (nLang != STRTABLE_GetLanguage())
        {
            for (Unicode* p = wszE; p->wChar; ++p)
                ;
        }
        INV_OpenRecipeScroll(wszE, nLang, pPacket->nMessageColor);
    }
}

// 0x0049F910
const Unicode* __fastcall TEXT_GetTextString(unsigned short nId)
{
    int nStart;
    int nEnd;
    if (gaTextIds[100].wId > nId)
    {
        nStart = 0;
        nEnd = 100;
    }
    else
    {
        nStart = 100;
        nEnd = gnTextIdCount;
    }
    for (int i = nStart; i < nEnd; ++i)
    {
        if (gaTextIds[i].wId == nId)
            return D2LANG_GetStringFromTblIndex(gaTextIds[i].wStringId);
    }
    return D2LANG_GetStringFromTblIndex(0xE8C);
}

// 0x0049F960
void __cdecl TEXT_ResetTextBox()
{
    SELECT_SetSelectionRect(0);
    if (gpTextBox)
    {
        TEXT_FreeTextBox(gpTextBox);
        gpTextBox = 0;
    }
    if (gnHintId)
    {
        const int nHint = sub_004B9610_FindHint(gnHintId);
        if (nHint)
            SOUNDINST_ArmHint(nHint, 0, 0, 4);
        gnHintId = 0;
    }
    ghHintSound = 0;
    if (gbTextHandlersRegistered == 1)
    {
        gbTextHandlersRegistered = 0;
        AUTOMAP_UnregisterHandlerTable(WINDOW_GetWindow(), gaTextMsgHandlers, 7);
    }
    if (gbTextSound)
    {
        MSG_SendTwoDwords(0x31, -1, gwTextStringId);
        gbTextSound = 0;
    }
}

// 0x0049FA10
void __cdecl TEXT_DrawPanelFrame()
{
    char szPath[0x104];
    D2CelContextStrc tContext;

    D2GFX_DrawBox(gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 0xE0, gnScreenWidth / 2, gnScreenHeight - 0x30, 0, 5);

    void* pCelFile = gpTextPanelFrameCel;
    if (!pCelFile)
    {
        wsprintfA(szPath, "%s\\UI\\MENU\\scroin", gszDataGlobal);
        pCelFile = ARCHIVE_LoadClientCellFile(szPath, 0);
        gpTextPanelFrameCel = pCelFile;
    }

    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = pCelFile;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    TEXTURE_CelDraw(&tContext, gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 0x6D, -1, 5, 0);
    tContext.nFrame = 1;
    TEXTURE_CelDraw(&tContext, gnPanelOffsetX + 0x100, gnScreenHeight + gnPanelOffsetY - 0x6D, -1, 5, 0);
    tContext.nFrame = 2;
    TEXTURE_CelDraw(&tContext, gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 0x31, -1, 5, 0);
    tContext.nFrame = 3;
    TEXTURE_CelDraw(&tContext, gnPanelOffsetX + 0x100, gnScreenHeight + gnPanelOffsetY - 0x31, -1, 5, 0);
    tContext.pCellFile = sub_00454600();
    tContext.nFrame = 10;
    TEXTURE_CelDraw(&tContext, gnPanelOffsetX + 0x115, gnScreenHeight + gnPanelOffsetY - 0x3D, -1, 5, 0);
}

// 0x0049FBA0
void __stdcall TEXT_OpenTextPanel(int bDraw)
{
    if (!sub_00463DD0_GetPlayerUnit())
    {
        return;
    }

    D2CelContextStrc tPiece;
    memset(&tPiece, 0, sizeof(tPiece));
    TEXT_DrawPanelFrame();

    if (!gpScroin2_007BF270)
    {
        char szPath[0x104] = { 0 };
        sprintf(szPath, "%s\\%s", "DATA\\GLOBAL", "UI\\menu\\scroin2");
        gpScroin2_007BF270 = ARCHIVE_LoadClientCellFile(szPath, 0);
    }

    if (!gpScroin3_007BF26C)
    {
        char szPath[0x104] = { 0 };
        sprintf(szPath, "%s\\%s", "DATA\\GLOBAL", "UI\\menu\\scroin3");
        gpScroin3_007BF26C = ARCHIVE_LoadClientCellFile(szPath, 0);
    }

    if (!bDraw)
    {
        return;
    }

    const int nOldMode = D2Win_10127_SetFont(5);
    tPiece.pCellFile = gpScroin2_007BF270;
    if (!gdwScrollTick)
    {
        gdwScrollTick = GetTickCount();
        gnScrollCounter = 0;
    }
    else if (gdwScrollTick + 50 < GetTickCount())
    {
        gdwScrollTick = GetTickCount();
        ++gnScrollCounter;
    }

    for (int i = 0; i < 5; ++i)
    {
        if (gnScrollCounter > gaScrollThresholds[i])
        {
            const int nTicks = gnScrollCounter - gaScrollThresholds[i];
            tPiece.nFrame = i;
            int nDrawMode = 5;
            if (nTicks == 1)
            {
                sub_004B9A00(0xA6F, 0, 0, 0, 0);
            }
            if (nTicks < 5)
            {
                nDrawMode = 0;
            }
            else if (nTicks < 10)
            {
                nDrawMode = 1;
            }
            else if (nTicks < 15)
            {
                nDrawMode = 2;
            }

            const unsigned short nSlot = gawScrollSlots[i];
            if (nSlot < 6)
            {
                D2_ASSERT(nSlot < 5, 0x1673);
                TEXTURE_CelDraw(&tPiece, gaScrollPiecePos[nSlot].nX + gnPanelOffsetX, gaScrollPiecePos[nSlot].nY - gnPanelOffsetY, -1, nDrawMode, 0);

                D2CelContextStrc tFade;
                memset(&tFade, 0, sizeof(tFade));
                tFade.pCellFile = gpScroin3_007BF26C;
                tFade.nFrame = nTicks >= 21 ? 0 : nTicks;
                TEXTURE_CelDraw(&tFade, gaScrollFadePos[nSlot].nX + gnPanelOffsetX, gaScrollFadePos[nSlot].nY - gnPanelOffsetY, -1, 3, 0);
            }
        }
    }

    D2Win_10127_SetFont(nOldMode);
}

extern "C" void __fastcall sub_00524280_InitializeDigest(unsigned int index)
{
    HashState* state = &gStates_00882760[index];
    state->a = 0x67452301u;
    state->b = 0xEFCDAB89u;
    state->c = 0x98BADCFEu;
    state->d = 0x10325476u;
    state->e = 0xC3D2E1F0u;
    state->lowCount = 0;
    state->highCount = 0;
}

// build: symbol ??0ListBoxWrapper@@QAE@HHHHHHHHH@Z 0x004BF8F0
// 0x0049FE10
void __cdecl TEXT_FreeTextPanelCels()
{
    if (gpScroin2Cel)
    {
        ARCHIVE_FreeClientCellFile(gpScroin2Cel);
        gpScroin2Cel = 0;
    }
    if (gpScroin3Cel)
    {
        ARCHIVE_FreeClientCellFile(gpScroin3Cel);
        gpScroin3Cel = 0;
    }
    if (gpTextPanelFrameCel)
    {
        ARCHIVE_FreeClientCellFile(gpTextPanelFrameCel);
        gpTextPanelFrameCel = 0;
    }
}

// 0x0049FE60
void __stdcall TEXT_CloseTextPanelMsg(SMSGHANDLER_PARAMS* pMsg)
{
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
    UI_SetUIVar(16, 2, 0);
    TEXT_FreeTextPanelCels();
}

// 0x0049FEA0
void __stdcall TEXT_PanelClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = (unsigned short)pMsg->lParam;
    int nY = (unsigned short)((unsigned int)pMsg->lParam >> 16);
    if (nY < gnScreenHeight - 0x30 && nX < gnScreenWidth / 2)
    {
        UI_SetUIVar(0x10, 2, 0);
        TEXT_FreeTextPanelCels();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        GAME_ResetMouseState();
    }
}

// 0x0049FF00
void __cdecl sub_0049FF00()
{
}

// 0x0049FF10
void __cdecl TEXT_DispatchTextData()
{
    if (!gpTextData)
        return;

    const int nTag = gpTextData->dwTag;
    if (nTag == 0x20736B62)
    {
        TEXT_OpenTextPanel(0);
        return;
    }
    if (nTag == 0x20646B62)
    {
        if (!gbTextDataOpen)
        {
            TEXT_OpenTextPanel(1);
            return;
        }
    }
    else if (nTag != 0x20317274)
    {
        return;
    }
    TEXT_DrawPanelFrame();
}

// 0x0049FF60
extern "C" void __fastcall TEXT_AcceptWordPacket(const PacketWords* packet)
{
    if (packet->kind == 4)
    {
        memcpy(gawScrollSlots, packet->wSlots, sizeof(gawScrollSlots));
        gValue_007BF254 = 0;
    }
}

// 0x0049FF90
void __fastcall TEXT_OpenTextData(D2UnitStrc* pUnit, D2ClientTextDataStrc* pTextData)
{
    gpTextData = pTextData;
    UI_SetUIVar(0x10, 2, 0);
    GAME_ResetMouseState();
    if (gpTextData->dwTag == 0x20646B62)
    {
        gbTextDataOpen = 1;
        MSG_SendDword(0x3E, !pUnit ? -1 : pUnit->dwUnitId);
        gnGlobal_007BF1E0 = 0;
    }
    else
    {
        gbTextDataOpen = 0;
        gnGlobal_007BF1E0 = 1;
    }
}

// 0x004A0030
int __cdecl TEXT_CloseMessageLogCallback()
{
    UI_SetUIVar(0x18, 1, 0);
    return 1;
}

// build: symbol ??1UIWidget@@UAE@XZ 0x004BE080
// 0x004A0050
void TEXT_OpenMessageLogDialog()
{
    if (gpListDialog)
    {
        return;
    }
    gpListDialog = DIALOG_CreateDialog(5, 0x1E, (int)TEXT_CloseMessageLogCallback, 0, 0, 0, 0,
        gnScreenWidth - 0x14, gnScreenHeight - 0x82, 0, 0);
    sub_004B8370_SetField5C(gpListDialog, 1);
    DIALOG_AddTextLine(gpListDialog, D2LANG_GetStringFromTblIndex(0xFC3), 0x15, 0, 4, 1, 0, 0);
    DIALOG_AddTextLine(gpListDialog, D2LANG_GetStringFromTblIndex(0x1030), gnScreenHeight - 0xA5, 0,
        0, 1, TEXT_CloseMessageLogCallback, 1);
    gpListBox = new ListBoxWrapper(5, 0x41, gnScreenWidth - 0x14, gnScreenHeight - 0xC8, 2, 0, 0xD, 0,
        1);
    if (gpListBox)
    {
        DIALOG_AddWidget(gpListDialog, gpListBox, 0x19, 0x1E);
        sub_0049E340();
        sub_004B82F0_Select(gpListDialog, -1);
    }
}

// 0x004A0200
void __fastcall TEXT_SetSpeechHoverText(D2UnitStrc* pUnit, int nStringId)
{
    char szText[12];

    if (!pUnit)
        return;

    const int nLangId = sub_00525150();
    if (nLangId < 6)
        return;
    if (nLangId > 7 && nLangId != 9)
        return;
    if (nStringId < 0xB76 || nStringId > 0x1230)
        return;

    const int nUnitType = !pUnit ? 6 : pUnit->dwUnitType;
    if (nUnitType == 0)
    {
        const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
        D2StringSoundStrc* pTable = gapClassStringSounds[nClassId];
        for (unsigned int i = 0; i < 0x4A; ++i)
        {
            if (pTable[i].wStringId == nStringId)
            {
                sprintf(szText, gszFormatSound, -1, -1, pTable[i].wSoundId);
                TEXT_SetHoverText(sub_00525150(), szText, pUnit);
                return;
            }
        }
    }
    else if (nUnitType == 1)
    {
        for (unsigned int i = 0; i < 6; ++i)
        {
            if (gaMonStringSounds[i].wStringId == nStringId)
            {
                sprintf(szText, gszFormatD, gaMonStringSounds[i].wSoundId);
                TEXT_SetHoverText(sub_00525150(), szText, pUnit);
                return;
            }
        }
    }
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

// 0x004A0320
D2SplittedTextStrc* __stdcall TEXT_BuildTextLines(const unsigned short* wszText, int* pLineCount, unsigned short* pMaxLines)
{
    Unicode szLine[100];
    const unsigned short* pText = wszText;

    *pLineCount = 0;
    D2SplittedTextStrc* pLast = 0;
    D2SplittedTextStrc* pFirst = 0;
    int bFirstLine = 1;
    while (*pText)
    {
        pText = TEXT_ReadLine(szLine, pText);

        D2SplittedTextStrc* pLine = (D2SplittedTextStrc*)FOG_Alloc(sizeof(D2SplittedTextStrc), ".\\UI\\text.cpp", 0x5B8, 0);
        if (bFirstLine == 1)
        {
            const int nLength = sub_00526800(szLine);
            int bAscii = 1;
            for (int j = 0; j < nLength; ++j)
            {
                if (szLine[j].wChar >= 0x80)
                {
                    bAscii = 0;
                }
            }

            if (bAscii)
            {
                char szNumber[100];
                sub_005263E0(szNumber, szLine, 100);
                *pMaxLines = atoi(szNumber);
            }
            else
            {
                char szMessage[80];
                wsprintfA(szMessage, "line 0 of string does not contain scroll rate");
                *pMaxLines = 8;
            }

            bFirstLine = 0;
            pText = TEXT_ReadLine(szLine, pText);
        }

        const int nLength = sub_00526800(szLine);
        if (D2Win_10121_GetTextWidth(szLine) >= 0x134)
        {
            char szMessage[80];
            wsprintfA(szMessage, "line %d of string is too long", *pLineCount);
        }

        pLine->wszLine = (Unicode*)FOG_Alloc(sizeof(Unicode) * (nLength + 1), ".\\UI\\text.cpp", 0x5EB, 0);
        sub_005267E0(pLine->wszLine, szLine);
        pLine->pNextLine = 0;
        if (pLast)
        {
            pLast->pNextLine = pLine;
        }
        else
        {
            pFirst = pLine;
        }
        ++*pLineCount;
        pLast = pLine;
    }
    return pFirst;
}

// 0x004A05E0
D2TextBoxStrc* __fastcall TEXT_CreateTextBox(const Unicode* wszText, int nMode)
{
    D2TextBoxStrc* pTextBox = (D2TextBoxStrc*)FOG_Alloc(sizeof(D2TextBoxStrc), ".\\UI\\text.cpp", 0x65D, 0);
    if (nMode == 3)
    {
        pTextBox->pFirst = D2WINFONT_SplitText(wszText, &pTextBox->nLines, 0xB4);
        TEXT_MeasureTextBox(pTextBox);
        return pTextBox;
    }

    const int nOldFont = D2Win_10127_SetFont(8);
    pTextBox->pFirst = TEXT_BuildTextLines(wszText, &pTextBox->nLines, &pTextBox->f_14);
    pTextBox->nWidth = 0x145;
    pTextBox->nHeight = 0x70;
    pTextBox->nField1A = 0;
    pTextBox->nField1E = 0;
    pTextBox->nField22 = 0;
    pTextBox->nField26 = 0;
    pTextBox->nField2A = 0;
    D2Win_10127_SetFont(nOldFont);
    TEXT_MeasureTextBox(pTextBox);
    return pTextBox;
}

// 0x004A0680
void __cdecl TEXT_FreeTextResources()
{
    if (gdwGlobal_007BF250)
    {
        TEXT_FreeTextHeader(gdwGlobal_007BF250);
        gdwGlobal_007BF250 = 0;
    }
    if (gpTextBox)
    {
        TEXT_FreeTextBox(gpTextBox);
        gpTextBox = 0;
    }
    if (gpMainTextBox)
    {
        TEXT_FreeTextBox(gpMainTextBox);
        FOG_Free(gpMainTextBox, ".\\UI\\text.cpp", 0x6E4, 0);
        gpMainTextBox = 0;
    }
    if (gpListDialog)
    {
        DIALOG_DestroyDialog(gpListDialog);
        gpListDialog = 0;
    }
    if (gpListBox)
    {
        delete gpListBox;
        gpListBox = 0;
    }
    TEXT_FreeTextPanelCels();
    SELECT_SetSelectionRect(0);
    TEXT_FreeTextList(&gtMessageTextList);
    TEXT_FreeTextList(&gtOverheadTextList);
    TEXT_FreeTextList(&gtTextHistory);
// build: symbol ?ghHintSound@* 0x007BF24B
    ghHintSound = 0;
}

// 0x004A0770
static int __stdcall TEXT_AdvanceTextBox(int bIgnore, D2TextBoxStrc* pTextBox)
{
    if (bIgnore)
    {
        pTextBox->nScroll = 2;
        return 0;
    }

    const int bBusy = D2SOUND_GetMasterVolumeOption();
    if (!gpHint_007BF24B || sub_004B95C0_IsHintPlaying(gpHint_007BF24B) || !bBusy)
    {
        gpHint_007BF24B = 0;
        if (sub_0049D5A0_UpdateTextBox(pTextBox))
        {
            gbTextBoxDone = 1;
            if (!gbHintActive_007BF20A && gpTextBox)
            {
                TEXT_FreeTextBox(gpTextBox);
                gpTextBox = 0;
                SELECT_SetSelectionRect(0);
            }

            TEXT_ResetTextBox();
            if (gpfnClose_007BF258)
            {
                return gpfnClose_007BF258(gpTextCallbackContext, 0, 0);
            }

            if (gnPending_007BF1C4 == 1)
            {
                gnPending_007BF1C4 = 0;
            }
            else if (gbHintActive_007BF20A)
            {
                NPCMENU_CancelNpcAndFlag(gpHint_007BF202);
            }

            UI_StartUIVarDelay();
            gbHintActive_007BF20A = 0;
            SELECT_SetSelectionRect(0);
            if (gbTextHandlersRegistered == 1)
            {
                gbTextHandlersRegistered = 0;
                AUTOMAP_UnregisterHandlerTable(WINDOW_GetWindow(), gaTextMsgHandlers, 7);
            }

            return 0;
        }
    }

    return 1;
}

// 0x004A0A00
static void __stdcall TEXT_ShowHoverText(const Unicode* wszText, D2UnitStrc* pUnit, D2HoverTextStrc* pHoverText, D2CoordStrc* pPos)
{
    if (gnGameFrame > CHAT_GetTimeoutFromHoverMsg(pHoverText))
    {
        CHAT_FreeHoverMsg(0, pHoverText);
        if (pUnit)
            pUnit->pHoverText = 0;
    }

    const int nOldFont = D2Win_10127_SetFont(0x0D);
    D2TextBoxStrc* pTextBox = (D2TextBoxStrc*)FOG_Alloc(sizeof(D2TextBoxStrc), ".\\UI\\text.cpp", 0x65D, 0);
    pTextBox->pFirst = D2WINFONT_SplitText(wszText, &pTextBox->nLines, 0xB4);
    TEXT_MeasureTextBox(pTextBox);

    pPos->nX -= pTextBox->nWidth >> 1;
    pPos->nY -= 0x32;
    pPos->nY = pPos->nY - pTextBox->nLines * 0x0F - 3;

    D2RectStrc tRect;
    tRect.nTop = pPos->nY;
    tRect.nLeft = pPos->nX;
    tRect.nBottom = pTextBox->nHeight + pPos->nY;
    tRect.nRight = pTextBox->nWidth + pPos->nX;
    if (gnHoverRectCount < 0x10 && !TEXT_PlaceHoverRect(gnHoverRectCount, &tRect))
    {
        TEXT_FreeTextBox(pTextBox);
        return;
    }

    ++gnHoverRectCount;
    TEXT_DrawTextBoxAt(pTextBox, &tRect);
    TEXT_FreeTextBox(pTextBox);
    D2Win_10127_SetFont(nOldFont);
}

// 0x004A0B30
void __fastcall TEXT_DrawUnitHoverText(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return;

    D2HoverTextStrc* pHoverText = pUnit->pHoverText;
    if (!pHoverText)
        return;

    D2CoordStrc tPos;
    UNITS_GetClientCoords(pUnit, &tPos);
    tPos.nY += -0x1E - gtHoverOffset.nTop;
    tPos.nX -= gtHoverOffset.nLeft;
    switch (sub_0045AE90())
    {
    case 1:
        tPos.nX -= gnScreenWidth / 4;
        break;
    case 2:
        tPos.nX += gnScreenWidth / 4;
        break;
    case 3:
        return;
    }

    if (tPos.nY <= 0 || tPos.nY >= gnScreenHeight)
        return;
    if (tPos.nX <= -0x64 || tPos.nX >= gnScreenWidth + 0x64)
        return;

    char szText[0x104];
    CHAT_CopyHoverMsgToBuffer(pHoverText, szText);
    if (szText[0] == -1 && szText[1] == -1)
    {
        const int nStringId = atoi(&szText[2]);
        if ((nStringId >= 0x42D && nStringId <= 0x50F) || (nStringId >= 0x5587 && nStringId <= 0x5615)
            || nStringId == 0x2AA4 || nStringId == 0x5586)
        {
            const Unicode* wszString = D2LANG_GetStringFromTblIndex(nStringId);
            if (wszString)
            {
                Unicode wszBuffer[0xC8];
                memset(wszBuffer, 0, sizeof(wszBuffer));
                int nLength = sub_00526800(wszString);
                if (nLength >= 0xC8)
                    nLength = 0xC7;
                sub_00526790(wszBuffer, wszString, nLength);
                TEXT_ShowHoverText(wszBuffer, pUnit, pHoverText, &tPos);
                return;
            }
        }
    }

    Unicode wszHover[0x100];
    if (!TEXT_ConvertHoverText(CHAT_GetLangIdFromHoverMsg(pHoverText), wszHover, szText))
        return;
    wszHover[0xFF].wChar = 0;
    TEXT_ShowHoverText(wszHover, pUnit, pHoverText, &tPos);
}

// 0x004A0D20
void __fastcall TEXT_DrawObjectHoverText(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return;

    D2HoverTextStrc* pHoverText = pUnit->pHoverText;
    if (!pHoverText)
        return;

    D2CoordStrc tPos;
    UNITS_GetClientCoords(pUnit, &tPos);
    tPos.nY += -0x0A - gtHoverOffset.nTop;
    tPos.nX -= gtHoverOffset.nLeft;
    switch (sub_0045AE90())
    {
    case 1:
        tPos.nX -= gnScreenWidth / 4;
        break;
    case 2:
        tPos.nX += gnScreenWidth / 4;
        break;
    case 3:
        return;
    }

    if (tPos.nY <= 0 || tPos.nY >= gnScreenHeight)
        return;
    if (tPos.nX <= -0x64 || tPos.nX >= gnScreenWidth + 0x64)
        return;

    char szText[0x100];
    CHAT_CopyHoverMsgToBuffer(pHoverText, szText);
    const int nStringId = atoi(szText);
    if (nStringId < 1 || nStringId > 0xFFFE)
        return;

    const Unicode* wszString = D2LANG_GetStringFromTblIndex(nStringId);
    if (!wszString)
        return;

    Unicode wszBuffer[0xC8];
    memset(wszBuffer, 0, sizeof(wszBuffer));
    int nLength = sub_00526800(wszString);
    if (nLength >= 0xC8)
        nLength = 0xC7;
    sub_00526790(wszBuffer, wszString, nLength);
    TEXT_ShowHoverText(wszBuffer, pUnit, pHoverText, &tPos);
}

// calling-convention shim (not game code)
static int __cdecl sub_0049D5A0_UpdateTextBox(D2TextBoxStrc* pTextBox)
{
    int nA = WINDOW_GetWindow();
    int nB = WINDOW_GetWindow();
    SELECT_SetSelectionRect((void*)nA);
    SELECT_SetSelectionRect((void*)nB);
    SELECT_SetSelectionRect((void*)nA);
    SELECT_SetSelectionRect((void*)nB);
    pTextBox->nScroll = 1;
    return *(char*)pTextBox;
}

// 0x004A0E70
void __fastcall TEXT_UpdateTexts(D2ViewStrc* pView)
{
    D2RectStrc tViewRect;
    D2CoordStrc tViewPos;

    ++gnGameFrame;
    int nResult = 0;
    sub_00476070_GetViewRect(pView, &tViewRect.nLeft, &tViewRect.nTop, &tViewRect.nRight, &tViewRect.nBottom);
    VIEW_GetViewOffset(pView, &tViewPos.nX, &tViewPos.nY);
    SetRect(&gtHoverOffset, tViewPos.nX, tViewPos.nY, tViewPos.nX + tViewRect.nRight - tViewRect.nLeft, tViewPos.nY + tViewRect.nBottom - tViewRect.nTop);

    if (gnTextActive == 1)
    {
        gaHoverRects[0].nLeft = gnTextLeft;
        gaHoverRects[0].nRight = gnTextLeft + 0x145;
// build: symbol ?gnTextTop@* 0x007225FC
        gaHoverRects[0].nTop = gnTextTop;
        gnHoverRectCount = 1;
        gaHoverRects[0].nBottom = gnTextTop + 0x70;
    }
    else
    {
        gnHoverRectCount = 0;
    }

    CUNIT_ForEachPlayer(TEXT_DrawUnitHoverText);
    CUNIT_ForEachMonster(TEXT_DrawObjectHoverText);
    CUNIT_ForEachObject(TEXT_DrawObjectHoverText);

    if (gnTextActive == 1 && gpTextBox && (gpTextBox->nScroll == 1 || !gpTextBox->nScroll))
    {
        nResult = TEXT_AdvanceTextBox(gbTextBoxDone, gpTextBox);

        D2UnitStrc* pUnit = 0;
        if (gbTextFromObject)
        {
            pUnit = CUNIT_FindClientUnit(gnTextNpcId, 1);
        }

        if (CUNIT_IsPlayerDeadOrMissing() || (gbTextFromObject && pUnit && pUnit->dwAnimMode == 0x0C))
        {
            if (gbTextFromObject)
            {
                MSG_SendTwoDwords(0x30, 1, gnTextNpcId);
                NPCMENU_ClearNpcInventoryAndSound(gnTextNpcId);
            }

            TEXT_CloseTextUnit();
            if (gbTextHandlersRegistered == 1)
            {
                gbTextHandlersRegistered = 0;
                AUTOMAP_UnregisterHandlerTable(WINDOW_GetWindow(), gaTextMsgHandlers, 7);
            }
        }
    }

    if (gbTextBoxPending)
    {
        gbTextBoxShown ? (void)0 : (FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0xD02), exit(-1));
        int nDrawn = 1;
        (gdwTextEndTick < GetTickCount()) ? (void)(nDrawn = 0) : (void)TEXT_DrawTextBoxAt(gpMainTextBox, &gtTextRect_007BF1D0);
        if (!nDrawn)
        {
            TEXT_FreeMainTextBox();
            gbTextBoxPending = 0;
            gbTextFromObject = 0;
        }
        nResult += nDrawn;
    }

    if (!nResult && gnTextActive == 1)
    {
// build: symbol ?gbTextPanelOpen@* 0x007BF1FA
        gbTextPanelOpen = 0;
        gbTextFromObject = 0;
        gbTextBoxDone = 1;
        gnTextActive = 0;
        if (gbTextHandlersRegistered == 1)
        {
            gbTextHandlersRegistered = 0;
            AUTOMAP_UnregisterHandlerTable(WINDOW_GetWindow(), gaTextMsgHandlers, 7);
        }
    }

    gbTextBoxDone = 0;
    if (!GAME_GetUIVarState(0x18))
    {
        TEXT_DrawMessageList();
        TEXT_DrawOverheadTextList();
    }

    if (gpListDialog)
    {
        DIALOG_DrawDialog(gpListDialog);
    }
}

// 0x004A1510
void __fastcall TEXT_ShowTextBox(unsigned short nStringId)
{
    if (gpMainTextBox)
    {
        TEXT_FreeTextBox(gpMainTextBox);
        gpMainTextBox = 0;
    }

    const Unicode* wszText = D2LANG_GetStringFromTblIndex(nStringId);
    const int nOldFont = D2Win_10127_SetFont(0x0D);
    gpMainTextBox = TEXT_CreateTextBox(wszText, 3);
    D2Win_10127_SetFont(nOldFont);
    if (gpMainTextBox)
    {
        gpMainTextBox->nScroll = 1;
        gdwTextEndTick = GetTickCount() + (sub_00526800(wszText) + 0x19) * 0xC8;
        gbTextBoxShown = 1;
// build: symbol ?gbTextBoxPending@* 0x007BF1C4
        gbTextBoxPending = 1;
        gnTextBoxY = 0x64 - (gpMainTextBox->nHeight >> 2);
        gnTextBoxX = 0x140 - (gpMainTextBox->nWidth >> 1);
    }
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

// 0x004A1600
void __fastcall TEXT_HandleNpcTextPacket(D2HoverTextPacketStrc* pPacket)
{
    if (pPacket->nType == 1)
    {
        D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->dwUnitId, 1);
        if (pUnit && pPacket->nArg == 1 && pPacket->nMode == 3)
        {
            if (pUnit->pHoverText)
            {
                CHAT_FreeHoverMsg(0, pUnit->pHoverText);
            }

            char szText[20];
            sprintf(szText, gszFormatD, pPacket->wStringId);
            pUnit->pHoverText = CHAT_AllocHoverMsg(0, szText, gnGameFrame);
            return;
        }

        if (gpTextHeader)
        {
            TEXT_FreeTextHeader(gpTextHeader);
        }

        gpTextHeader = TEXT_AllocTextHeader(0);
        TEXT_CreateTextHeaderFromMessageList(gpTextHeader, (D2MessageListStrc*)&pPacket->nArg);
        TEXT_SortTextNodeListByStringId(gpTextHeader);
    }
    else if (pPacket->nType == 2)
    {
        D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->dwUnitId, 2);
        if (pPacket->nMode == 3)
        {
            TEXT_ShowTextBox(pPacket->wStringId);
            return;
        }

        gwTextPanelClassId = 0;
// build: symbol ?gnTextObjectId@* 0x007BF206
        gnTextObjectId = pPacket->dwUnitId;
        if (pUnit)
        {
            gwTextPanelClassId = UNITS_GetWeaponClass(pUnit);
        }
        WARDENCLIENT_OpenTextPanel(pPacket->wStringId, 0, 1);
    }
    else
    {
        TEXT_FreeTextHeader(gpTextHeader);
        gpTextHeader = 0;
    }
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

// 0x004A1730
void __cdecl TEXT_ClearTextPanel()
{
    TEXT_ResetTextBox();
// build: symbol ?gbTextPanelOpen@* 0x007BF1FA
    gbTextPanelOpen = 0;
    if (gpTextHeader)
    {
        TEXT_FreeTextHeader(gpTextHeader);
        gpTextHeader = 0;
    }
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
void __cdecl QUESTLOG_LoadQuestPanelCels(); // 0x004A23D0

extern "C" { unsigned int gValue_007BF2A8; } // 0x007BF2A8


// build: symbol ?TEXT_FindQuestIndex@* 0x004A1910
int TEXT_FindQuestIndex(int nKey)
{
    for (int i = 0; i < 41; i++)
    {
        if (gaQuestLookup[i].nKey == nKey)
            return i;
    }
    return -1;
}

// build: symbol ?SCMD_HandleQuestEvent@* 0x0045E540
void __fastcall SCMD_HandleQuestEvent(const D2PacketRecord6Strc* pPacket)
{
    D2PacketRecord6Strc tPacket = *pPacket;
    TEXT_HandleQuestEvent(1, &tPacket);
}

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

void __fastcall QUESTLOG_ToggleQuestLog(int nMode); // 0x004A3FE0


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








static int __stdcall sub_E10_IsAbovePanelLineCopy(int nY)
{
    int nHalf = (gnScreenWidth - 620) / 2;
    return nY < nHalf + (gnScreenWidth - nHalf * 2 - 49) / 3 * 2 + 18;
}













// build: symbol ?EXCEPTIONS_ReleaseAllSymbols@* 0x0040D530
int __cdecl EXCEPTIONS_ReleaseAllSymbols()
{
    return EXCEPTIONS_ReleaseSymbols(1);
}









int __fastcall AITHINK_BaalThroneCheckAiParamFlag(D2AiTickParamStrc* pAiTickParam, int nFlag)
{
    return pAiTickParam->pAiControl->dwAiParam[1] & nFlag;
}







int __fastcall CMDTBL_QueryKey(int nId, int nMode, int nCommand, unsigned short* pKey);               // 0x00469C20

void __stdcall TEXT_UnregisterKeyConfigHandlers(int bReset);                                                // 0x004A5D70












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





// 0x004ED3F0
void __stdcall TEXT_DrawHintText(int nArg1, int nStringIndex)
{
    Unicode wszText[100];
    sub_005269D0(100, wszText, D2LANG_GetStringFromTblIndex(0x1058), nArg1);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nStringIndex));
    D2Win_10129_DrawFramedText(wszText, gnScreenWidth - 0x80, gnScreenHeight - 0x34, 0, 1);
}

#include "gen/data/Source/D2Client/UI/text.inc"
