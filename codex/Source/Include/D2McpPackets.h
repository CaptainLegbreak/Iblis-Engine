#pragma once
// MCP client: the realm (MCP) protocol packets the client builds and parses.

#include "D2Check.h"

#pragma pack(push, 1)
struct D2McpPacket02Strc
{
    unsigned char nPacketId;
    int nValue;
    unsigned short wValue;
    char szText[0x400];
};

struct D2McpPacket07Strc
{
    unsigned char nPacketId;
    char szText[0x400];
};

struct D2McpPacket04Strc
{
    unsigned char nPacketId;
    unsigned short wRequestId;
    char szText[0x400];
};

struct D2McpPacket08Strc
{
    unsigned char nPacketId;
    unsigned short wRequestId;
    char szText[0x400];
};

struct D2McpPacket09Strc
{
    unsigned char nPacketId;
    unsigned short wRequestId;
    char szText[0x400];
};

struct D2McpPacket0BStrc
{
    unsigned char nPacketId;
    char szText[0x400];
};

struct D2McpPacket0CStrc
{
    unsigned char nPacketId;
    char szText[0x400];
};

struct D2McpPacket16Strc
{
    unsigned char nPacketId;
    int nValue01;
    int nValue05;
    char szText[0x400];
};

struct D2McpPacket05Strc
{
    unsigned char nPacketId;
    unsigned short wRequestId;
    union
    {
        unsigned int dwFlags;
        int nValue;
    };
    union
    {
        struct
        {
            char szText[0x400];
        };
        struct
        {
            unsigned char nCount;
            int nToken;
            char szData[1];
        };
    };
};

struct D2McpPacket06Strc
{
    unsigned char nPacketId;
    unsigned short wRequestId;
    char szText[0x400];
};

struct D2McpPacket0AStrc
{
    unsigned char nPacketId;
    unsigned short wRequestId;
    char szText[0x400];
};

struct D2McpPacket18Strc
{
    unsigned char nPacketId;
    char szText[0x400];
};

struct D2McpPacket10Strc
{
    unsigned char nPacketId;
    int nValueB0;
    int nValue88;
    int nAddress;
    int nCode;
};

struct D2McpPacket01Strc
{
    unsigned char nPacketId;
    int nValue01;
    int nValue05;
    int nValue09;
    int nValue0D;
    int nValue11;
    int nValue15;
    int nValue19;
    int nValue1D;
    int nValue21;
    int nValue25;
    int nValue29;
    int nValue2D;
    int nValue31;
    int nValue35;
    int nValue39;
    int nValue3D;
    char szText[0x400];
};

struct D2McpPacket03Strc
{
    unsigned char nPacketId;
    unsigned short wRequestId;
    int nValue;
    unsigned char nByte07;
    unsigned char nByte08;
    unsigned char nByte09;
    char szText[0x400];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2McpPacketValueStrc
{
    unsigned char nPacketId;
    int nValue;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2McpIncoming03Strc
{
    unsigned char nPacketId;
    unsigned short wRequestId;
    int nValueB0;
    int nCode;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2McpIncoming04Strc
{
    unsigned char nPacketId;
    unsigned short wRequestId;
    int nValueB0;
    int nAddress;
    int nValue88;
    int nCode;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2McpIncoming0AStrc
{
    unsigned char nPacketId;
    unsigned short wRequestId;
    int nCode;
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2McpIncoming08Strc
{
    unsigned char nPacketId;
    unsigned short wRequestId;
    unsigned char aData[1];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2McpIncoming09Strc
{
    unsigned char nPacketId;
    unsigned short wRequestId;
    unsigned char nByte03;
    unsigned char aData[1];
};
#pragma pack(pop)

#pragma pack(push, 1)
struct D2McpIncoming0EStrc
{
    unsigned char nPacketId;
    char szText[1];
};
#pragma pack(pop)

struct D2McpCreateGameStrc
{
    char szName[0x10];
    char szPassword[0x10];
    char szDescription[0x20];
    int nValue40;
    unsigned char nByte44;
    unsigned char nByte45;
    unsigned char nByte46;
};
