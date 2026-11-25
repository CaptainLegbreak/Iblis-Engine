#include "D2Client.h"
#include "D2CelContext.h"
#include "D2Unicode.h"
#include "D2ClientTypes.h"
#include "D2ClientParty.h"
#include "D2ClientUi.h"
#include "D2StormTypes.h"

struct D2StoredUnitRecordStrc;

struct Unicode;

struct D2PartyRowStrc;

struct D2SevenIntStrc;


struct D2CelContextStrc;

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

D2StoredUnitRecordStrc* __fastcall ROSTER_GetNextStoredUnit(D2StoredUnitRecordStrc* pEntry); // 0x004795A0

unsigned short __fastcall ROSTER_GetEntryIndex(D2StoredUnitRecordStrc* pEntry); // 0x00479BC0

void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080

int __stdcall sub_004F6480(D2CelContextStrc* pContext, int nX, int nY, int nGamma, int nDrawMode, int nPalette); // 0x004F6480

int __fastcall D2Win_10127_SetFont(int nArg); // 0x00502EF0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

extern int gnPanelOffsetX; // 0x007A2858

extern int gnPanelOffsetY; // 0x007A285C

extern void* gpPartyButtonsCel; // 0x007BF01C


#pragma pack(push, 1)


#pragma pack(pop)

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

struct D2SevenIntStrc
{
    int n0;
    int n1;
    int n2;
    int n3;
    int n4;
    int n5;
    int n6;
};

void __cdecl sub_K04_EmitUse(D2SevenIntStrc* pRecord);

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

extern "C" const char* __fastcall ROSTER_GetEntryName(D2StoredUnitRecordStrc* pEntry); // 0x004795C0

int __fastcall ROSTER_GetLevel(D2StoredUnitRecordStrc* pEntry); // 0x00479B90

int __fastcall ROSTER_GetClassId(D2StoredUnitRecordStrc* pEntry); // 0x00479BA0

int __fastcall ROSTER_TestLootFlag(D2StoredUnitRecordStrc* pEntry); // 0x00479C20

int __fastcall ROSTER_TestMuteFlag(D2StoredUnitRecordStrc* pEntry); // 0x00479C60

int __fastcall ROSTER_TestSquelchFlag(D2StoredUnitRecordStrc* pEntry); // 0x00479CA0

int __fastcall ROSTER_TestHostileFlag(D2StoredUnitRecordStrc* pEntry); // 0x00479CE0

int __fastcall ROSTER_GetPartyFlags(D2StoredUnitRecordStrc* pEntry); // 0x00479D20

int __fastcall ROSTER_GetRecordUnitId(D2StoredUnitRecordStrc* pRecord); // 0x0047A0C0

int __fastcall ROSTER_GetLevelId(D2StoredUnitRecordStrc* pEntry); // 0x0047A1E0

void __cdecl PARTY_FreeRosterUnits(); // 0x0049A020

D2PartyRowStrc* gpRosterUnits; // 0x007BF014

const Unicode* __fastcall UI_GetLevelName(int nLevelId); // 0x00453E70

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

Unicode* __fastcall sub_00526700(Unicode* pDest, const Unicode* pSource); // 0x00526700

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

int __fastcall ROSTER_IsHostileToPlayer(D2StoredUnitRecordStrc* pEntry); // 0x0047A5B0

void __stdcall PARTY_DrawPanelIcons(D2PartyRowStrc* pRow); // 0x0049A690

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szDest, const char* szFormat, ...); // 0x006CC468

extern "C" size_t __cdecl strlen(const char* szString);

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

int __fastcall sub_005262A0_Utf8CountChars(const char* pSrc, int nCount); // 0x005262A0

#pragma pack(push, 1)

struct D2PanelIconStrc
{
    int nX;
    int nY;
    D2CelFileStrc* pCelFile;
    unsigned int nFrame;
    int nType;
    int nState;
    int unk0x18[2];
};

struct D2PanelIconRecordStrc
{
    int unk0x00;
    D2PanelIconStrc pIcons[5];
    unsigned char unk0xA4[0x19];
    int nLevel;
    int unk0xC1;
    int nUnitId;
};

#pragma pack(pop)

static unsigned char gnBoxColor_007BF034;                                                                   // 0x007BF034

int __cdecl WINMAIN_IsHardcore();                                                                      // 0x0044B850

int __fastcall GAME_GetUnitGUID(D2UnitStrc* pUnit);                                                 // 0x00451F50

void __fastcall AUTOMAP_DrawFramedBox(int nX, int nY, int nWidth, int nHeight, unsigned char nColor, unsigned char nArg6); // 0x0046EFD0

unsigned int __fastcall GFXUTIL_TestRelationFlags(int nUnitId1, int nUnitId2, unsigned int nFlags);              // 0x004DC440

void __stdcall TEXTURE_CelDraw(D2CelContextStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom);                                                // 0x0061AB00

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0

void* gpPartyBoxesCel; // 0x007BF020

extern unsigned char gnBoxColor; // 0x007BF034

int __cdecl sub_00468730(); // 0x00468730
int __cdecl sub_00468740(); // 0x00468740
static void __stdcall PARTY_DrawTextFrame(unsigned short nAltString, unsigned short nString, int nX, int bLarge); // 0x0049AAF0
int __fastcall TEXT_GetCenteredStringX(unsigned short nStringIndex, int nCenterX); // 0x0049AAA0
extern D2PartyRowStrc* gpRosterUnits; // 0x007BF014
int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
void __cdecl GAME_ResetMouseButtons(); // 0x0044DA70
int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290
int __stdcall TEXT_IsMouseInRect(int nX, int nY, int nWidth, int nHeight); // 0x0049AA50
void __cdecl ROSTER_SendLeaveParty(); // 0x00479FC0
extern int gnScreenWidth; // 0x0071146C
extern int gbRosterMode; // 0x007BF038
extern int gbRosterButtonDown; // 0x007BF030

// 0x00499DE0
D2PartyRowStrc* __fastcall PANEL_FindPartyRow(int nId) {
 D2PartyRowStrc* pFound=gpRosterUnits;
 while(pFound) {
  if(pFound->nId == nId) return pFound;
  pFound=pFound->pNext;
 }
 return 0;
}

// 0x00499E10
void __cdecl PANEL_SetRedColour()
{
    gnBoxColor = D2Win_10034_MixRGB(0xFF, 0, 0);
}

// 0x00499E30
void __cdecl PANEL_SetBlackColour()
{
    gnBoxColor = D2Win_10034_MixRGB(0, 0, 0);
}

extern void* gpPanelQuadCel; // 0x007BF018

extern void* gpCellFile_007BF028; // 0x007BF028

int gaRosterIndex[8]; // 0x007BEFF4

