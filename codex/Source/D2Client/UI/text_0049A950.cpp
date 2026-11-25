#include "D2Client.h"
#include "D2CelContext.h"
#include "D2ClientTypes.h"
#include "D2ClientUi.h"
#include "D2StormTypes.h"
#include "D2Primitives.h"
#include "D2Structs.h"
#include "D2Unicode.h"
#include "D2ClientQuestLog.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct Unicode;

struct D2RectStrc;

struct D2TextListStrc;

struct D2MsgHandlerEntryStrc;

class ListBoxWrapper;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

int __cdecl GAME_IsExitPending(); // 0x0044DA30

void __cdecl GAME_ResetMouseState(); // 0x0044DA40

void __fastcall sub_00451E10_RegisterHandlerTable(int hWnd, D2MsgHandlerEntryStrc* pTable, int nCount); // 0x00451E10

void __cdecl UI_RegisterKeyConfigHandlers(); // 0x00454980

int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

void __cdecl SELECT_ClearSelection(); // 0x00466FE0

void __fastcall sub_00467430(D2RectStrc* pRect); // 0x00467430

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

unsigned short __fastcall CUNIT_GetHotkeyBinding(int nA, int nB); // 0x00469AA0

void __fastcall CUNIT_ClearHotkeyBinding(int nId, int nB); // 0x00469D70

int __fastcall CUNIT_HasHotkeyBinding(int nA, int nB); // 0x00469D90

