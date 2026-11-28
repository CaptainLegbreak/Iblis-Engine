#include "D2ItemTypes.h"
#include "D2StateIds.h"
#include "D2SkillIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2CelContext.h"
#include "D2ClientUi.h"
#include "D2Unicode.h"
#include "D2StormTypes.h"
#include "D2ClientGfx.h"
#include "D2Path.h"
#include "D2ClientParty.h"
#include "D2ClientTextPanel.h"
#include "FogApi.h"
#include "D2CommonApi.h"
#include "D2LangApi.h"
#include "StormApi.h"
#include "D2CommonApi2.h"
#include "D2GfxApi.h"
#include "D2WinApi2.h"

struct D2ActiveRoomStrc;

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt("", sub_00408090(), line); exit(-1); }

struct BitStreamContext;

struct D2OrbSmoothStrc;

struct Unicode;

struct D2HotkeySlotTableStrc;

struct D2TextPanelLineStrc;

struct D2TextPanelStrc;

struct D2UiRectStrc;

struct D2UiRecordStrc;

struct D2Block1;

struct D2UnitStrc;

struct D2GfxDataStrc;

struct SMSGHANDLER_PARAMS;

struct D2GfxMotionStrc;

struct D2ItemsTxt;

struct D2OrbSmoothStrc
{
    int nValue;
    int nTick;
    int f_8;
    int nPrevTick;
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0



unsigned int __cdecl sub_0044DA90_GetTickCounter(); // 0x0044DA90

int __stdcall sub_004F6480(D2GfxDataStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, unsigned short nLayer); // 0x00625480



D2OrbSmoothStrc gaOrbSmooth[3]; // 0x007BEF30

static int gbControlPanelClicked;        // 0x007BEFA4

extern int gbLeftSkillButtonDown; // 0x007BEF84

extern int gbRightSkillButtonDown; // 0x007BEF88

extern int gdwShowHpText; // 0x007BEFDC

extern int gdwShowMpText; // 0x007BEFE0

static int gbMiniPanelButtonDown;        // 0x007BEFD0

static int gbRunButtonDown;        // 0x007BEFD8





extern "C" const char gszEmptyAssertText; // 0x006CC837



extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09








extern int gnTabSelection; // 0x00724CE0

extern int gnSkillPage; // 0x00724BEC




void* gpPanelQuadCel; // 0x007BF018

extern D2HotkeySlotTableStrc gtHotkeySlots_007C0300; // 0x007C0300




extern int gbSkillSelectRight; // 0x007C07FC

extern int gbSkillTabPressed; // 0x007C0C38







extern "C" int gnScreenWidth; // 0x0071146C

extern "C" int __cdecl sub_00468730_MouseX();

extern "C" int __cdecl sub_00468740_MouseY();


extern "C" const unsigned short* __fastcall sub_00524A30_LocalizedText(unsigned short index);

extern "C" void __fastcall sub_00502280_SetTooltip(const unsigned short* text, int x, int y, int color, int mode);

extern "C" void __stdcall BITMANIP_Write(BitStreamContext* stream, unsigned int value, int bitCount); // 0x00410EB0

extern "C" __declspec(dllimport) short __stdcall GetKeyState(int nVirtKey); // 0x006CC45C

void __stdcall DATATBLS_GetBeltsTxtRecord(int nIndex, int nRow, D2UiRecordStrc* pRecord); // 0x00660CB0

void __stdcall DATATBLS_GetInvRectFromBeltsTxt(int nIndex, int bHigherRes, D2UiRectStrc* pInvRect, int nBoxId); // 0x00660D10











int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00








void __fastcall sub_0049FF90_Close(D2UnitStrc* pItem, D2ItemsTxt* pState); // 0x0049FF90




extern int gnBeltUiRecordRow; // 0x007A5218


static int gnBeltHover; // 0x007BEF94

static int gbUiRecordMode;                                                                                // 0x007BEF98

static int gnBeltRecordMode2; // 0x007BEF9C

D2UnitStrc* gpBeltItemA; // 0x007BEFA8


extern "C" size_t __cdecl strlen(const char* szString);





void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

void __cdecl PARTY_DrawPanelQuad(); // 0x00499E50

void __cdecl PARTY_DrawPartyRows(); // 0x0049C270

void __cdecl PARTY_DrawPartyButtons(); // 0x0049A510

void __cdecl TEXT_DrawPanelCloseButton(); // 0x0049A950

void __cdecl PARTY_DrawRosterHoverHints(); // 0x0049ABD0

void __cdecl PARTY_DrawRosterButtonHints(); // 0x0049B330

void __cdecl PARTY_RefreshRosterIndices(); // 0x0049A9B0


extern int gpBeltItemB; // 0x007BEFAC

extern void* gpPartyBoxesCel; // 0x007BF020

extern unsigned char gnBoxColor; // 0x007BF034

void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0


Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

unsigned char gabBeltHotkey[4]; // 0x007BEFB0

static void __stdcall PANEL_ClickBeltBox(D2InventoryStrc* pInventory, int nX, int nY); // 0x00498870

void __stdcall PANEL_UseBeltSlot(int nSlot, D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, int bShift); // 0x00498A90

static int __stdcall INV_CheckState(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2ItemsTxt* pState); // 0x00498A20

unsigned char gnTextColorRed; // 0x007BEFBA

unsigned char gnTextColorA; // 0x007BEFBB

unsigned char gnTextColorB; // 0x007BEFE4







const Unicode* __fastcall CMDTBL_GetKeyName(int nA, int nB);                                          // 0x0046A530


Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0

int __fastcall UNICODE_StrLen(const Unicode* pString); // 0x00526800

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc* pItem, unsigned int dwFlag, int nLine, const char* szFile);  // 0x006280A0



extern D2CelFileStrc* gpCellFile_007BEF10;                                                                  // 0x007BEF10

unsigned char gabBeltColors[4];                                                                    // 0x007BEF6C

int gbBeltRowsShown;                                                                                      // 0x007BEFA0

void __cdecl VIEW_InitBeltColors(); // 0x004972B0

static void __stdcall PANEL_DrawBeltBoxFrame(int nBox, int nColor); // 0x004978D0

static void __cdecl PANEL_DrawCursorBeltBox(D2InventoryStrc* pInventory); // 0x00497920

void* gpBorderFrameCel; // 0x007BEF18

int gnLevelTimer; // 0x007BEFEC

int gnLevelId; // 0x007BEFF0

void* gpPartyButtonsCel; // 0x007BF01C

void* gpInvGoldBtnCel; // 0x007BF024

void* gpPartyBarCel; // 0x007BF028

void __cdecl PARTY_DrawPlayerName(); // 0x0049A580

int __stdcall STATLIST_GetUnitBaseStat(D2UnitStrc* pUnit, int nStatId, int nLayer);                         // 0x006253B0




struct D2StaticPathStrc;

void __fastcall ITEM_SetUninterruptableState(D2UnitStrc* pItem);

static void PANEL_HoverBeltBox(int nX, D2InventoryStrc* pInventory, int nY); // 0x00498930

struct D2QtyWarnStrc;

Unicode* __fastcall sub_00452170_ReturnText(Unicode* pText); // 0x00452170

Unicode* __fastcall INV_PrefixColorCode(Unicode* pText, int nDigit); // 0x004521C0

D2UnitStrc* __fastcall sub_00463DD0(); // 0x00463DD0

int __cdecl INV_IsInvPanelTradeMode(); // 0x00489840

void __fastcall INV_BuildItemName(D2UnitStrc* pItem, Unicode* pText, int nMaxLength); // 0x0048C060

int __fastcall NPCMENU_GetTradeCostText(D2UnitStrc* pItem, int nArg, int* pOut, Unicode* pName, int nMaxLength); // 0x004B2AD0

void __fastcall sub_004E6410_BuildPropText(D2UnitStrc* pItem, Unicode* wszText, int nUnused, int bFlag, const Unicode* wszExtra); // 0x004E6410

struct D2QtyWarnStrc
{
    int nWarnType;
    int nFrame;
    unsigned int nLevel0;
    unsigned int nLevel1;
    unsigned int nLevel2;
};

extern unsigned char gabSlots[]; // 0x007BEFB4

extern int gaBodyLocs[]; // 0x00722374

extern unsigned int gnBodyLocCount; // 0x0072237C

extern D2QtyWarnStrc gaQtyWarn[]; // 0x00722380

extern unsigned int gnQtyWarnCount; // 0x007223E4

int __fastcall GAME_GetUnitClassId(D2UnitStrc* pUnit); // 0x00451F60

void __stdcall INV_DrawWarningIcon(int nFrame); // 0x00497C50

unsigned char __stdcall ITEMS_GetInvPage(D2UnitStrc* pItem); // 0x00628250






void __cdecl PANEL_DrawBorderFrameLeft(); // 0x00498630

void __cdecl PANEL_DrawBorderFrameRight(); // 0x00498700

void __cdecl PANEL_DrawLifeOrb(); // 0x00496F80

void __cdecl PANEL_DrawManaOrb(); // 0x00497110

void __cdecl PANEL_DrawExperienceBar(); // 0x00498EA0

void __cdecl VIEW_DrawRunButton(); // 0x00497480

void __cdecl PANEL_DrawStaminaBar(); // 0x004975B0

void __cdecl PANEL_DrawMiniPanelButton(); // 0x004977C0

void __cdecl PANEL_DrawBelt(); // 0x00499040

void __cdecl PANEL_ValidateActiveSkills(); // 0x00496CF0

void __cdecl PANEL_DrawBeltItemHoverText();

