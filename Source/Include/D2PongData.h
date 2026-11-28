#pragma once
// Client: the data of the server's pong (packet 0x8F), kept in gtPongData (0x007A04D4). The last three
// words are the encoded name and offset that inv.cpp's check decodes.

#include "D2Check.h"

struct D2PongDataStrc
{
    unsigned long dwData0; // 0x00
    unsigned long dwData1; // 0x04
    unsigned long dwData2; // 0x08
    unsigned long dwData3; // 0x0C
    unsigned long dwTick; // 0x10
    unsigned long dwEncodedName0; // 0x14
    unsigned long dwEncodedName1; // 0x18
    unsigned long dwEncodedOffset; // 0x1C
};

D2_CHECK_SIZE(D2PongDataStrc, 0x20);

extern D2PongDataStrc gtPongData; // 0x007A04D4
