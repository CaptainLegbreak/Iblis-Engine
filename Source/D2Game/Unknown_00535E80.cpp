#include "D2Game.h"
#include "D2UnitData.h"

// 0x00535E80
extern "C" __declspec(dllexport) unsigned int __fastcall sub_00535E80(D2UnitStrc* pUnit) {
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData) {
        return (unsigned int)pUnit->pMonsterData->pMonInteract;
    }
    return 0;
}
