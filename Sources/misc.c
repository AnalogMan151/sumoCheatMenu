// Filename: misc.c

#include "cheats.h"
#include "hid.h"

/********************************
 *                              *
 *             Misc             *
 *                              *
 ********************************/

// Misc menu entry
void    miscMenu(void) {
    new_spoiler("Misc");
        qrMenu();
        new_entry("Instant Text Speed", instantText);
        (gameVer == 10) ? new_entry_arg_note("Access PC Anywhere", "Open Options submenu", pcAnywhere, 0, PCANYWHERE, TOGGLE) : NULL;
        (gameVer == 10) ? new_entry_managed_note("Rematch Trainers", "Hold L & talk to Trainer", rematchTrainers, REMATCHTRAINERS, 0) : NULL;
        new_entry_arg_note("Remove Character Outlines", "Open a menu to see change", toggleOutlines, 0, TOGGLEOUTLINES, TOGGLE);
        new_entry_arg_note("NTR Debug Connection", "Disables NFC in order to\nallow stable NTR connection", toggleNFC, 0, TOGGLENFC, TOGGLE);
        new_line();
    exit_spoiler();
}


// Sets text speed to instant
void	instantText(void) {
    WRITEU32(o_instanttext, 0xE3A04003);
	WRITEU32(o_instanttext + 0x8A4, 0xE3A05003);
}


// Access PC from anywhere by opening options menu
void    pcAnywhere(u32 state) {
    if (state) {
        static const u8    buffer[] =
        {
            0x0E, 0x40, 0x2D, 0xE9, 0x74, 0x10, 0x9F, 0xE5,
            0x00, 0x20, 0x91, 0xE5, 0x00, 0x30, 0xA0, 0xE3,
            0x00, 0x30, 0x81, 0xE5, 0x13, 0x3C, 0xA0, 0xE3,
            0x93, 0x30, 0x83, 0xE2, 0x03, 0x00, 0x52, 0xE1,
            0x00, 0x40, 0xA0, 0x03, 0x00, 0x40, 0xA0, 0x11,
            0x0E, 0x80, 0xBD, 0xE8, 0x0E, 0x00, 0x50, 0xE3,
            0x00, 0x00, 0x00, 0x00, 0x0F, 0x40, 0x2D, 0xE9,
            0x10, 0xD0, 0x4D, 0xE2, 0x00, 0x00, 0xA0, 0xE3,
            0x00, 0x00, 0x8D, 0xE5, 0x04, 0x00, 0x8D, 0xE5,
            0x08, 0x00, 0x8D, 0xE5, 0x0C, 0x00, 0x8D, 0xE5,
            0x00, 0x30, 0xA0, 0xE1, 0x00, 0x20, 0xA0, 0xE1,
            0x13, 0x1C, 0xA0, 0xE3, 0x93, 0x10, 0x81, 0xE2,
            0x18, 0x00, 0x9F, 0xE5, 0x00, 0x10, 0x80, 0xE5,
            0x14, 0x00, 0x9F, 0xE5, 0x00, 0x00, 0x90, 0xE5,
            0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0xA0, 0xE3,
            0x10, 0xD0, 0x8D, 0xE2, 0x0F, 0x80, 0xBD, 0xE8,
            0x00, 0x60, 0x63, 0x00, 0x6C, 0x20, 0x67, 0x00
        };

        memcpy((void *)(o_pcanywhere), buffer, 0x88);
        switch(gameVer) {
            case 10:
                WRITEU32(o_pcanywhere + 0x30, 0x1AF77D09);
                WRITEU32(o_pcanywhere + 0x70, 0xEBF7D9CE);
                WRITEU32(0x00373C48, 0xEB088755);
                WRITEU32(0x0037D560, 0xEB086104);
                break;
            case 11:
                WRITEU32(o_pcanywhere + 0x30, 0x1AF77962);
                WRITEU32(o_pcanywhere + 0x70, 0xEBF7DEAE);
                WRITEU32(0x00373C48 + 0xF74, 0xEB088AF9);
                WRITEU32(0x0037D560 + 0xF74, 0xEB0864A8);
                break;
        }
    } else {
        switch(gameVer) {
            case 10:
                WRITEU32(o_pcanywhere + 0x30, 0xEAF77D09);
                break;
            case 11:
                WRITEU32(o_pcanywhere + 0x30, 0xEAF77962);
                break;
        }
    }
}


// Re-battle trainer that have already been fought. Active by holding L and talking to them
void	rematchTrainers(void) {
    WRITEU32(0x0049D200, 0xE5911004);
    WRITEU32(0x0049D204, 0xE5900044);
	if (is_pressed(BUTTON_L)) {
		WRITEU32(0x0049D200, 0xE3A00000);
		WRITEU32(0x0049D204, 0xE12FFF1E);
	}
}


// Toggles model outlines for player and Pokémon off and on
void	toggleOutlines(u32 state) {
    WRITEU32(o_outlines, (state) ? 0xE320F000 : 0xE5802004);
}


// Disables inGame NFC to allow NTR connection outside of Festival Plaza.
void    toggleNFC(u32 state) {
    WRITEU32(o_nfc, (state) ? 0xE3A01000 : 0xE3A01001);
}