// 0x00499E50
void __cdecl PARTY_DrawPanelQuad()
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpPanelQuadCel;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 224, -1, 5, 0);
    tContext.nFrame = 1;
    sub_004F6480(&tContext, gnPanelOffsetX + 256, gnScreenHeight + gnPanelOffsetY - 224, -1, 5, 0);
    tContext.nFrame = 2;
    sub_004F6480(&tContext, gnPanelOffsetX, gnScreenHeight + gnPanelOffsetY - 48, -1, 5, 0);
    tContext.nFrame = 3;
    sub_004F6480(&tContext, gnPanelOffsetX + 256, gnScreenHeight + gnPanelOffsetY - 48, -1, 5, 0);
}

// 0x00499F40
static void PARTY_DrawRowSeparator(int nY)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = gpCellFile_007BF028;
    tContext.nDirection = 0;
    tContext.nFrame = 0;
    sub_004F6480(&tContext, gnPanelOffsetX + 0xC, nY - gnPanelOffsetY, -1, 5, 0);
    tContext.nFrame = 1;
    sub_004F6480(&tContext, gnPanelOffsetX + 0x10B, nY - gnPanelOffsetY, -1, 5, 0);
}

// 0x00499FC0
static void __stdcall PARTY_DrawPanelCel(void* pCellFile, int nX, int nFrame, int nY)
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = pCellFile;
    tContext.nFrame = nFrame;
    tContext.nDirection = 0;
    sub_004F6480(&tContext, gnPanelOffsetX + nX, nY - gnPanelOffsetY, -1, 5, 0);
}

// 0x0049A020
void __cdecl PARTY_FreeRosterUnits()
{
    D2PartyRowStrc* pUnit = gpRosterUnits;
    while (pUnit)
    {
        D2PartyRowStrc* pNext = pUnit->pNext;
        FOG_Free(pUnit, ".\\UI\\Party.cpp", 0x108, 0);
        pUnit = pNext;
    }
    gpRosterUnits = 0;
}

// 0x0049A060
static void __stdcall PARTY_FillRecord(D2SevenIntStrc* pRecord, int n0, int n1, int n2, int n3, int n4, int n5, int n6)
{
    pRecord->n0 = n0;
    pRecord->n1 = n1;
    pRecord->n2 = n2;
    pRecord->n3 = n3;
    pRecord->n4 = n4;
    pRecord->n5 = n5;
    pRecord->n6 = n6;
}

void __cdecl sub_K04_EmitFillRecord(int n0, int n1, int n2, int n3, int n4, int n5, int n6)
{
    D2SevenIntStrc tRecord;
    PARTY_FillRecord(&tRecord, n0, n1, n2, n3, n4, n5, n6);
    sub_K04_EmitUse(&tRecord);
}

static void sub_L04_InitSlot(D2RosterSlotStrc* pSlot, int bFlag, int nX, int nY, void* pCellFile, int nFrame, int nType, int nState)
{
    pSlot->bFlag = bFlag;
    pSlot->nX = nX;
    pSlot->nY = nY;
    pSlot->pCellFile = pCellFile;
    pSlot->nFrame = nFrame;
    pSlot->nType = nType;
    pSlot->nState = nState;
}

// 0x0049A090
static void PARTY_InitRosterUnit(D2StoredUnitRecordStrc* pEntry, D2PartyRowStrc* pUnit, int nY)
{
    pUnit->nY = nY + 0xD;
    sub_L04_InitSlot(&pUnit->aSlots[0], 1, 0xBE, nY, gpPartyButtonsCel, 0, 0, ROSTER_GetPartyFlags(pEntry));
    sub_L04_InitSlot(&pUnit->aSlots[1], 0, 0xE, nY + 7, gpPartyBoxesCel, ROSTER_TestHostileFlag(pEntry) ? 6 : 4, 1, 0);
    sub_L04_InitSlot(&pUnit->aSlots[2], 0, 0xF5, nY, gpPartyBoxesCel, ROSTER_TestLootFlag(pEntry) ? 0xE : 0xC, 2, 0);
    sub_L04_InitSlot(&pUnit->aSlots[3], 0, 0x10A, nY, gpPartyBoxesCel, ROSTER_TestMuteFlag(pEntry) ? 2 : 0, 3, 0);
    sub_L04_InitSlot(&pUnit->aSlots[4], 0, 0x11F, nY, gpPartyBoxesCel, ROSTER_TestSquelchFlag(pEntry) ? 0xA : 8, 4, 0);
    pUnit->nId = ROSTER_GetRecordUnitId(pEntry);
}

// 0x0049A1D0
static void PARTY_AddRosterUnit(int nY, D2StoredUnitRecordStrc* pEntry)
{
    D2PartyRowStrc* pLast = gpRosterUnits;
    D2PartyRowStrc* pUnit = (D2PartyRowStrc*)FOG_Alloc(sizeof(D2PartyRowStrc), ".\\UI\\Party.cpp", 0x14D, 0);
    memset(pUnit, 0, sizeof(D2PartyRowStrc));
    PARTY_InitRosterUnit(pEntry, pUnit, nY);
    strcpy(pUnit->szName, ROSTER_GetEntryName(pEntry));
    pUnit->nClass = ROSTER_GetClassId(pEntry);
    pUnit->nLevel = ROSTER_GetLevel(pEntry);
    pUnit->nLevelId = ROSTER_GetLevelId(pEntry);
    if (pLast)
    {
        while (pLast->pNext)
            pLast = pLast->pNext;
        pLast->pNext = pUnit;
    }
    else
    {
        gpRosterUnits = pUnit;
    }
}

// 0x0049A2A0
int __cdecl PARTY_IsPlayerHostileLevel()
{
    return ROSTER_GetLevel(ROSTER_GetNextStoredUnit(0)) >= 9;
}

// 0x0049A2C0
static void __stdcall PARTY_DrawRosterName(int nY, int nColor, int bShort, const char* szName)
{
    Unicode wszName[100];
    sub_00526320_ToUnicode(wszName, szName, 100);
    Unicode* pEnd = &wszName[99];
    char szDots[5] = "...";
    Unicode wszDots[5];
    const int nWidth = D2Win_10121_GetTextWidth(wszName);
    if (bShort)
    {
        if (nWidth > 0x5F)
        {
            while (D2Win_10121_GetTextWidth(wszName) > 0x5F)
            {
                --pEnd;
                *pEnd = 0;
            }
            sub_00526320_ToUnicode(wszDots, szDots, 5);
            sub_00526700(wszName, wszDots);
        }
    }
    else if (nWidth > 0x87)
    {
        while (D2Win_10121_GetTextWidth(wszName) > 0x87)
        {
            --pEnd;
            *pEnd = 0;
        }
        sub_00526320_ToUnicode(wszDots, szDots, 5);
        sub_00526700(wszName, wszDots);
    }
    D2Win_10117_DrawText(wszName, gnPanelOffsetX + 0x24, nY - gnPanelOffsetY - 2, nColor, 0);
}

