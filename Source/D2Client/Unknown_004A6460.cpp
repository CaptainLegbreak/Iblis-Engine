#include "D2StateIds.h"
#include "D2Client.h"
#include "D2ClientFuncs.h"
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
#include "FogApi.h"
#include "StormApi.h"
#include "D2CommonApi.h"
#include "D2LangApi.h"
#include "FogApi.h"
#include "StormApi.h"
#include "D2CommonApi2.h"
#include "D2GfxApi.h"
#include "D2SoundApi.h"
#include "StormApi2.h"
#include "D2LangApi2.h"
#include "D2GameApi.h"
#include "D2CMPApi.h"
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


extern int gbNpcTradeClicked; // 0x007BCBEC




extern int gbInvGoldButtonDown; // 0x007BCE30

extern int gnPetIconPopupState; // 0x007BEECC







void __fastcall AUTOMAP_UnregisterHandlerTable(void* hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451E10

void __fastcall SCMD_RegisterMsgHandlers(void* hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0


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



extern int gnGameFrame; // 0x007BF20E

static bool TEXT_IsLanguageCompatible(int nLangId);


class D2ListBoxViewStrc
{
public:
    virtual ~D2ListBoxViewStrc();
};




void __stdcall TEXT_FreeTextList(void* pList); // 0x0049D4D0


D2SplittedTextStrc* __stdcall TEXT_BuildTextLines(const Unicode* wszText, int* pLineCount, unsigned short* pMaxLines); // 0x004A0320


void __fastcall SOUNDINST_ArmHint(int nKey, int nGroup, int nOffset, unsigned int nCount); // 0x004B9EF0

int __fastcall UNICODE_StrLen(const Unicode* pString); // 0x00526800




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
    virtual void sub_004BBFB0_GetRepeatStep();
    virtual void Slot13();
    virtual void Slot14();
    virtual void Refresh();

    ListBoxImplementation* pImpl;
};






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



extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize); // 0x00681EF0

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize); // 0x00681EB0



extern D2TextBoxStrc* gpTextBox; // 0x007BF0A4








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

extern D2TextListStrc gtOverheadTextList; // 0x007BF1EA

extern D2TextListStrc gtTextHistory; // 0x007BF1F0


extern "C" __declspec(dllimport) int __stdcall IntersectRect(D2RectStrc* pDest, const D2RectStrc* pSrc1, const D2RectStrc* pSrc2); // 0x006CC4C4

extern "C" int __cdecl atoi(const char* szString); // 0x00681EBB



void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20




extern "C" const char gszTextSourceFile[]; // 0x006DA13C

extern int gaHoverDirs[]; // 0x00722654

extern int gnHoverDirCount; // 0x00722674




bool __stdcall TEXT_PlaceHoverRect(int nCount, D2RectStrc* pRect); // 0x0049E070


struct D2CelFileStrc;



extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD


D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0

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






void __fastcall TEXT_SetTextCallback(D2TextCallback pfnCallback, void* pContext); // 0x0049E7E0


extern D2QuestSlotRectStrc gaQuestSlots[]; // 0x00723EB0













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



int __cdecl GAME_GetLadderFlag(); // 0x0044DCA0

static int TEXT_GetKeyConfigButtonAt(int nX, int nY);














D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80



#define STAT_STATPTS 4

#define STAT_NEWSKILLS 5






enum { REPEAT_MASK = 0x40000000, UI_VARIABLE = 11 };




extern "C" int gnFlag_007C02EC; // 0x007C02EC

void __stdcall CURSOR_HandleButtonUp(SMSGHANDLER_PARAMS* pMsg); // 0x00467FA0



D2CelStrc* __stdcall CelGetHandle(D2GfxDataStrc* pContext); // 0x00601840

void* gpLevelCel; // 0x007C02DC

void* gpLevelSocketCel; // 0x007C02E0

int gbStatButtonPressed; // 0x007C02E4






static int TEXT_GetKeyConfigLineAt(int nY);

static int TEXT_IsInKeyConfigList(int nX, int nY);

static int TEXT_IsOnUpArrow(int nX, int nY);

static int TEXT_IsOnDownArrow(int nX, int nY);

static int TEXT_IsAboveThumb(int nX, int nY);

static int TEXT_IsOnThumb(int nX, int nY);

static int TEXT_IsBelowThumb(int nX, int nY);

unsigned char gnTextColor; // 0x007C02F8

#define D2_MAX(a, b) (((a) > (b)) ? (a) : (b))

static int TEXT_IsOnKeyConfigButton(int nX, int nY);

static int TEXT_IsOnPressedButton(int nX, int nY);











int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00

typedef void (__fastcall* UNITFN)(D2UnitStrc* pUnit);



extern "C" void __cdecl GAME_ConfigureEnvironmentOrDefer(); // 0x0044C820






void __fastcall CUNIT_ForEachMonster(UNITFN pfnCallback); // 0x00464990



void __cdecl INV_StopCinematic(); // 0x00483300

void __cdecl INV_ChainCinematic(); // 0x00483340




int __cdecl MONSTER_GetQuestFlags(); // 0x004B32D0


static int TEXT_FindQuestIndex(int nKey);


struct D2StringSoundStrc;



extern D2MsgHandlerEntryStrc gaDialogWheelHandlers[]; // 0x007273E4

extern D2MsgHandlerEntryStrc gaDialogHandlers[]; // 0x007273F0

extern const char* gaszDialogCels[]; // 0x007274AC

extern void* gpWaypointBackgroundCel; // 0x007BF071

extern void* gpWaypointActTabsCel; // 0x007BF075

extern void* gpWaypointIconCel; // 0x007BF079

#include "D2ClientNpcMenu.h"







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


extern Unicode gwszTradePartnerName[]; // 0x007C0E84

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


extern D2DrlgActStrc* gpGlobal_007A0634; // 0x007A0634

static int TEXT_FormatPartyEvent(Unicode* pOut, D2GSPacketSrv5A* pPacket); // 0x0049E8F0

void __fastcall TEXT_PrintChatLine(const Unicode* wszText, char nColor); // 0x0049E3A0


extern "C" __declspec(dllimport) int __stdcall SetRect(D2RectStrc* pRect, int nLeft, int nTop, int nRight, int nBottom);


void __fastcall CUNIT_ForEachPlayer(UNITFN pfnCallback); // 0x00464950

void __fastcall CUNIT_ForEachObject(UNITFN pfnCallback); // 0x004649D0

void __fastcall sub_00476070_GetViewRect(D2ViewStrc* pView, int* pLeft, int* pTop, int* pRight, int* pBottom); // 0x00476070



void __cdecl TEXT_DrawOverheadTextList(); // 0x0049DEE0





extern "C" void __fastcall NPCMENU_ClearNpcInventoryAndSound(int nUnitId); // 0x004B3830

void __fastcall DIALOG_DrawDialog(D2ClientDialogStrc* pDialog); // 0x004B8100

extern D2RectStrc gtTextRect_007BF1D0; // 0x007BF1D0

extern D2TextCallback gpfnTextCallback; // 0x007BF258



static int __stdcall TEXT_AdvanceTextBox(int bIgnore, D2TextBoxStrc* pTextBox); // 0x004A0770


inline void* operator new(unsigned int, void* pWhere) { return pWhere; }




#define gbUpPressed_007C028C (gaPressed[1])

#define gbDownPressed_007C0290 (gaPressed[2])

#define KEYCFG_X ((gnScreenWidth_0071146C - 620) / 2)

#define KEYCFG_Y ((gnAutomapHeight - 420) / 2)






void __fastcall UI_DrawRectangleBorder(D2RectStrc* pRect); // 0x00452E50

const Unicode* __fastcall CMDTBL_GetKeyText(int nKey, int nArg2); // 0x00469DE0

extern D2KeyConfigButtonStrc gaButtons_007246D8[3]; // 0x007246D8

extern unsigned int gdwMessageTick_007C02C8; // 0x007C02C8







static int TEXT_GetKeyConfigEntryState(int nIndex, int nFlag);


extern void* gpHint_007BF202; // 0x007BF202


extern void* gpHint_007BF24B; // 0x007BF24B

extern D2TextCallback gpfnTextCallback; // 0x007BF258

void __fastcall SELECT_SetSelectionRect(void* pRect); // 0x00467430

