#ifndef CHEATS_H
#define CHEATS_H
#include "plugin.h"

void	exp_x(void);
void	updateEXP(void);
void	increaseEXP(void);
void	increaseEXP10(void);
void	decreaseEXP(void);
void	decreaseEXP10(void);
void	resetEXP(void);

void	runFaster(void);
void	neverTrip(void);
void	walkThruWalls(void);

void	catch100(void);
void	shinyPokemon(void);
void	renamePokemon(void);
void	instantEgg(void);
void	instantHatch(void);

void	removeIslandScanWait(void);
void	qrScan100(void);

void	maxMoney(void);
void	maxCoins(void);
void	totalCoins(void);
void	totalThumbs(void);
void	maxBP(void);

void    allItems(void);
void	allMedicine(void);
void	allBerries(void);
u32		clothesFunction(u32 offset, u8 data, u32 loop_num);
void	allClothesMale(void);
void	allClothesFemale(void);

void	instantText(void);
void    pcAnywhere(void);
void	rematchTrainers(void);
void	toggleOutlines(void);
void	updateOutlines(void);

#endif
