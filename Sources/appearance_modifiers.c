// Filename: appearance_modifiers.c

#include "cheats.h"
#include "hid.h"

/********************************
*				*
*	Appearance Modifiers    *
*				*
********************************/

u8 matchingHair,
   currentGender,
   currentSkintone;

// Appearance menu entry
void    appearanceMenu(void) {
    currentGender = READU8(0x330D67D5);
    currentSkintone = READU8(0x330D6824);
    new_spoiler("Appearance");
        new_unselectable_entry("WARNING: Gender change");
        new_unselectable_entry("resets clothes & hair");
        new_line();
        new_entry_managed_note("Current Gender: XXXXXX", "Open a menu to see change", setGender, SETGENDER, AUTO_DISABLE);
        new_entry_managed_note("Current Skin Tone: X", "Ride Pokemon to see change\nor save & reboot", setSkintone, SETSKINTONE, AUTO_DISABLE);
        new_separator();
        new_entry_managed("Apply Changes", switchLooks, SWITCHLOOKS, EXECUTE_ONCE);
        new_line();
    exit_spoiler();
    updateGender();
    updateSkintone();
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
}


// Updates menu with current gender
void    updateGender(void) {
    replace_pattern(": ******", (currentGender == 0x00) ? ": Male  " : ": Female", SETGENDER);
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
}


// Updates menu with current skintone and changes hair color to match
void    updateSkintone(void) {
    if (currentSkintone == 0x00 || currentSkintone == 0x04) {
        matchingHair = 0x83;
        replace_pattern(": *", ": A", SETSKINTONE);
    }
    if (currentSkintone == 0x08 || currentSkintone == 0x0C) {
        matchingHair = 0x04;
        replace_pattern(": *", ": B", SETSKINTONE);
    }
    if (currentSkintone == 0x10 || currentSkintone == 0x14) {
        matchingHair = 0x48;
        replace_pattern(": *", ": C", SETSKINTONE);
    }
    if (currentSkintone == 0x18 || currentSkintone == 0x1C) {
        matchingHair = 0x08;
        replace_pattern(": *", ": D", SETSKINTONE);
    }
}
