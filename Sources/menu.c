#include "cheats.h"

char	*builder_name = "AnalogMan";


void	my_menus(void) {
	set_hid_address(0x10002000);

	new_unselectable_entry("Entries w/ an orange background");
    new_unselectable_entry("have notes. Press (Y) to view.");

	new_separator();

//    pokemonSpawnMenu();
    expMenu();
    new_spoiler("Modifiers");
        timeMenu();
        appearanceMenu();
        battleMenu();
        movementMenu();
        pokemonMenu();
    exit_spoiler();
    currencyMenu();
    itemMenu();
    miscMenu();
}
