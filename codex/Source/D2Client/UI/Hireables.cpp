#include "D2LanguageNames.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2StormTypes.h"
#include "D2CelContext.h"
#include "D2LevelTxt.h"
#include "D2Unicode.h"
#include "D2ClientUiRecords.h"

#define D2_FREE_PANEL_CEL(pCel) if (pCel) { ARCHIVE_FreeClientCellFile(pCel); pCel = 0; }

struct D2PetTypeTxt;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

int __stdcall SRegLoadValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long* pValue); // 0x00414F10

void* __fastcall GAME_LoadUiCelFile(const char* szPath); // 0x004520C0

int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0

int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

int __fastcall ROSTERPETS_FindPetIdByOwner(D2UnitStrc* pUnit, int nType, int bAny); // 0x00478F20

int __fastcall ROSTERPETS_HasPets(D2UnitStrc* pUnit); // 0x00478F70

int __fastcall ROSTER_HasPartyMate(D2UnitStrc* pUnit); // 0x0047A2C0

void __fastcall WARDENCLIENT_DrawSkillInfo(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nX, int nY, int nArg); // 0x00496BE0

int __stdcall D2GFX_GetResolutionMode(); // 0x004F5160

D2SkillStrc* __stdcall UNITS_GetLeftSkill(D2UnitStrc* pUnit); // 0x00620190

D2SkillStrc* __stdcall UNITS_GetRightSkill(D2UnitStrc* pUnit); // 0x006201D0

void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643BC0

void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643C50

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0

extern int gnScreenWidth; // 0x0071146C

extern D2DataTablesStrc* sgptDataTables; // 0x00744304


static int gnPetIconPopupState;                                                                               // 0x007BEECC

extern void* gpCel_007BEF18; // 0x007BEF18

extern void* gpCtrlPnl7Cel; // 0x007BEF1C

extern void* gp800CtrlPnl7Cel; // 0x007BEF74

extern int gbBeltRowsShown; // 0x007BEFA0

extern unsigned char gnTextColorA; // 0x007BEFBB

extern unsigned char gnTextColorB; // 0x007BEFE4

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0


extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

int __fastcall ROSTERPETS_GetHirelingClassId(int nUnitId); // 0x00479120

extern const unsigned int gdwBitMasks[]; // 0x006CE268

void** gpHirelingRecords; // 0x007BEEAC

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

void __fastcall VIEW_SetPetEntryValue(D2UnitStrc* pOwner, D2UnitStrc* pRecord, int nValue); // 0x00467410

int __cdecl GAME_IsExpansion(); // 0x0044DCC0

int __stdcall ITEMS_CheckItemFlag(D2UnitStrc*,unsigned int,int,const char*); // 0x006280A0

int __stdcall ITEMSIsA(D2UnitStrc*,int); // 0x00629BB0

unsigned int __stdcall ITEMS_CheckWeaponIfTwoHanded(D2UnitStrc*); // 0x006289C0

int __stdcall ITEMS_CheckRequirements(D2UnitStrc*,D2UnitStrc*,int,int*,int*,int*); // 0x0062EAF0

void __fastcall UNITSND_PlayEventSound(int,unsigned char,unsigned short); // 0x004CBDE0

int gnGlobal_007BEEDC; // 0x007BEEDC

static int gbPopupPending; // 0x007BEEE0

int gnGlobal_007BEEE8; // 0x007BEEE8

void* gpHelpBorderCel; // 0x007BEEEC

void* gpHelpWhiteBulletCel; // 0x007BEEF0

void* gpHelpYellowBulletCel; // 0x007BEEF4

void* gpRunButtonCel; // 0x007BEF0C

void* gpPopBeltCel; // 0x007BEF10

void* gpGemSocketCel; // 0x007BEF14

void* gpSkillPointsCel; // 0x007BEF20

void* gpInvWarnCel; // 0x007BEF24

void* gpHostilePicCel; // 0x007BEF28

void* gpMenuPanelCel; // 0x007BEF2C

void* gpDuroIconCel; // 0x007BEF60

void* gpInvCharCel; // 0x007BEF64

void* gpHlthManaCel; // 0x007BEF68

void* gpStateButtonCel; // 0x007BEF70

void* gpArrowCel; // 0x007BEF78

void* gpBtnCel; // 0x007BEF7C

void* gpOverlapCel; // 0x007BEF80

struct D2StoredUnitRecordStrc;

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();                                    // 0x006CC260

int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue); // 0x004150E0

int __cdecl sub_0045AE90();                                                                                 // 0x0045AE90

short __fastcall CUNIT_GetPlayerPartyId(D2UnitStrc* pUnit); // 0x00465400

const Unicode* __fastcall CUNIT_GetUnitName(D2UnitStrc* pUnit);                                     // 0x00464A60

int __fastcall ROSTERPETS_CountPets(D2UnitStrc* pOwner, int nPetType);                                 // 0x00478EE0

int __fastcall ROSTER_GetPetLife(int nUnitId);                                                       // 0x00479080

D2StoredUnitRecordStrc* __fastcall ROSTER_GetNextStoredUnit(D2StoredUnitRecordStrc* pEntry);              // 0x004795A0

extern "C" const char* __fastcall ROSTER_GetEntryName(D2StoredUnitRecordStrc* pEntry); // 0x004795C0

int __fastcall ROSTER_GetClassId(D2StoredUnitRecordStrc* pEntry);                                                // 0x00479BA0

unsigned short __fastcall ROSTER_GetEntryIndex(D2StoredUnitRecordStrc* pEntry);                      // 0x00479BC0

int __fastcall ROSTER_GetRecordUnitId(D2StoredUnitRecordStrc* pRecord);                              // 0x0047A0C0

int __fastcall ROSTER_GetPartyLife(int nUnitId);                                                     // 0x0047A150

D2CelFileStrc* __fastcall HIREABLES_GetPetIcon(D2UnitStrc* pOwner, int nPetType, int* pUnitId, int* pSingle); // 0x00493240

void __stdcall INV_DrawIconNumber(int nValue, int nX);                                                // 0x00493100

const Unicode* __fastcall CMDTBL_GetKeyName(int nA, int nB);                                         // 0x0046A530

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode); // 0x004F6300

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText);                                             // 0x00501820

void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered);          // 0x00502320

int __fastcall D2Win_10127_SetFont(int nArg);                                                                      // 0x00502EF0

void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5);    // 0x00502280

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);                              // 0x00524A30

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);                                 // 0x00526700

Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount);                    // 0x00526790

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);                                     // 0x005267E0

void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);               // 0x005269D0

extern D2CelFileStrc* gapHirelingIcons[7];                                                         // 0x007BEEB0

static unsigned char gnLifeColorHigh;                                                              // 0x007BEED0

static unsigned char gnLifeColorMid;                                                               // 0x007BEED1

static unsigned char gnLifeColorLow;                                                               // 0x007BEED2

static unsigned char gbLifeColorsInit;                                                             // 0x007BEED3

static int gnPopupX;                                                                               // 0x007BEED4

static int gnPopupY;                                                                               // 0x007BEED8

static int gbPopupShown;                                                                           // 0x007BEEDC

static unsigned char gbOpenMercInvPending;                                                                     // 0x007BEEE4

static int gdwPopupTick;                                                                           // 0x007BEEE8


extern D2HirelingIconRecordStrc* gpHirelingRecords_007BEEAC; // 0x007BEEAC
extern "C" size_t __cdecl strlen(const char* szString);




static inline int InBox(int nX, int nY, int nLeft, int nRight, int nTop, int nBottom)
{
    return nX >= nLeft && nX <= nRight && nY >= nTop && nY <= nBottom;
}

int __cdecl HIREABLES_GetHelpMenuSetting(); // 0x004942D0
int __stdcall HIREABLES_CanEquipHirelingItem(int playSound); // 0x004934D0
void __stdcall sub_K04_EmitUse(int nValue);

// 0x00492BC0
int __cdecl VIEW_GetPetTypeCount()
{
    return sgptDataTables->nPetTypeTxtRecordCount;
}

// 0x00492BD0
int __fastcall VIEW_IsInPetIcon(SMSGHANDLER_PARAMS* pMsg)
{
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    return gnPetIconPopupState != 2 && InBox(nX, nY, gnPopupX, gnPopupX + 0x2E, 0x18, 0x18 + 0x24);
}

// 0x00492C10
int __cdecl VIEW_IsPetIconVisible()
{
    return gnPetIconPopupState != 2;
}

// 0x00492C20
void __cdecl HIREABLES_LoadHirelingIcons()
{
    char aszClassIcons[5][32] = {
        "Hireables\\AmazonIcon",
        "Hireables\\SorceressIcon",
        "Hireables\\BarbarianIcon",
        "Hireables\\PaladinIcon",
        "Hireables\\NecromancerIcon",
    };
    char aszExpansionIcons[7][32] = {
        "Hireables\\AssassinIcon",
        "Hireables\\DruidIcon",
    };
    memset(gapHirelingIcons, 0, sizeof(gapHirelingIcons));
    int nIcon = 0;
    for (int i = 0; i < 5; ++i, ++nIcon)
    {
        gapHirelingIcons[nIcon] = (D2CelFileStrc*)GAME_LoadUiCelFile(aszClassIcons[i]);
    }
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (FOG_IsExpansion())
    {
        for (int i = 0; i < 7; ++i, ++nIcon)
        {
            if (!strlen(aszExpansionIcons[i]))
            {
                break;
            }
            gapHirelingIcons[nIcon] = (D2CelFileStrc*)GAME_LoadUiCelFile(aszExpansionIcons[i]);
        }
    }
    const int nSize = sgptDataTables->nPetTypeTxtRecordCount * sizeof(D2HirelingIconRecordStrc);
    gpHirelingRecords_007BEEAC = (D2HirelingIconRecordStrc*)sub_0040B430(0, nSize, ".\\UI\\Hireables.cpp", 0x96, 0);
    memset(gpHirelingRecords_007BEEAC, 0, nSize);
}

