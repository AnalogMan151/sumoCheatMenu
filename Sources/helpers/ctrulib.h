#ifndef CTRULIB_H
#define CTRULIB_H

#include "types.h"
#include "result.h"
#include "svc.h"
#include <sys/lock.h>

typedef u32     Handle;
typedef s32     Result;

static inline u32 IPC_MakeHeader(u16 command_id, unsigned normal_params, unsigned translate_params)
{
    return ((u32) command_id << 16) | (((u32) normal_params & 0x3F) << 6) | (((u32) translate_params & 0x3F) << 0);
}

/// Performs an atomic pre-increment operation.
#define AtomicIncrement(ptr) __atomic_add_fetch((u32*)(ptr), 1, __ATOMIC_SEQ_CST)
/// Performs an atomic pre-decrement operation.
#define AtomicDecrement(ptr) __atomic_sub_fetch((u32*)(ptr), 1, __ATOMIC_SEQ_CST)
/// Performs an atomic post-increment operation.
#define AtomicPostIncrement(ptr) __atomic_fetch_add((u32*)(ptr), 1, __ATOMIC_SEQ_CST)
/// Performs an atomic post-decrement operation.
#define AtomicPostDecrement(ptr) __atomic_fetch_sub((u32*)(ptr), 1, __ATOMIC_SEQ_CST)

Result srvInit(void);
Result acInit(void);
Result ACU_GetWifiStatus(u32 *out);
static inline u32 IPC_Desc_CurProcessHandle(void);
void srvExit(void);
Result srvGetServiceHandle(Handle* out, const char* name);
void acExit(void);
#endif
