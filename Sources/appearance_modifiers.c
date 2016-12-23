// Filename: appearance_modifiers.c

#include "cheats.h"
#include "hid.h"

/********************************
*				*
*	Appearance Modifiers    *
*				*
********************************/

int i_setGender,
    i_setSkintone,
    i_switchLooks;

char storedGender[40] = "Undefined",
     storedSkintone[40] = "Undefined";

u8 matchingHair,
   currentGender,
   currentSkintone;

// Appearance menu entry
void    appearanceMenu(void) {
    currentGender = READU8(0x330D67D5);
    currentSkintone = READU8(0x330D6824);
    updateGender();
    updateSkintone();
    new_spoiler("Appearance");
        new_unselectable_entry("WARNING: Gender change");
        new_unselectable_entry("resets clothes & hair");
        new_line();
        i_setGender = new_entry(storedGender, setGender);
        set_note("Open a menu to see change", i_setGender);
        i_setSkintone = new_entry(storedSkintone, setSkintone);
        set_note("Ride Pokemon to see change\nor save & reboot", i_setSkintone);
        new_separator();
        i_switchLooks = new_entry("Apply Changes", switchLooks);
        new_line();
    exit_spoiler();
}


// Changes current gender and skin tone. Sets clothes and hair to default with gender change.
void    switchLooks(void) {
    u32 offset = 0x330D67D4;

    if (currentGender == 0x00 && currentGender != READU8(0x330D67D5)) {
        WRITEU8(0x00000001 + offset, currentGender);
        WRITEU32(0x00000050 + offset, 0x00800000 + (matchingHair * 0x0100) + currentSkintone);
        WRITEU32(0x00000054 + offset, 0x00040000);
        WRITEU32(0x00000058 + offset, 0x0010040C);
        WRITEU16(0x0000005C + offset, 0x1C01);
        WRITEU8(0x000005E + offset, 0x30);
    } else if (currentGender == 0x01 && currentGender != READU8(0x330D67D5)) {
        WRITEU8(0x00000001 + offset, currentGender);
        WRITEU32(0x00000050 + offset, 0x00800000 + (matchingHair * 0x0100) + currentSkintone);
        WRITEU32(0x00000054 + offset, 0x00040000);
        WRITEU32(0x00000058 + offset, 0x00100405);
        WRITEU16(0x0000005C + offset, 0x3001);
        WRITEU8(0x000005E + offset, 0x30);
    } else {
        WRITEU8(0x00000050 + offset, currentSkintone);
    }

    WRITEU32(0x00000064 + offset, 0x00000000);

    if (any_is_pressed(0x0000CFFE))
        disableCheat(i_switchLooks);
}


// Cycles through gender choices
void    setGender(void) {
    if (currentGender == 0x00) {
        currentGender++;
        currentSkintone += 0x04;
    } else {
        currentGender--;
        currentSkintone -= 0x04;
    }

    updateGender();
    disableCheat(i_setGender);
}


// Updates menu with current gender
void    updateGender(void) {
    if (currentGender == 0x00)
        xsprintf(storedGender, "Current Gender: Male");
    if (currentGender == 0x01)
        xsprintf(storedGender, "Current Gender: Female");
}


// Cycles through skintone choices
void    setSkintone(void) {
    if (currentSkintone == 0x18)
        currentSkintone = 0x00;
    else if (currentSkintone == 0x1C)
        currentSkintone = 0x04;
    else
        currentSkintone += 0x08;

    updateSkintone();
    disableCheat(i_setSkintone);
}


// Updates menu with current skintone and changes hair color to match
void    updateSkintone(void) {
    if (currentSkintone == 0x00 || currentSkintone == 0x04) {
        matchingHair = 0x83;
        xsprintf(storedSkintone, "Current Skin Tone: A");
    }
    if (currentSkintone == 0x08 || currentSkintone == 0x0C) {
        matchingHair = 0x04;
        xsprintf(storedSkintone, "Current Skin Tone: B");
    }
    if (currentSkintone == 0x10 || currentSkintone == 0x14) {
        matchingHair = 0x48;
        xsprintf(storedSkintone, "Current Skin Tone: C");
    }
    if (currentSkintone == 0x18 || currentSkintone == 0x1C) {
        matchingHair = 0x08;
        xsprintf(storedSkintone, "Current Skin Tone: D");
    }
}