// 0x00492EC0
void __cdecl HIREABLES_FreeHirelingIcons()
{
    for (int i = 0; i < 7; ++i)
    {
        if (gapHirelingIcons[i])
        {
            ARCHIVE_FreeClientCellFile(gapHirelingIcons[i]);
            gapHirelingIcons[i] = 0;
        }
    }
    if (gpHirelingRecords)
    {
        const int nCount = sgptDataTables->nPetTypeTxtRecordCount * 5;
        for (int i = 0; i < nCount; ++i)
        {
            void* pCel = gpHirelingRecords[i];
            if (pCel)
            {
                ARCHIVE_FreeClientCellFile(pCel);
            }
        }
        sub_0040B480(0, gpHirelingRecords, ".\\UI\\Hireables.cpp", 0xB7, 0);
        gpHirelingRecords = 0;
    }
}

// 0x00492F40
void __fastcall VIEW_InitLifeColors(int nMode)
{
    if (!nMode)
    {
        if (gbLifeColorsInit)
            return;
        gbLifeColorsInit = 1;
    }

    gnLifeColorHigh = D2Win_10034_MixRGB(0, 0x80, 0);
    gnLifeColorMid = D2Win_10034_MixRGB(0xC0, 0xC0, 0);
    gnLifeColorLow = D2Win_10034_MixRGB(0xFF, 0, 0);
}

// 0x00492F90
void __cdecl VIEW_ResetLifeColors()
{
    gbLifeColorsInit = 0;
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x00492FA0
static void __stdcall HIREABLES_DrawFittedText(int nX, int nY, int nColor, Unicode* pText)
{
    const int nOldFont = D2Win_10127_SetFont(6);
    Unicode* pEnd = &pText[31];
    while (D2Win_10121_GetTextWidth(pText) > 0x42)
    {
        --pEnd;
        pEnd->wChar = 0;
    }
    nX += 0x16 - D2Win_10121_GetTextWidth(pText) / 2;
    if (nX < 0)
        nX = 0;
    D2Win_10117_DrawText(pText, nX, nY, nColor, 0);
    D2Win_10127_SetFont(nOldFont);
}

// 0x00493020
static void __stdcall HIREABLES_DrawPetTypeName(int nX, int nY, int nPetType)
{
    D2PetTypeTxt* pPetTypeTxt = (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount) ? &sgptDataTables->pPetTypeTxt[nPetType] : 0;
    if (pPetTypeTxt && pPetTypeTxt->wStringId > 0 && pPetTypeTxt->wStringId != 0x1506)
    {
        Unicode wszName[32];
        sub_005267E0(wszName, D2LANG_GetStringFromTblIndex(pPetTypeTxt->wStringId));
        HIREABLES_DrawFittedText(nX, nY, 0, wszName);
    }
}

// 0x004930A0
static void __stdcall HIREABLES_DrawRosterName(const char* szName, int nX, int nY)
{
    unsigned short wszName[32];
    for (int i = 0; i < 32; ++i)
    {
        wszName[i] = 0;
    }
    sub_00526320_ToUnicode((Unicode*)wszName, szName, 32);
    HIREABLES_DrawFittedText(nX, nY, 0, (Unicode*)wszName);
}

struct D2UnitStrc;


int __fastcall sub_00526800(const Unicode* pString); // 0x00526800


// 0x00493100
void __stdcall INV_DrawIconNumber(int nValue, int nX)
{
    unsigned short wszConvertedBuf[32];
    Unicode* wszConverted = (Unicode*)wszConvertedBuf;
    for (int i = 0; i < 32; ++i)
    {
        wszConverted[i].wChar = 0;
    }
    unsigned short wszTextBuf[32];
    Unicode* wszText = (Unicode*)wszTextBuf;
    for (int i = 0; i < 32; ++i)
    {
        wszText[i].wChar = 0;
    }
    char szNumber[0x20];
    sprintf(szNumber, szIntFormat_006D57BC, nValue);
    memset(wszText, 0, sizeof(wszTextBuf));
    sub_00526320_ToUnicode(wszConverted, szNumber, 32);
    Unicode::strncpy(wszText, wszConverted, 32);
    wszText[31].wChar = 0;
    Unicode* pEnd = &wszText[sub_00526800(wszText)];
    while (D2Win_10121_GetTextWidth(wszText) > 0x2E)
    {
        --pEnd;
        pEnd->wChar = 0;
    }
    const int nOldFont = D2Win_10127_SetFont(6);
    D2Win_10117_DrawText(wszText, nX + 8, 0x37, 0, 0);
    D2Win_10127_SetFont(nOldFont);
}

// 0x00493220
static inline void HIREABLES_ToggleAmount(int* pTotal, int* pAmount)
{
    if (*pAmount)
    {
        *pTotal -= *pAmount;
        *pAmount = 0;
    }
    else
    {
        *pAmount = 10;
        *pTotal += 10;
    }
}

void __fastcall sub_M110_Emit_00493220(int* pTotal, int* pAmount)
{
    HIREABLES_ToggleAmount(pTotal + 1, pAmount);
}

static inline D2PetTypeTxt* sub_00493240_GetPetTypeTxtRecord(int nPetType)
{
    if (nPetType >= 0 && nPetType < sgptDataTables->nPetTypeTxtRecordCount)
    {
        return &sgptDataTables->pPetTypeTxt[nPetType];
    }
    return 0;
}

int __cdecl GAME_GetConnectionType(); // 0x0044DB30

unsigned short __fastcall CUNIT_GetHotkeyBinding(int nA, int nB); // 0x00469AA0

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

void __fastcall MSG_SendWord(unsigned char nCmd, unsigned short nArg); // 0x004785B0

int gnGlobal_007BEED4; // 0x007BEED4

// 0x004936E0
void __stdcall WARDENCLIENT_HandlePetIconClick(SMSGHANDLER_PARAMS* pMsg)
{
    if (!GAME_IsExpansion())
    {
        return;
    }
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    pMsg->bReturn = 0;
    const int bHit = gnPetIconPopupState != 2 && InBox(nX, nY, gnGlobal_007BEED4, gnGlobal_007BEED4 + 0x2E, 0x18, 0x18 + 0x24);
    if (!bHit)
    {
        gnGlobal_007BEEE8 = 0;
        return;
    }
    if (HIREABLES_CanEquipHirelingItem(1))
    {
        MSG_SendWord(0x61, 0);
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}

// 0x00493760
void __stdcall HIREABLES_HirelingIconHoverMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (!GAME_IsExpansion())
    {
        return;
    }
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    pMsg->bReturn = 0;
    gbPopupPending = 0;
    const int bHit = gnPetIconPopupState != 2 && InBox(nX, nY, gnPopupX, gnPopupX + 0x2E, 0x18, 0x18 + 0x24);
    if (!bHit)
    {
        gbPopupShown = 0;
        gdwPopupTick = 0;
        return;
    }
    if (!gdwPopupTick)
    {
        gdwPopupTick = GetTickCount();
    }
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2UnitStrc* pCursorItem = pPlayer ? INVENTORY_GetCursorItem(pPlayer->pInventory) : 0;
    if (!pCursorItem)
    {
        if (ROSTERPETS_FindPetIdByOwner(sub_00463DD0_GetPlayerUnit(), 7, 0) != -1)
        {
            gbPopupPending = 1;
            if (GetTickCount() - gdwPopupTick >= 700)
            {
                gbPopupShown = 1;
            }
        }
    }
    if (HIREABLES_CanEquipHirelingItem(0))
    {
        gbPopupShown = 1;
    }
}

// 0x00493840
void __cdecl HIREABLES_TogglePetIconPopup()
{
    switch (gnPetIconPopupState)
    {
    case 0:
        if (!GAME_GetConnectionType())
        {
            gnPetIconPopupState = 2;
            gnGlobal_007BEEE8 = 0;
            UI_SetUIVar(0x23, 1, 0);
        }
        else
        {
            gnPetIconPopupState = 1;
            UI_SetUIVar(0x23, 0, 0);
        }
        break;

    case 1:
        if (!GAME_GetConnectionType())
        {
            gnPetIconPopupState = 0;
            UI_SetUIVar(0x23, 0, 0);
        }
        else
        {
            gnPetIconPopupState = 2;
            gnGlobal_007BEEE8 = 0;
            UI_SetUIVar(0x23, 1, 0);
        }
        break;

    default:
        gnPetIconPopupState = 0;
        UI_SetUIVar(0x23, 0, 0);
        break;
    }
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


// 0x004938E0
void __stdcall HIREABLES_HirelingIconClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (!GAME_IsExpansion())
    {
        return;
    }
    const int nX = pMsg->nXpos;
    const int nY = pMsg->nYpos;
    pMsg->bReturn = 0;
    const int bHit = gnPetIconPopupState != 2 && InBox(nX, nY, gnPopupX, gnPopupX + 0x2E, 0x18, 0x18 + 0x24);
    if (!bHit)
    {
        gdwPopupTick = 0;
        return;
    }
    if (!gdwPopupTick)
    {
        gdwPopupTick = GetTickCount();
    }
    if (GetTickCount() - gdwPopupTick >= 700)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
        if (!GAME_GetUIVarState(0x23) || GAME_GetUIVarState(0x24) || ROSTERPETS_FindPetIdByOwner(sub_00463DD0_GetPlayerUnit(), 7, 0) == -1)
        {
            return;
        }
        UI_SetUIVar(0x24, 0, 0);
    }
    gdwPopupTick = 0;
}

