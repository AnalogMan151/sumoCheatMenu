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
        // new_unselectable_entry("Version 1.0");
    } else if (READU8(0x00100040) == 0x78) {
        gameVer = 11;
        new_unselectable_entry("Version 1.1 not fully supported");
    } else {
        new_unselectable_entry("Version not supported");
    }
    switch(gameVer){
        case 10: ;
            o_battlestats1 = O_BATTLESTATS1;
            o_battlestats2 = O_BATTLESTATS2;
            o_shiny = O_SHINY;
            o_instanttext = O_INSTANTTEXT;
            o_outlines = O_OUTLINES;
            o_nfc = O_NFC;
            o_runfaster = O_RUNFASTER;
            o_walkthruwalls = O_WALKTHRUWALLS;
            o_renamepokemon = O_RENAMEPOKEMON;
            o_islandwait = O_ISLANDWAIT;
            o_pcanywhere = O_PCANYWHERE;
            o_exp1 = O_EXP1;
            o_exp2 = O_EXP2;
            o_instantegg = O_INSTANTEGG;
            o_catch1001 = O_CATCH1001;
            o_catch1002 = O_CATCH1002;
            break;
        case 11: ;
            o_battlestats1 = O_BATTLESTATS1 + 0x120;
            o_battlestats2 = O_BATTLESTATS2 + 0x1ED8;
            o_shiny = O_SHINY + 0x704;
            o_instanttext = O_INSTANTTEXT + 0x5C8;
            o_outlines = O_OUTLINES + 0x1884;
            o_nfc = O_NFC + 0x14F0;
            o_runfaster = O_RUNFASTER + 0x1420;
            o_walkthruwalls = O_WALKTHRUWALLS + 0x1420;
            o_renamepokemon = O_RENAMEPOKEMON + 0x1DA0;
            o_islandwait = O_ISLANDWAIT + 0x1C0D;
            o_pcanywhere = O_PCANYWHERE + 0x1ED8;
            o_exp1 = O_EXP1 + 0x18D8;
            o_exp2 = O_EXP2 + 0x1C60;
            o_instantegg = O_INSTANTEGG + 0x1C18;
            o_catch1001 = O_CATCH1001 + 0x18D8;
            o_catch1002 = O_CATCH1002 + 0x1C60;
            break;
    }
}
