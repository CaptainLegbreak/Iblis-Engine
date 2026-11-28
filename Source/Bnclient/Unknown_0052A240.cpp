struct D2StormBigStrc;

int __stdcall SBigNew(void** phBig); // 0x00423950
int __stdcall SBigFromUnsigned(void* hBig, unsigned int nValue); // 0x004238B0
int __stdcall SBigFromBinary(void* hBig, const void* pData, unsigned int nSize); // 0x00423850
void __stdcall SBigToBinaryBuffer(void* hBig, void* pBuffer, unsigned int nSize, unsigned int* pRead); // 0x00423B30
void __stdcall SBigDel(void* hBig); // 0x00424E40
int __stdcall SBigCompare(void* hLeft, void* hRight); // 0x00421530
int __stdcall SBigShl(void* hResult, void* hLeft, void* hRight); // 0x00423A80
int __stdcall SBigAdd(void* hResult, void* hLeft, void* hRight); // 0x00423790
int __stdcall SBigSub(void* hResult, void* hLeft, void* hRight); // 0x00423AC0
int __stdcall SBigMul(void* hResult, void* hLeft, void* hRight); // 0x00424F10
int __stdcall SBigDiv(void* hResult, void* hLeft, void* hRight); // 0x00424E70
int __stdcall SBigMod(void* hResult, void* hLeft, void* hRight); // 0x00424ED0
void __stdcall SBigPowMod(void* hResult, void* hArg1, void* hArg2, void* hArg3); // 0x00425330
void __stdcall SMemZero(void* pDest, unsigned int nSize); // 0x0041D300
int __stdcall SBigIsPrime(D2StormBigStrc* pBig); // 0x004255C0

// 0x0052A240
void* __fastcall sub_0052A240_BigFromUnsigned(unsigned int nValue)
{
    void* hBig;
    SBigNew(&hBig);
    SBigFromUnsigned(hBig, nValue);
    return hBig;
}

// 0x0052A270
void* __fastcall sub_0052A270_BigFromBinary(const void* pData, unsigned int nSize)
{
    void* hBig;
    SBigNew(&hBig);
    SBigFromBinary(hBig, pData, nSize);
    return hBig;
}

// 0x0052A2A0
unsigned int __fastcall sub_0052A2A0_BigToBinary(void* hBig, void* pBuffer, unsigned int nSize)
{
    unsigned int nRead;
    SBigToBinaryBuffer(hBig, pBuffer, nSize, &nRead);
    if (nRead < nSize)
        SMemZero((char*)pBuffer + nRead, nSize - nRead);
    return nRead;
}

// 0x0052A2F0
int __fastcall sub_0052A2F0_BigCompareUnsigned(void* hBig, unsigned int nValue)
{
    void* hValue;
    SBigNew(&hValue);
    SBigFromUnsigned(hValue, nValue);
    const int nResult = SBigCompare(hBig, hValue);
    SBigDel(hValue);
    return nResult;
}

// 0x0052A330
int __fastcall sub_0052A330_BigOp_423A80(void* hResult, void* hLeft, void* hRight)
{
    return SBigShl(hResult, hLeft, hRight);
}

// 0x0052A350
int __fastcall sub_0052A350_BigOp_423790(void* hResult, void* hLeft, void* hRight)
{
    return SBigAdd(hResult, hLeft, hRight);
}

// 0x0052A370
void __fastcall sub_0052A370_BigOpUnsigned_423790(void* hResult, void* hLeft, unsigned int nValue)
{
    void* hValue;
    SBigNew(&hValue);
    SBigFromUnsigned(hValue, nValue);
    SBigAdd(hResult, hLeft, hValue);
    SBigDel(hValue);
}

// 0x0052A3B0
int __fastcall sub_0052A3B0_BigOp_423AC0(void* hResult, void* hLeft, void* hRight)
{
    return SBigSub(hResult, hLeft, hRight);
}

// 0x0052A3D0
void __fastcall sub_0052A3D0_BigOpUnsigned_423AC0(void* hResult, void* hLeft, unsigned int nValue)
{
    void* hValue;
    SBigNew(&hValue);
    SBigFromUnsigned(hValue, nValue);
    SBigSub(hResult, hLeft, hValue);
    SBigDel(hValue);
}

// 0x0052A410
int __fastcall sub_0052A410_BigOp_424F10(void* hResult, void* hLeft, void* hRight)
{
    return SBigMul(hResult, hLeft, hRight);
}

// 0x0052A430
void __fastcall sub_0052A430_BigOpUnsigned_424F10(void* hResult, void* hLeft, unsigned int nValue)
{
    void* hValue;
    SBigNew(&hValue);
    SBigFromUnsigned(hValue, nValue);
    SBigMul(hResult, hLeft, hValue);
    SBigDel(hValue);
}

// 0x0052A470
void __fastcall sub_0052A470_BigOpUnsigned_424E70(void* hResult, void* hLeft, unsigned int nValue)
{
    void* hValue;
    SBigNew(&hValue);
    SBigFromUnsigned(hValue, nValue);
    SBigDiv(hResult, hLeft, hValue);
    SBigDel(hValue);
}

// 0x0052A4B0
int __fastcall sub_0052A4B0_BigOp_424ED0(void* hResult, void* hLeft, void* hRight)
{
    return SBigMod(hResult, hLeft, hRight);
}

// 0x0052A4D0
unsigned int __fastcall sub_0052A4D0_BigOpUnsignedToUInt_424ED0(void* hLeft, unsigned int nValue)
{
    void* hValue;
    void* hResult;
    SBigNew(&hValue);
    SBigNew(&hResult);
    SBigFromUnsigned(hValue, nValue);
    SBigMod(hResult, hLeft, hValue);
    unsigned char abResult[4];
    abResult[3] = 0;
    abResult[2] = 0;
    abResult[1] = 0;
    abResult[0] = 0;
    SBigToBinaryBuffer(hResult, abResult, sizeof(abResult), 0);
    SBigDel(hValue);
    SBigDel(hResult);
    return (((abResult[3] << 8 | abResult[2]) << 8 | abResult[1]) << 8) | abResult[0];
}

// 0x0052A560
void __fastcall sub_0052A560_BigOpPair_424F10_424ED0(void* hResult, void* hLeft, void* hRight, void* hSecond)
{
    SBigMul(hResult, hLeft, hRight);
    SBigMod(hResult, hResult, hSecond);
}

// 0x0052A590
void __fastcall sub_0052A590_BigOp_425330(void* hResult, void* hArg1, void* hArg2, void* hArg3)
{
    SBigPowMod(hResult, hArg1, hArg2, hArg3);
}

// 0x0052A5B0
void __fastcall sub_0052A5B0_BigOpUnsigned_425330(void* hResult, void* hArg1, unsigned int nValue, void* hArg3)
{
    void* hValue;
    SBigNew(&hValue);
    SBigFromUnsigned(hValue, nValue);
    SBigPowMod(hResult, hArg1, hValue, hArg3);
    SBigDel(hValue);
}

// 0x0052A2E0
int __fastcall sub_0052A2E0_BigCompare(void* hLeft, void* hRight)
{
    return SBigCompare(hLeft, hRight);
}

// 0x0052A5F0
int __fastcall sub_0052A5F0_IsPrime(D2StormBigStrc* pBig)
{
    return SBigIsPrime(pBig);
}
