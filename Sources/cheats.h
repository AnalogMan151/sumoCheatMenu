#ifndef CHEATS_H
#define CHEATS_H
#include "plugin.h"

int gameVer;
bool battleInfo;

u32 o_islandwait,
    o_qr100;

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
    ALLCLOTHES,
    SETGENDER,
    SETSKINTONE,
    SWITCHLOOKS,
    SHINYPOKEMON,
    MAXBATTLESTATS,
    CATCH100,
    ZMOVES,
    INCREASECURRENCYQUANTITY,
    MAXMONEY,
    MAXBP,
    MAXCOINS,
    TOTALCOINS,
    TOTALTHUMBS,
    INCREASEEXP1,
    INCREASEEXP10,
    INCREASEEXP100,
    WALKTHROUGHWALLS,
    INSTANTEGG,
    INSTANTHATCH,
    ACTIVATESPAWN,
    INCREASEID1,
    INCREASEID10,
    INCREASEID100,
    RANDOMID,
    INCREASELVL1,
    INCREASELVL10,
    PASSTHRULEVEL,
    INCREASETIME,
    DECREASETIME,
    SETFORM,
    CATCHTRAINERS,
    LEARNANYTM,
    RELEARNANYMOVE,
    CAMERAZOOM,
    NOENCOUNTERS,
    VIEWIVEV,
    SHOWOPPONENTINFO,
    DECREASESHINYCHANCE,
    INFZMOVES
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
bool    isinArray(int val, int *arr, int size);
void    memset32(void *dst, unsigned int value, unsigned int size);
void    protect_region(u32 addr);
bool    checkAddress(u32 address);
int     randomNum(int start, int end);
bool    getWifiStatus(void);

// Offsets
void    getVersion(void);

// Pokémon Spawner
void    pokemonSpawnMenu(void);
void    updateSpawn(void);
void    increaseID1(void);
void    increaseID10(void);
void    increaseID100(void);
void    randomID(u32 state);
void    setRandomID(void);
void    increaseLVL1(void);
void    increaseLVL10(void);
void    passthruLevel(u32 state);
void    activateSpawn(u32 state);
void    generateSpawn(void);
void    getForms(u32 id);
void    setForm(void);


// EXP Multipliers
void    expMenu(void);
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
void    fixMakeupBag(void);


// Battle Modifiers
void    battleMenu(void);
void    noEncounters(void);
void    alwaysCritical(void);
void    showOpponentInfo(u32 state);
void    maxBattleStats(u32 state);
void	catch100(void);
void    updateShiny(void);
void    decreaseShinyChance(void);
void	shinyPokemon(void);
void    zMoves(u32 state);
void    infZMoves(void);


// Movement Modifiers
void    movementMenu(void);
void	runFaster(void);
void	neverTrip(void);
void	walkThruWalls(void);


// Pokémon Modifiers
void    pokemonMenu(void);
void	renamePokemon(void);
void	instantEgg(void);
void	instantHatch(u32 state);


// Currency Modifiers
void    currencyMenu(void);
void	maxMoney(void);
void	maxCoins(void);
void	totalCoins(void);
void	totalThumbs(void);
void	maxBP(void);
void    increaseCurrencyQuantity(void);
void    updateCurrencyQuantity(void);


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
void    viewIVEV(void);
void    cameraZoom(void);
void	instantText(void);
void    pcAnywhere(u32 state);
void	rematchTrainers(void);
void	toggleOutlines(u32 state);
void    toggleNFC(u32 state);


// Illegal Cheats
void    illegalMenu(void);
void    catchTrial(void);
void    catchTrainers(void);
void    learnAnyTM(u32 state);
void    relearnAnyMove(u32 state);


void    overlayInit(void);
#endif