// 0x004939B0
void __cdecl TEXT_LoadPopupHireling()
{
    gnPetIconPopupState = 0;
    UI_SetUIVar(0x23, 0, 0);
    unsigned long dwValue = 0;
    SRegLoadValue("Diablo II", "PopupHireling", 0, &dwValue);
    if (!dwValue)
    {
        gbOpenMercInvPending = 1;
    }
}

// 0x00494300
static inline void HIREABLES_SetHelpMenuSetting(unsigned long dwValue)
{
// build: symbol ?gdwHelpMenu@* 0x00722310
    gdwHelpMenu = dwValue;
    SRegSaveValue("Diablo II", "Help Menu", 1, dwValue);
}

void __fastcall sub_M115_Emit_00494300(unsigned long dwValue)
{
    HIREABLES_SetHelpMenuSetting(dwValue);
}

// 0x00494320
void __cdecl HIREABLES_LoadHelpCels()
{
    if (D2GFX_GetResolutionMode() == 2)
    {
        if (!gpHelpBorderCel)
        {
            gpHelpBorderCel = GAME_LoadUiCelFile("Menu\\800helpborder");
        }
        else
        {
            ARCHIVE_FreeClientCellFile(gpHelpBorderCel);
            gpHelpBorderCel = 0;
            gpHelpBorderCel = GAME_LoadUiCelFile("Menu\\800helpborder");
        }
    }
    else
    {
        if (!gpHelpBorderCel)
        {
            gpHelpBorderCel = GAME_LoadUiCelFile("Menu\\helpborder");
        }
        else
        {
            ARCHIVE_FreeClientCellFile(gpHelpBorderCel);
            gpHelpBorderCel = 0;
            gpHelpBorderCel = GAME_LoadUiCelFile("Menu\\helpborder");
        }
    }
    if (!gpHelpWhiteBulletCel)
    {
        gpHelpWhiteBulletCel = GAME_LoadUiCelFile("Menu\\helpwhitebullet");
    }
    if (!gpHelpYellowBulletCel)
    {
        gpHelpYellowBulletCel = GAME_LoadUiCelFile("Menu\\helpyellowbullet");
    }
}

void __stdcall D2GFX_DrawLine(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, unsigned char nAlpha); // 0x004F6380

static int gbHelpCloseButtonDown; // 0x007BEEFC

extern void* gpLevelCel; // 0x007C02DC

extern void* gpLevelSocketCel; // 0x007C02E0

int gnGlobal_007BEF04; // 0x007BEF04

int gbHelpButtonVisible; // 0x007BEF08

void __cdecl sub_00499E30();

void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, int nArg5, int nArg6); // 0x0046EFD0

unsigned char gnHelpShadeColor; // 0x007BEEF8

// 0x004943B0
void __cdecl VIEW_DrawHelpFrameLowRes()
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpHelpBorderCel;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, 0, 0x100, -1, 5, 0);
    tContext.nFrame = 1;
    sub_004F6480(&tContext, 0x100, 0x100, -1, 5, 0);
    tContext.nFrame = 2;
    sub_004F6480(&tContext, 0, gnScreenHeight - 0x30, -1, 5, 0);
    tContext.nFrame = 3;
    sub_004F6480(&tContext, 0x100, gnScreenHeight - 0x30, -1, 5, 0);
    tContext.nFrame = 4;
    sub_004F6480(&tContext, 0x140, 0x100, -1, 5, 0);
    tContext.nFrame = 5;
    sub_004F6480(&tContext, 0x240, 0x100, -1, 5, 0);
    tContext.nFrame = 6;
    sub_004F6480(&tContext, 0x140, gnScreenHeight - 0x30, -1, 5, 0);
    tContext.nFrame = 7;
    sub_004F6480(&tContext, 0x240, gnScreenHeight - 0x30, -1, 5, 0);
}

// 0x004944F0
void __cdecl VIEW_DrawHelpFrameHighRes()
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpHelpBorderCel;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, 0, 0x100, -1, 5, 0);
    tContext.nFrame = 1;
    sub_004F6480(&tContext, 0, 0x200, -1, 5, 0);
    tContext.nFrame = 2;
    sub_004F6480(&tContext, 0x42, 0x14, -1, 5, 0);
    tContext.nFrame = 3;
    sub_004F6480(&tContext, 0x142, 0x14, -1, 5, 0);
    tContext.nFrame = 4;
    sub_004F6480(&tContext, 0x217, 0x100, -1, 5, 0);
    tContext.nFrame = 5;
    sub_004F6480(&tContext, 0x30C, 0x100, -1, 5, 0);
    tContext.nFrame = 6;
    sub_004F6480(&tContext, 0x30C, 0x200, -1, 5, 0);
}

// 0x004945F0
void __cdecl VIEW_DrawHelpShade()
{
    sub_00499E30();
    AUTOMAP_DrawFramedBox(0, 0, gnScreenWidth, gnScreenHeight - 0x31, gnHelpShadeColor, 1);
}

void __cdecl GAME_ResetMouseButtons();                                                                                // 0x0044DA70

// 0x00494620
void __cdecl ROSTERPETS_DrawHelpColumn()
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpHelpYellowBulletCel;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    int nY = 0x49;
    for (int i = 0; i < 8; ++i)
    {
        sub_004F6480(&tContext, 0x68, nY, -1, 5, 0);
        nY += 0x14;
    }
}

// 0x00494680
void __cdecl VIEW_DrawHelpLinesLowRes()
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpHelpWhiteBulletCel;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, 0x33, 0x19E, -1, 5, 0);
    D2GFX_DrawLine(0x36, 0x16D, 0x36, 0x19B, 0xFF, 0xFF);
    D2GFX_DrawLine(0x37, 0x16D, 0x37, 0x19B, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0x7F, 0x1BC, -1, 5, 0);
    D2GFX_DrawLine(0x82, 0x145, 0x82, 0x1B9, 0xFF, 0xFF);
    D2GFX_DrawLine(0x83, 0x145, 0x83, 0x1B9, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0xB2, 0x1D0, -1, 5, 0);
    D2GFX_DrawLine(0xB5, 0x195, 0xB5, 0x1CD, 0xFF, 0xFF);
    D2GFX_DrawLine(0xB6, 0x195, 0xB6, 0x1CD, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0xE3, 0x1D0, -1, 5, 0);
    D2GFX_DrawLine(0xE6, 0x16D, 0xE6, 0x1CD, 0xFF, 0xFF);
    D2GFX_DrawLine(0xE7, 0x16D, 0xE7, 0x1CD, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0x11C, 0x1BD, -1, 5, 0);
    D2GFX_DrawLine(0x11F, 0x195, 0x11F, 0x1BA, 0xFF, 0xFF);
    D2GFX_DrawLine(0x120, 0x195, 0x120, 0x1BA, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0x15E, 0x19F, -1, 5, 0);
    D2GFX_DrawLine(0x161, 0x145, 0x161, 0x19B, 0xFF, 0xFF);
    D2GFX_DrawLine(0x162, 0x145, 0x162, 0x19B, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0x1BD, 0x1C2, -1, 5, 0);
    D2GFX_DrawLine(0x1C0, 0x195, 0x1C0, 0x1BE, 0xFF, 0xFF);
    D2GFX_DrawLine(0x1C1, 0x195, 0x1C1, 0x1BE, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0x1F7, 0x1BD, -1, 5, 0);
    D2GFX_DrawLine(0x1FA, 0x145, 0x1FA, 0x1B9, 0xFF, 0xFF);
    D2GFX_DrawLine(0x1FB, 0x145, 0x1FB, 0x1B9, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0x246, 0x19F, -1, 5, 0);
    D2GFX_DrawLine(0x249, 0x16D, 0x249, 0x19B, 0xFF, 0xFF);
    D2GFX_DrawLine(0x24A, 0x16D, 0x24A, 0x19B, 0xFF, 0xFF);
}

