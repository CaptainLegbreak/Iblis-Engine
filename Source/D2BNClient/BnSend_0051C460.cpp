#include "D2BNClient.h"

#include "D2BnCryptTypes.h"

int __cdecl BNSEND_SendLeaveChat(); // 0x0051AF20

// 0x0051C460
int __cdecl BNSEND_LeaveChat()
{
    BNSEND_SendLeaveChat();
    return 1;
}
