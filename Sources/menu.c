#include "cheats.h"

char	*builder_name = "AnalogMan";

void	while_plugin_is_alive(void)
{
	execute_all();
}

void	my_menus(void) {
	// set_hid_address(0x10002000);

	new_super_unselectable_entry("Entries w/ an orange background", while_plugin_is_alive);
    new_unselectable_entry("have notes. Press (Y) to view.");

	new_separator();

    pokemonSpawnMenu();
    expMenu();
    new_spoiler("Modifiers");
       timeMenu();
       appearanceMenu();
       battleMenu();
       movementMenu();
       pokemonMenu();
    exit_spoiler();
    itemMenu();
    currencyMenu();
    miscMenu();
}
