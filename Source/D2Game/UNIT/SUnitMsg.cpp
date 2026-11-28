#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2ItemModes.h"
#include "D2Game.h"
#include "D2LevelTxt.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Constants.h"
#include "D2Txt.h"
#include "D2Primitives.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2GameAux.h"
#include "D2GameRecords.h"
#include "D2GameObjs.h"
#include "D2Packets.h"
#include "D2LanguageNames.h"
#include "FogApi.h"
#include "D2CommonApi.h"
#include "FogApi.h"
#include "D2CommonApi2.h"
// build: symbol _gaszLanguageNames 0x007326B8

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern const unsigned int gdwBitMasks[32]; // 0x006CE268

extern const unsigned int gdwInvBitMasks[32]; // 0x006CE2E8

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize); // 0x006829C0

int __stdcall BITMANIP_GetSize(D2BitBufferStrc* pBuffer); // 0x00410E90

#include "D2GameFuncs.h"

void __fastcall D2GAME_PACKETS_SendPacket0xA7_StateOn(D2ClientStrc* pClient, unsigned char nUnitType, unsigned long dwUnitId, unsigned char nState); // 0x0053E260

void __fastcall D2GAME_PACKETS_SendPacket0xA9_StateOff(D2ClientStrc* pClient, unsigned char nUnitType, unsigned long dwUnitId, unsigned char nState); // 0x0053E290

#define D2_MIN(a,b) (((a)<(b))?(a):(b))

#define D2_MAX(a,b) (((a)>(b))?(a):(b))


#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define NPC_LEVEL_COUNT 5

struct D2NpcRecordStrc;


struct D2UnitPacketListStrc;

struct D2UnitPacketLifeStrc;

struct D2UnitPacketSkillStrc;

struct D2UnitPacketPrecacheStrc;

struct D2PetInfoStrc;

struct D2PetDataStrc;

struct D2PetListStrc;

struct D2PlayerPetStrc;

struct D2PlayerDataStrc;

struct D2MonsterDataStrc;

struct D2NpcIndexMapStrc;

struct D2UnitPacketSkillEventStrc;

struct D2UnitStrc;

struct D2DataTablesStrc;

struct D2BitBufferStrc;


struct D2GameStrc;

struct D2CoordStrc;

struct D2ObjectsTxt;

struct D2ObjectDataStrc;

struct D2MonStatsTxt;

struct D2UnitPacketLifeStrc
{
    D2UnitPacketListStrc* pNext;
    unsigned char nHeader;
    char unk0x05[0x03];
    unsigned char nUnitType;
    char unk0x09[0x03];
    int nUnitGUID;
    unsigned char nLife;
    char unk0x11[0x03];
};

struct D2UnitPacketSkillStrc
{
    D2UnitPacketListStrc* pNext;
    unsigned char nHeader;
    char unk0x05[0x03];
    unsigned char nUnitType;
    char unk0x09[0x03];
    int nUnitGUID;
    short nSkillId;
    char unk0x12[0x02];
};

struct D2UnitPacketPrecacheStrc
{
    D2UnitPacketListStrc* pNext;
    unsigned char nHeader;
    char unk0x05[0x03];
    short nMonsterClassId;
    char unk0x0A[0x02];
};

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

void* __fastcall GFXUTIL_GetNextRosterInfo(D2UnitStrc* pUnit); // 0x004DC0B0


void __fastcall D2GAME_PACKETS_SendPacket0x11(D2ClientStrc* pClient, int nUnitType, int nUnitGUID, int nOverlay); // 0x0053D850

extern "C" const char gszEmptyAssertText; // 0x006CC837


extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09






struct D2UnitPacketSkillEventStrc
{
    D2UnitPacketListStrc* pNext;
    unsigned char nHeader;
    char unk0x05[0x03];
    unsigned char nSkillParam;
    char unk0x09;
    short nSkillId;
    short nSkillLevel;
    char unk0x0E[0x02];
    int nUnitType;
    int nUnitGUID;
    int nTargetType;
    int nTargetGUID;
    int nX;
    int nY;
};

int __fastcall sub_00451F30_TestUnitFlag(D2UnitStrc*, int); // 0x00451F30

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int); // 0x00451F80

int __fastcall ITEMS_CheckUnitFlagEx(D2UnitStrc*, unsigned int); // 0x00463720

void __fastcall PLAYER_SynchronizeItemsToClient(D2UnitStrc*, D2ClientStrc*); // 0x00534F80


void __fastcall D2GAME_PACKETS_SendPacket0x09(D2ClientStrc*, unsigned char, unsigned char, unsigned int, unsigned char, unsigned short, unsigned short); // 0x0053BCD0

void __fastcall D2GAME_PACKETS_SendPacket0x51(D2ClientStrc*, unsigned char, unsigned char, int, unsigned short, unsigned short, unsigned short, unsigned char, unsigned char); // 0x0053BD10


void __fastcall D2GAME_PACKETS_SendPacket0x74(D2ClientStrc*, D2UnitStrc*, D2UnitStrc*, unsigned char); // 0x0053DA40

void __fastcall D2GAME_PACKETS_SendPacket0x82(D2GameStrc*, D2ClientStrc*, int, int); // 0x0053DB90

void __fastcall D2GAME_PACKETS_SendPacket0x98(D2ClientStrc*, unsigned int, unsigned short); // 0x0053E0A0

void __fastcall SCMD_SendMonsterAssign(D2ClientStrc*, D2UnitStrc*); // 0x0053E2E0

void __fastcall SCMD_SendPlayerSpawnAndPartyRoster(D2ClientStrc*, int, unsigned char, const char*, short, short); // 0x0053E8F0

