#include "D2LanguageNames.h"
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
#include "D2CMPApi.h"
#include "D2SoundApi.h"
#include "StormApi2.h"
#include "D2GameApi.h"
#include "D2WinApi2.h"

#define OFFSET(T,F) ((unsigned int)&(((T*)0)->F))

struct D2MsgHandlerEntryStrc;

struct Unicode;

struct D2ClientTabStrc;

struct D2TextListStrc;







struct D2CommonChatIgnoreListStrc;

struct D2TextBoxStrc;


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



extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260




void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0


void __cdecl INV_SetupPanelButtons(); // 0x00487ED0


extern int gbNpcTradeClicked; // 0x007BCBEC




extern int gbInvGoldButtonDown; // 0x007BCE30

extern int gnPetIconPopupState; // 0x007BEECC







void __fastcall AUTOMAP_UnregisterHandlerTable(void* hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451E10

void __fastcall SCMD_RegisterMsgHandlers(void* hWnd, D2MsgHandlerEntryStrc* pTable, unsigned int nCount); // 0x00451DB0


extern D2MsgHandlerEntryStrc gaTextMsgHandlers[]; // 0x00722600


extern "C" __declspec(dllimport) int __stdcall MultiByteToWideChar(unsigned int nCodePage, unsigned long dwFlags, const char* szSource, int nSource, Unicode* wszDest, int nDest); // 0x006CC29C

extern "C" unsigned int __cdecl strlen(const char* szString);


Unicode* __fastcall INV_PrefixColorCode(Unicode* pText, int nDigit); // 0x004521C0

Unicode* __fastcall SCMD_StripColorCodes(Unicode* pText); // 0x00452300


void __fastcall INV_OpenRecipeScroll(const Unicode* wszName, int nUnused, int nArg); // 0x0048BBE0

void __fastcall TEXT_PrintChatLine(const Unicode* wszText, char nColor); // 0x0049E3A0


Unicode* __fastcall sub_005267E0(Unicode* pDest, const Unicode* pSource); // 0x005267E0



extern int gnGameFrame; // 0x007BF20E

static bool TEXT_IsLanguageCompatible(int nLangId);






void __stdcall TEXT_FreeTextList(void* pList); // 0x0049D4D0


D2SplittedTextStrc* __stdcall TEXT_BuildTextLines(const Unicode* wszText, int* pLineCount, unsigned short* pMaxLines); // 0x004A0320


void __fastcall SOUNDINST_ArmHint(int nKey, int nGroup, int nOffset, unsigned int nCount); // 0x004B9EF0

int __fastcall UNICODE_StrLen(const Unicode* pString); // 0x00526800











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








#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt("", sub_00408090(), line); exit(-1); }

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

struct D2HotkeyActionStrc;

struct D2CharStatsTxt;

struct D2MonStatsTxt;







void __stdcall TEXT_LoadQuestPage(int nPage, int nArg); // 0x004A3220


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









static int gnKeyConfigEntryCount; // 0x007C0274



static int gnKeyConfigFirstVisible; // 0x007C02AC

extern int gnAutomapHeight; // 0x007A521C

int gnKeyConfigThumbY = (gnAutomapHeight - 420) / 2 + 47; // 0x007C02CC

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

int gnKeyConfigSelected; // 0x007C02B0

int gbKeyCaptureActive; // 0x007C02B8

int gbKeyConfigPressRepeat; // 0x007C0284


int __stdcall sub_B05_Sink(int nA, int nB);



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



int __cdecl GAME_GetLadderFlag(); // 0x0044DCA0

static int TEXT_GetKeyConfigButtonAt(int nX, int nY);




int gnThumbRange; // 0x007C027C

int gnDragThumbY; // 0x007C02A4

int gnDragMouseY; // 0x007C02A8

unsigned long gdwKeyConfigRepeatTick; // 0x007C02C0







D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80



#define STAT_STATPTS 4

#define STAT_NEWSKILLS 5






enum { REPEAT_MASK = 0x40000000, UI_VARIABLE = 11 };




extern "C" int gnFlag_007C02EC; // 0x007C02EC

void __stdcall CURSOR_HandleButtonUp(SMSGHANDLER_PARAMS* pMsg); // 0x00467FA0



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

void __fastcall SKILLDESC_BuildPropText(D2UnitStrc* pItem, Unicode* wszText, int nArg, int bFlag, int nArg2); // 0x004E6410


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

int gnKeyConfigPressedButton; // 0x007C02B4

int gnMessage; // 0x007C02C4

unsigned int gnBlink; // 0x007C02D0

int gnLastMouseY; // 0x007C02D4

int gnLastMouseX; // 0x007C02D8


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


void __stdcall TEXT_QuestLButtonDownMsg(SMSGHANDLER_PARAMS* pMsg); // 0x004A3E40


void __stdcall TEXT_QuestLButtonUpMsg(SMSGHANDLER_PARAMS* pMsg); // 0x004A42A0

int __stdcall TEXT_GetChanceToHit(int nAttackRate); // 0x004A7340

struct D2QuestTableStrc;

struct D2UiEntry10Strc;




extern D2QuestTableStrc gaQuestTable[41]; // 0x00723F30




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














struct D2BitBufferStrc;

void __stdcall sub_L04_EmitUse(const Unicode* pText);


























































struct D2SetsTxt;











void __fastcall sub_00451E10_RegisterHandlerTable(void* hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10



bool __stdcall sub_004A2970(int nX, int nY); // 0x004A2970

// 0x004A43E0
void __cdecl TEXT_InitKeyConfigEntries()
{
    if (GAME_IsExpansion())
    {
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
        int nPrev = gnKeyConfigFirstVisible;
        if (gnKeyConfigFirstVisible > 0)
            nPrev = gnKeyConfigFirstVisible - 1;
        if (nPrev >= 0)
            gnKeyConfigFirstVisible = nPrev;
    }
    else if (nStep > 0)
    {
        int nNext = gnKeyConfigFirstVisible;
        if (gnKeyConfigFirstVisible < nMax)
            nNext = gnKeyConfigFirstVisible + 1;
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

// 0x004A4AD0
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

            const int nOldSelected = gnKeyConfigSelected;
            const int nOldColumn = gnKeyConfigColumn;
            gnKeyConfigSelected = TEXT_GetKeyConfigLineAt(nY);
            gnKeyConfigColumn = TEXT_IsAbovePanelLine(nX);
            if (gpListEntries[gnKeyConfigSelected].nId == 0x39)
            {
                gnKeyConfigSelected = nOldSelected;
                gnKeyConfigColumn = nOldColumn;
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
    ESCMENU_CloseMenus(1);
}

// 0x004A5040
void __cdecl TEXT_CancelKeyConfig()
{
    CMDTBL_RestoreHotkeys();
    UI_SetUIVar(11, 1, 0);
    WARDENCLIENT_ToggleEscMenuUIState(0, 1);
}

// 0x004A5060
void __cdecl TEXT_LayoutSlider()
{
    const int nOldFont = D2Win_10127_SetFont(13);
    for (unsigned int i = 0; i < 3; ++i)
    {
        const int nWidth = D2Win_10121_GetTextWidth(D2LANG_GetStringFromTblIndex(gaKeyConfigButtons[i].nStringId));
        const int nThird = (sub_F08_PanelRight() - sub_F08_PanelLeft()) / (sizeof(gaKeyConfigButtons) / sizeof(gaKeyConfigButtons[0]));
        gaKeyConfigButtons[i].nLeft = nThird * i + sub_F08_PanelLeft() + nThird / 2 - nWidth / 2 - 10;
        gaKeyConfigButtons[i].nRight = nThird * i + sub_F08_PanelLeft() + nThird / 2 + nWidth / 2 + 10;
        gaKeyConfigButtons[i].nTop = sub_F08_ListTop() + 0x149;
        gaKeyConfigButtons[i].nBottom = sub_F08_ListTop() + 0x16F;
    }
    D2Win_10127_SetFont(nOldFont);

    gnKeyConfigThumbY = sub_F08_TrackSpan() * gnKeyConfigFirstVisible / TEXT_GetMaxFirstEntry() + sub_F08_TrackTop();
}

// 0x004A5190
void __cdecl TEXT_InitTextSlider()
{
    char szPath[0x104];
    TEXT_InitKeyConfigEntries();
    sprintf(szPath, "%s\\UI\\Menu\\TextSlid", gszDataGlobal);
    gpKeyConfigSliderCel = ARCHIVE_LoadClientCellFile(szPath, 0);
    TEXT_LayoutSlider();
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
            CMDTBL_SetHotkeyHandlers(0, 0);
            GAME_UnregisterMouseHandlers();
            SELECT_RefreshHoverUnit(0);
        }
        gnKeyConfigFirstVisible = 0;
        gnKeyConfigSelected = 0;
    }
    else if (gbKeyCaptureActive == 0)
    {
        CMDTBL_SetHotkeyHandlers(1, 0);
        GAME_RegisterMouseHandlers();
        SELECT_ClearSelection();
    }
    TEXT_LayoutSlider();
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

    const int nOldFont = D2Win_10127_SetFont(13);
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

    D2GfxDataStrc tCel;
    memset(&tCel, 0, sizeof(tCel));
    tCel.pCelFile = gpKeyConfigSliderCel;
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

    D2Win_10127_SetFont(nOldFont);
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
    if (gbKeyConfigReady) {
        if (!(message->lParam & REPEAT_MASK)) {
            CMDTBL_RestoreHotkeys();
            UI_SetUIVar(UI_VARIABLE, 1, 0);
            WARDENCLIENT_ToggleEscMenuUIState(0, 1);
            sub_004B9A00(1, 0, 0, 0, 0);
        }
    } else gbKeyConfigReady = 1;
    message->bReturn = 1;
    message->lResult = 0;
    sub_00420290_BreakHandlerChain(message);
}

// 0x004A5D00
void __cdecl TEXT_RegisterKeyCaptureHandlers()
{
    gbKeyCaptureActive = 1;
    UI_ClearPanelHandlers(0xB);
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
        CMDTBL_RestoreHotkeys();
        CMDTBL_SetHotkeyHandlers(1, 0);
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
            TEXT_RegisterKeyCaptureHandlers();
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
            TEXT_RegisterKeyCaptureHandlers();
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
void __stdcall TEXT_RegisterPressMsgHandler(SMSGHANDLER_PARAMS* pMsg)
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


unsigned long gdwMessageTick;                                                                            // 0x007C02C8

// 0x004A60B0
void __stdcall TEXT_KeyDownMsgHandler(SMSGHANDLER_PARAMS* pMsg)
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
            gbKeyConfigReady = 0;
        }
        else
        {
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
void __stdcall TEXT_KeyUpMsgHandler(SMSGHANDLER_PARAMS* pMsg)
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





extern "C" __declspec(dllimport) short __stdcall GetKeyState(int nVirtKey);












extern "C" void __cdecl D2CLIENT_CloseNPCTalk(); // 0x004A17D0
extern "C" void __cdecl TEXT_EatMsg(); // 0x0049DA10
extern "C" void __cdecl TEXT_KeyUpMsg(); // 0x004A1770
extern "C" void __cdecl TEXT_HotkeyMsg(); // 0x004A1870
extern "C" void __cdecl TEXT_KeyDownMsg(); // 0x004A18C0
extern "C" void __cdecl TEXT_WheelCaptureMsg(); // 0x004A6310
extern "C" void __cdecl TEXT_ButtonCaptureMsg(); // 0x004A6350
extern "C" void __cdecl sub_004A63B0_WheelMsgHandler(); // 0x004A63B0

#pragma pack(push, 1)
struct d2data_007246D8_t
{
    unsigned char b0[2];
    const void* p1;
    unsigned char b2[22];
    const void* p3;
    unsigned char b4[22];
    const void* p5;
    unsigned char b6[20];
};
#pragma pack(pop)

extern "C" struct d2data_007246D8_t gData_007246D8; // 0x007246D8

extern int gnKeyConfigColumn = 1; // 0x007246D4

extern int gbKeyConfigReady = 1; // 0x00724728

extern D2ClientListEntryStrc gaKeyConfigEntries[51] = {
    { 0, 0xF54 },
    { 1, 0xF55 },
    { 2, 0xF56 },
    { 3, 0xF57 },
    { 4, 0xF58 },
    { 6, 0xF5D },
    { 57 },
    { 12, 0xF5E },
    { 13, 0x2A51 },
    { 14, 0xF60 },
    { 15, 0xF61 },
    { 16, 0xF62 },
    { 17, 0xF63 },
    { 18, 0xF64 },
    { 19, 0xF65 },
    { 20, 0xF66 },
    { 21, 0xF67 },
    { 39, 0xF68 },
    { 40, 0xF69 },
    { 57 },
    { 22, 0xF6A },
    { 23, 0xF6B },
    { 24, 0xF6C },
    { 25, 0xF6D },
    { 26, 0xF6E },
    { 57 },
    { 5, 0xF59 },
    { 34, 0xF7E },
    { 35, 0xF7F },
    { 36, 0xF80 },
    { 37, 0xF81 },
    { 43, 0xF8E },
    { 57 },
    { 7, 0xF5A },
    { 8, 0xF5B },
    { 9, 0xF8F },
    { 10, 0xF91 },
    { 11, 0xF90 },
    { 57 },
    { 27, 0xF77 },
    { 28, 0xF78 },
    { 29, 0xF79 },
    { 30, 0xF7A },
    { 31, 0xF7B },
    { 32, 0xF7C },
    { 33, 0xF7D },
    { 55, 0x2B4B },
    { 57 },
    { 42, 0xF83 },
    { 38, 0xF82 },
    { 41, 0xF8D }
}; // 0x00724268

extern D2ClientListEntryStrc gaKeyConfigEntriesExp[62] = {
    { 0, 0xF54 },
    { 1, 0xF55 },
    { 2, 0xF56 },
    { 54, 0x58C7 },
    { 3, 0xF57 },
    { 4, 0xF58 },
    { 6, 0xF5D },
    { 57 },
    { 12, 0xF5E },
    { 13, 0x2A51 },
    { 14, 0xF60 },
    { 15, 0xF61 },
    { 16, 0xF62 },
    { 17, 0xF63 },
    { 18, 0xF64 },
    { 19, 0xF65 },
    { 20, 0xF66 },
    { 21, 0xF67 },
    { 46, 0x58BD },
    { 47, 0x58BE },
    { 48, 0x58BF },
    { 49, 0x58C0 },
    { 50, 0x58C1 },
    { 51, 0x58C2 },
    { 52, 0x58C3 },
    { 53, 0x58C4 },
    { 39, 0xF68 },
    { 40, 0xF69 },
    { 57 },
    { 22, 0xF6A },
    { 23, 0xF6B },
    { 24, 0xF6C },
    { 25, 0xF6D },
    { 26, 0xF6E },
    { 44, 0x58C6 },
    { 57 },
    { 5, 0xF59 },
    { 34, 0xF7E },
    { 35, 0xF7F },
    { 36, 0xF80 },
    { 37, 0xF81 },
    { 43, 0xF8E },
    { 57 },
    { 7, 0xF5A },
    { 8, 0xF5B },
    { 9, 0xF8F },
    { 10, 0xF91 },
    { 11, 0xF90 },
    { 45, 0x58C5 },
    { 57 },
    { 27, 0xF77 },
    { 28, 0xF78 },
    { 29, 0xF79 },
    { 30, 0xF7A },
    { 31, 0xF7B },
    { 32, 0xF7C },
    { 33, 0xF7D },
    { 55, 0x2B4B },
    { 57 },
    { 42, 0xF83 },
    { 38, 0xF82 },
    { 41, 0xF8D }
}; // 0x00724468

extern D2MsgHandlerEntryStrc gaKeyCaptureMButtonHandlers[1] = { { 0, 519, (void*)(unsigned int)&TEXT_WheelCaptureMsg } }; // 0x0072472C

extern D2MsgHandlerEntryStrc gaKeyCaptureHandlers[6] = {
    { 0, 513, (void*)(unsigned int)&TEXT_RegisterPressMsgHandler },
    { 0, 516, (void*)(unsigned int)&TEXT_RegisterPressMsgHandler },
    { 0, 256, (void*)(unsigned int)&TEXT_KeyDownMsgHandler },
    { 0, 260, (void*)(unsigned int)&TEXT_KeyDownMsgHandler },
    { 0, 257, (void*)(unsigned int)&TEXT_KeyUpMsgHandler },
    { 0, 261, (void*)(unsigned int)&TEXT_KeyUpMsgHandler }
}; // 0x00724738

extern D2MsgHandlerEntryStrc gaKeyCaptureXButtonHandlers[1] = { { 0, 523, (void*)(unsigned int)&TEXT_ButtonCaptureMsg } }; // 0x00724780

extern D2MsgHandlerEntryStrc gaKeyCaptureWheelHandlers[1] = { { 0, 522, (void*)(unsigned int)&sub_004A63B0_WheelMsgHandler } }; // 0x0072478C

extern "C" struct d2data_007246D8_t gData_007246D8 = {
    { 0x86, 0x0F },
    (const void*)(unsigned int)&TEXT_CancelKeyConfig,
    {
        0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x84, 0x0F
    },
    (const void*)(unsigned int)&TEXT_ResetKeyConfigDefaults,
    {
        0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x85, 0x0F
    },
    (const void*)(unsigned int)&TEXT_AcceptKeyConfig,
    { 0x02 }
}; // 0x007246D8
#pragma comment(linker, "/alternatename:?gaKeyConfigButtons@@3PAUD2SliderButtonStrc@@A=_gData_007246D8")

extern D2ClientListEntryStrc* gpListEntries = (D2ClientListEntryStrc*)&gaKeyConfigEntries; // 0x00724264
