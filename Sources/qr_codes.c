// Filename: qr_codes.c

#include "cheats.h"
#include "hid.h"

/********************************
 *                              *
 *           QR Codes           *
 *                              *
 ********************************/

u32 o_islandwait =          0x0043DAA8,
    o_qr100 =               0x3313EF33;

// QR Codes menu entry
void    qrMenu(void) {

    switch(gameVer) {
        case 10:
            break;
        case 11: ;
            o_islandwait +=   0x1C0D;
            break;
    }

    new_spoiler("QR Codes");
        new_entry("Remove Island Scan Wait", removeIslandScanWait);
        new_entry("QR Scan Point 100", qrScan100);
        new_line();
    exit_spoiler();
}


// Remove 24 hour wait time for island scanning
void	removeIslandScanWait(void) {
	WRITEU32(o_islandwait, 0xE3A00000);
}


// Sets QR Scan points to 100 allowing you to Island Scan
void	qrScan100(void) {
	WRITEU8(o_qr100, 0x64);
}