void __fastcall D2GAME_SendP0x9C_ItemAction_AddToGround(D2ClientStrc*, D2UnitStrc*, unsigned int); // 0x0053EC00


void __fastcall PLRMSG_SendUnitBaseStats(D2UnitStrc*, D2ClientStrc*); // 0x005489F0

D2UnitStrc* __fastcall SUNIT_GetServerUnit(D2GameStrc*, int, int); // 0x00552F60


void __fastcall MISSILES_SyncToClient(D2ClientStrc*, D2GameStrc*, D2UnitStrc*, int); // 0x0059FEE0



#define STAT_ID_LIMIT 255

#define ASSERT_LINE 704

#define ALLOC_LINE 709

#define MESSAGE_SIZE 24

#define PAYLOAD_SHIFT 0

#define MESSAGE_HEADER 0xA1

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0);   // 0x0040B430

struct D2UnitPacketListStrc
{
    D2UnitPacketListStrc* pNext;
    unsigned char nHeader;
    unsigned char unk0x05[3];
    union
    {
        struct
        {
            unsigned int dwParam;
            unsigned short wParam;
            unsigned char nParam;
        } p23;
        struct
        {
            unsigned short wSkill;
            unsigned char nSkillLevel;
            unsigned char nUnitType;
            unsigned int dwUnitGUID;
            unsigned char nParam;
        } p99;
        struct
        {
            unsigned short wSkill;
            unsigned char nSkillLevel;
            unsigned char unk0x0B;
            unsigned short wX;
            unsigned short wY;
            unsigned char nParam;
        } p9A;
        struct
        {
            unsigned int unk0x08;
            unsigned char nStatId;
            unsigned char unk0x0D[3];
            unsigned int dwValue;
            unsigned int dwFullValue;
        } pStat;
        struct
        {
            unsigned char nSeed;
            unsigned char unk0x09;
            unsigned short nSkillId;
            unsigned short nSkillLevel;
            unsigned short unk0x0E;
            unsigned int nUnitType;
            unsigned int nUnitGUID;
            unsigned int nTargetType;
            unsigned int nTargetGUID;
            unsigned int nX;
            unsigned int nY;
        } pA3;
        struct
        {
            short nMonStatsId;
        } pA4;
        struct
        {
            unsigned char nUnitType;
            unsigned char unk0x09[3];
            unsigned int nUnitGUID;
            unsigned short nSkillId;
        } pA5;
        struct
        {
            unsigned char nUnitType;
            unsigned char unk0x09[3];
            unsigned int dwUnitId;
            unsigned char nUnitLife;
        } pAB;
    };
};

int __fastcall GAME_GetUnitTypeOrInvalid(D2UnitStrc* pUnit);                                        // 0x0044BE50

int __fastcall GAME_GetUnitGUID(D2UnitStrc* pUnit);                                                 // 0x00451F50

void __fastcall D2GAME_PACKETS_SendPacket0x9E_9F_A0(D2ClientStrc* pClient, D2UnitStrc* pUnit, unsigned short nStatId, unsigned int nValue); // 0x0053BEE0


void __fastcall SCMD_SendSkillUseOnUnit(D2ClientStrc* pClient, unsigned char nSourceUnitType, int nSourceUnitGUID, unsigned char nUnitType, int nUnitGUID, unsigned short nSkillId, unsigned short nSkillParam, unsigned char nSkillLevel, int bQueued); // 0x0053D530

void __fastcall D2GAME_PACKETS_SendPacket0xA4(D2ClientStrc* pClient, short nMonStatsId);                    // 0x0053E1A0


void __fastcall D2GAME_PACKETS_SendPacketSize06(D2ClientStrc*, unsigned char, int, int); // 0x0053B3D0

void __fastcall SCMD_SendPacket0x2C(D2ClientStrc* pClient, D2GSPacketSrv2C* pPacket); // 0x0053D780


static inline D2StatesTxt* GetStatesRecord(int nState)
{
    if (nState >= 0 && nState < sgptDataTables->nStatesTxtRecordCount) return &sgptDataTables->pStatesTxt[nState];
    return 0;
}

static inline D2ItemStatCostTxt* GetStatCostRecord(int nStat)
{
    if (nStat >= 0 && nStat < sgptDataTables->nItemStatCostTxtRecordCount) return &sgptDataTables->pItemStatCostTxt[nStat];
    return 0;
}


static inline D2StatesTxt* SKILLS_GetStatesTxtRecord(int id) { if (id < 0 || id >= sgptDataTables->nStatesTxtRecordCount) return 0; return &sgptDataTables->pStatesTxt[id]; }

static inline D2ItemStatCostTxt* SKILLS_GetItemStatCostTxtRecord(int id) { if (id < 0 || id >= sgptDataTables->nItemStatCostTxtRecordCount) return 0; return &sgptDataTables->pItemStatCostTxt[id]; }

static inline int sub_GetUnitTypeOrInvalid(D2UnitStrc* pUnit) { if (!pUnit) return UNIT_INVALID; return pUnit->dwUnitType; }

