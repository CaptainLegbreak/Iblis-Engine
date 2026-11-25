#include "D2Win32Types.h"








#include "D2GameTypes.h"

#include "D2Win.h"

#include "D2Records.h"

#include "D2CmpTypes.h"

#include "D2Unicode.h"

#include "D2ItemTypes.h"

#include "D2Txt.h"

#include "D2WinTypes.h"

#include "D2WinControls.h"

#include "D2StormTypes.h"

#include "D2TxtTables.h"
#include "D2WinPopupLine.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define COF_PAD 0x20

#define TOKEN_CHAR(c) ((char)(c) == COF_PAD ? 0 : (char)(c))

#define REMAP_COMPONENT(pComponent, nFallback)                                                              \
    {                                                                                                       \
        const int nItems = gnItems;                                                                \
        int nItem = 0;                                                                                      \
        for (; nItem < nItems; ++nItem)                                                                     \
        {                                                                                                   \
            if (gaItems[nItem].dwCode == gaCompItems[*(pComponent)].dwCode)               \
            {                                                                                               \
                *(pComponent) = (unsigned char)nItem;                                                       \
                break;                                                                                      \
            }                                                                                               \
        }                                                                                                   \
        if (nItem >= nItems)                                                                                \
        {                                                                                                   \
            *(pComponent) = (unsigned char)(nFallback);                                                     \
        }                                                                                                   \
    }

struct D2BinFieldStrc;

struct D2BinFileStrc;

struct D2CofDataStrc;

struct D2CofNodeStrc;

struct D2CofInfoStrc;

struct D2GfxInfoStrc;

struct D2CompositeUnitStrc;

struct D2CompItemStrc;

struct Unicode;

struct D2GfxDataStrc
{
    int nFrame;
    unsigned char unk0x04;
    unsigned char nComponent;
    unsigned char unk0x06[2];
    int nUnitType;
    int nUnitIndex;
    unsigned int nMode;
    int unk0x14;
    unsigned int dwUnitToken;
    unsigned int dwComponentToken;
    unsigned int dwArmorType;
    unsigned int dwModeToken;
    unsigned int dwWClassToken;
    int unk0x2C[2];
    D2CelFileStrc* pCelFile;
    int nDrawFlag;
    D2CelStrc* pCel;
    int nDirection;
    unsigned int dwFlags;
};

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void __stdcall TEXTURE_CelDraw(D2GfxDataStrc* pData, int nXPos, int nYPos, unsigned int dwGamma, int eDrawMode, unsigned char* pPalette); // 0x004F6480

int __fastcall D2Win_10143(D2CompositeUnitStrc* pCompositeUnit, int nMode); // 0x005042F0

void __stdcall D2COMP_InitCompItems(); // 0x00506000

extern unsigned int gdwBitMasks[]; // 0x006CE268

extern D2CompItemStrc gaCompItems[]; // 0x0072E1E0

D2CompItemStrc gaItems[255]; // 0x0087D838

int gaItemWeaponClass[254]; // 0x0087E430

D2CompositeUnitStrc* gpCompositeUnitList;                                                          // 0x0087E838

static D2CofNodeStrc* gpCofNodeList; // 0x0087E83C

unsigned int gdwNextFrameTick; // 0x0087E840

D2CelFileStrc* ghSquelchCelFile; // 0x0087E844

int gnSquelchCelFileFrameCount; // 0x0087E848

int gnSquelchCelFileFrame; // 0x0087E84C

D2CelFileStrc* ghSelectedCelFile; // 0x0087E850

int gnSelectedCelFileFrameCount; // 0x0087E854

int gnSelectedCelFileFrame; // 0x0087E858

extern "C" char* __cdecl strcat(char* szDest, const char* szSource);

extern "C" unsigned int __cdecl strlen(const char* szString);

int __fastcall D2Win_10122(const Unicode* wszText, int nTextLength); // 0x005017D0

void __fastcall sub_00526F20_ToUnicode(Unicode* pDst, const char* szSrc, int nMaxLength); // 0x00526F20

char* __fastcall sub_00526F70(char* szDest, const Unicode* pSource, int nCount); // 0x00526F70

extern "C" const char gszExcelDirectory_006D8ED4[]; // 0x006D8ED4

extern void* sghPentagram; // 0x0087E96C

D2CelFileStrc* __fastcall ARCHIVE_LoadCellFile(const char* szFile, int nType); // 0x004FA9B0

extern "C" int __cdecl _stricmp(const char* szString1, const char* szString2); // 0x006841E9

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void* __stdcall D2COMP_LoadExcelFile(void* hArchive, const char* szName, const char* szExtension, unsigned int* pnFileSize); // 0x005043E0

void __stdcall FOG_FreeBinFile(D2BinFileStrc* pBinFile); // 0x006BCDA0

int __stdcall FOG_GetRecordCountFromBinFile(D2BinFileStrc* pBinFile); // 0x006BCDE0

D2BinFileStrc* __stdcall FOG_CreateBinFile(void* pDataBuffer, int nBufferSize); // 0x006BD640

void __stdcall FOG_10207(D2BinFileStrc* pBinFile, D2BinFieldStrc* pBinField, void* pTxt, int nRecordCount, int nRecordSize); // 0x006BD780

extern "C" const char szBinExtension_006DCC68[]; // 0x006DCC68

extern int gbD2WinBinMode; // 0x0072EF2C

extern "C" const char gszTxtField_end[]; // 0x006D9060

extern "C" const char gszItemsTableMisc[]; // 0x006DCC70

extern "C" const char gszItemsTableArmor[]; // 0x006DCC78

extern "C" const char gszItemsFieldTransform[]; // 0x006DCC80

extern "C" const char gszItemsField1or2Handed[]; // 0x006DCC8C

extern "C" const char gszItemsField2HandedWClass[]; // 0x006DCC98

extern "C" const char gszItemsFieldWClass[]; // 0x006DCCA8

extern "C" const char gszItemsFieldComponent[]; // 0x006DCCB0

extern "C" const char gszItemsFieldLevel[]; // 0x006DCCBC

extern "C" const char gszItemsFieldSpawnable[]; // 0x006DCCC4

extern "C" const char gszItemsFieldAlternateGfx[]; // 0x006DCCD0

extern "C" const char gszItemTypesFieldCode[]; // 0x006DCCE0

extern "C" const char gszItemsFieldType[]; // 0x006DCCE8

extern "C" const char szItemsFieldVersion_006DCCF0[]; // 0x006DCCF0

extern "C" const char gszItemsTableWeapons[]; // 0x006DCCF8

D2TxtLinkStrc* gpCompItemTypesLinker; // 0x0087D828

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0); // 0x0040B480

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

void __stdcall sub_006BD230_AddLinkCode(D2TxtLinkStrc* pLinker, unsigned int dwCode); // 0x006BD230

void* __stdcall D2COMP_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pBinField, int* pRecordCount, int nRecordSize); // 0x00504430

extern "C" char* __cdecl strcpy(char* szDest, const char* szSource);

int __fastcall ARCHIVE_OpenFile(void* hArchive, const char* szFilePath, void** phFile, int bFileNotFoundLogSkipped); // 0x00516E46

void __fastcall ARCHIVE_CloseFile(void* hArchive, void* hFile); // 0x00516E84

void __fastcall ARCHIVE_ReadFileToBuffer(void* hArchive, void* hFile, void* pBuffer, unsigned int dwBytesToRead); // 0x00516F85

unsigned char gabItemPalettes[9][0x6900]; // 0x00842710

extern const char gszGuildPrefix[]; // 0x006DCE68

extern const char gszGuildSuffix[]; // 0x006DCE64

Unicode* __fastcall sub_005267E0(Unicode*,const Unicode*); // 0x005267E0

Unicode* __fastcall sub_00526700(Unicode*,const Unicode*); // 0x00526700

int __fastcall sub_00526800(const Unicode*); // 0x00526800

Unicode* __fastcall sub_00526F20(Unicode*,const char*,int); // 0x00526F20

Unicode* __fastcall sub_00526320_ToUnicode(Unicode* pDest, const char* szSource, int nLength); // 0x00526320

int __fastcall D2Win_10127_SetFont(int); // 0x00502EF0

int __stdcall D2COMP_TruncateTextToWidth(Unicode*,int); // 0x00503EC0

void __fastcall D2Win_10131_GetTextDimensions(const Unicode*,int*,int*); // 0x00502520

void __fastcall D2Win_10117_DrawText(const Unicode*,int,int,int,int); // 0x00502320

int gnItems; // 0x0087D834

struct D2HoverLineStrc;

struct tagRECT;

struct D2CompPairStrc;

struct D2ItemsTxt;

struct D2HoverLineStrc
{
    Unicode wszText[256];
    int nWidth;
    int nHeight;

    D2HoverLineStrc() {} // 0x00504020
};

extern "C" __declspec(dllimport) int __stdcall SetRect(tagRECT* lprc, int xLeft, int yTop, int xRight, int yBottom); // 0x006CC498

void __stdcall D2GFX_DrawBox(int nXStart, int nYStart, int nXEnd, int nYEnd, unsigned int dwColor, int eDrawMode); // 0x004F6300

int __stdcall CONTROL_MouseInsideRect(const tagRECT* pRect); // 0x004F97B0

const Unicode* __fastcall D2LANG_GetStringFromTblIndex(unsigned short nIndex); // 0x00524A30

void __cdecl sub_005269D0(int nBufferSize, Unicode* pBuffer, const Unicode* pFormat, ...); // 0x005269D0

void __stdcall D2COMP_AddHoverTextLine(const Unicode* wszText, D2HoverLineStrc* pLines, int* pCount, int* pMaxWidth, int* pTotalHeight); // 0x00503FA0

typedef unsigned int size_t;

struct D2CompPairStrc
{
    unsigned int nKey;
    int nValue;
};

typedef char check_size_itemstxt[(sizeof(D2ItemsTxt) == 0x1A8) ? 1 : -1];

void __fastcall D2COMP_LoadItems(void* hArchive); // 0x00504570

extern int gaWClassTokens[]; // 0x0072EF30

extern D2CompPairStrc gaCompPairs[]; // 0x0072EF68

extern unsigned int gnCompPairs; // 0x0072EFD0

extern int gnItemsTxtRecordCount_008426EC; // 0x008426EC

static void D2COMP_CopyTokenPadded(char* pDst, const char* pSrc);

static __declspec(noinline) D2CofDataStrc* __stdcall D2COMP_LoadCofFile(const char* szPath, unsigned int* pnSize);

struct D2WinEditBoxStrc;

struct D2CelFileStrc;

struct D2TxtLinkStrc;

struct D2WinControlStrc;

struct D2WinAccountListDataStrc;

struct D2WinTextBoxStrc;

struct D2PaletteRecordStrc;

struct D2ItemTypesTxt;

struct SMSGHANDLER_PARAMS;

struct D2WinSmackStrc;

struct D2WinListStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

void __fastcall ARCHIVE_FreeCellFile(D2CelFileStrc* pCellFile); // 0x004FAAE0

void __fastcall D2COMP_UnlinkCompositeUnit(D2CompositeUnitStrc* pCompositeUnit); // 0x00504100

struct D2PaletteRecordStrc
{
    unsigned char ab[0x100];
};

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

void __stdcall FOG_FreeLinker(D2TxtLinkStrc* pLinker); // 0x006BD0B0

extern D2TxtLinkStrc* gpCompItemsLinker_0087D824; // 0x0087D824

extern "C" const char gszItemTypesFieldEquiv1[]; // 0x006DCD14

extern "C" const char gszItemTypesFieldEquiv2[]; // 0x006DCD0C

extern "C" const char gszItemTypesTable[]; // 0x006DCD00

D2TxtLinkStrc* __stdcall sub_006BD040(const char* szFile, int nLine); // 0x006BD040

enum D2ControlTypes
{
    D2WIN_EDITBOX = 1,
    D2WIN_IMAGE = 2,
    D2WIN_ANIMIMAGE = 3,
    D2WIN_TEXTBOX = 4,
    D2WIN_SCROLLBAR = 5,
    D2WIN_BUTTON = 6,
    D2WIN_LIST = 7,
    D2WIN_TIMER = 8,
    D2WIN_SMACK = 9,
    D2WIN_PROGRESSBAR = 10,
    D2WIN_POPUP = 11,
    D2WIN_ACCOUNTLIST = 12,
    D2WIN_IMAGE2 = 13,
};

