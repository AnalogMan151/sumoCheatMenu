// Filename: appearance_modifiers.c

#include "cheats.h"
#include "hid.h"

/********************************
 *                              *
 *	  Appearance Modifiers      *
 *				                *
 ********************************/

// Define variables to be used
u8 matchingHair,
   currentGender,
   currentSkintone;

// Appearance menu entry
void    appearanceMenu(void) {
    // Reads currently set Gender and Skin tone from memory to initialize menu with
    currentGender = READU8(0x330D67D5);
    currentSkintone = READU8(0x330D6824);

    // Creates spoiler and cheat entries
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

    // Updates the menu with stored values the first time it's loaded
    updateGender();
    updateSkintone();
}


// Changes current gender and skin tone. Sets clothes and hair to default with gender change.
void    switchLooks(void) {

    // Sets offset that appearance data starts at
    u32 offset = 0x330D67D4;

    // Runs a check to see if your selected gender is different than current
    // gender and resets clothes and hair to prevent crashing. Writes just skin
    // tone if gender was not changed, preserving appearance
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

    // Checks if gender is male and sets it to female or vice versa. Also
    // increases or decreases skin tone value to match gender
    switch(currentGender) {
        case 0x00:
            currentGender++;
            currentSkintone += 0x04;
            break;
        case 0x01:
            currentGender--;
            currentSkintone -= 0x04;
            break;
    }
    updateGender();
}


// Updates menu with current gender
void    updateGender(void) {
    replace_pattern(": ******", (currentGender == 0x00) ? ": Male  " : ": Female", SETGENDER);
}


// Cycles through skintone choices
void    setSkintone(void) {
    switch(currentSkintone) {
        case 0x18:
            currentSkintone = 0x00;
            break;
        case 0x1C:
            currentSkintone = 0x04;
            break;
        default:
            currentSkintone += 0x08;
    }
    updateSkintone();
}


// Updates menu with current skintone and changes hair color to match
void    updateSkintone(void) {
    switch(currentSkintone) {
        case 0x00:
        case 0x04:
            matchingHair = 0x83;
            replace_pattern(": *", ": A", SETSKINTONE);
            break;
        case 0x08:
        case 0x0C:
            matchingHair = 0x04;
            replace_pattern(": *", ": B", SETSKINTONE);
            break;
        case 0x10:
        case 0x14:
            matchingHair = 0x48;
            replace_pattern(": *", ": C", SETSKINTONE);
            break;
        case 0x18:
        case 0x1C:
            matchingHair = 0x08;
            replace_pattern(": *", ": D", SETSKINTONE);
            break;
    }
}
