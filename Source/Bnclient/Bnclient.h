#pragma once

#include "D2LangTypes.h"
#include "D2BnCryptTypes.h"
#include "D2Win32Base.h"

struct D2LangByteRangeStrc;
struct D2SrpSha1ContextStrc;
struct Unicode;

extern "C" __declspec(dllimport) void __stdcall Sleep(unsigned long dwMilliseconds); // 0x006CC258
extern "C" const char gszEmptyAssertText; // 0x006CC837
extern "C" int __cdecl rand(); // 0x00687461
extern "C" unsigned int __security_cookie; // 0x00749DE0
extern "C" void __cdecl srand(unsigned int nSeed); // 0x00687454
extern "C" void* __cdecl bsearch(const void* pKey, const void* pBase, unsigned int nCount, unsigned int nSize, int (__cdecl* pfCompare)(const void*, const void*)); // 0x006881B1
extern D2LangByteRangeStrc* gpLeadByteRanges; // 0x00882B28
int __cdecl BNSEND_SendCrashDump(); // 0x0051BCF0
int __cdecl sub_00527AE0_CompareKey(const void* pLeft, const void* pRight); // 0x00527AE0
int __fastcall BNSEND_SendPacket(unsigned char nId, const void* pData, unsigned int nSize); // 0x0051C5C0
int __fastcall sub_0051E370_SetText(const char* szText, int nLength); // 0x0051E370
void __fastcall BNDOWNLOAD_RequestDownload(int nType, int nSubType, unsigned int nArg1, unsigned int nArg2, const D2FileTimeStrc* pFileTime, const char* szFile, const char* szLink); // 0x0051F910
int __fastcall BNMESSQUEUE_SetState(int nState); // 0x00520520
int __fastcall BNMESSQUEUE_SetStateArg(void* pArg); // 0x00520550
int __fastcall UNICODE_StrLen(const Unicode* pString); // 0x00526800
int __fastcall GAME_DeleteBigNum(void* pArg); // 0x0052A600
void __fastcall sub_00529F50_Sha1Init(D2SrpSha1ContextStrc* pContext); // 0x00529F50
void __fastcall sub_00529F80_Sha1Update(D2SrpSha1ContextStrc* pContext, const unsigned char* pData, unsigned int nLength); // 0x00529F80
void __fastcall sub_0052A040_Sha1Final(unsigned char* pDigest, D2SrpSha1ContextStrc* pContext); // 0x0052A040

// build: symbol ?FOG_DisplayHalt@* 0x00408A60
#define D2_ASSERT(expr, line) if (!(expr)) { FOG_DisplayHalt(&gszEmptyAssertText, sub_00408090(), line); exit(-1); }

struct D2BigLoginRecordStrc
{
    char szName[0x20];
    char szPassword[0x20];
    unsigned char abPrivate[0x20];
    unsigned char abPublic[0x20];
    unsigned char abKey[0x28];
    unsigned char abProof[0x14];
};

struct D2LangCharMapEntryStrc
{
    unsigned short wValue;
    unsigned short wChar;
};

struct D2SrpSha1ContextStrc
{
    unsigned int aState[5];
    unsigned int aCount[2];
    unsigned char f_1C[64];
};

struct Unicode
{
    unsigned short wChar;

    operator unsigned short() const
    {
        return wChar;
    }
};

void* __fastcall sub_0052A240_BigFromUnsigned(unsigned int nValue); // 0x0052A240
void* __fastcall sub_0052A270_BigFromBinary(const void* pData, unsigned int nSize); // 0x0052A270
unsigned int __fastcall sub_0052A2A0_BigToBinary(void* hBig, void* pBuffer, unsigned int nSize); // 0x0052A2A0
int __fastcall sub_0052A2F0_BigCompareUnsigned(void* hBig, unsigned int nValue); // 0x0052A2F0
