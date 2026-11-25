#include "SRP.h"
#include "D2BnCryptTypes.h"

void* __stdcall SMemAlloc(unsigned int nSize, const char* szFile, int nLine, unsigned int nFlags);         // 0x00413020

#define rol(value, bits) _rotl(value, bits)

#define blk0(i) (block->l[i] = (rol(block->l[i],24)&0xFF00FF00)|(rol(block->l[i],8)&0x00FF00FF))

#define blk(i) (block->l[i&15] = rol(block->l[(i+13)&15]^block->l[(i+8)&15]^block->l[(i+2)&15]^block->l[i&15],1))

#define blkF(i) (block->l[i&15] = rol(block->l[(i+13)&15]^block2->l[(i+8)&15]^block2->l[(i+2)&15]^block->l[i&15],1))

#define R0(v,w,x,y,z,i) z+=((w&(x^y))^y)+blk0(i)+0x5A827999+rol(v,5);w=rol(w,30);

#define R1(v,w,x,y,z,i) z+=((w&(x^y))^y)+blk(i)+0x5A827999+rol(v,5);w=rol(w,30);

#define R4F(v,w,x,y,z,i) z+=(w^x^y)+blkF(i)+0xCA62C1D6+rol(v,5);w=rol(w,30);

#define R2(v,w,x,y,z,i) z+=(w^x^y)+blk(i)+0x6ED9EBA1+rol(v,5);w=rol(w,30);

#define R3(v,w,x,y,z,i) z+=(((w|x)&y)|(w&x))+blk(i)+0x8F1BBCDC+rol(v,5);w=rol(w,30);

#define R4(v,w,x,y,z,i) z+=(w^x^y)+blk(i)+0xCA62C1D6+rol(v,5);w=rol(w,30);

struct D2BigServerRecordStrc;

struct D2BigServerHandlesStrc;

struct D2SrpSha1ContextStrc;

int __stdcall SMemFree(void* pMemory, const char* szFile, int nLine, unsigned int nFlags); // 0x00412650

struct D2BigServerRecordStrc
{
    unsigned char abSalt[0x20];
    unsigned char abVerifier[0x20];
    char szName[0x20];
    unsigned char abClientPublic[0x20];
    unsigned char abPrivate[0x20];
    unsigned char abServerPublic[0x20];
    unsigned char abKey[0x28];
    unsigned char abClientProof[0x14];
    unsigned char abServerProof[0x14];
};

int __fastcall sub_0052A350_BigOp_423790(void* hResult, void* hLeft, void* hRight); // 0x0052A350

int __fastcall sub_0052A3B0_BigOp_423AC0(void* hResult, void* hLeft, void* hRight); // 0x0052A3B0

extern "C" int __cdecl memcmp(const void* pBuffer1, const void* pBuffer2, unsigned int nSize);

struct D2BigServerHandlesStrc
{
    void* hClientPublic;
    void* hVerifier;
    void* hServerPublic;
    void* hPrivate;
};

unsigned char* __fastcall SHA_Interleave(unsigned char* pDest, const unsigned char* pData, unsigned int nSize); // 0x0052A120

extern "C" unsigned int __cdecl _rotl(unsigned int nValue, int nShift);

struct D2SrpSha1ContextStrc
{
    unsigned int aState[5];
    unsigned int aCount[2];
    unsigned char aBuffer[64];
};

struct D2Blob32Strc
{
    unsigned char abData[0x20];
};

struct D2BigRecordStrc
{
    D2Blob32Strc tFirst;
    D2Blob32Strc tSecond;
    char szName[0x20];
    D2Blob32Strc tThird;
};

void __fastcall sub_0052A590_BigOp_425330(void* hResult, void* hArg1, void* hArg2, void* hArg3);           // 0x0052A590
unsigned int __fastcall sub_0052A2A0_BigToBinary(void* hBig, void* pBuffer, unsigned int nSize);            // 0x0052A2A0
void* __fastcall sub_0052A270_BigFromBinary(const void* pData, unsigned int nSize);                         // 0x0052A270
int __fastcall sub_0052A2F0_BigCompareUnsigned(void* hBig, unsigned int nValue);                            // 0x0052A2F0
unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nDestSize);                // 0x004135D0

inline void* operator new(unsigned int nSize, void* pWhere) throw()
{
    return pWhere;
}

