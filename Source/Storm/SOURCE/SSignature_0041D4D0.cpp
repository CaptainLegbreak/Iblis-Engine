// Not joined into SSignature.cpp: the two Crypt::RSA functions here need /EHsc (their member BigNum destructors
// unwind), while SSignature.cpp is built without it: under /EHsc SSignatureGenerate (0x41D590),
// SSignatureVerifyStream_Finish (0x41D6D0) and HuffmanDecompress (0x41F9E0) gain unwind frames the image does not have.
// The original compiled these with different exception settings, so they were most likely separate files.
#include "Storm.h"

struct D2StormBigStrc;

void __stdcall SBigNew(D2StormBigStrc** ppBig);                                                             // 0x00423950
void __stdcall SBigDel(D2StormBigStrc* pBig);                                                               // 0x00424E40
void __stdcall SBigToBinaryBuffer(void* hBig, void* pBuffer, unsigned int nSize, unsigned int* pRead);            // 0x00423B30

struct BigNum
{
    D2StormBigStrc* hHandle;

    BigNum()
    {
        SBigNew(&hHandle);
    }
    // 0x0041D330
    ~BigNum()
    {
        SBigDel(hHandle);
    }
    void* ReadFill(void* pBuffer, unsigned int nSize)
    {
        unsigned int nRead;
        SBigToBinaryBuffer(hHandle, pBuffer, nSize, &nRead);
        if (nRead < nSize)
// build: symbol ?SMemZero@* 0x0041D300
            SMemZero((char*)pBuffer + nRead, nSize - nRead);
        return pBuffer;
    }
};

namespace Crypt
{

struct RSA
{
    BigNum hExponent;
    BigNum hModulus;

    RSA();
    ~RSA();
    void Process(void* pBuffer, unsigned int nSize);
};

}

// 0x0041D4D0
Crypt::RSA::RSA()
{
}

// 0x0041D530
Crypt::RSA::~RSA()
{
}

