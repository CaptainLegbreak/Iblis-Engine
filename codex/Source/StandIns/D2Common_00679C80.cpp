// Functional replacement for the function at 0x00679C80, not the original code: only the ordinary build (tools/link.py) uses it.
// The other functions in this file are copies that give it its callees and their calling conventions; the build links their verified definitions instead.

enum D2C_PathConstants
{
    UNIT_OBJECT = 2,
    UNIT_ITEM = 4,
    UNIT_TILE = 5,
};

struct D2ActiveRoomStrc;

struct D2PathPointStrc
{
    unsigned short X;
    unsigned short Y;
};

struct D2CoordStrc
{
    int nX;
    int nY;
};

struct D2StaticPathStrc
{
    char unk0x00[0x0C];
    int nXPos;
    int nYPos;
};

struct D2DynamicPathStrc;

struct D2UnitStrc
{
    int dwUnitType;
    char unk0x04[0x28];
    union
    {
        D2DynamicPathStrc* pDynamicPath;
        D2StaticPathStrc* pStaticPath;
    };
};

struct D2DynamicPathStrc
{
    unsigned short wOffsetX;
    unsigned short wPosX;
    unsigned short wOffsetY;
    unsigned short wPosY;
    char unk0x08[0x14];
    D2ActiveRoomStrc* pRoom;
    char unk0x20[0x4];
    int dwCurrentPointIdx;
    int dwPathPoints;
    char unk0x2C[0x4];
    D2UnitStrc* pUnit;
    char unk0x34[0x8];
    unsigned int eType;
    char unk0x40[0x8];
    unsigned int dwCollisionPattern;
    char unk0x4C[0x4];
    unsigned int nMoveTestCollisionMask;
    char unk0x54[0x4];
    D2UnitStrc* hTarget;
    char unk0x5C[0x20];
    int dwVelocity;
    char unk0x80[0x10];
    unsigned char nDist;
    char unk0x91[0x7];
    int nDirOffset;
    D2PathPointStrc PathPoints[78];
};

struct D2CollisionTestStrc
{
    D2ActiveRoomStrc* pRoom;
    unsigned int nCollisionPattern;
    unsigned int nCollisionMask;
};

struct D2PathInfoStrc
{
    D2PathPointStrc tStartCoord;
    D2PathPointStrc tTargetCoord;
    D2ActiveRoomStrc* pStartRoom;
    D2ActiveRoomStrc* pTargetRoom;
    int field_10;
    unsigned char field_14;
    unsigned char field_15;
    unsigned short field_16;
    int nDistMax;
    char unk0x1C[0xC];
    int nCollisionPattern;
    int nCollisionMask;
    D2DynamicPathStrc* pDynamicPath;
};

extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl ASSERT_GetSourceFile(); // 0x00408090
extern "C" void __cdecl ASSERT_Report(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09
#define D2_ASSERT(expr, line) if (!(expr)) { ASSERT_Report(&gszEmptyAssertText, ASSERT_GetSourceFile(), line); exit(-1); }

int __stdcall COLLISION_CheckAnyCollisionWithPattern(D2ActiveRoomStrc* pRoom, int nX, int nY, int nCollisionPattern, unsigned short nMask); // 0x0064D910
void __fastcall PATH_ComputeVelocityAndDirectionVectorsToNextPoint(D2DynamicPathStrc* pPath, int bNormalizeDirectionIfSamePos, int bForceDirectionNormalization); // 0x0064FE40
void __fastcall PATH_GetDirections_6FDAB790(int* pTestDir, D2PathPointStrc pPoint1, D2PathPointStrc pPoint2); // 0x00678D70
int __stdcall PATH_GetTableHeuristic(D2PathPointStrc pPoint1, D2PathPointStrc pPoint2); // 0x00679380
int __stdcall PATH_GetXPosition(D2DynamicPathStrc* pDynamicPath); // 0x006488C0
int __stdcall PATH_GetYPosition(D2DynamicPathStrc* pDynamicPath); // 0x00648900
void __stdcall D2COMMON_10170_PathSetTargetPos(D2DynamicPathStrc* pPath, int nX, int nY); // 0x00648AD0
extern const D2CoordStrc gatDirectionToOffset[8]; // 0x006F1798
static int __stdcall sub_6FDAA880(D2PathPointStrc tPoint, int* pTestDir, int* pDirection, D2PathInfoStrc* pPathInfo);
static int PATH_CheckCollisionsToNextPosition(D2DynamicPathStrc* pDynamicPath, D2PathPointStrc* pGameCoord);
int __fastcall sub_6FDAA720(D2PathInfoStrc* pPathInfo); // 0x00679B30

inline const int& PATH_MaxRef(const int& a, const int& b)
{
    return a > b ? a : b;
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

// 0x006793E0
static int __stdcall sub_6FDAA880(D2PathPointStrc tPoint, int* pTestDir, int* pDirection, D2PathInfoStrc* pPathInfo)
{
    D2_ASSERT(((pPathInfo->pDynamicPath->pUnit && pPathInfo->pDynamicPath->pUnit->dwUnitType == 0) || (pPathInfo->pDynamicPath->pUnit && pPathInfo->pDynamicPath->pUnit->dwUnitType == 1)) != 0, 52);

    D2ActiveRoomStrc* pRoom = pPathInfo->pStartRoom;
    const int nCollisionPattern = pPathInfo->nCollisionPattern;
    const int nCollisionMask = pPathInfo->nCollisionMask;

    const int nX0 = (unsigned short)(tPoint.X + gatDirectionToOffset[pTestDir[0]].nX);
    const int nY0 = (unsigned short)(tPoint.Y + gatDirectionToOffset[pTestDir[0]].nY);
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, nX0, nY0, nCollisionPattern, nCollisionMask))
    {
        *pDirection = pTestDir[0];
        return 1;
    }

    const int nX1 = (unsigned short)(tPoint.X + gatDirectionToOffset[pTestDir[1]].nX);
    const int nY1 = (unsigned short)(tPoint.Y + gatDirectionToOffset[pTestDir[1]].nY);
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, nX1, nY1, nCollisionPattern, nCollisionMask))
    {
        *pDirection = pTestDir[1];
        return 1;
    }

    D2_ASSERT(pTestDir[2] != 0xFF, 76);

    const int nX2 = (unsigned short)(tPoint.X + gatDirectionToOffset[pTestDir[2]].nX);
    const int nY2 = (unsigned short)(tPoint.Y + gatDirectionToOffset[pTestDir[2]].nY);
    if (!COLLISION_CheckAnyCollisionWithPattern(pRoom, nX2, nY2, nCollisionPattern, nCollisionMask))
    {
        *pDirection = pTestDir[2];
        return 1;
    }

    return 0;
}

static __forceinline int PATH_TestCollision(const D2CollisionTestStrc* pTest, int nX, int nY)
{
    return COLLISION_CheckAnyCollisionWithPattern(pTest->pRoom, nX, nY, pTest->nCollisionPattern, pTest->nCollisionMask);
}

