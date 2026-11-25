#include "D2StateIds.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2Structs.h"
#include "D2LevelTxt.h"
#include "D2ClientGame.h"
#include "D2TxtItems.h"
#include "D2Constants.h"
#include "D2Path.h"
#include "D2Drlg.h"
#include "D2DrlgMaps.h"
#include "D2ClientUi.h"
#include "D2SoundEnvironTxt.h"

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

#define UNIT_INVALID 6

struct D2UnitSfxNodeStrc;

struct D2UnitStrc;

struct D2MonSoundsTxt;

struct D2UnitSndPlayerStrc;

struct D2UnitSndObjectStrc;

struct D2SuperUniquesTxt;

struct D2MonStatsTxt;

struct D2DataTablesStrc;

struct D2DirRateStrc;

struct D2SkillsTxt;

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

extern D2DataTablesStrc* sgptDataTables; // 0x00744304

extern D2UnitSndPlayerStrc* gapUnitSndPlayers[]; // 0x0072A008

extern D2UnitSndObjectStrc* gapUnitSndObjects[]; // 0x007295F8

extern D2UnitSndObjectStrc gtUnitSndObject; // 0x00729328

extern D2UnitSndObjectStrc gaUnitSndObjects[]; // 0x00727F48

extern D2DirRateStrc gaDirRate[]; // 0x00727ED8

int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit); // 0x00621190

void __stdcall D2COMMON_11013_ConvertMode(D2UnitStrc* pUnit, int* pType, int* pClass, int* pMode, const char* szFile, int nLine); // 0x00645270

D2MonSoundsTxt* __stdcall DATATBLS_GetMonSoundsTxtRecordFromSoundId(int nSoundId); // 0x00656F90

D2MonSoundsTxt* __stdcall DATATBLS_GetMonSoundsTxtRecordFromMonsterId(int nMonsterId); // 0x00656FC0

D2SuperUniquesTxt* __stdcall DATATBLS_GetSuperUniquesTxtRecord(int nSuperUniqueId); // 0x006556E0

D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80

short __fastcall sub_004AC7C0_GetSuperUniqueId(D2UnitStrc* pUnit); // 0x004AC7C0

int __fastcall MONSTER_IsUniqueMonster(D2UnitStrc* pUnit); // 0x004AE360

int __fastcall MONSTER_IsMinionMonster(D2UnitStrc* pUnit); // 0x004AE380

int __fastcall MONSTER_IsSuperUniqueMonster(D2UnitStrc* pUnit); // 0x004AE3A0

int __fastcall MONSTERREGION_CheckMonStats2Flag(int nMonsterId, int nFlag); // 0x004638A0

int __fastcall CUNIT_GetMonsterBaseId(D2UnitStrc* pUnit); // 0x00463860

D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit(); // 0x00463DD0

int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit); // 0x00464820

int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4); // 0x004B9A00

void __fastcall SOUNDINST_SetValue(int nKey, int nValue); // 0x004B9B50

int __fastcall SOUNDINST_HasActiveHint(void* pEntry); // 0x004B9BE0

int __fastcall SOUNDINST_GetSoundIdByHandle(int nKey); // 0x004B9CA0

int __fastcall SOUNDINST_IsNearPlayer(D2UnitStrc* pUnit); // 0x004B9E10

int __fastcall SOUNDINST_HasUnitSound(D2UnitStrc* pUnit); // 0x004B9E90

void __fastcall SOUNDINST_ArmHint(void* pEntry, int nGroup, int nOffset, unsigned int nCount); // 0x004B9EF0

void __fastcall sub_004BA790_ReleaseUnitSfx(void* pUnitSfx, D2UnitStrc* pUnit, int bForce); // 0x004BA790

int __fastcall SOUNDHDR_GetGroupStart(int nId); // 0x00481890

void __fastcall SOUNDHDR_AddVariantRefs(int nIndex, int nDelta); // 0x004822B0

int __cdecl sub_0044DB00(); // 0x0044DB00

int __fastcall sub_004E40A0(int nRange); // 0x004E40A0

extern "C" int __fastcall SKILLDESC_RandomInRange(int nMin, int nMax); // 0x004E4100

int __fastcall sub_004E4180(int nFrame, int nOffset, int nStepLength); // 0x004E4180

int __fastcall UNITSND_GetModeSound(D2UnitStrc* pUnit, int nMode); // 0x004CA810

int __fastcall UNITSND_GetUnitFloorMaterial(D2UnitStrc* pUnit); // 0x004CADB0

unsigned int __fastcall UNITSND_GetAnimRate(D2UnitStrc* pUnit, unsigned int nDirection); // 0x004CA500

void* __fastcall UNITSND_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId); // 0x004CA900

void __fastcall UNITSND_PurgeUnitHints(D2UnitStrc* pUnit); // 0x004CAA10

int __fastcall UNITS_GetHitClass(D2UnitStrc* pUnit); // 0x00623C20

int __stdcall DRLG_UnitEdgeDistance(D2UnitStrc* pUnit, D2UnitStrc* pOther); // 0x006416D0

D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0

int __stdcall DUNGEON_IsRoomInTown(D2ActiveRoomStrc* pRoom); // 0x0061AB00

int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState); // 0x00639DF0

D2UnitStrc* __fastcall CUNIT_FindClientUnit(unsigned int nUnitId, int nUnitType); // 0x00463990

D2StatListStrc* __stdcall STATLIST_GetStatListFromUnitAndState(D2UnitStrc* pUnit, int nState); // 0x006256B0

int __stdcall STATLIST_GetStatValue(D2StatListStrc* pStatList, int nStatId, unsigned short nLayer); // 0x00625D00

D2SkillStrc* __fastcall SKILLS_GetHighestLevelSkillFromUnitAndId(D2UnitStrc* pUnit, int nSkillId); // 0x006439F0

D2SkillsTxt* __fastcall sub_0045C4B0_GetSkillsTxtRecord(int nSkillId); // 0x0045C4B0

void __fastcall TEXT_SetSpeechHoverText(D2UnitStrc* pUnit, int nStringId); // 0x004A0200

void __fastcall UNITSND_PlayPlayerSpeech(D2UnitStrc* pUnit, unsigned short nStringId); // 0x004CB9C0

int __fastcall sub_004E0590_PickNpcSound(D2UnitStrc* pUnit, int nType); // 0x004E0590

void __fastcall sub_004DCE10_UpdateTimedHint(int nDelay, int nArg); // 0x004DCE10

void __stdcall UNITSND_ReleaseMonsterSfx(D2UnitStrc* pUnit); // 0x004CB2C0

__declspec(noinline) void __fastcall UNITSND_AddUnitSoundRefs(D2UnitStrc* pUnit, int nDelta);

unsigned int gnNeutralTick; // 0x007C88B8

unsigned int gnSfxTick; // 0x007C88BC

unsigned int gnNeutralDelay; // 0x007C88C0

int gaLevelVisited[1024]; // 0x007C78B8
int gnLastLevelId; // 0x007C88CC

void __fastcall UNITSND_PlayAttackSound(D2UnitStrc* pUnit, int nMode, int bDelay);                     // 0x004CB6A0

static int UNITSND_GetUnitSndClassId(D2UnitStrc* pUnit);                                               // 0x004CA2C0

static int UNITSND_GetUnitSndType(D2UnitStrc* pUnit);                                                  // 0x004CA320

static int UNITSND_GetUnitSndMode(D2UnitStrc* pUnit);                                                  // 0x004CA380

static D2MonSoundsTxt* UNITSND_GetMonSoundsRecord(D2UnitStrc* pUnit);                                  // 0x004CA410

static void UNITSND_PlayHitClassSound(D2UnitStrc* pUnit);                                              // 0x004CB860

static void UNITSND_PlaySkillSound(D2UnitStrc* pUnit, int nMode);                                      // 0x004CB890

static void __stdcall UNITSND_PlayHitSound(D2UnitStrc* pUnit, int nMode);                              // 0x004CC410

void __fastcall UNITSND_UpdateUnitSound(D2UnitStrc* pUnit, int nMode, int bModeGiven); // 0x004CC5B0

static D2UnitSndPlayerStrc* UNITSND_GetPlayerSoundRecord(unsigned int nClass); // 0x004CA3E0

static unsigned int UNITSND_ReadSoundTick(D2UnitStrc* pUnit); // 0x004CAB30

static void __stdcall UNITSND_WriteSoundTick(D2UnitStrc* pUnit, unsigned int nTicks); // 0x004CAB60

static unsigned int UNITSND_ReadAsyncSoundTick(D2UnitStrc* pUnit); // 0x004CAB90

static void __stdcall UNITSND_WriteAsyncSoundTick(D2UnitStrc* pUnit, unsigned int nTicks); // 0x004CABC0

static void __stdcall UNITSND_WriteStepSoundTick(D2UnitStrc* pUnit, unsigned int nTicks); // 0x004CAC30

void __fastcall UNITSND_ReleaseSkillSfx(D2UnitStrc* pUnit); // 0x004CB190

void __stdcall UNITSND_ReleaseNeutralSfx(D2UnitStrc* pUnit, int bArm); // 0x004CB220

