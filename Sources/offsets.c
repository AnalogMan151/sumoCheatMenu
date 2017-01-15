#include "cheats.h"
#include "offsets.h"

int gameVer = 0;

void getVersion(void) {
    protect_region(0x00100000);
    o_gender = O_GENDER;
    o_skintone = O_SKINTONE;
    o_appearance = O_APPEARANCE;
    o_keyitems = O_KEYITEMS;
    o_nevertrip = O_NEVERTRIP,
    o_qr100 = O_QR100;

    if (READU8(0x00100040) == 0x30) {
        gameVer = 10;
    } else if (READU8(0x00100040) == 0x78) {
        gameVer = 11;
    } else {
        new_unselectable_entry("Version not supported");
    }
    switch(gameVer){
        case 10: ;
            o_pokespawn1 = O_POKESPAWN1;
            o_pokespawn2 = O_POKESPAWN2;
            o_battlestats1 = O_BATTLESTATS1;
            o_battlestats2 = O_BATTLESTATS2;
            o_shiny = O_SHINY;
            o_zmoves1 = O_ZMOVES1;
            o_zmoves2 = O_ZMOVES2;
            o_instanttext = O_INSTANTTEXT;
            o_outlines = O_OUTLINES;
            o_nfc = O_NFC;
            o_runfaster = O_RUNFASTER;
            o_walkthruwalls = O_WALKTHRUWALLS;
            o_renamepokemon = O_RENAMEPOKEMON;
            o_islandwait = O_ISLANDWAIT;
            o_pcanywhere1 = O_PCANYWHERE1;
            o_pcanywhere2 = O_PCANYWHERE2;
            o_exp1 = O_EXP1;
            o_exp2 = O_EXP2;
            o_instantegg = O_INSTANTEGG;
            o_instanthatch1 = O_INSTANTHATCH1;
            o_instanthatch2 = O_INSTANTHATCH2;
            o_catch1001 = O_CATCH1001;
            o_catch1002 = O_CATCH1002;
            o_rematch = O_REMATCH;
            break;
        case 11: ;
            o_pokespawn1 = O_POKESPAWN1 + 0x13D8;
            o_pokespawn2 = O_POKESPAWN2 + 0x1F00;
            o_battlestats1 = O_BATTLESTATS1 + 0x120;
            o_battlestats2 = O_BATTLESTATS2 + 0x1F00;
            o_shiny = O_SHINY + 0x704;
            o_zmoves1 = O_ZMOVES1 + 0x1F00;
            o_zmoves2 = O_ZMOVES2 + 0x540;
            o_instanttext = O_INSTANTTEXT + 0x122C;
            o_outlines = O_OUTLINES + 0x1884;
            o_nfc = O_NFC + 0x14F0;
            o_runfaster = O_RUNFASTER + 0x1420;
            o_walkthruwalls = O_WALKTHRUWALLS + 0x1420;
            o_renamepokemon = O_RENAMEPOKEMON + 0x1DA0;
            o_islandwait = O_ISLANDWAIT + 0x1C0D;
            o_pcanywhere1 = O_PCANYWHERE1 + 0x1F00;
            o_pcanywhere2 = O_PCANYWHERE2 + 0xFF4;
            o_exp1 = O_EXP1 + 0x1F00;
            o_exp2 = O_EXP2 + 0x1C60;
            o_instantegg = O_INSTANTEGG + 0x1C18;
            o_instanthatch1 = O_INSTANTHATCH1 + 0x1F00;
            o_instanthatch2 = O_INSTANTHATCH2 + 0x1C60;
            o_catch1001 = O_CATCH1001 + 0x1F00;
            o_catch1002 = O_CATCH1002 + 0x1C60;
            o_rematch = O_REMATCH + 0x1DA0;
            break;
    }
}