void __fastcall NPCMENU_CancelNpcAndFlag(void* pHint); // 0x004B3D10

struct D2MessageListStrc;

struct D2QuestTextMsgStrc;

struct D2QuestTextsStrc;

struct D2QuestPageRangeStrc;

struct D2QuestPosStrc;

struct D2QuestLogStateStrc;






extern D2QuestTextsStrc gtQuestTextsSevenTombs; // 0x00723A64

extern D2QuestTextsStrc gtQuestTextsFallenAngel; // 0x00723C64

extern D2QuestTextsStrc gtQuestTextsSiege; // 0x00723D24

extern D2QuestPageRangeStrc gaQuestPageRanges[]; // 0x00723F08




static void TEXT_BuildQuestText(D2QuestTextMsgStrc* pMsg); // 0x004A1950



extern D2QuestPosStrc gaQuestPos[]; // 0x00723EA8












extern D2ClientListEntryStrc gaKeyConfigEntries[]; // 0x00724268

extern D2ClientListEntryStrc gaKeyConfigEntriesExp[]; // 0x00724468

static int TEXT_GetWeaponBlock(D2UnitStrc* pUnit); // 0x004A70C0

static int TEXT_AddToHitFactor(D2UnitStrc* pUnit, int nAttackRate); // 0x004A7300

static void TEXT_SetQuestPage(int nPageArg); // 0x004A2220


void __stdcall TEXT_QuestLButtonDownMsg(SMSGHANDLER_PARAMS* pMsg);


void __stdcall TEXT_QuestLButtonUpMsg(SMSGHANDLER_PARAMS* pMsg);

int __stdcall TEXT_GetChanceToHit(int nAttackRate);

struct D2QuestTableStrc;

struct D2UiEntry10Strc;




extern D2QuestTableStrc gaQuestTable[41]; // 0x00723F30




Unicode* __fastcall strncpy(Unicode* pDest, const Unicode* pSource, int nCount); // 0x00526790


static void TEXT_FreeTextNode(D2TextNodeStrc* pNode); // 0x0049D490















struct D2BitBufferStrc;

void __stdcall sub_L04_EmitUse(const Unicode* pText);


























































struct D2SetsTxt;







































int __fastcall CMDTBL_QueryKey(int nId, int nMode, int nCommand, unsigned short* pKey);               // 0x00469C20





struct D2TextCellStrc
{
    int nValue;

    D2TextCellStrc() : nValue(0) {}
};

inline D2MonStatsTxt* DATATBLS_GetMonStatsTxtRecordInl(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }
    return 0;
}

// 0x004A6460
void __cdecl TEXT_LoadLevelCels()
{
    gpLevelCel = GAME_LoadUiCelFile("Panel\\Level");
    gpLevelSocketCel = GAME_LoadUiCelFile("Panel\\Levelsocket");
}

// 0x004A6480
void __cdecl TEXT_FreeLevelCels()
{
    if (gpLevelCel)
    {
        ARCHIVE_FreeClientCellFile(gpLevelCel);
        gpLevelCel = 0;
    }
    if (gpLevelSocketCel)
    {
        ARCHIVE_FreeClientCellFile(gpLevelSocketCel);
        gpLevelSocketCel = 0;
    }
}

// 0x004A64C0
void __cdecl TEXT_UpdateLevelUpButtons()
{
    if (GAME_GetUIVarState(0xB))
        return;
    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
    if (GAME_GetUIVarState(6))
    {
        if (!STATLIST_GetUnitBaseStat(pPlayer, STAT_STATPTS, 0))
            UI_SetUIVar(6, 1, 0);
    }
    else
    {
        if (STATLIST_GetUnitBaseStat(pPlayer, STAT_STATPTS, 0) && !GAME_GetUIVarState(2))
            UI_SetUIVar(6, 0, 0);
    }
    if (GAME_GetUIVarState(7))
    {
        if (STATLIST_GetUnitBaseStat(pPlayer, STAT_NEWSKILLS, 0) <= 0)
            UI_SetUIVar(7, 1, 0);
    }
    else
    {
        if (STATLIST_GetUnitBaseStat(pPlayer, STAT_NEWSKILLS, 0) > 0 && !GAME_GetUIVarState(4))
            UI_SetUIVar(7, 0, 0);
    }
}

// 0x004A6580
int __fastcall TEXT_IsInPanelButton(int nMode, int nX, int nY)
{
    if (nMode == 2)
    {
        int nHalf = gnScreenWidth / 2;
        if (nX <= nHalf + 40 || nX >= nHalf + 74)
        {
            return 0;
        }
    }
    else if (nX < 41 || nX > 41 + 32)
    {
        return 0;
    }

    if (nY <= gnScreenHeight - 139 || nY >= gnScreenHeight - 102)
    {
        return 0;
    }

    return 1;
}

// 0x004A65E0
int __cdecl TEXT_IsMouseOnStatButton()
{
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (nX > gnScreenWidth / 2 - 0xC2 && nX < gnScreenWidth / 2 - 0xA0 && nY > gnScreenHeight - 0x2A && nY < gnScreenHeight - 8)
        return 1;
    return 0;
}

// 0x004A6630
int __fastcall TEXT_IsInRightPanelButton(int nMode, int nX, int nY)
{
    switch (nMode)
    {
    case 1:
        if (nX > (gnScreenWidth - gnScreenWidth / 2) - 73 && nX < (gnScreenWidth - gnScreenWidth / 2) - 40 && nY > gnScreenHeight - 138 && nY < gnScreenHeight - 102)
            return 1;
        return 0;
    default:
        if (nX > gnScreenWidth - 73 && nX < gnScreenWidth - 40 && nY > gnScreenHeight - 138 && nY < gnScreenHeight - 102)
            return 1;
        return 0;
    }
}

// 0x004A6690
int __cdecl TEXT_IsMouseOnSkillButton()
{
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (nX > gnScreenWidth / 2 + 0xA3 && nX < gnScreenWidth / 2 + 0xC5 && nY > gnScreenHeight - 0x2A && nY < gnScreenHeight - 8)
        return 1;
    return 0;
}


// 0x004A66E0
void __stdcall TEXT_StatButtonDownMsg(SMSGHANDLER_PARAMS* message)
{
    int x = message->nXpos;
    int y = message->nYpos;
    const int nResolution = D2GFX_GetResolutionMode();
    if (nResolution == 2 && GAME_GetUIVarState(nResolution + 7))
    {
        return;
    }
    int border = sub_0045AE90_GetPanelSlideMode();
    if (D2GFX_GetResolutionMode() != 2)
    {
        if (TEXT_IsInPanelButton(border, x, y))
        {
            gbStatButtonPressed = 1;
            sub_004B9A00(4, 0, 0, 0, 0);
            CURSOR_HandleButtonDown(message);
            if (border == 2 && NPCMENU_IsNpcTalkActive()) return;
            message->bReturn = 1;
            message->lResult = 0;
            sub_00420290_BreakHandlerChain(message);
            return;
        }
    }
    else
    {
        if (TEXT_IsMouseOnStatButton())
        {
            gbStatButtonPressed = 1;
            sub_004B9A00(4, 0, 0, 0, 0);
            CURSOR_HandleButtonDown(message);
            if (border == 2 && NPCMENU_IsNpcTalkActive()) return;
            message->bReturn = 1;
            message->lResult = 0;
            sub_00420290_BreakHandlerChain(message);
            return;
        }
    }
    message->bReturn = 0;
}

static inline void MarkRightButtonPressed()
{
    gbSkillButtonPressed = 1;
    const int nClickSound = 4;
    sub_004B9A00(nClickSound, 0, 0, 0, 0);
}

// 0x004A6790
void __stdcall TEXT_SkillButtonDownMsg(SMSGHANDLER_PARAMS* message)
{
    int x = message->nXpos;
    int y = message->nYpos;
    const int nResolution = D2GFX_GetResolutionMode();
    if (nResolution == 2 && GAME_GetUIVarState(nResolution + 7))
        return;
    int border = sub_0045AE90_GetPanelSlideMode();
    if (D2GFX_GetResolutionMode() != 2)
    {
        if (TEXT_IsInRightPanelButton(border, x, y))
        {
            MarkRightButtonPressed();
            CURSOR_HandleButtonDown(message);
            if (border == 1 && NPCMENU_IsNpcTalkActive()) return;
            message->bReturn = 1;
            message->lResult = 0;
            sub_00420290_BreakHandlerChain(message);
            return;
        }
    }
    else
    {
        if (TEXT_IsMouseOnSkillButton())
        {
            MarkRightButtonPressed();
            CURSOR_HandleButtonDown(message);
            if (border == 1 && NPCMENU_IsNpcTalkActive()) return;
            message->bReturn = 1;
            message->lResult = 0;
            sub_00420290_BreakHandlerChain(message);
            return;
        }
    }
    message->bReturn = 0;
}