static int __stdcall UNITSND_GetObjectStopSound(D2UnitStrc* pUnit, int nMode, int nOldMode); // 0x004CB380

static int UNITSND_GetObjectModeSound(D2UnitStrc* pUnit, int nMode); // 0x004CB3E0

void __fastcall UNITSND_UpdateModeSound(D2UnitStrc* pUnit); // 0x004CB460

static void UNITSND_PlayFleeSound(D2UnitStrc* pUnit); // 0x004CB950

void __fastcall UNITSND_PlayInitSound(D2UnitStrc* pUnit); // 0x004CC380

struct D2StaticPathStrc;

struct D2DrlgCoordsStrc;

struct D2TileLibraryEntryStrc;

struct D2SoundEnvironTxtStrc;

void __stdcall DUNGEON_GetRoomCoordinates(D2ActiveRoomStrc* pRoom, D2DrlgCoordsStrc* pCoords); // 0x00619730

void __stdcall DUNGEON_GetAdjacentRoomsListFromRoom(D2ActiveRoomStrc* pRoom, D2ActiveRoomStrc*** pppRoomList, int* pnNumRooms); // 0x00619790

D2SoundEnvironTxtStrc* __fastcall SOUNDHDR_GetSoundEnvironTxtRecord(int nEnvironId); // 0x00481920

int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0

int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

void __fastcall UNITSND_GetHitSounds(D2UnitStrc* pUnit, int nHitClass, int bParam, int* pSound1, int* pSound2); // 0x004CA560

void __fastcall UNITSND_UpdateFootsteps(D2UnitStrc* pUnit); // 0x004CAF60

extern struct D2TimedHintEntryStrc;

extern struct D2TimedHintNodeStrc;

void __fastcall D2SOUNDUTIL_ListAddHead(D2TimedHintNodeStrc** ppList, D2TimedHintEntryStrc* pEntry); // 0x00516950

int __cdecl CUNIT_IsPlayerDeadOrMissing(); // 0x00463DF0

void __fastcall ITEM_ShowTimedHint(int nStringId, int nDelayA, int nDelayC, unsigned int nIndex, int nArgE, int nDelayF, int nArgG); // 0x004DCD40

unsigned int gnLastRequestTick;        // 0x007C88C4

int gnLastRequestSound;        // 0x007C88C8

static inline D2UnitSndPlayerStrc* UNITSND_GetPlayerSoundRecord(unsigned int nClass);

struct D2TimedHintNodeStrc;

struct D2LevelSpeechStrc
{
    int nLevels[10];
    int nCondition;
    unsigned short f_2C;
};

extern D2LevelSpeechStrc* gapLevelSpeeches[15]; // 0x0072A2C4

int __fastcall TEXT_TestQuestCondition(int nCondition); // 0x004A4180

int __cdecl SOUNDINST_IsSpeechPlaying(); // 0x004B9C20

int __cdecl sub_004DF880(); // 0x004DF880

int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom); // 0x0061A1B0

unsigned char __fastcall SOUNDHDR_GetGroupSize(int nId); // 0x004818C0

struct D2ActiveRoomStrc;
struct D2StatListStrc;

struct D2SkillStrc;

static inline void sub_004CA560_SetHitSound1(int nHitClass, int* pSound1)
{
    switch (nHitClass & 0xF)
    {
    case 1: *pSound1 = 0x141; break;
    case 8: case 9: *pSound1 = 0x149; break;
    case 6: case 7: *pSound1 = 0x14F; break;
    case 2: case 3: case 4: case 5: *pSound1 = 0x155; break;
    case 10: case 11: *pSound1 = 0x15B; break;
    case 12: *pSound1 = 0x145; break;
    }
}

static inline void sub_004CA560_SetHitSound2(int nHitClass, int* pSound1, int* pSound2, int nType, int bParam)
{
    switch (nHitClass & 0xF0)
    {
    case 0x20:
        *pSound2 = *pSound1 ? 0x164 : 0x161;
        break;
    case 0x30:
        if (!*pSound1)
        {
            *pSound2 = 0x167;
            break;
        }
        if ((nType == 0 || nType == 1) && !bParam)
            break;
        *pSound2 = 0x16A;
        break;
    case 0x40:
        *pSound2 = *pSound1 ? 0x174 : 0x170;
        break;
    case 0x50:
        if (*pSound1 && (nType == 0 || nType == 1) && !bParam)
            break;
        *pSound2 = 0x178;
        break;
    case 0x10:
        if (*pSound1)
            *pSound2 = 0x17B;
        break;
    case 0x60:
        *pSound2 = 0x17E;
        break;
    case 0x70:
        *pSound2 = 0x18B;
        break;
    case 0x80:
        *pSound2 = 0x956;
        break;
    case 0xB0:
        *pSound2 = 0x187;
        break;
    }
}

// 0x004CA2C0
static int UNITSND_GetUnitSndClassId(D2UnitStrc* pUnit)
{
    int nType;
    int nClass;
    int nMode;
    int nTypeValue = UNIT_INVALID;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }
    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    if (!nType)
        D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\UNIT\\UnitSnd.cpp", 0xB01);
    return nClass;
}

// 0x004CA320
static int UNITSND_GetUnitSndType(D2UnitStrc* pUnit)
{
    int nType;
    int nClass;
    int nMode;
    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }
    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    if (!nType)
        D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\UNIT\\UnitSnd.cpp", 0xB0D);
    return nType;
}

// 0x004CA380
static int UNITSND_GetUnitSndMode(D2UnitStrc* pUnit)
{
    int nType;
    int nClass;
    int nMode;
    int nTypeValue = 6;
    if (pUnit)
    {
        nTypeValue = pUnit->dwUnitType;
    }
    nType = nTypeValue;
    const int nClassValue = !pUnit ? -1 : pUnit->dwClassId;
    nClass = nClassValue;
    nMode = UNITS_GetAnimOrSeqMode(pUnit);
    if (!nType)
        D2COMMON_11013_ConvertMode(pUnit, &nType, &nClass, &nMode, ".\\UNIT\\UnitSnd.cpp", 0xB19);
    return nMode;
}

// 0x004CA3E0
static D2UnitSndPlayerStrc* UNITSND_GetPlayerSoundRecord(unsigned int nClass)
{
    D2_ASSERT(nClass < 7, 0xB22);
    return gapUnitSndPlayers[nClass];
}

void __fastcall UNITSND_GetHitSounds(D2UnitStrc* pUnit, int nHitClass, int bParam, int* pSound1, int* pSound2); // 0x004CA560
// 0x004CA410
static D2MonSoundsTxt* UNITSND_GetMonSoundsRecord(D2UnitStrc* pUnit)
{
    if (!pUnit)
        return DATATBLS_GetMonSoundsTxtRecordFromSoundId(0);

    const int nClass = UNITSND_GetUnitSndClassId(pUnit);
    if (nClass >= sgptDataTables->nMonStatsTxtRecordCount)
        return DATATBLS_GetMonSoundsTxtRecordFromSoundId(0);

    if (pUnit->dwUnitType != UNIT_MONSTER)
        return DATATBLS_GetMonSoundsTxtRecordFromMonsterId(nClass);

    if (MONSTER_IsSuperUniqueMonster(pUnit))
    {
        const int nSuperUniqueId = sub_004AC7C0_GetSuperUniqueId(pUnit);
        D2SuperUniquesTxt* pSuperUniquesTxtRecord = DATATBLS_GetSuperUniquesTxtRecord(nSuperUniqueId);
        if (pSuperUniquesTxtRecord && pSuperUniquesTxtRecord->dwMonSound > 0)
            return DATATBLS_GetMonSoundsTxtRecordFromSoundId(pSuperUniquesTxtRecord->dwMonSound);
    }

    if (MONSTER_IsUniqueMonster(pUnit) || MONSTER_IsMinionMonster(pUnit))
    {
        D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(nClass);
        if (!pMonStatsTxtRecord)
            return DATATBLS_GetMonSoundsTxtRecordFromSoundId(0);
        if (pMonStatsTxtRecord->wUMonSound > 0)
            return DATATBLS_GetMonSoundsTxtRecordFromSoundId(pMonStatsTxtRecord->wUMonSound);
    }

    return DATATBLS_GetMonSoundsTxtRecordFromMonsterId(nClass);
}

// 0x004CA4C0
int __fastcall UNITSND_GetDirectionRate(D2UnitStrc* pUnit, unsigned int nDirection)
{
    D2_ASSERT(pUnit, 0xB5C);
    nDirection &= 0xF;
    if (nDirection <= 0xD)
        return gaDirRate[nDirection].nValue;
    D2_ASSERT(0, 0xB60);
}

// 0x004CA500
unsigned int __fastcall UNITSND_GetAnimRate(D2UnitStrc* pUnit, unsigned int nDirection)
{
    D2_ASSERT(pUnit, 0xB6B);
    nDirection &= 0xF;
    if (nDirection <= 0xD)
    {
        int nSpeed = pUnit->wAnimSpeed;
        if (!nSpeed)
            nSpeed = 1;
        return ((gaDirRate[nDirection].nRate << 8) + 0x80) / nSpeed;
    }
    D2_ASSERT(0, 0xB6F);
}

