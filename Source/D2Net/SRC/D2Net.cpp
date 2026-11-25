#include "D2Net.h"

#include "D2GameServer.h"

struct D2NetPacketRecStrc;

struct D2ServerCallbackFunctions;

extern int gnConnectionMode; // 0x00882D10

typedef const char* (__stdcall* FnLoadComplete)();

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(); // 0x006CC260

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

extern char gszEmptyLoadComplete[]; // 0x006E0498

extern int gnGamesGUIDs[1024]; // 0x00882D38

extern D2ServerCallbackFunctions* gpD2EventCallbackTable; // 0x00883D50

extern int gbD2ServerCallbackFunctionsInitialized; // 0x00883D54

// 0x0052B7E0
int __fastcall NET_IsLocalConnection()
{
    if (gnConnectionMode == 1)
    {
        return 1;
    }
    return gnConnectionMode == 2;
}

// 0x0052B810
void __fastcall NET_SetConnectionMode(int nConnectionMode)
{
    gnConnectionMode = nConnectionMode;
}

// 0x0052B820
int __fastcall NET_DequeueFirstPacketFromList(D2CriticalSectionStrc* pCriticalSection, D2NetPacketRecStrc** ppPacketList, unsigned char* pBuffer, unsigned int nBufferSize)
{
    int nResult;

    EnterCriticalSection(pCriticalSection);

    D2NetPacketRecStrc* pPacket = *ppPacketList;
    if (pPacket && (gnConnectionMode != 2 || GetTickCount() - pPacket->dwTickCount >= 500))
    {
        memcpy(pBuffer, pPacket, nBufferSize < MAX_MSG_SIZE ? nBufferSize : MAX_MSG_SIZE);
        nResult = pPacket->nPacketSize;
        *ppPacketList = pPacket->pNext;
        FOG_Free(pPacket, ".\\SRC\\D2Net.cpp", 0x46, 0);
    }
    else
    {
        nResult = -1;
    }

    LeaveCriticalSection(pCriticalSection);
    return nResult;
}

// 0x0052B8F0
void __cdecl sub_0052B8F0_Nop()
{
}

int gnConnectionMode; // 0x00882D10

// 0x0052B900
void __cdecl sub_0052B900_Nop()
{
}

// 0x0052BE40
void __stdcall NET_DefaultLeaveGame(int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int, int)
{
}

// 0x0052BE60
void __stdcall NET_DefaultSaveDatabaseCharacter(int, int, int, int)
{
}

// 0x0052BE70
void __cdecl NET_DefaultServerLogMessage()
{
}

// 0x0052BE80
void __stdcall NET_DefaultEnterGame(int, int, int)
{
}

// 0x0052BE90
int __stdcall NET_DefaultFindPlayerToken(int, int, int, int, int, int, int)
{
    return 0;
}

// 0x0052BED0
void __stdcall NET_DefaultUpdateCharacterLadder(int, int, int, int, int)
{
}

// 0x0052BFE0
int __fastcall GAME_GetGamesCount()
{
    int nResult = 0;
    for (int i = 0; i < 1024; ++i)
    {
        if (gnGamesGUIDs[i] != 0 && gnGamesGUIDs[i] != -1)
        {
            ++nResult;
        }
    }
    return nResult;
}

// 0x0052B8B0
int __fastcall NET_FreePacketList(D2CriticalSectionStrc* pCriticalSection, D2NetPacketRecStrc** ppPacketList)
{
    EnterCriticalSection(pCriticalSection);

    while (*ppPacketList)
    {
        D2NetPacketRecStrc* pPacket = *ppPacketList;
        *ppPacketList = pPacket->pNext;
        FOG_Free(pPacket, ".\\SRC\\D2Net.cpp", 0x5D, 0);
    }

    LeaveCriticalSection(pCriticalSection);
    return 1;
}

// 0x0052B800
int __fastcall NET_IsSimulatedLagConnection()
{
    return gnConnectionMode == 2;
}