void __fastcall MSG_SendTwoDwords(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0

void __cdecl TEXT_FreeTextPanelCels(); // 0x0049FE10

bool __stdcall sub_004A2970(int nX, int nY); // 0x004A2970

void __fastcall QUESTLOG_ToggleQuestLog(int nMode); // 0x004A3FE0

void __fastcall TEXT_MoveKeyConfigSelection(int nStep); // 0x004A45C0


int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00

void __fastcall sub_004EF990_SetSkillPopUpText(D2UnitStrc* pUnit, int nId, int nA, int nB, int nState, int nX, int nY); // 0x004EF990

int __cdecl WINDOW_GetWindow(); // 0x004F59A0

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820

void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

extern int gnScreenWidth; // 0x0071146C

extern D2MsgHandlerEntryStrc gaKeyCaptureMButtonHandlers[]; // 0x0072472C

extern D2MsgHandlerEntryStrc gaKeyCaptureHandlers[]; // 0x00724738

extern D2MsgHandlerEntryStrc gaKeyCaptureXButtonHandlers[]; // 0x00724780

extern D2MsgHandlerEntryStrc gaKeyCaptureWheelHandlers[]; // 0x0072478C

extern int gnPanelOffsetX; // 0x007A2858

extern int gnPanelOffsetY; // 0x007A285C

extern int gbRosterButtonDown; // 0x007BF030

extern char gbSent; // 0x007BF085

extern char gData_007BF1B0[]; // 0x007BF1B0

extern unsigned long gnStartTick; // 0x007BF22C

extern int gnTextLeft; // 0x007BF278

extern int gtQuestLog; // 0x007BF298

extern int gbKeyCaptureActive; // 0x007C02B8

class ListBoxWrapper
{
public:
    virtual ~ListBoxWrapper();
};

void __fastcall DIALOG_DestroyDialog(void* pRes); // 0x004B8020

extern D2ClientDialogStrc* gpListDialog; // 0x007BF1B0

char gbGlobal_007BF2B0; // 0x007BF2B0

char gbQuestDescriptionOpen; // 0x007BF2B3

#define SOUND_ID 4

int __stdcall QUESTLOG_IsMouseOnQuestButton(int nX, int nY); // 0x004A2970

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

extern "C" PackedNode* gListHead_007BF1E4;

extern "C" { unsigned char gByte_007BF2B1; } // 0x007BF2B1

extern "C" unsigned char gByte_007BF2B2; // 0x007BF2B2

extern "C" unsigned char gByte_007BF2B0; // 0x007BF2B0

extern "C" int gSentinel_007BF2B5; // 0x007BF2B5

extern "C" unsigned char gByte_007BF2B4; // 0x007BF2B4

extern "C" unsigned char gByte_007C025D; // 0x007C025D

extern "C" unsigned char gByte_007C025E; // 0x007C025E

extern "C" unsigned char gByte_007C025F; // 0x007C025F

extern "C" unsigned char gByte_007C0260; // 0x007C0260

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

extern "C" int gSelected_007BF280[];

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

struct UnitView
{
    int type;
    char unused4[0x10];
    PayloadView* payload;
};

typedef char PayloadView_size[(sizeof(PayloadView)==0x28)?1:-1];

typedef char PayloadView_flags_offset[(FIELD_OFFSET(PayloadView,flags)==0x16)?1:-1];

typedef char PayloadView_modifiers_offset[(FIELD_OFFSET(PayloadView,modifiers)==0x1c)?1:-1];

typedef char PayloadView_value_offset[(FIELD_OFFSET(PayloadView,value26)==0x26)?1:-1];

typedef char UnitView_size[(sizeof(UnitView)==0x18)?1:-1];

typedef char UnitView_payload_offset[(FIELD_OFFSET(UnitView,payload)==0x14)?1:-1];

struct D2QuestTextsStrc;

struct D2UiEntry10Strc;

struct D2QuestPanelEntryStrc;

struct D2QuestSlotRectStrc;

struct D2ButtonLayoutStrc;

struct D2QuestTableStrc;

union D2SeedStrc;

extern D2UiEntry10Strc gaQuestLookup[41]; // 0x00723F38

extern int gaQuestPageDefault[5]; // 0x007BF280


D2BitBufferStrc* __cdecl MONSTER_GetQuestFlags(); // 0x004B32D0

int __stdcall QUESTRECORD_GetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C310

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

unsigned char __stdcall DRLG_GetActNoFromLevelId(int nLevelId); // 0x006427F0

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

void __stdcall TEXT_LoadQuestPage(int nPage, int nArg); // 0x004A3220

void __cdecl GAME_ResetMouseButtons(); // 0x0044DA70

int __cdecl GAME_IsExpansion(); // 0x0044DCC0

void __fastcall WARDENCLIENT_OpenTextPanel(unsigned short nStringId, int bSide, int bSound); // 0x004A1320

void __fastcall TEXT_SetTextCallback(D2TextCallback pfnCallback, void* pContext); // 0x0049E7E0

int __fastcall QUESTLOG_CloseQuestText(void* pContext, int nArg, int nValue); // 0x004A27B0

extern D2QuestSlotRectStrc gaQuestSlots[]; // 0x00723EB0

int gnQuestCount; // 0x007BF2A0

extern char gbGlobal_007BF2B2; // 0x007BF2B2

extern char gbGlobal_007BF2B4; // 0x007BF2B4

extern D2QuestPanelEntryStrc gaQuestEntries[]; // 0x007BF3AA

char gbGlobal_007C025D; // 0x007C025D

char gbGlobal_007C025E; // 0x007C025E

char gbGlobal_007C025F; // 0x007C025F

char gbGlobal_007C0260; // 0x007C0260

int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

void __fastcall MSG_SendWord(unsigned char nCmd, unsigned short nArg); // 0x004785B0

void __stdcall QUESTRECORD_SetQuestState(D2BitBufferStrc* pQuestFlags, int nQuestId, int nState); // 0x0065C360

extern int gnQuestAct; // 0x007BF2A4

extern int gnQuestParam; // 0x007BF2AC

extern int gnIndex_007BF2BD; // 0x007BF2BD

extern int gnIndex_007BF2C1; // 0x007BF2C1

extern int gnIndex_007BF2C5; // 0x007BF2C5

extern int gnIndex_007BF2C9; // 0x007BF2C9

extern int gnIndex_007BF2CD; // 0x007BF2CD

extern void* gapQuestIconCels[27]; // 0x007BF2E1

extern volatile char gabQuestFlagsB[]; // 0x007BF380


int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0

int __cdecl sub_0045AE90(); // 0x0045AE90

int __cdecl CUNIT_IsPlayerDeadOrMissing(); // 0x00463DF0

D2CelStrc* __stdcall CelGetHandle(D2CelContextStrc* pContext); // 0x00601840

int __stdcall CelGetWidth(D2CelStrc* pCel); // 0x006018C0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

extern D2ButtonLayoutStrc gaButtonLayouts[]; // 0x007241C0

extern void* gpLevelCel; // 0x007C02DC

extern void* gpLevelSocketCel; // 0x007C02E0


extern D2QuestTableStrc gaQuestTable[]; // 0x00723F30

typedef void (__stdcall* B27RecordHandler)(int, int, int);

typedef int (__cdecl* B27UIAction)();

extern "C" int __cdecl NPCMENU_ResurrectMercWait(); // 0x004B1DD0

extern "C" int __cdecl NPCMENU_IdentifyItemsWait(); // 0x004B2020

extern "C" unsigned int gB27_00726CC1;

extern "C" unsigned short gB27_00726CCB;

extern "C" unsigned int gB27_00726CDB;

extern "C" unsigned int gB27_00726DF9;

extern "C" unsigned short gB27_00726E01;

extern "C" unsigned int gB27_00726E0F;

extern "C" unsigned int gB27_00726E47;

extern "C" unsigned short gB27_00726E4F;

extern "C" unsigned int gB27_00726E5D;

extern "C" unsigned int gB27_00726E95;

extern "C" unsigned short gB27_00726E9D;

extern "C" unsigned int gB27_00726EAB;

extern "C" unsigned int gB27_00726EBC;

extern "C" unsigned short gB27_00726EC2;

extern "C" B27UIAction gB27_00726ECE;

extern "C" unsigned int gB27_00726EE3;

extern "C" unsigned short gB27_00726EE9;

extern "C" B27UIAction gB27_00726EF5;

extern "C" unsigned int gB27_00726F0A;

extern "C" unsigned short gB27_00726F10;

extern "C" B27UIAction gB27_00726F1C;

extern "C" unsigned int gB27_00726F31;

extern "C" unsigned short gB27_00726F37;

extern "C" B27UIAction gB27_00726F43;

extern "C" unsigned int gB27_00726F7F;

extern "C" unsigned short gB27_00726F85;

extern "C" unsigned short gB27_00726F87;

extern "C" unsigned int gB27_00726F91;

extern "C" unsigned int gB27_00726F95;

extern "C" unsigned int gB27_00727216;

extern "C" unsigned short gB27_0072721C;

extern "C" B27UIAction gB27_00727228;

extern "C" unsigned int gB27_0072723D;

extern "C" unsigned short gB27_00727247;

extern "C" unsigned int gB27_00727257;

extern "C" unsigned int gB27_0072728B;

extern "C" unsigned short gB27_00727297;

extern "C" unsigned int gB27_007272A9;

extern "C" unsigned int gB27_007272D9;

extern "C" unsigned short gB27_007272E1;

extern "C" B27UIAction gB27_007272EB;

extern "C" unsigned int gB27_007272EF;

extern "C" int gB27_007BCBF0;

extern "C" int gB27_007BF298; // 0x007BF298

extern "C" unsigned char gB27_007C025F; // 0x007C025F

extern "C" unsigned int gB27_007C0265; // 0x007C0265

// build: symbol _gpfnRecordHandler 0x00881834
extern "C" B27RecordHandler gpfnRecordHandler;

extern "C" unsigned int gB27_00883D70;

D2UnitStrc* __fastcall CUNIT_FindServerSideUnit(unsigned int nUnitId, int nUnitType); // 0x004639B0

extern unsigned int gnQuestUnitId; // 0x007C0261

D2UnitStrc* __fastcall CUNIT_SpawnPresetUnit(int nIndex, int nX, int nY, int nUnitType, int nMode); // 0x00466730

char gabQuestFlagsA[42]; // 0x007BF356

extern "C" B27RecordHandler __fastcall sub_005173D3_ExchangeRecordHandler(B27RecordHandler handler); // 0x005173D3

static inline int TEXT_FindEntryIndex(int nId);



D2UnitStrc* __cdecl SELECT_GetSelectedUnit(); // 0x00467A10

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

void __stdcall sub_004A1770(SMSGHANDLER_PARAMS* pMsg); // 0x004A1770

extern int gdwGlobal_007BF23F; // 0x007BF23F

extern unsigned char gbTextHoverSet; // 0x007BF23A

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

// 0x004A1760
int __cdecl TEXT_Forward()
{
    return sub_004A08C0();
}

// 0x004A1770
void __stdcall TEXT_KeyUpMsg(SMSGHANDLER_PARAMS* pMsg)
{
// build: symbol ?gbTextPanelOpen@* 0x007BF1FA
    gbTextPanelOpen = 0;
    if (GetTickCount() - gnStartTick < 100)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
// build: symbol ?gbTextCallbackAccepted@* 0x007BF23F
        gbTextCallbackAccepted = 0;
        return;
    }

    if (sub_004A08C0())
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}

