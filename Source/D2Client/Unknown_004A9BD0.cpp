#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2Structs.h"
#include "D2Txt.h"
#include "D2UnitData.h"
#include "D2ClientMenus.h"
#include "D2StormTypes.h"
#include "D2ClientUiRecords.h"
#include "FogApi.h"
#include "D2CommonApi.h"
#include "D2LangApi.h"
#include "StormApi.h"
#include "D2CommonApi2.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }
#define BITARRAY_CHECK(pBytes, nBit) ((pBytes)[(nBit) >> 3] & gdwBitMasks[(nBit) & 7])
struct Unicode;
struct D2HotkeySlotTableStrc;
struct D2SkillsTxt;
struct D2SkillIconStateStrc;
struct D2UiCelFileStrc;
struct D2WeatherLayerStateStrc;
struct D2MonsterDataStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
void __cdecl GAME_ResetMouseState(); // 0x0044DA40

extern D2HotkeySlotTableStrc gtHotkeySlots_007C0300; // 0x007C0300
extern int gbSkillSelectRight; // 0x007C07FC

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern D2SkillIconStateStrc gtHotkeySlots; // 0x007C0300

struct D2WeatherLayerStateStrc
{
    void* apCelFiles[4];
};

void __fastcall ARCHIVE_FreeClientCellFile(void* pCel); // 0x00478A00
extern D2UiCelFileStrc gaPanelCels[7]; // 0x00724BF0
extern D2WeatherLayerStateStrc gtSplashCels; // 0x007A89B0
extern D2WeatherLayerStateStrc gtBubbleCels; // 0x007A893C
extern D2NpcEntryStrc gaNpcEntries[]; // 0x00726850
void __fastcall TEXT_DrawCenteredText(int nLeft, int nY, int nRight, const Unicode* wszText, int nColor); // 0x004A7080
extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260
int __fastcall GAME_GetUnitClassId(D2UnitStrc* pUnit); // 0x00451F60


#include "D2ClientNpcMenu.h"


// 0x004B17A0
void __cdecl sub_004B17A0_ProcessNpcEntries()
{
    for (int i = 0; i < gnNpcEntryCount; ++i)
        NPCMENU_PickNpcChoice(&gaNpcEntries[i]);
    gtNpcMenu.bEntriesProcessed = 1;
}

// 0x004B1D70
int __cdecl sub_004B1D70_FindNpcEntry()
{
    int i = 0;
    int bFound = 0;
    while (i < gnNpcEntryCount && !bFound)
    {
        if (gaNpcEntries[i].nId == gtNpcMenu.nInteractNpcClassId)
            bFound = 1;
        else
            ++i;
    }

    if (bFound == 1)
        return i;
    return 0;
}




