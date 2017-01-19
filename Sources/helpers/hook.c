#include "hook.h"
#include <string.h>

static void  generate_jump_code(u32 jump_addr, u32 *jump_code)
{
    jump_code[0] = 0xE51FF004; // LDR   PC, [PC, #-4]
    jump_code[1] = jump_addr;
}

void init_hook(t_hook *hook, u32 target_addr, u32 callback_addr)
{
    if (hook->is_initialized)
        return;
    hook->is_initialized = 1;
    hook->is_enabled = 0;
    hook->target_address = target_addr;
    hook->after_hook_address = target_addr + 8;

    // Backup original code
    memcpy(hook->target_code, (void *)target_addr, 8);
    // Generate jump instruction
    generate_jump_code(callback_addr, hook->jump_code);
}

void    deinit_hook(t_hook *hook)
{
    if (!hook->is_initialized)
        return;
    if (hook->is_enabled)
        disable_hook(hook);
    memset(hook, 0, sizeof(t_hook));
}

void    enable_hook(t_hook *hook)
{
    if (hook->is_enabled || !hook->is_initialized)
        return;
    memcpy((void *)hook->target_address, hook->jump_code, 8);
    hook->is_enabled = 1;
}

void    disable_hook(t_hook *hook)
{
    if (!hook->is_enabled || !hook->is_initialized)
        return;
    memcpy((void *)hook->target_address, hook->target_code, 8);
    hook->is_enabled = 0;
}
