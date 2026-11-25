#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2ClientGame.h"
#include "D2Unicode.h"
#include "D2ClientUi.h"
#include "D2StormTypes.h"
#include "D2ClientSound.h"
#include "D2HintKeyList.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct Unicode;
struct D2HintKeyListStrc;
struct D2TimedHintNodeStrc;

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
int __fastcall UI_SetUIVar(unsigned int nUIVar, unsigned int nState, int nArg); // 0x00455F20
int __fastcall GAME_GetUIVarState(unsigned int nUIVar); // 0x004538D0
int __cdecl CUNIT_IsPlayerDeadOrMissing(); // 0x00463DF0
void __cdecl INV_ClearTradeFlag(); // 0x0048A6F0
void __fastcall MSG_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3); // 0x00478600
void __fastcall DIALOG_DestroyDialog(void* pRes); // 0x004B8020
// build: symbol ?DIALOG_CreateDialog@* 0x004B7EB0
D2ClientDialogStrc* __fastcall DIALOG_CreateDialog(int nArg1, int nArg2, int (__cdecl* pfnArg8)(),
    int (__cdecl* pfnArgC)(), int nArg10, int nArg14, int nArg18, int nArg1C, int nArg20, int nArg24, int nArg28); // 0x004B7EB0
void __fastcall sub_004B8370(void* pPanel, int nValue); // 0x004B8370
// build: symbol ?DIALOG_AddTextLine@* 0x004B85F0
void __fastcall DIALOG_AddTextLine(void* pPanel, const Unicode* pText, int nArg3, int nArg4, int nArg5, int nArg6,
    int (__cdecl* pfnArg7)(), int nArg8); // 0x004B85F0
void __fastcall sub_004B82F0_Select(D2ClientDialogStrc* pDialog, int nIndex); // 0x004B82F0
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
int __cdecl sub_004B8A30_OnCancel(); // 0x004B8A30
int __cdecl sub_004B8A80_OnClose(); // 0x004B8A80
extern D2ClientDialogStrc* gpTradeWaitDialog; // 0x007C0E6C
extern unsigned long gdwTradeTimeoutTick; // 0x007C0E70
extern unsigned long gdwSecondaryTradeGold; // 0x007C0E78
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
int __cdecl sub_004B8BA0_OnClose2(); // 0x004B8BA0


int __cdecl DLIGHTMAP_GetSoundTick(); // 0x00481820
D2SoundsTxt* __fastcall SOUNDHDR_GetSoundRecord(int nId); // 0x00481860
void __fastcall SOUNDINST_SetValue(int nKey, int nValue); // 0x004B9B50
extern D2TimedHintNodeStrc* gpClientSoundList; // 0x007C5458

D2ClientDialogStrc* gpTradeRequestDialog; // 0x007C0E64

unsigned long gdwPrimaryTradeGold; // 0x007C0E68

char gbGlobal_007C0E74; // 0x007C0E74

int gnTradeState; // 0x007C0E7C

char gbTradeActive; // 0x007C0E80

int __fastcall sub_004B9A00(int nSoundId, int nArg1, int nArg2, int nArg3, int nArg4); // 0x004B9A00

void __cdecl INV_OpenCubePanel(); // 0x0048A460

void __cdecl INV_OpenStashPanel(); // 0x00489E00

void __cdecl INV_ResetStashPanel(); // 0x00489F50

void __fastcall INV_SetTradePanelOpen(int bOpen); // 0x00489360

void __fastcall UNITSND_PlayPlayerSpeech(D2UnitStrc* pUnit, unsigned short nStringId); // 0x004CB9C0

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

D2UnitStrc* __stdcall INVENTORY_GetCursorItem(D2InventoryStrc* pInventory); // 0x0063C1E0

int __cdecl sub_004B85E0(); // 0x004B85E0

void __fastcall INV_UpdateTradeAcceptSound(int nArg1, int nArg2); // 0x004897E0

int __fastcall UI_GetUIVarUnchecked(int nUIVar); // 0x00453A90

void __cdecl INV_SetTradeFlag(); // 0x0048A6E0

extern "C" void __fastcall sub_00478600_SendPacket(unsigned char command, unsigned short value, unsigned short first, unsigned short second);