// 0x00528010
void D2BigPowModStrc::sub_00528010_PowMod(void* const& hExp, void* const& hResult)
{
    sub_0052A590_BigOp_425330(hResult, hBase, hExp, hModulus);
}

// 0x005281D0
int D2BigPowModStrc::sub_005281D0_ComputeServerKey(void* const& hClientPublic, void* const& hServerPublic, void* const& hSecret, void* const& hVerifier, void* const& hKey)
{
    unsigned int nHash;
    sub_00528030_HashToUInt(hServerPublic, &nHash);
    const unsigned int nScrambler = nHash;
    if (!nScrambler)
        return 0;
    void* hTemp = sub_0052A240_BigFromUnsigned(0);
    sub_0052A5B0_BigOpUnsigned_425330(hTemp, hVerifier, nScrambler, hModulus);
    sub_0052A560_BigOpPair_424F10_424ED0(hTemp, hClientPublic, hTemp, hModulus);
    if (sub_0052A2F0_BigCompareUnsigned(hTemp, 1) <= 0)
    {
        GAME_DeleteBigNum(hTemp);
        return 0;
    }
    void* hCheck = sub_0052A240_BigFromUnsigned(0);
    sub_0052A370_BigOpUnsigned_423790(hCheck, hTemp, 1);
    if (!sub_0052A2E0_BigCompare(hCheck, hModulus))
    {
        GAME_DeleteBigNum(hCheck);
        GAME_DeleteBigNum(hTemp);
        return 0;
    }
    GAME_DeleteBigNum(hCheck);
    sub_0052A590_BigOp_425330(hKey, hTemp, hSecret, hModulus);
    GAME_DeleteBigNum(hTemp);
    return 1;
}

// 0x00528500
D2BigPairStrc::D2BigPairStrc()
{
    void* pMemory = SMemAlloc(sizeof(D2BigPowModStrc), ".\\SRP.cpp", 0x157, 0);
    pState = pMemory ? new (pMemory) D2BigPowModStrc : 0;
}

// 0x005284F0
int __fastcall sub_005284F0_IsValid(D2BigPowModStrc* pState)
{
    return pState->bValid != 0;
}

// 0x00528550
int D2BigPairStrc::sub_00528550_ReadBoth(unsigned int* pnFirst, void* pFirst, unsigned int* pnSecond, void* pSecond)
{
    if (!pState->bValid)
        return 0;
    *pnFirst = sub_0052A2A0_BigToBinary(pState->hBase, pFirst, 0x20);
    *pnSecond = sub_0052A2A0_BigToBinary(pState->hModulus, pSecond, 0x20);
    return 1;
}

// 0x005285A0
int D2BigPairStrc::sub_005285A0_Init(int nSize1, const unsigned char* pData1, int nSize2, const unsigned char* pData2)
{
    if (pState->bValid)
    {
        GAME_DeleteBigNum(pState->hModulus);
        GAME_DeleteBigNum(pState->hBase);
    }
    pState->hBase = sub_0052A270_BigFromBinary(pData1, nSize1);
    pState->hModulus = sub_0052A270_BigFromBinary(pData2, nSize2);
    pState->bValid = 1;
    if (!sub_005284F0_IsValid(pState))
    {
        GAME_DeleteBigNum(pState->hModulus);
        GAME_DeleteBigNum(pState->hBase);
        pState->bValid = 0;
    }
    return pState->bValid;
}

// 0x00528660
void D2BigPairStrc::MakeVerifier(const char* szName, const char* szPassword, unsigned char* pSalt, unsigned char* pVerifier)
{
    sub_00527E70_RandomBytes(pSalt, 0x20);
    void* hExp;
    pState->sub_00527F40_ComputePrivateKey(pSalt, szName, szPassword, &hExp);
    void* hVerifier = sub_0052A240_BigFromUnsigned(0);
    {
        void* hResult = hVerifier;
        pState->sub_00528010_PowMod(hExp, hResult);
    }
    sub_0052A2A0_BigToBinary(hVerifier, pVerifier, 0x20);
    GAME_DeleteBigNum(hExp);
    GAME_DeleteBigNum(hVerifier);
}

inline void D2BigPowModStrc::operator delete(void* pMemory)
{
    SMemFree(pMemory, "delete", -1, 0);
}

// 0x00528620
void D2BigPairStrc::sub_00528620_InitRandom(unsigned int nSeed)
{
    pState->sub_00527DD0_InitRandom(nSeed);
}

