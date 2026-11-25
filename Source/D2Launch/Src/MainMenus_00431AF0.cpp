#include "D2Launch.h"
#include "D2MultiTypes.h"
struct D2FileTimeStrc;
struct D2MenuCallbackArgStrc;
struct D2ConfigStrc;

struct Unicode
{
    unsigned short wChar;
};

extern "C" __declspec(dllimport) int __stdcall FindNextFileA(void* hFindFile, D2FindDataStrc* pFindData); // 0x006CC1C8
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileAttributesA(const char* szFileName); // 0x006CC1B0
extern "C" __declspec(dllimport) int __stdcall DeleteFileA(const char* lpFileName); // 0x006CC1A0
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize); // 0x004135D0
const char* __stdcall Name(D2FuncRecordStrc* pRecord, int nIndex); // 0x005180A0
Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320
const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30
void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0
int __fastcall sub_00526800(const Unicode* pString); // 0x00526800
void __fastcall BUTTON_SetText(D2WinControlStrc* pControl, int nMode, Unicode* pText, int nArg); // 0x005009D0
int __stdcall CLIENT_DequeueSystemPacket(unsigned char* pBuffer, unsigned int nBufferSize); // 0x0052A8B0
int __fastcall D2Win_StopMessageLoop(); // 0x004F9190
int __fastcall FOG_CreatePathHierarchy(const char* szPath); // 0x00406A10
int __fastcall WINMAIN_DecodeCdKey(const char* szCdKey, unsigned int* pProduct, unsigned int* pValue); // 0x00449920
extern D2WinControlStrc* gpControl_007795AC; // 0x007795AC
extern int gdwGlobal_00779974; // 0x00779974

void __cdecl MAINMENUS_DestroyControls(); // 0x0042F3F0
D2WinControlStrc* __fastcall MAINMENUS_CreateFromTemplate(int nTemplateId); // 0x0042F3A0
int __fastcall D2Win_10051(D2WinControlStrc* pTextBox, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent); // 0x004FC9B0
Unicode* __fastcall sub_00526790(Unicode* pDest, const Unicode* pSource, int nCount); // 0x00526790
extern int gbFeCharPalette; // 0x007795F0


extern D2ComInterfaceStrc* gpFuncTable_0077ABF0; // 0x0077ABF0
extern int gnCancelled; // 0x0077932C
extern const char gszMainMenus[]; // 0x006D41C0
extern const char gszTextExt[]; // 0x006D48E0
extern const char gszTosPrefix[]; // 0x006D48E8
extern "C" __declspec(dllimport) unsigned long __stdcall GetFileSize(void*, unsigned long*); // 0x006CC2F0
extern "C" unsigned int __cdecl strlen(const char*);
void __cdecl sub_0042F800(); // 0x0042F800
void __stdcall STRTABLE_GetLanguageInfoField(void* pOut, int nField); // 0x00525260
unsigned int __stdcall SStrPack(char*, const char*, unsigned int); // 0x00413800
void __cdecl MAINMENUS_PollDownloadDone(); // 0x00430400
void __stdcall D2Win_RunMessageLoop(D2LaunchDoneFn); // 0x004FA590
void __cdecl MAINMENUS_ShowMainMenu(); // 0x004336C0
void __fastcall MAINMENUS_ShowMessage(const Unicode*, D2LaunchDoneFn, int); // 0x00433380
void __cdecl MAINMENUS_CreateTermsControls(); // 0x00430390
D2WinControlStrc* __fastcall MAINMENUS_CreateControl(int); // 0x0042F430
void* __fastcall FOG_CreateFileA(const char*, unsigned long, unsigned long, void*, unsigned long, unsigned long, void*); // 0x00406960
int __fastcall FOG_ReadFile(void*, void*, unsigned long, unsigned long*, void*); // 0x004069B0
int __fastcall FOG_CloseFile(void*); // 0x004069A0
int __fastcall FOG_DeleteFileA(const char*); // 0x00406990
void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380
int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0
void __fastcall CHARSEL_SwapUnicodeBytes(Unicode*, unsigned int); // 0x0042E5D0
Unicode* __fastcall win2Unicode(Unicode*, const char*, int); // 0x00526F20
int __fastcall D2Win_10121_GetTextWidth(const Unicode*); // 0x00501820
int __fastcall sub_00526D30_IsLineBreak(const Unicode* pText, unsigned int nIndex); // 0x00526D30
void __fastcall D2Win_10053(D2WinControlStrc*, int); // 0x004FBA30

