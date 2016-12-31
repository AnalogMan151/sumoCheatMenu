#ifndef CHEATS_H
#define CHEATS_H
#include "plugin.h"

typedef enum
{
    EXECUTE_ONCE = BIT(0),
    EXECUTED = BIT(1),
    TOGGLE = BIT(2),
    TOGGLE_ENABLE = BIT(3),
    AUTO_DISABLE = BIT(4)
}               entry_flags;

enum {
    TOGGLEOUTLINES,
    REMATCHTRAINERS,
    PCANYWHERE,
    TOGGLENFC,
    INCREASEQUANTITY,
    ALLPOKEBALLS,
    ALLITEMS,
    ALLMEDICINE,
    ALLTMS,
    ALLBERRIES,
    ALLBEANS,
    ALLCLOTHES
} e_identifiers;

// Helpers

void    disable_entry(int identifier);
void    update_status(int state, int identifier);
void    new_entry_note(char *str, const char * const note, void (*function)(void));
void    new_entry_managed(char *str, void (*function)(void), int identifier, int flags);
void    new_entry_managed_note(char *str, const char * const note, void (*function)(void), int identifier, int flags);
void    new_entry_arg(char *name, void (*function)(u32), u32 arg, int identifier, int flags);
void    new_entry_arg_note(char *name, char *note, void (*function)(u32), u32 arg, int identifier, int flags);
void    new_super_unselectable_entry(char *str, void (*f)());
void    execute_all(void);
void    replace_pattern(char *pattern, char *replace_str, int identifier);
void    add_prefix(char *prefix, int identifier);
void    add_suffix(char *suffix, int identifier);
void    xsprintf(char *dst, char *fmt, ...);


// Pokémon Spawner
void    pokemonSpawnMenu(void);
void    updateSpawn(void);
void    increaseID1(void);
void    increaseID10(void);
void    increaseID100(void);
void    increaseLVL1(void);
void    increaseLVL10(void);
void    activateSpawn(void);


// EXP Multipliers
void    expMenu(void);
void	exp_x(void);
void	updateEXP(void);
void	increaseEXP1(void);
void	increaseEXP10(void);
void	increaseEXP100(void);


// Time Modifiers
void    timeMenu(void);
void    updateTime(void);
void    increaseTime(void);
void    decreaseTime(void);


// Appearance Modifeirs
void    appearanceMenu(void);
void    switchLooks(void);
void    setGender(void);
void    updateGender(void);
void    setSkintone(void);
void    updateSkintone(void);


// Battle Modifiers
void    battleMenu(void);
void    alolaRat(void);
void    updateBattleStats(void);
void    maxBattleStats(void);
void	catch100(void);
void	shinyPokemon(void);
void    zMoves(void);
void    updateZMove(void);
void    updateShiny(void);


// Movement Modifiers
void    movementMenu(void);
void	runFaster(void);
void	neverTrip(void);
void	walkThruWalls(void);


// Pokémon Modifiers
void    pokemonMenu(void);
void	renamePokemon(void);
void	instantEgg(void);
void	instantHatch(void);


// Currency Modifiers
void    currencyMenu(void);
void	maxMoney(void);
void	maxCoins(void);
void	totalCoins(void);
void	totalThumbs(void);
void	maxBP(void);


// Item Modifiers
void    itemMenu(void);
void    updateQuantity(void);
void    increaseQuantity(void);
void    allPokeBalls(void);
void    allItems(void);
void	allMedicine(void);
void    allTMs(void);
void	allBerries(void);
void    allBeans(void);
u32		clothesFunction(u32 offset, u8 data, u16 loop_num);
void	allClothes(void);


// QR Codes
void    qrMenu(void);
void	removeIslandScanWait(void);
void	qrScan100(void);


// Misc
void    miscMenu(void);
void	instantText(void);
void    pcAnywhere(void);
void	rematchTrainers(void);
void	toggleOutlines(void);
void	updateOutlines(void);
void    toggleNFC(void);
void    updateNFC(void);


#endif