typedef int (__stdcall* D2WinMsgHandler)(SMSGHANDLER_PARAMS* pMsg);

typedef int (__fastcall* D2WinControlFn)(D2WinControlStrc* pControl);

extern "C" __declspec(dllimport) int __stdcall DeleteFileA(const char* lpFileName); // 0x006CC1A0

extern "C" char* __cdecl strncpy(char* szDest, const char* szSource, unsigned int nCount); // 0x00687330

int __stdcall SMsgRegisterCommand(void* hWnd, int nId, D2WinMsgHandler pfnHandler); // 0x00420BF0

int __stdcall SMsgRegisterKeyDown(void* hWnd, int nId, D2WinMsgHandler pfnHandler); // 0x00420C10

int __stdcall SMsgRegisterKeyUp(void* hWnd, int nId, D2WinMsgHandler pfnHandler); // 0x00420C30

int __stdcall SMsgRegisterMessage(void* hWnd, int nId, D2WinMsgHandler pfnHandler); // 0x00420C50

int __stdcall SMsgUnregisterCommand(void* hWnd, int nId, D2WinMsgHandler pfnHandler); // 0x00420C70

int __stdcall SMsgUnregisterKeyDown(void* hWnd, int nId, D2WinMsgHandler pfnHandler); // 0x00420C90

int __stdcall SMsgUnregisterKeyUp(void* hWnd, int nId, D2WinMsgHandler pfnHandler); // 0x00420CB0

int __stdcall SMsgUnregisterMessage(void* hWnd, int nId, D2WinMsgHandler pfnHandler); // 0x00420CD0

void __stdcall WINDOW_DecodeSmacker(const char* szSmacker, unsigned char* pBuffer, int nVersion); // 0x004F5E00

void __stdcall WINDOW_CloseSmacker(void* pContext); // 0x004F5E80

int __stdcall CONTROL_SetFocusedEditBox(D2WinEditBoxStrc* pEditBox); // 0x004F91C0

int __stdcall CONTROL_AppendToList(D2WinControlStrc* pControl); // 0x004F9210

const char* __stdcall D2Win_10160_GetPlayerTitle(int nClass, int nRank, int bSoftCore); // 0x00505640

extern tagPOINT gtMousePosition; // 0x007D55A4

extern char gszSmackFileName[260]; // 0x0087E860

extern char gnSmackVersion; // 0x0087E964

extern int gbSmackKeepFile; // 0x0087E968

struct D2FontStrc;

struct D2CharStrc;


struct D2EmblemColorStrc
{
    unsigned char nRed;
    unsigned char nGreen;
    unsigned char nBlue;
};

extern "C" __declspec(dllimport) int __stdcall GlobalUnlock(void* hMem);                                    // 0x006CC364

extern "C" __declspec(dllimport) void* __stdcall GlobalLock(void* hMem);                                    // 0x006CC368

extern "C" __declspec(dllimport) void* __stdcall GlobalAlloc(unsigned int uFlags, unsigned int dwBytes);    // 0x006CC36C

extern "C" __declspec(dllimport) void* __stdcall GlobalFree(void* hMem);                                    // 0x006CC370

extern "C" __declspec(dllimport) void* __stdcall GetClipboardData(unsigned int uFormat);                    // 0x006CC454

extern "C" __declspec(dllimport) int __stdcall CloseClipboard();                                            // 0x006CC51C

extern "C" __declspec(dllimport) int __stdcall OpenClipboard(void* hWnd);                                   // 0x006CC524

extern "C" __declspec(dllimport) int __stdcall IsClipboardFormatAvailable(unsigned int uFormat);            // 0x006CC528

extern "C" __declspec(dllimport) void* __stdcall SetClipboardData(unsigned int uFormat, void* hMem);        // 0x006CC52C

extern "C" __declspec(dllimport) int __stdcall EmptyClipboard();                                            // 0x006CC530

void __stdcall D2Win_10142_CompUnitDestroy(D2CompositeUnitStrc* pCompositeUnit, int bUnlink); // 0x005041B0

int __stdcall SMACK_DeleteFile(D2WinSmackStrc* pSmack);                                                     // 0x00506990

extern D2EmblemColorStrc gaEmblemColorRGB1[10];                                                    // 0x0072E19C

extern D2EmblemColorStrc gaEmblemColorRGB2[10];                                                    // 0x0072E1BC

struct D2CelStrc;

struct D2WinImageClickRectStrc;

struct D2AnimatedImageDescriptor;

int __stdcall CelFileGetCelsPerDirection(D2CelFileStrc* pCelFile);                                                // 0x006019F0

extern D2CharStrc* (__fastcall* gpfnGetCharInfo)(int nChar);                                        // 0x00841DA0

unsigned long gdwListLastClickTick; // 0x0087E970

static D2CofDataStrc* D2COMP_AssertCofData(D2CofDataStrc* pCofData);

static unsigned char* __stdcall D2COMP_GetLayerOrder(int nDirection, int nFrame, D2CofDataStrc* pCofData);

static void __stdcall D2COMP_SetupGfxData(D2CompositeUnitStrc* pCompositeUnit, unsigned char nComponent, int nFrame, int nDirection, D2GfxDataStrc* pGfxData, D2CelFileStrc* pCelFile);

static unsigned char __stdcall D2COMP_GetDirectionIndex(unsigned int nDirections, unsigned char nDirection);

static int __stdcall D2COMP_CountLayerCels(D2CofDataStrc* pCofData, const unsigned char* pLayerOrder, int* pMaxHeight, unsigned char nDirection, int nFrame, D2CompositeUnitStrc* pCompositeUnit);

void __fastcall D2COMP_DrawCompositeShadow(D2CompositeUnitStrc* pCompositeUnit);

static D2CofNodeStrc* __stdcall D2COMP_GetCofNode(unsigned int nClass, const char* szPath, unsigned int nMode, unsigned int dwWeaponClass);

static D2CofDataStrc* __stdcall D2COMP_GetCofData(D2GfxInfoStrc* pGfxInfo, unsigned int nClass, unsigned int nMode, unsigned int dwWeaponClass); // 0x00503640

void __stdcall D2Win_10145(D2CompositeUnitStrc* pCompositeUnit, unsigned int nUnitIndex, unsigned int nMode, unsigned char* pComponents, const unsigned char* pComponentColors); // 0x00504F80

D2CompositeUnitStrc* __stdcall D2COMP_CreateCompositeUnit(unsigned int nUnitIndex, unsigned int nMode, unsigned char* pComponents, const unsigned char* pComponentColors); // 0x005066C0

int __fastcall D2COMP_DrawCompositeUnit(D2CompositeUnitStrc* pCompositeUnit, int nGamma);

unsigned char gabEmblemColor1[12]; // 0x0087D810

unsigned char gabEmblemColor2[12]; // 0x0087E82C

int gnItemsTotalCount; // 0x008426EC

D2ItemsTxt* gpCompItemsTxt; // 0x008426F0

D2ItemsTxt* gpCompWeaponsTxt; // 0x008426F4

int gnCompWeaponsTxtRecordCount; // 0x008426F8

D2ItemsTxt* gpCompArmorTxt; // 0x008426FC

int gnCompArmorTxtRecordCount; // 0x00842700

D2ItemsTxt* gpCompMiscTxt; // 0x00842704

int gnCompMiscTxtRecordCount; // 0x00842708

unsigned short* gpItemsVersion0Index; // 0x0084270C

D2TxtLinkStrc* gpCompItemsLinker; // 0x0087D824

static int D2COMP_ValidateAndLoadCOFForUnit(D2CompositeUnitStrc* pCompositeUnit);

static int __stdcall D2COMP_GetWeaponClass(unsigned int nUnitIndex, const unsigned char* pComponents); // 0x00504AF0

static void D2COMP_FixComponent(int nComponent, unsigned char* pComponent);

static void __stdcall D2COMP_BuildCofPath(unsigned int nClass, unsigned int nMode, unsigned int dwWeaponClass, char* szPath);

static D2CofInfoStrc* D2COMP_FindCofInfo(D2GfxInfoStrc* pGfxInfo, unsigned int nMode, unsigned int dwWeaponClass);

void __fastcall D2COMP_InitGfxData(D2CompositeUnitStrc* pCompositeUnit, D2GfxDataStrc* pGfxData);

void* gpCompHitClassTxt; // 0x0087D81C

D2TxtLinkStrc* gpCompHitClassLinker; // 0x0087D820

void* gpCompItemTypesTxt; // 0x0087D82C

int gnCompItemTypesTxtRecordCount; // 0x0087D830

int gbCompItemsInit; // 0x0087E85C

// 0x005031D0
static void D2COMP_CopyTokenPadded(char* pDst, const char* pSrc)
{
    if (!pSrc[0])
    {
        pDst[0] = COF_PAD;
        pDst[1] = COF_PAD;
        pDst[2] = COF_PAD;
        pDst[3] = COF_PAD;
        return;
    }
    pDst[0] = pSrc[0];
    if (!pSrc[1])
    {
        pDst[1] = COF_PAD;
        pDst[2] = COF_PAD;
        pDst[3] = COF_PAD;
        return;
    }
    pDst[1] = pSrc[1];
    if (!pSrc[2])
    {
        pDst[2] = COF_PAD;
        pDst[3] = COF_PAD;
        return;
    }
    pDst[2] = pSrc[2];
    pDst[3] = COF_PAD;
}

// 0x00503220
static D2CofDataStrc* D2COMP_AssertCofData(D2CofDataStrc* pCofData)
{
    D2_ASSERT(pCofData, 0x3DD);
    return pCofData;
}

// 0x00503250
static D2CofDataStrc* __stdcall D2COMP_LoadCofFile(const char* szPath, unsigned int* pnSize)
{
    D2CofDataStrc* pCofData = (D2CofDataStrc*)sub_00517079_LoadFile(sub_004FAC80(), szPath, pnSize, ".\\Src\\D2Comp.cpp", 0x3EB);
    D2_ASSERT(pCofData, 0x3EC);
    D2_ASSERT(pCofData->nVersion == 20, 0x3F5);
    return pCofData;
}

// 0x005032B0
static unsigned char* __stdcall D2COMP_GetLayerOrder(int nDirection, int nFrame, D2CofDataStrc* pCofData)
{
    D2_ASSERT(pCofData, 0x400);
    const int nFrames = pCofData->nFramesPerDirection;
    unsigned char* pOrder = (unsigned char*)pCofData + 0x1C + nFrames + pCofData->nLayers * (nFrames * nDirection + nFrame + 9);
    D2_ASSERT(pOrder, 0x408);
    return pOrder;
}

// 0x00503310
static inline D2CofNodeStrc* D2COMP_FindCofNode(unsigned int nClass, unsigned int nMode, unsigned int dwWeaponClass)
{
    for (D2CofNodeStrc* pNode = gpCofNodeList; pNode; pNode = pNode->pNext)
    {
        if (pNode->nMode == nMode && pNode->nClass == nClass && pNode->dwWeaponClass == dwWeaponClass)
        {
            ++pNode->nRefCount;
            return pNode;
        }
    }
    return 0;
}

// emits the static 0x00503310 (not game code)
D2CofNodeStrc* __stdcall sub_M118_Emit_00503310(unsigned int nClass, unsigned int nMode, unsigned int dwWeaponClass)
{
    return D2COMP_FindCofNode(nClass, nMode, dwWeaponClass);
}

// 0x00503340
static D2CofNodeStrc* __stdcall D2COMP_GetCofNode(unsigned int nClass, const char* szPath, unsigned int nMode, unsigned int dwWeaponClass)
{
    for (D2CofNodeStrc* pNode = gpCofNodeList; pNode; pNode = pNode->pNext)
    {
        if (pNode->nMode == nMode && pNode->nClass == nClass && pNode->dwWeaponClass == dwWeaponClass)
        {
            ++pNode->nRefCount;
            return pNode;
        }
    }

    D2CofNodeStrc* pNode = (D2CofNodeStrc*)FOG_Alloc(sizeof(D2CofNodeStrc), ".\\Src\\D2Comp.cpp", 0x437, 0);
    memset(pNode, 0, sizeof(D2CofNodeStrc));
    pNode->nMode = nMode;
    pNode->nClass = nClass;
    D2CofNodeStrc* pHead = gpCofNodeList;
    ++pNode->nRefCount;
    pNode->dwWeaponClass = dwWeaponClass;
    pNode->pNext = pHead;
    pNode->pPrev = 0;
    if (pHead)
    {
        pHead->pPrev = pNode;
    }
    gpCofNodeList = pNode;
    pNode->pCofData = D2COMP_LoadCofFile(szPath, &pNode->dwCofSize);
    D2_ASSERT(pNode->pCofData, 0x446);
    return pNode;
}

