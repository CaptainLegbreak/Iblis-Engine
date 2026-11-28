#include "D2Launch.h"
#include "D2WinApi.h"

struct D2CelFileStrc;

struct Value;

class BNGatewayAccess;

struct Value { unsigned short value; };

struct Unicode
{
    unsigned short wChar;

    Unicode() {}
    Unicode(unsigned short wValue) : wChar(wValue) {}
    Unicode toUpper() const;
};

class BNGatewayAccess
{
public:
    int __stdcall NumGateways();
    int __stdcall CurGateway();

private:
    int unk0x00;
    int unk0x04;
    int m_nNumGateways;
    int m_nCurGateway;
};

extern int gnGatewayValue_007795BC; // 0x007795BC

extern int gbGatewayFlag; // 0x00779954

extern D2CelFileStrc* gpBlizNoCelFile; // 0x007796F8

extern D2CelFileStrc* gpTrademarkCelFile; // 0x007796FC

extern D2CelFileStrc* gpDiablo2LogoCelFile; // 0x00779704

extern D2CelFileStrc* gpD2LogoBlackLeftCelFile; // 0x00779708

extern D2CelFileStrc* gpD2LogoFireLeftCelFile; // 0x0077970C

extern D2CelFileStrc* gpD2LogoBlackRightCelFile; // 0x00779710

extern D2CelFileStrc* gpD2LogoFireRightCelFile; // 0x00779714

extern D2CelFileStrc* gpTitleScreenCelFile; // 0x00779718

extern D2CelFileStrc* gpCursorOHandCelFile; // 0x0077971C

extern D2CelFileStrc* gpCreditsBckgCelFile; // 0x00779720

extern D2CelFileStrc* gpRealmSelectButtonCelFile; // 0x0077972C

extern D2CelFileStrc* gpTallButtonBlankCelFile; // 0x00779730

extern D2CelFileStrc* gpCharacterSelectScreenExpCelFile; // 0x00779734

extern D2CelFileStrc* gpWideButtonBlankCelFile; // 0x00779738

extern D2CelFileStrc* gpMediumButtonBlankCelFile; // 0x0077973C

extern D2CelFileStrc* gpShortButtonBlankCelFile; // 0x00779740

extern D2CelFileStrc* gpTextBox2CelFile; // 0x00779748

extern D2CelFileStrc* gp3WideButtonBlankCelFile; // 0x0077974C

extern D2CelFileStrc* gpEditTextBoxWideCelFile; // 0x00779750

extern D2CelFileStrc* gpWideButtonBlank02CelFile; // 0x00779754

extern D2CelFileStrc* gpNarrowButtonBlankCelFile; // 0x00779758

extern D2CelFileStrc* gpGWListBoxCelFile; // 0x0077975C

extern D2CelFileStrc* gpTermsOfUseBckgCelFile; // 0x00779764

extern D2CelFileStrc* gpCharSelectBckgCelFile; // 0x00779768

extern D2CelFileStrc* gpDifficultyLevelsCelFile; // 0x0077976C

extern D2CelFileStrc* gpCinematicsSelectionCelFile; // 0x00779770

extern D2CelFileStrc* gpCinematicsSelectionExpCelFile; // 0x00779774

extern D2CelFileStrc* gpCharSelectBoxCelFile; // 0x00779778

extern D2CelFileStrc* gpCharSelectBoxGreyCelFile; // 0x0077977C

extern D2CelFileStrc* gpPopUpOkCancelCelFile; // 0x00779780

extern D2CelFileStrc* gpPopUpOkCancel2CelFile; // 0x00779784

extern D2CelFileStrc* gpSelectCharArrowsCelFile; // 0x00779788

extern D2CelFileStrc* gpRealmSelectCelFile; // 0x0077978C

extern D2CelFileStrc* gpRealmSelectButtonThinCelFile; // 0x00779790

extern D2CelFileStrc* gpCreateNewCharImageCelFile; // 0x00779794

extern D2CelFileStrc* gpPopUpOkCelFile; // 0x00779798

extern D2CelFileStrc* gpPopUp340x224CelFile; // 0x0077979C

extern D2CelFileStrc* gpPopUpWideCelFile; // 0x007797A0

extern D2CelFileStrc* gpPopUpLargestCelFile; // 0x007797A4

extern D2CelFileStrc* gpTileableDialogCelFile; // 0x007797A8

extern D2CelFileStrc* gpPopUpOk2CelFile; // 0x007797AC

extern D2CelFileStrc* gpOkCancelButtonBlankCelFile; // 0x007797B0

extern D2CelFileStrc* gpCancelButtonBlankCelFile; // 0x007797B4

extern D2CelFileStrc* gpPasswordCelFile; // 0x007797B8

extern D2CelFileStrc* gpRealmBckgCelFile; // 0x007797C8

extern D2CelFileStrc* gpJoinGameScrollBarsCelFile; // 0x007797CC

extern D2CelFileStrc* gpTcpIpBckgCelFile; // 0x007797D0

extern D2CelFileStrc* gpIPAddressBoxCelFile; // 0x007797D4

extern D2CelFileStrc* gpDownloadPatchBckgCelFile; // 0x007797D8

extern D2CelFileStrc* gpDownloadPatchBall2CelFile; // 0x007797DC

extern D2CelFileStrc* gapCellFiles_007797E0[5]; // 0x007797E0

extern D2CelFileStrc* gapCellFiles_007797F4[5]; // 0x007797F4

extern D2CelFileStrc* gapCellFiles_00779808[5]; // 0x00779808

extern D2CelFileStrc* gapCellFiles_0077981C[5]; // 0x0077981C

extern D2CelFileStrc* gapCellFiles_00779830[5]; // 0x00779830

extern D2CelFileStrc* gapCellFiles_00779844[5]; // 0x00779844

extern D2CelFileStrc* gapCellFiles_00779858[5]; // 0x00779858

extern D2CelFileStrc* gapCellFiles_00779888[3]; // 0x00779888

extern D2CelFileStrc* gapCellFiles_0077989C[3]; // 0x0077989C

// 0x0042E610
extern "C" unsigned short __fastcall sub_0042E610_GetValue(const Value* object) { return object->value; }

// 0x0042E650
Unicode Unicode::toUpper() const
{
// build: symbol ?gawToUpperTable@* 0x00730578
    return Unicode(wChar < 0x100 ? gawToUpperTable[wChar] : wChar);
}

// 0x0042E680
int __stdcall BNGatewayAccess::NumGateways()
{
    return m_nNumGateways;
}

// 0x0042E690
int __stdcall BNGatewayAccess::CurGateway()
{
    return m_nCurGateway;
}

D2CelFileStrc* gpCellFile; // 0x00779700

D2CelFileStrc* gpCharacterCreateCelFile; // 0x00779724

D2CelFileStrc* gpFireCelFile; // 0x00779728

D2CelFileStrc* gpMediumSelButtonBlankCelFile; // 0x00779744

D2CelFileStrc* gpTextBoxCelFile; // 0x007797BC

D2CelFileStrc* gpClickBoxCelFile; // 0x007797C0

D2CelFileStrc* gpJoinGameClickBoxGreyCelFile; // 0x007797C4

D2CelFileStrc* gpBaFwSCelFile; // 0x007798B0

D2CelFileStrc* gpPaFwSCelFile; // 0x007798C4