// 0x004CA560
void __fastcall UNITSND_GetHitSounds(D2UnitStrc* pUnit, int nHitClass, int bParam, int* pSound1, int* pSound2)
{
    D2_ASSERT(pUnit, 0xB82);
    int nType = UNITSND_GetUnitSndType(pUnit);
    *pSound1 = 0;
    *pSound2 = 0;
    if (nType == 1)
    {
        if (MONSTERREGION_CheckMonStats2Flag(UNITSND_GetUnitSndClassId(pUnit), 0xD))
            return;
    }

    const int nHitClassHigh = nHitClass & 0xF0;
    switch (nHitClass & 0xF)
    {
    case 1: *pSound1 = 0x141; break;
    case 8: case 9: *pSound1 = 0x149; break;
    case 6: case 7: *pSound1 = 0x14F; break;
    case 2: case 3: case 4: case 5: *pSound1 = 0x155; break;
    case 10: case 11: *pSound1 = 0x15B; break;
    case 12: *pSound1 = 0x145; break;
    }

    switch (nHitClassHigh)
    {
    case 0x20:
        *pSound2 = *pSound1 ? 0x164 : 0x161;
        break;
    case 0x30:
        if (!*pSound1)
        {
            *pSound2 = 0x167;
            break;
        }
        if ((nType == 0 || nType == 1) && !bParam)
            break;
        *pSound2 = 0x16A;
        break;
    case 0x40:
        *pSound2 = *pSound1 ? 0x174 : 0x170;
        break;
    case 0x50:
        if (*pSound1 && (nType == 0 || nType == 1) && !bParam)
            break;
        *pSound2 = 0x178;
        break;
    case 0x10:
        if (*pSound1)
            *pSound2 = 0x17B;
        break;
    case 0x60:
        *pSound2 = 0x17E;
        break;
    case 0x70:
        *pSound2 = 0x18B;
        break;
    case 0x80:
        *pSound2 = 0x956;
        break;
    case 0xB0:
        *pSound2 = 0x187;
        break;
    }
}

// 0x004CA810
int __fastcall UNITSND_GetModeSound(D2UnitStrc* pUnit, int nMode)
{
    D2_ASSERT(pUnit, 0xC08);
    int nSound = 0;
    switch (nMode & 0xF)
    {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 7:
    case 8:
    case 9:
        nSound = 0x18E;
        break;
    case 10:
    case 11:
        nSound = 0x191;
        break;
    }
    return nSound;
}

// 0x004CA8A0
void __fastcall UNITSND_AddUnitSfx(D2UnitStrc* pUnit, D2TimedHintEntryStrc* pEntry)
{
    D2_ASSERT(pUnit, 0xC2C);
    D2SOUNDUTIL_ListAddHead((D2TimedHintNodeStrc**)&pUnit->pUnitSfxData, pEntry);
}

void __fastcall D2SOUNDUTIL_ListRemove(D2TimedHintNodeStrc** ppList, D2TimedHintEntryStrc* pEntry); // 0x00516980

// 0x004CA8D0
void __fastcall UNITSND_RemoveUnitHint(D2UnitStrc* pUnit, D2TimedHintEntryStrc* pEntry)
{
    D2_ASSERT(pUnit, 0xC2C);
    D2SOUNDUTIL_ListRemove((D2TimedHintNodeStrc**)&pUnit->pUnitSfxData, pEntry);
}

// 0x004CA9C0
void __fastcall UNITSND_ReleaseUnitHints(D2UnitStrc* pUnit, int bForce)
{
    D2_ASSERT(pUnit, 0xC2C);
    D2TimedHintNodeStrc* pNode = (D2TimedHintNodeStrc*)pUnit->pUnitSfxData;
    while (pNode)
    {
        D2TimedHintNodeStrc* pNext = pNode->pNext;
        sub_004BA790_ReleaseUnitSfx(pNode->pEntry, pUnit, bForce);
        pNode = pNext;
    }
}

int __fastcall SOUNDHDR_GetLoopFlag(int nIndex); // 0x004818F0

// 0x004CAA10
void __fastcall UNITSND_PurgeUnitHints(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0xC2C);
    D2TimedHintNodeStrc* pNode = (D2TimedHintNodeStrc*)pUnit->pUnitSfxData;
    while (pNode)
    {
        D2TimedHintEntryStrc* pEntry = pNode->pEntry;
        D2TimedHintNodeStrc* pNext = pNode->pNext;
        if (SOUNDHDR_GetLoopFlag(SOUNDINST_GetSoundIdByHandle((int)pEntry)))
            sub_004BA790_ReleaseUnitSfx(pEntry, pUnit, 0);
        pNode = pNext;
    }
}

// 0x004CAAA0
static void __stdcall UNITSND_SetUnitSfx(D2UnitStrc* pUnit, unsigned char bUnitSfx)
{
    D2_ASSERT(pUnit, 0xC9A);
    pUnit->bUnitSfx = bUnitSfx;
}

void __fastcall sub_K06_Emitsfx70(D2UnitStrc* pUnit, unsigned char bUnitSfx)
{
    UNITSND_SetUnitSfx(pUnit, bUnitSfx);
}

// 0x004CAAD0
static inline int UNITSND_GetSfxMode(D2UnitStrc* unit)
{
    if (!unit) {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0xCA5);
        exit(-1);
    }
    return unit->dwSfxMode;
}

int __stdcall emit_getter_004CAAD0(D2UnitStrc* unit) { return UNITSND_GetSfxMode(unit); }

// 0x004CAB00
static void __stdcall UNITSND_SetSfxMode(D2UnitStrc* pUnit, int nSfxMode)
{
    D2_ASSERT(pUnit, 0xCB0);
    pUnit->dwSfxMode = nSfxMode;
}

void __fastcall sub_K06_Emitsfx74(D2UnitStrc* pUnit, int nSfxMode)
{
    UNITSND_SetSfxMode(pUnit, nSfxMode);
}

// 0x004CAB30
static __declspec(noinline) unsigned int UNITSND_ReadSoundTick(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0xCBB);
    return pUnit->dwSfxTicks;
}

// 0x004CAB60
static void __stdcall UNITSND_WriteSoundTick(D2UnitStrc* pUnit, unsigned int nTicks)
{
    D2_ASSERT(pUnit, 0xCC6);
    pUnit->dwSfxTicks = nTicks;
}

// 0x004CAB90
static unsigned int UNITSND_ReadAsyncSoundTick(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0xCD1);
    return pUnit->dwSfxAsyncTicks;
}

// 0x004CABC0
static void __stdcall UNITSND_WriteAsyncSoundTick(D2UnitStrc* pUnit, unsigned int nTicks)
{
    D2_ASSERT(pUnit, 0xCDC);
    pUnit->dwSfxAsyncTicks = nTicks;
}

// 0x004CAC30
static void __stdcall UNITSND_WriteStepSoundTick(D2UnitStrc* pUnit, unsigned int nTicks)
{
    D2_ASSERT(pUnit, 0xCF2);
    pUnit->dwSfxStepTicks = nTicks;
}

inline int CLIENTS_GetUnitXInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

inline int CLIENTS_GetUnitYInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x004CACA0
static void __stdcall UNITSND_SetHasActiveSound(D2UnitStrc* pUnit, int bHasActiveSound)
{
    D2_ASSERT(pUnit, 0xD08);
    pUnit->bHasActiveSound = bHasActiveSound;
}

void __fastcall sub_K06_Emitsfx88(D2UnitStrc* pUnit, int bHasActiveSound)
{
    UNITSND_SetHasActiveSound(pUnit, bHasActiveSound);
}

// 0x004CACE0
static D2DrlgTileDataStrc* UNITSND_FindFloorTileAt(D2ActiveRoomStrc* pRoom, int nX, int nY)
{
    D2DrlgCoordsStrc tCoords;
    DUNGEON_GetRoomCoordinates(pRoom, &tCoords);
    const int nTileX = (nX - tCoords.nSubtileX) / 5;
    const int nTileY = (nY - tCoords.nSubtileY) / 5;
    unsigned int nCount;
    D2DrlgTileDataStrc* pTiles = sub_00619660_GetFloorTiles(pRoom, &nCount);
    for (unsigned int i = 0; i < nCount; ++i)
    {
        D2DrlgTileDataStrc* pTile = &pTiles[i];
        if (pTile->nPosX == nTileX && pTile->nPosY == nTileY)
            return pTile;
    }
    return 0;
}

// 0x004CAD60
static __declspec(noinline) int UNITSND_GetTileMaterial(D2DrlgTileDataStrc* pTileData)
{
    D2TileLibraryEntryStrc* pTile = pTileData->pTile;
    if (pTile)
    {
        const unsigned short nFlags = pTile->nFlags;
        if (nFlags & 0x20)
            return 1;
        if (nFlags & 8)
            return 2;
        if (nFlags & 0x10)
            return 3;
        if (nFlags & 0x40)
            return 4;
        if (nFlags & 0x80)
            return 6;
        if (nFlags & 0x400)
            return 5;
    }
    return 0;
}

