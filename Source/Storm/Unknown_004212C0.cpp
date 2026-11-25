// 0x004212C0
// build: symbol ?WARDENCLIENT_SwapBytes@* 0x0047F8B0
void __fastcall WARDENCLIENT_SwapBytes(unsigned char* pA, unsigned char* pB)
{
    unsigned char nTemp = *pA;
    *pA = *pB;
    *pB = nTemp;
}
