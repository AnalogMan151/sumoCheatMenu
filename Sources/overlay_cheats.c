// Credit to dragonfyre173 for their PokeViewNTR code: https://github.com/dragonfyre173/PokeViewNTR

#include "cheats.h"
#include "hid.h"
#include "global.h"
#include "ov.h"
#include "pokeutil/pokemon.h"
#include "pokeutil/lookup.h"
#include "pokeutil/pokeball.h"
#include "pokemon_spawner.h"

Handle fsUserHandle = 0;

#define CALLBACK_OVERLAY (101)

#define TICKS_PER_MSEC (268123.480)
#define BLANK 255,255,255

Opponent selectedOpponent = PRIMARY;

// Volatile Global variables
vu8 enabled = 0;
vu8 togglebaselevel50 = 0;
vu8 plooklocation = 0;
vu8 plookarraysize = 0;
vu16 currentpkmnID = 0;
vu8 buttonAck = 0, buttonAckR = 0, buttonAckL = 0, buttonAckX = 0, buttonAckU = 0, buttonAckD = 0;
vu8 buttonAck2 = 0, buttonAckR2 = 0, buttonAckL2 = 0, buttonAckX2 = 0, buttonAckDL = 0, buttonAckDR = 0;
vu8 randini = 0, rand1 = 0, rand2 = 0, rand3 = 0, rand4 = 0, rand5 = 0, rand6 = 0, rand7 = 0, rand8 = 0, rand9 = 0;
vu8 isBottomToggle = 0;
vu8 toggleDebug = 0;
vu16 loopcounter = 0;
vu8 loopreset = 0;

vu8 sosactivate = 0;
vu8 soscounter = 0;
vu16 sosarray[2][6];

u8 RamLines = 22; // max 22
u16 pastValues[22][16][2];
u32 startupadd = 0x30009760;
u32 iniaddress = 0x30009760;


// u8 sosindex = OPPONENT_INDEX;
// ALTERNATE IS IN BATTLE /// NOT USED
// THIS WILL CHECK THE FIRST OPONENT SLOT WHEN IN BATTLE
// bool isInBattle2(){
//     u8 pkbytes[232];
//     Pokemon* pkm = (Pokemon*)pkbytes;
//     if(pkm != 0) {
//         decryptPokemon(sosindex, pkm);
//         if(isValid(pkm)) {
//             return true;
//         }
//     }
//     return false;
// }

// This will put the whole enemy array PIDs into an array to compare later
// The index used 0 for past state of enemys and 1 for current
void parseSOSData(char index){
    for (char i = 0; i < 6; i++) {
        u8 pkbytes[232];
        Pokemon* pkm = (Pokemon*)pkbytes;
        if(pkm != 0) {
            decryptPokemon(OPPONENT_INDEX + i, pkm);
            if(isValid(pkm)) {
                sosarray[index][i] = pkm->pid;
            }
        }
    }
}

// This will compare two enemy arrays, the past state and the current state
// If they change it will return true
bool compareSOSData(){
    char j = 0;
    for (char i = 0; i < 6; i++) {
        if(sosarray[0][i] != sosarray[1][i]){
            j++;
        }
    }
    if(j > 0){
        return true;
    }
    return false;
}

int xfloor(double x)
{
    return (int) x - (x < (int) x);
}

// RANDOMIZE RANDOM POKEBALLS =D
void randomizePokeballs(){
	rand1 = randomNum(0, 25); rand2 = randomNum(0, 25); rand3 = randomNum(0, 25);
	rand4 = randomNum(0, 25); rand5 = randomNum(0, 25); rand6 = randomNum(0, 25);
	rand7 = randomNum(0, 25); rand8 = randomNum(0, 25); rand9 = randomNum(0, 25);
}


// DRAW FANCY COLOR BORDER FROM CUSTOM SPRITE DATA
void drawTypeBorder(short posX, short posY, char xlen, char r, char g, char b, char r2, char g2, char b2){

    // B-LEFT
    OvDrawSymbol(0x05, posX, posY, r,g,b);
    OvDrawSymbol(0x0C, posX, posY, r2,g2,b2);
    for (char i = 1; i < xlen; i++) {
        // C-ENTER
        OvDrawSymbol(0x07, posX + (16 * i), posY, r,g,b);
        OvDrawSymbol(0x0E, posX + (16 * i), posY, r2,g2,b2);
    }
    // B-RIGHT
    OvDrawSymbol(0x06, posX + 16 * xlen, posY, r,g,b);
    OvDrawSymbol(0x0D, posX + 16 * xlen, posY, r2,g2,b2);

}

// DRAW TYPE WITH A FANCY COLOR BORDER
void drawType(char type, short posX, short posY){
    if(type < 1 || type > 18){
        return;
    }
    char buf[10];
    type = type - 1;
    drawTypeBorder(posX, posY, 3, TYPE_COLORS[type][0],TYPE_COLORS[type][1],TYPE_COLORS[type][2],
        TYPE_COLORS_DARK[type][0],TYPE_COLORS_DARK[type][1],TYPE_COLORS_DARK[type][2]);

    char len = strlen(TYPE_NAMES[type]);
    char mlen = len % 2;
    char space = ((8 - len) * 3) + (mlen == 1 ? 0 : 0);
    xsprintf(buf, "%s", TYPE_NAMES[type]);
    OvDrawString(buf, posX + 7 + space, posY + 1, BLANK);
}

