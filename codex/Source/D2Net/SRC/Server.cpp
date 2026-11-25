#include "D2Net.h"
#include "D2ItemTypes.h"
#include "D2StateIds.h"
#include "D2SkillIds.h"
#include "D2StatIds.h"
#include "D2GameAux.h"
#include "D2TxtItems.h"
#include "D2Constants.h"
#include "D2Txt.h"
#include "D2GameStrc.h"
#include "D2Path.h"
#include "D2UnitData.h"
#include "D2TxtTables.h"
#include "D2ItemsWorld.h"
#include "D2ItemModes.h"
#include "D2LanguageNames.h"

#include "D2SetsTxt.h"

#include "D2BnMessages.h"

#include "D2Structs.h"

#include "D2DataTbls.h"

#include "D2Primitives.h"

#include "D2ClientMenus.h"

#include "D2BnCryptTypes.h"

#include "D2Records.h"

#include "D2LevelTxt.h"

#include "D2StormSha1.h"

#include "D2GameServer.h"

#include "D2NetTypes.h"

#include "D2NetTypes.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837

extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

void __fastcall CLIENT_ReadPacketFromBuffer(void* pBuffer, int nBufferSize);                                // 0x0052AEB0

void __fastcall FOG_10222(const unsigned char* pData, unsigned int nSize);                                  // 0x0040B130

int __fastcall FOG_CompressPacket(unsigned char* pOut, int nCapacity, const unsigned char* pIn, int nSize);       // 0x0040B1B0

int __stdcall FOG_10157(void* pServer, unsigned int nKey, const void* pData, unsigned int nSize); // 0x006C03A0

extern void* gpServer_00882D08;                                                                             // 0x00882D08

#define GAME_PORT 4000


typedef int (__fastcall* D2NET_Unk_Callback)(int, int, int, int);

typedef int (__fastcall* D2NET_PacketCallback)(int, int, int, int);

typedef int (__fastcall* D2NET_ReadPacketCallback)(QServer*, D2PacketBufferStrc*, int);

int gnLocalClientGameGuid;                                                                         // 0x00882D0C

QServer* __stdcall QSInit(int nState, int nSlots, int nPort, int bDisableNt, D2NET_PacketCallback pfnProcess, D2NET_PacketCallback pfnOnNewClient, D2NET_PacketCallback pfnOnRemove, D2NET_ReadPacketCallback pfnHandler); // 0x006BF760

int __stdcall FOG_10165(QServer* pServer, int nClientId, const char* szFile, int nLine);                   // 0x006C06B0

int __stdcall FOG_10170(QServer* pServer, int pfnCallback);                                                          // 0x006BF040

int __stdcall FOG_10171(QServer* pServer, D2NET_Unk_Callback pfCallback);                                   // 0x006BF080

int __stdcall FOG_10172(QServer* pServer, int nClientId, int dwGameGuid);                                   // 0x006BF0A0

int __stdcall FOG_10173(void* pContainer, int nKey); // 0x006BF0C0

int __stdcall FOG_10177(QServer* pServer, int dwMilliseconds);                                              // 0x006BEBC0

void __stdcall FOG_10183_Return(QServer* pServer, int nUnused);                                             // 0x006BF600

int __fastcall SERVER_SendToLocalClientCallback(QServer* nUnused, D2PacketBufferStrc* pPacketBuffer, int nBufferSize); // 0x0052B0E0

int __fastcall SERVER_ValidateClientPacket(int a1, int a2, int a3, int a4);                                 // 0x0052B100

int __fastcall SERVER_OnClientConnectedCallback(int pServer, int nClientId, int szFile, int nLine);                                                // 0x0052B720

unsigned int __stdcall SERVER_SendPacketToClient(char nSendMode, void* pClientId, void* pPacketArg, unsigned int nPacketSize); // 0x0052B330

struct D2GSPacketSrvAFStrc
{
    unsigned char nHeader;
    unsigned char nCompression;
};

int __stdcall FOG_SetHackListEnabled(void* pObject, int nArg1); // 0x006BF4E0