int __stdcall STATLIST_UnitGetStatValue(D2UnitStrc* pUnit, int nStatId, int nLayer); // 0x00625480

void __fastcall WINMAIN_SetExitApplication(int nValue); // 0x0044B880

void __fastcall GAME_SetCinematicExit(int nValue); // 0x0044C860

void __cdecl GAME_RequestExit(); // 0x0044D520

extern int gnTradePartnerUnitId; // 0x007C0E60

extern "C" int gPacketState; // 0x007C0E7C

// build: symbol ??__EgwszTradePartnerName@@YAXXZ 0x006CAD80
Unicode gwszTradePartnerName[16]; // 0x007C0E84

struct D2NamePacketStrc
{
    unsigned char nHeader;
    char szName[16];
    unsigned char nValue[4];
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, size_t nSize); // 0x00681EB0

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20


int __cdecl sub_00468730(); // 0x00468730

int __cdecl sub_00468740(); // 0x00468740

int __cdecl UI_IsGoldPanelOpen(); // 0x004549C0

void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nTextColor, int nAlign); // 0x00502280

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall DUNGEON_IsTownLevelId(int nLevelId); // 0x0061AAF0

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

void __cdecl INV_ResetNpcState(); // 0x00487B30

void __fastcall DIALOG_DrawDialog(D2ClientDialogStrc* pDialog); // 0x004B8100

extern int gnPanelOffsetX; // 0x007A2858

extern int gnPanelOffsetY; // 0x007A285C

// 0x004B8720
void __cdecl sub_004B8720()
{
    gnTradeState = 0;
    gbGlobal_007C0E74 = 0;
}

// 0x004B8730
void __cdecl sub_004B8730_DrawDialogHover()
{
    int nX = sub_00468730();
    int nY = sub_00468740();
    if (gnTradeState > 2 && !UI_IsGoldPanelOpen())
    {
        if (nX >= gnPanelOffsetX + 0x111 && nX <= gnPanelOffsetX + 0x133 && nY >= 0xA8 - gnPanelOffsetY && nY <= 0xCA - gnPanelOffsetY)
            D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0x1023), gnPanelOffsetX + 0xEF, 0xA7 - gnPanelOffsetY, 0, 0);
        if (nX >= gnPanelOffsetX + 0xDD && nX <= gnPanelOffsetX + 0xFF && nY >= 0x17F - gnPanelOffsetY && nY <= 0x1A1 - gnPanelOffsetY)
            D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0x1023), gnPanelOffsetX + 0xBB, 0x17E - gnPanelOffsetY, 0, 0);
        if (nX >= gnPanelOffsetX + 0x111 && nX <= gnPanelOffsetX + 0x133 && nY >= 0x17F - gnPanelOffsetY && nY <= 0x1A1 - gnPanelOffsetY)
            D2Win_10129_DrawFramedText(D2LANG_GetStringFromTblIndex(0x1022), gnPanelOffsetX + 0x107, 0x17E - gnPanelOffsetY, 0, 0);
    }

    if (sub_00463DD0_GetPlayerUnit())
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(sub_00463DD0_GetPlayerUnit());
        if (CUNIT_IsPlayerDeadOrMissing() || (pRoom && !DUNGEON_IsTownLevelId(DUNGEON_GetLevelIdFromRoom(pRoom))))
        {
            if (GAME_GetUIVarState(0x17))
            {
                MSG_SendShorts(0x4F, 2, 0, 0);
                UI_SetUIVar(0x17, 1, 0);
                INV_ClearTradeFlag();
                INV_ResetNpcState();
                gnTradeState = 0;
            }
            return;
        }
    }

    if (gnTradeState >= 3 && gnTradeState <= 6)
        return;
    if (!gnTradeState)
        return;
    if (gnTradeState == 1)
    {
        if (gpTradeWaitDialog)
            DIALOG_DrawDialog(gpTradeWaitDialog);
    }
    else if (gnTradeState == 2)
    {
        if (gpTradeRequestDialog)
            DIALOG_DrawDialog(gpTradeRequestDialog);
    }
}


// 0x004B8920
void __cdecl sub_004B8920()
{
    gdwSecondaryTradeGold = 0;
    gdwPrimaryTradeGold = 0;
    gbTradeActive = 1;
}

