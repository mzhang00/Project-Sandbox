#ifndef MOVE_H_INCLUDED
#define MOVE_H_INCLUDED

#include <SDL2/SDL.h>
#include <stdio.h>

extern int shift;

struct rect{
  int x;
  int y;
  int w;
  int l;
};

void move(SDL_Rect * rec, int num, int scr);
void up_check(SDL_Rect * rec, int num, int scr);
void down_check(SDL_Rect * rec, int num, int scr);
void initializeRect(struct rect * recty, int x, int y, int w, int l);
float calcCenter(int *cX, int *cY, struct rect recty);
int whereRectComaparedToRect(struct rect rect1, struct rect rect2);
int detectBulletIntersectRect(struct rifleGun rifle, SDL_Rect recty);
#endif
