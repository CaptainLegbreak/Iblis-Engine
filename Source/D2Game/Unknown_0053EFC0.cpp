// 0x0053EFC0
extern "C" __declspec(dllexport) int __fastcall sub_0053EFC0(const char* pText, int nLength) {
    for (int i = 0; i < nLength; i++) {
        if (!*pText++) {
            return 1;
        }
    }
    return 0;
}