extern "C" void __cdecl PANEL_UpdateMiniPanelTooltip(); // 0x00498340

void* gpCtrlPnl7Cel; // 0x007BEF1C

void* gp800CtrlPnl7Cel; // 0x007BEF74





static int gbControlPanelMouseDown = 1; // 0x00722358

static int gnGlobal_007BEFD4;        // 0x007BEFD4

void __stdcall PANEL_BeltClickMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00499D10

static void __stdcall PANEL_DrawDurabilityIcon(int nState, int bType, int nQuiverType, int nBodyLoc); // 0x00497CF0


static int __stdcall PANEL_GetBeltBoxAt(int nY, int nX); // 0x004987E0

static void PANEL_BeltHotkey(int nSlot);





void __stdcall PANEL_BeltMouseMove(SMSGHANDLER_PARAMS* __restrict pMsg); // 0x00499BB0

static void __stdcall PANEL_UseBeltSlot(int nSlot, D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, int bShift); // 0x00498A90

static void PANEL_HoverBeltBox(int nX, D2InventoryStrc* pInventory, int nY); // 0x00498930

void __stdcall PANEL_BeltMouseMove(SMSGHANDLER_PARAMS* pMsg); // 0x00499BB0

static int ORB_AbsValue(int nValue)
{
    return nValue < 0 ? -nValue : nValue;
}

// 0x00496CF0
void __cdecl PANEL_ValidateActiveSkills()
{
    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
    if (!pPlayer)
    {
        return;
    }
    D2SkillStrc* pSkill = UNITS_GetLeftSkill(pPlayer);
    if (pSkill && SKILLS_GetSkillLevel(pPlayer, pSkill, 1) <= 0)
    {
        SKILLS_RemoveSkill(pPlayer, SKILLS_GetSkillIdFromSkill(pSkill, ".\\UI\\panel.cpp", 0x289), ".\\UI\\panel.cpp", 0x289);
        SKILLS_SetLeftActiveSkill(pPlayer, SKILL_ATTACK, -1);
        pSkill = UNITS_GetLeftSkill(pPlayer);
    }
    WARDENCLIENT_DrawSkillInfo(pPlayer, pSkill, 0x75, gnScreenHeight, 1);
    pSkill = UNITS_GetRightSkill(pPlayer);
    if (pSkill && SKILLS_GetSkillLevel(pPlayer, pSkill, 1) <= 0)
    {
        SKILLS_RemoveSkill(pPlayer, SKILLS_GetSkillIdFromSkill(pSkill, ".\\UI\\panel.cpp", 0x294), ".\\UI\\panel.cpp", 0x294);
        SKILLS_SetRightActiveSkill(pPlayer, SKILL_ATTACK, -1);
        pSkill = UNITS_GetRightSkill(pPlayer);
    }
    WARDENCLIENT_DrawSkillInfo(pPlayer, pSkill, gnScreenWidth - 0xA5, gnScreenHeight, 0);
}

// 0x00496DD0
static int PANEL_GetSmoothedOrbValue(int nStatId)
{
    int bCheckDrop = 1;
    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
    int nValue = STATLIST_UnitGetStatValue(pPlayer, nStatId, 0);
    int nIndex;
    int nMax = 0;
    switch (nStatId)
    {
    case 6:
        nMax = STATLIST_GetMaxLifeFromUnit(pPlayer);
        nIndex = 0;
        bCheckDrop = 0;
        break;
    case 8:
        nMax = STATLIST_GetMaxManaFromUnit(pPlayer);
        nIndex = 1;
        break;
    case 10:
        nMax = STATLIST_GetMaxStaminaFromUnit(pPlayer);
        nIndex = 2;
        break;
    }

    if (!nMax)
        return 0;

    if (sub_0044DA90_GetTickCounter() <= 1)
    {
        gaOrbSmooth[nIndex].f_8 = nValue;
        gaOrbSmooth[nIndex].nValue = nValue;
    }

    if (!bCheckDrop && nValue < gaOrbSmooth[nIndex].nValue)
    {
        gaOrbSmooth[nIndex].f_8 = nValue;
        gaOrbSmooth[nIndex].nValue = nValue;
        const unsigned int nTick = sub_0044DA90_GetTickCounter();
        gaOrbSmooth[nIndex].nTick = nTick;
        gaOrbSmooth[nIndex].nPrevTick = nTick;
    }

    const int nLast = gaOrbSmooth[nIndex].nValue;
    if (nLast != nValue)
    {
        const int nDiff = ORB_AbsValue(nLast - nValue);

        if (nDiff >= nMax / 8)
        {
            gaOrbSmooth[nIndex].f_8 = nValue;
            gaOrbSmooth[nIndex].nPrevTick = sub_0044DA90_GetTickCounter();
        }
        else
        {
            gaOrbSmooth[nIndex].nPrevTick = gaOrbSmooth[nIndex].nTick;
            if (nValue == nMax)
                gaOrbSmooth[nIndex].f_8 = nValue;
            else
                gaOrbSmooth[nIndex].f_8 = nLast;
        }
        gaOrbSmooth[nIndex].nValue = nValue;
        gaOrbSmooth[nIndex].nTick = sub_0044DA90_GetTickCounter();
    }

    const int nStart = gaOrbSmooth[nIndex].nTick;
    const int nElapsed = sub_0044DA90_GetTickCounter() - nStart;
    int nDuration = nStart - gaOrbSmooth[nIndex].nPrevTick;
    if (nDuration < 7)
        nDuration = 7;
    else if (nDuration > 15)
        nDuration = 15;

    if (nValue > 0 && nElapsed < nDuration)
    {
        const int nFrom = gaOrbSmooth[nIndex].f_8;
        const int nDelta = gaOrbSmooth[nIndex].nValue - nFrom;
        if (nDelta)
        {
            nValue = (int)((double)(nElapsed + 1) / nDuration * nDelta) + nFrom;
        }
    }

    if (nValue < 0)
        nValue = 0;
    else if (nValue > nMax)
        nValue = nMax;
    return nValue;
}

// 0x00496F80
void __cdecl PANEL_DrawLifeOrb()
{
    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
    const int nLife = PANEL_GetSmoothedOrbValue(6);
    const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pPlayer);
    if (!nMaxLife)
        return;

    int nHeight = 80 * nLife / nMaxLife;
    if (nHeight >= 1 && nHeight <= 2)
    {
        D2UnitStrc* pUnit = CUNIT_GetPlayerUnit();
        if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->dwAnimMode != 0x11)
            nHeight = 2;
    }

    D2GfxDataStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.nDirection = 0;
    tContext.pCelFile = gpHlthManaCel;
    tContext.nFrame = 0;
    if (STATES_CheckState(CUNIT_GetPlayerUnit(), STATE_HEALTHPOT))
    {
        int nPoison = 80 * STATLIST_UnitGetStatValue(CUNIT_GetPlayerUnit(), STAT_HPREGEN, 0) / 100;
        if (nPoison > 80)
            nPoison = 80;
        if (nPoison > nHeight)
        {
            if (D2GFX_GetDisplayType() == 6)
                TEXTURE_CelDrawEx(&tContext, 0x1C, gnScreenHeight - 0xD, nHeight, nPoison - nHeight, 0);
            else
                TEXTURE_CelDrawEx(&tContext, 0x1D, gnScreenHeight - 0xD, nHeight, nPoison - nHeight, 0);
        }
    }

    tContext.nFrame = STATES_CheckState(CUNIT_GetPlayerUnit(), STATE_POISON) ? 2 : 0;
    if (nHeight)
    {
        switch (D2GFX_GetDisplayType())
        {
        case 1:
        case 3:
            TEXTURE_CelDrawEx(&tContext, 0x1D, gnScreenHeight - 0xD, 0, nHeight, 5);
            break;
        default:
            TEXTURE_CelDrawEx(&tContext, 0x1D, gnScreenHeight - 0xD, 0, nHeight, 5);
            break;
        }
    }

    tContext.pCelFile = gpOverlapCel;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, 0x1C, gnScreenHeight - 5, -1, 5, 0);
}

// 0x00497110
void __cdecl PANEL_DrawManaOrb()
{
    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
    int nMana = PANEL_GetSmoothedOrbValue(8);
    const int nMaxMana = STATLIST_GetMaxManaFromUnit(pPlayer);
    if (!nMaxMana)
        return;

    if (nMana > nMaxMana)
        nMana = nMaxMana;
    const int nHeight = 80 * nMana / nMaxMana;

    D2GfxDataStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.nDirection = 0;
    tContext.pCelFile = gpHlthManaCel;
    tContext.nFrame = 1;
    if (STATES_CheckState(CUNIT_GetPlayerUnit(), STATE_MANAPOT))
    {
        int nShield = 80 * STATLIST_UnitGetStatValue(CUNIT_GetPlayerUnit(), STAT_MANARECOVERY, 0) / 100;
        if (nShield > 80)
            nShield = 80;
        if (nShield > nHeight)
        {
            if (D2GFX_GetDisplayType() == 6)
                TEXTURE_CelDrawEx(&tContext, gnScreenWidth - 0x70, gnScreenHeight - 0xD, nHeight, nShield - nHeight, 0);
            else
                TEXTURE_CelDrawEx(&tContext, gnScreenWidth - 0x6F, gnScreenHeight - 0xD, nHeight, nShield - nHeight, 0);
        }
    }

    switch (D2GFX_GetDisplayType())
    {
    case 1:
    case 3:
        TEXTURE_CelDrawEx(&tContext, gnScreenWidth - 0x6F, gnScreenHeight - 0xD, 0, nHeight, 5);
        break;
    default:
        TEXTURE_CelDrawEx(&tContext, gnScreenWidth - 0x6F, gnScreenHeight - 0xD, 0, nHeight, 5);
        break;
    }

    tContext.pCelFile = gpOverlapCel;
    tContext.nFrame = 1;
    sub_004F6480(&tContext, gnScreenWidth - 0x6E, gnScreenHeight - 9, -1, 5, 0);
}

