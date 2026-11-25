#pragma once

char* __fastcall FOG_inet_ntoa(int nAddress); // 0x0040E080
int __stdcall D2QSSOCKET_SendPacket(void* pConnection, const unsigned char* pBuffer, int nSize); // 0x006BC8A0
void __stdcall CHATDLG_SetMcpResult(int nValue); // 0x00449BF0
void __stdcall CHATDLG_SetCharCreateReceived(int nValue); // 0x00449C20
struct D2LaunchAddressStrc
{
    int nData0;
    int nData1;
    int nData2;
    int nData3;
};
struct D2LaunchThreadRecordStrc
{
    int nData[0x52];
};
