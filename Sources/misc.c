// Filename: misc.c

#include "cheats.h"
#include "hid.h"

/********************************
 *                              *
 *             Misc             *
 *                              *
 ********************************/

u32 o_camerazoom1 =            0x00595824,
    o_camerazoom2 =            0x0803797C,
    o_instanttext =            0x003BE9C8,
    o_pcanywhere1 =            0x00595978,
    o_pcanywhere2 =            0x00373C48,
    o_rematch =                0x0049D200,
    o_outlines =               0x0041B748,
    o_nfc =                    0x003DFFD0,
    o_viewivev =               0x08010000;


// Misc menu entry
void    miscMenu(void) {

    switch(gameVer) {
        case 10:
            break;
        case 11: ;
            o_camerazoom1 +=     0x1F00;
            o_camerazoom2 +=     0x019C;
            o_instanttext +=     0x122C;
            o_pcanywhere1 +=     0x1F00;
            o_pcanywhere2 +=     0x0FF4;
            o_rematch +=         0x1DA0;
            o_outlines +=        0x1884;
            o_nfc +=             0x14F0;
            break;
    }

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
    u32 version_offset = 0x00;

    switch(gameVer) {
        case 10:
            break;
        case 11:
            version_offset = 0xE8;
            break;
    }

    if (!checkAddress(o_viewivev + 0xEAC))
        return;
    if (READU32(o_viewivev + 0xEAC) == 0xEBFFFCE7) {
        if (is_pressed(BUTTON_X)) {
            WRITEU32(o_viewivev + 0xE78, 0xE591000C);
            WRITEU32(o_viewivev + 0xE7C, 0xEBF77382 - version_offset);
            WRITEU32(o_viewivev + 0xEB0, 0xE596000C);
            WRITEU32(o_viewivev + 0xEB4, 0xEBF77374 - version_offset);
            WRITEU32(o_viewivev + 0xEE0, 0xE596000C);
            WRITEU32(o_viewivev + 0xEE4, 0xEBF7740A - version_offset);
            WRITEU32(o_viewivev + 0xF10, 0xE596000C);
            WRITEU32(o_viewivev + 0xF14, 0xEBF77409 - version_offset);
            WRITEU32(o_viewivev + 0xF40, 0xE596000C);
            WRITEU32(o_viewivev + 0xF44, 0xEBF77484 - version_offset);
            WRITEU32(o_viewivev + 0xF70, 0xE596000C);
            WRITEU32(o_viewivev + 0xF74, 0xEBF77483 - version_offset);
            WRITEU32(o_viewivev + 0xFA0, 0xE596000C);
            WRITEU32(o_viewivev + 0xFA4, 0xEBF773CF - version_offset);
        }
        if (is_pressed(BUTTON_ST)) {
            WRITEU32(o_viewivev + 0xE78, 0xE591000C);
            WRITEU32(o_viewivev + 0xE7C, 0xEBF773E3 - version_offset);
            WRITEU32(o_viewivev + 0xEB0, 0xE596000C);
            WRITEU32(o_viewivev + 0xEB4, 0xEBF773D5 - version_offset);
            WRITEU32(o_viewivev + 0xEE0, 0xE596000C);
            WRITEU32(o_viewivev + 0xEE4, 0xEBF7742D - version_offset);
            WRITEU32(o_viewivev + 0xF10, 0xE596000C);
            WRITEU32(o_viewivev + 0xF14, 0xEBF7742E - version_offset);
            WRITEU32(o_viewivev + 0xF40, 0xE596000C);
            WRITEU32(o_viewivev + 0xF44, 0xEBF774B6 - version_offset);
            WRITEU32(o_viewivev + 0xF70, 0xE596000C);
            WRITEU32(o_viewivev + 0xF74, 0xEBF774B7 - version_offset);
            WRITEU32(o_viewivev + 0xFA0, 0xE596000C);
            WRITEU32(o_viewivev + 0xFA4, 0xEBF773F0 - version_offset);
        }
    }
}