void __cdecl INV_DrawKeyBindingPopup(); // 0x00497300




static int ButtonHitTest_00497480(int nX, int nY)
{
    int nHeight = gnScreenHeight;
    int nWidth = gnScreenWidth;
    return nX >= nWidth / 2 - 0x91 && nX <= nWidth / 2 - 0x80 && nY >= nHeight - 0x1C && nY <= nHeight - 8;
}

// 0x00497250
void __cdecl VIEW_InitTextColorRed()
{
    gnTextColorRed = D2Win_10034_MixRGB(0xFF, 0, 0);
}



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

// 0x00497270
void __cdecl HIREABLES_InitTextColorA()
{
    gnTextColorA = D2Win_10034_MixRGB(0xF4, 0xC0, 0x4C);
}

// 0x00497290
void __cdecl HIREABLES_InitTextColorB()
{
    gnTextColorB = D2Win_10034_MixRGB(0, 0, 0xFF);
}



// 0x00497300
void __cdecl INV_DrawKeyBindingPopup()
{
    unsigned short wszTextBuf[200];
    Unicode* wszText = (Unicode*)wszTextBuf;
    for (int i = 0; i < 200; ++i)
    {
        wszText[i].wChar = 0;
    }
    unsigned short wszKeyBuf[30];
    Unicode* wszKey = (Unicode*)wszKeyBuf;
    for (int i = 0; i < 30; ++i)
    {
        wszKey[i].wChar = 0;
    }
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x1053));
    if (CUNIT_GetHotkeyBinding(0x23, 1) != 0xFFFF)
    {
        memset(wszKey, 0, sizeof(wszKeyBuf));
        sub_005269D0_FormatText(30, wszKey, D2LANG_GetStringFromTblIndex(0x1052), CMDTBL_GetKeyName(0x23, 1));
        sub_00526700(wszText, wszKey);
    }
    if (CUNIT_GetHotkeyBinding(0x23, 0) != 0xFFFF)
    {
        memset(wszKey, 0, sizeof(wszKeyBuf));
        sub_005269D0_FormatText(30, wszKey, D2LANG_GetStringFromTblIndex(0x1052), CMDTBL_GetKeyName(0x23, 0));
        sub_00526700(wszText, wszKey);
    }
    D2Win_10129_DrawFramedText(wszText, gnScreenWidth / 2 - 0x91, gnScreenHeight - 0x17, 0, 1);
}

// 0x00497440
static int __cdecl PANEL_Bounds(int nX,int nY)
{
    int nHalf=gnScreenWidth / 2;
    if (nX >= nHalf + -145 && nX <= nHalf + -128
        && nY >= gnScreenHeight + -28 && nY <= gnScreenHeight + -8)
        return 1;
    return 0;
}

// 0x00497480
void __cdecl VIEW_DrawRunButton()
{
    int nX = sub_00468730();
    int nY = sub_00468740();
    D2GfxDataStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCelFile = gpRunButtonCel;
    tContext.nDirection = 0;
    if (GAME_GetAlwaysRun())
    {
        if (gbRunButtonDown && ButtonHitTest_00497480(nX, nY))
        {
            tContext.nFrame = 3;
        }
        else
        {
            tContext.nFrame = 2;
        }
    }
    else
    {
        if (gbRunButtonDown && ButtonHitTest_00497480(nX, nY))
        {
            tContext.nFrame = 1;
        }
        else
        {
            tContext.nFrame = 0;
        }
    }
    sub_004F6480(&tContext, gnScreenWidth / 2 - 0x91, gnScreenHeight - 0xA, -1, 5, 0);
    if (nX >= gnScreenWidth / 2 - 0x91 && nX <= gnScreenWidth / 2 - 0x80
        && nY >= gnScreenHeight - 0x1C && nY <= gnScreenHeight - 8)
    {
        INV_DrawKeyBindingPopup();
    }
}

// 0x004975B0
void __cdecl PANEL_DrawStaminaBar()
{
    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
    const int nStamina = PANEL_GetSmoothedOrbValue(10);
    int nMaxStamina = STATLIST_GetMaxStaminaFromUnit(pPlayer);
    if (!gnTextColorRed)
    {
        gnTextColorRed = D2Win_10034_MixRGB(0xFF, 0, 0);
        gnTextColorA = D2Win_10034_MixRGB(0xF4, 0xC0, 0x4C);
        gnTextColorB = D2Win_10034_MixRGB(0, 0, 0xFF);
    }

    int nColor = gnTextColorA;
    if (nMaxStamina + 5 < nStamina || STATES_CheckStateMaskOnUnit(pPlayer, 0x18))
    {
        nMaxStamina = nStamina;
        nColor = gnTextColorB;
    }

    int nWidth;
    if (nMaxStamina <= 0)
        nWidth = 0;
    else
        nWidth = 102 * nStamina / nMaxStamina;
    if (nWidth < 25)
        nColor = gnTextColorRed;

    AUTOMAP_DrawFramedBox(gnScreenWidth / 2 - 0x7F, gnScreenHeight - 0x1B, nWidth, 0x12, nColor, 2);

    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    int nCur = PANEL_GetSmoothedOrbValue(10) / 256;
    const int nMax = STATLIST_GetMaxStaminaFromUnit(pPlayer) / 256;
    int nTextColor = 0;
    if (nCur > nMax || STATES_CheckState(pPlayer, STATE_SHRINE_STAMINA))
    {
        nCur = nMax;
        nTextColor = 3;
    }

    Unicode wszText[100];
    if (nMouseX >= gnScreenWidth / 2 - 0x7F && nMouseX <= gnScreenWidth / 2 - 0x19
        && nMouseY >= gnScreenHeight - 0x1B && nMouseY <= gnScreenHeight - 9)
    {
        sub_005269D0_FormatText(100, wszText, D2LANG_GetStringFromTblIndex(0x1044), nCur, nMax);
        D2Win_10129_DrawFramedText(wszText, gnScreenWidth / 2 - 0x4C, gnScreenHeight - 0x34, nTextColor, 1);
    }
}

// 0x00497780
static int __cdecl sub_00497780_Bounds(int nX,int nY)
{
    int nHalf=gnScreenWidth / 2;
    if (nX >= nHalf + -8 && nX <= nHalf + 5
        && nY >= gnScreenHeight + -39 && nY <= gnScreenHeight + -13)
        return 1;
    return 0;
}

// @ref 0x00499500
// 0x004979E0
int __cdecl HIREABLES_AreBeltRowsShown()
{
    return gbBeltRowsShown != 0;
}

// 0x004979F0
int __cdecl HIREABLES_GetBeltRowCount()
{
    switch (gnUiRecordIndex)
    {
    case 2:
        return 1;
    case 1:
    case 4:
        return 2;
    case 0:
    case 5:
        return 3;
    default:
        return 4;
    }
}

// 0x00498D50
void __fastcall VIEW_SetBeltSlotValue(int nX, int nArg)
{
    if ((unsigned int)nX < 4)
        gabBeltHotkey[nX] = (unsigned char)nArg;
}

// 0x00498D60
void __cdecl VIEW_ResetBeltHover()
{
    gnBeltBox = -1;
    gnBeltRectX = -1;
    gnBeltRectY = -1;
    gnBeltHover = 0;
    gpBeltItemA = 0;
    gpBeltItemB = 0;
}





// 0x00498DC0
int __fastcall AUTOMAP_IsCursorOverMiniPanelButton(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    D2UiRecordStrc tRecord;
    DATATBLS_GetBeltsTxtRecord(gnUiRecordIndex, gnBeltUiRecordRow, &tRecord);
    if (gbUiRecordMode)
    {
        const D2UiRectStrc* pRect = &tRecord.aRects[tRecord.nBoxes - 4];
        if (nX >= pRect->nLeft && nX <= tRecord.aRects[3].nRight && nY >= pRect->nTop && nY <= tRecord.aRects[3].nBottom)
        {
            return 1;
        }
    }
    else if (nY > gnScreenHeight - 0x30 && nX >= gnScreenWidth / 2 + 0x17 && nX <= gnScreenWidth / 2 + 0x91
        && nY >= gnScreenHeight - 0x27 && nY <= gnScreenHeight - 0xA)
    {
        return 1;
    }
    return 0;
}

