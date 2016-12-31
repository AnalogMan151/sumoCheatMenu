#include "cheats.h"
#include "manager.h"
#include <string.h>

extern t_entry_data    g_entry_data[MAX_STORAGE];
extern int             g_current_data_count;

static t_entry_data *find_entry(int identifier)
{
    t_entry_data    *current;
    int             i;

    for (i = 0; i < g_current_data_count; i++)
    {
        current = &g_entry_data[i];
        if (current->identifier == identifier)
            break;
    }
    if (i == g_current_data_count)
        return (NULL);
    return (current);
}

char    *new_entry_name(char  *name)
{
    t_entry_data    *current;
    char            *buffer;

    if (!name || g_current_data_count >= MAX_STORAGE)
        goto error;
    current = &g_entry_data[g_current_data_count];
    memset(current->name, 0, 40);
    memset(current->displayed, 0, 40);
    strncpy(current->name, name, 39);
    buffer = current->displayed;
    strcpy(buffer, name);
    return (buffer);
error:
    return (name);
}

char    *get_base_name(int identifier)
{
    t_entry_data    *current;

    current = find_entry(identifier);
    if (current)
        return (current->name);
    return (NULL);
}

char    *get_displayed_name(int identifier)
{
    t_entry_data    *current;

    current = find_entry(identifier);
    if (current)
        return (current->displayed);
    return (NULL);
}

void    reset_name(int identifier)
{
    t_entry_data    *current;

    current = find_entry(identifier);
    if (current)
        strcpy(current->displayed, current->name);
exit:
    return;
}

void    change_base_name(char *str, int identifier)
{
    t_entry_data    *current;
    int             size;

    current = find_entry(identifier);
    if (!current)
        goto exit;
    memset(current->name, 0, 40);
    memset(current->displayed, 0, 40);
    strncpy(current->name, str, 39);
    strcpy(current->displayed, current->name);
exit:
    return;
}

void    add_suffix(char *suffix, int identifier)
{
    t_entry_data    *current;
    int             size;

    current = find_entry(identifier);
    if (!current)
        goto exit;
    size = strlen(current->name);
    memset(current->displayed, 0, 40);
    strcpy(current->displayed, current->name);
    strncpy(current->displayed + size, suffix, 40 - size);
exit:
    return;
}

void    add_prefix(char *prefix, int identifier)
{
    t_entry_data    *current;
    int             size;

    current = find_entry(identifier);
    if (!current)
        goto exit;
    size = strlen(prefix);
    memset(current->displayed, 0, 40);
    strcpy(current->displayed, prefix);
    strncpy(current->displayed + size, current->name, 40 - size);
exit:
    return;
}
