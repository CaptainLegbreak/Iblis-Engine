#include "D2Client.h"
#include "D2Path.h"
#include "D2ClientUi.h"
#include "D2DrlgMaps.h"
#include "D2ClientSound.h"
#include "D2Constants.h"
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2GameTypes.h"
#include "D2Txt.h"
#include "D2SoundEnvironTxt.h"

int gnSoundRestartArg; // 0x007C8A70

long gnSoundModeSwitchLock; // 0x007C8A74

D2SlotStrc gaSlots[16]; // 0x007C8A78

int gbSoundSystemInit; // 0x007C8C78

#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

extern "C" const char gszEmptyAssertText; // 0x006CC837

extern "C" const char* __cdecl sub_00408090(); // 0x00408090

extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60

extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

void __fastcall D2SOUND_SetSoundMixerOption(int nMode); // 0x00514CA0

D2SoundStrc* __fastcall D2SOUNDSMP_CreateSound(int nType, int nArg); // 0x00515530

void __cdecl sub_004DFA60(); // 0x004DFA60

#pragma pack(push, 1)

struct D2SlotObjectStrc
{
    char unk0x00[0x04];
    int nSoundId; // 0x04
    char unk0x08[0x04];
    D2SoundPosStrc tPos; // 0x0C
    char unk0x18[0x04];
    int nVolume; // 0x1C
    float fAttenuation; // 0x20
    int nField0x24; // 0x24
    char unk0x28[0x04];
    int nField0x2C; // 0x2C
    int nField0x30; // 0x30
    unsigned int nKey; // 0x34
    unsigned char nFlags; // 0x38
    char unk0x39[0x03];
    unsigned char nPriority; // 0x3C
    int nField0x3D; // 0x3D
    unsigned int f_41; // 0x41
};

#pragma pack(pop)

int __fastcall D2SOUNDSMP_GetSoundPlayingFlag(D2SoundStrc* pSound); // 0x00515710

int __fastcall D2SOUNDSMP_IsSoundBufferPlaying(D2SoundStrc* pSound); // 0x00515740

int __fastcall D2SOUNDSMP_IsSoundStreaming(D2SoundStrc* pSound); // 0x00515C30

void __fastcall D2SOUNDSMP_DestroySound(D2SoundStrc* pSound); // 0x005160D0

struct S { int pad; int type; };

extern "C" __declspec(dllimport) long __stdcall InterlockedIncrement(long volatile* pAddend); // 0x006CC208

extern "C" __declspec(dllimport) long __stdcall InterlockedDecrement(long volatile* pAddend); // 0x006CC204

void __fastcall D2SOUNDSMP_FadeOutMasterVolume(int nTime); // 0x00515F50

struct D2StringSoundStrc
{
    int f_0;
    unsigned short nStringId;
    char unk0x06[0x02];
};

extern D2StringSoundStrc gaStringSounds[]; // 0x0072B0E0

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern D2NpcSoundStrc gaNpcSounds[];                                                               // 0x0072AE28

extern D2DrlgActStrc* gpAct;                                                                       // 0x007A0634

int __fastcall sub_004E40A0(int nRange);                                                                    // 0x004E40A0

int __cdecl sub_0044DB00();                                                                                 // 0x0044DB00

int __fastcall SOUNDINST_CompareSounds(D2SlotObjectStrc* pA, D2SlotObjectStrc* pB, int bCompareFloat, int bCompareValue); // 0x004B9DA0

void __fastcall sub_004DFC20_UpdateSoundSlot(D2SlotStrc* pSlot); // 0x004DFC20

int __fastcall D2SOUNDSMP_SetSoundData(D2SoundStrc* pSound, const void* pFile, unsigned int nSize); // 0x005155D0

int __fastcall D2SOUNDSMP_PlaySound(D2SoundStrc* pSound); // 0x005156A0

