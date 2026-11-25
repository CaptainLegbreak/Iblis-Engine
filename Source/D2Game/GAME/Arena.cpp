#include "D2Game.h"
#include "D2Structs.h"
#include "D2GameStrc.h"
#include "D2UnitData.h"
#include "D2GameServer.h"
#include "D2GameClient.h"
#include "D2LanguageNames.h"
// build: symbol _gaszLanguageNames 0x007313D0

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_PLAYER 0

#define GAMEFLAG_ARENA_CLASS_OR_TEMPLATE_ID 0x100

struct D2ArenaStrc;

struct D2ArenaUnitStrc;

struct D2PlayerDataStrc;

void __fastcall FOG_FreeServerMemory(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

int __fastcall FOG_FreePool(void* pMemPool, void* pFree, const char* szFile, int nLine, int n0); // 0x0040B480

D2PlayerDataStrc* __stdcall UNITS_GetPlayerData(D2UnitStrc* pUnit); // 0x006221A0

void* __fastcall sub_0040B430(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430

// 0x0053F470
static int __stdcall ARENA_HasFlag(D2GameStrc* pGame, unsigned int nFlag)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 39);
    return (pArena->fFlags & nFlag) != 0;
}

int __fastcall sub_K10_EmitArenaTestFlag(D2GameStrc* pGame)
{
    return ARENA_HasFlag(pGame, 0x800);
}

// 0x0053F4B0
void __fastcall ARENA_AllocArena(D2GameStrc* pGame, int nUnused, unsigned int nFlags, unsigned char nTemplate)
{
    D2ArenaStrc* pArena = (D2ArenaStrc*)sub_0040B430(pGame->pMemoryPool, sizeof(D2ArenaStrc), ".\\GAME\\Arena.cpp", 50, 0);
    memset(pArena, 0, sizeof(D2ArenaStrc));
    pGame->pArenaCtrl = pArena;
    pArena->fFlags = nFlags & 0x3179C7;
    pArena->nTemplate = nTemplate;
}

// 0x0053F500
void __fastcall ARENA_FreeArena(D2GameStrc* pGame)
{
    if (pGame->pArenaCtrl)
    {
        FOG_FreeServerMemory(pGame->pMemoryPool, pGame->pArenaCtrl, ".\\GAME\\Arena.cpp", 0x40, 0);
        pGame->pArenaCtrl = 0;
    }
}

static int ARENA_IsPlayerUnit_Inlined(D2UnitStrc* pUnit)
{
    return pUnit && pUnit->dwUnitType == UNIT_PLAYER;
}

static int __stdcall ARENA_TestFlag_Inlined(D2GameStrc* pGame, unsigned int nFlag)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 39);
    if (pArena->fFlags & nFlag)
    {
        return 1;
    }

    return 0;
}

// 0x0053F530
void __fastcall ARENA_AllocArenaUnit(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2ArenaUnitStrc* pArenaUnit = (D2ArenaUnitStrc*)FOG_AllocPool(pGame->pMemoryPool, sizeof(D2ArenaUnitStrc), ".\\GAME\\Arena.cpp", 0x47, 0);
    memset(pArenaUnit, 0, sizeof(D2ArenaUnitStrc));

    D2PlayerDataStrc* ptPlayerInfo = UNITS_GetPlayerData(pUnit);
    D2_ASSERT(ptPlayerInfo, 0x4A);

    ptPlayerInfo->pArenaUnit = pArenaUnit;
}

// 0x0053F580
void __fastcall ARENA_FreeArenaUnit(D2GameStrc* pGame, D2UnitStrc* pPlayer)
{
    D2PlayerDataStrc* ptPlayerInfo = UNITS_GetPlayerData(pPlayer);
    D2_ASSERT(ptPlayerInfo, 0x52);

    if (!ptPlayerInfo->pArenaUnit)
    {
        return;
    }

    FOG_FreePool(pGame->pMemoryPool, ptPlayerInfo->pArenaUnit, ".\\GAME\\Arena.cpp", 0x57, 0);
    ptPlayerInfo->pArenaUnit = 0;
}

// 0x0053FA90
void __fastcall ARENA_ClearUnitUpdateScore(D2GameStrc* pGame, D2UnitStrc* pUnit)
{
    D2_ASSERT(ARENA_IsPlayerUnit_Inlined(pUnit), 0xC5);

    D2ArenaUnitStrc* pArenaUnit = UNITS_GetPlayerData(pUnit)->pArenaUnit;
    D2_ASSERT(pArenaUnit, 0xC9);

    pArenaUnit->bUpdateScore = 0;
}

// 0x0053FAE0
void __fastcall ARENA_ClearUpdateFlag(D2GameStrc* pGame)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    if (pArena)
    {
        pArena->fFlags &= ~GAMEFLAG_ARENA_UPDATE;
    }
}

// 0x0053FCA0
unsigned int __fastcall ARENA_NeedsClientUpdate(D2GameStrc* pGame)
{
    D2ArenaStrc* ptArena = pGame->pArenaCtrl;
    D2_ASSERT(ptArena, 39);
    return ptArena->bUpdateClients;
}