static int __stdcall PATH_RayTrace(D2PathPointStrc tStartCoord, D2PathPointStrc* pPathDestination, D2DynamicPathStrc* pDynamicPath); // 0x00679720
static int __stdcall PATH_RayTrace(D2PathPointStrc tStartCoord, D2PathPointStrc* pPathDestination, D2DynamicPathStrc* pDynamicPath)
{
    D2CollisionTestStrc tTest;
    tTest.pRoom = pDynamicPath->pRoom;
    tTest.nCollisionPattern = pDynamicPath->dwCollisionPattern;
    tTest.nCollisionMask = pDynamicPath->nMoveTestCollisionMask;
    const D2PathPointStrc tTargetPoint = *pPathDestination;

    D2PathPointStrc tLastPointWithoutCollision = tStartCoord;
    D2PathPointStrc tCurPoint = tStartCoord;
    const int nDeltaX = tTargetPoint.X - tStartCoord.X;
    const int nDeltaY = tTargetPoint.Y - tStartCoord.Y;
    const int nPointsX = (nDeltaX < 0 ? -nDeltaX : nDeltaX) + 1;
    const int nPointsY = (nDeltaY < 0 ? -nDeltaY : nDeltaY) + 1;

    if (nPointsX > nPointsY)
    {
        if (nDeltaX == 0)
        {
            const int nYIncrement = 2 * (nDeltaY >= 0) - 1;
            if (tStartCoord.Y != tTargetPoint.Y)
            {
                do
                {
                    tCurPoint.Y += nYIncrement;
                    if (PATH_TestCollision(&tTest, tStartCoord.X, tCurPoint.Y))
                    {
                        *pPathDestination = tLastPointWithoutCollision;
                        return 0;
                    }
                    tLastPointWithoutCollision = tCurPoint;
                }
                while (tCurPoint.Y != tTargetPoint.Y);
            }
        }
        else
        {
            const int nXIncrement = 2 * (nDeltaX >= 0) - 1;
            const int nYIncrement = 2 * (nDeltaY >= 0) - 1;
            if (tStartCoord.X != tTargetPoint.X)
            {
                int nYOffset = nPointsY;
                while (1)
                {
                    tCurPoint.X += nXIncrement;
                    if (PATH_TestCollision(&tTest, tCurPoint.X, tCurPoint.Y))
                    {
                        *pPathDestination = tLastPointWithoutCollision;
                        return 0;
                    }
                    nYOffset += nPointsY;
                    if (nYOffset >= nPointsX)
                    {
                        nYOffset -= nPointsX;
                        tCurPoint.Y += nYIncrement;
                        if (nYOffset > 0)
                        {
                            if (PATH_TestCollision(&tTest, tCurPoint.X, tCurPoint.Y))
                            {
                                *pPathDestination = tLastPointWithoutCollision;
                                return 0;
                            }
                        }
                    }
                    tLastPointWithoutCollision = tCurPoint;
                    if (tCurPoint.X == tTargetPoint.X)
                    {
                        return 1;
                    }
                }
            }
        }
        return 1;
    }

    if (nPointsX >= nPointsY)
    {
        const int nXIncrement = 2 * (nDeltaX >= 0) - 1;
        const int nYIncrement = 2 * (nDeltaY >= 0) - 1;
        if (tStartCoord.X == tTargetPoint.X)
        {
            return 1;
        }

        do
        {
            tCurPoint.Y += nYIncrement;
            tCurPoint.X += nXIncrement;
            if (PATH_TestCollision(&tTest, tCurPoint.X, tCurPoint.Y))
            {
                *pPathDestination = tLastPointWithoutCollision;
                return 0;
            }
            tLastPointWithoutCollision = tCurPoint;
        }
        while (tCurPoint.X != tTargetPoint.X);
        return 1;
    }

    if (nDeltaY == 0)
    {
        const int nXIncrement = 2 * (nDeltaX >= 0) - 1;
        if (tStartCoord.X == tTargetPoint.X)
        {
            return 1;
        }

        do
        {
            tCurPoint.X += nXIncrement;
            if (PATH_TestCollision(&tTest, tCurPoint.X, tStartCoord.Y))
            {
                *pPathDestination = tLastPointWithoutCollision;
                return 0;
            }
            tLastPointWithoutCollision = tCurPoint;
        }
        while (tCurPoint.X != tTargetPoint.X);
        return 1;
    }

    const int nXIncrement = 2 * (nDeltaX >= 0) - 1;
    const int nYIncrement = 2 * (nDeltaY >= 0) - 1;
    if (tStartCoord.Y == tTargetPoint.Y)
    {
        return 1;
    }

    int nEndOffsetX = nPointsX;
    do
    {
        tCurPoint.Y += nYIncrement;
        if (PATH_TestCollision(&tTest, tCurPoint.X, tCurPoint.Y))
        {
            *pPathDestination = tLastPointWithoutCollision;
            return 0;
        }

        nEndOffsetX += nPointsX;
        if (nEndOffsetX >= nPointsY)
        {
            nEndOffsetX -= nPointsY;
            tCurPoint.X += nXIncrement;
            if (nEndOffsetX > 0)
            {
                if (PATH_TestCollision(&tTest, tCurPoint.X, tCurPoint.Y))
                {
                    *pPathDestination = tLastPointWithoutCollision;
                    return 0;
                }
            }
        }
        tLastPointWithoutCollision = tCurPoint;
    }
    while (tCurPoint.Y != tTargetPoint.Y);
    return 1;
}

