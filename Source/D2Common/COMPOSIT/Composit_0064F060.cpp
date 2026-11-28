// COMPOSIT_GetWeaponClassCode is kept out of Composit.cpp because the join doesn't build equal: with its body in the
// same unit, the compiler folds D2Common_10884_COMPOSIT_unk's (0x0064F5B0) object-mode call
// COMPOSIT_GetWeaponClassCode(unit, 2, ...) to the constant ' hth' and drops the call, where the original makes it. The
// fold happens wherever the body sits in the file, so only a noinline declaration would keep the call; the piece stays.
#include "D2Structs.h"
#include "D2DataTbls.h"
#include "D2Txt.h"
#include "D2CommonApi.h"
#include "D2ClientApi.h"
struct D2InventoryStrc;

struct D2CompositStrc
{
    int nWeaponClassCode;
    int nWeaponClassId;
};

extern D2DataTablesStrc* sgptDataTables;                                                                    // 0x00744304
extern unsigned int gdwBitMasks[];                                                                          // 0x006CE268
extern const D2CompositStrc gaWeaponClassCodeTable[13];                                                     // 0x006EB748

unsigned int __stdcall ITEMS_GetWeaponClassCode(D2UnitStrc* pItem); // 0x00628500
unsigned int __stdcall ITEMS_Get2HandWeaponClassCode(D2UnitStrc* hItem); // 0x00628530
unsigned char __stdcall ITEMS_GetComponent(D2UnitStrc* pUnit);                                              // 0x00628660
unsigned short __stdcall ITEMS_GetWeaponClassId(D2UnitStrc* pUnit);                                         // 0x00629FE0
int __stdcall ITEMS_CanBeEquipped(D2UnitStrc* pItem);                                                       // 0x0062A4E0
D2UnitStrc* __stdcall INVENTORY_GetLeftHandWeapon(D2InventoryStrc* pInventory);                             // 0x0063BEF0
int __stdcall INVENTORY_GetWieldType(D2UnitStrc* pUnit, D2InventoryStrc* pInventory);                       // 0x0063D340
int __stdcall COMPOSIT_GetWeaponClassIdFromCode(int nWeaponClassCode);                                      // 0x0064F020

int __stdcall COMPOSIT_GetWeaponClassIdFromCode(int nWeaponClassCode)
{
    for (int i = 0; i < 13; ++i)
    {
        if (gaWeaponClassCodeTable[i].nWeaponClassCode == nWeaponClassCode)
        {
            return gaWeaponClassCodeTable[i].nWeaponClassId;
        }
    }

    return 0;
}

static D2CharStatsTxt* DATATBLS_GetCharStatsTxtRecord(int nClass)
{
    if (nClass >= 0 && nClass < sgptDataTables->nCharStatsTxtRecordCount)
    {
        return &sgptDataTables->pCharStatsTxt[nClass];
    }
    return 0;
}

#define WEAPONCLASS_HTH 0x20687468
#define WEAPONCLASS_HT2 0x20327468
#define WEAPONCLASS_1SS 0x20737331
#define WEAPONCLASS_1JS 0x20736A31
#define WEAPONCLASS_1JT 0x20746A31
#define WEAPONCLASS_1ST 0x20747331