void __fastcall sub_00515A30(D2SoundStrc* pSound, int nValue); // 0x00515A30

void __fastcall sub_00515A60(D2SoundStrc* pSound, int nValue); // 0x00515A60

void __fastcall D2SOUNDSMP_SetSoundReverbMix(D2SoundStrc* pSound, float fValue); // 0x00515B40

int __fastcall D2SOUNDSMP_StartSoundStream(D2SoundStrc* pSound, const char* szFileName, int nPosition, int bLoop); // 0x00515D70

void __fastcall D2SOUNDSMP_ResetSound(D2SoundStrc* pSound); // 0x00516140

extern "C" int __cdecl memcmp(const void* pA, const void* pB, unsigned int nSize);

float __stdcall GFXUTIL_VectorLength(float fX, float fY); // 0x004E4130

int __cdecl D2SOUND_GetMasterVolumeOption(); // 0x00514CC0

int __cdecl D2SOUND_GetMusicVolumeOption(); // 0x00514CF0

int __cdecl D2SOUND_GetPositionalBiasOption(); // 0x00514D20

void __fastcall D2SOUNDSMP_SetSoundVolume(D2SoundStrc* pSound, int nVolume); // 0x005157B0

void __fastcall D2SOUNDSMP_SetSoundPan(D2SoundStrc* pSound, int nPan); // 0x00515890

void __fastcall D2SOUNDSMP_SetSoundPosition(D2SoundStrc* pSound, float x, float y, float z); // 0x00515950

void __fastcall D2SOUNDSMP_SetSoundAttenuation(D2SoundStrc* pSound, float fAttenuation); // 0x00515A90

void __fastcall D2SOUNDSMP_GetPositionalVolumePan(int* pVolume, int* pPan, float x, float y, float z); // 0x00516830

extern int gnSfxVolume_00727564; // 0x00727564

extern int gnEnvVolume_00727568; // 0x00727568

struct D2SoundEnvironStrc
{
    int nEnviron;
    float f_4;
    float fEnvDiff;
    int nRoomVol;
    int f_10;
    float f_14;
    float fDecayHF;
    int nReflect;
    float fReflectDelay;
    int f_24;
    float fRevDelay;
    float fRoomRoll;
    float fAirAbsorb;
};

extern int gnSoundEnvironId; // 0x0072ADE4

D2SoundEnvironTxtStrc* __fastcall SOUNDHDR_GetSoundEnvironTxtRecord(int nEnvironId); // 0x00481920

void __fastcall D2SOUND_SetEaxEnvironment(D2SoundEnvironStrc* pEnviron); // 0x00513C50

// 0x004DF6C0
void __fastcall GFXUTIL_ApplySoundEnviron(int nEnvironId)
{
    if (nEnvironId == gnSoundEnvironId)
    {
        return;
    }

    D2SoundEnvironTxtStrc* pTxt = SOUNDHDR_GetSoundEnvironTxtRecord(nEnvironId);
    if ((sub_00514C90_GetSoundMode() == 2 || !nEnvironId) && sub_00513B70_IsSoundEnvironEnabled())
    {
        D2SoundEnvironStrc tEnviron;
        tEnviron.nEnviron = pTxt->nEAXEnviron;
        tEnviron.f_4 = pTxt->nEAXEnvSize / 1000.0;
        tEnviron.fEnvDiff = pTxt->nEAXEnvDiff / 1000.0;
        tEnviron.nRoomVol = pTxt->nEAXRoomVol;
        tEnviron.f_10 = pTxt->nEAXRoomHF;
        tEnviron.f_14 = pTxt->nEAXDecayTime / 1000.0;
        tEnviron.fDecayHF = pTxt->nEAXDecayHF / 1000.0;
        tEnviron.nReflect = pTxt->nEAXReflect;
        tEnviron.fReflectDelay = pTxt->nEAXReflectDelay / 1000.0;
        tEnviron.f_24 = pTxt->nEAXReverb;
        tEnviron.fRevDelay = pTxt->nEAXRevDelay / 1000.0;
        tEnviron.fRoomRoll = pTxt->nEAXRoomRoll / 1000.0;
        tEnviron.fAirAbsorb = pTxt->nEAXAirAbsorb / 1000.0;
        D2SOUND_SetEaxEnvironment(&tEnviron);
    }

    gnSoundEnvironId = nEnvironId;
}

