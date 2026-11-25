#include "D2SkillIds.h"
#include "D2Client.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Records.h"
#include "D2Structs.h"
#include "D2UnitData.h"
#include "D2ClientMenus.h"
#include "D2StormTypes.h"
#include "D2CelContext.h"
#include "D2Unicode.h"
#include "D2ClientGfx.h"
#include "D2StatIds.h"
#include "D2ClientUiRecords.h"

struct D2SkillStrc;

struct D2UnitStrc;

enum D2C_SkillsTxtFlagIndices
{
    SKILLSFLAGINDEX_PASSIVE = 4,
    SKILLSFLAGINDEX_LEFTSKILL = 30,
    SKILLSFLAGINDEX2_SCROLL = 4,
};

#pragma pack(push, 1)

struct D2SpellSelSlotsStrc
{
    int nX[60];
    int nY[60];
    int nSkill[60];
    int f_2D0[60];
    unsigned char nCount;
    int nState;
};

#pragma pack(pop)

extern D2DataTablesStrc* sgptDataTables;                                                                     // 0x00744304

extern D2SpellSelSlotsStrc gtHotkeySlots_007C0300;                                                           // 0x007C0300

int gaSkillRowY[4];                                                                                 // 0x007C070C

extern unsigned int gdwBitMasks_006CE268[];                                                                  // 0x006CE268

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                               // 0x00681EF0

int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine);               // 0x00643CE0

D2SkillsTxt* __fastcall SKILLS_GetSkillsTxtRecordFromSkill(D2SkillStrc* pSkill);                            // 0x00644140

int __stdcall SKILLS_GetFlags(D2SkillStrc* pSkill);                                                         // 0x006446A0

extern "C" int __fastcall sub_004D9FC0(D2UnitStrc* unit,D2SkillStrc* skill); // 0x004D9FC0

int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus);                     // 0x006442A0

void __fastcall SPELLSEL_DrawSkillSlot(D2SkillsTxt* pSkillsTxt, int nOwner, int nCharges, int nState, int nX, int nY, int bLeft); // 0x004A9870

void __fastcall SPELLSEL_UpdateSkillButtonHover(D2SkillsTxt* pSkillsTxt, int nState, int nLevel, int nCharges, int nX, int nY); // 0x004A8D50

void __fastcall SPELLSEL_DrawSkillQuantity(D2SkillsTxt* pSkillsTxt, int nState, int nQuantity, int nX, int nY); // 0x004AA1F0

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2HotkeySlotTableStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

int __stdcall sub_00420290_BreakHandlerChain(SMSGHANDLER_PARAMS* pMsg); // 0x00420290

void __cdecl GAME_ResetMouseState(); // 0x0044DA40

int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0

int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

void __fastcall MSG_SendTwoDwords(unsigned char nHeader, unsigned int d1, unsigned int d5); // 0x004786A0

D2SkillStrc* __fastcall SKILLS_GetSkillById(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x006439B0

int __stdcall SKILLS_GetOwnerGUIDFromSkill(D2SkillStrc* pSkill); // 0x00643AD0


extern int gbSkillSelectRight; // 0x007C07FC

static inline D2SkillsTxt* CLIENT_GetSkillsTxtRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        return &sgptDataTables->pSkillsTxt[nSkillId];
    }
    return 0;
}

static inline D2SkillDescTxt* CLIENT_GetSkillDescTxtRecord(int nSkillId)
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

struct D2UiCelFileStrc;


extern D2UiCelFileStrc gaSkillIconCels[7]; // 0x00724AC0

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00

unsigned char gnCharClass; // 0x007A0522

void* gpSkillIconCel; // 0x007C07F8

int ganIconValues[16]; // 0x007C0728

unsigned short gawIconValues[8]; // 0x007C07A8

#define SPELLSEL_HOTKEY_LABEL(i, key, flag) \
    if (gaHotkeySkills[i] == pSkillsTxt->nSkillId && gaHotkeyOwners[i] == nOwner \
        && gaHotkeySkills[i] != -1 && gaHotkeyLeft[i] == flag) \
    { \
        SPELLSEL_DrawKeyLabel(key, nX + 0x22, nY - 0x23, 4); \
    }

extern "C" char* __cdecl _itoa(int nValue, char* szOut, int nRadix);

int __fastcall sub_00526800(const Unicode* pString); // 0x00526800

int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820

D2UnitStrc* __stdcall INVENTORY_GetItemFromBodyLoc(D2InventoryStrc*,int); // 0x0063BDE0

int __stdcall ITEMSIsA(D2UnitStrc*,int); // 0x00629BB0

int __stdcall ITEMS_CheckIfThrowable(D2UnitStrc*); // 0x0062BA80

unsigned int __stdcall ITEMS_CheckIfStackable(D2UnitStrc* pItem); // 0x006289F0

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc*,int,int); // 0x00625480

D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc*); // 0x0063BEF0

void __stdcall TEXTURE_CelDrawColor(D2CelContextStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, int nPaletteShift); // 0x004F64B0

void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320

unsigned short __fastcall CUNIT_GetHotkeyBinding(int nA, int nB);                                                     // 0x00469AA0

const Unicode* __fastcall CMDTBL_GetKeyName(int nA, int nB);                                          // 0x0046A530

