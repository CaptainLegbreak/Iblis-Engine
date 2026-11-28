#include "D2BNClient.h"
#include "StormApi2.h"

void __cdecl BNMESSQUEUE_DeleteQueueLock();                                                                // 0x00520200
void* gpField00Arg;                                                                                // 0x0088185C

struct D2BnLogStrc
{
    void* hLog;

    D2BnLogStrc(const char* szFileName);
    ~D2BnLogStrc();
    static void operator delete(void* pMemory)
    {
        SMemFree(pMemory, "delete", -1, 0);
    }
    void* sub_00518B90_GetHandle();
};

// 0x00518B60
D2BnLogStrc::D2BnLogStrc(const char* szFileName)
{
    SLogCreate(szFileName, 0, &hLog);
}

// 0x00518B80
D2BnLogStrc::~D2BnLogStrc()
{
    SLogClose(hLog);
}

// 0x00518B90
void* D2BnLogStrc::sub_00518B90_GetHandle()
{
    return hLog;
}

// 0x00518BC0
void __fastcall sub_00518BC0_Field00(void* pArg)
{
    gpField00Arg = pArg;
}

// build: symbol ??_GD2BnLogStrc@@QAEPAXI@Z 0x00518BD0
void sub_F28_EmitScalarDeletingDestructor(D2BnLogStrc* pLog)
{
    delete pLog;
}

// 0x00518C20
void __cdecl sub_00518C20_DeleteQueueLock()
{
    BNMESSQUEUE_DeleteQueueLock();
}