int __stdcall sub_006C0170(void* pObject, const unsigned char* pData, int nSize); // 0x006C0170

int __stdcall sub_006BEAD0(void* pObject, int nMode, int nArg1, int nArg2); // 0x006BEAD0

int __stdcall sub_006BEE20(void* pObject, int nArg1); // 0x006BEE20

int __stdcall sub_006BEF40(void* pObject, int nArg1); // 0x006BEF40

int __stdcall QSERVER_HackListClient(void* pObject, int nArg1, int nArg2, int nArg3); // 0x006C0530

int __stdcall QSERVER_HackListIP(void* pObject, int nArg1, int nArg2, int nArg3); // 0x006C0600

int __stdcall QSERVER_HackUnlistIP(void* pObject, int nArg1, int nArg2, int nArg3); // 0x006BEFB0

int __stdcall QSERVER_DisconnectIP(void* pObject, int nArg1, int nArg2, int nArg3); // 0x006C06D0

QServer* gpServer; // 0x00882D08

int __fastcall SERVER_GetClientPacketSize(D2PacketBufferStrc* pBuffer, unsigned int nBufferSize, int* pSize); // 0x0052BC20

int __fastcall QSERVER_CheckClientMask(void* pServer, int nClientId); // 0x006BF6C0

// 0x0052B0E0
int __fastcall SERVER_SendToLocalClientCallback(QServer* pUnused, D2PacketBufferStrc* pPacketBuffer, int nBufferSize)
{
    CLIENT_ReadPacketFromBuffer(pPacketBuffer, nBufferSize);
    return 1;
}

// 0x0052B100
int __fastcall SERVER_ValidateClientPacket(D2PacketBufferStrc* pPacketBuffer, int nBufferSize, int* pPacketSize, int* pFlags, int* pType, int* pPriority, int nUnused1, int nUnused2, int nClientId)
{
    if (nBufferSize < sizeof(unsigned char))
        return 3;
    const unsigned char nHeader = pPacketBuffer->data[0];
    int nSize;
    if (SERVER_GetClientPacketSize(pPacketBuffer, nBufferSize, &nSize))
    {
        if (nHeader >= 0x71 && nHeader != 0xFF)
            return 4;
        if ((unsigned short)nSize > 0x204)
            return 4;
        const int nPacketSize = (unsigned short)nSize;
        if (nPacketSize <= nBufferSize)
        {
            *pFlags = 0;
            *pPacketSize = nPacketSize;
            if (nHeader < 0x67)
            {
                *pType = 1;
            }
            else if (nHeader < 0x71)
            {
                *pType = 0;
            }
            else
            {
                if (!QSERVER_CheckClientMask(gpServer, nClientId))
                    return 4;
                *pType = 2;
            }
            *pPriority = 100;
            if (*pType == 0)
                return 2;
            if (*pType == 1)
                return 1;
            return *pType == 2 ? 1 : 2;
        }
    }
    return 3;
}

int __stdcall FOG_WaitForSingleObject(void* pObject, int nArg1); // 0x006BE4E0

int __stdcall sub_006BE390(void* pObject, int nArg1, int nArg2); // 0x006BE390

int __fastcall sub_006BF610(void* pObject, int nArg1, int nArg2); // 0x006BF610

void __stdcall FOG_SetMaxClientsPerGame(void* pObject, int nArg1); // 0x006BE4A0

int __stdcall sub_006BED90(void* pObject, int nArg1, int nArg2, int nArg3); // 0x006BED90

// 0x0052B1F0
int __stdcall SERVER_WaitForSingleObject(int nArg1)
{
    return FOG_WaitForSingleObject(gpServer, nArg1);
}

// 0x0052B210
int __stdcall SERVER_SwapSlotValue(int nArg1, int nArg2)
{
    return sub_006BE390(gpServer, nArg1, nArg2);
}

// 0x0052B230
int __stdcall SERVER_AddKeyValuePair(int nArg1, int nArg2)
{
    return sub_006BF610(gpServer, nArg2, nArg1);
}

