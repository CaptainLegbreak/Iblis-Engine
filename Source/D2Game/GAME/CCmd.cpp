#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2GameClient.h"
#include "D2Packets.h"
#include "D2LanguageNames.h"
// build: symbol _gaszLanguageNames 0x00731394

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2ServerCallbackFunctions;
struct D2GameStrc;
struct D2ClientStrc;
struct D2UnitStrc;

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern D2ServerCallbackFunctions* gpD2EventCallbackTable; // 0x00883D50
int __stdcall SStrCmpI(const char* szString1, const char* szString2, unsigned int nMaxChars); // 0x00413590
int __fastcall GAME_GetGameGUIDFromGameId(unsigned short nGameId); // 0x0052C060
D2GameStrc* __fastcall GAME_LockGame(int nGameGUID); // 0x0052E860
void __fastcall GAME_LeaveGamesCriticalSection(D2GameStrc* pGame); // 0x0052DA90
D2ClientStrc* __fastcall CLIENTS_GetNext(D2ClientStrc* pClient); // 0x00539080
char* __fastcall CLIENTS_GetName(D2ClientStrc* pClient); // 0x00538830
int __fastcall SrvVerifyCreateNewGame(int nClientId, D2GSPacketClt66* pPacket); // 0x0052C330
void __fastcall sSrvSendGameInit(int nClientId, char* szGameName, unsigned char nGameType, unsigned char nCharTemplate, const char* szClientName, int nArena, unsigned int nFlags, int nArenaTemplate, int a9, int a10, unsigned char nDifficulty, unsigned char nLocale, int a13, int a14); // 0x00530BF0
void __fastcall GAME_UpdatePing(int nClientId, int a2, int a3, int a4); // 0x0052C400
void __cdecl GAME_LogMessage(int nLevel, const char* szFormat, ...); // 0x0052BE20
void __fastcall D2GAME_PACKETS_SendSystemError(int nClientId, unsigned int nErrorCode); // 0x0053B260
int __stdcall SERVER_HackListClient(int nClientId, const char* szFile, int nLine); // 0x0052B4F0
int __fastcall SrvVerifyJoinGame(int nClientId, unsigned short nGameId, unsigned char nPlayerClass, const char* szClientName, int nTokenId, char* szAccountName, int* a7, unsigned char nLocale, int* a9, int* a10, int* a11, int* a12, int a13); // 0x0052C690
void __fastcall SrvJoinGame(int dwClientId, unsigned short nGameId, int nClass, const char* szClientName, int a5, const char* szAccountName, int nCharSaveTransactionToken, int nLocale, int a8, int a9, int a11, int a12, int a13); // 0x0052FA50
int __fastcall GAME_VerifyEndGame(int nClientId); // 0x0052C8E0
void __fastcall SrvEndGame(int nClientId, int a2); // 0x005303D0
int __fastcall D2GAME_Return1_6FC41900(int nClientId); // 0x0052DAF0
void __fastcall GAME_HandleGameListRequest(int nClientId); // 0x0052E9B0
int __fastcall GAME_VerifyJoinAct(int nClientId); // 0x0052C550
void __fastcall SrvJoinAct(int nClientId); // 0x00530190
int __fastcall GAME_VerifyReceiveSaveFilePart(int nClientId); // 0x0052DB00
int __fastcall GAME_ReceiveSaveFilePart(int nClientId, D2GSPacketClt6B* pPacket); // 0x0052DB10
int __fastcall GAME_VerifyDisconnect(int nClientId); // 0x0052CBE0
void __fastcall SrvDisconnectClientById(int nClientId, int nEventType); // 0x00530270
D2ClientStrc* __fastcall CLIENTS_GetLockedClientFromId(int nClientId); // 0x00537760
void __fastcall CLIENTS_UnlockClientList(int nClientId); // 0x005377A0

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount();
D2ClientStrc* __fastcall CLIENTS_GetClientFromClientId(D2GameStrc* pGame, int nClientId); // 0x00537810
D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath); // 0x00537860
int __fastcall D2GAME_PACKET_Handler_6FC89320(D2GameStrc* pGame,D2UnitStrc* pUnit,unsigned char* pPacket,int nSize); // 0x0054D750

static int CCMD_IsStringZeroTerminated(const char* pData, int nDataSize)
{
    for (int i = 0; i < nDataSize; ++i)
    {
        if (!*pData++)
        {
            return 1;
        }
    }
    return 0;
}

// 0x0053EFF0
static unsigned int __stdcall CCMD_CanClientJoinGame(int a1, int a2, const char* szClientName)
{
    unsigned int nResult = 0;
    if (a1 != 1)
    {
        return 6;
    }
    const int nGUID = GAME_GetGameGUIDFromGameId(1);
    if (!nGUID)
    {
        return 6;
    }
    D2GameStrc* pGame = GAME_LockGame(nGUID);
    if (!pGame)
    {
        return 6;
    }
    if (a2 != 0xE)
    {
        nResult = 0x10;
    }
    else if (pGame->nClients >= 8)
    {
        nResult = 0xF;
    }
    else if (!szClientName[0] || !szClientName[1] || !CCMD_IsStringZeroTerminated(szClientName, 16))
    {
        nResult = 6;
    }
    else
    {
        for (D2ClientStrc* pClient = sub_00539070_GetClientList(pGame); pClient; pClient = CLIENTS_GetNext(pClient))
        {
            const char* szName = CLIENTS_GetName(pClient);
            if (szName && !SStrCmpI(szName, szClientName, 16))
            {
                nResult = 6;
                break;
            }
        }
    }
    GAME_LeaveGamesCriticalSection(pGame);
    return nResult;
}

