#pragma once
// Client-to-server game packets as D2Game's handlers read them (PlrMsg.cpp). Member names follow D2MOO;
// member types are the ones the handlers read with.

#pragma pack(push, 1)

struct D2GSPacketClt01 // 0x05 bytes, the move and skill-at-position packets (0x01, 0x03, 0x05, 0x08, 0x0C, 0x0F, ...) PLRMSG_ReadCoordinatePacket reads
{
    unsigned char nHeader; // 0x00
    unsigned short nPosX; // 0x01
    unsigned short nPosY; // 0x03
};

struct D2GSPacketClt06 // 0x09 bytes, the packets aimed at a unit (0x06, 0x09, 0x0A, 0x0D, 0x0E, 0x10, 0x11, ...) PLRMSG_ReadTargetUnitPacket reads
{
    unsigned char nHeader; // 0x00
    unsigned int dwUnitType; // 0x01
    int dwUnitGUID; // 0x05
};

struct D2GSPacketClt13 // 0x09 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x13_InteractWithEntity
{
    unsigned char nHeader; // 0x00
    unsigned int dwUnitType; // 0x01
    int dwUnitGUID; // 0x05
};

struct D2GSPacketClt16 // 0x0D bytes, read by D2GAME_PACKETCALLBACK_Rcv0x16_PickItemOnGround
{
    unsigned char nHeader; // 0x00
    unsigned int dwUnitType; // 0x01
    int dwUnitGUID; // 0x05
    int bCursor; // 0x09
};

struct D2GSPacketClt17 // 0x05 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x17_DropItemOnGround
{
    unsigned char nHeader; // 0x00
    int dwItemGUID; // 0x01
};

struct D2GSPacketClt18 // 0x11 bytes, read by sInsertItemGrid
{
    unsigned char nHeader; // 0x00
    int dwItemGUID; // 0x01
    int dwPosX; // 0x05
    int dwPosY; // 0x09
    unsigned int dwInvPage; // 0x0D
};

struct D2GSPacketClt19 // 0x05 bytes, read by sRemoveItemGrid
{
    unsigned char nHeader; // 0x00
    int dwItemGUID; // 0x01
};

struct D2GSPacketClt1A // 0x09 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x1A_EquipItem
{
    unsigned char nHeader; // 0x00
    int nItemGUID; // 0x01
    unsigned char nBodyLoc; // 0x05
    unsigned char unused0x06[3]; // 0x06
};

struct D2GSPacketClt1B // 0x09 bytes, read by sInsertItemBodyRmvOpp
{
    unsigned char nHeader; // 0x00
    int nItemGUID; // 0x01
    unsigned char nBodyLoc; // 0x05
    unsigned char unused0x06[3]; // 0x06
};

struct D2GSPacketClt1C // 0x03 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x1C_RemoveBodyItem
{
    unsigned char nHeader; // 0x00
    unsigned short nBodyLoc; // 0x01
};

struct D2GSPacketClt1D // 0x09 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x1D_SwapCursorItemWithBody
{
    unsigned char nHeader; // 0x00
    int nItemGUID; // 0x01
    unsigned char nBodyLoc; // 0x05
    unsigned char unused0x06[3]; // 0x06
};

struct D2GSPacketClt1E // 0x09 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x1E_SwapTwo1HandedWithOne2HandedItem
{
    unsigned char nHeader; // 0x00
    int nItemGUID; // 0x01
    unsigned char nBodyLoc; // 0x05
    unsigned char unused0x06[3]; // 0x06
};

struct D2GSPacketClt21 // 0x09 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x21_StackItems
{
    unsigned char nHeader; // 0x00
    int nCursorItemGUID; // 0x01
    int nTargetItemGUID; // 0x05
};

struct D2GSPacketClt22 // 0x05 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x22_UnstackItems
{
    unsigned char nHeader; // 0x00
    int nItemGUID; // 0x01
};

