#pragma once
// Storm compression bit writer.

struct CBitOutput
{
    unsigned char* pOutputStart;
    unsigned int nBytesLeft;
    unsigned char* pOutput;
    unsigned int nBitBuffer;
    unsigned int nBitCount;

    CBitOutput(void* pOutputBuffer, unsigned int nOutputSize);
    unsigned int GetSize();                                                                    // 0x0041D940
    void PutBits(unsigned int nValue, unsigned int nBits);                                     // 0x0041D950
    void Flush();                                                                              // 0x0041D9A0
};