// 0x00503410
static void __stdcall D2COMP_ReleaseCofNode(int bFree, D2CofNodeStrc* pCofNode)
{
    D2_ASSERT(pCofNode, 0x455);

    if (!gpCofNodeList)
        return;

    --pCofNode->nRefCount;
    if (pCofNode->nRefCount > 0)
        return;

    D2CofNodeStrc* pPrev = pCofNode->pPrev;
    D2CofNodeStrc* pNext = pCofNode->pNext;
    if (bFree)
    {
        FOG_Free(pCofNode->pCofData, ".\\Src\\D2Comp.cpp", 0x461, 0);
        pCofNode->pCofData = 0;
    }

    if (!pPrev)
    {
        gpCofNodeList = pNext;
        if (pNext)
            pNext->pPrev = 0;
    }
    else if (!pNext)
    {
        pPrev->pNext = 0;
    }
    else
    {
        pPrev->pNext = pNext;
        pNext->pPrev = pPrev;
    }

    FOG_Free(pCofNode, ".\\Src\\D2Comp.cpp", 0x47A, 0);
}

// 0x005034B0
static void __stdcall D2COMP_BuildCofPath(unsigned int nClass, unsigned int nMode, unsigned int dwWeaponClass, char* szPath)
{
    D2_ASSERT(nClass < 25, 0x488);
// build: symbol ?gnModeTokens@* 0x0072E0B4
    D2_ASSERT(nMode < gnModeTokens, 0x489);

    char szWeaponClass[4];
    char szUnit[4];
    char szMode[4];
// build: symbol ?gadwUnitTokens@* 0x0072E050
    const unsigned int dwUnit = gadwUnitTokens[nClass];
// build: symbol ?gadwModeTokens@* 0x0072E0B8
    const unsigned int dwMode = gadwModeTokens[nMode];
    const char* pWeaponClass = (const char*)&dwWeaponClass;
    szWeaponClass[0] = TOKEN_CHAR(pWeaponClass[0]);
    szWeaponClass[1] = TOKEN_CHAR(pWeaponClass[1]);
    szWeaponClass[2] = TOKEN_CHAR(pWeaponClass[2]);
    szWeaponClass[3] = 0;
    szUnit[0] = TOKEN_CHAR(dwUnit);
    szUnit[1] = TOKEN_CHAR(dwUnit >> 8);
    szUnit[2] = TOKEN_CHAR(dwUnit >> 16);
    szUnit[3] = 0;
    szMode[0] = TOKEN_CHAR(dwMode);
    szMode[1] = TOKEN_CHAR(dwMode >> 8);
    szMode[2] = TOKEN_CHAR(dwMode >> 16);
    szMode[3] = 0;

    const char* szDir = "DATA\\GLOBAL\\CHARS";
    if (nClass >= 7)
    {
        szDir = "DATA\\GLOBAL\\MONSTERS";
    }
    wsprintfA(szPath, "%s\\%s\\COF\\%s%s%s.COF", szDir, szUnit, szUnit, szMode, szWeaponClass);

    void* hFile;
// build: symbol ?FOG_FOpenFile@* 0x004068E0
    if (FOG_FOpenFile(szPath, &hFile))
    {
// build: symbol ?FOG_FCloseFile@* 0x004068F0
        FOG_FCloseFile(hFile);
    }
    else
    {
        szPath[0] = 0;
    }
}

// 0x005035F0
static D2CofInfoStrc* D2COMP_FindCofInfo(D2GfxInfoStrc* pGfxInfo, unsigned int nMode, unsigned int dwWeaponClass)
{
    D2_ASSERT(pGfxInfo, 0x4B0);
    for (D2CofInfoStrc* pCofInfo = pGfxInfo->pCofInfo; pCofInfo; pCofInfo = pCofInfo->pNext)
    {
        if (pCofInfo->pCofNode->nMode == nMode && pCofInfo->pCofNode->dwWeaponClass == dwWeaponClass)
        {
            return pCofInfo;
        }
    }
    return 0;
}

// 0x00503640
static D2CofDataStrc* __stdcall D2COMP_GetCofData(D2GfxInfoStrc* pGfxInfo, unsigned int nClass, unsigned int nMode, unsigned int dwWeaponClass)
{
    char szPath[260];

    D2_ASSERT(pGfxInfo, 0x4CA);

    D2CofInfoStrc* pCofInfo = D2COMP_FindCofInfo(pGfxInfo, nMode, dwWeaponClass);
    if (!pCofInfo)
    {
        szPath[0] = 0;
        memset(&szPath[1], 0, sizeof(szPath) - 1);
        D2COMP_BuildCofPath(nClass, nMode, dwWeaponClass, szPath);
        if (!szPath[0])
        {
            return 0;
        }

        pCofInfo = (D2CofInfoStrc*)FOG_Alloc(sizeof(D2CofInfoStrc), ".\\Src\\D2Comp.cpp", 0x4D8, 0);
        D2_ASSERT(pCofInfo, 0x4D9);
        memset(pCofInfo, 0, sizeof(D2CofInfoStrc));

        D2CofNodeStrc* pCofNode = D2COMP_GetCofNode(nClass, szPath, nMode, dwWeaponClass);
        D2_ASSERT(pCofNode, 0x4DC);
        pCofInfo->pCofNode = pCofNode;
        pCofInfo->pNext = pGfxInfo->pCofInfo;
        pGfxInfo->pCofInfo = pCofInfo;
    }

    D2CofDataStrc* pCofData = pCofInfo->pCofNode->pCofData;
    D2_ASSERT(pCofData, 0x4E2);
    return pCofData;
}

// 0x00503740
void __fastcall D2COMP_InitGfxData(D2CompositeUnitStrc* pCompositeUnit, D2GfxDataStrc* pGfxData)
{
    pGfxData->nUnitIndex = pCompositeUnit->nUnitIndex;
    pGfxData->nMode = pCompositeUnit->nMode;
    const int nComponent = pGfxData->nComponent;
// build: symbol ?gadwComponentTokens@* 0x0072E108
    pGfxData->dwComponentToken = gadwComponentTokens[nComponent];
// build: symbol ?gadwWClassTokens@* 0x0072E15C
    pGfxData->dwWClassToken = gadwWClassTokens[pCompositeUnit->nWClassTokenIndex];
    pGfxData->dwUnitToken = gadwUnitTokens[pCompositeUnit->nUnitIndex];
    pGfxData->dwArmorType = 0x2074696C;
    if (pCompositeUnit->dwArmorType[nComponent])
    {
        pGfxData->dwArmorType = pCompositeUnit->dwArmorType[nComponent];
    }

    D2GfxInfoStrc* pGfxInfo = pCompositeUnit->pGfxInfo;
    D2_ASSERT(pGfxInfo, 0x502);

    D2CofDataStrc* pCofData = D2COMP_GetCofData(pGfxInfo, pCompositeUnit->nUnitIndex, pCompositeUnit->nMode, gadwWClassTokens[pCompositeUnit->nWClassTokenIndex]);
    D2_ASSERT(pCofData, 0x506);

    const unsigned char* pLayer = (const unsigned char*)pCofData + 0x1C;
    for (unsigned int i = 0; i < pCofData->nLayers; ++i)
    {
        D2_ASSERT(nComponent < 16, 0x50E);
        if (pLayer[0] == nComponent)
        {
            pGfxData->nUnitType = pGfxData->nUnitIndex >= 7;
            pGfxData->dwModeToken = gadwModeTokens[pGfxData->nMode];
            D2_ASSERT(pGfxData->dwArmorType, 0x51F);
            unsigned int dwHitClass = 0;
            D2COMP_CopyTokenPadded((char*)&dwHitClass, (const char*)pLayer + 5);
            pGfxData->dwWClassToken = dwHitClass;
            break;
        }
        pLayer += 9;
    }

    D2_ASSERT(pGfxData->dwComponentToken, 0x52B);
    D2_ASSERT(pGfxData->dwUnitToken, 0x52C);
    D2_ASSERT(pGfxData->dwWClassToken, 0x52D);
    if (!pGfxData->dwArmorType)
    {
        pGfxData->dwArmorType = 0x20787878;
    }
    if (!pGfxData->dwModeToken)
    {
        pGfxData->dwModeToken = 0x20787878;
    }
}

// 0x005038A0
static __declspec(noinline) void __stdcall D2COMP_SetupGfxData(D2CompositeUnitStrc* pCompositeUnit, unsigned char nComponent, int nFrame, int nDirection, D2GfxDataStrc* pGfxData, D2CelFileStrc* pCelFile)
{
    pGfxData->pCelFile = pCelFile;
    pGfxData->nDirection = nDirection;
    pGfxData->nFrame = nFrame;
    pGfxData->nComponent = nComponent;
    D2COMP_InitGfxData(pCompositeUnit, pGfxData);
    pGfxData->dwFlags |= 2;
}

// 0x005038D0
unsigned char* __fastcall D2COMP_GetComponentPalette(int nColor)
{
    int nRow = nColor >> 5;
    unsigned int nCol = nColor & 0x1F;
    if (nCol <= 0x14)
    {
        if (nRow == 0)
            nRow = 8;
        else if (nRow < 0)
            return 0;
        else if (nRow >= 9)
            return 0;
        else
        {
            if (nRow > 2)
            {
                if (nRow <= 4)
                    goto fail;
            }
        }
        return ((D2PaletteRecordStrc (*)[0x69])gabItemPalettes)[nRow][nCol].ab;
    }
fail:
    return 0;
}

// 0x00503920
static unsigned char __stdcall D2COMP_GetDirectionIndex(unsigned int nDirections, unsigned char nDirection)
{
    D2_ASSERT(nDirection < 64, 0x576);
// build: symbol ?gaDirectionIndex@* 0x006DCA60
    const unsigned char nIndex = gaDirectionIndex[sub_00517ABB_BitScanForward1(nDirections)][nDirection];
    D2_ASSERT(nIndex <= 64, 0x578);
    return nIndex;
}

// 0x00503970
static int __stdcall D2COMP_CountLayerCels(D2CofDataStrc* pCofData, const unsigned char* pLayerOrder, int* pMaxHeight, unsigned char nDirection, int nFrame, D2CompositeUnitStrc* pCompositeUnit)
{
    D2_ASSERT(pCompositeUnit, 0x587);
    int nCount = 0;
    for (int i = 0; i < pCofData->nLayers; ++i)
    {
        const int nComponent = pLayerOrder[i];
        D2_ASSERT(nComponent < 16, 0x58E);

        D2GfxDataStrc tGfxData;
        memset(&tGfxData, 0, sizeof(tGfxData));
        tGfxData.pCelFile = 0;
        tGfxData.nDirection = nDirection;
        tGfxData.nFrame = nFrame;
        tGfxData.nComponent = nComponent;
        D2COMP_InitGfxData(pCompositeUnit, &tGfxData);
        tGfxData.dwFlags |= 2;

        if (sub_006001F0(&tGfxData, 0, 1) && tGfxData.pCel)
        {
            const int nHeight = CelGetOffsetY(tGfxData.pCel) + pCompositeUnit->nX;
            if (nHeight > *pMaxHeight)
            {
                *pMaxHeight = nHeight;
            }
            ++nCount;
        }
    }
    return nCount;
}