struct D2GSPacketClt23 // 0x09 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x23_ItemToBelt
{
    unsigned char nHeader; // 0x00
    int nCursorItemGUID; // 0x01
    int nBeltSlotId; // 0x05
};

struct D2GSPacketClt24 // 0x05 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x24_ItemFromBelt
{
    unsigned char nHeader; // 0x00
    int nItemGUID; // 0x01
};

struct D2GSPacketClt25 // 0x09 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x25_SwitchBeltItem
{
    unsigned char nHeader; // 0x00
    int nCursorItemGUID; // 0x01
    int nBeltItemGUID; // 0x05
};

struct D2GSPacketClt26 // 0x0D bytes, read by D2GAME_PACKETCALLBACK_Rcv0x26_UseBeltItem
{
    unsigned char nHeader; // 0x00
    int nItemGUID; // 0x01
    int bUseOnMerc; // 0x05
    int unused0x09; // 0x09
};

struct D2GSPacketClt27 // 0x09 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x27_UseItemAction
{
    unsigned char nHeader; // 0x00
    int nTargetItemGUID; // 0x01
    int nUseItemGUID; // 0x05
};

struct D2GSPacketClt28 // 0x09 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x28_SocketItem
{
    unsigned char nHeader; // 0x00
    int nCursorItemGUID; // 0x01
    int nTargetItemGUID; // 0x05
};

struct D2GSPacketClt29 // 0x09 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x29_ScrollToBook
{
    unsigned char nHeader; // 0x00
    int nScrollGUID; // 0x01
    int nBookGUID; // 0x05
};

struct D2GSPacketClt2A // 0x09 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x2A_ItemToCubeIndirect
{
    unsigned char nHeader; // 0x00
    int dwItemGUID; // 0x01
    int dwCubeGUID; // 0x05
};

struct D2GSPacketClt2F // 0x09 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x2F_InitEntityChat
{
    unsigned char nHeader; // 0x00
    int nUnitType; // 0x01
    int nUnitGUID; // 0x05
};

struct D2GSPacketClt30 // 0x09 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x30_TerminateEntityChat
{
    unsigned char nHeader; // 0x00
    int unused0x01; // 0x01
    int nUnitGUID; // 0x05
};

struct D2GSPacketClt31 // 0x09 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x31_QuestMessage
{
    unsigned char nHeader; // 0x00
    int nNpcGUID; // 0x01
    unsigned short nMessageId; // 0x05
    unsigned char unused0x07[2]; // 0x07
};

struct D2GSPacketClt33 // 0x11 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x33_SellItemToNpcBuffer
{
    unsigned char nHeader; // 0x00
    int dwMonGUID; // 0x01
    int dwItemGUID; // 0x05
    unsigned short nTab; // 0x09
    unsigned short unused0x0B; // 0x0B
    int dwGold; // 0x0D
};

struct D2GSPacketClt34 // 0x05 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x34_IdentifyItemsWithNpc
{
    unsigned char nHeader; // 0x00
    int nNpcGUID; // 0x01
};

struct D2GSPacketClt35 // 0x11 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x35_Repair
{
    unsigned char nHeader; // 0x00
    int nNpcGUID; // 0x01
    int nItemGUID; // 0x05
    unsigned short nItemMode; // 0x09
    unsigned char unused0x0B[2]; // 0x0B
    int nRepairFlags; // 0x0D
};

struct D2GSPacketClt36 // 0x09 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x36_HireMerc
{
    unsigned char nHeader; // 0x00
    int nNpcGUID; // 0x01
    unsigned short nHirelingId; // 0x05
    unsigned char unused0x07[2]; // 0x07
};

struct D2GSPacketClt37 // 0x05 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x37_IdentifyFromGamble
{
    unsigned char nHeader; // 0x00
    int nItemGUID; // 0x01
};

struct D2GSPacketClt38 // 0x0D bytes, read by D2GAME_PACKETCALLBACK_Rcv0x38_EntityAction
{
    unsigned char nHeader; // 0x00
    int nAction; // 0x01
    int nNpcGUID; // 0x05
    int nItemGUID; // 0x09
};

