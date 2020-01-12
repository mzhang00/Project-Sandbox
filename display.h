//Using SDL and standard IO
#ifndef DISPLAY_H_INCLUDED
#define DISPLAY_H_INCLUDED
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

#include <SDL2/SDL.h>
#include <stdio.h>
#include <strings.h>
#include <unistd.h>

struct unit {
  int number;
  int health;
  int weapon_id;
  int moves_left;
  int x;
  int y;
};

//The window we'll be rendering to
extern SDL_Window* gWindow;// = NULL;

//The surface contained by the window
extern SDL_Surface* gScreenSurface; //= NULL;

//The image we will load and show on the screen
extern SDL_Surface* gHelloWorld; //= NULL;

extern SDL_Surface* gXOut;
int init();

//Loads media
int loadMedia();

//Frees media and shuts down SDL
void close1();

#endif
