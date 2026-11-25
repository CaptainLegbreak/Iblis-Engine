#include "D2Common.h"
#include "D2Structs.h"
#include "D2Path.h"
#include "D2Structs.h"
struct D2ActiveRoomStrc;

#define MS_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2UnitStrc;
struct D2PathPointStrc;
struct D2MissileStreamStrc;



struct D2MissileStreamStrc
{
    int* pData;
    int nCapacity;
};

typedef int(__fastcall* MISSTREAM_HIT)(D2UnitStrc* pUnit, D2UnitStrc* pTarget);

typedef int(__fastcall* MISSTREAM_TEST)(D2UnitStrc* pUnit, void* pArg);

typedef int(__fastcall* MISSTREAM_CREATE)(D2UnitStrc* pUnit, int nPrevious, int nX, int nY, int nRange, int nType, char nDirection);

typedef void(__fastcall* MISSTREAM_RELEASE)(int nHandle);

D2MissileStreamStrc* __fastcall MISSILE_GetStream(D2UnitStrc* pMissile); // 0x0064A6F0
void __fastcall MISSILE_SetStream(D2UnitStrc* pMissile, D2MissileStreamStrc* pStream); // 0x0064A6D0
void* __fastcall FOG_AllocPool(void* pMemPool, int nSize, const char* szFile, int nLine, int n0); // 0x0040B430
void __fastcall FOG_FreePool(void* pMemPool, void* pMemory, const char* szFile, int nLine, int n0); // 0x0040B480
void* __fastcall FOG_ReallocPool(void* pMemPool, void* pMemory, int nSize, const char* szFile, int nLine, int n0); // 0x0040B4B0
void __stdcall PATH_SetType(D2DynamicPathStrc* pPath, int nType); // 0x00648CF0
void __stdcall D2Common_10142(D2DynamicPathStrc* pPath, D2UnitStrc* pUnit, int bAllowInTown); // 0x00649970
int __stdcall PATH_GetPathPoints(D2DynamicPathStrc* pPath, D2PathPointStrc** ppPathPoints); // 0x006487D0
D2ActiveRoomStrc* __stdcall UNITS_GetRoom(D2UnitStrc* pUnit); // 0x00620BB0
unsigned short __stdcall COLLISION_CheckMaskWithSize(D2ActiveRoomStrc* pRoom, int nX, int nY, int nUnitSize, unsigned short nMask); // 0x0064D9B0
D2UnitStrc* __stdcall D2Common_10407(D2ActiveRoomStrc* pRoom, int nX, int nY, MISSTREAM_TEST pfTest, void* pArg, int nPattern); // 0x00641CB0
int __stdcall PATH_ComputeDirection(int nX1, int nY1, int nX2, int nY2); // 0x0064FDC0
extern "C" __declspec(dllimport) int __stdcall IsBadCodePtr(void* lpfn); // 0x006CC34C
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize); // 0x00681EF0
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" const char* __cdecl sub_00408090(); // 0x00408090
extern "C" void __cdecl FOG_DisplayHalt(const char* szText, const char* szFile, int nLine); // 0x00408A60
extern "C" __declspec(noreturn) void __cdecl exit(int nCode); // 0x00681E09

typedef int (__fastcall* D2StreamCreate)(D2UnitStrc*, int, int, int, int, int, char);

typedef void (__fastcall* D2StreamFree)(int);
extern const char gszAssertExpression_006CC837[]; // 0x006CC837
extern const char gszMisStreamSourceFile[]; // 0x006EE540

// 0x00663D40
void __stdcall MISSTREAM_AllocMissileStream(D2UnitStrc* pMissile)
{
    if (!MISSILE_GetStream(pMissile))
    {
        D2MissileStreamStrc* pStream = (D2MissileStreamStrc*)FOG_AllocPool((pMissile == 0 ? 0 : pMissile->pMemoryPool), sizeof(D2MissileStreamStrc), ".\\UNITS\\MisStream.cpp", 46, 0);
        memset(pStream, 0, sizeof(D2MissileStreamStrc));
        MISSILE_SetStream(pMissile, pStream);
    }
}

// 0x00663D90
void __stdcall MISSTREAM_FreeMissileStream(D2UnitStrc* pMissile)
{
    D2MissileStreamStrc* pStream = MISSILE_GetStream(pMissile);
    if (pStream)
    {
        if (pStream->pData)
        {
            FOG_FreePool((pMissile == 0 ? 0 : pMissile->pMemoryPool), pStream->pData, ".\\UNITS\\MisStream.cpp", 59, 0);
        }

        FOG_FreePool((pMissile == 0 ? 0 : pMissile->pMemoryPool), pStream, ".\\UNITS\\MisStream.cpp", 60, 0);
    }
}

// 0x00663DF0
int __fastcall MISSTREAM_Return1(D2UnitStrc* pUnit, void* pArg)
{
    return 1;
}

