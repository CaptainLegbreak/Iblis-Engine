struct Data0055B7E0 {
    unsigned int dwValue00;
};

struct Unit0055B7E0 {
    int nType;
    unsigned int dwUnknown04;
    unsigned int dwUnknown08;
    unsigned int dwUnknown0C;
    unsigned int f_10;
    Data0055B7E0* pData;
};

// 0x0055B7E0
extern "C" __declspec(dllexport) unsigned int __fastcall sub_0055B7E0(Unit0055B7E0* pUnit) {
    if (pUnit && pUnit->nType == 1 && pUnit->pData) {
        return pUnit->pData->dwValue00;
    }
    return 0;
}
