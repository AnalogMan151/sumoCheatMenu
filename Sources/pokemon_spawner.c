// Filename: pokemon_spawner.c

#include "cheats.h"
#include "hid.h"
#include "pokemon_spawner.h"

/********************************
 *                              *
 *       Pokémon Spawner        *
 *                              *
 ********************************/

int spawnID = 1,
    spawnLVL = 5,
    formIndex = 0;

char currentSpawn[40],
     currentLVL[40];

bool spawnIsOn = false,
     randomIsOn = false,
     levelpass = false;

spawnForms formID[30] = {0};

// Pokémon Spawner menu entry
void    pokemonSpawnMenu(void) {

    getForms(spawnID, formID);
    updateSpawn();
    new_spoiler("Pokemon Spawner");
        new_unselectable_entry(currentSpawn);
        new_unselectable_entry(currentLVL);
        new_spoiler("Change ID");
        new_entry_managed("Increase Spawn ID 1's", increaseID1, INCREASEID1, AUTO_DISABLE);
        new_entry_managed("Increase Spawn ID 10's", increaseID10, INCREASEID10, AUTO_DISABLE);
        new_entry_managed("Increase Spawn ID 100's", increaseID100, INCREASEID100, AUTO_DISABLE);
        new_entry_arg("Random Spawn ID", randomID, 0, RANDOMID, TOGGLE);
        exit_spoiler();
        new_spoiler("Change LVL");
        new_entry_managed("Increase Level 1's", increaseLVL1, INCREASELVL1, AUTO_DISABLE);
        new_entry_managed("Increase Level 10's", increaseLVL10, INCREASELVL10, AUTO_DISABLE);
        new_entry_arg("Passthrough Wild Level", passthruLevel, 0, PASSTHRULEVEL, TOGGLE);
        exit_spoiler();
        new_entry_managed("Change Form", setForm, SETFORM, AUTO_DISABLE);
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
    const spawnPokemon *array;
    array = &pokemonID[spawnID - 1];
    spawnForms *formArray;
    formArray = &formID[formIndex];
    if (randomIsOn) {
        xsprintf(currentSpawn, "Pokemon: Random");
        if (levelpass)
            xsprintf(currentLVL, "Level: ---  Form: Random");
        else
            xsprintf(currentLVL, "Level: %3d  Form: Random" , spawnLVL);
    } else {
        xsprintf(currentSpawn, "Pokemon: %3d %s", array->id, array->name);
        if (levelpass)
            xsprintf(currentLVL, "Level: ---  Form: %s", formArray->name);
        else
            xsprintf(currentLVL, "Level: %3d  Form: %s", spawnLVL, formArray->name);
    }
}


// Redirects stack calls to custom location with selected data
void    generateSpawn(void) {

    static const u32 offset[][2] =
    {
        {0x005957E0, 0x003988DC},
        {0x005976E0, 0x00399CB4},
        {0x0059785C, 0x00399CB4}
    };
    static const u32 data[][3] =
    {
        {0xEB07F3BF, 0xEB07F3BB, 0xEB07F3B4},
        {0xEB07F689, 0xEB07F685, 0xEB07F67E},
        {0xEB07F6E8, 0xEB07F6E4, 0xEB07F6DD}
    };

    if (spawnIsOn)
        WRITEU32(offset[gameVer][0] + 0x04, 0xE59F000C);
    else
        WRITEU32(offset[gameVer][0] + 0x04, 0xE12FFF1E);

    WRITEU32(offset[gameVer][0] + 0x00, 0xE1D500B0);
    if (levelpass)
        WRITEU32(offset[gameVer][0] + 0x08, 0xE1A00000);
    else
        WRITEU32(offset[gameVer][0] + 0x08, 0xE5C40004);
    WRITEU32(offset[gameVer][0] + 0x0C, 0xE59F0000);
    WRITEU32(offset[gameVer][0] + 0x10, 0xE12FFF1E);
    WRITEU32(offset[gameVer][0] + 0x14, spawnID + (0x800 * formIndex));
    WRITEU32(offset[gameVer][0] + 0x18, spawnLVL);
    WRITEU32(offset[gameVer][1] + 0x00, data[gameVer][0]);
    WRITEU32(offset[gameVer][1] + 0x10, data[gameVer][1]);
    WRITEU32(offset[gameVer][1] + 0x2C, data[gameVer][2]);
}

//
void    activateSpawn(u32 state) {
    spawnIsOn = state ? true : false;
}


// Increases spawn ID by 1 each time it's called, updates menu and then deactivates
void	increaseID1(void) {
    if (strcmp(currentSpawn, "Pokemon: Random") == 0) {
        disable_entry(RANDOMID);
        spawnID = 0;
    }
    // Extracts ones place
    int ones = spawnID % 10;
    spawnID -= ones;

    // Prevent going above maximum ID (802)
    if (spawnID + ones + 1 > 802)
        ones = 0;
    else if (ones < 9)
        ones++;
    else
        ones = 0;

    // Adds ones place back in
    spawnID += ones;
    getForms(spawnID, formID);
    formIndex = 0;
    updateSpawn();
}