// 0x00499500
void __stdcall PANEL_OnMouseClick(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending() || CUNIT_IsPlayerDeadOrMissing())
    {
        pMsg->bReturn=0;
        return;
    }
    int nY=pMsg->nYpos;
    int nX=pMsg->nXpos;
    if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg))
    {
        gbControlPanelClicked=1;
        pMsg->bReturn=1;
        pMsg->lResult=0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    int nHeight=gnScreenHeight;
    if (nY>nHeight + -48)
    {
        int nWidth;
        if ((unsigned int)(nX + -117)<=48 && nY<=nHeight)
        {
            gbControlPanelClicked=1;
            gbLeftSkillButtonDown=1;
        }
        else if (nX>=(nWidth=gnScreenWidth) + -165 && nX<=nWidth + -117 && nY<=nHeight)
        {
            gbControlPanelClicked=1;
            gbRightSkillButtonDown=1;
        }
        else if ((unsigned int)(nX + -30)<=80 && nY>=nHeight + -75 && nY<=nHeight + -15)
        {
            gdwShowHpText=!gdwShowHpText;
            sub_004150E0_SaveValue("Diablo II","Show HP Text",0,gdwShowHpText);
        }
        else if (nX>=nWidth + -111 && nX<=nWidth + -31 && nY>=nHeight + -75 && nY<=nHeight + -15)
        {
            gdwShowMpText=!gdwShowMpText;
            sub_004150E0_SaveValue("Diablo II","Show MP Text",0,gdwShowMpText);
        }
        else if (sub_00497780_Bounds(nX,nY))
        {
            gbMiniPanelButtonDown=1;
            gbControlPanelClicked=1;
            sub_004B9A00_Sound(4,0,0,0,0);
        }
        else if (PANEL_Bounds(nX,nY))
        {
            gbRunButtonDown=1;
            gbControlPanelClicked=1;
            sub_004B9A00_Sound(4,0,0,0,0);
        }
        gbControlPanelMouseDown=1;
        pMsg->bReturn=1;
        pMsg->lResult=0;
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }
    pMsg->bReturn=0;
}


static int sub_004977C0_IsInButtonRect(int nX, int nY)
{
    return nX >= gnScreenWidth / 2 - 8 && nX <= gnScreenWidth / 2 + 5 && nY >= gnScreenHeight - 39 && nY <= gnScreenHeight - 13;
}

// 0x004977C0
void __cdecl PANEL_DrawMiniPanelButton()
{
    D2GfxDataStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCelFile = gpStateButtonCel;
    tContext.nDirection = 0;
    if (GAME_GetUIVarState(21))
    {
        if (gbMiniPanelButtonDown && sub_004977C0_IsInButtonRect(sub_00468730(), sub_00468740()))
        {
            tContext.nFrame = 3;
        }
        else
        {
            tContext.nFrame = 2;
        }
    }
    else
    {
        if (gbMiniPanelButtonDown && sub_004977C0_IsInButtonRect(sub_00468730(), sub_00468740()))
        {
            tContext.nFrame = 1;
        }
        else
        {
            tContext.nFrame = 0;
        }
    }
    sub_004F6480(&tContext, gnScreenWidth / 2 - 8, gnScreenHeight - 16, -1, 5, 0);
}

// 0x004978D0
static void __stdcall PANEL_DrawBeltBoxFrame(int nBox, int nColor)
{
    VIEW_InitBeltColors();
    if (nColor == 2)
        return;

    D2UiRectStrc tRect;
    DATATBLS_GetInvRectFromBeltsTxt(gnUiRecordIndex, gnBeltUiRecordRow, &tRect, nBox);
    AUTOMAP_DrawFramedBox(tRect.nLeft, tRect.nTop, 0x1D, 0x1D, gabBeltColors[nColor], 0);
}

// 0x00497920
static void __cdecl PANEL_DrawCursorBeltBox(D2InventoryStrc* pInventory)
{
    D2UnitStrc* pItem = INVENTORY_GetCursorItem(pInventory);
    if (!pItem || !gnBeltHover)
        return;

    D2UiRecordStrc tRecord;
    DATATBLS_GetBeltsTxtRecord(gnUiRecordIndex, gnBeltUiRecordRow, &tRecord);
    if (gnBeltBox < 0 || gnBeltBox >= tRecord.nBoxes)
        return;

    if (!INVENTORY_GetItemFromBeltSlot(pInventory, gnBeltBox) && ITEMS_CheckIfBeltable(pItem))
    {
        PANEL_DrawBeltBoxFrame(gnBeltBox, 1);
        return;
    }

    int nResult;
    if (INVENTORY_GetUseableItemFromBeltSlot(pInventory, pItem, gnBeltBox, &nResult))
    {
        PANEL_DrawBeltBoxFrame(gnBeltBox, 3);
        return;
    }

    PANEL_DrawBeltBoxFrame(gnBeltBox, 0);
}

// 0x00497A40
void __cdecl PANEL_DrawBeltItemHoverText()
{
    Unicode wszProps[0x100] = { 0 };
    Unicode wszName[0x80] = { 0 };
    Unicode wszText[0x180] = { 0 };

    D2UnitStrc* pPlayer = sub_00463DD0();
    if (!gnBeltHover || !gpBeltItemA)
    {
        return;
    }

    if (INVENTORY_GetCursorItem(pPlayer->pInventory))
    {
        return;
    }

    if (gnBeltBox > 3 && !gbUiRecordMode && !gnBeltRecordMode2)
    {
        return;
    }

    if (!DATATBLS_GetItemsTxtRecord(!gpBeltItemA ? -1 : gpBeltItemA->dwClassId))
    {
        FOG_DisplayHalt("", sub_00408090(), 0x61D);
        exit(-1);
    }

    INV_BuildItemName(gpBeltItemA, wszName, 0x80);
    if (ITEMS_GetItemQuality(gpBeltItemA) != 3)
    {
        sub_004E6410_BuildPropText(gpBeltItemA, wszProps, 0x100, 1, 0);
    }

    sub_005267E0(wszText, INV_PrefixColorCode(wszProps, 3));
    sub_00526700(wszText, INV_PrefixColorCode(wszName, 0));
    if (gnBeltRectX < 0 || gnBeltRectY < 0)
    {
        return;
    }

    sub_00452170_ReturnText(wszText);
    if (INV_IsInvPanelTradeMode())
    {
        Unicode wszSocket[0x40] = { 0 };
        int nUnused;
        if (NPCMENU_GetTradeCostText(gpBeltItemA, 1, &nUnused, wszSocket, 0x40) && wszSocket[0].wChar)
        {
            sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9E));
            sub_00526700(wszText, wszSocket);
        }
    }

    D2Win_10129_DrawFramedText(wszText, gnBeltRectX, gnBeltRectY, 0, 1);
}

// 0x00497CF0
static void __stdcall PANEL_DrawDurabilityIcon(int nState, int bType, int nQuiverType, int nBodyLoc)
{
    int nFrame = nState * 11;
    switch (nBodyLoc)
    {
    case 1:
        nFrame += 1;
        break;
    case 3:
        nFrame += 4;
        break;
    case 4:
        if (nQuiverType)
            nFrame += 10;
        else if (bType)
            nFrame += 7;
        else
            nFrame += 6;
        break;
    case 5:
        if (nQuiverType)
            nFrame += 9;
        else if (bType)
            nFrame += 5;
        else
            nFrame += 8;
        break;
    case 8:
        nFrame += 2;
        break;
    case 9:
        nFrame += 3;
        break;
    case 10:
        nFrame += 0;
        break;
    }
    int nOffset = 0;
    D2GfxDataStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCelFile = gpDuroIconCel;
    tContext.nDirection = 0;
    tContext.nFrame = nFrame;
    if (GAME_GetUIVarState(10))
    {
        if (ROSTER_IsAnyoneHostile())
            nOffset = 0x2B;
        sub_004F6480(&tContext, gnScreenWidth - 0x3C, nOffset + 0x8C, -1, 1, 0);
    }
    else
        sub_004F6480(&tContext, gnScreenWidth - 0x3C, 0x6E, -1, 1, 0);
}

// 0x00497E00
void __cdecl PANEL_DrawQuantityWarningIcons()
{
    memset(gabSlots, 0, 6);

    D2UnitStrc* pPlayer = sub_00463DD0();
    D2InventoryStrc* pInventory = pPlayer->pInventory;
    D2UnitStrc* pRightArm = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
    D2UnitStrc* pLeftArm = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
    if ((pRightArm && ITEMS_GetAmmoType(pRightArm) && (!pLeftArm || !ITEMSIsA(pLeftArm, ITEMS_GetAmmoType(pRightArm))))
        || (pLeftArm && ITEMS_GetAmmoType(pLeftArm) && (!pRightArm || !ITEMSIsA(pRightArm, ITEMS_GetAmmoType(pLeftArm)))))
    {
        INV_DrawWarningIcon(2);
    }

    for (unsigned int i = 0; i < gnBodyLocCount; ++i)
    {
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, gaBodyLocs[i]);
        if (!pItem)
        {
            continue;
        }

        const unsigned char nWarnType = ITEMS_GetQtyWarnCount(pItem);
        if (!nWarnType)
        {
            continue;
        }

        for (unsigned int j = 0; j < gnQtyWarnCount; ++j)
        {
            if (nWarnType != gaQtyWarn[j].nWarnType)
            {
                continue;
            }

            D2ItemsTxt* pItemsTxtRecord = DATATBLS_GetItemsTxtRecord(GAME_GetUnitClassId(pItem));
            unsigned int nQuantity = STATLIST_UnitGetStatValue(pItem, STAT_QUANTITY, 0);
            if (!ITEMS_IsMagSetRarUniCrfOrTmp(pItem))
            {
                for (D2UnitStrc* pNode = INVENTORY_GetFirstItem(pInventory); pNode; pNode = INVENTORY_GetNextItem(pNode))
                {
                    D2UnitStrc* pInvItem = INVENTORY_UnitIsItem(pNode);
                    if (pInvItem != pItem && !ITEMS_GetInvPage(pInvItem)
                        && DATATBLS_GetItemsTxtRecord(!pInvItem ? -1 : pInvItem->dwClassId)->dwCode == pItemsTxtRecord->dwCode)
                    {
                        nQuantity += STATLIST_UnitGetStatValue(pInvItem, STAT_QUANTITY, 0);
                    }
                }
            }

            if (nQuantity <= gaQtyWarn[j].nLevel2)
            {
                INV_DrawWarningIcon(gaQtyWarn[j].nFrame + 2);
            }
            else if (nQuantity <= gaQtyWarn[j].nLevel1)
            {
                INV_DrawWarningIcon(gaQtyWarn[j].nFrame + 1);
            }
            else if (nQuantity <= gaQtyWarn[j].nLevel0)
            {
                INV_DrawWarningIcon(gaQtyWarn[j].nFrame);
            }
        }
    }
}

