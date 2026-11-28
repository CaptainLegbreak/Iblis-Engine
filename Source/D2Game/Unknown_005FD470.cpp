#include "D2StateIds.h"
#include "D2SkillIds.h"
#include "D2Game.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2CommonApi.h"

struct D2SkillsTxt;


struct D2SkillsTxt { char unk_00[8]; unsigned char nFlags[4]; char unk_0C[0x22]; unsigned short wSrvDoFunc; char unk_30[0x20C]; };


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const unsigned int gdwBitMasks[32]; // 0x006CE268
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2ActiveRoomStrc* __fastcall sub_00463740_FindRoomAtPoint(D2ActiveRoomStrc* pRoom, int nX, int nY); // 0x00463740
#include "D2GameFuncs.h"
#include "D2CommonApi2.h"
static inline D2SkillsTxt* GetSkillsRecord(int nSkillId)
{
    if (nSkillId >= 0 && nSkillId < sgptDataTables->nSkillsTxtRecordCount)
        return &sgptDataTables->pSkillsTxt[nSkillId];
    return 0;
}

static inline int UnitHasFlag(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (!(pUnit))
    {
        return 0;
    }
    return (pUnit->dwFlags & nFlag) != 0;
}

// 0x005FD470
int __fastcall MONSTERSPAWN_CheckSkillPlacement(D2GameStrc* pGame, D2UnitStrc* pUnit, int nSkillId, D2UnitStrc* pTarget, int nX, int nY)
{
    D2SkillsTxt* pSkillsTxt = GetSkillsRecord(nSkillId);
    if (!pSkillsTxt) return 0;
    if (nSkillId == SKILL_NEST) return 0;
    if (pSkillsTxt->nFlags[0] & gdwBitMasks[0])
    {
        if (!UnitHasFlag(pTarget, 2)) return 0;
        const int nPattern = PATH_GetUnitCollisionPattern(pTarget);
        return !COLLISION_CheckAnyCollisionWithPattern(UNITS_GetRoom(pTarget), CLIENTS_GetUnitX(pTarget), CLIENTS_GetUnitY(pTarget), nPattern, 0x3C01);
    }
    if (nSkillId == SKILL_ANDRIALSPRAY) return pTarget != 0;
    if (pSkillsTxt->wSrvDoFunc != 77 && pSkillsTxt->wSrvDoFunc != 78)
    {
    if (nSkillId == SKILL_DIABPRISON)
            return MONSTERSPAWN_SpawnBonePrison(pGame, UNITS_GetRoom(pTarget), 0, 0, pTarget, 340, 1);
        if (nSkillId == SKILL_MONTELEPORT)
        {
            if (!pUnit) return 0;
            D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY);
            if (!pRoom || DUNGEON_IsRoomInTown(pRoom) || COLLISION_CheckAnyCollisionWithPattern(pRoom, nX, nY, PATH_GetUnitCollisionPattern(pUnit), 0x3C01)) return 0;
            const int nUnitX = CLIENTS_GetUnitX(pUnit);
            const int nUnitY = CLIENTS_GetUnitY(pUnit);
            return sub_00645910_TestLine(nUnitX, nUnitY, nX, nY, pRoom, 0xC01) != 0;
        }
        if (pSkillsTxt->wSrvDoFunc == 67)
        {
            if (!pUnit) return 0;
            D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY);
            if (!pRoom || DUNGEON_IsRoomInTown(pRoom)) return 0;
            const int nUnitX = CLIENTS_GetUnitX(pUnit);
            const int nUnitY = CLIENTS_GetUnitY(pUnit);
            return sub_00645910_TestLine(nUnitX, nUnitY, nX, nY, pRoom, 0xC01) != 0;
        }
        if (nSkillId == SKILL_DESERTTURRET)
        {
            if (!pUnit) return 0;
            D2ActiveRoomStrc* pRoom = sub_00463740_FindRoomAtPoint(UNITS_GetRoom(pUnit), nX, nY);
            if (!pRoom || DUNGEON_IsRoomInTown(pRoom)) return 0;
            const int nUnitX = CLIENTS_GetUnitX(pUnit);
            const int nUnitY = CLIENTS_GetUnitY(pUnit);
            return sub_00645910_TestLine(nUnitX, nUnitY, nX, nY, pRoom, 0x805) != 0;
        }
        return 1;
    }

        if (!pTarget)
        {
            return 0;
        }

        if (MONSTERS_IsDead(pUnit))
        {
            return 0;
        }
        const int nUnitX = CLIENTS_GetUnitX(pUnit);
        const int nUnitY = CLIENTS_GetUnitY(pUnit);
        const int nOldTargetX = CLIENTS_GetUnitX(pTarget);
        const int nDiffX = nOldTargetX - nUnitX;
        const int nTargetX = nOldTargetX + nDiffX;
        const int nTargetY = 2 * CLIENTS_GetUnitY(pTarget) - nUnitY;
        D2CoordStrc tCoords;
        tCoords.nX = nTargetX;
        tCoords.nY = nTargetY;
        D2ActiveRoomStrc* pRoom = COLLISION_GetFreeCoordinates(UNITS_GetRoom(pUnit), &tCoords, UNITS_GetUnitSizeX(pUnit), 0x3C01, 0);
        if (!pRoom)
            goto reflectionFailed;
        if (DUNGEON_IsRoomInTown(pRoom))
            goto reflectionFailed;
        if (COLLISION_CheckAnyCollisionWithPattern(pRoom, nTargetX, nTargetY, PATH_GetUnitCollisionPattern(pUnit), 0x3C01))
        {
reflectionFailed:
            return 0;
        }
        return sub_00645910_TestLine(nUnitX, nUnitY, nTargetX, nTargetY, pRoom, 0xC01) != 0;
    }
