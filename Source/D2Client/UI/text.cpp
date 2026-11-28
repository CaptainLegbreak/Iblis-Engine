#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2ClientTextState.h"
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
#include "FogApi.h"
#include "StormApi.h"
#include "D2CommonApi.h"
#include "D2LangApi.h"
#include "FogApi.h"
#include "StormApi.h"
#include "D2GfxApi.h"
#include "D2CMPApi.h"
#include "D2SoundApi.h"
#include "StormApi2.h"
#include "D2WinApi2.h"

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




void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0


void __cdecl INV_SetupPanelButtons(); // 0x00487ED0


#include "D2PanelTab.h"
extern D2PanelTabStrc gaNpcTabs[]; // 0x00722110


extern int gbNpcTradeClicked; // 0x007BCBEC




extern int gbInvGoldButtonDown; // 0x007BCE30

extern int gnPetIconPopupState; // 0x007BEECC







void __fastcall AUTOMAP_UnregisterHandlerTable(void* hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10

void __fastcall SCMD_RegisterMsgHandlers(void* hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0

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


Unicode* __fastcall INV_PrefixColorCode(Unicode* pText, int nDigit); // 0x004521C0

Unicode* __fastcall SCMD_StripColorCodes(Unicode* pText); // 0x00452300


void __fastcall INV_OpenRecipeScroll(const Unicode* wszName, int nUnused, int nArg); // 0x0048BBE0

void __fastcall TEXT_PrintChatLine(const Unicode* wszText, char nColor); // 0x0049E3A0


Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource); // 0x005267E0


char* __stdcall UNITS_GetPlayerName(D2UnitStrc* pUnit); // 0x00622150



static bool TEXT_IsLanguageCompatible(int nLangId);


class D2ListBoxViewStrc
{
public:
    virtual ~D2ListBoxViewStrc();
};




void __stdcall TEXT_FreeTextList(D2TextPanelListStrc* pList); // 0x0049D4D0


D2SplittedTextStrc* __stdcall TEXT_BuildTextLines(const Unicode* wszText, int* pLineCount, unsigned short* pMaxLines); // 0x004A0320


void __fastcall SOUNDINST_ArmHint(int nKey, int nGroup, int nOffset, unsigned int nCount); // 0x004B9EF0

int __fastcall UNICODE_StrLen(const Unicode* pString); // 0x00526800

D2TextBoxStrc* __stdcall CHAT_GetUsedFromHoverMsg(D2HoverTextStrc* pHoverMsg); // 0x00661200


void __stdcall TEXT_FreeTextHeader(int nHandle); // 0x006612A0

unsigned long gdwTextEndTick; // 0x007BF1AC

D2ClientDialogStrc* gpListDialog; // 0x007BF1B0

class UIWidget
{
public:
    static void* operator new(size_t nSize)
    {
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
    virtual void sub_004BEDE0_ForwardSlot3C(const Unicode* wszText0, const Unicode* wszText1,
        const Unicode* wszText2, const Unicode* wszText3, const Unicode* wszText4, const Unicode* wszText5,
        int nEntryData, int nColor, int bUseDefault, int nFont);
    virtual int sub_004BEDF0_ForwardGetEntryData(int nIndex);
    virtual int sub_004BEE00_Slot14();
    virtual void sub_004BEE10_Slot15();

    ListBoxImplementation* pImpl;
};



D2ClientTextStateStrc gtTextState; // 0x007BF1E4


void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00



void __cdecl GAME_ResetMouseState(); // 0x0044DA40


void __stdcall TEXT_OpenTextPanel(int bFlag); // 0x0049FBA0



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

struct PayloadView;

struct UnitView
{
    unsigned int type;
    int classId;
    char unused8[0xC];
    PayloadView* payload;
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

extern "C" ByteRecord* sgptSoundHeaderTable;

extern "C" int gRecordCount_007BC9A4;

extern "C" unsigned int gValue_007BF254; // 0x007BF254



extern "C" HashState gatBnHashCtx[];

extern "C" ClassTableView* gClassTable_00744304;

static bool TEXT_ConvertHoverText(int nLangId, Unicode* wszText, const char* szText); // 0x0049E280

static void __stdcall TEXT_SetHoverText(int nLangId, const char* szText, D2UnitStrc* pUnit); // 0x0049F410


void __fastcall DIALOG_AddWidget(D2ClientDialogStrc* pDialog, void* pWidget, int nArg8, int nArgC); // 0x004B7C00

D2ClientDialogStrc* __fastcall DIALOG_CreateDialog(int nArg1, int nArg2, int nArg8, int nArgC, int nArg10, int nArg14,
    int nArg18, int nArg1C, int nArg20, int nArg24, int nArg28); // 0x004B7EB0


void __fastcall ROSTER_SetCtrlState(D2ClientDialogStrc* pDialog, int nValue); // 0x004B8370

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



D2TextBoxStrc* gpTextBox; // 0x007BF0A4

D2TextBoxStrc* gpMainTextBox; // 0x007BF1A8

int gnTextBoxX; // 0x007BF1D0

int gnTextBoxY; // 0x007BF1D4


void* gpScroin3Cel; // 0x007BF26C

void* gpScroin2Cel; // 0x007BF270

void* gpTextPanelFrameCel; // 0x007BF274

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2TextNodeStrc;

struct D2RectStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837



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


Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount); // 0x00526790


D2TextNodeStrc* __fastcall TEXT_CloneStringList(D2TextNodeStrc* pSource); // 0x0049DB10




extern "C" __declspec(dllimport) int __stdcall IntersectRect(D2RectStrc* pDest, const D2RectStrc* pSrc1, const D2RectStrc* pSrc2); // 0x006CC4C4

extern "C" int __cdecl atoi(const char* szString); // 0x00681EBB



void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20




extern "C" const char gszTextSourceFile[]; // 0x006DA13C

extern int gaHoverDirs[]; // 0x00722654

extern int gnHoverDirCount; // 0x00722674

D2RectStrc gaHoverRects[16]; // 0x007BF0A8



bool __stdcall TEXT_PlaceHoverRect(int nCount, D2RectStrc* pRect); // 0x0049E070


struct D2CelFileStrc;



extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD


D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0

extern D2ScrollPosStrc gaScrollPiecePos[5]; // 0x00722EB8

extern D2ScrollPosStrc gaScrollFadePos[5]; // 0x00722EE0

extern unsigned int gaScrollThresholds[5]; // 0x00722F08

extern "C" { unsigned short gawScrollSlots[6]; } // 0x007BF098



extern D2CelFileStrc* gpScroin3_007BF26C; // 0x007BF26C

extern D2CelFileStrc* gpScroin2_007BF270; // 0x007BF270

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szDest, const char* szFormat, ...); // 0x006CC468


int __cdecl sub_00525150();

#define UNIT_PLAYER 0

#define STAT_LEVEL 12

struct D2SliderButtonStrc;




struct D2QuestSlotRectStrc;

struct D2AiControlStrc;

struct D2AiTickParamStrc;

struct D2CharStatsTxt;

struct D2MonStatsTxt;







void __stdcall TEXT_LoadQuestPage(int nPage, int nArg);


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


#pragma pack(pop)




extern D2SliderButtonStrc gaKeyConfigButtons[3]; // 0x007246D8

int gaPressed[7]; // 0x007C0288





void __fastcall TEXT_SetTextCallback(D2TextCallback pfnCallback, void* pContext); // 0x0049E7E0


extern D2QuestSlotRectStrc gaQuestSlots[]; // 0x00723EB0











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


extern "C" void __cdecl GAME_UnregisterMouseHandlers(); // 0x0044DCE0

extern "C" void __cdecl GAME_RegisterMouseHandlers(); // 0x0044DD20





extern int gbRedraw; // 0x007C0280





int __stdcall sub_B05_Sink(int nA, int nB);



extern "C" void __cdecl sub_00517ABB(void* pMemory); // 0x00517ABB


extern "C" int __stdcall sub_00420290_HandleMsg(void* pMessage); // 0x00420290

extern D2MsgHandlerEntryStrc gaKeyCaptureMButtonHandlers[]; // 0x0072472C

extern D2MsgHandlerEntryStrc gaKeyCaptureHandlers[]; // 0x00724738

extern D2MsgHandlerEntryStrc gaKeyCaptureXButtonHandlers[]; // 0x00724780

extern D2MsgHandlerEntryStrc gaKeyCaptureWheelHandlers[]; // 0x0072478C

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480



int __cdecl GAME_GetLadderFlag(); // 0x0044DCA0

static int TEXT_GetKeyConfigButtonAt(int nX, int nY);














D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80



int __stdcall COMPOSIT_GetWeaponClassId(D2UnitStrc* pUnit, D2InventoryStrc* pInventory, int* pWeaponClassId, int nAnimMode, int bUseConvertedMode); // 0x0064F380


#define STAT_STATPTS 4

#define STAT_NEWSKILLS 5






enum { REPEAT_MASK = 0x40000000, UI_VARIABLE = 11 };




int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x006253B0

extern "C" int gnFlag_007C02EC; // 0x007C02EC

void __stdcall CURSOR_HandleButtonUp(SMSGHANDLER_PARAMS* pMsg); // 0x00467FA0



int gbSkillButtonPressed; // 0x007C02E8

void __fastcall TEXT_MoveKeyConfigSelection(int nStep);




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




#include "D2WaypointLayout.h"
#include "D2GameApi.h"
extern D2WaypointLayoutStrc gaLayouts[9]; // 0x007224E8


static bool gbWaypointClosePressed;                                                                        // 0x007BF06C

static int gnWaypointSelected;                                                                       // 0x007BF06D

char gbSent; // 0x007BF085



int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00

typedef void (__fastcall* UNITFN)(D2UnitStrc* pUnit);



extern "C" void __cdecl GAME_ConfigureEnvironmentOrDefer(); // 0x0044C820






void __fastcall CUNIT_ForEachMonster(UNITFN pfnCallback); // 0x00464990



void __cdecl INV_StopCinematic(); // 0x00483300

void __cdecl INV_ChainCinematic(); // 0x00483340




D2BitBufferStrc* __cdecl MONSTER_GetQuestFlags(); // 0x004B32D0


static int TEXT_FindQuestIndex(int nKey);

int gaQuestPageDefault[5]; // 0x007BF280

struct D2StringSoundStrc;




extern D2MsgHandlerEntryStrc gaDialogWheelHandlers[]; // 0x007273E4

extern D2MsgHandlerEntryStrc gaDialogHandlers[]; // 0x007273F0

extern const char* gaszDialogCels[]; // 0x007274AC

extern void* gpWaypointBackgroundCel; // 0x007BF071

extern void* gpWaypointActTabsCel; // 0x007BF075

extern void* gpWaypointIconCel; // 0x007BF079

extern void* gpGlobal_007C0D43; // 0x007C0D43







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


static int gnDialogHandlerRegCount; // 0x007C0E4C

static D2ClientDialogStrc* gpDialogList; // 0x007C0E54

static int gbDialogHandlersRegistered; // 0x007C0E58

static int gnDialogCount; // 0x007C0E5C




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


Unicode* __fastcall sub_00526700(Unicode* pDst, const Unicode* pSrc); // 0x00526700


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

void __fastcall TEXT_PrintPartyText(const Unicode* wszText, char nColor); // 0x0049E5C0


D2SuperUniquesTxt* __stdcall DATATBLS_GetSuperUniquesTxtRecord(int nSuperUniqueId); // 0x006556E0

extern D2DrlgActStrc* gpGlobal_007A0634; // 0x007A0634

static int TEXT_FormatPartyEvent(Unicode* pOut, D2GSPacketSrv5A* pPacket); // 0x0049E8F0

void __fastcall TEXT_PrintChatLine(const Unicode* wszText, char nColor); // 0x0049E3A0


extern "C" __declspec(dllimport) int __stdcall SetRect(D2RectStrc* pRect, int nLeft, int nTop, int nRight, int nBottom);


void __fastcall CUNIT_ForEachPlayer(UNITFN pfnCallback); // 0x00464950

void __fastcall CUNIT_ForEachObject(UNITFN pfnCallback); // 0x004649D0

void __fastcall sub_00476070_GetViewRect(D2ViewStrc* pView, int* pLeft, int* pTop, int* pRight, int* pBottom); // 0x00476070


// noinline: the original calls this; without it the compiler expands it into 0x004A0770.
static __declspec(noinline) int __cdecl sub_0049D5A0_UpdateTextBox(D2TextBoxStrc* pTextBox);


void __cdecl TEXT_DrawOverheadTextList(); // 0x0049DEE0





extern "C" void __fastcall NPCMENU_ClearNpcInventoryAndSound(int nUnitId); // 0x004B3830

void __fastcall DIALOG_DrawDialog(D2ClientDialogStrc* pDialog); // 0x004B8100

extern D2RectStrc gtTextRect_007BF1D0; // 0x007BF1D0

D2TextCallback gpfnTextCallback; // 0x007BF258



static int __stdcall TEXT_AdvanceTextBox(int bIgnore, D2TextBoxStrc* pTextBox); // 0x004A0770

int gnTradePartnerUnitId; // 0x007C0E60

inline void* operator new(unsigned int, void* pWhere) { return pWhere; }

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







static int TEXT_GetKeyConfigEntryState(int nIndex, int nFlag);





extern D2TextCallback gpfnTextCallback; // 0x007BF258

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



void __stdcall TEXT_CreateTextHeaderFromMessageList(D2TextHeaderStrc* pTextHeader, D2MessageListStrc* pMessageList); // 0x00661510




extern D2QuestTextsStrc gtQuestTextsSevenTombs; // 0x00723A64

extern D2QuestTextsStrc gtQuestTextsFallenAngel; // 0x00723C64

extern D2QuestTextsStrc gtQuestTextsSiege; // 0x00723D24

extern D2QuestPageRangeStrc gaQuestPageRanges[]; // 0x00723F08




static void TEXT_BuildQuestText(D2QuestTextMsgStrc* pMsg); // 0x004A1950



extern D2QuestPosStrc gaQuestPos[]; // 0x00723EA8








D2TextHeaderStrc* gpTextHeader; // 0x007BF250




extern D2ClientListEntryStrc gaKeyConfigEntries[]; // 0x00724268

extern D2ClientListEntryStrc gaKeyConfigEntriesExp[]; // 0x00724468

static int TEXT_GetWeaponBlock(D2UnitStrc* pUnit); // 0x004A70C0

static int TEXT_AddToHitFactor(D2UnitStrc* pUnit, int nAttackRate); // 0x004A7300

static void TEXT_SetQuestPage(int nPageArg); // 0x004A2220


void __stdcall TEXT_QuestLButtonDownMsg(SMSGHANDLER_PARAMS* pMsg);


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



extern D2QuestTableStrc gaQuestTable[41]; // 0x00723F30




Unicode* __fastcall strncpy(Unicode* pDest, const Unicode* pSource, int nCount); // 0x00526790


static void TEXT_FreeTextNode(D2TextNodeStrc* pNode); // 0x0049D490





struct D2ClientTextBoxStrc;
struct D2HoverClearPacketStrc;
#pragma pack(push, 2)
#pragma pack(pop)
#pragma pack(push, 1)
struct D2HoverClearPacketStrc
{
    unsigned char nHeader;
    unsigned char nUnitType;
    int dwUnitId;
};
#pragma pack(pop)
void __fastcall sub_00451E10_RegisterHandlerTable(void* hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10

int gbTextBoxShown; // 0x007BF1C8


int gbTextDataOpen; // 0x007BF254

void* gpTextCallbackContext; // 0x007BF25C


bool __stdcall sub_004A2970(int nX, int nY); // 0x004A2970

int __stdcall sub_004F6480(D2GfxDataStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480



#define SOUND_ID 4
ListBoxWrapper* gpListBox; // 0x007BF1B4

#define FIELD_OFFSET(T, F) ((unsigned long)&(((T*)0)->F))
#pragma pack(push, 2)
struct PackedNode
{
    char unused0[0x1e];
    int value;
    PackedNode* next;
};
#pragma pack(pop)
typedef char PackedNode_value_offset[(FIELD_OFFSET(PackedNode,value)==0x1e)?1:-1];
typedef char PackedNode_next_offset[(FIELD_OFFSET(PackedNode,next)==0x22)?1:-1];
typedef char PackedNode_size[(sizeof(PackedNode)==0x26)?1:-1];









struct SearchRecord
{
    char unused0[2];
    unsigned char value;
    unsigned char destination;
    char unused4[4];
    int key;
    char unusedC[0x4];
};
typedef char SearchRecord_size[(sizeof(SearchRecord)==0x10)?1:-1];
typedef char SearchRecord_key_offset[(FIELD_OFFSET(SearchRecord,key)==8)?1:-1];
typedef char SearchRecord_value_offset[(FIELD_OFFSET(SearchRecord,value)==2)?1:-1];
typedef char SearchRecord_destination_offset[(FIELD_OFFSET(SearchRecord,destination)==3)?1:-1];
extern "C" SearchRecord gSearch_00723F30[41];
struct OutputRecord
{
    char opaque[0x120];
};
struct InputRecord
{
    char unused0[0x12c];
    short value;
    char unusedAfterValue[0x66];
    short outputIndex;
    char unusedTail[0xa6];
};
struct TablesView
{
    char unused0[0xb8c];
    OutputRecord* outputs;
    int unusedBetweenOutputs;
    int outputCount;
    InputRecord* inputs;
    int unusedBetweenInputs;
    int inputCount;
};
typedef char OutputRecord_size[(sizeof(OutputRecord)==0x120)?1:-1];
typedef char InputRecord_size[(sizeof(InputRecord)==0x23c)?1:-1];
typedef char InputRecord_value_offset[(FIELD_OFFSET(InputRecord,value)==0x12c)?1:-1];
typedef char InputRecord_index_offset[(FIELD_OFFSET(InputRecord,outputIndex)==0x194)?1:-1];
typedef char TablesView_size[(sizeof(TablesView)==0xba4)?1:-1];
typedef char TablesView_outputs_offset[(FIELD_OFFSET(TablesView,outputs)==0xb8c)?1:-1];
typedef char TablesView_outputCount_offset[(FIELD_OFFSET(TablesView,outputCount)==0xb94)?1:-1];
typedef char TablesView_inputs_offset[(FIELD_OFFSET(TablesView,inputs)==0xb98)?1:-1];
typedef char TablesView_inputCount_offset[(FIELD_OFFSET(TablesView,inputCount)==0xba0)?1:-1];
extern "C" TablesView* gTables_00744304;
struct PayloadView
{
    char unused0[0x16];
    unsigned short flags;
    char unusedAfterFlags[4];
    unsigned char modifiers[10];
    short value26;
};
typedef char PayloadView_size[(sizeof(PayloadView)==0x28)?1:-1];
typedef char PayloadView_flags_offset[(FIELD_OFFSET(PayloadView,flags)==0x16)?1:-1];
typedef char PayloadView_modifiers_offset[(FIELD_OFFSET(PayloadView,modifiers)==0x1c)?1:-1];
typedef char PayloadView_value_offset[(FIELD_OFFSET(PayloadView,value26)==0x26)?1:-1];
typedef char UnitView_size[(sizeof(UnitView)==0x18)?1:-1];
typedef char UnitView_payload_offset[(FIELD_OFFSET(UnitView,payload)==0x14)?1:-1];
struct D2ButtonLayoutStrc;
union D2SeedStrc;
int __cdecl GAME_IsExpansion(); // 0x0044DCC0











extern D2ButtonLayoutStrc gaButtonLayouts[]; // 0x007241C0

typedef void (__stdcall* B27RecordHandler)(int, int, int);
typedef int (__cdecl* B27UIAction)();
extern "C" int __cdecl NPCMENU_ResurrectMercWait(); // 0x004B1DD0

extern "C" int __cdecl NPCMENU_IdentifyItemsWait(); // 0x004B2020

extern "C" unsigned int gnImbueMenuState;
extern "C" unsigned short gB27_00726CCB;
extern "C" unsigned int gB27_00726CDB;
extern "C" unsigned int gnHireMenuState;
extern "C" unsigned short gB27_00726E01;
extern "C" unsigned int gB27_00726E0F;
extern "C" unsigned int gnTravelLutGholeinState;
extern "C" unsigned short gB27_00726E4F;
extern "C" unsigned int gB27_00726E5D;
extern "C" unsigned int gnTravelKurastDocksState;
extern "C" unsigned short gB27_00726E9D;
extern "C" unsigned int gB27_00726EAB;
extern "C" unsigned int gnIdentifyMenu1State;
extern "C" unsigned short gwIdentifyMenu1StringId;
extern "C" B27UIAction gpfnIdentifyMenu1Handler;
extern "C" unsigned int gnIdentifyMenu2State;
extern "C" unsigned short gwIdentifyMenu2StringId;
extern "C" B27UIAction gpfnIdentifyMenu2Handler;
extern "C" unsigned int gnIdentifyMenu3State;
extern "C" unsigned short gwIdentifyMenu3StringId;
extern "C" B27UIAction gpfnIdentifyMenu3Handler;
extern "C" unsigned int gnIdentifyMenu4State;
extern "C" unsigned short gwIdentifyMenu4StringId;
extern "C" B27UIAction gpfnIdentifyMenu4Handler;
extern "C" unsigned int gnTravelHarrogathState;
extern "C" unsigned short gwTravelHarrogathStringId;
extern "C" unsigned short gB27_00726F87;
extern "C" unsigned int gpfnTravelHarrogathHandler;
extern "C" unsigned int gB27_00726F95;
extern "C" unsigned int gnIdentifyMenu5State;
extern "C" unsigned short gwIdentifyMenu5StringId;
extern "C" B27UIAction gpfnIdentifyMenu5Handler;
extern "C" unsigned int gnSocketMenuState;
extern "C" unsigned short gB27_00727247;
extern "C" unsigned int gB27_00727257;
extern "C" unsigned int gnPersonalizeMenuState;
extern "C" unsigned short gB27_00727297;
extern "C" unsigned int gB27_007272A9;
extern "C" unsigned int gnResurrectMenuState;
extern "C" unsigned short gB27_007272E1;
extern "C" B27UIAction gpfnResurrectMenuHandler;
extern "C" unsigned int gB27_007272EF;
extern "C" int gB27_007BCBF0;



extern "C" B27RecordHandler gpfnRecordHandler;
extern "C" unsigned int gnVirtualPlayerCount;

extern "C" B27RecordHandler __fastcall sub_005173D3_ExchangeRecordHandler(B27RecordHandler handler); // 0x005173D3

static inline int TEXT_FindEntryIndex(int nId);
D2UnitStrc* __cdecl SELECT_GetSelectedUnit(); // 0x00467A10

void __stdcall sub_004A1770(SMSGHANDLER_PARAMS* pMsg); // 0x004A1770



extern "C" int __cdecl INV_IsInvPanelTradeMode()
{
    int mode = gB27_007BCBF0;
    if (mode == 1 || mode == 2 || mode == 3)
        return 1;
    return 0;
}

extern "C" void __cdecl NPCMENU_ResetHandlers()
{
    bool oldAction = (gpfnResurrectMenuHandler == NPCMENU_ResurrectMercWait);
    gnHireMenuState = 2;
    gB27_00726E01 = 0;
    gB27_00726E0F = 0;
    gnTravelLutGholeinState = 2;
    gB27_00726E4F = 0;
    gB27_00726E5D = 0;
    gnTravelKurastDocksState = 2;
    gB27_00726E9D = 0;
    gB27_00726EAB = 0;
    gnImbueMenuState = 3;
    gB27_00726CCB = 0;
    gB27_00726CDB = 0;
    gnResurrectMenuState = 2;
    gB27_007272E1 = 0;
    gB27_007272EF = 0;
    if (oldAction)
        gnResurrectMenuState = 3;
    gB27_00727247 = 0;
    gB27_00727257 = 0;
    gB27_00727297 = 0;
    gB27_007272A9 = 0;
    gnTravelHarrogathState = 2;
    gB27_00726F87 = 0;
    gB27_00726F95 = 0;
    gwTravelHarrogathStringId = 0;
    gpfnTravelHarrogathHandler = 0;
    gnSocketMenuState = 3;
    gnPersonalizeMenuState = 4;
    gwIdentifyMenu1StringId = 0xfb4;
    gpfnIdentifyMenu1Handler = NPCMENU_IdentifyItemsWait;
    gnIdentifyMenu1State = 3;
    gwIdentifyMenu2StringId = 0xfb4;
    gpfnIdentifyMenu2Handler = NPCMENU_IdentifyItemsWait;
    gnIdentifyMenu2State = 3;
    gwIdentifyMenu3StringId = 0xfb4;
    gpfnIdentifyMenu3Handler = NPCMENU_IdentifyItemsWait;
    gnIdentifyMenu3State = 3;
    gwIdentifyMenu4StringId = 0xfb4;
    gpfnIdentifyMenu4Handler = NPCMENU_IdentifyItemsWait;
    gnIdentifyMenu4State = 3;
    gwIdentifyMenu5StringId = 0xfb4;
    gpfnIdentifyMenu5Handler = NPCMENU_IdentifyItemsWait;
    gnIdentifyMenu5State = 3;
}

extern "C" void __fastcall PLAYER_SetVirtualPlayerCount(unsigned int count)
{
    if (count <= 8)
        gnVirtualPlayerCount = count;
}

extern "C" int __fastcall SPELLSEL_GetSkillMaxLevel(int index)
{
    if (index >= 0 && index < gTables_00744304->inputCount)
    {
        int value = gTables_00744304->inputs[index].value;
        if (value > 0)
            return value;
    }
    return 20;
}

// 0x00491940
void __cdecl TEXT_ResetNpcPanel()
{
    gbInvGoldButtonDown = 0;
    gnSelectedShopButton = -1;
    gnSelectedTab = 0;
    gnGlobal_007BCAF0 = 0;
    for (int i = 0; i < gnNpcTabCount; ++i)
    {
        gaNpcTabs[i].bSelected = 0;
        gaNpcTabs[i].bEnabled = 0;
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





static int sub_0049C510_GetWaypointRowAtPoint(int nX, int nY)
{
    for (int i = 0; i < 9; ++i)
    {
        if (gaWaypointEntries[i].bEnabled && nX > gaLayouts[i].nRowX && nX < gaLayouts[i].nRowX + 0x118
            && nY > gaLayouts[i].nRowY && nY < gaLayouts[i].nRowY + 0x1E)
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

// 0x0049D370
void TEXT_FreeTextLines(D2SplittedTextStrc* pLine)
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
        gtTextState.nTextDisplaySetting = 1;
    }
    else
    {
        gtTextState.nTextDisplaySetting = nValue;
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
void __stdcall TEXT_FreeTextList(D2TextPanelListStrc* pList)
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
    gtTextState.nTextDisplaySetting = nValue;
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

    switch (sub_0045AE90_GetPanelSlideMode())
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
        gtTextState.nTextHoverUnitId = pUnit->dwUnitId;
        gtTextState.bTextHoverSet = 1;
    }
    else
    {
        gtTextState.bTextHoverSet = 0;
    }
}

struct D2TextIdEntryStrc;



extern D2TextIdEntryStrc gaTextIds[]; // 0x00722678

extern int gnTextIdCount; // 0x00722EB4

int gnGlobal_007BF1E0; // 0x007BF1E0

// 0x0049DA50
void __cdecl TEXT_ClearHoverUnit()
{
    gtTextState.bTextHoverSet = 0;
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
        gtTextState.nStartTick = GetTickCount();
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
        pCopy->pStrings[i] = (Unicode*)FOG_Alloc((UNICODE_StrLen(pSource->pStrings[i]) + 1) * sizeof(Unicode), ".\\UI\\text.cpp", 0x9D4, 0);
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

    if (!gtTextState.tMessageList.wCount)
    {
        return;
    }

    nOldFont = D2Win_10127_SetFont(0xD);
    pNode = gtTextState.tMessageList.pFirst;
    nBaseY = 0x14;
    if (GAME_GetUIVarState(0x13))
    {
        nBaseY = 0x5F;
    }

    nX = 0xF;
    nLine = 0;
    bSplit = 0;
    switch (sub_0045AE90_GetPanelSlideMode())
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
                        nWidth = D2Win_10123(pTextLine->wszLine, UNICODE_StrLen(pTextLine->wszLine));
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
                nWidth = D2Win_10123(pNode->pLines[i], UNICODE_StrLen(pNode->pLines[i]));
                if (nWidth)
                {
                    AUTOMAP_DrawFramedBox(nX - 4, 15 * nLine + nBaseY - 0xE, nWidth + 8, 0x10, 0, 1);
                    D2Win_10117_DrawText(pNode->pLines[i], nX, 15 * nLine + nBaseY, pNode->nColor, 0);
                    ++nLine;
                }
            }
        }
    }

    pNode = gtTextState.tMessageList.pFirst;
    D2TextNodeStrc* pPrevious = 0;
    const unsigned long dwTick = GetTickCount();
    while (pNode)
    {
        if (pNode->dwEndTick < dwTick)
        {
            --gtTextState.tMessageList.wCount;
            D2TextNodeStrc* pNext = pNode->pNext;
            if (gtTextState.tMessageList.pFirst == pNode)
            {
                gtTextState.tMessageList.pFirst = pNext;
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
    if (!gtTextState.tOverheadList.wCount)
    {
        return;
    }

    int nOldFont = D2Win_10127_SetFont(13);
    D2TextNodeStrc* pNode = gtTextState.tOverheadList.pFirst;
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
                                               D2Win_10123(pNode->pLines[i], UNICODE_StrLen(pNode->pLines[i])) + 10, 0x10, 0, 1);
                    D2Win_10117_DrawText(pNode->pLines[i], nX, gnScreenHeight + 25 * nTextRow - i * 25 / 2 - 0x73, pNode->nColor, 0);
                }
            }
            pNode = pNode->pNext;
            ++nBoxRow;
            --nTextRow;
        }
        while (pNode);
    }

    pNode = gtTextState.tOverheadList.pFirst;
    D2TextNodeStrc* pPrev = 0;
    unsigned int dwNow = GetTickCount();
    while (pNode)
    {
        if (pNode->dwEndTick < dwNow)
        {
            --gtTextState.tOverheadList.wCount;
            D2TextNodeStrc* pNext = pNode->pNext;
            if (gtTextState.tOverheadList.pFirst == pNode)
            {
                gtTextState.tOverheadList.pFirst = pNext;
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
    if (gtTextState.tHistory.wCount >= 0x80)
    {
        pNode = gtTextState.tHistory.pFirst;
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
        if (gtTextState.tHistory.wCount >= 1)
            gtTextState.tHistory.wCount--;
    }
    pNode = gtTextState.tHistory.pFirst;
link:
    pClone->pNext = pNode;
    gtTextState.tHistory.wCount++;
    gtTextState.tHistory.pFirst = pClone;
}

void __fastcall sub_0049E5C0_PrintWrappedLine(const Unicode* wszText, char nColor)
{
    const int nOldFont = D2Win_10127_SetFont(0xD);
    D2TextNodeStrc* pNode = (D2TextNodeStrc*)FOG_Alloc(sizeof(D2TextNodeStrc), ".\\UI\\text.cpp", 0xDAD, 0);
    memset(pNode, 0, sizeof(D2TextNodeStrc));
    pNode->pNext = 0;
    pNode->dwEndTick = GetTickCount() + 10000;

    int nCount = UNICODE_StrLen(wszText);
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
        UNICODE_ToUtf8(szLine, pSource, nCount);
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

    if (gtTextState.tOverheadList.pFirst)
    {
        D2TextNodeStrc* pLast = gtTextState.tOverheadList.pFirst;
        unsigned short nNodes = 0;
        while (pLast->pNext)
        {
            pLast = pLast->pNext;
            nNodes++;
        }
        D2_ASSERT(nNodes == gtTextState.tOverheadList.wCount - 1, 0xDF1);
        pLast->pNext = pNode;
    }
    else
    {
        gtTextState.tOverheadList.pFirst = pNode;
    }
    gtTextState.tOverheadList.wCount++;
    TEXT_AddToHistory(pNode);

    if (gtTextState.tOverheadList.wCount > 2)
    {
        D2TextNodeStrc* pFirst = gtTextState.tOverheadList.pFirst;
        gtTextState.tOverheadList.pFirst = pFirst->pNext;
        TEXT_FreeTextNode(pFirst);
        gtTextState.tOverheadList.wCount--;
    }

    if (GAME_GetUIVarState(0x18) && gpListBox)
    {
        gpListBox->sub_004BEE10_Slot15();
        TEXT_FillListBox();
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

// 0x0049E340
void __cdecl TEXT_FillListBox()
{
    for (D2TextNodeStrc* pNode = gtTextState.tHistory.pFirst; pNode; pNode = pNode->pNext)
        gpListBox->sub_004BEDE0_ForwardSlot3C(pNode->pLines[0], pNode->pLines[1], pNode->pLines[2], pNode->pLines[3],
                                        pNode->pLines[4], pNode->pLines[5], 0, pNode->nColor, 0, 0xD);
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

    if (gtTextState.tMessageList.pFirst)
    {
        D2TextNodeStrc* pLast = gtTextState.tMessageList.pFirst;
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
        D2_ASSERT(wCount == gtTextState.tMessageList.wCount - 1, 0xD6C);
        pLast->pNext = pNode;
    }
    else
    {
        gtTextState.tMessageList.pFirst = pNode;
    }

    if (pNode->nColor == 4 && pNode->nLines == 1)
    {
        char szName[0x100] = {0};
        UNICODE_ToUtf8(szName, pNode->pLines[0], 0x100);
        sub_00611560_GetSquelchList()->AddName(szName, 0x100);
    }

    TEXT_AddToHistory(pNode);
    gtTextState.tMessageList.wCount++;

    int nTotal = 0;
    D2TextNodeStrc* p = gtTextState.tMessageList.pFirst;
    if (gtTextState.tMessageList.pFirst)
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
        D2TextNodeStrc* pOld = gtTextState.tMessageList.pFirst;
        gtTextState.tMessageList.pFirst = gtTextState.tMessageList.pFirst->pNext;
        gtTextState.tMessageList.wCount--;
        TEXT_FreeTextNode(pOld);
    }

    sub_004B9A00(6, 0, 0, 0, 0);
    if (GAME_GetUIVarState(0x18) && gpListBox)
    {
        gpListBox->sub_004BEE10_Slot15();
        TEXT_FillListBox();
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

    int nCount = UNICODE_StrLen(wszText);
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
        UNICODE_ToUtf8((char*)aLine, pSource, nCount);
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

    if (gtTextState.tOverheadList.pFirst)
    {
        D2TextNodeStrc* pLast = gtTextState.tOverheadList.pFirst;
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
        D2_ASSERT(nNodes == gtTextState.tOverheadList.wCount - 1, 0xDF1);
        pLast->pNext = pNode;
    }
    else
    {
        gtTextState.tOverheadList.pFirst = pNode;
    }
    gtTextState.tOverheadList.wCount++;
    TEXT_AddToHistory(pNode);

    if (gtTextState.tOverheadList.wCount > 2)
    {
        D2TextNodeStrc* pFirst = gtTextState.tOverheadList.pFirst;
        gtTextState.tOverheadList.pFirst = gtTextState.tOverheadList.pFirst->pNext;
        TEXT_FreeTextNode(pFirst);
        gtTextState.tOverheadList.wCount--;
    }

    if (GAME_GetUIVarState(0x18) && gpListBox)
    {
        gpListBox->sub_004BEE10_Slot15();
        TEXT_FillListBox();
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
    gtTextState.hHintSound = 0;
}

// 0x0049E8B0
D2UnitStrc* __cdecl TEXT_GetTextUnit()
{
    if (gtTextState.bTextFromObject)
        return CUNIT_FindClientUnit(gtTextState.nTextNpcId, 1);
    if (gnTextActive)
        return CUNIT_FindClientUnit(gtTextState.nTextObjectId, 2);
    return 0;
}

// 0x0049E8F0
static int TEXT_FormatPartyEvent(Unicode* pOut, D2GSPacketSrv5A* pPacket)
{
    D2StoredUnitRecordStrc* pRecord = ROSTER_FindRosterUnitById(pPacket->dwParam);
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
        sub_005269D0_FormatText(0x132, pOut, D2LANG_GetStringFromTblIndex(0x277A), wszName);
        break;
    case 2:
        sub_005269D0_FormatText(0x132, pOut, D2LANG_GetStringFromTblIndex(0x277B), wszName);
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
        sub_005269D0_FormatText(0x132, pOut, D2LANG_GetStringFromTblIndex(0x277C), wszName);
        break;
    case 11:
        sub_005269D0_FormatText(0x132, pOut, D2LANG_GetStringFromTblIndex(0x277D), wszName);
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
        D2_ASSERT(UNICODE_StrLen(D2LANG_GetStringFromTblIndex(0xE37)) < 0x104, 0x114C);
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        sub_005267E0(wszBuffer, wszName);
        sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(0xE37));
        break;
    case 1:
        D2_ASSERT(UNICODE_StrLen(D2LANG_GetStringFromTblIndex(0xE38)) < 0x104, 0x1152);
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        sub_005267E0(wszBuffer, wszName);
        sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(0xE38));
        break;
    case 2:
        if (sub_00463DD0_GetPlayerUnit() && !strcmp(pPacket->szTextData[0], sub_0047A210(sub_00463DD0_GetPlayerUnit())))
            break;
        D2_ASSERT(UNICODE_StrLen(D2LANG_GetStringFromTblIndex(0xE39)) < 0x104, 0x115C);
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        if (strlen(pPacket->szTextData[1]))
        {
            Unicode wszAccount[16];
            sub_00526F20_ToUnicode(wszAccount, pPacket->szTextData[1], 16);
            sub_005269D0_FormatText(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0xE3B), wszName, wszAccount);
            break;
        }
        sub_005269D0_FormatText(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0xE39), wszName);
        break;
    case 3:
        D2_ASSERT(UNICODE_StrLen(D2LANG_GetStringFromTblIndex(0xE3A)) < 0x104, 0x116A);
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        if (strlen(pPacket->szTextData[1]))
        {
            Unicode wszAccount[16];
            sub_00526F20_ToUnicode(wszAccount, pPacket->szTextData[1], 16);
            sub_005269D0_FormatText(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0xE3C), wszName, wszAccount);
            break;
        }
        sub_005269D0_FormatText(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0xE3A), wszName);
        break;
    case 4:
        D2_ASSERT(UNICODE_StrLen(D2LANG_GetStringFromTblIndex(0xE3D)) < 0x104, 0x1178);
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        sub_005267E0(wszBuffer, wszName);
        sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(0xE3D));
        break;
    case 13:
        D2_ASSERT(UNICODE_StrLen(D2LANG_GetStringFromTblIndex(0xE44)) < 0x104, 0x117E);
        sub_00526F20_ToUnicode(wszName, pPacket->szTextData[0], 16);
        sub_005267E0(wszBuffer, wszName);
        sub_00526700(wszBuffer, D2LANG_GetStringFromTblIndex(0xE44));
        break;
    case 5:
        D2_ASSERT(UNICODE_StrLen(D2LANG_GetStringFromTblIndex(0xE3E)) < 0x104, 0x1184);
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
        if (UNICODE_StrLen(D2LANG_GetStringFromTblIndex(nStringId)) + UNICODE_StrLen(pKiller) + 16 >= 0x132)
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
        sub_005269D0_FormatText(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0x69B), wszName);
        break;
    case 15:
        sub_005269D0_FormatText(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0xE43), pPacket->dwParam);
        break;
    case 17:
        sub_005269D0_FormatText(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0x2AFC), pPacket->dwParam);
        break;
    case 18:
        sub_005269D0_FormatText(0x132, wszBuffer, D2LANG_GetStringFromTblIndex(0x2AFD));
        if (gpGlobal_007A0634)
            ENVIRONMENT_InitializeEnvironment(gpGlobal_007A0634, CUNIT_GetPlayerRoom(), 5, 0, 1);
        SCMD_StartTimedEffect(6, 0xFA0, 0x2710, 0xFA0);
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

    D2HoverTextStrc* pHoverText = CHAT_AllocHoverMsg(0, szText, gtTextState.nGameFrame);
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
        TEXT_PrintChatLine(wszText, pPacket->nMessageColor);
        return;
    }

    Unicode wszA[0x264];
    Unicode wszB[0x264];
    Unicode wszC[0x10];
    if (pPacket->nMessageType == 6)
    {
        Unicode::win2Unicode(wszB, pPacket->szMessage, 0x100);
        Unicode::win2Unicode(wszC, pPacket->szName, 0x10);
        sub_005269D0_FormatText(0x264, wszA, D2LANG_GetStringFromTblIndex(0xE4A), wszC, wszB);
        SCMD_StripColorCodes(wszA);
        TEXT_PrintChatLine(wszA, 2);
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
            TEXT_PrintChatLine(wszA, 2);
            return;
        }
        if (nTextLen > 0x131)
            return;
        sub_005267E0(wszA, wszText);
        TEXT_PrintChatLine(wszA, 2);
    }
    else if (pPacket->nMessageType == 1)
    {
        if (pPacket->nUnitType == 0 || pPacket->nUnitType == 1)
        {
            TEXT_PrintChatLine(wszText, pPacket->nMessageColor);
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
            TEXT_PrintChatLine(wszA, pPacket->nMessageColor);
            return;
        }
        if (nTextLen > 0x131)
            return;
        sub_005267E0(wszA, wszText);
        TEXT_PrintChatLine(wszA, pPacket->nMessageColor);
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

// 0x0049F8C0
void __fastcall TEXT_ClearHoverText(D2HoverClearPacketStrc* pPacket)
{
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(pPacket->dwUnitId, pPacket->nUnitType);
    if (pUnit)
    {
        if (pUnit->pHoverText)
            CHAT_FreeHoverMsg(0, pUnit->pHoverText);
        pUnit->pHoverText = 0;
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
    gtTextState.hHintSound = 0;
    if (gbTextHandlersRegistered == 1)
    {
        gbTextHandlersRegistered = 0;
        AUTOMAP_UnregisterHandlerTable(WINDOW_GetWindow(), gaTextMsgHandlers, 7);
    }
    if (gtTextState.bTextSound)
    {
        MSG_SendTwoDwords(0x31, -1, gtTextState.wTextStringId);
        gtTextState.bTextSound = 0;
    }
}

// 0x0049FA10
void __cdecl TEXT_DrawPanelFrame()
{
    char szPath[0x104];
    D2GfxDataStrc tContext;

    D2GFX_DrawBox(gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 0xE0, gnScreenWidth / 2, gnScreenHeight - 0x30, 0, 5);

    void* pCelFile = gpTextPanelFrameCel;
    if (!pCelFile)
    {
        wsprintfA(szPath, "%s\\UI\\MENU\\scroin", gszDataGlobal);
        pCelFile = ARCHIVE_LoadClientCellFile(szPath, 0);
        gpTextPanelFrameCel = pCelFile;
    }

    memset(&tContext, 0, sizeof(tContext));
    tContext.pCelFile = pCelFile;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    TEXTURE_CelDraw(&tContext, gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 0x6D, -1, 5, 0);
    tContext.nFrame = 1;
    TEXTURE_CelDraw(&tContext, gnPanelOffsetX + 0x100, gnScreenHeight + gnPanelOffsetY - 0x6D, -1, 5, 0);
    tContext.nFrame = 2;
    TEXTURE_CelDraw(&tContext, gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 0x31, -1, 5, 0);
    tContext.nFrame = 3;
    TEXTURE_CelDraw(&tContext, gnPanelOffsetX + 0x100, gnScreenHeight + gnPanelOffsetY - 0x31, -1, 5, 0);
    tContext.pCelFile = sub_00454600();
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

    D2GfxDataStrc tPiece;
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
    tPiece.pCelFile = gpScroin2_007BF270;
    if (!gtTextState.dwScrollTick)
    {
        gtTextState.dwScrollTick = GetTickCount();
        gtTextState.nScrollCounter = 0;
    }
    else if (gtTextState.dwScrollTick + 50 < GetTickCount())
    {
        gtTextState.dwScrollTick = GetTickCount();
        ++gtTextState.nScrollCounter;
    }

    for (int i = 0; i < 5; ++i)
    {
        if (gtTextState.nScrollCounter > gaScrollThresholds[i])
        {
            const int nTicks = gtTextState.nScrollCounter - gaScrollThresholds[i];
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

                D2GfxDataStrc tFade;
                memset(&tFade, 0, sizeof(tFade));
                tFade.pCelFile = gpScroin3_007BF26C;
                tFade.nFrame = nTicks >= 21 ? 0 : nTicks;
                TEXTURE_CelDraw(&tFade, gaScrollFadePos[nSlot].nX + gnPanelOffsetX, gaScrollFadePos[nSlot].nY - gnPanelOffsetY, -1, 3, 0);
            }
        }
    }

    D2Win_10127_SetFont(nOldMode);
}

extern "C" void __fastcall sub_00524280_InitializeDigest(unsigned int index)
{
    HashState* state = &gatBnHashCtx[index];
    state->a = 0x67452301u;
    state->b = 0xEFCDAB89u;
    state->c = 0x98BADCFEu;
    state->d = 0x10325476u;
    state->e = 0xC3D2E1F0u;
    state->lowCount = 0;
    state->highCount = 0;
}

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
void __cdecl sub_0049FF00_Nop()
{
}

// 0x0049FF10
void __cdecl TEXT_DispatchTextData()
{
    if (!gtTextState.pTextData)
        return;

    const int nTag = gtTextState.pTextData->dwTag;
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
    gtTextState.pTextData = pTextData;
    UI_SetUIVar(0x10, 2, 0);
    GAME_ResetMouseState();
    if (gtTextState.pTextData->dwTag == 0x20646B62)
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

// 0x004A0000
int __cdecl TEXT_IsTextBoxOpen()
{
    return gpTextBox != 0;
}

// 0x004A0010
void __cdecl TEXT_FreeTextLists()
{
    TEXT_FreeTextList(&gtTextState.tMessageList);
    TEXT_FreeTextList(&gtTextState.tHistory);
}

// 0x004A0030
int __cdecl TEXT_CloseMessageLogCallback()
{
    UI_SetUIVar(0x18, 1, 0);
    return 1;
}

// 0x004A0050
void TEXT_OpenMessageLogDialog()
{
    if (gpListDialog)
    {
        return;
    }
    gpListDialog = DIALOG_CreateDialog(5, 0x1E, (int)TEXT_CloseMessageLogCallback, 0, 0, 0, 0,
        gnScreenWidth - 0x14, gnScreenHeight - 0x82, 0, 0);
    ROSTER_SetCtrlState(gpListDialog, 1);
    DIALOG_AddTextLine(gpListDialog, D2LANG_GetStringFromTblIndex(0xFC3), 0x15, 0, 4, 1, 0, 0);
    DIALOG_AddTextLine(gpListDialog, D2LANG_GetStringFromTblIndex(0x1030), gnScreenHeight - 0xA5, 0,
        0, 1, TEXT_CloseMessageLogCallback, 1);
    gpListBox = new ListBoxWrapper(5, 0x41, gnScreenWidth - 0x14, gnScreenHeight - 0xC8, 2, 0, 0xD, 0,
        1);
    if (gpListBox)
    {
        DIALOG_AddWidget(gpListDialog, gpListBox, 0x19, 0x1E);
        TEXT_FillListBox();
        sub_004B82F0_Select(gpListDialog, -1);
    }
}

// 0x004A01A0
void __cdecl TEXT_CloseMessageLogDialog()
{
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
}

// 0x004A01E0
void __cdecl TEXT_ClearListFlags()
{
    for (D2TextNodeStrc* pNode = gtTextState.tMessageList.pFirst; pNode; pNode = pNode->pNext)
        pNode->dwEndTick = 0;
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

// 0x004A02F0
void __cdecl TEXT_ToggleListDialogUI()
{
    if (gpListDialog)
    {
        UI_SetUIVar(0x18, 1, 0);
        UI_SetUIVar(0x18, 0, 0);
    }
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
            const int nLength = UNICODE_StrLen(szLine);
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
                UNICODE_ToUtf8(szNumber, szLine, 100);
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

        const int nLength = UNICODE_StrLen(szLine);
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
    TEXT_FreeTextList(&gtTextState.tMessageList);
    TEXT_FreeTextList(&gtTextState.tOverheadList);
    TEXT_FreeTextList(&gtTextState.tHistory);
    gtTextState.hHintSound = 0;
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
    if (!gtTextState.hHintSound || sub_004B95C0_IsHintPlaying(gtTextState.hHintSound) || !bBusy)
    {
        gtTextState.hHintSound = 0;
        if (sub_0049D5A0_UpdateTextBox(pTextBox))
        {
            gbTextBoxDone = 1;
            if (!gtTextState.bTextFromObject && gpTextBox)
            {
                TEXT_FreeTextBox(gpTextBox);
                gpTextBox = 0;
                SELECT_SetSelectionRect(0);
            }

            TEXT_ResetTextBox();
            if (gpfnTextCallback)
            {
                return gpfnTextCallback(gpTextCallbackContext, 0, 0);
            }

            if (gbTextBoxPending == 1)
            {
                gbTextBoxPending = 0;
            }
            else if (gtTextState.bTextFromObject)
            {
                NPCMENU_CancelNpcAndFlag(gtTextState.nTextNpcId);
            }

            UI_StartUIVarDelay();
            gtTextState.bTextFromObject = 0;
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

// 0x004A0880
void __cdecl TEXT_CloseTextUnit()
{
    if (gtTextState.bTextFromObject)
        NPCMENU_CancelNpcAndFlag(gtTextState.nTextNpcId);
    else
        TEXT_ResetTextBox();
    UI_StartUIVarDelay();
    gtTextState.bTextFromObject = 0;
}

// 0x004A08C0
int __cdecl TEXT_CloseText()
{
    int bResult = 0;
    gbTextBoxDone = 1;
    if (!gtTextState.bTextFromObject && gnTextActive != 1)
    {
        if (gbTextBoxPending == 1)
        {
            if (gbTextBoxShown == 1)
            {
                gtTextState.bTextCallbackAccepted = 0;
                return bResult;
            }
            D2_ASSERT(gpMainTextBox, 0x947);
            TEXT_FreeTextBox(gpMainTextBox);
            FOG_Free(gpMainTextBox, ".\\UI\\text.cpp", 0x949, 0);
            gpMainTextBox = 0;
            gbTextBoxPending = 0;
            gbTextBoxShown = 0;
            bResult = 1;
        }
    }
    else
    {
        if (gpfnTextCallback)
        {
            TEXT_ResetTextBox();
            UI_StartUIVarDelay();
            if (gpfnTextCallback(gpTextCallbackContext, 1, gtTextState.bTextCallbackAccepted))
            {
                gtTextState.bTextCallbackAccepted = 0;
                return 1;
            }
            if (gtTextState.bTextFromObject)
                NPCMENU_CancelNpcAndFlag(gtTextState.nTextNpcId);
        }
        else
        {
            if (gtTextState.bTextFromObject)
                NPCMENU_CancelNpcAndFlag(gtTextState.nTextNpcId);
            else
                TEXT_ResetTextBox();
            UI_StartUIVarDelay();
        }
        gtTextState.bTextFromObject = 0;
        if (gbTextHandlersRegistered == 1)
        {
            gbTextHandlersRegistered = 0;
            sub_00451E10_RegisterHandlerTable(WINDOW_GetWindow(), gaTextMsgHandlers, 7);
        }
        bResult = 1;
    }
    gtTextState.bTextCallbackAccepted = 0;
    return bResult;
}

// 0x004A0A00
static void __stdcall TEXT_ShowHoverText(const Unicode* wszText, D2UnitStrc* pUnit, D2HoverTextStrc* pHoverText, D2CoordStrc* pPos)
{
    if (gtTextState.nGameFrame > CHAT_GetTimeoutFromHoverMsg(pHoverText))
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
    if (gtTextState.nHoverRectCount < 0x10 && !TEXT_PlaceHoverRect(gtTextState.nHoverRectCount, &tRect))
    {
        TEXT_FreeTextBox(pTextBox);
        return;
    }

    ++gtTextState.nHoverRectCount;
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
    tPos.nY += -0x1E - gtTextState.tHoverOffset.nTop;
    tPos.nX -= gtTextState.tHoverOffset.nLeft;
    switch (sub_0045AE90_GetPanelSlideMode())
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
                int nLength = UNICODE_StrLen(wszString);
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
    tPos.nY += -0x0A - gtTextState.tHoverOffset.nTop;
    tPos.nX -= gtTextState.tHoverOffset.nLeft;
    switch (sub_0045AE90_GetPanelSlideMode())
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
    int nLength = UNICODE_StrLen(wszString);
    if (nLength >= 0xC8)
        nLength = 0xC7;
    sub_00526790(wszBuffer, wszString, nLength);
    TEXT_ShowHoverText(wszBuffer, pUnit, pHoverText, &tPos);
}

// calling-convention shim (not game code)
static int __cdecl sub_0049D5A0_UpdateTextBox(D2TextBoxStrc* pTextBox)
{
    void* nA = WINDOW_GetWindow();
    void* nB = WINDOW_GetWindow();
    SELECT_SetSelectionRect(nA);
    SELECT_SetSelectionRect(nB);
    SELECT_SetSelectionRect(nA);
    SELECT_SetSelectionRect(nB);
    pTextBox->nScroll = 1;
    return *(char*)pTextBox;
}

// 0x004A0E70
void __fastcall TEXT_UpdateTexts(D2ViewStrc* pView)
{
    D2RectStrc tViewRect;
    D2CoordStrc tViewPos;

    ++gtTextState.nGameFrame;
    int nResult = 0;
    sub_00476070_GetViewRect(pView, &tViewRect.nLeft, &tViewRect.nTop, &tViewRect.nRight, &tViewRect.nBottom);
    VIEW_GetViewOffset(pView, &tViewPos.nX, &tViewPos.nY);
    SetRect(&gtTextState.tHoverOffset, tViewPos.nX, tViewPos.nY, tViewPos.nX + tViewRect.nRight - tViewRect.nLeft, tViewPos.nY + tViewRect.nBottom - tViewRect.nTop);

    if (gnTextActive == 1)
    {
        gaHoverRects[0].nLeft = gnTextLeft;
        gaHoverRects[0].nRight = gnTextLeft + 0x145;
        gaHoverRects[0].nTop = gnTextTop;
        gtTextState.nHoverRectCount = 1;
        gaHoverRects[0].nBottom = gnTextTop + 0x70;
    }
    else
    {
        gtTextState.nHoverRectCount = 0;
    }

    CUNIT_ForEachPlayer(TEXT_DrawUnitHoverText);
    CUNIT_ForEachMonster(TEXT_DrawObjectHoverText);
    CUNIT_ForEachObject(TEXT_DrawObjectHoverText);

    if (gnTextActive == 1 && gpTextBox && (gpTextBox->nScroll == 1 || !gpTextBox->nScroll))
    {
        nResult = TEXT_AdvanceTextBox(gbTextBoxDone, gpTextBox);

        D2UnitStrc* pUnit = 0;
        if (gtTextState.bTextFromObject)
        {
            pUnit = CUNIT_FindClientUnit(gtTextState.nTextNpcId, 1);
        }

        if (CUNIT_IsPlayerDeadOrMissing() || (gtTextState.bTextFromObject && pUnit && pUnit->dwAnimMode == 0x0C))
        {
            if (gtTextState.bTextFromObject)
            {
                MSG_SendTwoDwords(0x30, 1, gtTextState.nTextNpcId);
                NPCMENU_ClearNpcInventoryAndSound(gtTextState.nTextNpcId);
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
            gtTextState.bTextFromObject = 0;
        }
        nResult += nDrawn;
    }

    if (!nResult && gnTextActive == 1)
    {
        gtTextState.bTextPanelOpen = 0;
        gtTextState.bTextFromObject = 0;
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
        gdwTextEndTick = GetTickCount() + (UNICODE_StrLen(wszText) + 0x19) * 0xC8;
        gbTextBoxShown = 1;
        gbTextBoxPending = 1;
        gnTextBoxY = 0x64 - (gpMainTextBox->nHeight >> 2);
        gnTextBoxX = 0x140 - (gpMainTextBox->nWidth >> 1);
    }
}


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
            pUnit->pHoverText = CHAT_AllocHoverMsg(0, szText, gtTextState.nGameFrame);
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

        gtTextState.wTextPanelClassId = 0;
        gtTextState.nTextObjectId = pPacket->dwUnitId;
        if (pUnit)
        {
            gtTextState.wTextPanelClassId = UNITS_GetWeaponClass(pUnit);
        }
        WARDENCLIENT_OpenTextPanel(pPacket->wStringId, 0, 1);
    }
    else
    {
        TEXT_FreeTextHeader(gpTextHeader);
        gpTextHeader = 0;
    }
}



struct D2SetsTxt;

// 0x004A1730
void __cdecl TEXT_ClearTextPanel()
{
    TEXT_ResetTextBox();
    gtTextState.bTextPanelOpen = 0;
    if (gpTextHeader)
    {
        TEXT_FreeTextHeader(gpTextHeader);
        gpTextHeader = 0;
    }
}



int TEXT_FindQuestIndex(int nKey)
{
    for (int i = 0; i < 41; i++)
    {
        if (gaQuestTable[i].nCondition == nKey)
            return i;
    }
    return -1;
}

void __fastcall SCMD_HandleQuestEvent(const D2PacketRecord6Strc* pPacket)
{
    D2PacketRecord6Strc tPacket = *pPacket;
    TEXT_HandleQuestEvent(1, &tPacket);
}















int __cdecl EXCEPTIONS_ReleaseAllSymbols()
{
    return EXCEPTIONS_ReleaseSymbols(1);
}









int __fastcall AITHINK_BaalThroneCheckAiParamFlag(D2AiTickParamStrc* pAiTickParam, int nFlag)
{
    return pAiTickParam->pAiControl->dwAiParam[1] & nFlag;
}







int __fastcall CMDTBL_QueryKey(int nId, int nMode, int nCommand, unsigned short* pKey);               // 0x00469C20

























D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80


#define STAT_ARMORCLASS_VS_HTH 33





extern D2BeltSlotStrc gaStatButtons[4];                                                                  // 0x00724A48

int __fastcall sub_00498DC0(SMSGHANDLER_PARAMS* pMsg);





extern "C" __declspec(dllimport) short __stdcall GetKeyState(int nVirtKey);





// 0x004A1760
int __cdecl TEXT_Forward()
{
    return TEXT_CloseText();
}

// 0x004A1770
void __stdcall TEXT_KeyUpMsg(SMSGHANDLER_PARAMS* pMsg)
{
    gtTextState.bTextPanelOpen = 0;
    if (GetTickCount() - gtTextState.nStartTick < 100)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        gtTextState.bTextCallbackAccepted = 0;
        return;
    }

    if (TEXT_CloseText())
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}

// 0x004A17D0
void __stdcall sub_004A17D0_FilterNpcClick(SMSGHANDLER_PARAMS* pMsg)
{
    gtTextState.bTextCallbackAccepted = 1;
    if (SELECT_GetSelectedUnit())
    {
        if (gtTextState.bTextFromObject && CUNIT_FindClientUnit(gtTextState.nTextNpcId, 1) == SELECT_GetSelectedUnit())
            return;
    }
    else if (!SELECT_GetSelectedUnit() && gtTextState.bTextHoverSet)
    {
        D2UnitStrc* pUnit = CUNIT_FindClientUnit(gtTextState.nTextHoverUnitId, 1);
        if (pUnit && pUnit == CUNIT_FindClientUnit(gtTextState.nTextNpcId, 1))
        {
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_HandleMsg(pMsg);
        }
        return;
    }
    sub_004A1770(pMsg);
}

// 0x004A1870
void __stdcall TEXT_HotkeyMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (CUNIT_HasHotkeyBinding(7, 1))
    {
        unsigned short nKey = CUNIT_GetHotkeyBinding(7, 1);
        if (nKey != 0xFFFF && nKey <= 0xDF && pMsg->wParam == nKey)
        {
            return;
        }
    }

    TEXT_KeyUpMsg(pMsg);
}

// 0x004A18C0
void __stdcall TEXT_KeyDownMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (pMsg->wParam != 0x73)
    {
        TEXT_HotkeyMsg(pMsg);
    }
}

extern "C" void __cdecl D2CLIENT_CloseNPCTalk(); // 0x004A17D0
extern "C" void __cdecl sub_004A6000_RegisterPressMsgHandler(); // 0x004A6000
extern "C" void __cdecl TEXT_WheelCaptureMsg(); // 0x004A6310
extern "C" void __cdecl TEXT_ButtonCaptureMsg(); // 0x004A6350
extern "C" void __cdecl sub_004A63B0_WheelMsgHandler(); // 0x004A63B0

#pragma pack(push, 1)
struct d2data_007225C0_t
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

#pragma pack(push, 1)
struct d2data_00722F38_t
{
    unsigned char b0[296];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00723060_t
{
    unsigned char b0[296];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00723188_t
{
    unsigned char b0[296];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007232B0_t
{
    unsigned char b0[296];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007233D8_t
{
    unsigned char b0[296];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00723500_t
{
    unsigned char b0[296];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00723628_t
{
    unsigned char b0[296];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00723750_t
{
    unsigned char b0[24];
};
#pragma pack(pop)

extern "C" struct d2data_007225C0_t gData_007225C0; // 0x007225C0
extern "C" struct d2data_00722F38_t gData_00722F38; // 0x00722F38
extern "C" struct d2data_00723060_t gData_00723060; // 0x00723060
extern "C" struct d2data_00723188_t gData_00723188; // 0x00723188
extern "C" struct d2data_007232B0_t gData_007232B0; // 0x007232B0
extern "C" struct d2data_007233D8_t gData_007233D8; // 0x007233D8
extern "C" struct d2data_00723500_t gData_00723500; // 0x00723500
extern "C" struct d2data_00723628_t gData_00723628; // 0x00723628
extern "C" struct d2data_00723750_t gData_00723750; // 0x00723750
extern "C" const char* const gData_006DA2C8[27]; // 0x006DA2C8

extern "C" struct d2data_007225C0_t gData_007225C0 = {
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
}; // 0x007225C0

extern int gnTextTop = 12; // 0x007225FC

extern D2MsgHandlerEntryStrc gaTextMsgHandlers[7] = {
    { 0, 517, (void*)(unsigned int)&TEXT_EatMsg },
    { 0, 516, (void*)(unsigned int)&D2CLIENT_CloseNPCTalk },
    { 0, 513, (void*)(unsigned int)&D2CLIENT_CloseNPCTalk },
    { 3, 27, (void*)(unsigned int)&TEXT_KeyUpMsg },
    { 3, 32, (void*)(unsigned int)&TEXT_KeyUpMsg },
    { 0, 258, (void*)(unsigned int)&TEXT_HotkeyMsg },
    { 0, 260, (void*)(unsigned int)&TEXT_KeyDownMsg }
}; // 0x00722600

extern "C" const char gszFormatSound[8] = "%c%c%d"; // 0x006DA194

extern D2StringSoundStrc* gapClassStringSounds[7] = { (D2StringSoundStrc*)&gData_00722F38, (D2StringSoundStrc*)&gData_00723060, (D2StringSoundStrc*)&gData_00723188, (D2StringSoundStrc*)&gData_007232B0, (D2StringSoundStrc*)&gData_007233D8, (D2StringSoundStrc*)&gData_00723500, (D2StringSoundStrc*)&gData_00723628 }; // 0x00722F1C

extern "C" struct d2data_00722F38_t gData_00722F38 = {
    {
        0x89, 0x0B, 0x2D, 0x04, 0x8A, 0x0B, 0x2E, 0x04, 0x79, 0x0B, 0x30, 0x04, 0x7A, 0x0B, 0x2F, 0x04,
        0x7B, 0x0B, 0x31, 0x04, 0x7C, 0x0B, 0x32, 0x04, 0x7D, 0x0B, 0x33, 0x04, 0x7E, 0x0B, 0x34, 0x04,
        0x7F, 0x0B, 0x36, 0x04, 0x80, 0x0B, 0x35, 0x04, 0x81, 0x0B, 0x38, 0x04, 0x82, 0x0B, 0x37, 0x04,
        0x83, 0x0B, 0x3A, 0x04, 0x84, 0x0B, 0x39, 0x04, 0x85, 0x0B, 0x3B, 0x04, 0x86, 0x0B, 0x3C, 0x04,
        0x8D, 0x0B, 0x3D, 0x04, 0x8E, 0x0B, 0x3E, 0x04, 0x78, 0x0B, 0x3F, 0x04, 0x76, 0x0B, 0x41, 0x04,
        0x77, 0x0B, 0x40, 0x04, 0x8F, 0x0B, 0x43, 0x04, 0x90, 0x0B, 0x42, 0x04, 0x8B, 0x0B, 0x46, 0x04,
        0x8C, 0x0B, 0x45, 0x04, 0x9F, 0x0B, 0x47, 0x04, 0x99, 0x0B, 0x4C, 0x04, 0x96, 0x0B, 0x51, 0x04,
        0x9B, 0x0B, 0x56, 0x04, 0x9C, 0x0B, 0x5B, 0x04, 0x9A, 0x0B, 0x60, 0x04, 0x98, 0x0B, 0x6A, 0x04,
        0x93, 0x0B, 0x6F, 0x04, 0x92, 0x0B, 0x74, 0x04, 0x9D, 0x0B, 0x79, 0x04, 0x97, 0x0B, 0x7E, 0x04,
        0x9E, 0x0B, 0x83, 0x04, 0xA0, 0x0B, 0x88, 0x04, 0x94, 0x0B, 0x8D, 0x04, 0x95, 0x0B, 0x92, 0x04,
        0x91, 0x0B, 0x97, 0x04, 0xA9, 0x0B, 0x9C, 0x04, 0xA2, 0x0B, 0xA1, 0x04, 0xA1, 0x0B, 0xA6, 0x04,
        0xA8, 0x0B, 0xAB, 0x04, 0xA4, 0x0B, 0xB0, 0x04, 0xA7, 0x0B, 0xB5, 0x04, 0xAA, 0x0B, 0xBA, 0x04,
        0xA3, 0x0B, 0xBF, 0x04, 0xAB, 0x0B, 0xC4, 0x04, 0xAC, 0x0B, 0xC9, 0x04, 0xA6, 0x0B, 0xCE, 0x04,
        0xB9, 0x0B, 0xD4, 0x04, 0xB3, 0x0B, 0xD9, 0x04, 0xB4, 0x0B, 0xDE, 0x04, 0xB6, 0x0B, 0xE3, 0x04,
        0xAF, 0x0B, 0xE8, 0x04, 0xB1, 0x0B, 0xED, 0x04, 0xB8, 0x0B, 0xF2, 0x04, 0xB5, 0x0B, 0xF7, 0x04,
        0xB0, 0x0B, 0xFC, 0x04, 0xB7, 0x0B, 0x01, 0x05, 0xB2, 0x0B, 0x06, 0x05, 0xBA, 0x0B, 0x0B, 0x05,
        0x87, 0x0B, 0xA4, 0x2A, 0x88, 0x0B, 0x86, 0x55, 0xBC, 0x0B, 0xE2, 0x55, 0xBD, 0x0B, 0xF7, 0x55,
        0xBE, 0x0B, 0x05, 0x56, 0xBF, 0x0B, 0x0C, 0x56, 0xC0, 0x0B, 0xE9, 0x55, 0xC1, 0x0B, 0xF0, 0x55,
        0xC2, 0x0B, 0xFE, 0x55, 0xC3, 0x0B, 0x13, 0x56
    }
}; // 0x00722F38

extern "C" struct d2data_00723060_t gData_00723060 = {
    {
        0xC1, 0x0C, 0x2D, 0x04, 0xC2, 0x0C, 0x2E, 0x04, 0xB1, 0x0C, 0x30, 0x04, 0xB2, 0x0C, 0x2F, 0x04,
        0xB3, 0x0C, 0x31, 0x04, 0xB4, 0x0C, 0x32, 0x04, 0xB5, 0x0C, 0x33, 0x04, 0xB6, 0x0C, 0x34, 0x04,
        0xB7, 0x0C, 0x36, 0x04, 0xB8, 0x0C, 0x35, 0x04, 0xB9, 0x0C, 0x38, 0x04, 0xBA, 0x0C, 0x37, 0x04,
        0xBB, 0x0C, 0x3A, 0x04, 0xBC, 0x0C, 0x39, 0x04, 0xBD, 0x0C, 0x3B, 0x04, 0xBE, 0x0C, 0x3C, 0x04,
        0xC5, 0x0C, 0x3D, 0x04, 0xC6, 0x0C, 0x3E, 0x04, 0xB0, 0x0C, 0x3F, 0x04, 0xAE, 0x0C, 0x41, 0x04,
        0xAF, 0x0C, 0x40, 0x04, 0xC7, 0x0C, 0x43, 0x04, 0xC8, 0x0C, 0x42, 0x04, 0xC3, 0x0C, 0x46, 0x04,
        0xC4, 0x0C, 0x45, 0x04, 0xD7, 0x0C, 0x4A, 0x04, 0xD1, 0x0C, 0x4F, 0x04, 0xCE, 0x0C, 0x54, 0x04,
        0xD3, 0x0C, 0x59, 0x04, 0xD4, 0x0C, 0x5E, 0x04, 0xD2, 0x0C, 0x63, 0x04, 0xD0, 0x0C, 0x6D, 0x04,
        0xCB, 0x0C, 0x72, 0x04, 0xCA, 0x0C, 0x77, 0x04, 0xD5, 0x0C, 0x7C, 0x04, 0xCF, 0x0C, 0x81, 0x04,
        0xD6, 0x0C, 0x86, 0x04, 0xD8, 0x0C, 0x8B, 0x04, 0xCC, 0x0C, 0x90, 0x04, 0xCD, 0x0C, 0x95, 0x04,
        0xC9, 0x0C, 0x9A, 0x04, 0xE1, 0x0C, 0x9F, 0x04, 0xDA, 0x0C, 0xA4, 0x04, 0xD9, 0x0C, 0xA9, 0x04,
        0xE0, 0x0C, 0xAE, 0x04, 0xDC, 0x0C, 0xB3, 0x04, 0xDF, 0x0C, 0xB8, 0x04, 0xE2, 0x0C, 0xBD, 0x04,
        0xDB, 0x0C, 0xC2, 0x04, 0xE3, 0x0C, 0xC7, 0x04, 0xE4, 0x0C, 0xCC, 0x04, 0xDE, 0x0C, 0xD1, 0x04,
        0xF1, 0x0C, 0xD7, 0x04, 0xEB, 0x0C, 0xDC, 0x04, 0xEC, 0x0C, 0xE1, 0x04, 0xEE, 0x0C, 0xE6, 0x04,
        0xE7, 0x0C, 0xEB, 0x04, 0xE9, 0x0C, 0xF0, 0x04, 0xF0, 0x0C, 0xF5, 0x04, 0xED, 0x0C, 0xFA, 0x04,
        0xE8, 0x0C, 0xFF, 0x04, 0xEF, 0x0C, 0x04, 0x05, 0xEA, 0x0C, 0x09, 0x05, 0xF2, 0x0C, 0x0E, 0x05,
        0xBF, 0x0C, 0xA4, 0x2A, 0xC0, 0x0C, 0x86, 0x55, 0xF4, 0x0C, 0xDE, 0x55, 0xF5, 0x0C, 0xF3, 0x55,
        0xF6, 0x0C, 0x01, 0x56, 0xF7, 0x0C, 0x08, 0x56, 0xF8, 0x0C, 0xE5, 0x55, 0xF9, 0x0C, 0xEC, 0x55,
        0xFA, 0x0C, 0xFA, 0x55, 0xFB, 0x0C, 0x0F, 0x56
    }
}; // 0x00723060

extern "C" struct d2data_00723188_t gData_00723188 = {
    {
        0x25, 0x0C, 0x2D, 0x04, 0x26, 0x0C, 0x2E, 0x04, 0x15, 0x0C, 0x30, 0x04, 0x16, 0x0C, 0x2F, 0x04,
        0x17, 0x0C, 0x31, 0x04, 0x18, 0x0C, 0x32, 0x04, 0x19, 0x0C, 0x33, 0x04, 0x1A, 0x0C, 0x34, 0x04,
        0x1B, 0x0C, 0x36, 0x04, 0x1C, 0x0C, 0x35, 0x04, 0x1D, 0x0C, 0x38, 0x04, 0x1E, 0x0C, 0x37, 0x04,
        0x1F, 0x0C, 0x3A, 0x04, 0x20, 0x0C, 0x39, 0x04, 0x21, 0x0C, 0x3B, 0x04, 0x22, 0x0C, 0x3C, 0x04,
        0x29, 0x0C, 0x3D, 0x04, 0x2A, 0x0C, 0x3E, 0x04, 0x14, 0x0C, 0x3F, 0x04, 0x12, 0x0C, 0x41, 0x04,
        0x13, 0x0C, 0x40, 0x04, 0x2B, 0x0C, 0x43, 0x04, 0x2C, 0x0C, 0x42, 0x04, 0x27, 0x0C, 0x46, 0x04,
        0x28, 0x0C, 0x45, 0x04, 0x3B, 0x0C, 0x4B, 0x04, 0x35, 0x0C, 0x50, 0x04, 0x32, 0x0C, 0x55, 0x04,
        0x37, 0x0C, 0x5A, 0x04, 0x38, 0x0C, 0x5F, 0x04, 0x36, 0x0C, 0x64, 0x04, 0x34, 0x0C, 0x6E, 0x04,
        0x2F, 0x0C, 0x73, 0x04, 0x2E, 0x0C, 0x78, 0x04, 0x39, 0x0C, 0x7D, 0x04, 0x33, 0x0C, 0x82, 0x04,
        0x3A, 0x0C, 0x87, 0x04, 0x3C, 0x0C, 0x8C, 0x04, 0x30, 0x0C, 0x91, 0x04, 0x31, 0x0C, 0x96, 0x04,
        0x2D, 0x0C, 0x9B, 0x04, 0x45, 0x0C, 0xA0, 0x04, 0x3E, 0x0C, 0xA5, 0x04, 0x3D, 0x0C, 0xAA, 0x04,
        0x44, 0x0C, 0xAF, 0x04, 0x40, 0x0C, 0xB4, 0x04, 0x43, 0x0C, 0xB9, 0x04, 0x46, 0x0C, 0xBE, 0x04,
        0x3F, 0x0C, 0xC3, 0x04, 0x47, 0x0C, 0xC8, 0x04, 0x48, 0x0C, 0xCD, 0x04, 0x42, 0x0C, 0xD2, 0x04,
        0x55, 0x0C, 0xD8, 0x04, 0x4F, 0x0C, 0xDD, 0x04, 0x50, 0x0C, 0xE2, 0x04, 0x52, 0x0C, 0xE7, 0x04,
        0x4B, 0x0C, 0xEC, 0x04, 0x4D, 0x0C, 0xF1, 0x04, 0x54, 0x0C, 0xF6, 0x04, 0x51, 0x0C, 0xFB, 0x04,
        0x4C, 0x0C, 0x00, 0x05, 0x53, 0x0C, 0x05, 0x05, 0x4E, 0x0C, 0x0A, 0x05, 0x56, 0x0C, 0x0F, 0x05,
        0x23, 0x0C, 0xA4, 0x2A, 0x24, 0x0C, 0x86, 0x55, 0x58, 0x0C, 0xE0, 0x55, 0x59, 0x0C, 0xF5, 0x55,
        0x5A, 0x0C, 0x03, 0x56, 0x5B, 0x0C, 0x0A, 0x56, 0x5C, 0x0C, 0xE7, 0x55, 0x5D, 0x0C, 0xEE, 0x55,
        0x5E, 0x0C, 0xFC, 0x55, 0x5F, 0x0C, 0x11, 0x56
    }
}; // 0x00723188

extern "C" struct d2data_007232B0_t gData_007232B0 = {
    {
        0x73, 0x0C, 0x2D, 0x04, 0x74, 0x0C, 0x2E, 0x04, 0x63, 0x0C, 0x30, 0x04, 0x64, 0x0C, 0x2F, 0x04,
        0x65, 0x0C, 0x31, 0x04, 0x66, 0x0C, 0x32, 0x04, 0x67, 0x0C, 0x33, 0x04, 0x68, 0x0C, 0x34, 0x04,
        0x69, 0x0C, 0x36, 0x04, 0x6A, 0x0C, 0x35, 0x04, 0x6B, 0x0C, 0x38, 0x04, 0x6C, 0x0C, 0x37, 0x04,
        0x6D, 0x0C, 0x3A, 0x04, 0x6E, 0x0C, 0x39, 0x04, 0x6F, 0x0C, 0x3B, 0x04, 0x70, 0x0C, 0x3C, 0x04,
        0x77, 0x0C, 0x3D, 0x04, 0x78, 0x0C, 0x3E, 0x04, 0x62, 0x0C, 0x3F, 0x04, 0x60, 0x0C, 0x41, 0x04,
        0x61, 0x0C, 0x40, 0x04, 0x79, 0x0C, 0x43, 0x04, 0x7A, 0x0C, 0x42, 0x04, 0x75, 0x0C, 0x46, 0x04,
        0x76, 0x0C, 0x45, 0x04, 0x89, 0x0C, 0x49, 0x04, 0x83, 0x0C, 0x4E, 0x04, 0x80, 0x0C, 0x53, 0x04,
        0x85, 0x0C, 0x58, 0x04, 0x86, 0x0C, 0x5D, 0x04, 0x84, 0x0C, 0x62, 0x04, 0x82, 0x0C, 0x6C, 0x04,
        0x7D, 0x0C, 0x71, 0x04, 0x7C, 0x0C, 0x76, 0x04, 0x87, 0x0C, 0x7B, 0x04, 0x81, 0x0C, 0x80, 0x04,
        0x88, 0x0C, 0x85, 0x04, 0x8A, 0x0C, 0x8A, 0x04, 0x7E, 0x0C, 0x8F, 0x04, 0x7F, 0x0C, 0x94, 0x04,
        0x7B, 0x0C, 0x99, 0x04, 0x93, 0x0C, 0x9E, 0x04, 0x8C, 0x0C, 0xA3, 0x04, 0x8B, 0x0C, 0xA8, 0x04,
        0x92, 0x0C, 0xAD, 0x04, 0x8E, 0x0C, 0xB2, 0x04, 0x91, 0x0C, 0xB7, 0x04, 0x94, 0x0C, 0xBC, 0x04,
        0x8D, 0x0C, 0xC1, 0x04, 0x95, 0x0C, 0xC6, 0x04, 0x96, 0x0C, 0xCB, 0x04, 0x90, 0x0C, 0xD0, 0x04,
        0xA3, 0x0C, 0xD6, 0x04, 0x9D, 0x0C, 0xDB, 0x04, 0x9E, 0x0C, 0xE0, 0x04, 0xA0, 0x0C, 0xE5, 0x04,
        0x99, 0x0C, 0xEA, 0x04, 0x9B, 0x0C, 0xEF, 0x04, 0xA2, 0x0C, 0xF4, 0x04, 0x9F, 0x0C, 0xF9, 0x04,
        0x9A, 0x0C, 0xFE, 0x04, 0xA1, 0x0C, 0x03, 0x05, 0x9C, 0x0C, 0x08, 0x05, 0xA4, 0x0C, 0x0D, 0x05,
        0x71, 0x0C, 0xA4, 0x2A, 0x72, 0x0C, 0x86, 0x55, 0xA6, 0x0C, 0xE1, 0x55, 0xA7, 0x0C, 0xF6, 0x55,
        0xA8, 0x0C, 0x04, 0x56, 0xA9, 0x0C, 0x0B, 0x56, 0xAA, 0x0C, 0xE8, 0x55, 0xAB, 0x0C, 0xEF, 0x55,
        0xAC, 0x0C, 0xFD, 0x55, 0xAD, 0x0C, 0x12, 0x56
    }
}; // 0x007232B0

extern "C" struct d2data_007233D8_t gData_007233D8 = {
    {
        0xD7, 0x0B, 0x2D, 0x04, 0xD8, 0x0B, 0x2E, 0x04, 0xC7, 0x0B, 0x30, 0x04, 0xC8, 0x0B, 0x2F, 0x04,
        0xC9, 0x0B, 0x31, 0x04, 0xCA, 0x0B, 0x32, 0x04, 0xCB, 0x0B, 0x33, 0x04, 0xCC, 0x0B, 0x34, 0x04,
        0xCD, 0x0B, 0x36, 0x04, 0xCE, 0x0B, 0x35, 0x04, 0xCF, 0x0B, 0x38, 0x04, 0xD0, 0x0B, 0x37, 0x04,
        0xD1, 0x0B, 0x3A, 0x04, 0xD2, 0x0B, 0x39, 0x04, 0xD3, 0x0B, 0x3B, 0x04, 0xD4, 0x0B, 0x3C, 0x04,
        0xDB, 0x0B, 0x3D, 0x04, 0xDC, 0x0B, 0x3E, 0x04, 0xC6, 0x0B, 0x3F, 0x04, 0xC4, 0x0B, 0x41, 0x04,
        0xC5, 0x0B, 0x40, 0x04, 0xDD, 0x0B, 0x43, 0x04, 0xDE, 0x0B, 0x42, 0x04, 0xD9, 0x0B, 0x46, 0x04,
        0xDA, 0x0B, 0x45, 0x04, 0xED, 0x0B, 0x48, 0x04, 0xE7, 0x0B, 0x4D, 0x04, 0xE4, 0x0B, 0x52, 0x04,
        0xE9, 0x0B, 0x57, 0x04, 0xEA, 0x0B, 0x5C, 0x04, 0xE8, 0x0B, 0x61, 0x04, 0xE6, 0x0B, 0x6B, 0x04,
        0xE1, 0x0B, 0x70, 0x04, 0xE0, 0x0B, 0x75, 0x04, 0xEB, 0x0B, 0x7A, 0x04, 0xE5, 0x0B, 0x7F, 0x04,
        0xEC, 0x0B, 0x84, 0x04, 0xEE, 0x0B, 0x89, 0x04, 0xE2, 0x0B, 0x8E, 0x04, 0xE3, 0x0B, 0x93, 0x04,
        0xDF, 0x0B, 0x98, 0x04, 0xF7, 0x0B, 0x9D, 0x04, 0xF0, 0x0B, 0xA2, 0x04, 0xEF, 0x0B, 0xA7, 0x04,
        0xF6, 0x0B, 0xAC, 0x04, 0xF2, 0x0B, 0xB1, 0x04, 0xF5, 0x0B, 0xB6, 0x04, 0xF8, 0x0B, 0xBB, 0x04,
        0xF1, 0x0B, 0xC0, 0x04, 0xF9, 0x0B, 0xC5, 0x04, 0xFA, 0x0B, 0xCA, 0x04, 0xF4, 0x0B, 0xCF, 0x04,
        0x07, 0x0C, 0xD5, 0x04, 0x01, 0x0C, 0xDA, 0x04, 0x02, 0x0C, 0xDF, 0x04, 0x04, 0x0C, 0xE4, 0x04,
        0xFD, 0x0B, 0xE9, 0x04, 0xFF, 0x0B, 0xEE, 0x04, 0x06, 0x0C, 0xF3, 0x04, 0x03, 0x0C, 0xF8, 0x04,
        0xFE, 0x0B, 0xFD, 0x04, 0x05, 0x0C, 0x02, 0x05, 0x00, 0x0C, 0x07, 0x05, 0x08, 0x0C, 0x0C, 0x05,
        0xD5, 0x0B, 0xA4, 0x2A, 0xD6, 0x0B, 0x86, 0x55, 0x0A, 0x0C, 0xDF, 0x55, 0x0B, 0x0C, 0xF4, 0x55,
        0x0C, 0x0C, 0x02, 0x56, 0x0D, 0x0C, 0x09, 0x56, 0x0E, 0x0C, 0xE6, 0x55, 0x0F, 0x0C, 0xED, 0x55,
        0x10, 0x0C, 0xFB, 0x55, 0x11, 0x0C, 0x10, 0x56
    }
}; // 0x007233D8

extern "C" struct d2data_00723500_t gData_00723500 = {
    {
        0x5D, 0x0D, 0x2D, 0x04, 0x5E, 0x0D, 0x2E, 0x04, 0x4D, 0x0D, 0x30, 0x04, 0x4E, 0x0D, 0x2F, 0x04,
        0x4F, 0x0D, 0x31, 0x04, 0x50, 0x0D, 0x32, 0x04, 0x51, 0x0D, 0x33, 0x04, 0x52, 0x0D, 0x34, 0x04,
        0x53, 0x0D, 0x36, 0x04, 0x54, 0x0D, 0x35, 0x04, 0x55, 0x0D, 0x38, 0x04, 0x56, 0x0D, 0x37, 0x04,
        0x57, 0x0D, 0x3A, 0x04, 0x58, 0x0D, 0x39, 0x04, 0x59, 0x0D, 0x3B, 0x04, 0x5A, 0x0D, 0x3C, 0x04,
        0x61, 0x0D, 0x3D, 0x04, 0x62, 0x0D, 0x3E, 0x04, 0x4C, 0x0D, 0x3F, 0x04, 0x4A, 0x0D, 0x41, 0x04,
        0x4B, 0x0D, 0x40, 0x04, 0x63, 0x0D, 0x43, 0x04, 0x64, 0x0D, 0x42, 0x04, 0x5F, 0x0D, 0x46, 0x04,
        0x60, 0x0D, 0x45, 0x04, 0x73, 0x0D, 0x87, 0x55, 0x6D, 0x0D, 0x8A, 0x55, 0x6A, 0x0D, 0x8C, 0x55,
        0x6F, 0x0D, 0x8E, 0x55, 0x70, 0x0D, 0x90, 0x55, 0x6E, 0x0D, 0x92, 0x55, 0x6C, 0x0D, 0x94, 0x55,
        0x67, 0x0D, 0x96, 0x55, 0x66, 0x0D, 0x98, 0x55, 0x71, 0x0D, 0x9A, 0x55, 0x6B, 0x0D, 0x9C, 0x55,
        0x72, 0x0D, 0x9E, 0x55, 0x74, 0x0D, 0xA0, 0x55, 0x68, 0x0D, 0xA2, 0x55, 0x69, 0x0D, 0xA4, 0x55,
        0x65, 0x0D, 0xA6, 0x55, 0x7D, 0x0D, 0xA8, 0x55, 0x76, 0x0D, 0xAA, 0x55, 0x75, 0x0D, 0xAC, 0x55,
        0x7C, 0x0D, 0xAE, 0x55, 0x78, 0x0D, 0xB0, 0x55, 0x7B, 0x0D, 0xB2, 0x55, 0x7E, 0x0D, 0xB4, 0x55,
        0x77, 0x0D, 0xB6, 0x55, 0x7F, 0x0D, 0xB8, 0x55, 0x80, 0x0D, 0xBA, 0x55, 0x7A, 0x0D, 0xBC, 0x55,
        0x8D, 0x0D, 0xBE, 0x55, 0x87, 0x0D, 0xC1, 0x55, 0x88, 0x0D, 0xC3, 0x55, 0x8A, 0x0D, 0xC5, 0x55,
        0x83, 0x0D, 0xC7, 0x55, 0x85, 0x0D, 0xC9, 0x55, 0x8C, 0x0D, 0xCB, 0x55, 0x89, 0x0D, 0xCD, 0x55,
        0x84, 0x0D, 0xCF, 0x55, 0x8B, 0x0D, 0xD1, 0x55, 0x86, 0x0D, 0xD3, 0x55, 0x8E, 0x0D, 0xD6, 0x55,
        0x5B, 0x0D, 0xA4, 0x2A, 0x5C, 0x0D, 0x86, 0x55, 0x90, 0x0D, 0xE4, 0x55, 0x91, 0x0D, 0xF9, 0x55,
        0x92, 0x0D, 0x07, 0x56, 0x93, 0x0D, 0x0E, 0x56, 0x94, 0x0D, 0xEB, 0x55, 0x95, 0x0D, 0xF2, 0x55,
        0x96, 0x0D, 0x00, 0x56, 0x97, 0x0D, 0x15, 0x56
    }
}; // 0x00723500

extern "C" struct d2data_00723628_t gData_00723628 = {
    {
        0x0F, 0x0D, 0x2D, 0x04, 0x10, 0x0D, 0x2E, 0x04, 0xFF, 0x0C, 0x30, 0x04, 0x00, 0x0D, 0x2F, 0x04,
        0x01, 0x0D, 0x31, 0x04, 0x02, 0x0D, 0x32, 0x04, 0x03, 0x0D, 0x33, 0x04, 0x04, 0x0D, 0x34, 0x04,
        0x05, 0x0D, 0x36, 0x04, 0x06, 0x0D, 0x35, 0x04, 0x07, 0x0D, 0x38, 0x04, 0x08, 0x0D, 0x37, 0x04,
        0x09, 0x0D, 0x3A, 0x04, 0x0A, 0x0D, 0x39, 0x04, 0x0B, 0x0D, 0x3B, 0x04, 0x0C, 0x0D, 0x3C, 0x04,
        0x13, 0x0D, 0x3D, 0x04, 0x14, 0x0D, 0x3E, 0x04, 0xFE, 0x0C, 0x3F, 0x04, 0xFC, 0x0C, 0x41, 0x04,
        0xFD, 0x0C, 0x40, 0x04, 0x15, 0x0D, 0x43, 0x04, 0x16, 0x0D, 0x42, 0x04, 0x11, 0x0D, 0x46, 0x04,
        0x12, 0x0D, 0x45, 0x04, 0x25, 0x0D, 0x88, 0x55, 0x1F, 0x0D, 0x89, 0x55, 0x1C, 0x0D, 0x8B, 0x55,
        0x21, 0x0D, 0x8D, 0x55, 0x22, 0x0D, 0x8F, 0x55, 0x20, 0x0D, 0x91, 0x55, 0x1E, 0x0D, 0x93, 0x55,
        0x19, 0x0D, 0x95, 0x55, 0x18, 0x0D, 0x97, 0x55, 0x23, 0x0D, 0x99, 0x55, 0x1D, 0x0D, 0x9B, 0x55,
        0x24, 0x0D, 0x9D, 0x55, 0x26, 0x0D, 0x9F, 0x55, 0x1A, 0x0D, 0xA1, 0x55, 0x1B, 0x0D, 0xA3, 0x55,
        0x17, 0x0D, 0xA5, 0x55, 0x2F, 0x0D, 0xA7, 0x55, 0x28, 0x0D, 0xA9, 0x55, 0x27, 0x0D, 0xAB, 0x55,
        0x2E, 0x0D, 0xAD, 0x55, 0x2A, 0x0D, 0xAF, 0x55, 0x2D, 0x0D, 0xB1, 0x55, 0x30, 0x0D, 0xB3, 0x55,
        0x29, 0x0D, 0xB5, 0x55, 0x31, 0x0D, 0xB7, 0x55, 0x32, 0x0D, 0xB9, 0x55, 0x2C, 0x0D, 0xBB, 0x55,
        0x3F, 0x0D, 0xBD, 0x55, 0x39, 0x0D, 0xBF, 0x55, 0x3A, 0x0D, 0xC2, 0x55, 0x3C, 0x0D, 0xC4, 0x55,
        0x35, 0x0D, 0xC6, 0x55, 0x37, 0x0D, 0xC8, 0x55, 0x3E, 0x0D, 0xCA, 0x55, 0x3B, 0x0D, 0xCC, 0x55,
        0x36, 0x0D, 0xCE, 0x55, 0x3D, 0x0D, 0xD0, 0x55, 0x38, 0x0D, 0xD2, 0x55, 0x40, 0x0D, 0xD4, 0x55,
        0x0D, 0x0D, 0xA4, 0x2A, 0x0E, 0x0D, 0x86, 0x55, 0x42, 0x0D, 0xE3, 0x55, 0x43, 0x0D, 0xF8, 0x55,
        0x44, 0x0D, 0x06, 0x56, 0x45, 0x0D, 0x0D, 0x56, 0x46, 0x0D, 0xEA, 0x55, 0x47, 0x0D, 0xF1, 0x55,
        0x48, 0x0D, 0xFF, 0x55, 0x49, 0x0D, 0x14, 0x56
    }
}; // 0x00723628

extern "C" struct d2data_00723750_t gData_00723750 = {
    {
        0x07, 0x12, 0xA9, 0x58, 0x11, 0x12, 0xAA, 0x58, 0x04, 0x12, 0x2D, 0x04, 0x08, 0x12, 0x2D, 0x04,
        0x05, 0x12, 0x3F, 0x04, 0x0B, 0x12, 0x3F, 0x04
    }
}; // 0x00723750
#pragma comment(linker, "/alternatename:?gaMonStringSounds@@3PAUD2StringSoundStrc@@A=_gData_00723750")

extern int gaHoverDirs[8] = { 1, 1, -1, 1, 1, -1, -1, -1 }; // 0x00722654

extern int gnHoverDirCount = 8; // 0x00722674

extern D2TextIdEntryStrc gaTextIds[527] = {
    { 0x40, 0xE82 },
    { 0x41, 0xE82 },
    { 0x42, 0xE82 },
    { 0x43, 0xE82 },
    { 0x44, 0xE82 },
    { 0x45, 0xE82 },
    { 0x46, 0xE82 },
    { 0x47, 0xE82 },
    { 0x48, 0xE82 },
    { 0x49, 0xE82 },
    { 0x4A, 0xE82 },
    { 0x4B, 0xE82 },
    { 0x4C, 0xE82 },
    { 0x4D, 0xE82 },
    { 0x4E, 0xE82 },
    { 0x4F, 0xE82 },
    { 0x50, 0xE82 },
    { 0x51, 0xE83 },
    { 0x52, 0xE83 },
    { 0x53, 0xE83 },
    { 0x54, 0xE83 },
    { 0x55, 0xE83 },
    { 0x56, 0xE83 },
    { 0x57, 0xE83 },
    { 0x58, 0xE83 },
    { 0x59, 0xE83 },
    { 0x5A, 0xE83 },
    { 0x5B, 0xE83 },
    { 0x5C, 0xE83 },
    { 0x5D, 0xE83 },
    { 0x5E, 0xE83 },
    { 0x5F, 0xE83 },
    { 0x60, 0xE83 },
    { 0x61, 0xE85 },
    { 0x62, 0xE85 },
    { 0x63, 0xE85 },
    { 0x64, 0xE85 },
    { 0x65, 0xE85 },
    { 0x66, 0xE85 },
    { 0x67, 0xE85 },
    { 0x68, 0xE85 },
    { 0x69, 0xE85 },
    { 0x6A, 0xE85 },
    { 0x6B, 0xE85 },
    { 0x6C, 0xE85 },
    { 0x6D, 0xE85 },
    { 0x6E, 0xE85 },
    { 0x6F, 0xE85 },
    { 0x70, 0xE85 },
    { 0x71, 0xE85 },
    { 0x72, 0xE85 },
    { 0x73, 0xE85 },
    { 0x74, 0xE85 },
    { 0x75, 0xE85 },
    { 0x76, 0xE85 },
    { 0x77, 0xE85 },
    { 0x78, 0xE85 },
    { 0x79, 0xE85 },
    { 0x7A, 0xE85 },
    { 0x7B, 0xE85 },
    { 0x7E, 0xE85 },
    { 0x7C, 0xE85 },
    { 0x7D, 0xE85 },
    { 0x7F, 0xE86 },
    { 0x80, 0xE86 },
    { 0x81, 0xE86 },
    { 0x82, 0xE86 },
    { 0x83, 0xE86 },
    { 0x84, 0xE86 },
    { 0x85, 0xE86 },
    { 0x86, 0xE86 },
    { 0x87, 0xE86 },
    { 0x88, 0xE86 },
    { 0x89, 0xE86 },
    { 0x8A, 0xE86 },
    { 0x8B, 0xE86 },
    { 0x8C, 0xE86 },
    { 0x8D, 0xE86 },
    { 0x8E, 0xE86 },
    { 0x8F, 0xE86 },
    { 0x90, 0xE86 },
    { 0x91, 0xE86 },
    { 0x92, 0xE84 },
    { 0x93, 0xE84 },
    { 0x94, 0xE84 },
    { 0x95, 0xE84 },
    { 0x96, 0xE84 },
    { 0x97, 0xE84 },
    { 0x98, 0xE84 },
    { 0x99, 0xE84 },
    { 0x9A, 0xE84 },
    { 0x9B, 0xE84 },
    { 0x9C, 0xE84 },
    { 0x9D, 0xE84 },
    { 0x9E, 0xE84 },
    { 0x9F, 0xE84 },
    { 0xA0, 0xE84 },
    { 0xA1, 0xE84 },
    { 0xA2, 0xE84 },
    { 0xA3, 0xE84 },
    { 0xA4, 0xE84 },
    { 0xA5, 0xE84 },
    { 0xA6, 0xE87 },
    { 0xA7, 0xE87 },
    { 0xA8, 0xE87 },
    { 0xA9, 0xE87 },
    { 0xAA, 0xE87 },
    { 0xAB, 0xE87 },
    { 0xAC, 0xE87 },
    { 0xAD, 0xE87 },
    { 0xAE, 0xE87 },
    { 0xAF, 0xE87 },
    { 0xB0, 0xE87 },
    { 0xB1, 0xE87 },
    { 0xB2, 0xE87 },
    { 0xB3, 0xE87 },
    { 0xB4, 0xE87 },
    { 0xB5, 0xE87 },
    { 0xB6, 0xE87 },
    { 0xB7, 0xE87 },
    { 0xB8, 0xE87 },
    { 0x130, 0x39B },
    { 0x131, 0x39B },
    { 0x132, 0x39B },
    { 0x133, 0x39B },
    { 0x134, 0x39B },
    { 0x135, 0x39B },
    { 0x136, 0x39B },
    { 0x137, 0x39B },
    { 0x138, 0x39B },
    { 0x139, 0x39B },
    { 0x13A, 0x39B },
    { 0x13B, 0x39B },
    { 0x13C, 0x39B },
    { 0x13D, 0x39B },
    { 0x13E, 0x39B },
    { 0x13F, 0x39B },
    { 0x140, 0x39B },
    { 0x141, 0x39B },
    { 0x142, 0x39B },
    { 0x143, 0x39B },
    { 0x144, 0x39B },
    { 0x145, 0x39B },
    { 0x146, 0x39B },
    { 0x147, 0x39B },
    { 0x148, 0x39B },
    { 0x149, 0x39B },
    { 0x14A, 0x39B },
    { 0x14B, 0x39B },
    { 0x14C, 0x39B },
    { 0x14D, 0x39B },
    { 0x14E, 0x39B },
    { 0x14F, 0x39C },
    { 0x150, 0x39C },
    { 0x151, 0x39C },
    { 0x152, 0x39C },
    { 0x153, 0x39C },
    { 0x154, 0x39D },
    { 0x155, 0x39D },
    { 0x156, 0x39D },
    { 0x157, 0x39D },
    { 0x158, 0x39D },
    { 0x159, 0x39D },
    { 0x15A, 0x39D },
    { 0x15B, 0x39D },
    { 0x15C, 0x39D },
    { 0x15D, 0x39D },
    { 0x15E, 0x39D },
    { 0x15F, 0x39D },
    { 0x160, 0x39D },
    { 0x161, 0x39D },
    { 0x162, 0x39D },
    { 0x163, 0x39D },
    { 0x164, 0x39D },
    { 0x165, 0x39D },
    { 0x166, 0x39D },
    { 0x167, 0x39D },
    { 0x168, 0x39D },
    { 0x169, 0x39D },
    { 0x16A, 0x39D },
    { 0x16B, 0x39D },
    { 0x16C, 0x39D },
    { 0x16D, 0x39D },
    { 0x16E, 0x39D },
    { 0x16F, 0x39D },
    { 0x170, 0x39D },
    { 0x171, 0x39D },
    { 0x172, 0x39D },
    { 0x173, 0x39D },
    { 0x174, 0x39D },
    { 0x175, 0x39E },
    { 0x176, 0x39E },
    { 0x177, 0x39E },
    { 0x178, 0x39E },
    { 0x179, 0x39E },
    { 0x17A, 0x39E },
    { 0x17B, 0x39E },
    { 0x17C, 0x39E },
    { 0x17D, 0x39E },
    { 0x17E, 0x39E },
    { 0x17F, 0x39E },
    { 0x180, 0x39E },
    { 0x181, 0x39E },
    { 0x182, 0x39E },
    { 0x183, 0x39E },
    { 0x184, 0x39E },
    { 0x185, 0x39E },
    { 0x186, 0x39E },
    { 0x187, 0x39E },
    { 0x188, 0x39E },
    { 0x189, 0x39E },
    { 0x18A, 0x39E },
    { 0x18B, 0x39E },
    { 0x18D, 0x39E },
    { 0x18E, 0x39E },
    { 0x18F, 0x39E },
    { 0x190, 0x39E },
    { 0x191, 0x39E },
    { 0x192, 0x39E },
    { 0x193, 0x39E },
    { 0x194, 0x39E },
    { 0x195, 0x39E },
    { 0x196, 0x39E },
    { 0x197, 0x39E },
    { 0x198, 0x39F },
    { 0x199, 0x39F },
    { 0x19A, 0x39F },
    { 0x19B, 0x39F },
    { 0x19C, 0x39F },
    { 0x19D, 0x39F },
    { 0x19E, 0x39F },
    { 0x19F, 0x39F },
    { 0x1A0, 0x39F },
    { 0x1A1, 0x39F },
    { 0x1A2, 0x39F },
    { 0x1A3, 0x39F },
    { 0x1A4, 0x39F },
    { 0x1A5, 0x39F },
    { 0x1A6, 0x39F },
    { 0x1A7, 0x39F },
    { 0x1A8, 0x39F },
    { 0x1A9, 0x39F },
    { 0x1AA, 0x39F },
    { 0x1AB, 0x39F },
    { 0x1AC, 0x39F },
    { 0x1AD, 0x39F },
    { 0x1AE, 0x3A0 },
    { 0x1B0, 0x3A0 },
    { 0x1B1, 0x3A0 },
    { 0x1B2, 0x3A0 },
    { 0x1B3, 0x3A0 },
    { 0x1AF, 0x3A0 },
    { 0x1B4, 0x3A0 },
    { 0x1B5, 0x3A0 },
    { 0x1B6, 0x3A0 },
    { 0x1B7, 0x3A0 },
    { 0x1B8, 0x3A0 },
    { 0x1B9, 0x3A0 },
    { 0x1BA, 0x3A0 },
    { 0x1BB, 0x3A0 },
    { 0x1BC, 0x3A0 },
    { 0x1BD, 0x3A0 },
    { 0x1BE, 0x3A0 },
    { 0x1BF, 0x3A0 },
    { 0x1C0, 0x3A0 },
    { 0x1C1, 0x3A0 },
    { 0x1C2, 0x3A0 },
    { 0x1C3, 0x3A0 },
    { 0x1C4, 0x3A0 },
    { 0x225, 0x3A2 },
    { 0x226, 0x3A2 },
    { 0x227, 0x3A2 },
    { 0x228, 0x3A2 },
    { 0x229, 0x3A2 },
    { 0x22A, 0x3A2 },
    { 0x22B, 0x3A2 },
    { 0x22C, 0x3A2 },
    { 0x22D, 0x3A2 },
    { 0x22E, 0x3A2 },
    { 0x22F, 0x3A2 },
    { 0x230, 0x3A2 },
    { 0x231, 0x3A2 },
    { 0x232, 0x3A2 },
    { 0x233, 0x3A2 },
    { 0x234, 0x3A2 },
    { 0x235, 0x3A2 },
    { 0x236, 0x3A2 },
    { 0x237, 0x3A2 },
    { 0x238, 0x3A2 },
    { 0x239, 0x3A2 },
    { 0x23A, 0x3A2 },
    { 0x21F, 0x3A3 },
    { 0x221, 0x3A3 },
    { 0x220, 0x3A3 },
    { 0x222, 0x3A3 },
    { 0x223, 0x3A3 },
    { 0x224, 0x3A3 },
    { 0x23B, 0x3A4 },
    { 0x23C, 0x3A4 },
    { 0x23D, 0x3A4 },
    { 0x23E, 0x3A4 },
    { 0x23F, 0x3A4 },
    { 0x240, 0x3A4 },
    { 0x241, 0x3A4 },
    { 0x242, 0x3A4 },
    { 0x243, 0x3A4 },
    { 0x244, 0x3A4 },
    { 0x245, 0x3A4 },
    { 0x246, 0x3A4 },
    { 0x247, 0x3A4 },
    { 0x248, 0x3A4 },
    { 0x249, 0x3A4 },
    { 0x24A, 0x3A4 },
    { 0x24B, 0x3A4 },
    { 0x251, 0x3A4 },
    { 0x24C, 0x3A4 },
    { 0x24D, 0x3A4 },
    { 0x24E, 0x3A4 },
    { 0x24F, 0x3A4 },
    { 0x250, 0x3A4 },
    { 0x20F, 0x3A5 },
    { 0x210, 0x3A5 },
    { 0x211, 0x3A5 },
    { 0x212, 0x3A5 },
    { 0x213, 0x3A5 },
    { 0x214, 0x3A5 },
    { 0x215, 0x3A5 },
    { 0x216, 0x3A5 },
    { 0x217, 0x3A5 },
    { 0x218, 0x3A5 },
    { 0x219, 0x3A5 },
    { 0x21A, 0x3A5 },
    { 0x21B, 0x3A5 },
    { 0x21C, 0x3A5 },
    { 0x21D, 0x3A5 },
    { 0x21E, 0x3A5 },
    { 0x252, 0x3A6 },
    { 0x253, 0x3A6 },
    { 0x254, 0x3A6 },
    { 0x255, 0x3A6 },
    { 0x256, 0x3A6 },
    { 0x257, 0x3A6 },
    { 0x258, 0x3A6 },
    { 0x259, 0x3A6 },
    { 0x25A, 0x3A6 },
    { 0x25B, 0x3A6 },
    { 0x25C, 0x3A6 },
    { 0x25D, 0x3A6 },
    { 0x25E, 0x3A6 },
    { 0x25F, 0x3A6 },
    { 0x260, 0x3A6 },
    { 0x261, 0x3A6 },
    { 0x262, 0x3A6 },
    { 0x263, 0x3A6 },
    { 0x264, 0x3A6 },
    { 0x265, 0x3A6 },
    { 0x266, 0x3A6 },
    { 0x267, 0x3A6 },
    { 0x268, 0x3A6 },
    { 0x269, 0x3A6 },
    { 0x26A, 0x3A6 },
    { 0x26B, 0x3A6 },
    { 0x26C, 0x3A6 },
    { 0x26D, 0x3A6 },
    { 0x26E, 0x3A6 },
    { 0x26F, 0x3A6 },
    { 0x270, 0x3A6 },
    { 0x271, 0x3A6 },
    { 0x272, 0x3A6 },
    { 0x273, 0x3A6 },
    { 0x274, 0x3A7 },
    { 0x275, 0x3A7 },
    { 0x276, 0x3A7 },
    { 0x277, 0x3A7 },
    { 0x278, 0x3A7 },
    { 0x279, 0x3A7 },
    { 0x27A, 0x3A7 },
    { 0x27B, 0x3A7 },
    { 0x27D, 0x3A7 },
    { 0x27E, 0x3A7 },
    { 0x27F, 0x3A7 },
    { 0x280, 0x3A7 },
    { 0x281, 0x3A7 },
    { 0x282, 0x3A7 },
    { 0x283, 0x3A7 },
    { 0x284, 0x3A7 },
    { 0x285, 0x3A7 },
    { 0x286, 0x3A7 },
    { 0x287, 0x3A7 },
    { 0x288, 0x3A7 },
    { 0x289, 0x3A7 },
    { 0x28A, 0x3A7 },
    { 0x28B, 0x3A7 },
    { 0x28C, 0x3A7 },
    { 0x28D, 0x3A7 },
    { 0x28E, 0x3A7 },
    { 0x28F, 0x3A7 },
    { 0x290, 0x3A7 },
    { 0x291, 0x3A7 },
    { 0x292, 0x3A7 },
    { 0x293, 0x3A7 },
    { 0x294, 0x3A7 },
    { 0x295, 0x3A7 },
    { 0x296, 0x3A7 },
    { 0x297, 0x3A7 },
    { 0x29E, 0x3A9 },
    { 0x29F, 0x3A9 },
    { 0x2A0, 0x3A9 },
    { 0x2A1, 0x3A9 },
    { 0x2A2, 0x3A9 },
    { 0x2A3, 0x3A9 },
    { 0x2A4, 0x3A9 },
    { 0x2A5, 0x3A9 },
    { 0x2A9, 0x3AA },
    { 0x2AA, 0x3AA },
    { 0x2AB, 0x3AA },
    { 0x2AC, 0x3AA },
    { 0x2AD, 0x3AA },
    { 0x2A6, 0x3AB },
    { 0x2A7, 0x3AB },
    { 0x2A8, 0x3AB },
    { 0x4E20, 0x3AA },
    { 0x4E21, 0x3AA },
    { 0x4E6D, 0x585A },
    { 0x4E6E, 0x585A },
    { 0x4E6F, 0x585A },
    { 0x4E70, 0x585A },
    { 0x4E71, 0x585A },
    { 0x4E72, 0x585A },
    { 0x4E73, 0x585A },
    { 0x4E74, 0x585A },
    { 0x4E75, 0x585A },
    { 0x4E76, 0x585A },
    { 0x4E77, 0x585A },
    { 0x4E78, 0x585A },
    { 0x4E79, 0x585A },
    { 0x4E7A, 0x585A },
    { 0x4E7B, 0x585A },
    { 0x4E7C, 0x585A },
    { 0x4E7D, 0x585A },
    { 0x4E7E, 0x585A },
    { 0x4E7F, 0x585A },
    { 0x4E80, 0x585E },
    { 0x4E81, 0x585E },
    { 0x4E82, 0x585E },
    { 0x4E83, 0x585E },
    { 0x4E84, 0x585E },
    { 0x4E85, 0x585E },
    { 0x4E86, 0x585E },
    { 0x4E87, 0x585E },
    { 0x4E88, 0x585E },
    { 0x4E89, 0x585E },
    { 0x4E8A, 0x585E },
    { 0x4E8B, 0x585E },
    { 0x4E8C, 0x585E },
    { 0x4E8D, 0x585E },
    { 0x4E8E, 0x585E },
    { 0x4E8F, 0x585E },
    { 0x4E90, 0x585E },
    { 0x4E91, 0x585E },
    { 0x4E92, 0x585E },
    { 0x4E93, 0x585E },
    { 0x4E94, 0x5863 },
    { 0x4E95, 0x5863 },
    { 0x4E96, 0x5863 },
    { 0x4E97, 0x5863 },
    { 0x4E98, 0x5863 },
    { 0x4E99, 0x5863 },
    { 0x4E9A, 0x5863 },
    { 0x4E9B, 0x5863 },
    { 0x4E9C, 0x5863 },
    { 0x4E9D, 0x5863 },
    { 0x4E9E, 0x5863 },
    { 0x4E9F, 0x5863 },
    { 0x4EA0, 0x5863 },
    { 0x4EA1, 0x5863 },
    { 0x4EA2, 0x5863 },
    { 0x4EA3, 0x5863 },
    { 0x4EA8, 0x5863 },
    { 0x4EA4, 0x5863 },
    { 0x4EA5, 0x5863 },
    { 0x4EA6, 0x5863 },
    { 0x4EA7, 0x5863 },
    { 0x4EA9, 0x5869 },
    { 0x4EAC, 0x5869 },
    { 0x4EAB, 0x5869 },
    { 0x4EAD, 0x5869 },
    { 0x4EAE, 0x5869 },
    { 0x4EAF, 0x5869 },
    { 0x4EB0, 0x5869 },
    { 0x4EB1, 0x5869 },
    { 0x4EB2, 0x5869 },
    { 0x4EB3, 0x5869 },
    { 0x4EB4, 0x5869 },
    { 0x4EB5, 0x5869 },
    { 0x4EB6, 0x5869 },
    { 0x4EB7, 0x5869 },
    { 0x4EB8, 0x5869 },
    { 0x4EB9, 0x586D },
    { 0x4EBA, 0x586D },
    { 0x4EBB, 0x586D },
    { 0x4EBC, 0x586D },
    { 0x4EBD, 0x586D },
    { 0x4EBE, 0x586D },
    { 0x4EBF, 0x586D },
    { 0x4EC0, 0x586D },
    { 0x4EC1, 0x586D },
    { 0x4EC2, 0x586D },
    { 0x4EC3, 0x586D },
    { 0x4E22, 0x5871 },
    { 0x4EC6, 0x586D },
    { 0x4EC5, 0x586D },
    { 0x4EC7, 0x586D },
    { 0x4EC8, 0x586D },
    { 0x4EC4, 0x586D },
    { 0x4EC9, 0x5871 },
    { 0x4ECA, 0x5871 },
    { 0x4ECB, 0x5871 },
    { 0x4ECC, 0x5871 },
    { 0x4ECD, 0x5871 },
    { 0x4ECE, 0x5871 },
    { 0x4ECF, 0x5871 },
    { 0x4ED0, 0x5871 },
    { 0x4ED1, 0x5871 },
    { 0x4ED2, 0x5871 },
    { 0x4ED3, 0x5871 },
    { 0x4ED4, 0x5871 }
}; // 0x00722678

extern int gnTextIdCount = 527; // 0x00722EB4

extern D2ScrollPosStrc gaScrollPiecePos[5] = {
    { 242, 104 },
    { 255, 222 },
    { 148, 310 },
    { 47, 222 },
    { 75, 104 }
}; // 0x00722EB8

extern D2ScrollPosStrc gaScrollFadePos[5] = {
    { 303, 161 },
    { 322, 242 },
    { 254, 290 },
    { 190, 238 },
    { 211, 162 }
}; // 0x00722EE0

extern unsigned int gaScrollThresholds[5] = { 0, 0xC, 0x18, 0x24, 0x30 }; // 0x00722F08

extern "C" const char* const gData_006DA2C8[27] = {
    "a1q1", "a1q2", "a1q3", "a1q4", "a1q5", "a1q6", "a2q1", "a2q2", "a2q3", "a2q4", "a2q5", "a2q6", "a3q1", "a3q2", "a3q3", "a3q4",
    "a3q5", "a3q6", "a4q1", "a4q2", "a4q3", "a5q1", "a5q2", "a5q3", "a5q4", "a5q5", "a5q6"
}; // 0x006DA2C8
#pragma comment(linker, "/alternatename:?gaszQuestCelNames@@3PAPBDA=_gData_006DA2C8")