// 0x004DF770
static bool __fastcall sub_004DF770(S* p, char unused, int x) { return p->type == x; }

// 0x004DF790
void __fastcall sub_004DF790_ReleaseSlotObject(D2SlotStrc* pSlot)
{
    if (pSlot->pObject)
    {
        pSlot->pObject->nField0x30 = 2;
        pSlot->pObject->nField0x2C = 0;
        pSlot->pObject = 0;
    }
}

// 0x004DF7B0
void __fastcall sub_004DF7B0_StopSlot(D2SlotStrc* pSlot)
{
    if (pSlot->pSound)
    {
        if (pSlot->pObject)
        {
// build: symbol ?D2SOUNDSMP_GetStreamPosition@* 0x005159B0
            pSlot->pObject->f_41 = D2SOUNDSMP_GetStreamPosition(pSlot->pSound);
        }

// build: symbol ?D2SOUNDSMP_StopSound@* 0x00515EE0
        D2SOUNDSMP_StopSound(pSlot->pSound);
    }

    if (pSlot->pObject)
    {
        pSlot->pObject->nField0x30 = 2;
        pSlot->pObject->nField0x2C = 0;
        pSlot->pObject = 0;
    }
}

// 0x004DF800
void __cdecl sub_004DF800()
{
// build: symbol ?D2SOUND_GetDirectSound@* 0x00513B50
    if (!D2SOUND_GetDirectSound())
    {
        return;
    }

// build: symbol ?D2SOUNDSMP_SetMasterVolume@* 0x00515CE0
    D2SOUNDSMP_SetMasterVolume(0);
    for (int i = 0; i < 16; ++i)
    {
        sub_004DF7B0_StopSlot(&gaSlots[i]);
    }

    D2SOUNDSMP_SetMasterVolume(0xFF);
}

// 0x004DF870
int __cdecl sub_004DF870()
{
    return gbSoundSystemInit;
}

// 0x004DF880
int __cdecl sub_004DF880()
{
    return gbSoundSystemInit;
}

// 0x004DF890
void __cdecl sub_004DF890()
{
    for (int i = 0; i < 16; ++i)
    {
        D2SlotStrc* pSlot = &gaSlots[i];
        if (pSlot->pObject && !SOUNDHDR_GetSoundRecord(pSlot->pObject->nSoundId)->nLoop && !D2SOUNDSMP_GetSoundPlayingFlag(pSlot->pSound))
        {
            if (D2SOUNDSMP_IsSoundStreaming(pSlot->pSound))
            {
                sub_004DF7B0_StopSlot(pSlot);
            }

            if (pSlot->pObject)
            {
                pSlot->pObject->nField0x30 = 2;
                pSlot->pObject->nField0x2C = 0;
                pSlot->pObject = 0;
            }
        }
    }
}

// 0x004DF900
unsigned int __fastcall sub_004DF900_GetSlotSampleCount(D2SlotStrc* pSlot)
{
// build: symbol ?D2SOUNDSMP_GetStreamPosition@* 0x005159B0
    return D2SOUNDSMP_GetStreamPosition(pSlot->pSound);
}

// 0x004DF910
int __cdecl sub_004DF910_GetSoundMode()
{
    return sub_00514C90_GetSoundMode();
}

// 0x004DF920
void __cdecl sub_004DF920_Nop()
{
}

// 0x004DF930
void __cdecl sub_004DF930_Nop()
{
}

