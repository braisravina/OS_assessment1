cc=gcc
cflags= -c -WALL
lflags= -o


all: shell

shell: mymemory.o shell.o
        $(cc) $(lflags) shell mymemory.o shell.o

mymemory.o: mymemory.c mymemory.h
		$(cc) $(cflags) mymemory.c

shell.o: shell.c mymemory.h
		$(cc) $(cflags) shell.c

clean:
		rm -f mymemory
		rm -f *.o