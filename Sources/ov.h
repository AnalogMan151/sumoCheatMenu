#ifndef OV_H
#define OV_H

void    OvSettings(u32 addr, u32 addrB, u32 stride, u32 format, int isTop);
void    OvDrawTranspartBlackRect(int posX, int posY, int width, int height, u8 level);
void    OvDrawRect(int posX, int posY, int width, int height, u32 r, u32 g, u32 b);
void    OvDrawChar(char letter, int posX, int posY, u32 r, u32 g, u32 b);
int     OvDrawString(char *str, int posX, int posY, u32 r, u32 g, u32 b);
int     OvDrawStringTiny(char *str, int posX, int posY, u32 r, u32 g, u32 b);

#endif