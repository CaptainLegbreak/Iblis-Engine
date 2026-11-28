#pragma once
// The game server's NPC transaction result (packet 0x2A): the server's D2GAME_SendPacket0x2A builds it, and the
// client's NPC menu keeps the last one (gtNpcMenu.tPacket2A).

#pragma pack(push, 1)
struct D2PacketSrv2AStrc
{
    unsigned char nHeader; // 0x00
    unsigned char nTransactionType; // 0x01
    unsigned char nResult; // 0x02
    unsigned int unused0x03; // 0x03
    int nUnitGUID; // 0x07
    int nGold; // 0x0B
};
#pragma pack(pop)