struct D2MenuCallbackArgStrc { D2WinControlStrc* pControl; unsigned int nMessage, nParam, nArg; };

extern D2WinControlStrc* gpClassImages_0077956C[7]; // 0x0077956C
extern D2ConfigStrc* gpLaunchRecord; // 0x007795D4
extern D2WinControlStrc* gpOkButton; // 0x00779330
extern D2WinControlStrc* gpControl_0077933C; // 0x0077933C
extern D2WinControlStrc* gpNameEdit; // 0x0077934C
extern D2WinControlStrc* gpControl_007795B0; // 0x007795B0
extern D2WinControlStrc* gpControl_007795B8; // 0x007795B8
extern D2WinControlStrc* gpControl_007795C4; // 0x007795C4
extern D2WinControlStrc* gpControl_007795CC; // 0x007795CC
int __fastcall MAINMENUS_ShowOptionDescription(unsigned int, int, int, int); // 0x004307A0
int __stdcall MAINMENUS_OnSelectAssassin(D2MenuCallbackArgStrc*); // 0x004308A0
int __stdcall MAINMENUS_OnSelectDruid(D2MenuCallbackArgStrc*); // 0x004308E0
void __stdcall CONTROL_SetFocusedEditBox(D2WinControlStrc*); // 0x004F91C0
void __fastcall CONTROL_SetVisible(D2WinControlStrc*, int); // 0x004F9740
extern "C" int __fastcall D2Win_10106(D2WinControlStrc*); // 0x00500310
int __fastcall D2Win_10104(D2WinControlStrc*); // 0x00500340
extern "C" void __fastcall BUTTON_SetIsPressed(D2WinControlStrc*, int); // 0x005009A0
void __fastcall D2SOUND_10039(const char*); // 0x00514EC0
void __cdecl D2SOUNDFAST_FadeOutWaves(); // 0x00515020

int gdwGlobal_00779990; // 0x00779990

extern "C" char* __cdecl strstr(const char* szString, const char* szSubString);                             // 0x00686900

int __fastcall MAINMENUS_ReadPaletteFiles(const char* szFile1, const char* szFile2); // 0x0042F2E0

char* __fastcall sub_005263E0(char* szDest, const Unicode* pSource, int nMaxLength); // 0x005263E0

void __fastcall sub_004FC9B0_SetText(D2WinControlStrc* pControl, const Unicode* pText, int nA, int nB, int nC); // 0x004FC9B0

unsigned int __stdcall SStrLen(const char* szString);                                                       // 0x00413750