// 0x004A8C00
void __cdecl SPELLSEL_FreeSkillIcons()
{
    if (gpSkillIconCel)
    {
        ARCHIVE_FreeClientCellFile(gpSkillIconCel);
        gpSkillIconCel = 0;
    }

    if (gaSkillIconCels[gnCharClass].pCelFile)
    {
        ARCHIVE_FreeClientCellFile(gaSkillIconCels[gnCharClass].pCelFile);
        gaSkillIconCels[gnCharClass].pCelFile = 0;
    }

    for (int i = 0; i < 7; ++i)
    {
        if (gaSkillIconCels[i].pCelFile)
        {
            ARCHIVE_FreeClientCellFile(gaSkillIconCels[i].pCelFile);
            gaSkillIconCels[i].pCelFile = 0;
        }
    }
}

void* __fastcall GAME_LoadUiCelFile(const char* szPath); // 0x004520C0

int __stdcall SKILLS_GetClassIdFromSkillId(int nSkillId); // 0x00645040

// 0x004A8C80
void* __fastcall SPELLSEL_GetSkillIconCel(D2SkillsTxt* pSkillsTxt)
{
    if (!pSkillsTxt)
    {
        return gaSkillIconCels[gnCharClass].pCelFile;
    }

    int nClass = pSkillsTxt->nSkillId;
    nClass = SKILLS_GetClassIdFromSkillId(nClass);
    if (nClass >= 0 && nClass <= 6)
    {
        if (!gaSkillIconCels[nClass].pCelFile)
        {
            gaSkillIconCels[nClass].pCelFile = GAME_LoadUiCelFile(gaSkillIconCels[nClass].szPath);
        }
        return gaSkillIconCels[nClass].pCelFile;
    }

    return gpSkillIconCel;
}

// 0x004A8CE0
void __fastcall SPELLSEL_SetSkillSelectRight(int nValue)
{
    gbSkillSelectRight = nValue;
}

// 0x004A8D30
int __fastcall SPELLSEL_GetSkillState(D2UnitStrc* pUnit, D2SkillStrc* pSkill)
{
    const int nState = sub_004D9FC0(pUnit, pSkill);
    if (nState)
    {
        return nState == 6 ? 4 : 1;
    }
    return 0;
}

void __fastcall sub_004EF990_SetSkillPopUpText(D2UnitStrc* pUnit, int nId, int nA, int nB, int nState, int nX, int nY); // 0x004EF990

// 0x004A8D50
void __fastcall SPELLSEL_UpdateSkillButtonHover(short* pId, int nState, int nA, int nB, int nX, int nY)
{
    int nMouseX = sub_00468730();
    int nMouseY = sub_00468740();
    if (nMouseX >= nX && nMouseX <= nX + 48 && nMouseY >= nY - 48 && nMouseY <= nY)
    {
        nState = nState == 1;
    }
    else
    {
        nState = 1;
    }

    nMouseX = sub_00468730();
    nMouseY = sub_00468740();
    if (nMouseX >= nX && nMouseX <= nX + 48 && nMouseY >= nY - 48 && nMouseY <= nY)
    {
        sub_004EF990_SetSkillPopUpText(sub_00463DD0_GetPlayerUnit(), *pId, nA, nB, nState, nX, nY);
    }
}

// 0x004A9A00
static int __stdcall SPELLSEL_AddSkillSlot(int nX, int bLeft, int nY, D2SkillStrc* pSkill, int nState)
{
    gtHotkeySlots_007C0300.nX[gtHotkeySlots_007C0300.nCount] = nX;
    gtHotkeySlots_007C0300.nY[gtHotkeySlots_007C0300.nCount] = nY;
    gtHotkeySlots_007C0300.nSkill[gtHotkeySlots_007C0300.nCount] = SKILLS_GetSkillIdFromSkill(pSkill, ".\\UI\\spellsel.cpp", 0x23D);
    SKILLS_GetSkillInfo(pSkill, &gtHotkeySlots_007C0300.f_2D0[gtHotkeySlots_007C0300.nCount], 0, 0, 0);
    gtHotkeySlots_007C0300.nState = nState;
    ++gtHotkeySlots_007C0300.nCount;
    if (!bLeft)
        nX -= 0x30;
    else
        nX += 0x30;
    return nX;
}

// 0x004A9A90
int __fastcall sub_004A9A90_FindSkill(D2UnitStrc* pUnit, int nSkillId)
{
    if (!pUnit)
    {
        return 0;
    }
    for (D2SkillStrc* pSkill = UNITS_GetStartSkill(pUnit); pSkill; pSkill = SKILLS_GetNextSkill(pSkill))
    {
        D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
        if (pSkillsTxt && SKILLS_GetQuantity(pSkill) > 0 && pSkillsTxt->nSkillId == nSkillId)
        {
            break;
        }
    }
    return 0;
}

// 0x004A9AE0
int __fastcall sub_004A9AE0_FindSkill(D2UnitStrc* pUnit, int nSkillId)
{
    if (!pUnit)
    {
        return 0;
    }
    for (D2SkillStrc* pSkill = UNITS_GetStartSkill(pUnit); pSkill; pSkill = SKILLS_GetNextSkill(pSkill))
    {
        D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
        if (pSkillsTxt && SKILLS_GetQuantity(pSkill) > 0 && pSkillsTxt->nSkillId == nSkillId)
        {
            break;
        }
    }
    return 0;
}

