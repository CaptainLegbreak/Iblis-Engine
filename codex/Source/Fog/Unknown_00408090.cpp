extern "C" void* _ReturnAddress();
#pragma intrinsic(_ReturnAddress)

// 0x00408090
extern "C" const char* __cdecl sub_00408090()
{
    return (const char*)_ReturnAddress();
}
