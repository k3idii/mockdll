#include <stdio.h>
#include <windows.h>
#include "bitstr.h"

#define hello_str "DLL: Hello from " bitstr "bit code ! "

// #ifdef BUILD_DLL /* DLL export */
#define EXPORT __declspec(dllexport)
//#else /* EXE import */
//#define EXPORT __declspec(dllimport)
//#endif

EXPORT void hello(void);

//extern "C" BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD Reason, LPVOID LPV) {
//This one was only necessary if you were using a C++ compiler

void message(char* msg){
    puts(msg);
    MessageBoxA(NULL, msg, "Message", MB_OK|MB_ICONINFORMATION);
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {

    switch (fdwReason)
    {
        case DLL_PROCESS_ATTACH:
            // Code to run when the DLL is loaded
        message("DLL: Load working...");
            break;
        case DLL_PROCESS_DETACH:
            // Code to run when the DLL is freed
        message("DLL: Unload working...");
            break;
        case DLL_THREAD_ATTACH:
            // Code to run when a thread is created during the DLL's lifetime
        message("DLL: ThreadLoad working...");
            break;
        case DLL_THREAD_DETACH:
            // Code to run when a thread ends normally.
        message("DLL: ThreadUnload working...");
            break;
    }
    return TRUE;
}   

EXPORT void hello(void) {
    message(hello_str);
}