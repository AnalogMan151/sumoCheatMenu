// Filename: qr_codes.c

#include "cheats.h"
#include "hid.h"

/********************************
*				*
*	     QR Codes		*
*				*
********************************/

// Remove 24 hour wait time for island scanning
void	removeIslandScanWait(void) {
	WRITEU32(0x0043DAA8, 0xE3A00000);
}


// Sets QR Scan points to 100 allowing you to Island Scan
void	qrScan100(void) {
	if (READU32(0x0067206C) != 0x00) {
		u32 offset;

		// offset = READU32(0x04 + READU32(0x24 + READU32(0x0067206C)));
        offset = READU32(0x0067206C);
        offset = READU32(0x00000024 + offset);
        offset = READU32(0x00000004 + offset);

		WRITEU8(0x0006960B + offset, 0x64);
	}
}
