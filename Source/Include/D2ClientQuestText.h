#pragma once
// Client: a quest's text message (quest id, title, text, description, cel, step and state) and the quest log
// state that holds six of them (gtQuestLog_007BF298).

#include "D2Check.h"

#pragma pack(push, 1)
struct D2QuestTextMsgStrc
{
    unsigned char unk0x000[1];
    int nQuestId;
    unsigned short wTitle;
    Unicode wszText[300];
    unsigned short wDesc;
    unsigned char nCelId;
    unsigned char nCelId2;
    unsigned char bStepChanged;
    unsigned char bValid;
    unsigned char nStep;
    int nState;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2QuestLogStateStrc
{
    int nState;
    char unk0x004[4];
    int f_8;
    char unk0x00C[4];
    int nA8;
    char unk0x014[4];
    char bB0;
    char bB1;
    char bB2;
    char bB3;
    char bB4;
    int nIndexB5;
    int nIndexB9;
    char unk0x025[0x14];
    void* pCelD1;
    void* pCelD5;
    void* pCelD9;
    void* pCelDD;
    void* apCel[27];
    void* pCel34D;
    void* pCel351;
    char unk0x0BD[0x54];
    D2QuestTextMsgStrc aMsgs[6];
    int anAnim[6];
    unsigned int anTick[6];
    int nPage;
    char unk0xFC1[0x13];
    int n26C;
    int n270;
};
#pragma pack(pop)

struct D2QuestUiFlagsStrc
{
    char bLocked;
    unsigned char unk0x01[0xA2];
    unsigned char abFlags[41];
    unsigned char unk0xCC;
    unsigned char abFlagsB[41];
};
