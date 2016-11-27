#include "cheats.h"

char    statusOutlines[40] = "Value not found";
char	currentEXP[40] = "Value not found";
char    storedGender[40] = "Value not found";
char    storedSkintone[40] = "Value not found";
u8      currentGender;
u8      currentSkintone;

// Index numbers for cheats with notes or disableCheat() commands
int i_increaseEXP;
int i_increaseEXP10;
int i_decreaseEXP;
int i_decreaseEXP10;
int i_resetEXP;
int i_walkThruWalls;
int i_shinyPokemon;
int i_instantEgg;
int i_allItems;
int i_allMedicine;
int i_allTMs;
int i_allBerries;
int i_allClothes;
int i_toggleOutlines;
int i_rematchTrainers;
int i_pcAnywhere;
int i_setGender;
int i_setSkintone;
int i_switchLooks;


void	my_menus(void)
{
	set_hid_address(0x10002000);
	currentGender = READU8(0x330D67D5);
    currentSkintone = READU8(0x330D6824);
    
	updateOutlines();
	exp_x();
	updateEXP();
    updateGender();
    updateSkintone();
	
	new_unselectable_entry("Press Y to see notes (*)");
	new_separator();
	
	new_spoiler("Exp Multiplier");
		new_unselectable_entry(currentEXP);
		i_increaseEXP = new_entry("Increase Exp Rate + 1", increaseEXP);
		i_increaseEXP10 = new_entry("Increase Exp Rate +10", increaseEXP10);
		i_decreaseEXP = new_entry("Decrease Exp Rate - 1", decreaseEXP);
		i_decreaseEXP10 = new_entry("Decrease EXP Rate -10", decreaseEXP10);
		i_resetEXP = new_entry("Reset EXP Rate", resetEXP);
	exit_spoiler();
	
	new_spoiler("Movement Modifiers");
		new_entry("Run Faster", runFaster);
		new_entry("Never Trip", neverTrip);
		i_walkThruWalls = new_entry("Walk Through Walls *", walkThruWalls);
		set_note("Activate = Hold R", i_walkThruWalls);
	exit_spoiler();
	
	new_spoiler("Pokemon Modifiers");
		new_entry("100% Capture Rate", catch100);
		i_shinyPokemon = new_entry("Wild Pokemon Shiny *", shinyPokemon);
		set_note("Enable  = START+L\nDisable = START+R", i_shinyPokemon);
		new_entry("Rename any Pokemon", renamePokemon);
		i_instantEgg = new_entry("Instant Egg from Nursary *", instantEgg);
		set_note("Hold START & talk to Nursary NPC", i_instantEgg);
		new_entry("Instant Egg Hatching", instantHatch);
	exit_spoiler();
	
	new_spoiler("QR Codes");
		new_entry("Remove Island Scan Wait", removeIslandScanWait);
		new_entry("QR Scan Point 100", qrScan100);
	exit_spoiler();
	
	new_spoiler("Currency Manipulators");
		new_entry("Maximum PokeDollars", maxMoney);
		new_entry("Maximum Festival Coins", maxCoins);
		new_entry("Total Festival Coins 9,999,999", totalCoins);
		new_entry("Total Thumbs Up 1,500,000", totalThumbs);
		new_entry("Maximum Battle Points (BP)", maxBP);
	exit_spoiler();
	
	new_spoiler("Items");
        i_allItems = new_entry("All Items    x950", allItems);
		i_allMedicine = new_entry("All Medicine x950", allMedicine);
		i_allBerries = new_entry("All Berries  x950", allBerries);
        i_allTMs = new_entry("All TMs", allTMs);
		i_allClothes = new_entry("All Clothes", allClothes);
	exit_spoiler();
	
	new_spoiler("Misc");
        new_spoiler("Gender & Skin Tone");
            new_unselectable_entry("WARNING: Gender change resets");
            new_unselectable_entry("         clothes & hair");
            new_line();
            i_setGender = new_entry(storedGender, setGender);
            set_note("Open a menu to see change", i_setGender);
            i_setSkintone = new_entry(storedSkintone, setSkintone);
            set_note("Ride Pokemon to see change\nor switch genders", i_setSkintone);
            i_switchLooks = new_entry("Apply Changes", switchLooks);
        exit_spoiler();
		new_entry("Instant Text Speed", instantText);
        i_pcAnywhere = new_entry("Access PC Anywhere *", pcAnywhere);
        set_note("Hold START while opening options menu", i_pcAnywhere);
		i_rematchTrainers = new_entry("Rematch Trainers *", rematchTrainers);
		set_note("Hold L & talk to Trainer", i_rematchTrainers);
		i_toggleOutlines = new_entry(statusOutlines, toggleOutlines);
        set_note("Open a menu to see change", i_toggleOutlines);
	exit_spoiler();

}



