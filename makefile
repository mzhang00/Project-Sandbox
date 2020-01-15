all: main.o display.o move.o
	gcc -g -o program main.o display.o move.o -D_REENTRANT -I/usr/include/SDL2 -lSDL2
main.o: main.c
	gcc -g -c main.c
display.o: display.c
	gcc -g -c display.c
move.o: move.c
	gcc -g -c move.c
run:
	./program
clean:
	rm *.o
