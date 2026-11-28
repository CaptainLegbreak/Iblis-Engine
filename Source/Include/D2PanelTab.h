#pragma once

// One tab of the NPC trade panel (gaNpcTabs, 4 entries of 0x12 bytes).
#pragma pack(push, 1)
struct D2PanelTabStrc
{
    int nX;
    int nY;
    unsigned short nString;
    int bSelected;
    int bEnabled;
};
#pragma pack(pop)
