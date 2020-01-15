#include "move.h"

void move(SDL_Rect * rec, int num) {
  int x = rec[num].x;
  int y = rec[num].y;
  if (x > 0 && x < 24){
    if (y == 210) rec[num].y = 234;
    else if (y != 234) rec[num].y = 284;
  }
  else if (x > 24 && x < 42){
    if (y == 234 || y == 194) rec[num].y = 210;
    else if (y != 210) rec[num].y = 284;
  }
  else if (x > 42 && x < 109){
    if (y == 210 || y == 214) rec[num].y = 194;
    else if (y != 194) rec[num].y = 284;
  }
  else if (x > 109 && x < 126){
    if (y == 234 || y == 194) rec[num].y = 214;
    else if (y != 214) rec[num].y = 284;
  }
  else if (x > 126 && x < 174){
    if (y == 214 || (y == 174 && x < 150)) rec[num].y = 234;
    else if (y != 174 && y != 234) rec[num].y = 284;
  }
  else if (x > 174 && x < 288){
    if (y == 234 || y == 264) rec[num].y = 284;
    else if (y != 284) rec[num].y = 174;
  }
  else if (x > 288 && x < 321){
    if (y == 230) rec[num].y = 264;
    else if (y != 174 && y != 264) rec[num].y = 284;
  }
  else if (x > 321 && x < 345){
    if (y == 264 || y == 174) rec[num].y = 230;
    else if (y != 230) rec[num].y = 284;
  }
  else if (x > 345 && x < 384){
    if (y == 230 || (y == 196 && x < 366)) rec[num].y = 264;
    else if (y != 196 && y != 264) rec[num].y = 284;
  }
  else if (x > 384 && x < 459){
    if (y == 264 || (y == 196 && x > 417) || (y == 170 && x < 438) || y == 295) rec[num].y = 284;
    else if (y != 196 && y != 170) rec[num].y = 284;
  }
  else if (x > 459 && x < 498){
    if (y == 284) rec[num].y = 295;
    else if (y != 295) rec[num].y = 170;
  }
  else if (x > 537 && x < 576){
    if (y == 284) rec[num].y = 295;
    else if (y != 295) rec[num].y = 170;
  }
  else if (x > 576 && x < 640){
    if (y == 170 || y == 295 || (y == 175 && x < 603)) rec[num].y = 284;
    else if (y != 284) rec[num].y = 175;
  }
}
