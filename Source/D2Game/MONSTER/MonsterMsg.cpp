#include "D2StatIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2LanguageNames.h"
// build: symbol _gaszLanguageNames 0x00738CC8

#define D2_ASSERT(expr,line) if(!(expr)) {FOG_DisplayHalt(&gszEmptyAssertText,sub_00408090(),line);exit(-1);}
struct D2MonsterModeInfo;

void __fastcall SCMD_SendUnitActionAtPosition(D2ClientStrc* pClient, unsigned char a2, int a3, unsigned short a4, unsigned short a5, int a6, unsigned short a7, unsigned char a8, int a9); // 0x0053D4D0
void __fastcall SCMD_SendSkillUseOnUnit(D2ClientStrc* pClient, unsigned char a2, int a3, unsigned char nUnitType, int nUnitGUID, unsigned short a6, unsigned short a7, unsigned char a8, int a9); // 0x0053D530
int __fastcall CLIENTS_IsInUnitsRoom(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x005387F0
D2UnitStrc* __stdcall SUNIT_GetTargetUnit(D2GameStrc* pGame, D2UnitStrc* pUnit); // 0x00553540
D2SkillStrc* __stdcall UNITS_GetUsedSkill(D2UnitStrc* pUnit); // 0x00620250
int __stdcall SKILLS_GetSkillIdFromSkill(D2SkillStrc* pSkill, const char* szFile, int nLine); // 0x00643CE0
int __stdcall SKILLS_GetSkillLevel(D2UnitStrc* pUnit, D2SkillStrc* pSkill, int bBonus); // 0x006442A0
int __stdcall D2COMMON_10175_PathGetFirstPointX(D2DynamicPathStrc* pDynamicPath); // 0x00648A00
int __stdcall D2COMMON_10176_PathGetFirstPointY(D2DynamicPathStrc* pDynamicPath); // 0x00648A10
static void __stdcall MONSTERMSG_SendUsedSkill(D2UnitStrc* pMonster, D2UnitStrc* pTarget, D2ClientStrc* pClient); // 0x00597D70

struct D2MonsterModeInfo { int bTarget,bTargetCoords,bSimple,bIncludeCoords,nCoordMode,nTargetMode; };

extern D2MonsterModeInfo gMonsterModeInfo[]; // 0x006E1D90
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char*,const char*,int); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int); // 0x00681E09
int __stdcall PATH_GetType(D2DynamicPathStrc*); // 0x00648E30
int __stdcall PATH_GetLastPointX(D2DynamicPathStrc*); // 0x00648A40
int __stdcall PATH_GetLastPointY(D2DynamicPathStrc*); // 0x00648A60
int __stdcall PATH_GetXPosition(D2DynamicPathStrc*); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc*); // 0x00648900
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc*); // 0x006487F0
unsigned char __stdcall D2COMMON_10191_PATH_GetDistance(D2DynamicPathStrc*); // 0x00648E60
unsigned char __stdcall PATH_GetStepNum(D2DynamicPathStrc*); // 0x006490A0
unsigned char __fastcall MONSTERMODE_GetHpPercent128(D2UnitStrc*); // 0x005A5650
int __fastcall MONSTERUNIQUE_CheckMonTypeFlag(D2UnitStrc*,int); // 0x005A0180
int __fastcall CLIENTS_GetUnitX(D2UnitStrc*); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc*); // 0x0045AE20
void __stdcall STATLIST_SetUnitStat(D2UnitStrc*,int,int,int); // 0x00627260
void __fastcall D2GAME_PACKETS_SendPacket0x6D_6FC3D080(D2ClientStrc*,unsigned int,unsigned short,unsigned short,unsigned char); // 0x0053BB70
void __fastcall D2GAME_PACKETS_SendPacket0x68(D2ClientStrc*,unsigned char,int,char,char,int,char); // 0x0053B5F0
void __fastcall D2GAME_PACKETS_SendPacket0x67(D2ClientStrc*,unsigned char,int,char,short,short,char); // 0x0053B710
void __fastcall D2GAME_PACKETS_SendPacket0x68Ex(D2ClientStrc*,unsigned char,int,char,char,int,char,char,char); // 0x0053B7F0
void __fastcall D2GAME_PACKETS_SendPacket0x67Ex(D2ClientStrc*,unsigned char,int,char,short,short,char,char,char); // 0x0053B910
void __fastcall D2GAME_PACKETS_SendPacket0x6A_6FC3CEE0(D2ClientStrc*,char,int,char,char,int,char); // 0x0053B9F0
void __fastcall D2GAME_PACKETS_SendPacket0x69_6FC3CF30(D2ClientStrc*,char,int,char,short,short,char,char); // 0x0053BA40
void __fastcall D2GAME_PACKETS_SendPacket0x6C_6FC3CF90(D2ClientStrc*,char,int,char,char,int,char,short,short); // 0x0053BAA0
void __fastcall D2GAME_PACKETS_SendPacket0x6B_6FC3D000(D2ClientStrc*,char,int,char,short,short,char,char,short,short); // 0x0053BB00