// 0x004CADB0
int __fastcall UNITSND_GetUnitFloorMaterial(D2UnitStrc* pUnit)
{
    int nRooms;
    D2SoundEnvironTxtStrc* pSoundEnvironTxtRecord = SOUNDHDR_GetSoundEnvironTxtRecord(sub_004817A0_GetPlayerSoundEnviron());
    int nDefault = 1;
    if (pSoundEnvironTxtRecord && pSoundEnvironTxtRecord->nMaterial1 > 0 && pSoundEnvironTxtRecord->nMaterial1 < 7)
        nDefault = pSoundEnvironTxtRecord->nMaterial1;

    const int nX = CLIENTS_GetUnitXInline(pUnit);
    const int nY = CLIENTS_GetUnitYInline(pUnit);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (!pRoom)
        return 0;

    D2DrlgTileDataStrc* pTileData = UNITSND_FindFloorTileAt(pRoom, nX, nY);
    if (!pTileData)
    {
        D2ActiveRoomStrc** ppRooms;
        DUNGEON_GetAdjacentRoomsListFromRoom(pRoom, &ppRooms, &nRooms);
        for (int i = 0; i < nRooms; ++i)
        {
            pTileData = UNITSND_FindFloorTileAt(ppRooms[i], nX, nY);
            if (pTileData)
                break;
        }

    }

    if (pTileData)
    {
        const int nMaterial = UNITSND_GetTileMaterial(pTileData);
        if (nMaterial)
            return nMaterial;
    }
    return nDefault;
}

static __forceinline int UNITSND_IsMonsterWalkMode(D2UnitStrc* pUnit, int nMode)
{
    int nClass = UNITSND_GetUnitSndClassId(pUnit);
    if (nClass < 0 || nClass >= sgptDataTables->nMonStatsTxtRecordCount)
        nClass = -1;

    int bWalk = 0;
    if (nMode == 2 || nMode == 0xF)
        bWalk = 1;

    if (nClass == 0xF && nMode == 1)
        bWalk = 1;
    else if (nClass == 0x6E)
        bWalk = nMode == 8;

    return bWalk;
}

// 0x004CAEB0
int __fastcall UNITSND_GetFootstepSound(D2UnitStrc* pUnit, int bLayer)
{
    int nSound = 0;
    const int nType = UNITSND_GetUnitSndType(pUnit);
    if (nType == 0)
    {
        nSound = UNITSND_GetPlayerSoundRecord(UNITSND_GetUnitSndClassId(pUnit))->nFootstep;
    }
    if (nType == 1)
    {
        D2MonSoundsTxt* pMonSoundsTxtRecord = UNITSND_GetMonSoundsRecord(pUnit);
        if (!pMonSoundsTxtRecord)
            return 0;
        nSound = pMonSoundsTxtRecord->dwFootstep;
    }

    if (!nSound)
        return 0;

    switch (UNITSND_GetUnitFloorMaterial(pUnit))
    {
    case 2:
        nSound += 4;
        break;
    case 3:
        nSound += 8;
        break;
    case 4:
        nSound += 0xC;
        break;
    case 6:
        nSound += 0x14;
        break;
    case 5:
        nSound += 0x10;
        break;
    }

    if (bLayer)
        nSound += 0x18;
    return nSound;
}

// 0x004CAF60
void __fastcall UNITSND_UpdateFootsteps(D2UnitStrc* pUnit)
{
    int nMode;
    int nType;
    nType = UNITSND_GetUnitSndType(pUnit);
    nMode = UNITSND_GetUnitSndMode(pUnit);
    if (nType == 1 && !UNITSND_IsMonsterWalkMode(pUnit, nMode))
    {
        return;
    }

    const int nFrame = pUnit->nSeqCurrentFramePrecise;
    unsigned int nFrameCount = pUnit->dwFrameCountPrecise;
    const int nSpeed = pUnit->wAnimSpeed;
    if (!nSpeed)
        return;

    unsigned int nSteps = 2;
    unsigned int nOffset = 0;
    unsigned int nLayerSound = 0;
    unsigned int nChance = 100;
    if (nType == 1)
    {
        D2MonSoundsTxt* pMonSoundsTxtRecord = UNITSND_GetMonSoundsRecord(pUnit);
        if (pMonSoundsTxtRecord)
        {
            nOffset = pMonSoundsTxtRecord->dwFsOff << 8;
            nSteps = pMonSoundsTxtRecord->dwFsCnt;
            nLayerSound = pMonSoundsTxtRecord->dwFootstepLayer;
            nChance = pMonSoundsTxtRecord->dwFsPrb;
            if (!nSteps)
                return;
        }
    }

    const unsigned int nTick = sub_0044DB00();
    const unsigned int nPeriod = nFrameCount / (nSteps * nSpeed);
    const unsigned int nElapsed = nTick - pUnit->dwSfxStepTicks;
    if (nSteps > 1 && nElapsed < nPeriod * 2 / 3)
        return;

    const unsigned int nStepLength = nFrameCount / nSteps;
    const int nDist = sub_004E4180(nFrame, nOffset, nStepLength);
    const int nDistNext = sub_004E4180(nFrame + nSpeed, nOffset, nStepLength);
    const int nDistPrev = sub_004E4180(nFrame - nSpeed, nOffset, nStepLength);
    if (nDist >= nDistNext || nDist >= nDistPrev)
        return;

    int bRun = 0;
    if (nType == 0)
    {
        if (nMode == 3)
            bRun = 1;
    }
    else if (nType == 1)
    {
        if (nMode == 0xF)
            bRun = 1;
    }

    const int hSound = sub_004B9A00(UNITSND_GetFootstepSound(pUnit, bRun), pUnit, 0, 0, 0);
    if (hSound)
    {
        int nVolume = 0xFF;
        if (pUnit != sub_00463DD0_GetPlayerUnit())
            nVolume = 0xC8;
        if (nElapsed > nPeriod * 3 / 2)
            nVolume = nVolume * 160 / 255;
        SOUNDINST_SetValue(hSound, nVolume);
    }

    if (nLayerSound && (unsigned int)sub_004E40A0(100) < nChance)
        sub_004B9A00(nLayerSound, pUnit, 0, 0, 0);

    UNITSND_WriteStepSoundTick(pUnit, nTick);
}

// 0x004CB170
static inline unsigned int UNITSND_GetNeutralSound(D2UnitStrc* pUnit)
{
    D2MonSoundsTxt* pMonSoundsTxtRecord = UNITSND_GetMonSoundsRecord(pUnit);
    if (!pMonSoundsTxtRecord)
        return 0;
    return pMonSoundsTxtRecord->dwNeutral;
}

// 0x004CB180
static inline unsigned int UNITSND_GetTauntSound(D2UnitStrc* pUnit)
{
    D2MonSoundsTxt* pMonSoundsTxtRecord = UNITSND_GetMonSoundsRecord(pUnit);
    if (!pMonSoundsTxtRecord)
        return 0;
    return pMonSoundsTxtRecord->dwTaunt;
}

unsigned int __fastcall sub_M110_Emit_004CB170(D2UnitStrc* pUnit, int bTaunt)
{
    if (bTaunt)
        return UNITSND_GetTauntSound(pUnit);
    return UNITSND_GetNeutralSound(pUnit) + 1;
}

// 0x004CB190
void __fastcall UNITSND_ReleaseSkillSfx(D2UnitStrc* pUnit)
{
    if (UNITSND_GetUnitSndType(pUnit) != 1)
        return;

    D2MonSoundsTxt* pMonSoundsTxtRecord = UNITSND_GetMonSoundsRecord(pUnit);
    if (!pMonSoundsTxtRecord)
        return;

    D2_ASSERT(pUnit, 0xC2C);
    D2UnitSfxNodeStrc* pNode = (D2UnitSfxNodeStrc*)pUnit->pUnitSfxData;
    while (pNode)
    {
        void* pEntry = pNode->pUnitSfx;
        D2UnitSfxNodeStrc* pNext = pNode->pNext;
        const int nGroup = SOUNDHDR_GetGroupStart(SOUNDINST_GetSoundIdByHandle((int)pEntry));
        if (nGroup == pMonSoundsTxtRecord->dwSkill[0] || nGroup == pMonSoundsTxtRecord->dwSkill[1]
            || nGroup == pMonSoundsTxtRecord->dwSkill[2] || nGroup == pMonSoundsTxtRecord->dwSkill[3])
            sub_004BA790_ReleaseUnitSfx(pEntry, pUnit, 1);
        pNode = pNext;
    }
}

// 0x004CB220
void __stdcall UNITSND_ReleaseNeutralSfx(D2UnitStrc* pUnit, int bArm)
{
    D2_ASSERT(pUnit, 0xC2C);
    D2UnitSfxNodeStrc* pNode = (D2UnitSfxNodeStrc*)pUnit->pUnitSfxData;
    while (pNode)
    {
        D2UnitSfxNodeStrc* pNext = pNode->pNext;
        void* pEntry = pNode->pUnitSfx;
        D2MonSoundsTxt* pMonSoundsTxtRecord = UNITSND_GetMonSoundsRecord(pUnit);
        const int nNeutral = !pMonSoundsTxtRecord ? 0 : pMonSoundsTxtRecord->dwNeutral;
        if (SOUNDHDR_GetGroupStart(SOUNDINST_GetSoundIdByHandle((int)pEntry)) == nNeutral)
        {
            if (bArm && !SOUNDINST_HasActiveHint(pEntry))
                SOUNDINST_ArmHint(pEntry, 0, 0, 6);
            else
                sub_004BA790_ReleaseUnitSfx(pEntry, pUnit, 1);
        }
        pNode = pNext;
    }
}

