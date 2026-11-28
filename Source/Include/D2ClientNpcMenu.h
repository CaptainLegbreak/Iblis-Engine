#pragma once
// D2Client: the NPC menu's state (npcmenu.cpp's gtNpcMenu) and the records it holds.

#include "D2PacketSrv2A.h"

struct D2BitBufferStrc;
struct D2ClientDialogStrc;
struct D2ClientObjectStrc;
struct D2NpcEntryStrc;
struct D2UnitStrc;
class D2NpcTradeObjStrc;
class ListBoxWrapper;

// One of the NPC menu's 10 slots (the hireling list): the hireling id, its seed, and its unit id (0 = free).
struct D2ClientItemSlotStrc
{
    unsigned short wId;
    unsigned short pad0x02;
    unsigned int dwSeed;
    int nUnitId;
    int unused0x0C;
};

struct D2ClientStringListStrc
{
    unsigned short awStrings[10];
    unsigned short wCount;
};

// The NPC menu's state, one packed block at 0x007C0C68 (NPCMENU_InitNpcMenu clears its first 0x160 bytes).
#pragma pack(push, 1)
struct D2NpcMenuStateStrc
{
    char bState; // 0x000
    char bMessageShown; // 0x001
    unsigned char bEntriesProcessed; // 0x002
    int nMenuState; // 0x003
    int unused0x07; // 0x007
    int nGoldSnapshot; // 0x00B
    unsigned short wGreetingString; // 0x00F
    unsigned short wMessageString; // 0x011
    unsigned short wLastString; // 0x013
    D2NpcEntryStrc* pEntry; // 0x015
    int nEntryIndex; // 0x019
    D2ClientItemSlotStrc aItemSlots[10]; // 0x01D
    int nInteractNpcId; // 0x0BD
    int bInteracting; // 0x0C1
    int nInteractNpcClassId; // 0x0C5
    int nTradeMode; // 0x0C9
    int unused0xCD; // 0x0CD
    int bSubIdReceived; // 0x0D1
    short wSubId; // 0x0D5
    int bTradeItemOnCursor; // 0x0D7
    D2BitBufferStrc* pPlayerQuestFlags; // 0x0DB
    D2BitBufferStrc* pGameQuestFlags; // 0x0DF
    int nTradeClickX; // 0x0E3
    int nTradeClickY; // 0x0E7
    unsigned long dwRequestTimeout; // 0x0EB
    int dwTransactionTick; // 0x0EF
    int nTradeItemDropSound; // 0x0F3
    D2ClientDialogStrc* pTradeDialog; // 0x0F7
    D2ClientDialogStrc* pSubMenuDialog; // 0x0FB
    D2ClientDialogStrc* pWaitDialog; // 0x0FF
    D2ClientDialogStrc* pMainMenuDialog; // 0x103
    D2ClientDialogStrc* pMessageDialog; // 0x107
    D2ClientDialogStrc* pConfirmDialog; // 0x10B
    D2ClientDialogStrc* pHireDialog; // 0x10F
    D2ClientDialogStrc* pGreetingDialog; // 0x113
    int nTransactionCost; // 0x117
    union { D2NpcTradeObjStrc* pTradeObj; D2ClientObjectStrc* pObject; ListBoxWrapper* pListBox; }; // 0x11B
    D2PacketSrv2AStrc tPacket2A; // 0x11F the last NPC transaction result
    int bActionPending; // 0x12E
    D2ClientStringListStrc tStringList; // 0x132
    int bGambleShop; // 0x148
    int nSoundActive; // 0x14C
    int nSoundHandle; // 0x150
    int bWaitSoundPlayed; // 0x154
    int bWaitSoundScheduled; // 0x158
    unsigned long dwWaitSoundTick; // 0x15C
    void* pBuySellCel; // 0x160
    void* pGoldBtnCel; // 0x164
    int nMenuValue; // 0x168
    D2UnitStrc* pPlayerUnit; // 0x16C
    unsigned short wGlobal170; // 0x170
    unsigned char bObjectFound; // 0x172
    unsigned char unused0x173[5]; // 0x173
    char bTradeClickPending; // 0x178
    int nTradeItemClassId; // 0x179
    int nTradeItemUnitId; // 0x17D
    unsigned long dwTradeRequestTick; // 0x181
    int nTradeRequestFailCount; // 0x185
    unsigned long dwLastTradeSendTick; // 0x189
};
#pragma pack(pop)

extern D2NpcMenuStateStrc gtNpcMenu; // 0x007C0C68

// The NPC the menu is talking to, or 0 when it isn't talking to one.
#define NPC_GET_INTERACT_UNIT() (gtNpcMenu.bInteracting ? CUNIT_FindClientUnit(gtNpcMenu.nInteractNpcId, 1) : 0)
