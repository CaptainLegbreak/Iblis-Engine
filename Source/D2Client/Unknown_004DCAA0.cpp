#include "D2Client.h"
#include "D2ClientUi.h"
#include "D2ClientSound.h"
#include "D2SoundEnvironTxt.h"
#include "D2MultiTypes.h"

struct D2TimedHintStrc
{
    int bActive;
    void* pOwner;
    unsigned int nEndTickA;
    int bActive2;
    int nArgE;
    unsigned int nEndTickF;
    int nArgG;
    unsigned int nEndTickC;
};

unsigned int gdwLevelEnterTick;                                                                             // 0x007C89D0
unsigned int gdwSongStartTick;                                                                             // 0x007C89D4
int gnCurrentSongId;                                                                                      // 0x007C89D8
int gnSongLevelId;                                                                                      // 0x007C89DC
unsigned int gdwSongPositionTick;                                                                             // 0x007C89E0
D2TimedHintStrc gtTimedHint;                                                                        // 0x007C89E4
int gnSpeechLevelId;                                                                                      // 0x007C8A04

int __cdecl sub_0044DB00();                                                                                 // 0x0044DB00
D2UnitStrc* __cdecl sub_00463DD0_GetPlayerUnit();                                                               // 0x00463DD0
int __fastcall CUNIT_IsDeadOrDying(D2UnitStrc* pUnit);                                               // 0x00464820
int __cdecl UNITMODE_GetPlayerLevelId();                                                                // 0x00481780
int __cdecl sub_004817F0();                                                                                 // 0x004817F0
int __cdecl sub_00481800();                                                                                 // 0x00481800
int __cdecl sub_00481810();                                                                                 // 0x00481810
D2SoundsTxt* __fastcall SOUNDHDR_GetSoundRecord(int nId);                                                         // 0x00481860
D2SoundEnvironTxtStrc* __fastcall SOUNDHDR_GetSoundEnvironTxtRecord(int nEnvironId);                        // 0x00481920
int __fastcall sub_004B9590(void* pEntry);                                                                  // 0x004B9590
void* __fastcall sub_004B9610(int nId);                                                                     // 0x004B9610
int __fastcall sub_004B9A00(int nSoundId, D2UnitStrc* pUnit, int nArg2, int nArg3, int nArg4);           // 0x004B9A00
int __cdecl SOUNDINST_IsSongPlaying();                                                                   // 0x004B9C60
int __fastcall SOUNDINST_GetPosition(void* pEntry);                                                      // 0x004B9D50
void __fastcall SOUNDINST_LockSoundsById(int nHintId);                                                 // 0x004BA890
void __cdecl UNITSND_CheckLevelSpeech();                                                               // 0x004CC270
int __cdecl D2SOUND_GetMasterVolumeOption();                                                                                 // 0x00514CC0
int __cdecl D2SOUND_GetMusicVolumeOption();                                                                                 // 0x00514CF0

int __cdecl DLIGHTMAP_GetSoundTick(); // 0x00481820

extern "C" void* __cdecl sub_00481810_GetTokenData(); // 0x00481810

extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0

extern "C" int gnGlobal_007C89E4; // 0x007C89E4

