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
            sub_0041D300_ZeroMemory((char*)pBuffer + nRead, nSize - nRead);
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