// 0x00494A00
void __cdecl VIEW_DrawHelpLinesHighRes()
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpHelpWhiteBulletCel;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, 0x37, 0x217, -1, 5, 0);
    D2GFX_DrawLine(0x3A, 0x1E6, 0x3A, 0x214, 0xFF, 0xFF);
    D2GFX_DrawLine(0x3B, 0x1E6, 0x3B, 0x214, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0x82, 0x234, -1, 5, 0);
    D2GFX_DrawLine(0x85, 0x1BD, 0x85, 0x231, 0xFF, 0xFF);
    D2GFX_DrawLine(0x86, 0x1BD, 0x86, 0x231, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0xD9, 0x23F, -1, 5, 0);
    D2GFX_DrawLine(0xDC, 0x177, 0xDC, 0x23C, 0xFF, 0xFF);
    D2GFX_DrawLine(0xDD, 0x177, 0xDD, 0x23C, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0x104, 0x249, -1, 5, 0);
    D2GFX_DrawLine(0x107, 0x20E, 0x107, 0x246, 0xFF, 0xFF);
    D2GFX_DrawLine(0x108, 0x20E, 0x108, 0x246, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0x136, 0x249, -1, 5, 0);
    D2GFX_DrawLine(0x139, 0x1E6, 0x139, 0x246, 0xFF, 0xFF);
    D2GFX_DrawLine(0x13A, 0x1E6, 0x13A, 0x246, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0x16D, 0x235, -1, 5, 0);
    D2GFX_DrawLine(0x170, 0x20D, 0x170, 0x232, 0xFF, 0xFF);
    D2GFX_DrawLine(0x171, 0x20D, 0x171, 0x232, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0x1BD, 0x21C, -1, 5, 0);
    D2GFX_DrawLine(0x1C0, 0x1C3, 0x1C0, 0x219, 0xFF, 0xFF);
    D2GFX_DrawLine(0x1C1, 0x1C3, 0x1C1, 0x219, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0x212, 0x239, -1, 5, 0);
    D2GFX_DrawLine(0x215, 0x20D, 0x215, 0x236, 0xFF, 0xFF);
    D2GFX_DrawLine(0x216, 0x20D, 0x216, 0x236, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0x23C, 0x23F, -1, 5, 0);
    D2GFX_DrawLine(0x23F, 0x177, 0x23F, 0x23C, 0xFF, 0xFF);
    D2GFX_DrawLine(0x240, 0x177, 0x240, 0x23C, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0x29E, 0x234, -1, 5, 0);
    D2GFX_DrawLine(0x2A1, 0x1BD, 0x2A1, 0x231, 0xFF, 0xFF);
    D2GFX_DrawLine(0x2A2, 0x1BD, 0x2A2, 0x231, 0xFF, 0xFF);
    sub_004F6480(&tContext, 0x2E4, 0x217, -1, 5, 0);
    D2GFX_DrawLine(0x2E7, 0x1E6, 0x2E7, 0x214, 0xFF, 0xFF);
    D2GFX_DrawLine(0x2E8, 0x1E6, 0x2E8, 0x214, 0xFF, 0xFF);
}

// 0x00494E40
void __cdecl VIEW_DrawHelpPanelCel()
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = sub_00454600();
    tContext.nFrame = (gbHelpCloseButtonDown != 0) + 10;
    tContext.nDirection = 0;
    if (D2GFX_GetResolutionMode() == 2)
    {
        sub_004F6480(&tContext, 0x2AD, 0x38, -1, 5, 0);
    }
    else
    {
        sub_004F6480(&tContext, 0x20D, 0x38, -1, 5, 0);
    }
}

void __cdecl PANEL_SetBlackColour();                                                                                // 0x00499E30

// 0x00494EB0
void __cdecl sub_00494EB0()
{
    PANEL_SetBlackColour();
    AUTOMAP_DrawFramedBox(0, 0, gnScreenWidth, gnScreenHeight - 0x31, gnHelpShadeColor, 1);
}

// 0x00494EE0
void __cdecl HIREABLES_FreeHelpCels()
{
    if (gpHelpBorderCel)
    {
        ARCHIVE_FreeClientCellFile(gpHelpBorderCel);
        gpHelpBorderCel = 0;
    }
    if (gpHelpWhiteBulletCel)
    {
        ARCHIVE_FreeClientCellFile(gpHelpWhiteBulletCel);
        gpHelpWhiteBulletCel = 0;
    }
    if (gpHelpYellowBulletCel)
    {
        ARCHIVE_FreeClientCellFile(gpHelpYellowBulletCel);
        gpHelpYellowBulletCel = 0;
    }
}

extern int gbHelpUiOpened;                                                                         // 0x007BEF00

// 0x00494F30
void __stdcall ROSTERPETS_HandleHelpButtonDown(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = pMsg->nXpos;
    int nY = pMsg->nYpos;
    if (D2GFX_GetResolutionMode() == 2)
    {
        if (nX >= 0x2AD && nX <= 0x2CD && nY >= 0x18 && nY <= 0x38)
        {
            gbHelpCloseButtonDown = 1;
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
    else
    {
        if (nX >= 0x20D && nX <= 0x22D && nY >= 0x18 && nY <= 0x38)
        {
            gbHelpCloseButtonDown = 1;
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }
    }
    GAME_ResetMouseButtons();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}



// 0x00494FB0
void __stdcall sub_00494FB0(int nUnused1)
{
}

// 0x00494FC0
void __cdecl HIREABLES_CloseHelpUi()
{
    if (gbHelpUiOpened)
    {
        UI_SetUIVar(0x15, 1, 0);
        gbHelpUiOpened = 0;
    }
}


// 0x00494FF0
static int __stdcall HIREABLES_IsMouseInBox(int nLeft, int nBottom, int nWidth, int nHeight)
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    if (nMouseX >= nLeft && nMouseX <= nLeft + nWidth && nMouseY >= nBottom - nHeight && nMouseY <= nBottom)
        return 1;
    return 0;
}

void __fastcall sub_K04_EmitIsMouseInBox(int nX, int nY)
{
    sub_K04_EmitUse(HIREABLES_IsMouseInBox(nX + 0x31, nY - 0x27, 0x23, 0x25));
}

// 0x00495030
void __cdecl HIREABLES_DrawKeyHelp()
{
    Unicode wszText[200];
    Unicode wszKey[30];
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x1051));
    if (CUNIT_GetHotkeyBinding(6, 1) != 0xFFFF)
    {
        memset(wszKey, 0, sizeof(wszKey));
        sub_005269D0(30, wszKey, D2LANG_GetStringFromTblIndex(0x1052), CMDTBL_GetKeyName(6, 1));
        sub_00526700(wszText, wszKey);
    }
    if (CUNIT_GetHotkeyBinding(6, 0) != 0xFFFF)
    {
        memset(wszKey, 0, sizeof(wszKey));
        sub_005269D0(30, wszKey, D2LANG_GetStringFromTblIndex(0x1052), CMDTBL_GetKeyName(6, 0));
        sub_00526700(wszText, wszKey);
    }
    const int nWidth = D2Win_10121_GetTextWidth(wszText);
    D2Win_10117_DrawText(wszText, gnScreenWidth - nWidth / 2 - 0x3A, gnScreenHeight - 0xC5, 0, 0);
}

// 0x00495180
void __cdecl VIEW_DrawHelpButtons()
{
    if (GAME_GetUIVarState(4) || GAME_GetUIVarState(3) || GAME_GetUIVarState(1) || GAME_GetUIVarState(0xC)
        || GAME_GetUIVarState(0x17) || GAME_GetUIVarState(0x19))
    {
        gbHelpButtonVisible = 1;
        return;
    }
    gbHelpButtonVisible = 0;
    if (!HIREABLES_GetHelpMenuSetting())
    {
        D2CelContextStrc tContext;
        memset(&tContext, 0, sizeof(tContext));
        HIREABLES_DrawKeyHelp();
        tContext.pCellFile = gpLevelSocketCel;
        tContext.nDirection = 0;
        tContext.nFrame = 0;
        sub_004F6480(&tContext, gnScreenWidth - 0x4B, gnScreenHeight - 0xA0, -1, 5, 0);
        tContext.pCellFile = gpLevelCel;
        tContext.nFrame = gnGlobal_007BEF04 != 0;
        sub_004F6480(&tContext, gnScreenWidth - 0x48, gnScreenHeight - 0xA4, -1, 5, 0);
    }
    else
    {
        UI_SetUIVar(0x22, 1, 0);
    }
}

extern int gnGlobal_00722310; // 0x00722310

static int gbHelpButtonPressed; // 0x007BEF04

// 0x004952B0
void __stdcall HIREABLES_ButtonDownMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gbHelpButtonVisible)
    {
        return;
    }
    const int nBottom = gnScreenHeight - 0xA0;
    const int nLeft = gnScreenWidth - 0x4B;
    const int nX = sub_00468730();
    const int nY = sub_00468740();
    if (nX >= nLeft && nX <= nLeft + 0x23 && nY >= nBottom - 0x24 && nY <= nBottom)
    {
        gbHelpButtonPressed = 1;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}

// 0x00495320
void __stdcall HIREABLES_ButtonUpMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gbHelpButtonVisible)
    {
        return;
    }
    const int nBottom = gnScreenHeight - 0xA0;
    const int nLeft = gnScreenWidth - 0x4B;
    const int nX = sub_00468730();
    const int nY = sub_00468740();
    if (nX >= nLeft && nX <= nLeft + 0x23 && nY >= nBottom - 0x24 && nY <= nBottom)
    {
        UI_SetUIVar(0x22, 1, 0);
        UI_SetUIVar(0x21, 2, 0);
        gnGlobal_00722310 = 1;
        SRegSaveValue("Diablo II", "Help Menu", 1, 1);
        gbHelpButtonPressed = 0;
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }
}

void __stdcall sub_00420290_HandleMsg(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

D2CelFileStrc* __fastcall ARCHIVE_LoadClientCellFile(const char* szFile, int nType); // 0x004788B0

extern void* gpCellFile_007BEF78; // 0x007BEF78

extern void* gpCellFile_007BEF10; // 0x007BEF10

extern void* gpCellFile_007BEF2C; // 0x007BEF2C

extern void* gpCellFile_007BEF20; // 0x007BEF20

int gdwGlobal_007BEEFC; // 0x007BEEFC

int __cdecl STRTABLE_GetLanguage();                                                                         // 0x00525150

const Unicode* __fastcall CMDTBL_GetKeyText(int nKey, int nArg2);                                     // 0x00469DE0

static int __fastcall GetCenteredXInline(unsigned short nString, int nX)
{
    unsigned short wszTextBuf[100];
    Unicode* wszText = (Unicode*)wszTextBuf;
    for (int i = 0; i < 100; ++i)
    {
        wszText[i].wChar = 0;
    }
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nString));
    int nWidth = D2Win_10121_GetTextWidth(wszText);
    nWidth /= 2;
    return nX - nWidth;
}