// 0x004DCAA0
void __fastcall sub_004DCAA0_UpdateLevelSong(unsigned int dwTick)
{
    int nLevelId = UNITMODE_GetPlayerLevelId();
    if (!nLevelId)
    {
        return;
    }

    if (nLevelId != gnSongLevelId)
    {
        gnSongLevelId = nLevelId;
        gdwLevelEnterTick = dwTick;
    }

    int nSong = 0;
    D2SoundEnvironTxtStrc* pSoundEnvironTxtRecord = SOUNDHDR_GetSoundEnvironTxtRecord(sub_004817A0_GetPlayerSoundEnviron());
    if (pSoundEnvironTxtRecord)
    {
        nSong = pSoundEnvironTxtRecord->nSong;
        if (nSong && (nSong < sub_004817F0() || nSong > sub_00481800()))
        {
            nSong = 0;
        }
    }

    int bEnabled = D2SOUND_GetMasterVolumeOption() && D2SOUND_GetMusicVolumeOption() ? 1 : 0;
    int bChange = 0;
    if (!gnCurrentSongId)
    {
        bChange = 1;
    }

    if (!bEnabled)
    {
        bChange = 1;
    }

    if (dwTick - gdwLevelEnterTick >= 0x4B)
    {
        bChange = 1;
    }

    if (gnCurrentSongId != nSong && bChange)
    {
        gnCurrentSongId = nSong;
        gdwSongPositionTick = dwTick;
    }

    if (!bEnabled)
    {
        sub_004BA8F0();
    }

    if (!gnCurrentSongId)
    {
        sub_004BA8F0();
    }

    if (gtTimedHint.bActive)
    {
        if (gtTimedHint.bActive2 && sub_0044DB00() >= gtTimedHint.nEndTickA)
        {
            sub_004B9A00((int)gtTimedHint.pOwner, 0, 0, 0, 0);
            gtTimedHint.bActive2 = 0;
        }

        if (gtTimedHint.nArgG && sub_0044DB00() >= gtTimedHint.nEndTickF)
        {
            D2UnitStrc* pPlayer = sub_00463DD0_GetPlayerUnit();
            if (!CUNIT_IsDeadOrDying(pPlayer))
            {
                sub_004B9A00(gtTimedHint.nArgE, pPlayer, 0, 0, 0);
            }

            gtTimedHint.nArgG = 0;
        }

        if (sub_0044DB00() < gtTimedHint.nEndTickC)
        {
            return;
        }

        gtTimedHint.bActive = 0;
        if (bEnabled)
        {
            SOUNDINST_LockSoundsById((int)gtTimedHint.pOwner);
        }
    }

    if (gnCurrentSongId && bEnabled && !sub_004B9610(gnCurrentSongId))
    {
        const int nOffset = 4 * (gnCurrentSongId - sub_004817F0());
        int nValue = *(int*)(sub_00481810() + nOffset);
        int nMode = !SOUNDINST_IsSongPlaying() && !nValue ? 2 : 0;
        sub_004BA8F0();
        sub_004B9A00(gnCurrentSongId, 0, 0, nMode, nValue);
        gdwSongStartTick = dwTick;
    }

    if (gnSongLevelId != gnSpeechLevelId && dwTick - gdwLevelEnterTick >= 0x3E)
    {
        UNITSND_CheckLevelSpeech();
        gnSpeechLevelId = gnSongLevelId;
    }

    if (!gnCurrentSongId || dwTick <= gdwSongPositionTick + 0x7D)
    {
        return;
    }

    D2SoundsTxt* pSoundTxt = SOUNDHDR_GetSoundRecord(gnCurrentSongId);
    void* pEntry = sub_004B9610(gnCurrentSongId);
    if (!pEntry || !sub_004B9590(pEntry))
    {
        return;
    }

    int nPosition = SOUNDINST_GetPosition(pEntry);
    int nValue = 0;
    if (nPosition >= 0 && nPosition < pSoundTxt->nBlock[0])
    {
        nValue = pSoundTxt->nBlock[0];
    }

    if (nPosition >= pSoundTxt->nBlock[0] && nPosition < pSoundTxt->nBlock[1])
    {
        nValue = pSoundTxt->nBlock[1];
    }

    if (nPosition >= pSoundTxt->nBlock[1] && nPosition < pSoundTxt->nBlock[2])
    {
        nValue = pSoundTxt->nBlock[2];
    }

    const int nOffset = 4 * (gnCurrentSongId - sub_004817F0());
    *(int*)(sub_00481810() + nOffset) = nValue;
    gdwSongPositionTick = dwTick;
}

// 0x004DCD40
void __fastcall ITEM_ShowTimedHint(void* pOwner, int nDelayA, int nDelayC, unsigned int nIndex, int nArgE, int nDelayF, int nArgG)
{
    if (gnCurrentSongId)
    {
        D2SoundsTxt* pSoundTxt = SOUNDHDR_GetSoundRecord(gnCurrentSongId);
        void* pEntry = sub_004B9610(gnCurrentSongId);
        if (pEntry && sub_004B9590(pEntry))
        {
            const int nValue = nIndex > 0 ? pSoundTxt->nBlock[nIndex - 1] : 0;
            const int nOffset = 4 * (gnCurrentSongId - sub_004817F0());
            *(int*)(sub_00481810() + nOffset) = nValue;
            gdwSongPositionTick = DLIGHTMAP_GetSoundTick();
        }
    }

    sub_004BA8F0();
    gtTimedHint.bActive = 1;
    gtTimedHint.pOwner = pOwner;
    gtTimedHint.nEndTickA = sub_0044DB00() + nDelayA;
    gtTimedHint.bActive2 = 1;
    gtTimedHint.nArgE = nArgE;
    gtTimedHint.nEndTickF = sub_0044DB00() + nDelayF;
    gtTimedHint.nArgG = nArgG;
    gtTimedHint.nEndTickC = sub_0044DB00() + nDelayC;
}

// 0x004DCE10
void __fastcall sub_004DCE10_UpdateTimedHint(int nDelay, int nArg)
{
    if (gtTimedHint.bActive)
    {
        if (nArg)
        {
            gtTimedHint.nEndTickF = sub_0044DB00() + nDelay;
        }

        gtTimedHint.nArgG = nArg;
        gtTimedHint.nEndTickC = gtTimedHint.nEndTickF + 0x32;
    }
}

// 0x004DCA30
void __cdecl sub_004DCA30_ResetTokenCache()
{
    if (gpClientConfig->bNoSound)
        return;

    gdwLevelEnterTick = 0;
    gdwSongStartTick = 0;
    gnCurrentSongId = 0;
    gnSongLevelId = 0;
    gdwSongPositionTick = 0;
    gnGlobal_007C89E4 = 0;
    gnSpeechLevelId = 0;

    void* pTokenData = sub_00481810_GetTokenData();
    if (pTokenData)
    {
        memset(pTokenData, 0, (1 - sub_004817F0() + sub_00481800()) * 4);
    }
}



