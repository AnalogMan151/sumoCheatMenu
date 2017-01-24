#include "ctrulib.h"


static Handle   srv2Handle;
static int      srvRefCount;

Result srvRegisterClient(void)
{
    Result rc = 0;
    u32* cmdbuf = getThreadCommandBuffer();

    cmdbuf[0] = IPC_MakeHeader(0x1,0,2); // 0x10002
    cmdbuf[1] = IPC_Desc_CurProcessHandle();

    if(R_FAILED(rc = svcSendSyncRequest(srv2Handle)))return rc;

    return cmdbuf[1];
}

Result srvInit(void)
{
    Result rc = 0;

    if (AtomicPostIncrement(&srvRefCount)) return 0;

    rc = svcConnectToPort(&srv2Handle, "srv:");
    if (R_FAILED(rc)) goto end;

    rc = srvRegisterClient();
end:
    if (R_FAILED(rc))
    {
        //new_log(WARNING, "Services Init: FAILED\n");
        srvExit();
    }
    //else new_log(INFO, "Services Init: OK\n");
    return rc;
}

Result srvGetServiceHandle(Handle* out, const char* name)
{
    Result rc = 0;
    u32* cmdbuf = getThreadCommandBuffer();

    cmdbuf[0] = IPC_MakeHeader(0x5,4,0); // 0x50100
    strncpy((char*) &cmdbuf[1], name,8);
    cmdbuf[3] = strlen(name);
    cmdbuf[4] = 0x0;

    if(R_FAILED(rc = svcSendSyncRequest(srv2Handle)))return rc;

    if(out) *out = cmdbuf[3];

    return cmdbuf[1];
}


static Handle acHandle;
static int acRefCount;

Result acInit(void)
{
    Result ret;

    if (AtomicPostIncrement(&acRefCount)) return 0;

    ret = srvGetServiceHandle(&acHandle, "ac:u");
    if(R_FAILED(ret)) ret = srvGetServiceHandle(&acHandle, "ac:i");
    if(R_FAILED(ret)) AtomicDecrement(&acRefCount);

    return ret;
}

Result ACU_GetWifiStatus(u32 *out)
{
    Result ret=0;
    u32 *cmdbuf = getThreadCommandBuffer();

    cmdbuf[0] = IPC_MakeHeader(0xD,0,0); // 0x000D0000

    if(R_FAILED(ret = svcSendSyncRequest(acHandle)))return ret;

    *out = cmdbuf[2];

    return (Result)cmdbuf[1];
}

static inline u32 IPC_Desc_CurProcessHandle(void)
{
    return 0x20;
}

void acExit(void)
{
	if (AtomicDecrement(&acRefCount)) return;
	svcCloseHandle(acHandle);
}

void srvExit(void)
{
    if (AtomicDecrement(&srvRefCount)) return;

    if (srv2Handle != 0) svcCloseHandle(srv2Handle);
    srv2Handle = 0;
}
