// Filename: time_modifiers.c

#include "cheats.h"
#include "hid.h"

/********************************
 *                              *
 *       Time Modifiers         *
 *                              *
 ********************************/

char currentTime[40] = "Undefined";


// Time menu entry
void    timeMenu(void) {
    updateTime();
    new_spoiler("Time");
        new_unselectable_entry(currentTime);
        new_separator();
        new_entry_managed("Increase Hour +1", increaseTime, INCREASETIME, AUTO_DISABLE);
        new_entry_managed("Decrease Hour -1", decreaseTime, DECREASETIME, AUTO_DISABLE);
        new_line();
    exit_spoiler();
}


 // Reads current time offset and prints it to the menu
 void	updateTime(void) {
     u32 timeOffset = READU32(0x330D9238);
     char timeType[4] = "NULL";
     int timeHours = 0;

     timeOffset = timeOffset / 3600;

     if (timeOffset == 24) {
        xsprintf(timeType, "Sun");
        timeHours = 0;
     } else if (timeOffset < 12) {
        xsprintf(timeType, "Sun");
        timeHours = timeOffset;
     } else if (timeOffset >= 12) {
        xsprintf(timeType, "Moon");
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

    WRITEU32(0x330D9238, timeOffset * 3600);
    updateTime();
 }


// Decreases time offset by one hour and rolls over if at min
 void   decreaseTime(void) {
    u32 timeOffset = READU32(0x330D9238);
    timeOffset = timeOffset / 3600;

    if (timeOffset == 1)
        timeOffset = 24;
    else
        timeOffset -= 1;

    WRITEU32(0x330D9238, timeOffset * 3600);
    updateTime();
 }
