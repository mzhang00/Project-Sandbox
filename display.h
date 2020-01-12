//Using SDL and standard IO
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

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;

//The image we will load and show on the screen
SDL_Surface* gHelloWorld = NULL;

int init();

//Loads media
int loadMedia();

//Frees media and shuts down SDL
void close1();
