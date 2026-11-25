#include "D2StateIds.h"
#include "D2Client.h"
#include "D2Structs.h"
#include "D2Txt.h"




D2UnitStrc* __cdecl sub_00463DE0_GetPlayerUnit();                                                           // 0x00463DE0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit);                                               // 0x00620BB0
int __stdcall DUNGEON_GetLevelIdFromRoom(D2ActiveRoomStrc* pRoom);                                          // 0x0061A1B0
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
int __stdcall UNITS_GetPrecisionX(D2UnitStrc* pUnit);                                                       // 0x006203B0
int __stdcall UNITS_GetPrecisionY(D2UnitStrc* pUnit);                                                       // 0x00620410
D2ObjectsTxt* __stdcall DATATBLS_GetObjectsTxtRecord(int nObjectId);                                        // 0x00640E90
int __stdcall UNITS_GetAnimOrSeqMode(D2UnitStrc* pUnit);                                                    // 0x00621190
extern "C" int __cdecl PLAYER_GetScreenOffsetX();                                                          // 0x0045AFC0
extern "C" int __cdecl PLAYER_GetScreenOffsetY();                                                      // 0x0045AFD0
int __stdcall UNITS_GetClientCoordX(D2UnitStrc* pUnit);                                                     // 0x00620650
int __stdcall UNITS_GetClientCoordY(D2UnitStrc* pUnit);                                                     // 0x006206B0
D2MissilesTxt* __fastcall sub_0046ACE0(int nMissileId);                                    // 0x0046ACE0
int __fastcall GFX_DrawUnit(D2UnitStrc* pUnit, unsigned int dwColor, int nX, int nY, int nArg, int bOverlay); // 0x00471EC0
void __fastcall PLRSKILLS_CallSkillSeqDoForward(D2UnitStrc* pUnit, int nArg);                                 // 0x004D85B0
void __fastcall PLRSKILLS_CallSkillSeqDoBackward(D2UnitStrc* pUnit, int nArg);                                                  // 0x004D8650
void __fastcall PLRSKILLS_SkillSeqDoForward(D2UnitStrc* pUnit, int nArg);                                      // 0x004D8520
void __fastcall PLRSKILLS_SkillSeqDoBackward(D2UnitStrc* pUnit, int nArg);                                      // 0x004D85C0

inline int UNIT_HasFlagEx(D2UnitStrc* pUnit, unsigned int nFlag)
{
    if (!pUnit)
        return 0;
    return (pUnit->dwFlagEx & nFlag) != 0;
}

// 0x004DC710
static int sub_004DC710_UpdateUnitSightFlag(D2UnitStrc* pUnit)
{
    if (pUnit)
    {
        D2UnitStrc* pPlayer;
        switch (pUnit->dwUnitType)
        {
        case UNIT_PLAYER:
            pPlayer = sub_00463DE0_GetPlayerUnit();
            if (pPlayer == pUnit || !pUnit->dwAnimMode || pUnit->dwAnimMode == 0x11)
                goto set_flag;
            break;
        case UNIT_MONSTER:
            if (!pUnit->dwAnimMode || pUnit->dwAnimMode == 0xC)
                goto set_flag;
            pPlayer = sub_00463DE0_GetPlayerUnit();
            break;
        case UNIT_MISSILE:
        case UNIT_ITEM:
            pPlayer = sub_00463DE0_GetPlayerUnit();
            break;
        default:
            goto set_flag;
        }
        if (pPlayer)
        {
            D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pPlayer);
            if ((!pRoom || DRLG_GetLOSDrawFromLevelId(DUNGEON_GetLevelIdFromRoom(pRoom))) && UNITS_TestCollisionWithUnit(pPlayer, pUnit, 2))
            {
                pUnit->dwFlagEx &= ~0x80;
                return 0;
            }
        }
set_flag:
        pUnit->dwFlagEx |= 0x80;
    }
    return 1;
}

