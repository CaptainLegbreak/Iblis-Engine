#include "D2StateIds.h"
#include "D2Game.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2UnitData.h"
#include "D2Txt.h"
#include "D2SaveHeader.h"
#include "D2LanguageNames.h"
#include "D2CommonApi.h"

#define STAT_HITPOINTS 6
#define STAT_MANA 8
struct D2PlayerDataStrc;
struct D2SaveHeaderStrc;


extern D2DataTablesStrc* sgptDataTables; // 0x00744304
extern const int gnPlrSave2ErrorRemap[PLRSAVE2ERROR_COUNT]; // 0x006E1208
#include "D2GameFuncs.h"
#include "D2CommonApi2.h"


typedef char M195_CheckUnitFlags[(int)&((D2UnitStrc*)0)->dwFlags == 0xC4 ? 1 : -1];

typedef char M195_CheckUnitMode[(int)&((D2UnitStrc*)0)->dwAnimMode == 0x10 ? 1 : -1];

typedef char M195_CheckMonStatsFlags[(int)&((D2MonStatsTxt*)0)->nMonStatsFlags == 0x0C ? 1 : -1];

typedef char M195_CheckMissilesFlags[(int)&((D2MissilesTxt*)0)->nMissileFlags == 0x04 ? 1 : -1];

enum
{
    UNITFLAG_CANBEATTACKED = 0x00000004,
    UNITFLAG_ISVALIDTARGET = 0x00000008,
};

extern unsigned int gdwBitMasks[]; // 0x006CE268
D2MonStatsTxt* __fastcall DATATBLS_GetMonStatsTxtRecord(int nMonsterId); // 0x00451F80
int __fastcall CLIENTS_GetUnitX(D2UnitStrc* pUnit); // 0x0045ADF0
int __fastcall CLIENTS_GetUnitY(D2UnitStrc* pUnit); // 0x0045AE20
D2MissilesTxt* __fastcall sub_0046ACE0_GetMissilesTxtRecord(int nMissileId); // 0x0046ACE0

#pragma pack(push, 1)
struct d2data_006E1208_t
{
    unsigned char b0[108];
};
#pragma pack(pop)

extern "C" const struct d2data_006E1208_t gData_006E1208; // 0x006E1208

extern "C" const struct d2data_006E1208_t gData_006E1208 = {
    {
        0x00, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00,
        0x09, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
        0x18, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0x15, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00,
        0x13, 0x00, 0x00, 0x00, 0x11, 0x00, 0x00, 0x00, 0x12, 0x00, 0x00, 0x00, 0x02, 0x00, 0x00, 0x00,
        0x03, 0x00, 0x00, 0x00, 0x0B, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00,
        0x07, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00, 0x0A, 0x00, 0x00, 0x00,
        0x0E, 0x00, 0x00, 0x00, 0x1A, 0x00, 0x00, 0x00, 0x19
    }
}; // 0x006E1208
#pragma comment(linker, "/alternatename:?gnPlrSave2ErrorRemap@@3QBHB=_gData_006E1208")
struct D2SkillStrc;
struct D2UnitStrc;

static __forceinline int UNIT_HasFlag_M195(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (pUnit)
    {
        return (pUnit->dwFlags & nFlag) != 0;
    }
    return 0;
}

