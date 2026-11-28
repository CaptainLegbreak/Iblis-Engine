#pragma once
// Client: the quest log and quest panel records (the quest table and the button layout).

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

struct D2ButtonLayoutStrc
{
    int nTextX; // 0x00
    int nRight; // 0x04
    int nTop; // 0x08
    int nBottom; // 0x0C
    int nTextY; // 0x10
};
