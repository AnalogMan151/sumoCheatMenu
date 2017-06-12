// Filename: battle_modifiers.c

#include "cheats.h"
#include "hid.h"

/********************************
 *                              *
 *      Battle Modifiers        *
 *                              *
 ********************************/

int shinyChanceValue = 4096;

// Battle menu entry
void    battleMenu(void) {

    // Creates spoiler and cheat entries

    new_spoiler("Party");
        new_entry_arg("Stat Stages +6", maxBattleStats, 0, MAXBATTLESTATS, TOGGLE);
        new_entry_arg("Use Z-Moves w/o Z-Crystal", zMoves, 0, ZMOVES, TOGGLE);
        new_entry_managed("Infinite Z-Moves", infZMoves, INFZMOVES, 0);
        new_entry_managed("Invincible Party", invincibleParty, INVINCIBLEPARTY, 0);
        new_line();
    exit_spoiler();
    new_spoiler("Opponent");
        new_entry_arg_note("No Wild Encounters", "Hold START to temporarily enable encounters", noEncounters, 0, NOENCOUNTERS, TOGGLE);
        new_entry("100% Capture Rate", catch100);
        new_entry_arg_note("View Opponent's Info", "Hold X during battle\nPress R to cycle enemies", showOpponentInfo, 0, SHOWOPPONENTINFO, TOGGLE);
        new_entry_managed("1-Hit KO", oneHitKO, ONEHITKO, 0);
        new_entry_managed("Shiny Chance: XXXXXX", decreaseShinyChance, DECREASESHINYCHANCE, AUTO_DISABLE);
        new_line();
    exit_spoiler();
    updateShiny();
}

// No wild encounters unless START is held
void    noEncounters(u32 state) {
    static const u32 offset[] =
    {
        0x0807A28C,
        0x0807A5E8,
        0x0807A5E8
    };
    if (state) {
        if (!checkAddress(offset[gameVer]))
            return;
        else {

            if (READU32(offset[gameVer]) == 0xE3A00064) {
                if (is_pressed(BUTTON_ST))
                    WRITEU32(offset[gameVer] - 0x8, 0xE3A09064);
                else
                    WRITEU32(offset[gameVer] - 0x8, 0xE3A09000);
            }
        }
    } else {
        WRITEU32(offset[gameVer] - 0x8, 0xE3A09064);
    }
}

// Shows opponent Pokémon's info during battle on bottom screen when icon is tapped
void    showOpponentInfoOld(void) {
    if (battleInfo && !getWifiStatus) {
        static const u32 offset[] =
        {
            0x080AE178,
            0x080AE5F8,
            0x080AE610
        };
        if (checkAddress(offset[gameVer])) {
            if (READU32(offset[gameVer]) == 0xE92D40F8)
                WRITEU32(offset[gameVer], 0xEAFFFEE7);
        }
    }
}

// Shows opponent Pokémon's info during battle on top screen when X is held
void    showOpponentInfo(u32 state) {

    if (state)
        battleInfo = true;
    else
        battleInfo = false;
}



// Sets all in-battle stats to +6 ranks
void    maxBattleStats(u32 state) {
    static const u32 offset[][2] =
    {
        {0x00595A00, 0x0029A048},
        {0x00597900, 0x0029A168},
        {0x00597900, 0x0029A168}
    };
    static const u32 data[] =
    {
        0xEA0BEE6C,
        0xEA0BF5E4,
        0xEA0BF5E4
    };

    // Checks if cheat is enabled from menu and executes if it is
    if (state) {

        static const u8    buffer1[144] =
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
            0x00, 0x00, 0x00, 0x00, 0x0C, 0x0C, 0x0C, 0x0C
        };
        static const u8    buffer2[][8] =
        {
            {0x70, 0x11, 0xF4, 0xEA, 0xA4, 0x77, 0x6E, 0x00},
            {0xF8, 0x09, 0xF4, 0xEA, 0x80, 0x96, 0x6E, 0x00},
            {0xF8, 0x09, 0xF4, 0xEA, 0x80, 0x96, 0x6E, 0x00}
        };

        memcpy((void *)(offset[gameVer][0]), buffer1, 0x90);
        memcpy((void *)(offset[gameVer][0] + 0x84), buffer2[gameVer], 0x08);
        WRITEU32(offset[gameVer][1], data[gameVer]);
    } else {

        // Sets value back to original when cheat is disabled
        WRITEU32(offset[gameVer][1], 0xE1A00000);
    }
}