// 0x0042FB20
void __cdecl MAINMENUS_CreateVideoScreen()
{
// build: symbol ?MAINMENUS_Reset@* 0x0042F480
    MAINMENUS_Reset();
// build: symbol ?MAINMENUS_CreateControl@* 0x0042F430
    MAINMENUS_CreateControl(2);
    MAINMENUS_CreateControl(3);
    MAINMENUS_CreateControl(6);
    MAINMENUS_CreateControl(7);
    MAINMENUS_ReadPaletteFiles("palette\\sky\\pal.dat", "palette\\sky\\pal.pl2");
    D2WinControlStrc* pControl = MAINMENUS_CreateControl(4);
    char szTail[0x200] = { 0 };
    char szText[0x200] = { 0 };
    Unicode wszText[0x200];
    wszText[0].wChar = 0;
    for (int i = 1; i < 0x200; i++)
        wszText[i].wChar = 0;
    const char* szKey;
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (FOG_IsExpansion())
    {
        sub_005263E0(szText, D2LANG_GetStringFromTblIndex(0x557A), 0x200);
        szKey = "2001";
    }
    else
    {
        sub_005263E0(szText, D2LANG_GetStringFromTblIndex(0x13F0), 0x200);
        szKey = "2000";
    }
    int nKeyLen = SStrLen(szKey);
    char* pFound = strstr(szText, szKey);
    if (pFound)
    {
        SStrCopy(szTail, pFound + nKeyLen, 0x7FFFFFFF);
        SStrCopy(pFound, "2000 - 2016", 0x7FFFFFFF);
        SStrCopy(pFound + SStrLen("2000 - 2016"), szTail, 0x7FFFFFFF);
    }
    sub_00526320_ToUnicode(wszText, szText, 0x200);
    sub_004FC9B0_SetText(pControl, wszText, 4, 0, 0);
    sub_004FC9B0_SetText(pControl, D2LANG_GetStringFromTblIndex(0x13F1), 4, 0, 0);
    D2Win_10029(0);
// build: symbol ?D2SOUND_GetOptionsMusicOption@* 0x00514D80
    if (D2SOUND_GetOptionsMusicOption())
        D2SOUND_10034(1);
}

// 0x00431AF0
void __cdecl MAINMENUS_ShowCurrentGateway()
{
    D2FuncRecordStrc* pRecord = gpFuncTable_0077ABF0->pfnGetRecord();
    char szText[0x100];
    const int nIndex = pRecord->nIndex;
    SStrCopy(szText, Name(pRecord, nIndex), 0x100);

    Unicode wszText[0x100];
    for (int i = 0; i < 0x100; ++i)
        wszText[i].wChar = 0;
    sub_00526320_ToUnicode(wszText, szText, 0x100);

    Unicode wszFormat[0x100];
    for (int i = 0; i < 0x100; ++i)
        wszFormat[i].wChar = 0;
    sub_005267E0(wszFormat, D2LANG_GetStringFromTblIndex(0x2B29));

    Unicode wszOut[0x100];
    for (int i = 0; i < 0x100; ++i)
        wszOut[i].wChar = 0;
    memset(wszOut, 0, 0x100);
    sub_005269D0(0x100, wszOut, wszFormat, wszText);

    for (int i = 0; i < sub_00526800(wszOut); ++i)
    {
        const unsigned short wChar = wszOut[i].wChar;
// build: symbol ?gawToUpperTable@* 0x00730578
        wszOut[i].wChar = wChar < 0x100 ? gawToUpperTable[wChar] : wChar;
    }

    BUTTON_SetText(gpControl_007795AC, 10, wszOut, 0);
}

// 0x0043C750
void __fastcall MAINMENUS_DeleteCharFiles(const char* szCharName, const char* szSubdirectory)
{
    char szDir[0x104];
    D2FindDataStrc tFind;
    char szTemp[0x104];
    char szPath[500];
    char szMask[500];

    D2_ASSERT(szCharName[0], 0xAF);

// build: symbol ?FOG_GetSavePath@* 0x00407050
    FOG_GetSavePath(szDir, 0x104);
    if (szSubdirectory && szSubdirectory[0])
    {
        SStrPrintf(szTemp, 0x104, "%s%s\\", szDir, szSubdirectory);
        FOG_CreatePathHierarchy(szTemp);
        SStrCopy(szDir, szTemp, 0x104);
    }

    sprintf(szMask, "%s%s.*", szDir, szCharName);
    void* hFind = FindFirstFileA(szMask, &tFind);
    while (hFind != (void*)-1)
    {
        sprintf(szPath, "%s%s", szDir, tFind.cFileName);
        if (GetFileAttributesA(szPath) & 0x10)
        {
            if (!FindNextFileA(hFind, &tFind))
                return;
        }
        else
        {
            if (!DeleteFileA(szPath))
                return;
            hFind = FindFirstFileA(szMask, &tFind);
        }
    }
}

