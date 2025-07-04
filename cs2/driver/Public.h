/*++

Module Name:

    public.h

Abstract:

    This module contains the common declarations shared by driver
    and user applications.

Environment:

    user and kernel

--*/

//
// Define an Interface Guid so that apps can find the device and talk to it.
//

DEFINE_GUID (GUID_DEVINTERFACE_driver,
    0x06325b47,0x90d7,0x46dc,0xb2,0xc1,0x02,0x79,0x97,0x21,0xa3,0x81);
// {06325b47-90d7-46dc-b2c1-02799721a381}

#define IOCTL_READ_PROCESS_MEMORY CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)

typedef struct _KERNEL_READ_REQUEST {
    ULONG ProcessId;
    ULONGLONG Address;
    ULONG Size;
    PVOID Buffer; // user-mode land pointer
} KERNEL_READ_REQUEST, *PKERNEL_READ_REQUEST;
