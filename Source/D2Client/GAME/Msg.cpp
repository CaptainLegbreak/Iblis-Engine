#include "D2Client.h"
#include "gen/data/Source/D2Client/GAME/Msg.inc"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2SaveFilePacketStrc;

struct D2RosterPetNodeStrc;

#pragma pack(push, 1)

struct D2SaveFilePacketStrc
{
    unsigned char nHeader;
    unsigned char f_1;
    int nTotalSize;
    unsigned char pData[0x100];
};

#pragma pack(pop)

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" int __cdecl sprintf(char* szDest, const char* szFormat, ...); // 0x006823FD

extern "C" int __cdecl fseek(_iobuf* pFile, long nOffset, int nOrigin); // 0x00684A2A

extern "C" long __cdecl ftell(_iobuf* pFile); // 0x00684935

extern "C" size_t __cdecl fread(void* pBuffer, size_t nSize, size_t nCount, _iobuf* pFile); // 0x00684782

void* __fastcall FOG_Alloc(int nSize, const char* szFile, int nLine, int n0); // 0x0040B380

int __fastcall FOG_Free(void* pFree, const char* szFile, int nLine, int n0); // 0x0040B3C0

int __fastcall FOG_GetSavePath(char* szPath, int nSize); // 0x00407050

void __fastcall MSG_ShowProgressSteps(int nDone, int nTotal); // 0x00478160

extern char gszClientCharName[]; // 0x007A05C4

extern "C" const char gszSavePathFormat_006D4230[]; // 0x006D4230

extern "C" const char gszFileModeRb[]; // 0x006CDC90

extern int gnSentBytes; // 0x007A6AF8

extern int gnSentPackets; // 0x007A6B00

int gnProgress; // 0x007BB3B4

int __stdcall CelFileFreeHardware(D2CelFileStrc* pCelFile); // 0x00601A50

extern D2RosterPetNodeStrc* gpRosterPets; // 0x007BB5BC

struct D2PacketDwords9Strc;

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

extern "C" int __cdecl memcmp(const void* p1, const void* p2, unsigned int nSize);

unsigned char gaLastSentPacket[0x200]; // 0x007BB3B8

unsigned int gdwLastSendTick; // 0x007BB5B8

#pragma pack(push, 1)

struct D2PacketDwords9Strc
{
    unsigned char nHeader;
    unsigned int d1;
    unsigned int d5;
};

struct D2PacketSize1Strc
{
    unsigned char nHeader;
};

struct D2PacketSize3Strc
{
    unsigned char nHeader;
    unsigned short w1;
};

struct D2PacketShorts5Strc
{
    unsigned char nHeader;
    unsigned short w1;
    unsigned short w3;
};

struct D2PacketShorts7Strc
{
    unsigned char nHeader;
    unsigned short w1;
    unsigned short w3;
    unsigned short w5;
};

struct D2PacketShorts9Strc
{
    unsigned char nHeader;
    unsigned short w1;
    unsigned short w3;
    unsigned short w5;
    unsigned short w7;
};

struct D2PacketDword5Strc
{
    unsigned char nHeader;
    unsigned int d1;
};

struct D2PacketDwords13Strc
{
    unsigned char nHeader;
    unsigned int d1;
    unsigned int d5;
    unsigned int d9;
};

struct D2PacketDwords17Strc
{
    unsigned char nHeader;
    unsigned int d1;
    unsigned int d5;
    unsigned int d9;
    unsigned int d13;
};

struct D2PacketPvp7Strc
{
    unsigned char nHeader;
    unsigned char b1;
    unsigned char bFlag;
    unsigned int d3;
};

struct D2PacketParty6Strc
{
    unsigned char nHeader;
    unsigned char b1;
    unsigned int d2;
};

#pragma pack(pop)

// 0x00478040
static unsigned char* MSG_ReadSaveFile(int* pnFileSize)
{
    char szSavePath[0x400];
    char szFileName[0x1F4];
    D2_ASSERT(gszClientCharName[0], 0x1EB);
    FOG_GetSavePath(szSavePath, 0x400);
    sprintf(szFileName, gszSavePathFormat_006D4230, szSavePath, gszClientCharName);
    _iobuf* pFile = fopen(szFileName, gszFileModeRb);
    if (!pFile)
        return 0;
    if (fseek(pFile, 0, 2))
    {
        fclose(pFile);
        return 0;
    }
    *pnFileSize = ftell(pFile);
    fseek(pFile, 0, 0);
    unsigned char* pBuffer = (unsigned char*)FOG_Alloc(*pnFileSize, ".\\GAME\\Msg.cpp", 0x1FF, 0);
    fread(pBuffer, *pnFileSize, 1, pFile);
    fclose(pFile);
    return pBuffer;
}

