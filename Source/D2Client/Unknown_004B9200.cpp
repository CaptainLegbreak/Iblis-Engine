#include "D2StatIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2ClientGame.h"
#include "D2Unicode.h"
#include "D2ClientUi.h"
#include "D2StormTypes.h"
#include "D2ClientSound.h"

struct D2GSPacketText5EStrc
{
    unsigned char aText[37];
};

struct D2GSPacketSrv5E
{
    unsigned char nHeader;
    D2GSPacketText5EStrc tText;
};

#pragma pack(push, 1)
struct D2UiPacketStrc_004B9210
{
    unsigned char nHeader;
    unsigned short nType;
    unsigned short nArg;
};

#pragma pack(pop)

struct D2CinematicPacketStrc
{
    unsigned char nHeader;
    unsigned char nCinematic;
};

void __fastcall INV_PlayCinematic(int nIndex); // 0x00482EF0

void __fastcall sub_0046B630_FireLevelEvent(int nIndex); // 0x0046B630

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

int gbQuestIntroFlagsReady; // 0x007C0ECC

D2GSPacketText5EStrc gaQuestIntroFlags; // 0x007C0EA4

extern "C" void __fastcall QUESTLOG_SetQuestPacketValue(unsigned int value); // 0x004A3100

void __fastcall NPCMENU_ReloadHirelingPopup(unsigned short nArg); // 0x004B3340

void __fastcall QUESTLOG_AcceptShortPacket(D2UiPacketStrc_004B9210* pPacket); // 0x004A28A0

void __fastcall NPCMENU_OnNpcPacketStoreSubId(D2UiPacketStrc_004B9210* pPacket); // 0x004B25C0

void __fastcall TEXT_AcceptWordPacket(D2UiPacketStrc_004B9210* pPacket); // 0x0049FF60

void __fastcall WINMAIN_SetExitApplication(int nValue); // 0x0044B880

void __fastcall GAME_SetCinematicExit(int nValue); // 0x0044C860

void __cdecl GAME_RequestExit(); // 0x0044D520

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" const char gszEmptyAssertText; // 0x006CC837


// 0x004B9200
void __cdecl sub_004B9200_ResetTable()
{
    gbQuestIntroFlagsReady = 0;
}

// 0x004B9210
void __fastcall sub_004B9210_DispatchUiPacket(D2UiPacketStrc_004B9210* pPacket)
{
    switch (pPacket->nType)
    {
    case 36:
        QUESTLOG_SetQuestPacketValue(pPacket->nArg);
        return;

    case 2:
        NPCMENU_ReloadHirelingPopup(pPacket->nArg);
        return;

    case 1:
        QUESTLOG_AcceptShortPacket(pPacket);
        return;

    case 3:
    case 6:
        NPCMENU_OnNpcPacketStoreSubId(pPacket);
        return;

    case 4:
    case 13:
        TEXT_AcceptWordPacket(pPacket);
        return;

    case 23:
        sub_00477EE0();
        WINMAIN_SetExitApplication(0);
        GAME_SetCinematicExit(1);
        GAME_RequestExit();
        return;
    }
}

// 0x004B92B0
void __fastcall sub_004B92B0_StorePacketText(const D2GSPacketSrv5E* pPacket)
{
    gaQuestIntroFlags = pPacket->tText;
    gbQuestIntroFlagsReady = 1;
}

// 0x004B92D0
int __stdcall sub_004B92D0_IsTableReady(int nUnused)
{
    return gbQuestIntroFlagsReady;
}

// 0x004B9320
void __fastcall sub_004B9320_PlayCinematicFromPacket(const D2CinematicPacketStrc* pPacket)
{
    INV_PlayCinematic(pPacket->nCinematic);
}

// 0x004B9330
void __fastcall sub_004B9330_ForwardByte(const unsigned char* pPacket)
{
    sub_0046B630_FireLevelEvent(pPacket[1]);
}

// 0x004B9340
float __fastcall sub_004B9340_MaxFloat(float fA, float fB)
{
    return fA > fB ? fA : fB;
}

// 0x004B9370
float __fastcall sub_004B9370_MinFloat(float fA, float fB)
{
    return fA < fB ? fA : fB;
}

// 0x004B93A0
float __fastcall sub_004B93A0_ClampFloat(float fValue, float fMin, float fMax)
{
    return sub_004B9370_MinFloat(sub_004B9340_MaxFloat(fValue, fMin), fMax);
}

// 0x004B92E0
int __stdcall INV_GetTableByte(int nUnused, int nIndex)
{
    D2_ASSERT(gbQuestIntroFlagsReady, 0x60);
    D2_ASSERT(nIndex < 0x25, 0x65);
    return gaQuestIntroFlags.aText[nIndex];
}




#include "gen/data/Source/D2Client/Unknown_004B9200.inc"
