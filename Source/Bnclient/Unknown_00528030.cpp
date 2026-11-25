#include "Bnclient.h"
#include "D2BnCryptTypes.h"

unsigned char* __fastcall SHA_Interleave(unsigned char* pDest, const unsigned char* pData, unsigned int nSize); // 0x0052A120
void* __fastcall sub_0052A240_BigFromUnsigned(unsigned int nValue);                                         // 0x0052A240
void* __fastcall sub_0052A270_BigFromBinary(const void* pData, unsigned int nSize);                         // 0x0052A270
unsigned int __fastcall sub_0052A2A0_BigToBinary(void* hBig, void* pBuffer, unsigned int nSize);            // 0x0052A2A0
int __fastcall sub_0052A2F0_BigCompareUnsigned(void* hBig, unsigned int nValue);                            // 0x0052A2F0

// 0x00528030
void D2BigPowModStrc::sub_00528030_HashToUInt(void* const& hBig, unsigned int* pValue)
{
    unsigned char abBuffer[0x20];
    D2SrpSha1ContextStrc tContext;
    unsigned char abDigest[20];
    const unsigned int nSize = sub_0052A2A0_BigToBinary(hBig, abBuffer, 0x20);
    sub_00529F50_Sha1Init(&tContext);
    sub_00529F80_Sha1Update(&tContext, abBuffer, nSize);
    sub_0052A040_Sha1Final(abDigest, &tContext);
    *pValue = ((((abDigest[0] << 8) | abDigest[1]) << 8 | abDigest[2]) << 8) | abDigest[3];
}

// 0x00528480
void __stdcall sub_00528480_HashThreeBlocks(const unsigned char* pFirst, const unsigned char* pSecond, const unsigned char* pThird, unsigned char* pDigest)
{
    D2SrpSha1ContextStrc tContext;
    sub_00529F50_Sha1Init(&tContext);
    sub_00529F80_Sha1Update(&tContext, pFirst, 0x20);
    sub_00529F80_Sha1Update(&tContext, pSecond, 0x14);
    sub_00529F80_Sha1Update(&tContext, pThird, 0x28);
    sub_0052A040_Sha1Final(pDigest, &tContext);
}

// 0x00528760
int D2BigPairStrc::sub_00528760_ComputeLoginProof(D2BigLoginRecordStrc* pRecord, const unsigned char* pSalt, const unsigned char* pServerPublic)
{
    unsigned char abKey[0x20];
    void* hPublic = sub_0052A270_BigFromBinary(pServerPublic, 0x20);
    void* hPublicRef = hPublic;
    if (sub_0052A2F0_BigCompareUnsigned(hPublic, 0) != 1)
    {
        GAME_DeleteBigNum(hPublic);
        return 0;
    }
    void* hExp;
    pState->sub_00527F40_ComputePrivateKey(pSalt, pRecord->szName, pRecord->szPassword, &hExp);
    void* hKey = sub_0052A240_BigFromUnsigned(0);
    void* hKeyRef = hKey;
    void* hSecret = sub_0052A270_BigFromBinary(pRecord->abPrivate, 0x20);
    const int nResult = pState->sub_005280C0_ComputeSessionKey(hSecret, hPublicRef, hExp, hKeyRef);
    GAME_DeleteBigNum(hSecret);
    GAME_DeleteBigNum(hPublicRef);
    GAME_DeleteBigNum(hExp);
    if (!nResult)
    {
        GAME_DeleteBigNum(hKey);
        return 0;
    }
    const unsigned int nSize = sub_0052A2A0_BigToBinary(hKey, abKey, 0x20);
    SHA_Interleave(pRecord->abKey, abKey, nSize);
    GAME_DeleteBigNum(hKeyRef);
    pState->sub_005282A0_ComputeProof(pRecord->szName, pSalt, pRecord->abPublic, pServerPublic, pRecord->abKey, pRecord->abProof);
    return 1;
}