// 0x00570E30
void __fastcall D2GAME_STATES_SendUnitStates(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    D2BitBufferStrc bitBuffer;
    unsigned int nFlags[8];
    D2StatStrc stats[16];
    if (!pUnit || !pClient) return;
    unsigned int* pFlags = D2COMMON_10494_STATES_GetStatFlags(pUnit);
    const int nTotalStatFlagCount = (sgptDataTables->nStatesTxtRecordCount + 31) / 32;
    memcpy(nFlags, pFlags, sizeof(unsigned int) * nTotalStatFlagCount);
    D2GSPacketSrvAA packetAA;
    packetAA.nHeader = 0xAA;
    packetAA.nUnitType = sub_GetUnitTypeOrInvalid(pUnit);
    packetAA.nUnitId = pUnit->dwUnitId;
    BITMANIP_Initialize(&bitBuffer, packetAA.pStream, 244);
    int i = 0;
    int nStateOffset = 0;
    for (; i < nTotalStatFlagCount; ++i, nStateOffset += 32)
    {
        int nBit = sub_004111A0_GetLowestSetBit(nFlags[i]);
        while (nBit >= 0)
        {
            nFlags[i + (nBit >> 5)] &= gdwInvBitMasks[nBit & 31];
            const int nStateId = nBit + nStateOffset;
            D2StatesTxt* pStatesTxtRecord = SKILLS_GetStatesTxtRecord(nStateId);
            if (!pStatesTxtRecord) { nBit = sub_004111A0_GetLowestSetBit(nFlags[i]); continue; }
            if (pStatesTxtRecord->nStateFlags[0] & gdwBitMasks[0]) { nBit = sub_004111A0_GetLowestSetBit(nFlags[i]); continue; }
            {
                if (BITMANIP_GetSize(&bitBuffer) + 7 >= 219) break;
                BITMANIP_Write(&bitBuffer, nStateId, 8);
                D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nStateId);
                if (pStatList)
                {
                    const int nStatCount = STATLIST_GetBaseStatsData(pStatList, stats, 16);
                    if (nStatCount > 0)
                    {
                        BITMANIP_Write(&bitBuffer, 1, 1);
                        for (int j = 0; j < nStatCount; ++j)
                        {
                            const int nStatId = (unsigned int)stats[j].nPackedValue >> 16;
                            const unsigned short nLayer = stats[j].nLayer;
                            int nValue = stats[j].nValue;
                            D2ItemStatCostTxt* pItemStatCostTxtRecord = SKILLS_GetItemStatCostTxtRecord(nStatId);
                            if (pItemStatCostTxtRecord && pItemStatCostTxtRecord->nSendBits > 0)
                            {
                                if (pItemStatCostTxtRecord->nSendBits < 32)
                                {
                                    if (pItemStatCostTxtRecord->nItemStatFlags[0] & gdwBitMasks[1])
                                    {
                                        const int nMin = -1 << (pItemStatCostTxtRecord->nSendBits - 1);
                                        nValue = D2_MIN(D2_MAX(nValue, nMin), (1 << (pItemStatCostTxtRecord->nSendBits - 1)) - 1);
                                    }
                                    else
                                    {
                                        nValue = D2_MIN(D2_MAX(nValue, 0), (1 << pItemStatCostTxtRecord->nSendBits) - 1);
                                    }
                                }
                                BITMANIP_Write(&bitBuffer, nStatId, 9);
                                if (pItemStatCostTxtRecord->nSendParamBits)
                                    BITMANIP_Write(&bitBuffer, nLayer, pItemStatCostTxtRecord->nSendParamBits);
                                BITMANIP_Write(&bitBuffer, nValue, pItemStatCostTxtRecord->nSendBits);
                            }
                        }
                        BITMANIP_Write(&bitBuffer, 0x1FF, 9);
                    }
                    else BITMANIP_Write(&bitBuffer, 0, 1);
                }
                else BITMANIP_Write(&bitBuffer, 0, 1);
            }
            nBit = sub_004111A0_GetLowestSetBit(nFlags[i]);
        }
    }
    BITMANIP_Write(&bitBuffer, 0xFF, 8);
    const int nSize = BITMANIP_GetSize(&bitBuffer) + 7;
    packetAA.nSize = nSize;
    SCMD_SendRawPacket(pClient, &packetAA, nSize);
}