// 0x00679A60
static int PATH_CheckCollisionsToNextPosition(D2DynamicPathStrc* pDynamicPath, D2PathPointStrc* pGameCoord)
{
    D2PathPointStrc tPoint;

    D2_ASSERT(((pDynamicPath->pUnit && pDynamicPath->pUnit->dwUnitType == 0) || (pDynamicPath->pUnit && pDynamicPath->pUnit->dwUnitType == 1)) != 0, 324);
    D2_ASSERT(pDynamicPath->eType != 4, 325);
    D2_ASSERT(pGameCoord->X != 0, 326);
    D2_ASSERT(pGameCoord->Y != 0, 327);

    if (!pDynamicPath->dwVelocity)
    {
        pGameCoord->X = pDynamicPath->wPosX;
        pGameCoord->Y = pDynamicPath->wPosY;
        return 0;
    }

    PATH_ComputeVelocityAndDirectionVectorsToNextPoint(pDynamicPath, 1, 1);

    if (!pDynamicPath->dwVelocity)
    {
        pGameCoord->X = pDynamicPath->wPosX;
        pGameCoord->Y = pDynamicPath->wPosY;
        return 0;
    }

    tPoint.X = pDynamicPath->wPosX;
    tPoint.Y = pDynamicPath->wPosY;
    return PATH_RayTrace(tPoint, pGameCoord, pDynamicPath);
}

// 0x00679C80
int __fastcall PATH_Toward_6FDAA9F0(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pPath = pPathInfo->pDynamicPath;
    pPath->dwCurrentPointIdx = 0;
    pPath->dwPathPoints = 0;
    if (pPath->nDirOffset)
        return sub_6FDAA720(pPathInfo);
    D2PathPointStrc nNextPoint = pPathInfo->tTargetCoord;
    pPath->PathPoints[0] = nNextPoint;

    if (PATH_CheckCollisionsToNextPosition(pPath, &nNextPoint))
    {
        pPath->PathPoints[pPath->dwPathPoints] = nNextPoint;
        pPath->dwPathPoints++;
        return pPath->dwPathPoints;
    }

    if (PATH_GetTableHeuristic(nNextPoint, pPathInfo->tTargetCoord) <= pPathInfo->field_14)
    {
        pPath->PathPoints[pPath->dwPathPoints] = nNextPoint;
        pPath->dwPathPoints++;
        return pPath->dwPathPoints;
    }

    {
        D2PathPointStrc tPoint = pPathInfo->tStartCoord;
        D2PathPointStrc tCurCoords = pPathInfo->tStartCoord;
        if (tCurCoords.X != nNextPoint.X || tCurCoords.Y != nNextPoint.Y)
        {
            pPath->PathPoints[pPath->dwPathPoints++] = nNextPoint;
            tPoint = nNextPoint;
            tCurCoords = nNextPoint;
        }
        nNextPoint = pPathInfo->tTargetCoord;
        int nPrevDir = 0xFF;
        int nNewPointsCount = pPath->dwPathPoints;
        const int nDistMax = pPathInfo->nDistMax;
        int bNotStraightLine = 0;
        int nCurDist = 0;
        if (nDistMax > 0)
        {
            D2PathPointStrc* pPathPointsEnd = &pPath->PathPoints[pPath->dwPathPoints];
            do
            {
                if (tCurCoords.X == nNextPoint.X && tCurCoords.Y == nNextPoint.Y)
                    break;
                bNotStraightLine = 0;
                int aTestDir[3];
                PATH_GetDirections_6FDAB790(aTestDir, tPoint, nNextPoint);
                int nDirection;
                if (!sub_6FDAA880(tPoint, aTestDir, &nDirection, pPathInfo) || ((nDirection - 4) & 7) == nPrevDir)
                    goto LABEL_20;
                tCurCoords.X += gatDirectionToOffset[nDirection].nX;
                tCurCoords.Y += gatDirectionToOffset[nDirection].nY;
                if (nDirection != nPrevDir)
                {
                    const D2PathPointStrc tPrev = tPoint;
                    if (tPrev.X != pPathInfo->tStartCoord.X || tPrev.Y != pPathInfo->tStartCoord.Y)
                    {
                        *pPathPointsEnd = tPoint;
                        ++nNewPointsCount;
                        ++pPathPointsEnd;
                    }
                    bNotStraightLine = 1;
                }
                tPoint = tCurCoords;
                nPrevDir = nDirection;
                ++nCurDist;
            } while (nCurDist < nDistMax);
            if (bNotStraightLine)
                goto LABEL_STORE;
        LABEL_20:
            if (nCurDist)
                pPath->PathPoints[nNewPointsCount++] = tPoint;
        }
    LABEL_STORE:
        pPath->dwPathPoints = nNewPointsCount;
        return nNewPointsCount;
    }
}

