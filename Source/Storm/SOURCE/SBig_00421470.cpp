#include "D2StormBigBuffer.h"

// 0x00421470
unsigned int __stdcall sub_00421470_FindLowestSetBit(BigBuffer* pQueue)
{
    const unsigned int nStart = pQueue->m_start;
    unsigned int i = 0;
    const unsigned int nCount = pQueue->m_array.m_count - nStart;
    const unsigned int nUsed = pQueue->m_array.m_count;
    if (nCount)
    {
        unsigned int nPos = nStart;
        do
        {
            if (nPos < nUsed && pQueue->m_array.m_data[nStart + i])
            {
                unsigned int nMask = 1;
                for (unsigned int nBit = 0; nBit < 32; ++nBit, nMask <<= 1)
                {
                    if (pQueue->sub_004212D0_Get(i) & nMask)
                        return i * 32 + nBit;
                }
            }
            ++i;
            ++nPos;
        } while (i < nCount);
    }
    return 0;
}