D2LaunchDoneFn gpfnGatewayDone; // 0x007795BC

// 0x004330A0
static int __stdcall MAINMENUS_SetMultilineText(D2WinControlStrc* pControl, int nArg, const Unicode* pText, bool bWrapped)
{
    Unicode aBuffer[0x400];
    for (int i = 0; i < 0x400; ++i)
        aBuffer[i].wChar = 0;
    sub_00526790(aBuffer, pText, 0x400);
    Unicode* pChar = aBuffer;
    Unicode* pLine = pChar;
    while (pChar->wChar)
    {
        if (pChar->wChar == 0xA)
        {
            pChar->wChar = 0;
            D2Win_10051(pControl, pLine, nArg, bWrapped, 0);
            pLine = pChar + 1;
        }
        ++pChar;
    }
    if (pLine < pChar)
        D2Win_10051(pControl, pLine, nArg, bWrapped, 0);
    return 1;
}

// 0x00433130
void __fastcall MAINMENUS_ShowTwoTexts(const Unicode* pText1, const Unicode* pText2, D2LaunchDoneFn pfnDone)
{
    MAINMENUS_DestroyControls();
    D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0xE7);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pOther = MAINMENUS_CreateFromTemplate(0xE8);
    D2Win_10030_CONTROL_ToggleFourthFlag(pOther, 1);
    pControl = MAINMENUS_CreateFromTemplate(0xE9);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    MAINMENUS_SetMultilineText(pControl, 0, pText1, false);
    pControl = MAINMENUS_CreateFromTemplate(0xEA);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    MAINMENUS_SetMultilineText(pControl, 0, pText2, false);
    gpfnGatewayDone = pfnDone;
}

// 0x004331C0
void __fastcall MAINMENUS_ShowThreeTexts(const Unicode* pText1, const Unicode* pText2, const Unicode* pText3, D2LaunchDoneFn pfnDone)
{
    MAINMENUS_DestroyControls();
    D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0xEB);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pOther = MAINMENUS_CreateFromTemplate(0xEC);
    D2Win_10030_CONTROL_ToggleFourthFlag(pOther, 1);
    pControl = MAINMENUS_CreateFromTemplate(0xED);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    MAINMENUS_SetMultilineText(pControl, 0, pText1, false);
    if (pText3 && pText3->wChar)
    {
        pControl = MAINMENUS_CreateFromTemplate(0xEF);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        MAINMENUS_SetMultilineText(pControl, 0, pText2, false);
        pControl = MAINMENUS_CreateFromTemplate(0xF0);
        D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
        MAINMENUS_SetMultilineText(pControl, 4, pText3, false);
        gpfnGatewayDone = pfnDone;
        return;
    }
    pControl = MAINMENUS_CreateFromTemplate(0xEE);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    MAINMENUS_SetMultilineText(pControl, 0, pText2, false);
    gpfnGatewayDone = pfnDone;
}

// 0x004332B0
void __fastcall MAINMENUS_ShowFourTexts(const Unicode* pText1, const Unicode* pText2, const Unicode* pText3, const Unicode* pText4, D2LaunchDoneFn pfnDone)
{
    MAINMENUS_DestroyControls();
    D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0xF1);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pOther = MAINMENUS_CreateFromTemplate(0xF2);
    D2Win_10030_CONTROL_ToggleFourthFlag(pOther, 1);
    pControl = MAINMENUS_CreateFromTemplate(0xF3);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    MAINMENUS_SetMultilineText(pControl, 0, pText1, false);
    pControl = MAINMENUS_CreateFromTemplate(0xF4);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    MAINMENUS_SetMultilineText(pControl, 0, pText2, false);
    pControl = MAINMENUS_CreateFromTemplate(0xF5);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    MAINMENUS_SetMultilineText(pControl, 0, pText3, false);
    pControl = MAINMENUS_CreateFromTemplate(0xF6);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    MAINMENUS_SetMultilineText(pControl, 4, pText4, false);
    gpfnGatewayDone = pfnDone;
}