// 0x0049A3D0
static void __stdcall PARTY_DrawRosterClass(int nColor, int nY, int nClass)
{
    int nStringId;
    switch (nClass)
    {
    case 0:
        nStringId = 0x103A;
        break;
    case 1:
        nStringId = 0x103B;
        break;
    case 2:
        nStringId = 0x103D;
        break;
    case 3:
        nStringId = 0x103E;
        break;
    case 4:
        nStringId = 0x103C;
        break;
    case 5:
        nStringId = 0x2771;
        break;
    case 6:
        nStringId = 0x2772;
        break;
    default:
        return;
    }
    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(nStringId), gnPanelOffsetX + 0x24, nY - gnPanelOffsetY, nColor, 0);
}

// 0x0049A510
void __cdecl PARTY_DrawPartyButtons()
{
    D2StoredUnitRecordStrc* pEntry = ROSTER_GetNextStoredUnit(0);
    D2Win_10127_SetFont(0);
    if (ROSTER_GetEntryIndex(pEntry) != 0xFFFF)
    {
        PARTY_DrawPanelCel(gpPartyButtonsCel, 0xE3, 0, 0x23);
        TEXT_DrawCenteredText(gnPanelOffsetX + 0xE3, 0x21 - gnPanelOffsetY, gnPanelOffsetX + 0x118, D2LANG_GetStringFromTblIndex(0x1038), 2);
    }
    D2Win_10127_SetFont(1);
}

// 0x0049A580
void __cdecl PARTY_DrawPlayerName()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return;
    const char* szName = sub_0047A210(pPlayer);
    if (!szName)
        return;
    unsigned int nLen = sub_005262A0_Utf8CountChars(szName, strlen(szName)) + 1;
    if (nLen > 11)
    {
        if (nLen >= 14)
            D2Win_10127_SetFont(6);
        else
            D2Win_10127_SetFont(0);
    }
    Unicode* wszName = (Unicode*)FOG_Alloc(sizeof(Unicode) * nLen, ".\\UI\\Party.cpp", 0x211, 0);
    sub_00526320_ToUnicode(wszName, szName, nLen);
    TEXT_DrawCenteredText(gnPanelOffsetX + 0x14, 0x1F - gnPanelOffsetY, gnPanelOffsetX + 0xBE, wszName, 0);
    D2Win_10127_SetFont(0);
    FOG_Free(wszName, ".\\UI\\Party.cpp", 0x21A, 0);
}

// 0x0049A640
void __cdecl PARTY_RebuildRosterUnits()
{
    PARTY_FreeRosterUnits();
    int nY = 0x5A;
    D2StoredUnitRecordStrc* pEntry = ROSTER_GetNextStoredUnit(ROSTER_GetNextStoredUnit(0));
    for (int i = 0; pEntry || i > 8; ++i)
    {
        PARTY_AddRosterUnit(nY, pEntry);
        nY += 0x26;
        pEntry = ROSTER_GetNextStoredUnit(pEntry);
    }
}

// 0x0049A690
void __stdcall PARTY_DrawPanelIcons(D2PanelIconRecordStrc* pRecord)
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();

    D2CelContextStrc tGfx;
    memset(&tGfx, 0, sizeof(tGfx));
    tGfx.nDirection = 0;

    for (int i = 0; i < 5; ++i)
    {
        if (pRecord->pIcons[i].nType || pRecord->pIcons[i].nState != 1)
        {
            tGfx.pCellFile = pRecord->pIcons[i].pCelFile;
            const unsigned int nFrame = pRecord->pIcons[i].nFrame;
            tGfx.nFrame = nFrame;

            switch (pRecord->pIcons[i].nType)
            {
            case 1:
                if (nFrame < 4 || nFrame > 7)
                {
                    tGfx.nFrame = 4;
                }
                TEXTURE_CelDraw(&tGfx, pRecord->pIcons[i].nX + gnPanelOffsetX, pRecord->pIcons[i].nY - gnPanelOffsetY, -1, 5, 0);
                break;

            case 2:
                if (nFrame < 12 || nFrame > 15)
                {
                    tGfx.nFrame = 12;
                }

                if (WINMAIN_IsHardcore())
                {
                    TEXTURE_CelDraw(&tGfx, pRecord->pIcons[i].nX + gnPanelOffsetX, pRecord->pIcons[i].nY - gnPanelOffsetY, -1, 5, 0);
                }
                break;

            case 3:
                if (nFrame > 3)
                {
                    tGfx.nFrame = 0;
                }
                TEXTURE_CelDraw(&tGfx, pRecord->pIcons[i].nX + gnPanelOffsetX, pRecord->pIcons[i].nY - gnPanelOffsetY, -1, 5, 0);
                break;

            case 4:
                if (nFrame < 8 || nFrame > 11)
                {
                    tGfx.nFrame = 8;
                }
                TEXTURE_CelDraw(&tGfx, pRecord->pIcons[i].nX + gnPanelOffsetX, pRecord->pIcons[i].nY - gnPanelOffsetY, -1, 5, 0);
                break;

            default:
                TEXTURE_CelDraw(&tGfx, pRecord->pIcons[i].nX + gnPanelOffsetX, pRecord->pIcons[i].nY - gnPanelOffsetY, -1, 5, 0);
                break;
            }
        }

        if (pRecord->pIcons[i].nType == 1)
        {
            int bShowBox = 0;
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
            if (!pRoom || !DUNGEON_IsRoomInTown(pRoom))
            {
                bShowBox = 1;
            }

            if (pRecord->nLevel < 9 && !GFXUTIL_TestRelationFlags(GAME_GetUnitGUID(pPlayer), pRecord->nUnitId, 8))
            {
                bShowBox = 1;
            }

            if (ROSTER_GetLevel(ROSTER_GetNextStoredUnit(0)) < 9 || bShowBox)
            {
                AUTOMAP_DrawFramedBox(pRecord->pIcons[i].nX + gnPanelOffsetX, pRecord->pIcons[i].nY - gnPanelOffsetY - 19, 20, 20, gnBoxColor_007BF034 = D2Win_10034_MixRGB(255, 0, 0), 1);
            }
        }
    }
}

// 0x0049A460
static void __stdcall ROSTERPETS_DrawPanelLabel(int nY, int bAlt, unsigned short nFlag, int nType)
{
    int nStringId;
    int nColor = 0;
    int nX = 0xBE;
    switch (nType)
    {
    case 1:
        if (nFlag == 0xFFFF)
        {
            return;
        }

        if (bAlt)
        {
            nStringId = 0x1034;
            nColor = 2;
            nX = 0x9B;
        }
        else
        {
            nStringId = 0x1035;
            nColor = 8;
            nX = 0xAF;
        }
        break;
    case 0:
        nStringId = 0x1036;
        break;
    case 2:
        nStringId = 0x1037;
        break;
    case 3:
        nStringId = 0x1038;
        break;
    case 4:
        nStringId = 0x13EF;
        break;
    default:
        D2Win_10127_SetFont(0);
        return;
    }

    int nLeft = gnPanelOffsetX + nX;
    TEXT_DrawCenteredText(nLeft, nY - gnPanelOffsetY - 2, nLeft + 0x35, D2LANG_GetStringFromTblIndex(nStringId), nColor);
}

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ClientNotifyStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" char* __cdecl strcat(char* szDest, const char* szSource);

