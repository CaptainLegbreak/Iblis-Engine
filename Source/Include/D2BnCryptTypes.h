#pragma once
// Battle.net client big numbers, hashing and IDEA key records

#include "D2Check.h"

struct D2BigLoginRecordStrc;
struct D2BigServerRecordStrc;
struct D2BigPairStrc;
struct D2BnHashCtxStrc;
struct D2IdeaKeyScheduleStrc;
struct D2BigPowModStrc;
struct D2IdeaUserKeyStrc;

struct D2SrpDigestStrc
{
    unsigned char ab[20]; // 0x00
};

struct D2BigPairStrc
{
    D2BigPowModStrc* pState; // 0x00

    D2BigPairStrc(); // 0x00528500
    ~D2BigPairStrc(); // 0x00528530
    void sub_00527E70_RandomBytes(unsigned char* pBuffer, unsigned int nSize); // 0x00527E70
    int sub_00528550_ReadBoth(unsigned int* pnFirst, void* pFirst, unsigned int* pnSecond, void* pSecond); // 0x00528550
    int sub_005285A0_Init(int nSize1, const unsigned char* pData1, int nSize2, const unsigned char* pData2); // 0x005285A0
    void sub_00528620_InitRandom(unsigned int nSeed); // 0x00528620
    void sub_00528630_Release(); // 0x00528630
    void MakeVerifier(const char* szName, const char* szPassword, unsigned char* pSalt, unsigned char* pVerifier); // 0x00528660
    void sub_005286D0_InitLogin(D2BigLoginRecordStrc* pRecord, const char* szName, const char* szPassword); // 0x005286D0
    int sub_00528760_ComputeLoginProof(D2BigLoginRecordStrc* pRecord, const unsigned char* pSalt, const unsigned char* pServerPublic); // 0x00528760
    int sub_00528890_CompareServerProof(const D2BigLoginRecordStrc* pRecord, const unsigned char* pServerProof); // 0x00528890
    void sub_005289F0_ComputeServerPublic(D2BigServerRecordStrc* pRecord); // 0x005289F0
    int sub_00528AC0_VerifyClientProof(D2BigServerRecordStrc* pRecord, const unsigned char* pClientProof); // 0x00528AC0
    void sub_00528C60_ComputeServerProof(D2BigServerRecordStrc* pRecord); // 0x00528C60
};

struct D2BnHashCtxStrc
{
    unsigned int aState[5]; // 0x00
    int nBitCountLo; // 0x14
    int nBitCountHi; // 0x18
    int aBlock[16]; // 0x1C
};

struct D2IdeaKeyScheduleStrc
{
    unsigned short aKey[52]; // 0x00
};

struct D2BigPowModStrc
{
    int bValid; // 0x00
    void* hBase; // 0x04
    void* hModulus; // 0x08
    D2SrpDigestStrc tDigest; // 0x0C
    D2SrpDigestStrc tSavedDigest; // 0x20
    union
    {
        unsigned int aClear[6]; // 0x34
        struct
        {
            unsigned char abOutput[20]; // 0x34
            unsigned int nRandomBytesLeft; // 0x48
        };
    };

    D2BigPowModStrc(); // 0x00527DC0
    static void operator delete(void* pMemory);
    void sub_00527DD0_InitRandom(unsigned int nSeed); // 0x00527DD0
    void sub_00527F40_ComputePrivateKey(const unsigned char* pSalt, const char* szName, const char* szPassword, void** phResult); // 0x00527F40
    void sub_00528010_PowMod(void* const& hExp, void* const& hResult); // 0x00528010
    void sub_00528030_HashToUInt(void* const& hBig, unsigned int* pValue); // 0x00528030
    int sub_005280C0_ComputeSessionKey(void* const& hSecret, void* const& hPublic, void* const& hExp, void* const& hKey); // 0x005280C0
    int sub_005281D0_ComputeServerKey(void* const& hClientPublic, void* const& hServerPublic, void* const& hSecret, void* const& hVerifier, void* const& hKey); // 0x005281D0
    void sub_005282A0_ComputeProof(const char* szName, const unsigned char* pSalt, const unsigned char* pClientPublic, const unsigned char* pServerPublic, const unsigned char* pKey, unsigned char* pProof); // 0x005282A0
    void sub_00528480_HashThreeBlocks(const unsigned char* pFirst, const unsigned char* pSecond, const unsigned char* pThird, unsigned char* pDigest); // 0x00528480
};

struct D2IdeaUserKeyStrc
{
    unsigned int aKey[4]; // 0x00
};

D2_CHECK_SIZE(D2SrpDigestStrc, 0x14);
D2_CHECK_SIZE(D2BigPairStrc, 0x4);
D2_CHECK_SIZE(D2BnHashCtxStrc, 0x5C);
D2_CHECK_SIZE(D2IdeaKeyScheduleStrc, 0x68);
D2_CHECK_SIZE(D2BigPowModStrc, 0x4C);
D2_CHECK_SIZE(D2IdeaUserKeyStrc, 0x10);

struct D2EncodedTrailerStrc
{
    unsigned int nDigest;
    unsigned char nReserved;
    unsigned char nLastBlockSize;
    unsigned short wReserved;
};