// 0x0064F060
int __stdcall COMPOSIT_GetWeaponClassCode(D2UnitStrc* pUnit, int nUnitType, int nClass, int nMode, D2InventoryStrc* pInventory, int* pWeaponClassId)
{
    unsigned char nComponent = 0;

    switch (nUnitType)
    {
    case 0:
    {
        D2UnitStrc* pItem = 0;
        if (pInventory)
        {
            pItem = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
            if (pItem && ITEMS_CanBeEquipped(pItem))
            {
                if (pItem->dwUnitType != UNIT_ITEM)
                {
                    return 0;
                }

                nComponent = ITEMS_GetComponent(pItem);
                if (nComponent == 5 || nComponent == 6)
                {
                    goto CheckClass;
                }
            }

            pItem = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
            if (pItem)
            {
                if (!ITEMS_CanBeEquipped(pItem))
                {
                    pItem = 0;
                }
                else
                {
                    nComponent = ITEMS_GetComponent(pItem);
                }
            }
        }

CheckClass:
        D2CharStatsTxt* pCharStatsTxtRecord = DATATBLS_GetCharStatsTxtRecord(nClass);
        if (nMode == 0 || nMode == 0x11 || !pItem || (nComponent != 5 && nComponent != 6))
        {
            *pWeaponClassId = COMPOSIT_GetWeaponClassIdFromCode(pCharStatsTxtRecord->dwBaseWClass);
            return pCharStatsTxtRecord->dwBaseWClass;
        }

        D2UnitStrc* pRightHandItem = INVENTORY_GetItemFromBodyLoc(pInventory, 4);
        if (!ITEMS_CanBeEquipped(pRightHandItem))
        {
            pRightHandItem = 0;
        }

        D2UnitStrc* pLeftHandItem = INVENTORY_GetItemFromBodyLoc(pInventory, 5);
        if (!ITEMS_CanBeEquipped(pLeftHandItem))
        {
            pLeftHandItem = 0;
        }

        if (nClass == 4)
        {
            if (ITEMSIsA(pRightHandItem, 0x2D) && ITEMSIsA(pLeftHandItem, 0x2D))
            {
                D2UnitStrc* pPrimaryWeapon = INVENTORY_GetLeftHandWeapon(pInventory);
                if (!pPrimaryWeapon)
                {
                    INVENTORY_UpdateWeaponGUIDOnInsert(pInventory, pRightHandItem);
                    pPrimaryWeapon = pRightHandItem;
                }

                const int nWeaponClass1 = ITEMS_GetWeaponClassId(pPrimaryWeapon);
                int nWeaponClass2;
                if (pRightHandItem == pPrimaryWeapon)
                {
                    nWeaponClass2 = ITEMS_GetWeaponClassId(pLeftHandItem);
                }
                else
                {
                    nWeaponClass2 = ITEMS_GetWeaponClassId(pRightHandItem);
                }
                if (nWeaponClass1 == 2)
                {
                    if (nWeaponClass2 == 2)
                    {
                        *pWeaponClassId = COMPOSIT_GetWeaponClassIdFromCode(WEAPONCLASS_1SS);
                        return WEAPONCLASS_1SS;
                    }

                    if (nWeaponClass2 == 3)
                    {
                        *pWeaponClassId = COMPOSIT_GetWeaponClassIdFromCode(WEAPONCLASS_1JS);
                        return WEAPONCLASS_1JS;
                    }
                }
                else if (nWeaponClass1 == 3)
                {
                    if (nWeaponClass2 == 3)
                    {
                        *pWeaponClassId = COMPOSIT_GetWeaponClassIdFromCode(WEAPONCLASS_1JT);
                        return WEAPONCLASS_1JT;
                    }

                    if (nWeaponClass2 == 2)
                    {
                        *pWeaponClassId = COMPOSIT_GetWeaponClassIdFromCode(WEAPONCLASS_1ST);
                        return WEAPONCLASS_1ST;
                    }
                }

                *pWeaponClassId = COMPOSIT_GetWeaponClassIdFromCode(WEAPONCLASS_1SS);
                return WEAPONCLASS_1SS;
            }
        }
        else if (nClass == 6)
        {
            if (ITEMSIsA(pRightHandItem, 0x2D) && ITEMSIsA(pLeftHandItem, 0x2D))
            {
                *pWeaponClassId = COMPOSIT_GetWeaponClassIdFromCode(WEAPONCLASS_HT2);
                return WEAPONCLASS_HT2;
            }
        }

        int nWeaponClassCode;
        if (INVENTORY_GetWieldType(pUnit, pInventory) == 2)
        {
            nWeaponClassCode = ITEMS_Get2HandWeaponClassCode(pItem);
        }
        else
        {
            nWeaponClassCode = ITEMS_GetWeaponClassCode(pItem);
        }
        *pWeaponClassId = COMPOSIT_GetWeaponClassIdFromCode(nWeaponClassCode);
        return nWeaponClassCode;
    }
    case 1:
    {
        D2MonStats2Txt* pMonStats2TxtRecord = UNITS_GetMonStats2TxtRecordFromMonsterId(nClass);
        if (!pMonStats2TxtRecord)
        {
            *pWeaponClassId = COMPOSIT_GetWeaponClassIdFromCode(WEAPONCLASS_HTH);
            return WEAPONCLASS_HTH;
        }

        if ((nMode == 0 || nMode == 0xC) && !(pMonStats2TxtRecord->nFlags[16 >> 3] & gdwBitMasks[16 & 7]))
        {
            *pWeaponClassId = COMPOSIT_GetWeaponClassIdFromCode(WEAPONCLASS_HTH);
            return WEAPONCLASS_HTH;
        }

        *pWeaponClassId = COMPOSIT_GetWeaponClassIdFromCode(pMonStats2TxtRecord->dwBaseW);
        return pMonStats2TxtRecord->dwBaseW;
    }
    case 2:
        *pWeaponClassId = COMPOSIT_GetWeaponClassIdFromCode(WEAPONCLASS_HTH);
        return WEAPONCLASS_HTH;
    }

    *pWeaponClassId = 0;
    return 0;
}
