#ifndef MANAGER_H
#define MANAGER_H

#include "plugin.h"

// The menu can handle a maximum of 300 entries
#define MAX_STORAGE    100

typedef struct  s_entry_data
{
    char        name[40];
    char        displayed[40];
    int         identifier;
    int         index;
}               t_entry_data;

/*
** index_manager.c
*/
void    push_index(int index, int identifier);
int     get_index(int identifier);

/*
** entry_name_manager.c
*/
char    *new_entry_name(char  *name);
char    *get_base_name(int identifier);
char    *get_displayed_name(int identifier);
void    reset_name(int identifier);
void    change_base_name(char *str, int identifier);
void    add_suffix(char *suffix, int identifier);
void    add_prefix(char *prefix, int identifier);


#endif
