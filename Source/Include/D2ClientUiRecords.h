#pragma once
// Client: small UI records several units share (the UI-variable close-kind table, a UI cel file with
// its path, the NPC menu and panel buttons, panel labels, and the item-type and speed name tables).

#include "D2Check.h"

struct D2UIVarRecordStrc
{
    int anCloseKind[0x26]; // 0x00
};

#pragma pack(push, 2)
struct D2UiCelFileStrc
{
    void* pCelFile; // 0x00
    char szPath[0x1E]; // 0x04
};
#pragma pack(pop)

#pragma pack(push, 2)
struct D2NpcButtonStrc
{
    int nId;
    int bActive;
    unsigned short nTextId;
    int nMode;
    unsigned short nKey;
    int nArg;
};
#pragma pack(pop)

#pragma pack(push, 2)
struct D2PanelButtonStrc
{
    int bActive;
    int nValue;
    unsigned short nString;
    int nCel;
    unsigned short nFrame;
    int nType;
};
#pragma pack(pop)

#pragma pack(push, 2)
struct D2PanelLabelStrc
{
    int nX;
    int nX2;
    int nY;
    unsigned short nString;
};
#pragma pack(pop)

#pragma pack(push, 2)
struct D2ItemTypeNameStrc
{
    int nItemType;
    unsigned short nString;
};
#pragma pack(pop)

struct D2SpeedNameStrc
{
    unsigned short nString;
    unsigned short unk0x02[2];
};

struct D2HirelingIconRecordStrc
{
    int unk0x00[5];
};
