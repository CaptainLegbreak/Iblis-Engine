#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"

#define D2_ABS(x) ((x) >= 0 ? (x) : -(x))

struct D2CoordStrc;

struct D2UnkPathStrc;

struct D2UnkPathStrc2;

struct D2PathTestStrc;

struct D2PathRayStrc;

struct D2UnkPathStrc
{
    int unk0x00;
    int unk0x04;
    int unk0x08;
};

struct D2UnkPathStrc2
{
    unsigned char unk0x00;
    unsigned char unk0x01;
    unsigned char unk0x02;
};

extern const D2UnkPathStrc gaPathDirectionTriplets[25]; // 0x006F1518

extern const D2UnkPathStrc2 gaPathDirectionTripletsAlt[25]; // 0x006F1648

int __stdcall PATH_GetDirectionIndex(D2PathPointStrc pPoint1, D2PathPointStrc pPoint2); // 0x00678C10

struct D2PathTestStrc
{
    char unk0x00[0x08];
    D2ActiveRoomStrc* pRoom;
    char unk0x0C[0x18];
    int nUnitSize;
    char unk0x28[0x04];
    int nCollisionMask;
};

struct D2PathRayStrc
{
    unsigned short nStartX;
    unsigned short nStartY;
    unsigned short nTargetX;
    unsigned short nTargetY;
    char unk0x08[0x08];
    int nStepX;
    int nStepY;
    int bValid;
};

struct PathOwner;
struct D2DynamicPathStrc;
struct D2PathPointStrc;
struct D2StaticPathStrc;
struct D2UnitStrc;

struct PathOwner { char pad0[0x2c]; D2DynamicPathStrc* pPath; };


extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
extern "C" const char gszEmptyAssertText; // 0x006CC837
unsigned char __stdcall PATH_GetDirection(D2DynamicPathStrc* pDynamicPath); // 0x006487F0



int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900

unsigned short __stdcall COLLISION_CheckMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, unsigned short nMask); // 0x0064D9B0

void __fastcall PATH_UpdateMotionVelocity(D2PathRayStrc* pRay); // 0x00678E30

// 0x00678B10
int __fastcall PATH_EstimateDistanceXY(int nX1, int nY1, int nX2, int nY2)
{
    int nDiffX = nX1 - nX2;
    if (nDiffX < 0)
    {
        nDiffX = -nDiffX;
    }

    int nDiffY = nY1 - nY2;
    if (nDiffY < 0)
    {
        nDiffY = -nDiffY;
    }

    const int nMin = nDiffX < nDiffY ? nDiffX : nDiffY;
    const int nMax = nDiffX > nDiffY ? nDiffX : nDiffY;
    return nMin + 2 * nMax;
}

// 0x00678B40
int __stdcall PATH_EstimateDistance(D2PathPointStrc tPoint1, D2PathPointStrc tPoint2)
{
    int nDiffX = tPoint2.X - tPoint1.X;
    if (nDiffX < 0)
    {
        nDiffX = -nDiffX;
    }

    int nDiffY = tPoint2.Y - tPoint1.Y;
    if (nDiffY < 0)
    {
        nDiffY = -nDiffY;
    }

    const int nMin = nDiffX < nDiffY ? nDiffX : nDiffY;
    const int nMax = nDiffX > nDiffY ? nDiffX : nDiffY;
    return nMin + 2 * nMax;
}

// 0x00678B80
static int __fastcall PATH_GetDirectionIndexXY(int nX1, int nY1, int nX2, int nY2)
{
    int nAbsDiffX = nX2 - nX1;
    int nAbsDiffY = nY2 - nY1;
    int nDiffX = nAbsDiffX;
    int nDiffY = nAbsDiffY;

    if (nAbsDiffX < 0)
        nAbsDiffX = -nAbsDiffX;
    if (nAbsDiffY < 0)
        nAbsDiffY = -nAbsDiffY;

    if (nAbsDiffX >= 2 * nAbsDiffY)
    {
        if (nDiffY < 0)
            nDiffY = -1;
        else
            nDiffY &= 1;
    }
    else if (nAbsDiffY >= 2 * nAbsDiffX)
    {
        if (nDiffX < 0)
            nDiffX = -1;
        else
            nDiffX &= 1;
    }

    if (nDiffX < -1)
        nDiffX = -2;
    else if (nDiffX > 1)
        nDiffX = 2;

    if (nDiffY < -1)
        nDiffY = -2;
    else if (nDiffY > 1)
        nDiffY = 2;

    return nDiffY + 5 * nDiffX + 12;
}

