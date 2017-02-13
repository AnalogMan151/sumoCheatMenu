#ifndef SHARED_FUNC_H
#define SHARED_FUNC_H

#if IS_PLUGIN
#define INIT_SHARED_FUNC(name,id) rtGenerateJumpCode(((NS_CONFIG*)(NS_CONFIGURE_ADDR))->sharedFunc[id], (void*) name);rtFlushInstructionCache((void*) name, 8);
#else
#define INIT_SHARED_FUNC(name,id) (g_nsConfig->sharedFunc[id] = (u32) name)
#endif


void initSharedFunc();

/* register a entry for NTR Menu */
u32 plgRegisterMenuEntry(u32 catalog, char* title, void* callback) ;
#define CATALOG_MAIN_MENU	1

/* get a shared service's handle ie. fs:USER */
u32 plgGetSharedServiceHandle(char* servName, u32* handle);
/* request a memory block */
u32 plgRequestMemory(u32 size);
/* not implemented */
u32 plgRegisterCallback(u32 type, void* callback, u32 param0);

/* xsprintf(buf, fmt, v1, v2); showMsg(buf) */
void showDbg(u8* fmt, u32 v1, u32 v2);
/* send debug print to the NTR Debugger */
void nsDbgPrint (const char*	fmt,	...	);

/* control the direct video access */
u32 controlVideo(u32 cmd, u32 arg1, u32 arg2, u32 arg3);
#define CONTROLVIDEO_ACQUIREVIDEO 1
#define CONTROLVIDEO_RELEASEVIDEO 2
#define CONTROLVIDEO_GETFRAMEBUFFER 3
#define CONTROLVIDEO_SETFRAMEBUFFER 4
#define CONTROLVIDEO_UPDATESCREEN 5

/* get the base address of specified IO Type */
u32 plgGetIoBase(u32 IoType);
#define IO_BASE_PAD		1
#define IO_BASE_LCD		2
#define IO_BASE_PDC		3
#define IO_BASE_GSPHEAP		4

#endif