// 0x004A9B30
int __fastcall sub_004A9B30_FindSkill(D2UnitStrc* pUnit, int nSkillId)
{
    if (!pUnit)
    {
        return 0;
    }
    for (D2SkillStrc* pSkill = UNITS_GetStartSkill(pUnit); pSkill; pSkill = SKILLS_GetNextSkill(pSkill))
    {
        D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
        if (pSkillsTxt && SKILLS_GetQuantity(pSkill) > 0 && pSkillsTxt->nSkillId == nSkillId)
        {
            break;
        }
    }
    return 0;
}

// 0x004A9B80
int __fastcall sub_004A9B80_FindSkill(D2UnitStrc* pUnit, int nSkillId)
{
    if (!pUnit)
    {
        return 0;
    }
    for (D2SkillStrc* pSkill = UNITS_GetStartSkill(pUnit); pSkill; pSkill = SKILLS_GetNextSkill(pSkill))
    {
        D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
        if (pSkillsTxt && SKILLS_GetQuantity(pSkill) > 0 && pSkillsTxt->nSkillId == nSkillId)
        {
            break;
        }
    }
    return 0;
}

// 0x004A9BD0
void __stdcall SPELLSEL_SkillSelectClickMsg(SMSGHANDLER_PARAMS* pMsg)
{
    D2_ASSERT(sub_00463DD0_GetPlayerUnit(), 954);

    const int nStartY = sub_00468740();
    int bHandled = 0;
    for (int i = 0; i < 60; ++i)
    {
        const int nY = gtHotkeySlots_007C0300.nY[i];
        const int nX = gtHotkeySlots_007C0300.nX[i];
        const int nMouseX = sub_00468730();
        const int nMouseY = sub_00468740();
        if (nMouseX >= nX && nMouseX <= nX + 48 && nMouseY >= nY - 48 && nMouseY <= nY)
        {
            D2SkillStrc* pSkill = SKILLS_GetSkillById(sub_00463DD0_GetPlayerUnit(), gtHotkeySlots_007C0300.nSkill[i], gtHotkeySlots_007C0300.f_2D0[i]);
            if (pSkill)
            {
                int nCharges;
                if (SKILLS_GetOwnerGUIDFromSkill(pSkill) != -1 && SKILLS_GetSkillInfo(pSkill, 0, 0, 0, &nCharges) && nCharges <= 0)
                {
                    if (GAME_GetUIVarState(3))
                    {
                        UI_SetUIVar(3, 1, 0);
                    }

                    pMsg->bReturn = 1;
                    pMsg->lResult = 0;
                    sub_00420290_BreakHandlerChain(pMsg);
                    return;
                }

                MSG_SendTwoDwords(0x3C, (gbSkillSelectRight ? 0x80000000 : 0) + gtHotkeySlots_007C0300.nSkill[i], gtHotkeySlots_007C0300.f_2D0[i]);
                UI_SetUIVar(3, 1, 0);
                gbSkillSelectRight = 0;
                bHandled = 1;
                GAME_ResetMouseState();
            }
        }
    }

    if (nStartY <= gnScreenHeight - 49 && !bHandled && GAME_GetUIVarState(3))
    {
        UI_SetUIVar(3, 1, 0);
    }

    pMsg->bReturn = 1;
    pMsg->lResult = 0;
    sub_00420290_BreakHandlerChain(pMsg);
}

int gaHotkeySkills[16]; // 0x007C06C8

int gaHotkeyOwners[16]; // 0x007C0768

int gaHotkeyLeft[16]; // 0x007C07B8

extern int gaChargedSkillIds[60]; // 0x007C04E0

// 0x004A9D70
void __stdcall SPELLSEL_ClearChargedSkillHotkeys(D2SkillsTxt* pSkillsTxt, int nQuantity)
{
    int i = 0;
    while (i < 60)
    {
        if (gaChargedSkillIds[i] != pSkillsTxt->nSkillId)
        {
            ++i;
            continue;
        }

        for (int nSlot = 0; nSlot < 16; ++nSlot)
        {
            if (gaHotkeySkills[nSlot] == gaChargedSkillIds[i] && nQuantity <= 0)
            {
                gaHotkeySkills[nSlot] = -1;
                gaHotkeyLeft[nSlot] = -1;
                gaHotkeyOwners[nSlot] = -1;
                MSG_SendTwoDwords(0x51, (nSlot << 16) + 0xFFFF, -1);
            }
        }

        ++i;
    }
}


#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])

extern unsigned int gdwBitMasks[]; // 0x006CE268

// 0x004A9DF0
void __cdecl SPELLSEL_UpdateSkillIcons()
{
    D2SkillStrc* pSkill = UNITS_GetStartSkill(sub_00463DD0_GetPlayerUnit());
    D2_ASSERT(pSkill, 1149);

    do
    {
        D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
        if (BITARRAY_CHECK(pSkillsTxt->nFlags, 36))
        {
            SPELLSEL_ClearChargedSkillHotkeys(pSkillsTxt, SKILLS_GetQuantity(pSkill));
        }
        pSkill = SKILLS_GetNextSkill(pSkill);
    }
    while (pSkill);
}