void __fastcall ROSTER_HandlePartyButton(D2StoredUnitRecordStrc* pEntry); // 0x00479EB0

static __forceinline int GetStringWidthInline(unsigned short nStringIndex)
{
    Unicode wszText[100];
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nStringIndex));
    return D2Win_10121_GetTextWidth(wszText);
}

// 0x0049A830
static void __stdcall PARTY_DrawRosterArea(int nY, D2PartyRowStrc* pEntry, int nColor)
{
    Unicode wszName[0xFF];
    sub_005267E0(wszName, UI_GetLevelName(pEntry->nLevelId));
    Unicode* pEnd = &wszName[0xFE];
    if (D2Win_10121_GetTextWidth(wszName) > 0x8C)
    {
        const int nLength = sub_00526800(wszName);
        const Unicode wLast = wszName[nLength - 1];
        char szDots[] = "....";
        Unicode wszDots[5];
        sub_00526320_ToUnicode(wszDots, szDots, 5);
        wszDots[3] = wLast;
        const int nMax = 0x8B - D2Win_10121_GetTextWidth(wszDots);
        while (D2Win_10121_GetTextWidth(wszName) > nMax)
        {
            --pEnd;
            *pEnd = 0;
        }
        sub_00526700(wszName, wszDots);
    }
    D2Win_10117_DrawText(wszName, gnPanelOffsetX + 0x7E, nY - gnPanelOffsetY + 0xC, nColor, 0);
}

// 0x0049ABD0
void __cdecl PARTY_DrawRosterHoverHints()
{
    D2PartyRowStrc* pRow = gpRosterUnits;
    D2StoredUnitRecordStrc* pFirst = ROSTER_GetNextStoredUnit(0);
    gnBoxColor = D2Win_10034_MixRGB(0, 0, 0);
    if (ROSTER_GetEntryIndex(pFirst) != 0xFFFF)
    {
        const int nMouseX = sub_00468730();
        const int nMouseY = sub_00468740();
        if (nMouseX >= gnPanelOffsetX + 0xE3 && nMouseX <= gnPanelOffsetX + 0x118 && nMouseY >= 0x18 - gnPanelOffsetY && nMouseY <= 0x23 - gnPanelOffsetY)
        {
            PARTY_DrawTextFrame(0, 0x1018, 0xD5, 0);
            {
                const int nTextX = TEXT_GetCenteredStringX(0x1018, 0xD5);
                D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1018), nTextX + gnPanelOffsetX, 0x37 - gnPanelOffsetY, 0, 0);
            }
        }
    }
    D2StoredUnitRecordStrc* pEntry = ROSTER_GetNextStoredUnit(pFirst);
    while (pRow)
    {
        const int nY = pRow->aSlots[0].nY;
        const int nX = pRow->aSlots[0].nX;
        const int nMouseX = sub_00468730();
        const int nMouseY = sub_00468740();
        if (nMouseX >= gnPanelOffsetX + nX && nMouseX <= gnPanelOffsetX + nX + 0x35 && nMouseY >= nY - gnPanelOffsetY - 0x14 && nMouseY <= nY - gnPanelOffsetY)
        {
            if (!pRow->aSlots[0].nType)
            {
                if (pRow->aSlots[0].nState == 0)
                {
                    PARTY_DrawTextFrame(0x1005, 0x1004, 0xDA, 1);
                    {
                        const int nHalf = GetStringWidthInline(0x1004) / 2;
                        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1004), gnPanelOffsetX - nHalf + 0xDA, 0x32 - gnPanelOffsetY, 0, 0);
                    }
                    {
                        const int nHalf = GetStringWidthInline(0x1005) / 2;
                        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1005), gnPanelOffsetX - nHalf + 0xDA, 0x41 - gnPanelOffsetY, 0, 0);
                    }
                }
                else if (pRow->aSlots[0].nState == 2)
                {
                    PARTY_DrawTextFrame(0x1007, 0x1006, 0xDA, 1);
                    {
                        const int nTextX = TEXT_GetCenteredStringX(0x1006, 0xDA);
                        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1006), nTextX + gnPanelOffsetX, 0x32 - gnPanelOffsetY, 0, 0);
                    }
                    {
                        const int nTextX = TEXT_GetCenteredStringX(0x1007, 0xDA);
                        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1007), nTextX + gnPanelOffsetX, 0x41 - gnPanelOffsetY, 0, 0);
                    }
                }
                else if (pRow->aSlots[0].nState == 4)
                {
                    PARTY_DrawTextFrame(0x1009, 0x1008, 0xDA, 1);
                    {
                        const int nTextX = TEXT_GetCenteredStringX(0x1008, 0xDA);
                        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1008), nTextX + gnPanelOffsetX, 0x32 - gnPanelOffsetY, 0, 0);
                    }
                    {
                        const int nTextX = TEXT_GetCenteredStringX(0x1009, 0xDA);
                        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1009), nTextX + gnPanelOffsetX, 0x41 - gnPanelOffsetY, 0, 0);
                    }
                }
            }
        }
        pRow = pRow->pNext;
        if (pEntry)
            pEntry = ROSTER_GetNextStoredUnit(pEntry);
    }
}

// 0x0049B990
static int PARTY_DoRosterButtonAction(D2StoredUnitRecordStrc* pEntry, int nType)
{
    int nResult = 0;
    switch (nType)
    {
    case 1:
        sub_00479FE0(pEntry);
        nResult = ROSTER_TestHostileFlag(pEntry);
        break;
    case 2:
        if (!WINMAIN_IsHardcore())
            break;
        sub_00479DA0(pEntry);
        nResult = ROSTER_TestLootFlag(pEntry);
        break;
    case 3:
        sub_00479DE0(pEntry);
        nResult = ROSTER_TestMuteFlag(pEntry);
        break;
    case 4:
    {
        sub_00479E20(pEntry);
        nResult = ROSTER_TestSquelchFlag(pEntry);
        D2ClientNotifyStrc* pNotify = WINMAIN_GetClientNotify();
        if (pNotify)
        {
            char szText[0x200];
            if (nResult)
                strcpy(szText, "/squelch ");
            else
                strcpy(szText, "/unsquelch ");
            strcat(szText, ROSTER_GetEntryName(pEntry));
            pNotify->pfnResign(szText);
        }
        break;
    }
    }
    return nResult;
}

