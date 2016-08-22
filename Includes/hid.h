#ifndef MYHID_H
#define MYHID_H

#include "types.h"

#define BIT(x)	(1U << x)
enum
{
	KEY_A = BIT(0),       ///< A
	KEY_B = BIT(1),       ///< B
	KEY_SELECT = BIT(2),       ///< Select
	KEY_START = BIT(3),       ///< Start
	KEY_DRIGHT = BIT(4),       ///< D-Pad Right
	KEY_DLEFT = BIT(5),       ///< D-Pad Left
	KEY_DUP = BIT(6),       ///< D-Pad Up
	KEY_DDOWN = BIT(7),       ///< D-Pad Down
	KEY_R = BIT(8),       ///< R
	KEY_L = BIT(9),       ///< L
	KEY_X = BIT(10),      ///< X
	KEY_Y = BIT(11),      ///< Y
	KEY_ZL = BIT(14),      ///< ZL (New 3DS only)
	KEY_ZR = BIT(15),      ///< ZR (New 3DS only)
	KEY_TOUCH = BIT(20),      ///< Touch (Not actually provided by HID)
	KEY_CSTICK_RIGHT = BIT(24), ///< C-Stick Right (New 3DS only)
	KEY_CSTICK_LEFT = BIT(25), ///< C-Stick Left (New 3DS only)
	KEY_CSTICK_UP = BIT(26), ///< C-Stick Up (New 3DS only)
	KEY_CSTICK_DOWN = BIT(27), ///< C-Stick Down (New 3DS only)
	KEY_CPAD_RIGHT = BIT(28),   ///< Circle Pad Right
	KEY_CPAD_LEFT = BIT(29),   ///< Circle Pad Left
	KEY_CPAD_UP = BIT(30),   ///< Circle Pad Up
	KEY_CPAD_DOWN = BIT(31),   ///< Circle Pad Down

	// Generic catch-all directions
	KEY_UP = KEY_DUP | KEY_CPAD_UP,    ///< D-Pad Up or Circle Pad Up
	KEY_DOWN = KEY_DDOWN | KEY_CPAD_DOWN,  ///< D-Pad Down or Circle Pad Down
	KEY_LEFT = KEY_DLEFT | KEY_CPAD_LEFT,  ///< D-Pad Left or Circle Pad Left
	KEY_RIGHT = KEY_DRIGHT | KEY_CPAD_RIGHT, ///< D-Pad Right or Circle Pad Right
	KEY_CPAD = KEY_CPAD_DOWN | KEY_CPAD_UP | KEY_CPAD_LEFT | KEY_CPAD_RIGHT
};

typedef struct	s_touch
{
	u16	px; ///< Touch X
	u16	py; ///< Touch Y
}		t_touch;

u32	hidKeysDown(void);
t_touch hidTouchPos(void);
void	setHID(u32 keys);

#endif