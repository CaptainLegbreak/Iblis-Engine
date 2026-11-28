#include "D2Game.h"
#include "D2EventTimer.h"
#include "D2UnitData.h"


#include "D2GameFuncs.h"

// 0x00541860
extern "C" __declspec(dllexport) unsigned int __fastcall sub_00541860(D2UnitStrc* pUnit) {
    if (pUnit && pUnit->dwUnitType == UNIT_MONSTER && pUnit->pMonsterData) {
        return (unsigned int)pUnit->pMonsterData->pAiControl;
    }
    return 0;
}
