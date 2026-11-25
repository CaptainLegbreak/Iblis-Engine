#include "Bnclient.h"

struct D2SrpSeedRecordStrc;
struct D2BigLoginRecordStrc;

extern "C" unsigned int __cdecl strlen(const char* szString);
extern "C" long __cdecl _time32(long* pTime);
extern "C" int __cdecl tolower(int nChar);
// build: symbol ?gacCDKeyMap@* 0x006DF238
extern const char gacCDKeyMap[];

struct D2SrpSeedRecordStrc
{
    long nTime;
    unsigned int nSeed;
    int nRandom;
};

extern "C" void* __cdecl memcpy(void* pDst, const void* pSrc, unsigned int nSize);
extern "C" void* __cdecl memset(void* pDst, int nValue, unsigned int nSize);

unsigned int __stdcall SStrCopy(char* szDest, const char* szSource, unsigned int nMax); // 0x004135D0
void* __fastcall sub_0052A240_BigFromUnsigned(unsigned int nValue); // 0x0052A240
void* __fastcall sub_0052A270_BigFromBinary(const void* pData, unsigned int nSize); // 0x0052A270
unsigned int __fastcall sub_0052A2A0_BigToBinary(void* hBig, void* pBuffer, unsigned int nSize); // 0x0052A2A0
void __fastcall sub_0052A590_BigOp_425330(void* hResult, void* hArg1, void* hArg2, void* hArg3); // 0x0052A590
extern const char* gpszSrpSeparator; // 0x00730ADC
int __fastcall sub_0052A2E0_BigCompare(void* hLeft, void* hRight); // 0x0052A2E0
int __fastcall sub_0052A2F0_BigCompareUnsigned(void* hBig, unsigned int nValue); // 0x0052A2F0
int __fastcall sub_0052A350_BigOp_423790(void* hResult, void* hLeft, void* hRight); // 0x0052A350
int __fastcall sub_0052A3B0_BigOp_423AC0(void* hResult, void* hLeft, void* hRight); // 0x0052A3B0
void __fastcall sub_0052A430_BigOpUnsigned_424F10(void* hResult, void* hLeft, unsigned int nValue); // 0x0052A430

// 0x00527DB0
// build: symbol ?BNDOWNLOAD_GetTime@* 0x00521B40
static long BNDOWNLOAD_GetTime(long* pTime)
{
    return _time32(pTime);
}

// build: symbol ?BNSEND_NibbleToHex@* 0x0051DD10
static unsigned int BNSEND_NibbleToHex(unsigned int nValue)
{
    nValue &= 0xF;
    if (nValue >= 10)
        return nValue + 0x37;
    return nValue + 0x30;
}

// build: symbol ?BNSEND_HexToNibble@* 0x0051DD20
static int BNSEND_HexToNibble(char cChar)
{
    char cLower = (char)tolower(cChar);
    if (cLower >= 'a')
        return cLower - 0x57;
    return cLower - 0x30;
}

// build: symbol ?BNSEND_MapKeyChar@* 0x0051DD40
static int BNSEND_MapKeyChar(unsigned char cChar)
{
    return gacCDKeyMap[cChar];
}

long __stdcall sub_M106_Emit_0051DC70(long* pTime)
{
    return BNDOWNLOAD_GetTime(pTime);
}

unsigned int __stdcall sub_M106_Emit_0051DD10(int n)
{
    return BNSEND_NibbleToHex(tolower(n)) + BNSEND_NibbleToHex(tolower(n + 1));
}

int __stdcall sub_M106_Emit_0051DD20(int n)
{
    return BNSEND_HexToNibble((char)tolower(n)) * 16 + BNSEND_HexToNibble((char)tolower(n + 1));
}

int __stdcall sub_M106_Emit_0051DD40(int n)
{
    return BNSEND_MapKeyChar((unsigned char)tolower(n)) * 24 + BNSEND_MapKeyChar((unsigned char)tolower(n + 1));
}

// 0x00527DC0
D2BigPowModStrc::D2BigPowModStrc() : bValid(0), nRandomBytesLeft(0)
{
}