static int __fastcall CLIENT_HitPanelButton(int nMode, int nX, int nY)
{
    return TEXT_IsInPanelButton(nMode, nX, nY);
}

// 0x004A6840
void __stdcall TEXT_StatButtonUpMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = pMsg->nXpos;
    int nY = pMsg->nYpos;
    if (D2GFX_GetResolutionMode() == 2 && GAME_GetUIVarState(9))
    {
        return;
    }

    CURSOR_HandleButtonUp(pMsg);
    if (D2GFX_GetResolutionMode() != 2)
    {
        if (gbStatButtonPressed && CLIENT_HitPanelButton(sub_0045AE90_GetPanelSlideMode(), nX, nY))
        {
            gbStatButtonPressed = 0;
            UI_SetUIVar(6, 1, 0);
            UI_SetUIVar(2, 0, 0);
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
    else
    {
        if (gbStatButtonPressed && TEXT_IsMouseOnStatButton())
        {
            gbStatButtonPressed = 0;
            UI_SetUIVar(2, 0, 0);
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }

    gbStatButtonPressed = 0;
    pMsg->bReturn = 0;
}

static int __fastcall CLIENT_HitRightPanelButton(int nMode, int nX, int nY)
{
    return TEXT_IsInRightPanelButton(nMode, nX, nY);
}

// 0x004A6920
void __stdcall TEXT_SkillButtonUpMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = pMsg->nXpos;
    int nY = pMsg->nYpos;
    if (D2GFX_GetResolutionMode() == 2 && GAME_GetUIVarState(9))
    {
        return;
    }

    CURSOR_HandleButtonUp(pMsg);
    if (D2GFX_GetResolutionMode() != 2)
    {
        if (gbSkillButtonPressed && CLIENT_HitRightPanelButton(sub_0045AE90_GetPanelSlideMode(), nX, nY))
        {
            gbSkillButtonPressed = 0;
            UI_SetUIVar(7, 1, 0);
            UI_SetUIVar(4, 0, 0);
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
    else
    {
        if (gbSkillButtonPressed && TEXT_IsMouseOnSkillButton())
        {
            gbSkillButtonPressed = 0;
            UI_SetUIVar(4, 0, 0);
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }

    gbSkillButtonPressed = 0;
    pMsg->bReturn = 0;
}

// 0x004A6A00
bool __stdcall TEXT_IsStatButtonHidden(int nArg)
{
    if (nArg == 3)
        return true;
    if (GAME_GetUIVarState(2))
        return true;
    if (GAME_GetUIVarState(0x16) && GAME_GetUIVarState(1))
        return true;
    if (GAME_GetUIVarState(0x16) && GAME_GetUIVarState(4))
        return true;
    return (bool)GAME_GetUIVarState(0xC);
}

int __stdcall sub_004F6480(D2GfxDataStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

// 0x004A6A70
void __cdecl TEXT_DrawLeftPanelButton()
{
    if (D2GFX_GetResolutionMode() != 2)
    {
        return;
    }

    D2GfxDataStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.nDirection = 0;
    tContext.pCelFile = gpLevelCel;
    tContext.nFrame = 2;
    if (TEXT_IsMouseOnStatButton() && !GAME_GetUIVarState(9))
    {
        D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0xF92), gnScreenWidth / 2 - 0xB3, gnScreenHeight - 0x32, 0, 1);
    }

    sub_004F6480(&tContext, gnScreenWidth / 2 - 0xC2, gnScreenHeight - 8, -1, 5, 0);
}

// 0x004A6B30
void __cdecl TEXT_DrawStatButton()
{
    const int nBorder = sub_0045AE90_GetPanelSlideMode();
    if (D2GFX_GetResolutionMode() != 2 && TEXT_IsStatButtonHidden(nBorder))
    {
        gbStatButtonPressed = 0;
        return;
    }

    int nX;
    if (nBorder == 2)
        nX = gnScreenWidth / 2 + 0x28;
    else
        nX = 0x28;

    D2GfxDataStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.nDirection = 0;
    tContext.pCelFile = gpLevelSocketCel;
    tContext.nFrame = 0;
    const int nCelWidth = CelGetWidth(CelGetHandle(&tContext));
    const int nTextWidth = D2Win_10121_GetTextWidth(D2LANG_GetStringFromTblIndex(0xF92));
    if (D2GFX_GetResolutionMode() != 2)
    {
        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0xF92), nCelWidth / 2 - nTextWidth / 2 + nX + 1, gnScreenHeight - 0x8E, 0, 0);
        TEXTURE_CelDraw(&tContext, nX, gnScreenHeight - 0x69, -1, 5, 0);
    }

    memset(&tContext, 0, sizeof(tContext));
    tContext.nDirection = 0;
    tContext.pCelFile = gpLevelCel;
    if (D2GFX_GetResolutionMode() != 2)
    {
        if (gbStatButtonPressed && TEXT_IsInPanelButton(nBorder, sub_00468730(), sub_00468740()))
            tContext.nFrame = 1;
        else
            tContext.nFrame = 0;
    }
    else
    {
        if (gbStatButtonPressed && TEXT_IsMouseOnStatButton())
            tContext.nFrame = 1;
        else
            tContext.nFrame = 0;
    }
    CelGetWidth(CelGetHandle(&tContext));
    D2Win_10121_GetTextWidth(D2LANG_GetStringFromTblIndex(0xF92));
    if (D2GFX_GetResolutionMode() != 2)
    {
        TEXTURE_CelDraw(&tContext, nX + 3, gnScreenHeight - 0x6D, -1, 5, 0);
        return;
    }

    if (TEXT_IsMouseOnStatButton() && !GAME_GetUIVarState(9))
        D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0xF92), gnScreenWidth / 2 - 0xB3, gnScreenHeight - 0x32, 0, 1);
    TEXTURE_CelDraw(&tContext, gnScreenWidth / 2 - 0xC2, gnScreenHeight - 8, -1, 5, 0);
}

// 0x004A6D50
bool __stdcall TEXT_IsSkillButtonHidden(int nArg)
{
    if (nArg == 3)
        return true;
    if (GAME_GetUIVarState(4))
        return true;
    if (GAME_GetUIVarState(0xC))
        return true;
    if (GAME_GetUIVarState(0x16) && GAME_GetUIVarState(1))
        return true;
    return false;
}

// 0x004A6DA0
void __cdecl TEXT_DrawRightPanelButton()
{
    if (D2GFX_GetResolutionMode() != 2)
    {
        return;
    }

    D2GfxDataStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.nDirection = 0;
    tContext.pCelFile = gpLevelCel;
    tContext.nFrame = 2;
    if (TEXT_IsMouseOnSkillButton() && !GAME_GetUIVarState(9))
    {
        D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0xF93), gnScreenWidth / 2 + 0xB2, gnScreenHeight - 0x32, 0, 1);
    }

    sub_004F6480(&tContext, gnScreenWidth / 2 + 0xA3, gnScreenHeight - 8, -1, 5, 0);
}