// 0x00679F70
int __fastcall PATH_Leap_6FDAB1E0(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pDynamicPath = pPathInfo->pDynamicPath;
    pDynamicPath->dwCurrentPointIdx = 0;
    D2PathPointStrc pGameCoord = pPathInfo->tTargetCoord;
    pDynamicPath->PathPoints[0] = pGameCoord;
    PATH_CheckCollisionsToNextPosition(pDynamicPath, &pGameCoord);
    if (pPathInfo->tStartCoord.X == pGameCoord.X && pPathInfo->tStartCoord.Y == pGameCoord.Y)
    {
        return 0;
    }

    pDynamicPath->PathPoints[0] = pGameCoord;
    pDynamicPath->dwPathPoints = 1;
    return pDynamicPath->dwPathPoints;
}

// 0x00679FD0
int __fastcall PATH_Knockback_Client(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pDynamicPath = pPathInfo->pDynamicPath;
    pDynamicPath->dwCurrentPointIdx = 0;
    pDynamicPath->PathPoints[0] = pPathInfo->tTargetCoord;
    PATH_CheckCollisionsToNextPosition(pDynamicPath, &pDynamicPath->PathPoints[0]);
    return 1;
}

static __forceinline int PATH_ScaleDelta(int nScale, int nDelta, int nMax)
{
    int nResult = nScale;
    nResult *= nDelta;
    return nResult / nMax;
}

#define D2_ABS(x) ((x) < 0 ? -(x) : (x))
#define D2_MAX(a, b) ((a) > (b) ? (a) : (b))

// 0x0067A000
int __fastcall PATH_Knockback_Server(D2PathInfoStrc* pPathInfo)
{
    D2DynamicPathStrc* pDynamicPath = pPathInfo->pDynamicPath;
    int nDeltaX = 0;
    int nDeltaY = 0;
    const int nHalfDist = (pDynamicPath->nDist >> 1) + 1;
    D2PathPointStrc tFinalCoords;
    if ((pDynamicPath ? pDynamicPath->hTarget : 0))
    {
        tFinalCoords = pPathInfo->tStartCoord;

        const int nTargetUnitX = UNITS_GetXPositionInline((pDynamicPath ? pDynamicPath->hTarget : 0));
        const int nTargetUnitY = UNITS_GetYPositionInline((pDynamicPath ? pDynamicPath->hTarget : 0));
        nDeltaX = pPathInfo->tStartCoord.X - nTargetUnitX;
        nDeltaY = pPathInfo->tStartCoord.Y - nTargetUnitY;
        if (const int nMax = D2_MAX(D2_ABS(nDeltaX), D2_ABS(nDeltaY)))
        {
            nDeltaX = PATH_ScaleDelta(nHalfDist, nDeltaX, nMax);
            nDeltaY = PATH_ScaleDelta(nHalfDist, nDeltaY, nMax);
        }
        tFinalCoords.X += nDeltaX;
        tFinalCoords.Y += nDeltaY;
    }
    else
    {
        tFinalCoords = pPathInfo->tTargetCoord;
    }

    pDynamicPath->PathPoints[0] = tFinalCoords;
    PATH_RayTrace(pPathInfo->tStartCoord, &tFinalCoords, pDynamicPath);
    D2COMMON_10170_PathSetTargetPos(pDynamicPath, tFinalCoords.X, tFinalCoords.Y);
    if (tFinalCoords.X == pPathInfo->tStartCoord.X && tFinalCoords.Y == pPathInfo->tStartCoord.Y)
    {
        return 0;
    }

    pDynamicPath->PathPoints[0] = tFinalCoords;
    pDynamicPath->dwPathPoints = 1;
    return pDynamicPath->dwPathPoints;
}
