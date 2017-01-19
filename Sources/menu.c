#include "cheats.h"

char	*builder_name = "AnalogMan",
        version[7] = "v0.2.9",
        formattedVer[23];

int gameVer = 0;

void getVersion(void) {
    protect_region(0x00100000);

    if (READU8(0x00100040) == 0x30)
        gameVer = 10;
    else if (READU8(0x00100040) == 0x78)
        gameVer = 11;
    else
        new_unselectable_entry("Version not supported");
}

void	my_menus(void) {
    getVersion();
    xsprintf(formattedVer, "%22s", version);
    new_unselectable_entry("Entries w/ an orange background");
    new_unselectable_entry("have notes. Press (Y) to view.");
    new_super_unselectable_entry(formattedVer, execute_all);
	new_separator();
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
    new_line();
    new_line();
    new_separator();
    new_unselectable_entry("WARNING: The codes on the next");
    new_unselectable_entry("page may create Pokemon that");
    new_unselectable_entry("cannot be battled or traded");
    new_separator();
    pokemonSpawnMenu();

}