static int __fastcall GetCenteredX_Inl(unsigned short nString, int nX)
{
    unsigned short wszTextBuf[100];
    Unicode* wszText = (Unicode*)wszTextBuf;
    for (int i = 0; i < 100; ++i)
    {
        wszText[i].wChar = 0;
    }
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nString));
    int nWidth = D2Win_10121_GetTextWidth(wszText);
    nWidth /= 2;
    return nX - nWidth;
}

// 0x004953C0
int __fastcall INV_GetCenteredX(unsigned short nString, int nX)
{
    unsigned short wszTextBuf[100];
    Unicode* wszText = (Unicode*)wszTextBuf;
    for (int i = 0; i < 100; ++i)
    {
        wszText[i].wChar = 0;
    }
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nString));
    return nX - D2Win_10121_GetTextWidth(wszText) / 2;
}

// 0x00495410
void __cdecl sub_00495410_DrawHelpText()
{
    unsigned short wszLine1Buf[100];
    Unicode* wszLine1 = (Unicode*)wszLine1Buf;
    unsigned short wszLine2Buf[100];
    Unicode* wszLine2 = (Unicode*)wszLine2Buf;
    unsigned short wszLine3Buf[100];
    Unicode* wszLine3 = (Unicode*)wszLine3Buf;
    unsigned short wszLine4Buf[100];
    Unicode* wszLine4 = (Unicode*)wszLine4Buf;
    unsigned short wszLine5Buf[100];
    Unicode* wszLine5 = (Unicode*)wszLine5Buf;

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1066), GetCenteredX_Inl(0x1066, 0x17C), 0x11, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1030), GetCenteredX_Inl(0x1030, 0x2BD), 0x49, 0, 0);

    const int nOldFont = D2Win_10127_SetFont(5);

    for (int i = 0; i < 100; ++i)
    {
        wszLine1[i].wChar = 0;
    }
    sub_005269D0(sizeof(wszLine1Buf) / sizeof(wszLine1[0]), wszLine1, D2LANG_GetStringFromTblIndex(0x1067), CMDTBL_GetKeyText(0x22, 1));
    D2Win_10117_DrawText(wszLine1, 0x75, 0x4E, 0, 0);

    for (int i = 0; i < 100; ++i)
    {
        wszLine2[i].wChar = 0;
    }
    sub_005269D0(sizeof(wszLine2Buf) / sizeof(wszLine2[0]), wszLine2, D2LANG_GetStringFromTblIndex(0x1068), CMDTBL_GetKeyText(0x25, 1));
    D2Win_10117_DrawText(wszLine2, 0x75, 0x62, 0, 0);

    for (int i = 0; i < 100; ++i)
    {
        wszLine3[i].wChar = 0;
    }
    sub_005269D0(sizeof(wszLine3Buf) / sizeof(wszLine3[0]), wszLine3, D2LANG_GetStringFromTblIndex(0x1069), CMDTBL_GetKeyText(0x24, 1));
    D2Win_10117_DrawText(wszLine3, 0x75, 0x76, 0, 0);

    for (int i = 0; i < 100; ++i)
    {
        wszLine4[i].wChar = 0;
    }
    sub_005269D0(sizeof(wszLine4Buf) / sizeof(wszLine4[0]), wszLine4, D2LANG_GetStringFromTblIndex(0x106A), CMDTBL_GetKeyText(0x7, 1));
    D2Win_10117_DrawText(wszLine4, 0x75, 0x8A, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x106B), 0x75, 0x9E, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x106C), 0x75, 0xB2, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x106D), 0x75, 0xC6, 0, 0);

    for (int i = 0; i < 100; ++i)
    {
        wszLine5[i].wChar = 0;
    }
    sub_005269D0(sizeof(wszLine5Buf) / sizeof(wszLine5[0]), wszLine5, D2LANG_GetStringFromTblIndex(0x106E), CMDTBL_GetKeyText(0x6, 1));
    D2Win_10117_DrawText(wszLine5, 0x75, 0xDA, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x106F), GetCenteredX_Inl(0x106F, 0x3B), 0x1E1, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1070), GetCenteredX_Inl(0x1070, 0x86), 0x19A, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1071), GetCenteredX_Inl(0x1071, 0x86), 0x1A9, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1072), GetCenteredX_Inl(0x1072, 0x86), 0x1B8, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0xF92), GetCenteredX_Inl(0xF92, 0xDE), 0x177, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1074), GetCenteredX_Inl(0x1074, 0x108), 0x1FA, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1075), GetCenteredX_Inl(0x1075, 0x108), 0x209, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1076), GetCenteredX_Inl(0x1076, 0x13A), 0x1E1, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1077), GetCenteredX_Inl(0x1077, 0x171), 0x1F9, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1078), GetCenteredX_Inl(0x1078, 0x171), 0x208, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1079), GetCenteredX_Inl(0x1079, 0x1C1), 0x191, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x107A), GetCenteredX_Inl(0x107A, 0x1C1), 0x1A0, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x107B), GetCenteredX_Inl(0x107B, 0x1C1), 0x1AF, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x107C), GetCenteredX_Inl(0x107C, 0x1C1), 0x1BE, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x107D), GetCenteredX_Inl(0x107D, 0x216), 0x208, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0xF93), GetCenteredX_Inl(0xF93, 0x23C), 0x177, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1073), GetCenteredX_Inl(0x1073, 0x2A2), 0x19A, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1071), GetCenteredX_Inl(0x1071, 0x2A2), 0x1A9, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1072), GetCenteredX_Inl(0x1072, 0x2A2), 0x1B8, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x107E), GetCenteredX_Inl(0x107E, 0x2E8), 0x1E1, 0, 0);

    D2Win_10127_SetFont(nOldFont);
}

// 0x00495DC0
void __cdecl sub_00495DC0_DrawHelpText()
{
    unsigned short wszLine1Buf[100];
    Unicode* wszLine1 = (Unicode*)wszLine1Buf;
    unsigned short wszLine2Buf[100];
    Unicode* wszLine2 = (Unicode*)wszLine2Buf;
    unsigned short wszLine3Buf[100];
    Unicode* wszLine3 = (Unicode*)wszLine3Buf;
    unsigned short wszLine4Buf[100];
    Unicode* wszLine4 = (Unicode*)wszLine4Buf;
    unsigned short wszLine5Buf[100];
    Unicode* wszLine5 = (Unicode*)wszLine5Buf;

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1066), GetCenteredXInline(0x1066, 0x131), 0x11, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1030), GetCenteredXInline(0x1030, 0x21D), 0x49, 0, 0);

    const int nOldFont = D2Win_10127_SetFont(5);

    for (int i = 0; i < 100; ++i)
    {
        wszLine1[i].wChar = 0;
    }
    sub_005269D0(sizeof(wszLine1Buf) / sizeof(wszLine1[0]), wszLine1, D2LANG_GetStringFromTblIndex(0x1067), CMDTBL_GetKeyText(0x22, 1));
    D2Win_10117_DrawText(wszLine1, 0x75, 0x4E, 0, 0);

    for (int i = 0; i < 100; ++i)
    {
        wszLine2[i].wChar = 0;
    }
    sub_005269D0(sizeof(wszLine2Buf) / sizeof(wszLine2[0]), wszLine2, D2LANG_GetStringFromTblIndex(0x1068), CMDTBL_GetKeyText(0x25, 1));
    D2Win_10117_DrawText(wszLine2, 0x75, 0x62, 0, 0);

    for (int i = 0; i < 100; ++i)
    {
        wszLine3[i].wChar = 0;
    }
    sub_005269D0(sizeof(wszLine3Buf) / sizeof(wszLine3[0]), wszLine3, D2LANG_GetStringFromTblIndex(0x1069), CMDTBL_GetKeyText(0x24, 1));
    D2Win_10117_DrawText(wszLine3, 0x75, 0x76, 0, 0);

    for (int i = 0; i < 100; ++i)
    {
        wszLine4[i].wChar = 0;
    }
    sub_005269D0(sizeof(wszLine4Buf) / sizeof(wszLine4[0]), wszLine4, D2LANG_GetStringFromTblIndex(0x106A), CMDTBL_GetKeyText(0x7, 1));
    D2Win_10117_DrawText(wszLine4, 0x75, 0x8A, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x106B), 0x75, 0x9E, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x106C), 0x75, 0xB2, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x106D), 0x75, 0xC6, 0, 0);

    for (int i = 0; i < 100; ++i)
    {
        wszLine5[i].wChar = 0;
    }
    sub_005269D0(sizeof(wszLine5Buf) / sizeof(wszLine5[0]), wszLine5, D2LANG_GetStringFromTblIndex(0x106E), CMDTBL_GetKeyText(0x6, 1));
    D2Win_10117_DrawText(wszLine5, 0x75, 0xDA, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x106F), GetCenteredXInline(0x106F, 0x37), 0x168, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1070), GetCenteredXInline(0x1070, 0x83), 0x122, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1071), GetCenteredXInline(0x1071, 0x83), 0x131, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1072), GetCenteredXInline(0x1072, 0x83), 0x140, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1074), GetCenteredXInline(0x1074, 0xB6), 0x181, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1075), GetCenteredXInline(0x1075, 0xB6), 0x190, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1076), GetCenteredXInline(0x1076, 0xE7), 0x168, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1077), GetCenteredXInline(0x1077, 0x120), 0x181, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1078), GetCenteredXInline(0x1078, 0x120), 0x190, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1079), GetCenteredXInline(0x1079, 0x162), 0x113, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x107A), GetCenteredXInline(0x107A, 0x162), 0x122, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x107B), GetCenteredXInline(0x107B, 0x162), 0x131, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x107C), GetCenteredXInline(0x107C, 0x162), 0x140, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x107D), GetCenteredXInline(0x107D, 0x1C1), 0x190, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1073), GetCenteredXInline(0x1073, 0x1FB), 0x122, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1071), GetCenteredXInline(0x1071, 0x1FB), 0x131, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1072), GetCenteredXInline(0x1072, 0x1FB), 0x140, 0, 0);

    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x107E), GetCenteredXInline(0x107E, 0x24A), 0x168, 0, 0);

    D2Win_10127_SetFont(nOldFont);
}

