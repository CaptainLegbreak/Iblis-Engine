extern "C" int __stdcall WSAGetLastError(void);    // 0x006B0168

// 0x0052B910
int __cdecl sub_0052B910_GetLastError()
{
    return WSAGetLastError();
}
