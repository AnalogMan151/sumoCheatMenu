#include "plugin.h"
#include "manager.h"

t_entry_data    g_entry_data[MAX_STORAGE];
int             g_current_data_count = 0;

void    disable_entry(int identifier)
{
    int index;

    index = get_index(identifier);
    if (index != -1)
        disableCheat(index);
}

void    update_status(int state, int identifier)
{
    static const char * const enabled = " [On]";
    static const char * const disabled = " [Off]";

    if (state)
        add_suffix((char *)enabled, identifier);
    else
        add_suffix((char *)disabled, identifier);
}

static  int add_new_entry(char *str, void (*function)(void), int identifier)
{
    int     index;
    char    *buffer;

    if (g_current_data_count >= MAX_STORAGE)
        goto exit;
    buffer = new_entry_name(str);
    index = new_entry(buffer, function);
    push_index(index, identifier);
    g_current_data_count++;
    return (index);
exit:
    return (-1);
}

void    new_entry_note(char *str, const char * const note, void (*function)(void))
{
    int index;

    index = new_entry(str, function);
    set_note((char *)note, index);
}

void    new_entry_index(char *str, void (*function)(void), int identifier)
{
    add_new_entry(str, function, identifier);
}

void    new_entry_index_note(char *str, const char * const note, void (*function)(void), int identifier)
{
    int     index;
    
    index = add_new_entry(str, function, identifier);
    set_note((char *)note, index);
}

void    new_toggle_entry(char *str, void (*function)(void), int identifier)
{
    add_new_entry(str, function, identifier);
    update_status(0, identifier);
}

void    new_toggle_entry_note(char *str, char *note, void (*function)(void), int identifier)
{
    int     index;

    index = add_new_entry(str, function, identifier);
    update_status(0, identifier);
    set_note(note, index);
}