// 0x004B8940
void __fastcall sub_004B8940_CloseWait(int bReopen)
{
    gbTradeActive = 0;
    if (gpTradeWaitDialog)
    {
        DIALOG_DestroyDialog(gpTradeWaitDialog);
        gpTradeWaitDialog = 0;
    }

    if (gpTradeRequestDialog)
    {
        DIALOG_DestroyDialog(gpTradeRequestDialog);
        gpTradeRequestDialog = 0;
    }

    if (gnTradeState == 7)
    {
        return;
    }

    if (GAME_GetUIVarState(0x17))
    {
        UI_SetUIVar(0x17, 1, 0);
        INV_ClearTradeFlag();
        sub_00487B30();
        if (!CUNIT_IsPlayerDeadOrMissing() && bReopen)
        {
            UI_SetUIVar(1, 2, 0);
        }

        if (GAME_GetUIVarState(5))
        {
            UI_SetUIVar(5, 1, 0);
        }
    }

    if (gnTradeState)
    {
        MSG_SendShorts(0x4F, 2, 0, 0);
        gnTradeState = 0;
    }
}

// 0x004B8AD0
int __cdecl sub_004B8AD0_OpenWait()
{
    if (gpTradeRequestDialog)
    {
        return 0;
    }

    gpTradeRequestDialog = DIALOG_CreateDialog(0x140, 0x64, sub_004B8A80_OnClose, sub_004B8A80_OnClose, 0, 1, 1, 0, 0, 0, 1);
    sub_004B8370(gpTradeRequestDialog, 1);
    DIALOG_AddTextLine(gpTradeRequestDialog, D2LANG_GetStringFromTblIndex(0xFCA), 0xF, 0, 0, 1, 0, 0);
    DIALOG_AddTextLine(gpTradeRequestDialog, D2LANG_GetStringFromTblIndex(0xD49), 0xF, 0, 0, 1, sub_004B8A30_OnCancel, 1);
    DIALOG_AddTextLine(gpTradeRequestDialog, D2LANG_GetStringFromTblIndex(0xD48), 0xF, 0, 0, 1, sub_004B8A80_OnClose, 1);
    sub_004B82F0_Select(gpTradeRequestDialog, -1);
    return 1;
}

// 0x004B8CB0
void __cdecl sub_004B8CB0()
{
    MSG_SendShorts(0x4F, 2, 0, 0);
    if (gnTradeState != 7)
    {
        gbGlobal_007C0E74 = 1;
        gdwTradeTimeoutTick = GetTickCount();
        gnTradeState = 7;
    }
}

// 0x004B9070
void __cdecl sub_004B9070_SendPosition()
{
    gnTradeState = 7;
    MSG_SendShorts(0x4F, 4, (unsigned short)(gdwPrimaryTradeGold >> 16), (unsigned short)gdwPrimaryTradeGold);
    gdwTradeTimeoutTick = 0xFFFFFFFF;
}

D2ClientDialogStrc* gpTradeWaitDialog; // 0x007C0E6C

// 0x004B8BF0
void __cdecl sub_004B8BF0_OpenWait2()
{
    D2_ASSERT(!gpTradeWaitDialog, 0x13D);
    gpTradeWaitDialog = DIALOG_CreateDialog(0x140, 0x64, sub_004B8BA0_OnClose2, sub_004B8BA0_OnClose2, 0, 1, 1, 0, 0, 0, 1);
    sub_004B8370(gpTradeWaitDialog, 1);
    DIALOG_AddTextLine(gpTradeWaitDialog, D2LANG_GetStringFromTblIndex(0xFCB), 0xF, 0, 0, 1, 0, 0);
    DIALOG_AddTextLine(gpTradeWaitDialog, D2LANG_GetStringFromTblIndex(0xD48), 0xF, 0, 0, 1, sub_004B8BA0_OnClose2, 1);
    sub_004B82F0_Select(gpTradeWaitDialog, -1);
}

// 0x004B8A00
int __cdecl sub_004B8A00_IsGlobalClear()
{
    return gbTradeActive == 0;
}

// 0x004B8A10
int __cdecl CUNIT_IsTrading()
{
    if (gnTradeState == 1 || gnTradeState == 2)
    {
        return 1;
    }

    return 0;
}


