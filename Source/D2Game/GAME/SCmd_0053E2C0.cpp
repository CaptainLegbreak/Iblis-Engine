#include "FogApi.h"
struct D2BitBufferStrc
{
    unsigned char* pBuffer;
    int nBits;
    int nPos;
    int nPosBits;
    int bFull;

    void SCMD_WriteBitBufferBool(int bValue);
};


// 0x0053E2C0
void D2BitBufferStrc::SCMD_WriteBitBufferBool(int bValue)
{
    BITMANIP_Write(this, bValue != 0, 1);
}