// 0x00497FE0
void __cdecl PANEL_DrawDurabilityIcons()
{
    D2InventoryStrc* pInventory = CUNIT_GetPlayerUnit()->pInventory;
    for (int j = 0; j < 7; ++j)
    {
        const int nLoc = gaDurabilityBodyLocs[j];
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, nLoc);
        if (!pItem || !ITEMS_HasDurability(pItem) || ITEMS_CheckIfStackable(pItem))
            continue;
        const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
        if (!nMaxDurability)
            continue;
        if (STATLIST_UnitGetStatValue(pItem, STAT_DURABILITY, 0) * 100 / nMaxDurability <= 20)
            goto found;
    }
    return;
found:
    for (int i = 0; i < 7; ++i)
    {
        const int nBodyLoc = gaDurabilityBodyLocs[i];
        D2UnitStrc* pItem = INVENTORY_GetItemFromBodyLoc(pInventory, nBodyLoc);
        int nState = 0;
        int bType = 0;
        int nQuiverType = 0;
        if (pItem)
        {
            if (ITEMS_HasDurability(pItem) && !ITEMS_CheckIfStackable(pItem))
            {
                const int nMaxDurability = STATLIST_GetMaxDurabilityFromUnit(pItem);
                bType = ITEMSIsA(pItem, 0x33);
                nQuiverType = ITEMS_GetQuiverType(pItem);
                if (nMaxDurability)
                {
                    const int nPercent = STATLIST_UnitGetStatValue(pItem, STAT_DURABILITY, 0) * 100 / nMaxDurability;
                    if (nPercent <= 0)
                        nState = 2;
                    else if (nPercent <= 20)
                        nState = 1;
                }
            }
        }
        else if (nBodyLoc == 4 || nBodyLoc == 5)
            continue;
        PANEL_DrawDurabilityIcon(nState, bType, nQuiverType, nBodyLoc);
    }
}

// 0x00498120
void __cdecl PANEL_DrawLifeManaText()
{
    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    Unicode wszLife[100];
    Unicode wszMana[100];
    Unicode wszLifeText[100];
    Unicode wszManaText[100];

    if (gdwShowHpText_007BEFDC || (nMouseX >= 0x1E && nMouseX <= 0x1E + 0x50
        && nMouseY >= gnScreenHeight - 0x4B && nMouseY <= gnScreenHeight - 0xF))
    {
        int nLife = PANEL_GetSmoothedOrbValue(6) >> 8;
        const int nMaxLife = STATLIST_GetMaxLifeFromUnit(pPlayer) >> 8;
        D2UnitStrc* pUnit = CUNIT_GetPlayerUnit();
        if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->dwAnimMode != 0x11 && nLife >= 0 && nLife <= 1)
            nLife = 1;

        sub_005269D0_FormatText(100, wszLifeText, D2LANG_GetStringFromTblIndex(0x1045), nLife, nMaxLife);
        sub_00526700(wszLife, wszLifeText);
        const int nHalfWidth = D2Win_10121_GetTextWidth(wszLife) / 2;
        D2Win_10117_DrawText(wszLife, 0x41 - nHalfWidth, gnScreenHeight - 0x5F, 0, 0);
    }

    if (gdwShowMpText_007BEFE0 || (nMouseX >= gnScreenWidth - 0x6F && nMouseX <= gnScreenWidth - 0x1F
        && nMouseY >= gnScreenHeight - 0x4B && nMouseY <= gnScreenHeight - 0xF))
    {
        const int nMana = PANEL_GetSmoothedOrbValue(8) >> 8;
        sub_005269D0_FormatText(100, wszManaText, D2LANG_GetStringFromTblIndex(0x1046), nMana, STATLIST_GetMaxManaFromUnit(pPlayer) >> 8);
        sub_00526700(wszMana, wszManaText);
        const int nHalfWidth = D2Win_10121_GetTextWidth(wszMana) / 2;
        D2Win_10117_DrawText(wszMana, gnScreenWidth - nHalfWidth - 0x50, gnScreenHeight - 0x5F, 0, 0);
    }
}

// 0x00498310
void __cdecl PANEL_UpdateLevelTimer()
{
    D2ActiveRoomStrc* pRoom = CUNIT_GetPlayerRoom();
    if (pRoom)
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
        if (gnLevelId != nLevelId)
        {
            gnLevelId = nLevelId;
            gnLevelTimer = 0x3C;
        }
    }
}

// 0x00498340
extern "C" void __cdecl PANEL_UpdateMiniPanelTooltip()
{
    const int mouseX = sub_00468730_MouseX();
    const int mouseY = sub_00468740_MouseY();
    if (mouseX >= gnScreenWidth / 2 - 8 && mouseX <= gnScreenWidth / 2 + 5
        && mouseY >= gnScreenHeight - 39 && mouseY <= gnScreenHeight - 13)
    {
        if (GAME_GetUIVarState(21))
            sub_00502280_SetTooltip(sub_00524A30_LocalizedText(4168), gnScreenWidth / 2 - 1, gnScreenHeight - 39, 0, 1);
        else
            sub_00502280_SetTooltip(sub_00524A30_LocalizedText(4167), gnScreenWidth / 2 - 1, gnScreenHeight - 39, 0, 1);
    }
}

// 0x004983D0
static void PANEL_DrawControlPanelFrame(int nOffset)
{
    D2GfxDataStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    if (D2GFX_GetResolutionMode() - 2)
    {
        if (!gpCtrlPnl7Cel)
        {
            gpCtrlPnl7Cel = GAME_LoadUiCelFile("Panel\\CtrlPnl7");
        }
        if (gp800CtrlPnl7Cel)
        {
            ARCHIVE_FreeClientCellFile(gp800CtrlPnl7Cel);
            gp800CtrlPnl7Cel = 0;
        }
        if (gpBorderFrameCel)
        {
            ARCHIVE_FreeClientCellFile(gpBorderFrameCel);
            gpBorderFrameCel = 0;
        }
        tContext.pCelFile = gpCtrlPnl7Cel;
        tContext.nDirection = 0;
        tContext.nFrame = 0;
        sub_004F6480(&tContext, 0, gnScreenHeight - nOffset, -1, 5, 0);
        tContext.nFrame = 1;
        sub_004F6480(&tContext, gnScreenWidth / 2 - 0x9B, gnScreenHeight, -1, 5, 0);
        tContext.nFrame = 2;
        sub_004F6480(&tContext, gnScreenWidth / 2 - 0x1B, gnScreenHeight, -1, 5, 0);
        tContext.nFrame = 3;
        sub_004F6480(&tContext, gnScreenWidth / 2 + 0x65, gnScreenHeight, -1, 5, 0);
        tContext.nFrame = 4;
        sub_004F6480(&tContext, gnScreenWidth - 0x75, gnScreenHeight - nOffset, -1, 5, 0);
    }
    else
    {
        if (gpCtrlPnl7Cel)
        {
            ARCHIVE_FreeClientCellFile(gpCtrlPnl7Cel);
            gpCtrlPnl7Cel = 0;
        }
        if (!gp800CtrlPnl7Cel)
        {
            gp800CtrlPnl7Cel = GAME_LoadUiCelFile("Panel\\800CtrlPnl7");
        }
        tContext.pCelFile = gp800CtrlPnl7Cel;
        tContext.nDirection = 0;
        tContext.nFrame = 0;
        sub_004F6480(&tContext, 0, gnScreenHeight - nOffset, -1, 5, 0);
        tContext.nFrame = 1;
        sub_004F6480(&tContext, gnScreenWidth / 2 - 0xEB, gnScreenHeight, -1, 5, 0);
        tContext.nFrame = 2;
        sub_004F6480(&tContext, gnScreenWidth / 2 - 0x6B, gnScreenHeight, -1, 5, 0);
        tContext.nFrame = 3;
        sub_004F6480(&tContext, gnScreenWidth / 2 + 0x15, gnScreenHeight, -1, 5, 0);
        tContext.nFrame = 4;
        sub_004F6480(&tContext, gnScreenWidth / 2 + 0x95, gnScreenHeight, -1, 5, 0);
        tContext.nFrame = 5;
        sub_004F6480(&tContext, gnScreenWidth - 0x75, gnScreenHeight - nOffset, -1, 5, 0);
    }
}

// 0x00498630
void __cdecl PANEL_DrawBorderFrameLeft()
{
    D2GfxDataStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    if (!gpBorderFrameCel)
    {
        gpBorderFrameCel = GAME_LoadUiCelFile("Panel\\800BorderFrame");
    }
    tContext.pCelFile = gpBorderFrameCel;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, 0, 253, -1, 5, 0);
    tContext.nFrame = 1;
    sub_004F6480(&tContext, 256, 63, -1, 5, 0);
    tContext.nFrame = 2;
    sub_004F6480(&tContext, 0, 484, -1, 5, 0);
    tContext.nFrame = 3;
    sub_004F6480(&tContext, 0, 553, -1, 5, 0);
    tContext.nFrame = 4;
    sub_004F6480(&tContext, 256, 553, -1, 5, 0);
}

