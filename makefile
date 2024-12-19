all: memmemtest.exe memmemtest

memmemtest: memmemtest.c
	gcc memmemtest.c -o memmemtest

memmemtest.exe: memmem.c memmem.h memmemtest.c
	x86_64-w64-mingw32-gcc memmem.c memmemtest.c -o memmemtest

clean:
	rm -rf memmemtest memmemtest.exe