// 100% Catch rate for Pokemon
void    catch100(void) {
    static const u32 offset[] =
    {
        0x0803528C,
        0x080350BC,
        0x080350BC
    };
    if (!checkAddress(offset[gameVer]))
        return;
    if (READU32(offset[gameVer]) == 0x0A000004)
        WRITEU32(offset[gameVer], 0xEA000004);
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
    static const u32 offset[] =
    {
        0x003183EC,
        0x00318AF0,
        0x00318AF0
    };
    if (shinyChanceValue == 4096) {
        WRITEU32(offset[gameVer], 0x0A00001C);
        return;
    } else {
        int r = randomNum(1, shinyChanceValue);
        if (r == 1)
            WRITEU32(offset[gameVer], 0xEA00001C);
        else
            WRITEU32(offset[gameVer], 0x0A00001C);
    }
}


// Use Z-Moves without the need of a Z-Crystal
void    zMoves(u32 state) {
    static const u32 offset[][3] =
    {
        {0x00595900, 0x00313DC0, 0x0036D0EC},
        {0x00597800, 0x00314300, 0x0036DFF4},
        {0x00597800, 0x00314300, 0x0036DFF4}
    };
    static const u32 data[][3] =
    {
        {0x0078BA28, 0xEB0A06CE, 0xEB0A06B5},
        {0x0078BF60, 0xEB0A0D3E, 0xEB0A0D25},
        {0x0078BF60, 0xEB0A0D3E, 0xEB0A0D25}
    };
    if (state) {
        static const u8    buffer[] =
        {
            0x05, 0x40, 0x2D, 0xE9, 0x06, 0x00, 0xA0, 0xE1,
            0x00, 0x00, 0x00, 0xEA, 0x05, 0x40, 0x2D, 0xE9,
            0x50, 0x20, 0x9D, 0xE5, 0x0C, 0x10, 0x9F, 0xE5,
            0x02, 0x00, 0x51, 0xE1, 0xB4, 0x10, 0xD5, 0x01,
            0x00, 0x10, 0xA0, 0x11, 0x05, 0x80, 0xBD, 0xE8
        };

        memcpy((void *)(offset[gameVer][0]), buffer, 0x28);
        WRITEU32(offset[gameVer][0] + 0x28, data[gameVer][0]);
        WRITEU32(offset[gameVer][1] + 0x00, data[gameVer][1]);
        WRITEU32(offset[gameVer][1] + 0x70, data[gameVer][2]);
        WRITEU32(offset[gameVer][2], 0xE3A00001);

    } else {
        WRITEU32(offset[gameVer][1] + 0x00, 0xE1D510B4);
        WRITEU32(offset[gameVer][1] + 0x70, 0xE1D510B4);
        WRITEU32(offset[gameVer][2], 0xE3A00000);
    }
}


// Inifinite Z-Moves
void    infZMoves(void) {
    static const u32 offset = 0x08031100;

    if (!checkAddress(offset + 0xDC))
        return;
    else {
        if (READU32(offset + 0xDC) == 0xE320F000) {
            WRITEU32(offset + 0xD4, 0xE3A00000);
            WRITEU32(offset + 0xD8, 0xE5C30005);
            WRITEU32(offset + 0xDC, 0xE1500000);
        }
    }
}

// 1-Hit KO
void    oneHitKO(void) {
    static const u32 offset[3] =
    {
        0x30004DB6,  // Max HP
        0x30004DB8,  // Displayed HP
        0x3000BDA0   // Actual HP
    };

    if (isInBattle()) {
        for (int i = 0; i < 6; i++) {
            // If Actual HP is above 1, set it to 1
            if (READU16(offset[2] + (i * 0x330)) > 1) {
                WRITEU16(offset[1] + (i * 0x330), READU16(offset[0] + (i * 0x330)));
                WRITEU16(offset[2] + (i * 0x330), 1);

            // If actual HP is 0, make displayed HP match
            } else if (READU16(offset[2] + (i * 0x330)) == 0)
                WRITEU16(offset[1] + (i * 0x330), 0);
        }
    }
}

// Invincible Party
void    invincibleParty(void) {
    static const u32 offset[3] =
    {
        0x30002776,  // Max HP
        0x30002778,  // Displayed HP
        0x30009760   // Actual HP
    };
    if (isInBattle()) {
        for (int i = 0; i < 6; i++) {
            if (READU16(offset[2] + (i * 0x330)) > 0) {
                // If Actual HP is less than 65535 then set it to 65535
                if (READU16(offset[2] + (i * 0x330)) < 0xFFFF)
                    WRITEU16(offset[2] + (i * 0x330), 0xFFFF);
                // If Display HP is less than max then set it to max
                if (READU16(offset[1] + (i * 0x330)) < READU16(offset[0] + (i * 0x330)))
                    WRITEU16(offset[1] + (i * 0x330), READU16(offset[0] + (i * 0x330)));
            }
        }
    }
}