// 0x00503A50
void __fastcall D2COMP_DrawCompositeShadow(D2CompositeUnitStrc* pCompositeUnit)
{
    D2_ASSERT(pCompositeUnit, 0x5B3);

    if (!(pCompositeUnit->dwFlags & gdwBitMasks[0]) || !(pCompositeUnit->dwFlags & gdwBitMasks[2]))
    {
        return;
    }

    const int nX = pCompositeUnit->nX - 2;
    const int nY = pCompositeUnit->nY;
    D2_ASSERT(pCompositeUnit->pGfxInfo, 0x5C3);

    D2CofInfoStrc* pCofInfo = D2COMP_FindCofInfo(pCompositeUnit->pGfxInfo, pCompositeUnit->nMode, gadwWClassTokens[pCompositeUnit->nWClassTokenIndex]);
    if (!pCofInfo)
    {
        return;
    }

    D2CofDataStrc* pCofData = pCofInfo->pCofNode->pCofData;
    D2_ASSERT(pCofData, 0x5CB);
    D2CofDataStrc* pHeader = D2COMP_AssertCofData(pCofData);
    const int nFrame = pCompositeUnit->nFrame >> 8;
    const unsigned char* pLayerOrder = D2COMP_GetLayerOrder(pCompositeUnit->nDirection, nFrame, pCofData);
    D2_ASSERT(pLayerOrder, 0x5D0);

    int nMaxHeight = 0;
    if (D2COMP_CountLayerCels(pHeader, pLayerOrder, &nMaxHeight, pCompositeUnit->nDirection, nFrame, pCompositeUnit) <= 0)
    {
        return;
    }

    for (unsigned int i = 0; i < pHeader->nLayers; ++i)
    {
        const int nComponent = pLayerOrder[i];
        D2_ASSERT(nComponent < 16, 0x5DA);

        D2GfxDataStrc tGfxData;
        memset(&tGfxData, 0, sizeof(tGfxData));
        D2COMP_SetupGfxData(pCompositeUnit, nComponent, nFrame, pCompositeUnit->nDirection, &tGfxData, 0);
        sub_004F6540(&tGfxData, nX, nY);
    }
}

// 0x00503BA0
int __fastcall D2COMP_DrawCompositeUnit(D2CompositeUnitStrc* pCompositeUnit, int nGamma)
{
    D2_ASSERT(pCompositeUnit, 0x5F3);

    if (!(pCompositeUnit->dwFlags & gdwBitMasks[0]))
    {
        return 0;
    }

    D2GfxDataStrc tGfxData;
    if (pCompositeUnit->dwFlags & gdwBitMasks[10])
    {
        D2CelFileStrc* pCelFile = ghSelectedCelFile;
        D2_ASSERT(pCelFile, 0x5FE);
        memset(&tGfxData, 0, sizeof(tGfxData));
        tGfxData.nFrame = gnSelectedCelFileFrame;
        tGfxData.pCelFile = pCelFile;
        tGfxData.nDirection = 0;
        TEXTURE_CelDraw(&tGfxData, pCompositeUnit->nX + 5, pCompositeUnit->nY - 5, -1, 3, 0);
    }

    D2CelFileStrc* pEmblemCellFile = pCompositeUnit->pEmblemCellFile;
    if (pEmblemCellFile)
    {
        unsigned char aPalette[256];
        aPalette[1] = pCompositeUnit->nEmblemColor1;
        aPalette[2] = pCompositeUnit->nEmblemColor2;
        memset(&tGfxData, 0, sizeof(tGfxData));
        tGfxData.pCelFile = pEmblemCellFile;
        tGfxData.nDirection = 0;
        tGfxData.nFrame = 0;
        tGfxData.nDrawFlag = 1;
        TEXTURE_CelDraw(&tGfxData, pCompositeUnit->nX - 0x14, pCompositeUnit->nY - 0x3C, -1, 5, aPalette);
    }

    D2_ASSERT(pCompositeUnit->pGfxInfo, 0x622);
    const unsigned int nMode = pCompositeUnit->nMode;
    D2CofInfoStrc* pCofInfo = D2COMP_FindCofInfo(pCompositeUnit->pGfxInfo, nMode, gadwWClassTokens[pCompositeUnit->nWClassTokenIndex]);
    if (!pCofInfo)
    {
        return 0;
    }

    D2CofDataStrc* pCofData = pCofInfo->pCofNode->pCofData;
    D2_ASSERT(pCofData, 0x62B);
    D2CofDataStrc* pHeader = D2COMP_AssertCofData(pCofData);
    const int nFrame = pCompositeUnit->nFrame >> 8;
    const unsigned char* pLayerOrder = D2COMP_GetLayerOrder(pCompositeUnit->nDirection, nFrame, pCofData);
    D2_ASSERT(pLayerOrder, 0x630);

    int nDrawMode;
    if ((pCompositeUnit->dwFlags & gdwBitMasks[5]) && (pCompositeUnit->dwFlags & gdwBitMasks[4]))
    {
        nDrawMode = 1;
    }
    else
    {
        nDrawMode = 5;
        if (pCompositeUnit->dwFlags & gdwBitMasks[13])
        {
            nDrawMode = 1;
        }
    }

    for (int i = 0; i < pHeader->nLayers; ++i)
    {
        const int nComponent = pLayerOrder[i];
        memset(&tGfxData, 0, sizeof(tGfxData));
        const int nDirection = D2COMP_GetDirectionIndex(pCompositeUnit->nDirections, pCompositeUnit->nDirection);
        tGfxData.nFrame = nFrame;
        tGfxData.pCelFile = 0;
        tGfxData.nDirection = nDirection;
        tGfxData.nComponent = nComponent;
        D2COMP_InitGfxData(pCompositeUnit, &tGfxData);
        tGfxData.dwFlags |= 2;

        const int nColor = pCompositeUnit->nComponentColors[nComponent];
        unsigned char* pPalette = 0;
        if (nColor != 0xFF)
        {
// build: symbol ?D2COMP_GetComponentPalette@* 0x005038D0
            pPalette = D2COMP_GetComponentPalette(nColor);
        }
        TEXTURE_CelDraw(&tGfxData, pCompositeUnit->nX, pCompositeUnit->nY, nGamma, nDrawMode, pPalette);
    }

    pCompositeUnit->nFrame += pCompositeUnit->nAnimSpeed;
    if ((pCompositeUnit->nFrame >> 8) >= pCompositeUnit->nFrameCount - 1)
    {
        pCompositeUnit->nFrame = 0;
    }

    const unsigned int dwTickCount = GetTickCount();
    if (dwTickCount > gdwNextFrameTick)
    {
        gdwNextFrameTick = dwTickCount + 0x42;
        ++gnSquelchCelFileFrame;
        if (gnSquelchCelFileFrame >= gnSquelchCelFileFrameCount)
        {
            gnSquelchCelFileFrame = 0;
        }
        ++gnSelectedCelFileFrame;
        if (gnSelectedCelFileFrame >= gnSelectedCelFileFrameCount)
        {
            gnSelectedCelFileFrame = 0;
        }
    }

    if (pCompositeUnit->dwFlags & gdwBitMasks[9])
    {
        D2CelFileStrc* pCelFile = ghSquelchCelFile;
        D2_ASSERT(pCelFile, 0x671);
        memset(&tGfxData, 0, sizeof(tGfxData));
        tGfxData.nFrame = gnSquelchCelFileFrame;
        tGfxData.pCelFile = pCelFile;
        tGfxData.nDirection = 0;
        TEXTURE_CelDraw(&tGfxData, pCompositeUnit->nX, pCompositeUnit->nY + 10, -1, 3, 0);
    }

    return 1;
}

// 0x00503EC0
int __stdcall D2COMP_TruncateTextToWidth(Unicode* wszText, int nMaxWidth)
{
    char szText[300];
    int nCount = 0;
    sub_00526F70(szText, wszText, 300);
    const int nLength = strlen(szText);
    int bTruncated = 0;
    while (nCount < nLength)
    {
        if (D2Win_10122(wszText, nCount + 1) >= nMaxWidth)
        {
            bTruncated = 1;
            break;
        }

        ++nCount;
    }

    szText[nCount] = 0;
    if (bTruncated)
    {
        strcat(szText, "...");
    }

    sub_00526F20_ToUnicode(wszText, szText, 299);
    return nCount;
}

// 0x00503F70
static inline int sub_00503F70(unsigned int selector)
{
    switch (selector) {
    case 0:
    case 1:
    case 6:
    case 9:
        return 0;
    default:
        return 1;
    }
}

int __stdcall emit_selector_00503F70(unsigned int selector)
{
    return sub_00503F70(selector);
}

// 0x00503FA0
void __stdcall D2COMP_AddHoverTextLine(const Unicode* wszText, D2HoverLineStrc* pLines, int* pCount, int* pMaxWidth, int* pTotalHeight)
{
    D2HoverLineStrc* pLine = &pLines[*pCount];
    D2_ASSERT(*pCount < 7, 0x738);

    sub_005267E0(pLine->wszText, wszText);
    D2Win_10131_GetTextDimensions(pLine->wszText, &pLine->nWidth, &pLine->nHeight);
    *pMaxWidth = *pMaxWidth > pLine->nWidth + 6 ? *pMaxWidth : pLine->nWidth + 6;
    *pTotalHeight += pLine->nHeight;
    ++*pCount;
}

// 0x00504020
int* __fastcall D2COMP_ClearTable(int* table)
{
    for (int i = 0; i < 128; ++i)
        table[i] = 0;
    return table;
}

// 0x00504040
static int D2COMP_ValidateAndLoadCOFForUnit(D2CompositeUnitStrc* ptCompositeUnit)
{
    D2_ASSERT(ptCompositeUnit, 0x81A);

// build: symbol ?gnUnitTokens@* 0x0072E04C
// build: symbol ?gnWClassTokens@* 0x0072E198
    if (ptCompositeUnit->nUnitIndex >= gnUnitTokens || ptCompositeUnit->nMode >= gnModeTokens || ptCompositeUnit->nWClassTokenIndex >= gnWClassTokens)
    {
        ptCompositeUnit->nUnitIndex = 7;
        ptCompositeUnit->nMode = 5;
        ptCompositeUnit->nWClassTokenIndex = 1;
    }

    D2GfxInfoStrc* ptGfxInfo = ptCompositeUnit->pGfxInfo;
    D2_ASSERT(ptGfxInfo, 0x827);

    if (!D2COMP_GetCofData(ptGfxInfo, ptCompositeUnit->nUnitIndex, ptCompositeUnit->nMode, gadwWClassTokens[ptCompositeUnit->nWClassTokenIndex]))
    {
        ptCompositeUnit->nUnitIndex = 7;
        ptCompositeUnit->nMode = 5;
        ptCompositeUnit->nWClassTokenIndex = 1;
        D2_ASSERT(D2COMP_GetCofData(ptGfxInfo, 7, 5, gadwWClassTokens[1]), 0x836);
    }

    return 1;
}

// 0x00504100
void __fastcall D2COMP_UnlinkCompositeUnit(D2CompositeUnitStrc* pCompositeUnit)
{
    D2CompositeUnitStrc* pPrev = pCompositeUnit->pPrev;
    D2CompositeUnitStrc* pNext = pCompositeUnit->pNext;
    if (!pPrev)
    {
        gpCompositeUnitList = pNext;
        if (pNext)
            pNext->pPrev = 0;
    }
    else if (!pNext)
    {
        pPrev->pNext = 0;
    }
    else
    {
        pPrev->pNext = pNext;
        pNext->pPrev = pPrev;
    }
    FOG_Free(pCompositeUnit, ".\\Src\\D2Comp.cpp", 0x85A, 0);
}

// 0x00504170
int* __cdecl D2COMP_AllocGfxInfo()
{
    int* pValue = (int*)FOG_Alloc(4, ".\\Src\\D2Comp.cpp", 0x866, 0);
    D2_ASSERT(pValue, 0x867);
    *pValue = 0;
    return pValue;
}

