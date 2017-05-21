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
        new_spoiler("Group 1");
            new_entry("Instant Text Speed", instantText);
            new_entry_arg_note("Access PC Anywhere", "Open Options submenu", pcAnywhere, 0, PCANYWHERE, TOGGLE);
            new_entry_managed_note("Rematch Trainers", "Hold L & talk to Trainer", rematchTrainers, REMATCHTRAINERS, 0);
            new_entry_arg_note("Remove Character Outlines", "Open a menu to see change", toggleOutlines, 0, TOGGLEOUTLINES, TOGGLE);
            new_entry_arg_note("NTR Debug Connection", "Disables NFC in order to allow stable NTR connection", toggleNFC, 0, TOGGLENFC, TOGGLE);
        exit_spoiler();
        new_spoiler("Group 2");
            new_entry_managed_note("Change Camera Zoom", "START+L = Enable\nSTART+R = Disable", cameraZoom, CAMERAZOOM, 0);
            new_entry_managed_note("View IV/EV on Status Screen", "Press (START) or (X) respectively on Pokemon staus screen and then change Pokemon", viewIVEV, VIEWIVEV, 0);
        exit_spoiler();
        new_line();
    exit_spoiler();
}

// Displays IVs or EVs in place of stats on Pokémon Status screen when X or START is held
void    viewIVEV(void) {

    u32 offset = 0x08010000;

    u32 version_diff[] =
    {
        0x00,
        0xE8,
        0xDE
    };

    if (!checkAddress(offset + 0xEAC))
        return;
    if (READU32(offset + 0xEAC) == 0xEBFFFCE7) {
        if (is_pressed(BUTTON_X)) {
            WRITEU32(offset + 0xE78, 0xE591000C);
            WRITEU32(offset + 0xE7C, 0xEBF77382 - version_diff[gameVer]);
            WRITEU32(offset + 0xEB0, 0xE596000C);
            WRITEU32(offset + 0xEB4, 0xEBF77374 - version_diff[gameVer]);
            WRITEU32(offset + 0xEE0, 0xE596000C);
            WRITEU32(offset + 0xEE4, 0xEBF7740A - version_diff[gameVer]);
            WRITEU32(offset + 0xF10, 0xE596000C);
            WRITEU32(offset + 0xF14, 0xEBF77409 - version_diff[gameVer]);
            WRITEU32(offset + 0xF40, 0xE596000C);
            WRITEU32(offset + 0xF44, 0xEBF77484 - version_diff[gameVer]);
            WRITEU32(offset + 0xF70, 0xE596000C);
            WRITEU32(offset + 0xF74, 0xEBF77483 - version_diff[gameVer]);
            WRITEU32(offset + 0xFA0, 0xE596000C);
            WRITEU32(offset + 0xFA4, 0xEBF773CF - version_diff[gameVer]);
        }
        if (is_pressed(BUTTON_ST)) {
            WRITEU32(offset + 0xE78, 0xE591000C);
            WRITEU32(offset + 0xE7C, 0xEBF773E3 - version_diff[gameVer]);
            WRITEU32(offset + 0xEB0, 0xE596000C);
            WRITEU32(offset + 0xEB4, 0xEBF773D5 - version_diff[gameVer]);
            WRITEU32(offset + 0xEE0, 0xE596000C);
            WRITEU32(offset + 0xEE4, 0xEBF7742D - version_diff[gameVer]);
            WRITEU32(offset + 0xF10, 0xE596000C);
            WRITEU32(offset + 0xF14, 0xEBF7742E - version_diff[gameVer]);
            WRITEU32(offset + 0xF40, 0xE596000C);
            WRITEU32(offset + 0xF44, 0xEBF774B6 - version_diff[gameVer]);
            WRITEU32(offset + 0xF70, 0xE596000C);
            WRITEU32(offset + 0xF74, 0xEBF774B7 - version_diff[gameVer]);
            WRITEU32(offset + 0xFA0, 0xE596000C);
            WRITEU32(offset + 0xFA4, 0xEBF773F0 - version_diff[gameVer]);
        }
    }
}


