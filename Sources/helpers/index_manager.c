#include "manager.h"

extern t_entry_data    g_entry_data[MAX_STORAGE];
extern int             g_current_data_count;

void    push_index(int index, int identifier)
{
    t_entry_data *current;

    current = &g_entry_data[g_current_data_count];
    current->index = index;
    current->identifier = identifier;
}

int     get_index(int identifier)
{
    t_entry_data    *current;
    int             i;

    for (i = 0; i < g_current_data_count; i++)
    {
        current = &g_entry_data[i];
        if (current->identifier == identifier)
            return (current->index);
    }
    return (-1);
}