// 0x00678CB0
int __fastcall PATH_GetAltFirstDirectionXY(int nX1, int nY1, int nX2, int nY2)
{
    return gaPathDirectionTripletsAlt[PATH_GetDirectionIndexXY(nX1, nY1, nX2, nY2)].unk0x00;
}

// 0x00678CF0
int __fastcall PATH_GetFirstDirectionXY(int nX1, int nY1, int nX2, int nY2)
{
    return gaPathDirectionTriplets[PATH_GetDirectionIndexXY(nX1, nY1, nX2, nY2)].unk0x00;
}

// 0x00678D30
void __fastcall PATH_GetDirectionTripletXY(int nX1, int nY1, int nX2, int nY2, int* pTestDir)
{
    int nIndex = PATH_GetDirectionIndexXY(nX1, nY1, nX2, nY2);

    pTestDir[0] = gaPathDirectionTriplets[nIndex].unk0x00;
    pTestDir[1] = gaPathDirectionTriplets[nIndex].unk0x04;
    pTestDir[2] = gaPathDirectionTriplets[nIndex].unk0x08;
}

// 0x00678DB0
void __fastcall PATH_GetAltDirectionTripletXY(int nX1, int nY1, int nX2, int nY2, int* pTestDir)
{
    int nIndex = PATH_GetDirectionIndexXY(nX1, nY1, nX2, nY2);

    pTestDir[0] = gaPathDirectionTripletsAlt[nIndex].unk0x00;
    pTestDir[1] = gaPathDirectionTripletsAlt[nIndex].unk0x01;
    pTestDir[2] = gaPathDirectionTripletsAlt[nIndex].unk0x02;
}

// 0x00678C10
int __stdcall PATH_GetDirectionIndex(D2PathPointStrc pPoint1, D2PathPointStrc pPoint2)
{
    int nAbsDiffX = pPoint2.X - pPoint1.X;
    int nAbsDiffY = pPoint2.Y - pPoint1.Y;
    int nDiffX = nAbsDiffX;
    int nDiffY = nAbsDiffY;

    if (nAbsDiffX < 0)
    {
        nAbsDiffX = -nAbsDiffX;
    }

    if (nAbsDiffY < 0)
    {
        nAbsDiffY = -nAbsDiffY;
    }

    if (nAbsDiffX >= 2 * nAbsDiffY)
    {
        if (nDiffY < 0)
        {
            nDiffY = -1;
        }
        else
        {
            nDiffY &= 1;
        }
    }
    else if (nAbsDiffY >= 2 * nAbsDiffX)
    {
        if (nDiffX < 0)
        {
            nDiffX = -1;
        }
        else
        {
            nDiffX &= 1;
        }
    }

    if (nDiffX < -1)
    {
        nDiffX = -2;
    }
    else if (nDiffX > 1)
    {
        nDiffX = 2;
    }

    if (nDiffY < -1)
    {
        nDiffY = -2;
    }
    else if (nDiffY > 1)
    {
        nDiffY = 2;
    }

    return nDiffY + 5 * nDiffX + 12;
}

// 0x00678CD0
int __stdcall PATH_GetAltFirstDirection(D2PathPointStrc pPoint1, D2PathPointStrc pPoint2)
{
    return gaPathDirectionTripletsAlt[PATH_GetDirectionIndex(pPoint1, pPoint2)].unk0x00;
}

// 0x00678D70
void __fastcall PATH_GetDirections_6FDAB790(int* pTestDir, D2PathPointStrc pPoint1, D2PathPointStrc pPoint2)
{
    int nIndex = PATH_GetDirectionIndex(pPoint1, pPoint2);

    pTestDir[0] = gaPathDirectionTriplets[nIndex].unk0x00;
    pTestDir[1] = gaPathDirectionTriplets[nIndex].unk0x04;
    pTestDir[2] = gaPathDirectionTriplets[nIndex].unk0x08;
}

