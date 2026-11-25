#include "Storm.h"

struct D2AdpcmHeaderStrc;

extern "C" int __cdecl abs(int);

void sub_0041DA30_GetCompressionLevel(unsigned int nCmpLevel, unsigned char* pnLevel, int* pCmpType); // 0x0041DA30
// 0x0041DA60
static int __stdcall ImaAdpcmCompress(int nOutSize, const short* pIn, int nInSize, unsigned int nChannels, unsigned char nLevel, unsigned char* pOut)
{
    unsigned char* pOutStart = pOut;
    if ((unsigned int)nOutSize < 2)
    {
        return 2;
    }
    D2AdpcmHeaderStrc tHeader;
    tHeader.nZero = 0;
    tHeader.nShift = nLevel - 1;
    *(D2AdpcmHeaderStrc*)pOut = tHeader;
    pOut += 2;
    if (pOut + nChannels * 2 - pOutStart > nOutSize)
    {
        return pOut + nChannels * 2 - pOutStart;
    }
    int aSample[2];
    int aPredicted[2];
    int aStepIndex[2];
    aStepIndex[0] = 0x2C;
    aStepIndex[1] = 0x2C;
    unsigned int i;
    for (i = 0; i < nChannels; i++)
    {
        aPredicted[i] = *pIn++;
        *(short*)pOut = (short)aPredicted[i];
        pOut += 2;
    }
    int nGrowLeft = (nInSize / 2 - (pOut - pOutStart) < 0) ? 0 : nInSize / 2 - (pOut - pOutStart);
    int nChannel = nChannels - 1;
    const unsigned int nWords = nInSize / sizeof(short);
    for (i = nChannels; i < nWords; i++)
    {
        if (pOut + 2 - pOutStart > nOutSize)
        {
            return pOut + 2 - pOutStart;
        }
        if (nChannels == 2)
        {
            nChannel = nChannel == 0;
        }
        aSample[nChannel] = *pIn++;
        const unsigned int nAbs = abs(aSample[nChannel] - aPredicted[nChannel]);
        const int nSignBit = aSample[nChannel] >= aPredicted[nChannel] ? 0 : 0x40;
        unsigned int nStepSize = gaADPCMStepTable_006CFD38[aStepIndex[nChannel]];
        if (nAbs < (nStepSize >> nLevel))
        {
            if (aStepIndex[nChannel])
            {
                aStepIndex[nChannel]--;
            }
            *pOut++ = 0x80;
            continue;
        }
        while (nAbs > nStepSize * 2 && aStepIndex[nChannel] < 0x58 && nGrowLeft)
        {
            aStepIndex[nChannel] += 8;
            if (aStepIndex[nChannel] > 0x58)
            {
                aStepIndex[nChannel] = 0x58;
            }
            nStepSize = gaADPCMStepTable_006CFD38[aStepIndex[nChannel]];
            *pOut++ = 0x81;
            nGrowLeft--;
        }
        unsigned int nMask = 0;
        unsigned int nTotal = 0;
        const unsigned int nStepRest = nStepSize >> tHeader.nShift;
        unsigned int nBit = 1;
        const unsigned int nMaxBit = ((unsigned int)(1 << (nLevel - 2)) > 0x20) ? 0x20 : (1 << (nLevel - 2));
        for (;;)
        {
            if (nTotal + nStepSize <= nAbs)
            {
                nMask |= nBit;
                nTotal += nStepSize;
            }
            if (nBit == nMaxBit)
            {
                break;
            }
            nStepSize >>= 1;
            nBit <<= 1;
        }
        nTotal += nStepRest;
        int nPredicted = aPredicted[nChannel];
        if (nSignBit)
        {
            nPredicted -= nTotal;
            if (nPredicted < -0x8000)
            {
                nPredicted = -0x8000;
            }
        }
        else
        {
            nPredicted += nTotal;
            if (nPredicted > 0x7FFF)
            {
                nPredicted = 0x7FFF;
            }
        }
        aPredicted[nChannel] = nPredicted;
        *pOut++ = (unsigned char)(nSignBit | nMask);
        aStepIndex[nChannel] += gaADPCMIndexTable_006CFCB8[nMask & 0x1F];
        if (aStepIndex[nChannel] < 0)
        {
            aStepIndex[nChannel] = 0;
        }
        else if (aStepIndex[nChannel] > 0x58)
        {
            aStepIndex[nChannel] = 0x58;
        }
    }
    return pOut - pOutStart;
}

// 0x0041E360
void __fastcall ImaAdpcmMonoCompress(unsigned char* pvOutBuffer, int* pcbOutBuffer, const short* pvInBuffer, int cbInBuffer, int* pCmpType, int nCmpLevel)
{
    unsigned char nLevel;
    sub_0041DA30_GetCompressionLevel(nCmpLevel, &nLevel, pCmpType);
    *pcbOutBuffer = ImaAdpcmCompress(*pcbOutBuffer, pvInBuffer, cbInBuffer, 1, nLevel, pvOutBuffer);
}

