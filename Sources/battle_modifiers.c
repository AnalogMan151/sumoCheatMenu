// Filename: battle_modifiers.c

#include "cheats.h"
#include "hid.h"

/********************************
 *                              *
 *      Battle Modifiers        *
 *                              *
 ********************************/

u32 o_noencounters =        0x0807A28C,
    o_alwayscritical[2] =   {0x0595AD0, 0x08085D1C},
    o_battlestats[2] =      {0x00595A00, 0x0029A048},
    o_shiny =               0x003183EC,
    o_catch100 =            0x0803528C,
    o_zmoves[2] =           {0x00595900, 0x00313DC0},
    o_infzmoves =           0x08031100;

u32 catch100_jump = 0;
int shinyChanceValue = 4096;

// Battle menu entry
void    battleMenu(void) {

    switch(gameVer) {
        case 10:
            break;
        case 11:
            o_noencounters +=        0x035C;
            o_alwayscritical[0] +=   0x1F00;
            o_alwayscritical[1] +=   0x03BC;
            o_battlestats[0] +=      0x1F00;
            o_battlestats[1] +=      0x0120;
            o_shiny +=               0x0704;
            o_catch100 -=            0x01D0;
            o_zmoves[0] +=           0x1F00;
            o_zmoves[1] +=           0x0540;
            break;
    }

    // Creates spoiler and cheat entries

    new_spoiler("Battle");
        new_entry_managed_note("No Wild Encounters", "Hold START to temporarily enable encounters", noEncounters, NOENCOUNTERS, 0);
        new_entry("100% Capture Rate", catch100);
        new_entry_managed("Shiny Chance: XXXXXX", decreaseShinyChance, DECREASESHINYCHANCE, AUTO_DISABLE);
        new_entry_arg_note("View Opponent's Info", "Hold X during battle\nPress R to cycle enemies", showOpponentInfo, 0, SHOWOPPONENTINFO, TOGGLE);
        new_entry_arg("Stat Stages +6", maxBattleStats, 0, MAXBATTLESTATS, TOGGLE);
        new_entry_arg("Use Z-Moves w/o Z-Crystal", zMoves, 0, ZMOVES, TOGGLE);
        new_entry_managed("Infinite Z-Moves", infZMoves, INFZMOVES, 0);
        new_line();
    exit_spoiler();
    updateShiny();
}

// No wild encounters unless START is held
void    noEncounters(void) {
    if (!checkAddress(o_noencounters))
        return;
    else {
        if (READU32(o_noencounters) == 0xE3A00064 || READU32(o_noencounters) == 0xE3A09000) {
            if (is_pressed(BUTTON_ST))
                WRITEU32(o_noencounters, 0xE3A00064);
            else
                WRITEU32(o_noencounters, 0xE3A09000);
        }
    }
}


// Shows opponent Pokémon's info during battle on bottom screen when icon is tapped
void    showOpponentInfo(u32 state) {
    if (state)
        battleInfo = true;
    else
        battleInfo = false;
}



// Sets all in-battle stats to +6 ranks
void    maxBattleStats(u32 state) {
    static u32  original;

    // Checks if cheat is enabled from menu and executes if it is
    if (state) {

        // Stores original value in memory
        original = READU32(o_battlestats[1]);

        static const u8    buffer[] =
        {
            0x80, 0x20, 0x9F, 0xE5, 0x0E, 0x00, 0x52, 0xE1,
            0x1D, 0x00, 0x00, 0x1A, 0x1F, 0x00, 0x2D, 0xE9,
            0x74, 0x20, 0x9F, 0xE5, 0xD0, 0x00, 0x94, 0xE5,
            0x04, 0x30, 0x80, 0xE2, 0x1C, 0x40, 0x80, 0xE2,
            0x04, 0x10, 0x93, 0xE4, 0x00, 0x00, 0x51, 0xE3,
            0xEA, 0x21, 0xC1, 0x15, 0xEB, 0x21, 0xC1, 0x15,
            0xEC, 0x21, 0x81, 0x15, 0xF0, 0x21, 0xC1, 0x15,
            0x04, 0x00, 0x53, 0xE1, 0xF7, 0xFF, 0xFF, 0x1A,
            0x2C, 0x00, 0x9D, 0xE5, 0x88, 0x0A, 0x90, 0xE5,
            0x01, 0x0A, 0x80, 0xE2, 0x08, 0x08, 0x90, 0xE5,
            0x0C, 0x00, 0x90, 0xE5, 0x08, 0x00, 0x90, 0xE5,
            0x04, 0x30, 0x80, 0xE2, 0x1C, 0x40, 0x80, 0xE2,
            0x04, 0x10, 0x93, 0xE4, 0x00, 0x00, 0x51, 0xE3,
            0xEA, 0x21, 0xC1, 0x15, 0xEB, 0x21, 0xC1, 0x15,
            0xEC, 0x21, 0x81, 0x15, 0xF0, 0x21, 0xC1, 0x15,
            0x04, 0x00, 0x53, 0xE1, 0xF7, 0xFF, 0xFF, 0x1A,
            0x1F, 0x00, 0xBD, 0xE8, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x6E, 0x00, 0x0C, 0x0C, 0x0C, 0x0C
        };
        static const u8    buffer10[] =
        {
            0x70, 0x11, 0xF4, 0xEA, 0xA4, 0x77
        };
        static const u8    buffer11[] =
        {
            0xF8, 0x09, 0xF4, 0xEA, 0x80, 0x96
        };

        memcpy((void *)(o_battlestats[0]), buffer, 0x90);
        switch(gameVer) {
            case 10:
                memcpy((void *)(o_battlestats[0] + 0x84), buffer10, 0x06);
                WRITEU32(o_battlestats[1], 0xEA0BEE6C);
                break;
            case 11:
                memcpy((void *)(o_battlestats[0] + 0x84), buffer11, 0x06);
                WRITEU32(o_battlestats[1], 0xEA0BF5E4);
                break;
        }
    } else {

        // Sets value back to original when cheat is disabled
        WRITEU32(o_battlestats[1], original);
    }
}