// 0x004A9E60
void __fastcall SPELLSEL_AssignHotkey(int nHotkey)
{
    for (int i = 0; i < 60; ++i)
    {
        const int nY = gtHotkeySlots_007C0300.nY[i];
        const int nX = gtHotkeySlots_007C0300.nX[i];
        const int nMouseX = sub_00468730();
        const int nMouseY = sub_00468740();
        if (nMouseX >= nX && nMouseX <= nX + 48 && nMouseY >= nY - 48 && nMouseY <= nY)
        {
            if (gaHotkeySkills[nHotkey] != -1)
            {
                MSG_SendTwoDwords(0x51, (nHotkey << 16) + 0xFFFF, -1);
            }

            gaHotkeySkills[nHotkey] = gtHotkeySlots_007C0300.nSkill[i];
            if (!gbSkillSelectRight)
            {
                gaHotkeyLeft[nHotkey] = 0;
            }
            else
            {
                gaHotkeyLeft[nHotkey] = 1;
            }
            gaHotkeyOwners[nHotkey] = gtHotkeySlots_007C0300.f_2D0[i];
            MSG_SendTwoDwords(0x51, (nHotkey << 16) + (gaHotkeyLeft[nHotkey] ? 0x8000 : 0) + gaHotkeySkills[nHotkey], gaHotkeyOwners[nHotkey]);

            for (int j = 0; j < 16; ++j)
            {
                if (gaHotkeySkills[nHotkey] == gaHotkeySkills[j] && gaHotkeyOwners[nHotkey] == gaHotkeyOwners[j] && nHotkey != j)
                {
                    gaHotkeySkills[j] = -1;
                    gaHotkeyLeft[j] = -1;
                    gaHotkeyOwners[j] = -1;
                    MSG_SendTwoDwords(0x51, (j << 16) + 0xFFFF, -1);
                }
            }
        }
    }
}


void __stdcall SKILLS_SetLeftActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643BC0

void __stdcall SKILLS_SetRightActiveSkill(D2UnitStrc* pUnit, int nSkillId, int nOwnerGUID); // 0x00643C50

int gnSelectedHotkey; // 0x007C0708

// 0x004A9FC0
static int SPELLSEL_IsHotkeyUsable(int nSlot)
{
    if (gaHotkeySkills[nSlot] == -1)
        return 0;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    if (!pPlayer)
        return 0;
    D2SkillStrc* pSkill = SKILLS_GetSkillById(pPlayer, gaHotkeySkills[nSlot], gaHotkeyOwners[nSlot]);
    if (!pSkill)
        return 0;
    if (SKILLS_GetOwnerGUIDFromSkill(pSkill) != -1)
    {
        int nCharges;
        if (SKILLS_GetSkillInfo(pSkill, 0, 0, 0, &nCharges) && nCharges <= 0)
            return 0;
    }
    return 1;
}

// 0x004AA030
void __fastcall SPELLSEL_SelectHotkey(int nSlot)
{
    if (gaHotkeySkills[nSlot] == -1)
        return;
    if (!SPELLSEL_IsHotkeyUsable(nSlot))
        return;
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    gnSelectedHotkey = nSlot;
    MSG_SendTwoDwords(0x3C, (gaHotkeyLeft[nSlot] ? 0x80000000 : 0) + gaHotkeySkills[nSlot], gaHotkeyOwners[nSlot]);
    if (gaHotkeyLeft[nSlot])
        SKILLS_SetLeftActiveSkill(pPlayer, gaHotkeySkills[nSlot], gaHotkeyOwners[nSlot]);
    else
        SKILLS_SetRightActiveSkill(pPlayer, gaHotkeySkills[nSlot], gaHotkeyOwners[nSlot]);
}

// 0x004AA0C0
void __fastcall SPELLSEL_SetHotkeySkillSlot(int nSlot, int nValueA, int nValueB, int nValueC)
{
    gaHotkeySkills[nSlot] = nValueA;
    gaHotkeyLeft[nSlot] = nValueB;
    gaHotkeyOwners[nSlot] = nValueC;
}

struct Unicode;

extern "C" __declspec(dllimport) int __cdecl wsprintfA(char* szOut, const char* szFormat, ...); // 0x006CC468

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

Unicode* __fastcall sub_005267E0(Unicode* pDst, const Unicode* pSrc); // 0x005267E0

Unicode* __fastcall sub_00526700(Unicode* pDst, const Unicode* pSrc); // 0x00526700

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

unsigned short __fastcall SKILLDESC_GetSkillDescStringId(int nId, int nIndex); // 0x004E6CE0

void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nArg4, int nArg5); // 0x00502280

static inline int IsMouseInSquare(int nX, int nY)
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    return nMouseX >= nX && nMouseX <= nX + 0x30 && nMouseY >= nY - 0x30 && nMouseY <= nY;
}

// 0x004AA0F0
static void SPELLSEL_AssignFreeHotkey(int nSlot, int nIndex)
{
    if (nSlot >= 16)
        return;
    if (gaHotkeySkills[nSlot] != -1)
        return;

    gaHotkeySkills[nSlot] = gtHotkeySlots_007C0300.nSkill[nIndex];
    if (!gbSkillSelectRight)
        gaHotkeyLeft[nSlot] = 0;
    else
        gaHotkeyLeft[nSlot] = 1;
    gaHotkeyOwners[nSlot] = gtHotkeySlots_007C0300.f_2D0[nIndex];
    MSG_SendTwoDwords(0x51, (nSlot << 16) + (gaHotkeyLeft[nSlot] ? 0x8000 : 0) + gaHotkeySkills[nSlot], gaHotkeyOwners[nSlot]);
}

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

// 0x004AA160
void __cdecl SPELLSEL_FillHotkeys()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2_ASSERT(UNITS_GetStartSkill(pPlayer), 0x524);
    int nSlot = 0;
    for (int i = 0; i < 60; ++i)
    {
        D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pPlayer, gtHotkeySlots_007C0300.nSkill[i]);
        if (!pSkill)
            continue;
        D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
        if (!pSkillsTxt)
            continue;
        if (BITARRAY_CHECK(pSkillsTxt->nFlags, 4))
            continue;
        if (nSlot > 15)
            continue;
        SPELLSEL_AssignFreeHotkey(nSlot, i);
        ++nSlot;
    }
}

