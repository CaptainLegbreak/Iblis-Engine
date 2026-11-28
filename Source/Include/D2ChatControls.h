#pragma once

struct D2WinControlStrc;
struct D2WinControlInitStrc;

// The chat screen's controls: the first six are its panels, then its buttons, scroll buttons and ad.
enum D2ChatControlInit
{
    CHATINIT_CREATESCREENBUTTON = 6,
    CHATINIT_CONTROL_7 = 7,
    CHATINIT_JOINSCREENBUTTON = 8,
    CHATINIT_CONTROL_C = 9,
    CHATINIT_QUITBUTTON = 10,
    CHATINIT_UPBUTTON_A = 11,
    CHATINIT_DOWNBUTTON_A = 12,
    CHATINIT_UPBUTTON_B = 13,
    CHATINIT_DOWNBUTTON_B = 14,
    CHATINIT_ADIMAGE = 15,
    CHATINIT_ADSMACK = 16,
    CHATINIT_COUNT = 17,
};

// The controls the chat screen creates from gatChatControlInits, one for each entry.
extern D2WinControlStrc* gapChatDlgControls[CHATINIT_COUNT]; // 0x0077B058
