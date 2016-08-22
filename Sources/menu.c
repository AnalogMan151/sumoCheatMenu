#include "cheats.h"
#include "notes.h"
#include <string.h>

void	my_menus(void)
{
	int index;
	int i;
	
	set_hid_address(0x10002000);

	new_spoiler("Item Codes");
		new_entry("Except Sharpness + 2", exceptSharpness);
		new_entry("Code 2", code2);
	exit_spoiler();

	for (i = 2; i <= index; i++)
		set_note(notes[i - 2], i);
}



