#pragma once
// D2Common's message lists (TEXT_ functions): a menu and string id per entry, eight entries per list.

struct D2MessageStrc
{
    unsigned char nMenu; // 0x00
    unsigned char pad0x01; // 0x01
    unsigned short nStringId; // 0x02
};

struct D2MessageListStrc
{
    unsigned char bCount; // 0x00
    unsigned char pad0x01; // 0x01
    D2MessageStrc pMessages[8]; // 0x02
};
