// Filename: items.c

#include "cheats.h"
#include "hid.h"

/********************************
*				*
*	      Items		*
*				*
********************************/

int i_allPokeBalls,
    i_allItems,
    i_allMedicine,
    i_allTMs,
    i_allBerries,
    i_allBeans,
    i_allClothes;


// Item menu entry
void    itemMenu(void) {
    new_spoiler("Items");
        i_allPokeBalls = new_entry("All Poke Balls x100", allPokeBalls);
        i_allItems = new_entry("All Items      x100", allItems);
        i_allMedicine = new_entry("All Medicine   x100", allMedicine);
        i_allBerries = new_entry("All Berries    x100", allBerries);
        i_allBeans = new_entry("All Poke Beans x100", allBeans);
        i_allTMs = new_entry("All TMs", allTMs);
        i_allClothes = new_entry("All Clothes", allClothes);
        new_line();
    exit_spoiler();
}


// Gives only Poké Balls and sets quantity to 100
void    allPokeBalls(void) {
    u32 offset = 0x330D5934;
    u32 quantity = 100;
    u32 value;
    int existingIndex = 0;
    bool skip;
    static bool done;
    static const u32 pokeballs[25] = {
      1,   2,   3,   4,   5,
      6,   7,   8,   9,  10,
     11,  12,  13,  14,  15,
     16, 492, 493, 494, 495,
    496, 497, 498, 576, 851
    };

    u32 existingPokeBalls[25] = {
    999, 999, 999, 999, 999,
    999, 999, 999, 999, 999,
    999, 999, 999, 999, 999,
    999, 999, 999, 999, 999,
    999, 999, 999, 999, 999
    };

    for (int itemCount = 0; (itemCount < 335) && !done; itemCount++) { // Iterates through inventory
    	value = READU32(offset + itemCount*4) & 0x3FF; // Reads inventory slot
    	if (value == 0x0) { // Checks if end of inventory was reached
    		for (int i = 0; i < 25; i++) { // Iterates through Poké Balls to add
    			skip = false;
    			for (int haveCheck = 0; (haveCheck < 25) && !skip; haveCheck++) { // Iterates through Poké Balls that player already has and skips adding them if found
    				if (pokeballs[i] == existingPokeBalls[haveCheck]) {
    					skip = true;
    				}
    			}
    			if (!skip) { // Writes Poké Ball to empty slot if not previously owned
    				WRITEU32(offset + itemCount*4, pokeballs[i] + (quantity << 10));
    				itemCount++;
    			}
    		}
            done = true;
    		break;
    	}
    	for (int ballCheck = 0; ballCheck < 25; ballCheck++) { // Checks if inventory slot is already a Poké Ball and sets quantity
    		if (value == pokeballs[ballCheck]) {
    			WRITEU32(offset + itemCount*4, value + (quantity << 10));
    			existingPokeBalls[existingIndex] = value; // Keeps track of which Poké Balls the player already has
    			existingIndex++;
                break;
    		}
    	}
    }
    if (any_is_pressed(0x0000CFFE)) { // Any button but A disables cheat
        done = false;
        disableCheat(i_allPokeBalls);
    }
}


