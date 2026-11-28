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
#include "FogApi.h"
#include "FogApi2.h"





#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt("", sub_00408090(), line); exit(-1); }

#define GAME_PORT 4000


typedef int (__fastcall* D2NET_Unk_Callback)(int, int, int, int);

// Several of the queue server's routines that the exports below return the result of return nothing: the exports
// return what the routine leaves in EAX, so they call it through one of these types.
typedef int (__stdcall* D2NetQServerCall1)(D2QueueServerStrc*, int);
typedef int (__stdcall* D2NetQServerCall2)(D2QueueServerStrc*, int, int);
typedef int (__stdcall* D2NetQServerCall3)(D2QueueServerStrc*, int, int, int);
typedef int (__fastcall* D2NetQServerFastCall2)(D2QueueServerStrc*, int, int);

int gnLocalClientGameGuid;                                                                         // 0x00882D0C

int __fastcall SERVER_SendToLocalClientCallback(D2QueueServerStrc* pUnused, D2PacketBufferStrc* pPacketBuffer, int nBufferSize); // 0x0052B0E0

unsigned int __stdcall SERVER_SendPacketToClient(char nSendMode, void* pClientId, void* pPacketArg, unsigned int nPacketSize); // 0x0052B330

struct D2GSPacketSrvAFStrc
{
    unsigned char nHeader;
    unsigned char nCompression;
};

// 0x0052B0E0
int __fastcall SERVER_SendToLocalClientCallback(D2QueueServerStrc* pUnused, D2PacketBufferStrc* pPacketBuffer, int nBufferSize)
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
    if (SERVER_GetClientPacketSize(pPacketBuffer->data, nBufferSize, &nSize))
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

// 0x0052B1F0
int __stdcall SERVER_WaitForSingleObject(int nArg1)
{
    return FOG_WaitForSingleObject(gpServer, nArg1);
}

// 0x0052B210
int __stdcall SERVER_SwapSlotValue(int nArg1, int nArg2)
{
    return FOG_10186(gpServer, nArg1, nArg2);
}

// 0x0052B230
int __stdcall SERVER_AddKeyValuePair(int nArg1, int nArg2)
{
    return ((D2NetQServerFastCall2)FOG_10187)(gpServer, nArg2, nArg1);
}

// 0x0052B250
void __stdcall SERVER_SetMaxClientsPerGame(int nArg1)
{
    FOG_SetMaxClientsPerGame(gpServer, nArg1);
}

// 0x0052B270
int __fastcall D2NET_10027()
{
    return FOG_10180(gpServer);
}

// 0x0052B280
int __stdcall SERVER_SetHackListEnabled(int nArg1)
{
    return ((D2NetQServerCall1)FOG_SetHackListEnabled)(gpServer, nArg1);
}

// 0x0052B2A0
void __cdecl SERVER_Release()
{
    unsigned char nMessage = 0xB0;
    FOG_10152(gpServer, (char*)&nMessage, 1);
    gpServer = 0;
}

// 0x0052B2D0
int __stdcall SERVER_ReadGamePacket(int nArg1, int nArg2)
{
    return FOG_10156(gpServer, 1, (void*)nArg1, nArg2);
}

// 0x0052B2F0
int __stdcall SERVER_ReadSystemPacket(int nArg1, int nArg2)
{
    return FOG_10156(gpServer, 0, (void*)nArg1, nArg2);
}

// 0x0052B310
int __stdcall SERVER_ReadAdminPacket(int nArg1, int nArg2)
{
    return FOG_10156(gpServer, 2, (void*)nArg1, nArg2);
}

// 0x0052B330
unsigned int __stdcall SERVER_SendPacketToClient(char nSendMode, void* pClientId, void* pPacketArg, unsigned int nPacketSize)
{
    const unsigned char* pPacket = (const unsigned char*)pPacketArg;

    D2_ASSERT(nPacketSize <= 516, 344);

    if (NET_IsLocalConnection())
    {
        CLIENT_ReadPacketFromBuffer((D2PacketBufferStrc*)pPacket, nPacketSize);
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
                return FOG_10157(gpServer, (unsigned int)pClientId, (char*)&frame[1], nFrameSize) != 0 ? nFrameSize : 0;
            }

            ++nFrameSize;
            frame[0] = (unsigned char)((nFrameSize >> 8) | 0xF0);
            frame[1] = (unsigned char)nFrameSize;
            return FOG_10157(gpServer, (unsigned int)pClientId, (char*)frame, nFrameSize) != 0 ? nFrameSize : 0;
        }
    }

    return FOG_10157(gpServer, (unsigned int)pClientId, (char*)pPacket, nPacketSize) != 0 ? nPacketSize : 0;
}