// 0x0041E3C0
void __fastcall ImaAdpcmStereoCompress(unsigned char* pvOutBuffer, int* pcbOutBuffer, const short* pvInBuffer, int cbInBuffer, int* pCmpType, int nCmpLevel)
{
    unsigned char nLevel;
    sub_0041DA30_GetCompressionLevel(nCmpLevel, &nLevel, pCmpType);
    *pcbOutBuffer = ImaAdpcmCompress(*pcbOutBuffer, pvInBuffer, cbInBuffer, 2, nLevel, pvOutBuffer);
}

// 0x0041DCE0
static int __stdcall ImaAdpcmDecompress(short* pOut, unsigned int nOutSize, unsigned char* pIn, int nInLength, unsigned int nChannels)
{
    int aPredicted[2];
    int aStep[2];
    unsigned char* pHeader = pIn;
    short* pOutStart = pOut;
    aStep[0] = 0x2C;
    aStep[1] = 0x2C;
    unsigned char* pInEnd = pIn + nInLength;
    pIn += 2;
    for (unsigned int i = 0; i < nChannels; i++)
    {
        aPredicted[i] = *(short*)pIn;
        pIn += 2;
        if (nOutSize < 2)
        {
            return (char*)pOut - (char*)pOutStart;
        }
        nOutSize -= 2;
        *pOut = aPredicted[i];
        pOut++;
    }
    int nChannel = nChannels - 1;
    while (pIn < pInEnd)
    {
        if (nChannels == 2)
        {
            nChannel = (nChannel == 0);
        }
        const unsigned char nByte = *pIn++;
        if (nByte & 0x80)
        {
            int bSameChannel = 0;
            switch (nByte & 0x7F)
            {
            case 0:
                if (aStep[nChannel])
                {
                    aStep[nChannel]--;
                }
                if (nOutSize < 2)
                {
                    return (char*)pOut - (char*)pOutStart;
                }
                *pOut = aPredicted[nChannel];
                pOut++;
                nOutSize -= 2;
                break;
            case 1:
                aStep[nChannel] += 8;
                if (aStep[nChannel] > 0x58)
                {
                    aStep[nChannel] = 0x58;
                }
                bSameChannel = 1;
                break;
            case 2:
                aStep[nChannel] -= 8;
                if (aStep[nChannel] < 0)
                {
                    aStep[nChannel] = 0;
                }
                bSameChannel = 1;
                break;
            default:
                continue;
            }
            if (bSameChannel && nChannels == 2)
            {
                nChannel = (nChannel == 0);
            }
        }
        else
        {
            const unsigned int nStep = gaADPCMStepTable_006CFD38[aStep[nChannel]];
            unsigned int nDiff = nStep >> pHeader[1];
            if (nByte & 1)
                nDiff += nStep;
            if (nByte & 2)
                nDiff += nStep >> 1;
            if (nByte & 4)
                nDiff += nStep >> 2;
            if (nByte & 8)
                nDiff += nStep >> 3;
            if (nByte & 0x10)
                nDiff += nStep >> 4;
            if (nByte & 0x20)
                nDiff += nStep >> 5;
            int nValue = aPredicted[nChannel];
            if (nByte & 0x40)
            {
                nValue -= nDiff;
                if (nValue <= -0x8000)
                {
                    nValue = -0x8000;
                }
            }
            else
            {
                nValue += nDiff;
                if (nValue >= 0x7FFF)
                {
                    nValue = 0x7FFF;
                }
            }
            aPredicted[nChannel] = nValue;
            if (nOutSize < 2)
            {
                return (char*)pOut - (char*)pOutStart;
            }
            nOutSize -= 2;
            *pOut = aPredicted[nChannel];
            pOut++;
            aStep[nChannel] += gaADPCMIndexTable_006CFCB8[nByte & 0x1F];
            if (aStep[nChannel] < 0)
            {
                aStep[nChannel] = 0;
            }
            else if (aStep[nChannel] > 0x58)
            {
                aStep[nChannel] = 0x58;
            }
        }
    }
    return (char*)pOut - (char*)pOutStart;
}

// 0x0041E3A0
void __fastcall ImaAdpcmMonoDecompress(short* pOut, unsigned int* pOutSize, unsigned char* pIn, int nInLength, int nUnused)
{
    *pOutSize = ImaAdpcmDecompress(pOut, *pOutSize, pIn, nInLength, 1);
}

// 0x0041E400
void __fastcall ImaAdpcmStereoDecompress(short* pOut, unsigned int* pOutSize, unsigned char* pIn, int nInLength, int nUnused)
{
    *pOutSize = ImaAdpcmDecompress(pOut, *pOutSize, pIn, nInLength, 2);
}
