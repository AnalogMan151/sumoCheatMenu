// Filename: items.c

#include "cheats.h"
#include "hid.h"
#include "items.h"



/********************************
 *                              *
 *            Items             *
 *                              *
 ********************************/


char selectedQuantity[4];

static u16 quantity = 50;


// Item menu entry
void    itemMenu(void) {

    new_spoiler("Items");
        new_entry_managed("Increase Quantity +50", increaseQuantity, INCREASEQUANTITY, AUTO_DISABLE);
        new_separator();

        new_entry_managed("All Poke Balls      xCCC", allPokeBalls, ALLPOKEBALLS, EXECUTE_ONCE);
        new_entry_managed("All Items           xCCC", allItems, ALLITEMS, EXECUTE_ONCE);
        new_entry_managed("All Medicine        xCCC", allMedicine, ALLMEDICINE, EXECUTE_ONCE);
        new_entry_managed("All Berries         xCCC", allBerries, ALLBERRIES, EXECUTE_ONCE);
        new_entry_managed("All Poke Beans      xCCC", allBeans, ALLBEANS, EXECUTE_ONCE);
        new_entry_managed("All TMs", allTMs, ALLTMS, EXECUTE_ONCE);
        new_entry_managed("All Clothes", allClothes, ALLCLOTHES, EXECUTE_ONCE);
        new_line();
    exit_spoiler();
    updateQuantity();
}

// Updates item quantity on menu
void    updateQuantity(void) {
    char buf[5];

    xsprintf(buf, "x%-3d", quantity);
    replace_pattern("x***", buf, ALLPOKEBALLS);
    replace_pattern("x***", buf, ALLITEMS);
    replace_pattern("x***", buf, ALLMEDICINE);
    replace_pattern("x***", buf, ALLBERRIES);
    replace_pattern("x***", (quantity > 255) ? "x255" : buf, ALLBEANS);
}


// Increases item quantity by 50
void    increaseQuantity(void) {
    switch(quantity) {
        case 999:
            quantity = 50;
            break;
        case 950:
            quantity = 999;
            break;
        default:
            quantity += 50;
    }
    updateQuantity();
}


// Gives only Poké Balls
void    allPokeBalls(void) {
    u32 offset = 0x330D5934;
    int value;
    int existingIndex = 0;

    // Initialize array of already owned Poké Balls to an unused value
    int existingPokeBalls[25];
    memset32(existingPokeBalls, 999, sizeof(existingPokeBalls));

    // Iterates through inventory
    for (int itemCount = 0; itemCount < TOTALPOKEBALLS + TOTALITEMS; itemCount++) {

        // Reads inventory slot and stores the item
    	value = READU32(offset + itemCount*4) & 0x3FF;

        // Checks if inventory slot has an item in it
    	if (value) {

            // Checks if inventory slot is already a Poké Ball and sets quantity
            if (isinArray(value, arr_allPokeBalls, sizeof(arr_allPokeBalls))) {
                WRITEU32(offset + itemCount*4, value + (quantity << 10));

                // Adds Poké Ball to array so it will be skipped when end of
                // inventory is reached
                existingPokeBalls[existingIndex] = value;
                existingIndex++;
            }

        // Reached end of inventory
        } else {

            // Iterates through Poké Balls to add
    		for (int i = 0; i < TOTALPOKEBALLS; i++) {

                // Checks if Poké Ball already exists in inventory and adds it if not
                if (!isinArray(arr_allPokeBalls[i], existingPokeBalls, sizeof(existingPokeBalls))) {
                    WRITEU32(offset + itemCount*4, arr_allPokeBalls[i] + (quantity << 10));
                    itemCount++;
                }
    		}

            // Stops checking inventory and exits function after writing the
            // last remaining Poké Balls
    		break;
    	}
    }
}


// Gives all items
void    allItems(void) {
    int i = 0;

    // Start of Item Inventory
    u32    offset = 0x330D5934;

    // Writes the array to inventory overwriting what's already there
    for (i = 0; i < TOTALPOKEBALLS; i++) {
       WRITEU32(offset + i*4, arr_allPokeBalls[i] + (quantity << 10));
    }
    offset += i*4;
    
    for (i = 0; i < TOTALITEMS; i++) {
       WRITEU32(offset + i*4, arr_allItems[i] + (quantity << 10));
    }
    offset += i*4;

    // Writes 10 empty slots at end of inventory to erase duplicates from previous versions of this code
    for (i = 0; i < 10; i++) {
        WRITEU32(offset + i*4, 0x0);
    }
}


// Gives all medicine
void    allMedicine(void) {

    // Start of Medicine Inventory
    u32    offset = 0x330D647C;

    // Writes the array to inventory overwriting what's already there
    for (int i = 0; i < TOTALMEDICINE; i++) {
       WRITEU32(offset + i*4, arr_allMedicine[i] + (quantity << 10));
    }
}

// Gives all TMs
void    allTMs(void) {

    // Start of TM Inventory
    u32    offset = 0x330D62CC;

    // Writes the array to inventory overwriting what's already there
    for (int i = 0; i < TOTALTMS; i++) {
       WRITEU32(offset + i*4, arr_allTMs[i] + (1 << 10));
    }
}


// Gives all Berries
void    allBerries(void) {

    // Start of Berry Inventory
    u32    offset = 0x330D657C;

    // Writes the array to inventory  overwriting what's already there
    for (int i = 0; i < TOTALBERRIES; i++) {
       WRITEU32(offset + i*4, arr_allBerries[i] + (quantity << 10));
    }
}


// Gives all PokeBeans
void    allBeans(void) {
    for (int i = 0; i < 15; i++) {
        WRITEU8(0x33115490 + i, (quantity > 255) ? 0xFF : quantity);
    }
}


// Function to add clothes to inventory
u32		clothesFunction(u32 offset, u8 data, u16 loop_num) {
	for (int i = 0; i < loop_num; i++) {
		WRITEU8(offset, data);
		offset += 0x01;
	}
	return(offset);
}

// All Clothes
void	allClothes(void) {
	u32 offset = 0x33116620;

    //Check if character is male
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

    // Else character is female
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
}
