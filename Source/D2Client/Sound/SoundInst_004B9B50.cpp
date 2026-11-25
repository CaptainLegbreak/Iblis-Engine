#include "D2Client.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2ClientGame.h"
#include "D2ClientSound.h"


#pragma pack(push, 1)

struct D2ClientSoundStrc
{
    int bActive;
    int nSoundId;
    int f_8;
    D2SoundVecStrc vPos;
    float fDistance;
    int f_1C;
    float fPan;
    int nArg4;
    D2SoundUnitNodeStrc* pUnitList;
    void* pStream;
    int nType;
    unsigned int f_34;
    int nArg3;
    unsigned char nPriority;
    int bLocked;
    int nRestart;
    int f_45;
    int nFadeFrom;
    int nFadeTo;
    unsigned int dwFadeStart;
    unsigned int dwFadeEnd;
};

#pragma pack(pop)

extern D2SoundNodeStrc* gpSoundList_007C5458; // 0x007C5458

// 0x004B9B50
void __fastcall SOUNDINST_SetValue(int nKey, int nValue)
{
    if (!nKey)
        return;
    D2SoundNodeStrc* pLink = gpSoundList_007C5458;
    if (!pLink)
        return;
    do
    {
        D2ClientSoundStrc* pValue = pLink->pSound;
        if (pValue->f_8 == nKey)
        {
            pValue->f_1C = nValue;
            return;
        }
        pLink = pLink->pNext;
    } while (pLink);
}