// DRAW POKEMON NAME WITH A FANCY COLOR BORDER
void drawName(char* name, char color, short posX, short posY){
    if(color < 1 || color > 10){
        color = 1;
    }
    char buf[11];
    drawTypeBorder(posX, posY, 5, PKM_COLORS[color][0],PKM_COLORS[color][1],PKM_COLORS[color][2],
        PKM_COLORS[color][3],PKM_COLORS[color][4],PKM_COLORS[color][5]);

    char len = strlen(name);
    char mlen = len % 2;
    char space = ((12 - len) * 3) + (mlen == 1 ? 0 : 0);
    xsprintf(buf, "%s", name);
    if(color == 3 || color == 5 || color == 8 || color == 9){
        // DRAW BLACK FONT ON TOP OF DARK COLORS
        OvDrawString(buf, posX + 9 + space, posY + 1, 0,0,0);
    }else{
        OvDrawString(buf, posX + 9 + space, posY + 1, BLANK);
    }
}

// DRAW POKEMON MOVE WITH A FANCY COLOR BORDER
void drawMove(const char* move, char type, short posX, short posY){
    if(type < 1 || type > 18){
        return;
    }
    char buf[17];
    type = type - 1;
    drawTypeBorder(posX, posY, 6, TYPE_COLORS[type][0],TYPE_COLORS[type][1],TYPE_COLORS[type][2],
        TYPE_COLORS_DARK[type][0],TYPE_COLORS_DARK[type][1],TYPE_COLORS_DARK[type][2]);

    char len = strlen(move);
    char space = len < 16 ? ((16 - len) * 3) : 0;
    xsprintf(buf, "%-16s", move);
    OvDrawString(buf, posX + 8 + space, posY + 1, BLANK);
}