// Gives all items and sets them to quantity 100
void    allItems(void) {
    u32    offset = 0x330D5934; // Start of Item Inventory
    u16    quantity = 100; // Number of each item to give

    // Array of legal items
    static const u16    allItems[335] =
    {
      1,   2,   3,   4,   5,   6,   7,   8,
      9,  10,  11,  12,  13,  14,  15,  16,
     55,  56,  57,  58,  59,  60,  61,  62,
     63,  64,  68,  69,  70,  71,  72,  73,
     74,  75,  76,  77,  78,  79,  80,  81,
     82,  83,  84,  85,  86,  87,  88,  89,
     90,  91,  92,  93,  94,  99, 100, 101,
    102, 103, 104, 105, 106, 107, 108, 109,
    110, 111, 112, 116, 117, 118, 119, 135,
    136, 137, 213, 214, 215, 217, 218, 219,
    220, 221, 222, 223, 224, 225, 226, 227,
    228, 229, 230, 231, 232, 233, 234, 235,
    236, 237, 238, 239, 240, 241, 242, 243,
    244, 245, 246, 247, 248, 249, 250, 251,
    252, 253, 254, 255, 256, 257, 258, 259,
    260, 261, 262, 263, 264, 265, 266, 267,
    268, 269, 270, 271, 272, 273, 274, 275,
    276, 277, 278, 279, 280, 281, 282, 283,
    284, 285, 286, 287, 288, 289, 290, 291,
    292, 293, 294, 295, 296, 297, 298, 299,
    300, 301, 302, 303, 304, 305, 306, 307,
    308, 309, 310, 311, 312, 313, 314, 315,
    316, 317, 318, 319, 320, 321, 322, 323,
    324, 325, 326, 327, 492, 493, 494, 495,
    496, 497, 498, 499, 534, 535, 537, 538,
    539, 540, 541, 542, 543, 544, 545, 546,
    547, 548, 549, 550, 551, 552, 553, 554,
    555, 556, 557, 558, 559, 560, 561, 562,
    563, 564, 571, 572, 573, 576, 577, 580,
    581, 582, 583, 584, 585, 586, 587, 588,
    589, 590, 639, 640, 644, 646, 647, 648,
    649, 650, 656, 657, 658, 659, 660, 661,
    662, 663, 664, 665, 666, 667, 668, 669,
    670, 671, 672, 673, 674, 675, 676, 677,
    678, 679, 680, 681, 682, 683, 684, 685,
    699, 704, 710, 711, 715, 752, 753, 754,
    755, 756, 757, 758, 759, 760, 761, 762,
    763, 764, 767, 768, 769, 770, 795, 796,
    844, 846, 849, 851, 853, 854, 855, 856,
    879, 880, 881, 882, 883, 884, 904, 905,
    906, 907, 908, 909, 910, 911, 912, 913,
    914, 915, 916, 917, 918, 919, 920
    };

    // Writes the array to inventory
    for (int i = 0; i < 335; i++) {
       WRITEU32(offset + i*4, allItems[i] + (quantity << 10));
    }

    if (any_is_pressed(0x0000CFFE)) // Any button but A disables cheat
        disableCheat(i_allItems);
}


// Gives all medicine and sets them to quantity 100
void    allMedicine(void) {
    u32    offset = 0x330D647C; // Start of Medicine Inventory
    u16    quantity = 100; // Number of each item to give

    // Array of legal items
    static const u16    allMedicine[54] =
    {
     17,  18,  19,  20,  21,  22,  23,  24,
     25,  26,  27,  28,  29,  30,  31,  32,
     33,  34,  35,  36,  37,  38,  39,  40,
     41,  42,  43,  44,  45,  46,  47,  48,
     49,  50,  51,  52,  53,  54,  65,  66,
     67, 134, 504, 565, 566, 567, 568, 569,
    570, 591, 645, 708, 709, 852
    };

    // Writes the array to inventory
    for (int i = 0; i < 54; i++) {
       WRITEU32(offset + i*4, allMedicine[i] + (quantity << 10));
    }

    if (any_is_pressed(0x0000CFFE)) // Any button but A disables cheat
        disableCheat(i_allMedicine);
}

// Gives all TMs
void    allTMs(void) {
    u32    offset = 0x330D62CC; // Start of TM Inventory
    u16    quantity = 1; // Number of each item to give

    // Array of legal items
    static const u16    allTMs[100] =
    {
    328, 329, 330, 331, 332, 333, 334, 335,
    336, 337, 338, 339, 340, 341, 342, 343,
    344, 345, 346, 347, 348, 349, 350, 351,
    352, 353, 354, 355, 356, 357, 358, 359,
    360, 361, 362, 363, 364, 365, 366, 367,
    368, 369, 370, 371, 372, 373, 374, 375,
    376, 377, 378, 379, 380, 381, 382, 383,
    384, 385, 386, 387, 388, 389, 390, 391,
    392, 393, 394, 395, 396, 397, 398, 399,
    400, 401, 402, 403, 404, 405, 406, 407,
    408, 409, 410, 411, 412, 413, 414, 415,
    416, 417, 418, 419, 618, 619, 620, 690,
    691, 692, 693, 694
    };

    // Writes the array to inventory
    for (int i = 0; i < 100; i++) {
       WRITEU32(offset + i*4, allTMs[i] + (quantity << 10));
    }

    if (any_is_pressed(0x0000CFFE)) // Any button but A disables cheat
        disableCheat(i_allTMs);
}


