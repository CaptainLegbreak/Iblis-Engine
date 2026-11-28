#pragma once
// D2Lang string table, character set and UTF conversion records

#include "D2Check.h"

struct Unicode;
struct D2LangByteRangeStrc;
struct D2UtfConvertSpecStrc;
struct D2TblNodeStrc;
struct D2TblHeaderStrc;
struct D2LangCharSetStrc;

struct D2LangByteRangeStrc
{
    unsigned char nLow; // 0x00
    unsigned char nHigh; // 0x01

    int UNISYS_Contains(unsigned char nValue) const; // 0x005276C0
};

struct D2UtfConvertSpecStrc
{
    unsigned short nMask; // 0x00
    short nLeading; // 0x02
    short nTrailingBits; // 0x04
    short pad0x06; // 0x06
    int nLast; // 0x08
    int nFirst; // 0x0C
};

#pragma pack(push, 1)

struct D2TblNodeStrc
{
    unsigned char bUsed; // 0x00
    unsigned short nIndexNo; // 0x01
    unsigned int dwHashValue; // 0x03
    unsigned int dwStringOffset; // 0x07
    unsigned int dwKeyOffset; // 0x0B
    unsigned short nNameLen; // 0x0F
};

struct D2TblHeaderStrc
{
    unsigned short nCRC; // 0x00
    unsigned short nNumElements; // 0x02
    int nHashTableSize; // 0x04
    unsigned char nVersion; // 0x08
    unsigned int dwIndexStart; // 0x09
    unsigned int dwNumLoops; // 0x0D
    unsigned int dwFileSize; // 0x11
};

#pragma pack(pop)

struct D2LangCharSetStrc
{
    char szChars[1]; // 0x00

    bool ContainsChar(const Unicode* pChar) const; // 0x00527090
};

D2_CHECK_SIZE(D2LangByteRangeStrc, 0x2);
D2_CHECK_SIZE(D2UtfConvertSpecStrc, 0x10);
D2_CHECK_SIZE(D2TblNodeStrc, 0x11);
D2_CHECK_SIZE(D2TblHeaderStrc, 0x15);
D2_CHECK_SIZE(D2LangCharSetStrc, 0x1);
