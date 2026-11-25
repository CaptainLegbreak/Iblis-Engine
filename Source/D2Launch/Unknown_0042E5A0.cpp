extern "C" int __cdecl isalpha(int c);                                                                      // 0x00686DA5

extern "C" unsigned short __cdecl _rotl16(unsigned short nValue, unsigned char nShift);

#pragma intrinsic(_rotl16)

struct Unicode
{
    unsigned short wChar;

    int isNewline() const;
    int isAlpha() const;
};

// 0x0042E620
int Unicode::isNewline() const
{
    return wChar == L'\n';
}

// 0x0042E630
int Unicode::isAlpha() const
{
    return (wChar < 0x80 && ::isalpha((char)wChar));
}
