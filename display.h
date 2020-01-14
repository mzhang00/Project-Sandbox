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
int init();

//Loads media
int loadMedia();

//Frees media and shuts down SDL
void close1(SDL_Renderer * rend,SDL_Texture * tex, SDL_Window * win);

void render(SDL_Renderer* rend, SDL_Texture * tex, SDL_Rect *rect,SDL_Texture * tex2, SDL_Rect *rect2, SDL_Texture * tex3, SDL_Rect * rect3);
void clear(SDL_Renderer * renderer);

#endif
