#include "D2Multi.h"
#include "D2StormTypes.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Drlg.h"
#include "D2LevelTxt.h"

#include "D2Unicode.h"

#include "D2MultiTypes.h"
#include "D2LaunchRequest.h"
#include "FogApi.h"
#include "D2LangApi.h"
#include "D2WinApi.h"

extern int gnChatLaunchMode; // 0x0077BBE4


#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2WinTextBoxStrc;

struct Unicode;

struct D2ConfigStrc;

struct D2GameListRecordStrc;

struct D2LaunchFuncsStrc;


void __fastcall D2Win_10044(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FD060

extern D2WinControlInitStrc gtHelpBckgImageInit; // 0x0070E9E0

extern D2WinControlInitStrc gtControlInit_0070EA10; // 0x0070EA10

extern D2WinControlInitStrc gtControlInit_0070EA40; // 0x0070EA40

extern D2WinControlInitStrc gtControlInit_0070EA70; // 0x0070EA70


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

#pragma pack(push, 1)

struct D2GameListRecordStrc
{
    char szName[0x10];
    char szDesc[0x22];
    unsigned short wType;
    char unk0x34[2];
    unsigned int f_36;
    char unk0x3A;
};

#pragma pack(pop)

extern D2LaunchFuncsStrc* gpLaunchFuncs; // 0x0077B09C

extern D2ConfigStrc* gpCharInfo; // 0x0077BBD8

extern D2GameListRecordStrc gtGameList_0077BDC9[]; // 0x0077BDC9

int __fastcall CHATDLG_IsCharOverLimit(const char* szText); // 0x00442B20




void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0

extern D2WinControlStrc* gpLevelDiffLabel; // 0x00798C04

extern D2WinControlStrc* gpControl_00798C08; // 0x00798C08

extern D2WinControlStrc* gpLevelDiffUpButton; // 0x00798C1C

extern D2WinControlStrc* gpLevelDiffDownButton; // 0x00798C20

extern D2WinControlStrc* gpLevelDiffGreyArrows; // 0x00798C24

extern D2WinControlStrc* gpLevelDiffEdit; // 0x00798C3C

extern D2WinControlStrc* gpLevelDiffCheck; // 0x00798C40

extern D2WinControlStrc* gpLevelDiffBoxImage; // 0x00798C44

D2WinControlStrc* gpControl_00798CB0; // 0x00798CB0

D2WinControlStrc* gpControl_00798CB4; // 0x00798CB4

D2WinControlStrc* gpControl_00798CB8; // 0x00798CB8

D2WinControlStrc* gpHelpBckgImage; // 0x00798CBC

int gfGameListControlsCreated; // 0x00798CC0

// build: symbol ?CHATDLG_ResetLaunchState@* 0x0043F8C0
// build: symbol ?GAME_IsLaunchExpansion@* 0x0043DB10
// build: symbol ?gszSpace@* 0x006FFC44

extern "C" const unsigned char gData_006FFC46[18] = { // 0x006FFC46
    0x00, 0x00, 0x25, 0x2A, 0x73, 0x00, 0x20, 0x25, 0x73, 0x2B, 0x25, 0x6C, 0x6C, 0x75, 0x00, 0x00,
    0x00, 0x00
};
#include "D2MCPClientApi.h"

extern int gnGameCount; // 0x00798CCC

static inline int sub_00444E70_HasProgress(unsigned short wFlags, unsigned int nClassic, unsigned int nExpansion)
{
    if (wFlags & 0x20)
        return (wFlags & 0x1F00u) >= nExpansion;
    return (wFlags & 0x1F00u) >= nClassic;
}

static inline char* sub_00444E70_NextString(char* p)
{
    D2_ASSERT(p, 0xAD);
    while (*p)
        ++p;
    return p + 1;
}

// build: symbol ?gpGameList@* 0x00798BC0
// build: symbol ?CHATDLG_FillGameListControl@* 0x00442C20
void __cdecl CHATDLG_FillGameList(); // 0x00444E70

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern unsigned short gwSavedRequestId; // 0x0077BBDC

// 0x00445020
void __cdecl CHARSEL_RequestGameList()
{
// build: symbol ?gnChatLaunchMode@* 0x0077BBE4
    gnChatLaunchMode = 3;
    gnGameCount = 0;
// build: symbol ?gpCharInfo@* 0x0077BBD8
    if (gpCharInfo->nStartMode == 2)
    {
        D2LaunchRequestStrc tRequest;
        memset(&tRequest, 0, sizeof(tRequest));
        if (gpCharInfo->aFlags1EF[0] & 4)
            tRequest.dwFlags |= 0x800;
        while (++gwRequestId == 0)
        {
        }
        WINMAIN_SendMcpGameListRequest(&tRequest, gwRequestId);
        gwSavedRequestId = gwRequestId;
    }
    else
    {
        CHATDLG_FillGameList();
    }
}

// build: symbol ?CHATDLG_UpdateJoinButtonState@* 0x004437E0

// build: symbol ?CONTROL_SetEnabled@* 0x004F96F0
