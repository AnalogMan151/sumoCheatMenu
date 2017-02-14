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

void decryptPokemon(Opponent slot, Pokemon* poke) {
    if(poke == 0) return;
    const u8* ekm = OPPONENT_POINTERS[slot];
    u8 shuffled[232];

    u32 pkval = *(u32*)ekm;
    u32 shval = (((pkval >> 0xD) & 0x1F) % 24);
    u32 seed = *(u32*)ekm;

    memcpy(shuffled, ekm, 232);

    u16 a;
    u16 b;
    for(int i = 4; i < 116; i ++) {
        seed = lcrng(seed);
        a = (seed >> 16);
        b = *((u16*)ekm + i) ^ a;
        *(((u16*)shuffled) + i) = b;
    }
    unshuffle(shuffled, (u8*)poke, shval);
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