static inline int sub_F05_MsgGetUnitId(D2UnitStrc* pUnit)
{
    return !pUnit ? -1 : pUnit->dwUnitId;
}

static void __stdcall INVMODE_SendLifeUpdate(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00597CF0
unsigned short __fastcall MONSTERUNIQUE_GetNameSeed(D2UnitStrc* pUnit); // 0x005A0140
unsigned char* __fastcall MONSTERUNIQUE_GetUMods(D2UnitStrc* pUnit); // 0x005A0120
void __fastcall SCMD_SendUniqueMonsterInfo(D2ClientStrc* pClient, int a2, unsigned char a3, unsigned short a4, unsigned short a5, unsigned short a6, unsigned short a7); // 0x0053D880

// 0x00597C70
static void __stdcall INVMODE_SendSummonerInfo(D2ClientStrc* pClient, D2UnitStrc* pUnit)
{
    if (!MONSTER_CheckSummonerFlag(pUnit, 1))
    {
        return;
    }

    const unsigned char* pUMods = MONSTERUNIQUE_GetUMods(pUnit);
    if (!pUMods)
    {
        return;
    }

    const unsigned short nNameSeed = MONSTERUNIQUE_GetNameSeed(pUnit);
    const unsigned short nUMods = pUMods[0] | (pUMods[1] << 8);
    const unsigned short nUMod2 = pUMods[2];
    const unsigned short nChampion = MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 4);
    SCMD_SendUniqueMonsterInfo(pClient, sub_F05_MsgGetUnitId(pUnit), 1, nNameSeed, nUMods, nUMod2, nChampion);
}

void __fastcall D2GAME_PACKETS_SendPacket0x0C_6FC3C8A0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, unsigned char a5, unsigned char nHitClass, unsigned char nLifePct); // 0x0053B430

// 0x00597CF0
static void __stdcall INVMODE_SendLifeUpdate(D2UnitStrc* pUnit, D2ClientStrc* pClient)
{
    const unsigned char nHitClass = pUnit->dwLastHitClass;
    unsigned char nHpPct = MONSTERMODE_GetHpPercent128(pUnit);
    STATLIST_SetUnitStat(pUnit, STAT_LAST_SENT_HP_PCT, nHpPct, 0);
    if (nHpPct > 1)
    {
        --nHpPct;
    }

    if (MONSTERUNIQUE_CheckMonTypeFlag(pUnit, 0x100))
    {
        nHpPct |= 0x80;
    }

    const int nUnitGUID = (pUnit ? pUnit->dwUnitId : -1);
    D2ClientStrc* const pTarget = pClient;
    D2GAME_PACKETS_SendPacket0x0C_6FC3C8A0(pTarget, 0xC, 1, nUnitGUID, 19, nHitClass, nHpPct);
}