// 0x004DF940
int __cdecl sub_004DF940()
{
    if (!gbSoundSystemInit)
    {
        return 0;
    }
// build: symbol ?D2SOUND_IsPositionalSoundEnabled@* 0x00513B60
    return D2SOUND_IsPositionalSoundEnabled();
}

// 0x004DF960
int __cdecl sub_004DF960()
{
    if (!gbSoundSystemInit)
    {
        return 0;
    }
    return sub_00513B70_IsSoundEnvironEnabled();
}

// 0x004DF980
int __cdecl sub_004DF980_IsSoundMode1Or2()
{
    if (!gbSoundSystemInit)
    {
        return 0;
    }

    const int nMode = sub_00514C90_GetSoundMode();
    if (nMode == 1 || nMode == 2)
    {
        return 1;
    }

    return 0;
}

// 0x004DF9B0
int __cdecl sub_004DF9B0_IsSoundMode2()
{
    if (!gbSoundSystemInit)
    {
        return 0;
    }

    return sub_00514C90_GetSoundMode() == 2;
}

// 0x004DF9D0
D2SlotStrc* __fastcall SoundChannelFind(int nOwner)
{
    if (!gbSoundSystemInit)
    {
        return 0;
    }

    D2SlotStrc* pBest = 0;
    for (int i = 0; i < 16; i++)
    {
        D2SlotStrc* pSlot = &gaSlots[i];
        if (D2SOUNDSMP_GetSoundPlayingFlag(pSlot->pSound) && pSlot->pObject && pSlot->pObject->nSoundId == nOwner)
        {
            if (!pBest || pSlot->pObject->nKey < pBest->pObject->nKey)
            {
                pBest = pSlot;
            }
        }
    }

    return pBest;
}

// 0x004DFA40
int __fastcall sub_004DFA40_IsSlotPlaying(D2SlotStrc* pSlot)
{
    if (pSlot && pSlot->pSound)
    {
        return D2SOUNDSMP_IsSoundBufferPlaying(pSlot->pSound);
    }

    return 0;
}

// 0x004DFA60
void __cdecl sub_004DFA60()
{
    if (gbSoundSystemInit)
    {
        sub_004DF800();
        for (int i = 0; i < 16; ++i)
        {
            D2SOUNDSMP_DestroySound(gaSlots[i].pSound);
            gaSlots[i].pSound = 0;
        }

        gbSoundSystemInit = 0;
    }
}

// 0x004DFAA0
static int sub_004DFAA0_InitSoundChannels(int nMode)
{
// build: symbol ?D2SOUND_GetDirectSound@* 0x00513B50
    if (!D2SOUND_GetDirectSound())
        return 0;

    D2_ASSERT(!gbSoundSystemInit, 204);

    for (int i = 0; i < 16; ++i)
    {
        gaSlots[i].nType = 0;
        if (i < 4)
            gaSlots[i].nType = 1;
        else if (nMode == 1)
            gaSlots[i].nType = 2;
        else
            gaSlots[i].nType = nMode == 2 ? 6 : 0;

        gaSlots[i].pSound = D2SOUNDSMP_CreateSound(gaSlots[i].nType, gnSoundRestartArg);
        if (!gaSlots[i].pSound)
        {
            sub_004DFA60();
            return 0;
        }
    }

    GFXUTIL_ApplySoundEnviron(0);
    gbSoundSystemInit = 1;
    return 1;
}