// 0x00498700
void __cdecl PANEL_DrawBorderFrameRight()
{
    if (!gpBorderFrameCel)
    {
        gpBorderFrameCel = GAME_LoadUiCelFile("Panel\\800BorderFrame");
    }
    D2GfxDataStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCelFile = gpBorderFrameCel;
    tContext.nDirection = 0;
    tContext.nFrame = 5;
    sub_004F6480(&tContext, 400, 63, -1, 5, 0);
    tContext.nFrame = 6;
    sub_004F6480(&tContext, 544, 253, -1, 5, 0);
    tContext.nFrame = 7;
    sub_004F6480(&tContext, 713, 484, -1, 5, 0);
    tContext.nFrame = 8;
    sub_004F6480(&tContext, 544, 553, -1, 5, 0);
    tContext.nFrame = 9;
    sub_004F6480(&tContext, 400, 553, -1, 5, 0);
}

extern "C" void __fastcall SCMD_WriteVariableValue(BitStreamContext* stream, unsigned int value)
{
    if (value < 256u)
    {
        BITMANIP_Write(stream, 0, 1);
        BITMANIP_Write(stream, value, 8);
    }
    else
    {
        BITMANIP_Write(stream, 1, 1);
        if (value < 65536u)
        {
            BITMANIP_Write(stream, 0, 1);
            BITMANIP_Write(stream, value, 16);
        }
        else
        {
            BITMANIP_Write(stream, 1, 1);
            BITMANIP_Write(stream, value, 32);
        }
    }
}

// 0x004987E0
static int __stdcall PANEL_GetBeltBoxAt(int nY, int nX)
{
    D2UiRecordStrc tRecord;
    int nResult = -1;
    DATATBLS_GetBeltsTxtRecord(gnUiRecordIndex, gnBeltUiRecordRow, &tRecord);
    for (int i = 0; i < tRecord.nBoxes; ++i)
    {
        D2UiRectStrc tRect;
        DATATBLS_GetInvRectFromBeltsTxt(gnUiRecordIndex, gnBeltUiRecordRow, &tRect, i);
        if (nX >= tRect.nLeft && nX <= tRect.nRight && nY >= tRect.nTop && nY <= tRect.nBottom)
        {
            nResult = i;
            break;
        }
    }
    return nResult;
}