// 0x00478130
void __fastcall MSG_SetProgress(int nValue, int nDivisor)
{
    if (!nDivisor)
    {
        gnProgress = 0;
        return;
    }
    gnProgress = (nValue << 8) / nDivisor;
}

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long nMilliseconds); // 0x006CC258

void __fastcall UI_DrawLoadingScreen(int nArg); // 0x004565E0

// 0x00478160
void __fastcall MSG_ShowProgressSteps(int nDone, int nTotal)
{
    const int nDivisor = nTotal * 8;
    int nPosition = nDone * 8;
    for (int i = 0; i < 8; ++i)
    {
        if (nDivisor == 0)
            gnProgress = 0;
        else
            gnProgress = (nPosition * 0x100) / nDivisor;
        UI_DrawLoadingScreen(0);
        Sleep(250);
        ++nPosition;
    }
}

// 0x004781D0
void __fastcall MSG_UploadSaveFile(int bAnimate)
{
    D2SaveFilePacketStrc tPacket;
    int nFileSize = 0;
    unsigned char* pBuffer = MSG_ReadSaveFile(&nFileSize);
    D2_ASSERT(pBuffer, 0x232);
    if (bAnimate)
        MSG_ShowProgressSteps(0, 0);
    unsigned char* pRead = pBuffer;
    const int nChunks = nFileSize / 0xFF;
    for (int i = 0; i < nChunks; ++i)
    {
        tPacket.nHeader = 0x6C;
        tPacket.nTotalSize = nFileSize;
        tPacket.f_1 = 0xFF;
        for (int k = 0; k < 0xFF; ++k)
            tPacket.pData[k] = *pRead++;
// build: symbol ?CLIENT_Send@* 0x0052AE50
        CLIENT_Send(0xFF + 7, 0, &tPacket);
        gnSentBytes += 0xFF + 7;
        gnSentPackets += 1;
        if (bAnimate)
            MSG_ShowProgressSteps(i, nChunks);
    }
    const int nRemain = nFileSize - nChunks * 0xFF;
    tPacket.nHeader = 0x6C;
    tPacket.nTotalSize = nFileSize;
    tPacket.f_1 = (unsigned char)nRemain;
    for (int k = 0; k < nRemain; ++k)
        tPacket.pData[k] = *pRead++;
    const int nSize = nRemain + 7;
    CLIENT_Send(nSize, 0, &tPacket);
    gnSentBytes += nSize;
    gnSentPackets += 1;
    FOG_Free(pBuffer, ".\\GAME\\Msg.cpp", 0x262, 0);
    if (nChunks == 0)
        gnProgress = nChunks;
    else
        gnProgress = (nChunks << 8) / nChunks;
}

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

// 0x00478350
static void __stdcall MSG_SendToServer(const unsigned char* pPacket, int nSize)
{
    D2_ASSERT(nSize < 0x200, 0x272);
    const unsigned int dwTick = GetTickCount();
    switch (pPacket[0])
    {
    case 0x05:
    case 0x06:
    case 0x07:
    case 0x08:
    case 0x09:
    case 0x0A:
    case 0x0C:
    case 0x0D:
    case 0x0E:
    case 0x0F:
    case 0x10:
    case 0x11:
        if (dwTick - gdwLastSendTick < 50 && !memcmp(gaLastSentPacket, pPacket, nSize))
            return;
        break;

    case 0x3A:
        break;

    default:
        if (dwTick - gdwLastSendTick < 200 && !memcmp(gaLastSentPacket, pPacket, nSize))
            return;
        break;
    }

    memcpy(gaLastSentPacket, pPacket, nSize);
    gdwLastSendTick = dwTick;
    unsigned char aBuffer[0x200];
    memcpy(aBuffer, pPacket, nSize);
// build: symbol ?CLIENT_Send@* 0x0052AE50
    if (CLIENT_Send(nSize, 1, aBuffer))
    {
        gnSentBytes += nSize;
        ++gnSentPackets;
    }
}

// 0x00478590
void __fastcall MSG_SendHeaderOnly(char nValue)
{
    D2PacketSize1Strc tPacket;
    tPacket.nHeader = nValue;
    MSG_SendToServer((unsigned char*)&tPacket, 1);
}

// 0x004785B0
void __fastcall MSG_SendWord(unsigned char nCmd, unsigned short nArg)
{
    D2PacketSize3Strc tPacket;
    tPacket.nHeader = nCmd;
    tPacket.w1 = nArg;
    MSG_SendToServer((unsigned char*)&tPacket, 3);
}

