// Filename: movement_modifiers.c

#include "cheats.h"
#include "hid.h"

/********************************
 *                              *
 *      Movement Modifiers      *
 *                              *
 ********************************/

// Movement menu entry
void    movementMenu(void) {

    new_spoiler("Movement");
        new_entry("Run Faster", runFaster);
        new_entry("Never Trip", neverTrip);
        new_entry_managed_note("Walk Through Walls", "Hold R = Enable\nPress R+A to toggle", walkThruWalls, WALKTHROUGHWALLS, 0);
        new_line();
    exit_spoiler();
}


// Increases run speed to 1.375x
void	runFaster(void) {
    static const u32 offset[] =
    {
        0x0039AF74,
        0x0039C394,
        0x0039C394
    };
    WRITEFLOAT(offset[gameVer], (is_pressed(BUTTON_B)) ? 1.375f : 1.0f);
}


// Disables occational tripping animation
void	neverTrip(void) {
	WRITEU8(0x3419833E, 0x00);
}


// Walk through wall while R is held down or toggle with R+A
void	walkThruWalls(void) {
    static bool permActivation = false;
    static bool btn = false;
    static const u32 offset[] =
    {
        0x0039D140,
        0x0039E560,
        0x0039E560
    };

    static const u32 original[][2] =
    {
        {0xEB01E7E7, 0xEB01E79A},
        {0xEB01E8DC, 0xEB01E88F},
        {0xEB01E8DC, 0xEB01E88F}
    };

    if (is_pressed(BUTTON_R)) {
        WRITEU32(offset[gameVer], 0xE1A00000);
        WRITEU32(offset[gameVer] + 0x134, 0xE1A00000);
        if (is_pressed(BUTTON_A) && !btn) {
            permActivation = !permActivation;
            btn = true;
        } else if (!is_pressed(BUTTON_A)) {
            btn = false;
        }
    } else if (permActivation) {
        WRITEU32(offset[gameVer], 0xE1A00000);
        WRITEU32(offset[gameVer] + 0x134, 0xE1A00000);
    } else {
        WRITEU32(offset[gameVer], original[gameVer][0]);
        WRITEU32(offset[gameVer] + 0x134, original[gameVer][1]);
    }
}
