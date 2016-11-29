// Filename: currency_manipulators.c

#include "cheats.h"
#include "hid.h"

/********************************
*				*
*     Currency Manipulators	*
*				*
********************************/

// Set PokeDollars to 9,999,999
void	maxMoney(void)
{
	WRITEU32(0x330D8FC0, 0x0098967F);
}

// Set current Festival Coins to 999,999
void	maxCoins(void)
{
	WRITEU32(0x33124D58, 0x000F423F);
}


// Set total Festival Coins to 9,999,999
void	totalCoins(void)
{
	WRITEU32(0x33124D5C, 0x0098967F);
}


// Set total Thumbs Up for photos to 1,500,000
void	totalThumbs(void)
{
	WRITEU32(0x33138B8C, 0x0016E360);
}


// Set Battle Points to 9,999
void	maxBP(void)
{
	if (READU32(0x0067206C) != 0x00)
	{
		u32 offset;

		// offset = READU32(0x4 + READU32(0x24 + READU32(0x0067206C)));
        offset = READU32(0x0067206C);
        offset = READU32(0x00000024 + offset);
        offset = READU32(0x00000004 + offset);

		WRITEU16(0x000037B0 + offset, 0x0000270F);
	}
}