void drawPokemonID() {

    // INITIALIZE RANDOM POKEBALLS
    // FOR FUN
    if(!randini){
		randini = 1;
		randomizePokeballs();
	}

    //--- R BUTTON
    //--- R BUTTON
    //--- R BUTTON
    // THIS WILL ALLOW ONLY THE FIRST PRESS OF THE BUTTON R
    if(buttonAckDR){
		if(!is_pressed(BUTTON_R) && !is_pressed(BUTTON_X)){
			buttonAckDR = 0;
		}
	}else{
	    if (is_pressed(BUTTON_R) && !is_pressed(BUTTON_X)) {
			buttonAckDR = 1;
			plooklocation = 0;
			currentpkmnID = 0;

            randomizePokeballs();

        	selectedOpponent = (selectedOpponent + 1) % NUM_OPPONENTS;
	    }
	}

    //--- L BUTTON
    //--- L BUTTON
    //--- L BUTTON
    // THIS WILL ALLOW ONLY THE FIRST PRESS OF THE BUTTON L
	if(buttonAckDL){
		if(!is_pressed(BUTTON_L) && !is_pressed(BUTTON_X)){
			buttonAckDL = 0;
		}
	}else{
	    if (is_pressed(BUTTON_L) && !is_pressed(BUTTON_X)) {
			buttonAckDL = 1;
			plooklocation = 0;
			currentpkmnID = 0;

            randomizePokeballs();

	        	selectedOpponent = (selectedOpponent + NUM_OPPONENTS - 1) % NUM_OPPONENTS;
	    }
	}
    //--- X BUTTON COMBO
    //--- X BUTTON COMBO
    //--- X BUTTON COMBO
    if(buttonAckX){
		if(!is_pressed(BUTTON_X)){
			buttonAckX = 0;
		}else{
            if(buttonAckX2){
                if(!is_pressed(BUTTON_DD) && !is_pressed(BUTTON_DL) && !is_pressed(BUTTON_DR) && !is_pressed(BUTTON_L) && !is_pressed(BUTTON_R)){
                    buttonAckX2 = 0;
                }
            }else{

                if(toggleDebug){
                    iniaddress = 0x30009760;
                    loopreset = 1;
                }

                if(is_pressed(BUTTON_DD)){
                    buttonAckX2 = 1;
                    isBottomToggle = !isBottomToggle;
                }
                // TOGGLE ALTERNATE LEVEL CALCULATION
                if(is_pressed(BUTTON_DL)){
                    buttonAckX2 = 1;
                    togglebaselevel50 = !togglebaselevel50;
                }
                if(is_pressed(BUTTON_L)){
                    buttonAckX2 = 1;
                    toggleDebug = !toggleDebug;
                }
                if(is_pressed(BUTTON_R)){
                    buttonAckX2 = 1;
                }
                if(is_pressed(BUTTON_DR)){
                    // INCREASE POKEMON FORM
                    buttonAckX2 = 1;
                    u8 cform = POKEMON_LOOKUP[currentpkmnID - 1][0][0];
                    plookarraysize = cform == 1 ? 1 : 0;
                    plookarraysize = cform == 2 ? 2 : plookarraysize;
                    plookarraysize = cform == 3 ? 3 : plookarraysize;
                    plookarraysize = cform == 4 ? 4 : plookarraysize;
                    plookarraysize = cform == 5 ? 5 : plookarraysize;
                    plookarraysize = cform == 6 ? 6 : plookarraysize;
                    plooklocation = (plooklocation + 1) % plookarraysize;
                }
            }
        }

	}else{
	    if (is_pressed(BUTTON_X)) {
            // TOGGLE BUTTON COMBO X
			buttonAckX = 1;
			buttonAckX2 = 1;
	    }
	}

    //--- UP BUTTON
    //--- UP BUTTON
    //--- UP BUTTON
    if(buttonAckU){
		if(!is_pressed(BUTTON_DU)){
			buttonAckU = 0;
		}
	}else{
	    if (is_pressed(BUTTON_DU)) {
            buttonAckU = 1;

            // This activates when UP is pressed once

            if(toggleDebug){
                loopcounter = 0;
                loopreset = 1;
                iniaddress -= 20 * 16;
                if(iniaddress >= 0x34000000){
                    iniaddress = 0x34000000;
                }
            }

	    }
	}


    //--- DOWN BUTTON
    //--- DOWN BUTTON
    //--- DOWN BUTTON
	if(buttonAckD){
		if(!is_pressed(BUTTON_DD)){
			buttonAckD = 0;
		}
	}else{
	    if (is_pressed(BUTTON_DD)) {
    		buttonAckD = 1;

            // This activates when DOWN is pressed once


            if(toggleDebug){
                loopcounter = 0;
                loopreset = 1;
                iniaddress += 20 * 16;
                if(iniaddress <= 0x30000000){
                    iniaddress = 0x30000000;
                }
            }
	    }
	}

    //--- RIGHT BUTTON
    //--- RIGHT BUTTON
    //--- RIGHT BUTTON
    if(buttonAckR){
		if(!is_pressed(BUTTON_DR)){
			buttonAckR = 0;
		}
	}else{
	    if (is_pressed(BUTTON_DR)) {
            buttonAckR = 1;

            // This activates when UP is pressed once

            if(toggleDebug){
                loopcounter = 0;
                loopreset = 1;
                iniaddress -= 1 * 16;
                if(iniaddress >= 0x34000000){
                    iniaddress = 0x34000000;
                }
            }

	    }
	}


    //--- LEFT BUTTON
    //--- LEFT BUTTON
    //--- LEFT BUTTON
	if(buttonAckL){
		if(!is_pressed(BUTTON_DL)){
			buttonAckL = 0;
		}
	}else{
	    if (is_pressed(BUTTON_DL)) {
    		buttonAckL = 1;
            // This activates when DOWN is pressed once

            if(toggleDebug){
                loopcounter = 0;
                loopreset = 1;
                iniaddress += 1 * 16;
                if(iniaddress <= 0x30000000){
                    iniaddress = 0x30000000;
                }
            }
	    }
	}



    // SOS BATTLE COUNTER
    // SOS BATTLE COUNTER
    // SOS BATTLE COUNTER

    // ARRAY TO STORE ENEMY POKEMON
    if(sosactivate){
        if(!isInBattle()){
            sosactivate = 0;
            soscounter = 0;
            for (char i = 0; i < 6; i++) {
                sosarray[0][i] = 0;
                sosarray[1][i] = 0;
            }
        }
    }else{
        if(isInBattle()){
            // INITIALIZE ENEMY ARRAY AND RESET COUNTER
            sosactivate = 1;
            soscounter = 0;
            parseSOSData(0);
        }
    }

    // THIS ACTIVATE AS SOON AS A BATTLE STARTS
    if(sosactivate){
        parseSOSData(1);
        if(compareSOSData()){
            soscounter++;
            parseSOSData(0);
        }
    }

    u8 pkbytes[232];
    Pokemon* pkm = (Pokemon*)pkbytes;


    if(toggleDebug){

        // INCREASE COUNTER AND RESET IF REACHED MAX LIMIT
        loopcounter++;
        if(loopcounter > 0xFF00){
            loopcounter = 0;
            loopreset = 1;
        }

        char buf[150];
        int posX = 6;
        int posY = 6;
        u32 yaddress = 0x30000000;
        u8 value = 0;
        u32 xaddress = 0x30000000;

        OvDrawTranspartBlackRect(posX - 4, posY - 4, 350, (10 * (RamLines + 1)) + 6, 1);
        OvDrawTranspartBlackRect(posX - 4, posY - 4, 350, (10 * (RamLines + 1)) + 6, 1);

        xsprintf(buf, "Offset 00 01 02 03 04 05 06 07 08 09 0A 0B 0C 0D 0E 0F %x", loopcounter);
        posY = OvDrawString(buf, posX, posY, 152, 216, 216);


        if(loopreset){
            for (u8 i = 0; i < RamLines; i++) {
                yaddress = iniaddress + (i * 16);
                for (u8 j = 0; j < 16; j++){
                    xaddress = yaddress + j;
                    pastValues[i][j][0] = (u8)*((u8*)(xaddress));
                    pastValues[i][j][1] = loopcounter;
                }
            }
            loopreset = 0;
        }

        for (u8 i = 0; i < RamLines; i++) {

            yaddress = iniaddress + (i * 16);
            xsprintf(buf, "%x", yaddress - 0x30000000);
            u8 ry = 255, gy = 110, by = 255;
            if(yaddress == startupadd){
                ry = 187, gy = 31, by = 31;
            }
            OvDrawString(buf, posX, posY, ry, gy, by);

            for (u8 j = 0; j < 16; j++) {
                xaddress = yaddress + j;
                u8 r = 255, g = 255, b = 255;

                value = (u8)*((u8*)(xaddress));
                if((u16)value != (u16)pastValues[i][j][0]){
                    pastValues[i][j][1] = loopcounter + 0x0300;
                }

                if(pastValues[i][j][1] > (loopcounter + 0x70)){
                    r = 255;
                    g = 0;
                    b = 0;
                }else if(pastValues[i][j][1] > (loopcounter + 0x150)){
                    r = 255;
                    g = 0;
                    b = 0;
                }else if(pastValues[i][j][1] > loopcounter){
                    r = 255;
                    g = 0;
                    b = 255;
                }

                pastValues[i][j][0] = (u16)value;
                if(!togglebaselevel50){
                    xsprintf(buf, "%02x", (u8)value);
                }else{
                    xsprintf(buf, "%02x", (u8)pastValues[i][j][1]);
                }
                OvDrawString(buf, posX + (6*7) + (18)*j, posY, r, g, b);


            }
            posY += 11;
        }

    }else{
        // RESET COUNTER
        loopcounter = 0;
    }


    if(pkm != 0 && !toggleDebug) {
        decryptPokemon(selectedOpponent, pkm);

        char buf[100];
        char nick[13];
        int posX = 14;
        int posY = 9;
		int posXsav = 0;
		int posYsav = 0;
        u8 battleDataValid = 0;

        u16 bstats[6] = {0};

        // See if the pokemon's actually valid first
        if(isValid(pkm)) {

            u8 ScreenLines = 23;
            // Draw background twice. Better contrast.
			OvDrawTranspartBlackRect(posX - 4, posY - 4, 210, (10 * ScreenLines) + 2, 1);
			OvDrawTranspartBlackRect(posX - 4, posY - 4, 210, (10 * ScreenLines) + 2, 1);

            ///HYPER TRAINING FLAG POKEMON DATA 0XDE
			//otData starts from 0xB0
			//0xB0 + 46 = 0xDE
			unsigned char hyperFlag = (pkm->otData[46] & 0xFF);

            ///POKEBALL FLAG POKEMON DATA 0XDC
			//otData starts from 0xB0
			//0xB0 + 44 = 0xDC
			unsigned char pokeballFlag = (pkm->otData[44] & 0xFF);


            ///FATEFUL/GENDER/GENDERLESS/FORM BYTE
			//miscData contains all this information
        	u8 fate = (pkm->miscData >> 0) & 0x01; // 1 bit
        	u8 gen = (pkm->miscData >> 1) & 0x01; // 1 bit
        	u8 gless = (pkm->miscData >> 2) & 0x01; // 1 bit
        	u8 form = (pkm->miscData >> 3) & 0xFF;
	        char *gender = (gless == 0x1) ? "-" : (gen == 0x0) ? " " : " ";
	        char genderq = (gless == 0x1) ? 2 : (gen == 0x0) ? 0 : 1;

            u16 tsv = (pkm->tid ^ pkm->sid) >> 4;
            u16 esv = ((pkm->pid >> 16) ^ (pkm->pid & 0xFFFF)) >> 4;
            bool shiny = (tsv == esv) ? true : false;




            // Get Pokemon nickname into nick char array
            asciiNick(pkm, nick);

            // Get pokedex number
            currentpkmnID = pkm->species;

            const spawnPokemon *pokemon;
            pokemon = &pokemonID[currentpkmnID - 1];


            // DETECT IF FORM EXISTS BEFORE GETTING DATA
            // this is to avoid random crashes when changing pokemon who don't have a certain form
            char formsnum = POKEMON_LOOKUP[currentpkmnID - 1][0][0];

            if(plooklocation + 1 > formsnum){
                // IF IT DOESNT EXISTS CHANGE FORM TO SLOT 0
                plooklocation = 0;
            }

            // GET POKEMON GENERAL COLOR
            char xcolor = POKEMON_LOOKUP[currentpkmnID - 1][plooklocation][8] - 1;

            // DRAW FANCY BORDERED NAME
            drawName(pokemon->name, xcolor, posX + 56, posY - 2);

            // Print the pointer index / the nick of the pokemon, pokedex number / and pointer name
			// xsprintf(buf, "[%s] %-11s [%03d]", OPPONENT_NAMES[selectedOpponent], pokemon->name, currentpkmnID);
			xsprintf(buf, "[%s]", OPPONENT_NAMES[selectedOpponent]);
            OvDrawString(buf, posX, posY, BLANK);

			xsprintf(buf, "No. %03d", currentpkmnID);
            posY = OvDrawString(buf, 170, posY, BLANK);
            // posY will move to the next line's position each time a string is drawn on screen

            posX += 6; // This works as a tab and moves all lines one character to the right
            posY += 2; // Little Space from header



            // GET LEVEL
            // Level is calculated with the experience and the exprate.
            // EXP_BYLEVEL array contains all posible levels for a certain experience rate.
            u32 pkexp = pkm->exp;
            int pklevel = 0;
            int pkrate = EXP_RATE[currentpkmnID - 1];
            int baseexp = 0;
            for(u8 i = 0; i < 100; i++) {
                baseexp = EXP_BYLEVEL[i][pkrate];
                if(pkexp >= baseexp){
                    pklevel = i + 1;
                }else{
                    break;
                }
            }

            // TRY TO DECRYPT BATTLE DATA
            // AFTER GETTING THE LEVEL TO COMPARE
            u8 battlebytes[28];
            BattleData* battleStats = (BattleData*)battlebytes;
            decryptBattleData(selectedOpponent, battleStats);
            if(battleStats->level == pklevel && isInBattle()){
                battleDataValid = 1;

                // GET DECRYPTED BATTLE DATA
                u16 selectedHP = battleStats->currentHP;
                u16 selectedATT = battleStats->attack;
                u16 selectedDEF = battleStats->defense;
                u16 selectedSPA = battleStats->specialAttack;
                u16 selectedSPD = battleStats->specialDefense;
                u16 selectedSPE = battleStats->speed;

                if(selectedOpponent >= OPPONENT_INDEX && selectedOpponent < (OPPONENT_INDEX + 6)){
                    selectedHP = (u16)*((u16*)(0x3000BDA0 + (selectedOpponent - OPPONENT_INDEX) * 0x0330));
                    // selectedATT = (u16)*((u16*)((0x3000BDA0 + (selectedOpponent - OPPONENT_INDEX) * 0x0330) + 0x01CA + (0x02 * 0)));
                    // selectedDEF = (u16)*((u16*)((0x3000BDA0 + (selectedOpponent - OPPONENT_INDEX) * 0x0330) + 0x01CA + (0x02 * 1)));
                    // selectedSPA = (u16)*((u16*)((0x3000BDA0 + (selectedOpponent - OPPONENT_INDEX) * 0x0330) + 0x01CA + (0x02 * 2)));
                    // selectedSPD = (u16)*((u16*)((0x3000BDA0 + (selectedOpponent - OPPONENT_INDEX) * 0x0330) + 0x01CA + (0x02 * 3)));
                    // selectedSPE = (u16)*((u16*)((0x3000BDA0 + (selectedOpponent - OPPONENT_INDEX) * 0x0330) + 0x01CA + (0x02 * 4)));
                }
                if(selectedOpponent >= PARTY_INDEX && selectedOpponent < (PARTY_INDEX + 6)){
                    selectedHP = (u16)*((u16*)(0x30009760 + (selectedOpponent - PARTY_INDEX) * 0x0330));
                    // selectedATT = (u16)*((u16*)((0x30009760 + (selectedOpponent - PARTY_INDEX) * 0x0330) + 0x01CA + (0x02 * 0)));
                    // selectedDEF = (u16)*((u16*)((0x30009760 + (selectedOpponent - PARTY_INDEX) * 0x0330) + 0x01CA + (0x02 * 1)));
                    // selectedSPA = (u16)*((u16*)((0x30009760 + (selectedOpponent - PARTY_INDEX) * 0x0330) + 0x01CA + (0x02 * 2)));
                    // selectedSPD = (u16)*((u16*)((0x30009760 + (selectedOpponent - PARTY_INDEX) * 0x0330) + 0x01CA + (0x02 * 3)));
                    // selectedSPE = (u16)*((u16*)((0x30009760 + (selectedOpponent - PARTY_INDEX) * 0x0330) + 0x01CA + (0x02 * 4)));
                }

                bstats[0] = selectedHP;
                bstats[1] = selectedATT;
                bstats[2] = selectedDEF;
                bstats[3] = selectedSPA;
                bstats[4] = selectedSPD;
                bstats[5] = selectedSPE;
            }

            //POKEBALL
            // xpokeball identifies the index of the arrays containing the pokeball names and their sprites
			int xpokeball = 0;
			if(pokeballFlag == 0){ // if pokeball data is missing
				xpokeball = 3; // index 3 is a regular pokeball
			}else{
				xpokeball = pokeballFlag - 1;
			}

            // DRAW POKEBALL SYMBOL WHITE RED
            OvDrawSymbol(0x00, posX + 30, posY - 2, 0,0,0);
            OvDrawSymbol(0x01, posX + 30, posY - 2, 255,0,0);
            OvDrawSymbol(0x0F, posX + 30, posY - 2, 255,255,255);

            // DRAW POKEBALL SPRITE
			OvDrawPokeball(posX + 156, 20, BALLS7ARR[xpokeball]);

            // DRAW POKEBALL NAME
            xsprintf(buf, "Bll:   %s", BALLS7[xpokeball]);
            posY = OvDrawString(buf, posX, posY, BLANK);


            // DRAW NATURE AND CURRENT LEVEL
		  	if(pkm->nature < NATURE_COUNT)
		  	{
                xsprintf(buf, "Nat: %-11s Lv: %d", NATURE_LOOKUP[pkm->nature], pklevel);
				posY = OvDrawString(buf, posX, posY, BLANK);
			}



            // DRAW ABILITY
			if(pkm->ability < ABILITY_COUNT)
			{
				xsprintf(buf, "Abi: %s", ABILITY_LOOKUP[pkm->ability]);
				posY = OvDrawString(buf, posX, posY, BLANK);
			}

            // DRAW HELD ITEM
			if(pkm->heldItem < ITEM_COUNT)
			{
				xsprintf(buf, "Itm: %s", ITEM_LOOKUP[pkm->heldItem]);
				posY = OvDrawString(buf, posX, posY, BLANK);
			}


            // DRAW GENDER SPRITES
            if(genderq == 0){
                // MALE
                OvDrawSymbol(0x0A, posX + 30, posY - 2, 2,93,166);
                OvDrawSymbol(0x0B, posX + 30, posY - 2, 0,0,0);
            }
            if(genderq == 1){
                // FEMALE
                OvDrawSymbol(0x08, posX + 30, posY - 2, 234,26,62);
                OvDrawSymbol(0x09, posX + 30, posY - 2, 0,0,0);
            }

            // DRAW GENDER & CATCH RATE STRING
            xsprintf(buf, "Gen: %s  Catch Rate: %d/255", gender, CATCH_RATE[currentpkmnID - 1] );
            posY = OvDrawString(buf, posX, posY, BLANK);

            // DRAW SHINY STAR
            if(shiny){
                OvDrawSymbol(0x02, posX + 105 + 52, posY - 1, 255,0,0);
            }
            OvDrawSymbol(0x04, posX + 105 + 52, posY - 1, 0,0,0);

            // FORM AND SHINY STRING
            xsprintf(buf, "%26s", "Shiny:");
            OvDrawString(buf, posX, posY, BLANK);

            spawnForms formID[30] = {0};
            getForms(currentpkmnID, formID);
            spawnForms *forms;
            spawnForms *simform;
            forms = &formID[form];
            simform = &formID[plooklocation];

            xsprintf(buf, "Form: %s", forms->name);
            posY = OvDrawString(buf, posX, posY, BLANK);

            // LEVEL AND NAME
			if(togglebaselevel50 == 1){
				pklevel = 50;
			}


            // Move the line index a bit to match the colored border sprites
            // Not needed anymore as the Pokemon name and color are not drawed
            // posY = posY + 2;


            // // DRAW LEVEL USED FOR STAT CALCULATION
            xsprintf(buf, "Sim Lv:       Sim Form: %s", simform->name);
			OvDrawString(buf, posX,  posY, BLANK);

            // // DRAW LEVEL AND HIGHLIGHT SIMULATION BASE LVL WHEN ACTIVE
            xsprintf(buf, "%10d", pklevel);
			posY = OvDrawString(buf, posX,  posY, togglebaselevel50 ? 255 : 255, togglebaselevel50 ? 0 : 255, togglebaselevel50 ? 0 : 255);

            // DRAW POKEMON NAME ON TOP OF THE COLOR BORDER
            // xsprintf(buf, "      %s", POKEMON_LOOKUP_NAME[currentpkmnID - 1][plooklocation][0]);
            // if(xcolor == 9 || xcolor == 8 || xcolor == 5 || xcolor == 3){ // WHITE YELLOW PINK GRAY => DARK TEXT
			    // posY = OvDrawString(buf, posX,  posY, 55,55,55);
            // }else{
			    // posY = OvDrawString(buf, posX,  posY, BLANK);
            // }


            // DRAW BOTH TYPES
            drawType(POKEMON_LOOKUP[currentpkmnID - 1][plooklocation][9], posX, posY);
            drawType(POKEMON_LOOKUP[currentpkmnID - 1][plooklocation][10], posX + 65, posY);
            posY = posY + 12;

            // HEADER STATS IVS EVS TOTAL
			xsprintf(buf, "Stat   IV   EV   Total %9s", battleDataValid ? "Current" : "");
			posY = OvDrawString(buf, posX, posY, BLANK);

            // STORE INITIAL GRID X AND Y
			posYsav = posY;
			posXsav = posX;

            // IVs
            int statOrder[] = {0, 1, 2, 4, 5, 3};
			for(u8 i = 0; i < 6; i++)
			{

                // GET IV
				u8 iv = getIV(pkm, statOrder[i]);

				xsprintf(buf, "%2d", iv);
				u8 r = iv > 29 ? 0 : 255;
				u8 g = iv < 2 ? 0 : 255;
				u8 b = (iv > 29 || iv < 2) ? 0 : 255;

                // Change color and draw an H if stat has hyper training
				if((hyperFlag & (1 << i)) > 0){
					r = 255;
					g = 191;
					b = 0;
					xsprintf(buf, "%dH", iv);
				}
                // DRAW SINGLE IV STRING
				OvDrawString(buf, posX + 43, posY, r, g, b);


                // DRAW PLUS MINUS NATURE SIGN
				if(STAT_NAME[statOrder[i]] == NATURE_PLUS[pkm->nature]){
					xsprintf(buf, "+%3s:", STAT_NAME[statOrder[i]]); //PURE RED
					posY = OvDrawString(buf, posX - 6,  posY, 255, 0, 0);
				}else if(STAT_NAME[statOrder[i]] == NATURE_MINUS[pkm->nature]){
					xsprintf(buf, "-%3s:", STAT_NAME[statOrder[i]]); // ICE BLUE
					posY = OvDrawString(buf, posX - 6,  posY, 152, 216, 216);
				}else{
					xsprintf(buf, "%3s:", STAT_NAME[statOrder[i]]); // WHITE
					posY = OvDrawString(buf, posX,  posY, BLANK);
				}
			}


            // RESTORE Y POS
			posY = posYsav;
			posX += 72;

            // EVs
			for(u8 j = 0; j < 6; j++)
			{
                // CHANGE ORDER OF STATS TO MATCH HP/ATK/DEF/SpA/SpD/SPE
                u8 i = statOrder[j];

                // GET EV
				u8 ev = pkm->evs[i];

                // CHANGE COLOR IF STAT IS TRAINED
                u8 r = 255; u8 g = 255; u8 b = 255;
                if(ev > 50){
                    r = 255; g = 0; b = 0;
                }
                if(ev > 200){
                    r = 0; g = 255; b = 0;
                }

                // DRAW SINGLE EV STRING
                xsprintf(buf, "%d", ev);
				posY = OvDrawString(buf, posX ,  posY, r, g, b);
			}


            // RESTORE Y POS
            posY = posYsav;
			posX += 32;

			// Stats
			for(u8 j = 0; j < 6; j++) {

                // GET BASE STAT VALUE
                int curstat = POKEMON_LOOKUP[currentpkmnID - 1][plooklocation][2 + j];

                // CHANGE ORDER OF STATS TO MATCH HP/ATK/DEF/SpA/SpD/SPE
				u8 i = statOrder[j];

                // CHANGE COLORS IF NATURE IS PLUS OR MINUS
                u8 r = (u8)255; u8 g = (u8)255; u8 b = (u8)255;
                float natmult = 1.0;
                if(STAT_NAME[i] == NATURE_PLUS[pkm->nature]){
                    r = 255; g = 0; b = 0;
                    natmult = 1.1;
                }
                if(STAT_NAME[i] == NATURE_MINUS[pkm->nature]){
                    r = 152; g = 216; b = 216;
                    natmult = 0.9;
                }

                // GET IV
                u8 iv = getIV(pkm, i);

                // IF HYPERTRAINED USE 31 IN CALCULATION
                if((hyperFlag & (1 << j)) > 0){
					iv = 31;
				}

                // GET EV
				u8 ev = pkm->evs[i];

                if(j == 0){
                    // HP CALCULATION
                    curstat = xfloor((2 * curstat + iv + ev / 4) * pklevel / 100 + pklevel + 10);
                }else{
                    // OTHER STAT CALCULATION
                    curstat = xfloor(xfloor((2 * curstat + iv + ev / 4) * pklevel / 100 + 5) * natmult);
                }

                if(battleDataValid) {
                    // DRAW SINGLE FINAL CURRENT STAT
    				xsprintf(buf, "%7d", bstats[j]);
    				OvDrawString(buf, posX + 24, posY, r, g, b);
                }

                // DRAW SINGLE FINAL STAT
				xsprintf(buf, "%d", curstat);
				posY = OvDrawString(buf, posX, posY, r, g, b);
			}



            // RESTORE X POS
            posX = posXsav;
            posY += 1;

			// MOVES
			for(u8 i = 0; i < 4; i++) {

                // CREATE VARIABLES TO STORE MOVE VALUES
                char movePP_s[5];
                char maxPP_s[5];
                char move_damage_s[5];
                char move_acc_s[5];

                // GET MOVE ID
				u16 move = pkm->moves[i];

                // GET MOVE PP
				u8 movePP = pkm->movePP[i];

                // GET MOVE TYPE
                u8 moveType = MOVE_DATA[move][0];

                // STORE MOVE DATA INSIDE THE STRING VARIABLES
                //
                itoa(movePP,movePP_s,10);
                itoa(MOVE_DATA[move][2],maxPP_s,10);
                itoa(MOVE_DATA[move][3],move_damage_s,10);
                itoa(MOVE_DATA[move][4],move_acc_s,10);

                // CREATE MOVE STRING
				// xsprintf(buf, "%-16s %2s|%2s[%3s][%3s]",
                //     "",
                //     movePP <= 0 ? "--" : movePP_s,
                //     MOVE_PP[move] <= 0 ? "--" : MOVE_PP[move] == 255 ? "--" : maxPP_s,
                //     MOVE_DAMAGE[move] <= 0 ? "---" : move_damage_s,
                //     MOVE_ACC[move] <= 0 ? "---" : MOVE_ACC[move] > 900 ? "---" : move_acc_s);

				xsprintf(buf, "%-17s %2s|%2s[%3s][%3s]",
                    "",
                    movePP < 0 ? "--" : movePP_s,
                    (u8)MOVE_DATA[move][2] < 0 ? "--" : (u8)MOVE_DATA[move][2] >= 255 ? "--" : maxPP_s,
                    (u8)MOVE_DATA[move][3] < 0 ? "---" : (u8)MOVE_DATA[move][3] >= 255 ? "---" : move_damage_s,
                    (u8)MOVE_DATA[move][4] < 0 ? "---" : (u8)MOVE_DATA[move][4] >= 255 ? "---" : move_acc_s);

                if(move == 0){
				    xsprintf(buf, "");
                }else{
                    drawMove(MOVE_LOOKUP[move], moveType, posX - 3, posY -2);
                }

                // // GET MOVE COLOR
				u8 r = (u8)TYPE_COLORS[moveType - 1][0];
				u8 g = (u8)TYPE_COLORS[moveType - 1][1];
				u8 b = (u8)TYPE_COLORS[moveType - 1][2];
                // DRAW MOVE STRING
				posY = OvDrawString(buf, posX, posY, r, g, b);
                posY += 1;
			}


			// DRAW HIDDEN POWER
            char hpow = getHiddenPower(pkm);
			xsprintf(buf, "Hidden Power: ");

            // DRAW FANCY HIDDEN POWER
            drawType(hpow + 2, posX + 86, posY - 1);
			posY = OvDrawString(buf, posX, posY, BLANK);



            // TSV AND ESV
            // Trainer Shiny value and Egg's shiny value
			xsprintf(buf, "TSV: %d  ESV: %d", tsv, esv);
			OvDrawString(buf, posX, posY, BLANK);


        } else {
            // ----------------------------
            // NO DATA SCREEN INIT
            // ----------------------------

            int NoDataScreenLines = 11;

            // DRAW DOUBLE BACKGROUND
            OvDrawTranspartBlackRect(posX - 4, posY - 4, 210, (10 * NoDataScreenLines) + 6, 1);
			OvDrawTranspartBlackRect(posX - 4, posY - 4, 210, (10 * NoDataScreenLines) + 6, 1);


            // DRAW POKEBALL SYMBOL WHITE RED
            OvDrawSymbol(0x00, posX + 142, posY - 2, 0,0,0);
            OvDrawSymbol(0x01, posX + 142, posY - 2, 255,0,0);
            OvDrawSymbol(0x0F, posX + 142, posY - 2, 255,255,255);
            // STAR
            OvDrawSymbol(0x02, posX + 142 + 11, posY - 2, 255,255,0);
            OvDrawSymbol(0x03, posX + 142 + 11, posY - 2, 0,0,0);
            // Female
            OvDrawSymbol(0x08, posX + 142 + 10 + 12*1, posY - 2, 248,88,136);
            OvDrawSymbol(0x09, posX + 142 + 10 + 12*1, posY - 2, 0,0,0);
            // Male
            OvDrawSymbol(0x0A, posX + 142 + 10 + 12*2, posY - 2, 104,144,240);
            OvDrawSymbol(0x0B, posX + 142 + 10 + 12*2, posY - 2, 0,0,0);


			xsprintf(buf, "[%s] No Data", OPPONENT_NAMES[selectedOpponent]);

			posY = OvDrawString(buf, posX, posY, BLANK);
            posY += 2;

            int offsetl = 6;
			xsprintf(buf, "[L][R] To switch pokemon slots");
			posY = OvDrawString(buf, posX + offsetl, posY, BLANK);

			xsprintf(buf, "[X+Right] To see other forms");
			posY = OvDrawString(buf, posX + offsetl, posY, BLANK);

			xsprintf(buf, "[X+Left] Toggle between lvl 50");
			posY = OvDrawString(buf, posX + offsetl, posY, BLANK);

			xsprintf(buf, "         and current lvl stats");
			posY = OvDrawString(buf, posX + offsetl, posY, BLANK);

			xsprintf(buf, "[X+Down] Toggle Bottom Screen");
			posY = OvDrawString(buf, posX + offsetl, posY, BLANK);

			xsprintf(buf, "%s  %s", getWifiStatus() ? "Wifi [On]" : "Wifi [Off]", isInBattle() ? "In Battle" : "Not In Battle");
			posY = OvDrawString(buf, posX + 6, posY, BLANK);
			xsprintf(buf, "SOS Counter %s [%d]", sosactivate ? "On" : "Off", soscounter - 1 < 0 ? 0 : soscounter - 1);
			posY = OvDrawString(buf, posX + 6, posY, BLANK);

            // SHOW DATA FOR SOS POKEMON
            // for (char i = 0; i < 4; i++) {
    		// 	xsprintf(buf, "%x / %x", sosarray[0][i], sosarray[1][i]);
    		// 	posY = OvDrawString(buf, posX + 6, posY, BLANK);
            // }

			OvDrawPokeball(posX + (22 * 0), posY + 3, BALLS7ARR[rand1]);
			OvDrawPokeball(posX + (22 * 1), posY + 3, BALLS7ARR[rand2]);
			OvDrawPokeball(posX + (22 * 2), posY + 3, BALLS7ARR[rand3]);
			OvDrawPokeball(posX + (22 * 3), posY + 3, BALLS7ARR[rand4]);
			OvDrawPokeball(posX + (22 * 4), posY + 3, BALLS7ARR[rand5]);
			OvDrawPokeball(posX + (22 * 5), posY + 3, BALLS7ARR[rand6]);
			OvDrawPokeball(posX + (22 * 6), posY + 3, BALLS7ARR[rand7]);
			OvDrawPokeball(posX + (22 * 7), posY + 3, BALLS7ARR[rand8]);
			OvDrawPokeball(posX + (22 * 8), posY + 3, BALLS7ARR[rand9]);
        }
    }
}


u32 overlayCallback(u32 isBottom, u32 addr, u32 addrB, u32 stride, u32 format) {
    // Set draw settings
    OvSettings(addr, addrB, stride, format, !isBottomToggle);


    if(buttonAck){
		if(!is_pressed(BUTTON_ST)){
			buttonAck = 0;
		}
	}else{
	    // if(is_pressed(BUTTON_ST) && battleInfo) {
	    if(is_pressed(BUTTON_ST)) {
			buttonAck = 1;
			enabled = !enabled;
	    }
	}
	if(enabled && isBottom == isBottomToggle){
        drawPokemonID();
        return 0;
	}

    return 1;
}

void overlayInit(void) {
    initSharedFunc();
    plgRegisterCallback(CALLBACK_OVERLAY, (void*) overlayCallback, 0);
}