// 0x004DFB50
static D2SlotStrc* __stdcall sub_004DFB50_GetFreeSlot(D2SlotObjectStrc* pObject, int nType)
{
    for (int i = 0; i < 16; ++i)
    {
        D2SlotStrc* pSlot = &gaSlots[i];
        if (!pSlot->pObject && pSlot->nType == nType && !D2SOUNDSMP_GetSoundPlayingFlag(pSlot->pSound))
            return pSlot;
    }
    D2SlotStrc* pBest = 0;
    for (int i = 0; i < 16; ++i)
    {
        if (gaSlots[i].nType == nType && gaSlots[i].pObject)
        {
            if (!pBest || SOUNDINST_CompareSounds(pBest->pObject, gaSlots[i].pObject, 1, 1))
                pBest = &gaSlots[i];
        }
    }
    if (!pBest || !SOUNDINST_CompareSounds(pObject, pBest->pObject, 0, 0))
        return 0;
    if (pBest->pSound)
    {
        if (pBest->pObject)
// build: symbol ?D2SOUNDSMP_GetStreamPosition@* 0x005159B0
            pBest->pObject->f_41 = D2SOUNDSMP_GetStreamPosition(pBest->pSound);
// build: symbol ?D2SOUNDSMP_StopSound@* 0x00515EE0
        D2SOUNDSMP_StopSound(pBest->pSound);
    }
    if (pBest->pObject)
    {
        pBest->pObject->nField0x30 = 2;
        pBest->pObject->nField0x2C = 0;
        pBest->pObject = 0;
    }
    return pBest;
}

// 0x004DFC20
void __fastcall sub_004DFC20_UpdateSoundSlot(D2SlotStrc* pSlot)
{
    if (!pSlot->pObject)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x1E7);
        exit(-1);
    }

    D2SlotObjectStrc* const pObject = pSlot->pObject;

    const D2SoundPosStrc* pPos = &pObject->tPos;
    D2SoundsTxt* pRecord = SOUNDHDR_GetSoundRecord(pObject->nSoundId);
    float fMin = SOUNDHDR_GetFalloffVolume(pObject->nSoundId);
    float fMax = SOUNDHDR_GetFalloffRange(pObject->nSoundId);

    int nVolume = pObject->nVolume;
    if (pRecord->bMusicVol)
        nVolume = D2SOUND_GetMusicVolumeOption() * nVolume / 100;
    nVolume = D2SOUND_GetMasterVolumeOption() * nVolume / 100;

    if (gnSfxVolume_00727564 != 100)
    {
        if (!(pObject->nSoundId >= 0x1231 && pObject->nSoundId <= 0x125A) && !(pObject->nSoundId >= 0x34 && pObject->nSoundId <= 0x47)
            && !(pObject->nSoundId >= 1 && pObject->nSoundId <= 0x0F))
            nVolume = gnSfxVolume_00727564 * nVolume / 100;
    }

    if (gnEnvVolume_00727568 != 100 && !pRecord->bSolo)
        nVolume = gnEnvVolume_00727568 * nVolume / 100;

    if (gbSoundSystemInit)
    {
// build: symbol ?D2SOUND_GetSoundMixerOption@* 0x00514C90
        const int nMode = D2SOUND_GetSoundMixerOption();
        if ((nMode == 1 || nMode == 2) && D2SOUND_GetPositionalBiasOption() != 50)
        {
            const int nLevel = (D2SOUND_GetPositionalBiasOption() * 2 - 100) / 3;
            if (pSlot->pSound && nLevel > 0)
                nVolume = (255 - nLevel * 255 / 50) * nVolume / 255;
            if ((pSlot->nType & 2) && nLevel < 0)
                nVolume = (nLevel * 255 / 50 + 255) * nVolume / 255;
        }
    }

    if (nVolume == pSlot->nVolume && pObject->fAttenuation == pSlot->fAttenuation && !memcmp(pPos, &pSlot->tPos, sizeof(D2SoundPosStrc)))
        return;

    int nFinal = nVolume;
    float fDist = GFXUTIL_VectorLength(pPos->fX, pPos->fY);
    if (fDist > fMin)
    {
        float fNum = fMax - fDist;
        float fDen = fMax - fMin;
        nFinal = (int)(fNum * nVolume / fDen);
    }

    nFinal = pRecord->nVolume * nFinal / 255;

    float fX = pPos->fX * 0.0031250000465661287;
    float fY = pPos->fY * 0.0031250000465661287;
    float fZ = pPos->fZ * 0.0031250000465661287;
    if (!pSlot->nType)
    {
        int nPanVolume;
        int nPan;
        D2SOUNDSMP_GetPositionalVolumePan(&nPanVolume, &nPan, fX, fY, fZ);
        D2SOUNDSMP_SetSoundPan(pSlot->pSound, nPan);
        nFinal = nPanVolume * nFinal / 255;
    }

    if (pSlot->nType & 2)
        D2SOUNDSMP_SetSoundPosition(pSlot->pSound, fX, fY, fZ);

    D2SOUNDSMP_SetSoundAttenuation(pSlot->pSound, pObject->fAttenuation);
    D2SOUNDSMP_SetSoundVolume(pSlot->pSound, nFinal);
    pSlot->tPos = *pPos;
    pSlot->nVolume = nVolume;
    pSlot->fAttenuation = pObject->fAttenuation;
}