// 0x0053FCE0
unsigned int __fastcall ARENA_IsInArenaMode(D2GameStrc* pGame)
{
    D2ArenaStrc* ptArena = pGame->pArenaCtrl;
    D2_ASSERT(ptArena, 39);
    return ptArena->bArenaMode;
}

// 0x0053FE70
unsigned int __fastcall ARENA_ShouldTreatClassIdAsTemplateId(D2GameStrc* pGame)
{
    return ARENA_TestFlag_Inlined(pGame, GAMEFLAG_ARENA_CLASS_OR_TEMPLATE_ID);
}

// 0x0053FEA0
int __fastcall ARENA_GetTemplateType(D2GameStrc* pGame)
{
    D2ArenaStrc* ptArena = pGame->pArenaCtrl;
    D2_ASSERT(ptArena, 0x172);
    return ptArena->nTemplate;
}

#define NUM_ARENA_SCORES 7

struct D2GameStrc;

struct D2UnitStrc;

struct D2ArenaTxt;

struct D2ClientStrc;

struct D2ArenaTxt
{
    int dwScores[7];
};

void __stdcall UNITROOM_RefreshUnit(D2UnitStrc* pUnit); // 0x0064C040

D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath); // 0x00537860

unsigned int __fastcall CLIENTS_HasArenaFlag(D2ClientStrc* pClient); // 0x005388C0

void __fastcall D2GAME_PACKETS_SendPacket0x65_6FC3F5E0(D2ClientStrc* pClient, unsigned int dwPlayerId, unsigned short nCount); // 0x0053D9C0

// 0x0053F5D0
int __fastcall ARENA_GetAlternateStartTown(D2GameStrc* pGame)
{
    D2ArenaStrc* ptArena = pGame->pArenaCtrl;
    D2_ASSERT(ptArena, 99);

    return ptArena->nAlternateStartTown;
}

static D2ArenaStrc* ARENA_GetArenaCtrl_Inlined(D2GameStrc* pGame)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 0x6C);
    return pArena;
}

// 0x0053F630
static void __stdcall ARENA_UpdateScore(D2GameStrc* pGame, D2UnitStrc* pAttacker, D2UnitStrc* pDefender, int eScore)
{
    const int bAttackerIsPlayer = pAttacker && pAttacker->dwUnitType == UNIT_PLAYER;
    D2_ASSERT(bAttackerIsPlayer, 0x73);
    D2ArenaUnitStrc* pArenaUnit = UNITS_GetPlayerData(pAttacker)->pArenaUnit;
    D2_ASSERT(pArenaUnit, 0x77);
    D2ArenaTxt* pArenaTxtRecord = DATATBLS_GetArenaTxtRecord(ARENA_GetArenaCtrl_Inlined(pGame)->nType);
    D2_ASSERT(eScore < NUM_ARENA_SCORES, 0x7D);
    switch (eScore)
    {
    case 0:
    case 1:
    case 3:
    case 4:
    case 6:
        pArenaUnit->nScore += pArenaTxtRecord->dwScores[eScore];
        break;
    case 2:
    case 5:
    {
        D2ArenaUnitStrc* pSrcArenaUnit = UNITS_GetPlayerData(pDefender)->pArenaUnit;
        D2_ASSERT(pSrcArenaUnit, 0x8C);
        pArenaUnit->nScore += pSrcArenaUnit->nScore * pArenaTxtRecord->dwScores[eScore] / 100;
        break;
    }
    default:
        break;
    }
    pArenaUnit->bUpdateScore = 1;
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 0x94);
    pArena->fFlags |= GAMEFLAG_ARENA_UPDATE;
    UNITROOM_RefreshUnit(pDefender);
}

static inline void ARENA_MarkUpdated(D2GameStrc* pGame)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 0x94);
    pArena->fFlags |= GAMEFLAG_ARENA_UPDATE;
}

static int UnitType(D2UnitStrc* pUnit) { return !pUnit ? 6 : pUnit->dwUnitType; }

// 0x0053F720
void __fastcall ARENA_ProcessKillEvent(D2GameStrc* pGame,D2UnitStrc* pAttacker,D2UnitStrc* pDefender)
{
 if(!pGame->pArenaCtrl) return;
 switch(UnitType(pAttacker))
 {
 case 0:
  D2_ASSERT(UNITS_GetPlayerData(pAttacker)->pArenaUnit,0xAC);
  if(pAttacker==pDefender)
  {
   ARENA_UpdateScore(pGame,pAttacker,pAttacker,0);
  }
  else if(pDefender)
  {
   if(pDefender->dwUnitType==UNIT_PLAYER)
   {
    ARENA_UpdateScore(pGame,pAttacker,pDefender,1);
    ARENA_UpdateScore(pGame,pAttacker,pDefender,2);
    ARENA_UpdateScore(pGame,pDefender,pAttacker,4);
    ARENA_UpdateScore(pGame,pDefender,pAttacker,5);
   }
   else if(pDefender->dwUnitType==UNIT_MONSTER)
   {
    ARENA_UpdateScore(pGame,pAttacker,pDefender,3);
   }
  }
  break;
 case 1:
  if(pDefender && UnitType(pDefender)==0)
   ARENA_UpdateScore(pGame,pDefender,pAttacker,6);
  break;
 }
}