// 0x004B8A30
int __cdecl sub_004B8A30_OnCancel()
{
    sub_004B9A00(2, 0, 0, 0, 0);
    DIALOG_DestroyDialog(gpTradeRequestDialog);
    gpTradeRequestDialog = 0;
    gnTradeState = 3;
    MSG_SendShorts(0x4F, 3, 0, 0);
    return 1;
}

// 0x004B8A80
int __cdecl sub_004B8A80_OnClose()
{
    sub_004B9A00(2, 0, 0, 0, 0);
    DIALOG_DestroyDialog(gpTradeRequestDialog);
    gpTradeRequestDialog = 0;
    gnTradeState = 7;
    MSG_SendShorts(0x4F, 2, 0, 0);
    gdwTradeTimeoutTick = GetTickCount();
    return 1;
}

// 0x004B8BA0
int __cdecl sub_004B8BA0_OnClose2()
{
    sub_004B9A00(2, 0, 0, 0, 0);
    DIALOG_DestroyDialog(gpTradeWaitDialog);
    gpTradeWaitDialog = 0;
    gnTradeState = 7;
    gdwTradeTimeoutTick = GetTickCount();
    MSG_SendShorts(0x4F, 2, 0, 0);
    return 1;
}

// 0x004B8CF0
void __fastcall sub_004B8CF0_HandleTradePacket(const unsigned char* pPacket)
{
    switch (pPacket[1])
    {
    case 21:
        INV_OpenCubePanel();
        return;

    case 16:
        INV_OpenStashPanel();
        return;

    case 17:
        INV_ResetStashPanel();
        return;

    case 12:
        gnTradeState = 0;
        sub_004B8940_CloseWait(0);
        return;

    case 13:
        gnTradeState = 0;
        sub_004B8940_CloseWait(1);
        return;

    case 0:
        if (!gnTradeState)
        {
            if (!GAME_GetUIVarState(0x17))
            {
                if (!UI_SetUIVar(0x17, 0, 0))
                {
                    sub_004B8CB0();
                    return;
                }

                INV_ClearTradeFlag();
                gdwTradeTimeoutTick = 0xFFFFFFFF;
            }

            gnTradeState = 1;
            sub_004B8BF0_OpenWait2();
            INV_SetTradePanelOpen(0);
            return;
        }

        sub_004B8CB0();
        return;

    case 9:
        UNITSND_PlayPlayerSpeech(sub_00463DD0_GetPlayerUnit(), 0x17);
        return;

    case 10:
    {
        D2UnitStrc* pUnit = CUNIT_FindClientUnit(gnTradePartnerUnitId, 0);
        if (pUnit)
        {
            UNITSND_PlayPlayerSpeech(pUnit, 0x17);
        }
        return;
    }

    case 1:
        if (!gnTradeState)
        {
            D2InventoryStrc* const pInventory = sub_00463DD0_GetPlayerUnit()->pInventory;
            if (INVENTORY_GetCursorItem(pInventory))
            {
                MSG_SendShorts(0x4F, 2, 0, 0);
                return;
            }

            if (sub_004B85E0() || !sub_004B8AD0_OpenWait() || GAME_GetUIVarState(5))
            {
                MSG_SendShorts(0x4F, 2, 0, 0);
                return;
            }

            if (!GAME_GetUIVarState(0x17))
            {
                if (!UI_SetUIVar(0x17, 0, 0))
                {
                    sub_004B8CB0();
                    return;
                }

                gdwTradeTimeoutTick = 0xFFFFFFFF;
            }

            gnTradeState = 2;
            INV_SetTradePanelOpen(0);
            return;
        }

        sub_004B8CB0();
        return;

    case 2:
        INV_UpdateTradeAcceptSound(0, 0);
        sub_004B8940_CloseWait(0);
        return;

    case 5:
        if (!UI_GetUIVarUnchecked(0x17))
        {
            return;
        }

        gdwTradeTimeoutTick = 0xFFFFFFFF;
        INV_SetTradePanelOpen(1);
        switch (gnTradeState)
        {
        case 3:
            gnTradeState = 5;
        case 5:
            INV_UpdateTradeAcceptSound(0, 1);
            return;

        case 4:
            gnTradeState = 6;
            INV_UpdateTradeAcceptSound(1, 1);
            return;

        case 6:
        case 7:
            return;

        default:
            sub_004B8CB0();
            return;
        }

    case 6:
        if (!UI_GetUIVarUnchecked(0x17))
        {
            return;
        }

        MSG_SendShorts(0x4F, 8, (unsigned short)(gdwPrimaryTradeGold >> 16), (unsigned short)gdwPrimaryTradeGold);
        gdwTradeTimeoutTick = 0xFFFFFFFF;
        INV_SetTradePanelOpen(1);
        switch (gnTradeState)
        {
        case 7:
            gnTradeState = 3;
        case 3:
            INV_UpdateTradeAcceptSound(0, 0);
            return;

        case 4:
        case 5:
        case 6:
            INV_UpdateTradeAcceptSound(0, 0);
            gnTradeState = 3;
            return;

        case 1:
            gdwSecondaryTradeGold = 0;
            INV_UpdateTradeAcceptSound(0, 0);
            gnTradeState = 3;
            if (gpTradeWaitDialog)
            {
                DIALOG_DestroyDialog(gpTradeWaitDialog);
                gpTradeWaitDialog = 0;
            }
            return;

        default:
            sub_004B8CB0();
            return;
        }

    case 14:
        INV_SetTradeFlag();
        return;

    case 15:
        INV_ClearTradeFlag();
        return;
    }
}

