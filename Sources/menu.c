#include "cheats.h"

// Note: Luma3DS LayeredFS writes code up to 0x005977B8. Do not use addresses
// prior to this when storing ASM code for cheats

char	*builder_name = "AnalogMan",
        version[7] = "v0.6.3",
        updateVer[12] = "Update v?.?",
        formattedVer[35];

int gameVer = 0;
bool battleInfo = false;

void getVersion(void) {
    protect_region(0x00100000);
    switch (READU8(0x00100040)) {
        case 0x30:
            gameVer = 0;
            xsprintf(updateVer, "%s", "Update v1.0");
            break;
        case 0x78:
            gameVer = 1;
            xsprintf(updateVer, "%s", "Update v1.1");
            break;
        case 0x80:
            gameVer = 2;
            xsprintf(updateVer, "%s", "Update v1.2");
            break;
        default:
            xsprintf(updateVer, "%s", "Update v?.?");
    }
}

void    disableOnlineCheats(void) {
    if(getWifiStatus()) {
        disable_entry(MAXBATTLESTATS);
        disable_entry(ZMOVES);
        disable_entry(INFZMOVES);
        disable_entry(SHOWOPPONENTINFO);
    }
}


void    always_run(void) {
    execute_all();
    generateSpawn();
    setRandomID();
    shinyPokemon();
    showOpponentInfoOld();
    disableOnlineCheats();
}


void	my_menus(void) {
    overlayInit();
    getVersion();
    xsprintf(formattedVer, "%14s %s", version, updateVer);
    new_unselectable_entry("Entries w/ an orange background");
    new_unselectable_entry("have notes. Press (Y) to view.");
    new_super_unselectable_entry(formattedVer, always_run);
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
    illegalMenu();
}
