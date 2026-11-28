#pragma once

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

void __stdcall CHATDLG_SetCharLogonReceived(int nValue); // 0x00449C40
void __stdcall sub_00449E50_SetValue(int nValue); // 0x00449E50
int __fastcall GAME_DispatchMcpPacket(const char* pPacket, unsigned int nSize); // 0x0044B190
