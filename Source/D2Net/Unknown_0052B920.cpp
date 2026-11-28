#include "D2NetTypes.h"
#include "StormApi.h"



extern int ganServerPacketSizeTable[]; // 0x00730AE8
extern int ganClientPacketSizes[]; // 0x00730DC0

// 0x0052B920
int __fastcall SERVER_GetServerPacketSize(D2PacketBufferStrc* pBuffer, int nBufferSize, int* pSize)
{
    if (nBufferSize < 1u)
    {
        return 0;
    }

    const unsigned char nHeader = pBuffer->data[0];
    if (nHeader >= 0xB5u)
    {
        return 0;
    }

    *pSize = ganServerPacketSizeTable[nHeader];
    if (*pSize == 0)
    {
        return 0;
    }

    if (*pSize < 0)
    {
        switch (nHeader)
        {
        case 0x16:
            if (nBufferSize < 13u)
            {
                return 0;
            }
            *pSize = *(unsigned short*)&pBuffer->data[1];
            break;

        case 0x26:
        {
            if (nBufferSize < 10)
            {
                return 0;
            }

            const char* szName = (const char*)&pBuffer->data[10];
            int nPacketSize = SStrLen(szName) + 11;
            if (nBufferSize < nPacketSize)
            {
                return 0;
            }

            const char* szMessage = &szName[SStrLen(szName) + 1];
            nPacketSize += SStrLen(szMessage) + 1;
            if (nBufferSize < nPacketSize)
            {
                return 0;
            }

            *pSize = nPacketSize;
            break;
        }

        case 0x5B:
            if (nBufferSize < 34u)
            {
                return 0;
            }
            *pSize = *(unsigned short*)&pBuffer->data[1];
            break;

        case 0x94:
            if (nBufferSize < 9u)
            {
                return 0;
            }
            *pSize = 3 * (pBuffer->data[1] + 2);
            break;

        case 0x9C:
            if (nBufferSize < 3u)
            {
                return 0;
            }
            *pSize = pBuffer->data[2];
            break;

        case 0x3E:
            if (nBufferSize < 2u)
            {
                return 0;
            }
            *pSize = pBuffer->data[1];
            break;

        case 0x9D:
            if (nBufferSize < 3u)
            {
                return 0;
            }
            *pSize = pBuffer->data[2];
            break;

        case 0xA6:
            if (nBufferSize < 4u)
            {
                return 0;
            }
            *pSize = *(unsigned short*)&pBuffer->data[2];
            break;

        case 0xA8:
            if (nBufferSize < 7u)
            {
                return 0;
            }
            *pSize = pBuffer->data[6];
            break;

        case 0xAA:
            if (nBufferSize < 7u)
            {
                return 0;
            }
            *pSize = pBuffer->data[6];
            break;

        case 0xAC:
            if (nBufferSize < 13u)
            {
                return 0;
            }
            *pSize = pBuffer->data[12];
            break;

        case 0xAE:
        {
            if (nBufferSize < 3u)
            {
                return 0;
            }

            unsigned short nDataSize = *(unsigned short*)&pBuffer->data[1];
            if (nDataSize > 0x1FD)
            {
                nDataSize = 0;
            }
            *pSize = nDataSize + 3;
            break;
        }

        case 0xAF:
            if (nBufferSize < 2u)
            {
                return 0;
            }

            if (!pBuffer->data[1])
            {
                *pSize = 2;
            }
            else
            {
                *pSize = pBuffer->data[1] + 1;
            }
            break;

        case 0xB3:
            if (nBufferSize < 8u)
            {
                return 0;
            }
            *pSize = pBuffer->data[1] + 7;
            break;

        default:
            *pSize = 0;
            break;
        }
    }

    return 1;
}