// 0x004E0000
int __fastcall sub_004E0000_SetSoundMode(int nMode)
{
// build: symbol ?D2SOUND_IsPositionalSoundEnabled@* 0x00513B60
    if (nMode == 1 && !D2SOUND_IsPositionalSoundEnabled())
        return 0;

    if (nMode == 2 && !sub_00513B70_IsSoundEnvironEnabled())
        return 0;

    sub_004DFA60();
    if (!sub_004DFAA0_InitSoundChannels(nMode))
        return 0;

    if (sub_00514C90_GetSoundMode() != nMode)
        D2SOUND_SetSoundMixerOption(nMode);

    return 1;
}

// 0x004E0050
void __fastcall sub_004E0050_RestartSound(int nArg)
{
    gnSoundRestartArg = nArg;
    if (!sub_004E0000_SetSoundMode(sub_00514C90_GetSoundMode()))
        sub_004E0000_SetSoundMode(0);
}

// 0x004E00C0
void __cdecl sub_004E00C0_CloseSoundChannels()
{
    sub_004DFA60();
}

// 0x004E00D0
int __cdecl sub_004E00D0_ToggleSoundMode01()
{
    if (!gbSoundSystemInit || gnSoundModeSwitchLock)
        return 0;

    InterlockedIncrement(&gnSoundModeSwitchLock);
// build: symbol ?D2SOUND_GetSoundMixerOption@* 0x00514C90
    const int nOld = D2SOUND_GetSoundMixerOption();
    int nNew;
    if (nOld == 0)
        nNew = 1;
    else
        nNew = 0;
    D2SOUNDSMP_FadeOutMasterVolume(0xB4);
    const int nResult = sub_004E0000_SetSoundMode(nNew);
    if (!nResult)
        sub_004E0000_SetSoundMode(nOld);
// build: symbol ?D2SOUNDSMP_SetMasterVolume@* 0x00515CE0
    D2SOUNDSMP_SetMasterVolume(0xFF);
    InterlockedDecrement(&gnSoundModeSwitchLock);
    return nResult;
}

// 0x004E0140
int __cdecl sub_004E0140_ToggleSoundMode12()
{
    if (!gbSoundSystemInit || gnSoundModeSwitchLock)
        return 0;

    InterlockedIncrement(&gnSoundModeSwitchLock);
    const int nOld = D2SOUND_GetSoundMixerOption();
    int nNew;
    if (nOld == 2)
        nNew = 1;
    else
        nNew = 2;
    D2SOUNDSMP_FadeOutMasterVolume(0xB4);
    const int nResult = sub_004E0000_SetSoundMode(nNew);
    if (!nResult)
        sub_004E0000_SetSoundMode(nOld);
    D2SOUNDSMP_SetMasterVolume(0xFF);
    InterlockedDecrement(&gnSoundModeSwitchLock);
    return nResult;
}