// 0x005711D0
void __fastcall D2GAME_STATES_SendUnitStateUpdates(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    if (!pUnit || !pClient) return;
    unsigned int dwFlags[8];
    unsigned int* pGfxFlags = STATES_GetGfxStateFlags(pUnit);
    int nWords = (sgptDataTables->nStatesTxtRecordCount + 31) / 32;
    memcpy(dwFlags, pGfxFlags, nWords * sizeof(unsigned int));
    int nUnitType = pUnit->dwUnitType;
    int nUnitId = pUnit->dwUnitId;
    int i = 0;
    int nStateBase = 0;
    for (; i < nWords; ++i, nStateBase += 32)
    {
        int nBit = sub_004111A0_GetLowestSetBit(dwFlags[i]);
        while (nBit >= 0)
        {
            dwFlags[i + (nBit >> 5)] &= gdwInvBitMasks[nBit & 31];
            int nState = nStateBase + nBit;
            D2StatesTxt* pStates = GetStatesRecord(nState);
            if (pStates)
            {
                if (pStates->nStateFlags[0] & gdwBitMasks[0])
                {
                    nBit = sub_004111A0_GetLowestSetBit(dwFlags[i]);
                    continue;
                }
                if (STATES_CheckState(pUnit, nState))
                {
                    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, nState);
                    if (pStatList)
                    {
                        D2StatStrc stats[16];
                        int nStats = STATLIST_GetBaseStatsData(pStatList, stats, 16);
                        if (nStats > 0)
                        {
                            D2GSPacketSrvA8 packet;
                            D2BitBufferStrc bitBuffer;
                            packet.nHeader = 0xA8;
                            packet.nUnitType = (unsigned char)nUnitType;
                            packet.nUnitId = nUnitId;
                            packet.nState = (unsigned char)nState;
                            BITMANIP_Initialize(&bitBuffer, packet.pData, sizeof(packet.pData));
                            for (int j = 0; j < nStats; ++j)
                            {
                                const int nStatId = (unsigned int)stats[j].nPackedValue >> 16;
                                const unsigned short nLayer = stats[j].nLayer;
                                int nValue = stats[j].nValue;
                                D2ItemStatCostTxt* pCost = GetStatCostRecord(nStatId);
                                if (pCost && pCost->nSendBits > 0)
                                {
                                    if (pCost->nSendBits < 32)
                                    {
                                        if (pCost->nItemStatFlags[0] & gdwBitMasks[1])
                                        {
                                            const int nMin = -1 << (pCost->nSendBits - 1);
                                            nValue = D2_MIN(D2_MAX(nValue, nMin), (1 << (pCost->nSendBits - 1)) - 1);
                                        }
                                        else
                                        {
                                            nValue = D2_MIN(D2_MAX(nValue, 0), (1 << pCost->nSendBits) - 1);
                                        }
                                    }
                                    BITMANIP_Write(&bitBuffer, nStatId, 9);
                                    if (pCost->nSendParamBits)
                                        BITMANIP_Write(&bitBuffer, nLayer, pCost->nSendParamBits);
                                    BITMANIP_Write(&bitBuffer, nValue, pCost->nSendBits);
                                }
                            }
                            BITMANIP_Write(&bitBuffer, 511, 9);
                            int nPacketSize = BITMANIP_GetSize(&bitBuffer) + 8;
                            packet.nSize = (unsigned char)nPacketSize;
                            SCMD_SendRawPacket(pClient, &packet, nPacketSize);
                        }
                        else D2GAME_PACKETS_SendPacket0xA7_StateOn(pClient, (unsigned char)nUnitType, nUnitId, (unsigned char)nState); // 0x0053E260
                    }
                    else D2GAME_PACKETS_SendPacket0xA7_StateOn(pClient, (unsigned char)nUnitType, nUnitId, (unsigned char)nState); // 0x0053E260
                }
                else D2GAME_PACKETS_SendPacket0xA9_StateOff(pClient, (unsigned char)nUnitType, nUnitId, (unsigned char)nState); // 0x0053E290
            }
            nBit = sub_004111A0_GetLowestSetBit(dwFlags[i]);
        }
    }
}

// 0x00571580
void __fastcall D2GAME_STATES_SendStates(D2UnitStrc* pUnit, D2ClientStrc* pClient, int bPlayer)
{
    if (bPlayer)
    {
        D2GAME_STATES_SendUnitStates(pUnit, pClient);
    }
    else
    {
        D2GAME_STATES_SendUnitStateUpdates(pUnit, pClient);
    }
}

// 0x005715A0
void __fastcall SUNITMSG_SendOverlay(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndFlag(pUnit, 0x80);
    if (pStatList)
    {
        const int nOverlay = STATLIST_GetTotalStatValue_Layer0(pStatList, STAT_UNIT_DOOVERLAY);
        if (nOverlay >= 0 && nOverlay <= sgptDataTables->nOverlayTxtRecordCount)
        {
            D2GAME_PACKETS_SendPacket0x11(pClient, !pUnit ? UNIT_INVALID : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId, nOverlay);
        }
    }
}

// 0x00571600
void __fastcall SUNITMSG_SendRemoveObject(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    D2GAME_PACKETS_SendPacket0x0A_RemoveObject(pClient, 0x0A, pUnit->dwUnitType, pUnit->dwUnitId);
}

static inline int UNITS_GetUnitTypeInline(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        return pUnit->dwUnitType;
    }

    return UNIT_INVALID;
}

// 0x00571740
void __fastcall D2GAME_UpdateUnit(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    D2UnitStrc* pUpdateUnit = pUnit->pUpdateUnit;
    if (!pUpdateUnit || CLIENTS_GetPlayerFromClient(pClient, 0) == pUpdateUnit)
    {
        D2GSPacketSrv2C packet2C;
        packet2C.nHeader = 0x2C;
        packet2C.dwUnitGUID = pUnit->dwUnitId;
        packet2C.nUnitType = UNITS_GetUnitTypeInline(pUnit);
        packet2C.nSoundEvent = pUnit->nUpdateType;
        SCMD_SendPacket0x2C(pClient, &packet2C);
    }
}

// 0x00571790
static inline void SUNITMSG_AppendUnitMessage(D2UnitStrc* pUnit, D2UnitPacketListStrc* pMsg)
{
    if (!pUnit->pMsgFirst)
    {
        pUnit->pMsgFirst = pMsg;
    }

    if (pUnit->pMsgLast)
    {
        pUnit->pMsgLast->pNext = pMsg;
    }

    pUnit->pMsgLast = pMsg;
    UNITROOM_RefreshUnit(pUnit);
}

// 0x005717C0
void __fastcall SUNITMSG_QueueItemSkillOnUnit(D2UnitStrc* pUnit, int nSkillId, unsigned char nSkillLevel, unsigned char nUnitType, int nUnitGUID, unsigned char nSkillParam)
{
    D2UnitPacketListStrc* pMsg = (D2UnitPacketListStrc*)FOG_AllocPool(!pUnit ? 0 : pUnit->pMemoryPool, 20, ".\\UNIT\\SUnitMsg.cpp", 644, 0);
    *((unsigned char*)pMsg + 10) = nSkillLevel;
    *((unsigned char*)pMsg + 11) = nUnitType;
    pMsg->nHeader = 0x99;
    pMsg->pNext = 0;
    *((short*)pMsg + 4) = nSkillId;
    *((int*)pMsg + 3) = nUnitGUID;
    *((unsigned char*)pMsg + 16) = nSkillParam;

    if (!pUnit->pMsgFirst)
    {
        pUnit->pMsgFirst = pMsg;
    }

    if (pUnit->pMsgLast)
    {
        pUnit->pMsgLast->pNext = pMsg;
    }

    pUnit->pMsgLast = pMsg;
    UNITROOM_RefreshUnit(pUnit);
}