int ganServerPacketSizeTable[182] = { // 0x00730AE8
    1, 8, 1, 12, 1, 1, 1, 6, 6, 11, 6, 6, 9, 13, 12, 16,
    16, 8, 26, 14, 18, 11, -1, 0, 15, 2, 2, 3, 5, 3, 4, 6,
    10, 12, 12, 13, 90, 90, -1, 40, 103, 97, 15, 0, 8, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 8,
    13, 0, 6, 0, 0, 13, 0, 11, 11, 0, 0, 0, 16, 17, 7, 1,
    15, 14, 42, 10, 3, 0, 0, 14, 7, 26, 40, -1, 5, 6, 38, 5,
    7, 2, 7, 21, 0, 7, 7, 16, 21, 12, 12, 16, 16, 10, 1, 1,
    1, 1, 1, 32, 10, 13, 6, 2, 21, 6, 13, 8, 6, 18, 5, 10,
    0, 20, 29, 0, 0, 0, 0, 0, 0, 2, 6, 6, 11, 7, 10, 33,
    13, 26, 6, 8, -1, 13, 9, 1, 7, 16, 17, 7, -1, -1, 7, 8,
    10, 7, 8, 24, 3, 8, -1, 7, -1, 7, -1, 7, -1, 0, -1, -1,
    1, 0, 53, -1, 5, 0
};

int ganClientPacketSizes[113] = { // 0x00730DC0
    0, 5, 9, 5, 9, 5, 9, 9, 5, 9, 9, 1, 5, 9, 9, 5,
    9, 9, 1, 9, -1, -1, 13, 5, 17, 5, 9, 9, 3, 9, 9, 17,
    13, 9, 5, 9, 5, 9, 13, 9, 9, 9, 9, 0, 0, 1, 3, 9,
    9, 9, 17, 17, 5, 17, 9, 5, 13, 5, 3, 3, 9, 5, 5, 3,
    1, 1, 1, 1, 17, 9, 13, 13, 1, 9, 0, 9, 5, 3, 0, 7,
    9, 9, 5, 1, 1, 0, 0, 0, 3, 17, 0, 0, 0, 7, 6, 5,
    1, 3, 5, 5, 0, 0, -1, 46, 37, 1, 1, 1, -1, 13, 1, 0,
    1
};

extern "C" const char* gData_00730FC0[15] = { // 0x00730FC0
    "English",
    "Spanish",
    "German",
    "French",
    "Portuguese",
    "Italian",
    "Japanese",
    "Korean",
    "Simplified Chinese",
    "Traditional Chinese",
    "Polish",
    "Russian",
    "English with Korean Chat",
    "Unknown",
    "14"
};

static inline const char* NextString(const char* szString)
{
    return szString + SStrLen(szString) + 1;
}

// 0x0052BC20
int __fastcall SERVER_GetClientPacketSize(unsigned char* pBuffer, unsigned int nBufferSize, int* pSize)
{
    if (nBufferSize < 1)
    {
        return 0;
    }

    const unsigned char nHeader = pBuffer[0];
    if (nHeader == 0xFF)
    {
        *pSize = 16;
        return 1;
    }

    if (nHeader >= 0x71)
    {
        return 0;
    }

    *pSize = ganClientPacketSizes[nHeader];
    if (!*pSize)
    {
        return 0;
    }

    if (*pSize < 0)
    {
        switch (nHeader)
        {
        case 0x14:
        case 0x15:
        {
            if ((int)nBufferSize < 3)
            {
                return 0;
            }

            const char* szName = (const char*)pBuffer + 3;
            int nSize = SStrLen(szName) + 4;
            if ((int)nBufferSize < nSize)
            {
                return 0;
            }

            const char* szMessage = NextString(szName);
            nSize += SStrLen(szMessage) + 1;
            if ((int)nBufferSize < nSize)
            {
                return 0;
            }

            nSize += *NextString(szMessage) + 1;
            if ((int)nBufferSize < nSize)
            {
                return 0;
            }

            *pSize = nSize;
            break;
        }
        case 0x66:
        {
            if (nBufferSize < 3)
            {
                return 0;
            }

            unsigned short nLength = *(unsigned short*)(pBuffer + 1);
            if (nLength > 0x1FD)
            {
                nLength = 0;
            }

            *pSize = nLength + 3;
            break;
        }
        case 0x6C:
            if (nBufferSize < 6)
            {
                return 0;
            }

            *pSize = pBuffer[1] + 7;
            break;

        default:
            *pSize = 0;
            break;
        }
    }

    return *pSize;
}
