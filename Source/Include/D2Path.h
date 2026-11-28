// Positions and paths: the static path of objects, items and tiles, the dynamic path of moving units.
#pragma once

#include "D2Structs.h"

struct D2CoordStrc
{
    int nX; // 0x00
    int nY; // 0x04
};

struct D2PathPointStrc
{
    unsigned short X; // 0x00
    unsigned short Y; // 0x02
};

// A position in 16.16 fixed point: the low word is the fraction, the high word the tile coordinate.
union D2FP32_16
{
    struct
    {
        unsigned short wOffsetX; // 0x00
        unsigned short wPosX; // 0x02
        unsigned short wOffsetY; // 0x04
        unsigned short wPosY; // 0x06
    };
    struct
    {
        unsigned int dwPrecisionX; // 0x00
        unsigned int dwPrecisionY; // 0x04
    };
};

struct D2StaticPathStrc
{
    D2ActiveRoomStrc* pRoom; // 0x00
    int nTargetX; // 0x04
    int nTargetY; // 0x08
    union // 0x0C
    {
        struct
        {
            int nXPos; // 0x0C
            int nYPos; // 0x10
        };
        D2CoordStrc tGameCoords; // 0x0C
    };
    unsigned char unk0x14[0x8]; // 0x14
    unsigned char nDirection; // 0x1C
    unsigned char bRoomNeedsUpdate; // 0x1D
    unsigned char pad0x1E[2]; // 0x1E
};

#pragma pack(push, 1)
struct D2DynamicPathStrc
{
    union // 0x00
    {
        D2FP32_16 tGameCoords;
        struct
        {
            unsigned short wOffsetX;
            unsigned short wPosX;
            unsigned short wOffsetY;
            unsigned short wPosY;
        };
        struct
        {
            unsigned int dwPrecisionX;
            unsigned int dwPrecisionY;
        };
    };
    int dwClientCoordX; // 0x08
    int dwClientCoordY; // 0x0C
    D2PathPointStrc tTargetCoord; // 0x10
    D2PathPointStrc tPrevTargetCoord; // 0x14
    D2PathPointStrc tFinalTargetCoord; // 0x18
    D2ActiveRoomStrc* pRoom; // 0x1C
    D2ActiveRoomStrc* pPreviousRoom; // 0x20
    int dwCurrentPointIdx; // 0x24
    int dwPathPoints; // 0x28
    void* unused0x2C; // 0x2C
    D2UnitStrc* pUnit; // 0x30
    unsigned int dwFlags; // 0x34
    unsigned int unk0x38; // 0x38
    unsigned int eType; // 0x3C
    unsigned int ePrevType; // 0x40
    unsigned int dwUnitSize; // 0x44
    unsigned int dwCollisionPattern; // 0x48
    unsigned int nFootprintCollisionMask; // 0x4C
    unsigned int nMoveTestCollisionMask; // 0x50
    unsigned short nCollidedWithMask; // 0x54
    unsigned short pad0x56; // 0x56
    D2UnitStrc* hTarget; // 0x58
    unsigned int dwTargetType; // 0x5C
    unsigned int dwTargetId; // 0x60
    unsigned char nDirection; // 0x64
    unsigned char nNewDirection; // 0x65
    unsigned char nDiffDirection; // 0x66
    unsigned char unk0x67; // 0x67
    unsigned char dwSpeed; // 0x68
    unsigned char unused0x69; // 0x69
    D2CoordStrc tDirectionVector; // 0x6A
    D2CoordStrc tVelocityVector; // 0x72
    unsigned char pad0x7A[2]; // 0x7A
    int dwVelocity; // 0x7C
    unsigned int nPreviousVelocity; // 0x80
    int dwMaxVelocity; // 0x84
    int dwAcceleration; // 0x88
    int dwAccelerationsCounter; // 0x8C
    unsigned char nDist; // 0x90
    unsigned char bDistMax; // 0x91
    unsigned char nIDAStarInitFScore; // 0x92
    unsigned char nStepNum; // 0x93
    unsigned char nDistance; // 0x94
    unsigned char pad0x95[3]; // 0x95
    int nDirOffset; // 0x98
    D2PathPointStrc PathPoints[78]; // 0x9C
    int nSavedStepsCount; // 0x1D4
    D2PathPointStrc SavedSteps[10]; // 0x1D8
};
#pragma pack(pop)

D2_CHECK_SIZE(D2CoordStrc, 0x08);
D2_CHECK_SIZE(D2PathPointStrc, 0x04);
D2_CHECK_SIZE(D2FP32_16, 0x08);
D2_CHECK_SIZE(D2StaticPathStrc, 0x20);
D2_CHECK_OFFSET(D2StaticPathStrc, nDirection, 0x1C);
D2_CHECK_OFFSET(D2StaticPathStrc, nXPos, 0x0C);
D2_CHECK_OFFSET(D2StaticPathStrc, tGameCoords, 0x0C);
D2_CHECK_SIZE(D2DynamicPathStrc, 0x200);
D2_CHECK_OFFSET(D2DynamicPathStrc, pRoom, 0x1C);
D2_CHECK_OFFSET(D2DynamicPathStrc, pUnit, 0x30);
D2_CHECK_OFFSET(D2DynamicPathStrc, hTarget, 0x58);
D2_CHECK_OFFSET(D2DynamicPathStrc, tDirectionVector, 0x6A);
D2_CHECK_OFFSET(D2DynamicPathStrc, dwVelocity, 0x7C);
D2_CHECK_OFFSET(D2DynamicPathStrc, PathPoints, 0x9C);
D2_CHECK_OFFSET(D2DynamicPathStrc, SavedSteps, 0x1D8);