// 0x004CBDE0
void __fastcall UNITSND_PlayEventSound(int nUnitId, unsigned char nUnitType, unsigned short nEvent)
{
    D2UnitStrc* pUnit = CUNIT_FindClientUnit(nUnitId, nUnitType);
    if (!pUnit)
        return;

    int nSpeech;

    switch (nEvent)
    {
    case 90:
        sub_004B9A00(0x111B, pUnit, 0, 0, 0);
        return;
    case 10:
        SOUNDINST_SetValue(sub_004B9A00(0xA71, pUnit, 0, 0, 0), 0x78);
        return;
    case 93:
        sub_004B9A00(0x9F9, pUnit, 0, 0, 0);
        return;
    case 12:
    {
        D2StatListStrc* pStatList = STATLIST_GetStatListFromUnitAndState(pUnit, STATE_EVADE);
        if (!pStatList)
            return;
        const int nSkillId = STATLIST_GetStatValue(pStatList, STAT_MODIFIERLIST_SKILL, 0);
        if (!SKILLS_GetHighestLevelSkillFromUnitAndId(pUnit, nSkillId))
            return;
        D2SkillsTxt* pSkillsTxtRecord = sub_0045C4B0_GetSkillsTxtRecord(nSkillId);
        if (pSkillsTxtRecord && pSkillsTxtRecord->wStSound > 0)
            sub_004B9A00(pSkillsTxtRecord->wStSound, pUnit, 0, 0, 0);
        return;
    }
    case 84:
        if (UNITSND_GetUnitSndClassId(pUnit) == 0x10F)
        {
            sub_004B9A00(0x1207, pUnit, 0, 0, 0);
            nSpeech = 0x1207;
        }
        else
        {
            sub_004B9A00(0x1211, pUnit, 0, 0, 0);
            nSpeech = 0x1211;
        }
        TEXT_SetSpeechHoverText(pUnit, nSpeech);
        break;
    case 85:
        if (UNITSND_GetUnitSndClassId(pUnit) == 0x10F)
        {
            sub_004B9A00(0x1204, pUnit, 0, 0, 0);
            nSpeech = 0x1204;
        }
        else
        {
            sub_004B9A00(0x1208, pUnit, 0, 0, 0);
            nSpeech = 0x1208;
        }
        TEXT_SetSpeechHoverText(pUnit, nSpeech);
        break;
    case 86:
        if (UNITSND_GetUnitSndClassId(pUnit) == 0x10F)
        {
            sub_004B9A00(0x1205, pUnit, 0, 0, 0);
            nSpeech = 0x1205;
        }
        else
        {
            sub_004B9A00(0x120B, pUnit, 0, 0, 0);
            nSpeech = 0x120B;
        }
        TEXT_SetSpeechHoverText(pUnit, nSpeech);
        break;
    case 87:
        if (UNITSND_GetUnitSndClassId(pUnit) == 0x10F)
        {
            sub_004B9A00(0x1206, pUnit, 0, 0, 0);
            nSpeech = 0x1206;
        }
        else
        {
            sub_004B9A00(0x120E, pUnit, 0, 0, 0);
            nSpeech = 0x120E;
        }
        TEXT_SetSpeechHoverText(pUnit, nSpeech);
        break;
    case 15:
        if (UNITSND_GetUnitSndClassId(pUnit) == 0x10F)
            sub_004B9A00(0x10C2, pUnit, 0, 0, 0);
        return;
    case 16:
        if (UNITSND_GetUnitSndType(pUnit) == 1)
        {
            D2MonSoundsTxt* pMonSoundsTxtRecord = UNITSND_GetMonSoundsRecord(pUnit);
            sub_004B9A00(!pMonSoundsTxtRecord ? 0 : pMonSoundsTxtRecord->dwTaunt, pUnit, 0, 0, 0);
        }
        return;
    case 17:
        UNITSND_PlayFleeSound(pUnit);
        return;
    case 18:
        sub_004B9A00(sub_004E0590_PickNpcSound(pUnit, 1), sub_00463DD0_GetPlayerUnit(), 0, 1, 0);
        return;
    case 13:
        sub_004B9A00(0xA4A, pUnit, 0, 0, 0);
        return;
    case 14:
        sub_004B9A00(0xA4B, pUnit, 0, 0, 0);
        return;
    case 92:
        sub_004DCE10_UpdateTimedHint(0x19, 1);
        return;
    case 91:
        sub_004B9A00(8, sub_00463DD0_GetPlayerUnit(), 0, 0, 0);
        return;
    default:
        break;
    }

    if (pUnit->dwUnitType == UNIT_PLAYER)
        UNITSND_PlayPlayerSpeech(pUnit, nEvent);
}

// 0x004CC250
static inline int UNITSND_HasSlotValue(int* pSlots, int nValue)
{
    for (int i = 0; i < 10; i++)
    {
        const int nSlot = pSlots[i];
        if (!nSlot)
        {
            return 0;
        }
        if (nSlot == nValue)
        {
            return 1;
        }
    }
    return 0;
}

int __fastcall sub_M119_Emit_004CC250(int* pSlots, int nValue)
{
    return UNITSND_HasSlotValue(pSlots, nValue + 1);
}

// 0x004CC5B0
void __fastcall UNITSND_UpdateUnitSound(D2UnitStrc* pUnit, int nMode, int bModeGiven)
{
    int nAttackMode;
    const int nType = UNITSND_GetUnitSndType(pUnit);
    const int nClass = UNITSND_GetUnitSndClassId(pUnit);
    if (!bModeGiven)
        nMode = UNITSND_GetUnitSndMode(pUnit);

    if (nType == 0)
    {
        switch (nMode)
        {
        case 15:
            if (nClass == 4)
            {
                nAttackMode = 15;
                goto attack;
            }
            break;
        case 16:
            if (nClass == 6)
            {
                nAttackMode = 16;
                goto attack;
            }
            break;
        case 9:
            UNITSND_PlayHitClassSound(pUnit);
            break;
        case 12:
            if (nClass == 6)
                sub_004B9A00(0xFF, pUnit, 4, 0, 0);
            else
                sub_004B9A00(0xFF, pUnit, 0, 0, 0);
            break;
        case 7:
        case 8:
            nAttackMode = nMode;
            goto attack;
        case 0:
        case 4:
        case 19:
            UNITSND_PlayHitSound(pUnit, nMode);
            break;
        }
    }
    else if (nType == 1)
    {
        D2MonSoundsTxt* pMonSoundsTxtRecord = UNITSND_GetMonSoundsRecord(pUnit);
        if (!pMonSoundsTxtRecord)
            return;

        if (nMode == pMonSoundsTxtRecord->nCvtMo1 && pMonSoundsTxtRecord->dwCvtSk1 < 0)
            nMode = pMonSoundsTxtRecord->nCvtTgt1;
        if (nMode == pMonSoundsTxtRecord->nCvtMo2 && pMonSoundsTxtRecord->dwCvtSk2 < 0)
            nMode = pMonSoundsTxtRecord->nCvtTgt2;
        if (nMode == pMonSoundsTxtRecord->nCvtMo3 && pMonSoundsTxtRecord->dwCvtSk3 < 0)
            nMode = pMonSoundsTxtRecord->nCvtTgt3;

        switch (nMode)
        {
        case 4:
        case 5:
            nAttackMode = nMode;
            goto attack;
        case 0:
        case 3:
        case 13:
            UNITSND_PlayHitSound(pUnit, nMode);
            break;
        case 8:
        case 9:
        case 10:
        case 11:
            UNITSND_PlaySkillSound(pUnit, nMode);
            break;
        case 12:
            UNITSND_ReleaseMonsterSfx(pUnit);
            break;
        }
    }
    return;

attack:
    UNITSND_PlayAttackSound(pUnit, nAttackMode, 1);
}

// 0x004CB2C0
void __stdcall UNITSND_ReleaseMonsterSfx(D2UnitStrc* pUnit)
{
    if (UNITSND_GetUnitSndType(pUnit) != 1)
        return;

    D2MonSoundsTxt* pMonSoundsTxtRecord = UNITSND_GetMonSoundsRecord(pUnit);
    if (!pMonSoundsTxtRecord)
        return;

    D2_ASSERT(pUnit, 0xC2C);
    D2UnitSfxNodeStrc* pNode = (D2UnitSfxNodeStrc*)pUnit->pUnitSfxData;
    while (pNode)
    {
        void* pEntry = pNode->pUnitSfx;
        D2UnitSfxNodeStrc* pNext = pNode->pNext;
        const int nGroup = SOUNDHDR_GetGroupStart(SOUNDINST_GetSoundIdByHandle((int)pEntry));
        if (nGroup == pMonSoundsTxtRecord->dwAttack1 || nGroup == pMonSoundsTxtRecord->dwWeapon1
            || nGroup == pMonSoundsTxtRecord->dwHitSound || nGroup == pMonSoundsTxtRecord->dwNeutral
            || nGroup == pMonSoundsTxtRecord->dwSkill[0] || nGroup == pMonSoundsTxtRecord->dwSkill[1]
            || nGroup == pMonSoundsTxtRecord->dwSkill[2] || nGroup == pMonSoundsTxtRecord->dwSkill[3]
            || nGroup == pMonSoundsTxtRecord->dwInit || nGroup == pMonSoundsTxtRecord->dwTaunt
            || nGroup == pMonSoundsTxtRecord->dwFlee)
            sub_004BA790_ReleaseUnitSfx(pEntry, pUnit, 1);
        pNode = pNext;
    }
}