// 0x00678DF0
void __fastcall PATH_GetAltDirectionTriplet(int* pTestDir, D2PathPointStrc pPoint1, D2PathPointStrc pPoint2)
{
    int nIndex = PATH_GetDirectionIndex(pPoint1, pPoint2);

    pTestDir[0] = gaPathDirectionTripletsAlt[nIndex].unk0x00;
    pTestDir[1] = gaPathDirectionTripletsAlt[nIndex].unk0x01;
    pTestDir[2] = gaPathDirectionTripletsAlt[nIndex].unk0x02;
}

// 0x00678D10
int __stdcall PATH_GetFirstDirection(D2PathPointStrc tPoint1, D2PathPointStrc tPoint2)
{
    return gaPathDirectionTriplets[PATH_GetDirectionIndex(tPoint1, tPoint2)].unk0x00;
}

struct D2MotionPathStrc
{
    D2PathPointStrc tStart;
    D2PathPointStrc tTarget;
    D2CoordStrc tDirectionVector;
    D2CoordStrc tVelocity;
    int nSpeed;
    unsigned char nDirection;
    char unk_1D[3];
    unsigned int nFlags;
};

void __fastcall PATH_GetDirectionVectorFromPoints(D2CoordStrc* pDirectionVector, int* pOutDirection, D2PathPointStrc tPoint1, D2PathPointStrc tPoint2); // 0x0064FD70

// 0x00678E30
int __fastcall PATH_UpdateMotionVelocity(D2MotionPathStrc* pPath)
{
    if (pPath->tStart.X == pPath->tTarget.X && pPath->tStart.Y == pPath->tTarget.Y)
    {
        pPath->tDirectionVector.nX = 0;
        pPath->tDirectionVector.nY = 0;
        pPath->tVelocity.nX = 0;
        pPath->tVelocity.nY = 0;
        pPath->nSpeed = 0;
        return 1;
    }
    int nDirection;
    PATH_GetDirectionVectorFromPoints(&pPath->tDirectionVector, &nDirection, pPath->tStart, pPath->tTarget);
    pPath->nDirection = nDirection;
    if (pPath->nFlags & 0x200)
        pPath->nDirection = (pPath->nDirection - 32) & 63;
    pPath->tVelocity.nX = (pPath->tDirectionVector.nX * pPath->nSpeed) >> 8;
    pPath->tVelocity.nY = (pPath->tDirectionVector.nY * pPath->nSpeed) >> 8;
    const int nVelocityX = pPath->tVelocity.nX < 0 ? -pPath->tVelocity.nX : pPath->tVelocity.nX;
    unsigned short nTargetCoordinate = pPath->tTarget.X;
    const int nDiffX = (int)pPath->tStart.X - nTargetCoordinate;
    const int nDeltaX = (nDiffX < 0 ? -nDiffX : nDiffX) << 16;
    const int nVelocityY = pPath->tVelocity.nY < 0 ? -pPath->tVelocity.nY : pPath->tVelocity.nY;
    nTargetCoordinate = pPath->tTarget.Y;
    const int nDiffY = (int)pPath->tStart.Y - nTargetCoordinate;
    const int nDeltaY = nDiffY < 0 ? -nDiffY : nDiffY;
    return (nVelocityX <= nDeltaX || nVelocityY <= (nDeltaY << 16)) ? 1 : 0;
}

// 0x00678F00
void __fastcall PATH_NormalizeStep(int* a1, int* a2)
{
    if (*a1 >= 0)
    {
        while (*a1 > 65536)
        {
            *a1 >>= 1;
            *a2 >>= 1;
        }
    }
    else
    {
        while (*a1 < -65536)
        {
            *a1 >>= 1;
            *a2 >>= 1;
        }
    }

    if (*a2 >= 0)
    {
        while (*a2 > 65536)
        {
            *a1 >>= 1;
            *a2 >>= 1;
        }
    }
    else
    {
        while (*a2 < -65536)
        {
            *a1 >>= 1;
            *a2 >>= 1;
        }
    }
}