// 0x004A6E60
void __cdecl TEXT_DrawSkillButton()
{
    const int nBorder = sub_0045AE90_GetPanelSlideMode();
    if (D2GFX_GetResolutionMode() != 2 && TEXT_IsSkillButtonHidden(nBorder))
    {
        gbSkillButtonPressed = 0;
        return;
    }

    int nX;
    if (nBorder == 1)
        nX = gnScreenWidth - gnScreenWidth / 2 - 0x49;
    else
        nX = gnScreenWidth - 0x49;

    D2GfxDataStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.nDirection = 0;
    tContext.pCelFile = gpLevelSocketCel;
    tContext.nFrame = 0;
    const int nCelWidth = CelGetWidth(CelGetHandle(&tContext));
    const int nTextWidth = D2Win_10121_GetTextWidth(D2LANG_GetStringFromTblIndex(0xF93));
    if (D2GFX_GetResolutionMode() != 2)
    {
        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0xF93), nCelWidth / 2 - nTextWidth / 2 + nX + 1, gnScreenHeight - 0x8E, 0, 0);
        TEXTURE_CelDraw(&tContext, nX, gnScreenHeight - 0x69, -1, 5, 0);
    }

    memset(&tContext, 0, sizeof(tContext));
    tContext.nDirection = 0;
    tContext.pCelFile = gpLevelCel;
    if (D2GFX_GetResolutionMode() != 2)
    {
        if (gbSkillButtonPressed && TEXT_IsInRightPanelButton(nBorder, sub_00468730(), sub_00468740()))
            tContext.nFrame = 1;
        else
            tContext.nFrame = 0;
    }
    else
    {
        if (gbSkillButtonPressed && TEXT_IsMouseOnSkillButton())
            tContext.nFrame = 1;
        else
            tContext.nFrame = 0;
    }
    CelGetWidth(CelGetHandle(&tContext));
    D2Win_10121_GetTextWidth(D2LANG_GetStringFromTblIndex(0xF93));
    if (D2GFX_GetResolutionMode() != 2)
    {
        TEXTURE_CelDraw(&tContext, nX + 3, gnScreenHeight - 0x6D, -1, 5, 0);
        return;
    }

    if (TEXT_IsMouseOnSkillButton() && !GAME_GetUIVarState(9))
        D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0xF93), gnScreenWidth / 2 + 0xB2, gnScreenHeight - 0x32, 0, 1);
    TEXTURE_CelDraw(&tContext, gnScreenWidth / 2 + 0xA3, gnScreenHeight - 8, -1, 5, 0);
}

// 0x004A7080
void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor)
{
    int nSpan = nRight - nLeft + 1;
    int nWidth = D2Win_10121_GetTextWidth(wszText);
    if (nWidth < nSpan)
    {
        nLeft += (nSpan - nWidth) >> 1;
    }

    D2Win_10117_DrawText(wszText, nLeft, nY, nColor, 0);
}

// 0x004A70C0
static int TEXT_GetWeaponBlock(D2UnitStrc* pUnit)
{
    int i;
    if (!pUnit)
    {
        return 0;
    }

    D2InventoryStrc* pInventory = pUnit->pInventory;
    D2UnitStrc* pRightItem = 0;
    D2UnitStrc* pLeftItem = 0;
    if (pInventory)
    {
        pRightItem = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        pLeftItem = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    }

    D2StatStrc aStats[0x20];
    const int nCount = STATLIST_CopyStats(pUnit, STAT_PASSIVE_WEAPONBLOCK, aStats, 0x20);
    int nBest = 0;
    for (i = 0; i < nCount; ++i)
    {
        const int nItemType = aStats[i].nLayer;
        const int nValue = aStats[i].nValue;
        if (nItemType <= 0)
        {
            nBest = nValue;
        }
        else if (pLeftItem && ITEMSIsA(pLeftItem, nItemType))
        {
            if (nValue > nBest)
            {
                nBest = nValue;
            }
        }
        else if (pRightItem && ITEMSIsA(pRightItem, nItemType))
        {
            if (nValue > nBest)
            {
                nBest = nValue;
            }
        }
    }

    return nBest;
}

// 0x004A7180
static void TEXT_DrawBlockChanceHover(int nX, int nY, int nValue)
{
    if (nValue < 5)
    {
        nValue = 5;
    }
    else if (nValue > 0x5F)
    {
        nValue = 0x5F;
    }

    Unicode wszText[0x80];
    if (nX < gnPanelOffsetX + 0xAD || nX > gnPanelOffsetX + 0x137
        || nY < gnScreenHeight + gnPanelOffsetY - 0x11E || nY > gnScreenHeight + gnPanelOffsetY - 0x10B)
    {
        return;
    }

    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit2();
    int nLevel = UNITS_GetBlockRate(pPlayer, GAME_IsExpansion());
    if (nLevel <= 0)
    {
        nLevel = TEXT_GetWeaponBlock(pPlayer);
        if (nLevel > 0)
        {
            int nWeaponClass;
            COMPOSIT_GetWeaponClassId(pPlayer, pPlayer->pInventory, &nWeaponClass, -1, 1);
            if (nWeaponClass != 0x0D)
            {
                nLevel = 0;
            }
        }
    }

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(SELECT_GetHoverClassId());
    D2_ASSERT(pMonStatsTxtRecord, 0x15C);

    if (nLevel)
    {
        sub_005269D0_FormatText(0x80, wszText, D2LANG_GetStringFromTblIndex(0x2779), nLevel, nValue, D2LANG_GetStringFromTblIndex(pMonStatsTxtRecord->wNameStr), nValue);
    }
    else
    {
        sub_005269D0_FormatText(0x80, wszText, D2LANG_GetStringFromTblIndex(0x2778), D2LANG_GetStringFromTblIndex(pMonStatsTxtRecord->wNameStr), nValue);
    }

    D2Win_10132(wszText, gnPanelOffsetX + 0x8B, gnScreenHeight + gnPanelOffsetY - 0x13B, gnTextColor, 2, 0);
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

// 0x004A7300
static int TEXT_AddToHitFactor(D2UnitStrc* pUnit, int nAttackRate)
{
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER)
    {
        D2CharStatsTxt* pCharStatsTxtRecord = DATATBLS_GetCharStatsTxtRecord_Inl(pUnit->dwClassId);
        if (pCharStatsTxtRecord)
        {
            nAttackRate += pCharStatsTxtRecord->dwToHitFactor;
        }
    }

    return nAttackRate;
}

inline D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId)
{
    if (nMonsterId >= 0 && nMonsterId < sgptDataTables->nMonStatsTxtRecordCount)
    {
        return &sgptDataTables->pMonStatsTxt[nMonsterId];
    }

    return 0;
}

// 0x004A7340
int __stdcall TEXT_GetChanceToHit(int nAttackRate)
{
    if (!nAttackRate)
    {
        return 0;
    }

    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
    int nPercent = 100;
    const int nDifficulty = GAME_GetDifficulty();
    D2_ASSERT(nDifficulty < 3, 398);

    const int nMonsterId = SELECT_GetHoverMonClassId();
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nMonsterId);
    D2_ASSERT(pMonStatsTxtRecord, 403);

    D2MonStatsInitStrc monStatsInit;
    memset(&monStatsInit, 0, sizeof(monStatsInit));
    DATATBLS_CalculateMonsterStatsByLevel(nMonsterId, GAME_GetLadderFlag(), nDifficulty, pMonStatsTxtRecord->nLevel[nDifficulty], 2, &monStatsInit);
    int nDefense = monStatsInit.nAC;
    if (pMonStatsTxtRecord->nAlign != 1 && !GAME_IsExpansion() && GAME_GetDifficulty())
    {
        nDefense = nDefense * 10 / 12;
    }

    int nToHit = TEXT_AddToHitFactor(pPlayer, nAttackRate);
    if (nDefense < 0)
    {
        nToHit -= nDefense;
        nDefense = 0;
    }

    if (nToHit < 0)
    {
        nDefense -= nToHit;
        nToHit = 0;
    }

    if (nToHit || nDefense)
    {
        nDefense += nToHit;
        nToHit *= 100;
        nPercent = nToHit / nDefense;
    }

    const int nPlayerLevel = STATLIST_UnitGetStatValue(pPlayer, STAT_LEVEL, 0);
    const int nChance = 2 * nPlayerLevel * nPercent / (pMonStatsTxtRecord->nLevel[nDifficulty] + nPlayerLevel);
    if (nChance < 5)
    {
        return 5;
    }
    if (nChance > 95)
    {
        return 95;
    }
    return nChance;
}

#define STAT_ARMORCLASS_VS_HTH 33