// 0x00527DD0
void D2BigPowModStrc::sub_00527DD0_InitRandom(unsigned int nSeed)
{
    D2SrpSeedRecordStrc tRecord;
    D2SrpSha1ContextStrc tContext;
    _time32(&tRecord.nTime);
    tRecord.nSeed = nSeed;
    srand(nSeed);
    tRecord.nRandom = rand();
    sub_00529F50_Sha1Init(&tContext);
    sub_00529F80_Sha1Update(&tContext, (const unsigned char*)&tRecord, sizeof(tRecord));
    sub_0052A040_Sha1Final(tDigest.ab, &tContext);
    memcpy(&tSavedDigest, &tDigest, sizeof(tSavedDigest));
    memset(aClear, 0, sizeof(aClear));
}

// 0x00527E70
void D2BigPairStrc::sub_00527E70_RandomBytes(unsigned char* pBuffer, unsigned int nSize)
{
    D2SrpSha1ContextStrc tContext;

    if (!nSize)
        return;

    unsigned int nAvail = pState->nRandomBytesLeft;
    while (nSize > nAvail)
    {
        memcpy(pBuffer, &pState->abOutput[sizeof(pState->abOutput) - nAvail], nAvail);
        pBuffer += pState->nRandomBytesLeft;
        nSize -= pState->nRandomBytesLeft;
        sub_00529F50_Sha1Init(&tContext);
        sub_00529F80_Sha1Update(&tContext, pState->tDigest.ab, 0x14);
        sub_00529F80_Sha1Update(&tContext, pState->abOutput, 0x14);
        sub_00529F80_Sha1Update(&tContext, pState->tSavedDigest.ab, 0x14);
        sub_0052A040_Sha1Final(pState->abOutput, &tContext);
        pState->nRandomBytesLeft = 0x14;
        nAvail = pState->nRandomBytesLeft;
    }

    if (nSize > 0)
    {
        memcpy(pBuffer, &pState->abOutput[sizeof(pState->abOutput) - pState->nRandomBytesLeft], nSize);
        pState->nRandomBytesLeft -= nSize;
    }
}

// 0x00527F40
void D2BigPowModStrc::sub_00527F40_ComputePrivateKey(const unsigned char* pSalt, const char* szName, const char* szPassword, void** phResult)
{
    D2SrpSha1ContextStrc tContext;
    unsigned char abDigest[0x14];
    sub_00529F50_Sha1Init(&tContext);
    sub_00529F80_Sha1Update(&tContext, (const unsigned char*)szName, SStrLen(szName));
    sub_00529F80_Sha1Update(&tContext, (const unsigned char*)gpszSrpSeparator, SStrLen(gpszSrpSeparator));
    sub_00529F80_Sha1Update(&tContext, (const unsigned char*)szPassword, SStrLen(szPassword));
    sub_0052A040_Sha1Final(abDigest, &tContext);
    sub_00529F50_Sha1Init(&tContext);
    sub_00529F80_Sha1Update(&tContext, pSalt, 0x20);
    sub_00529F80_Sha1Update(&tContext, abDigest, 0x14);
    sub_0052A040_Sha1Final(abDigest, &tContext);
    *phResult = sub_0052A270_BigFromBinary(abDigest, 0x14);
}

