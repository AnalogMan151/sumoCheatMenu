// Filename: exp_multipliers.c

#include "cheats.h"
#include "hid.h"

/********************************
 *                              *
 *      EXP Multipliers         *
 *                              *
 ********************************/

 int i_increaseEXP1,
     i_increaseEXP10,
     i_increaseEXP100;

static char currentEXP[40] = "Undefined";
u8 exp_rate = 0;

// EXP menu entry
void    expMenu(void) {
    exp_x();
    updateEXP();

    new_spoiler("EXP Multiplier");
        new_unselectable_entry(currentEXP);
        new_separator();
        i_increaseEXP1 = new_entry("Increase 1's", increaseEXP1);
        i_increaseEXP10 = new_entry("Increase 10's", increaseEXP10);
        i_increaseEXP100 = new_entry("Increase 100's", increaseEXP100);
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
    // Prevent going above maximum exp_rate (255)
    exp_rate = READU8(0x00595808);
    int ones = exp_rate % 10;
    exp_rate -= ones;

    if (exp_rate + ones + 1 > 255)
        ones = 0;
    else if (ones < 9)
        ones++;
    else
        ones = 0;
    exp_rate += ones;

    WRITEU8(0x00595808, exp_rate);
    updateEXP();
    disableCheat(i_increaseEXP1);
}


// Increases EXP modifier by 10 each time it's called, updates menu and then deactivates
void	increaseEXP10(void) {
    // Prevent going above maximum exp_rate (255)
    exp_rate = READU8(0x00595808);
    int tens = (exp_rate / 10) % 10;
    exp_rate -= (tens * 10);

    if (exp_rate + (tens * 10) + 10 > 255)
        tens = 0;
    else if (tens < 9)
        tens++;
    else
        tens = 0;
    exp_rate += (tens * 10);

    WRITEU8(0x00595808, exp_rate);
    updateEXP();
    disableCheat(i_increaseEXP10);
}


// Increases EXP modifier by 100 each time it's called, updates menu and then deactivates
void	increaseEXP100(void) {
    // Prevent going above maximum exp_rate (255)
    exp_rate = READU8(0x00595808);
    int hundreds = (exp_rate / 100);
    exp_rate -= (hundreds * 100);

    if (exp_rate + (hundreds * 100) + 100 > 255)
        hundreds = 0;
    else if (hundreds < 2)
        hundreds++;
    else
        hundreds = 0;
    exp_rate += (hundreds * 100);

    WRITEU8(0x00595808, exp_rate);
    updateEXP();
    disableCheat(i_increaseEXP100);
}
