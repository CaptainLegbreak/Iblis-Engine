#pragma once
// Client sound: a SoundEnviron.txt record, as SoundHdr loads the table (sgptSoundEnvironTable) and
// build: symbol ?SOUNDHDR_GetSoundEnvironTxtRecord@* 0x00481920
// SOUNDHDR_GetSoundEnvironTxtRecord returns it: the song, the day and night ambience, the day and night
// events and their delay, the indoors flag, two materials and the EAX settings.

#include "D2Check.h"

struct D2SoundEnvironTxtStrc
{
    int nSong; // 0x00
    int nDayAmbience; // 0x04
    int nNightAmbience; // 0x08
    int nDayEvent; // 0x0C
    int nNightEvent; // 0x10
    unsigned int nEventDelay; // 0x14
    unsigned char bIndoors; // 0x18
    unsigned char unk0x19[3]; // 0x19
    int nMaterial1; // 0x1C
    int nMaterial2; // 0x20
    int nEAXEnviron; // 0x24
    int nEAXEnvSize; // 0x28
    int nEAXEnvDiff; // 0x2C
    int nEAXRoomVol; // 0x30
    int nEAXRoomHF; // 0x34
    int nEAXDecayTime; // 0x38
    int nEAXDecayHF; // 0x3C
    int nEAXReflect; // 0x40
    int nEAXReflectDelay; // 0x44
    int nEAXReverb; // 0x48
    int nEAXRevDelay; // 0x4C
    int nEAXRoomRoll; // 0x50
    int nEAXAirAbsorb; // 0x54
};