// 0x00571840
void __fastcall SUNITMSG_QueueItemSkillOnPosition(D2UnitStrc* pUnit, int nSkillId, unsigned char nSkillLevel, short nX, short nY, unsigned char nSkillParam)
{
    D2UnitPacketListStrc* pMsg = (D2UnitPacketListStrc*)FOG_AllocPool(!pUnit ? 0 : pUnit->pMemoryPool, 20, ".\\UNIT\\SUnitMsg.cpp", 667, 0);
    *((unsigned char*)pMsg + 10) = nSkillLevel;
    *((short*)pMsg + 6) = nX;
    pMsg->nHeader = 0x9A;
    pMsg->pNext = 0;
    *((short*)pMsg + 4) = nSkillId;
    *((short*)pMsg + 7) = nY;
    *((unsigned char*)pMsg + 16) = nSkillParam;

    if (!pUnit->pMsgFirst)
    {
        pUnit->pMsgFirst = pMsg;
    }

    if (pUnit->pMsgLast)
    {
        pUnit->pMsgLast->pNext = pMsg;
    }

    pUnit->pMsgLast = pMsg;
    UNITROOM_RefreshUnit(pUnit);
}

// 0x005718C0
void __fastcall D2GAME_MERCS_SendStat(D2UnitStrc* pUnit, unsigned short wStat, int nValue)
{
    D2_ASSERT(wStat < ((unsigned char)-1), 685);

    D2UnitPacketListStrc* pMsg = (D2UnitPacketListStrc*)FOG_AllocPool(!pUnit ? 0 : pUnit->pMemoryPool, 20, ".\\UNIT\\SUnitMsg.cpp", 687, 0);
    pMsg->nHeader = 0x9E;
    pMsg->pNext = 0;
    *((int*)pMsg + 2) = !pUnit ? -1 : pUnit->dwUnitId;
    *((unsigned char*)pMsg + 12) = (unsigned char)wStat;
    *((int*)pMsg + 4) = nValue;

    if (!pUnit->pMsgFirst)
    {
        pUnit->pMsgFirst = pMsg;
    }

    if (pUnit->pMsgLast)
    {
        pUnit->pMsgLast->pNext = pMsg;
    }

    pUnit->pMsgLast = pMsg;
    UNITROOM_RefreshUnit(pUnit);
}

// 0x00571960
void __fastcall SUNITMSG_QueueStatChange(D2UnitStrc* pUnit, unsigned short nStat, int nOldValue, int nNewValue)
{
    D2_ASSERT(nStat < STAT_ID_LIMIT, ASSERT_LINE);
    if (nOldValue != nNewValue)
    {
        D2UnitPacketListStrc* pMsg = (D2UnitPacketListStrc*)sub_0040B430(!pUnit ? 0 : pUnit->pMemoryPool, MESSAGE_SIZE, ".\\UNIT\\SUnitMsg.cpp", ALLOC_LINE, 0);
        pMsg->nHeader = MESSAGE_HEADER;
        pMsg->pNext = 0;
        *(int*)((char*)pMsg + 8 + PAYLOAD_SHIFT) = !pUnit ? -1 : pUnit->dwUnitId;
        *((unsigned char*)pMsg + 12 + PAYLOAD_SHIFT) = (unsigned char)nStat;
        *(int*)((char*)pMsg + 16 + PAYLOAD_SHIFT) = nOldValue;
        *(int*)((char*)pMsg + 20 + PAYLOAD_SHIFT) = nNewValue;
        if (!pUnit->pMsgFirst)
            pUnit->pMsgFirst = pMsg;
        if (pUnit->pMsgLast)
            pUnit->pMsgLast->pNext = pMsg;
        pUnit->pMsgLast = pMsg;
        UNITROOM_RefreshUnit(pUnit);
    }
}

// 0x00571A10
void __fastcall SUNITMSG_QueueLifeUpdate(D2UnitStrc* pUnit, unsigned char nLifePercent)
{
    D2UnitPacketLifeStrc* pMsg = (D2UnitPacketLifeStrc*)FOG_AllocPool(!pUnit ? 0 : pUnit->pMemoryPool, sizeof(D2UnitPacketLifeStrc), ".\\UNIT\\SUnitMsg.cpp", 729, 0);
    memset(pMsg, 0, sizeof(D2UnitPacketLifeStrc));
    pMsg->nHeader = 0xAB;
    pMsg->nUnitType = !pUnit ? UNIT_INVALID : pUnit->dwUnitType;
    pMsg->nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    pMsg->nLife = nLifePercent;

    if (!pUnit->pMsgFirst)
    {
        pUnit->pMsgFirst = (D2UnitPacketListStrc*)pMsg;
    }

    if (pUnit->pMsgLast)
    {
        pUnit->pMsgLast->pNext = (D2UnitPacketListStrc*)pMsg;
    }

    pUnit->pMsgLast = (D2UnitPacketListStrc*)pMsg;
    UNITROOM_RefreshUnit(pUnit);
}

struct D2ClientStrc;

