#include "D2StormLink.h"

struct D2StormListStrc;
struct D2LinkStrc;
struct D2ListStrc;

struct D2StormListStrc
{
    int nLinkOffset;
    D2StormLinkStrc tTerminator;
    void __thiscall sub_0051763C_UnlinkAll(); // 0x0051763C
    void __thiscall sub_005176D3_Destroy();
};


extern "C" void* __cdecl memset(void*, int, unsigned int);

struct D2LinkStrc {
    D2LinkStrc* previous;
    unsigned int next;
    inline D2LinkStrc() {
        memset(this, 0, sizeof(*this));
        previous = this;
    }
};

struct D2ListStrc {
    unsigned int linkOffset;
    D2LinkStrc head;
    D2ListStrc();
};


// 0x005176D3
void __thiscall D2StormListStrc::sub_005176D3_Destroy()
{
    sub_0051763C_UnlinkAll();
    tTerminator.sub_005174E2_Unlink();
}

// 0x005176E4
D2ListStrc::D2ListStrc() {
    linkOffset = 0;
    head.next = ~(unsigned int)&head;
}