// 0x004A74A0
int __cdecl MONSTER_GetPlayerDefensePercent()
{
    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
    int nPercent = 100;
    int nDefense = UNITS_GetDefense(pPlayer);
    nDefense += STATLIST_UnitGetStatValue(pPlayer, STAT_ARMORCLASS_VS_HTH, 0);
    const int nDifficulty = GAME_GetDifficulty();
    D2_ASSERT(nDifficulty < 3, 470);

    const int nMonsterId = SELECT_GetHoverClassId();
    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord_Inl(nMonsterId);
    if (!pMonStatsTxtRecord)
    {
        return 0;
    }

    D2MonStatsInitStrc monStatsInit;
    memset(&monStatsInit, 0, sizeof(monStatsInit));
    DATATBLS_CalculateMonsterStatsByLevel(nMonsterId, GAME_GetLadderFlag(), nDifficulty, pMonStatsTxtRecord->nLevel[nDifficulty], 8, &monStatsInit);
    int nToHit = monStatsInit.nTH;
    if (!nToHit)
    {
        memset(&monStatsInit, 0, sizeof(monStatsInit));
        DATATBLS_CalculateMonsterStatsByLevel(nMonsterId, GAME_GetLadderFlag(), nDifficulty, pMonStatsTxtRecord->nLevel[nDifficulty], 0x10, &monStatsInit);
        nToHit = monStatsInit.nTH;
        if (!nToHit)
        {
            memset(&monStatsInit, 0, sizeof(monStatsInit));
            DATATBLS_CalculateMonsterStatsByLevel(nMonsterId, GAME_GetLadderFlag(), nDifficulty, pMonStatsTxtRecord->nLevel[nDifficulty], 0x20, &monStatsInit);
            nToHit = monStatsInit.nTH;
        }
    }

    if (pMonStatsTxtRecord->nAlign != 1 && !GAME_IsExpansion() && GAME_GetDifficulty())
    {
        nToHit = nToHit * 10 / 15;
    }

    if (nDefense < 0)
    {
        nToHit -= nDefense;
        nDefense = 0;
    }

    if (nToHit < 0)
    {
        nDefense -= nToHit;
        nToHit = 0;
    }

    if (nToHit || nDefense)
    {
        nPercent = nToHit * 100 / (nToHit + nDefense);
    }

    const int nLevel = pMonStatsTxtRecord->nLevel[nDifficulty];
    return 2 * nLevel * nPercent / (STATLIST_UnitGetStatValue(pPlayer, STAT_LEVEL, 0) + nLevel);
}

// 0x004A7660
int __fastcall TEXT_SplitAtNewline(Unicode* wszText, Unicode** ppNext)
{
    Unicode* pChar = wszText;
    *ppNext = 0;
    int nLen = UNICODE_StrLen(wszText);
    int i = 0;
    while (pChar->wChar)
    {
        if (pChar->wChar == '\n')
        {
            wszText[i].wChar = 0;
            if (i >= nLen)
                return 0;
            *ppNext = pChar + 1;
            return 1;
        }
        ++pChar;
        ++i;
    }
    return 0;
}


static int gbStatScreenButtonDown;                                                                               // 0x007C02F4

extern D2BeltSlotStrc gaStatButtons[4];                                                                  // 0x00724A48

int __fastcall sub_00498DC0(SMSGHANDLER_PARAMS* pMsg);




// 0x004A76C0
static int TEXT_ClaimLeftPanelClick(SMSGHANDLER_PARAMS* pMsg)
{
    if (D2GFX_GetResolutionMode() == 2 && !AUTOMAP_IsCursorOverMiniPanelButton(pMsg) && pMsg->nXpos <= gnScreenWidth / 2 && pMsg->nYpos < gnScreenHeight - 0x2F)
    {
        if (sub_00468830_GetCursorState() == 6)
            UI_CancelCursorItemUse();
        pMsg->bReturn = 1;
        sub_00420290_BreakHandlerChain(pMsg);
        return 1;
    }
    return 0;
}

// 0x004A7720
void __stdcall TEXT_OnLButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    if (nX >= gnPanelOffsetX + 0x80 && nX <= gnPanelOffsetX + 0xA0 && nY >= gnScreenHeight + gnPanelOffsetY - 0x5C && nY <= gnScreenHeight + gnPanelOffsetY - 0x3C)
    {
        gbStatScreenButtonDown = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_004B9A00(4, 0, 0, 0, 0);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (nX >= gnPanelOffsetX && nX <= gnScreenWidth / 2 - 1 && nY >= gnPanelOffsetY && nY <= gnScreenHeight + gnPanelOffsetY - 0x31)
    {
        D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
        if (STATLIST_GetUnitBaseStat(pPlayer, STAT_STATPTS, 0))
        {
            for (int i = 0; i < 4; ++i)
            {
                if (nY > gaStatButtons[i].nY + gnPanelOffsetY + gnScreenHeight - 0x1F6 && nY < gaStatButtons[i].nY + gnPanelOffsetY + gnScreenHeight - 0x1E0 && nX > gaStatButtons[i].nX + gnPanelOffsetX && nX < gaStatButtons[i].nX + gnPanelOffsetX + 0x28)
                {
                    gaStatButtons[i].bActive = 1;
                    CURSOR_HandleButtonDown(pMsg);
                    pMsg->bReturn = 1;
                    pMsg->lResult = 0;
                    sub_004B9A00(5, 0, 0, 0, 0);
                    sub_00420290_BreakHandlerChain(pMsg);
                    return;
                }
            }
        }
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (!TEXT_ClaimLeftPanelClick(pMsg))
        pMsg->bReturn = 0;
}


extern "C" __declspec(dllimport) short __stdcall GetKeyState(int nVirtKey);

// 0x004A78C0
void __stdcall TEXT_OnLButtonUp(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    CURSOR_HandleButtonUp(pMsg);
    gbStatScreenButtonDown = 0;
    if (nX >= gnPanelOffsetX + 0x80 && nX <= gnPanelOffsetX + 0xA0 && nY >= gnScreenHeight + gnPanelOffsetY - 0x5C && nY <= gnScreenHeight + gnPanelOffsetY - 0x3C)
    {
        UI_SetUIVar(2, 1, 0);
        return;
    }
    if (nX >= gnPanelOffsetX && nX <= gnScreenWidth / 2 - 1 && nY >= gnPanelOffsetY && nY <= gnScreenHeight + gnPanelOffsetY - 0x31)
    {
        D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
        if (STATLIST_GetUnitBaseStat(pPlayer, STAT_STATPTS, 0))
        {
            const int nScreenH = gnScreenHeight;
            for (int i = 0; i < 4; ++i)
            {
                gaStatButtons[i].bActive = 0;
                if (nY > gaStatButtons[i].nY + gnPanelOffsetY + nScreenH - 0x1F6 && nY < gaStatButtons[i].nY + gnPanelOffsetY + nScreenH - 0x1E0 && nX > gaStatButtons[i].nX + gnPanelOffsetX && nX < gaStatButtons[i].nX + gnPanelOffsetX + 0x28)
                {
                    int nCount = STATLIST_UnitGetStatValue(pPlayer, STAT_STATPTS, 0);
                    if (GetKeyState(0x10) >= 0)
                        nCount = 1;
                    else if (!nCount)
                        break;
                    do
                    {
                        const int nStack = nCount < 0x20 ? nCount : 0x20;
                        nCount -= nStack;
                        MSG_SendWord(0x3A, ((unsigned char)(nStack - 1) << 8) | gaStatButtons[i].wCode);
                    }
                    while (nCount);
                    break;
                }
            }
        }
        GAME_ResetMouseButtons();
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    if (!TEXT_ClaimLeftPanelClick(pMsg))
        pMsg->bReturn = 0;
}


// 0x004A7A80
extern "C" void __cdecl INV_ClearGoldDialogFlag()
{
    gnFlag_007C02EC = 0;
}

// 0x004A7A90
void __cdecl TEXT_SetGoldDialogFlag()
{
    gnFlag_007C02EC = 1;
}

// One line of the character panel's fixed text: its box, the string and
// the string's length, which TEXT_InitTextEntryLengths fills in.
#pragma pack(push, 2)
struct D2CharTextStrc
{
    int nX;
    int nY;
    int nX2;
    unsigned short wStringId;
    int nLength;
};
#pragma pack(pop)

extern D2CharTextStrc gaCharTexts[15]; // 0x00724818

// 0x004A7AA0
void __cdecl TEXT_InitTextEntryLengths()
{
    for (unsigned int i = 0; i < sizeof(gaCharTexts) / sizeof(gaCharTexts[0]); ++i)
    {
        gaCharTexts[i].nLength = UNICODE_StrLen(D2LANG_GetStringFromTblIndex(gaCharTexts[i].wStringId));
    }
}

// 0x004A7AD0
void __cdecl sub_004A7AD0_Nop()
{
}







struct D2SkillsTxt;

struct D2SkillDescTxt;

static inline D2SkillsTxt* CLIENT_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

#define D2_MIN(a, b) ((a) < (b) ? (a) : (b))

struct D2DifficultyLevelsTxt;

struct D2CharTextStrc;

struct D2CharFieldStrc;

struct D2HoverBoxStrc;

struct D2ZeroDwordStrc;

struct D2PointsTextStrc;

struct D2CharFieldStrc
{
    int nX;
    int nY;
    int nX2;
    int nStatId;
};

struct D2ZeroDwordStrc
{
    int nValue;

    D2ZeroDwordStrc() : nValue(0) {}
};

struct D2PointsTextStrc
{
    Unicode w0, w1, w2, w3, w4, w5, w6, w7, w8, w9;
};



extern void* gpSkillPointsCel; // 0x007BEF20

extern D2CharFieldStrc gaCharFields[18]; // 0x00724928

extern D2HoverBoxStrc gaHoverBoxes[2]; // 0x006DA430

int __fastcall GAME_GetUnitClassId(D2UnitStrc* pUnit); // 0x00451F60

void* __cdecl GAME_GetBuySellButtonCells(); // 0x00454600





Unicode* __fastcall win2Unicode(Unicode* pDest, const char* szSource, int nCount); // 0x00526F20



int __stdcall INVENTORY_GetEquippedShield(D2InventoryStrc* pInventory, D2UnitStrc** ppItem); // 0x0063C8F0

static void __stdcall TEXT_DrawHoverValueBox(int nValueA, int nValueB, int nX, int nY); // 0x004A7AE0

static inline D2CharStatsTxt* sub_CharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }

    return 0;
}