// Zooms camera out or in with START+L / START+R
void    cameraZoom(void) {
    u32 camera_value;

    switch(gameVer) {
        case 10:
            camera_value = 0xEBFAEBA8;
            break;
        case 11:
            camera_value = 0xEBFAEB01;
            break;
    }

    static const u8    buffer[] = {
        0x1C, 0x0A, 0x94, 0xED,
        0x03, 0x1A, 0x9F, 0xED,
        0x01, 0x0A, 0x30, 0xEE,
        0x1C, 0x0A, 0x84, 0xED,
        0x04, 0x00, 0x84, 0xE2,
        0x1E, 0xFF, 0x2F, 0xE1
    };
    memcpy((void *)(o_camerazoom1), buffer, 0x18);

    if (!checkAddress(o_camerazoom2))
        return;
    else {
        if (READU32(o_camerazoom2) == 0xE2840004)
            WRITEU32(o_camerazoom2, camera_value);
        if (is_pressed(BUTTON_L + BUTTON_ST))
            WRITEU32(o_camerazoom1 + 0x18, 0xC4BB8000);
        if (is_pressed(BUTTON_R + BUTTON_ST))
            WRITEU32(o_camerazoom1 + 0x18, 0x00000000);
    }
}


// Sets text speed to instant
void	instantText(void) {
    WRITEU32(o_instanttext + 0x000, 0xE3A04003);
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
            0x10, 0xD0, 0x8D, 0xE2, 0x0F, 0x80, 0xBD, 0xE8
        };

        memcpy((void *)(o_pcanywhere1), buffer, 0x80);
        switch(gameVer) {
            case 10:
                WRITEU32(o_pcanywhere1 + 0x30, 0x1AF77D09);
                WRITEU32(o_pcanywhere1 + 0x70, 0xEBF7D9CE);
                WRITEU32(o_pcanywhere1 + 0x80, 0x00636000);
                WRITEU32(o_pcanywhere1 + 0x84, 0x0067206C);
                WRITEU32(o_pcanywhere2, 0xEB088755);
                WRITEU32(o_pcanywhere2 + 0x9918, 0xEB086104);
                break;
            case 11:
                WRITEU32(o_pcanywhere1 + 0x30, 0x1AF77958);
                WRITEU32(o_pcanywhere1 + 0x70, 0xEBF7D6DC);
                WRITEU32(o_pcanywhere1 + 0x80, 0x00638000);
                WRITEU32(o_pcanywhere1 + 0x84, 0x006740B4);
                WRITEU32(o_pcanywhere2 + 0x0000, 0xEB088B18);
                WRITEU32(o_pcanywhere2 + 0x99A8, 0xEB0864A3);
                break;
        }
    } else {
        switch(gameVer) {
            case 10:
                WRITEU32(o_pcanywhere1 + 0x30, 0xEAF77D09);
                break;
            case 11:
                WRITEU32(o_pcanywhere1 + 0x30, 0xEAF77958);
                break;
        }
    }
}


// Re-battle trainer that have already been fought. Active by holding L and talking to them
void	rematchTrainers(void) {
    WRITEU32(o_rematch, (is_pressed(BUTTON_L)) ? 0xE3A00000 :  0xE5911004);
    WRITEU32(o_rematch + 0x04, (is_pressed(BUTTON_L)) ? 0xE12FFF1E :  0xE5900044);
}


// Toggles model outlines for player and Pokémon off and on
void	toggleOutlines(u32 state) {
    WRITEU32(o_outlines, (state) ? 0xE320F000 : 0xE5802004);
}


// Disables inGame NFC to allow NTR connection outside of Festival Plaza.
void    toggleNFC(u32 state) {
    WRITEU32(o_nfc, (state) ? 0xE3A01000 : 0xE3A01001);
}