// 0x004785D0
void __fastcall MSG_SendTwoWords(char nHeader, short nArg1, short nArg2)
{
    D2PacketShorts5Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.w1 = nArg1;
    tPacket.w3 = nArg2;
    MSG_SendToServer((unsigned char*)&tPacket, 5);
}

// 0x00478600
void __fastcall MSG_SendShorts(char nHeader, short nArg1, short nArg2, short nArg3)
{
    D2PacketShorts7Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.w1 = nArg1;
    tPacket.w3 = nArg2;
    tPacket.w5 = nArg3;
    MSG_SendToServer((unsigned char*)&tPacket, 7);
}

// 0x00478640
void __fastcall MSG_SendFourWords(unsigned char nHeader, unsigned short w1, unsigned short w3, unsigned short w5, unsigned short w7)
{
    D2PacketShorts9Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.w1 = w1;
    tPacket.w3 = w3;
    tPacket.w5 = w5;
    tPacket.w7 = w7;
    MSG_SendToServer((unsigned char*)&tPacket, 9);
}

// 0x00478680
void __fastcall MSG_SendDword(char nHeader, int nArg)
{
    D2PacketDword5Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.d1 = nArg;
    MSG_SendToServer((unsigned char*)&tPacket, 5);
}

// 0x004786A0
void __fastcall MSG_SendTwoDwords(unsigned char nHeader, unsigned int d1, unsigned int d5)
{
    D2PacketDwords9Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.d1 = d1;
    tPacket.d5 = d5;
    MSG_SendToServer((unsigned char*)&tPacket, 9);
}

// 0x004786D0
void __fastcall MSG_SendDwords3(unsigned char nHeader, unsigned int d1, unsigned int d5, unsigned int d9)
{
    D2PacketDwords13Strc tPacket;
    tPacket.nHeader = nHeader;
    tPacket.d1 = d1;
    tPacket.d5 = d5;
    tPacket.d9 = d9;
    MSG_SendToServer((unsigned char*)&tPacket, 0xD);
}

// 0x00478700
void __fastcall MSG_SendFourDwords(char nCommand, int nUnitId, int nArg1, int nArg2, int nArg3)
{
    D2PacketDwords17Strc tPacket;
    tPacket.nHeader = nCommand;
    tPacket.d1 = nUnitId;
    tPacket.d5 = nArg1;
    tPacket.d9 = nArg2;
    tPacket.d13 = nArg3;
    MSG_SendToServer((unsigned char*)&tPacket, 0x11);
}

// 0x00478740
void __fastcall MSG_SendPvpCommand(int nCommand, int nUnitId, int bSet)
{
    D2PacketPvp7Strc tPacket;
    memset(&tPacket, 0, sizeof(tPacket));
    tPacket.nHeader = 0x5D;
    tPacket.b1 = nCommand;
    tPacket.d3 = nUnitId;
    if (bSet)
        tPacket.bFlag = 1;
    MSG_SendToServer((unsigned char*)&tPacket, 7);
}

// 0x00478780
void __fastcall MSG_SendPartyCommand(unsigned char nCommand, int nUnitId)
{
    D2PacketParty6Strc tPacket;
    memset(&tPacket, 0, sizeof(tPacket));
    tPacket.nHeader = 0x5E;
    tPacket.b1 = nCommand;
    tPacket.d2 = nUnitId;
    MSG_SendToServer((unsigned char*)&tPacket, 6);
}

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0

// 0x004787B0
void __fastcall MSG_SendStrings(const unsigned char* pData)
{
    unsigned char aBuffer[0x204];
    aBuffer[0] = pData[0];
    aBuffer[1] = pData[1];
    aBuffer[2] = pData[2];
    unsigned char* pEnd = &aBuffer[3];
    pEnd += SStrCopy((char*)pEnd, (const char*)&pData[3], 0x100) + 1;
    const char* szSecond = (const char*)&pData[0x103];
    if (szSecond)
    {
        pEnd += SStrCopy((char*)pEnd, szSecond, 0x10) + 1;
    }
    else
    {
        *pEnd++ = 0;
    }
    *pEnd = 0;
    MSG_SendToServer(aBuffer, pEnd - aBuffer + 1);
}


// 0x00478830
void __fastcall MSG_SendWardenPacket(const void* pData, unsigned int nLength)
{
    if (nLength <= 0x1FD)
    {
        const unsigned int nSize = nLength + 3;
        D2_ASSERT(nSize <= 0x200, 0x453);
        unsigned char aBuffer[0x200];
        aBuffer[0] = 0x66;
        *(unsigned short*)&aBuffer[1] = (unsigned short)nLength;
        memcpy(&aBuffer[3], pData, nLength);
        MSG_SendToServer(aBuffer, nSize);
        return;
    }
    D2_ASSERT(nLength <= 0x1FD, 0x452);
}

