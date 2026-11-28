#pragma once
// The server's system error packet (0xB4): the game server sends it when it drops a client for an error.

#pragma pack(push, 1)

struct D2GSPacketSrvB4
{
    unsigned char nHeader; // 0x00
    unsigned int nErrorCode; // 0x01
};

#pragma pack(pop)
