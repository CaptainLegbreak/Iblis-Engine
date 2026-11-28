#include "D2Game.h"
#include "D2UnitData.h"

// 0x0055B7E0
extern "C" __declspec(dllexport) unsigned int __fastcall sub_0055B7E0(D2UnitStrc* pUnit) {
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData) {
        return (unsigned int)pUnit->pMonsterData->pMonstatsTxt;
    }
    return 0;
}