// 0x0052B490
int __stdcall CLIENT_ObjectCall_6BED90(int nArg1, int nArg2, int nArg3)
{
    return ((D2NetQServerCall3)FOG_10159)(gpServer, nArg1, nArg2, nArg3);
}

// 0x0052B4B0
int __stdcall SERVER_GetIpAddressFromClientId(int nArg1)
{
    return FOG_10158(gpServer, nArg1);
}

// 0x0052B4D0
int __stdcall SERVER_GetSocketFromClientId(int nArg1)
{
    return FOG_10161(gpServer, nArg1);
}

// 0x0052B4F0
int __stdcall SERVER_HackListClient(int nArg1, int nArg2, int nArg3)
{
    return ((D2NetQServerCall3)QSERVER_HackListClient)(gpServer, nArg1, nArg2, nArg3);
}

// 0x0052B510
int __stdcall SERVER_HackListIP(int nArg1, int nArg2, int nArg3)
{
    return ((D2NetQServerCall3)QSERVER_HackListIP)(gpServer, nArg1, nArg2, nArg3);
}

// 0x0052B530
int __stdcall SERVER_HackUnlistIP(int nArg1, int nArg2, int nArg3)
{
    return ((D2NetQServerCall3)QSERVER_HackUnlistIP)(gpServer, nArg1, nArg2, nArg3);
}

// 0x0052B550
int __stdcall SERVER_DisconnectIP(int nArg1, int nArg2, int nArg3)
{
    return ((D2NetQServerCall3)QSERVER_DisconnectIP)(gpServer, nArg1, nArg2, nArg3);
}

// 0x0052B570
void __stdcall D2NET_10016(int nClientId)
{
    FOG_10165(gpServer, nClientId, ".\\SRC\\Server.cpp", 468);
}

// 0x0052B5A0
void __stdcall D2NET_10018(int nClientId)
{
    if (!gpServer)
    {
        return;
    }

    FOG_10170(gpServer, (D2NetAddressCallback)nClientId);
}

// 0x0052B5C0
int __stdcall SERVER_SetRemoveClientCallback(D2NET_Unk_Callback pfCallback)
{
    return ((D2NetQServerCall1)FOG_10171)(gpServer, (int)pfCallback);
}

// 0x0052B5E0
int __stdcall SERVER_SetClientGameGUID(int nClientId, int dwGameGuid)
{
    if (nClientId)
    {
        return ((D2NetQServerCall2)FOG_10172)(gpServer, nClientId, dwGameGuid);
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
int __fastcall SERVER_EnqueueClientPacket(const unsigned char* pBuffer, unsigned short nBufferSize, int nClientId)
{
    D2_ASSERT(nBufferSize <= MAX_MSG_SIZE, 521);

    return FOG_10175(gpServer, pBuffer, nBufferSize, nClientId);
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
    FOG_10182_Return((int)gpServer);
}

// 0x0052B700
void __stdcall D2NET_10029_Return(int nUnused)
{
    FOG_10183_Return((int)gpServer, nUnused);
}

// 0x0052B720
int __fastcall SERVER_OnClientConnectedCallback(D2QueueServerStrc* pServer, int nClientId, const char* szFile, int nLine)
{
    unsigned char data[2];
    data[0] = 0xAF;
    data[1] = 1;
    SERVER_SendPacketToClient(0, (void*)nClientId, data, sizeof(data));
    return 1;
}

// 0x0052B750
int __fastcall SERVER_OnClientDisconnectedCallback(int nArg1, int nClientId, int nArg3, int nArg4)
{
    const unsigned char data[1] = { 0x70 };

    FOG_10175(gpServer, data, sizeof(data), nClientId);
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
void __stdcall SERVER_Initialize(int nState, int bDisableNt)
{
    gpServer = QSInit(nState, 3, GAME_PORT, bDisableNt, (D2NetMessageCallback)SERVER_ValidateClientPacket, (D2NetClientCallback)SERVER_OnClientConnectedCallback, (D2NetClientCallback)SERVER_OnClientDisconnectedCallback, (D2NetHandlerCallback)SERVER_SendToLocalClientCallback);
}