// 0x0056B3E0
int __fastcall SKILLS_CheckAuraTarget(D2UnitStrc* pUnit, D2UnitStrc* pTarget, unsigned int nAuraFilter)
{
    D2UnitStrc* pAttacker = pUnit;
    const int nType = pTarget ? pTarget->dwUnitType : UNIT_INVALID;

    switch (nType)
    {
    case 0:
    {
        if (!(nAuraFilter & 1))
        {
            return 0;
        }

        const int nMode = pTarget->dwAnimMode;
        if (nAuraFilter & 0x1000)
        {
            if (nMode != 0x11)
            {
                return 0;
            }
        }
        else
        {
            if (nMode == 0x11 || nMode == 0)
            {
                return 0;
            }
        }
        break;
    }
    case 1:
    {
        if (!(nAuraFilter & 2))
        {
            return 0;
        }

        const int nMode = pTarget->dwAnimMode;
        if (nAuraFilter & 0x1000)
        {
            if (nMode != 0x0C)
            {
                return 0;
            }
        }
        else
        {
            if (nMode == 0x0C || nMode == 0)
            {
                return 0;
            }
        }

        if (nAuraFilter & 4 && !MONSTERS_IsUndead(pTarget) || nAuraFilter & 0x4000 && MONSTERS_IsBoss(0, pTarget) || nAuraFilter & 0x40000 && MONSTERS_IsPrimeEvil(pTarget))
        {
            return 0;
        }
        break;
    }
    case 2:
    {
        if (!(nAuraFilter & 0x10))
        {
            return 0;
        }
        break;
    }
    case 3:
    {
        if (!(nAuraFilter & 8))
        {
            return 0;
        }

        D2MissilesTxt* pMissilesTxtRecord = sub_0046ACE0_GetMissilesTxtRecord(pTarget->dwClassId);
        if (!pMissilesTxtRecord || pMissilesTxtRecord->nMissileFlags[0] & gdwBitMasks[1])
        {
            return 0;
        }
        break;
    }
    case 4:
    {
        if (!(nAuraFilter & 0x20))
        {
            return 0;
        }
        break;
    }
    default:
        return 0;
    }

    if (nAuraFilter & 0x80 && !UNIT_HasFlag_M195(pTarget, UNITFLAG_CANBEATTACKED))
    {
        return 0;
    }

    if (nAuraFilter & 0x400 && !UNIT_HasFlag_M195(pTarget, UNITFLAG_ISVALIDTARGET))
    {
        return 0;
    }

    if (nAuraFilter & 0x100 && DUNGEON_IsRoomInTown(UNITS_GetRoom(pTarget)))
    {
        return 0;
    }

    if (nAuraFilter & 0x10000)
    {
        if (pAttacker && pAttacker->dwUnitType == UNIT_MISSILE)
        {
            D2UnitStrc* pOwner = SUNIT_GetOwner(SUNIT_GetGameFromUnit(pAttacker), pAttacker);
            if (!pOwner)
            {
                return 0;
            }

            pAttacker = pOwner;
        }

        if (!SUNIT_AreUnitsAligned(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pTarget))
        {
            return 0;
        }

        if (pTarget->dwUnitType == UNIT_MONSTER)
        {
            D2MonStatsTxt* pMonStatsTxtRecord = DATATBLS_GetMonStatsTxtRecord(pTarget->dwClassId);
            if (!pMonStatsTxtRecord || pMonStatsTxtRecord->nMonStatsFlags[1] & gdwBitMasks[0])
            {
                return 0;
            }
        }
    }

    if (nAuraFilter & 0x8000)
    {
        if (pAttacker && pAttacker->dwUnitType == UNIT_MISSILE)
        {
            D2UnitStrc* pOwner = SUNIT_GetOwner(SUNIT_GetGameFromUnit(pAttacker), pAttacker);
            if (!pOwner)
            {
                return 0;
            }

            pAttacker = pOwner;
        }

        if (!SUNIT_AreUnitsHostile(SUNIT_GetGameFromUnit(pAttacker), pAttacker, pTarget))
        {
            return 0;
        }
    }

    if (nAuraFilter & 0x20000)
    {
        if (pAttacker && pAttacker->dwUnitType == UNIT_MISSILE)
        {
            D2UnitStrc* pOwner = SUNIT_GetOwner(SUNIT_GetGameFromUnit(pAttacker), pAttacker);
            if (!pOwner)
            {
                return 0;
            }

            pAttacker = pOwner;
        }

        if (!UNITS_IsInMeleeRange(pAttacker, pTarget, 0))
        {
            return 0;
        }
    }

    if (nAuraFilter & 0x80000 && STATES_CheckState(pTarget, STATE_JUSTHIT))
    {
        return 0;
    }

    if (nAuraFilter & 0x200)
    {
        D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pAttacker);
        if (!pRoom || !UNITS_GetRoom(pTarget))
        {
            return 0;
        }

        D2CoordStrc coords;
        coords.nX = CLIENTS_GetUnitX(pAttacker);
        coords.nY = CLIENTS_GetUnitY(pAttacker);

        D2CoordStrc targetCoords;
        targetCoords.nX = CLIENTS_GetUnitX(pTarget);
        targetCoords.nY = CLIENTS_GetUnitY(pTarget);

        if (COLLISION_RayTrace(pRoom, &coords, &targetCoords, 4))
        {
            return 0;
        }
    }

    return 1;
}