// 0x00597D70
static void __stdcall MONSTERMSG_SendUsedSkill(D2UnitStrc* pMonster, D2UnitStrc* pTarget, D2ClientStrc* pClient)
{
    D2SkillStrc* pSkill = UNITS_GetUsedSkill(pMonster);
    if (!pSkill)
    {
        return;
    }

    const int nSkillId = SKILLS_GetSkillIdFromSkill(pSkill, ".\\MONSTER\\MonsterMsg.cpp", 150);
    const char nSkillLevel = SKILLS_GetSkillLevel(pMonster, pSkill, 1);
    const int nUnitGUID = !pMonster ? -1 : pMonster->dwUnitId;

    if (pTarget && CLIENTS_IsInUnitsRoom(pTarget, pClient))
    {
        SCMD_SendSkillUseOnUnit(pClient, 1, nUnitGUID, !pTarget ? 6 : pTarget->dwUnitType, !pTarget ? -1 : pTarget->dwUnitId, nSkillId, 0, nSkillLevel, 0);
    }
    else
    {
        SCMD_SendUnitActionAtPosition(pClient, 1, nUnitGUID, D2COMMON_10175_PathGetFirstPointX(pMonster->pDynamicPath), D2COMMON_10176_PathGetFirstPointY(pMonster->pDynamicPath), (unsigned short)nSkillId, 0, nSkillLevel, 0);
    }
}

static inline int GetUnitGUID(D2UnitStrc* pUnit) { return !pUnit ? -1 : pUnit->dwUnitId; }

// 0x00597E20
void __fastcall MONSTERMSG_SendMonsterModeUpdate(D2GameStrc* pGame,D2UnitStrc* pUnit,D2ClientStrc* hClient)
{
 unsigned char nDirection=0,nHitClass=0,nExtra=0,nStep=0;
 D2_ASSERT(pUnit,0xD4);
 D2_ASSERT(hClient,0xD5);
 int nMode=pUnit->dwAnimMode;
 D2MonsterModeInfo* pInfo=&gMonsterModeInfo[nMode];
 D2UnitStrc* pTarget=SUNIT_GetTargetUnit(pGame,pUnit);
 if((pTarget && !CLIENTS_IsInUnitsRoom(pTarget,hClient)) || !pInfo->bTarget) pTarget=0;
 if(nMode==14 || UNITS_GetUsedSkill(pUnit)) { MONSTERMSG_SendUsedSkill(pUnit,pTarget,hClient); return; }
 D2DynamicPathStrc* hPath=pUnit->pDynamicPath;
 D2_ASSERT(hPath,0xE6);
 int nX,nY,nSendMode,nHeader;
 if(pTarget) {
  nSendMode=pInfo->nTargetMode;
  nX=pTarget->dwUnitType;nY=pTarget->dwUnitId;
  nHeader=0x68;
  switch(nMode) { case 2:case 15: {
   int nPathType=PATH_GetType(hPath);
   switch(nPathType) { case 5:case 6: {
    nSendMode=pInfo->nCoordMode;nHeader=0x67;
    nX=PATH_GetLastPointX(hPath);nY=PATH_GetLastPointY(hPath);
   } }
  } }
 } else {
  nHeader=0x67;nSendMode=pInfo->nCoordMode;
  if(pInfo->bTargetCoords) {nX=PATH_GetLastPointX(hPath);nY=PATH_GetLastPointY(hPath);}
  else {nX=PATH_GetXPosition(hPath);nY=PATH_GetYPosition(hPath);}
 }
 switch(nMode) {
 case 6: if(!pTarget) {nX=0;nY=-1;} break;
 case 0: nDirection=PATH_GetDirection(hPath);nHitClass=pUnit->dwLastHitClass;break;
 case 12: nDirection=PATH_GetDirection(hPath);break;
 case 13: nDirection=D2COMMON_10191_PATH_GetDistance(hPath);nHitClass=MONSTERMODE_GetHpPercent128(pUnit);nExtra=pUnit->dwLastHitClass;break;
 case 3:
  nDirection=MONSTERMODE_GetHpPercent128(pUnit);
  if(nDirection>1) --nDirection;
  if(MONSTERUNIQUE_CheckMonTypeFlag(pUnit,0x100)) nDirection|=0x80;
  nHitClass=pUnit->dwLastHitClass;break;
 default: nStep=PATH_GetStepNum(hPath);break;
 }
 if(nMode==1) {
  nDirection=MONSTERMODE_GetHpPercent128(pUnit);
  int nGUID=pUnit->dwUnitId;
  D2GAME_PACKETS_SendPacket0x6D_6FC3D080(hClient,nGUID,CLIENTS_GetUnitX(pUnit),CLIENTS_GetUnitY(pUnit),nDirection);
  STATLIST_SetUnitStat(pUnit,STAT_PIERCE_IDX,sub_006253B0_GetBaseStat(pUnit,0x148,0)+1,0);
  return;
 }
 if(nMode==13) {
  int nGUID=pUnit->dwUnitId;
  if(nHeader==0x68) D2GAME_PACKETS_SendPacket0x68Ex(hClient,0x68,nGUID,nSendMode,nX,nY,nDirection,nHitClass,nExtra);
  else D2GAME_PACKETS_SendPacket0x67Ex(hClient,(unsigned char)nHeader,nGUID,nSendMode,nX,nY,nDirection,nHitClass,nExtra); // 0x0053B910
  return;
 }
 if(!pInfo->bSimple) {
 if(pInfo->bIncludeCoords) {
  if(nHeader==0x68) {
   int nGUID=pUnit->dwUnitId;
   D2GAME_PACKETS_SendPacket0x6C_6FC3CF90(hClient,0x6C,nGUID,nSendMode,nX,nY,nDirection,CLIENTS_GetUnitX(pUnit),CLIENTS_GetUnitY(pUnit));
  } else {
   int nGUID=pUnit->dwUnitId;
   D2GAME_PACKETS_SendPacket0x6B_6FC3D000(hClient,0x6B,nGUID,nSendMode,nX,nY,nDirection,nHitClass,CLIENTS_GetUnitX(pUnit),CLIENTS_GetUnitY(pUnit));
  }
  return;
 }
 int nGUID=pUnit->dwUnitId;
 if(nHeader==0x68) D2GAME_PACKETS_SendPacket0x6A_6FC3CEE0(hClient,0x6A,nGUID,nSendMode,nX,nY,nDirection);
 else D2GAME_PACKETS_SendPacket0x69_6FC3CF30(hClient,0x69,nGUID,nSendMode,nX,nY,nDirection,nHitClass);
 return;
 }
 if(pInfo->bSimple) {
  int nGUID=pUnit->dwUnitId;
  if(nHeader==0x68) D2GAME_PACKETS_SendPacket0x68(hClient,0x68,nGUID,nSendMode,nX,nY,nStep);
  else D2GAME_PACKETS_SendPacket0x67(hClient,(unsigned char)nHeader,nGUID,nSendMode,nX,nY,nStep); // 0x0053B710
  return;
 }

}