// 0x004AA1F0
void __fastcall SPELLSEL_DrawSkillQuantity(short* pId, int nState, int nQuantity, int nX, int nY)
{
    if (IsMouseInSquare(nX, nY))
    {
        if (nState != 1)
        {
            nState = 0;
        }
    }
    else
    {
        nState = 1;
    }

    if (!IsMouseInSquare(nX, nY))
    {
        return;
    }

    const Unicode* wszNewline = D2LANG_GetStringFromTblIndex(0xF9E);
    Unicode wszText[0x100];
    const unsigned short nNameId = SKILLDESC_GetSkillDescStringId(*pId, 0);
    const int nTextId = SKILLDESC_GetSkillDescStringId(*pId, 1);
    sub_005267E0(wszText, D2LANG_GetStringFromTblIndex(nTextId));
    sub_00526700(wszText, wszNewline);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0x105C));
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(0xF9D));
    Unicode wszNumber[10];
    char szNumber[12];
// build: symbol ?gszFormatI@* 0x006D6454
    wsprintfA(szNumber, gszFormatI, nQuantity);
    sub_00526320_ToUnicode(wszNumber, szNumber, 9);
    sub_00526700(wszText, wszNumber);
    sub_00526700(wszText, wszNewline);
    sub_00526700(wszText, D2LANG_GetStringFromTblIndex(nNameId));
    D2Win_10129_DrawFramedText(wszText, nX, nY - 0x32, nState, 1);
}

// 0x004AA3A0
void __fastcall SPELLSEL_BuildSkillRows(D2UnitStrc* pUnit, int nStartX, int bLeft, int bNoSlots, int bNoDraw)
{
    int nY = gnScreenHeight - 0x56;
    int nMaxRow = 0;
    const int nStepX = bLeft ? 0x30 : -0x30;
    unsigned char abPoolUsed[0x100];
    memset(abPoolUsed, 0, sizeof(abPoolUsed));
    for (int nRow = 0; nRow < 5; ++nRow)
    {
        int nX = nStartX;
        D2SkillStrc* pNext;
        for (D2SkillStrc* pSkill = UNITS_GetStartSkill(pUnit); pSkill; pSkill = pNext)
        {
            pNext = SKILLS_GetNextSkill(pSkill);
            D2SkillsTxt* pSkillsTxt = SKILLS_GetSkillsTxtRecordFromSkill(pSkill);
            if (!pSkillsTxt)
                continue;
            D2SkillDescTxt* pSkillDescTxt = CLIENT_GetSkillDescTxtRecord(pSkillsTxt->nSkillId);
            if (!pSkillDescTxt)
                continue;
            if (bLeft && !(pSkillsTxt->nFlags[SKILLSFLAGINDEX_LEFTSKILL >> 3] & gdwBitMasks_006CE268[SKILLSFLAGINDEX_LEFTSKILL & 7]))
                continue;
            if (pSkillsTxt->nFlags[SKILLSFLAGINDEX_PASSIVE >> 3] & gdwBitMasks_006CE268[SKILLSFLAGINDEX_PASSIVE & 7])
                continue;
            if (SKILLS_GetFlags(pSkill) & 8)
                continue;
            int nOwner = -1;
            int nCharges = 0;
            int nQuantity = 0;
            int bItem = SKILLS_GetSkillInfo(pSkill, &nOwner, 0, 0, &nCharges);
            if (!bLeft && !bItem)
            {
                nQuantity = SKILLS_GetQuantity(pSkill);
                if (nQuantity > 0 && (pSkillsTxt->nFlags[4 + (SKILLSFLAGINDEX2_SCROLL >> 3)] & gdwBitMasks_006CE268[SKILLSFLAGINDEX2_SCROLL & 7]))
                    bItem = 1;
            }
            if (nRow < 4)
            {
                if (bItem)
                    continue;
                if (nRow != (char)pSkillDescTxt->nListRow)
                    continue;
            }
            else if (!bItem)
                continue;
            int nState;
            const int nUse = sub_004D9FC0(pUnit, pSkill);
            if (nUse)
                nState = nUse == 6 ? 4 : 1;
            else
                nState = 0;
            if (nMaxRow < nRow)
            {
                nY -= 0x30;
                nMaxRow = nRow;
            }
            if (pSkillDescTxt->nListPool > 0 && pSkillDescTxt->nListPool < 0x100)
            {
                if (abPoolUsed[pSkillDescTxt->nListPool] > 0)
                    continue;
                abPoolUsed[pSkillDescTxt->nListPool] = 1;
            }
            if (!bNoSlots)
            {
                if (!bNoDraw)
                    SPELLSEL_DrawSkillSlot(pSkillsTxt, nOwner, nCharges, nState, nX, nY, bLeft);
                nX = SPELLSEL_AddSkillSlot(nX, bLeft, nY, pSkill, nState);
            }
            else
            {
                if (!nQuantity)
                    SPELLSEL_UpdateSkillButtonHover(pSkillsTxt, nState, SKILLS_GetSkillLevel(pUnit, pSkill, 1), nCharges, nX, nY);
                else
                    SPELLSEL_DrawSkillQuantity(pSkillsTxt, nState, nQuantity, nX, nY);
                nX += nStepX;
            }
            switch (nRow)
            {
            case 1:
                gaSkillRowY[0] = nY;
                break;
            case 2:
                gaSkillRowY[1] = nY;
                break;
            case 3:
                gaSkillRowY[2] = nY;
                break;
            case 4:
                gaSkillRowY[3] = nY;
                break;
            }
        }
    }
}

