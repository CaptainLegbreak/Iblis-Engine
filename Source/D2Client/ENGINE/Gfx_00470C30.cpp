#include "D2Client.h"
#include "D2ClientGfxState.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837
extern "C" const char* __cdecl sub_00408090();                                                      // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine);                   // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" __declspec(dllimport) unsigned long __stdcall GetTickCount(void);                               // 0x006CC260

D2StateOwnerStrc* __fastcall CUNIT_GetGfxData(D2UnitStrc* pUnit);                                    // 0x00463E10
void __stdcall GFX_RemoveStateOverlay(D2UnitStrc* pUnit, D2StateNodeStrc* pNode);                      // 0x0046E040
void __fastcall GFX_AddUnitOverlay(D2UnitStrc* pUnit, int nOverlay, int nArg3, int nArg4, int nArg5, int nArg6, int nArg7, int nArg8); // 0x00470390
int __stdcall STATES_CheckState(D2UnitStrc* pUnit, int nState);                                             // 0x00639DF0
void __stdcall STATES_ToggleState(D2UnitStrc* pUnit, int nState, int bSet);                                 // 0x00639DB0

static void __stdcall GFX_RecalcStateOverlays(D2StateOwnerStrc* pOwner, D2UnitStrc* pUnit, D2StateNodeStrc* pNode); // 0x0046DF40

static void __stdcall GFX_RecalcStateOverlays(D2StateOwnerStrc* pOwner, D2UnitStrc* pUnit, D2StateNodeStrc* pNode)
{
    const int nStateId = pNode->nStateId;
    const int bHasState = STATES_CheckState(pUnit, nStateId);
    if (bHasState)
    {
        STATES_ToggleState(pUnit, nStateId, 0);
    }
    if (!sub_0063A250(pUnit))
    {
        pNode->nCurrent = 0;
        if (bHasState)
        {
            STATES_ToggleState(pUnit, nStateId, 1);
        }
    }
    if (bHasState)
    {
        STATES_ToggleState(pUnit, nStateId, 1);
    }

    for (D2StateNodeStrc* pEntry = pOwner->pFirst; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->nStateId == nStateId && pEntry->dwType == 8)
        {
            pEntry->bSelected = 0;
            pEntry->nCurrent = -1;
        }
    }

    int nNext = 0;
    int nLowest = 0;
    for (D2StateNodeStrc* pEntry = pOwner->pFirst; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->dwType == 8)
        {
            if ((!nNext || pEntry->nStateId < nNext) && pEntry->nStateId > nStateId)
            {
                nNext = pEntry->nStateId;
            }
            if (!nLowest || pEntry->nStateId < nLowest)
            {
                nLowest = pEntry->nStateId;
            }
        }
    }
    if (!nNext)
    {
        nNext = nLowest;
    }

    for (D2StateNodeStrc* pEntry = pOwner->pFirst; pEntry; pEntry = pEntry->pNext)
    {
        if (pEntry->nStateId == nNext && pEntry->dwType == 8)
        {
            pEntry->bSelected = 1;
            pEntry->nCurrent = 0;
        }
    }
}

// 0x00470C30
void __fastcall GFX_UpdateStateOverlays(D2UnitStrc* pUnit)
{
    D2StateNodeStrc* pNode;
    int nNextOverlay;
    D2StateOwnerStrc* pOwner = CUNIT_GetGfxData(pUnit);
    D2_ASSERT(pOwner, 0x2FE);

    const unsigned int dwTick = GetTickCount();
    int nOverlay;
    int nState;
    for (;;)
    {
        for (pNode = pOwner->pFirst; pNode; pNode = pNode->pNext)
        {
            if (pNode->dwStamp != dwTick)
            {
                break;
            }
        }
        if (!pNode)
        {
            return;
        }

        pNode->dwStamp = dwTick;
        int bRemove = 0;
        switch (pNode->dwType)
        {
        case 0:
            if (sub_0046DA60_GetUnitMode(pUnit) != pNode->nCurrent)
            {
                bRemove = 1;
            }
            break;

        case 2:
            if (!pNode->nCurrent)
            {
                bRemove = 1;
            }
            break;

        case 1:
            if (!pNode->nCurrent)
            {
                bRemove = 1;
            }
            --pNode->nCurrent;
            break;

        case 6:
            if (!pNode->nCurrent)
            {
                if (GetTickCount() - pNode->dwDelayStart < pNode->dwDelay)
                {
                    continue;
                }
                pNode->nCurrent = 1;
            }
            break;

        case 8:
            if (!STATES_CheckState(pUnit, pNode->nStateId))
            {
                bRemove = 1;
            }
            else if (pNode->bSelected)
            {
                if (pNode->nCurrent >= 50)
                {
                    GFX_RecalcStateOverlays(pOwner, pUnit, pNode);
                }
                else
                {
                    ++pNode->nCurrent;
                }
            }
            break;
        }

        if (bRemove)
        {
            GFX_RemoveStateOverlay(pUnit, pNode);
            continue;
        }

        pNode->nFrame += pNode->nSpeed;
        if (pNode->nFrame < pNode->nFrames)
        {
            continue;
        }

        switch (pNode->dwType)
        {
        case 5:
            pNode->nSpeed = 0;
            pNode->nFrame = pNode->nFrames - 1;
            pNode->nCurrent = 1;
            break;

        case 2:
            pNode->nCurrent = 0;
            break;

        case 4:
            nOverlay = pNode->nCurrent;
            nNextOverlay = pNode->nNextOverlay;
            GFX_RemoveStateOverlay(pUnit, pNode);
            if (nOverlay != -1)
            {
                GFX_AddUnitOverlay(pUnit, nOverlay, 3, 0, 0, 0, 0, 0);
            }
            if (nNextOverlay != -1)
            {
                GFX_AddUnitOverlay(pUnit, nNextOverlay, 3, 0, 0, 0, 0, 0);
            }
            break;

        case 9:
            nOverlay = pNode->nCurrent;
            nNextOverlay = pNode->nNextOverlay;
            nState = pNode->nNextState;
            GFX_RemoveStateOverlay(pUnit, pNode);
            if (!STATES_CheckState(pUnit, nState))
            {
                break;
            }
            if (nOverlay != -1)
            {
                GFX_AddUnitOverlay(pUnit, nOverlay, 8, 0, nState, 0, 0, 0);
            }
            if (nNextOverlay != -1)
            {
                GFX_AddUnitOverlay(pUnit, nNextOverlay, 8, 0, nState, 0, 0, 0);
            }
            break;

        case 1:
        case 3:
        case 8:
            pNode->nFrame -= pNode->nFrames;
            break;

        case 6:
            pNode->nFrame -= pNode->nFrames;
            pNode->nCurrent = 0;
            pNode->dwDelayStart = GetTickCount();
            break;

        case 7:
            GFX_RemoveStateOverlay(pUnit, pNode);
            GFX_AddUnitOverlay(pUnit, 0x8C, 4, 0, 0x8D, 0x8E, 0, 0);
            break;
        }
    }
}
