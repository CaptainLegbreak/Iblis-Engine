#pragma once
// Client: the quest log and quest panel records (the quest table, the panel entries and the button layout).

#include "D2Check.h"

struct D2QuestTextsStrc;

struct D2QuestTableStrc
{
    unsigned char bEnabled; // 0x00
    unsigned char nCelId; // 0x01
    unsigned char nCelId2; // 0x02
    unsigned char nPage; // 0x03
    D2QuestTextsStrc* pTexts; // 0x04
    int nCondition; // 0x08
    int nQuestId; // 0x0C
};

#pragma pack(push, 1)
struct D2QuestPanelEntryStrc
{
    int nQuestId; // 0x00
    char unk0x004[0x25E - 0x004]; // 0x04
    unsigned short wTextId; // 0x25E
    unsigned char nSlot; // 0x260
    char unk0x261[0x263 - 0x261]; // 0x261
    unsigned char bEnabled; // 0x263
    char unk0x264[0x265 - 0x264]; // 0x264
    int bDone; // 0x265
    char unk0x269[0x26A - 0x269]; // 0x269
};
#pragma pack(pop)

struct D2ButtonLayoutStrc
{
    int nTextX; // 0x00
    int nRight; // 0x04
    int nTop; // 0x08
    int nBottom; // 0x0C
    int nTextY; // 0x10
};