struct D2SkillIconStateStrc;

extern D2SkillIconStateStrc gtHotkeySlots; // 0x007C0300

// 0x004AA680
void __cdecl SPELLSEL_BuildRightRows()
{
    if (gbSkillSelectRight)
    {
        gtHotkeySlots.bFlag = 0;
        SPELLSEL_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), 0x50, 1, 0, 0);
    }
}

extern int gnScreenWidth; // 0x0071146C

// 0x004AA6B0
void __fastcall SPELLSEL_BuildLeftRows(int bNoDraw)
{
    if (!gbSkillSelectRight)
    {
        gtHotkeySlots.bFlag = 0;
        SPELLSEL_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), gnScreenWidth - 0x80, 0, 0, bNoDraw);
    }
}

// 0x004AA6E0
void __cdecl SPELLSEL_BuildRightRows2()
{
    if (gbSkillSelectRight)
        SPELLSEL_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), 0x50, 1, 1, 0);
}

// 0x004AA710
void __cdecl SPELLSEL_BuildLeftRows2()
{
    if (!gbSkillSelectRight)
        SPELLSEL_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), gnScreenWidth - 0x80, 0, 1, 0);
}

int __cdecl CUNIT_IsPlayerDeadOrMissing(); // 0x00463DF0

// 0x004AA740
void __fastcall SPELLSEL_CycleHotkey(int nDelta)
{
    if (CUNIT_IsPlayerDeadOrMissing())
        return;
    const int nStep = (nDelta > 0) * 2 - 1;
    if (nDelta < 0)
        nDelta = -nDelta;
    if (!nDelta)
        return;
    int nFound = -1;
    int nSlot = gnSelectedHotkey + nStep;
    for (int i = 0; i < 16; ++i, nSlot += nStep)
    {
        if (nSlot < 0)
            nSlot = 15;
        else if (nSlot >= 16)
            nSlot = 0;
        if (gaHotkeySkills[nSlot] != -1 && !gaHotkeyLeft[nSlot] && SPELLSEL_IsHotkeyUsable(nSlot))
        {
            nFound = nSlot;
            if (!--nDelta)
                break;
        }
    }
    if (nFound != -1)
        SPELLSEL_SelectHotkey(nFound);
}

// 0x004AA7E0
void __cdecl SPELLSEL_ResetSkillIcons()
{
    memset(&gtHotkeySlots, 0, 0x3C5);
    for (int i = 0; i < 60; ++i)
    {
        gtHotkeySlots.anValues[i] = -1;
    }

    if (gbSkillSelectRight)
    {
        gtHotkeySlots.bFlag = 0;
        SPELLSEL_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), 0x50, 1, 0, 0);
    }
    if (!gbSkillSelectRight)
    {
        gtHotkeySlots.bFlag = 0;
        SPELLSEL_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), gnScreenWidth - 0x80, 0, 0, 0);
    }
    if (gbSkillSelectRight)
    {
        SPELLSEL_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), 0x50, 1, 1, 0);
    }
    if (!gbSkillSelectRight)
    {
        SPELLSEL_BuildSkillRows(sub_00463DD0_GetPlayerUnit(), gnScreenWidth - 0x80, 0, 1, 0);
    }
}

// 0x004AA8B0
int __fastcall SPELLSEL_GetSkillMaxLevel(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
    {
        const int nValue = sgptDataTables->pSkillsTxt[nSkillId].nMaxLevel;
        if (nValue > 0)
            return nValue;
    }
    return 20;
}

extern "C" int gbSkillPointsHighlight; // 0x007C0C3C

// 0x004AA8E0
void __cdecl SPELLSEL_ClearSkillPointsHighlight()
{
    gbSkillPointsHighlight = 0;
}

// 0x004AA8F0
extern "C" void __cdecl INV_ClearSkillPointsHighlight()
{
    gbSkillPointsHighlight = 0;
}

// 0x004A8A30
void __cdecl SPELLSEL_InitSkillIcons()
{
    gpSkillIconCel = GAME_LoadUiCelFile("Spells\\Skillicon");
    gaSkillIconCels[gnCharClass].pCelFile = GAME_LoadUiCelFile(gaSkillIconCels[gnCharClass].szPath);

    int i;
    for (i = 0; i < 16; ++i)
    {
        ganIconValues[i] = -1;
    }
    for (i = 0; i < 16; ++i)
    {
        gaHotkeyOwners[i] = -1;
    }
    for (i = 0; i < 16; ++i)
    {
        gaHotkeyLeft[i] = -1;
    }
    for (i = 0; i < 16; ++i)
    {
        gaHotkeySkills[i] = -1;
    }

    memset(&gtHotkeySlots, 0, 0x3C5);
    for (i = 0; i < 60; ++i)
    {
        gtHotkeySlots.anValues[i] = -1;
    }
    for (i = 0; i < 8; ++i)
    {
        gawIconValues[i] = 0;
    }
}

