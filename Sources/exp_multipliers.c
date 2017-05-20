// Filename: exp_multipliers.c

#include "cheats.h"
#include "hid.h"

/********************************
 *                              *
 *        EXP Multipliers       *
 *                              *
 ********************************/

static char currentEXP[40] = "Current EXP rate:   1x";
u8 exp_rate = 1;

// EXP menu entry
void    expMenu(void) {

    new_spoiler("EXP Multiplier");
        new_unselectable_entry(currentEXP);
        new_separator();
        new_entry_managed("Increase 1's", increaseEXP1, INCREASEEXP1, AUTO_DISABLE);
        new_entry_managed("Increase 10's", increaseEXP10, INCREASEEXP10, AUTO_DISABLE);
        new_entry_managed("Increase 100's", increaseEXP100, INCREASEEXP100, AUTO_DISABLE);
        new_line();
    exit_spoiler();
}

// Reads current EXP modifier and prints it to the menu
void	updateEXP(void) {
    u32 offset[][2] =
    {
        {0x00595800, 0x0048F1EC},
        {0x00597700, 0x00490E4C},
        {0x00597700, 0x00490E74}
    };

    u32 data[] =
    {
        0xEB041983,
        0xEB041A2B,
        0xEB041A21
    };

    static const u8 buffer[] =
    {
        0xB2, 0x02, 0xD0, 0xE1,
        0x02, 0x40, 0x2D, 0xE9,
        0x01, 0x10, 0xA0, 0xE3,
        0x90, 0x01, 0x00, 0xE0,
        0x02, 0x80, 0xBD, 0xE8
    };
    memcpy((void *)(offset[gameVer][0]), buffer, 0x14);
    WRITEU8(offset[gameVer][0] + 0x08, exp_rate);
    WRITEU32(offset[gameVer][1], data[gameVer]);

    xsprintf(currentEXP, "Current EXP rate: %3dx", exp_rate);
}


// Increases EXP modifier by 1 each time it's called, updates menu and then deactivates
void	increaseEXP1(void) {

    // Extracts ones place
    int ones = exp_rate % 10;
    exp_rate -= ones;

    // Prevent going over 255
    if (exp_rate + ones + 1 > 255)
        ones = 0;
    else if (ones < 9)
        ones++;
    else
        ones = 0;

    // Adds ones place back in
    exp_rate += ones;
    updateEXP();
}


// Increases EXP modifier by 10 each time it's called, updates menu and then deactivates
void	increaseEXP10(void) {

    // Extracts tens place
    int tens = (exp_rate / 10) % 10;
    exp_rate -= (tens * 10);

    // Prevents going over 255
    if (exp_rate + (tens * 10) + 10 > 255)
        tens = 0;
    else if (tens < 9)
        tens++;
    else
        tens = 0;

    // Adds tens place back in
    exp_rate += (tens * 10);
    updateEXP();
}


// Increases EXP modifier by 100 each time it's called, updates menu and then deactivates
void	increaseEXP100(void) {

    // Extracts hundreds place
    int hundreds = (exp_rate / 100);
    exp_rate -= (hundreds * 100);

    // Prevents going over 255
    if (exp_rate + (hundreds * 100) + 100 > 255)
        hundreds = 0;
    else if (hundreds < 2)
        hundreds++;
    else
        hundreds = 0;

    // Adds hundreds place back in
    exp_rate += (hundreds * 100);
    updateEXP();
}