// 0x004966C0
void __cdecl INV_DrawHelpScreen()
{
    if (!GAME_GetUIVarState(0x15))
    {
        UI_SetUIVar(0x15, 0, 0);
        gbHelpUiOpened = 1;
    }
    if (D2GFX_GetResolutionMode() == 2)
    {
        VIEW_DrawHelpFrameHighRes();
        VIEW_DrawHelpPanelCel();
        ROSTERPETS_DrawHelpColumn();
        VIEW_DrawHelpLinesHighRes();
        sub_00495410_DrawHelpText();
    }
    else
    {
        VIEW_DrawHelpFrameLowRes();
        VIEW_DrawHelpPanelCel();
        ROSTERPETS_DrawHelpColumn();
        VIEW_DrawHelpLinesLowRes();
        sub_00495DC0_DrawHelpText();
    }
}

// 0x00496720
void __stdcall INV_HelpCloseButtonMsg(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = pMsg->nXpos;
    int nY = pMsg->nYpos;
    if (gdwGlobal_007BEEFC)
    {
        if (D2GFX_GetResolutionMode() == 2)
        {
            if (nX >= 0x2AD && nX <= 0x2CD && nY >= 0x18 && nY <= 0x38)
            {
                UI_SetUIVar(0x21, 2, 0);
                HIREABLES_CloseHelpUi();
                pMsg->bReturn = 1;
                pMsg->lResult = 0;
                sub_00420290_HandleMsg(pMsg);
                return;
            }
        }
        else
        {
            if (nX >= 0x20D && nX <= 0x22D && nY >= 0x18 && nY <= 0x38)
            {
                UI_SetUIVar(0x21, 2, 0);
                HIREABLES_CloseHelpUi();
                pMsg->bReturn = 1;
                pMsg->lResult = 0;
                sub_00420290_HandleMsg(pMsg);
                return;
            }
        }
    }
    gdwGlobal_007BEEFC = 0;
    GAME_ResetMouseButtons();
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_HandleMsg(pMsg);
}

// 0x004967A0
void __stdcall INV_OnKeyCloseHelp(SMSGHANDLER_PARAMS* pMsg)
{
    UI_SetUIVar(0x21, 1, 0);
    if (gbHelpUiOpened)
    {
        UI_SetUIVar(0x15, 1, 0);
        gbHelpUiOpened = 0;
    }
}

// 0x004967E0
void __cdecl sub_004967E0_Empty()
{
}

// 0x004967F0
void __cdecl INV_LoadPanelCels()
{
    char szPath[0x104];
    gpBtnCel = GAME_LoadUiCelFile("Panel\\btn");
    const int nLanguage = STRTABLE_GetLanguage();
    int bExpansion = 0;
    if (FOG_IsExpansion() && GAME_IsExpansion())
    {
        bExpansion = 1;
    }
    if (nLanguage >= 6 && nLanguage <= 9)
    {
        if (bExpansion)
        {
            sprintf(szPath, "%s\\UI\\InvChar6", szDataLocal_006D41A8);
        }
        else
        {
            sprintf(szPath, "%s\\UI\\InvChar", szDataLocal_006D41A8);
        }
        gpCellFile_007BEF64 = ARCHIVE_LoadClientCellFile(szPath, 0);
    }
    else
    {
        gpCellFile_007BEF64 = GAME_LoadUiCelFile(bExpansion ? "Panel\\InvChar6" : "Panel\\InvChar");
    }
    gpCellFile_007BEF78 = GAME_LoadUiCelFile("Panel\\Arrow");
    gpCellFile_007BEF24 = GAME_LoadUiCelFile("Panel\\Invwarn");
    gpCellFile_007BEF60 = GAME_LoadUiCelFile("Panel\\DuroIcon");
    gpCellFile_007BEF14 = GAME_LoadUiCelFile("Panel\\GemSocket");
    gpCellFile_007BEF10 = GAME_LoadUiCelFile("Panel\\ctrlpnl_popbelt");
    gpCellFile_007BEF68 = GAME_LoadUiCelFile("Panel\\Hlthmana");
    gpCellFile_007BEF80 = GAME_LoadUiCelFile("Panel\\overlap");
    gpStateButtonCel_007BEF70 = GAME_LoadUiCelFile("Panel\\menubutton");
    gpCellFile_007BEF2C = GAME_LoadUiCelFile("Panel\\menupanel");
    gpCellFile_007BEF20 = GAME_LoadUiCelFile("Panel\\skillpoints");
    gpGlobal_007BEF0C = GAME_LoadUiCelFile("Panel\\runbutton");
    gpCellFile_007BEF28 = GAME_LoadUiCelFile("Panel\\hostilepic");
    memset(gabGlobal_007BEF30, 0, sizeof(gabGlobal_007BEF30));
    SRegLoadValue("Diablo II", "Show HP Text", 0, &gdwShowHpText_007BEFDC);
    SRegLoadValue("Diablo II", "Show MP Text", 0, &gdwShowMpText_007BEFE0);
}

// 0x00496980
void __cdecl sub_00496980_Empty()
{
}

// 0x00496990
void __cdecl HIREABLES_FreePanelCels()
{
    D2_FREE_PANEL_CEL(gpBtnCel);
    D2_FREE_PANEL_CEL(gpInvCharCel);
    D2_FREE_PANEL_CEL(gpArrowCel);
    D2_FREE_PANEL_CEL(gpInvWarnCel);
    D2_FREE_PANEL_CEL(gpDuroIconCel);
    D2_FREE_PANEL_CEL(gpGemSocketCel);
    D2_FREE_PANEL_CEL(gpPopBeltCel);
    D2_FREE_PANEL_CEL(gp800CtrlPnl7Cel);
    D2_FREE_PANEL_CEL(gpCel_007BEF18);
    D2_FREE_PANEL_CEL(gpCtrlPnl7Cel);
    D2_FREE_PANEL_CEL(gpHlthManaCel);
    D2_FREE_PANEL_CEL(gpOverlapCel);
    D2_FREE_PANEL_CEL(gpStateButtonCel);
    D2_FREE_PANEL_CEL(gpMenuPanelCel);
    D2_FREE_PANEL_CEL(gpSkillPointsCel);
    D2_FREE_PANEL_CEL(gpRunButtonCel);
    D2_FREE_PANEL_CEL(gpHostilePicCel);
    memset(gabGlobal_007BEF30, 0, sizeof(gabGlobal_007BEF30));
}

struct D2SkillsTxt;

int __cdecl ROSTER_IsAnyoneHostile(); // 0x0047A560

int __cdecl CUNIT_IsTrading(); // 0x004B8A10

int __fastcall SPELLSEL_GetSkillIconCel(D2SkillsTxt* pSkillsTxt); // 0x004A8C80

int __fastcall SPELLSEL_GetSkillState(D2UnitStrc* pUnit, D2SkillStrc* pSkill); // 0x004A8D30

void __fastcall SPELLSEL_DrawSkillInfoBase(int nValue, D2SkillsTxt* pSkillsTxt, int nOwnerGUID, int nCharges, int nState, int nX, int nY, int nArg); // 0x004A9690

void __fastcall SPELLSEL_UpdateSkillButtonHover(short* pId, int nState, int nA, int nB, int nX, int nY); // 0x004A8D50

void __fastcall SPELLSEL_DrawSkillQuantity(short* pId, int nState, int nQuantity, int nX, int nY); // 0x004AA1F0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill); // 0x00644140

// 0x00496B10
void __cdecl WARDENCLIENT_DrawHostileIcon()
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    int bPanel = 0;
    int nYOffset = 0;
    if (!ROSTER_IsAnyoneHostile())
    {
        return;
    }
    if (GAME_GetUIVarState(0x19) || GAME_GetUIVarState(0x0C) || GAME_GetUIVarState(0x18) || GAME_GetUIVarState(1) || GAME_GetUIVarState(4))
    {
        bPanel = 1;
    }
    if (GAME_GetUIVarState(0x17) && !CUNIT_IsTrading())
    {
        return;
    }
    if (bPanel)
    {
        return;
    }
    tContext.pCellFile = gpCellFile_007BEF28;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    if (GAME_GetUIVarState(0x0A))
    {
        nYOffset = 0x46;
    }
    sub_004F6480(&tContext, gnScreenWidth - 0x3A, nYOffset + 0x2D, -1, 1, 0);
}