// 100% Catch rate for Pokemon
void    catch100(void) {
    if (!checkAddress(o_catch100))
        return;
    if (READU32(o_catch100) == 0x0A000004)
        WRITEU32(o_catch100, 0xEA000004);
}

//
void    updateShiny(void) {
    char buf[7];
    xsprintf(buf, ": 1/%-4d", shinyChanceValue);
    replace_pattern(": ******", (shinyChanceValue == 4096) ? ": Normal" : buf, DECREASESHINYCHANCE);
}


//
void    decreaseShinyChance(void) {
    if (shinyChanceValue == 4096)
        shinyChanceValue = 1;
    else
        shinyChanceValue *= 2;
    updateShiny();
}


// Make wild Pokemon shiny
void	shinyPokemon(void) {
    if (shinyChanceValue == 4096) {
        WRITEU32(o_shiny, 0x0A00001C);
        return;
    } else {
        int r = randomNum(1, shinyChanceValue);
        if (r == 1)
            WRITEU32(o_shiny, 0xEA00001C);
        else
            WRITEU32(o_shiny, 0x0A00001C);
    }
}


// Use Z-Moves without the need of a Z-Crystal
void    zMoves(u32 state) {
    if (state) {
        static const u8    buffer[] =
        {
            0x05, 0x40, 0x2D, 0xE9, 0x06, 0x00, 0xA0, 0xE1,
            0x00, 0x00, 0x00, 0xEA, 0x05, 0x40, 0x2D, 0xE9,
            0x50, 0x20, 0x9D, 0xE5, 0x0C, 0x10, 0x9F, 0xE5,
            0x02, 0x00, 0x51, 0xE1, 0xB4, 0x10, 0xD5, 0x01,
            0x00, 0x10, 0xA0, 0x11, 0x05, 0x80, 0xBD, 0xE8
        };

        memcpy((void *)(o_zmoves[0]), buffer, 0x28);

        switch(gameVer) {
            case 10:
                WRITEU32(o_zmoves[0] + 0x28, 0x0078BA28);
                WRITEU32(o_zmoves[1] + 0x00, 0xEB0A06CE);
                WRITEU32(o_zmoves[1] + 0x70, 0xEB0A06B5);
                WRITEU32(o_zmoves[1] + 0x5932C, 0xE3A00001);
                break;
            case 11:
                WRITEU32(o_zmoves[0] + 0x28, 0x0078BF60);
                WRITEU32(o_zmoves[1] + 0x00, 0xEB0A0D3E);
                WRITEU32(o_zmoves[1] + 0x70, 0xEB0A0D25);
                WRITEU32(o_zmoves[1] + 0x59CF4, 0xE3A00001);
                break;
        }

    } else {
        WRITEU32(o_zmoves[1] + 0x00, 0xE1D510B4);
        WRITEU32(o_zmoves[1] + 0x70, 0xE1D510B4);
        switch(gameVer) {
            case 10:
                WRITEU32(o_zmoves[1] + 0x5932C, 0xE3A00000);
                break;
            case 11:
                WRITEU32(o_zmoves[1] + 0x59CF4, 0xE3A00000);
                break;
        }
    }
}


// Inifinite Z-Moves
void    infZMoves(void) {
    if (!checkAddress(o_infzmoves + 0xDC))
        return;
    else {
        if (READU32(o_infzmoves + 0xDC) == 0xE320F000) {
            WRITEU32(o_infzmoves + 0xD4, 0xE3A00000);
            WRITEU32(o_infzmoves + 0xD8, 0xE5C30005);
            WRITEU32(o_infzmoves + 0xDC, 0xE1500000);
        }
    }
}
