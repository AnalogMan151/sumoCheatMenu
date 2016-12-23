// Filename: pokemon_spawner.c

#include "cheats.h"
#include "hid.h"
#include "pokemon_spawner.h"

/********************************
*				*
*	Pokemon Spawner   	*
*				*
********************************/
int i_increaseID1,
    i_increaseID10,
    i_increaseID100,
    i_increaseLVL1,
    i_increaseLVL10,
    i_activateSpawn;

int spawnID = 1,
    spawnLVL = 5;

char currentSpawn[40],
     currentLVL[40];

// Pokémon Spawner menu entry
void    pokemonSpawnMenu(void) {

    updateSpawn();
    new_spoiler("Pokemon Spawner");
        new_unselectable_entry(currentSpawn);
        new_unselectable_entry(currentLVL);
        new_spoiler("Change ID");
        i_increaseID1 = new_entry("Increase Spawn ID 1's", increaseID1);
        i_increaseID10 = new_entry("Increase Spawn ID 10's", increaseID10);
        i_increaseID100 = new_entry("Increase Spawn ID 100's", increaseID100);
        exit_spoiler();
        new_spoiler("Change LVL");
        i_increaseLVL1 = new_entry("Increase Level 1's", increaseLVL1);
        i_increaseLVL10 = new_entry("Increase Level 10's", increaseLVL10);
        exit_spoiler();
        new_spoiler("Change Form");
        new_unselectable_entry("Not yet supported");
        exit_spoiler();
        i_activateSpawn = new_entry("Activate", activateSpawn);
        set_note("Hold L to encounter Pokemon", i_activateSpawn);
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
    spawnPokemon *array;
    array = &pokemonID[spawnID - 1];
    xsprintf(currentSpawn, "Pokemon: %3d %s", array->id, array->name);
    xsprintf(currentLVL, "Level: %3d  Form: Normal" , spawnLVL);
}


// Redirects stack calls to custom location with selected data
void    activateSpawn(void) {
    u32 offset = 0x005957E0;
    WRITEU32(0x00 + offset, 0xE1D500B0);
    WRITEU32(0x04 + offset, 0xE12FFF1E);
    WRITEU32(0x08 + offset, 0xE5C40004);
    WRITEU32(0x0C + offset, 0xE59F0000);
    WRITEU32(0x10 + offset, 0xE12FFF1E);
    WRITEU32(0x14 + offset, spawnID);
    WRITEU32(0x18 + offset, spawnLVL);

    offset = 0x003988DC;
    WRITEU32(0x00 + offset, 0xEB07F3BF);
    WRITEU32(0x10 + offset, 0xEB07F3BB);
    WRITEU32(0x1C + offset, 0xEB07F3B4);

    if (is_pressed(BUTTON_L))
        WRITEU32(0x005957E4, 0xE59F000C);
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
    updateSpawn();
    disableCheat(i_increaseID1);
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
    updateSpawn();
    disableCheat(i_increaseID10);
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
    updateSpawn();
    disableCheat(i_increaseID100);
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
    disableCheat(i_increaseLVL1);
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
    disableCheat(i_increaseLVL10);
}