// 0x00496BE0
void __fastcall WARDENCLIENT_DrawSkillInfo(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int nX, int nY, int nArg)
{
    if (!pUnit || !pSkill)
    {
        return;
    }

    D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
    if (!pSkillsTxt)
    {
        return;
    }

    const int nValue = SPELLSEL_GetSkillIconCel(pSkillsTxt);
    int nState = SPELLSEL_GetSkillState(pUnit, pSkill);
    if (!(pSkillsTxt->nFlags[1] & gdwBitMasks[0]))
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
        if (pRoom && DUNGEON_IsRoomInTown(pRoom))
        {
            nState = 1;
        }
    }

    int nOwnerGUID = -1;
    int nSkillLevel = 0;
    int nCharges = 0;
    const int bItemSkill = SKILLS_GetSkillInfo(pSkill, &nOwnerGUID, 0, &nSkillLevel, &nCharges);
    if (!bItemSkill)
    {
        nSkillLevel = SKILLS_GetSkillLevel(pUnit, pSkill, 1);
    }

    int nQuantity = 0;
    if (!bItemSkill)
    {
        nQuantity = SKILLS_GetQuantity(pSkill);
    }

    SPELLSEL_DrawSkillInfoBase(nValue, pSkillsTxt, nOwnerGUID, nCharges, nState, nX, nY, nArg);
    if (nQuantity)
    {
        SPELLSEL_DrawSkillQuantity(&pSkillsTxt->nSkillId, nState, nQuantity, nX, nY);
    }
    else
    {
        SPELLSEL_UpdateSkillButtonHover(&pSkillsTxt->nSkillId, nState, nSkillLevel, nCharges, nX, nY);
    }
}



static void __stdcall sub_00493A00_DrawLifeBar(int nPetType, int nX, int nUnitId)
{
    int nLife = nPetType ? ROSTER_GetPetLife(nUnitId) : ROSTER_GetPartyLife(nUnitId);
    if (!nLife)
        return;

    nLife = nLife <= 0 ? 0 : nLife;
    const int nXEnd = nX + 0x2E;
    if (nLife >= 100)
        nLife = 100;
    const int nXFill = nX + nLife * 0x2E / 100;
    if (!gbLifeColorsInit)
    {
        gbLifeColorsInit = 1;
        gnLifeColorHigh = D2Win_10034_MixRGB(0, 0x80, 0);
        gnLifeColorMid = D2Win_10034_MixRGB(0xC0, 0xC0, 0);
        gnLifeColorLow = D2Win_10034_MixRGB(0xFF, 0, 0);
    }
    unsigned char nColor = gnLifeColorHigh;
    if (nLife < 50)
        nColor = gnLifeColorMid;
    if (nLife < 25)
        nColor = gnLifeColorLow;
    D2GFX_DrawBox(nX, 0xE, nXFill, 0x13, nColor, 5);
    D2GFX_DrawBox(nXFill, 0xE, nXEnd, 0x13, 0, 5);
}



// 0x00493240
D2CelFileStrc* __fastcall HIREABLES_GetPetIcon(D2UnitStrc* pOwner, int nPetType, int* pUnitId, int* pSingle)
{
    int aPath[0x40];

    D2PetTypeTxt* pPetTypeTxtRecord = sub_00493240_GetPetTypeTxtRecord(nPetType);
    if (!pPetTypeTxtRecord)
    {
        return 0;
    }

    if (pSingle)
    {
        *pSingle = pPetTypeTxtRecord->nPetFlags[5 >> 3] & gdwBitMasks[5 & 7];
    }

    int nUnitId = ROSTERPETS_FindPetIdByOwner(pOwner, nPetType, 0);
    *pUnitId = nUnitId;
    if (nUnitId == -1)
    {
        return 0;
    }

    int nClassId = ROSTERPETS_GetHirelingClassId(nUnitId);
    int nIcon = 0;
    for (int i = 1; i < 5; ++i)
    {
        if (nClassId == pPetTypeTxtRecord->wClass[i] && pPetTypeTxtRecord->szIcon[i][0])
        {
            nIcon = i;
            break;
        }
    }

    int nSlot = nPetType * 5 + nIcon;
    void** ppCel = &gpHirelingRecords[nSlot];
    if (!*ppCel)
    {
        sprintf((char*)aPath, "hireables\\%s", pPetTypeTxtRecord->szIcon[nIcon]);
        ppCel = &gpHirelingRecords[nSlot];
        *ppCel = GAME_LoadUiCelFile((char*)aPath);
    }
    return (D2CelFileStrc*)*ppCel;
}

// 0x00493340
void __cdecl HIREABLES_UpdateHirelingPanel()
{
    if (gnPetIconPopupState == 2)
    {
        gnGlobal_007BEEE8 = 0;
        gbPopupPending = 0;
        gnGlobal_007BEEDC = 0;
        return;
    }
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    int bHasPet = 0;
    if (ROSTERPETS_HasPets(pPlayer))
    {
        bHasPet = 1;
    }
    if ((ROSTER_HasPartyMate(pPlayer) && gnPetIconPopupState != 1) || bHasPet)
    {
        const int nPetId = ROSTERPETS_FindPetIdByOwner(pPlayer, 7, 0);
        D2UnitStrc* pPet;
        if (nPetId == -1 || ((pPet = CUNIT_FindClientUnit(nPetId, 1)) != 0 && CUNIT_IsDeadOrDying(pPet)))
        {
            gnGlobal_007BEEDC = 0;
            gbPopupPending = 0;
            gnGlobal_007BEEE8 = 0;
        }
        if (!GAME_GetUIVarState(0x13))
        {
            UI_SetUIVar(0x13, 0, 0);
        }
    }
    else
    {
        gnGlobal_007BEEE8 = 0;
        gbPopupPending = 0;
        gnGlobal_007BEEDC = 0;
        if (GAME_GetUIVarState(0x13))
        {
            UI_SetUIVar(0x13, 1, 0);
        }
    }
}

// 0x00493430
void __stdcall HIREABLES_PetIconClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    if (gnPetIconPopupState == 2)
    {
        pMsg->bReturn = 1;
        pMsg->lResult = 0;
        sub_00420290_BreakHandlerChain(pMsg);
    }

    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    const int nUnitId = ROSTERPETS_FindPetIdByOwner(pPlayer, 7, 0);
    if (nUnitId != -1)
    {
        pMsg->bReturn = 0;
        return;
    }

    D2UnitStrc* pPet = CUNIT_FindClientUnit(nUnitId, 1);
    if (!pPet)
    {
        pMsg->bReturn = 0;
        return;
    }

    VIEW_SetPetEntryValue(pPlayer, pPet, 1);
    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

// 0x004934B0
D2UnitStrc* __cdecl HIREABLES_GetPlayerCursorItem()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return 0;
    return INVENTORY_GetCursorItem(pPlayer->pInventory);
}

// 0x004934D0
int __stdcall HIREABLES_CanEquipHirelingItem(int playSound)
{
 if(!GAME_IsExpansion()) return 0;
 int result=0;
 D2UnitStrc* player=sub_00463DD0_GetPlayerUnit();
 if(!player) return 0;
 D2UnitStrc* current=sub_00463DD0_GetPlayerUnit();
 D2UnitStrc* item=current ? INVENTORY_GetCursorItem(current->pInventory):0;
 if(!item) return 0;
 int petId=ROSTERPETS_FindPetIdByOwner(player,7,0);
 if(petId==-1) return 0;
 if(ITEMS_CheckItemFlag(item,16,955,".\\UI\\Hireables.cpp") && !ITEMS_CheckItemFlag(item,256,955,".\\UI\\Hireables.cpp")) {
  if(ITEMSIsA(item,76) || ITEMSIsA(item,80) || ITEMSIsA(item,81)) {
   if(playSound) UNITSND_PlayEventSound(petId,1,84);
   return 1;
  }
  if(ITEMSIsA(item,3) || ITEMSIsA(item,37)) result=1;
  D2UnitStrc* pet=CUNIT_FindClientUnit(petId,1);
  if(!pet) return 0;
  switch(ROSTERPETS_GetHirelingClassId(petId)) {
   case 271: if(ITEMSIsA(item,27)) result=1; break;
   case 338: if(ITEMSIsA(item,33) || ITEMSIsA(item,34)) result=1; break;
   case 359:
    if(ITEMSIsA(item,2)) result=1;
    if(ITEMSIsA(item,30) && !ITEMS_CheckWeaponIfTwoHanded(item)) result=1;
    break;
   case 560: if(ITEMSIsA(item,28) && !ITEMS_CheckWeaponIfTwoHanded(item)) result=1; break;
   case 561: if(ITEMSIsA(item,30)) result=1; break;
  }
  if(!result) {
   if(playSound) UNITSND_PlayEventSound(petId,1,85);
  } else if(!ITEMS_CheckRequirements(item,pet,0,0,0,0)) result=0;
  return result;
 }
 if(playSound) UNITSND_PlayEventSound(petId,1,86);
 return 0;
}

// 0x00493B00
static void __stdcall HIREABLES_DrawUnitName(D2UnitStrc* pUnit, int nX, int nY)
{
    if (pUnit)
    {
        unsigned short wszName[32];
        memset(wszName, 0, sizeof(wszName));
        sub_00526790((Unicode*)wszName, CUNIT_GetUnitName(pUnit), 32);
        wszName[31] = 0;
        HIREABLES_DrawFittedText(nX, nY, 0, (Unicode*)wszName);
    }
}

// 0x004942D0
int __cdecl HIREABLES_GetHelpMenuSetting()
{
// build: symbol ?gdwHelpMenu@* 0x00722310
    if (gdwHelpMenu == 0xFFFFFFFF)
    {
        gdwHelpMenu = 0;
        SRegLoadValue("Diablo II", "Help Menu", 1, &gdwHelpMenu);
    }
    return gdwHelpMenu;
}