// 0x0052B250
void __stdcall SERVER_SetMaxClientsPerGame(int nArg1)
{
    FOG_SetMaxClientsPerGame(gpServer, nArg1);
}

int __stdcall FOG_10180(void* pObject); // 0x006BE450
void __stdcall FOG_10182_Return(void* pObject); // 0x006BF5F0

// 0x0052B270
int __fastcall D2NET_10027()
{
    return FOG_10180(gpServer);
}

// 0x0052B280
int __stdcall SERVER_SetHackListEnabled(int nArg1)
{
    return FOG_SetHackListEnabled(gpServer, nArg1);
}

// 0x0052B2A0
void __cdecl SERVER_Release()
{
    unsigned char nMessage = 0xB0;
    sub_006C0170(gpServer, &nMessage, 1);
    gpServer = 0;
}

// 0x0052B2D0
int __stdcall SERVER_ReadGamePacket(int nArg1, int nArg2)
{
    return sub_006BEAD0(gpServer, 1, nArg1, nArg2);
}

// 0x0052B2F0
int __stdcall SERVER_ReadSystemPacket(int nArg1, int nArg2)
{
    return sub_006BEAD0(gpServer, 0, nArg1, nArg2);
}

// 0x0052B310
int __stdcall SERVER_ReadAdminPacket(int nArg1, int nArg2)
{
    return sub_006BEAD0(gpServer, 2, nArg1, nArg2);
}

// 0x0052B330
unsigned int __stdcall SERVER_SendPacketToClient(char nSendMode, void* pClientId, void* pPacketArg, unsigned int nPacketSize)
{
    const unsigned char* pPacket = (const unsigned char*)pPacketArg;

    D2_ASSERT(nPacketSize <= 516, 344);

    if (NET_IsLocalConnection())
    {
        CLIENT_ReadPacketFromBuffer((void*)pPacket, nPacketSize);
        return nPacketSize;
    }

    if (nSendMode != 0 || *pPacket != 0xAF)
    {
        FOG_10222(pPacket, nPacketSize);
        if (nSendMode != 2)
        {
            unsigned char frame[1036];
            unsigned int nFrameSize = FOG_CompressPacket(&frame[2], 1032, pPacket, nPacketSize);
            D2_ASSERT(nFrameSize, 376);

            if (++nFrameSize < 0xF0)
            {
                frame[1] = (unsigned char)nFrameSize;
                return FOG_10157(gpServer_00882D08, (unsigned int)pClientId, &frame[1], nFrameSize) != 0 ? nFrameSize : 0;
            }

            ++nFrameSize;
            frame[0] = (unsigned char)((nFrameSize >> 8) | 0xF0);
            frame[1] = (unsigned char)nFrameSize;
            return FOG_10157(gpServer_00882D08, (unsigned int)pClientId, frame, nFrameSize) != 0 ? nFrameSize : 0;
        }
    }

    return FOG_10157(gpServer_00882D08, (unsigned int)pClientId, pPacket, nPacketSize) != 0 ? nPacketSize : 0;
}

// 0x0052B490
int __stdcall CLIENT_ObjectCall_6BED90(int nArg1, int nArg2, int nArg3)
{
    return sub_006BED90(gpServer, nArg1, nArg2, nArg3);
}

// 0x0052B4B0
int __stdcall SERVER_GetIpAddressFromClientId(int nArg1)
{
    return sub_006BEE20(gpServer, nArg1);
}

// 0x0052B4D0
int __stdcall SERVER_GetSocketFromClientId(int nArg1)
{
    return sub_006BEF40(gpServer, nArg1);
}

// 0x0052B4F0
int __stdcall SERVER_HackListClient(int nArg1, int nArg2, int nArg3)
{
    return QSERVER_HackListClient(gpServer, nArg1, nArg2, nArg3);
}

// 0x0052B510
int __stdcall SERVER_HackListIP(int nArg1, int nArg2, int nArg3)
{
    return QSERVER_HackListIP(gpServer, nArg1, nArg2, nArg3);
}

