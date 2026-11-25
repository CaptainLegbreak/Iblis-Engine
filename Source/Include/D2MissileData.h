#pragma once
// D2Common: a missile unit's data (D2UnitStrc::pMissileData): the stream missile and range, the activate frame, the
// skill and level, the frame counts, flags, owner, home and target.

#include "D2Check.h"

struct D2MissileDataStrc
{
    unsigned int unk0x00; // 0x00
    short nStreamMissile; // 0x04
    short nStreamRange; // 0x06
    short nActivateFrame; // 0x08
    short nSkill; // 0x0A
    short nLevel; // 0x0C
    short nTotalFrames; // 0x0E
    short nCurrentFrame; // 0x10
    unsigned short unk0x12; // 0x12
    unsigned int fFlags; // 0x14
    int nOwnerType; // 0x18
    int dwOwnerGUID; // 0x1C
    int nHomeType; // 0x20
    int dwHomeGUID; // 0x24
    int nTargetX; // 0x28
    int nTargetY; // 0x2C
    void* pStream; // 0x30
};