static int __stdcall sub_00493B50_DrawRosterIcons(int* pnY, int* pbAlternate, D2UnitStrc* pPlayer, int* pnX)
{
    int bDrawn = 0;
    const unsigned short nIndex = CUNIT_GetPlayerPartyId(pPlayer);
    const int nPlayerId = pPlayer ? pPlayer->dwUnitId : -1;
    if (nIndex == 0xFFFF || gnPetIconPopupState)
        return 0;

    D2StoredUnitRecordStrc* pEntry = ROSTER_GetNextStoredUnit(0);
    if (!pEntry)
        return 0;

    do
    {
        if (ROSTER_GetEntryIndex(pEntry) != nIndex)
            continue;

        const int nUnitId = ROSTER_GetRecordUnitId(pEntry);
        if (nUnitId == nPlayerId)
            continue;

        D2CelFileStrc* pCelFile;
        switch (ROSTER_GetClassId(pEntry))
        {
        case 0:
            pCelFile = gapHirelingIcons[0];
            break;
        case 1:
            pCelFile = gapHirelingIcons[1];
            break;
        case 2:
            pCelFile = gapHirelingIcons[2];
            break;
        case 3:
            pCelFile = gapHirelingIcons[3];
            break;
        case 4:
            pCelFile = gapHirelingIcons[4];
            break;
        case 5:
            pCelFile = gapHirelingIcons[5];
            break;
        case 6:
            pCelFile = gapHirelingIcons[6];
            break;
        default:
            continue;
        }

        if (!pCelFile)
            continue;

        sub_00493A00_DrawLifeBar(0, *pnX, nUnitId);
        HIREABLES_DrawRosterName(ROSTER_GetEntryName(pEntry), *pnX, *pnY);
        if (*pbAlternate)
        {
            *pnY -= *pbAlternate;
            *pbAlternate = 0;
        }
        else
        {
            *pbAlternate = 10;
            *pnY += 10;
        }
        D2CelContextStrc tContext;
        memset(&tContext, 0, sizeof(tContext));
        tContext.pCellFile = pCelFile;
        sub_004F6480(&tContext, *pnX, 0x3C, -1, 1, 0);
        *pnX += 0x38;
        bDrawn = 1;
    }
    while ((pEntry = ROSTER_GetNextStoredUnit(pEntry)) != 0);

    if (!bDrawn)
        return 0;

    return 1;
}

static int __stdcall sub_00493CE0_DrawSummonIcon(D2UnitStrc* pPlayer, int* pbAlternate, int* pnX, int* pnY)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    int nUnitId;
    tContext.pCellFile = HIREABLES_GetPetIcon(pPlayer, 7, &nUnitId, 0);
    if (!tContext.pCellFile)
        return 0;

    sub_00493A00_DrawLifeBar(7, *pnX, nUnitId);
    HIREABLES_DrawUnitName(CUNIT_FindClientUnit(nUnitId, 1), *pnX, *pnY);
    if (*pbAlternate)
    {
        *pnY -= *pbAlternate;
        *pbAlternate = 0;
    }
    else
    {
        *pbAlternate = 10;
        *pnY += 10;
    }
    gnPopupX = *pnX;
    gnPopupY = *pnY;
    if (gbPopupPending && gdwPopupTick && GetTickCount() - gdwPopupTick >= 700)
    {
        gbPopupShown = 1;
        sub_004F6480(&tContext, *pnX, 0x3C, -1, 7, 0);
        *pnX += 0x38;
        return 1;
    }

    if (gbPopupShown)
    {
        sub_004F6480(&tContext, *pnX, 0x3C, -1, 7, 0);
        *pnX += 0x38;
        return 1;
    }

    sub_004F6480(&tContext, *pnX, 0x3C, -1, 1, 0);
    *pnX += 0x38;
    return 1;
}

static int __stdcall sub_00493E10_DrawPetIcon(D2UnitStrc* pPlayer, int* pnX, int* pbAlternate, int nPetType, int* pnY)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    int nUnitId;
    tContext.pCellFile = HIREABLES_GetPetIcon(pPlayer, nPetType, &nUnitId, 0);
    if (!tContext.pCellFile)
        return 0;

    sub_00493A00_DrawLifeBar(nPetType, *pnX, nUnitId);
    HIREABLES_DrawPetTypeName(*pnX, *pnY, nPetType);
    if (*pbAlternate)
    {
        *pnY -= *pbAlternate;
        *pbAlternate = 0;
    }
    else
    {
        *pbAlternate = 10;
        *pnY += 10;
    }
    sub_004F6480(&tContext, *pnX, 0x3C, -1, 1, 0);
    *pnX += 0x38;
    return 1;
}

static int __stdcall sub_00493EB0_DrawPetCountIcon(D2UnitStrc* pPlayer, int* pnY, int* pbAlternate, int* pnX, int nPetType)
{
    const int nCount = ROSTERPETS_CountPets(pPlayer, nPetType);
    if (!nCount)
        return 0;

    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    int nUnitId;
    int bSingle = 0;
    tContext.pCellFile = HIREABLES_GetPetIcon(pPlayer, nPetType, &nUnitId, &bSingle);
    if (!tContext.pCellFile)
        return 0;

    if (nCount == 1 && bSingle)
        sub_00493A00_DrawLifeBar(nPetType, *pnX, ROSTERPETS_FindPetIdByOwner(pPlayer, nPetType, 0));

    INV_DrawIconNumber(nCount, *pnX);
    HIREABLES_DrawPetTypeName(*pnX, *pnY, nPetType);
    if (*pbAlternate)
    {
        *pnY -= *pbAlternate;
        *pbAlternate = 0;
    }
    else
    {
        *pbAlternate = 10;
        *pnY += 10;
    }
    sub_004F6480(&tContext, *pnX, 0x3C, -1, 1, 0);
    *pnX += 0x38;
    return 1;
}

static int __stdcall sub_00493F80_DrawPetIcon3(D2UnitStrc* pPlayer, int* pnX, int* pbAlternate, int nPetType, int* pnY)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    int nUnitId;
    tContext.pCellFile = HIREABLES_GetPetIcon(pPlayer, nPetType, &nUnitId, 0);
    if (!tContext.pCellFile)
        return 0;

    sub_00493A00_DrawLifeBar(nPetType, *pnX, nUnitId);
    HIREABLES_DrawPetTypeName(*pnX, *pnY, nPetType);
    if (*pbAlternate)
    {
        *pnY -= *pbAlternate;
        *pbAlternate = 0;
    }
    else
    {
        *pbAlternate = 10;
        *pnY += 10;
    }
    sub_004F6480(&tContext, *pnX, 0x3C, -1, 1, 0);
    *pnX += 0x38;
    return 1;
}

void __cdecl sub_00494020_DrawPetIcons()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    int nY = 0x48;
    int bAlternate = 0;
    int nX = 0xF;
    const int nMode = sub_0045AE90();
    if (nMode != 3 && nMode != 2 && !GAME_GetUIVarState(9) && !GAME_GetUIVarState(0xB) && gnPetIconPopupState != 2)
    {
        if (GAME_IsExpansion() && !GAME_GetUIVarState(0x23) && gnPetIconPopupState != 2 && ROSTERPETS_FindPetIdByOwner(pPlayer, 7, 0) != -1)
            UI_SetUIVar(0x23, 0, 0);

        int bAny = sub_00493B50_DrawRosterIcons(&nY, &bAlternate, pPlayer, &nX);
        bAny |= sub_00493CE0_DrawSummonIcon(pPlayer, &bAlternate, &nX, &nY);
        for (int i = 0; i < sgptDataTables->nPetTypeTxtRecordCount; ++i)
        {
            D2PetTypeTxt* pPetTypeTxt = (i >= 0 && i < sgptDataTables->nPetTypeTxtRecordCount) ? &sgptDataTables->pPetTypeTxt[i] : 0;
            if (!pPetTypeTxt)
                continue;

            switch (pPetTypeTxt->nIconType)
            {
            case 1:
                bAny |= sub_00493E10_DrawPetIcon(pPlayer, &nX, &bAlternate, i, &nY);
                break;
            case 2:
                bAny |= sub_00493EB0_DrawPetCountIcon(pPlayer, &nY, &bAlternate, &nX, i);
                break;
            case 3:
                bAny |= sub_00493F80_DrawPetIcon3(pPlayer, &nX, &bAlternate, i, &nY);
                break;
            }
        }

        if (!bAny)
            UI_SetUIVar(0x13, 1, 0);

        if (gbOpenMercInvPending && !GAME_GetUIVarState(0x24) && UI_SetUIVar(0x24, 0, 0))
        {
            SRegSaveValue("Diablo II", "PopupHireling", 0, 1);
            gbOpenMercInvPending = 0;
        }

        if (gbPopupPending && gbPopupShown)
        {
            Unicode wszText[0x100];
            wszText[0].wChar = 0;
            const Unicode* wszSuffix = D2LANG_GetStringFromTblIndex(0x58A2);
            const Unicode* wszFormat = D2LANG_GetStringFromTblIndex(0x58A3);
            const Unicode* wszMiddle = D2LANG_GetStringFromTblIndex(0xF9E);
            sub_005269D0(0x100, wszText, wszFormat, CMDTBL_GetKeyName(0x36, 1));
            sub_00526700(wszText, wszMiddle);
            sub_00526700(wszText, wszSuffix);
            D2Win_10129_DrawFramedText(wszText, gnPopupX, gnPopupY + 0x24, 0, 0);
        }
    }
    else
    {
        gbPopupShown = 0;
        gbPopupPending = 0;
    }
}

#include "gen/data/Source/D2Client/UI/Hireables.inc"
