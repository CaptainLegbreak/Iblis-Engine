// A piece of SCmd.cpp (0x0053E2C0 sits just before its run), kept as its own file: the image's 0x0053E2C0 is a
// __thiscall method of D2BitBufferStrc (this in ecx, the flag on the stack), and SCmd.cpp takes D2BitBufferStrc from
// the shared header, which declares no methods. It joins once that struct declares the method.
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
