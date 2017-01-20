#ifndef HOOK_H
#define HOOK_H
#include "configs.h"
#include "types.h"

typedef struct  s_hook
{
    bool        is_initialized;
    bool        is_enabled;
    u32         target_address;
    u32         after_hook_address;
    u32         target_code[2];
    u32         jump_code[2];
}               t_hook;

void    init_hook(t_hook *hook, u32 target_addr, u32 callback_addr);
void    deinit_hook(t_hook *hook);
void    enable_hook(t_hook *hook);
void    disable_hook(t_hook *hook);

#endif
