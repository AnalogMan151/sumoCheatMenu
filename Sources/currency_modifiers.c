// Filename: currency_modifiers.c

#include "cheats.h"
#include "hid.h"

/********************************
*				*
*     Currency Modifiers	*
*				*
********************************/


// Currency menu entry
void    currencyMenu(void) {
    new_spoiler("Currency");
        new_entry("Maximum Poke Dollars", maxMoney);
        new_entry("Maximum Battle Points (BP)", maxBP);
        new_entry("Maximum Festival Coins", maxCoins);
        new_entry("Total Festival Coins 2,000,000", totalCoins);
        new_entry("Total Thumbs Up 1,500,000", totalThumbs);
        new_line();
    exit_spoiler();
}


// Set Poke Dollars to 9,999,999
void	maxMoney(void) {
	WRITEU32(0x330D8FC0, 0x0098967F);
}

// Set current Festival Coins to 999,999
void	maxCoins(void) {
	WRITEU32(0x33124D58, 0x000F423F);
}


// Set total Festival Coins to 2,000,000
void	totalCoins(void) {
    u32 total = 2000000;
    u32 current = READU32(0x33124D58);
    u32 spent = total - current;
    WRITEU32(0x3313DCE8, spent);
	WRITEU32(0x33124D5C, total);
}


// Set total Thumbs Up for photos to 1,500,000
void	totalThumbs(void) {
	WRITEU32(0x33138B8C, 0x0016E360);
}


// Set Battle Points to 9,999
void	maxBP(void) {
	if (READU32(0x0067206C) != 0x00) {
		u32 offset;

		// offset = READU32(0x4 + READU32(0x24 + READU32(0x0067206C)));
        offset = READU32(0x0067206C);
        offset = READU32(0x00000024 + offset);
        offset = READU32(0x00000004 + offset);

		WRITEU16(0x000037B0 + offset, 0x0000270F);
	}
}
