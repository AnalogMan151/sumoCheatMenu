// Filename: misc.c

#include "cheats.h"
#include "hid.h"


/********************************
*				*
*		Misc		*
*				*
********************************/


char statusOutlines[40] = "Undefined",
     statusNFC[40] = "Undefined";
     
int i_toggleOutlines,
    i_rematchTrainers,
    i_pcAnywhere,
    i_toggleNFC;


// Misc menu entry
void    miscMenu(void) {
    updateNFC();
    updateOutlines();
    new_spoiler("Misc");
        qrMenu();
        new_entry("Instant Text Speed", instantText);
        i_pcAnywhere = new_entry("Access PC Anywhere", pcAnywhere);
        set_note("Hold Y while opening options menu", i_pcAnywhere);
        i_rematchTrainers = new_entry("Rematch Trainers", rematchTrainers);
        set_note("Hold L & talk to Trainer", i_rematchTrainers);
        i_toggleOutlines = new_entry(statusOutlines, toggleOutlines);
        set_note("Open a menu to see change", i_toggleOutlines);
        i_toggleNFC = new_entry(statusNFC, toggleNFC);
        set_note("Disables NFC in order to\nallow stable NTR connection", i_toggleNFC);
        new_line();
    exit_spoiler();
}


// Sets text speed to instant
void	instantText(void) {
	WRITEU32(0x003BF26C, 0xE3A05003);
	WRITEU32(0x003BE9C8, 0xE3A04003);
}


// Access PC from anywhere by holding START while opening options menu
void    pcAnywhere(void) {
    u32    offset;
    u32    address;

    static const u8    buffer[] =
    {
        0x0E, 0x40, 0x2D, 0xE9, 0x74, 0x10, 0x9F, 0xE5,
        0x00, 0x20, 0x91, 0xE5, 0x00, 0x30, 0xA0, 0xE3,
        0x00, 0x30, 0x81, 0xE5, 0x13, 0x3C, 0xA0, 0xE3,
        0x93, 0x30, 0x83, 0xE2, 0x03, 0x00, 0x52, 0xE1,
        0x00, 0x40, 0xA0, 0x03, 0x00, 0x40, 0xA0, 0x11,
        0x0E, 0x80, 0xBD, 0xE8, 0x0E, 0x00, 0x50, 0xE3,
        0x09, 0x7D, 0xF7, 0xEA, 0x0F, 0x40, 0x2D, 0xE9,
        0x10, 0xD0, 0x4D, 0xE2, 0x00, 0x00, 0xA0, 0xE3,
        0x00, 0x00, 0x8D, 0xE5, 0x04, 0x00, 0x8D, 0xE5,
        0x08, 0x00, 0x8D, 0xE5, 0x0C, 0x00, 0x8D, 0xE5,
        0x00, 0x30, 0xA0, 0xE1, 0x00, 0x20, 0xA0, 0xE1,
        0x13, 0x1C, 0xA0, 0xE3, 0x93, 0x10, 0x81, 0xE2,
        0x18, 0x00, 0x9F, 0xE5, 0x00, 0x10, 0x80, 0xE5,
        0x14, 0x00, 0x9F, 0xE5, 0x00, 0x00, 0x90, 0xE5,
        0xCE, 0xD9, 0xF7, 0xEB, 0x02, 0x00, 0xA0, 0xE3,
        0x10, 0xD0, 0x8D, 0xE2, 0x0F, 0x80, 0xBD, 0xE8,
        0x00, 0x60, 0x63, 0x00, 0x6C, 0x20, 0x67, 0x00
    };

    offset = 0x0;
    address = 0x00595978;
    memcpy((void *)(address + offset), buffer, 0x88);

    WRITEU32(0x0037D560, 0xEB086104);
    WRITEU32(0x00373C48, 0xEB088755);

    if (is_pressed(BUTTON_Y))
        WRITEU32(0x005959A8, 0x1AF77D09);
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


// Toggles model outlines for player and Pokemon off and on
void	toggleOutlines(void) {
	if (READU32(0x0041B748) == 0xE5802004)
		WRITEU32(0x0041B748, 0xE320F000);
	else
		WRITEU32(0x0041B748, 0xE5802004);
	updateOutlines();
	disableCheat(i_toggleOutlines);
}


// Updates code name on menu depending on current enable / disable status
void	updateOutlines(void) {
	if (READU32(0x0041B748) == 0xE5802004)
		xsprintf(statusOutlines, "Disable Outlines");
	else
		xsprintf(statusOutlines, "Enable  Outlines");
}


// Disables inGame NFC to allow NTR connection outside of Festival Plaza.
void    toggleNFC(void) {
    if (READU32(0x003DFFD0) != 0xE3A01000) {
        WRITEU32(0x003DFFD0, 0xE3A01000);
        disableCheat(i_toggleNFC);
    } else {
        WRITEU32(0x003DFFD0, 0xE3A01001);
        disableCheat(i_toggleNFC);
    }
    updateNFC();
}


void    updateNFC(void) {
    if(READU32(0x003DFFD0) == 0xE3A01001)
        xsprintf(statusNFC, "Enable  NTR Debug Connection");
    else
        xsprintf(statusNFC, "Disable NTR Debug Connection");
}
