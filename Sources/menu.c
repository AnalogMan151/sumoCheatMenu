#include "cheats.h"

char	*builder_name = "AnalogMan",
        version[7] = "v0.2.4",
        formattedVer[23];

void	my_menus(void) {
    getVersion();
	new_unselectable_entry("Entries w/ an orange background");
    new_unselectable_entry("have notes. Press (Y) to view.");
	new_separator();
    (gameVer == 10) ? pokemonSpawnMenu() : NULL;
    (gameVer == 10) ? expMenu() : NULL;
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

    // Centers and writes version at bottom of menu
    for (int i = 0; i < 6; i++) {
        new_line();
    }
    xsprintf(formattedVer, "%22s", version);
    new_super_unselectable_entry(formattedVer, execute_all);
}