// 0x00528530
D2BigPairStrc::~D2BigPairStrc()
{
    if (pState)
    {
        delete pState;
    }
}

// 0x00528630
void D2BigPairStrc::sub_00528630_Release()
{
    if (pState->bValid)
    {
        GAME_DeleteBigNum(pState->hModulus);
        GAME_DeleteBigNum(pState->hBase);
    }
    pState->bValid = 0;
}

// 0x00528970
int __stdcall sub_00528970_FillRecord(D2BigRecordStrc* pRecord, const char* szName, const D2Blob32Strc* pFirst, const D2Blob32Strc* pSecond, const D2Blob32Strc* pThird)
{
    SStrCopy(pRecord->szName, szName, 0x7FFFFFFF);
    pRecord->tFirst = *pFirst;
    pRecord->tSecond = *pSecond;
    pRecord->tThird = *pThird;
    void* hBig = sub_0052A270_BigFromBinary(pThird, 0x20);
    const int nResult = sub_0052A2F0_BigCompareUnsigned(hBig, 0);
    GAME_DeleteBigNum(hBig);
    return nResult == 1;
}

// 0x005289F0
void D2BigPairStrc::sub_005289F0_ComputeServerPublic(D2BigServerRecordStrc* pRecord)
{
    void* hVerifier = sub_0052A270_BigFromBinary(pRecord->abVerifier, 0x20);
    sub_00527E70_RandomBytes(pRecord->abPrivate, 0x20);
    void* hPrivate = sub_0052A270_BigFromBinary(pRecord->abPrivate, 0x20);
    void* hPublic = sub_0052A240_BigFromUnsigned(0);
    sub_0052A590_BigOp_425330(hPublic, pState->hBase, hPrivate, pState->hModulus);
    sub_0052A350_BigOp_423790(hPublic, hPublic, hVerifier);
    while (sub_0052A2E0_BigCompare(hPublic, pState->hModulus) > 0)
        sub_0052A3B0_BigOp_423AC0(hPublic, hPublic, pState->hModulus);
    GAME_DeleteBigNum(hPrivate);
    GAME_DeleteBigNum(hVerifier);
    sub_0052A2A0_BigToBinary(hPublic, pRecord->abServerPublic, 0x20);
    GAME_DeleteBigNum(hPublic);
}

// 0x00528C60
void D2BigPairStrc::sub_00528C60_ComputeServerProof(D2BigServerRecordStrc* pRecord)
{
    pState->sub_00528480_HashThreeBlocks(pRecord->abClientPublic, pRecord->abClientProof, pRecord->abKey, pRecord->abServerProof);
}

// 0x00528AC0
int D2BigPairStrc::sub_00528AC0_VerifyClientProof(D2BigServerRecordStrc* pRecord, const unsigned char* pClientProof)
{
    unsigned char abKey[0x20];
    void* hKey = sub_0052A240_BigFromUnsigned(0);
    D2BigServerHandlesStrc tHandles;
    tHandles.hVerifier = sub_0052A270_BigFromBinary(pRecord->abVerifier, 0x20);
    tHandles.hPrivate = sub_0052A270_BigFromBinary(pRecord->abPrivate, 0x20);
    tHandles.hServerPublic = sub_0052A270_BigFromBinary(pRecord->abServerPublic, 0x20);
    tHandles.hClientPublic = sub_0052A270_BigFromBinary(pRecord->abClientPublic, 0x20);
    pState->sub_005281D0_ComputeServerKey(tHandles.hClientPublic, tHandles.hServerPublic, tHandles.hPrivate, tHandles.hVerifier, hKey);
    GAME_DeleteBigNum(tHandles.hClientPublic);
    GAME_DeleteBigNum(tHandles.hServerPublic);
    GAME_DeleteBigNum(tHandles.hPrivate);
    GAME_DeleteBigNum(tHandles.hVerifier);
    const unsigned int nSize = sub_0052A2A0_BigToBinary(hKey, abKey, 0x20);
    GAME_DeleteBigNum(hKey);
    SHA_Interleave(pRecord->abKey, abKey, nSize);
    pState->sub_005282A0_ComputeProof(pRecord->szName, pRecord->abSalt, pRecord->abClientPublic, pRecord->abServerPublic, pRecord->abKey, pRecord->abClientProof);
    return memcmp(pRecord->abClientProof, pClientProof, sizeof(pRecord->abClientProof)) == 0;
}

#include "gen/data/Source/SRP/SRP.inc"
