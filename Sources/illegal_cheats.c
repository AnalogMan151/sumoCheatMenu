// Filename: illegal_cheats.c

#include "cheats.h"
#include "hid.h"
#include "hook.h"

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
    if (!checkAddress(o_catchtrial[0]))
        return;
    if (READU32(o_catchtrial[0]) == 0xE1A01004) {
        WRITEU32(o_catchtrial[1], 0xE3A00001);
        WRITEU32(o_catchtrial[0], 0xE3A01000);
    }
}


// Catch Trainer's Pokémon
void    catchTrainers(void) {
    if (!checkAddress(o_catchtrainers + 0xC84))
        return;
    if (READU32(o_catchtrainers + 0xC84) == 0x0A00000B) {
        WRITEU32(o_catchtrainers + 0xC78, 0xE3A0B000);
        WRITEU32(o_catchtrainers + 0xC7C, 0xE590000C);
        WRITEU32(o_catchtrainers + 0xC80, 0xE5C0B000);
        WRITEU32(o_catchtrainers + 0xC84, 0xEA00000B);
    }
}

void    learnAnyTM(u32 state) {
    if (state) {
        WRITEU32(o_learnanyTM, 0xE3A00001);
    } else {
        // Deactivate code
    }
}

void    relearnAnyMove(u32 state) {
    if (state) {
        WRITEU32(o_relearnanymove + 0x00000, 0xE3A01C02);
        WRITEU32(o_relearnanymove + 0x00004, 0xE28110CF);
        WRITEU32(o_relearnanymove + 0x00008, 0xE5851004);
        switch(gameVer) {
            case 10:
                WRITEU32(o_relearnanymove + 0x78E5C, 0xE2850001);
                break;
            case 11:
                WRITEU32(o_relearnanymove + 0x79238, 0xE2850001);
                break;
        }
    } else {
        // Deactivate code
    }
}
