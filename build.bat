
set VANILA_PATH=%PATH%

set PATH=C:\tools\mingw-w64\i686-8.1.0-posix-dwarf-rt_v6-rev0\mingw32\bin;%VANILA_PATH%

gcc -c mock.c -o mock32.o
gcc -shared -o mock32.dll mock32.o
gcc -c test.c -o test32.o
gcc -o test32.exe test32.o

test32.exe

set PATH=C:\tools\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin;%VANILA_PATH%

gcc -c mock.c -o mock64.o -m64
gcc -shared -o mock64.dll mock64.o -m64
gcc -c test.c -o test64.o -m64
gcc -o test64.exe test64.o -m64

test64.exe