// 0x00571AA0
void __fastcall SUNITMSG_QueueSkillEvent(D2UnitStrc* pUnit, D2UnitStrc* pTargetUnit, short nSkillId, short nSkillLevel, int nX, int nY, unsigned char nSkillParam)
{
    D2UnitPacketSkillEventStrc* pMsg = (D2UnitPacketSkillEventStrc*)FOG_AllocPool(!pUnit ? 0 : pUnit->pMemoryPool, sizeof(D2UnitPacketSkillEventStrc), ".\\UNIT\\SUnitMsg.cpp", 746, 0);
    memset(pMsg, 0, sizeof(D2UnitPacketSkillEventStrc));
    pMsg->pNext = 0;
    pMsg->nHeader = 0xA3;
    pMsg->nSkillParam = nSkillParam;
    pMsg->nSkillId = nSkillId;
    pMsg->nSkillLevel = nSkillLevel;
    pMsg->nUnitType = !pUnit ? UNIT_INVALID : pUnit->dwUnitType;
    pMsg->nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    pMsg->nX = nX;
    pMsg->nY = nY;

    if (pTargetUnit)
    {
        const int nTargetType = (pTargetUnit ? pTargetUnit->dwUnitType : UNIT_INVALID);
        pMsg->nTargetType = nTargetType;
        const int nTargetGUID = (pTargetUnit ? pTargetUnit->dwUnitId : -1);
        pMsg->nTargetGUID = nTargetGUID;
    }
    else
    {
        pMsg->nTargetGUID = -1;
    }

    if (!pUnit->pMsgFirst)
    {
        pUnit->pMsgFirst = (D2UnitPacketListStrc*)pMsg;
    }

    if (pUnit->pMsgLast)
    {
        pUnit->pMsgLast->pNext = (D2UnitPacketListStrc*)pMsg;
    }

    pUnit->pMsgLast = (D2UnitPacketListStrc*)pMsg;
    UNITROOM_RefreshUnit(pUnit);
}

// 0x00571B70
void __fastcall SUNITMSG_QueueSkillStop(D2UnitStrc* pUnit, int nSkillId)
{
    STATES_ToggleState(pUnit, STATE_SKILL_MOVE, 0);

    D2UnitPacketSkillStrc* pMsg = (D2UnitPacketSkillStrc*)FOG_AllocPool(!pUnit ? 0 : pUnit->pMemoryPool, sizeof(D2UnitPacketSkillStrc), ".\\UNIT\\SUnitMsg.cpp", 783, 0);
    memset(pMsg, 0, sizeof(D2UnitPacketSkillStrc));
    pMsg->pNext = 0;
    pMsg->nHeader = 0xA5;
    pMsg->nUnitType = !pUnit ? UNIT_INVALID : pUnit->dwUnitType;
    pMsg->nUnitGUID = !pUnit ? -1 : pUnit->dwUnitId;
    pMsg->nSkillId = nSkillId;

    if (!pUnit->pMsgFirst)
    {
        pUnit->pMsgFirst = (D2UnitPacketListStrc*)pMsg;
    }

    if (pUnit->pMsgLast)
    {
        pUnit->pMsgLast->pNext = (D2UnitPacketListStrc*)pMsg;
    }

    pUnit->pMsgLast = (D2UnitPacketListStrc*)pMsg;
    UNITROOM_RefreshUnit(pUnit);
}

// 0x00571C00
void __fastcall SUNITMSG_QueueMonsterPrecache(D2UnitStrc* pUnit, int nMonsterClassId)
{
    D2UnitPacketPrecacheStrc* pMsg = (D2UnitPacketPrecacheStrc*)FOG_AllocPool(!pUnit ? 0 : pUnit->pMemoryPool, sizeof(D2UnitPacketPrecacheStrc), ".\\UNIT\\SUnitMsg.cpp", 802, 0);
    pMsg->nHeader = 0xA4;
    pMsg->pNext = 0;
    pMsg->nMonsterClassId = nMonsterClassId;

    if (!pUnit->pMsgFirst)
    {
        pUnit->pMsgFirst = (D2UnitPacketListStrc*)pMsg;
    }

    if (pUnit->pMsgLast)
    {
        pUnit->pMsgLast->pNext = (D2UnitPacketListStrc*)pMsg;
    }

    pUnit->pMsgLast = (D2UnitPacketListStrc*)pMsg;
    UNITROOM_RefreshUnit(pUnit);
}

// 0x00571C60
void __fastcall SUNITMSG_QueueSkillSelection(D2UnitStrc* pUnit, int bLeftSkill, short nSkillId, int nOwnerGUID)
{
    D2UnitPacketListStrc* pMsg = (D2UnitPacketListStrc*)FOG_AllocPool(!pUnit ? 0 : pUnit->pMemoryPool, 16, ".\\UNIT\\SUnitMsg.cpp", 818, 0);
    pMsg->nHeader = 0x23;
    pMsg->pNext = 0;
    *((unsigned char*)pMsg + 14) = bLeftSkill;
    *((short*)pMsg + 6) = nSkillId;
    *((int*)pMsg + 2) = nOwnerGUID;

    if (!pUnit->pMsgFirst)
    {
        pUnit->pMsgFirst = pMsg;
    }

    if (pUnit->pMsgLast)
    {
        pUnit->pMsgLast->pNext = pMsg;
    }

    pUnit->pMsgLast = pMsg;
    UNITROOM_RefreshUnit(pUnit);
}

// 0x00571F40
void __fastcall D2GAME_SUNITMSG_FreeUnitMessages(D2UnitStrc* pUnit)
{
    D2UnitPacketListStrc* pMsg = pUnit->pMsgFirst;
    if (pMsg)
    {
        do
        {
            D2UnitPacketListStrc* pFree = pMsg;
            pMsg = pMsg->pNext;
            FOG_FreeServerMemory(GFXUTIL_GetNextRosterInfo(pUnit), pFree, ".\\UNIT\\SUnitMsg.cpp", 974, 0);
        }
        while (pMsg);

        pUnit->pMsgLast = 0;
        pUnit->pMsgFirst = 0;
    }
}

