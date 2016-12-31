#include "cheats.h"
#include "manager.h"

t_entry_data    g_entry_data[MAX_STORAGE] = {0};
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

static  int add_new_entry(char *str, void (*function)(void), int identifier, int flags)
{
    int     index;
    char    *buffer;

    if (g_current_data_count >= MAX_STORAGE) goto exit;

    buffer = new_entry_name(str);
    index = new_entry(buffer, function);
    push_index(index, identifier);
    g_entry_data[g_current_data_count].f = NULL;
    g_entry_data[g_current_data_count].arg = 0;
    g_entry_data[g_current_data_count].flags = flags;
    g_current_data_count++;

    return (index);
exit:
    return (-1);
}

static  int add_new_entry_arg(char *str, void (*function)(u32), u32 arg, int identifier, int flags)
{
    int     index;
    char    *buffer;

    if (g_current_data_count >= MAX_STORAGE) goto exit;

    buffer = new_entry_name(str);
    index = new_entry(buffer, NULL);
    push_index(index, identifier);
    g_entry_data[g_current_data_count].f = function;
    g_entry_data[g_current_data_count].arg = arg;
    g_entry_data[g_current_data_count].flags = flags;
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

void    new_entry_managed(char *str, void (*function)(void), int identifier, int flags)
{
    add_new_entry(str, function, identifier, flags);
}

void    new_entry_managed_note(char *str, const char * const note, void (*function)(void), int identifier, int flags)
{
    int     index;

    index = add_new_entry(str, function, identifier, flags);
    set_note((char *)note, index);
}

void    new_entry_arg(char *name, void (*function)(u32), u32 arg, int identifier, int flags)
{
    add_new_entry_arg(name, function, arg, identifier, flags);
}

void    new_entry_arg_note(char *name, char *note, void (*function)(u32), u32 arg, int identifier, int flags)
{
    int index;

    index = add_new_entry_arg(name, function, arg, identifier, flags);
    set_note(note, index);
}

extern  t_menu  menu;

void    new_super_unselectable_entry(char *str, void (*f)())
{
    int index;

    index = new_unselectable_entry(str);
    if (index == 0)
        index = 2;
    if (index >= menu.count) return;
    menu.flags[index] |= STATE;
    menu.flags[index] |= FREEZE;
    menu.f[index] = f;
}

void    execute_all(void)
{
    int i;
    int index;

    for (i = 0; i < g_current_data_count; i++)
    {
        index = g_entry_data[i].index;
        u32 flags = g_entry_data[i].flags;

        if (index > 2 && index < menu.count)
        {
            if (flags & TOGGLE)
            {
                if ((menu.flags[index] & STATE) && !(flags & TOGGLE_ENABLE))
                {
                    g_entry_data[i].flags |= TOGGLE_ENABLE;
                    if (g_entry_data[i].f != NULL)
                    {
                        g_entry_data[i].f(1);
                    }
                }
                else if (!(menu.flags[index] & STATE) && (flags & TOGGLE_ENABLE))
                {
                   g_entry_data[i].flags &= ~(flags & TOGGLE_ENABLE);
                    if (g_entry_data[i].f != NULL)
                    {
                        g_entry_data[i].f(0);
                    }
                }
            }
            else if(menu.flags[index] & STATE)
            {
                if (flags & EXECUTE_ONCE)
                {
                    if (flags & EXECUTED)
                    {
                        g_entry_data[i].flags &= ~(flags & EXECUTED);
                        menu.flags[index] &= ~(menu.flags[index] & STATE);
                    }
                    else
                    {
                        g_entry_data[i].flags |= EXECUTED;
                        if (g_entry_data[i].f != NULL)
                            g_entry_data[i].f(g_entry_data[i].arg);
                        else
                            menu.f[index]();
                    }
                }
                else if (flags & AUTO_DISABLE)
                {
                    if (g_entry_data[i].f != NULL)
                    {
                        g_entry_data[i].f(g_entry_data[i].arg);
                    }
                    else
                        menu.f[index]();
                    menu.flags[index] &= ~(menu.flags[index] & STATE);

                }
                else if (g_entry_data[i].f != NULL)
                {
                    g_entry_data[i].f(g_entry_data[i].arg);
                }
            }
        }
    }
}

void    disable_once_only(void)
{
    int i;
    int index;

    for (i = 0; i < g_current_data_count; i++)
    {
        if (!(g_entry_data[i].flags & EXECUTE_ONCE))
            continue;
        index = g_entry_data[i].index;

        if (index > 2 && index < menu.count)
        {
            menu.flags[index] &= ~(menu.flags[index] & STATE);
        }
    }
}
