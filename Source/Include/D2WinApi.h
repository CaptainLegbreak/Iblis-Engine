#pragma once
// D2Win's exports that the other modules call: controls, fonts, text and the window.

struct Character;
struct D2CelFileStrc;
struct D2CompositeUnitStrc;
struct D2WinAnimImageStrc;
struct D2WinButtonStrc;
struct D2WinControl004FBB30Strc;
struct D2WinControl004FD110Strc;
struct D2WinControlInitStrc;
struct D2WinControlStrc;
struct D2WinEditBoxStrc;
struct D2WinImageStrc;
struct D2WinTextBoxStrc;
struct D2WinTimerStrc;
struct Obj004FA490;
struct tagRECT;

extern "C" void __cdecl sub_004F8DC0_InitLookupTable(); // 0x004F8DC0
int __stdcall D2Win_InitializeSpriteCache(int bWindowed, int nResolution); // 0x004F8F10
int __fastcall D2Win_10015(); // 0x004F8FE0
int __stdcall D2Win_CloseSpriteCache(); // 0x004F9030
int __stdcall D2Win_10005(int nResolution); // 0x004F90A0
void __stdcall D2Win_10006_ClearDrawCaches(); // 0x004F9130
int __stdcall BACKGROUND_SetCellFile(D2CelFileStrc* pCellFile); // 0x004F9140
int __stdcall CURSOR_SetCellFile(D2CelFileStrc* pCellFile); // 0x004F9160
int __fastcall D2Win_StopMessageLoop(); // 0x004F9190
int __stdcall CONTROL_SetCellFile(D2WinControlStrc* pControl, D2CelFileStrc* pCellFile); // 0x004F91A0
int __stdcall CONTROL_SetFocusedEditBox(D2WinEditBoxStrc* pEditBox); // 0x004F91C0
int __stdcall CONTROL_RemoveFromList(D2WinControlStrc* pControl); // 0x004F9310
D2WinControlStrc* __stdcall CONTROL_Create(D2WinControlInitStrc* pControlInit); // 0x004F93C0
int __stdcall CONTROL_Destroy(D2WinControlStrc** ppControl); // 0x004F95C0
void __fastcall CONTROL_SetVisible(D2WinControlStrc* pControl, int bSet); // 0x004F9740
int __stdcall CONTROL_MouseInsideRect(const tagRECT* pRect); // 0x004F97B0
void __stdcall D2Win_UpdateAndDraw(); // 0x004F98E0
void __stdcall CONTROL_SetEscapeButton(void* pButton); // 0x004FA450
int __stdcall D2Win_10033(D2WinControlStrc* pControlList, int bDimBehind); // 0x004FA470
extern "C" unsigned int __stdcall CONTROL_GetType(Obj004FA490* pObj); // 0x004FA490
int __stdcall D2Win_CreateWindow(void* hInstance, int nRenderMode, int bWindowed, int bCompress); // 0x004FA520
int __fastcall D2Win_10016(); // 0x004FA550
D2CelFileStrc* __fastcall ARCHIVE_LoadCellFile(const char* szFile, int nType); // 0x004FA9B0
void __fastcall ARCHIVE_FreeCellFile(D2CelFileStrc* pCellFile); // 0x004FAAE0
int __cdecl ARCHIVE_ShowInsertExpansionDiscMessage(); // 0x004FAB00
int __cdecl ARCHIVE_ShowInsertPlayDiscMessage(); // 0x004FAB30
int __cdecl ARCHIVE_LoadArchives(); // 0x004FAB90
void* __stdcall D2Win_GetArchive(); // 0x004FAC80
int __cdecl D2Win_10185_CheckCharMpq(); // 0x004FAC90
int __fastcall ARCHIVE_LoadVideoArchives(void* pfShowMessage, void* hFile, int bExpansion); // 0x004FAD10
void __cdecl ARCHIVE_FreeArchives(); // 0x004FAE00
unsigned char* __fastcall D2Win_10175_GetPL2Shift(int nIndex); // 0x004FB0C0
unsigned char __stdcall PALETTE_FindPaletteIndex(unsigned char nRed, unsigned char nGreen, unsigned char nBlue); // 0x004FB180
int __fastcall D2Win_10177(unsigned char nAct); // 0x004FB480
int __stdcall D2Win_10028(const char* pszPalDatFilename, const char* pszPalPL2Filename); // 0x004FB500
void __fastcall TEXTBOX_SetSmallGap(int nValue); // 0x004FB590
int __fastcall D2Win_10047(D2WinTextBoxStrc* ptTextData); // 0x004FB6A0
int __fastcall D2Win_10062(D2WinTextBoxStrc* ptTextData, int nWrappedLineGap, int nLineGap); // 0x004FB740
void __fastcall D2Win_10197(D2WinTextBoxStrc* pTextBox, int nLineNum); // 0x004FB870
int __fastcall D2Win_10052_TEXTBOX_GetNumLines(D2WinTextBoxStrc* ptTextData); // 0x004FB910
int __fastcall D2Win_10054(D2WinTextBoxStrc* ptTextData); // 0x004FB950
int __fastcall D2Win_10049(D2WinTextBoxStrc* ptTextData); // 0x004FB990
void __fastcall D2Win_10050_TEXTBOX_SetLine(D2WinTextBoxStrc* ptTextData, int nLine); // 0x004FB9D0
void* __fastcall D2Win_10048(D2WinControl004FBB30Strc* pControl); // 0x004FBB30
void __fastcall D2Win_10060(D2WinTextBoxStrc* ptTextData, int nColumn, int nAlignFlags); // 0x004FBCD0
int __fastcall D2Win_10061(D2WinTextBoxStrc* ptTextData); // 0x004FBD20
int __fastcall D2Win_10191(D2WinTextBoxStrc* ptTextData, int nMaxSteps); // 0x004FC5E0
int __fastcall D2Win_10192(D2WinTextBoxStrc* ptTextData); // 0x004FC620
int __fastcall D2Win_10193(D2WinTextBoxStrc* ptTextData, int nCurrentStep); // 0x004FC660
int __fastcall D2Win_10194(D2WinTextBoxStrc* ptTextData, D2WinTextBoxStrc* pLinkedTextBox); // 0x004FC6A0
void __fastcall D2Win_10204(D2WinTextBoxStrc* ptTextData, int nPosition); // 0x004FC720
int __fastcall D2Win_10057(D2WinControlStrc* pControl, const char* szText, int nLineNum, int nColumn); // 0x004FCD40
void __fastcall D2Win_10045(D2WinControlStrc* pControl, const char* szText); // 0x004FCF80
void __fastcall D2Win_10046(D2WinControlStrc* pTextBox, const char* szText, int nColor); // 0x004FCFF0
int __stdcall IMAGE_SetCoordinates(D2WinImageStrc* ptImageData, int nX, int nY); // 0x004FD0B0
int __stdcall IMAGE_SetFrame(D2WinControl004FD110Strc* pControl, int nFrame); // 0x004FD110
int __stdcall IMAGE_ForceNormalDrawMode(D2WinImageStrc* ptImageData, int nUnused); // 0x004FD170
int __stdcall IMAGE_GetFrameCount(D2WinImageStrc* ptImageData); // 0x004FD1B0
void __fastcall TIMER_DisableSpaceKey(D2WinTimerStrc* ptTimerData); // 0x004FD830
void __fastcall TIMER_SetRepeating(D2WinTimerStrc* ptTimerData); // 0x004FDA50
void __fastcall EDITBOX_SetKeyFilter(D2WinEditBoxStrc* ptEditData, void* pfKeyFilter); // 0x004FDAD0
void __fastcall EDITBOX_SetChangeCallback(D2WinEditBoxStrc* ptEditData, void* pfOnChange); // 0x004FDB00
int __stdcall D2Win_10078_IsNumber(void* unused1,void* unused2,const Character* text); // 0x004FE770
int __fastcall D2Win_10076(D2WinControlStrc* pControl, const char* szText); // 0x004FFE10
extern "C" int __fastcall D2Win_10106(D2WinAnimImageStrc* ptAnim); // 0x00500310
int __fastcall D2Win_10104(D2WinAnimImageStrc* ptAnim); // 0x00500340
int __stdcall ANIMIMAGE_SetIsRunning(D2WinAnimImageStrc* ptAnim, int bIsRunning); // 0x00500810
int __fastcall BUTTON_IsPressed(D2WinButtonStrc* ptBtnData); // 0x00500960
extern "C" void __fastcall BUTTON_SetIsPressed(D2WinButtonStrc* ptBtnData, int bIsPressed); // 0x005009A0
void __fastcall BUTTON_SetCoordinates(D2WinButtonStrc* ptBtnData, int nX, int nY, int nWidth, int nHeight); // 0x00500A70
extern "C" void __fastcall BUTTON_SetBaseFrame(D2WinButtonStrc* ptBtnData, int nValue); // 0x00500B20
void __fastcall BUTTON_SetStringId(D2WinButtonStrc* pButton, int nStringId); // 0x00500BF0
void __stdcall D2Win_10116(); // 0x005015F0
int __stdcall D2Win_10125(); // 0x00501A40
unsigned int __fastcall D2Win_10128(unsigned char nCharCode); // 0x00502550
void __fastcall D2Win_10134_DrawCellFile(D2CelFileStrc* pCell, int nX, int nY, int nAlign, int eDrawMode, int nShift); // 0x00502680
int __fastcall D2Win_10127_SetFont(int nFontSize); // 0x00502EF0
void __stdcall D2Win_10124(); // 0x00503000
void __stdcall D2Win_10142_CompUnitDestroy(D2CompositeUnitStrc* pCompositeUnit, int bUnlink); // 0x005041B0
int __fastcall D2Win_10143(D2CompositeUnitStrc* pCompositeUnit, int nMode); // 0x005042F0
void __stdcall D2Win_10159(D2CelFileStrc* pSquelchCelFile, D2CelFileStrc* pSelectedCelFile); // 0x00504D30
void __stdcall D2Win_10146(); // 0x00505100
void __stdcall D2Win_10149(D2CompositeUnitStrc* ptUnit, unsigned char nValue); // 0x005051A0
void __stdcall D2Win_10151(D2CompositeUnitStrc* ptUnit, int nFrame); // 0x00505260
void __stdcall D2Win_10152(D2CompositeUnitStrc* ptUnit, int nX); // 0x005052B0
void __stdcall D2Win_10153(D2CompositeUnitStrc* ptUnit, int nY); // 0x005052F0
unsigned int __stdcall D2Win_10155(D2CompositeUnitStrc* hCompositeUnit); // 0x00505330
void __stdcall D2Win_10156(D2CompositeUnitStrc* hCompositeUnit, int nFlags); // 0x00505360
const char* __stdcall D2Win_10160_GetPlayerTitle(int nClass, int nTitle, int bExpansion); // 0x00505640
D2CompositeUnitStrc* __stdcall D2COMP_CreateCompositeUnit(unsigned int nUnitIndex, unsigned int nMode, unsigned char* pComponents, const unsigned char* pComponentColors); // 0x005066C0
const char* __stdcall D2Win_10161(int nClass, int nLevel, int bExpansion, int bSoftCore); // 0x005068A0
