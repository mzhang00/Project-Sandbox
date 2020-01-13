all: main.o display.o move.o
	gcc -o program main.o display.o move.o -D_REENTRANT -I/usr/include/ -lSDL2
main.o: main.c
	gcc -c main.c
display.o: display.c
	gcc -c display.c
move.o: move.c
	gcc -c move.c
run:
	./program
clean:
	rm *.o