void __fastcall D2GAME_PACKETS_SendPacket0x0C_6FC3C8A0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, unsigned char a5, unsigned char nHitClass, unsigned char nLifePct); // 0x0053B430

void __fastcall D2GAME_PACKETS_SendPacket0x15_6FC3D0D0(D2ClientStrc* pClient, unsigned char nHeader, unsigned char nUnitType, int nUnitGUID, unsigned short nPosX, unsigned short nPosY, unsigned char a7); // 0x0053BC10

void __fastcall SCMD_SendUniqueMonsterInfo(D2ClientStrc* pClient, int a2, unsigned char a3, unsigned short a4, unsigned short a5, unsigned short a6, unsigned short a7); // 0x0053D880

void __fastcall SUNITPROXY_UpdateGambleInventory(D2GameStrc* pGame, D2UnitStrc* pUnit, D2UnitStrc* pPlayer, D2ClientStrc* pClient); // 0x00537680

D2UnitStrc* __stdcall CLIENTS_GetPlayerFromClient(D2ClientStrc* pClient, int bIgnoreDeath); // 0x00537860

void __fastcall SUNIT_SynchronizeRoomClients(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ActiveRoomStrc* pRoom); // 0x00554670

void __fastcall D2GAME_STATES_SendStates_6FCC5F00(D2UnitStrc* pUnit, D2ClientStrc* pClient, int bPlayer); // 0x00571580

