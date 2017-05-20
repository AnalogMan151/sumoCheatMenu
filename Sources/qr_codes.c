// Filename: qr_codes.c

#include "cheats.h"
#include "hid.h"

/********************************
 *                              *
 *           QR Codes           *
 *                              *
 ********************************/

// QR Codes menu entry
void    qrMenu(void) {

    new_spoiler("QR Codes");
        new_entry("Remove Island Scan Wait", removeIslandScanWait);
        new_entry("QR Scan Point 100", qrScan100);
        new_line();
    exit_spoiler();
}


// Remove 24 hour wait time for island scanning
void	removeIslandScanWait(void) {
    u32 offset[] =
    {
        0x0043DAA8,
        0x0043F6B4,
        0x0043F6D8
    };
	WRITEU32(offset[gameVer], 0xE3A00000);
}


// Sets QR Scan points to 100 allowing you to Island Scan
void	qrScan100(void) {
	WRITEU8(0x3313EF33, 0x64);
}
