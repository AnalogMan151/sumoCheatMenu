// Filename: pokemon_spawner.c

#include "cheats.h"
#include "hid.h"
#include "pokemon_spawner.h"

/********************************
*				*
*	Pokemon Spawner   	*
*				*
********************************/

int spawnID = 1,
    spawnLVL = 5,
    spawnForm = 0;

char currentSpawn[40],
     currentLVL[40],
     currentForm[7] = "Normal";

// Pokémon Spawner menu entry
void    pokemonSpawnMenu(void) {

    updateSpawn();
    new_spoiler("Pokemon Spawner");
        new_unselectable_entry(currentSpawn);
        new_unselectable_entry(currentLVL);
        new_spoiler("Change ID");
        new_entry_managed("Increase Spawn ID 1's", increaseID1, INCREASEID1, AUTO_DISABLE);
        new_entry_managed("Increase Spawn ID 10's", increaseID10, INCREASEID10, AUTO_DISABLE);
        new_entry_managed("Increase Spawn ID 100's", increaseID100, INCREASEID100, AUTO_DISABLE);
        exit_spoiler();
        new_spoiler("Change LVL");
        new_entry_managed("Increase Level 1's", increaseLVL1, INCREASELVL1, AUTO_DISABLE);
        new_entry_managed("Increase Level 10's", increaseLVL10, INCREASELVL10, AUTO_DISABLE);
        exit_spoiler();
        new_spoiler("Change Form");
        new_entry_managed("Change Form", changeForm, CHANGEFORM, AUTO_DISABLE);
        exit_spoiler();
        new_entry_arg("Activate", activateSpawn, 0, ACTIVATESPAWN, TOGGLE);
        new_line();
    exit_spoiler();
}


// Updates menu with currently selected ID and level
void    updateSpawn(void) {
    if (spawnID == 0)
        spawnID = 1;
    if (spawnLVL == 0)
        spawnLVL = 1;
    if (spawnLVL > 100)
        spawnLVL = 100;
    xsprintf(currentForm, (spawnForm) ? "Alola" : "Normal");
    spawnPokemon *array;
    array = &pokemonID[spawnID - 1];
    xsprintf(currentSpawn, "Pokemon: %3d %s", array->id, array->name);
    xsprintf(currentLVL, "Level: %3d  Form: %s" , spawnLVL, currentForm);
}


// Redirects stack calls to custom location with selected data
void    activateSpawn(u32 state) {
    u32 offset = 0x003988DC;
    static u32 original[3];
    if (state) {
        original[0] = READU32(0x00 + offset);
        original[1] = READU32(0x10 + offset);
        original[2] = READU32(0x2C + offset);

        WRITEU32(0x00 + offset, 0xEB07F3BF);
        WRITEU32(0x10 + offset, 0xEB07F3BB);
        WRITEU32(0x2C + offset, 0xEB07F3B4);

        offset = 0x005957E0;
        WRITEU32(0x00 + offset, 0xE1D500B0);
        WRITEU32(0x04 + offset, 0xE59F000C);
        WRITEU32(0x08 + offset, 0xE5C40004);
        WRITEU32(0x0C + offset, 0xE59F0000);
        WRITEU32(0x10 + offset, 0xE12FFF1E);
        WRITEU32(0x14 + offset, (spawnForm) ? spawnID + 0x800 : spawnID);
        WRITEU32(0x18 + offset, spawnLVL);


    } else {
        WRITEU32(0x00 + offset, original[0]);
        WRITEU32(0x10 + offset, original[1]);
        WRITEU32(0x2C + offset, original[2]);
    }
}


// Increases spawn ID by 1 each time it's called, updates menu and then deactivates
void	increaseID1(void) {
    // Prevent going above maximum ID (802)
    int ones = spawnID % 10;
    spawnID -= ones;

    if (spawnID + ones + 1 > 802)
        ones = 0;
    else if (ones < 9)
        ones++;
    else
        ones = 0;
    spawnID += ones;
    spawnForm = 0;
    updateSpawn();
    disable_entry(ACTIVATESPAWN);
}


// Increases spawn ID by 10 each time it's called, updates menu and then deactivates
void	increaseID10(void) {
    // Prevent going above maximum ID (802)
    int tens = (spawnID / 10) % 10;
    spawnID -= (tens * 10);

    if (spawnID + (tens * 10) + 10 > 802)
        tens = 0;
    else if (tens < 9)
        tens++;
    else
        tens = 0;
    spawnID += (tens * 10);
    spawnForm = 0;
    updateSpawn();
    disable_entry(ACTIVATESPAWN);
}


// Increases spawn ID by 100 each time it's called, updates menu and then deactivates
void	increaseID100(void) {
    // Prevent going above maximum ID (802)
    int hundreds = (spawnID / 100);
    spawnID -= (hundreds * 100);

    if (spawnID + (hundreds * 100) + 100 > 802)
        hundreds = 0;
    else if (hundreds < 8)
        hundreds++;
    else
        hundreds = 0;
    spawnID += (hundreds * 100);
    spawnForm = 0;
    updateSpawn();
    disable_entry(ACTIVATESPAWN);
}


// Increases spawn level by 1 each time it's called, updates menu and then deactivates
void	increaseLVL1(void) {
    // Prevent going above maximum level (100)
    int ones = spawnLVL % 10;
    spawnLVL -= ones;

    if (spawnLVL == 100)
        spawnLVL = 1;
    else if (ones < 9)
        ones++;
    else
        ones = 0;
    spawnLVL += ones;
    updateSpawn();
    disable_entry(ACTIVATESPAWN);
}


// Increases spawn level by 10 each time it's called, updates menu and then deactivates
void	increaseLVL10(void) {
    // Prevent going above maximum level (100)
    int tens = (spawnLVL / 10);
    spawnLVL -= (tens * 10);

    if (tens < 10)
        tens++;
    else
        tens = 0;
    spawnLVL += (tens * 10);
    updateSpawn();
    disable_entry(ACTIVATESPAWN);
}


// Changes spawn Form
void    changeForm(void) {
    spawnForm = (alolaCheck(spawnID) && !spawnForm) ? 1 : 0;

    updateSpawn();
    disable_entry(ACTIVATESPAWN);
}


// Checks if ID is on Alola Form List
bool    alolaCheck(u32 id) {
    switch(id) {
        case 19:  // Rattata
        case 20:  // Raticate
        case 26:  // Raichu
        case 27:  // Sandshrew
        case 28:  // Sandslash
        case 37:  // Vulpix
        case 38:  // Ninetails
        case 50:  // Diglett
        case 51:  // Dugtrio
        case 52:  // Meowth
        case 53:  // Persian
        case 74:  // Geodude
        case 75:  // Graveler
        case 76:  // Golem
        case 88:  // Grimer
        case 89:  // Muk
        case 105: // Marowak
        case 103: // Exeggutor
            return true;
        }
    return false;
}