// 0x005282A0
void D2BigPowModStrc::sub_005282A0_ComputeProof(const char* szName, const unsigned char* pSalt, const unsigned char* pClientPublic, const unsigned char* pServerPublic, const unsigned char* pKey, unsigned char* pProof)
{
    D2SrpSha1ContextStrc tContext;
    unsigned char abHashBase[0x14];
    unsigned char abBuffer[0x20];
    unsigned char abHash[0x14];

    unsigned int nLength = sub_0052A2A0_BigToBinary(hModulus, abBuffer, 0x20);
    sub_00529F50_Sha1Init(&tContext);
    sub_00529F80_Sha1Update(&tContext, abBuffer, nLength);
    sub_0052A040_Sha1Final(abHash, &tContext);

    nLength = sub_0052A2A0_BigToBinary(hBase, abBuffer, 0x20);
    sub_00529F50_Sha1Init(&tContext);
    sub_00529F80_Sha1Update(&tContext, abBuffer, nLength);
    sub_0052A040_Sha1Final(abHashBase, &tContext);

    for (int i = 0; i < 0x14; ++i)
        abBuffer[i] = abHashBase[i] ^ abHash[i];

    sub_00529F50_Sha1Init(&tContext);
    sub_00529F80_Sha1Update(&tContext, (const unsigned char*)szName, SStrLen(szName));
    sub_0052A040_Sha1Final(abHash, &tContext);

    sub_00529F50_Sha1Init(&tContext);
    sub_00529F80_Sha1Update(&tContext, abBuffer, 0x14);
    sub_00529F80_Sha1Update(&tContext, abHash, 0x14);
    sub_00529F80_Sha1Update(&tContext, pSalt, 0x20);
    sub_00529F80_Sha1Update(&tContext, pClientPublic, 0x20);
    sub_00529F80_Sha1Update(&tContext, pServerPublic, 0x20);
    sub_00529F80_Sha1Update(&tContext, pKey, 0x28);
    sub_0052A040_Sha1Final(pProof, &tContext);
}

// 0x005286D0
void D2BigPairStrc::sub_005286D0_InitLogin(D2BigLoginRecordStrc* pRecord, const char* szName, const char* szPassword)
{
    SStrCopy(pRecord->szName, szName, 0x7FFFFFFF);
    SStrCopy(pRecord->szPassword, szPassword, 0x7FFFFFFF);
    sub_00527E70_RandomBytes(pRecord->abPrivate, 0x20);
    void* hPrivate = sub_0052A270_BigFromBinary(pRecord->abPrivate, 0x20);
    void* hPublic = sub_0052A240_BigFromUnsigned(0);
    sub_0052A590_BigOp_425330(hPublic, pState->hBase, hPrivate, pState->hModulus);
    GAME_DeleteBigNum(hPrivate);
    sub_0052A2A0_BigToBinary(hPublic, pRecord->abPublic, 0x20);
    GAME_DeleteBigNum(hPublic);
}

#include "gen/data/Source/Bnclient/Unknown_00527BE0.inc"

// 0x005280C0
int D2BigPowModStrc::sub_005280C0_ComputeSessionKey(void* const& hSecret, void* const& hPublic, void* const& hExp, void* const& hKey)
{
    if (sub_0052A2E0_BigCompare(hPublic, hModulus) < 0)
    {
        if (sub_0052A2F0_BigCompareUnsigned(hPublic, 0))
        {
            unsigned int nScrambler;
            sub_00528030_HashToUInt(hPublic, &nScrambler);
            if (nScrambler)
            {
                void* hPower = sub_0052A240_BigFromUnsigned(0);
                void* hResult = hPower;
                sub_00528010_PowMod(hExp, hResult);
                void* hBase = sub_0052A240_BigFromUnsigned(0);
                void* hTemp = sub_0052A240_BigFromUnsigned(0);
                if (sub_0052A2E0_BigCompare(hPublic, hPower) < 0)
                {
                    sub_0052A350_BigOp_423790(hTemp, hPublic, hModulus);
                    sub_0052A3B0_BigOp_423AC0(hBase, hTemp, hPower);
                }
                else
                {
                    sub_0052A3B0_BigOp_423AC0(hBase, hPublic, hPower);
                }
                sub_0052A430_BigOpUnsigned_424F10(hTemp, hExp, nScrambler);
                sub_0052A350_BigOp_423790(hTemp, hTemp, hSecret);
                sub_0052A590_BigOp_425330(hKey, hBase, hTemp, hModulus);
                GAME_DeleteBigNum(hTemp);
                GAME_DeleteBigNum(hBase);
                GAME_DeleteBigNum(hPower);
                return 1;
            }
        }
    }
    return 0;
}
