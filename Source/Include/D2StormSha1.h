#pragma once

// Storm's SHA-1 context.
struct Sha1
{
    unsigned __int64 nBitCount;                                     // 0x00
    unsigned int aState[5];                                         // 0x08
    unsigned char aBlock[64];                                       // 0x1C

    void Initialize();                                              // 0x00425D90
    void Append(const unsigned char* pData, unsigned int nLen);     // 0x00425DD0
    void Final(unsigned char* pDigest);                // 0x00425F00
};