struct D2GSPacketClt3A // 0x03 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x3A_AddStatPoint
{
    unsigned char nHeader; // 0x00
    unsigned short nStat; // 0x01
};

struct D2GSPacketClt3C // 0x09 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x3C_SelectSkill
{
    unsigned char nHeader; // 0x00
    int nSkill; // 0x01
    int nOwnerGUID; // 0x05
};

struct D2GSPacketClt3D // 0x05 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x3D_HighlightADoor
{
    unsigned char nHeader; // 0x00
    int nDoorGUID; // 0x01
};

struct D2GSPacketClt3E // 0x05 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x3E_ActivateInifussScroll
{
    unsigned char nHeader; // 0x00
    int nItemGUID; // 0x01
};

struct D2GSPacketClt44 // 0x11 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x44_StaffInOrifice
{
    unsigned char nHeader; // 0x00
    int nPlayerGUID; // 0x01
    int nAnvilInteractGUID; // 0x05
    int nItemGUID; // 0x09
    unsigned short nState; // 0x0D
    short unused0x0F; // 0x0F
};

struct D2GSPacketClt4B // 0x09 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x4B_RequestEntityUpdate
{
    unsigned char nHeader; // 0x00
    unsigned int nUnitType; // 0x01
    int nUnitGUID; // 0x05
};

struct D2GSPacketClt4C // 0x05 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x4C_Transmogrify
{
    unsigned char nHeader; // 0x00
    int nItemGUID; // 0x01
};

struct D2GSPacketClt4D // 0x03 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x4D_PlayNpcMessage
{
    unsigned char nHeader; // 0x00
    unsigned short nMonStatsId; // 0x01
};

struct D2GSPacketClt4F // 0x07 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x4F_ClickButton
{
    unsigned char nHeader; // 0x00
    unsigned short nButtonId; // 0x01
    unsigned short nParam1; // 0x03
    unsigned short nParam2; // 0x05
};

struct D2GSPacketClt50 // 0x09 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x50_DropGold
{
    unsigned char nHeader; // 0x00
    int nUnitGUID; // 0x01
    int nGold; // 0x05
};

struct D2GSPacketClt51 // 0x09 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x51_BindHotkeyToSkill
{
    unsigned char nHeader; // 0x00
    unsigned int nSkillId; // 0x01
    int nOwnerGUID; // 0x05
};

struct D2GSPacketClt58 // 0x03 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x58_QuestCompleted
{
    unsigned char nHeader; // 0x00
    unsigned short nQuest; // 0x01
};

struct D2GSPacketClt59 // 0x11 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x59_MakeEntityMove
{
    unsigned char nHeader; // 0x00
    unsigned int nUnitType; // 0x01
    int dwUnitGUID; // 0x05
    int dwTargetX; // 0x09
    int dwTargetY; // 0x0D
};

struct D2GSPacketClt5D // 0x07 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x5D_SquelchHostile
{
    unsigned char nHeader; // 0x00
    unsigned char nType; // 0x01
    unsigned char nToggle; // 0x02
    int dwPlayerGUID; // 0x03
};

struct D2GSPacketClt5E // 0x06 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x5E_InviteToParty
{
    unsigned char nHeader; // 0x00
    unsigned char nType; // 0x01
    int dwPlayerGUID; // 0x02
};

struct D2GSPacketClt61 // 0x03 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x61_DropPickupMercItem
{
    unsigned char nHeader; // 0x00
    unsigned short nBodyLoc; // 0x01
};

struct D2GSPacketClt62 // 0x05 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x62_ResurrectMerc
{
    unsigned char nHeader; // 0x00
    int nNpcGUID; // 0x01
};

struct D2GSPacketClt63 // 0x05 bytes, read by D2GAME_PACKETCALLBACK_Rcv0x63_ShiftLeftClickItemToBelt
{
    unsigned char nHeader; // 0x00
    int dwItemGUID; // 0x01
};

#pragma pack(pop)