// 0x004CB380
static int __stdcall UNITSND_GetObjectStopSound(D2UnitStrc* pUnit, int nMode, int nOldMode)
{
    const unsigned int nClass = UNITSND_GetUnitSndClassId(pUnit);
    if (nClass < 0x23D && nMode < 8)
    {
        D2UnitSndObjectStrc* pRecord = gapUnitSndObjects[nClass];
        if (!pRecord)
            return 0;
        if (pRecord == &gtUnitSndObject && nOldMode > nMode)
            return 0;
        return pRecord->nModeSound[nMode];
    }
    D2_ASSERT(0, 0xE72);
}

// 0x004CB3E0
static int UNITSND_GetObjectModeSound(D2UnitStrc* pUnit, int nMode)
{
    const unsigned int nClass = UNITSND_GetUnitSndClassId(pUnit);
    if (nClass < 0x23D && nMode < 8)
    {
        D2UnitSndObjectStrc* pRecord = gapUnitSndObjects[nClass];
        if (!pRecord)
            return 0;
        if (nClass == 0x3D)
            return gaUnitSndObjects[21].nModeSound[nMode];
        if (!pRecord->nSoundA && !pRecord->nSoundB)
            return 0;
        if (pRecord->nSoundAMode == nMode || pRecord->nSoundAMode == 8)
            return pRecord->nSoundA;
        if (pRecord->nSoundBMode == nMode || pRecord->nSoundBMode == 8)
            return pRecord->nSoundB;
        return 0;
    }
    D2_ASSERT(0, 0xE86);
}

// 0x004CB460
void __fastcall UNITSND_UpdateModeSound(D2UnitStrc* pUnit)
{
    const int nMode = UNITSND_GetUnitSndMode(pUnit);
    if (UNITSND_GetUnitSndType(pUnit) == 2)
    {
        if (UNITSND_GetUnitSndClassId(pUnit) == 0x1A && !nMode && !UNITSND_ReadAsyncSoundTick(pUnit)
            && DRLG_UnitEdgeDistance(pUnit, sub_00463DD0_GetPlayerUnit()) < 0x14)
        {
            sub_004B9A00(0xE57, pUnit, 0, 0, 0);
            UNITSND_WriteAsyncSoundTick(pUnit, sub_0044DB00());
        }

        D2_ASSERT(pUnit, 0xC8F);
        if (pUnit->bUnitSfx && nMode == pUnit->dwSfxMode)
            return;

        const int nSound = UNITSND_GetObjectModeSound(pUnit, nMode);
        if (nSound)
        {
            if (!UNITSND_FindUnitSfxInRange(pUnit, nSound))
                sub_004B9A00(nSound, pUnit, 0, 0, 0);
        }
        else
        {
            UNITSND_PurgeUnitHints(pUnit);
        }

        int bForce = 0;
        if (UNITSND_GetUnitSndClassId(pUnit) == 0x3B)
            bForce = 1;

        if (pUnit->bUnitSfx || bForce)
        {
            const int nStopSound = UNITSND_GetObjectStopSound(pUnit, nMode, pUnit->dwSfxMode);
            if (nStopSound)
                sub_004B9A00(nStopSound, pUnit, 0, 0, 0);
        }

        pUnit->dwSfxMode = nMode;
        pUnit->bUnitSfx = 1;
        return;
    }

    if (UNITSND_GetUnitSndType(pUnit) != 1)
        return;

    int nClass = CUNIT_GetMonsterBaseId(pUnit);
    if (nClass < 0 || nClass >= sgptDataTables->nMonStatsTxtRecordCount)
        nClass = -1;

    int bNeutral = 0;
    if (nMode == 1 || nMode == 2 || nMode == 0xF)
        bNeutral = 1;

    if (nClass == 0x6E && nMode == 8)
        bNeutral = 1;
    else if (nClass == 0x88 && nMode == 0xB)
        bNeutral = 1;

    if (!bNeutral)
        return;

    D2MonSoundsTxt* pMonSoundsTxtRecord = UNITSND_GetMonSoundsRecord(pUnit);
    if (!pMonSoundsTxtRecord)
        return;

    D2MonSoundsTxt* pNeutralRecord = UNITSND_GetMonSoundsRecord(pUnit);
    const int nNeutral = !pNeutralRecord ? 0 : pNeutralRecord->dwNeutral;
    const unsigned int nTick = sub_0044DB00();
    const unsigned int nNeuTime = pMonSoundsTxtRecord->dwNeuTime;
    if (!nNeutral)
        return;
    if (UNITSND_FindUnitSfxInRange(pUnit, nNeutral))
        return;
    if (nTick - gnNeutralTick < gnNeutralDelay)
        return;
    if (nTick - UNITSND_ReadSoundTick(pUnit) < nNeuTime)
        return;
    if (nTick - UNITSND_ReadAsyncSoundTick(pUnit) < nNeuTime)
        return;

    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);
    if (pRoom && DUNGEON_IsRoomInTown(pRoom))
        return;
    if (!SOUNDINST_IsNearPlayer(pUnit))
        return;
    if (sub_004E40A0(0xF))
        return;

    sub_004B9A00(nNeutral, pUnit, 0, 0, 0);
    gnNeutralTick = nTick;
    UNITSND_WriteAsyncSoundTick(pUnit, nTick);
    gnNeutralDelay = SKILLDESC_RandomInRange(0x1E, 0x5A);
}

// 0x004CB6A0
void __fastcall UNITSND_PlayAttackSound(D2UnitStrc* pUnit, int nMode, int bDelay)
{
    const int nType = UNITSND_GetUnitSndType(pUnit);
    if (nType == 0)
    {
        const int nDirection = UNITS_GetHitClass(pUnit);
        const int nSound = UNITSND_GetDirectionRate(pUnit, nDirection);
        unsigned int nRate = UNITSND_GetAnimRate(pUnit, nDirection);
        if (!bDelay)
            nRate = 0;
        sub_004B9A00(nSound, pUnit, nRate, 0, 0);
        pUnit->dwSfxTicks = sub_0044DB00();
        return;
    }

    if (nType != 1)
        return;

    D2MonSoundsTxt* pMonSoundsTxtRecord = UNITSND_GetMonSoundsRecord(pUnit);
    if (!pMonSoundsTxtRecord)
        return;

    int nSound;
    if (nMode == 4)
        nSound = pMonSoundsTxtRecord->dwAttack1;
    else
        nSound = pMonSoundsTxtRecord->dwWeapon1;

    int nDelay;
    if (nMode == 4)
        nDelay = pMonSoundsTxtRecord->dwAtt1Del;
    else
        nDelay = pMonSoundsTxtRecord->dwWea1Del;

    if (!bDelay)
        nDelay = 0;

    int nChance;
    if (nMode == 4)
        nChance = pMonSoundsTxtRecord->dwAtt1Prb;
    else
        nChance = pMonSoundsTxtRecord->dwWea1Vol;

    int bPlay = 1;
    if (!nSound)
        bPlay = 0;
    if ((unsigned int)nChance < 100)
    {
        if (sub_0044DB00() - gnSfxTick < 0xF)
            bPlay = 0;
        if (SOUNDINST_HasUnitSound(pUnit))
            goto second;
    }

    if (bPlay && sub_004E40A0(100) < nChance)
    {
        UNITSND_ReleaseNeutralSfx(pUnit, 1);
        sub_004B9A00(nSound, pUnit, nDelay, 0, 0);
        UNITSND_WriteSoundTick(pUnit, sub_0044DB00());
        gnSfxTick = sub_0044DB00();
    }

second:
    int nSpeed = pUnit->wAnimSpeed;
    if (!nSpeed)
        nSpeed = 1;

    if (nMode == 4)
        nSound = pMonSoundsTxtRecord->dwAttack2;
    else
        nSound = pMonSoundsTxtRecord->dwWeapon2;

    unsigned int nRate;
    if (nMode == 4)
        nRate = pMonSoundsTxtRecord->dwAtt2Del;
    else
        nRate = pMonSoundsTxtRecord->dwWea2Del;
    nRate = ((nRate << 8) + 0x80) / nSpeed;

    int nVolume;
    if (nMode == 4)
        nVolume = pMonSoundsTxtRecord->dwAtt2Prb;
    else
        nVolume = pMonSoundsTxtRecord->dwWea2Vol;

    const int hSound = sub_004B9A00(nSound, pUnit, nRate, 0, 0);
    if (hSound)
        SOUNDINST_SetValue(hSound, nVolume);
}

