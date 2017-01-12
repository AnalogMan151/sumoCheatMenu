// Filename: currency_modifiers.c

#include "cheats.h"
#include "hid.h"

/********************************
 *                              *
 *     Currency Modifiers       *
 *                              *
 ********************************/

static u32 quantity = 500000;

// Currency menu entry
void    currencyMenu(void) {
    new_spoiler("Currency");
        new_entry_managed("Increase Quantity +500,000", increaseCurrencyQuantity, INCREASECURRENCYQUANTITY, AUTO_DISABLE);
        new_separator();
        new_entry_managed("Poke Dollars          xCCCCCCC", maxMoney, MAXMONEY, EXECUTE_ONCE);
        new_entry_managed("Battle Points         xCCCCCCC", maxBP, MAXBP, EXECUTE_ONCE);
        new_entry_managed("Festival Coins        xCCCCCCC", maxCoins, MAXCOINS, EXECUTE_ONCE);
        new_entry_managed("Total Festival Coins  xCCCCCCC", totalCoins, TOTALCOINS, EXECUTE_ONCE);
        new_entry_managed("Thumbs Up             xCCCCCCC", totalThumbs, TOTALTHUMBS, EXECUTE_ONCE);
        new_line();
    exit_spoiler();
    updateCurrencyQuantity();
}

// Increases currency quantity by 500,000
void    increaseCurrencyQuantity(void) {
    switch(quantity) {
        case 9999999:
            quantity = 500000;
            break;
        case 9500000:
            quantity = 9999999;
            break;
        default:
            quantity += 500000;
    }
    updateCurrencyQuantity();
}

// Updates currency quantity on menu and limits value for Max BP and Max FC
void    updateCurrencyQuantity(void) {
    char buf[9];

    xsprintf(buf, "x%-7d", quantity);
    replace_pattern("x*******", buf, MAXMONEY);
    replace_pattern("x*******", buf, TOTALCOINS);
    replace_pattern("x*******", buf, TOTALTHUMBS);
    replace_pattern("x*******", (quantity > 9999) ? "x9999   " : buf, MAXBP);
    replace_pattern("x*******", (quantity > 999999) ? "x999999 " : buf, MAXCOINS);
}


// Set Poké Dollars
void	maxMoney(void) {
	WRITEU32(0x330D8FC0, quantity);
}

// Set current Festival Coins to 999,999
void	maxCoins(void) {
    WRITEU32(0x33124D58, (quantity > 999999) ? 0x000F423F : quantity);
}


// Set total Festival Coins and also updates spent amount to match
void	totalCoins(void) {
    u32 current = READU32(0x33124D58);
    u32 total = quantity;
    u32 spent = total - current;
    WRITEU32(0x3313DCE8, spent);
	WRITEU32(0x33124D5C, total);
}


// Set total Thumbs Up for photos
void	totalThumbs(void) {
	WRITEU32(0x33138B8C, quantity);
}


// Set Battle Points
void	maxBP(void) {
        WRITEU16(0x330D90D8, (quantity > 9999) ? 0x0000270F : quantity);
}
