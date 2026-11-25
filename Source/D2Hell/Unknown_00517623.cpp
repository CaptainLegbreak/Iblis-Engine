struct D2StormLinkStrc;
struct D2LinkStrc;
struct D2ListStrc;

struct D2StormLinkStrc {
    void __thiscall sub_005174E2_Unlink(); // 0x005174E2
    void __thiscall sub_00517623_ForwardUnlink();
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


void __fastcall sub_0051763C_Destroy(void* pObject); // 0x0051763C
void __fastcall sub_005174E2_DestroyMember(void* pMember); // 0x005174E2

// 0x00517623
void D2StormLinkStrc::sub_00517623_ForwardUnlink()
{
    sub_005174E2_Unlink();
}

// 0x00517628
D2ListStrc::D2ListStrc() {
    linkOffset = 0;
    head.next = ~(unsigned int)&head;
}

// 0x00517658
void __fastcall sub_00517658_Destroy(char* pObject)
{
    sub_0051763C_Destroy(pObject);
    sub_005174E2_DestroyMember(pObject + 4);
}
