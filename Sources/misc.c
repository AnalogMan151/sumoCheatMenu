// Filename: misc.c

#include "cheats.h"
#include "hid.h"


/********************************
*				*
*		Misc		*
*				*
********************************/

char statusOutlines[10] = "Undefined",
     statusNFC[10] = "Undefined";

// Misc menu entry
void    miscMenu(void) {
    new_spoiler("Misc");
//        qrMenu();
        new_entry("Instant Text Speed", instantText);
        new_entry_managed_note("Access PC Anywhere", "Hold Y while opening options menu", pcAnywhere, PCANYWHERE, 0);
        new_entry_managed_note("Rematch Trainers", "Hold L & talk to Trainer", rematchTrainers, REMATCHTRAINERS, 0);
        new_entry_managed_note("Outlines", "Open a menu to see change", toggleOutlines, TOGGLEOUTLINES, AUTO_DISABLE);
        new_entry_managed_note("NTR Debug Connection", "Disables NFC in order to\nallow stable NTR connection", toggleNFC, TOGGLENFC, AUTO_DISABLE);
        new_line();
    exit_spoiler();
    updateNFC();
    updateOutlines();
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
}


// Updates code name on menu depending on current enable / disable status
void	updateOutlines(void) {
    char buf[10];

	if (READU32(0x0041B748) == 0xE5802004)
		xsprintf(buf, "DISABLE ");
	else
		xsprintf(buf, "ENABLE  ");
    add_prefix(buf, TOGGLEOUTLINES);
}


// Disables inGame NFC to allow NTR connection outside of Festival Plaza.
void    toggleNFC(void) {
    if (READU32(0x003DFFD0) != 0xE3A01000)
        WRITEU32(0x003DFFD0, 0xE3A01000);
    else
        WRITEU32(0x003DFFD0, 0xE3A01001);
    updateNFC();
}


void    updateNFC(void) {
    char buf[10];

    if(READU32(0x003DFFD0) == 0xE3A01001)
        xsprintf(buf, "ENABLE  ");
    else
        xsprintf(buf, "DISABLE ");
    add_prefix(buf, TOGGLENFC);
}
