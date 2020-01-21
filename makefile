all: main.o display.o move.o
	gcc -o program main.o display.o move.o -D_REENTRANT -I/usr/include/SDL2 -lSDL2 -lm
main.o: main.c display.c move.c
	gcc -c main.c
display.o: display.c move.c
	gcc -c display.c
move.o: move.c display.c
	gcc -c move.c
run:
	./program
clean:
	rm *.o