// 0x005041B0
void __stdcall D2Win_10142_CompUnitDestroy(D2CompositeUnitStrc* pCompositeUnit, int bUnlink)
{
    D2_ASSERT(pCompositeUnit, 0x877);

    D2GfxInfoStrc* pGfxInfo = pCompositeUnit->pGfxInfo;
    D2_ASSERT(pGfxInfo, 0x87B);

    D2CofInfoStrc* pCofInfo = pGfxInfo->pCofInfo;
    if (pCofInfo)
    {
        do
        {
            D2CofNodeStrc* pCofNode = pCofInfo->pCofNode;
            D2CofInfoStrc* pNext = pCofInfo->pNext;
            D2COMP_ReleaseCofNode(1, pCofNode);
            FOG_Free(pCofInfo, ".\\Src\\D2Comp.cpp", 0x883, 0);
            pCofInfo = pNext;
        }
        while (pCofInfo);
    }

    pGfxInfo->pCofInfo = 0;
    FOG_Free(pGfxInfo, ".\\Src\\D2Comp.cpp", 0x889, 0);

    if (pCompositeUnit->pEmblemCellFile)
    {
        ARCHIVE_FreeCellFile(pCompositeUnit->pEmblemCellFile);
        pCompositeUnit->pEmblemCellFile = 0;
    }

    if (bUnlink)
        D2COMP_UnlinkCompositeUnit(pCompositeUnit);
}

// 0x00504270
void __stdcall D2Win_10154(D2CompositeUnitStrc* hCompositeUnit, const Unicode* pAccountName, const Unicode* pCharName, const Unicode* pGuildTag, const Unicode* pRealmName, int nCharLevel, int dwProductCode)
{
    D2_ASSERT(hCompositeUnit, 0x8A8);
    sub_005267E0((Unicode*)hCompositeUnit->wszAccountName, pAccountName);
    sub_005267E0((Unicode*)hCompositeUnit->wszCharName, pCharName);
    sub_005267E0((Unicode*)hCompositeUnit->wszGuildTag, pGuildTag);
    sub_005267E0((Unicode*)hCompositeUnit->wszRealmName, pRealmName);
    hCompositeUnit->nCharLevel = nCharLevel;
    hCompositeUnit->dwProductCode = dwProductCode;
}

static int sub_D2Win_10143_ApplyCof(D2CompositeUnitStrc* pCompositeUnit, D2CofNodeStrc* pCofNode, int nMode)
{
    D2CofDataStrc* pCofData = pCofNode->pCofData;
    D2_ASSERT(pCofData, 0x3DD);
    pCompositeUnit->nMode = nMode;
    pCompositeUnit->nFrameCount = pCofData->nFramesPerDirection;
    pCompositeUnit->nFrame = 0;
    pCompositeUnit->nAnimSpeed = pCofData->nAnimSpeed;
    pCompositeUnit->nDirections = pCofData->nDirections;
    return 1;
}

// 0x005042F0
int __fastcall D2Win_10143(D2CompositeUnitStrc* pCompositeUnit, int nMode)
{
    D2_ASSERT(pCompositeUnit, 0x8BF);
    for (D2CofInfoStrc* pCofInfo = pCompositeUnit->pGfxInfo->pCofInfo; pCofInfo; pCofInfo = pCofInfo->pNext)
    {
        if (pCofInfo->pCofNode->nMode == nMode)
            return sub_D2Win_10143_ApplyCof(pCompositeUnit, pCofInfo->pCofNode, nMode);
    }
    return 0;
}

// 0x00504370
int __stdcall D2COMP_GetPairValue(int nKey)
{
    for (unsigned int i = 0; i < gnCompPairs; ++i)
    {
        if (nKey == gaCompPairs[i].nKey)
            return gaCompPairs[i].nValue;
    }
    return 0;
}

// 0x005043B0
void __stdcall D2COMP_FreePoolMemory(void* pMemory)
{
    FOG_FreePool(0, pMemory, ".\\Src\\D2Comp.cpp", 0x939, 0);
}

// 0x005043D0
void __stdcall D2COMP_Stub4(int, int, int, int)
{
}

// 0x005043E0
void* __stdcall D2COMP_LoadExcelFile(void* hArchive, const char* szName, const char* szExtension, unsigned int* pnFileSize)
{
    char szFilename[260];
    wsprintfA(szFilename, "%s\\%s%s", gszExcelDirectory_006D8ED4, szName, szExtension);
    return sub_00517079_LoadFile(hArchive, szFilename, pnFileSize, ".\\Src\\D2Comp.cpp", 0x958);
}

// 0x00504430
void* __stdcall D2COMP_CompileTxt(void* hArchive, const char* szName, D2BinFieldStrc* pBinField, int* pRecordCount, int nRecordSize)
{
    unsigned int nFileSize = 0;
    void* pFileData;
    if (gbD2WinBinMode)
    {
        char szFilename[260];
        wsprintfA(szFilename, "%s\\%s%s", gszExcelDirectory_006D8ED4, szName, szBinExtension_006DCC68);
        pFileData = sub_00517079_LoadFile(hArchive, szFilename, &nFileSize, ".\\Src\\D2Comp.cpp", 0x958);
    }
    else if (!_stricmp(szName, "leveldefs"))
    {
        pFileData = D2COMP_LoadExcelFile(hArchive, "levels", ".txt", &nFileSize);
    }
    else
    {
        pFileData = D2COMP_LoadExcelFile(hArchive, szName, ".txt", &nFileSize);
    }

    D2_ASSERT(pFileData, 0x9E3);

    int nRecordCount;
    void* pBinData;
    if (gbD2WinBinMode)
    {
        nRecordCount = *(int*)pFileData;
        pBinData = (char*)pFileData + 4;
    }
    else
    {
        D2BinFileStrc* pBinFile = FOG_CreateBinFile(pFileData, nFileSize);
        nRecordCount = FOG_GetRecordCountFromBinFile(pBinFile);
        const int nSize = nRecordCount * nRecordSize;
        pBinData = FOG_AllocPool(0, nSize, ".\\Src\\D2Comp.cpp", 0x9FA, 0);
        memset(pBinData, 0, nSize);
        FOG_10207(pBinFile, pBinField, pBinData, nRecordCount, nRecordSize);
        FOG_FreeBinFile(pBinFile);
    }

    if (pRecordCount)
    {
        *pRecordCount = nRecordCount;
    }

    return pBinData;
}