static inline int UnitHasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit) return (pUnit->dwFlags & nFlag) != 0;
    return 0;
}

static inline int UnitGUID(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

static inline D2DynamicPathStrc* UnitPath(D2UnitStrc* pUnit)
{
    return !pUnit ? 0 : pUnit->pDynamicPath;
}

static inline D2InventoryStrc* UnitInventory(D2UnitStrc* pUnit)
{
    return !pUnit ? 0 : pUnit->pInventory;
}

// 0x00571F90
void __fastcall SUNITMSG_SendUnitToClient(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    const int nClassId = !pUnit ? -1 : pUnit->dwClassId;
    D2CoordStrc tCoords;
    UNITS_GetCoords(pUnit, &tCoords);
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        SCMD_SendPlayerSpawnAndPartyRoster(pClient, pUnit->dwUnitId, pUnit->dwClassId, pUnit->pPlayerData->szName, tCoords.nX, tCoords.nY);
        break;
    case UNIT_ITEM:
        if (UnitHasFlag(pUnit, 0x10))
        {
            if (pUnit->dwAnimMode == IMODE_ONGROUND && sub_00451F30_TestUnitFlag(pUnit, 0x1000))
                D2GAME_SendP0x9C_ItemAction_DropToGround(pClient, pPlayer, pUnit, 0);
            else D2GAME_SendP0x9C_ItemAction_AddToGround(pClient, pUnit, 0); // 0x0053EC00
        }
        break;
    case UNIT_OBJECT:
        D2GAME_PACKETS_SendPacket0x51(pClient, 0x51, 2, pUnit->dwUnitId, pUnit->dwClassId, tCoords.nX, tCoords.nY, pUnit->dwAnimMode, pUnit->pObjectData->InteractType);
        if (pUnit->pObjectData->pObjectTxt->nSubClass & 4)
        {
            SCMD_SendPortalState(pClient, pUnit);
            if ((short)nClassId == 59)
            {
                D2UnitStrc* pOwner = SUNIT_GetPortalOwner(pGame, pUnit);
                int nOwnerId = -1;
                if (pOwner) nOwnerId = pOwner->dwUnitId;
                const int nPortalId = UnitGUID(pUnit);
                D2GAME_PACKETS_SendPacket0x82(pGame, pClient, nPortalId, nOwnerId);
            }
        }
        break;
    case UNIT_MONSTER:
        if (!SUNIT_IsDead(pUnit) || !STATES_CheckStateMaskHideOnUnit(pUnit))
        {
            SCMD_SendMonsterAssign(pClient, pUnit);
            STATLIST_SetUnitStat(pUnit, STAT_PIERCE_IDX, (unsigned short)(tCoords.nX + tCoords.nY), 0);
            if (pUnit->dwClassId == 528)
                D2GAME_PACKETS_SendPacket0x98(pClient, pUnit->dwUnitId, AIGENERAL_GetMinionSpawnClassId(pUnit));
            D2MonStatsTxt* pMonStatsTxt = DATATBLS_GetMonStatsTxtRecord(pUnit->dwClassId);
            if (pMonStatsTxt)
            {
                int i = 0;
                short* pSkillId = pMonStatsTxt->nSkill;
                for (; i < 8; ++i, ++pSkillId)
                {
                    if (pMonStatsTxt->nSendSkill[i >> 3] & gdwBitMasks[i & 7])
                    {
                        const unsigned short nSkillId = *pSkillId;
                        if ((short)nSkillId >= 0 && (short)nSkillId < sgptDataTables->nSkillsTxtRecordCount)
                        {
                            D2SkillStrc* pSkill = SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, (short)nSkillId);
                            if (pSkill)
                                D2GAME_PACKETS_SendPacket0x21_UpdateSkills(pClient, pUnit, nSkillId, SKILLS_GetSkillLevel(pUnit, pSkill, 0), 0);
                        }
                    }
                }
            }
            D2GAME_STATES_SendUnitStates(pUnit, pClient);
            SUNITMSG_SendQueuedMessages(pUnit, pClient);
        }
        break;
    case UNIT_MISSILE:
        MISSILES_SyncToClient(pClient, pGame, pUnit, PATH_GetVelocity(UnitPath(pUnit)));
        break;
    default:
        D2GAME_PACKETS_SendPacket0x09(pClient, 9, pUnit->dwUnitType, pUnit->dwUnitId, pUnit->dwClassId, tCoords.nX, tCoords.nY);
        break;
    }
    switch (pUnit->dwUnitType)
    {
    case UNIT_PLAYER:
        PLRMSG_SendUnitBaseStats(pUnit, pClient);
        if (SUNIT_IsDead(pUnit) && STATES_CheckState(pUnit, STATE_PLAYERBODY))
        {
            D2UnitStrc* pOwner = SUNIT_GetServerUnit(pGame, 0, INVENTORY_GetOwnerId(UnitInventory(pUnit)));
            D2_ASSERT(pOwner, 184);
            D2GAME_PACKETS_SendPacket0x74(pClient, pOwner, pUnit, ITEMS_CheckUnitFlagEx(pUnit, 0x1000));
        }
        else PLAYER_SynchronizeItemsToClient(pUnit, pClient);
        D2GAME_STATES_SendUnitStates(pUnit, pClient);
        PLRMSG_SendUnitMode(pGame, pUnit, pClient);
        SUNITMSG_SendQueuedMessages(pUnit, pClient);
        SUNITMSG_SendHoverText(pUnit, pClient);
        break;
    case UNIT_MONSTER:
        MONSTERMSG_SendMonsterModeUpdate(pGame, pUnit, pClient);
        if (STATES_CheckState(pUnit, STATE_VALKYRIE) || pUnit->dwClassId == 291 || pUnit->dwClassId == 417 || pUnit->dwClassId == 418)
            PLAYER_SynchronizeItemsToClient(pUnit, pClient);
        break;
    case UNIT_ITEM:
        ITEMMODE_SendGroundItemToClient(pUnit, pClient);
        break;
    case UNIT_OBJECT:
    case UNIT_MISSILE:
    case UNIT_TILE:
        return;
    }
}