// 0x004A7AE0
static void __stdcall TEXT_DrawHoverValueBox(int nValueA, int nValueB, int nX, int nY)
{
    D2TextCellStrc aText[0x40];
    PANEL_SetBlackColour();

    int bHoverA = 0;
    int bHoverB = 0;
    if (nX >= gnPanelOffsetX + 0xA2 && nX <= gnPanelOffsetX + 0x140
        && nY >= gnScreenHeight + gnPanelOffsetY - 0x14E && nY <= gnScreenHeight + gnPanelOffsetY - 0x13B)
    {
        bHoverA = 1;
    }
    else if (nX >= gnPanelOffsetX + 0xA2 && nX <= gnPanelOffsetX + 0x140
        && nY >= gnScreenHeight + gnPanelOffsetY - 0x134 && nY <= gnScreenHeight + gnPanelOffsetY - 0x121)
    {
        bHoverB = 1;
    }

    if (!nValueA)
    {
        bHoverA = 0;
    }
    if (!nValueB)
    {
        bHoverB = 0;
    }

    int nIndex;
    int nValue;
    if (bHoverA)
    {
        nIndex = 0;
        nValue = nValueA;
    }
    else if (bHoverB)
    {
        nIndex = 1;
        nValue = nValueB;
    }
    else
    {
        return;
    }

    if (nValue < 5)
    {
        nValue = 5;
    }
    else if (nValue > 0x5F)
    {
        nValue = 0x5F;
    }

    AUTOMAP_DrawFramedBox(gaHoverBoxes[nIndex].nBoxX + gnPanelOffsetX, gaHoverBoxes[nIndex].nBoxY + gnPanelOffsetY + gnScreenHeight - 480, 0x9B, 0x1E, gnTextColor, 2);
    const int nTitleY = gaHoverBoxes[nIndex].nTitleY + gnPanelOffsetY + gnScreenHeight - 480;
    const int nTitleX = gaHoverBoxes[nIndex].nTitleX + gnPanelOffsetX;
    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x103F), nTitleX, nTitleY, 0, 0);

    D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecordInl(SELECT_GetHoverMonClassId());
    D2_ASSERT(pMonStatsTxtRecord, 0xEC);

    sub_005269D0_FormatText(0x80, (Unicode*)aText, D2LANG_GetStringFromTblIndex(0x2777), D2LANG_GetStringFromTblIndex(pMonStatsTxtRecord->wNameStr), nValue);
    D2Win_10117_DrawText((Unicode*)aText, gaHoverBoxes[nIndex].nTextX + gnPanelOffsetX, gaHoverBoxes[nIndex].nTextY + gnPanelOffsetY + gnScreenHeight - 480, 0, 0);
}