// 0x00504570
void __fastcall D2COMP_LoadItems(void* hArchive)
{
    D2BinFieldStrc aItemsFields[] =
    {
        { szItemsFieldVersion_006DCCF0, 3, 0, 0xF6, 0 },
        { gszItemsFieldType, 0xF, 0, 0x11E, &gpCompItemTypesLinker },
        { gszItemTypesFieldCode, 9, 0, 0x80, 0 },
        { gszItemsFieldAlternateGfx, 9, 0, 0x90, 0 },
        { gszItemsFieldSpawnable, 4, 0, 0x133, 0 },
        { gszItemsFieldLevel, 4, 0, 0xFD, 0 },
        { gszItemsFieldComponent, 4, 0, 0x115, 0 },
        { gszItemsFieldWClass, 9, 0, 0xC0, 0 },
        { gszItemsField2HandedWClass, 9, 0, 0xC4, 0 },
        { gszItemsField1or2Handed, 6, 0, 0x13D, 0 },
        { gszItemsFieldTransform, 4, 0, 0x141, 0 },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    D2ItemsTxt* pWeapons = (D2ItemsTxt*)D2COMP_CompileTxt(hArchive, gszItemsTableWeapons, aItemsFields, &gnCompWeaponsTxtRecordCount, sizeof(D2ItemsTxt));
    D2ItemsTxt* pArmor = (D2ItemsTxt*)D2COMP_CompileTxt(hArchive, gszItemsTableArmor, aItemsFields, &gnCompArmorTxtRecordCount, sizeof(D2ItemsTxt));
    D2ItemsTxt* pMisc = (D2ItemsTxt*)D2COMP_CompileTxt(hArchive, gszItemsTableMisc, aItemsFields, &gnCompMiscTxtRecordCount, sizeof(D2ItemsTxt));

    gnItemsTotalCount = gnCompArmorTxtRecordCount + gnCompMiscTxtRecordCount + gnCompWeaponsTxtRecordCount;

    gpCompItemsTxt = (D2ItemsTxt*)FOG_AllocPool(0, gnItemsTotalCount * sizeof(D2ItemsTxt), gszD2CompSourceFile, 0xA34, 0);
    D2ItemsTxt* pItems = gpCompItemsTxt;
    gpCompWeaponsTxt = gpCompItemsTxt;
    memcpy(gpCompItemsTxt, pWeapons, gnCompWeaponsTxtRecordCount * sizeof(D2ItemsTxt));
    pItems += gnCompWeaponsTxtRecordCount;
    gpCompArmorTxt = pItems;
    memcpy(pItems, pArmor, gnCompArmorTxtRecordCount * sizeof(D2ItemsTxt));
    pItems += gnCompArmorTxtRecordCount;
    gpCompMiscTxt = pItems;
    memcpy(pItems, pMisc, gnCompMiscTxtRecordCount * sizeof(D2ItemsTxt));

    FOG_FreePool(0, (char*)pWeapons - 4, gszD2CompSourceFile, 0xA44, 0);
    FOG_FreePool(0, (char*)pArmor - 4, gszD2CompSourceFile, 0xA45, 0);
    FOG_FreePool(0, (char*)pMisc - 4, gszD2CompSourceFile, 0xA46, 0);

    gpItemsVersion0Index = (unsigned short*)FOG_AllocPool(0, gnItemsTotalCount * sizeof(unsigned short), gszD2CompSourceFile, 0xA4B, 0);
    memset(gpItemsVersion0Index, 0, gnItemsTotalCount * sizeof(unsigned short));

    int i = 0;
    if (i < gnItemsTotalCount)
    {
        D2ItemsTxt* pRecords = gpCompItemsTxt;
        int nCount = 0;
        do
        {
            if (!pRecords[i].wVersion)
            {
                gpItemsVersion0Index[nCount] = i;
                ++nCount;
            }
            ++i;
        }
        while (i < gnItemsTotalCount);
    }

    gpCompItemsLinker = sub_006BD040(gszD2CompSourceFile, 0xA56);
    for (int i = 0; i < gnItemsTotalCount; ++i)
    {
        sub_006BD230_AddLinkCode(gpCompItemsLinker, gpCompItemsTxt[i].dwCode);
    }
}

// 0x00504920
void __fastcall D2COMP_LoadItemTypes(void* hArchive)
{
    D2BinFieldStrc aItemTypesFields[] =
    {
        { gszItemTypesFieldCode, 0xA, 0, 0, &gpCompItemTypesLinker },
        { gszItemTypesFieldEquiv1, 0xF, 0, 4, &gpCompItemTypesLinker },
        { gszItemTypesFieldEquiv2, 0xF, 0, 6, &gpCompItemTypesLinker },
        { gszTxtField_end, 0, 0, 0, 0 },
    };

    gpCompItemTypesLinker = sub_006BD040(".\\Src\\D2Comp.cpp", 0xA97);
    gpCompItemTypesTxt = D2COMP_CompileTxt(hArchive, gszItemTypesTable, aItemTypesFields, &gnCompItemTypesTxtRecordCount, 0xE4);
}

// 0x005049D0
void __stdcall D2COMP_FreeLinkers()
{
    if (gpCompItemsLinker_0087D824)
    {
        FOG_FreeLinker(gpCompItemsLinker_0087D824);
        gpCompItemsLinker_0087D824 = 0;
    }
    if (gpCompItemTypesLinker)
    {
        FOG_FreeLinker(gpCompItemTypesLinker);
        gpCompItemTypesLinker = 0;
    }
    if (gpCompHitClassLinker)
    {
        FOG_FreeLinker(gpCompHitClassLinker);
        gpCompHitClassLinker = 0;
    }
}

// 0x00504A20
int __stdcall D2COMP_IsItemTypeDescendant(int nStartType, int nItemType)
{
    if (!nItemType)
    {
        return 1;
    }

    if (!nStartType)
    {
        return 0;
    }

    int itemTypeStack[64];

    itemTypeStack[0] = nStartType;
    int nStackIndex = 1;
    while (nStackIndex)
    {
        const int nCurrentType = itemTypeStack[nStackIndex - 1];
        --nStackIndex;

        if (nItemType == nCurrentType)
        {
            return 1;
        }

        D2ItemTypesTxt* pItemTypesTxtRecord = &((D2ItemTypesTxt*)gpCompItemTypesTxt)[nCurrentType];
        if (pItemTypesTxtRecord->nEquiv1)
        {
            itemTypeStack[nStackIndex] = pItemTypesTxtRecord->nEquiv1;
            ++nStackIndex;

            if (pItemTypesTxtRecord->nEquiv2)
            {
                itemTypeStack[nStackIndex] = pItemTypesTxtRecord->nEquiv2;
                ++nStackIndex;
            }
        }

        D2_ASSERT(nStackIndex < 64, 2898);
    }

    return 0;
}

// 0x00504AF0
static int __stdcall D2COMP_GetWeaponClass(unsigned int nUnitIndex, const unsigned char* pComponents)
{
    int nRight;
    int nLeft;
    int bTwoWeapons;
    if (pComponents[5] == 0xFF || pComponents[6] == 0xFF)
    {
        bTwoWeapons = 0;
    }
    else
    {
        bTwoWeapons = 1;
    }

    nRight = 0;
    if (pComponents[5] != 0xFF)
    {
        const int nItem = pComponents[5];
        if (bTwoWeapons)
        {
            nRight = gaItemWeaponClass[nItem];
        }
        else
        {
            nRight = gaItems[nItem].nWeaponClass;
            if (pComponents[6] == 0xFF && pComponents[7] == 0xFF && gaItemWeaponClass[pComponents[5]] != gaItems[pComponents[5]].nWeaponClass)
            {
                nRight = gaItemWeaponClass[nItem];
            }
        }

        const int nItemType = gaItems[nItem].nItemType;
        if ((nRight == 13 || nRight == 14) && nUnitIndex != 6 || sub_00504A20_CheckItemType(nItemType, 0x32))
        {
            nRight = gaCompItems[pComponents[5]].nWeaponClass;
        }
    }

    nLeft = 0;
    if (pComponents[6] != 0xFF)
    {
        const int nItem = pComponents[6];
        nLeft = bTwoWeapons ? gaItemWeaponClass[nItem] : gaItems[nItem].nWeaponClass;
        const int nItemType = gaItems[nItem].nItemType;
        if ((nLeft == 13 || nLeft == 14) && nUnitIndex != 6 || sub_00504A20_CheckItemType(nItemType, 0x32))
        {
            nLeft = gaCompItems[pComponents[6]].nWeaponClass;
        }
    }

    if ((nRight == 13 || nRight == 14) && nUnitIndex != 6)
    {
        nRight = 0;
    }
    if ((nLeft == 13 || nLeft == 14) && nUnitIndex != 6)
    {
        nLeft = 0;
    }

    if (!nRight && !nLeft)
    {
        return 1;
    }
    if (nRight == nLeft && (nRight == 6 || nRight == 7))
    {
        return nRight;
    }
    if (nRight == 8)
    {
        return nRight;
    }
    if (!nRight)
    {
        return nLeft;
    }
    if (!nLeft)
    {
        return nRight;
    }

    if (nRight == 4 && nLeft == 4)
    {
        return 11;
    }
    if (nRight == 4 && nLeft == 2)
    {
        return 9;
    }
    if (nRight == 2 && nLeft == 4)
    {
        return 12;
    }
    if (nRight == 5 && nLeft == 2)
    {
        return 11;
    }
    if (nLeft == 4 && nRight == 2 || nLeft == 5 && nRight == 2)
    {
        return 11;
    }
    if (nRight == 2 && nLeft == 2)
    {
        return 10;
    }
    if (nRight == 5 && nLeft == 4 || nRight == 4 && nLeft == 5 || nRight == 5 && nLeft == 5)
    {
        return 11;
    }
    if (nRight == 4)
    {
        return 0;
    }
    if (nRight == 13 && nLeft == 13 || nRight == 14 && nLeft == 14)
    {
        return 13;
    }
    if (nRight == 1 && nLeft == 1)
    {
        return 1;
    }
    return 0;
}

// 0x00504D30
void __stdcall D2Win_10159(D2CelFileStrc* pSquelchCelFile, D2CelFileStrc* pSelectedCelFile)
{
    ghSquelchCelFile = pSquelchCelFile;
    gnSquelchCelFileFrameCount = CelFileGetCelsPerDirection(pSquelchCelFile);
    ghSelectedCelFile = pSelectedCelFile;
    gnSelectedCelFileFrameCount = CelFileGetCelsPerDirection(pSelectedCelFile);
}

// 0x00504D60
static void D2COMP_FixComponent(int nComponent, unsigned char* pComponent)
{
    if ((nComponent == 1 || nComponent == 2 || nComponent == 3 || nComponent == 4) && *pComponent > 3)
    {
        if (sub_00504A20_CheckItemType(gaCompItems[*pComponent].nItemType, 3))
        {
            REMAP_COMPONENT(pComponent, *pComponent % 3 + 1);
        }
        if (sub_00504A20_CheckItemType(gaCompItems[*pComponent].nItemType, 0x10))
        {
            REMAP_COMPONENT(pComponent, *pComponent % 3 + 1);
        }
        if (sub_00504A20_CheckItemType(gaCompItems[*pComponent].nItemType, 0xF))
        {
            REMAP_COMPONENT(pComponent, *pComponent % 3 + 1);
        }
        if (sub_00504A20_CheckItemType(gaCompItems[*pComponent].nItemType, 0x33))
        {
            REMAP_COMPONENT(pComponent, *pComponent % 3 + 1);
        }
        else
        {
            *pComponent = *pComponent % 3 + 1;
        }
    }

    if (!nComponent && !sub_00504A20_CheckItemType(gaItems[*pComponent].nItemType, 0x25))
    {
        if (sub_00504A20_CheckItemType(gaCompItems[*pComponent].nItemType, 0x25))
        {
            REMAP_COMPONENT(pComponent, 1);
        }
        else
        {
            *pComponent = 1;
        }
    }
}

// 0x00504F80
void __stdcall D2Win_10145(D2CompositeUnitStrc* pCompositeUnit, unsigned int nUnitIndex, unsigned int nMode, unsigned char* pComponents, const unsigned char* pComponentColors)
{
    D2_ASSERT(pCompositeUnit, 0xCDD);

    D2GfxInfoStrc* pGfxInfo = (D2GfxInfoStrc*)FOG_Alloc(sizeof(D2GfxInfoStrc), ".\\Src\\D2Comp.cpp", 0x866, 0);
    D2_ASSERT(pGfxInfo, 0x867);
    unsigned char* pComponent = pComponents;
    pGfxInfo->pCofInfo = 0;
    pCompositeUnit->pGfxInfo = pGfxInfo;
    pCompositeUnit->nUnitIndex = nUnitIndex;
    if (nUnitIndex >= 7)
    {
        pCompositeUnit->nWClassTokenIndex = 1;
    }
    else
    {
        pCompositeUnit->nWClassTokenIndex = D2COMP_GetWeaponClass(nUnitIndex, pComponent);
        if (!pCompositeUnit->nWClassTokenIndex)
        {
            return;
        }
    }

    pCompositeUnit->nMode = nMode;
    unsigned int i = 0;
    pCompositeUnit->dwFlags |= gdwBitMasks[0];
    pCompositeUnit->dwFlags |= gdwBitMasks[1];
    pCompositeUnit->dwFlags |= gdwBitMasks[2];

    unsigned int* pArmorType = pCompositeUnit->dwArmorType;
    do
    {
        pArmorType[16] = 1;
        if (*pComponent > 0 && *pComponent < 0xFF)
        {
            D2COMP_FixComponent(i, pComponent);
            pArmorType[0] = gaItems[*pComponent].dwCode;
            pArmorType[16] = gaItems[*pComponent].nItemType;
        }
        else
        {
            pArmorType[0] = 0;
        }
        ++i;
        ++pComponent;
        ++pArmorType;
    }
    while (i < 16);

    for (int j = 0; j < 16; ++j)
    {
        const unsigned char nColor = *pComponentColors++;
        pCompositeUnit->nComponentColors[j] = nColor;
        if (nColor != 0xFF)
        {
            pCompositeUnit->nComponentColors[j] = nColor - 1;
        }
    }

    if (D2COMP_ValidateAndLoadCOFForUnit(pCompositeUnit))
    {
        D2Win_10143(pCompositeUnit, nMode);
    }
}

// 0x00505100
void __stdcall D2Win_10146()
{
    D2CompositeUnitStrc* pCompositeUnit = gpCompositeUnitList;
    while (pCompositeUnit)
    {
        D2CompositeUnitStrc* pNext = pCompositeUnit->pNext;
        D2Win_10142_CompUnitDestroy(pCompositeUnit, 0);
        FOG_Free(pCompositeUnit, ".\\Src\\D2Comp.cpp", 0xD38, 0);
        pCompositeUnit = pNext;
    }
    gpCompositeUnitList = 0;
}

extern int gdwGlobal_0087E838; // 0x0087E838

// 0x00505150
int __cdecl D2COMP_GetFirstCompositeUnit()
{
    return gdwGlobal_0087E838;
}

// 0x00505160
D2CompositeUnitStrc* __stdcall D2Win_10148(D2CompositeUnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 0xD4C);
    return ptUnit->pNext;
}

// 0x005051A0
void __stdcall D2Win_10149(D2CompositeUnitStrc* ptUnit, unsigned char nValue)
{
    D2_ASSERT(ptUnit, 0xD57);
    const int nLow = nValue > 0 ? nValue : 0;
    ptUnit->nDirection = nLow < ptUnit->nDirections ? (nValue > 0 ? nValue : 0) : ptUnit->nDirections;
}

// 0x00505200
unsigned char __stdcall D2Win_10150(D2CompositeUnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 0xD61);
    return ptUnit->nDirections;
}

// 0x00505230
int __stdcall D2Win_10169(D2CompositeUnitStrc* ptUnit)
{
    D2_ASSERT(ptUnit, 0xD6B);
    return ptUnit->nFrameCount;
}

// 0x00505260
void __stdcall D2Win_10151(D2CompositeUnitStrc* ptUnit, int nFrame)
{
    D2_ASSERT(ptUnit, 0xD76);
    const int nValue = nFrame > 0 ? nFrame : 0;
    const int nMax = ptUnit->nFrameCount << 8;
    ptUnit->nFrame = nValue < nMax ? nValue : nMax;
}

// 0x005052B0
void __stdcall D2Win_10152(D2CompositeUnitStrc* ptUnit, int nX)
{
    D2_ASSERT(ptUnit, 0xD81);
    ptUnit->nX = nX;
}

// 0x005052F0
void __stdcall D2Win_10153(D2CompositeUnitStrc* ptUnit, int nY)
{
    D2_ASSERT(ptUnit, 0xD8C);
    ptUnit->nY = nY;
}

// 0x00505330
unsigned int __stdcall D2Win_10155(D2CompositeUnitStrc* hCompositeUnit)
{
    D2_ASSERT(hCompositeUnit, 0xD95);
    return hCompositeUnit->dwFlags;
}

// 0x00505360
void __stdcall D2Win_10156(D2CompositeUnitStrc* hCompositeUnit, int nFlags)
{
    D2_ASSERT(hCompositeUnit, 0xDA2);
    hCompositeUnit->dwFlags = nFlags;
}

// 0x005053A0
void __stdcall D2Win_10158(D2CompositeUnitStrc* hCompositeUnit, unsigned char nEmblemIcon, unsigned char nColor1, unsigned char nColor2)
{
    D2_ASSERT(hCompositeUnit, 0xDB0);

    if (nEmblemIcon < 1u || nEmblemIcon > 32u)
    {
        return;
    }

    char szFile[512];
// build: symbol ?gszDataGlobal@* 0x006D4118
    wsprintfA(szFile, "%s\\ui\\emblems\\icon%02dc", gszDataGlobal, nEmblemIcon - 1);
    hCompositeUnit->pEmblemCellFile = ARCHIVE_LoadCellFile(szFile, 0);

    if (nColor1 >= 1u && nColor1 <= 10u)
    {
        hCompositeUnit->nEmblemColor1 = gabEmblemColor1[nColor1 - 1];
    }
    else
    {
        hCompositeUnit->nEmblemColor1 = 0;
    }

    if (nColor2 >= 1u && nColor2 <= 10u)
    {
        hCompositeUnit->nEmblemColor2 = gabEmblemColor2[nColor2 - 1];
    }
    else
    {
        hCompositeUnit->nEmblemColor2 = 0;
    }
}

