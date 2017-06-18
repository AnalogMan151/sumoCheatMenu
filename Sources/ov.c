#include "global.h"
#include "font_mini_4x6.h"
#include "font6x10Linux.h"
#include "pokeutil/symbols.h"
#include "ov.h"

static u32  g_lframebuf;
static u32  g_rframebuf;
static u32  g_stride;
static u32  g_format;
static u32  g_isTop;
static u32  g_maxWidth;
static u32  g_is3DEnabled;

void    OvSettings(u32 addr, u32 addrB, u32 stride, u32 format, int isTop)
{
    g_lframebuf = addr;
    g_rframebuf = addrB;
    g_stride = stride;
    g_format = format & 0xF;
    g_isTop = isTop;
    g_maxWidth = isTop ? 400 : 320;
    g_is3DEnabled = *(float *)(0x1FF81080) > 0.f && isTop && addr != addrB && addrB;
}

void    OvDrawTranspartBlackRect(int posX, int posY, int width, int height, u8 level)
{
    static int mode3D = 0;

    if (g_is3DEnabled && mode3D == 0)
    {
        mode3D = 1;
        OvDrawTranspartBlackRect(posX - 5, posY, width, height, level);
        mode3D = 0;
    }

    u32  addr = mode3D ? g_rframebuf : g_lframebuf;

    for (int posC = posX; posC < posX + width; posC++)
    {
        if (g_format == 2)
        {
            u16* sp = (u16*)(addr + g_stride * posC + 240 * 2 - 2 * (posY + height - 1));
            u16* spEnd = sp + height;
            while (sp < spEnd)
            {
                u16 pix = *sp;
                u16 r = (pix >> 11) & 0x1f;
                u16 g = (pix >> 5) & 0x3f;
                u16 b = (pix & 0x1f);
                pix = ((r >> level) << 11) | ((g >> level) << 5) | (b >> level);
                *sp = pix;
                sp++;
            }
        }
        else if (g_format == 1)
        {
            u8* sp = (u8*)(addr + g_stride * posC + 240 * 3 - 3 * (posY + height - 1));
            u8* spEnd = sp +  3 * height;
            while (sp < spEnd)
            {
                sp[0] >>= level;
                sp[1] >>= level;
                sp[2] >>= level;
                sp += 3;
            }
        }
    }
}

static inline void OvDrawPixel(u32 addr, int posX, int posY, u32 r, u32 g, u32 b)
{
    if (g_format == 2)
    {
        u16 pix = ((r ) << 11) | ((g ) << 5) | (b );
        *(u16*)(addr + g_stride * posX + 240 * 2 -2 * posY) = pix;
    }
    else
    {
        u8* sp = (u8*)(addr + g_stride * posX + 240 * 3 - 3 * posY);
        sp[0] = b;
        sp[1] = g;
        sp[2] = r;
    }
}

// DRAW POKEBALL FROM PIXEL ARRAY
void OvDrawPokeball(u32 colOffset, u32 yOffset, u32 BALL[]){
	static int mode3D = 0;
	u32 addr = mode3D ? g_rframebuf : g_lframebuf;

    u32 color = 0xFFFFFF;
    int x = 0;
    int y = 0;
    for(int i = 0; i < 576; i++){
        // beastball()
        color = BALL[i];
        if(i % 24 == 0){
            y++;
        }
        x = i % 24;
        if(color != 0xFF00FF){
            // ovDrawPixel(addr, stride, format, yOffset + y, colOffset + x, (color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF);
			OvDrawPixel(addr, colOffset + x, yOffset + y, (color >> 16) & 0xFF, (color >> 8) & 0xFF, color & 0xFF);
        }
    }
}

void    OvDrawRect(int posX, int posY, int width, int height, u32 r, u32 g, u32 b)
{
    static int mode3D = 0;

    if (g_is3DEnabled && mode3D == 0)
    {
        mode3D = 1;
        OvDrawRect(posX - 5, posY, width, height, r, g, b);
        mode3D = 0;
    }

    u32  addr = mode3D ? g_rframebuf : g_lframebuf;

    for (int x = posX; x < posX + width; x++)
    {
        for (int y = posY; y < posY + height; y++)
        {
            OvDrawPixel(addr, x, y, r, g, b);
        }
    }
}

void    OvDrawChar(char letter, int posX, int posY, u32 r, u32 g, u32 b)
{

    static int mode3D = 0;

    if (g_is3DEnabled && mode3D == 0)
    {
        mode3D = 1;
        OvDrawChar(letter, posX - 5, posY, r, g, b);
        mode3D = 0;
    }

    u32  addr = mode3D ? g_rframebuf : g_lframebuf;

    if ((letter < 32) || (letter > (127 + 10)))
    {
        letter = '?';
    }

    int c = letter * 10;

    for (int y = 0; y < 10; y++)
    {
        u8 l = font[y + c];
        int xx = posX;
        for (int x = 8; x >= 0; x--, xx++)
        {
            if ((l >> x) & 1)
                OvDrawPixel(addr, xx, posY + y, r, g, b);
        }
    }
}


void OvDrawSymbol(char letter, int posX, int posY, u32 r, u32 g, u32 b)
{

    static int mode3D = 0;

    if (g_is3DEnabled && mode3D == 0)
    {
        mode3D = 1;
        OvDrawChar(letter, posX - 5, posY, r, g, b);
        mode3D = 0;
    }

    u32  addr = mode3D ? g_rframebuf : g_lframebuf;

    int c = letter * 24;

    for (int y = 0; y < 24; y++)
    {
        int ry = posY + (y / 2);
        int my = y % 2;
        u8 l = symbols[y + c];
        for (int x = 8; x > 0; x--)
        {
            int rx = my == 0 ? posX + x - 1 : posX + x + 7;
            // if(!(my == 1 && rx > 16)){
            // }
            int pix = (l >> (8 - x)) & 0x1;
            if(pix){
                OvDrawPixel(addr, rx, ry, r, g, b);
            }else{
                // OvDrawPixel(addr, rx, ry, 255, 0, 255);
            }
        }
    }
}

int     OvDrawString(char *str, int posX, int posY, u32 r, u32 g, u32 b)
{
    while(*str)
    {
        if ((posY + 6 > 240) || (posX + 6 > g_maxWidth))
        {
            break;
        }

        OvDrawChar(*str, posX, posY, r, g, b);
        str++;
        posX += 6;
    }
    return (posY + 10);
}

void    OvDrawCharTiny(char letter, int posX, int posY, u32 r, u32 g, u32 b)
{

    static int mode3D = 0;

    if (g_is3DEnabled && mode3D == 0)
    {
        mode3D = 1;
        OvDrawCharTiny(letter, posX - 5, posY, r, g, b);
        mode3D = 0;
    }

    u32  addr = mode3D ? g_rframebuf : g_lframebuf;

    if ((letter < 32) || (letter > 127))
    {
        letter = '?';
    }

    int c = (letter) * 6;

    for (int y = 0; y < 6; y++)
    {
        u8 l = fontdata_mini_4x6[y + c];
        int xx = posX;
        for (int x = 3; x >= 0; x--, xx++)
        {
            if ((l >> x) & 1)
                OvDrawPixel(addr, xx, posY + y, r, g, b);
        }
    }
}

int     OvDrawStringTiny(char *str, int posX, int posY, u32 r, u32 g, u32 b)
{
    while(*str)
    {
        if ((posY + 4 > 240) || (posX + 4 > g_maxWidth))
        {
            break;
        }

        OvDrawCharTiny(*str, posX, posY, r, g, b);
        str++;
        posX += 4;
    }
    return (posY + 7);
}