// 0x00678F70
int __fastcall PATH_TestRay(D2PathTestStrc* pPath, D2PathRayStrc* pRay)
{
    if (!pRay->bValid)
        return 0;

    PATH_UpdateMotionVelocity(pRay);
    if (!pRay->bValid)
        return 0;

    int nStepX = pRay->nStepX;
    int nStepY = pRay->nStepY;
    if (!nStepX && !nStepY)
        return 0;

    int nX = (pRay->nStartX << 16) + 0x8000;
    int nY = (pRay->nStartY << 16) + 0x8000;
    const int nTargetX = (pRay->nTargetX << 16) + 0x8000;
    const int nTargetY = (pRay->nTargetY << 16) + 0x8000;
    PATH_NormalizeStep(&nStepX, &nStepY);

    int nStep;
    if (D2_ABS(nStepX) > D2_ABS(nStepY))
        nStep = D2_ABS(nStepX);
    else
        nStep = D2_ABS(nStepY);

    D2ActiveRoomStrc* pRoom = pPath->pRoom;
    const int nUnitSize = pPath->nUnitSize;
    const int nCollisionMask = pPath->nCollisionMask;
    while (1)
    {
        const int nDeltaX = nTargetX - nX;
        if (D2_ABS(nDeltaX) < nStep)
        {
            const int nDeltaY = nTargetY - nY;
            if (D2_ABS(nDeltaY) < nStep)
                break;
        }

        const int nNewX = nX + nStepX;
        const int nNewY = nY + nStepY;
        if ((short)(nX >> 16) != (short)(nNewX >> 16) || (short)(nY >> 16) != (short)(nNewY >> 16))
        {
            if (COLLISION_CheckMaskWithSize(pRoom, (unsigned short)(nNewX >> 16), (unsigned short)(nNewY >> 16), nUnitSize, nCollisionMask))
                return 0;
        }

        nX = nNewX;
        nY = nNewY;
    }

    D2_ASSERT(nX != 0x80008000, 0x1DF);
    D2_ASSERT(nY != 0x80008000, 0x1E0);
    return 1;
}



// 0x00679190
void __fastcall PATHUTIL_AdvanceTowardsTarget(D2DynamicPathStrc* ptPath)
{
    if (ptPath == 0)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x1ea);
        exit(-1);
    }
    if (ptPath->hTarget == 0)
    {
        FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), 0x1eb);
        exit(-1);
    }

    unsigned char dir = PATH_GetDirection(ptPath->hTarget->pDynamicPath);
    int dir8 = (int)dir * 8;
    int offset = (int)ptPath->dwSpeed * 256;
    int angle = (dir8 - offset) & 0x1FF;
    float f = (float)ptPath->dwSpeed;

// build: symbol ?FOG_10083_Cos_LUT@* 0x0040B330
    ptPath->tTargetCoord.X += (unsigned short)(int)(FOG_10083_Cos_LUT(angle) * f);
// build: symbol ?FOG_10084_Sin_LUT@* 0x0040B350
    ptPath->tTargetCoord.Y += (unsigned short)(int)(FOG_10084_Sin_LUT(angle) * f);
}

inline int UNITS_GetXPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nXPos;
    }
    return pUnit->pDynamicPath ? PATH_GetXPosition(pUnit->pDynamicPath) : 0;
}

inline int UNITS_GetYPositionInline(D2UnitStrc* pUnit)
{
    switch (pUnit->dwUnitType)
    {
    case UNIT_OBJECT:
    case UNIT_ITEM:
    case UNIT_TILE:
        return pUnit->pStaticPath->nYPos;
    }
    return pUnit->pDynamicPath ? PATH_GetYPosition(pUnit->pDynamicPath) : 0;
}

// 0x00679250
void __fastcall PATHUTIL_GetTargetPathPoint(D2PathPointStrc* pOutPathPoint, D2DynamicPathStrc* ptPath)
{
    D2_ASSERT(ptPath, 0x201);
    D2_ASSERT(ptPath->hTarget, 0x202);

    pOutPathPoint->X = UNITS_GetXPositionInline(ptPath->hTarget);
    pOutPathPoint->Y = UNITS_GetYPositionInline(ptPath->hTarget);

    if (ptPath->dwSpeed)
    {
        int nDirection = 8 * PATH_GetDirection(ptPath->hTarget->pDynamicPath);
        nDirection = (nDirection - (ptPath->dwSpeed << 8)) & 0x1FF;
        const float fSpeed = ptPath->dwSpeed;
        pOutPathPoint->X += (short)(FOG_10083_Cos_LUT(nDirection) * fSpeed);
        pOutPathPoint->Y += (short)(FOG_10084_Sin_LUT(nDirection) * fSpeed);
    }
}

#include "gen/data/Source/D2Common/PATH/PathUtil.inc"