// 0x00433380
void __fastcall MAINMENUS_ShowMessage(const Unicode* pText, D2LaunchDoneFn pfnDone, int nArg)
{
    D2WinControlStrc* pFrame;
    D2WinControlStrc* pButton;
    D2WinControlStrc* pTextBox;
    MAINMENUS_DestroyControls();
    if (gbFeCharPalette)
    {
        pFrame = MAINMENUS_CreateFromTemplate(0xF7);
        D2Win_10033(pFrame, 1);
        pButton = MAINMENUS_CreateFromTemplate(nArg ? 0xF8 : 0xFA);
        pTextBox = MAINMENUS_CreateFromTemplate(0xF9);
    }
    else
    {
        pFrame = MAINMENUS_CreateFromTemplate(0xDE);
        D2Win_10033(pFrame, 1);
        pButton = MAINMENUS_CreateFromTemplate(nArg ? 0xE1 : 0xDF);
        pTextBox = MAINMENUS_CreateFromTemplate(0xE0);
    }
    D2Win_10030_CONTROL_ToggleFourthFlag(pFrame, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pButton, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pTextBox, 1);
    MAINMENUS_SetMultilineText(pTextBox, 0, pText, false);
    gpfnGatewayDone = pfnDone;
}

// 0x00433460
void __fastcall MAINMENUS_ShowTextBox(const Unicode* pText, D2LaunchDoneFn pfnDone)
{
    MAINMENUS_DestroyControls();
    D2WinControlStrc* pControl = MAINMENUS_CreateFromTemplate(0xF7);
    D2Win_10033(pControl, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    D2WinControlStrc* pOther = MAINMENUS_CreateFromTemplate(0xFA);
    D2Win_10030_CONTROL_ToggleFourthFlag(pOther, 1);
    pControl = MAINMENUS_CreateFromTemplate(0xF9);
    D2Win_10030_CONTROL_ToggleFourthFlag(pControl, 1);
    MAINMENUS_SetMultilineText(pControl, 0, pText, false);
    gpfnGatewayDone = pfnDone;
}

// 0x00435180
void __fastcall MAINMENUS_ShowExpansionMessage(const Unicode* pText, D2LaunchDoneFn pfnDone, int nArg)
{
    MAINMENUS_DestroyControls();
    D2WinControlStrc* pFrame = MAINMENUS_CreateFromTemplate(0xDE);
    D2Win_10033(pFrame, 1);
    D2WinControlStrc* pButton = MAINMENUS_CreateFromTemplate(nArg ? 0xE1 : 0xDF);
    D2WinControlStrc* pTextBox = MAINMENUS_CreateFromTemplate(0xE0);
    D2Win_10030_CONTROL_ToggleFourthFlag(pFrame, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pButton, 1);
    D2Win_10030_CONTROL_ToggleFourthFlag(pTextBox, 1);
    MAINMENUS_SetMultilineText(pTextBox, 0, pText, false);
    gpfnGatewayDone = pfnDone;
}

// 0x00433810
int __cdecl MAINMENUS_ShowTerms()
{
    char szLanguage[128];
    Unicode wszLine[200];
    char szFileName[128];
    gnCancelled = 0;
    sub_0042F800();
    STRTABLE_GetLanguageInfoField(szLanguage, 2);
    SStrCopy(szFileName, gszTosPrefix, 128);
    SStrPack(szFileName, szLanguage, 128);
    SStrPack(szFileName, gszTextExt, 128);
    gpFuncTable_0077ABF0->pfnRequest(szFileName, strlen(szFileName));
    D2Win_RunMessageLoop(MAINMENUS_PollDownloadDone);
    if (gnCancelled) { MAINMENUS_DestroyControls(); return 0; }
    if (!gpFuncTable_0077ABF0->pfnSlot68())
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x14E3);
        MAINMENUS_ShowMessage(pMessage, MAINMENUS_ShowMainMenu, 1);
        return 0;
    }
    MAINMENUS_DestroyControls();
    MAINMENUS_CreateTermsControls();
    MAINMENUS_CreateControl(0x4D);
    D2WinControlStrc* pText = MAINMENUS_CreateControl(0x4E);
    void* hFile = FOG_CreateFileA(szFileName, 0x80000000, 0, 0, 3, 0x08000000, 0);
    if (hFile == (void*)-1)
    {
        const Unicode* pMessage = D2LANG_GetStringFromTblIndex(0x14E3);
        MAINMENUS_ShowMessage(pMessage, MAINMENUS_ShowMainMenu, 1);
        return 0;
    }
    unsigned long nSize = GetFileSize(hFile, 0);
    void* pBuffer = FOG_Alloc(nSize, gszMainMenus, 0xC4D, 0);
    unsigned long nRead;
    FOG_ReadFile(hFile, pBuffer, nSize, &nRead, 0);
    FOG_CloseFile(hFile);
    FOG_DeleteFileA(szFileName);
    Unicode* pChars = 0;
    int nCount;
    if (nSize == nRead && nSize > 2)
    {
        if (*(unsigned short*)pBuffer == 0xFEFF)
        {
            pChars = (Unicode*)pBuffer + 1;
            nCount = (nSize - 2) / 2;
        }
        else if (*(unsigned short*)pBuffer == 0xFFFE)
        {
            pChars = (Unicode*)pBuffer + 1;
            nCount = (nSize - 2) / 2;
            CHARSEL_SwapUnicodeBytes(pChars, nCount);
        }
        else
        {
            pChars = (Unicode*)FOG_Alloc(2*nSize+1, gszMainMenus, 0xC6B, 0);
            win2Unicode(pChars, (const char*)pBuffer, nSize);
            FOG_Free(pBuffer, gszMainMenus, 0xC6D, 0);
            pBuffer = pChars;
            nCount = nSize;
        }
    }
    else nCount = 0;
    int nStart = 0;
    int i = 0;
    while (i < nCount)
    {
        memset(wszLine, 0, sizeof(wszLine));
        int nLine = 0;
        do
        {
            if (i >= nCount) break;
            const unsigned short nChar = pChars[i].wChar;
            if (nChar == '\r' || nChar == '\n') { wszLine[nLine].wChar = ' '; nLine = 200; ++i; }
            else if (nChar != '\t') { wszLine[nLine++].wChar = nChar; ++i; }
            else { ++i; wszLine[nLine++].wChar = ' '; }
            if (D2Win_10121_GetTextWidth(wszLine) > 540)
            {
                int nLength = sub_00526800(wszLine);
                while (nLength > 1 && !sub_00526D30_IsLineBreak(pChars + nStart, nLength)) --nLength;
                i = nStart + nLength;
                wszLine[nLength].wChar = 0;
                if (nLength && wszLine[nLength - 1].wChar == ' ') wszLine[nLength - 1].wChar = 0;
                break;
            }
        } while (nLine < 200);
        int nLength = sub_00526800(wszLine);
        for (int j = 0; j < nLength; ++j)
        {
            if (wszLine[j].wChar != ' ')
            {
                D2Win_10051(pText, wszLine, 0, 0, 0);
                break;
            }
        }
        nStart = i;
    }
    FOG_Free(pBuffer, gszMainMenus, 0xCB4, 0);
    D2Win_10053(pText, 0);
    MAINMENUS_CreateControl(0x4F);
    MAINMENUS_CreateControl(0x50);
    pText = MAINMENUS_CreateControl(0x51);
    D2Win_10051(pText, D2LANG_GetStringFromTblIndex(0x143C), 0, 0, 0);
    MAINMENUS_CreateControl(0x52);
    MAINMENUS_CreateControl(0x53);
    return 1;
}