// 0x004A8CF0
static int __stdcall SPELLSEL_IsMouseInRect(int nX, int nWidth, int nY, int nHeight)
{
    const int nMouseX = sub_00468730();
    const int nMouseY = sub_00468740();
    if (nMouseX >= nX && nMouseX <= nX + nWidth && nMouseY >= nY - nHeight && nMouseY <= nY)
        return 1;
    return 0;
}

// calling-convention shim (not game code): nothing in the image calls 0x4A8CF0, so this gives the
// static the register arguments it has there
void __stdcall sub_K05_EmitUse(int nValue);

void __fastcall sub_K05_EmitMouseInRect(int nX, int nY)
{
    sub_K05_EmitUse(SPELLSEL_IsMouseInRect(nX, 0x30, nY, 0x30));
    sub_K05_EmitUse(SPELLSEL_IsMouseInRect(nX + 0x30, 0x30, nY, 0x30));
}

// build: symbol ?$S1@?4??SPELLSEL_DrawKeyLabel@@YIXHHHH@Z@4IA 0x007C0830
// 0x004A8DF0
void __fastcall SPELLSEL_DrawKeyLabel(int nKeyId, int nX, int nY, int nColor)
{
    if (CUNIT_GetHotkeyBinding(nKeyId, 1) == 0xFFFF)
    {
        return;
    }

    static Unicode wszBuf[16]; // 0x007C0810
    const Unicode* wszText = CMDTBL_GetKeyName(nKeyId, 1);
    int nWidth = D2Win_10121_GetTextWidth(wszText);
    if (nWidth > 40)
    {
        Unicode::strncpy(wszBuf, wszText, 16);
        wszText = wszBuf;
        Unicode* pEnd = &wszBuf[sub_00526800(wszText)];
        do
        {
            --pEnd;
            pEnd->wChar = 0;
            nWidth = D2Win_10121_GetTextWidth(wszBuf);
        }
        while (nWidth > 40);
    }

    if (nWidth > 13)
    {
        nX += 13 - nWidth;
    }

    D2Win_10117_DrawText(wszText, nX, nY, nColor, 0);
}

// 0x004A8ED0
static void __stdcall SPELLSEL_DrawSkillHotkeyLabels(const D2SkillsTxt* pSkillsTxt, int nOwner, int nX, int nY)
{
    SPELLSEL_HOTKEY_LABEL(0, 0x0E, 1)
    SPELLSEL_HOTKEY_LABEL(1, 0x0F, 1)
    SPELLSEL_HOTKEY_LABEL(2, 0x10, 1)
    SPELLSEL_HOTKEY_LABEL(3, 0x11, 1)
    SPELLSEL_HOTKEY_LABEL(4, 0x12, 1)
    SPELLSEL_HOTKEY_LABEL(5, 0x13, 1)
    SPELLSEL_HOTKEY_LABEL(6, 0x14, 1)
    SPELLSEL_HOTKEY_LABEL(7, 0x15, 1)
    SPELLSEL_HOTKEY_LABEL(8, 0x2E, 1)
    SPELLSEL_HOTKEY_LABEL(9, 0x2F, 1)
    SPELLSEL_HOTKEY_LABEL(10, 0x30, 1)
    SPELLSEL_HOTKEY_LABEL(11, 0x31, 1)
    SPELLSEL_HOTKEY_LABEL(12, 0x32, 1)
    SPELLSEL_HOTKEY_LABEL(13, 0x33, 1)
    SPELLSEL_HOTKEY_LABEL(14, 0x34, 1)
    SPELLSEL_HOTKEY_LABEL(15, 0x35, 1)
}

// 0x004A9260
static void __stdcall SPELLSEL_DrawSkillCharges(int nCharges, int nX, int nY)
{
    Unicode wszText[16] = {};
    char szText[16];
    if (nCharges > 0)
    {
        sub_00526320_ToUnicode(wszText, _itoa(nCharges, szText, 10), 16);
        int nLength = sub_00526800(wszText);
        while (D2Win_10121_GetTextWidth(wszText) > 40)
        {
            wszText[nLength].wChar = 0;
            --nLength;
        }
        D2Win_10121_GetTextWidth(wszText);
        D2Win_10117_DrawText(wszText, nX + 4, nY - 1, 3, 0);
    }
}

// 0x004A9300
static void __stdcall SPELLSEL_DrawHotkeyLabelsB(const D2SkillsTxt* pSkillsTxt, int nOwner, int nX, int nY)
{
    SPELLSEL_HOTKEY_LABEL(0, 0x0E, 0)
    SPELLSEL_HOTKEY_LABEL(1, 0x0F, 0)
    SPELLSEL_HOTKEY_LABEL(2, 0x10, 0)
    SPELLSEL_HOTKEY_LABEL(3, 0x11, 0)
    SPELLSEL_HOTKEY_LABEL(4, 0x12, 0)
    SPELLSEL_HOTKEY_LABEL(5, 0x13, 0)
    SPELLSEL_HOTKEY_LABEL(6, 0x14, 0)
    SPELLSEL_HOTKEY_LABEL(7, 0x15, 0)
    SPELLSEL_HOTKEY_LABEL(8, 0x2E, 0)
    SPELLSEL_HOTKEY_LABEL(9, 0x2F, 0)
    SPELLSEL_HOTKEY_LABEL(10, 0x30, 0)
    SPELLSEL_HOTKEY_LABEL(11, 0x31, 0)
    SPELLSEL_HOTKEY_LABEL(12, 0x32, 0)
    SPELLSEL_HOTKEY_LABEL(13, 0x33, 0)
    SPELLSEL_HOTKEY_LABEL(14, 0x34, 0)
    SPELLSEL_HOTKEY_LABEL(15, 0x35, 0)
}