// 0x0049BAD0
static void PARTY_SetRosterButtonState(D2StoredUnitRecordStrc* pEntry, D2PartyRowStrc* pRow, int nSlot)
{
    if (pRow->aSlots[nSlot].nState == 1)
        return;

    const int nId = pRow->nId;
    ROSTER_HandlePartyButton(pEntry);
    const int nState = ROSTER_GetPartyFlags(pEntry);
    D2PartyRowStrc* pFound = gpRosterUnits;
    while (pFound && pFound->nId != nId)
        pFound = pFound->pNext;
    D2_ASSERT(pFound, 0x4E3);
    pFound->aSlots[nSlot].nState = nState;
}

void __stdcall sub_0049BDD0_OnRosterClick(SMSGHANDLER_PARAMS* pMsg)
{
    int nX = sub_00468730();
    D2StoredUnitRecordStrc* pEntry = ROSTER_GetNextStoredUnit(0);
    D2PartyRowStrc* pRow = gpRosterUnits;
    gbRosterButtonDown = 0;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (nX < gnScreenWidth / 2)
    {
        nX = sub_00468730();
        int nY = sub_00468740();
        if (nX >= gnPanelOffsetX + 0x116 && nX <= gnPanelOffsetX + 0x136 && nY >= 0x185 - gnPanelOffsetY && nY <= 0x1A5 - gnPanelOffsetY)
        {
            UI_SetUIVar(0x16, 1, 0);
            GAME_ResetMouseButtons();
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }

        if (TEXT_IsMouseInRect(0xE3, 0x23, 0x35, 0xB) && ROSTER_GetEntryIndex(pEntry) != 0xFFFF)
        {
            ROSTER_SendLeaveParty();
            GAME_ResetMouseButtons();
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }

        if (gbRosterMode)
        {
            pEntry = ROSTER_GetNextStoredUnit(pEntry);
            while (pEntry && pRow)
            {
                for (int i = 0; i < 5; i++)
                {
                    D2RosterSlotStrc* pSlot = &pRow->aSlots[i];
                    const int nSlotX = pSlot->nX;
                    if (!pSlot->bFlag)
                    {
                        const int nSlotY = pSlot->nY;
                        nX = sub_00468730();
                        nY = sub_00468740();
                        if (nX >= gnPanelOffsetX + nSlotX && nX <= gnPanelOffsetX + nSlotX + 0x14 && nY >= nSlotY - gnPanelOffsetY - 0x14 && nY <= nSlotY - gnPanelOffsetY)
                        {
                            if (pSlot->nType == 1 && ROSTER_GetLevel(ROSTER_GetNextStoredUnit(0)) < 9)
                            {
                                pMsg->bReturn = 1;
                                pMsg->lResult = 0;
                                sub_00420290_BreakHandlerChain(pMsg);
                                return;
                            }
                            if (pSlot->nType == 1)
                            {
                                D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
                                if (!pRoom || !DUNGEON_IsRoomInTown(pRoom))
                                    continue;
                            }
                            const int bDone = PARTY_DoRosterButtonAction(pEntry, pSlot->nType);
                            const int nCount = pSlot->nFrame;
                            if (bDone)
                                pSlot->nFrame = nCount + 2;
                        }
                    }
                    else
                    {
                        const int nSlotY = pSlot->nY;
                        nX = sub_00468730();
                        nY = sub_00468740();
                        if (nX >= gnPanelOffsetX + nSlotX && nX <= gnPanelOffsetX + nSlotX + 0x35 && nY >= nSlotY - gnPanelOffsetY - 0x14 && nY <= nSlotY - gnPanelOffsetY)
                        {
                            PARTY_SetRosterButtonState(pEntry, pRow, i);
                            GAME_ResetMouseButtons();
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
                        }
                    }
                }
                pRow = pRow->pNext;
                pEntry = ROSTER_GetNextStoredUnit(pEntry);
            }
            gbRosterMode = 0;
            GAME_ResetMouseButtons();
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
        }

        for (; pRow; pRow = pRow->pNext)
        {
            for (int i = 0; i < 5; i++)
            {
                if (pRow->aSlots[i].bActive)
                {
                    pRow->aSlots[i].nFrame--;
                    pRow->aSlots[i].bActive = 0;
                }
            }
        }
        GAME_ResetMouseButtons();
            pMsg->bReturn = 1;
            pMsg->lResult = 0;
            sub_00420290_BreakHandlerChain(pMsg);
            return;
    }
    pMsg->bReturn = 0;
}

// 0x0049C170
static void __stdcall PARTY_DrawRosterLevel(int nY, int nLevel, int nColor)
{
    Unicode wszText[100];
    Unicode wszNumber[10];
    char szNumber[100];
    Unicode::strncpy(wszText, D2LANG_GetStringFromTblIndex(0xD28), 0x14);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9B));
// build: symbol ?gszFormat2u@* 0x006DA0CC
    wsprintfA(szNumber, gszFormat2u, nLevel);
    sub_00526F20_ToUnicode(wszNumber, szNumber, 9);
    sub_00526700(wszText, wszNumber);
    D2Win_10117_DrawText(wszText, gnPanelOffsetX + 0x10A, nY - gnPanelOffsetY, nColor, 0);
}

void __cdecl sub_Z12_EmitRosterRows(D2PartyRowStrc* pEntry, int nColor)
{
    int nY = 0x3A;
    for (; pEntry; pEntry = pEntry->pNext)
    {
        PARTY_DrawRosterLevel(nY + 0xE, pEntry->nLevel, nColor);
        PARTY_DrawRosterArea(nY, pEntry, nColor);
        nY += 0x22;
    }
}




// 0x0049A950
void __cdecl TEXT_DrawPanelCloseButton()
{
    D2CelContextStrc tContext;
    memset(&tContext, 0, sizeof(tContext));
    tContext.pCellFile = sub_00454600();
    tContext.nFrame = (gbRosterButtonDown != 0) + 10;
    tContext.nDirection = 0;
    sub_004F6480(&tContext, gnPanelOffsetX + 278, 421 - gnPanelOffsetY, -1, 5, 0);
}

