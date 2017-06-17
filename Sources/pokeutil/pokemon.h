#ifndef POKEMON_H
#define POKEMON_H
#include "3dstypes.h"

// https://github.com/drgoku282/PKMN-NTR

#define NUM_OPPONENTS 21
// #define NUM_OPPONENTSWIFI 6 // We don't need this anymore
#define PARTY_INDEX 13
#define OPPONENT_INDEX 1

typedef enum Stat {
    HP=0, ATK, DEF, SPE, SPA, SPD
} Stat;

typedef enum Opponent {
    PRIMARY=0,
	// SECONDARY,
    OPP1, OPP2, OPP3, OPP4, OPP5, OPP6,
    BPARTY1, BPARTY2, BPARTY3, BPARTY4, BPARTY5, BPARTY6,
    PARTY1, PARTY2, PARTY3, PARTY4, PARTY5, PARTY6,
    BOXP,
	// SOS0, SOS1, SOS2, SOS3, SOS4,
	TRADE,
	// GTSTRADE,
    // DAYCARE1,DAYCARE2,
    // NURSERYEGG,
	// BOX11, BOX12, BOX13, BOX14, BOX15, BOX16,


} Opponent;



static const u8* SOSPointers[12] = {
    // OPPONENT SOS*
    (u8*)(0x3002F7B8),
    (u8*)(0x3002F7B8 + 0x01E4 * 1), // 0x3002E254
    (u8*)(0x3002F7B8 + 0x01E4 * 2),
    (u8*)(0x3002F7B8 + 0x01E4 * 3),
    (u8*)(0x3002F7B8 + 0x01E4 * 4),
    (u8*)(0x3002F7B8 + 0x01E4 * 5),

    // PARTY SOS*
    (u8*)(0x3002E070),
    (u8*)(0x3002E070 + 0x01E4 * 1), // 0x3002E254
    (u8*)(0x3002E070 + 0x01E4 * 2),
    (u8*)(0x3002E070 + 0x01E4 * 3),
    (u8*)(0x3002E070 + 0x01E4 * 4),
    (u8*)(0x3002E070 + 0x01E4 * 5),
};


static const u8* OPPONENT_POINTERS[NUM_OPPONENTS] = {

    // PRIMARY, SECONDARY
	(u8*)(0),
    // (u8*)0x32550284,

    // OPPONENT PARTY IN BATTLE IS ONLY UPDATED INSIDE A BATTLE
    // THESE POINTERS DON'T UPDATE INSIDE THE BATTLE PROPERLY AND ARE MISSING BATTLE DATA
    (u8*)(0x3254F4AC),
    (u8*)(0x3254F4AC + 0x0104 * 1),
    (u8*)(0x3254F4AC + 0x0104 * 2),
    (u8*)(0x3254F4AC + 0x0104 * 3),
    (u8*)(0x3254F4AC + 0x0104 * 4),
    (u8*)(0x3254F4AC + 0x0104 * 5),

    // PARTY ON BATTLE INITIAL DATA*
    (u8*)(0x3254EE60),
    (u8*)(0x3254EE60 + 0x0104 * 1), // 0x3002E254
    (u8*)(0x3254EE60 + 0x0104 * 2),
    (u8*)(0x3254EE60 + 0x0104 * 3),
    (u8*)(0x3254EE60 + 0x0104 * 4),
    (u8*)(0x3254EE60 + 0x0104 * 5),

    // PLAYER PARTY
    (u8*)(0x34195E10),
    (u8*)(0x34195E10 + 0x01E4 * 1), // 0x3002E254
    (u8*)(0x34195E10 + 0x01E4 * 2),
    (u8*)(0x34195E10 + 0x01E4 * 3),
    (u8*)(0x34195E10 + 0x01E4 * 4),
    (u8*)(0x34195E10 + 0x01E4 * 5),

    // POKEMON BOX POINTER
    (u8*)(0x30000298),

    // SOS 0 1 2 3 4
    // DISABLED
    // (u8*)0x3003969C, (u8*)0x3002FD64, (u8*)0x3002FF48, (u8*)0x3003012C, (u8*)0x30030310,
	// POKEMON shown when Trading
	(u8*)(0x32A870C8),
    // POKEMON TRADE DEPOSITED GTS
    // (u8*)(0x330D8C88),
	//DayCare1
	// (u8*)(0x3313EC01),
	//DayCare2
	// (u8*)(0x3313ECEA),
    // Nursery Egg
    // (u8*)(unknown),

    // PARTY BOX POINTERS ONLY SHOWS AND CHANGES IF VIEWING BOX
    // 0x30413E40 + 0x01E4 * 0   /// SHOWS SLOT 3
    // 0x30413E40 + 0x01E4 * 1   /// SHOWS SLOT 2
    // 0x30413E40 + 0x01E4 * 2   /// SHOWS SLOT 1
    // 0x30413E40 + 0x01E4 * 3   /// SHOWS SLOT 4
    // 0x30413E40 + 0x01E4 * 4   /// SHOWS SLOT 5
    // 0x30413E40 + 0x01E4 * 5   /// SHOWS SLOT 6

    // PARTY BOX POINTERS 2 UPDATES ONLY AFTER MOVING (FROM AND OUT) PARTY POKEMON TO BOX [RIGHT ORDER]
    // 0x307A632C + 0x01E4 * 0
    // 0x307A632C + 0x01E4 * 1
    // 0x307A632C + 0x01E4 * 2
    // 0x307A632C + 0x01E4 * 3
    // 0x307A632C + 0x01E4 * 4
    // 0x307A632C + 0x01E4 * 5

    // PARTY BOX POINTERS 3 UPDATES AFTER GAME SAVE [RIGHT ORDER]
    // 0x330D689C + 0x01E4 * 0
    // 0x330D689C + 0x01E4 * 1
    // 0x330D689C + 0x01E4 * 2
    // 0x330D689C + 0x01E4 * 3
    // 0x330D689C + 0x01E4 * 4
    // 0x330D689C + 0x01E4 * 5

	// Box1 P1-P6
	// (u8*)(0x330D9838),
	// (u8*)(0x330D9838 + 0X00E8 * 1),
	// (u8*)(0x330D9838 + 0X00E8 * 2),
	// (u8*)(0x330D9838 + 0X00E8 * 3),
	// (u8*)(0x330D9838 + 0X00E8 * 4),
	// (u8*)(0x330D9838 + 0X00E8 * 5),

    // PARTY OUTSIDE OF BATTLE 1 UPDATES ONLY AFTER THE START OF A BATTLE
    // 0x32000000 + 0x54EE60
    // 0x3254EE60 + 0x104 * 0

    // PARTY OUTSIDE OF BATTLE 2 UPDATES ONLY AFTER THE START OF A BATTLE
    // 0x32000000 + 0xA6A860
    // 0x32A6A860 + 0x01E4 * 0

    // PARTY OUTSIDE OF BATTLE 3 UPDATES AFTER CHANGING AND EXITING THE BOX [WEIRD ORDER]
    // 0x34000000 + 0x195E10
    // 0x34195E10 + 0x01E4 * 0

    // TO GET BATTLE DATA ADD + 0x0158


};