// Increases spawn ID by 10 each time it's called, updates menu and then deactivates
void	increaseID10(void) {
    if (strcmp(currentSpawn, "Pokemon: Random") == 0) {
        disable_entry(RANDOMID);
        spawnID = 0;
    }
    // Extracts tens place
    int tens = (spawnID / 10) % 10;
    spawnID -= (tens * 10);

    // Prevent going above maximum ID (802)
    if (spawnID + (tens * 10) + 10 > 802)
        tens = 0;
    else if (tens < 9)
        tens++;
    else
        tens = 0;

    // Adds tens place back in
    spawnID += (tens * 10);
    getForms(spawnID, formID);
    formIndex = 0;
    updateSpawn();
}


// Increases spawn ID by 100 each time it's called, updates menu and then deactivates
void	increaseID100(void) {
    if (strcmp(currentSpawn, "Pokemon: Random") == 0) {
        disable_entry(RANDOMID);
        spawnID = 0;
    }
    // Extracts hundreds place
    int hundreds = (spawnID / 100);
    spawnID -= (hundreds * 100);

    // Prevent going above maximum ID (802)
    if (spawnID + (hundreds * 100) + 100 > 802)
        hundreds = 0;
    else if (hundreds < 8)
        hundreds++;
    else
        hundreds = 0;

    // Adds hundreds place back in
    spawnID += (hundreds * 100);
    getForms(spawnID, formID);
    formIndex = 0;
    updateSpawn();
}

//
void    randomID(u32 state) {
    if (state)
        randomIsOn = true;
    else {
        randomIsOn = false;
        spawnID = 1;
        formIndex = 0;
    }
    updateSpawn();
}


void    setRandomID(void) {
    if (randomIsOn) {
        if (!checkAddress(0x080AE178))
            return;
        spawnID = randomNum(1, 802);
        getForms(spawnID, formID);
        formIndex = 28;
        while (!formID[formIndex].name) {
            formIndex = randomNum(0, 27);
        }
    }
}


// Increases spawn level by 1 each time it's called, updates menu and then deactivates
void	increaseLVL1(void) {
    if (levelpass) {
        spawnLVL = 4;
        disable_entry(PASSTHRULEVEL);
    }
    // Extracts ones place
    int ones = spawnLVL % 10;
    spawnLVL -= ones;

    // Prevent going above maximum level (100)
    if (spawnLVL == 100)
        spawnLVL = 1;
    else if (ones < 9)
        ones++;
    else
        ones = 0;

    // Adds ones place back in
    spawnLVL += ones;
    updateSpawn();

}


// Increases spawn level by 10 each time it's called, updates menu and then deactivates
void	increaseLVL10(void) {
    if (levelpass) {
        spawnLVL = 5;
        disable_entry(PASSTHRULEVEL);
    }
    // Extracts tens place
    int tens = (spawnLVL / 10);
    spawnLVL -= (tens * 10);

    // Prevent going above maximum level (100)
    if (tens < 10)
        tens++;
    else
        tens = 0;

    // Adds tens place back in
    spawnLVL += (tens * 10);
    updateSpawn();

}


void    passthruLevel(u32 state) {
    if (state)
        levelpass = true;
    else
        levelpass = false;
    updateSpawn();
}



// Cycles through the forms of the selected ID
void    setForm(void) {
    if (strcmp(currentSpawn, "Pokemon: Random") == 0)
        return;
    if (!formID[formIndex + 1].name)
        formIndex = 0;
    else
        formIndex++;
    updateSpawn();

}


