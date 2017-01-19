// Filename: pokemon_modifiers.c

#include "cheats.h"
#include "hid.h"

/********************************
 *                              *
 *       Pokémon Modifiers      *
 *                              *
 ********************************/


u32 o_renamepokemon =           0x004A84F8,
    o_instantegg =              0x00444A6C,
    o_instanthatch1 =           0x005958C0,
    o_instanthatch2 =           0x004919E0;

// Pokémon menu entry
void    pokemonMenu(void) {

    switch(gameVer) {
        case 10:
            break;
        case 11: ;
            o_renamepokemon +=  0x1DA0;
            o_instantegg +=     0x1C18;
            o_instanthatch1 +=  0x1F00;
            o_instanthatch2 +=  0x1C60;
            break;
    }

    new_spoiler("Pokemon");
        new_entry("Rename any Pokemon", renamePokemon);
        new_entry_managed_note("Instant Egg from Nursery", "Hold L & talk to Nursery NPC", instantEgg, INSTANTEGG, 0);
        new_entry_arg("Instant Egg Hatching", instantHatch, 0, INSTANTHATCH, TOGGLE);
        new_line();
    exit_spoiler();
}


// Rename any Pokemon at the Name Rater
void	renamePokemon(void) {
	WRITEU32(o_renamepokemon, 0xE3A00001);
}


// Egg instantly ready when talking to Nursery NPC while holding L
void	instantEgg(void) {
    WRITEU32(o_instantegg + 0x00, (is_pressed(BUTTON_L)) ? 0xE3A01001 : 0xE2800E1E);
    WRITEU32(o_instantegg + 0x04, (is_pressed(BUTTON_L)) ? 0xE5C011E0 : 0xE1D000D0);
    WRITEU32(o_instantegg + 0x08, (is_pressed(BUTTON_L)) ? 0xEA00684B : 0xE12FFF1E);
}


// Instant egg hatching in one step
void	instantHatch(u32 state) {
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
        memcpy((void *)(o_instanthatch1), buffer, 0x18);

        switch(gameVer) {
            case 10:
                WRITEU32(o_instanthatch1 + 0x18, 0x006CE724);
                WRITEU32(o_instanthatch2, 0xEB040FB6);
                break;
            case 11:
                WRITEU32(o_instanthatch1 + 0x18, 0x006D08C0);
                WRITEU32(o_instanthatch2, 0xEB04105E);
                break;
        }
    } else {
        WRITEU32(o_instanthatch2, 0xE1A00004);
    }

}
