#include "pokemon.h"
#include <string.h>
#include <stdlib.h>
u8 blockPosition[4][24] = {
    {0, 0, 0, 0, 0, 0, 1, 1, 2, 3, 2, 3, 1, 1, 2, 3, 2, 3, 1, 1, 2, 3, 2, 3},
    {1, 1, 2, 3, 2, 3, 0, 0, 0, 0, 0, 0, 2, 3, 1, 1, 3, 2, 2, 3, 1, 1, 3, 2},
    {2, 3, 1, 1, 3, 2, 2, 3, 1, 1, 3, 2, 0, 0, 0, 0, 0, 0, 3, 2, 3, 2, 1, 1},
    {3, 2, 3, 2, 1, 1, 3, 2, 3, 2, 1, 1, 3, 2, 3, 2, 1, 1, 0, 0, 0, 0, 0, 0}
};

u32 lcrng(u32 seed) {
    return (seed * 0x41C64E6D + 0x00006073);
}


void unshuffle(u8* shuffled, u8* pkm, u32 sv) {
  memcpy(pkm, shuffled, 232);
  for(short block = 0; block < 4; block++){
    for(short b = 0; b < 56; b++) {
      *(pkm + b + 8 + 56 * block) = *(shuffled + b + 8 + 56 * blockPosition[block][sv]);
    }
  }
}

// void decryptPokemon(Opponent slot, Pokemon* poke) {
void decryptPokemon(u8* PokemonPointer, Pokemon* poke) {
    if(poke == 0 || PokemonPointer == 0) return;

    // ENCRYPTED DATA POINTER TO FIRST BYTE
    const u8* ekm = PokemonPointer;

    // NEW ARRAY TO STORE THE SHUFFLED DATA
    u8 shuffled[232];

    // ENCRYPTION KEY FROM FIRST 4 BYTES OF EK7
    u32 pkval = *(u32*)ekm;

    // SHUFFLE VALUE USED TO UNSHUFFLE THE DATA
    u32 shval = (((pkval >> 0xD) & 0x1F) % 24);

    // GET INITIAL SEED FROM FIRST 4 BYTES, SAME AS ENC KEY
    u32 seed = *(u32*)ekm;

    // COPY DATA TO NEW ARRAY
    memcpy(shuffled, ekm, 232);

    u16 a;
    u16 b;
    for(int i = 4; i < 116; i ++) {

        // CALCULATE NEXT SEED
        seed = lcrng(seed);

        // USE SEED TO GET REAL VALUE
        a = (seed >> 16);
        b = *((u16*)ekm + i) ^ a;

        // MOVE REAL VALUE B TO SHUFFLED ARRAY
        *(((u16*)shuffled) + i) = b;
    }
    // UNSHUFFLE DATA
    unshuffle(shuffled, (u8*)poke, shval);
}

void decryptBattleData(u8* BattlePointer, BattleData* bdata) {
    if(bdata == 0) return;

    // ENCRYPTED DATA POINTER TO FIRST OPONENT BYTE
    const u8* ekm = BattlePointer;

    // ENCRYPTED DATA POINTER TO FIRST BATTLE DATA BYTE
    const u8* ekm2 = BattlePointer + 0x0158;

    // NEW ARRAY TO STORE THE DATA
    u8 decrypted[28];

    // ENCRYPTION KEY FROM FIRST 4 BYTES OF EK7
    u32 pkval = *(u32*)ekm;

    // GET INITIAL SEED FROM FIRST 4 BYTES, SAME AS ENC KEY
    u32 seed = *(u32*)ekm;

    u16 a;
    u16 b;
    for(int i = 0; i < 14; i ++) {

        // CALCULATE NEXT SEED
        seed = lcrng(seed);

        // USE SEED TO GET REAL VALUE FROM THE EKM2
        a = (seed >> 16);
        b = *((u16*)ekm2 + i) ^ a;

        // MOVE REAL VALUE B TO DECRYPTED ARRAY
        *(((u16*)decrypted) + i) = b;
    }
    memcpy(bdata, decrypted, 28);
}

u8 getIV(Pokemon* poke, Stat stat) {
    return (poke->ivData >> (5 * stat)) & 0x1F;
}

void asciiNick(Pokemon* poke, char* buf) {
    for(char i = 0; i < 13; i++) {
        u16 a = *(poke->nickname + i);
        char b;
             if(a == 0x0000) b = '\0';
        else if(a == 0x2019) b = '\'';
        else if(a == 0xE08E || a == 0xE08F || a > 0xFF) b = ' ';
        else b = a & 0xFF;

        *(buf + i) = b;
        if(b == '\0') return;
    }
    *(buf + 13) = '\0';
}

int isValid(Pokemon* poke) {
    // 1. Ensure sanity check
    if(!poke || poke->sanity)
        return 0;

    // 2. Calculate checksum
    u16 chksum = 0;
    for(u8 i = 4; i < 116; i++) {
        chksum += *((u16*)(poke) + i);
    }

    if(chksum != poke->checksum)
        return 0;

    // 3. Ensure species is in a valid range.
    return (poke->species >= 1 && poke->species <= 802);
}

char getHiddenPower(Pokemon* poke) {
	char type = 0;
	for(Stat i = HP; i <= SPD; i++) {
		type |= ((getIV(poke, i) % 2) << i);
	}
	type = (type * 15) / 63;
	return type;
}
