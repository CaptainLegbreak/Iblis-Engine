#pragma once
// Networking: the Winsock records the network modules declare for themselves.

#include "D2Check.h"

struct D2InAddrStrc;
struct D2SockAddrInStrc;
struct D2WSADataStrc;
struct D2TimevalStrc;
struct D2FdSetStrc;

struct D2InAddrStrc
{
    unsigned long s_addr; // 0x00
};

struct D2SockAddrInStrc
{
    short sin_family; // 0x00
    unsigned short sin_port; // 0x02
    D2InAddrStrc sin_addr; // 0x04
    char sin_zero[8]; // 0x08
};

struct D2WSADataStrc
{
    unsigned short wVersion; // 0x00
    unsigned short wHighVersion; // 0x02
    char szDescription[257]; // 0x04
    char szSystemStatus[129]; // 0x105
    unsigned short iMaxSockets; // 0x186
    unsigned short iMaxUdpDg; // 0x188
    unsigned short pad0x18A; // 0x18A
    char* lpVendorInfo; // 0x18C
};

struct D2TimevalStrc
{
    long tv_sec; // 0x00
    long tv_usec; // 0x04
};

struct D2FdSetStrc
{
    unsigned int fd_count; // 0x00
    unsigned int fd_array[64]; // 0x04
};

struct D2HostentStrc
{
    char* h_name; // 0x00
    char** h_aliases; // 0x04
    short h_addrtype; // 0x08
    short h_length; // 0x0A
    char** h_addr_list; // 0x0C
};

D2_CHECK_SIZE(D2HostentStrc, 0x10);
D2_CHECK_SIZE(D2InAddrStrc, 0x4);
D2_CHECK_SIZE(D2SockAddrInStrc, 0x10);
D2_CHECK_SIZE(D2WSADataStrc, 0x190);
D2_CHECK_SIZE(D2TimevalStrc, 0x8);
D2_CHECK_SIZE(D2FdSetStrc, 0x104);

struct D2PacketBufferStrc
{
    unsigned char data[1976];
    int nUsedBytes;
};