// 0x004A7D00
void __cdecl TEXT_DrawCharStats()
{
    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
    int nColor = 0;
    int nWidth;
    D2GfxDataStrc tCel;
    int nHeight;
    memset(&tCel, 0, sizeof(tCel));
    tCel.pCelFile = gpInvCharCel;
    tCel.nDirection = 0;
    tCel.nFrame = 0;
    TEXTURE_CelDraw(&tCel, gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 0xE0, -1, 5, 0);
    tCel.nFrame = 1;
    TEXTURE_CelDraw(&tCel, gnPanelOffsetX + 0x100, gnScreenHeight + gnPanelOffsetY - 0xE0, -1, 5, 0);
    tCel.nFrame = 2;
    TEXTURE_CelDraw(&tCel, gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 0x30, -1, 5, 0);
    tCel.nFrame = 3;
    TEXTURE_CelDraw(&tCel, gnPanelOffsetX + 0x100, gnScreenHeight + gnPanelOffsetY - 0x30, -1, 5, 0);

    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    if (nMouseX >= gnPanelOffsetX + 0x80 && nMouseX <= gnPanelOffsetX + 0xA0
        && nMouseY >= gnPanelOffsetY + gnScreenHeight - 0x5C && nMouseY <= gnPanelOffsetY + gnScreenHeight - 0x3C)
    {
        D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0x1030), gnPanelOffsetX + 0x8F, gnPanelOffsetY + gnScreenHeight - 0x5F, 0, 1);
    }

    if (STATLIST_GetUnitBaseStat(pPlayer, STAT_STATPTS, 0))
    {
        tCel.pCelFile = gpSkillPointsCel;
        tCel.nFrame = 0;
        TEXTURE_CelDraw(&tCel, gnPanelOffsetX + 3, gnScreenHeight + gnPanelOffsetY - 0x74, -1, 5, 0);

        D2PointsTextStrc wszPoints;
        D2Win_10127_SetFont(6);
        TEXT_DrawCenteredText(gnPanelOffsetX + 0xB, gnScreenHeight + gnPanelOffsetY - 0x7D, gnPanelOffsetX + 0x58, D2LANG_GetStringFromTblIndex(0xFEB), 1);
        TEXT_DrawCenteredText(gnPanelOffsetX + 0xB, gnPanelOffsetY + gnScreenHeight - 0x75, gnPanelOffsetX + 0x58, D2LANG_GetStringFromTblIndex(0xFEC), 1);

        int anPoints[3];
        wsprintfA((char*)anPoints, "%i", STATLIST_GetUnitBaseStat(pPlayer, STAT_STATPTS, 0));
        D2Win_10127_SetFont(1);
        win2Unicode(&wszPoints.w0, (const char*)anPoints, 9);
        TEXT_DrawCenteredText(gnPanelOffsetX + 0x5C, gnScreenHeight + gnPanelOffsetY - 0x78, gnPanelOffsetX + 0x7F, &wszPoints.w0, 0);
    }

    if (STATLIST_GetUnitBaseStat(pPlayer, STAT_STATPTS, 0))
    {
        for (int i = 0; i < 4; ++i)
        {
            tCel.pCelFile = gpLevelSocketCel;
            const int nX = gaStatButtons[i].nX + gnPanelOffsetX;
            const int nY = gaStatButtons[i].nY + gnPanelOffsetY + gnScreenHeight - 0x1E0;
            tCel.nFrame = 0;
            TEXTURE_CelDraw(&tCel, nX + 5, nY + 5, -1, 5, 0);
            tCel.pCelFile = gpLevelCel;
            tCel.nFrame = gaStatButtons[i].bActive != 0;
            TEXTURE_CelDraw(&tCel, nX + 8, nY + 1, -1, 5, 0);
        }
    }

    D2Win_10127_SetFont(6);
    for (unsigned int i = 0; i < sizeof(gaCharTexts) / sizeof(gaCharTexts[0]); ++i)
    {
        D2ZeroDwordStrc aLine[50];
        Unicode* wszLine = (Unicode*)aLine;
        strncpy(wszLine, D2LANG_GetStringFromTblIndex(gaCharTexts[i].wStringId), 99);
        const int nLeft = gaCharTexts[i].nX + gnPanelOffsetX;
        const int nRight = gaCharTexts[i].nX2 + gnPanelOffsetX;
        const int nY = gaCharTexts[i].nY + gnPanelOffsetY + gnScreenHeight - 0x1E0;
        wszLine[99].wChar = 0;
        Unicode* pChar = wszLine;
        const int nLength = UNICODE_StrLen(wszLine);
        int nPos = 0;
        while (pChar->wChar)
        {
            if (pChar->wChar == '\n')
            {
                wszLine[nPos].wChar = 0;
                if (nPos < nLength)
                {
                    Unicode* pSecond = pChar + 1;
                    TEXT_DrawCenteredText(nLeft, nY - 4, nRight, wszLine, 0);
                    TEXT_DrawCenteredText(nLeft, nY + 4, nRight, pSecond, 0);
                    goto NEXT_TEXT;
                }

                break;
            }

            ++pChar;
            ++nPos;
        }

        TEXT_DrawCenteredText(nLeft, nY, nRight, wszLine, 0);
NEXT_TEXT:;
    }

    SKILLDESC_RefreshSkills(pPlayer);
    D2Win_10127_SetFont(0);
    const int nLeftChance = TEXT_GetChanceToHit(SKILLDESC_CallSkillDescFunc(pPlayer, 1));
    const int nRightChance = TEXT_GetChanceToHit(SKILLDESC_CallSkillDescFunc(pPlayer, 0));
    const int nPercent = MONSTER_GetPlayerDefensePercent();
    TEXT_DrawHoverValueBox(nLeftChance, nRightChance, nMouseX, nMouseY);
    TEXT_DrawBlockChanceHover(nMouseX, nMouseY, nPercent);
    D2Win_10127_SetFont(1);

    tCel.pCelFile = GAME_GetBuySellButtonCells();
    tCel.nFrame = (gbStatScreenButtonDown != 0) + 10;
    TEXTURE_CelDraw(&tCel, gnPanelOffsetX + 0x80, gnPanelOffsetY + gnScreenHeight - 0x3C, -1, 5, 0);

    int anNumber[0x20];
    D2ZeroDwordStrc aText[0x40];
    Unicode* wszText = (Unicode*)aText;
    if (pPlayer && pPlayer->dwUnitType == UNIT_PLAYER)
    {
        D2CharStatsTxt* pCharStatsTxtRecord = sub_CharStatsTxtRecord(pPlayer->dwClassId);
        TEXT_DrawCenteredText(gnPanelOffsetX + 0xC1, gnPanelOffsetY + gnScreenHeight - 0x1C7, gnPanelOffsetX + 0x136, (const Unicode*)pCharStatsTxtRecord->wszClassName, 0);

        const char* szName = ROSTER_GetUnitName(pPlayer);
        const unsigned int nChars = sub_005262A0_Utf8CountChars(szName, strlen(szName)) + 1;
        if (nChars > 11)
        {
            if (nChars >= 14)
            {
                D2Win_10127_SetFont(6);
            }
            else
            {
                D2Win_10127_SetFont(0);
            }
        }

        win2Unicode(wszText, szName, 0x80);
        TEXT_DrawCenteredText(gnPanelOffsetX + 0xD, gnScreenHeight + gnPanelOffsetY - 0x1C7, gnPanelOffsetX + 0xA0, wszText, 0);
        D2Win_10127_SetFont(1);
    }

    int nFont;
    for (unsigned int i = 0; i < sizeof(gaCharFields) / sizeof(gaCharFields[0]); ++i)
    {
        int bCheckWidth = 0;
        int nValue = STATLIST_UnitGetStatValue(pPlayer, gaCharFields[i].nStatId, 0);
        const int nBase = STATLIST_GetUnitBaseStat(pPlayer, gaCharFields[i].nStatId, 0);
        switch (gaCharFields[i].nStatId)
        {
        case STAT_MAXHP:
            if (nValue > nBase)
            {
                nColor = 3;
            }
            else if (nValue < nBase)
            {
                nColor = 1;
            }

            nValue >>= 8;
            wsprintfA((char*)anNumber, "%ld", nValue);
            bCheckWidth = 1;
            break;

        case STAT_HITPOINTS:
        {
            nValue >>= 8;
            D2UnitStrc* pUnit = CUNIT_GetPlayerUnit();
            if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->dwAnimMode != 0x11 && (unsigned int)nValue <= 1)
            {
                nValue = 1;
            }

            wsprintfA((char*)anNumber, "%ld", nValue);
            bCheckWidth = 1;
            break;
        }
        case STAT_MAXMANA:
            if (nValue > nBase)
            {
                nColor = 3;
            }
            else if (nValue < nBase)
            {
                nColor = 1;
            }

            nValue >>= 8;
            wsprintfA((char*)anNumber, "%ld", nValue);
            bCheckWidth = 1;
            break;

        case STAT_MANA:
            nValue >>= 8;
            wsprintfA((char*)anNumber, "%ld", nValue);
            bCheckWidth = 1;
            break;

        case STAT_MAXSTAMINA:
            if (nValue > nBase)
            {
                nColor = 3;
            }
            else if (nValue < nBase)
            {
                nColor = 1;
            }

            nValue >>= 8;
            wsprintfA((char*)anNumber, "%ld", nValue);
            bCheckWidth = 1;
            break;

        case STAT_STAMINA:
            nValue >>= 8;
            wsprintfA((char*)anNumber, gszFormatLd, nValue);
            bCheckWidth = 1;
            break;

        case STAT_MAGICRESIST:
        case STAT_FIRERESIST:
        case STAT_LIGHTRESIST:
        case STAT_COLDRESIST:
        case STAT_POISONRESIST:
        {
            D2DifficultyLevelsTxt* pDifficultyLevelsTxtRecord = DATATBLS_GetDifficultyLevelsTxtRecord(GAME_GetDifficulty());
            int nMax = 0;
            switch (gaCharFields[i].nStatId)
            {
            case STAT_MAGICRESIST:
                nMax = STATLIST_UnitGetStatValue(pPlayer, STAT_MAXMAGICRESIST, 0);
                break;

            case STAT_FIRERESIST:
                if (STATES_CheckStateMaskRFBlueOnUnit(pPlayer))
                {
                    nColor = 3;
                }

                if (STATES_CheckStateMaskRFRedOnUnit(pPlayer))
                {
                    nColor = 1;
                }

                nMax = STATLIST_UnitGetStatValue(pPlayer, STAT_MAXFIRERESIST, 0);
                break;

            case STAT_LIGHTRESIST:
                if (STATES_CheckStateMaskRLBlueOnUnit(pPlayer))
                {
                    nColor = 3;
                }

                if (STATES_CheckStateMaskRLRedOnUnit(pPlayer))
                {
                    nColor = 1;
                }

                nMax = STATLIST_UnitGetStatValue(pPlayer, STAT_MAXLIGHTRESIST, 0);
                break;

            case STAT_COLDRESIST:
                if (STATES_CheckStateMaskRCBlueOnUnit(pPlayer))
                {
                    nColor = 3;
                }

                if (STATES_CheckStateMaskRCRedOnUnit(pPlayer))
                {
                    nColor = 1;
                }

                nMax = STATLIST_UnitGetStatValue(pPlayer, STAT_MAXCOLDRESIST, 0);
                break;

            case STAT_POISONRESIST:
                if (STATES_CheckStateMaskRPBlueOnUnit(pPlayer))
                {
                    nColor = 3;
                }

                if (STATES_CheckStateMaskRPRedOnUnit(pPlayer))
                {
                    nColor = 1;
                }

                nMax = STATLIST_UnitGetStatValue(pPlayer, STAT_MAXPOISONRESIST, 0);
                break;
            }

            if (GAME_IsExpansion())
            {
                nValue += pDifficultyLevelsTxtRecord->dwResistPenalty;
            }
            else
            {
                switch (GAME_GetDifficulty())
                {
                case 1:
                    nValue -= 20;
                    break;

                case 2:
                    nValue -= 50;
                    break;
                }
            }

            nMax += 75;
            nMax = D2_MIN(nMax, 95);
            nValue = D2_MIN(D2_MAX(nValue, -100), nMax);
            if (nValue >= nMax && nColor != 3)
            {
                nColor = 4;
            }
            else if (nValue < 0)
            {
                nColor = 1;
            }

            wsprintfA((char*)anNumber, "%ld", nValue);
            break;
        }
        case STAT_ARMORCLASS:
            nValue = UNITS_GetDefense(pPlayer);
            if (STATES_CheckStateMaskArmBlueOnUnit(pPlayer))
            {
                nColor = 3;
            }

            if (pPlayer->pInventory && INVENTORY_GetEquippedShield(pPlayer->pInventory, 0) && STATES_CheckState(pPlayer, STATE_HOLYSHIELD))
            {
                nColor = 3;
            }

            if (STATES_CheckStateMaskArmRedOnUnit(pPlayer))
            {
                nColor = 1;
            }

            wsprintfA((char*)anNumber, "%ld", nValue);
            if (nValue >= 1000 || STRTABLE_GetLanguage() == 6)
            {
                bCheckWidth = 1;
            }
            break;

        case STAT_NEXTEXP:
        {
            const int nLevel = STATLIST_GetUnitBaseStat(pPlayer, STAT_LEVEL, 0);
            const int nClass = GAME_GetUnitClassId(pPlayer);
            if (nLevel != DATATBLS_GetMaxLevel(nClass))
            {
                nValue = DATATBLS_GetLevelThreshold(nClass, nLevel);
            }

            STR_GroupUintDigits(wszText, nValue, 0x80);
            TEXT_DrawCenteredText(gaCharFields[i].nX + gnPanelOffsetX, gaCharFields[i].nY + gnPanelOffsetY + gnScreenHeight - 0x1E0, gaCharFields[i].nX2 + gnPanelOffsetX, wszText, 0);
            nColor = 0;
            continue;
        }
        case STAT_EXPERIENCE:
            STR_GroupUintDigits(wszText, nValue, 0x80);
            TEXT_DrawCenteredText(gaCharFields[i].nX + gnPanelOffsetX, gaCharFields[i].nY + gnPanelOffsetY + gnScreenHeight - 0x1E0, gaCharFields[i].nX2 + gnPanelOffsetX, wszText, 0);
            nColor = 0;
            continue;

        default:
            if (nValue > nBase)
            {
                nColor = 3;
            }
            else if (nValue < nBase)
            {
                nColor = 1;
            }

            wsprintfA((char*)anNumber, "%ld", nValue);
            break;
        }

        win2Unicode(wszText, (const char*)anNumber, 0x80);
        wszText[0x7F].wChar = 0;
        if (bCheckWidth)
        {
            nFont = 0xE;
            int nNewFont;
            if (nValue >= 1000)
            {
                nNewFont = D2Win_10127_SetFont(0);
            }
            else
            {
                D2Win_10131_GetTextDimensions(wszText, &nWidth, &nHeight);
                if (nWidth < gaCharFields[i].nX2 - gaCharFields[i].nX)
                {
                    goto DRAW_FIELD;
                }

                nNewFont = D2Win_10127_SetFont(0);
            }

            nFont = nNewFont;
        }
        else
        {
            nFont = 0xE;
        }

