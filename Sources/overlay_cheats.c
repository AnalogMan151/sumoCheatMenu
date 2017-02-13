// Credit to dragonfyre173 for their PokeViewNTR code: https://github.com/dragonfyre173/PokeViewNTR

#include "cheats.h"
#include "hid.h"
#include "global.h"
#include "ov.h"
#include "pokeutil/pokemon.h"
#include "pokeutil/lookup.h"

Handle fsUserHandle = 0;

#define CALLBACK_OVERLAY (101)

#define TICKS_PER_MSEC (268123.480)
#define BLANK 255,255,255

u32 battleOff = 0x006747D8;
Opponent selectedOpponent = PRIMARY;

bool isInBattle() {
	if (READU32(battleOff) >= 0x40400000 && READU32(battleOff) <= 0x40410000)
        return true;
	return false;
}

void drawPokemonID()
{
    if (is_pressed(BUTTON_R)) {
        selectedOpponent = (selectedOpponent + 1) % NUM_OPPONENTS;
        svc_sleepThread(300000000);
    }
	u8 pkbytes[232];
	Pokemon* pkm = (Pokemon*)pkbytes;

	if(pkm != 0)
	{
		decryptPokemon(selectedOpponent, pkm);

		char buf[100];
		char nick[13];
		int posX = 14;
		int posY = 11;
		// Bounding box
		OvDrawTranspartBlackRect(posX, 9, 125, 87, 1);

		// See if the pokemon's actually valid first
		if(isValid(pkm))
		{
			// This value will be updated when the battle is over
			// Now we're good to display it
			// Pokemon name
			asciiNick(pkm, nick);
			xsprintf(buf, "[%s] %s", OPPONENT_NAMES[selectedOpponent], nick);
			posY = OvDrawString(buf, posX, posY, BLANK);

			posX += 10;

			//Nature
		  	if(pkm->nature < NATURE_COUNT)
		  	{
				xsprintf(buf, "%s", NATURE_LOOKUP[pkm->nature]);
				posY = OvDrawString(buf, posX, posY, BLANK);
			}


			// Ability
			if(pkm->ability < ABILITY_COUNT)
			{
				xsprintf(buf, "%s", ABILITY_LOOKUP[pkm->ability]);
				posY = OvDrawString(buf, posX, posY, BLANK);
			}

			// Held item
			if(pkm->heldItem < ITEM_COUNT)
			{
				xsprintf(buf, "%s", ITEM_LOOKUP[pkm->heldItem]);
				posY = OvDrawString(buf, posX, posY, BLANK);
			}

			posX += 6;
			// IVs
            int statOrder[] = {0, 1, 2, 4, 5, 3};
			for(u8 i = 0; i < 6; i++)
			{
				u8 iv = getIV(pkm, statOrder[i]);
				xsprintf(buf, "%3s: %2d", STAT_NAME[statOrder[i]], iv);
				u8 r = iv > 29 ? 0 : 255;
				u8 g = iv < 2 ? 0 : 255;
				u8 b = (iv > 29 || iv < 2) ? 0 : 255;
				OvDrawString(buf, posX + (60 * (i / 3)),  posY + (12 * (i % 3)), r, g, b);
			}
		}
		else
		{
			xsprintf(buf, "[%s] No Info", OPPONENT_NAMES[selectedOpponent]);
			OvDrawString(buf, posX, posY, BLANK);
		}
	}
}


u32 overlayCallback(u32 isBottom, u32 addr, u32 addrB, u32 stride, u32 format)
{
	// Set draw settings
	OvSettings(addr, addrB, stride, format, !isBottom);
    if(is_pressed(BUTTON_X) && isBottom == 0 && isInBattle() && battleInfo) {
        drawPokemonID();
        return 0;
    }
	return 1;
}

void overlayInit(void) {
    initSharedFunc();
    plgRegisterCallback(CALLBACK_OVERLAY, (void*) overlayCallback, 0);
}