// 0x0049A9B0
void __cdecl PARTY_RefreshRosterIndices()
{
    D2StoredUnitRecordStrc* pEntry = ROSTER_GetNextStoredUnit(0);
    for (int i = 0; i < 8; ++i)
        gaRosterIndex[i] = 0xFFFF;
    int nIndex = 0;
    while (pEntry)
    {
        gaRosterIndex[nIndex] = ROSTER_GetEntryIndex(pEntry);
        pEntry = ROSTER_GetNextStoredUnit(pEntry);
        ++nIndex;
    }
    int nY = 0x43;
    for (int i = 0; i < 7; ++i)
    {
        if (gaRosterIndex[i + 1] != gaRosterIndex[i] && gaRosterIndex[i] != 0xFFFF)
            PARTY_DrawRowSeparator(nY);
        nY += 0x26;
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


// 0x0049AA50
int __stdcall TEXT_IsMouseInRect(int nX, int nY, int nWidth, int nHeight)
{
    int nMouseX = sub_00468730();
    int nMouseY = sub_00468740();
    int nLeft = nX + gnPanelOffsetX;
    if (nMouseX >= nLeft && nMouseX <= nLeft + nWidth)
    {
        int nBottom = nY - gnPanelOffsetY;
        if (nMouseY >= nBottom - nHeight && nMouseY <= nBottom)
        {
            return 1;
        }
    }

    return 0;
}

// 0x0049AAA0
int __fastcall TEXT_GetCenteredStringX(unsigned short nStringIndex, int nCenterX)
{
    Unicode wszText[100];
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nStringIndex));
    return nCenterX - D2Win_10121_GetTextWidth(wszText) / 2;
}

void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...);              // 0x005269D0

int __fastcall ROSTER_IsPlayerHostile(D2StoredUnitRecordStrc* pEntry);                                                // 0x0047A5E0

int __fastcall ROSTER_PlayerAllowsLoot(D2StoredUnitRecordStrc* pEntry);                                                // 0x0047A640

int __fastcall ROSTER_AllowsPlayerLoot(D2StoredUnitRecordStrc* pEntry);                                                // 0x0047A610

int __fastcall ROSTER_IsMaleClass(D2StoredUnitRecordStrc* pEntry);                                                // 0x0047A670


static void __stdcall sub_0049AF60_DrawButtonHint(unsigned short nString1, unsigned short nString2, int nCenterX, int nUnused, int nY2, int nY1, int nColor); // 0x0049AF60

static void PARTY_DrawRosterTooltip(D2StoredUnitRecordStrc* pEntry); // 0x0049B030

// 0x0049AAF0
static void __stdcall PARTY_DrawTextFrame(unsigned short nAltString, unsigned short nString, int nX, int bLarge)
{
    Unicode wszText[100];
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nString));
    const int nWidth = D2Win_10121_GetTextWidth(wszText);
    int nAltWidth = 0;
    if (nAltString)
    {
        Unicode wszAlt[100];
        sub_005267E0(wszAlt, D2LANG_GetStringFromTblIndex(nAltString));
        nAltWidth = D2Win_10121_GetTextWidth(wszAlt);
    }
    int nY = 0x23;
    int nHeight = 0x1E;
    if (!bLarge)
    {
        nY = 0x2A;
        nHeight = 0xF;
    }
    if (nWidth > nAltWidth)
        AUTOMAP_DrawFramedBox(gnPanelOffsetX - nWidth / 2 + nX - 5, nY - gnPanelOffsetY, nWidth + 0xA, nHeight, gnBoxColor, 2);
    else
        AUTOMAP_DrawFramedBox(gnPanelOffsetX - nAltWidth / 2 + nX - 5, nY - gnPanelOffsetY, nAltWidth + 0xA, nHeight, gnBoxColor, 2);
}

static void __stdcall sub_0049AF60_DrawButtonHint(unsigned short nString1, unsigned short nString2, int nCenterX, int nUnused, int nY2, int nY1, int nColor)
{
    if (!nString2)
    {
        PARTY_DrawTextFrame(0, nString1, nCenterX, 0);
        {
            const int nTextX = TEXT_GetCenteredStringX(nString1, nCenterX);
            D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(nString1), nTextX + gnPanelOffsetX, nY1 - gnPanelOffsetY, nColor, nUnused);
        }
        return;
    }
    PARTY_DrawTextFrame(nString2, nString1, nCenterX, 1);
    {
        const int nTextX = TEXT_GetCenteredStringX(nString1, nCenterX);
        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(nString1), nTextX + gnPanelOffsetX, nY1 - gnPanelOffsetY, nColor, nUnused);
    }
    {
        const int nTextX = TEXT_GetCenteredStringX(nString2, nCenterX);
        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(nString2), nTextX + gnPanelOffsetX, nY2 - gnPanelOffsetY, nColor, nUnused);
    }
}

// 0x0049B030
static void PARTY_DrawRosterTooltip(D2StoredUnitRecordStrc* pEntry)
{
    Unicode wszLine1[0x80];
    Unicode wszLine2[0x80];
    int nColor1 = 0;
    int nColor2 = 0;
    int nHeight = 0x10;
    Unicode wszName[0x80];
    char szDefault[0x80];
    const char* szName = ROSTER_GetEntryName(pEntry);
    if (!szName)
    {
        strcpy(szDefault, "ERROR PLAYER NAME");
        szName = szDefault;
    }
    sub_00526320_ToUnicode(wszName, szName, 0x80);
    const int nA = ROSTER_IsPlayerHostile(pEntry);
    const int nB = ROSTER_PlayerAllowsLoot(pEntry);
    const int nC = ROSTER_IsHostileToPlayer(pEntry);
    const int nD = ROSTER_AllowsPlayerLoot(pEntry);
    const int bE = ROSTER_IsMaleClass(pEntry);
    if (nA == nC)
    {
        if (bE)
// build: symbol ?gawRosterHostileMale@* 0x00722450
            sub_005267E0(wszLine1, D2LANG_GetStringFromTblIndex(gawRosterHostileMale[nA][nC]));
        else
// build: symbol ?gawRosterHostileFemale@* 0x00722458
            sub_005267E0(wszLine1, D2LANG_GetStringFromTblIndex(gawRosterHostileFemale[nA][nC]));
    }
    else
    {
        if (bE)
            sub_005269D0(0x80, wszLine1, D2LANG_GetStringFromTblIndex(gawRosterHostileMale[nA][nC]), wszName);
        else
            sub_005269D0(0x80, wszLine1, D2LANG_GetStringFromTblIndex(gawRosterHostileFemale[nA][nC]), wszName);
    }
    if (WINMAIN_IsHardcore())
    {
        nHeight = 0x1E;
        if (nB == nD)
        {
            if (ROSTER_IsMaleClass(pEntry))
// build: symbol ?gawRosterLootMale@* 0x00722460
                sub_005267E0(wszLine2, D2LANG_GetStringFromTblIndex(gawRosterLootMale[nB][nD]));
            else
// build: symbol ?gawRosterLootFemale@* 0x00722468
                sub_005267E0(wszLine2, D2LANG_GetStringFromTblIndex(gawRosterLootFemale[nB][nD]));
        }
        else
        {
            if (ROSTER_IsMaleClass(pEntry))
                sub_005269D0(0x80, wszLine2, D2LANG_GetStringFromTblIndex(gawRosterLootMale[nB][nD]), wszName);
            else
                sub_005269D0(0x80, wszLine2, D2LANG_GetStringFromTblIndex(gawRosterLootFemale[nB][nD]), wszName);
        }
    }
    if (nA)
        nColor1 = 8;
    if (nC)
        nColor1 = 1;
    if (nB)
        nColor2 = 9;
    if (nD)
        nColor2 = 4;
    const int nWidth1 = D2Win_10121_GetTextWidth(wszLine1) + 0xA;
    const int nWidth2 = D2Win_10121_GetTextWidth(wszLine2) + 0xA;
    AUTOMAP_DrawFramedBox(gnPanelOffsetX + 0x24, 0x23 - gnPanelOffsetY, nWidth1 > nWidth2 ? nWidth1 : nWidth2, nHeight, gnBoxColor, 2);
    D2Win_10117_DrawText(wszLine1, gnPanelOffsetX + 0x29, 0x32 - gnPanelOffsetY, nColor1, 0);
    D2Win_10117_DrawText(wszLine2, gnPanelOffsetX + 0x29, 0x41 - gnPanelOffsetY, nColor2, 0);
}

