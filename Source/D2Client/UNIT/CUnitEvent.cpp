#include "D2Client.h"
#include "D2Structs.h"

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
void* __fastcall sub_004DC0B0_GetUnitMemoryPool(D2UnitStrc* pUnit); // 0x004DC0B0

typedef int (__fastcall* D2CltUnitEventFn)(int nType, D2UnitStrc* pUnit, int nArg1, int nArg2, int nParam1, int nParam2);

// 0x004DC0C0
void __fastcall CUNITEVENT_FreeCltUnitEvents(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return;
    }

    D2CltUnitEventStrc* pEvent = pUnit->pCltTimerList;
    while (pEvent)
    {
        D2CltUnitEventStrc* pNext = pEvent->pNext;
        sub_0040B480(sub_004DC0B0_GetUnitMemoryPool(pUnit), pEvent, ".\\UNIT\\CUnitEvent.cpp", 0x2F, 0);
        pEvent = pNext;
    }

    pUnit->pCltTimerList = 0;
}


// 0x004DC110
D2CltUnitEventStrc* __fastcall CUNITEVENT_AddCltUnitEvent(D2UnitStrc* pUnit, int nType, int nParam1, int nParam2, int nParam3, int nParam4, int nParam5)
{
    if (!pUnit)
    {
        return 0;
    }

    D2CltUnitEventStrc* pEvent = (D2CltUnitEventStrc*)FOG_AllocPool(pUnit->pMemoryPool, sizeof(D2CltUnitEventStrc), ".\\UNIT\\CUnitEvent.cpp", 72, 0);
    memset(pEvent, 0, sizeof(D2CltUnitEventStrc));
    pEvent->nParam1 = nParam1;
    pEvent->nParam2 = nParam2;
    pEvent->nParam3 = nParam3;
    pEvent->nType = nType;
    pEvent->pNext = pUnit->pCltTimerList;
    pEvent->f_4 = nParam4;
    pEvent->f_8 = nParam5;
    if (pUnit->pCltTimerList)
    {
        pUnit->pCltTimerList->pPrevious = pEvent;
    }
    pUnit->pCltTimerList = pEvent;
    return pEvent;
}


// 0x004DC190
void __fastcall CUNITEVENT_RemoveCltUnitEvents(D2UnitStrc* pUnit, int nParam4, int nParam5)
{
    if (!pUnit)
    {
        return;
    }

    D2CltUnitEventStrc* pEvent = pUnit->pCltTimerList;
    while (pEvent)
    {
        D2CltUnitEventStrc* pNext = pEvent->pNext;
        if (pEvent->f_4 == nParam4 && pEvent->f_8 == nParam5)
        {
            if (pEvent->pPrevious)
            {
                pEvent->pPrevious->pNext = pEvent->pNext;
            }
            else
            {
                pUnit->pCltTimerList = pEvent->pNext;
            }

            if (pEvent->pNext)
            {
                pEvent->pNext->pPrevious = pEvent->pPrevious;
            }

            sub_0040B480(sub_004DC0B0_GetUnitMemoryPool(pUnit), pEvent, ".\\UNIT\\CUnitEvent.cpp", 0x80, 0);
        }

        pEvent = pNext;
    }
}

// 0x004DC210
int __fastcall CUNITEVENT_RunCltUnitEvents(int nType, D2UnitStrc* pUnit, int nArg1, int nArg2)
{
    if (!pUnit)
    {
        return 0;
    }

    int nResult = 0;
    D2CltUnitEventStrc* pEvent = pUnit->pCltTimerList;
    while (pEvent)
    {
        D2CltUnitEventStrc* pNext = pEvent->pNext;
        if (pEvent->nType == nType)
        {
            nResult = ((D2CltUnitEventFn)pEvent->nParam3)(nType, pUnit, nArg1, nArg2, pEvent->nParam1, pEvent->nParam2);
        }
        pEvent = pNext;
    }
    return nResult;
}