// 0x004E01B0
D2SlotStrc* __fastcall sub_004E01B0_PlaySlotSound(D2SlotObjectStrc* pObject)
{
    D2SoundsTxt* pFirst = SOUNDHDR_GetSoundRecord(pObject->nSoundId);
    if (!(pObject->nFlags & 1))
        pObject->nSoundId = SOUNDHDR_PickVariant(pObject->nSoundId);
    D2SlotStrc* pOld = SoundChannelFind(pObject->nSoundId);
    if (pOld && !pOld->pObject->nField0x3D && pObject->nKey - pOld->pObject->nKey < 2 && pOld->pObject->nPriority >= pObject->nPriority)
        return 0;
    D2SoundsTxt* pRecord = SOUNDHDR_GetSoundRecord(pObject->nSoundId);
    pFirst->anRecent[1] = pFirst->anRecent[0];
    pFirst->anRecent[0] = pObject->nSoundId;
    if (!pRecord->bStream && pRecord->nState != 2)
    {
        SOUNDHDR_LoadCacheEntry(pObject->nSoundId, pRecord->bAsyncOnly == 0, 0);
        if (pRecord->nState != 2)
            return 0;
    }
    if (pRecord->bFailed)
        return 0;
    int nType = 0;
    if (pRecord->bStereo)
        nType = 1;
    if (!(nType & 1))
    {
        if (sub_00514C90_GetSoundMode() == 1)
            nType |= 2;
        if (sub_00514C90_GetSoundMode() == 2)
            nType |= 6;
    }
    D2SlotStrc* pSlot = sub_004DFB50_GetFreeSlot(pObject, nType);
    if (!pSlot)
        return 0;
    D2SOUNDSMP_ResetSound(pSlot->pSound);
    if (!pRecord->bStream)
    {
        sub_00515A30(pSlot->pSound, pRecord->nLoop);
        if (pRecord->nBlocks == 1)
            sub_00515A60(pSlot->pSound, pRecord->nBlock[0] * 2);
        if (!D2SOUNDSMP_SetSoundData(pSlot->pSound, pRecord->pData, pRecord->nSize))
            return 0;
    }
    pSlot->pObject = pObject;
    if (nType & 4)
    {
        float fValue = pRecord->bReverb ? 1.0f : 0.0f;
        D2SOUNDSMP_SetSoundReverbMix(pSlot->pSound, fValue);
    }
    pSlot->fAttenuation = 0.0f;
    pSlot->nVolume = -1;
    memset(&pSlot->tPos, 0, sizeof(pSlot->tPos));
    sub_004DFC20_UpdateSoundSlot(pSlot);
    int bOk;
    if (!pRecord->bStream)
    {
        bOk = D2SOUNDSMP_PlaySound(pSlot->pSound);
    }
    else
    {
        char szPath[0x50];
        sub_00482710(pObject->nSoundId, szPath);
        bOk = D2SOUNDSMP_StartSoundStream(pSlot->pSound, szPath, pObject->nField0x24, pRecord->nLoop);
    }
    if (!bOk)
    {
        pSlot->pObject = 0;
        return 0;
    }
    return pSlot;
}

