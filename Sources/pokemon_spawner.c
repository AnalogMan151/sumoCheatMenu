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
    if (!formID[formIndex + 1].name || formID[formIndex + 1].battleOnly)
        formIndex = 0;
    else
        formIndex++;
    updateSpawn();

}


// Looks up ID from switch case and loads available forms into array
void    getForms(u32 id, spawnForms *formID) {
    memset32(formID, 0, sizeof(formID));
    switch(id) {
        case 3:
        case 9:
        case 15:
        case 18:
        case 65:
        case 80:
        case 94:
        case 115:
        case 127:
        case 130:
        case 142:
        case 181:
        case 208:
        case 212:
        case 214:
        case 229:
        case 248:
        case 254:
        case 257:
        case 260:
        case 282:
        case 302:
        case 303:
        case 306:
        case 308:
        case 310:
        case 319:
        case 323:
        case 334:
        case 354:
        case 359:
        case 362:
        case 373:
        case 376:
        case 380:
        case 381:
        case 384:
        case 428:
        case 445:
        case 448:
        case 460:
        case 475:
        case 531:
        case 719:
            formID[0].name = "Normal";
            formID[1].name = "Mega";
            formID[1].battleOnly = 1;
            break;
        case 6:
        case 150:
            formID[0].name = "Normal";
            formID[1].name = "Mega X";
            formID[1].battleOnly = 1;
            formID[2].name = "Mega Y";
            formID[2].battleOnly = 1;
            break;
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
        case 351:
            formID[0].name = "Normal";
            formID[1].name = "Sunny";
            formID[1].battleOnly = 1;
            formID[2].name = "Rainy";
            formID[2].battleOnly = 1;
            formID[3].name = "Snowy";
            formID[3].battleOnly = 1;
            break;
        case 382:
        case 383:
            formID[0].name = "Normal";
            formID[1].name = "Primal";
            formID[1].battleOnly = 1;
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
        case 422:
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
        case 492:
            formID[0].name = "Land";
            formID[1].name = "Sky";
            formID[1].battleOnly = 1;
            break;
        case 493: // Arceus
        case 773: // Silvally
            formID[0].name = "Normal";
            formID[1].name = "Fighting";
            formID[1].battleOnly = 1;
            formID[2].name = "Flying";
            formID[2].battleOnly = 1;
            formID[3].name = "Poison";
            formID[3].battleOnly = 1;
            formID[4].name = "Ground";
            formID[4].battleOnly = 1;
            formID[5].name = "Rock";
            formID[5].battleOnly = 1;
            formID[6].name = "Bug";
            formID[6].battleOnly = 1;
            formID[7].name = "Ghost";
            formID[7].battleOnly = 1;
            formID[8].name = "Steel";
            formID[8].battleOnly = 1;
            formID[9].name = "Fire";
            formID[9].battleOnly = 1;
            formID[10].name = "Water";
            formID[10].battleOnly = 1;
            formID[11].name = "Grass";
            formID[11].battleOnly = 1;
            formID[12].name = "Electric";
            formID[12].battleOnly = 1;
            formID[13].name = "Psychic";
            formID[13].battleOnly = 1;
            formID[14].name = "Ice";
            formID[14].battleOnly = 1;
            formID[15].name = "Dragon";
            formID[15].battleOnly = 1;
            formID[16].name = "Dark";
            formID[16].battleOnly = 1;
            formID[17].name = "Fairy";
            formID[17].battleOnly = 1;
            break;
        case 550: // Basculin
            formID[0].name = "Red";
            formID[1].name = "Blue";
            break;
        case 555:
            formID[0].name = "Standard";
            formID[1].name = "Zen";
            formID[1].battleOnly = 1;
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
        case 648:
            formID[0].name = "Aria";
            formID[1].name = "Pirouette";
            formID[1].battleOnly = 1;
            break;
        case 649:
            formID[0].name = "Normal";
            formID[1].name = "Douse";
            formID[1].battleOnly = 1;
            formID[2].name = "Shock";
            formID[2].battleOnly = 1;
            formID[3].name = "Burn";
            formID[3].battleOnly = 1;
            formID[4].name = "Chill";
            formID[4].battleOnly = 1;
        case 658: //Greninja
            formID[0].name = "Normal";
            formID[1].name = "Ash";
            formID[2].name = "Bonded";
            formID[2].battleOnly = 1;
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
        case 681:
            formID[0].name = "Shield";
            formID[1].name = "Blade";
            formID[1].battleOnly = 1;
            break;
        case 710: // Pumpkaboo
        case 711: // Gourgeist
            formID[0].name = "Average";
            formID[1].name = "Small";
            formID[2].name = "Large";
            formID[3].name = "Super";
            break;
        case 716:
            formID[0].name = "Neutral";
            formID[1].name = "Active";
            break;
        case 718:
            formID[0].name = "50%";
            formID[1].name = "10%";
            formID[1].battleOnly = 1;
            formID[2].name = "10%-C";
            formID[2].battleOnly = 1;
            formID[3].name = "50%-C";
            formID[3].battleOnly = 1;
            formID[4].name = "100%-C";
            formID[4].battleOnly = 1;
            break;
        case 720:
            formID[0].name = "Confined";
            formID[1].name = "Unbound";
            formID[1].battleOnly = 1;
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
        case 746: // Wishiwashi
            formID[0].name = "Normal";
            formID[1].name = "School";
            formID[1].battleOnly = 1;
            break;
        case 774: //Minior
            formID[0].name = "R-Meteor"; // Meteor Red
            formID[1].name = "O-Meteor"; // Meteor Orange
            formID[2].name = "Y-Meteor"; // Meteor Yellow
            formID[3].name = "G-Meteor"; // Meteor Green
            formID[4].name = "B-Meteor"; // Meteor Blue
            formID[5].name = "I-Meteor"; // Meteor Indigo
            formID[6].name = "V-Meteor"; // Meteor Violet

            formID[7].name = "R-Core"; // Core Red
            formID[7].battleOnly = 1;
            formID[8].name = "O-Core"; // Core Orange
            formID[8].battleOnly = 1;
            formID[9].name = "Y-Core"; // Core Yellow
            formID[9].battleOnly = 1;
            formID[10].name = "G-Core"; // Core Green
            formID[10].battleOnly = 1;
            formID[11].name = "B-Core"; // Core Blue
            formID[11].battleOnly = 1;
            formID[12].name = "I-Core"; // Core Indigo
            formID[12].battleOnly = 1;
            formID[13].name = "V-Core"; // Core Violet
            formID[13].battleOnly = 1;
            break;
        case 778:
            formID[0].name = "Disguised";
            formID[1].name = "Busted";
            formID[1].battleOnly = 1;
            break;
        case 801: // Magearna
            formID[0].name = "Normal";
            formID[1].name = "Original";
            break;
        default:  // All Others
            formID[0].name = "Normal";
    }
}
