#pragma once
// Client: the state of the NPC/object text panel and the chat text lists, one pack(1) block at 0x007BF1E4.
// The code addresses its members at odd offsets (0x7BF23B, 0x7BF23F, ...), so it was one packed struct.

#include "D2Check.h"
#include "D2Client.h"

struct D2TextNodeStrc;
struct D2ClientTextDataStrc;

#pragma pack(push, 1)
// A list of text nodes as the panel block keeps it: the first node and the count, six bytes.
struct D2TextPanelListStrc
{
    D2TextNodeStrc* pFirst; // 0x00
    unsigned short wCount; // 0x04
};

struct D2ClientTextStateStrc
{
    D2TextPanelListStrc tMessageList; // 0x00 chat messages
    D2TextPanelListStrc tOverheadList; // 0x06 overhead messages
    D2TextPanelListStrc tHistory; // 0x0C up to 128 sent lines
    unsigned long nTextDisplaySetting; // 0x12
    int bTextPanelOpen; // 0x16
    int unk0x1A; // 0x1A
    int nTextNpcId; // 0x1E
    int nTextObjectId; // 0x22
    int bTextFromObject; // 0x26
    int nGameFrame; // 0x2A
    unsigned short wTextStringId; // 0x2E
    D2RectStrc tHoverOffset; // 0x30
    int nHoverRectCount; // 0x40
    D2ClientTextDataStrc* pTextData; // 0x44
    unsigned long nStartTick; // 0x48
    int bTextSound; // 0x4C
    unsigned short wTextPanelClassId; // 0x50
    int bTextSide; // 0x52
    unsigned char bTextHoverSet; // 0x56
    int nTextHoverUnitId; // 0x57
    int bTextCallbackAccepted; // 0x5B
    unsigned int dwScrollTick; // 0x5F
    unsigned int nScrollCounter; // 0x63
    int hHintSound; // 0x67
};
#pragma pack(pop)

D2_CHECK_SIZE(D2TextPanelListStrc, 0x06);
D2_CHECK_SIZE(D2ClientTextStateStrc, 0x6B);

extern D2ClientTextStateStrc gtTextState; // 0x007BF1E4