static const char *OPPONENT_NAMES[NUM_OPPONENTS] = {
	"Info", // "2nd Opp",
    "Opp 1", "Opp 2", "Opp 3", "Opp 4", "Opp 5", "Opp 6",
    "Team 1", "Team 2", "Team 3", "Team 4", "Team 5", "Team 6",
    "Party 1", "Party 2", "Party 3", "Party 4", "Party 5", "Party 6",
    "Box",
    // "SOS0", "SOS1", "SOS2", "SOS3", "SOS4",
	"Trade",
	// "GTS Trade",
    // "Parent 1","Parent 2",
    // "Nursery",
	// "Box 1-1", "Box 1-2", "Box 1-3", "Box 1-4", "Box 1-5", "Box 1-6",
};

static const char *STAT_NAME[] = {
    "HP", "ATK", "DEF", "SPE", "SpA", "SpD"
};

static const char* TYPE_NAME[] = {
	"Fighting", "Flying", "Poison", "Ground", "Rock", "Bug", "Ghost", "Steel", "Fire", "Water", "Grass", "Electric", "Psychic", "Ice", "Dragon", "Dark"
};

static const u32 TYPE_COLOR[] = {
	0xC03028,0xA890F0,0xA040A0,0xE0C068,0xB8A038,0xA8B820,0x705898,0xB8B8D0,0xF08030,0x6890F0,0x78C850,0xF8D030,0xF85888,0x98D8D8,0x7038F8,0x705848
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
    u8     markByte1;            // 0x16 - Symbol Marks 1st and 2nd byte => 0xBA
    u8     markByte2;            // 0x17 - Symbol Marks 3rd byte, 4th byte Should be 0 => 0x0C
    u32    pid;                  // 0x18
    u8     nature;               // 0x1C
    u8     miscData;             // 0x1D - Fateful encounter, gender, form flags
    u8     evs[6];               // 0x1E - HP, ATK, DEF, SPE, SPA, SPD
    u8     contest[6];           // 0x24 - Cool, Beauty, Cute, Smart, Tough, Sheen
    u8     pokePelago;           // 0x2A - Poke Pelago Event Status Flag
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

typedef struct BattleData {
    u8    statusFlags;          // 0x00 0XE8
    u8    unknownFlags;         // 0x01 0XE9
    u16   unknown1;             // 0x02 - 0x03 0XEA - 0xEB
    u8    level;                // 0x04 0XEC
    u8    unknown2;             // 0x05 0XED
    u16   unknown3;             // 0x06 - 0x07 0XEE - 0xEF
    u16   currentHP;            // 0x08 - 0x09 0XF0 - 0xF1
    u16   maxHP;                // 0x0A - 0x0B 0XF2 - 0xF3
    u16   attack;               // 0x0C - 0x0D 0XF4 - 0xF5
    u16   defense;              // 0x0E - 0x0F 0XF6 - 0xF7
    u16   speed;                // 0x10 - 0x11 0XF8 - 0xF9
    u16   specialAttack;        // 0x12 - 0x13 0XFA - 0xFB
    u16   specialDefense;       // 0x14 - 0x15 0XFC - 0xFD
    u16   unknown4;             // 0x16 - 0x17 0XFE - 0xFF
    u32   unknown5;             // 0x18 - 0x21 0X100 - 0x103
} BattleData;

void decryptPokemon(u8* PokemonPointer, Pokemon* poke);
void decryptBattleData(u8* BattlePointer, BattleData* bdata);
u8 getIV(Pokemon* poke, Stat stat);
void asciiNick(Pokemon* poke, char* buf);
char getHiddenPower(Pokemon* poke);

int isValid(Pokemon* poke);
#endif
