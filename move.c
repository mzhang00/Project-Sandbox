#include "move.h"
struct rect{
  int x;
  int y;
  int w;
  int l;
};
void move(SDL_Rect * rec, int num) {
  int x = rec[num].x;
  int y = rec[num].y;
  if (x >= 0 && x <= 24){
    if (y == 210) rec[num].y = 234;
    else if (y != 234) rec[num].y = 284;
  }
  else if (x >= 24 && x <= 42){
    if (y == 234 || y == 194) rec[num].y = 210;
    else if (y != 210) rec[num].y = 284;
  }
  else if (x >= 42 && x <= 109){
    if (y == 210 || y == 214) rec[num].y = 194;
    else if (y != 194) rec[num].y = 284;
  }
  else if (x >= 109 && x <= 126){
    if (y == 234 || y == 194) rec[num].y = 214;
    else if (y != 214) rec[num].y = 284;
  }
  else if (x >= 126 && x <= 174){
    if (y == 214 || (y == 174 && x <= 150)) rec[num].y = 234;
    else if (y != 174 && y != 234) rec[num].y = 284;
  }
  else if (x >= 174 && x <= 288){
    if (y == 234 || y == 264) rec[num].y = 284;
    else if (y != 284) rec[num].y = 174;
  }
  else if (x >= 288 && x <= 321){
    if (y == 230) rec[num].y = 264;
    else if (y != 174 && y != 264) rec[num].y = 284;
  }
  else if (x >= 321 && x <= 345){
    if (y == 264 || y == 174) rec[num].y = 230;
    else if (y != 230) rec[num].y = 284;
  }
  else if (x >= 345 && x <= 384){
    if (y == 230 || (y == 196 && x <= 366)) rec[num].y = 264;
    else if (y != 196 && y != 264) rec[num].y = 284;
  }
  else if (x >= 384 && x <= 459){
    if (y == 264 || (y == 196 && x >= 417) || (y == 170 && x <= 438) || y == 295) rec[num].y = 284;
    else if (y != 196 && y != 170) rec[num].y = 284;
  }
  else if (x >= 459 && x <= 498){
    if (y == 284) rec[num].y = 295;
    else if (y != 295) rec[num].y = 170;
  }
  else if (x >= 537 && x <= 576){
    if (y == 284) rec[num].y = 295;
    else if (y != 295) rec[num].y = 170;
  }
  else if (x >= 576 && x <= 640){
    if (y == 170 || y == 295 || (y == 175 && x <= 603)) rec[num].y = 284;
    else if (y != 284) rec[num].y = 175;
  }
}