// 0x0053FB00
static int ARENA_GetUnitUpdateScore(D2UnitStrc* pPlayer)
{
    D2ArenaUnitStrc* pArenaUnit = UNITS_GetPlayerData(pPlayer)->pArenaUnit;
    D2_ASSERT(pArenaUnit, 219);
    return pArenaUnit->bUpdateScore;
}

// 0x0053FB30
static void __stdcall ARENA_SendArenaScore(D2ClientStrc* pClient, D2UnitStrc* pPlayer)
{
    D2ArenaUnitStrc* pArenaUnit = UNITS_GetPlayerData(pPlayer)->pArenaUnit;
    D2_ASSERT(pArenaUnit, 229);
    D2GAME_PACKETS_SendPacket0x65_6FC3F5E0(pClient, !pPlayer ? -1 : pPlayer->dwUnitId, pArenaUnit->nScore);
}

// 0x0053FB90
static void __stdcall ARENA_SendArenaScores(D2GameStrc* pGame, int bAll, D2ClientStrc* pClient)
{
    D2UnitStrc* pLocalPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    for (D2ClientStrc* i = pGame->pClientList; i; i = i->pNext)
    {
        D2UnitStrc* pOtherPlayer = CLIENTS_GetPlayerFromClient(i, 0);
        if (i->dwClientState == CLIENTSTATE_INGAME && pOtherPlayer)
        {
            if (bAll || (pOtherPlayer != pLocalPlayer && ARENA_GetUnitUpdateScore(pOtherPlayer)))
            {
                ARENA_SendArenaScore(pClient, pOtherPlayer);
            }
        }
    }
}

// 0x0053FC20
void __fastcall ARENA_SynchronizeWithClients(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    if (!pArena || !(pArena->fFlags & GAMEFLAG_ARENA_UPDATE))
    {
        return;
    }
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
    if (pPlayer && ARENA_GetUnitUpdateScore(pPlayer))
    {
        ARENA_SendArenaScore(pClient, pPlayer);
    }
    if (CLIENTS_HasArenaFlag(pClient))
    {
        ARENA_SendArenaScores(pGame, 0, pClient);
    }
}

// 0x0053FC70
void __fastcall ARENA_SendScoresToClient(D2GameStrc* pGame, D2ClientStrc* pClient)
{
    ARENA_SendArenaScores(pGame, 1, pClient);
    D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 1);
    if (pClient->dwClientState != CLIENTSTATE_INGAME && pPlayer)
    {
        ARENA_SendArenaScore(pClient, pPlayer);
    }
}

// 0x0053FD40
unsigned int __fastcall ARENA_GetFlags(D2GameStrc* pGame)
{
    D2ArenaStrc* ptArena = pGame->pArenaCtrl;
    D2_ASSERT(ptArena, 313);

    return ptArena->fFlags;
}

// 0x0053FD70
unsigned int __fastcall ARENA_TestFlags(D2GameStrc* pGame, unsigned int nMask)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 323);

    return pArena->fFlags & nMask;
}

// 0x0053FDA0
void __fastcall ARENA_SetFlags(D2GameStrc* pGame, unsigned int nFlags, int bSet)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 333);

    if (bSet)
    {
        pArena->fFlags |= nFlags;
    }
    else
    {
        pArena->fFlags &= ~nFlags;
    }
}

// 0x0053FDF0
int __cdecl ARENA_Return0()
{
    return 0;
}

// 0x0053F600
static int ARENA_GetArenaType(D2GameStrc* pGame)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 0x6C);
    return pArena->nType;
}

int __fastcall sub_M116_Emit_0053F600(D2GameStrc* pGame)
{
    return ARENA_GetArenaType(pGame) == 3;
}

// 0x0053FE00
unsigned int __fastcall ARENA_TestArenaFlag40(D2GameStrc* pGame)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 39);
    return pArena->bFlag40;
}

// 0x0053FE40
unsigned int __fastcall ARENA_TestArenaFlag80(D2GameStrc* pGame)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 39);
    return pArena->bFlag80;
}

// 0x0053FED0
unsigned int __fastcall ARENA_TestArenaFlag200(D2GameStrc* pGame)
{
    D2ArenaStrc* pArena = pGame->pArenaCtrl;
    D2_ASSERT(pArena, 39);
    return (pArena->fFlags & 0x200) != 0;
}

#define GAMEFLAG_ARENA_ACTIVE 0x10000

// 0x0053FD10
int __fastcall ARENA_IsActive(D2GameStrc* pGame)
{
    return ARENA_TestFlag_Inlined(pGame, GAMEFLAG_ARENA_ACTIVE);
}

