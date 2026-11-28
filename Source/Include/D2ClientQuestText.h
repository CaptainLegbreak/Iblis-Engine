#pragma once
// Client: a quest's text message (quest id, title, text, description, cel, step and state) and the quest log
// state that holds six of them (gtQuestLog).

#include "D2Check.h"

#pragma pack(push, 1)
struct D2QuestTextMsgStrc
{
    unsigned char bShown;
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

// The quest record the server sends (QUESTLOG_SetQuestRecord): a byte, then one step per quest.
#pragma pack(push, 2)
struct D2Record42Strc
{
    int aData[10];
    unsigned short wLast;
};
#pragma pack(pop)

// The quest log panel's state: one packed global (gtQuestLog, 0x007BF298).
#pragma pack(push, 1)
struct D2QuestLogStateStrc
{
    int nState; // 0x000: 0 closed, 1 or 2 open
    int unused0x04; // 0x04
    int nMsgCount; // 0x008: quests shown on the page
    int nQuestAct; // 0x00C
    unsigned int nA8; // 0x010
    unsigned int nQuestParam; // 0x014
    unsigned char bQuestButtonDown; // 0x018
    unsigned char bQuestSlotDown; // 0x019
    unsigned char bCloseButtonDown; // 0x01A
    char bDescriptionOpen; // 0x01B
    unsigned char bDescButtonDown; // 0x01C
    int nPressedSlot; // 0x01D
    int nSelectedSlot; // 0x021
    int anPageSelection[5]; // 0x025: the selected slot of each act's page
    void* pSocketsCel; // 0x039
    void* pBackgroundCel; // 0x03D
    void* pTabsCel; // 0x041
    void* pDoneCel; // 0x045
    void* apIconCels[27]; // 0x049
    void* pLastCel; // 0x0B5
    void* pInvPsCel; // 0x0B9
    union
    {
        D2Record42Strc tQuestRecord; // 0x0BD
        struct
        {
            unsigned char unused0xBD; // 0xBD
            unsigned char abQuestStepsA[41]; // 0x0BE: the step of each quest, by quest index
        };
    };
    unsigned char unused0xE7; // 0xE7
    unsigned char abQuestStepsB[41]; // 0x0E8: the step last shown, by quest index
    D2QuestTextMsgStrc aMsgs[6]; // 0x111: the quests on the page
    int anAnim[6]; // 0xF8D
    unsigned int anTick[6]; // 0xFA5
    int nPage; // 0xFBD
    unsigned long dwToggleTick; // 0xFC1
    char bDurielCofsLoaded; // 0xFC5
    char bAncientsCofsLoaded; // 0xFC6
    unsigned char bHasQuestPacketValue; // 0xFC7
    char bQuestUnitsSpawned; // 0xFC8
    unsigned int nQuestUnitId; // 0xFC9
    unsigned int nQuestPacketValue; // 0xFCD
    char unused0xFD1[3]; // 0xFD1
    int n26C; // 0xFD4
    int n270; // 0xFD8

    D2QuestLogStateStrc();
};
#pragma pack(pop)

D2_CHECK_SIZE(D2QuestLogStateStrc, 0xFDC);

extern D2QuestLogStateStrc gtQuestLog; // 0x007BF298
