# compiler
CC = g++
# for building main program as linkable 
# dlopen, dlclose, dlsym ...  <dlfcn.h>
LINKABLE = -ldl


all: superman examples superman_exec

superman: main.o
	$(CC) $(LINKABLE) main.o -o superman

main.o:
	$(CC) -c main.cpp -o main.o


superman_exec:
	mv superman build/superman


clean: 
	rm *.o 
