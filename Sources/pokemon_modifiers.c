// Filename: pokemon_modifiers.c

#include "cheats.h"
#include "hid.h"

/********************************
 *                              *
 *       Pokémon Modifiers      *
 *                              *
 ********************************/

// Pokémon menu entry
void    pokemonMenu(void) {

    new_spoiler("Pokemon");
        new_entry("Rename any Pokemon", renamePokemon);
        new_entry_managed_note("Instant Egg from Nursery", "Hold L & talk to Nursery NPC", instantEgg, INSTANTEGG, 0);
        new_entry_arg("Instant Egg Hatching", instantHatch, 0, INSTANTHATCH, TOGGLE);
        new_line();
    exit_spoiler();
}


// Rename any Pokemon at the Name Rater
void	renamePokemon(void) {
    u32 offset[] =
    {
        0x004A84F8,
        0x004AA298,
        0x004AA2C0
    };
	WRITEU32(offset[gameVer], 0xE3A00001);
}


// Egg instantly ready when talking to Nursery NPC while holding L
void	instantEgg(void) {
    u32 offset[] =
    {
        0x00444A6C,
        0x00446684,
        0x004466A8
    };
    WRITEU32(offset[gameVer] + 0x00, (is_pressed(BUTTON_L)) ? 0xE3A01001 : 0xE2800E1E);
    WRITEU32(offset[gameVer] + 0x04, (is_pressed(BUTTON_L)) ? 0xE5C011E0 : 0xE1D000D0);
    WRITEU32(offset[gameVer] + 0x08, (is_pressed(BUTTON_L)) ? 0xEA00684B : 0xE12FFF1E);
}


// Instant egg hatching in one step
void	instantHatch(u32 state) {

    u32 offset[][2] =
    {
        {0x005958C0, 0x004919E0},
        {0x005977C0, 0x00493640},
        {0x005977C0, 0x00493668}
    };
    u32 data[][2] =
    {
        {0x006CE724, 0xEB040FB6},
        {0x006D08C0, 0xEB04105E},
        {0x006D08C0, 0xEB041054}
    };

    if (state) {
        static const u8 buffer[] =
        {
            0x0C, 0x00, 0x9D, 0xE5,
            0x0C, 0x50, 0x9F, 0xE5,
            0x05, 0x00, 0x50, 0xE1,
            0x00, 0x00, 0xA0, 0x03,
            0x04, 0x00, 0xA0, 0x11,
            0x1E, 0xFF, 0x2F, 0xE1
        };
        memcpy((void *)(offset[gameVer][0]), buffer, 0x18);
        WRITEU32(offset[gameVer][0] + 0x18, data[gameVer][0]);
        WRITEU32(offset[gameVer][1], data[gameVer][1]);
    } else {
        WRITEU32(offset[gameVer][1], 0xE1A00004);
    }

}