// 0x004DC7B0
void __fastcall sub_004DC7B0_DrawUnitByType(D2UnitStrc* pUnit, int nColor, int bForce)
{
    int nY;
    int nTempY;
    int nX;
    int bFlag;
    if (!bForce && UNIT_HasFlagEx(pUnit, 0x40000))
        return;
    if (pUnit && pUnit->dwUnitType == UNIT_PLAYER && pUnit->dwAnimMode == 0x11 && !STATES_CheckState(pUnit, STATE_PLAYERBODY))
        return;
    if (!bForce && pUnit && pUnit->dwUnitType > 0 && pUnit->dwUnitType <= 2)
    {
        if (STATES_CheckState(pUnit, STATE_ATTACHED))
            return;
        if (STATES_CheckState(pUnit, STATE_INVIS))
            return;
    }
    const int bPerspective = sub_004F51D0_IsPerspective();
    const int nPrecisionX = UNITS_GetPrecisionX(pUnit);
    const int nPrecisionY = UNITS_GetPrecisionY(pUnit);
    if (bPerspective && !sub_004F66E0_IsPrecisionOnScreen(nPrecisionX, nPrecisionY))
        return;
    if (!sub_004DC710_UpdateUnitSightFlag(pUnit))
        return;
    const int nType = !pUnit ? 6 : pUnit->dwUnitType;
    if (bPerspective)
    {
        bFlag = 0;
        if (pUnit && pUnit->dwUnitType == UNIT_OBJECT)
        {
            const int nClassId = pUnit->dwClassId;
            D2ObjectsTxt* pObjectsRecord = DATATBLS_GetObjectsTxtRecord(nClassId);
            const int nMode = UNITS_GetAnimOrSeqMode(pUnit);
            if (pObjectsRecord->nOrderFlag[nMode] == 2)
                bFlag = 1;
        }
        SCALE_ScalePerspectivePosition(nPrecisionX, nPrecisionY, 0x60, &nX, &nTempY, bFlag);
        nX += PLAYER_GetScreenOffsetX();
        nTempY += PLAYER_GetScreenOffsetY();
        nY = nTempY;
    }
    else
    {
        nX = UNITS_GetClientCoordX(pUnit);
        nY = UNITS_GetClientCoordY(pUnit);
        nTempY = nY;
    }
    bFlag = 0;
    switch (nType)
    {
    case 0:
        PLRSKILLS_SkillSeqDoForward(pUnit, nColor);
        if (GFX_DrawUnit(pUnit, nColor, nX, nTempY, 0, 1) && pUnit)
            pUnit->dwFlags |= 0x10000000;
        PLRSKILLS_SkillSeqDoBackward(pUnit, nColor);
        break;
    case 1:
        if (sub_004AE340(pUnit))
            bFlag = 1;
        PLRSKILLS_CallSkillSeqDoForward(pUnit, nColor);
        if (GFX_DrawUnit(pUnit, nColor, nX, nTempY, bFlag, 1) && pUnit)
            pUnit->dwFlags |= 0x10000000;
        PLRSKILLS_CallSkillSeqDoBackward(pUnit, nColor);
        break;
    case 3:
    {
        D2MissilesTxt* pMisTxt = sub_0046ACE0(!pUnit ? -1 : pUnit->dwClassId);
        if (!pMisTxt)
            break;
        if (GFX_DrawUnit(pUnit, nColor, nX + pMisTxt->nOffsetX, nY + pMisTxt->nOffsetY + pMisTxt->wYoffset, 0, 1) && pUnit)
            pUnit->dwFlags |= 0x10000000;
        break;
    }
    default:
        if (GFX_DrawUnit(pUnit, nColor, nX, nY, bFlag, 1) && pUnit)
            pUnit->dwFlags |= 0x10000000;
        break;
    }
    if (bPerspective)
        sub_004F6830();
}
