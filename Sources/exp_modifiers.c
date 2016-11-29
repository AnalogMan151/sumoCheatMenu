// Filename: exp_modifiers.c

#include "cheats.h"
#include "hid.h"

/********************************
 *				*
 *	  EXP Modifiers		*
 *				*
 ********************************/

// Sets the stage for Experience Modifier code by setting EXP rate to 1x
void	exp_x()
{
    WRITEU32(0x00595800, 0xE1D002B2);
    WRITEU32(0x00595804, 0xE92D4002);
    WRITEU32(0x00595808, 0xE3A01001);
    WRITEU32(0x0059580C, 0xE0000190);
    WRITEU32(0x00595810, 0xE8BD8002);
    WRITEU32(0x0048F1EC, 0xEB041983);
}


// Reads current EXP modifier and prints it to the menu
void	updateEXP(void)
{
    u8 exp_rate = READU8(0x00595808);
    xsprintf(currentEXP, "Current EXP rate: %dx", exp_rate);
}


// Increases EXP modifier by 1 each time its called, updates menu and then deactivates
void	increaseEXP(void)
{
    // Prevent going above maximum exp_rate (0xFF)
    u8 exp_rate = READU8(0x00595808);
    if (exp_rate < 0xFF)
    {
        exp_rate++;
        WRITEU8(0x00595808, exp_rate);
        updateEXP();
    }
    disableCheat(i_increaseEXP);
}


// Increases EXP modifier by 10 each time its called, updates menu and then deactivates
void	increaseEXP10(void)
{
    // Prevent going above maximum exp_rate (0xFF)
    u8 exp_rate = READU8(0x00595808);
    if (exp_rate < 0xF5)
    {
        exp_rate += 10;
        WRITEU8(0x00595808, exp_rate);
        updateEXP();
    }
    disableCheat(i_increaseEXP10);
}


// Decrease EXP modifier by 1 each time its called, updates menu and then deactivates
void	decreaseEXP(void)
{
    // Prevent going below minimum exp_rate (0x0)
    u8 exp_rate = READU8(0x00595808);
    if (exp_rate > 0x00)
    {
        exp_rate--;
        WRITEU8(0x00595808, exp_rate);
        updateEXP();
    }
    disableCheat(i_decreaseEXP);
}


// Decrease EXP modifier by 10 each time its called, updates menu and then deactivates
void	decreaseEXP10(void)
{
    // Prevent going below minimum exp_rate (0x0)
    u8 exp_rate = READU8(0x00595808);
    if (exp_rate > 0x0A)
    {
        exp_rate -= 10;
        WRITEU8(0x00595808, exp_rate);
        updateEXP();
    }
    disableCheat(i_decreaseEXP10);
}


// Resets EXP modifier back to 1x each time its called, updates menu and then deactivates
void	resetEXP(void)
{
    WRITEU8(0x00595808, 0x01);
    updateEXP();
    disableCheat(i_resetEXP);
}
