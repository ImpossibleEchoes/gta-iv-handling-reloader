// dllmain.cpp : Defines the entry point for the DLL application.
#include <Windows.h>

#include "addrs.h"
#include "handling.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        if(initAddrsDynamicAll())
            MessageBoxA(nullptr, "bad version", nullptr, 0x10);

        initHandlingReloader();

        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