// 0x00505470
static void D2COMP_LoadItemPalette(const char* szName, int nIndex)
{
    char szPath[256];
    strcpy(szPath, "Data\\Global\\Items\\Palette\\");
    strcat(szPath, szName);
    strcat(szPath, ".dat");
    void* hFile;
    D2_ASSERT(ARCHIVE_OpenFile(0, szPath, &hFile, 1), 0xDD8);
    ARCHIVE_ReadFileToBuffer(0, hFile, gabItemPalettes[nIndex], 0x1500);
    ARCHIVE_CloseFile(0, hFile);
}

// 0x00505550
void __cdecl D2Win_10157()
{
    D2COMP_LoadItemPalette("grey", 1);
    D2COMP_LoadItemPalette("grey2", 2);
    D2COMP_LoadItemPalette("gold", 3);
    D2COMP_LoadItemPalette("brown", 4);
    D2COMP_LoadItemPalette("greybrown", 5);
    D2COMP_LoadItemPalette("invgrey", 6);
    D2COMP_LoadItemPalette("invgrey2", 7);
    D2COMP_LoadItemPalette("invgreybrown", 8);
}

// 0x005055D0
void __fastcall D2COMP_InitEmblemColorTables()
{
    for (int i = 0; i < 10; ++i)
        gabEmblemColor1[i] = D2Win_10034_MixRGB(gaEmblemColorRGB1[i].nRed, gaEmblemColorRGB1[i].nGreen, gaEmblemColorRGB1[i].nBlue);
    for (int i = 0; i < 10; ++i)
        gabEmblemColor2[i] = D2Win_10034_MixRGB(gaEmblemColorRGB2[i].nRed, gaEmblemColorRGB2[i].nGreen, gaEmblemColorRGB2[i].nBlue);
}

static inline int sub_00505640_IsFemaleClass(int nClass)
{
    switch (nClass)
    {
    case 0:
    case 1:
    case 6:
    case 9:
        return 1;
    }
    return 0;
}

// 0x00505640
const char* __stdcall D2Win_10160_GetPlayerTitle(int nClass, int nTitle, int bExpansion)
{
    if (bExpansion)
    {
        if (!sub_00505640_IsFemaleClass(nClass))
        {
            switch (nTitle)
            {
            case 1: return "Slayer ";
            case 2: return "Champion ";
            case 3: return "Patriarch ";
            case 4: return "Destroyer ";
            case 5: return "Conqueror ";
            case 6: return "Guardian ";
            }
        }
        else
        {
            switch (nTitle)
            {
            case 1: return "Slayer ";
            case 2: return "Champion ";
            case 3: return "Matriarch ";
            case 4: return "Destroyer ";
            case 5: return "Conqueror ";
            case 6: return "Guardian ";
            }
        }
    }
    else
    {
        if (!sub_00505640_IsFemaleClass(nClass))
        {
            switch (nTitle)
            {
            case 1: return "Sir ";
            case 2: return "Lord ";
            case 3: return "Baron ";
            case 4: return "Count ";
            case 5: return "Duke ";
            case 6: return "King ";
            }
        }
        else
        {
            switch (nTitle)
            {
            case 1: return "Dame ";
            case 2: return "Lady ";
            case 3: return "Baroness ";
            case 4: return "Countess ";
            case 5: return "Duchess ";
            case 6: return "Queen ";
            }
        }
    }

    return &gszEmptyAssertText;
}

// 0x00505810
int __fastcall D2COMP_DrawCompositeLabel(D2CompositeUnitStrc* unit)
{
 if(!unit){FOG_DisplayHalt(&gszEmptyAssertText,sub_00408090(),1723);exit(-1);}
 if(!(unit->dwFlags & gdwBitMasks[1]))return 0;
 int y=unit->nY+6;
 Unicode text[256];
 int color=0,shadow=0;
 if(unit->nUnitIndex==20){shadow=1;color=3;}
 else if(unit->nUnitIndex==18){color=3;shadow=1;}
 else if(unit->dwFlags & gdwBitMasks[5])color=1;
 unsigned int flags=unit->dwFlags;
 if(unit->dwFlags & gdwBitMasks[8])y+=15;
 if((flags & gdwBitMasks[6]) || (flags & gdwBitMasks[7])){
  const char* title=D2Win_10160_GetPlayerTitle(unit->nUnitIndex,3*((flags>>5)&1)+2*((flags>>7)&1)+((flags>>6)&1),(flags>>12)&1);
  Unicode titleText[256];
  sub_00526F20(titleText,title,255);
  memset(text,0,sizeof(text));
  sub_005267E0(text,titleText);
  sub_00526700(text,(Unicode*)unit->wszCharName);
 }else{
  if(unit->dwProductCode=='D2DV' || unit->dwProductCode=='D2ST' || unit->dwProductCode=='D2XP')
   sub_005267E0(text,(Unicode*)unit->wszCharName);
  else sub_005267E0(text,(Unicode*)unit->wszAccountName);
 }
 Unicode decoration[256];
 if(sub_00526800((Unicode*)unit->wszGuildTag)){
  sub_00526320_ToUnicode(decoration,gszGuildPrefix,256);
  sub_00526700(text,decoration);
  sub_00526700(text,(Unicode*)unit->wszGuildTag);
  sub_00526320_ToUnicode(decoration,gszGuildSuffix,256);
  sub_00526700(text,decoration);
 }
 D2Win_10127_SetFont(12);
 D2COMP_TruncateTextToWidth(text,120);
 int width,height;
 D2Win_10131_GetTextDimensions(text,&width,&height);
 if(shadow)D2Win_10117_DrawText(text,unit->nX-(width>>1)-1,y-1,6,0);
 D2Win_10117_DrawText(text,unit->nX-(width>>1),y,color,0);
 return 1;
}

// build: symbol ??_H@YGXPAXIHP6EPAX0@Z@Z 0x00403040
// 0x00505A80
int __fastcall D2COMP_DrawCompositeHover(D2CompositeUnitStrc* pCompositeUnit)
{
    D2_ASSERT(pCompositeUnit, 1864);

    Unicode wszText[256];
    if (!(pCompositeUnit->dwFlags & gdwBitMasks[3]))
    {
        return 0;
    }

    tagRECT rect;
    SetRect(&rect, pCompositeUnit->nX - 30, pCompositeUnit->nY - 80, pCompositeUnit->nX + 30, pCompositeUnit->nY + 20);
    if (!CONTROL_MouseInsideRect(&rect))
    {
        return 0;
    }

    int nX = pCompositeUnit->nX;
    int nYEnd = pCompositeUnit->nY - 80;
    int nWidth = 0;
    int nHeight = 0;
    D2HoverLineStrc lines[7];
    int nCount = 0;
    int nColor = 0;
    D2Win_10127_SetFont(1);

    if (pCompositeUnit->dwProductCode == 'D2XP')
    {
        sub_00526320_ToUnicode(wszText, "Expansion", 256);
        D2COMP_AddHoverTextLine(wszText, lines, &nCount, &nWidth, &nHeight);
    }

    const int nType = pCompositeUnit->nUnitIndex;
    if (nType == 19)
    {
        sub_00526320_ToUnicode(wszText, "Moderator", 256);
        D2COMP_AddHoverTextLine(wszText, lines, &nCount, &nWidth, &nHeight);
ShowLevel:
        {
            const int nLevel = pCompositeUnit->nCharLevel;
            if (nLevel > 0)
            {
                memset(wszText, 0, sizeof(wszText));
                sub_005269D0(256, wszText, D2LANG_GetStringFromTblIndex(5017), nLevel);
                D2COMP_AddHoverTextLine(wszText, lines, &nCount, &nWidth, &nHeight);

                if (pCompositeUnit->dwFlags & gdwBitMasks[5])
                {
                    D2COMP_AddHoverTextLine(D2LANG_GetStringFromTblIndex(5016), lines, &nCount, &nWidth, &nHeight);
                }

                sub_00526320_ToUnicode(wszText, "Realm: ", 256);
                sub_00526700(wszText, (Unicode*)pCompositeUnit->wszRealmName);
                D2COMP_AddHoverTextLine(wszText, lines, &nCount, &nWidth, &nHeight);
            }
        }
    }
    else if (nType == 20)
    {
        sub_00526320_ToUnicode(wszText, "Sysop", 256);
        D2COMP_AddHoverTextLine(wszText, lines, &nCount, &nWidth, &nHeight);
        nColor = 3;
    }
    else if (nType == 18)
    {
        sub_00526320_ToUnicode(wszText, "Blizzard Rep", 256);
        D2COMP_AddHoverTextLine(wszText, lines, &nCount, &nWidth, &nHeight);
        nColor = 3;
    }
    else if (nType == 23)
    {
        sub_00526320_ToUnicode(wszText, "Speaker", 256);
        D2COMP_AddHoverTextLine(wszText, lines, &nCount, &nWidth, &nHeight);
    }
    else if (nType == 21)
    {
        sub_00526320_ToUnicode(wszText, "Referee", 256);
        D2COMP_AddHoverTextLine(wszText, lines, &nCount, &nWidth, &nHeight);
    }
    else if (nType == 22)
    {
        sub_00526320_ToUnicode(wszText, "Chat", 256);
        D2COMP_AddHoverTextLine(wszText, lines, &nCount, &nWidth, &nHeight);
    }
    else if (nType == 24)
    {
        sub_00526320_ToUnicode(wszText, "Open Character", 256);
        D2COMP_AddHoverTextLine(wszText, lines, &nCount, &nWidth, &nHeight);
    }
    else
    {
        const unsigned int dwProductCode = pCompositeUnit->dwProductCode;
        if (dwProductCode == 'D2DV' || dwProductCode == 'D2XP' || dwProductCode == 'D2ST')
        {
            goto ShowLevel;
        }

        const char* szProduct;
        switch (dwProductCode)
        {
        case 'DRTL':
        case 'DTST':
            szProduct = "Diablo";
            break;
        case 'DSHR':
            szProduct = "Diablo Shareware";
            break;
        case 'SSHR':
            szProduct = "Starcraft Shareware";
            break;
        case 'STAR':
        case 'JSTR':
            szProduct = "Starcraft";
            break;
        case 'SEXP':
            szProduct = "Brood War";
            break;
        case 'W2BN':
            szProduct = "Warcraft II";
            break;
        case 'WAR3':
            szProduct = "Warcraft III";
            break;
        case 'W3XP':
            szProduct = "Frozen Throne";
            break;
        default:
            szProduct = "Unknown";
            break;
        }

        sub_00526320_ToUnicode(wszText, szProduct, 256);
        D2COMP_AddHoverTextLine(wszText, lines, &nCount, &nWidth, &nHeight);
    }

    sub_00526320_ToUnicode(wszText, "Account Name: ", 256);
    sub_00526700(wszText, (Unicode*)pCompositeUnit->wszAccountName);
    D2COMP_AddHoverTextLine(wszText, lines, &nCount, &nWidth, &nHeight);

    const int nBoxHeight = nHeight + 6;
    int nLeft = nX - (nWidth >> 1);
    int nOffset = 0;
    if (nLeft < 0)
    {
        nOffset = -nLeft;
        nLeft = 0;
    }
    else if (nLeft + nWidth > 800)
    {
        nOffset = 800 - nLeft - nWidth;
        nLeft = 800 - nWidth;
    }

    const int nTop = nYEnd - nBoxHeight;
    D2GFX_DrawBox(nLeft, nTop, nLeft + nWidth, nYEnd, 0, 2);
    nX += nOffset;

    int nY = nTop + 3;
    D2_ASSERT(nCount <= 7, 2052);
    const int nValidStrings = nCount;
    for (int i = 0; i < nValidStrings; ++i)
    {
        nY += lines[i].nHeight;
        D2HoverLineStrc* pLine = &lines[i];
        int nLineColor = 0;
        if (!i)
        {
            nLineColor = nColor;
        }
        D2Win_10117_DrawText(pLine->wszText, nX - (pLine->nWidth >> 1), nY, nLineColor, 0);
    }

    return 1;
}

static inline int sub_GetCompPairValue(unsigned int nKey)
{
    for (unsigned int i = 0; i < gnCompPairs; ++i)
    {
        if (nKey == gaCompPairs[i].nKey)
        {
            return gaCompPairs[i].nValue;
        }
    }

    return 0;
}

