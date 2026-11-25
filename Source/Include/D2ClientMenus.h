#pragma once
// Client: NPC menu entries (1-byte packed, with their gossip choices) and hotkey bindings (2-byte packed).

#include "D2Check.h"
#include "D2Structs.h"

struct D2NpcChoiceStrc;
struct D2NpcEntryStrc;
struct D2HotkeyStrc;

#pragma pack(push, 1)
struct D2NpcChoiceStrc
{
    unsigned short wId; // 0x00
    char bQuest; // 0x02
    int nQuestState; // 0x03
    int nQuestId; // 0x07
    int nClass; // 0x0B
};

struct D2NpcEntryStrc
{
    int nId; // 0x00
    char unk0x04; // 0x04
    D2NpcChoiceStrc* pChoices; // 0x05
    int nChoices; // 0x09
    int nSelected; // 0x0D
    char bSelected; // 0x11
    char bFlag; // 0x12
    char unk0x13; // 0x13
    char bFlag14; // 0x14
    char bRefreshed; // 0x15
};
#pragma pack(pop)

#pragma pack(push, 2)
struct D2HotkeyStrc
{
    int nCommand; // 0x00
    unsigned short nKey; // 0x04
    int nMode; // 0x06
};
#pragma pack(pop)

D2_CHECK_SIZE(D2NpcChoiceStrc, 0xF);
D2_CHECK_SIZE(D2NpcEntryStrc, 0x16);
D2_CHECK_SIZE(D2HotkeyStrc, 0xA);
