#include "D2LanguageNames.h"
#include "D2StatIds.h"
#include "D2Client.h"
#include "D2ClientFuncs.h"
#include "D2Structs.h"
#include "D2ClientGame.h"
#include "D2Unicode.h"
#include "D2ClientUi.h"
#include "D2StormTypes.h"
#include "D2Path.h"
#include "D2ClientSound.h"
#include "D2ClientDialogWidget.h"
#include "D2SoundEnvironTxt.h"
#include "FogApi.h"
#include "D2CommonApi.h"
#include "D2SoundApi.h"

extern "C" const char gszEmptyAssertText;                                                                   // 0x006CC837



extern "C" __declspec(noreturn) void __cdecl exit(int nCode);                                               // 0x00681E09

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt("", sub_00408090(), line); exit(-1); }

int __fastcall sub_004DF900_GetSoundPosition(void* pSound);                                                 // 0x004DF900

void __fastcall SOUNDINST_ArmHint(int nKey, int nGroup, int nOffset, unsigned int nCount);               // 0x004B9EF0



extern "C" { int gnSoundSerial; }                                                                  // 0x007C5460




#pragma pack(push, 1)

struct D2ClientSoundStrc
{
    int bActive;
    int nSoundId;
    int nHandle;
    D2SoundVecStrc vPos;
    float fDistance;
    int nVolume;
    float fPan;
    int nArg4;
    D2SoundUnitNodeStrc* pUnitList;
    void* pStream;
    int nType;
    unsigned int dwStartTick;
    int nArg3;
    unsigned char nPriority;
    int bLocked;
    int nRestart;
    int bFading;
    int nFadeFrom;
    int nFadeTo;
    unsigned int dwFadeStart;
    unsigned int dwFadeEnd;
};

#pragma pack(pop)




unsigned int __cdecl DLIGHTMAP_GetSoundTick(); // 0x00481820






D2ClientSoundStrc* __stdcall SOUNDINST_FindOldestEntry(int nGroup, D2UnitStrc* pUnit, D2ClientSoundStrc* pExclude); // 0x004B9690

void __fastcall UNITSND_RemoveUnitHint(D2UnitStrc* pUnit, int nHandle); // 0x004CA8D0

void __fastcall sub_004DFC20(void* pStream); // 0x004DFC20

void* __fastcall sub_004E01B0(D2ClientSoundStrc* pSound); // 0x004E01B0

extern "C" int __fastcall SKILLDESC_RandomInRange(int nMin, int nMax); // 0x004E4100


void __fastcall D2SOUNDUTIL_ListAddHead(void* ppList, void* pData); // 0x00516950

void __fastcall D2SOUNDUTIL_ListRemove(void* ppList, void* pData); // 0x00516980

int __fastcall D2SOUNDUTIL_ListContains(D2SoundUnitNodeStrc* pList, D2UnitStrc* pUnit); // 0x005169D0

void __fastcall D2SOUNDUTIL_ListFree(void* ppList); // 0x00516A10


extern int gnSfxVolume; // 0x00727564

extern int gnEnvVolume; // 0x00727568


static D2SoundNodeStrc* gpSoundList_007C5458; // 0x007C5458

int gbClientSoundReady;        // 0x007C545C

unsigned int gdwLastVolumeTick;        // 0x007C5464

extern int gbRandomSoundTest; // 0x007C5468

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);                                // 0x00681EF0

D2ClientSoundStrc gaHintEntries[200];                                                           // 0x007C0ED0

int gbRandomSoundTest; // 0x007C5468

struct D2TimedHintEntryStrc
{
    int unk0x00;
    int nHintId;
    int nKey;
    char unk0x0C[0x20];
    void* pSound;
    int nState;
};

extern D2TimedHintNodeStrc* gpClientSoundList; // 0x007C5458

int __fastcall sub_004DFA40_IsSoundPlaying(void* pSound);                                                   // 0x004DFA40

// 0x004B93F0
D2ClientSoundStrc* __cdecl SOUNDINST_AllocSoundEntry()
{
    for (int i = 0; i < 200; ++i)
    {
        D2ClientSoundStrc* pEntry = &gaHintEntries[i];
        if (!pEntry->bActive)
        {
            memset(pEntry, 0, sizeof(D2ClientSoundStrc));
            pEntry->bActive = 1;
            D2SOUNDUTIL_ListAddHead(&gpSoundList_007C5458, pEntry);
            gnSoundSerial += 1;
            pEntry->nHandle = gnSoundSerial;
            return pEntry;
        }
    }

    return 0;
}