// 0x00571620
void __fastcall SUNITMSG_SendHoverText(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    if (pUnit && pUnit->pHoverText)
    {
        D2HoverTextStrc* pHoverText = pUnit->pHoverText;
        CLIENTS_GetGame(pClient);
        D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
        if (pPlayer && pUnit->dwUnitType == UNIT_PLAYER)
        {
            if (PLAYERLIST_CheckFlag(pPlayer, pUnit, 4) || PLAYERLIST_CheckFlag(pUnit, pPlayer, 2))
                return;
        }
        D2GSPacketSrv26 packet;
        packet.dwUnitGUID = pUnit ? pUnit->dwUnitId : -1;
        const int nType = pUnit ? pUnit->dwUnitType : UNIT_INVALID;
        packet.nHeader = 0x26;
        packet.nUnitType = nType;
        packet.szName[0] = 0;
        packet.nMessageType = 5;
        packet.nLang = CHAT_GetLangIdFromHoverMsg(pHoverText);
        memset(packet.szMessage, 0, 256);
        CHAT_CopyHoverMsgToBuffer(pHoverText, packet.szMessage);
        D2GAME_PACKETS_SendPacket0x26_ServerMessage(pClient, &packet);
    }
    else
    {
        D2GAME_PACKETS_SendPacketSize06(pClient, 0x76, !pUnit ? 6 : pUnit->dwUnitType, !pUnit ? -1 : pUnit->dwUnitId);
    }
}

// 0x00571CD0
void __fastcall SUNITMSG_SendQueuedMessages(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    for (D2UnitPacketListStrc* pMsg = pUnit->pMsgFirst; pMsg; pMsg = pMsg->pNext)
    {
        switch (pMsg->nHeader)
        {
        case 0x99:
            SCMD_SendSkillUseOnUnit(pClient, GAME_GetUnitTypeOrInvalid(pUnit), GAME_GetUnitGUID(pUnit), pMsg->p99.nUnitType, pMsg->p99.dwUnitGUID, pMsg->p99.wSkill, pMsg->p99.nParam, pMsg->p99.nSkillLevel, 1);
            break;

        case 0x9A:
            SCMD_SendUnitActionAtPosition(pClient, GAME_GetUnitTypeOrInvalid(pUnit), GAME_GetUnitGUID(pUnit), pMsg->p9A.wX, pMsg->p9A.wY, pMsg->p9A.wSkill, pMsg->p9A.nParam, pMsg->p9A.nSkillLevel, 1);
            break;

        case 0x9E:
            D2GAME_PACKETS_SendPacket0x9E_9F_A0(pClient, pUnit, pMsg->pStat.nStatId, pMsg->pStat.dwValue);
            break;

        case 0xA1:
            D2GAME_PACKETS_SendPacket0xA0_A1_A2(pClient, pUnit, pMsg->pStat.nStatId, pMsg->pStat.dwValue, pMsg->pStat.dwFullValue);
            break;

        case 0xA4:
            D2GAME_PACKETS_SendPacket0xA4(pClient, pMsg->pA4.nMonStatsId);
            break;

        case 0xA3:
            D2GAME_PACKETS_SendPacket0xA3(pClient, pMsg->pA3.nSeed, pMsg->pA3.nSkillId, pMsg->pA3.nSkillLevel, pMsg->pA3.nUnitType, pMsg->pA3.nUnitGUID, pMsg->pA3.nTargetType, pMsg->pA3.nTargetGUID, pMsg->pA3.nX, pMsg->pA3.nY);
            break;

        case 0xAB:
            if (!sub_00451F30_TestUnitFlag(pUnit, UNITFLAG_UPGRLIFENHITCLASS))
            {
                D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
                if (pPlayer && SUNIT_AreUnitsHostile(SUNIT_GetGameFromUnit(pPlayer), pPlayer, pUnit))
                {
                    D2GAME_PACKETS_SendPacket0xAB(pClient, pMsg->pAB.nUnitType, pMsg->pAB.dwUnitId, pMsg->pAB.nUnitLife);
                }
            }
            break;

        case 0xA5:
            D2GAME_PACKETS_SendPacket0xA5(pClient, pMsg->pA5.nUnitType, pMsg->pA5.nUnitGUID, pMsg->pA5.nSkillId);
            break;

        case 0x23:
            D2GAME_PACKETS_SendPacket0x23(pClient, GAME_GetUnitTypeOrInvalid(pUnit), GAME_GetUnitGUID(pUnit), pMsg->p23.nParam, pMsg->p23.wParam, pMsg->p23.dwParam);
            break;

        default:
            break;
        }
    }
}

void __fastcall sub_M120_Emit_00571790(D2UnitStrc* pUnit, D2UnitPacketListStrc* pMsg)
{
    SUNITMSG_AppendUnitMessage(pUnit, pMsg);
}