// Zooms camera out or in with START+L / START+R
void    cameraZoom(void) {

    u32 offset[][2] =
    {
        {0x00595824, 0x0803797C},
        {0x00597724, 0x08037B18},
        {0x00597840, 0x08037B18},
    };

    u32 data[] =
    {
        0xEBFAEBA8,
        0xEBFAEB01,
        0xEBFAEB48
    };

    static const u8    buffer[] = {
        0x1C, 0x0A, 0x94, 0xED,
        0x03, 0x1A, 0x9F, 0xED,
        0x01, 0x0A, 0x30, 0xEE,
        0x1C, 0x0A, 0x84, 0xED,
        0x04, 0x00, 0x84, 0xE2,
        0x1E, 0xFF, 0x2F, 0xE1
    };
    memcpy((void *)(offset[gameVer][0]), buffer, 0x18);

    if (!checkAddress(offset[gameVer][1]))
        return;
    else {
        if (READU32(offset[gameVer][1]) == 0xE2840004)
            WRITEU32(offset[gameVer][1], data[gameVer]);
        if (is_pressed(BUTTON_L + BUTTON_ST))
            WRITEU32(offset[gameVer][0] + 0x18, 0xC4BB8000);
        if (is_pressed(BUTTON_R + BUTTON_ST))
            WRITEU32(offset[gameVer][0] + 0x18, 0x00000000);
    }
}


// Sets text speed to instant
void	instantText(void) {

    u32 offset[] =
    {
        0x003BE9C8,
        0x003BFBF4,
        0x003BFBF4
    };

    WRITEU32(offset[gameVer] + 0x000, 0xE3A04003);
	WRITEU32(offset[gameVer] + 0x8A4, 0xE3A05003);
}


// Access PC from anywhere by opening options menu
void    pcAnywhere(u32 state) {

    u32 offset[][3] =
    {
        {0x00595978, 0x00373C48, 0x00373C48},
        {0x00597878, 0x0037E5E4, 0x00374C3C},
        {0x00597878, 0x0037E5E4, 0x00374C3C}
    };

    u32 data[][7] =
    {
        {0x1AF77D09, 0xEBF7D9CE, 0x00636000, 0x0067206C, 0xEB088755, 0xEB086104, 0xEAF77D09},
        {0x1AF77958, 0xEBF7D6DC, 0x00638000, 0x006740B4, 0xEB088B18, 0xEB0864A3, 0xEAF77958},
        {0x1AF77958, 0xEBF7D6DC, 0x00638000, 0x006740BC, 0xEB0864A3, 0xEB088B18, 0xEAF77958}
    };

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
        0x10, 0xD0, 0x8D, 0xE2, 0x0F, 0x80, 0xBD, 0xE8
    };

    if (state) {

        memcpy((void *)(offset[gameVer][0]), buffer, 0x80);
        WRITEU32(offset[gameVer][0] + 0x30, data[gameVer][0]);
        WRITEU32(offset[gameVer][0] + 0x70, data[gameVer][1]);
        WRITEU32(offset[gameVer][0] + 0x80, data[gameVer][2]);
        WRITEU32(offset[gameVer][0] + 0x84, data[gameVer][3]);
        WRITEU32(offset[gameVer][1], data[gameVer][4]);
        WRITEU32(offset[gameVer][2], data[gameVer][5]);

    } else {
        WRITEU32(offset[gameVer][0] + 0x30, data[gameVer][6]);
    }
}


// Re-battle trainer that have already been fought. Active by holding L and talking to them
void	rematchTrainers(void) {

    u32 offset[] =
    {
        0x0049D200,
        0x0049EFA0,
        0x0049EFC8
    };

    WRITEU32(offset[gameVer], (is_pressed(BUTTON_L)) ? 0xE3A00000 :  0xE5911004);
    WRITEU32(offset[gameVer] + 0x04, (is_pressed(BUTTON_L)) ? 0xE12FFF1E :  0xE5900044);
}


// Toggles model outlines for player and Pokémon off and on
void	toggleOutlines(u32 state) {

    u32 offset[] =
    {
        0x0041B748,
        0x0041CFCC,
        0x0041CFCC
    };

    WRITEU32(offset[gameVer], (state) ? 0xE320F000 : 0xE5802004);
}


// Disables inGame NFC to allow NTR connection outside of Festival Plaza.
void    toggleNFC(u32 state) {

    u32 offset[] =
    {
        0x003DFFD0,
        0x003E14C0,
        0x003E14C0
    };

    WRITEU32(offset[gameVer], (state) ? 0xE3A01000 : 0xE3A01001);
}
