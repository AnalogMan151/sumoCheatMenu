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
vu8 toggleRelearn = 0;
vu16 loopcounter = 0;
vu8 loopreset = 0;
vu32 lastPID = 0;

vu8 sosenemydiff = 0;
vu8 sosactivate = 0;
vu8 soscounter = 0;
vu16 sosarray[3][12];

u8 RamLines = 22; // max 22
u16 pastValues[22][16][2];
u32 startupadd = 0x30009760;
u32 iniaddress = 0x30009760;

// ((.*\/\/.*\r\n)?)(\s\s\s\s\})(,?)
// ALTERNATE IS IN BATTLE
// THIS WILL CHECK THE FIRST OPONENT SLOT WHEN IN BATTLE
bool isInBattle2(){
    u8 pkbytes[232];
    Pokemon* pkm = (Pokemon*)pkbytes;
    if(pkm != 0) {
        decryptPokemon((u8*)SOSPointers[0], pkm);
        if(isValid(pkm)) {
            return true && isInBattle();
        }
    }
    return false;
}

// This will put the whole enemy array PIDs into an array to compare later
// The index used 0 for past state of enemys and 1 for current
void parseSOSData(char index, char initial){
    for (char i = 0; i < 12; i++) {
        u8 pkbytes[232];
        Pokemon* pkm = (Pokemon*)pkbytes;
        u8* sosP = initial ? (u8*)(OPPONENT_POINTERS[OPPONENT_INDEX + i]) : (u8*)(SOSPointers[i]);
        if(pkm != 0) {
            decryptPokemon(sosP, pkm);
            if(isValid(pkm)) {
                sosarray[index][i] = pkm->pid;
            }
        }
    }
}