// 0x0049B330
void __cdecl PARTY_DrawRosterButtonHints()
{
    D2PartyRowStrc* pRow = gpRosterUnits;
    D2StoredUnitRecordStrc* pFirst = ROSTER_GetNextStoredUnit(0);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(sub_00463DD0_GetPlayerUnit());
    int bInTown = 0;
    D2StoredUnitRecordStrc* pEntry = ROSTER_GetNextStoredUnit(pFirst);
    gnBoxColor = D2Win_10034_MixRGB(0, 0, 0);
    if (pRoom && DUNGEON_IsRoomInTown(pRoom))
        bInTown = 1;
    while (pRow)
    {
        const int nRowY = pRow->nY;
        const int nMouseX = sub_00468730();
        const int nMouseY = sub_00468740();
        if (nMouseX >= gnPanelOffsetX + 0x24 && nMouseX <= gnPanelOffsetX + 0x8C && nMouseY >= nRowY - gnPanelOffsetY - 0x1A && nMouseY <= nRowY - gnPanelOffsetY)
            PARTY_DrawRosterTooltip(pEntry);
        else
        {
            for (int k = 1; k < 5; ++k)
            {
                const int nY = pRow->aSlots[k].nY;
                const int nX = pRow->aSlots[k].nX;
                const int nBX = sub_00468730();
                const int nBY = sub_00468740();
                if (nBX >= gnPanelOffsetX + nX && nBX <= gnPanelOffsetX + nX + 0x14 && nBY >= nY - gnPanelOffsetY - 0x14 && nBY <= nY - gnPanelOffsetY)
                {
                    if (pRow->aSlots[k].nType == 1)
                    {
                        if (ROSTER_GetLevel(ROSTER_GetNextStoredUnit(0)) >= 9)
                        {
                            if (pRow->nLevel >= 9)
                            {
                                if (!bInTown)
                                {
                                    PARTY_DrawTextFrame(0, 0x1019, 0x6E, 0);
                                    {
                                        const int nTextX = TEXT_GetCenteredStringX(0x1019, 0x6E);
                                        D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1019), nTextX + gnPanelOffsetX, 0x37 - gnPanelOffsetY, 1, 0);
                                    }
                                    return;
                                }
                                if (ROSTER_TestHostileFlag(pEntry))
                                    sub_0049AF60_DrawButtonHint(0x100C, 0x100D, 0x6E, 0, 0x41, 0x32, 0);
                                else
                                    sub_0049AF60_DrawButtonHint(0x100A, 0x100B, 0x6E, 0, 0x41, 0x32, 0);
                                return;
                            }
                            PARTY_DrawTextFrame(0x101B, 0x101A, 0xA0, 1);
                            {
                                const int nTextX = TEXT_GetCenteredStringX(0x101A, 0xA0);
                                D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x101A), nTextX + gnPanelOffsetX, 0x32 - gnPanelOffsetY, 0, 0);
                            }
                            {
                                const int nTextX = TEXT_GetCenteredStringX(0x101B, 0xA0);
                                D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x101B), nTextX + gnPanelOffsetX, 0x41 - gnPanelOffsetY, 0, 0);
                            }
                            return;
                        }
                        PARTY_DrawTextFrame(0x101B, 0x101A, 0xA0, 1);
                        {
                            Unicode wszText[100];
                            sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x101A));
                            const int nWidth = D2Win_10121_GetTextWidth(wszText);
                            const int nHalfWidth = nWidth / 2;
                            D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x101A), gnPanelOffsetX - nHalfWidth + 0xA0, 0x32 - gnPanelOffsetY, 0, 0);
                        }
                        {
                            Unicode wszText[100];
                            sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(0x101B));
                            const int nWidth = D2Win_10121_GetTextWidth(wszText);
                            const int nHalfWidth = nWidth / 2;
                            D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x101B), gnPanelOffsetX - nHalfWidth + 0xA0, 0x41 - gnPanelOffsetY, 0, 0);
                        }
                        return;
                    }
                    else if (pRow->aSlots[k].nType == 2)
                    {
                        if (WINMAIN_IsHardcore())
                        {
                            if (ROSTER_TestLootFlag(pEntry))
                            {
                                PARTY_DrawTextFrame(0x1011, 0x1010, 0xFF, 1);
                                {
                                    const int nTextX = TEXT_GetCenteredStringX(0x1010, 0xFF);
                                    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1010), nTextX + gnPanelOffsetX, 0x32 - gnPanelOffsetY, 0, 0);
                                }
                                {
                                    const int nTextX = TEXT_GetCenteredStringX(0x1011, 0xFF);
                                    D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1011), nTextX + gnPanelOffsetX, 0x41 - gnPanelOffsetY, 0, 0);
                                }
                                return;
                            }
                            PARTY_DrawTextFrame(0x100F, 0x100E, 0xFF, 1);
                            {
                                const int nTextX = TEXT_GetCenteredStringX(0x100E, 0xFF);
                                D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x100E), nTextX + gnPanelOffsetX, 0x32 - gnPanelOffsetY, 0, 0);
                            }
                            {
                                const int nTextX = TEXT_GetCenteredStringX(0x100F, 0xFF);
                                D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x100F), nTextX + gnPanelOffsetX, 0x41 - gnPanelOffsetY, 0, 0);
                            }
                            return;
                        }
                    }
                    else if (pRow->aSlots[k].nType == 3)
                    {
                        if (ROSTER_TestMuteFlag(pEntry))
                        {
                            PARTY_DrawTextFrame(0x1013, 0x1012, 0x114, 1);
                            {
                                const int nTextX = TEXT_GetCenteredStringX(0x1012, 0x114);
                                D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1012), nTextX + gnPanelOffsetX, 0x32 - gnPanelOffsetY, 0, 0);
                            }
                            {
                                const int nTextX = TEXT_GetCenteredStringX(0x1013, 0x114);
                                D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1013), nTextX + gnPanelOffsetX, 0x41 - gnPanelOffsetY, 0, 0);
                            }
                            return;
                        }
                        PARTY_DrawTextFrame(0x1015, 0x1014, 0x114, 1);
                        {
                            const int nTextX = TEXT_GetCenteredStringX(0x1014, 0x114);
                            D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1014), nTextX + gnPanelOffsetX, 0x32 - gnPanelOffsetY, 0, 0);
                        }
                        {
                            const int nTextX = TEXT_GetCenteredStringX(0x1015, 0x114);
                            D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1015), nTextX + gnPanelOffsetX, 0x41 - gnPanelOffsetY, 0, 0);
                        }
                        return;
                    }
                    else if (pRow->aSlots[k].nType == 4)
                    {
                        if (ROSTER_TestSquelchFlag(pEntry))
                        {
                            PARTY_DrawTextFrame(0, 0x1017, 0x128, 0);
                            {
                                const int nTextX = TEXT_GetCenteredStringX(0x1017, 0x128);
                                D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1017), nTextX + gnPanelOffsetX, 0x37 - gnPanelOffsetY, 0, 0);
                            }
                            return;
                        }
                        PARTY_DrawTextFrame(0, 0x1016, 0x128, 0);
                        {
                            const int nTextX = TEXT_GetCenteredStringX(0x1016, 0x128);
                            D2Win_10117_DrawText(D2LANG_GetStringFromTblIndex(0x1016), gnPanelOffsetX + nTextX, 0x37 - gnPanelOffsetY, 0, 0);
                        }
                        return;
                    }
                }
            }
        }
        pRow = pRow->pNext;
        if (pEntry)
            pEntry = ROSTER_GetNextStoredUnit(pEntry);
    }
}

