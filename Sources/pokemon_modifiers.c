// Filename: pokemon_modifiers.c

#include "cheats.h"
#include "hid.h"

/********************************
*				*
*	Pokemon Modifiers	*
*				*
********************************/

// 100% Catch rate for Pokemon
void	catch100(void) {
	WRITEU32(0x0059585C, 0xE5D00008);
	WRITEU32(0x00595860, 0xE92D4003);
	WRITEU32(0x00595864, 0xE59D0010);
	WRITEU32(0x00595868, 0xE59F100C);
	WRITEU32(0x0059586C, 0xE1510000);
	WRITEU32(0x00595870, 0x024000F8);
	WRITEU32(0x00595874, 0x058D0010);
	WRITEU32(0x00595878, 0xE8BD8003);
	WRITEU32(0x0059587C, 0x006D839C);
	WRITEU32(0x0048F1E0, 0xEB04199D);
}


// Make wild Pokemon shiny. Activate with START+L and deactivate with START+R
void	shinyPokemon(void) {
	if (is_pressed(BUTTON_ST + BUTTON_L))
		WRITEU32(0x003183EC, 0xEA00001C);

	if (is_pressed(BUTTON_ST + BUTTON_R))
		WRITEU32(0x003183EC, 0x0A00001C);
}


// Rename any Pokemon at the Name Rater
void	renamePokemon(void) {
	WRITEU32(0x004A84F8, 0xE3A00001);
}


// Egg instantly ready when talking to Nursery NPC while holding START
void	instantEgg(void) {
    WRITEU32(0x00444A6C, 0xE2800E1E);
    WRITEU32(0x00444A70, 0xE1D000D0);
    WRITEU32(0x00444A74, 0xE12FFF1E);
	if (is_pressed(BUTTON_ST))
	{
		WRITEU32(0x00444A6C, 0xE3A01001);
		WRITEU32(0x00444A70, 0xE5C011E0);
		WRITEU32(0x00444A74, 0xEA00684B);
	}
}


// Instant egg hatching in one step
void	instantHatch(void) {
	WRITEU32(0x005958C0, 0xE59D000C);
	WRITEU32(0x005958C4, 0xE59F500C);
	WRITEU32(0x005958C8, 0xE1500005);
	WRITEU32(0x005958CC, 0x03A00000);
	WRITEU32(0x005958D0, 0x11A00004);
	WRITEU32(0x005958D4, 0xE12FFF1E);
	WRITEU32(0x005958D8, 0x006CE724);
	WRITEU32(0x004919E0, 0xEB040FB6);
}