// 0x0052B530
int __stdcall SERVER_HackUnlistIP(int nArg1, int nArg2, int nArg3)
{
    return QSERVER_HackUnlistIP(gpServer, nArg1, nArg2, nArg3);
}

// 0x0052B550
int __stdcall SERVER_DisconnectIP(int nArg1, int nArg2, int nArg3)
{
    return QSERVER_DisconnectIP(gpServer, nArg1, nArg2, nArg3);
}

// 0x0052B570
void __stdcall D2NET_10016(int nClientId)
{
    FOG_10165(gpServer, nClientId, ".\\SRC\\Server.cpp", 468);
}

// 0x0052B5A0
void __stdcall D2NET_10018(int a1)
{
    if (!gpServer)
    {
        return;
    }

    FOG_10170(gpServer, a1);
}

// 0x0052B5C0
int __stdcall SERVER_SetRemoveClientCallback(D2NET_Unk_Callback pfCallback)
{
    return FOG_10171(gpServer, pfCallback);
}

// 0x0052B5E0
int __stdcall SERVER_SetClientGameGUID(int nClientId, int dwGameGuid)
{
    if (nClientId)
    {
        return FOG_10172(gpServer, nClientId, dwGameGuid);
    }

    gnLocalClientGameGuid = dwGameGuid;

    return dwGameGuid;
}

// 0x0052B610
int __stdcall SERVER_GetClientGameGUID(int nClientId)
{
    if (nClientId)
    {
        return FOG_10173(gpServer, nClientId);
    }

    return gnLocalClientGameGuid;
}

// 0x0052B640
int __fastcall SERVER_EnqueueClientPacket(const unsigned char* pBuffer, unsigned short nBufferSize, int a3)
{
    D2_ASSERT(nBufferSize <= MAX_MSG_SIZE, 521);

    return FOG_10175(gpServer, pBuffer, nBufferSize, a3);
}

// 0x0052B690
int __fastcall SERVER_EnqueueLocalClientPacket(const unsigned char* pBuffer, unsigned short nSize)
{
    D2_ASSERT(nSize <= MAX_MSG_SIZE, 0x217);
    return FOG_10175(gpServer, pBuffer, nSize, 0) != 0;
}

// 0x0052B6D0
int __stdcall D2NET_10022(int dwMilliseconds)
{
    return FOG_10177(gpServer, dwMilliseconds);
}

// 0x0052B6F0
void __fastcall D2NET_10028_Return()
{
    FOG_10182_Return(gpServer);
}

// 0x0052B700
void __stdcall D2NET_10029_Return(int nUnused)
{
    FOG_10183_Return(gpServer, nUnused);
}

int __stdcall sub_0052B330(unsigned char nFlags, int nClientId, void* pPacket, int nSize); // 0x0052B330

// 0x0052B720
int __fastcall SERVER_OnClientConnectedCallback(QServer* pServer, int nClientId, const char* szFile, int nLine)
{
    unsigned char data[2];
    data[0] = 0xAF;
    data[1] = 1;
    sub_0052B330(0, nClientId, data, sizeof(data));
    return 1;
}

// 0x0052B750
int __fastcall SERVER_OnClientDisconnectedCallback(int a1, int a2, int a3, int a4)
{
    const unsigned char data[1] = { 0x70 };

    FOG_10175(gpServer, data, sizeof(data), a2);
    return 1;
}

// 0x0052B780
void __fastcall SERVER_SendConnectionInfo()
{
    D2GSPacketSrvAFStrc packetAF;
    packetAF.nHeader = 0xAF;
    packetAF.nCompression = 0;
    SERVER_SendPacketToClient(0, 0, &packetAF, sizeof(packetAF));
}

// 0x0052B7A0
void __stdcall SERVER_Initialize(int a1, int a2)
{
    gpServer = QSInit(a1, 3, GAME_PORT, a2, SERVER_ValidateClientPacket, SERVER_OnClientConnectedCallback, SERVER_OnClientDisconnectedCallback, SERVER_SendToLocalClientCallback);
}