void __fastcall SUNITMSG_SendOverlay(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x005715A0

void __fastcall SUNITMSG_SendHoverText(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571620

void __fastcall D2GAME_UpdateUnit_6FCC6080(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571740

void __fastcall SUNITMSG_SendQueuedMessages(D2UnitStrc* pUnit, D2ClientStrc* pClient); // 0x00571CD0

D2UnitStrc* __fastcall AIGENERAL_GetMinionOwner(D2UnitStrc* pUnit); // 0x0058F0D0

void __fastcall D2GAME_INVMODE_First_6FC40FB0(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, D2InventoryStrc* pInventoryArg); // 0x00597890

unsigned char* __fastcall MONSTERUNIQUE_GetUMods(D2UnitStrc* pUnit); // 0x005A0120

unsigned short __fastcall MONSTERUNIQUE_GetNameSeed(D2UnitStrc* pUnit); // 0x005A0140

int __stdcall MONSTERS_GetHirelingTypeId(D2UnitStrc* pUnit); // 0x0063EE90

static inline int sub_F05_MsgGetUnitX(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetXPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static inline int sub_F05_MsgGetUnitY(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;

    default:
        if (pUnit->pDynamicPath)
        {
            return PATH_GetYPosition(pUnit->pDynamicPath);
        }
        return 0;
    }
}

static inline int sub_F05_UnitFlagBit(D2UnitStrc* pUnit, int nBit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlags >> nBit) & 1;
}

static inline int sub_F05_UnitFlagExBit(D2UnitStrc* pUnit, int nBit)
{
    if (!pUnit)
    {
        return 0;
    }

    return (pUnit->dwFlagEx >> nBit) & 1;
}



// 0x00598220
void __fastcall MONSTERMSG_SendMonsterUpdates(D2GameStrc* pGame, D2UnitStrc* pUnit, D2ClientStrc* pClient, int bUnitInitialized)
{
    if (pUnit)
    {
        if (sub_F05_UnitFlagExBit(pUnit, 16))
        {
            const int nY = sub_F05_MsgGetUnitY(pUnit);
            const int nX = sub_F05_MsgGetUnitX(pUnit);
            const int nUnitGUID = (pUnit ? pUnit->dwUnitId : -1);
            const int nUnitType = (pUnit ? pUnit->dwUnitType : UNIT_INVALID);
            D2GAME_PACKETS_SendPacket0x15_6FC3D0D0(pClient, 0x15, nUnitType, nUnitGUID, nX, nY, 1);
            SUNIT_SynchronizeRoomClients(pGame, pUnit, 0);
        }

        if (sub_F05_UnitFlagBit(pUnit, 0))
        {
            MONSTERMSG_SendMonsterModeUpdate(pGame, pUnit, pClient);
        }

        pUnit->dwFlags &= ~0x80000;
    }

    SUNITMSG_SendQueuedMessages(pUnit, pClient);

    if (pUnit)
    {
        if (sub_F05_UnitFlagBit(pUnit, 8))
        {
            SUNITMSG_SendHoverText(pUnit, pClient);
        }

        if (sub_F05_UnitFlagExBit(pUnit, 0))
        {
            D2UnitStrc* pPlayer = CLIENTS_GetPlayerFromClient(pClient, 0);
            if (pPlayer && MONSTERAI_IsTrading(pUnit, pPlayer))
            {
                SUNITPROXY_UpdateGambleInventory(pGame, pUnit, pPlayer, pClient);
            }
            else if (MONSTERS_GetHirelingTypeId(pUnit) && AIGENERAL_GetMinionOwner(pUnit) == pPlayer)
            {
                D2GAME_INVMODE_First_6FC40FB0(pGame, pUnit, pClient, 0);
            }
        }

        if (sub_F05_UnitFlagBit(pUnit, 10))
        {
            D2GAME_UpdateUnit_6FCC6080(pUnit, pClient);
        }

        if (sub_F05_UnitFlagBit(pUnit, 15))
        {
            INVMODE_SendLifeUpdate(pUnit, pClient);
        }
    }

    if (!bUnitInitialized && STATES_IsAnyGfxStateFlagSet(pUnit))
    {
        D2GAME_STATES_SendStates_6FCC5F00(pUnit, pClient, 0);
    }

    if (D2COMMON_10530_D2CheckStatlistFlagDMGRed(pUnit))
    {
        SUNITMSG_SendOverlay(pUnit, pClient);
    }

    if (pUnit && sub_F05_UnitFlagBit(pUnit, 11))
    {
        INVMODE_SendSummonerInfo(pClient, pUnit);
    }
}

#include "gen/data/Source/D2Game/MONSTER/MonsterMsg.inc"
struct D2ClientStrc;
