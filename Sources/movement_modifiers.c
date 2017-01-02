// Filename: movement_modifiers.c

#include "cheats.h"
#include "hid.h"

/********************************
*				*
*	Movement Modifiers	*
*				*
********************************/

int i_walkThruWalls;


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
    WRITEU32(0x0039AF74, (is_pressed(BUTTON_B)) ? 0x3FB00000 : 0x3F800000);
}


// Disables occational tripping animation
void	neverTrip(void) {
	WRITEU8(0x3419833E, 0x00);
}


// Walk through wall while R is held down
void	walkThruWalls(void) {
    WRITEU32(0x0039D140, (is_pressed(BUTTON_R)) ? 0xE1A00000 : 0xEB01E7E7);
    WRITEU32(0x0039D274, (is_pressed(BUTTON_R)) ? 0xE1A00000 : 0xEB01E79A);
}