DRAW_FIELD:
        TEXT_DrawCenteredText(gaCharFields[i].nX + gnPanelOffsetX, gaCharFields[i].nY + gnPanelOffsetY + gnScreenHeight - 0x1E0, gaCharFields[i].nX2 + gnPanelOffsetX, wszText, nColor);
        nColor = 0;
        if (nFont != 0xE)
        {
            D2Win_10127_SetFont(nFont);
        }
    }
}

// 0x004A89D0
D2SkillDescTxt* __fastcall sub_004A89D0_SkillDescRec(int nSkillId)
{
    D2SkillsTxt* pSkillsTxt = CLIENT_GetSkillsTxtRecord(nSkillId);
    if (pSkillsTxt)
    {
        const int nSkillDesc = pSkillsTxt->wSkillDesc;
        if (nSkillDesc >= 0 && nSkillDesc < sgptDataTables->nSkillDescTxtRecordCount)
        {
            return &sgptDataTables->pSkillDescTxt[nSkillDesc];
        }
    }
    return 0;
}

extern "C" void __cdecl D2CLIENT_CloseNPCTalk(); // 0x004A17D0
extern "C" void __cdecl TEXT_EatMsg(); // 0x0049DA10
extern "C" void __cdecl TEXT_KeyUpMsg(); // 0x004A1770
extern "C" void __cdecl TEXT_HotkeyMsg(); // 0x004A1870
extern "C" void __cdecl TEXT_KeyDownMsg(); // 0x004A18C0
extern "C" void __cdecl TEXT_RegisterPressMsgHandler(); // 0x004A6000
extern "C" void __cdecl TEXT_WheelCaptureMsg(); // 0x004A6310
extern "C" void __cdecl TEXT_ButtonCaptureMsg(); // 0x004A6350
extern "C" void __cdecl sub_004A63B0_WheelMsgHandler(); // 0x004A63B0

#pragma pack(push, 1)
struct d2data_00724810_t
{
    const void* p0;
    unsigned char b1[4];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_007247D8_t
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
};
#pragma pack(pop)

extern "C" struct d2data_00724810_t gData_00724810; // 0x00724810
extern "C" const D2HoverBoxStrc gData_006DA430[2]; // 0x006DA430
extern "C" struct d2data_007247D8_t gData_007247D8; // 0x007247D8

extern "C" struct d2data_00724810_t gData_00724810 = {
    (const void*)"14",
    { 0x00 }
}; // 0x00724810

extern "C" const D2HoverBoxStrc gData_006DA430[2] = {
    { 154, 115, 159, 128, 159, 140 },
    { 154, 130, 159, 143, 159, 155 }
}; // 0x006DA430
#pragma comment(linker, "/alternatename:?gaHoverBoxes@@3PAUD2HoverBoxStrc@@A=_gData_006DA430")

extern D2CharTextStrc gaCharTexts[15] = {
    { 11, 44, 52, 0xFD9, 6 },
    { 65, 44, 180, 0xFDA, 11 },
    { 193, 44, 308, 0xFDB, 11 },
    { 10, 97, 73, 0xFDC, 9 },
    { 10, 160, 73, 0xFDE, 10 },
    { 174, 207, 268, 0xFE0, 8 },
    { 10, 245, 73, 0xFE2, 9 },
    { 174, 245, 228, 0xFE3, 8 },
    { 174, 269, 228, 0xFE4, 5 },
    { 10, 307, 73, 0xFE5, 7 },
    { 174, 307, 228, 0xFE6, 5 },
    { 190, 346, 268, 0xFE7, 5 },
    { 190, 370, 268, 0xFE8, 5 },
    { 190, 395, 268, 0xFE9, 10 },
    { 190, 419, 268, 0xFEA, 7 }
}; // 0x00724818

extern D2CharFieldStrc gaCharFields[18] = {
    { 13, 59, 53, 12 },
    { 67, 59, 180, 13 },
    { 195, 59, 308, 30 },
    { 77, 99, 112 },
    { 77, 161, 112, 2 },
    { 273, 209, 307, 31 },
    { 77, 247, 112, 3 },
    { 232, 246, 267, 11 },
    { 273, 246, 308, 10 },
    { 232, 270, 267, 7 },
    { 273, 270, 308, 6 },
    { 77, 308, 112, 1 },
    { 232, 308, 267, 9 },
    { 273, 308, 308, 8 },
    { 273, 348, 307, 39 },
    { 273, 372, 307, 43 },
    { 273, 396, 307, 41 },
    { 273, 420, 307, 45 }
}; // 0x00724928

extern D2BeltSlotStrc gaStatButtons[4] = {
    { 117, 105 },
    { 117, 167, 0, 2 },
    { 117, 253, 0, 3 },
    { 117, 315, 0, 1 }
}; // 0x00724A48

extern "C" struct d2data_007247D8_t gData_007247D8 = {
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
    (const void*)"Unknown"
}; // 0x007247D8
