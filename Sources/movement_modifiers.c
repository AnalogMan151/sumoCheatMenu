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
        new_entry_managed_note("Walk Through Walls", "Activate = Hold R", walkThruWalls, WALKTHROUGHWALLS, 0);
        new_line();
    exit_spoiler();
}


// Increases run speed to 1.375x
void	runFaster(void) {
    WRITEU32(o_runfaster, (is_pressed(BUTTON_B)) ? 0x3FB00000 : 0x3F800000);
}


// Disables occational tripping animation
void	neverTrip(void) {
	WRITEU8(o_nevertrip, 0x00);
}


// Walk through wall while R is held down
void	walkThruWalls(void) {
    u32 original[] = {0, 0};

    switch(gameVer) {
        case 10: ;
            original[0] = 0xEB01E7E7;
            original[1] = 0xEB01E79A;
            break;
        case 11: ;
            original[0] = 0xEB01E8DC;
            original[1] = 0xEB01E88F;
            break;
    }

    WRITEU32(o_walkthruwalls, (is_pressed(BUTTON_R)) ? 0xE1A00000 : original[0]);
    WRITEU32(o_walkthruwalls + 0x134, (is_pressed(BUTTON_R)) ? 0xE1A00000 : original[1]);
}