// 0x00506000
void __stdcall D2COMP_InitCompItems()
{
    if (gbCompItemsInit)
    {
        return;
    }

    gbCompItemsInit = 1;
    memset(gaItems, 0, sizeof(gaItems));

    D2BinFieldStrc aItemTypesFields[] =
    {
        { "code", 0xA, 0, 0x00, &gpCompItemTypesLinker },
        { "equiv1", 0xF, 0, 0x04, &gpCompItemTypesLinker },
        { "equiv2", 0xF, 0, 0x06, &gpCompItemTypesLinker },
        { "repair", 4, 0, 0x08, 0 },
        { "body", 4, 0, 0x09, 0 },
        { "shoots", 0xF, 0, 0x0C, &gpCompItemTypesLinker },
        { "quiver", 0xF, 0, 0x0E, &gpCompItemTypesLinker },
        { "throwable", 4, 0, 0x10, 0 },
        { "reload", 4, 0, 0x11, 0 },
        { "reequip", 4, 0, 0x12, 0 },
        { "autostack", 4, 0, 0x13, 0 },
        { "magic", 4, 0, 0x14, 0 },
        { "normal", 4, 0, 0x16, 0 },
        { "charm", 4, 0, 0x17, 0 },
        { "gem", 4, 0, 0x18, 0 },
        { "beltable", 4, 0, 0x19, 0 },
        { "costformula", 4, 0, 0x20, 0 },
        { "varinvgfx", 4, 0, 0x23, 0 },
        { "invgfx1", 1, 0x1F, 0x24, 0 },
        { "invgfx2", 1, 0x1F, 0x44, 0 },
        { "invgfx3", 1, 0x1F, 0x64, 0 },
        { "invgfx4", 1, 0x1F, 0x84, 0 },
        { "invgfx5", 1, 0x1F, 0xA4, 0 },
        { "end", 0, 0, 0, 0 },
    };

    gpCompItemTypesLinker = sub_006BD040(".\\Src\\D2Comp.cpp", 0xACB);
    gpCompItemTypesTxt = D2COMP_CompileTxt(sub_004FAC80(), "itemtypes", aItemTypesFields,
        &gnCompItemTypesTxtRecordCount, 0xE4);

    D2BinFieldStrc aHitClassFields[] =
    {
        { "code", 0xA, 0, 0, &gpCompHitClassLinker },
        { "end", 0, 0, 0, 0 },
    };

    gpCompHitClassLinker = sub_006BD040(".\\Src\\D2Comp.cpp", 0xAD7);
    gpCompHitClassTxt = D2COMP_CompileTxt(sub_004FAC80(), "hitclass", aHitClassFields, 0, 4);

    D2COMP_LoadItems(sub_004FAC80());

    gaItems[1].dwCode = ' til';
    gaItems[1].nItemType = ITEMTYPE_ARMOR;
    gaItems[1].nWeaponClass = gaWClassTokens[0];
    gaItems[2].dwCode = ' dem';
    gaItems[2].nItemType = ITEMTYPE_ARMOR;
    gaItems[2].nWeaponClass = gaWClassTokens[0];
    gaItems[3].dwCode = ' yvh';
    gaItems[3].nItemType = ITEMTYPE_ARMOR;
    gaItems[3].nWeaponClass = gaWClassTokens[0];

    int nNext = 4;
    for (int i = 0; i < gnItemsTxtRecordCount_008426EC; ++i)
    {
        D2ItemsTxt* pRecord = &gpCompItemsTxt[i];

        unsigned int dwCode;
        if (pRecord->dwAltCode2)
        {
            dwCode = pRecord->dwAltCode2;
        }
        else
        {
            dwCode = pRecord->dwCode;
        }

        int bArmor = 1;
        if (!(sub_00504A20_CheckItemType(pRecord->wType[0], 0x2D) || sub_00504A20_CheckItemType(pRecord->wType[0], 3)
            || sub_00504A20_CheckItemType(pRecord->wType[0], 0x33) || sub_00504A20_CheckItemType(pRecord->wType[0], 0x25))
            || sub_00504A20_CheckItemType(pRecord->wType[0], 0x4B))
        {
            bArmor = 0;
        }

        int j;
        for (j = 0; j < nNext; ++j)
        {
            if (gaItems[j].dwCode == dwCode)
            {
                goto next;
            }
        }

        if (bArmor == 1)
        {
            int nSlot = nNext;
            while ((sub_00504A20_CheckItemType(gaCompItems[nSlot].nItemType, 0x2D)
                       && sub_00504A20_CheckItemType(pRecord->wType[0], 0x2D))
                || (sub_00504A20_CheckItemType(gaCompItems[nSlot].nItemType, 0x32)
                       && sub_00504A20_CheckItemType(pRecord->wType[0], 0x32))
                || gaItems[nSlot].dwCode)
            {
                ++nSlot;
            }

            if (nSlot >= 0xFF)
            {
                nSlot = nNext;
            }

            gaItems[nSlot].dwCode = dwCode;
            gaItems[nSlot].nItemType = pRecord->wType[0];
            gaItems[nSlot].nWeaponClass = gaWClassTokens[sub_GetCompPairValue(pRecord->dwWeapClass)];
            gaItemWeaponClass[nSlot] = gaWClassTokens[sub_GetCompPairValue(pRecord->dwWeapClass2Hand)];

            if (nNext == nSlot)
            {
                ++nNext;
            }
        }
next:
        ;
    }

    gnItems = 0xFF;
}

// 0x005066C0
D2CompositeUnitStrc* __stdcall D2COMP_CreateCompositeUnit(unsigned int nUnitIndex, unsigned int nMode, unsigned char* pComponents, const unsigned char* pComponentColors)
{
    D2CompositeUnitStrc* ptNewUnit = (D2CompositeUnitStrc*)FOG_Alloc(sizeof(D2CompositeUnitStrc), gszD2CompSourceFile, 0xC70, 0);
    D2_ASSERT(ptNewUnit, 0xC71);
    memset(ptNewUnit, 0, sizeof(D2CompositeUnitStrc));

    D2GfxInfoStrc* ptGfxInfo = (D2GfxInfoStrc*)FOG_Alloc(sizeof(D2GfxInfoStrc), gszD2CompSourceFile, 0x866, 0);
    D2_ASSERT(ptGfxInfo, 0x867);
    ptGfxInfo->pCofInfo = 0;
    ptNewUnit->pGfxInfo = ptGfxInfo;
    D2COMP_InitCompItems();
    unsigned char* pComponent = pComponents;
    ptNewUnit->nUnitIndex = nUnitIndex;
    if (nUnitIndex >= 7)
    {
        ptNewUnit->nWClassTokenIndex = 1;
    }
    else
    {
        ptNewUnit->nWClassTokenIndex = D2COMP_GetWeaponClass(nUnitIndex, pComponent);
        if (!ptNewUnit->nWClassTokenIndex)
        {
            return 0;
        }
    }

    ptNewUnit->nMode = nMode;
    ptNewUnit->dwFlags |= gdwBitMasks[0];
    ptNewUnit->dwFlags |= gdwBitMasks[1];
    ptNewUnit->dwFlags |= gdwBitMasks[2];

    unsigned int i = 0;
    do
    {
        ptNewUnit->nItemTypes[i] = 1;
        if (*pComponent > 0 && *pComponent < gnItems && *pComponent != 0xFF)
        {
            D2COMP_FixComponent(i, pComponent);
            ptNewUnit->dwArmorType[i] = gaItems[*pComponent].dwCode;
            ptNewUnit->nItemTypes[i] = gaItems[*pComponent].nItemType;
        }
        else
        {
            ptNewUnit->dwArmorType[i] = 0;
        }
        ++pComponent;
        ++i;
    }
    while (i < 16);

    for (int j = 0; j < 16; ++j)
    {
        const unsigned char nColor = *pComponentColors++;
        ptNewUnit->nComponentColors[j] = nColor;
        if (nColor != 0xFF)
        {
            ptNewUnit->nComponentColors[j] = nColor - 1;
        }
    }

    if (D2COMP_ValidateAndLoadCOFForUnit(ptNewUnit) && !D2Win_10143(ptNewUnit, nMode))
    {
        return 0;
    }

    D2CompositeUnitStrc* pHead = gpCompositeUnitList;
    ptNewUnit->pPrev = 0;
    ptNewUnit->pNext = pHead;
    if (pHead)
    {
        pHead->pPrev = ptNewUnit;
    }
    gpCompositeUnitList = ptNewUnit;
    return ptNewUnit;
}

// 0x005068A0
const char* __stdcall D2Win_10161(int nClass, int nLevel, int bExpansion, int bSoftCore)
{
    int nRank;
    if (bSoftCore)
    {
        if (nLevel < 5)
            nRank = 0;
        else if (nLevel < 10)
            nRank = 1;
        else if (nLevel < 15)
            nRank = 2;
        else
            nRank = 3;
    }
    else
    {
        if (nLevel < 4)
            nRank = 0;
        else if (nLevel < 8)
            nRank = 1;
        else if (nLevel < 12)
            nRank = 2;
        else
            nRank = 3;
    }
    if (bExpansion && nRank)
        nRank += 3;
    return D2Win_10160_GetPlayerTitle(nClass, nRank, bSoftCore);
}

// 0x00506910
int __stdcall SMACK_Decode(D2WinSmackStrc* pSmack, const char* szFileName, int nVersion)
{
    D2_ASSERT(pSmack->controlHeader.eType == D2WIN_SMACK, 0x53);
    strncpy(pSmack->szFileName, szFileName, 0x100);
    WINDOW_CloseSmacker(&pSmack->field_140);
    WINDOW_DecodeSmacker(pSmack->szFileName, (unsigned char*)&pSmack->field_140, nVersion);
    strncpy(gszSmackFileName, szFileName, 0x104);
    gnSmackVersion = nVersion;
    return 1;
}

// 0x00506990
int __stdcall SMACK_DeleteFile(D2WinSmackStrc* pSmack)
{
    D2_ASSERT(pSmack->controlHeader.eType == D2WIN_SMACK, 0x66);
    WINDOW_CloseSmacker(&pSmack->field_140);
    if (!gbSmackKeepFile)
        DeleteFileA(pSmack->szFileName);
    return 1;
}

// 0x005069F0
int __stdcall SMACK_SetCoordinates(D2WinSmackStrc* pSmack, int nX, int nY)
{
    D2_ASSERT(pSmack->controlHeader.eType == D2WIN_SMACK, 0x7B);
    pSmack->controlHeader.nImageX = nX;
    pSmack->controlHeader.nImageY = nY;
    pSmack->nMovieX = nX;
    pSmack->nMovieY = nY;
    return 1;
}

// 0x00506C40
void __fastcall WREGISTER_RegisterCommand(void* hWnd, int nType, int nId, D2WinMsgHandler pCallback)
{
    D2_ASSERT(hWnd, 0x13);
    switch (nType)
    {
    case 0:
        D2_ASSERT(nId != 0x111, 0x17);
        D2_ASSERT(nId != 0x101, 0x18);
        D2_ASSERT(nId != 0x100, 0x19);
        SMsgRegisterMessage(hWnd, nId, pCallback);
        break;
    case 1:
        SMsgRegisterCommand(hWnd, nId, pCallback);
        break;
    case 2:
        SMsgRegisterKeyUp(hWnd, nId, pCallback);
        break;
    case 3:
        SMsgRegisterKeyDown(hWnd, nId, pCallback);
        break;
    default:
        return;
    }
}

// 0x00506CF0
void __fastcall WREGISTER_UnregisterCommand(void* hWnd, int nType, int nId, D2WinMsgHandler pCallback)
{
    D2_ASSERT(hWnd, 0x30);
    switch (nType)
    {
    case 0:
        D2_ASSERT(nId != 0x111, 0x34);
        D2_ASSERT(nId != 0x101, 0x35);
        D2_ASSERT(nId != 0x100, 0x36);
        SMsgUnregisterMessage(hWnd, nId, pCallback);
        break;
    case 1:
        SMsgUnregisterCommand(hWnd, nId, pCallback);
        break;
    case 2:
        SMsgUnregisterKeyUp(hWnd, nId, pCallback);
        break;
    case 3:
        SMsgUnregisterKeyDown(hWnd, nId, pCallback);
        break;
    default:
        return;
    }
}

#include "gen/data/Source/D2Win/Src/D2Comp.inc"
