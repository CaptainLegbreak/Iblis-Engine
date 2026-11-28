#include "Storm.h"
#include "D2GameTypes.h"
#include "D2StormLink.h"

struct HWND__;
struct D2StormLinkStrc;
class TOutputStream;
class THuffmannTree;
struct D2CriticalSectionStrc;
struct D2SLogStrc;
struct D2Field14Strc;
struct D2UnitStrc;

class TOutputStream
{
public:
    TOutputStream(void* pvOutBuffer, unsigned int cbOutLength);                                             // 0x0041D920

    unsigned char* pbOutBuffer;
    unsigned int cbOutSize;
    unsigned char* pbOutPos;
    unsigned int BitBuffer;
    unsigned int BitCount;
};

class THuffmannTree
{
public:
    THuffmannTree();                                                                                        // 0x0041F4A0
    ~THuffmannTree();                                                                                       // 0x0041F6A0
    unsigned int Compress(TOutputStream* os, void* pvInBuffer, int cbInBuffer, unsigned char nCmpType);    // 0x0041F850

    unsigned int adwData[0x3474 / 4];
};

typedef int (__stdcall* SMSGHANDLER)(void* pParams);

inline void* operator new(unsigned int, void* pWhere) throw()
{
    return pWhere;
}

#include "D2StormBigBuffer.h"

// 0x0041F980
void __fastcall HuffmanCompress(void* pvOutBuffer, int* pcbOutBuffer, void* pvInBuffer, int cbInBuffer, int* pCmpType, int nCmpLevel)
{
    TOutputStream os(pvOutBuffer, *pcbOutBuffer);
    THuffmannTree ht;
    *pcbOutBuffer = ht.Compress(&os, pvInBuffer, cbInBuffer, *pCmpType);
}

// 0x00420E70
int* __fastcall MONSTERMODE_GetTargetTimerPtr(D2Field14Strc* pRecord)
{
    return &pRecord->nField14;
}

static inline int MONSTERMODE_IsActionFrame(D2UnitStrc* pUnit)
{
    if (pUnit && pUnit->dwAnimMode == 14)
        return (pUnit->dwFlags >> 6) & 1;
    return pUnit->nActionFrame == 1;
}

// build: symbol ?BigIsEven@* 0x00421440
static int BigIsEven(const BigBuffer& a)
{
    return !a.Count() || !(a[0] & 1);
}