// 0x004CB860
static void UNITSND_PlayHitClassSound(D2UnitStrc* pUnit)
{
    const int nSound = UNITSND_GetModeSound(pUnit, pUnit->dwLastHitClass);
    sub_004B9A00(nSound, pUnit, 0, 0, 0);
    pUnit->dwSfxTicks = sub_0044DB00();
    gnSfxTick = sub_0044DB00();
}

// 0x004CB890
static void UNITSND_PlaySkillSound(D2UnitStrc* pUnit, int nMode)
{
    if (UNITSND_GetUnitSndType(pUnit) != 1)
        return;

    D2MonSoundsTxt* pMonSoundsTxtRecord = UNITSND_GetMonSoundsRecord(pUnit);
    if (!pMonSoundsTxtRecord)
        return;

    const unsigned int nTick = sub_0044DB00();
    int nSound;
    if (nMode == 8)
        nSound = pMonSoundsTxtRecord->dwSkill[0];
    else if (nMode == 9)
        nSound = pMonSoundsTxtRecord->dwSkill[1];
    else if (nMode == 0xA)
        nSound = pMonSoundsTxtRecord->dwSkill[2];
    else if (nMode == 0xB)
        nSound = pMonSoundsTxtRecord->dwSkill[3];
    else
        return;

    if (nSound == 0xA84)
    {
        D2_ASSERT(pUnit, 0xCBB);
        if (nTick - pUnit->dwSfxTicks < 0x19)
            return;
    }
    else if (!nSound)
    {
        return;
    }

    sub_004B9A00(nSound, pUnit, 0, 0, 0);
    const unsigned int nNow = sub_0044DB00();
    D2_ASSERT(pUnit, 0xCC6);
    pUnit->dwSfxTicks = nNow;
    gnSfxTick = sub_0044DB00();
}

// 0x004CB950
static void UNITSND_PlayFleeSound(D2UnitStrc* pUnit)
{
    if (UNITSND_GetUnitSndType(pUnit) != 1)
        return;

    D2MonSoundsTxt* pMonSoundsTxtRecord = UNITSND_GetMonSoundsRecord(pUnit);
    if (!pMonSoundsTxtRecord)
        return;

    if (sub_0044DB00() - gnSfxTick < 4)
        return;

    sub_004B9A00(pMonSoundsTxtRecord->dwFlee, pUnit, sub_004E40A0(3) + 6, 0, 0);
    UNITSND_WriteSoundTick(pUnit, sub_0044DB00());
    gnSfxTick = sub_0044DB00();
}

// 0x004CB9C0
void __fastcall UNITSND_PlayPlayerSpeech(D2UnitStrc* pUnit, unsigned short nStringId)
{
    D2UnitSndPlayerStrc* pRecord = UNITSND_GetPlayerSoundRecord(pUnit ? pUnit->dwClassId : -1);
    if (!pRecord)
    {
        return;
    }

    int nId = nStringId;
    int nSoundId = 0;
    D2UnitStrc* pSoundUnit = pUnit;
    if (pUnit == sub_00463DD0_GetPlayerUnit() && CUNIT_IsPlayerDeadOrMissing())
    {
        return;
    }

    if (nId >= 0x19 && nId <= 0x20 && !SOUNDINST_HasUnitSound(pUnit))
    {
        nSoundId = pRecord->anEventSounds[6] + 2 * (nId - 0x19);
    }

    if (nId >= 0x21 && nId <= 0x53)
    {
        int nHintSound = pRecord->anEventSounds[7] + nId - 0x21;
        if (nId == 0x23)
        {
            ITEM_ShowTimedHint(0x1250, 0x0, 0x12C, 1, nHintSound, 0xFA, 1);
            return;
        }

        if (nId == 0x22)
        {
            ITEM_ShowTimedHint(0x124E, 0x1DB, 0x320, 1, nHintSound, 0x20D, 1);
            return;
        }

        if (nId == 0x25)
        {
            ITEM_ShowTimedHint(0x0, 0x0, 0x5DC, 0, nHintSound, 0x0, 0);
            return;
        }

        if (nId == 0x21)
        {
            ITEM_ShowTimedHint(0x124D, 0x0, 0x1DB, 0, nHintSound, 0x1A9, 1);
            return;
        }

        if (nId == 0x32)
        {
            ITEM_ShowTimedHint(0x1255, 0x1DB, 0x44C, 1, nHintSound, 0x20D, 1);
            return;
        }

        if (nId == 0x34)
        {
            ITEM_ShowTimedHint(0x1256, 0x0, 0x1A9, 1, nHintSound, 0x177, 1);
            return;
        }

        if (nId == 0x42)
        {
            ITEM_ShowTimedHint(0x1254, 0x0, 0x1A9, 0, nHintSound, 0x177, 1);
            return;
        }

        if (nId == 0x4B)
        {
            ITEM_ShowTimedHint(0x1257, 0x0, 0x1DB, 0, nHintSound, 0x145, 1);
            return;
        }

        if (nId == 0x50)
        {
            ITEM_ShowTimedHint(0x125A, 0x0, 0x1F4, 1, nHintSound, 0x1DB, 1);
            return;
        }

        if (nId == 0x52)
        {
            ITEM_ShowTimedHint(0x1259, 0x0, 0x226, 1, nHintSound, 0x190, 1);
            return;
        }

        if (nId == 0x53)
        {
            ITEM_ShowTimedHint(0x1258, 0x0, 0x20D, 1, nHintSound, 0x1A9, 1);
            return;
        }

        int nFlags;
        switch (nId)
        {
        case 0x26:
        case 0x28:
        case 0x29:
        case 0x2A:
        case 0x2B:
        case 0x2C:
        case 0x2E:
        case 0x2F:
        case 0x37:
        case 0x38:
            nFlags = 0;
            break;

        default:
            nFlags = 0xC;
            break;
        }

        TEXT_SetSpeechHoverText(pUnit, SOUNDINST_GetSoundIdByHandle(sub_004B9A00(nHintSound, pUnit, nFlags, 0, 0)));
        return;
    }

    int bCheckRepeat = 0;
    switch (nId)
    {
    case 0x13:
        nSoundId = pRecord->anEventSounds[0];
        bCheckRepeat = 1;
        break;

    case 0x15:
        nSoundId = pRecord->anEventSounds[1];
        bCheckRepeat = 1;
        break;

    case 0x16:
        nSoundId = pRecord->anEventSounds[2];
        bCheckRepeat = 1;
        break;

    case 0x17:
        nSoundId = pRecord->anEventSounds[3];
        bCheckRepeat = 1;
        break;

    case 0x14:
        nSoundId = pRecord->anEventSounds[4];
        bCheckRepeat = 1;
        break;

    case 0x18:
        nSoundId = pRecord->anEventSounds[5];
        bCheckRepeat = 1;
        break;

    case 1:
        nSoundId = 0xEB;
        break;

    case 2:
        nSoundId = 7;
        pSoundUnit = 0;
        break;

    case 3:
        nSoundId = 0xA;
        pSoundUnit = 0;
        break;

    case 4:
        nSoundId = 0xB;
        pSoundUnit = 0;
        break;

    case 5:
        nSoundId = 0xC;
        pSoundUnit = 0;
        break;

    case 6:
        nSoundId = 0xD;
        pSoundUnit = 0;
        break;

    case 7:
        nSoundId = 0x8B6;
        break;

    case 8:
        nSoundId = 0x8B7;
        break;

    case 9:
        nSoundId = 9;
        break;

    case 11:
        nSoundId = 0xE4;
        break;
    }

    if (bCheckRepeat && SOUNDINST_HasUnitSound(pUnit))
    {
        return;
    }

    if (!nSoundId)
    {
        return;
    }

    if (bCheckRepeat)
    {
        unsigned int nTick = sub_0044DB00();
        if (nSoundId == gnLastRequestSound && nTick - gnLastRequestTick < 0x4B)
        {
            return;
        }

        gnLastRequestTick = nTick;
        gnLastRequestSound = nSoundId;
    }

    TEXT_SetSpeechHoverText(pUnit, SOUNDINST_GetSoundIdByHandle(sub_004B9A00(nSoundId, pSoundUnit, 0, 0, 0)));
}

// 0x004CC160
__declspec(noinline) void __fastcall UNITSND_AddUnitSoundRefs(D2UnitStrc* pUnit, int nDelta)
{
    const int nType = UNITSND_GetUnitSndType(pUnit);
    D2_ASSERT(pUnit, 0xCFD);
    if (pUnit->bHasActiveSound)
    {
        if (nDelta > 0)
            return;
    }
    else if (nDelta < 0)
    {
        return;
    }

    pUnit->bHasActiveSound = nDelta > 0;
    if (nType == 1)
    {
        D2MonSoundsTxt* pMonSoundsTxtRecord = UNITSND_GetMonSoundsRecord(pUnit);
        if (!pMonSoundsTxtRecord)
            return;
        SOUNDHDR_AddVariantRefs(pMonSoundsTxtRecord->dwAttack1, nDelta);
        SOUNDHDR_AddVariantRefs(pMonSoundsTxtRecord->dwWeapon1, nDelta);
        SOUNDHDR_AddVariantRefs(pMonSoundsTxtRecord->dwHitSound, nDelta);
        SOUNDHDR_AddVariantRefs(pMonSoundsTxtRecord->dwDeathSound, nDelta);
        SOUNDHDR_AddVariantRefs(pMonSoundsTxtRecord->dwFlee, nDelta);
        SOUNDHDR_AddVariantRefs(pMonSoundsTxtRecord->dwFootstepLayer, nDelta);
    }
    else if (nType == 2)
    {
        const unsigned int nClass = UNITSND_GetUnitSndClassId(pUnit);
        D2_ASSERT(nClass < 0x23D, 0x1213);
        D2UnitSndObjectStrc* pRecord = gapUnitSndObjects[nClass];
        if (pRecord)
        {
            for (int i = 0; i < 8; ++i)
                SOUNDHDR_AddVariantRefs(pRecord->nModeSound[i], nDelta);
        }
    }
}

