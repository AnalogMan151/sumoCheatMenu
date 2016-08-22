#ifndef PLUGIN_H
#define PLUGIN_H

#include "types.h"
#include "configs.h"
#include "result.h"
#include "common.h"
#include "hid.h"

#define MAX(x, y) (x > y ? x : y)

#define ABS(x) MAX(x, -x)

u32		plgGetIoBase(u32 IoType);
Handle		getCurrentProcessHandle(void);
u32		getCurrentProcessId(void);
void		onCheatItemChanged(int id);

enum
{
	SLOW = 0,
	NORMAL = 1,
	FAST = 2
};

typedef enum
{
	INFO = BIT(0),
	WARNING = BIT(1),
	DEBUG = BIT(2),
	ERROR = BIT(3)
}				log_type;

typedef union	u_ib
{
	u32			i;
	u8			b[4];
}				t_ib;

/*
** void init_img(void)
** Initialize the graphics components of the plugin
*/
void	init_img(void);

/*
** cheats.c
*/
/* void menu(void)
** Initialize the menu
*/
void	menu(void);

/*
** void set_default_speed(int speed)
** speed: can be SLOW, NORMAL or FAST
** Define the speed of the plugin to the specified mode
*/
void	set_default_speed(int speed);

/*
** u32 get_tid_high(void)
** Return the high value of the current process's title id
*/
u32	get_tid_high(void);

/*
** u32 get_tid_lo(void)
** Return the low value of the current process's title id
*/
u32	get_tid_low(void);

/*
** u8 *get_title_id(void)
** Return a pointer to a string with the full title id value
*/
u8	*get_title_id(void);

/*
** int new_entry(char *text, void (*f)())
** *text: a pointer to the entry's text
** *f: the function you want to execute when the entry is active
** can be NULL
** Return value: the index of the entry in the menu
** Create a new entry in the menu
** If a spoiler is open, the entry will be created in the spoiler
*/
int	new_entry(char *text, void(*f)());

/*
** int new_spoiler(char *text)
** *text:  a pointer to the spoiler's text
** Return value: the index of the spoiler in the menu
** Create a new spoiler and define it as the default location 
** for the nexts new_entry calls
*/
int	new_spoiler(char *text);

/*
** exit_spoiler(void)
** Close a spoiler and redefine the default location of
** the next new_entry call outside of the spoiler
*/
void	exit_spoiler(void);

/*
** int new_radio_entry(char *text, void (*f)())
** *text: a pointer to the entry's text
** *f: the function to execute when the entry is active
** can be NULL
** Return value: the index of the entry in the menu
** Create a new menu entry but with a radio mode:
** Only one radio entry can be activated at a time
** The range of the radio mode is the spoiler range
*/
int	new_radio_entry(char *text, void(*f)());

/*
** int new_unselectable_entry(char *text)
** *text: a pointer to the entry's text
** Return value: the index of the entry
** Create an entry in the menu which can't be selected by the cursor
*/
int	new_unselectable_entry(char *text);

/*
** int new_spearator(void)
** Return value: the index of the entry
** Create a separator in the menu which can't be selected 
*/
int	new_separator(void);

/*
** int new_line(void)
** Return value: the index of the entry
** Create an empty and unselectable entry in the menu
*/
int	new_line(void);

/*
** void set_note(const char *text, int index)
** *text: a pointer to the text note
** index: the index of the entry
** Define the text note printed when pressing Y in the menu
*/
void	set_note(const char *text, int index);

/*
** void disableCheat(int index)
** index: the index of the entry to disable
** Disable an entry
*/
void    disableCheat(int index);
void	new_log(int log_type, char *text, ...);

#endif