#include "gen/data/Source/D2Launch/Src/MainMenus_00431AF0.inc"

D2WinControlStrc* gpControl_00779348; // 0x00779348

D2WinControlStrc* gpControl_00779568; // 0x00779568

D2WinControlStrc* gpControl_00779598; // 0x00779598

D2WinControlStrc* gpControl_007795B4; // 0x007795B4

D2WinControlStrc* gpControl_007795C8; // 0x007795C8

// 0x00431E70
static void MAINMENUS_SetModeFlags(char nMode)
{
    gpLaunchRecord->nMode = nMode;
    gpLaunchRecord->bAmazon = 0;
    gpLaunchRecord->bBarbarian = 0;
    gpLaunchRecord->bNecromancer = 0;
    gpLaunchRecord->bPaladin = 0;
    gpLaunchRecord->bSorceress = 0;
    gpLaunchRecord->bDruid = 0;
    gpLaunchRecord->bAssassin = 0;
    if (nMode == 0) gpLaunchRecord->bAmazon = 1;
    else if (nMode == 4) gpLaunchRecord->bBarbarian = 1;
    else if (nMode == 2) gpLaunchRecord->bNecromancer = 1;
    else if (nMode == 3) gpLaunchRecord->bPaladin = 1;
    else if (nMode == 1) gpLaunchRecord->bSorceress = 1;
    else if (nMode == 5) gpLaunchRecord->bDruid = 1;
    else if (nMode == 6) gpLaunchRecord->bAssassin = 1;
}