// 0x004A17D0
void __stdcall sub_004A17D0(SMSGHANDLER_PARAMS* pMsg)
{
    gdwGlobal_007BF23F = 1;
    if (SELECT_GetSelectedUnit())
    {
// build: symbol ?gnTextNpcId@* 0x007BF202
// build: symbol ?gbTextFromObject@* 0x007BF20A
        if (gbTextFromObject && CUNIT_FindClientUnit(gnTextNpcId, 1) == SELECT_GetSelectedUnit())
            return;
    }
    else if (!SELECT_GetSelectedUnit() && gbTextHoverSet)
    {
// build: symbol ?gnTextHoverUnitId@* 0x007BF23B
        D2UnitStrc* pUnit = CUNIT_FindClientUnit(gnTextHoverUnitId, 1);
        if (pUnit && pUnit == CUNIT_FindClientUnit(gnTextNpcId, 1))
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






// build: symbol _TEXT_ClearListFlags 0x004A01E0
extern "C" void __cdecl TEXT_ClearListFlags(void)
{
    for (PackedNode* p = gListHead_007BF1E4; p; p = p->next)
        p->value = 0;
}




void __cdecl QUESTLOG_FreeQuestCels(); // 0x004A2550

static void sub_004A2390_ResetQuestSelection()
{
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




int __fastcall QUESTLOG_CloseQuestText(void* pContext, int nArg, int nValue); // 0x004A27B0




int __stdcall QUESTLOG_IsMouseOnQuestButton(int nX, int nY); // 0x004A2970

// build: symbol _CUNIT_IsInvPanelTradeMode 0x00489840
extern "C" int __cdecl INV_IsInvPanelTradeMode()
{
    int mode = gB27_007BCBF0;
    if (mode == 1 || mode == 2 || mode == 3)
        return 1;
    return 0;
}

// build: symbol _NPCMENU_ResetHandlers 0x004B2250
extern "C" void __cdecl NPCMENU_ResetHandlers()
{
    bool oldAction = (gB27_007272EB == NPCMENU_ResurrectMercWait);
    gB27_00726DF9 = 2;
    gB27_00726E01 = 0;
    gB27_00726E0F = 0;
    gB27_00726E47 = 2;
    gB27_00726E4F = 0;
    gB27_00726E5D = 0;
    gB27_00726E95 = 2;
    gB27_00726E9D = 0;
    gB27_00726EAB = 0;
    gB27_00726CC1 = 3;
    gB27_00726CCB = 0;
    gB27_00726CDB = 0;
    gB27_007272D9 = 2;
    gB27_007272E1 = 0;
    gB27_007272EF = 0;
    if (oldAction)
        gB27_007272D9 = 3;
    gB27_00727247 = 0;
    gB27_00727257 = 0;
    gB27_00727297 = 0;
    gB27_007272A9 = 0;
    gB27_00726F7F = 2;
    gB27_00726F87 = 0;
    gB27_00726F95 = 0;
    gB27_00726F85 = 0;
    gB27_00726F91 = 0;
    gB27_0072723D = 3;
    gB27_0072728B = 4;
    gB27_00726EC2 = 0xfb4;
    gB27_00726ECE = NPCMENU_IdentifyItemsWait;
    gB27_00726EBC = 3;
    gB27_00726EE9 = 0xfb4;
    gB27_00726EF5 = NPCMENU_IdentifyItemsWait;
    gB27_00726EE3 = 3;
    gB27_00726F10 = 0xfb4;
    gB27_00726F1C = NPCMENU_IdentifyItemsWait;
    gB27_00726F0A = 3;
    gB27_00726F37 = 0xfb4;
    gB27_00726F43 = NPCMENU_IdentifyItemsWait;
    gB27_00726F31 = 3;
    gB27_0072721C = 0xfb4;
    gB27_00727228 = NPCMENU_IdentifyItemsWait;
    gB27_00727216 = 3;
}

// build: symbol @PLAYER_SetVirtualPlayerCount@* 0x00535780
extern "C" void __fastcall PLAYER_SetVirtualPlayerCount(unsigned int count)
{
    if (count <= 8)
        gB27_00883D70 = count;
}

static inline unsigned int SEED_RollRandomNumber(D2SeedStrc* pSeed)
{
    unsigned __int64 lSeed = (unsigned __int64)pSeed->nHighSeed + (unsigned __int64)pSeed->nLowSeed * 0x6AC690C5;
    pSeed->nHighSeed = (unsigned int)(lSeed >> 32);
    pSeed->nLowSeed = (unsigned int)lSeed;
    return (unsigned int)lSeed;
}

static inline unsigned int SEED_RollLimitedRandomNumber(D2SeedStrc* pSeed, int nMax)
{
    if (nMax <= 0)
    {
        return 0;
    }

    if ((nMax - 1) & nMax)
    {
        return SEED_RollRandomNumber(pSeed) % nMax;
    }

    return SEED_RollRandomNumber(pSeed) & (nMax - 1);
}

static inline int UNITS_GetUnitId(D2UnitStrc* pUnit)
{
    if (!pUnit) return -1;
    return pUnit->dwUnitId;
}
















// build: symbol @SPELLSEL_GetSkillMaxLevel@* 0x004AA8B0
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

#include "gen/data/Source/D2Client/UI/text_0049A950.inc"
