#pragma once
// D2Win's exports that the other modules call; included only by the units that use it.

struct D2CelFileStrc;
struct D2SplittedTextStrc;
struct D2WinControlStrc;
struct D2WinEditBoxStrc;
struct D2WinSmackStrc;
struct D2WinTextBoxStrc;
struct Unicode;

void __fastcall WINDOW_SetScreenBuffer(unsigned char* pBuffer, int nWidth, int nHeight, int nArg4); // 0x004F8DE0
void __cdecl WINDOW_LoadGammaSettings(); // 0x004F8EA0
int __cdecl D2Win_10003(); // 0x004F9050
void __stdcall D2Win_10004(int nResolution); // 0x004F9060
void __fastcall CONTROL_SetEnabled(D2WinControlStrc* pControl, int nFlags); // 0x004F96F0
void __stdcall D2Win_10029(int bDrawCursor); // 0x004FA410
void __stdcall D2Win_10030_CONTROL_ToggleFourthFlag(D2WinControlStrc* pControl, int bSet); // 0x004FA420
void __cdecl ARCHIVE_UnloadExpansionArchives(); // 0x004FAD70
int __fastcall D2Win_10051(D2WinTextBoxStrc* ptTextData, const Unicode* wszText, int nColor, char bIsWrapped, int nIndent); // 0x004FC9B0
int __fastcall D2Win_10058(D2WinControlStrc* pControl, const Unicode* pText, int nLineNum, int nColumn); // 0x004FCD90
void __fastcall D2Win_10044(D2WinControlStrc* pControl, const Unicode* pText); // 0x004FD060
const Unicode* __fastcall D2Win_10077_EDITBOX_GetText(D2WinEditBoxStrc* pEditBox); // 0x004FDD90
int __fastcall EDITBOX_SetText(D2WinEditBoxStrc* pEditBox, const Unicode* pText); // 0x004FF5A0
int __fastcall D2Win_10123(const Unicode* wszText, int nTextLength); // 0x00501730
int __fastcall D2Win_10121_GetTextWidth(const Unicode* wszText); // 0x00501820
void __fastcall D2WINFONT_DrawClippedFontText(const Unicode* pText, int nX, int nY, int nTextColor, int nSkipLines, int nDrawLines); // 0x00501DF0
void __fastcall D2Win_10129_DrawFramedText(const Unicode* wszText, int nX, int nY, int nTextColor, int nAlign); // 0x00502280
void __fastcall D2Win_10130_DrawFramedTextEx(const Unicode* wszText, int nX, int nY, int nTextColor, int nAlign, int nRectangleColor); // 0x005022F0
void __fastcall D2Win_10117_DrawText(const Unicode* wszText, int nX, int nY, int nColor, int bCentered); // 0x00502320
void __fastcall D2Win_10132(const Unicode* wszText, int nX, int nY, unsigned int dwColor, int eDrawMode, int nColor); // 0x005023B0
void __fastcall D2Win_10131_GetTextDimensions(const Unicode* pText, int* pWidth, int* pHeight); // 0x00502520
void __fastcall D2Win_10200(D2SplittedTextStrc* pLines); // 0x005028A0
D2SplittedTextStrc* __fastcall D2WINFONT_SplitText(const Unicode* wszText, int* pLineCount, int nWidth); // 0x00502970
int __stdcall SMACK_Decode(D2WinSmackStrc* pSmack, const char* szFileName, int nVersion); // 0x00506910
int __stdcall SMACK_DeleteFile(D2WinSmackStrc* pSmack); // 0x00506990
extern int gnViewMatrixAdjust; // 0x007C8CC4
extern int gbIsMouseButtonPressed; // 0x007D55E0
extern D2CelFileStrc* sghPentagram; // 0x0087E96C