// 0x004A9690
void __fastcall SPELLSEL_DrawSkillInfoBase(void* cell,D2SkillsTxt* skills,int owner,int charges,int state,int x,int y,int left) {
 int id=skills->nSkillId;
 D2SkillsTxt* record;
 if(id>=0 && id<sgptDataTables->nSkillsTxtRecordCount)record=&sgptDataTables->pSkillsTxt[id];else record=0;
 if(!record)return;
 id=record->wSkillDesc;
 D2SkillDescTxt* desc;
 if(id>=0 && id<sgptDataTables->nSkillDescTxtRecordCount)desc=&sgptDataTables->pSkillDescTxt[id];else desc=0;
 if(!desc)return;
 int frame=desc->nIconCel;
 int mouseX=sub_00468730();
 int mouseY=sub_00468740();
 int drawState;
 if(mouseX>=x && mouseX<=x+48 && mouseY>=y-48 && mouseY<=y) {
  if(state==0)drawState=0;
  else if(state==1)drawState=1;
  else drawState=state==4?4:1;
 } else drawState=state;
 D2CelContextStrc ctx;memset(&ctx,0,sizeof(ctx));
 ctx.pCellFile=cell;ctx.nDirection=0;ctx.nFrame=frame;
 TEXTURE_CelDrawColor(&ctx,x,y,-1,5,drawState);
 if(left)SPELLSEL_DrawSkillHotkeyLabels(skills,owner,x,y);
 else SPELLSEL_DrawHotkeyLabelsB(skills,owner,x,y); // 0x004A9300
 D2UnitStrc* player=sub_00463DD0_GetPlayerUnit();
 int quantity;
 if(player && player->pInventory) {
  D2InventoryStrc* inv=player->pInventory;
  switch(skills->nSkillId) {
  case SKILL_LEFTHANDTHROW: {
   D2UnitStrc* hand=INVENTORY_GetLeftHandWeapon(inv);
   D2UnitStrc* item=INVENTORY_GetItemFromBodyLoc(inv,4);
   D2UnitStrc* other=INVENTORY_GetItemFromBodyLoc(inv,5);
   if(hand==item)item=other;
   if(item && ITEMSIsA(item,45) && ITEMS_CheckIfThrowable(item) && ITEMS_CheckIfStackable(item)) {
    quantity=STATLIST_UnitGetStatValue(item,STAT_QUANTITY,0);goto draw;
   }
   break;
  }
  case SKILL_THROW: {
   D2UnitStrc* item=INVENTORY_GetLeftHandWeapon(inv);
   if(item && ITEMS_CheckIfThrowable(item) && ITEMS_CheckIfStackable(item)) {
    quantity=STATLIST_UnitGetStatValue(item,STAT_QUANTITY,0);goto draw;
   }
   break;
  }
  }
 }
 quantity=charges;
 draw: SPELLSEL_DrawSkillCharges(quantity,x,y); // 0x004A9260
}

// 0x004A9870
void __fastcall SPELLSEL_DrawSkillSlot(D2SkillsTxt* skills,int owner,int charges,int state,int x,int y,int left) {
 void* cell;
 unsigned int classId=SKILLS_GetClassIdFromSkillId(skills->nSkillId);
 if(classId<=6) {
  if(!gaSkillIconCels[classId].pCelFile)gaSkillIconCels[classId].pCelFile=GAME_LoadUiCelFile(gaSkillIconCels[classId].szPath);
  cell=gaSkillIconCels[classId].pCelFile;
 } else cell=gpSkillIconCel;
 int id=skills->nSkillId;
 D2SkillsTxt* record;
 if(id>=0 && id<sgptDataTables->nSkillsTxtRecordCount)record=&sgptDataTables->pSkillsTxt[id];else record=0;
 if(!record)return;
 id=record->wSkillDesc;
 D2SkillDescTxt* desc;
 if(id>=0 && id<sgptDataTables->nSkillDescTxtRecordCount)desc=&sgptDataTables->pSkillDescTxt[id];else desc=0;
 if(!desc)return;
 int frame=desc->nIconCel;
 int mouseX=sub_00468730();
 int mouseY=sub_00468740();
 int drawState,drawY;
 if(mouseX>=x && mouseX<=x+48) {
  // volatile: the original reads y from its stack slot here
  drawY=*(int volatile*)&y;
  if(mouseY>=drawY-48 && mouseY<=drawY) {
   if(state==0)drawState=0;
   else if(state==1)drawState=1;
   else drawState=state==4?4:1;
  } else drawState=state;
 } else {drawY=y;drawState=state;}
 D2CelContextStrc ctx;
 memset(&ctx,0,sizeof(ctx));
 ctx.pCellFile=cell;ctx.nDirection=0;ctx.nFrame=frame;
 TEXTURE_CelDrawColor(&ctx,x,drawY,-1,5,drawState);
 if(left) {
  SPELLSEL_DrawSkillHotkeyLabels(skills,owner,x,drawY);
  SPELLSEL_DrawSkillCharges(charges,x,drawY);
 } else {
  SPELLSEL_DrawHotkeyLabelsB(skills,owner,x,drawY);
  SPELLSEL_DrawSkillCharges(charges,x,drawY);
 }
}

#include "gen/data/Source/D2Client/UI/spellsel.inc"
