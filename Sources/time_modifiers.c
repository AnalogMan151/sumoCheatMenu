// Filename: time_modifiers.c

#include "cheats.h"
#include "hid.h"

/********************************
 *                              *
 *       Time Modifiers         *
 *                              *
 ********************************/

 // Reads current time offset and prints it to the menu
 void	updateTime(void) {
     u32 timeOffset = READU32(0x330D9238);
     char timeType[4] = "NULL";
     int timeHours = 0;

     timeOffset = timeOffset / 3600;

     if (timeOffset == 24) {
        strcpy(timeType, "Sun");
        timeHours = 0;
     } else if (timeOffset < 12) {
        strcpy(timeType, "Sun");
        timeHours = timeOffset;
     } else if (timeOffset >= 12) {
        strcpy(timeType, "Moon");
        timeHours = timeOffset - 12;
     }

     xsprintf(currentTime, "Current: %4s Time +%-2d hours", timeType, timeHours);
 }


// Increases time offset by one hour and rolls over if at max
 void   increaseTime(void) {
    u32 timeOffset = READU32(0x330D9238);
    timeOffset = timeOffset / 3600;

    if (timeOffset == 24)
        timeOffset = 1;
    else
        timeOffset += 1;

    timeOffset = timeOffset * 3600;

    WRITEU32(0x330D9238, timeOffset);
    updateTime();
    disableCheat(i_increaseTime);
 }


// Decreases time offset by one hour and rolls over if at min
 void   decreaseTime(void) {
    u32 timeOffset = READU32(0x330D9238);
    timeOffset = timeOffset / 3600;

    if (timeOffset == 1)
        timeOffset = 24;
    else
        timeOffset -= 1;

    timeOffset = timeOffset * 3600;

    WRITEU32(0x330D9238, timeOffset);
    updateTime();
    disableCheat(i_decreaseTime);
 }
