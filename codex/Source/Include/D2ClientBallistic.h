#pragma once
// Client: a missile's ballistic path (flags, the velocities, the frame count).

#include "D2Check.h"

struct D2BallisticStrc
{
    unsigned int dwFlags;
    int f_4;
    int f_8;
    int nVelocity;
    int nVelA;
    int nVelB;
    int nStartVelocity;
    int unk0x1C[2];
    int nAcceleration;
    int unk0x28[8];
    int nFrames;
};
