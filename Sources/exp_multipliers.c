// Filename: exp_multipliers.c

#include "cheats.h"
#include "hid.h"

/********************************
 *                              *
 *      EXP Multipliers         *
 *                              *
 ********************************/

static char currentEXP[40] = "Undefined";
u8 exp_rate = 0;

// EXP menu entry
void    expMenu(void) {
    exp_x();
    updateEXP();

    new_spoiler("EXP Multiplier");
        new_unselectable_entry(currentEXP);
        new_separator();
        new_entry_managed("Increase 1's", increaseEXP1, INCREASEEXP1, AUTO_DISABLE);
        new_entry_managed("Increase 10's", increaseEXP10, INCREASEEXP10, AUTO_DISABLE);
        new_entry_managed("Increase 100's", increaseEXP100, INCREASEEXP100, AUTO_DISABLE);
        new_line();
    exit_spoiler();
}


// Sets the stage for Experience Modifier code by setting EXP rate to 1x
void	exp_x(void) {
    WRITEU32(0x00595800, 0xE1D002B2);
    WRITEU32(0x00595804, 0xE92D4002);
    WRITEU32(0x00595808, 0xE3A01001);
    WRITEU32(0x0059580C, 0xE0000190);
    WRITEU32(0x00595810, 0xE8BD8002);
    WRITEU32(0x0048F1EC, 0xEB041983);
}


// Reads current EXP modifier and prints it to the menu
void	updateEXP(void) {
    exp_rate = READU8(0x00595808);
    xsprintf(currentEXP, "Current EXP rate: %3dx", exp_rate);
}


// Increases EXP modifier by 1 each time it's called, updates menu and then deactivates
void	increaseEXP1(void) {

    // Extracts ones place
    exp_rate = READU8(0x00595808);
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

    WRITEU8(0x00595808, exp_rate);
    updateEXP();
}


// Increases EXP modifier by 10 each time it's called, updates menu and then deactivates
void	increaseEXP10(void) {

    // Extracts tens place
    exp_rate = READU8(0x00595808);
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

    WRITEU8(0x00595808, exp_rate);
    updateEXP();
}


// Increases EXP modifier by 100 each time it's called, updates menu and then deactivates
void	increaseEXP100(void) {

    // Extracts hundreds place
    exp_rate = READU8(0x00595808);
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

    WRITEU8(0x00595808, exp_rate);
    updateEXP();
}
