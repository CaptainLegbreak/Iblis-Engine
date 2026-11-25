#pragma once
// Client: UI panels, dialogs, text lists, hints, option menus, automap cells and notifications.

#include "D2Check.h"
#include "D2Structs.h"
#include "D2ClientTypes.h"
#include "D2Unicode.h"
#include "D2ClientSound.h"

struct D2BnetChatPacketStrc;
struct D2DialogWidgetNodeStrc;
struct D2SlotObjectStrc;
struct D2SoundStrc;
struct D2TextNodeStrc;
struct D2DialogLineStrc;
struct D2TimedHintEntryStrc;
struct SMSGHANDLER_PARAMS;
struct D2ClientNotifyStrc;
struct D2AutomapCellStrc;
struct D2InvCompGridStrc;
struct D2TextListStrc;
struct D2OptionHeaderStrc;
struct D2OptionEntryStrc;
struct D2ClientDialogStrc;
struct D2UiRectStrc;
struct D2UiRecordStrc;
struct D2TimedHintNodeStrc;
struct D2SoundPosStrc;
struct D2SlotStrc;

struct D2ClientNotifyStrc
{
    int unk0x00[5]; // 0x00
    void (__fastcall* pfnResign)(const char*); // 0x14
    int unk0x18[3]; // 0x18
    int (__fastcall* pfnGetMessage)(int*, D2BnetChatPacketStrc*); // 0x24
    int unk0x28[3]; // 0x28
    void (__fastcall* pfnCharUpdate)(char*, char*, char*, int); // 0x34
    int unk0x38[22]; // 0x38
    void (__cdecl* pfnNotify)(void); // 0x90
};

struct D2AutomapCellStrc
{
    unsigned int fSaved; // 0x00
    short nCellNo; // 0x04
    short xPixel; // 0x06
    short yPixel; // 0x08
    short wWeight; // 0x0A
    D2AutomapCellStrc* pPrev; // 0x0C
    D2AutomapCellStrc* pNext; // 0x10
};

struct D2InvCompGridStrc
{
    D2InvRectStrc rect; // 0x00
    unsigned char nWidth; // 0x10
    unsigned char nHeight; // 0x11
    unsigned short unk0x12; // 0x12
};

struct D2TextListStrc
{
    D2TextNodeStrc* pFirst; // 0x00
    unsigned short wCount; // 0x04
    unsigned short unk0x06; // 0x06
    int unk0x08[2]; // 0x08
    unsigned short nWidth; // 0x10
    unsigned short nHeight; // 0x12
};

struct D2OptionHeaderStrc
{
    int nCount; // 0x00
    int nHeight; // 0x04
    int nTextOffset; // 0x08
    int nArrowOffset; // 0x0C
    int nY; // 0x10
};

struct D2OptionEntryStrc
{
    int nKind; // 0x00
    int bExpansionOnly; // 0x04
    int nY; // 0x08
    char szCelName[260]; // 0x0C
    int (__cdecl* pfnEnabled)(void); // 0x110
    void (__fastcall* pfnChanged)(D2OptionEntryStrc*, SMSGHANDLER_PARAMS*); // 0x114
    void (__fastcall* pfnLoad)(D2OptionEntryStrc*, int); // 0x118
    void (__fastcall* pfnInit)(D2OptionEntryStrc*, int); // 0x11C
    unsigned int nValues; // 0x120
    unsigned int nValue; // 0x124
    int bEnabled; // 0x128
    char szValueCels[4][260]; // 0x12C
    D2CelFileStrc* pCel; // 0x53C
    D2CelFileStrc* pValueCels[4]; // 0x540
};

struct D2DialogLineStrc
{
    Unicode wszText[0x78]; // 0x00
    int nHeight; // 0xF0
    int nX; // 0xF4
    int nWidth; // 0xF8
    int nArg4; // 0xFC
    int nFont; // 0x100
    int nType; // 0x104
    int (__cdecl* pfnCallback)(); // 0x108
    int bEnabled; // 0x10C
};

struct D2ClientDialogStrc
{
    unsigned long dwTick; // 0x00
    int unk0x04; // 0x04
    void* pCelFile; // 0x08
    int bDrawCel; // 0x0C
    int bActive; // 0x10
    int bCountEnabled; // 0x14
    int bConsumeKeys; // 0x18
    int bModal; // 0x1C
    int bKeepKeys; // 0x20
    int nCenterX; // 0x24
    int nCenterY; // 0x28
    int nX; // 0x2C
    int nY; // 0x30
    int nWidth; // 0x34
    int nHeight; // 0x38
    int unk0x3C[2]; // 0x3C
    int nHover; // 0x44
    int nPressedItem; // 0x48
    int nEnabled; // 0x4C
    int nLines; // 0x50
    unsigned int nState; // 0x54
    int bAutoSize; // 0x58
    int nMode; // 0x5C
    void (__cdecl* pfnDefault)(void); // 0x60
    int (__cdecl* pfnOutside)(void); // 0x64
    D2DialogLineStrc pLines[10]; // 0x68
    D2DialogWidgetNodeStrc* pWidgets; // 0xB08
    D2ClientDialogStrc* pNext; // 0xB0C
};

struct D2UiRectStrc
{
    int nLeft; // 0x00
    int nRight; // 0x04
    int nTop; // 0x08
    int nBottom; // 0x0C
};

struct D2UiRecordStrc
{
    int unk0x00; // 0x00
    unsigned char nBoxes; // 0x04
    unsigned char unk0x05; // 0x05
    unsigned short unk0x06; // 0x06
    D2UiRectStrc aRects[16]; // 0x08
};

struct D2TimedHintNodeStrc
{
    D2TimedHintEntryStrc* pEntry; // 0x00
    D2TimedHintNodeStrc* pNext; // 0x04
};

struct D2SoundPosStrc
{
    float fX; // 0x00
    float fY; // 0x04
    float fZ; // 0x08
};

struct D2SlotStrc
{
    D2SoundStrc* pSound; // 0x00
    int nType; // 0x04
    D2SlotObjectStrc* pObject; // 0x08
    D2SoundPosStrc tPos; // 0x0C
    int nVolume; // 0x18
    float fAttenuation; // 0x1C
};

D2_CHECK_SIZE(D2SoundPosStrc, 0xC);
D2_CHECK_SIZE(D2ClientNotifyStrc, 0x94);
D2_CHECK_SIZE(D2AutomapCellStrc, 0x14);
D2_CHECK_SIZE(D2InvCompGridStrc, 0x14);
D2_CHECK_SIZE(D2TextListStrc, 0x14);
D2_CHECK_SIZE(D2OptionHeaderStrc, 0x14);
D2_CHECK_SIZE(D2OptionEntryStrc, 0x550);
D2_CHECK_SIZE(D2DialogLineStrc, 0x110);
D2_CHECK_SIZE(D2ClientDialogStrc, 0xB10);
D2_CHECK_SIZE(D2UiRectStrc, 0x10);
D2_CHECK_SIZE(D2UiRecordStrc, 0x108);
D2_CHECK_SIZE(D2TimedHintNodeStrc, 0x8);
D2_CHECK_SIZE(D2SlotStrc, 0x20);
