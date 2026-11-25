#include "D2Net.h"

#include "D2GameServer.h"

struct D2NetLockStrc;

struct D2Net52BE10Strc;

struct D2NetLockStrc
{
    D2CriticalSectionStrc tLock;

    void Lock(int nUnused);
    void Unlock(int nUnused);
};

struct D2Net52BE10Strc
{
    char unk0x00[0xD0];
    char aData[4];
};

extern int gdwGlobal_00882D14; // 0x00882D14

#include "gen/data/Source/D2Net/Unknown_0052BDA0.inc"

// 0x0052BDA0
void __cdecl sub_0052BDA0_Empty()
{
}

// 0x0052BDB0
void __cdecl sub_0052BDB0_Empty()
{
}

// 0x0052BDC0
int __cdecl sub_0052BDC0()
{
    return gdwGlobal_00882D14;
}

// 0x0052BDD0
bool __stdcall sub_0052BDD0_AlwaysTrue(int nUnused)
{
    return true;
}

// 0x0052BDE0
void D2NetLockStrc::Lock(int nUnused)
{
    EnterCriticalSection(&tLock);
}

// 0x0052BDF0
void D2NetLockStrc::Unlock(int nUnused)
{
    LeaveCriticalSection(&tLock);
}

// 0x0052BE00
unsigned int __fastcall NET_GetBits12(unsigned int nValue)
{
    return (nValue >> 12) & 7;
}

// 0x0052BE10
char* __fastcall NET_GetField0D0(D2Net52BE10Strc* pRecord)
{
    return pRecord->aData;
}