// 0x00498870
static void __stdcall PANEL_ClickBeltBox(D2InventoryStrc* pInventory, int nX, int nY)
{
    const int nBox = PANEL_GetBeltBoxAt(nY, nX);
    if (nBox == -1)
    {
        return;
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
    D2UnitStrc* pBeltItem = INVENTORY_GetItemFromBeltSlot(pInventory, nBox);
    if (CURSOR_GetCursorState() == 6)
    {
        return;
    }

    if (pCursorItem && ITEMS_CheckIfBeltable(pCursorItem))
    {
        const int bBusy = ITEM_IsItemActionBlocked(pCursorItem);
        if (pBeltItem)
        {
            if (!bBusy)
            {
                MSG_SendTwoDwords(0x25, pCursorItem->dwUnitId, !pBeltItem ? -1 : pBeltItem->dwUnitId);
                ITEM_SetUninterruptableState(pCursorItem);
            }
        }
        else if (!bBusy)
        {
            MSG_SendTwoDwords(0x23, pCursorItem->dwUnitId, (unsigned short)nBox);
            ITEM_SetUninterruptableState(pCursorItem);
        }
        sub_004B9A00(ITEM_GetDropSound(pCursorItem), 0, 0, 0, 0);
        return;
    }

    if (pBeltItem && !pCursorItem && !ITEM_IsItemActionBlocked(pBeltItem))
    {
        MSG_SendDword(0x24, pBeltItem->dwUnitId);
        ITEM_SetUninterruptableState(pBeltItem);
    }
}

// 0x00498930
static void PANEL_HoverBeltBox(int nX, D2InventoryStrc* pInventory, int nY)
{
    const int nBox = PANEL_GetBeltBoxAt(nY, nX);
    if (nBox < 0)
    {
        return;
    }

    D2UnitStrc* pCursorItem = INVENTORY_GetCursorItem(pInventory);
    if (CURSOR_GetCursorState() == 6 || CURSOR_GetCursorState() == 8)
    {
        return;
    }

    if (pCursorItem)
    {
        gnBeltBox = nBox;
        gnBeltHover = 1;
        gpBeltItemA = 0;
        gpBeltItemB_007BEFAC = 0;
        return;
    }

    D2UnitStrc* pItem = INVENTORY_GetItemFromBeltSlot(pInventory, nBox);
    gnBeltBox = nBox;
    if (pItem)
    {
        gnBeltHover = 1;
        if (pItem == gpBeltItemB_007BEFAC)
        {
            return;
        }

        D2UiRectStrc tRect;
        const int nBoxId = CLIENTS_GetUnitX(pItem);
        DATATBLS_GetInvRectFromBeltsTxt(gnUiRecordIndex, gnBeltUiRecordRow, &tRect, nBoxId);
        gpBeltItemA = pItem;
        gpBeltItemB_007BEFAC = pItem;
        gnBeltRectX = tRect.nLeft + 0xE;
        gnBeltRectY = tRect.nTop;
    }
    else
    {
        gnBeltHover = 0;
        gpBeltItemA = 0;
        gpBeltItemB_007BEFAC = 0;
    }
}

// 0x00498A90
static void __stdcall PANEL_UseBeltSlot(int nSlot, D2UnitStrc* pPlayer, D2InventoryStrc* pInventory, int bShift)
{
    if (!GAME_IsExpansion())
    {
        bShift = 0;
    }

    if (INVENTORY_GetCursorItem(pInventory))
    {
        return;
    }

    if (GAME_GetUIVarState(9))
    {
        return;
    }

    D2Block1 tBlock1;
    const int nClass = UNITS_GetInventoryRecordId(pPlayer, 0, GAME_IsExpansion());
    DATATBLS_GetInventoryGridInfo(nClass, gnBeltUiRecordRow, &tBlock1);
    D2UnitStrc* pItem = INVENTORY_GetItemFromBeltSlot(pInventory, nSlot);
    if (!pItem)
    {
        return;
    }

    const int nClassId = pItem->dwClassId;
    D2ItemsTxt* pItemsTxt = DATATBLS_GetItemsTxtRecord(nClassId);
    D2_ASSERT(pItemsTxt, 0xA64);
    if (INV_CheckState(pPlayer, pItem, pItemsTxt) != 1)
    {
        return;
    }

    if (ITEM_IsItemActionBlocked(pItem))
    {
        return;
    }

    MSG_SendDwords3(0x26, pItem->dwUnitId, bShift, 0);
    ITEM_SetUninterruptableState(pItem);
    if (bShift)
    {
        const int nPetId = ROSTERPETS_FindPetIdByOwner(pPlayer, 7, 0);
        if (nPetId != -1)
        {
            if (ITEMSIsA(pItem, 0x4C) || ITEMSIsA(pItem, 0x51) || ITEMSIsA(pItem, 0x50))
            {
                UNITSND_PlayEventSound(nPetId, 1, 0x54);
            }
            else
            {
                UNITSND_PlayEventSound(nPetId, 1, 0x55);
            }
            gnBeltHover = 0;
            return;
        }

        sub_004B9A00(ITEM_GetItemUseSound(pItem), 0, 0, 0, 0);
        gnBeltHover = 0;
        return;
    }

    sub_004B9A00(ITEM_GetItemUseSound(pItem), 0, 0, 0, 0);
    gnBeltHover = 0;
}

// 0x00498C00
void __stdcall PANEL_CloseUIVarsMsg(SMSGHANDLER_PARAMS* pMsg)
{
    UI_CloseUIVars(1, 0);
}


static int __stdcall INV_CheckState(D2UnitStrc* pPlayer, D2UnitStrc* pItem, D2ItemsTxt* pState)
{
    D2_ASSERT(pState, 0xA3D);
    if (pState->nUnique == 1 || pState->nQuest == 1)
    {
        sub_0049FF90_Close(pItem, pState);
        return 0;
    }
    if (pState->bFlag0x11D == 1)
    {
        return 1;
    }
    UNITSND_PlayPlayerSpeech(pPlayer, 0x14);
    return 0;
}

// 0x00498C10
static void PANEL_BeltHotkey(int nSlot)
{
    if (GAME_IsExitPending() || CUNIT_IsPlayerDeadOrMissing())
    {
        return;
    }

    if (gabBeltHotkey[nSlot] != 1)
    {
        return;
    }

    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
    PANEL_UseBeltSlot(nSlot, pPlayer, pPlayer->pInventory, GetKeyState(0x10) & 0x8000);
}

// 0x00498C50
void __cdecl PANEL_BeltHotkeyFirst()
{
    PANEL_BeltHotkey(0);
}

// 0x00498C90
void __cdecl PANEL_BeltHotkeySecond()
{
    PANEL_BeltHotkey(1);
}

// 0x00498CD0
void __cdecl PANEL_BeltHotkeyThird()
{
    PANEL_BeltHotkey(2);
}

// 0x00498D10
void __cdecl PANEL_BeltHotkeyFourth()
{
    PANEL_BeltHotkey(3);
}

// 0x00498D90
void __fastcall PANEL_SetBeltType(int nIndex)
{
    if (nIndex >= 0)
    {
        gnUiRecordIndex = nIndex;
        return;
    }
    FOG_DisplayHalt("", sub_00408090(), 0xB07);
    exit(-1);
}

// 0x00498E80
void __cdecl PANEL_ClearPair()
{
    gpBeltItemA = 0;
    gpBeltItemB = 0;
}

// 0x00498E90
void __cdecl PANEL_SetBeltExpandedMode()
{
    gbUiRecordMode = 1;
}

// 0x00498EA0
void __cdecl PANEL_DrawExperienceBar()
{
    unsigned short awText[100];
    Unicode* wszText = (Unicode*)awText;

    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
    const int nClass = !pPlayer ? -1 : pPlayer->dwClassId;
    const unsigned int nLevel = STATLIST_UnitGetStatValue(pPlayer, STAT_LEVEL, 0);
    const unsigned int nExperience = STATLIST_UnitGetStatValue(pPlayer, STAT_EXPERIENCE, 0);
    const unsigned int nNextExperience = DATATBLS_GetLevelThreshold(nClass, STATLIST_GetUnitBaseStat(pPlayer, STAT_LEVEL, 0));
    const unsigned int nLastExperience = DATATBLS_GetLevelThreshold(nClass, nLevel - 1);
    unsigned int nRange = nNextExperience - nLastExperience;
    unsigned int nProgress;
    if (nExperience > nLastExperience)
    {
        nProgress = nExperience - nLastExperience;
    }
    else
    {
        nProgress = 0;
    }

    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    for (int i = 0; i < 100; ++i)
    {
        wszText[i].wChar = 0;
    }

    if (nMouseX >= gnScreenWidth / 2 - 0x92 && nMouseX <= gnScreenWidth / 2 - 0x17 && nMouseY >= gnScreenHeight - 0x2B && nMouseY <= gnScreenHeight - 0x22)
    {
        sub_005269D0_FormatText(100, wszText, D2LANG_GetStringFromTblIndex(0x1043), nExperience, nNextExperience);
        D2Win_10129_DrawFramedText(wszText, gnScreenWidth / 2 - 0x92, gnScreenHeight - 0x33, 0, 1);
    }

    if (nRange)
    {
        unsigned int nWidth;
        if (nProgress >= 0x226B902)
        {
            nWidth = (nProgress >> 7) * 0x77 / (nRange >> 7);
        }
        else
        {
            nWidth = nProgress * 0x77 / nRange;
        }

        if (nWidth > 0x77)
        {
            nWidth = 0;
        }

        if (nLevel < DATATBLS_GetMaxLevel(nClass) && nWidth > 0)
        {
            const int nX = gnScreenWidth / 2 - 0x90;
            int nY = gnScreenHeight - 0x26;
            D2GFX_DrawLine(nX, nY, nX + nWidth, nY, 0xFF, 0xFF);
            nY += 1;
            D2GFX_DrawLine(nX, nY, nX + nWidth, nY, 0xFF, 0xFF);
        }
    }
}

// 0x004972B0
void __cdecl VIEW_InitBeltColors()
{
    gabBeltColors[0] = D2Win_10034_MixRGB(0x80, 0, 0);
    gabBeltColors[1] = D2Win_10034_MixRGB(0, 0x80, 0);
    gabBeltColors[2] = D2Win_10034_MixRGB(0, 0, 0x80);
    gabBeltColors[3] = D2Win_10034_MixRGB(0x80, 0x80, 0);
}

// 0x00499040
void __cdecl PANEL_DrawBelt()
{
    D2Win_10127_SetFont(1);
    D2InventoryStrc* pInventory = CUNIT_GetPlayerUnit()->pInventory;
    D2UnitStrc* pBelt = INVENTORY_GetItemFromBodyLoc(pInventory, 8);
    if (pBelt)
    {
        if (ITEMS_GetItemType(pBelt) == ITEMTYPE_BELT)
        {
            const int nBeltType = UNITS_GetBeltType(pBelt);
            if (nBeltType >= 0)
            {
                gnUiRecordIndex = nBeltType;
            }
            else
            {
                FOG_DisplayHalt("", sub_00408090(), 0xB07);
                exit(-1);
            }
        }
    }
    else
    {
        gnUiRecordIndex = 2;
    }

    if (!GAME_GetUIVarState(0x1F) && !gnBeltRecordMode2)
        gbUiRecordMode = 0;

    if (GAME_GetUIVarState(9))
        gbUiRecordMode = 0;

    gbBeltRowsShown = 0;
    if (gbUiRecordMode)
    {
        unsigned char abShow[3];
        abShow[0] = 1;
        abShow[1] = 1;
        abShow[2] = 1;
        switch (gnUiRecordIndex)
        {
        case 2:
            abShow[0] = 0;
            abShow[1] = 0;
            abShow[2] = 0;
            gbBeltRowsShown = 0;
            break;
        case 1:
        case 4:
            abShow[1] = 0;
            abShow[2] = 0;
            gbBeltRowsShown = 1;
            break;
        case 0:
        case 5:
            abShow[2] = 0;
            gbBeltRowsShown = 1;
            break;
        case 3:
        default:
            gbBeltRowsShown = 1;
            break;
        }

        D2GfxDataStrc tContext;
        memset(&tContext, 0, sizeof(tContext));
        tContext.nDirection = 0;
        tContext.nFrame = 0;
        tContext.pCelFile = gpCellFile_007BEF10;
        int nOffset = 0;
        unsigned char* pShow = abShow;
        for (int i = 0; i < 3; ++i)
        {
            if (*pShow)
                sub_004F6480(&tContext, gnScreenWidth / 2 + 0x15, gnScreenHeight - nOffset - 0x29, -1, 5, 0);

            ++pShow;
            nOffset += 0x20;
        }
    }

    D2UiRecordStrc tRecord;
    DATATBLS_GetBeltsTxtRecord(gnUiRecordIndex, gnBeltUiRecordRow, &tRecord);
    for (int nSlot = 0; nSlot < tRecord.nBoxes; ++nSlot)
    {
        if (nSlot > 3 && !gbBeltRowsShown)
            break;

        D2UnitStrc* pItem = INVENTORY_GetItemFromBeltSlot(pInventory, nSlot);
        if (!pItem)
            continue;

        int nBox;
        switch (pItem->dwUnitType)
        {
        case UNIT_OBJECT:
        case UNIT_ITEM:
        case UNIT_TILE:
            nBox = pItem->pStaticPath->nXPos;
            break;
        default:
            if (pItem->pDynamicPath)
                nBox = PATH_GetXPosition(pItem->pDynamicPath);
            else
                nBox = 0;
            break;
        }

        if (!ITEMS_CheckItemFlag(pItem, 4, 0x5D5, ".\\UI\\panel.cpp") && ITEMS_CheckIfUseable(pItem) && !ITEM_IsItemActionBlocked(pItem))
        {
            if (pItem == gpBeltItemA && gnBeltHover)
                PANEL_DrawBeltBoxFrame(nBox, 1);
            else
                PANEL_DrawBeltBoxFrame(nBox, 2);
        }
        else
        {
            PANEL_DrawBeltBoxFrame(nBox, 0);
        }

        D2UiRectStrc tRect;
        DATATBLS_GetInvRectFromBeltsTxt(gnUiRecordIndex, gnBeltUiRecordRow, &tRect, nBox);
        GFX_DrawItemCel(pItem, tRect.nLeft, tRect.nTop);
        if (nSlot < sizeof(gaBeltKeys) / sizeof(gaBeltKeys[0]) && ITEMS_CheckIfUseable(pItem))
        {
            Unicode wszKey[100];
            for (int i = 0; i < 100; ++i)
            {
                wszKey[i].wChar = 0;
            }

            if (CUNIT_GetHotkeyBinding(gaBeltKeys[nSlot], 1) != 0xFFFF || CUNIT_GetHotkeyBinding(gaBeltKeys[nSlot], 0) != 0xFFFF)
            {
                sub_005267E0(wszKey, CMDTBL_GetKeyName(gaBeltKeys[nSlot], 1));
                const int nLength = UNICODE_StrLen(wszKey);
                if (D2Win_10121_GetTextWidth(wszKey) > 0x1C)
                {
                    Unicode* pEnd = &wszKey[nLength];
                    do
                    {
                        pEnd->wChar = 0;
                        --pEnd;
                    }
                    while (D2Win_10121_GetTextWidth(wszKey) > 0x1C);
                }
                D2Win_10117_DrawText(wszKey, tRect.nLeft + 2, tRect.nBottom - 2, 4, 0);
            }
        }
    }

    if (gnUiRecordIndex == 2 || GAME_GetUIVarState(0x1F) || gbUiRecordMode)
        PANEL_DrawCursorBeltBox(pInventory);
}

// 0x00499450
void __cdecl PANEL_DrawControlPanel()
{
    int nOffset = 0;
    if (D2GFX_GetDisplayType() == 3)
    {
        nOffset = 1;
    }
    if (D2GFX_GetResolutionMode() == 2)
    {
        if (sub_0045AE90_GetPanelSlideMode() == 2 || sub_0045AE90_GetPanelSlideMode() == 3)
        {
            PANEL_DrawBorderFrameLeft();
        }
        if (sub_0045AE90_GetPanelSlideMode() == 1 || sub_0045AE90_GetPanelSlideMode() == 3)
        {
            PANEL_DrawBorderFrameRight();
        }
    }
    PANEL_DrawControlPanelFrame(nOffset);
    PANEL_DrawLifeOrb();
    PANEL_DrawManaOrb();
    PANEL_DrawExperienceBar();
    VIEW_DrawRunButton();
    PANEL_DrawStaminaBar();
    PANEL_DrawMiniPanelButton();
    PANEL_DrawBelt();
    PANEL_ValidateActiveSkills();
    PANEL_DrawBeltItemHoverText();
    D2ActiveRoomStrc* pRoom = CUNIT_GetPlayerRoom();
    if (pRoom)
    {
        const int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
        if (gnLevelId != nLevelId)
        {
            gnLevelId = nLevelId;
            gnLevelTimer = 0x3C;
        }
    }
    PANEL_UpdateMiniPanelTooltip();
}

static __forceinline void CancelCursorMode()
{
    if(CURSOR_GetCursorState()==6) UI_CancelCursorItemUse();
    else if(CURSOR_GetCursorState()==8) MSG_SendDword(0x4C,-1);
}

// 0x004996A0
void __stdcall PANEL_BeltMouseReleaseMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if(GAME_IsExitPending() || CUNIT_IsPlayerDeadOrMissing()) {
        pMsg->bReturn=0;
        return;
    }
    D2UnitStrc* pPlayer=CUNIT_GetPlayerUnit();
    const int x=pMsg->nXpos;
    const int y=pMsg->nYpos;
    gbRightSkillButtonDown=0;
    gbLeftSkillButtonDown=0;
    if(gbControlPanelClicked) {
        if(gbUiRecordMode) {
            if(AUTOMAP_IsCursorOverMiniPanelButton(pMsg)) {
                CancelCursorMode();
                PANEL_ClickBeltBox(pPlayer->pInventory,x,y);
                pMsg->bReturn=1;
                pMsg->lResult=0;
                sub_00420290_BreakHandlerChain(pMsg);
            }
            else if(x>=gnScreenWidth/2-8 && x<=gnScreenWidth/2+5 && y>=gnScreenHeight-39 && y<=gnScreenHeight-13) {
                if(GAME_GetUIVarState(21)) UI_SetUIVar(21,1,0);
                else UI_SetUIVar(21,2,0); // 0x00455F20
            }
            else if(x>=117 && x<=165 && y>=gnScreenHeight-48 && y<=gnScreenHeight) {
                UI_SetUIVar(3,2,0);
                SPELLSEL_SetSkillSelectRight(1);
            }
            else if(x>=gnScreenWidth-165 && x<=gnScreenWidth-117 && y>=gnScreenHeight-48 && y<=gnScreenHeight) {
                UI_SetUIVar(3,2,0);
                SPELLSEL_SetSkillSelectRight(0);
            }
            else if(x>=gnScreenWidth/2-145 && x<=gnScreenWidth/2-128 && y>=gnScreenHeight-28 && y<=gnScreenHeight-8) {
                GAME_SetAlwaysRun(!GAME_GetAlwaysRun());
            }
            gbControlPanelClicked=0;
        }
        else if(y>gnScreenHeight-48) {
            if(x>=gnScreenWidth/2+23 && x<=gnScreenWidth/2+145 && y>=gnScreenHeight-39 && y<=gnScreenHeight-10) {
                CancelCursorMode();
                PANEL_ClickBeltBox(pPlayer->pInventory,x,y);
            }
            else if(x>=117 && x<=165 && y<=gnScreenHeight) {
                CancelCursorMode();
                if(GAME_GetUIVarState(3)) UI_SetUIVar(3,1,0);
                else UI_SetUIVar(3,0,0); // 0x00455F20
                SPELLSEL_SetSkillSelectRight(1);
            }
            else if(x>=gnScreenWidth-165 && x<=gnScreenWidth-117 && y<=gnScreenHeight) {
                CancelCursorMode();
                if(GAME_GetUIVarState(3)) UI_SetUIVar(3,1,0);
                else UI_SetUIVar(3,0,0); // 0x00455F20
                SPELLSEL_SetSkillSelectRight(0);
            }
            else if(x>=gnScreenWidth/2-145 && x<=gnScreenWidth/2-128 && y>=gnScreenHeight-28 && y<=gnScreenHeight-8) {
                GAME_SetAlwaysRun(!GAME_GetAlwaysRun());
            }
            else if(x>=gnScreenWidth/2-8 && x<=gnScreenWidth/2+5 && y>=gnScreenHeight-39 && y<=gnScreenHeight-13) {
                if(GAME_GetUIVarState(21)) UI_SetUIVar(21,1,0);
                else UI_SetUIVar(21,2,0); // 0x00455F20
                if(gbMiniPanelButtonDown) gnGlobal_007BEFD4=!gnGlobal_007BEFD4;
            }
            gbControlPanelClicked=0;
            gbControlPanelMouseDown=0;
            pMsg->bReturn=1;
            pMsg->lResult=0;
            sub_00420290_BreakHandlerChain(pMsg);
        }
        else {
            pMsg->bReturn=0;
        }
    }
    else {
        if((x>=117 && x<=165 && y>=gnScreenHeight-48 && y<=gnScreenHeight) ||
           (x>=gnScreenWidth-165 && x<=gnScreenWidth-117 && y>=gnScreenHeight-48 && y<=gnScreenHeight)) {
            if(GAME_GetUIVarState(3)) UI_SetUIVar(3,1,0);
        }
        gbControlPanelClicked=0;
        pMsg->bReturn=0;
    }
    gbMiniPanelButtonDown=0;
    gbRunButtonDown=0;
}