extern int gdwGlobal_007BF024; // 0x007BF024



void* __fastcall GAME_LoadUiCelFile(const char* szPath); // 0x004520C0

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

void __cdecl PARTY_DrawRosterHoverHints(); // 0x0049ABD0

void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280

void* gpInvGoldBtnCel; // 0x007BF024

void* gpPartyBarCel; // 0x007BF028

// 0x0049C0A0
void __cdecl PANEL_LoadPartyCels()
{
    gpPanelQuadCel = GAME_LoadUiCelFile("Menu\\party");
    gpPartyButtonsCel = GAME_LoadUiCelFile("Menu\\partybuttons");
    gpPartyBoxesCel = GAME_LoadUiCelFile("Menu\\partyboxes");
    gpInvGoldBtnCel = GAME_LoadUiCelFile("Panel\\inv_goldbtn");
    gpPartyBarCel = GAME_LoadUiCelFile("Menu\\partybar");
}

// 0x0049C0F0
void __cdecl PANEL_FreePartyCels()
{
    if (gpPanelQuadCel)
    {
        ARCHIVE_FreeClientCellFile(gpPanelQuadCel);
        gpPanelQuadCel = 0;
    }
    if (gpPartyButtonsCel)
    {
        ARCHIVE_FreeClientCellFile(gpPartyButtonsCel);
        gpPartyButtonsCel = 0;
    }
    if (gpPartyBoxesCel)
    {
        ARCHIVE_FreeClientCellFile(gpPartyBoxesCel);
        gpPartyBoxesCel = 0;
    }
    if (gpInvGoldBtnCel)
    {
        ARCHIVE_FreeClientCellFile(gpInvGoldBtnCel);
        gpInvGoldBtnCel = 0;
    }
    if (gpPartyBarCel)
    {
        ARCHIVE_FreeClientCellFile(gpPartyBarCel);
        gpPartyBarCel = 0;
    }
}

// 0x0049C160
int __cdecl sub_0049C160()
{
    return gdwGlobal_007BF024;
}

// 0x0049C270
void __cdecl PARTY_DrawPartyRows()
{
    D2PartyRowStrc* pRow = gpRosterUnits;
    int nY = 0x5A;
    D2StoredUnitRecordStrc* pEntry = ROSTER_GetNextStoredUnit(0);
    const unsigned short nSelfIndex = ROSTER_GetEntryIndex(pEntry);
    pEntry = ROSTER_GetNextStoredUnit(pEntry);
    int nCount = 0;
    while (pRow && pEntry && nCount < 8)
    {
        int nColor = 0;
        int bSelf = 0;
        const unsigned short nIndex = ROSTER_GetEntryIndex(pEntry);
        if (ROSTER_GetEntryIndex(pEntry) != 0xFFFF)
        {
            if (nSelfIndex == nIndex)
            {
                nColor = 2;
                bSelf = 1;
            }
            else
            {
                nColor = 8;
            }
        }
        if (ROSTER_IsHostileToPlayer(pEntry))
        {
            nColor = 1;
        }
        D2Win_10127_SetFont(0);
        if (nIndex == 0xFFFF)
        {
            PARTY_DrawRosterName(nY, nColor, 0, pRow->szName);
        }
        else
        {
            PARTY_DrawRosterName(nY, nColor, 1, pRow->szName);
        }
        PARTY_DrawRosterClass(nColor, nY + 0xC, pRow->nClass);
        PARTY_DrawRosterLevel(nY + 0xC, pRow->nLevel, nColor);
        if (bSelf && pRow->nLevelId)
        {
            PARTY_DrawRosterArea(nY, pRow, nColor);
        }
        PARTY_DrawPanelIcons(pRow);
        if (nSelfIndex == nIndex)
        {
            ROSTERPETS_DrawPanelLabel(nY, 1, nIndex, pRow->aSlots[0].nState);
        }
        else
        {
            ROSTERPETS_DrawPanelLabel(nY, 0, nIndex, pRow->aSlots[0].nState);
        }
        pRow = pRow->pNext;
        ++nCount;
        nY += 0x26;
        pEntry = ROSTER_GetNextStoredUnit(pEntry);
        D2Win_10127_SetFont(1);
    }
}

// 0x0049C3D0
void __cdecl PANEL_DrawPartyPanel()
{
    PARTY_DrawPanelQuad();
    PARTY_DrawPlayerName();
    PARTY_DrawPartyRows();
    PARTY_DrawPartyButtons();
    TEXT_DrawPanelCloseButton();
    PARTY_DrawRosterHoverHints();
    PARTY_DrawRosterButtonHints();
    PARTY_RefreshRosterIndices();
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (nX >= gnPanelOffsetX + 0x116 && nX <= gnPanelOffsetX + 0x136 && nY >= 0x185 - gnPanelOffsetY && nY <= 0x1A5 - gnPanelOffsetY)
        D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0x102F), gnPanelOffsetX + 0x125, 0x182 - gnPanelOffsetY, 0, 1);
}

#include "gen/data/Source/D2Client/UI/Party.inc"