// 0x004E0370
static D2NpcSoundStrc* sub_004E0370_GetNpcSoundRecord(D2UnitStrc* pUnit)
{
    if (!pUnit)
    {
        return 0;
    }

    switch ((unsigned int)pUnit->dwClassId)
    {
    case 0x94:
        return &gaNpcSounds[0];
    case 0xFE:
        return &gaNpcSounds[1];
    case 0xFC:
        return &gaNpcSounds[2];
    case 0xB0:
        return &gaNpcSounds[3];
    case 0x9A:
        return &gaNpcSounds[5];
    case 0xB1:
        return &gaNpcSounds[6];
    case 0xC7:
        return &gaNpcSounds[7];
    case 0xB2:
        return &gaNpcSounds[8];
    case 0xC8:
        return &gaNpcSounds[9];
    case 0x93:
        return &gaNpcSounds[10];
    case 0xC6:
        return &gaNpcSounds[11];
    case 0x101:
        return &gaNpcSounds[12];
    case 0xFD:
        return &gaNpcSounds[13];
    case 0xC9:
        return &gaNpcSounds[16];
    case 0x96:
        return &gaNpcSounds[17];
    case 0xCA:
        return &gaNpcSounds[18];
    case 0xD2:
        return &gaNpcSounds[19];
    case 0x129:
        return &gaNpcSounds[20];
    case 0xFF:
        return &gaNpcSounds[21];
    case 0x9B:
    case 0xAF:
        return &gaNpcSounds[23];
    case 0x195:
        return &gaNpcSounds[14];
    case 0x92:
    case 0xF4:
    case 0xF5:
    case 0xF6:
    case 0x109:
    case 0x208:
        return &gaNpcSounds[4];
    case 0xFB:
    case 0x209:
        return &gaNpcSounds[22];
    case 0x200:
        return &gaNpcSounds[24];
    case 0x203:
        return &gaNpcSounds[25];
    case 0x202:
        return &gaNpcSounds[28];
    case 0x1FF:
        return &gaNpcSounds[27];
    case 0x201:
        return &gaNpcSounds[26];
    }

    return 0;
}

// 0x004E0590
int __fastcall sub_004E0590_PickNpcSound(D2UnitStrc* pUnit, int nType)
{
    int nSound;
    D2NpcSoundStrc* pSound = sub_004E0370_GetNpcSoundRecord(pUnit);
    if (!pSound)
    {
        return 0;
    }

    if (nType == 2)
    {
        nSound = pSound->nGreetSound;
        return nSound;
    }

    for (unsigned int i = 0; i < 20; ++i)
    {
        nSound = pSound->f_0;
        if (!nType && pSound->nDaySound && !sub_004E40A0(2))
        {
            nSound = pSound->nDaySound;
        }

        if (pSound->nNightSound)
        {
            if (!nSound || !sub_004E40A0(3))
            {
                const int nCycle = ENVIRONMENT_GetCycleIndexFromAct(gpAct);
                nSound = pSound->nNightSound;
                if (nCycle != 1)
                {
                    if (nCycle >= 2 && nCycle <= 3)
                    {
                        nSound += 1;
                    }
                    else
                    {
                        nSound += 2;
                    }
                }
            }

            nSound = SOUNDHDR_PickVariant(nSound);
        }
        else
        {
            nSound = SOUNDHDR_PickVariant(nSound);
        }

        if (nSound != pSound->nLastSound)
        {
            break;
        }
    }

    pSound->nLastSound = nSound;
    pSound->nLastTick = sub_0044DB00();
    return nSound;
}

// 0x004E0650
int __fastcall sub_004E0650_GetStringSound(unsigned short nStringId)
{
    if (gbNpcSpeechAudio)
    {
        for (D2StringSoundStrc* pEntry = gaStringSounds; pEntry; ++pEntry)
        {
            if (!pEntry->f_0)
            {
                break;
            }

            if (pEntry->nStringId == nStringId)
            {
                return pEntry->f_0;
            }
        }
    }

    return 0;
}

// 0x004E0680
int __cdecl MONSTER_GetNpcSpeechAudio()
{
// build: symbol ?gbNpcSpeechAudio@* 0x0072AE24
    return gbNpcSpeechAudio;
}

// 0x004E0690
void __fastcall sub_004E0690_SetSoundTableFlag(int nValue)
{
// build: symbol ?gbNpcSpeechAudio@* 0x0072AE24
    gbNpcSpeechAudio = nValue;
}

// calling-convention shim (not game code)
void sub_004DF770_Shim(S* p, int x) { (void)sub_004DF770(p, 0, x); }

#include "gen/data/Source/D2Client/Unknown_004DF6C0.inc"
