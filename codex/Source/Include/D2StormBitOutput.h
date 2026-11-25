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
    unsigned int sub_0041D940_GetSize();                                                                    // 0x0041D940
    void sub_0041D950_PutBits(unsigned int nValue, unsigned int nBits);                                     // 0x0041D950
    void Flush();                                                                              // 0x0041D9A0
};
