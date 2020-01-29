#include <windows.h>
#include <stdio.h>
#include "bitstr.h"

#define dll_file "mock" bitstr  ".dll"
#define motd "LOADER" bitstr ": Hello, i will load : " dll_file " ... "

/*  based on https://stackoverflow.com/questions/6431345/how-to-specify-dll-onload-function-for-mingw32  */
int main () {

    /*Typedef the hello function*/
    typedef void (*pfunc)();

    /*Windows handle*/
    HANDLE hdll;

    /*A pointer to a function*/
    pfunc hello;

    /*LoadLibrary*/
    puts(motd);
    hdll = LoadLibrary(dll_file);

    /*GetProcAddress*/
    hello = (pfunc)GetProcAddress(hdll, "hello");

    /*Call the function*/
    hello();
    return 0;
}