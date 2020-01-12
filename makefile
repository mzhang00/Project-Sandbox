all: main.o display.o
	gcc -o program main.o display.o -D_REENTRANT -I/usr/include/SDL2 -lSDL2
main.o: main.c
	gcc -c main.c
display.o: display.c
	gcc -c display.c
run:
	./program
clean:
	rm *.o