// This will compare two enemy arrays, the past state and the current state
// If they change it will return true
bool compareSOSData(char index1, char index2){
    char j = 0;
    for (char i = 0; i < 6; i++) {
        if(sosarray[index1][i] != sosarray[index2][i]){
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
void drawTypeBorder(char limit, short posX, short posY, char xlen, char r, char g, char b, char r2, char g2, char b2){
    // LIMIT CONTROLS WHICH PART TO DRAW
    if((limit >> 3) & 0x1){
        // B-LEFT ALT
        OvDrawSymbol(0x10, posX, posY, r,g,b);
        OvDrawSymbol(0x11, posX, posY, r2,g2,b2);
    }
    if((limit >> 2) & 0x1){
        // B-LEFT
        OvDrawSymbol(0x05, posX, posY, r,g,b);
        OvDrawSymbol(0x0C, posX, posY, r2,g2,b2);
    }
    if((limit >> 1) & 0x1){
        for (char i = 1; i < xlen; i++) {
            // C-ENTER
            OvDrawSymbol(0x07, posX + (16 * i), posY, r,g,b);
            OvDrawSymbol(0x0E, posX + (16 * i), posY, r2,g2,b2);
        }
    }
    if((limit >> 0) & 0x1){
        // B-RIGHT
        OvDrawSymbol(0x06, posX + 16 * xlen, posY, r,g,b);
        OvDrawSymbol(0x0D, posX + 16 * xlen, posY, r2,g2,b2);
    }

}

// DRAW TYPE WITH A FANCY COLOR BORDER
void drawType(char type, short posX, short posY){
    if(type < 1 || type > 18){
        return;
    }
    char buf[10];
    type = type - 1;
    drawTypeBorder(0b0111, posX, posY, 3, TYPE_COLORS[type][0],TYPE_COLORS[type][1],TYPE_COLORS[type][2],
        TYPE_COLORS_DARK[type][0],TYPE_COLORS_DARK[type][1],TYPE_COLORS_DARK[type][2]);

    char len = strlen(TYPE_NAMES[type]);
    char space = ((8 - len) * 3);
    xsprintf(buf, "%s", TYPE_NAMES[type]);
    OvDrawString(buf, posX + 5 + space, posY + 1, BLANK);
}

// DRAW POKEMON NAME WITH A FANCY COLOR BORDER
void drawName(char* name, char color, short posX, short posY){
    if(color < 0 || color > 10){
        color = 0;
    }
    char buf[11];
    drawTypeBorder(0b0111, posX, posY, 5, PKM_COLORS[color][0],PKM_COLORS[color][1],PKM_COLORS[color][2],
        PKM_COLORS[color][3],PKM_COLORS[color][4],PKM_COLORS[color][5]);

    char len = strlen(name);
    char space = ((12 - len) * 3);
    xsprintf(buf, "%s", name);
    if(color == 3 || color == 5 || color == 8 || color == 9){
        // DRAW BLACK FONT ON TOP OF DARK COLORS
        OvDrawString(buf, posX + 8 + space, posY + 1, 0,0,0);
    }else{
        OvDrawString(buf, posX + 8 + space, posY + 1, BLANK);
    }
}

// DRAW POKEMON MOVE WITH A FANCY COLOR BORDER
void drawMove(const char* move, char type, char style, short posX, short posY){
    if(type < 1 || type > 18){
        return;
    }
    char buf[17];
    type = type - 1;

    // FIND COLOR OF THE BACKGROUND OF THE TYPE OF MOVE, 1 PHYSICAL 2 SPECIAL 3 STATUS
    // RED PHYSICAL 252,83,2        DARK 176,58,2
    // ORANGE PHYSICAL 254,238,2
    // BLUE SPECIAL 40,120,235      DARK 17,84,182
    // GRAY SPECIAL 220,255,255
    // GRAY STATUS 169,159,147      DARK 133,121,106
    u8 lr = (style == 1) ? 252 : (style == 2) ? 40  : (style == 3) ? 169 : 255;
    u8 lg = (style == 1) ? 83  : (style == 2) ? 120 : (style == 3) ? 159 : 255;
    u8 lb = (style == 1) ? 2   : (style == 2) ? 235 : (style == 3) ? 147 : 255;

    u8 br = (style == 1) ? 176 : (style == 2) ? 17  : (style == 3) ? 133 : 255;
    u8 bg = (style == 1) ? 58  : (style == 2) ? 84  : (style == 3) ? 121 : 255;
    u8 bb = (style == 1) ? 2   : (style == 2) ? 182 : (style == 3) ? 106 : 255;

    u8 ir = (style == 1) ? 254 : (style == 2) ? 220 : (style == 3) ? 255 : 255;
    u8 ig = (style == 1) ? 238 : (style == 2) ? 255 : (style == 3) ? 255 : 255;
    u8 ib = (style == 1) ? 2   : (style == 2) ? 255 : (style == 3) ? 255 : 255;

    drawTypeBorder(0b0111, posX + 2, posY, 6, TYPE_COLORS[type][0],TYPE_COLORS[type][1],TYPE_COLORS[type][2],
        TYPE_COLORS_DARK[type][0],TYPE_COLORS_DARK[type][1],TYPE_COLORS_DARK[type][2]);

    // THIS DRAWS THE BACKGROUND COLOR OF THE TYPE OF THE MOVE, 1 PHYSICAL 2 SPECIAL 3 STATUS
    drawTypeBorder(0b1000, posX - 6, posY, 6, lr,lg,lb, br,bg,bb);

    // THIS DRAWS THE COLOR ICON OF THE TYPE OF THE MOVE, 1 PHYSICAL 2 SPECIAL 3 STATUS
    u8 icon = (style == 1) ? 0x84 : (style == 2) ? 0x80  : (style == 3) ? 0x85 : 0x80;
    OvDrawChar(icon, posX - 3, posY + 2, ir, ig, ib);

    char len = strlen(move);
    char space = len < 16 ? ((16 - len) * 3) : 0;
    xsprintf(buf, "%-16s", move);
    OvDrawString(buf, posX + 6 + space, posY + 1, BLANK);
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
            if(toggleDebug){
                loopcounter = 0;
                loopreset = 1;
                iniaddress += 20 * 16 * 10; // INCREASE 10 PAGES
                if(iniaddress >= 0x34000000){
                    iniaddress = 0x34000000;
                }
            }

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
            if(toggleDebug){
                loopcounter = 0;
                loopreset = 1;
                iniaddress -= 20 * 16 * 10; // DECREASE 10 PAGES
                if(iniaddress <= 0x30000000){
                    iniaddress = 0x30000000;
                }
            }

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
                    toggleRelearn = !toggleRelearn;
                    if(toggleDebug){
                        iniaddress = startupadd; // RESET TO INITIAL ADDRESS
                        loopreset = 1;
                    }
                }
                if(is_pressed(BUTTON_R)){
                    buttonAckX2 = 1;
                    toggleDebug = !toggleDebug;
                }
                if(is_pressed(BUTTON_DR)){
                    // INCREASE POKEMON FORM
                    buttonAckX2 = 1;
                    plooklocation = (plooklocation + 1) % PK_SIZE[currentpkmnID - 1];
                    // u8 cform = POKEMON_LOOKUP[currentpkmnID - 1][0][0];
                    // plookarraysize = cform == 1 ? 1 : 0;
                    // plookarraysize = cform == 2 ? 2 : plookarraysize;
                    // plookarraysize = cform == 3 ? 3 : plookarraysize;
                    // plookarraysize = cform == 4 ? 4 : plookarraysize;
                    // plookarraysize = cform == 5 ? 5 : plookarraysize;
                    // plookarraysize = cform == 6 ? 6 : plookarraysize;
                    // plooklocation = (plooklocation + 1) % plookarraysize;
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
                iniaddress -= 1 * 16; // DEREASE A PAGE
                if(iniaddress <= 0x30000000){
                    iniaddress = 0x30000000;
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
                iniaddress += 1 * 16; // INCREASE A PAGE
                if(iniaddress >= 0x34000000){
                    iniaddress = 0x34000000;
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
            // This activates when RIGHT is pressed once

            if(toggleDebug){
                loopcounter = 0;
                loopreset = 1;
                iniaddress += 20 * 16; // INCREASE A LINE
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
            // This activates when LEFT is pressed once

            if(toggleDebug){
                loopcounter = 0;
                loopreset = 1;
                iniaddress -= 20 * 16; // DECREASE A LINE
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
        if(!isInBattle2()){
            sosactivate = 0;
            soscounter = 0;
            for (char i = 0; i < 12; i++) {
                sosarray[0][i] = 0;
                sosarray[1][i] = 0;
                sosarray[2][i] = 0;
            }
        }
    }else{
        if(isInBattle2()){
            // INITIALIZE ENEMY ARRAY AND RESET COUNTER
            sosactivate = 1;
            soscounter = 0;
            parseSOSData(0,0);
            parseSOSData(2,1);
            sosenemydiff = 0;
            if(compareSOSData(0,2)){
                sosenemydiff = 1;
            }
        }
    }

    // THIS ACTIVATE AS SOON AS A BATTLE STARTS
    if(sosactivate){
        parseSOSData(1,0);
        if(compareSOSData(0,1)){
            soscounter++;
            parseSOSData(0,0);
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

    if(!isInBattle2()){
        // HIDE OPPONENT AND TEAM OUTSIDE BATTLE
        if(selectedOpponent >= OPPONENT_INDEX && selectedOpponent < (OPPONENT_INDEX + 11)){
            selectedOpponent = OPPONENT_INDEX + 12;
        }
        if(selectedOpponent >= (OPPONENT_INDEX + 11) && selectedOpponent < (OPPONENT_INDEX + 12)){
            selectedOpponent = OPPONENT_INDEX - 1;
        }
    }else{
        // HIDE PARTY INSIDE A BATTLE
        if(selectedOpponent >= PARTY_INDEX && selectedOpponent < (PARTY_INDEX + 5)){
            selectedOpponent = PARTY_INDEX + 6;
        }
        if(selectedOpponent >= (PARTY_INDEX + 5) && selectedOpponent < (PARTY_INDEX + 6)){
            selectedOpponent = PARTY_INDEX - 1;
        }
    }

    u8 enemyIndex = (selectedOpponent >= OPPONENT_INDEX && selectedOpponent < ((u8)OPPONENT_INDEX + 12)) ? (u8)(selectedOpponent - (u8)OPPONENT_INDEX) : (u8)(0xFF);
    u8 enemyExists = (enemyIndex != 0xFF && sosarray[2][enemyIndex] > 1) ? 1 : 0;

    u8* enemyPointer = (u8*)(OPPONENT_POINTERS[selectedOpponent]);
    if(isInBattle2() && !sosenemydiff && enemyIndex != 0xFF){
        enemyPointer = (u8*)(SOSPointers[enemyIndex]);
    }

    if(pkm != 0 && !toggleDebug ) {

        decryptPokemon(enemyPointer, pkm);

        char buf[100];
        char nick[13];
        int posX = 12;
        int posY = 9;
		int posXsav = 0;
		int posYsav = 0;
        u8 battleDataValid = 0;

        u16 bstats[6] = {0};
        u8 buffs[7] = {0};
        u8 sleepbit = 0;
        u8 sleepbit2 = 0;

        // See if the pokemon's actually valid first
        if(isValid(pkm)) {

            u8 ScreenLines = 23;
            // Draw background twice. Better contrast.
			OvDrawTranspartBlackRect(posX - 6, posY - 4, 212, (10 * ScreenLines) + 3, 1);
			OvDrawTranspartBlackRect(posX - 6, posY - 4, 212, (10 * ScreenLines) + 3, 1);

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

            // DETECT WHEN A NEW POKEMON IS SHOWING

            if((u16)lastPID != (u16)pkm->pid){
                // WHEN THIS HAPPENS SWITCH FORMS TO THE RIGHT ONE
                lastPID = pkm->pid;
                plooklocation = form;
            }

            // Get Pokemon nickname into nick char array
            asciiNick(pkm, nick);

            // Get pokedex number
            currentpkmnID = pkm->species;

            const spawnPokemon *pokemon;
            pokemon = &pokemonID[currentpkmnID - 1];


            // DETECT IF FORM EXISTS BEFORE GETTING DATA
            // this is to avoid random crashes when changing pokemon who don't have a certain form
            // char formsnum = POKEMON_LOOKUP[currentpkmnID - 1][0][0];
            char formsnum = PK_SIZE[currentpkmnID - 1];
            if(plooklocation + 1 > formsnum){
                // IF IT DOESNT EXISTS CHANGE FORM TO SLOT 0
                plooklocation = 0;
            }

            // GET POKEMON GENERAL COLOR
            // char xcolor = POKEMON_LOOKUP[currentpkmnID - 1][plooklocation][7] - 1;
            char xcolor = PK_LOOKUP[currentpkmnID - 1][(plooklocation * 9) + 6] - 1;

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


            decryptBattleData(enemyPointer, battleStats);
            if(battleStats->level == pklevel && isInBattle2()){
                battleDataValid = 1;

                // GET DECRYPTED BATTLE DATA
                u16 selectedHP = battleStats->currentHP;
                u16 selectedATT = battleStats->attack;
                u16 selectedDEF = battleStats->defense;
                u16 selectedSPA = battleStats->specialAttack;
                u16 selectedSPD = battleStats->specialDefense;
                u16 selectedSPE = battleStats->speed;


                // CURRENT ENEMY HP AND BUFFS
                if(selectedOpponent >= OPPONENT_INDEX && selectedOpponent < (OPPONENT_INDEX + 6)){
                    selectedHP = (u16)*((u16*)(0x3000BDA0 + (selectedOpponent - OPPONENT_INDEX) * 0x0330));

                    // STATS STORED IN MEMORY OUTSIDE OF POKEMON BATTLE DATA
                    // selectedATT = (u16)*((u16*)((0x3000BDA0 + (selectedOpponent - OPPONENT_INDEX) * 0x0330) + 0x01CA + (0x02 * 0)));
                    // selectedDEF = (u16)*((u16*)((0x3000BDA0 + (selectedOpponent - OPPONENT_INDEX) * 0x0330) + 0x01CA + (0x02 * 1)));
                    // selectedSPA = (u16)*((u16*)((0x3000BDA0 + (selectedOpponent - OPPONENT_INDEX) * 0x0330) + 0x01CA + (0x02 * 2)));
                    // selectedSPD = (u16)*((u16*)((0x3000BDA0 + (selectedOpponent - OPPONENT_INDEX) * 0x0330) + 0x01CA + (0x02 * 3)));
                    // selectedSPE = (u16)*((u16*)((0x3000BDA0 + (selectedOpponent - OPPONENT_INDEX) * 0x0330) + 0x01CA + (0x02 * 4)));

                    // ATTACK BUFF
                    buffs[0] = (u8)*((u8*)(0x30004f92 + (selectedOpponent - OPPONENT_INDEX) * 0x0330));
                    // DEFENSE BUFF
                    buffs[1] = (u8)*((u8*)(0x30004f93 + (selectedOpponent - OPPONENT_INDEX) * 0x0330));
                    // SPA BUFF
                    buffs[2] = (u8)*((u8*)(0x30004f94 + (selectedOpponent - OPPONENT_INDEX) * 0x0330));
                    // SPD BUFF
                    buffs[3] = (u8)*((u8*)(0x30004f95 + (selectedOpponent - OPPONENT_INDEX) * 0x0330));
                    // SPE BUFF
                    buffs[4] = (u8)*((u8*)(0x30004f96 + (selectedOpponent - OPPONENT_INDEX) * 0x0330));

                    // SLEEP
                    // sleepbit2 = (u8)*((u8*)(0x30004DD8 + (selectedOpponent - OPPONENT_INDEX) * 0x0330));
                    // sleepbit = (u8)*((u8*)(0x30004DD9 + (selectedOpponent - OPPONENT_INDEX) * 0x0330));

                    // ACCURACY
                    // buffs[5] = (u8)*((u8*)(0x30004f97 + (selectedOpponent - OPPONENT_INDEX) * 0x0330));
                    // EVASION
                    // buffs[6] = (u8)*((u8*)(0x30004f98 + (selectedOpponent - OPPONENT_INDEX) * 0x0330));
                }

                // DIFF BETWEEN ENEMY AND TEAM 1rst POKE
                // == 0x2640
                // == 0x1B9

                // CURRENT TEAM HP AND BUFFS
                if(selectedOpponent >= (OPPONENT_INDEX + 6) && selectedOpponent < (OPPONENT_INDEX + 12)){
                    selectedHP = (u16)*((u16*)(0x30009760 + (selectedOpponent - OPPONENT_INDEX - 6) * 0x0330));

                    // ATTACK BUFF
                    buffs[0] = (u8)*((u8*)(0x30002952 + (selectedOpponent - OPPONENT_INDEX - 6) * 0x0330));
                    // DEFENSE BUFF
                    buffs[1] = (u8)*((u8*)(0x30002953 + (selectedOpponent - OPPONENT_INDEX - 6) * 0x0330));
                    // SPA BUFF
                    buffs[2] = (u8)*((u8*)(0x30002954 + (selectedOpponent - OPPONENT_INDEX - 6) * 0x0330));
                    // SPD BUFF
                    buffs[3] = (u8)*((u8*)(0x30002955 + (selectedOpponent - OPPONENT_INDEX - 6) * 0x0330));
                    // SPE BUFF
                    buffs[4] = (u8)*((u8*)(0x30002956 + (selectedOpponent - OPPONENT_INDEX - 6) * 0x0330));

                    // SLEEP IF SLEEP = 3 POKEMON IS ASLEEP... UNKOWN TURNS
                    // sleepbit2 = (u8)*((u8*)(0x30002798 + (selectedOpponent - OPPONENT_INDEX - 6) * 0x0330));
                    // sleepbit = (u8)*((u8*)(0x30002799 + (selectedOpponent - OPPONENT_INDEX - 6) * 0x0330));

                    // ACCURACY
                    // buffs[5] = (u8)*((u8*)(0x30002957 + (selectedOpponent - OPPONENT_INDEX - 6) * 0x0330));
                    // EVASION
                    // buffs[6] = (u8)*((u8*)(0x30002958 + (selectedOpponent - OPPONENT_INDEX - 6) * 0x0330));
                }

                // THIS IS NOT SHOWING CURRENTLY AS PARTY IS DISABLED ON BATTLE
                if(selectedOpponent >= PARTY_INDEX && selectedOpponent < (PARTY_INDEX + 6)){
                    selectedHP = (u16)*((u16*)(0x30009760 + (selectedOpponent - PARTY_INDEX) * 0x0330));
                    // selectedATT = (u16)*((u16*)((0x30009760 + (selectedOpponent - PARTY_INDEX) * 0x0330) + 0x01CA + (0x02 * 0)));
                    // selectedDEF = (u16)*((u16*)((0x30009760 + (selectedOpponent - PARTY_INDEX) * 0x0330) + 0x01CA + (0x02 * 1)));
                    // selectedSPA = (u16)*((u16*)((0x30009760 + (selectedOpponent - PARTY_INDEX) * 0x0330) + 0x01CA + (0x02 * 2)));
                    // selectedSPD = (u16)*((u16*)((0x30009760 + (selectedOpponent - PARTY_INDEX) * 0x0330) + 0x01CA + (0x02 * 3)));
                    // selectedSPE = (u16)*((u16*)((0x30009760 + (selectedOpponent - PARTY_INDEX) * 0x0330) + 0x01CA + (0x02 * 4)));
                }

                // RESET BUFFS IF THEY ARE OVERLOADING
                for (u8 i = 0; i < 6; i++) {
                    if(buffs[i] > 12){
                        for (u8 j = 0; j < 6; j++) {
                            buffs[j] = 6;
                        }
                    }
                }

                // HP
                bstats[0] = selectedHP;
                // ATTACK
                bstats[1] = (buffs[0] - 6) < 0 ? xfloor((double)(selectedATT * 2 / (12 - buffs[0] - 4))) : xfloor((double)(selectedATT * (buffs[0] - 4) / 2));
                // DEFENSE
                bstats[2] = (buffs[1] - 6) < 0 ? xfloor((double)(selectedDEF * 2 / (12 - buffs[1] - 4))) : xfloor((double)(selectedDEF * (buffs[1] - 4) / 2));
                // SPA
                bstats[3] = (buffs[2] - 6) < 0 ? xfloor((double)(selectedSPA * 2 / (12 - buffs[2] - 4))) : xfloor((double)(selectedSPA * (buffs[2] - 4) / 2));
                // SPD
                bstats[4] = (buffs[3] - 6) < 0 ? xfloor((double)(selectedSPD * 2 / (12 - buffs[3] - 4))) : xfloor((double)(selectedSPD * (buffs[3] - 4) / 2));
                // SPE
                bstats[5] = (buffs[4] - 6) < 0 ? xfloor((double)(selectedSPE * 2 / (12 - buffs[4] - 4))) : xfloor((double)(selectedSPE * (buffs[4] - 4) / 2));


                // bstats[1] = selectedATT;
                // bstats[2] = selectedDEF;
                // bstats[3] = selectedSPA;
                // bstats[4] = selectedSPD;
                // bstats[5] = selectedSPE;



            }

            // SLEEP ADDRESS holds 3 after rest
            // 0x30002799 + (0x0330 * partyIndex)


            // STATS UPS Party Pokemon
            // 0x30002952 + (0x0330 * partyIndex) ATT
            // 0x30002953 + (0x0330 * partyIndex) DEF
            // 0x30002954 + (0x0330 * partyIndex) SPA
            // 0x30002955 + (0x0330 * partyIndex) SPD
            // 0x30002956 + (0x0330 * partyIndex) SPE
            // 0x30002957 + (0x0330 * partyIndex) ACC
            // 0x30002958 + (0x0330 * partyIndex) EVASION


            // STATS UPS ENEMY Pokemon
            // 0x30004f92 + (0x0330 * EnemyIndex) ATT
            // 0x30004f93 + (0x0330 * EnemyIndex) DEF
            // 0x30004f94 + (0x0330 * EnemyIndex) SPA
            // 0x30004f95 + (0x0330 * EnemyIndex) SPD
            // 0x30004f96 + (0x0330 * EnemyIndex) SPE
            // 0x30004f97 + (0x0330 * EnemyIndex) ACC
            // 0x30004f98 + (0x0330 * EnemyIndex) EVASION


            // POISON BYTE FOR 1rst POKEMON
            // 0x300029AC





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
            // xsprintf(buf, "Gen: %s  Catch Rate: %d/255", gender, CATCH_RATE[currentpkmnID - 1] );
            xsprintf(buf, "Gen: %s  Catch Rate: %d/255", gender, CATCH_RATE[currentpkmnID - 1] );
            posY = OvDrawString(buf, posX, posY, BLANK);

            // DRAW SHINY STAR
            if(shiny){
                OvDrawSymbol(0x02, posX + 105 + 68, posY - 1, 255,0,0);
            }
            OvDrawSymbol(0x04, posX + 105 + 68, posY - 1, 0,0,0);

            // FORM AND SHINY STRING
            xsprintf(buf, "%28s", "Shiny:");
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


            // // DRAW LEVEL USED FOR STAT CALCULATION
            xsprintf(buf, "Sim Lv:       Sim Form: %s", simform->name);
			OvDrawString(buf, posX,  posY, BLANK);

            // // DRAW LEVEL AND HIGHLIGHT SIMULATION BASE LVL WHEN ACTIVE
            xsprintf(buf, "%11d", pklevel);
			posY = OvDrawString(buf, posX,  posY, togglebaselevel50 ? 255 : 255, togglebaselevel50 ? 0 : 255, togglebaselevel50 ? 0 : 255);

            // DRAW POKEMON NAME ON TOP OF THE COLOR BORDER
            // xsprintf(buf, "      %s", POKEMON_LOOKUP_NAME[currentpkmnID - 1][plooklocation][0]);
            // if(xcolor == 9 || xcolor == 8 || xcolor == 5 || xcolor == 3){ // WHITE YELLOW PINK GRAY => DARK TEXT
			    // posY = OvDrawString(buf, posX,  posY, 55,55,55);
            // }else{
			    // posY = OvDrawString(buf, posX,  posY, BLANK);
            // }

            // DRAW BOTH TYPES
            // drawType(POKEMON_LOOKUP[currentpkmnID - 1][plooklocation][8], posX, posY);
            // drawType(POKEMON_LOOKUP[currentpkmnID - 1][plooklocation][9], posX + 65, posY);
            drawType(PK_LOOKUP[currentpkmnID - 1][(plooklocation * 9) + 7], posX, posY);
            drawType(PK_LOOKUP[currentpkmnID - 1][(plooklocation * 9) + 8], posX + 65, posY);

            u16 pkmarks = (pkm->markByte2 << 8) + pkm->markByte1;
            for (u8 i = 0; i < 6; i++) {
                u8 mark1 = (pkmarks >> ((i * 2) + 0)) & 0x1;
                u8 mark2 = (pkmarks >> ((i * 2) + 1)) & 0x1;
                // BLUE 0,191,255
                // PINK 255,114,176
                // GRAY 187,192,187
                u8 r = mark1 ? 0 : mark2 ? 255 : 187;
                u8 g = mark1 ? 191 : mark2 ? 114 : 192;
                u8 b = mark1 ? 255 : mark2 ? 176 : 187;
                OvDrawChar(0x80 + i, posX + 136 + (9 * i), posY + 3, r, g, b);
            }

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
                // int curstat = POKEMON_LOOKUP[currentpkmnID - 1][plooklocation][1 + j];
                int curstat = PK_LOOKUP[currentpkmnID - 1][(plooklocation * 9) + j];

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
                    // DRAW BUFFED STATS AND SYMBOLS
                    if(j > 0){
                        if(buffs[j - 1] < 6){
    				        xsprintf(buf, "\x89");
            				OvDrawString(buf, posX + 78, posY + 1, 152, 216, 216);

    				        xsprintf(buf, " %d", 12 - buffs[j - 1] - 6);
            				OvDrawString(buf, posX + 80, posY, 152, 216, 216);
                        }else if(buffs[j - 1] > 6){
                            xsprintf(buf, "\x81");
            				OvDrawString(buf, posX + 78, posY + 1, 255, 0, 0);

    				        xsprintf(buf, " %d", buffs[j - 1] - 6);
            				OvDrawString(buf, posX + 80, posY, 255, 0, 0);
                        }
                    }
                }

                // DRAW SINGLE FINAL STAT
				xsprintf(buf, "%d", curstat);
				posY = OvDrawString(buf, posX, posY, r, g, b);
			}



            // RESTORE X POS
            posX = posXsav;
            posY += 1;

            if(toggleRelearn){
                OvDrawChar(0x85, posX + 187, posY - 10, 255, 0, 0);
            }
			// MOVES
			for(u8 i = 0; i < 4; i++) {

                // CREATE VARIABLES TO STORE MOVE VALUES
                char movePP_s[5];
                char maxPP_s[5];
                char move_damage_s[5];
                char move_acc_s[5];

                // GET MOVE ID
				u16 move = pkm->moves[i];
                if(toggleRelearn){
                    move = pkm->relearnMoves[i];
                }

                // GET MOVE PP
				u8 movePP = pkm->movePP[i];
                u8 movePPUp = pkm->movePPUp[i];

                // GET MOVE TYPE
                u8 moveType = MOVE_DATA[move][0];
                u8 moveStyle = MOVE_DATA[move][1];

                // STORE MOVE DATA INSIDE THE STRING VARIABLES
                //
                itoa(movePP,movePP_s,10);
                itoa(MOVE_DATA[move][2] + (0.2 * MOVE_DATA[move][2] * movePPUp),maxPP_s,10);
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
                    drawMove(MOVE_LOOKUP[move], moveType, moveStyle, posX - 3, posY -2);
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



            // TSV AND ESV AND POKERUS
            u8 hasPKRS = (pkm->pkrsData >> 4) == 0 ? 0 : ( ((pkm->pkrsData << 4) & 0xFF) >> 4 ) > 0 ? 1 : 2;
            // Trainer Shiny value and Egg's shiny value
			xsprintf(buf, "TSV: %-4d ESV: %-4d PKRS:", tsv, esv );
			OvDrawString(buf, posX, posY, BLANK);


            // PINK POKERUS CURED 248,83,224
            // GREEN 0,255,0
            // Dark Grey
            u8 r = hasPKRS == 0 ? 80 : hasPKRS == 1 ? 0 : 248;
            u8 g = hasPKRS == 0 ? 80 : hasPKRS == 1 ? 255 : 83;
            u8 b = hasPKRS == 0 ? 80 : hasPKRS == 1 ? 0 : 224;
            if(hasPKRS){
    			OvDrawChar(0x86, posX + 156, posY, r, g, b);
    			OvDrawChar(0x87, posX + 156, posY, 255, 255, 255);
            }
            OvDrawChar(0x88,     posX + 156, posY, r, g, b);



        } else {
            // ----------------------------
            // NO DATA SCREEN INIT
            // ----------------------------

            int NoDataScreenLines = 12;

            // DRAW DOUBLE BACKGROUND
            OvDrawTranspartBlackRect(posX - 6, posY - 4, 212, (10 * NoDataScreenLines) + 6, 1);
			OvDrawTranspartBlackRect(posX - 6, posY - 4, 212, (10 * NoDataScreenLines) + 6, 1);


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

			xsprintf(buf, "[X+L] Toggle Relearn Moves");
			posY = OvDrawString(buf, posX + offsetl, posY, BLANK);

			xsprintf(buf, "[X+Down] Toggle Bottom Screen");
			posY = OvDrawString(buf, posX + offsetl, posY, BLANK);

			xsprintf(buf, "%s  %s", getWifiStatus() ? "Wifi [On]" : "Wifi [Off]", isInBattle2() ? "In Battle" : "Not In Battle");
			posY = OvDrawString(buf, posX + 6, posY, BLANK);
			xsprintf(buf, "SOS Counter %s [%x]", sosactivate ? "On" : "Off", soscounter);
			posY = OvDrawString(buf, posX + 6, posY, BLANK);

			// xsprintf(buf, "[%d] [%d] [%x][%x][%x]", enemyIndex, enemyExists, OPPONENT_POINTERS[selectedOpponent], enemyOffset, enemyPointer);
			// posY = OvDrawString(buf, posX + 6, posY, BLANK);
			// xsprintf(buf, "[%d]", sosenemydiff);
			// posY = OvDrawString(buf, posX + 6, posY, BLANK);

            // // SHOW DATA FOR SOS POKEMON
            // for (char i = 0; i < 12; i++) {
    		// 	xsprintf(buf, "SOS: %x | %x / %x", sosarray[2][i], sosarray[0][i], sosarray[1][i]);
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
	if(enabled && isBottom == isBottomToggle && battleInfo){
        drawPokemonID();
        return 0;
	}

    return 1;
}

void overlayInit(void) {
    initSharedFunc();
    plgRegisterCallback(CALLBACK_OVERLAY, (void*) overlayCallback, 0);
}