// 0x004CC380
void __fastcall UNITSND_PlayInitSound(D2UnitStrc* pUnit)
{
    if (UNITSND_GetUnitSndType(pUnit) != 1)
        return;

    const unsigned int nTick = sub_0044DB00();
    D2MonSoundsTxt* pMonSoundsTxtRecord = UNITSND_GetMonSoundsRecord(pUnit);
    if (!pMonSoundsTxtRecord)
        return;

    const int nInit = pMonSoundsTxtRecord->dwInit;
    if (nInit && !CUNIT_IsDeadOrDying(pUnit) && !UNITSND_ReadAsyncSoundTick(pUnit))
    {
        sub_004B9A00(nInit, pUnit, 0, 0, 0);
        gnNeutralTick = nTick;
        UNITSND_WriteAsyncSoundTick(pUnit, nTick);
        gnNeutralDelay = SKILLDESC_RandomInRange(0x1E, 0x5A);
        return;
    }

    const int nMode = UNITSND_GetUnitSndMode(pUnit);
    if (nMode == 8)
        UNITSND_PlaySkillSound(pUnit, nMode);
}

// 0x004CC410
static void __stdcall UNITSND_PlayHitSound(D2UnitStrc* pUnit, int nMode)
{
    const int nType = UNITSND_GetUnitSndType(pUnit);
    const int nHitClass = pUnit->dwLastHitClass;
    if (nType == 1 && STATES_CheckState(pUnit, STATE_INVIS))
        return;

    int nSound1;
    int nSound2;
    UNITSND_GetHitSounds(pUnit, nHitClass, nMode, &nSound1, &nSound2);
    const int hSound = sub_004B9A00(nSound1, pUnit, 0, 0, 0);
    sub_004B9A00(nSound2, pUnit, 0, 0, 0);
    if (hSound && pUnit == sub_00463DD0_GetPlayerUnit())
        SOUNDINST_SetValue(hSound, 0xFF);

    if (nType == 1 && !nMode)
    {
        UNITSND_ReleaseMonsterSfx(pUnit);
        UNITSND_AddUnitSoundRefs(pUnit, -1);
    }

    if (STATES_CheckState(pUnit, STATE_FREEZE))
        return;
    if ((nHitClass & 0xF0) == 0xA0)
        return;

    if (nType == 1)
    {
        D2MonSoundsTxt* pMonSoundsTxtRecord = UNITSND_GetMonSoundsRecord(pUnit);
        if (pMonSoundsTxtRecord)
        {
            int nSound;
            int nDelay;
            if (nMode == 3 || nMode == 0xD)
            {
                if (SOUNDINST_HasUnitSound(pUnit))
                    goto done;
                nSound = pMonSoundsTxtRecord->dwHitSound;
                nDelay = pMonSoundsTxtRecord->dwHitDelay;
            }
            else
            {
                nSound = pMonSoundsTxtRecord->dwDeathSound;
                nDelay = pMonSoundsTxtRecord->dwDeaDelay;
            }

            if (nSound)
                sub_004B9A00(nSound, pUnit, nDelay, 0, 0);
            if (nSound == 0x2E9)
            {
                sub_004B9A00(nSound + 1, pUnit, 0x6A, 0, 0);
                sub_004B9A00(nSound + 2, pUnit, 0xC1, 0, 0);
            }
        }
    }
    else if (nType == 0)
    {
        D2UnitSndPlayerStrc* pRecord = UNITSND_GetPlayerSoundRecord(UNITSND_GetUnitSndClassId(pUnit));
        if (pRecord)
        {
            int nSound;
            int nArg;
            if (nMode == 4 || nMode == 0x13)
            {
                if (SOUNDINST_HasUnitSound(pUnit))
                    goto done;
                nSound = pRecord->f_0;
                nArg = 2;
            }
            else
            {
                nSound = pRecord->nDeathSound;
                nArg = 1;
            }

            if (nSound)
                sub_004B9A00(nSound, pUnit, nArg, 0, 0);
        }
    }

done:
    pUnit->dwSfxTicks = sub_0044DB00();
    gnSfxTick = sub_0044DB00();
}

// 0x004CA870
static inline D2TimedHintNodeStrc** UNITSND_GetUnitHintList(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0xC2C);
    return (D2TimedHintNodeStrc**)&pUnit->pUnitSfxData;
}

D2TimedHintNodeStrc** __stdcall sub_M121_Emit_004CA870(D2UnitStrc* pUnit) { return UNITSND_GetUnitHintList(pUnit); }

// 0x004CAA70
static inline int UNITSND_GetUnitSfxFlag(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0xC8F);
    return pUnit->bUnitSfx;
}

int __stdcall sub_M121_Emit_004CAA70(D2UnitStrc* pUnit) { return UNITSND_GetUnitSfxFlag(pUnit); }

// 0x004CAC00
static inline int UNITSND_GetSfxStepTicks(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0xCE7);
    return pUnit->dwSfxStepTicks;
}

int __stdcall sub_M121_Emit_004CAC00(D2UnitStrc* pUnit) { return UNITSND_GetSfxStepTicks(pUnit); }

// 0x004CAC70
static inline int UNITSND_HasActiveSound(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0xCFD);
    return pUnit->bHasActiveSound;
}

int __stdcall sub_M121_Emit_004CAC70(D2UnitStrc* pUnit) { return UNITSND_HasActiveSound(pUnit); }

// 0x004CA900
void* __fastcall UNITSND_FindUnitSfxInRange(D2UnitStrc* pUnit, int nId)
{
    D2_ASSERT(pUnit, 0xC47);
    if (!sub_004DF880())
    {
        return 0;
    }

    int nGroup = SOUNDHDR_GetGroupStart(nId);
    int nCount = SOUNDHDR_GetGroupSize(nGroup);
    for (D2UnitSfxNodeStrc* pNode = (D2UnitSfxNodeStrc*)pUnit->pUnitSfxData; pNode; pNode = pNode->pNext)
    {
        void* pUnitSfx = pNode->pUnitSfx;
        int nHintId = SOUNDINST_GetSoundIdByHandle((int)pUnitSfx);
        if (nHintId >= nGroup && nHintId < nGroup + nCount)
        {
            return pUnitSfx;
        }
    }

    return 0;
}

// 0x004CA990
void* __fastcall UNITSND_GetLinkFirst(D2UnitStrc* pUnit)
{
    D2_ASSERT(pUnit, 0xC63);
    D2UnitSfxNodeStrc* pNode = (D2UnitSfxNodeStrc*)pUnit->pUnitSfxData;
    if (pNode)
    {
        return pNode->pUnitSfx;
    }

    return 0;
}

// 0x004CC270
void __cdecl UNITSND_CheckLevelSpeech()
{
    D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
    if (!pRoom)
    {
        return;
    }

    int nLevelId = DUNGEON_GetLevelIdFromRoom(pRoom);
    if (nLevelId >= sgptDataTables->nLevelsTxtRecordCount || nLevelId == gnLastLevelId)
    {
        return;
    }

    gnLastLevelId = nLevelId;
    if (gaLevelVisited[nLevelId])
    {
        return;
    }

    D2LevelSpeechStrc* pEntry;
    for (int i = 0; i < 20; ++i)
    {
        pEntry = gapLevelSpeeches[i];
        if (!pEntry)
        {
            return;
        }

        for (int j = 0; j < 10; ++j)
        {
            int nLevel = pEntry->nLevels[j];
            if (!nLevel)
            {
                break;
            }

            if (nLevel == nLevelId)
            {
                goto found;
            }
        }
    }

    return;

found:
    for (int j = 0; j < 10; ++j)
    {
        int nLevel = pEntry->nLevels[j];
        if (!nLevel)
        {
            break;
        }

        gaLevelVisited[nLevel] = 1;
    }

    if (pEntry->nCondition && !TEXT_TestQuestCondition(pEntry->nCondition))
    {
        return;
    }

    D2_ASSERT(pPlayer, 0xCBB);
    unsigned int dwSfxTicks = pPlayer->dwSfxTicks;
    if (sub_0044DB00() - dwSfxTicks <= 0x3E)
    {
        return;
    }

    if (SOUNDINST_IsSpeechPlaying())
    {
        return;
    }

    UNITSND_PlayPlayerSpeech(pPlayer, pEntry->f_2C);
}

#include "gen/data/Source/D2Client/UNIT/UnitSnd.inc"