// 0x00499BB0
void __stdcall PANEL_BeltMouseMove(SMSGHANDLER_PARAMS* pMsg)
{
    if (!gbPositionalSound || GAME_IsExitPending() || CUNIT_IsPlayerDeadOrMissing())
    {
        pMsg->bReturn = 0;
        return;
    }

    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
    if (GAME_IsLeftClickRepeating())
    {
        return;
    }

    if (gbUiRecordMode)
    {
        if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg))
        {
            if (GAME_GetUIVarState(0x1F))
            {
                pMsg->bReturn = 1;
                pMsg->lResult = 0;
            }
            PANEL_HoverBeltBox(nX, pPlayer->pInventory, nY);
            return;
        }

        if (!GAME_GetUIVarState(0x1F))
        {
            pMsg->bReturn = 0;
            gbUiRecordMode = 0;
            gnBeltRecordMode2 = 0;
        }
        else
        {
            pMsg->bReturn = 0;
            gnBeltRecordMode2 = 0;
        }
        gnBeltHover = 0;
        return;
    }

    if (nX < gnScreenWidth / 2 + 0x17 || nX > gnScreenWidth / 2 + 0x91 || nY < gnScreenHeight - 0x27 || nY > gnScreenHeight - 0xA)
    {
        pMsg->bReturn = 0;
        gnBeltHover = 0;
        return;
    }

    if (!UI_GetUIVarUnchecked(9))
    {
        gbUiRecordMode = 1;
        gnBeltRecordMode2 = 1;
        PANEL_HoverBeltBox(nX, pPlayer->pInventory, nY);
    }
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
}

// 0x00499D10
void __stdcall PANEL_BeltClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (GAME_IsExitPending() || CUNIT_IsPlayerDeadOrMissing())
    {
        pMsg->bReturn = 0;
        return;
    }

    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
    if (AUTOMAP_IsCursorOverMiniPanelButton(pMsg))
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        if (CURSOR_GetCursorState() == 6)
        {
            UI_CancelCursorItemUse();
        }
        else if (CURSOR_GetCursorState() == 8)
        {
            MSG_SendDword(0x4C, -1);
        }

        const int nBox = PANEL_GetBeltBoxAt(nY, nX);
        if (nBox < 0)
        {
            pMsg->bReturn = 0;
            return;
        }

        PANEL_UseBeltSlot(nBox, pPlayer, pPlayer->pInventory, (pMsg->wParam >> 2) & 1);
        sub_00420290_BreakHandlerChain(pMsg);
        return;
    }

    pMsg->bReturn = 0;
    gnBeltHover = 0;
}



extern D2PartyRowStrc* gpRosterUnits;  // 0x007BF014








#pragma pack(push, 1)
struct d2data_00722368_t
{
    unsigned char b0[12];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct d2data_00722318_t
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

extern "C" struct d2data_00722368_t gData_00722368; // 0x00722368
extern "C" struct d2data_00722318_t gData_00722318; // 0x00722318

extern int gnBeltBox = -1; // 0x0072235C

extern int gnBeltRectX = -1; // 0x00722360

extern int gnBeltRectY = -1; // 0x00722364

extern "C" struct d2data_00722368_t gData_00722368 = {
    { 0x55, 0x0F, 0x54, 0x0F, 0x5A, 0x0F, 0x5E, 0x0F, 0x58, 0x0F }
}; // 0x00722368

extern int gaBodyLocs[2] = { 4, 5 }; // 0x00722374

extern unsigned int gnBodyLocCount = 2; // 0x0072237C

extern D2QtyWarnStrc gaQtyWarn[5] = {
    { 1, 0, 0x32, 0x19, 0xA },
    { 2, 3, 0xF, 0xA, 5 },
    { 3, 6, 5, 4, 2 },
    { 4, 9, 0xF, 0xA, 5 },
    { 5, 12, 5, 4, 2 }
}; // 0x00722380

extern unsigned int gnQtyWarnCount = 5; // 0x007223E4

extern int gaDurabilityBodyLocs[7] = { 1, 3, 8, 9, 10, 4, 5 }; // 0x007223E8

extern int gnUiRecordIndex = 2; // 0x00722354

extern int gaBeltKeys[4] = { 23, 24, 25, 26 }; // 0x00722404

extern "C" struct d2data_00722318_t gData_00722318 = {
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
}; // 0x00722318