// 0x00663E00
void __stdcall MISSTREAM_ExecuteHit(D2UnitStrc* pUnit, int nCollisionMask, int nCollisionPattern, MISSTREAM_HIT pfnHit)
{
    D2PathPointStrc* pPathPoints;
    D2DynamicPathStrc* pPath = pUnit->pDynamicPath;
    PATH_SetType(pPath, 16);
    D2Common_10142(pPath, pUnit, 0);
    int nPathPoints = PATH_GetPathPoints(pPath, &pPathPoints);
    D2ActiveRoomStrc* pRoom = UNITS_GetRoom(pUnit);

    for (int i = 0; i < nPathPoints; ++i)
    {
        int nX = pPathPoints[i].X;
        int nY = pPathPoints[i].Y;
        if (COLLISION_CheckMaskWithSize(pRoom, nX, nY, nCollisionPattern, nCollisionMask))
        {
            D2UnitStrc* pTargetUnit = D2Common_10407(pRoom, nX, nY, MISSTREAM_Return1, 0, nCollisionPattern);
            if (pTargetUnit)
            {
                MS_ASSERT(!IsBadCodePtr((void*)pfnHit), 113);
                pfnHit(pUnit, pTargetUnit);
            }
        }
    }
}

// 0x00663ED0
void __stdcall MISSTREAM_Update(D2UnitStrc* pUnit, D2UnitStrc* pMissile, int nAmount, int nStep, D2StreamCreate pfCreate, D2StreamFree pfFree)
{
    D2PathPointStrc* pPathPoints;
    D2DynamicPathStrc* pPath = pMissile->pDynamicPath;
    PATH_SetType(pPath, 16);
    D2Common_10142(pPath, pMissile, 0);
    int nPathPoints = PATH_GetPathPoints(pPath, &pPathPoints);
    if (nPathPoints != 0 && nPathPoints != 1) {
        D2MissileStreamStrc* ptStream = MISSILE_GetStream(pMissile);
        if (!ptStream) { FOG_DisplayHalt(gszAssertExpression_006CC837, sub_00408090(), 138); exit(-1); }
        int nRatio = nAmount / nStep;
        int bCreate = 0;
        int nTemp = nPathPoints - 1;
        int nPoints = nTemp;
        if (nTemp < nRatio) { nPoints = nRatio; bCreate = 1; }
        if (!ptStream->nCapacity) {
            unsigned int nSize = sizeof(int) * nPoints;
            ptStream->nCapacity = nPoints;
            void* const pPool = pMissile->pMemoryPool;
            ptStream->pData = (int*)FOG_AllocPool(pPool, nSize, gszMisStreamSourceFile, 151, 0);
            memset(ptStream->pData, 0, nSize);
        } else if (ptStream->nCapacity < nPoints) {
            void* const pPool = pMissile->pMemoryPool;
            ptStream->pData = (int*)FOG_ReallocPool(pPool, ptStream->pData, sizeof(int) * nPoints, gszMisStreamSourceFile, 154, 0);
        }
        int nMax = nTemp / nRatio;
        int nExtra = 0;
        if (bCreate) nExtra = 4 * (nRatio - nTemp) / nTemp;
        int nCurrent = nAmount;
        int nCycle = 4;
        if (IsBadCodePtr((void*)pfCreate)) { FOG_DisplayHalt(gszAssertExpression_006CC837, sub_00408090(), 169); exit(-1); }
        int nCounter = 0;
        int nIndex = 0;
        while (nIndex < nTemp) {
            int nX = pPathPoints[nIndex].X;
            int nY = pPathPoints[nIndex].Y;
            char nDirection = (char)PATH_ComputeDirection(pPathPoints[nIndex + 1].X, pPathPoints[nIndex + 1].Y, nX, nY);
            if (nCounter >= nMax && nAmount) {
                nCounter = 1;
                ptStream->pData[nIndex] = pfCreate(pMissile, ptStream->pData[nIndex], nX, nY, nCurrent, 1, nDirection);
                nCurrent -= nStep;
                if (bCreate) {
                    int nRepeat = nExtra / 4;
                    if (nCycle < nExtra % 4) ++nRepeat;
                    --nCycle;
                    if (nCycle <= 0) nCycle = 4;
                    for (int i = 0; i < nRepeat; ++i) {
                        ptStream->pData[nIndex] = pfCreate(pUnit, ptStream->pData[nIndex], nX, nY, nCurrent, 2, nDirection);
                        nCurrent -= nStep;
                    }
                }
            } else {
                ++nCounter;
                ptStream->pData[nIndex] = pfCreate(pUnit, ptStream->pData[nIndex], nX, nY, nCurrent, 0, nDirection);
            }
            ++nIndex;
        }
        while (nIndex < ptStream->nCapacity) {
            pfFree(ptStream->pData[nIndex]);
            ptStream->pData[nIndex] = 0;
            ++nIndex;
        }
    }
}

#include "gen/data/Source/D2Common/UNITS/MisStream.inc"
