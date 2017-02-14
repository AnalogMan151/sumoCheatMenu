#ifndef POKEMON_H
#define POKEMON_H
#include "3dstypes.h"

// https://github.com/drgoku282/PKMN-NTR

#define NUM_OPPONENTS 7

typedef enum Stat {
    HP=0, ATK, DEF, SPE, SPA, SPD
} Stat;

typedef enum Opponent {
    PRIMARY = 0,
    SECONDARY,
    SOS0, SOS1, SOS2, SOS3, SOS4
} Opponent;

static const u8* OPPONENT_POINTERS[NUM_OPPONENTS] = {
    (u8*)0x3254F4AC, (u8*)0x32550284, (u8*)0x3003969C, (u8*)0x3002FD64,
    (u8*)0x3002FF48, (u8*)0x3003012C, (u8*)0x30030310
};

static const char *OPPONENT_NAMES[NUM_OPPONENTS] = {
    "1st", "2nd", "SOS0", "SOS1", "SOS2", "SOS3", "SOS4"
};

static const char *STAT_NAME[] = {
    "HP", "ATK", "DEF", "SPE", "SpA", "SpD"
};

typedef struct Pokemon {
    u32    encConstant;          // 0x00
    u16    sanity;               // 0x04 - Should be 0
    u16    checksum;             // 0x06
    u16    species;              // 0x08
    u16    heldItem;             // 0x0A
    u16    tid;                  // 0x0C
    u16    sid;                  // 0x0E
    u32    exp;                  // 0x10
    u8     ability;              // 0x14
    u8     abilityNum;           // 0x15
    u8     trainingBagHits;      // 0x16
    u8     trainingBag;          // 0x17
    u32    pid;                  // 0x18
    u8     nature;               // 0x1C
    u8     miscData;             // 0x1D - Fateful encounter, gender, form flags
    u8     evs[6];               // 0x1E - HP, ATK, DEF, SPE, SPA, SPD
    u8     contest[6];           // 0x24 - Cool, Beauty, Cute, Smart, Tough, Sheen
    u8     markByte;             // 0x2A
    u8     pkrsData;             // 0x2B - Duration and strain
    u8     stData[4];            // 0x2C - Super training data
    u8     ribbons[6];           // 0x30 - Misc ribbon flags
    u8     _unknown1[4];         // 0x38
    u8     distByte;             // 0x3A
    u8     _unknown2[5];         // 0x3B
    u16    nickname[13];         // 0x40 - Unicode + null terminator
    u16    moves[4];             // 0x5A
    u8     movePP[4];            // 0x62
    u8     movePPUp[4];          // 0x66
    u16    relearnMoves[4];      // 0x6A
    u8     superSecretTrain;     // 0x72 - & 1 = unlocked, & 2 = complete
    u8     _unknown3;            // 0x73
    u32    ivData;               // 0x74 - Also stores egg and nickname flags
    u8     htData[56];           // 0x78 - HT Data block
    u8     otData[56];           // 0xB0 - OT data block
} Pokemon;

void decryptPokemon(Opponent slot, Pokemon* poke);
u8 getIV(Pokemon* poke, Stat stat);
void asciiNick(Pokemon* poke, char* buf);

int isValid(Pokemon* poke);
#endif