// 0x004B9060
Unicode* __cdecl MONSTER_GetTradePartnerName()
{
    return gwszTradePartnerName;
}

// 0x004B90F0
int __cdecl MONSTER_GetSecondaryTradeGold()
{
    return gdwSecondaryTradeGold;
}

// 0x004B9100
int __cdecl MONSTER_GetPrimaryTradeGold()
{
    return gdwPrimaryTradeGold;
}


// 0x004B90B0
extern "C" void __cdecl sub_004B90B0_SendState()
{
    sub_00478600_SendPacket(0x4F, 7, 0, 0);
    gPacketState = 3;
}

// 0x004B90D0
void __fastcall sub_004B90D0_SetValue(unsigned long nValue, bool bFirst)
{
    if (bFirst)
    {
        gdwPrimaryTradeGold = nValue;
    }
    else
    {
        gdwSecondaryTradeGold = nValue;
    }
}

// 0x004B9110
void __fastcall sub_004B9110_SendGoldRequest(unsigned long nGold)
{
    if (gnTradeState == 4 || gnTradeState == 5 || gnTradeState == 6)
    {
        MSG_SendShorts(0x4F, 7, 0, 0);
        gnTradeState = 3;
        return;
    }

    const unsigned long nMaxGold = STATLIST_UnitGetStatValue(sub_00463DD0_GetPlayerUnit(), STAT_GOLD, 0);
    if (nGold >= nMaxGold)
    {
        gdwPrimaryTradeGold = nMaxGold;
        MSG_SendShorts(0x4F, 8, nMaxGold >> 0x10, nMaxGold);
    }
    else
    {
        gdwPrimaryTradeGold = nGold;
        MSG_SendShorts(0x4F, 8, nGold >> 0x10, nGold);
    }
}

// 0x004B9180
int __cdecl sub_004B9180_PollWait()
{
    if (gnTradeState == 7)
    {
        if (gdwTradeTimeoutTick != 0xFFFFFFFF && GetTickCount() > gdwTradeTimeoutTick + 30000)
        {
            sub_0048A6A0_ClearHover();
            gnTradeState = 0;
            sub_004B8940_CloseWait(0);
            sub_00477EE0();
            WINMAIN_SetExitApplication(0);
            GAME_SetCinematicExit(1);
            GAME_RequestExit();
        }

        return 1;
    }

    return 0;
}

// 0x004B91F0
void __cdecl sub_004B91F0()
{
    sub_004B8940_CloseWait(0);
}

// 0x004B9010
void __fastcall TEXT_SetNameFromPacket(D2NamePacketStrc* pPacket)
{
    char szName[16];
    memcpy(szName, pPacket->szName, 16);
    szName[15] = 0;
    sub_00526F20_ToUnicode(gwszTradePartnerName, szName, 16);
    gnTradePartnerUnitId = *(int*)pPacket->nValue;
}



#include "gen/data/Source/D2Client/Unknown_004B8720.inc"