void up_check(SDL_Rect * rec, int num) {
  int x = rec[num].x;
  int y = rec[num].y;
  if (x >= 0 && x <= 24){
    if (y == 284) rec[num].y = 234;
  }
  else if (x >= 24 && x <= 42){
    if (y == 284) rec[num].y = 210;
  }
  else if (x >= 42 && x <= 109){
    if (y == 284) rec[num].y = 194;
  }
  else if (x >= 109 && x <= 126){
    if (y == 284) rec[num].y = 214;
  }
  else if (x >= 126 && x <= 174){
    if (y == 284) rec[num].y = 234;
    else if (y == 234 && x >= 150) rec[num].y = 174;
  }
  else if (x >= 174 && x <= 288){
    if (y == 284) rec[num].y = 174;
  }
  else if (x >= 288 && x <= 321){
    if (y == 284) rec[num].y = 264;
    else if (y == 264) rec[num].y = 174;
  }
  else if (x >= 321 && x <= 345){
    if (y == 284) rec[num].y = 230;
  }
  else if (x >= 345 && x <= 384){
    if (y == 284) rec[num].y = 264;
    else if (x >= 366) rec[num].y = 196;
  }
  else if (x >= 384 && x <= 459){
    if (y == 284 && x <= 417) rec[num].y = 196;
    else if (y == 284 && x >= 366) rec[num].y = 170;
  }
  else if (x >= 459 && x <= 498){
    if (y == 295) rec[num].y = 170;
  }
  else if (x >= 537 && x <= 576){
    if (y == 295) rec[num].y = 170;
  }
  else if (x >= 576 && x <= 640){
    if (y == 284 && x >= 603) rec[num].y = 175;
  }
}
void down_check(SDL_Rect * rec, int num) {
  int x = rec[num].x;
  int y = rec[num].y;
  if (x >= 0 && x <= 24){
    if (y == 234) rec[num].y = 284;
  }
  else if (x >= 24 && x <= 42){
    if (y == 210) rec[num].y = 284;
  }
  else if (x >= 42 && x <= 109){
    if (y == 194) rec[num].y = 284;
  }
  else if (x >= 109 && x <= 126){
    if (y == 214) rec[num].y = 284;
  }
  else if (x >= 126 && x <= 174){
    if (y == 234) rec[num].y = 284;
    else if (y == 174 && x >= 150) rec[num].y = 234;
  }
  else if (x >= 174 && x <= 288){
    if (y == 174) rec[num].y = 284;
  }
  else if (x >= 288 && x <= 321){
    if (y == 264) rec[num].y = 284;
    else if (y == 174) rec[num].y = 264;
  }
  else if (x >= 321 && x <= 345){
    if (y == 230) rec[num].y = 284;
  }
  else if (x >= 345 && x <= 384){
    if (y == 264) rec[num].y = 284;
    else if (y == 196 && x >= 366) rec[num].y = 264;
  }
  else if (x >= 384 && x <= 459){
    if (y == 196 && x <= 417) rec[num].y = 284;
    else if (y == 170 && x >= 366) rec[num].y = 284;
  }
  else if (x >= 459 && x <= 498){
    if (y == 170) rec[num].y = 295;
  }
  else if (x >= 537 && x <= 576){
    if (y == 170) rec[num].y = 295;
  }
  else if (x >= 576 && x <= 640){
    if (y == 175 && x >= 603) rec[num].y = 284;
  }
}
void moveDown(SDL_Rect * rec, int num){
  struct rect [20];
  initializeRect(&(rect[0]),0,234,24,50);
  initializeRect(&(rect[1]),24,234,42,50);
  initializeRect(&(rect[2]),42,234,109,50);
  initializeRect(&(rect[3]),109,234,126,50);
  initializeRect(&(rect[4]),126,234,174,50);
  initializeRect(&(rect[5]),174,234,288,50);
  initializeRect(&(rect[6]),288,234,321,50);
  initializeRect(&(rect[7]),321,234,345,50);
  initializeRect(&(rect[8]),345,234,384,50);
  initializeRect(&(rect[9]),459,234,498,50);
  initializeRect(&(rect[10]),498,234,576,50);
  initializeRect(&(rect[11]),576,234,640,50);

  int intervals [20] = {0,24,42,109,126,174,288,321,345,384,459,498,576,640};
  int movement [20] = {1,1,1,0,0,-1,0,0};
  int x = rec[num].x;
  int y = rec[num].y;
  if (x >= 0 && x <= 24){
    if (y == 210) rec[num].y = 234;
    else if (y != 234) rec[num].y = 284;
  }
  else if (x >= 24 && x <= 42){
    if (y == 234 || y == 194) rec[num].y = 210;
    else if (y != 210) rec[num].y = 284;
  }
  else if (x >= 42 && x <= 109){
    if (y == 210 || y == 214) rec[num].y = 194;
    else if (y != 194) rec[num].y = 284;
  }
  else if (x >= 109 && x <= 126){
    if (y == 234 || y == 194) rec[num].y = 214;
    else if (y != 214) rec[num].y = 284;
  }
  else if (x >= 126 && x <= 174){
    if (y == 214 || (y == 174 && x <= 150)) rec[num].y = 234;
    else if (y != 174 && y != 234) rec[num].y = 284;
  }
  else if (x >= 174 && x <= 288){
    if (y == 234 || y == 264) rec[num].y = 284;
    else if (y != 284) rec[num].y = 174;
  }
  else if (x >= 288 && x <= 321){
    if (y == 230) rec[num].y = 264;
    else if (y != 174 && y != 264) rec[num].y = 284;
  }
  else if (x >= 321 && x <= 345){
    if (y == 264 || y == 174) rec[num].y = 230;
    else if (y != 230) rec[num].y = 284;
  }
  else if (x >= 345 && x <= 384){
    if (y == 230 || (y == 196 && x <= 366)) rec[num].y = 264;
    else if (y != 196 && y != 264) rec[num].y = 284;
  }
  else if (x >= 384 && x <= 459){
    if (y == 264 || (y == 196 && x >= 417) || (y == 170 && x <= 438) || y == 295) rec[num].y = 284;
    else if (y != 196 && y != 170) rec[num].y = 284;
  }
  else if (x >= 459 && x <= 498){
    if (y == 284) rec[num].y = 295;
    else if (y != 295) rec[num].y = 170;
  }
  else if (x >= 537 && x <= 576){
    if (y == 284) rec[num].y = 295;
    else if (y != 295) rec[num].y = 170;
  }
  else if (x >= 576 && x <= 640){
    if (y == 170 || y == 295 || (y == 175 && x <= 603)) rec[num].y = 284;
    else if (y != 284) rec[num].y = 175;
  }
}
void initializeRect(struct rect * recty, int x, int y, int w, int l){
  recty->x = x;
  recty->y = y;
  recty->w = w;
  retcy->l = l;
}
int rectIntersectRect(struct rect1, struct rect2)
int whereRectComapredToRect(struct rect1, struct rect2){
  int c1x,c1y,c2x,c2y;
  calcCenter(&c1x,&c1y,rect1);
  calcCenter(&c2x,&c2y,rect2);
  if (abs(c1y-c2y)>rect1.l){
    if(c1y>c2y){
      return 1;
    }
    else
      return 3;
  }
  else if (c2x>c1x){
    return 4;
  }
  return 3;
}
float calcCenter(int *cX, int *cY, struct rect){
  *cX = rect.x+w/2;
  *cy = rect.y+l/2;
}