// Looks up ID from switch case and loads available forms into array
void    getForms(u32 id, spawnForms *formID) {
    memset32(formID, 0, sizeof(formID));
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
        case 103: // Marowak
        case 105: // Exeggutor
            formID[0].name = "Normal";
            formID[1].name = "Alola";
            break;
        case 25:  // Pikachu
            formID[0].name = "Normal";
            formID[1].name = "Original Cap";
            formID[2].name = "Hoenn Cap";
            formID[3].name = "Sinnoh Cap";
            formID[4].name = "Unova Cap";
            formID[5].name = "Kalos Cap";
            formID[6].name = "Alola Cap";
            break;
        case 201: // Unown
            formID[0].name = "A";
            formID[1].name = "B";
            formID[2].name = "C";
            formID[3].name = "D";
            formID[4].name = "E";
            formID[5].name = "F";
            formID[6].name = "G";
            formID[7].name = "H";
            formID[8].name = "I";
            formID[9].name = "J";
            formID[10].name = "K";
            formID[11].name = "L";
            formID[12].name = "M";
            formID[13].name = "N";
            formID[14].name = "O";
            formID[15].name = "P";
            formID[16].name = "Q";
            formID[17].name = "R";
            formID[18].name = "S";
            formID[19].name = "T";
            formID[20].name = "U";
            formID[21].name = "V";
            formID[22].name = "W";
            formID[23].name = "X";
            formID[24].name = "Y";
            formID[25].name = "Z";
            formID[26].name = "!";
            formID[27].name = "?";
            break;
        case 386: //Deoxys
            formID[0].name = "Normal";
            formID[1].name = "Attack";
            formID[2].name = "Defense";
            formID[3].name = "Speed";
            break;
        case 412: // Burmy
        case 413: // Wormadam
        case 414: // Mothim
            formID[0].name = "Plant";
            formID[1].name = "Sandy";
            formID[2].name = "Trash";
            break;
        case 423: //Gastrodon
            formID[0].name = "East";
            formID[1].name = "West";
            break;
        case 479: // Rotom
            formID[0].name = "Normal";
            formID[1].name = "Heat";
            formID[2].name = "Wash";
            formID[3].name = "Frost";
            formID[4].name = "Fan";
            formID[5].name = "Mow";
            break;
        case 487: // Giratina
            formID[0].name = "Altered";
            formID[1].name = "Origin";
            break;
        case 550: // Basculin
            formID[0].name = "Red";
            formID[1].name = "Blue";
            break;
        case 585: // Deerling
        case 586: // Sawsbuck
            formID[0].name = "Spring";
            formID[1].name = "Summer";
            formID[2].name = "Autumn";
            formID[3].name = "Winter";
            break;
        case 641: // Tornadus
        case 642: // Thundurus
        case 645: // Landorus
            formID[0].name = "Incarnate";
            formID[1].name = "Therian";
            break;
        case 646: // Kyurem
            formID[0].name = "Normal";
            formID[1].name = "White";
            formID[2].name = "Black";
            break;
        case 647: //Keldeo
            formID[0].name = "Ordinary";
            formID[1].name = "Resolute";
            break;
        case 658: //Greninja
            formID[0].name = "Normal";
            formID[1].name = "Ash";
            break;
        case 664: // Scatterbug
        case 665: // Spewpa
        case 666: // Vivillon
            formID[0].name = "Icy Snow";
            formID[1].name = "Polar";
            formID[2].name = "Tundra";
            formID[3].name = "Continental";
            formID[4].name = "Garden";
            formID[5].name = "Elegant";
            formID[6].name = "Meadow";
            formID[7].name = "Modern";
            formID[8].name = "Marine";
            formID[9].name = "Archipelago";
            formID[10].name = "High-Plains";
            formID[11].name = "Sandstorm";
            formID[12].name = "River";
            formID[13].name = "Monsoon";
            formID[14].name = "Savannah";
            formID[15].name = "Sun";
            formID[16].name = "Ocean";
            formID[17].name = "Jungle";
            formID[18].name = "Fancy";
            formID[19].name = "Poke Ball";
            break;
        case 669: // Flabébé
        case 671: // Florges
            formID[0].name = "Red";
            formID[1].name = "Yellow";
            formID[2].name = "Orange";
            formID[3].name = "Blue";
            formID[4].name = "White";
            break;
        case 670: // Floette
            formID[0].name = "Red";
            formID[1].name = "Yellow";
            formID[2].name = "Orange";
            formID[3].name = "Blue";
            formID[4].name = "White";
            formID[5].name = "Eternal";
            break;
        case 676: //Furfrou
            formID[0].name = "Natural";
            formID[1].name = "Heart";
            formID[2].name = "Star";
            formID[3].name = "Diamond";
            formID[4].name = "Deputante";
            formID[5].name = "Matron";
            formID[6].name = "Dandy";
            formID[7].name = "La Reine";
            formID[8].name = "Kabuki";
            formID[9].name = "Pharaoh";
            break;
        case 710: // Pumpkaboo
        case 711: // Gourgeist
            formID[0].name = "Average";
            formID[1].name = "Small";
            formID[2].name = "Large";
            formID[3].name = "Super";
            break;
        case 741: // Oricorio
            formID[0].name = "Red";
            formID[1].name = "Yellow";
            formID[2].name = "Pink";
            formID[3].name = "Blue";
            break;
        case 745: // Lycanroc
            formID[0].name = "Midday";
            formID[1].name = "Midnight";
            break;
        case 774: //Minior
            formID[0].name = "Random";
            break;
        case 801: // Magearna
            formID[0].name = "Normal";
            formID[1].name = "Original";
            break;
        default:  // All Others
            formID[0].name = "Normal";
    }
}
