#include "D2Client.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2CelContext.h"
#include "D2LevelTxt.h"
#include "D2Unicode.h"

extern "C" void* __cdecl memset(void* pDst, int nValue, size_t nSize);
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
int __stdcall SRegSaveValue(const char* szKeyName, const char* szValueName, unsigned int nFlags, unsigned long dwValue);
D2UnitStrc* __cdecl sub_00463DD0();
int __cdecl sub_0045AE90();
int __cdecl GAME_IsExpansion(); // 0x0044DCC0
int __fastcall GAME_GetUIVarState(int nUIVar); // 0x004538D0
int __fastcall UI_SetUIVar(int nUIVar, int nState, int nArg); // 0x00455F20
D2UnitStrc* __fastcall CUNIT_FindClientUnit(int nUnitId, int nUnitType); // 0x00463990
unsigned short __fastcall CUNIT_GetPlayerPartyId(D2UnitStrc* pUnit); // 0x00465400
const Unicode* __fastcall CUNIT_GetUnitName(D2UnitStrc* pUnit); // 0x00464A60
int __fastcall sub_00478EE0_GetPetCount(D2UnitStrc* pOwner, int nPetType);
int __fastcall ROSTERPETS_FindPetIdByOwner(D2UnitStrc* pOwner, int nPetType, int bAny); // 0x00478F20
int __fastcall ROSTER_GetPetLife(int nUnitId); // 0x00479080
D2StoredUnitRecordStrc* __fastcall ROSTER_GetNextStoredUnit(D2StoredUnitRecordStrc* pEntry); // 0x004795A0
const char* __fastcall ROSTER_GetEntryName(D2StoredUnitRecordStrc* pEntry); // 0x004795C0
int __fastcall ROSTER_GetClassId(D2StoredUnitRecordStrc* pEntry); // 0x00479BA0
unsigned short __fastcall ROSTER_GetEntryIndex(D2StoredUnitRecordStrc* pEntry); // 0x00479BC0
int __fastcall ROSTER_GetRecordUnitId(D2StoredUnitRecordStrc* pRecord); // 0x0047A0C0
int __fastcall ROSTER_GetPartyLife(int nUnitId); // 0x0047A150
D2CelFileStrc* __fastcall HIREABLES_GetPetIcon(D2UnitStrc* pOwner, int nPetType, int* pUnitId, int* pSingle);
void __stdcall INV_DrawIconNumber(int nValue, int nX);
const Unicode* __fastcall CMDTBL_GetKeyName(int nA, int nB);
int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette);
void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned char nColor, int eDrawMode); // 0x004F6300
int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820
void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0
void __fastcall sub_00502280_SetPopUpText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5);
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex);
void __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength);
Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource);
Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount);
Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc);
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);

extern D2DataTablesStrc* sgptDataTables;
// build: symbol ?gapHirelingIcons@* 0x007BEEB0
extern D2CelFileStrc* gapHirelingIcons[7];
extern "C" const char szDiabloII_006CC8B8[];
// build: symbol _gszPopupHireling 0x006D9E60
extern "C" const char gszPopupHireling[];

// build: symbol ?gnPetIconPopupState@* 0x007BEECC
static int gnPetIconPopupState;
static unsigned char gnLifeColorHigh;                                                              // 0x007BEED0
static unsigned char gnLifeColorMid;                                                               // 0x007BEED1
static unsigned char gnLifeColorLow;                                                               // 0x007BEED2
static unsigned char gbLifeColorsInit;                                                             // 0x007BEED3
// build: symbol ?gnPopupX@* 0x007BEED4
static int gnPopupX;
// build: symbol ?gnPopupY@* 0x007BEED8
static int gnPopupY;
// build: symbol ?gbPopupShown@* 0x007BEEDC
static int gbPopupShown;
// build: symbol ?gbPopupPending@* 0x007BEEE0
static int gbPopupPending;
// build: symbol ?gbOpenMercInvPending@* 0x007BEEE4
static unsigned char gbOpenMercInvPending;
// build: symbol ?gdwPopupTick@* 0x007BEEE8
static int gdwPopupTick;

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

// build: symbol ?HIREABLES_DrawPetTypeName@* 0x00493020
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

// build: symbol ?HIREABLES_DrawRosterName@* 0x004930A0
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

// 0x00493A00
static void __stdcall sub_00493A00_DrawLifeBar(int nPetType, int nX, int nUnitId)
{
    int nLife = nPetType ? ROSTER_GetPetLife(nUnitId) : ROSTER_GetPartyLife(nUnitId);
    if (!nLife)
        return;

    const int nXEnd = nX + 0x2E;
    nLife = nLife <= 0 ? 0 : nLife;
    const int nPct = nLife < 100 ? nLife : 100;
    const int nXFill = nX + nPct * 0x2E / 100;
    if (!gbLifeColorsInit)
    {
        gbLifeColorsInit = 1;
        gnLifeColorHigh = D2Win_10034_MixRGB(0, 0x80, 0);
        gnLifeColorMid = D2Win_10034_MixRGB(0xC0, 0xC0, 0);
        gnLifeColorLow = D2Win_10034_MixRGB(0xFF, 0, 0);
    }
    unsigned char nColor = gnLifeColorHigh;
    if (nPct < 50)
        nColor = gnLifeColorMid;
    if (nPct < 25)
        nColor = gnLifeColorLow;
    D2GFX_DrawBox(nX, 0xE, nXFill, 0x13, nColor, 5);
    D2GFX_DrawBox(nXFill, 0xE, nXEnd, 0x13, 0, 5);
}

// build: symbol ?HIREABLES_DrawUnitName@* 0x00493B00
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
    const int nCount = sub_00478EE0_GetPetCount(pPlayer, nPetType);
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
    D2UnitStrc* pPlayer = sub_00463DD0();
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
            SRegSaveValue(szDiabloII_006CC8B8, gszPopupHireling, 0, 1);
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
            sub_00502280_SetPopUpText(wszText, gnPopupX, gnPopupY + 0x24, 0, 0);
        }
    }
    else
    {
        gbPopupShown = 0;
        gbPopupPending = 0;
    }
}