// Gives all Berries and sets quantity to 100
void    allBerries(void) {
    u32    offset = 0x330D657C; // Start of Berry Inventory
    u16    quantity = 100; // Number of each item to give

    // Array of legal items
    static const u16    allBerries[67] =
    {
    149, 150, 151, 152, 153, 154, 155, 156,
    157, 158, 159, 160, 161, 162, 163, 164,
    165, 166, 167, 168, 169, 170, 171, 172,
    173, 174, 175, 176, 177, 178, 179, 180,
    181, 182, 183, 184, 185, 186, 187, 188,
    189, 190, 191, 192, 193, 194, 195, 196,
    197, 198, 199, 200, 201, 202, 203, 204,
    205, 206, 207, 208, 209, 210, 211, 212,
    686, 687, 688
    };

    // Writes the array to inventory
    for (int i = 0; i < 67; i++) {
       WRITEU32(offset + i*4, allBerries[i] + (quantity << 10));
    }

    if (any_is_pressed(0x0000CFFE)) // Any button but A disables cheat
        disableCheat(i_allBerries);
}


// Gives all PokeBeans and sets them to quantity of 100
void    allBeans(void) {
    for (int i = 0; i < 15; i++) {
    WRITEU8(0x33115490 + i, 0x64);
    }

    if (any_is_pressed(0x0000CFFE)) // Any button but A
		disableCheat(i_allBeans);
}


// Function to add clothes to inventory
u32		clothesFunction(u32 offset, u8 data, u16 loop_num) {
	for (int i = 0; i < loop_num; i++) {
		WRITEU8(0x00000000 + offset, data);
		offset += 0x01;
	}
	return(offset);
}

// All Clothes
void	allClothes(void) {
	u32 offset = 0x33116620;

    if (READU8(0x330D67D5) == 0x00) {
        offset = clothesFunction(offset, 0x01, 0x003A);
        offset = clothesFunction(offset, 0x00, 0x0087);
        offset = clothesFunction(offset, 0x01, 0x0014);
        offset = clothesFunction(offset, 0x00, 0x0020);
        offset = clothesFunction(offset, 0x01, 0x0100);
        offset = clothesFunction(offset, 0x00, 0x008F);
        offset = clothesFunction(offset, 0x01, 0x0069);
        offset = clothesFunction(offset, 0x00, 0x00C7);
        offset = clothesFunction(offset, 0x01, 0x0025);
        offset = clothesFunction(offset, 0x00, 0x0079);
        offset = clothesFunction(offset, 0x01, 0x005F);
        offset = clothesFunction(offset, 0x00, 0x0066);
        offset = clothesFunction(offset, 0x01, 0x006D);
        clothesFunction(offset, 0x00, 0x0044);
    } else {
        offset = clothesFunction(offset, 0x01, 0x005E);
        offset = clothesFunction(offset, 0x00, 0x0020);
        offset = clothesFunction(offset, 0x01, 0x0023);
        offset = clothesFunction(offset, 0x00, 0x0020);
        offset = clothesFunction(offset, 0x01, 0x0014);
        offset = clothesFunction(offset, 0x00, 0x0020);
        offset = clothesFunction(offset, 0x01, 0x018A);
        offset = clothesFunction(offset, 0x00, 0x0005);
        offset = clothesFunction(offset, 0x01, 0x00F9);
        offset = clothesFunction(offset, 0x00, 0x0037);
        offset = clothesFunction(offset, 0x01, 0x007E);
        offset = clothesFunction(offset, 0x00, 0x0020);
        offset = clothesFunction(offset, 0x01, 0x00A7);
        offset = clothesFunction(offset, 0x00, 0x001E);
        offset = clothesFunction(offset, 0x01, 0x0091);
        clothesFunction(offset, 0x00, 0x0020);
    }

    offset = 0x33116620;

	WRITEU32(0x000000F8 + offset, 0x03010101);
	WRITEU32(0x000002C8 + offset, 0x03010101);
	WRITEU32(0x000003B4 + offset, 0x01010103);
	WRITEU32(0x00000450 + offset, 0x01030000);
	WRITEU32(0x00000514 + offset, 0x03000000);

	if (any_is_pressed(0x0000CFFE))
		disableCheat(i_allClothes);
}