// 0x00433BF0
int __stdcall MAINMENUS_SelectCharacterClass(D2MenuCallbackArgStrc* pArg)
{
    int nImageState = D2Win_10106(pArg->pControl);
// build: symbol ?FOG_IsExpansion@* 0x00408F20
    if (FOG_IsExpansion())
    {
        for (int i = 0; i < 7; ++i)
            if (!D2Win_10104(gpClassImages_0077956C[i])) return 0;
    }
    else
    {
        for (int i = 0; i < 5; ++i)
            if (!D2Win_10104(gpClassImages_0077956C[i])) return 0;
    }
// build: symbol ?gnTextSentinel@* 0x0070CB80
    int nPreviousClass = gnTextSentinel;
    int nClass = -1;
    gnTextSentinel = -1;
    if (nPreviousClass != -1)
    {
        D2SOUNDFAST_FadeOutWaves();
        switch (nPreviousClass)
        {
        case 0: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\amazon deselect.wav"); break;
        case 4: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\barbarian deselect.wav"); break;
        case 3: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\paladin deselect.wav"); break;
        case 2: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\necromancer deselect.wav"); break;
        case 1: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\sorceress deselect.wav"); break;
        case 5: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\druid deselect.wav"); break;
        case 6: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\assassin deselect.wav"); break;
        }
    }
    if (pArg->pControl == gpClassImages_0077956C[0])
    {
        nClass = 4;
        MAINMENUS_ShowOptionDescription(pArg->nArg, 4, 0xFA7, 0x140A);
    }
    else if (pArg->pControl == gpClassImages_0077956C[1])
    {
        nClass = 2;
        MAINMENUS_ShowOptionDescription(pArg->nArg, 2, 0xFA9, 0x1409);
    }
    else if (pArg->pControl == gpClassImages_0077956C[2])
    {
        nClass = 0;
        MAINMENUS_ShowOptionDescription(pArg->nArg, 0, 0xFAB, 0x1408);
    }
    else if (pArg->pControl == gpClassImages_0077956C[3])
    {
        nClass = 1;
        MAINMENUS_ShowOptionDescription(pArg->nArg, 1, 0xFAA, 0x140B);
    }
    else if (pArg->pControl == gpClassImages_0077956C[4])
    {
        nClass = 3;
        MAINMENUS_ShowOptionDescription(pArg->nArg, 3, 0xFA8, 0x140C);
    }
    else if (pArg->pControl == gpClassImages_0077956C[5])
    {
        nClass = 5;
        MAINMENUS_OnSelectDruid(pArg);
    }
    else if (pArg->pControl == gpClassImages_0077956C[6])
    {
        nClass = 6;
        MAINMENUS_OnSelectAssassin(pArg);
    }
    if (nClass != nPreviousClass && nImageState == 1)
    {
        switch (nClass)
        {
        case 0: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\amazon select.wav"); break;
        case 4: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\barbarian select.wav"); break;
        case 3: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\paladin select.wav"); break;
        case 2: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\necromancer select.wav"); break;
        case 1: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\sorceress select.wav"); break;
        case 6: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\assassin select.wav"); break;
        case 5: D2SOUND_10039("data\\global\\sfx\\cursor\\intro\\druid select.wav"); break;
        }
        gnTextSentinel = nClass;
    }
    else if (nImageState != 2 && nImageState != 3 && nImageState != 4)
        gnTextSentinel = nClass;
    MAINMENUS_SetModeFlags((char)gnTextSentinel);
    if (gnTextSentinel == -1 && nImageState != 1)
    {
        CONTROL_SetVisible(gpControl_00779598, 0);
        CONTROL_SetVisible(gpControl_007795CC, 0);
        CONTROL_SetVisible(gpControl_007795B0, 0);
        CONTROL_SetVisible(gpControl_007795C4, 0);
        CONTROL_SetVisible(gpNameEdit, 0);
        CONTROL_SetVisible(gpOkButton, 0);
// build: symbol ?gnLaunchMode@* 0x007795EC
        if (gnLaunchMode == 1)
        {
            CONTROL_SetVisible(gpControl_007795B8, 0);
            CONTROL_SetVisible(gpControl_00779348, 0);
        }
        if (FOG_IsExpansion())
        {
            CONTROL_SetVisible(gpControl_00779568, 0);
            CONTROL_SetVisible(gpControl_007795C8, 0);
            CONTROL_SetVisible(gpControl_007795B4, 0);
        }
        CONTROL_SetFocusedEditBox(0);
        if (gnLaunchMode == 1) CONTROL_SetVisible(gpControl_0077933C, 1);
    }
    else
    {
        CONTROL_SetVisible(gpControl_00779598, 1);
        CONTROL_SetVisible(gpControl_007795CC, 1);
        if (gdwGlobal_00779DA4)
        {
            CONTROL_SetVisible(gpControl_007795B0, 1);
            CONTROL_SetVisible(gpControl_007795C4, 1);
        }
        if (gnLaunchMode == 1)
        {
            CONTROL_SetVisible(gpControl_007795B8, 1);
            CONTROL_SetVisible(gpControl_00779348, 1);
        }
        CONTROL_SetVisible(gpNameEdit, 1);
        CONTROL_SetFocusedEditBox(gpNameEdit);
        CONTROL_SetVisible(gpOkButton, 1);
        if (gnLaunchMode == 1) CONTROL_SetVisible(gpControl_0077933C, 0);
    }
    if (FOG_IsExpansion())
    {
        if (gnTextSentinel == 6 || gnTextSentinel == 5)
        {
            CONTROL_SetVisible(gpControl_00779568, 1);
            CONTROL_SetVisible(gpControl_007795C8, 0);
            CONTROL_SetVisible(gpControl_007795B4, 1);
            gpLaunchRecord->wFlags1EF |= 0x20;
        }
        else if (gnTextSentinel != -1)
        {
            CONTROL_SetVisible(gpControl_00779568, 1);
            CONTROL_SetVisible(gpControl_007795C8, 1);
            CONTROL_SetVisible(gpControl_007795B4, 0);
            BUTTON_SetIsPressed(gpControl_007795C8, 1);
            gpLaunchRecord->wFlags1EF |= 0x20;
        }
    }
    if (gnLaunchMode == 1)
    {
        BUTTON_SetIsPressed(gpControl_00779348, 1);
        gpLaunchRecord->wFlags1EF |= 0x40;
    }
    return 1;
}
