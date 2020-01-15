#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED

#include <SDL2/SDL.h>
#include <stdio.h>


void move(SDL_Rect * rec, int num);
void up_check(SDL_Rect * rec, int num);
void down_check(SDL_Rect * rec, int num);

#endif
