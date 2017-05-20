// Filename: illegal_cheats.c

#include "cheats.h"
#include "hid.h"

/********************************
 *                              *
 *        Illegal Cheats        *
 *                              *
 ********************************/

u32 o_catchtrial[2] =           {0x080B8440, 0x0807638C},
    o_catchtrainers =           0x08035000,
    o_learnanyTM =              0x0048F0AC,
    o_relearnanymove =          0x0042DCD4;

void    illegalMenu(void) {

    switch(gameVer) {
        case 10:
            break;
        case 11:
            o_catchtrial[0] +=     0x04BC;
            o_catchtrial[1] +=     0x01A4;
            o_catchtrainers -=     0x01D0;
            o_learnanyTM +=        0x1C60;
            o_relearnanymove +=    0x19C4;
            break;
    }

    new_entry("Catch Trial Pokemon", catchTrial);
    new_entry("Catch Trainer's Pokemon", catchTrainers);
    new_entry_arg("Pokemon can learn any TM", learnAnyTM, 0, LEARNANYTM, TOGGLE);
    new_entry_arg("Learn all from Move Reminder", relearnAnyMove, 0, RELEARNANYMOVE, TOGGLE);
}

// Catch Pokémon during Trial
void    catchTrial(void) {

    u32 offset[][2] =
    {
        {0x080B8440, 0x0807638C},
        {0x080B88FC, 0x08076530},
        {0x080B8914, 0x08076530}
    };

    if (!checkAddress(o_catchtrial[0]))
        return;
    if (READU32(offset[gameVer][0]) == 0xE1A01004) {
        WRITEU32(offset[gameVer][1], 0xE3A00001);
        WRITEU32(offset[gameVer][0], 0xE3A01000);
    }
}


// Catch Trainer's Pokémon
void    catchTrainers(void) {

    u32 offset[] =
    {
        0x08035000,
        0x08034E30,
        0x08034E30
    };

    if (!checkAddress(o_catchtrainers + 0xC84))
        return;
    if (READU32(offset[gameVer] + 0xC84) == 0x0A00000B) {
        WRITEU32(offset[gameVer] + 0xC78, 0xE3A0B000);
        WRITEU32(offset[gameVer] + 0xC7C, 0xE590000C);
        WRITEU32(offset[gameVer] + 0xC80, 0xE5C0B000);
        WRITEU32(offset[gameVer] + 0xC84, 0xEA00000B);
    }
}

void    learnAnyTM(u32 state) {

    u32 offset[] =
    {
        0x0048F0AC,
        0x00490D0C,
        0x00490D34
    };

    static u32 original;

    if (state) {
        original = READU32(offset[gameVer]);
        WRITEU32(offset[gameVer], 0xE3A00001);
    } else {
        WRITEU32(offset[gameVer], original);
    }
}

void    relearnAnyMove(u32 state) {

    u32 offset[][2] =
    {
        {0x0042DCD4, 0x004A6B30},
        {0x0042F698, 0x004A88D0},
        {0x0042F698, 0x004A88D0}
    };

    static u32 original[4];

    if (state) {
        original[0] = READU32(offset[gameVer][0] + 0x00000);
        original[1] = READU32(offset[gameVer][0] + 0x4);
        original[2] = READU32(offset[gameVer][0] + 0x8);
        original[3] = READU32(offset[gameVer][1]);

        WRITEU32(offset[gameVer][0] + 0x0, 0xE3A01C02);
        WRITEU32(offset[gameVer][0] + 0x4, 0xE28110CF);
        WRITEU32(offset[gameVer][0] + 0x8, 0xE5851004);
        WRITEU32(offset[gameVer][1], 0xE2850001);
    } else {
        WRITEU32(offset[gameVer][0] + 0x0, original[0]);
        WRITEU32(offset[gameVer][0] + 0x4, original[1]);
        WRITEU32(offset[gameVer][0] + 0x8, original[2]);
        WRITEU32(offset[gameVer][1], original[3]);
    }
}