// 0x0053F100
void __fastcall CCMD_ProcessClientSystemMessage(void* pData, int nSize)
{
    const int nClientId = *(int*)pData;
    pData = (char*)pData + 4;
    switch (*(unsigned char*)pData)
    {
    case 0x67:
    {
        D2GSPacketClt66* p66 = (D2GSPacketClt66*)pData;
        if (SrvVerifyCreateNewGame(nClientId, p66))
        {
            sSrvSendGameInit(nClientId, p66->szGameName, p66->nGameType, p66->nPlayerClass, p66->szClientName, p66->wArena, p66->nGameFlags, p66->nTemplate, p66->unk0x2B, p66->unk0x2C, p66->nDifficulty, p66->nLocale, 0, 0);
        }
        break;
    }
    case 0x6D:
    {
        D2GSPacketClt6D* p6D = (D2GSPacketClt6D*)pData;
        GAME_UpdatePing(nClientId, p6D->unk0x01, p6D->unk0x05, 0);
        break;
    }
    case 0x68:
    {
        D2GSPacketClt67* p67 = (D2GSPacketClt67*)pData;
        int n3C = 0;
        int n40 = 0;
        GAME_LogMessage(6, "[JOIN 1] %d clientid - Begin", nClientId);
        if (!gpD2EventCallbackTable)
        {
            const unsigned int nErrorCode = CCMD_CanClientJoinGame(p67->nGameId, p67->dwVersion, p67->szClientName);
            if (nErrorCode)
            {
                D2GAME_PACKETS_SendSystemError(nClientId, nErrorCode);
                SERVER_HackListClient(nClientId, ".\\GAME\\CCmd.cpp", 0x14B);
            }
        }
        char szAccountName[0x34];
        int n48;
        int n4C;
        int n44;
        szAccountName[0] = '\0';
        if (SrvVerifyJoinGame(nClientId, p67->nGameId, p67->nPlayerClass, p67->szClientName, p67->nTokenId, szAccountName, &n48, p67->nLocale, &n4C, &n44, &n3C, &n40, p67->dwVersion))
        {
            SrvJoinGame(nClientId, p67->nGameId, p67->nPlayerClass, p67->szClientName, p67->nTokenId, szAccountName, n48, p67->nLocale, n4C, n44, n3C, n40, p67->dwVersion);
        }
        break;
    }
    case 0x69:
        if (GAME_VerifyEndGame(nClientId))
        {
            SrvEndGame(nClientId, 1);
        }
        break;
    case 0x6A:
        if (D2GAME_Return1_6FC41900(nClientId))
        {
            GAME_HandleGameListRequest(nClientId);
        }
        break;
    case 0x6B:
        if (GAME_VerifyJoinAct(nClientId))
        {
            SrvJoinAct(nClientId);
        }
        break;
    case 0x6C:
    {
        D2GSPacketClt6B* p6B = (D2GSPacketClt6B*)pData;
        D2_ASSERT(p6B->dwTotalSize < 0x2000, 0x1A8);
        if (GAME_VerifyReceiveSaveFilePart(nClientId))
        {
            GAME_ReceiveSaveFilePart(nClientId, p6B);
        }
        break;
    }
    case 0x6E:
        if (GAME_VerifyDisconnect(nClientId))
        {
            SrvDisconnectClientById(nClientId, 0);
        }
        break;
    case 0x70:
    {
        D2ClientStrc* pClient = CLIENTS_GetLockedClientFromId(nClientId);
        if (pClient)
        {
            pClient->dw504 = 1;
            CLIENTS_UnlockClientList(nClientId);
        }
        break;
    }
    default:
        break;
    }
}

// 0x0053F3D0
void __fastcall ProcessClientMessage(void* pData, int nPacketSize)
{
    const int nClientId = *(int*)pData;
    unsigned char* pPacket = (unsigned char*)pData + 4;
    D2GameStrc* pGame = sub_0052FEE0_LockGameByClientId(nClientId);
    if (!pGame)
    {
        GAME_LogMessage(9, "[ProcessClientMessage] Client %d is not in any game", nClientId);
        return;
    }

    D2ClientStrc* ptClient = CLIENTS_GetClientFromClientId(pGame, nClientId);
    D2_ASSERT(ptClient, 0x1F9);
    ptClient->dwLastPacketTick = GetTickCount();
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(ptClient, 0);
    if (pPlayer && (pPlayer ? pPlayer->dwUnitType : UNIT_INVALID) == 0)
    {
        D2GAME_PACKET_Handler_6FC89320(pGame, pPlayer, pPacket, nPacketSize);
    }

    GAME_LeaveGamesCriticalSection(pGame);
}

