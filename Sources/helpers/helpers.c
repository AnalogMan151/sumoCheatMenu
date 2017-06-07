#include "cheats.h"
#include "manager.h"
#include "ctrulib.h"
#include <stdlib.h>

t_entry_data    g_entry_data[MAX_STORAGE] = {0};
int             g_current_data_count = 0;

void    disable_entry(int identifier)
{
    int index;

    index = get_index(identifier);
    if (index != -1)
        disableCheat(index);
}

void    memset32(void *dst, unsigned int value, unsigned int size)
{
    unsigned int    *p = (unsigned int *)dst;
    unsigned int    s = size / 4;

    while (s-- > 0)
        *p++ = value;
}

Handle        getCurrentProcessHandle(void);

bool    checkAddress(u32 address) {
    Result         res;
    PageInfo    pInfo = {0};
    MemInfo        mInfo = {0};

    res = svcQueryMemory(&mInfo, &pInfo, address);
    if (R_SUCCEEDED(res) && mInfo.base_addr <= address && mInfo.base_addr + mInfo.size > address) {
        if (!(mInfo.perm & MEMPERM_WRITE)) {
            res = svcControlProcessMemory(getCurrentProcessHandle(), mInfo.base_addr, mInfo.base_addr, mInfo.size, 6, 7);
            if (R_SUCCEEDED(res))
                return true;
            else
                return false;
        }
        return true;
    }
    return false;
}

int    randomNum(int start, int end) {
    srand(svcGetSystemTick());
    int r[20];
    for (int i = 0; i < 20; i++) {
        r[i] = rand()%(end - start + 1) + start;
    }
    return r[rand()%20];
}

bool    isinArray(int val, const int *arr, int size) {
    for (int i = 0; i < (size / 4); i++) {
        if (arr[i] == val)
            return true;
    }
    return false;
}


bool getWifiStatus()
{
    Result r = 0;
    u32 wifiStatus = 0;
    static bool wifiInit = false;

    if (!wifiInit) {
        r = srvInit();
    	if (R_FAILED(r)) return false;

        r = acInit();
    	if (R_FAILED(r)) return false;

        wifiInit = true;
    }

    if (wifiInit) {
    	r = ACU_GetWifiStatus(&wifiStatus);
    	if (R_FAILED(r)) return false;

        if (wifiStatus == 1 || wifiStatus == 2)
    	    return true;
        else
            return false;
    }
    return false;
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