// 0x004B9440
D2ClientSoundStrc* __fastcall SOUNDINST_FindSoundByHandle(int nHandle)
{
    if (nHandle)
    {
        for (D2SoundNodeStrc* pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
        {
            D2ClientSoundStrc* pSound = pNode->pSound;
            if (pSound->nHandle == nHandle)
            {
                return pSound;
            }
        }
    }
    return 0;
}

// 0x004B9470
static inline void SOUNDINST_ReleaseUnits(D2ClientSoundStrc* pSound)
{
    for (D2SoundUnitNodeStrc* pNode = pSound->pUnitList; pNode; pNode = pNode->pNext)
    {
        UNITSND_RemoveUnitHint(pNode->pUnit, pSound->nHandle);
    }
    D2SOUNDUTIL_ListFree(&pSound->pUnitList);
}

// 0x004B94A0
static inline void SOUNDINST_StopStream(D2ClientSoundStrc* pSound)
{
    if (pSound->nType == 1)
    {
        sub_004DF7B0(pSound->pStream);
    }
    D2_ASSERT(!pSound->pStream, 0x93);
}

// 0x004B9560
int __fastcall SOUNDINST_HasSoundHandle(int nHandle)
{
    return SOUNDINST_FindSoundByHandle(nHandle) != 0;
}

// 0x004B9590
// noinline: 0x004B95C0 calls this out of line in the original image (call 0x4B9590 at +0x29); without it the
// compiler expands it into 0x004B95C0.
__declspec(noinline) int __fastcall SOUNDINST_IsTypeOneSound(int nKey)
{
    if (nKey)
    {
        for (D2SoundNodeStrc* pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
        {
            D2ClientSoundStrc* pEntry = pNode->pSound;
            if (pEntry->nHandle == nKey)
            {
                return pEntry->nType == 1;
            }
        }
    }
    return 0;
}

// 0x004B95C0
int __fastcall SOUNDINST_IsHintPlaying(int nKey)
{
    if (nKey)
    {
        for (D2TimedHintNodeStrc* pNode = gpClientSoundList; pNode; pNode = pNode->pNext)
        {
            D2TimedHintEntryStrc* pEntry = pNode->pEntry;
            if (pEntry->nKey == nKey)
            {
                void* pSound = pEntry->pSound;
                if (pSound && SOUNDINST_IsTypeOneSound(nKey) && sub_004DFA40_IsSoundPlaying(pSound))
                {
                    return 1;
                }

                break;
            }
        }
    }

    return 0;
}

// 0x004B9610
void* __fastcall SOUNDINST_FindSoundHandle(int nHintId)
{
    for (D2SoundNodeStrc* pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2ClientSoundStrc* pEntry = pNode->pSound;
        if (pEntry->nSoundId == nHintId)
        {
            return (void*)pEntry->nHandle;
        }
    }
    return 0;
}

// 0x004B9640
int __fastcall VIEW_CountHintsForOwner(int nOwnerId)
{
    int nCount = 0;
    for (D2TimedHintNodeStrc* pNode = gpClientSoundList; pNode; pNode = pNode->pNext)
    {
        D2TimedHintEntryStrc* pEntry = pNode->pEntry;
        if (SOUNDHDR_GetSoundRecord(pEntry->nHintId)->nGroupStart == nOwnerId && pEntry->nState == 1)
            nCount += 1;
    }
    return nCount;
}


// 0x004B9690
D2ClientSoundStrc* __stdcall SOUNDINST_FindOldestEntry(int nGroup, D2UnitStrc* pUnit, D2ClientSoundStrc* pExclude)
{
    D2ClientSoundStrc* pOldest = 0;
    D2SoundNodeStrc* pNode = gpSoundList_007C5458;
    if (gpSoundList_007C5458)
    {
        for (; pNode; pNode = pNode->pNext)
        {
            D2ClientSoundStrc* pEntry = pNode->pSound;
            if (SOUNDHDR_GetSoundRecord(pEntry->nSoundId)->nGroupStart == nGroup && pEntry != pExclude && pEntry->nType == 1
                && (!pUnit || D2SOUNDUTIL_ListContains(pEntry->pUnitList, pUnit)) && (!pOldest || pEntry->dwStartTick < pOldest->dwStartTick))
            {
                pOldest = pEntry;
            }
        }
    }

    return pOldest;
}

// 0x004B9760
static D2ClientSoundStrc* __stdcall SOUNDINST_FindGroupSound(D2ClientSoundStrc* pExclude, int nSoundId)
{
    D2SoundsTxt* pTxt = SOUNDHDR_GetSoundRecord(nSoundId);
    for (D2SoundNodeStrc* pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2ClientSoundStrc* pSound = pNode->pSound;
        if (SOUNDHDR_GetGroupStart(pSound->nSoundId) == pTxt->nGroupStart && pSound != pExclude && !pSound->bLocked)
        {
            if (pTxt->nCompound < 0 || DLIGHTMAP_GetSoundTick() - pSound->dwStartTick <= pTxt->nCompound)
                return pSound;
        }
    }
    return NULL;
}

// 0x004B98F0
static void SOUNDINST_SetSoundPosition(D2ClientSoundStrc* pSound, D2SoundVecStrc* pPos)
{
    D2_ASSERT(pSound && pPos, 0x1A6);

    pSound->vPos = *pPos;
    const float fX = sub_004B93A0_ClampFloat(pPos->fX, -2000.0f, 2000.0f);
    const float fY = sub_004B93A0_ClampFloat(pPos->fY, -2000.0f, 2000.0f);
    pSound->fDistance = GFXUTIL_VectorLengthSquared(fX, fY);
}

// 0x004B99A0
void __fastcall SOUNDINST_MoveSound(int nHandle, int nX, int nY, int nZ)
{
    if (!nHandle)
        return;

    for (D2SoundNodeStrc* pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2ClientSoundStrc* pSound = pNode->pSound;
        if (pSound->nHandle == nHandle)
        {
            D2SoundVecStrc tPos;
            tPos.fX = (float)nX;
            tPos.fY = (float)nY;
            tPos.fZ = (float)(nZ + 640.0);
            SOUNDINST_SetSoundPosition(pSound, &tPos);
            return;
        }
    }
}

struct D2DialogWidgetNodeStrc;


// 0x004B97D0
static void __stdcall SOUNDINST_GetSoundOffset(D2UnitStrc* pUnit, int nSoundId, D2SoundVecStrc* pPos)
{
    D2CoordStrc tPlayer;
    D2CoordStrc tUnit;
    int nX;
    int nY;

    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
    UNITS_GetClientCoords(pPlayer, &tPlayer);
    UNITS_GetClientCoords(pUnit, &tUnit);
    if (nSoundId == 0xA27)
    {
        const double dSlope = -2.0;
        const float fPX = (float)tPlayer.nX;
        const float fPY = (float)tPlayer.nY;
        const float fT = (dSlope * fPX + fPY - tUnit.nX * 0.5 - tUnit.nY) / -2.5;
        nX = (int)fT;
        const float fY = dSlope * fPX - dSlope * fT + fPY;
        nY = (int)fY;
    }
    else
    {
        nY = tUnit.nY;
        nX = tUnit.nX;
    }

    pPos->fX = (float)(nX - tPlayer.nX);
    pPos->fZ = 640.0f;
    pPos->fY = (float)(nY - tPlayer.nY) * 2.0f;
}

// 0x004B9890
static float __stdcall SOUNDINST_GetSoundPan(D2UnitStrc* pUnit, int nSoundId)
{
    D2SoundsTxt* pTxt = SOUNDHDR_GetSoundRecord(nSoundId);
    if (pTxt)
    {
        if (pTxt->nFalloff == 4)
            return 0.0f;

        if (pTxt->nGroupStart == 0xCA)
        {
            D2SoundEnvironTxtStrc* pEnviron = SOUNDHDR_GetSoundEnvironTxtRecord(UNITMODE_GetPlayerSoundEnviron());
            if (pEnviron && pEnviron->bIndoors)
                return 0.5f;

            return 0.0f;
        }
    }

    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
    if (UNITS_TestCollisionWithUnit(pPlayer, pUnit, 2))
        return 0.5f;

    return 0.0f;
}

// 0x004B9A00
int __fastcall SOUNDINST_PlaySound(int nSoundId, D2UnitStrc* pUnit, int nDelay, int nArg3, int nArg4)
{
    if (!gbClientSoundReady)
        return 0;

    if (nSoundId <= 0)
        return 0;

    D2SoundsTxt* pTxt = SOUNDHDR_GetSoundRecord(nSoundId);
    int nTick = DLIGHTMAP_GetSoundTick();
    if (!pTxt->nVolume)
        return 0;

    D2ClientSoundStrc* pSound = NULL;
    if (pTxt->nCompound)
        pSound = SOUNDINST_FindGroupSound(NULL, nSoundId);

    if (!pSound)
    {
        pSound = SOUNDINST_AllocSoundEntry();
        if (!pSound)
            return 0;

        pSound->nArg3 = nArg3;
        pSound->nSoundId = nSoundId;
        pSound->dwStartTick = nTick + nDelay;
        pSound->nArg4 = nArg4;
        pSound->nVolume = 0xFF;
        pSound->nPriority = pTxt->nPriority;

        D2SoundVecStrc tPos;
        if (pUnit)
        {
            SOUNDINST_GetSoundOffset(pUnit, nSoundId, &tPos);
            SOUNDINST_SetSoundPosition(pSound, &tPos);
            pSound->fPan = SOUNDINST_GetSoundPan(pUnit, nSoundId);
        }
        else
        {
            tPos.fX = 0.0f;
            tPos.fY = 0.0f;
            tPos.fZ = 320.0f;
            SOUNDINST_SetSoundPosition(pSound, &tPos);
        }
    }

    if (pUnit == CUNIT_GetPlayerUnit())
        pSound->nPriority += 0x50;

    if (pUnit)
    {
        D2SOUNDUTIL_ListAddHead(&pSound->pUnitList, pUnit);
        UNITSND_AddUnitSfx(pUnit, pSound->nHandle);
    }

    return pSound->nHandle;
}

// 0x004B9B20
int __fastcall SOUNDINST_GetValue(int nKey)
{
    if (nKey)
    {
        for (D2SoundNodeStrc* pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
        {
            D2ClientSoundStrc* pEntry = pNode->pSound;
            if (pEntry->nHandle == nKey)
            {
                return pEntry->nVolume;
            }
        }
    }
    return 0;
}

// 0x004B9B50
// noinline: 0x004B9EF0 (+0xF7) and 0x004BAAB0 (+0xCB) call this out of line in the original image; without it
// the compiler expands it into both.
__declspec(noinline) void __fastcall SOUNDINST_SetValue(int nKey, int nValue)
{
    if (!nKey)
        return;
    D2SoundNodeStrc* pLink = gpSoundList_007C5458;
    if (!pLink)
        return;
    do
    {
        D2ClientSoundStrc* pValue = pLink->pSound;
        if (pValue->nHandle == nKey)
        {
            pValue->nVolume = nValue;
            return;
        }
        pLink = pLink->pNext;
    } while (pLink);
}

// 0x004B9B80
void __fastcall SOUNDINST_StartFade(D2ClientSoundStrc* pSound, int nValue, int nBase, int nOffset)
{
    pSound->nFadeFrom = pSound->nVolume;
    pSound->nFadeTo = nValue;
    pSound->dwFadeStart = nBase;
    pSound->dwFadeEnd = nBase + nOffset;
    pSound->bFading = 1;
}

// 0x004B9BB0
static inline int SOUNDINST_GetStreamValue(D2ClientSoundStrc* pSound)
{
    return pSound->bFading;
}

// 0x004B9BE0
int __fastcall SOUNDINST_HasActiveHint(int nKey)
{
    if (nKey)
    {
        for (D2SoundNodeStrc* pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
        {
            D2ClientSoundStrc* pEntry = pNode->pSound;
            if (pEntry->nHandle == nKey)
            {
                D2SoundUnitNodeStrc* pList = pEntry->pUnitList;
                if (pList && pList->pNext)
                {
                    return 1;
                }
                break;
            }
        }
    }
    return 0;
}

// 0x004B9C20
int __cdecl SOUNDINST_IsSpeechPlaying()
{
    for (D2SoundNodeStrc* pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2ClientSoundStrc* pEntry = pNode->pSound;
        if (pEntry->nType != 2 && pEntry->nSoundId >= 0xB76 && pEntry->nSoundId <= 0x1230)
        {
            return 1;
        }
    }
    return 0;
}

// 0x004B9C60
int __cdecl SOUNDINST_IsSongPlaying()
{
    for (D2SoundNodeStrc* pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2ClientSoundStrc* pEntry = pNode->pSound;
        if (pEntry->nType != 2 && pEntry->nSoundId >= 0x1231 && pEntry->nSoundId <= 0x125A)
        {
            return 1;
        }
    }
    return 0;
}

// 0x004B9CA0
int __fastcall SOUNDINST_GetSoundIdByHandle(int nKey)
{
    if (nKey)
    {
        for (D2SoundNodeStrc* pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
        {
            D2ClientSoundStrc* pEntry = pNode->pSound;
            if (pEntry->nHandle == nKey)
            {
                return pEntry->nSoundId;
            }
        }
    }
    return 0;
}

extern "C" int gbClientSoundReady; // 0x007C545C

extern "C" void __cdecl SKILLDESC_ResetEnvironSounds(); // 0x004E4280

// 0x004B9CD0
void __fastcall SOUNDINST_SetEntryByte(int nId, unsigned char nValue)
{
    if (!nId)
    {
        return;
    }
    for (D2SoundNodeStrc* pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2ClientSoundStrc* pEntry = pNode->pSound;
        if (pEntry->nHandle == nId)
        {
            pEntry->nPriority = nValue;
            return;
        }
    }
}

// 0x004B9D00
extern "C" void __cdecl SOUNDINST_ResetSoundState()
{
    gbClientSoundReady = 1;
    gnSoundSerial = 0;
    SKILLDESC_ResetEnvironSounds();
}

// 0x004B94E0
static void SOUNDINST_FreeSound(D2ClientSoundStrc* pSound)
{
    if (!pSound)
        return;

    D2SOUNDUTIL_ListRemove(&gpSoundList_007C5458, pSound);
    SOUNDINST_ReleaseUnits(pSound);
    SOUNDINST_StopStream(pSound);
    pSound->bActive = 0;
}

// 0x004B9D20
void __cdecl SOUNDINST_FreeAllSounds()
{
    SKILLDESC_ResetEnvironSounds();
    while (gpSoundList_007C5458)
        SOUNDINST_FreeSound(gpSoundList_007C5458->pSound);

    gbClientSoundReady = 1;
}

// 0x004B9D50
int __fastcall SOUNDINST_GetPosition(int nKey)
{
    if (nKey)
    {
        for (D2SoundNodeStrc* pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
        {
            D2ClientSoundStrc* pEntry = pNode->pSound;
            if (pEntry->nHandle == nKey)
            {
                D2_ASSERT(pEntry->pStream, 0x45A);
                return sub_004DF900_GetSoundPosition(pEntry->pStream);
            }
        }
    }

    return 0;
}

struct D2Vector3FStrc;

struct D2Vector3FStrc
{
    float fX;
    float fY;
    float fZ;
};

// 0x004B9DA0
int __fastcall SOUNDINST_CompareSounds(D2ClientSoundStrc* pA, D2ClientSoundStrc* pB, int bCompareFloat,
                                         int bCompareValue)
{
    if (pA->nPriority > pB->nPriority)
    {
        return 1;
    }

    if (pA->nPriority < pB->nPriority)
    {
        return 0;
    }

    if (bCompareFloat)
    {
        if (pA->fDistance < pB->fDistance)
        {
            return 1;
        }

        if (pA->fDistance > pB->fDistance)
        {
            return 0;
        }
    }

    if (bCompareValue)
    {
        if (pA->dwStartTick > pB->dwStartTick)
        {
            return 1;
        }

        if (pA->dwStartTick < pB->dwStartTick)
        {
            return 0;
        }
    }

    return pA > pB;
}

// 0x004B9E10
int __fastcall SOUNDINST_IsNearPlayer(D2UnitStrc* pUnit)
{
    D2Vector3FStrc tDelta;
    D2CoordStrc tPlayerCoords;
    D2CoordStrc tUnitCoords;
    D2UnitStrc* pPlayer = CUNIT_GetPlayerUnit();
    UNITS_GetClientCoords(pPlayer, &tPlayerCoords);
    UNITS_GetClientCoords(pUnit, &tUnitCoords);
    tDelta.fX = tUnitCoords.nX - tPlayerCoords.nX;
    tDelta.fY = (tUnitCoords.nY - tPlayerCoords.nY) * 2.0f;
    if (GFXUTIL_VectorLengthSquared(tDelta.fX, tDelta.fY) <= 490000.0)
    {
        return 1;
    }

    return 0;
}

// 0x004B9700
static D2ClientSoundStrc* __stdcall SOUNDINST_FindUnitSound(D2ClientSoundStrc* pExclude, D2UnitStrc* pUnit)
{
    for (D2SoundNodeStrc* pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2ClientSoundStrc* pSound = pNode->pSound;
        if (pSound != pExclude && pSound->nType == 1)
        {
            if (!pUnit || D2SOUNDUTIL_ListContains(pSound->pUnitList, pUnit))
            {
                if (pSound->nSoundId >= 0xB76 && pSound->nSoundId <= 0x1230)
                    return pSound;
            }
        }
    }
    return 0;
}

// 0x004B9E90
int __fastcall SOUNDINST_HasUnitSound(D2UnitStrc* pUnit)
{
    return SOUNDINST_FindUnitSound(0, pUnit) != 0;
}

// 0x004B9EF0
void __fastcall SOUNDINST_ArmHint(int nKey, int nGroup, int nOffset, unsigned int nCount)
{
    if (!nKey)
    {
        return;
    }
    D2SoundNodeStrc* pHead = gpSoundList_007C5458;
    D2SoundNodeStrc* pNode = pHead;
    if (!pHead)
    {
        return;
    }

    D2ClientSoundStrc* pEntry;
    for (; pNode; pNode = pNode->pNext)
    {
        pEntry = pNode->pSound;
        if (pEntry->nHandle == nKey)
        {
            break;
        }
    }
    if (!pNode)
    {
        return;
    }

    for (pNode = pHead; pNode; pNode = pNode->pNext)
    {
        D2ClientSoundStrc* pOther = pNode->pSound;
        if (pOther->nHandle == nKey)
        {
            D2SoundUnitNodeStrc* pUnitList = pOther->pUnitList;
            if (pUnitList && pUnitList->pNext)
            {
                return;
            }
            break;
        }
    }

    D2SoundsTxt* pTxt = SOUNDHDR_GetSoundRecord(pEntry->nSoundId);
    if (nGroup == 0xFF)
    {
        if (pTxt->nFadeIn > nCount)
        {
            nCount = pTxt->nFadeIn;
        }
    }
    else if (!nGroup)
    {
        if (pTxt->nFadeOut > nCount)
        {
            nCount = pTxt->nFadeOut;
        }
    }

    if (pEntry->bFading)
    {
        if (nGroup == pEntry->nFadeTo && DLIGHTMAP_GetSoundTick() + nOffset + nCount >= pEntry->dwFadeEnd)
        {
            return;
        }

        if (!pEntry->nFadeTo && nGroup)
        {
            return;
        }
    }

    if (!nGroup)
    {
        pEntry->bLocked = 1;
    }

    if (!nCount)
    {
        D2_ASSERT(!nOffset, 0x25C);
        SOUNDINST_SetValue(nKey, nGroup);
        return;
    }

    unsigned int nStart = DLIGHTMAP_GetSoundTick() + nOffset;
    pEntry->dwFadeStart = nStart;
    pEntry->nFadeFrom = pEntry->nVolume;
    pEntry->nFadeTo = nGroup;
    pEntry->dwFadeEnd = nStart + nCount;
    pEntry->bFading = 1;
}

// 0x004B9BC0
static inline int SOUNDINST_IsOnAndNotHeld(D2ClientSoundStrc* pSound)
{
    return pSound->bFading && !pSound->nFadeTo;
}

// 0x004B9EB0
void __cdecl SOUNDINST_PlayRandomSpeech()
{
    if (DLIGHTMAP_GetSoundTick() % 3 == 0)
    {
        const int nSound = SKILLDESC_RandomInRange(0xB76, 0x1230);
        SOUNDINST_PlaySound(nSound, 0, 0, 0, 0);
    }
}

int __fastcall sub_M112_Emit_004B9BB0(D2ClientSoundStrc* pSound)
{
    return SOUNDINST_GetStreamValue(pSound);
}

static int sub_004BA020_SortsBefore(D2ClientSoundStrc* pSound1, D2ClientSoundStrc* pSound2)
{
    if (pSound1->nPriority > pSound2->nPriority)
        return 1;
    if (pSound1->nPriority < pSound2->nPriority)
        return 0;
    if (pSound1->fDistance < pSound2->fDistance)
        return 1;
    if (pSound1->fDistance > pSound2->fDistance)
        return 0;
    if (pSound1->dwStartTick > pSound2->dwStartTick)
        return 1;
    if (pSound1->dwStartTick < pSound2->dwStartTick)
        return 0;
    return pSound1 > pSound2;
}

static float sub_004BA020_MinF(float a, float b)
{
    return a < b ? a : b;
}

static float sub_004BA020_MaxF(float a, float b)
{
    return a > b ? a : b;
}

// 0x004BA020
void __fastcall SOUNDINST_UpdateSounds(unsigned int nTick)
{
    if (!gbClientSoundReady)
        return;

    D2SoundNodeStrc* pFreeList = NULL;
    if (gbRandomSoundTest)
        SOUNDINST_PlayRandomSpeech();

    D2SoundNodeStrc* pNode;
    int bSorted;
    do
    {
        bSorted = 1;
        for (pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
        {
            if (pNode->pNext)
            {
                if (sub_004BA020_SortsBefore(pNode->pNext->pSound, pNode->pSound))
                {
                    D2ClientSoundStrc* pTmp = pNode->pSound;
                    pNode->pSound = pNode->pNext->pSound;
                    pNode->pNext->pSound = pTmp;
                    bSorted = 0;
                }
            }
        }
    }
    while (!bSorted);

    for (pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2ClientSoundStrc* pSound = pNode->pSound;
        if (pSound->bLocked && !SOUNDINST_IsOnAndNotHeld(pSound))
        {
            if (pSound->nType == 0)
                pSound->nType = 2;

            if (pSound->nType == 1)
            {
                sub_004DF7B0(pSound->pStream);
                D2_ASSERT(!pSound->pStream, 0x93);
            }
        }
    }

    const int bEnabled = D2SOUND_GetMasterVolumeOption() > 0;
    for (pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2ClientSoundStrc* pSound = pNode->pSound;
        D2SoundsTxt* pTxt = SOUNDHDR_GetSoundRecord(pSound->nSoundId);
        int bAudible = bEnabled;
        if (pSound->nSoundId >= SOUNDHDR_GetSongMin() && pSound->nSoundId <= SOUNDHDR_GetSongMax() && !D2SOUND_GetMusicVolumeOption())
            bAudible = 0;

        if (pSound->nType == 2)
        {
            D2_ASSERT(!pSound->pStream, 0x349);
            if (pTxt->nLoop && !pTxt->nDuration && !pSound->bLocked)
            {
                if (pSound->bFading)
                {
                    pSound->nVolume = pSound->nFadeTo;
                    pSound->bFading = 0;
                }
                pSound->nType = 0;
            }
            else
            {
                D2SOUNDUTIL_ListAddHead(&pFreeList, pSound);
            }
            continue;
        }

        if (gbPositionalSound && pTxt->bTracking && pSound->pUnitList)
        {
            D2SoundVecStrc tPos;
            D2SoundVecStrc tBest;
            tPos.fX = 0.0f;
            tPos.fY = 0.0f;
            tPos.fZ = 0.0f;
            D2UnitStrc* pBest = NULL;
            int nCount = 0;
            tBest.fX = 0.0f;
            tBest.fY = 0.0f;
            tBest.fZ = 0.0f;
            float fBestDist = -1.0f;
            float fPanSum = 0.0f;
            for (D2SoundUnitNodeStrc* pUnitNode = pSound->pUnitList; pUnitNode; pUnitNode = pUnitNode->pNext)
            {
                D2UnitStrc* pUnit = pUnitNode->pUnit;
                D2_ASSERT(pUnit, 0x36C);
                SOUNDINST_GetSoundOffset(pUnit, pSound->nSoundId, &tPos);
                const float fDist = GFXUTIL_VectorLengthSquared(tPos.fX, tPos.fY);
                if (!pBest || fDist < fBestDist)
                {
                    tBest = tPos;
                    pBest = pUnit;
                    fBestDist = fDist;
                }

                fPanSum += SOUNDINST_GetSoundPan(pUnit, pSound->nSoundId);
                ++nCount;
            }

            SOUNDINST_SetSoundPosition(pSound, &tBest);
            const float fTarget = fPanSum / nCount;
            if (fTarget > pSound->fPan)
                pSound->fPan = sub_004BA020_MinF(pSound->fPan + 0.05000000074505806, fTarget);
            else
                pSound->fPan = sub_004BA020_MaxF(pSound->fPan - 0.05000000074505806, fTarget);
        }

        if (pSound->bFading)
        {
            if (nTick > pSound->dwFadeEnd)
            {
                pSound->bFading = 0;
                pSound->nVolume = pSound->nFadeTo;
            }
            else if (nTick < pSound->dwFadeStart)
            {
                pSound->nVolume = pSound->nFadeFrom;
            }
            else
            {
                pSound->nVolume = pSound->nFadeFrom + (pSound->nFadeTo - pSound->nFadeFrom) * (int)(nTick - pSound->dwFadeStart) / (int)(pSound->dwFadeEnd - pSound->dwFadeStart);
            }
        }

        const float fRange = SOUNDHDR_GetFalloffRange(pSound->nSoundId);
        const float fRangeSq = fRange * fRange;
        if (pSound->nType == 0 && nTick >= pSound->dwStartTick && pSound->nVolume)
        {
            if (bAudible && pSound->fDistance <= fRangeSq)
            {
                D2_ASSERT(!pSound->pStream, 0x3A1);
                D2UnitStrc* pUnit = NULL;
                D2ClientSoundStrc* pOther = NULL;
                if (pSound->pUnitList && !pSound->pUnitList->pNext)
                    pUnit = pSound->pUnitList->pUnit;

                const int bHasPos = pSound->vPos.fX != 0.0f || pSound->vPos.fY != 0.0f || pSound->vPos.fZ != 0.0f;

                if (pTxt->bDeferInst || pTxt->bStopInst)
                    pOther = SOUNDINST_FindOldestEntry(pTxt->nGroupStart, pUnit, pSound);

                if (pUnit && pSound->nSoundId >= 0xB76 && pSound->nSoundId <= 0x1230)
                    pOther = SOUNDINST_FindUnitSound(pSound, pUnit);

                if (!(pTxt->bDeferInst && !pSound->pUnitList && bHasPos) && pOther)
                {
                    if (pTxt->bStopInst)
                    {
                        pOther->bLocked = 1;
                        D2SOUNDUTIL_ListAddHead(&pFreeList, pOther);
                    }
                    else
                    {
                        pSound->bLocked = 1;
                        D2SOUNDUTIL_ListAddHead(&pFreeList, pSound);
                        continue;
                    }
                }

                int bRestart = 0;
                if (pSound->nRestart)
                {
                    pSound->nArg4 = pSound->nRestart;
                    pSound->nRestart = 0;
                    bRestart = 1;
                }

                int nVolume = 0;
                int nFade = 0;
                if (bRestart)
                {
                    nFade = 3;
                    nVolume = pSound->nVolume;
                    pSound->nVolume = 0;
                }
                else if (pTxt->nFadeIn && !pSound->bFading && !(pSound->nArg3 & 2))
                {
                    nFade = pTxt->nFadeIn;
                    nVolume = pSound->nVolume;
                    pSound->nVolume = 0;
                }

                pSound->pStream = sub_004E01B0(pSound);
                if (pSound->pStream)
                {
                    pSound->nType = 1;
                    if (nFade)
                    {
                        pSound->nFadeFrom = pSound->nVolume;
                        pSound->nFadeTo = nVolume;
                        pSound->dwFadeStart = nTick;
                        pSound->dwFadeEnd = nTick + nFade;
                        pSound->bFading = 1;
                    }
                }

                pTxt = SOUNDHDR_GetSoundRecord(pSound->nSoundId);
            }

            if (!pSound->pStream && !pTxt->nLoop && (!pTxt->bAsyncOnly || pTxt->nState != 1))
                D2SOUNDUTIL_ListAddHead(&pFreeList, pSound);
        }

        if (pSound->nType == 1)
        {
            D2_ASSERT(pSound->pStream, 0x3F3);
            if ((!pTxt->nDuration || nTick - pSound->dwStartTick <= pTxt->nDuration) && bAudible && !(pSound->fDistance > fRangeSq))
            {
                sub_004DFC20(pSound->pStream);
                if (pTxt->nState == 2)
                    SOUNDHDR_TouchCacheEntry(pSound->nSoundId);
            }
            else
            {
                sub_004DF7B0(pSound->pStream);
                D2_ASSERT(!pSound->pStream, 0x93);
            }
        }
    }

    for (D2SoundNodeStrc* pFree = pFreeList; pFree; pFree = pFree->pNext)
        SOUNDINST_FreeSound(pFree->pSound);

    D2SOUNDUTIL_ListFree(&pFreeList);

    int bPanel;
    if ((!GAME_GetConnectionType() || GAME_GetConnectionType() == 1) && (UI_GetUIVarUnchecked(9) || UI_GetUIVarUnchecked(11)))
        bPanel = 1;
    else
        bPanel = 0;

    int bDuck = 0;
    for (pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2ClientSoundStrc* pSound = pNode->pSound;
        if (SOUNDHDR_GetSoundRecord(pSound->nSoundId)->bSolo && !SOUNDINST_IsOnAndNotHeld(pSound))
        {
            bDuck = 1;
            break;
        }
    }

    if (nTick > gdwLastVolumeTick)
    {
        if (bPanel)
        {
            const int n = gnSfxVolume - 5;
            gnSfxVolume = n < 0 ? 0 : n;
        }
        else
        {
            const int n = gnSfxVolume + 5;
            gnSfxVolume = n > 100 ? 100 : n;
        }

        if (bDuck)
        {
            const int n = gnEnvVolume - 2;
            gnEnvVolume = n < 70 ? 70 : n;
        }
        else
        {
            const int n = gnEnvVolume + 2;
            gnEnvVolume = n > 100 ? 100 : n;
        }
    }

    gdwLastVolumeTick = nTick;
}

// 0x004BA760
// noinline: the original calls this; without it the compiler expands it into 0x004BA790.
static __declspec(noinline) void SOUNDINST_RefreshHint(D2ClientSoundStrc* pSound)
{
    D2SoundsTxt* pTxt = SOUNDHDR_GetSoundRecord(pSound->nSoundId);
    pSound->bLocked = 1;
    unsigned char nCount = pTxt->nFadeOut;
    if (nCount && pSound->nType == 1)
    {
        SOUNDINST_ArmHint(pSound->nHandle, 0, 0, nCount);
    }
}

// 0x004BA790
void __fastcall SOUNDINST_UpdateUnitHint(D2UnitStrc* pUnit, D2UnitStrc* pOther, int bForce)
{
    D2_ASSERT(pUnit && pOther, 0xCE);
    UNITSND_RemoveUnitHint(pOther, (int)pUnit);
    D2SoundNodeStrc* pNode;
    D2ClientSoundStrc* pSound;
    for (pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
    {
        pSound = pNode->pSound;
        if (pSound->nHandle == (int)pUnit)
            break;
    }
    if (!pNode)
        return;
    D2SoundsTxt* pTxt = SOUNDHDR_GetSoundRecord(pSound->nSoundId);
    D2SOUNDUTIL_ListRemove(&pSound->pUnitList, pOther);
    const int bReady = !pTxt->nLoop || (pSound->bFading && !pSound->nFadeTo) ? 1 : 0;
    if (pSound->pUnitList)
        return;
    if (!bForce && bReady)
        return;
    SOUNDINST_RefreshHint(pSound);
}

// 0x004BA840
void __fastcall SOUNDINST_StopSound(int nHandle)
{
    if (nHandle)
    {
        for (D2SoundNodeStrc* pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
        {
            D2ClientSoundStrc* pEntry = pNode->pSound;
            if (pEntry->nHandle == nHandle)
            {
                D2SoundsTxt* pTxt = SOUNDHDR_GetSoundRecord(pEntry->nSoundId);
                pEntry->bLocked = 1;
                unsigned char nCount = pTxt->nFadeOut;
                if (nCount && pEntry->nType == 1)
                {
                    SOUNDINST_ArmHint(pEntry->nHandle, 0, 0, nCount);
                }

                return;
            }
        }
    }
}

// 0x004BA890
void __fastcall SOUNDINST_LockSoundsById(int nHintId)
{
    for (D2SoundNodeStrc* pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2ClientSoundStrc* pEntry = pNode->pSound;
        if (pEntry->nSoundId == nHintId)
        {
            D2SoundsTxt* pTxt = SOUNDHDR_GetSoundRecord(pEntry->nSoundId);
            pEntry->bLocked = 1;
            unsigned char nCount = pTxt->nFadeOut;
            if (nCount && pEntry->nType == 1)
            {
                SOUNDINST_ArmHint(pEntry->nHandle, 0, 0, nCount);
            }
        }
    }
}

// 0x004BA8F0
void __cdecl SOUNDINST_StopSongs()
{
    D2SoundNodeStrc* pNode = gpSoundList_007C5458;
    if (!gpSoundList_007C5458)
    {
        return;
    }

    for (; pNode; pNode = pNode->pNext)
    {
        D2ClientSoundStrc* pEntry = pNode->pSound;
        if (pEntry->nSoundId >= SOUNDHDR_GetSongMin() && pEntry->nSoundId <= SOUNDHDR_GetSongMax())
        {
            D2SoundsTxt* pTxt = SOUNDHDR_GetSoundRecord(pEntry->nSoundId);
            pEntry->bLocked = 1;
            unsigned char nCount = pTxt->nFadeOut;
            if (nCount && pEntry->nType == 1)
            {
                SOUNDINST_ArmHint(pEntry->nHandle, 0, 0, nCount);
            }
        }
    }
}

// 0x004BA950
void __fastcall SOUNDINST_RefreshHintsInRangeA(int nGroupA, int nGroupB)
{
    D2SoundNodeStrc* pNode = gpSoundList_007C5458;
    if (!gpSoundList_007C5458)
    {
        return;
    }

    for (; pNode; pNode = pNode->pNext)
    {
        D2ClientSoundStrc* pEntry = pNode->pSound;
        if (SOUNDHDR_GetGroupStart(pEntry->nSoundId) != nGroupA && SOUNDHDR_GetGroupStart(pEntry->nSoundId) != nGroupB
            && pEntry->nSoundId >= 0x34 && pEntry->nSoundId <= 0x47)
        {
            D2SoundsTxt* pTxt = SOUNDHDR_GetSoundRecord(pEntry->nSoundId);
            pEntry->bLocked = 1;
            unsigned char nCount = pTxt->nFadeOut;
            if (nCount && pEntry->nType == 1)
            {
                SOUNDINST_ArmHint(pEntry->nHandle, 0, 0, nCount);
            }
        }
    }
}

// 0x004BA9D0
void __fastcall SOUNDINST_RefreshHintsInRangeB(int nGroupA, int nGroupB)
{
    D2SoundNodeStrc* pNode = gpSoundList_007C5458;
    if (!gpSoundList_007C5458)
    {
        return;
    }

    for (; pNode; pNode = pNode->pNext)
    {
        D2ClientSoundStrc* pEntry = pNode->pSound;
        if (SOUNDHDR_GetGroupStart(pEntry->nSoundId) != nGroupA && SOUNDHDR_GetGroupStart(pEntry->nSoundId) != nGroupB
            && pEntry->nSoundId >= 0x48 && pEntry->nSoundId <= 0xC9)
        {
            D2SoundsTxt* pTxt = SOUNDHDR_GetSoundRecord(pEntry->nSoundId);
            pEntry->bLocked = 1;
            unsigned char nCount = pTxt->nFadeOut;
            if (nCount && pEntry->nType == 1)
            {
                SOUNDINST_ArmHint(pEntry->nHandle, 0, 0, nCount);
            }
        }
    }
}

// 0x004BAA50
void __cdecl SOUNDINST_LockSpeechSounds()
{
    for (D2SoundNodeStrc* pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2ClientSoundStrc* pEntry = pNode->pSound;
        if (pEntry->nSoundId >= 0xB76 && pEntry->nSoundId <= 0x1230)
        {
            D2SoundsTxt* pTxt = SOUNDHDR_GetSoundRecord(pEntry->nSoundId);
            pEntry->bLocked = 1;
            unsigned char nCount = pTxt->nFadeOut;
            if (nCount && pEntry->nType == 1)
            {
                SOUNDINST_ArmHint(pEntry->nHandle, 0, 0, nCount);
            }
        }
    }
}

// 0x004BAAB0
void __cdecl SOUNDINST_RefreshGroupTimers()
{
    for (D2SoundNodeStrc* pNode = gpSoundList_007C5458; pNode; pNode = pNode->pNext)
    {
        D2ClientSoundStrc* pSound = pNode->pSound;
        D2SoundsTxt* pTxt = SOUNDHDR_GetSoundRecord(pSound->nSoundId);
        pSound->bLocked = 1;
        unsigned char nCount = pTxt->nFadeOut;
        if (nCount && pSound->nType == 1)
        {
            SOUNDINST_ArmHint(pSound->nHandle, 0, 0, nCount);
        }
    }
}

// 0x004BABC0
void __cdecl SOUNDINST_ToggleHints()
{
    gbRandomSoundTest = !gbRandomSoundTest;
    if (!gbRandomSoundTest)
    {
        SOUNDINST_LockSpeechSounds();
    }
}


extern int gnSfxVolume = 100; // 0x00727564

extern int gnEnvVolume = 100; // 0x00727568
