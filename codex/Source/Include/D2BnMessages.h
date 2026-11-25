#pragma once
// Battle.net client: the message bodies the client reads from the Battle.net server (client id, versioning,
// logon info and ad checks).

#include "D2Check.h"
#include "D2Win32Base.h"

struct D2BnClientIdReplyStrc
{
    unsigned int dwRegistrationVersion; // 0x00
    unsigned int dwRegistrationAuthority; // 0x04
    unsigned int dwClientId; // 0x08
    unsigned int dwRegistrationToken; // 0x0C
};

struct D2BnStartVersioningStrc
{
    D2FileTimeStrc tFileTime; // 0x00
    char szFileName[4]; // 0x08
};

struct D2BnAuthInfoStrc
{
    unsigned int dwLogonType; // 0x00
    unsigned int dwServerToken; // 0x04
    unsigned int dwUdpValue; // 0x08
    D2FileTimeStrc tFileTime; // 0x0C
    char szFileName[4]; // 0x14
};

struct D2BnCheckAdReplyStrc
{
    unsigned int nAdId; // 0x00
    unsigned int nExtension; // 0x04
    unsigned char pData[1]; // 0x08
};

struct FSafeSock;

struct D2BnServerEntryStrc
{
    char szAddress[0x100];
    FSafeSock* pSafeSock;
    int nUnused;
};
