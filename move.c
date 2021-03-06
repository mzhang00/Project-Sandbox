#include "move.h"
#include "display.h"
#include <math.h>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

int shift = 0;
void move(SDL_Rect * rec, int num, int scr) {
  int x = rec[num].x - shift;
  if (scr == 1) x -= SCREEN_WIDTH-3;
  int y = rec[num].y;
  if (scr == 0) {
    if (x >= -21 && x <= 15){
      if (y == 210) rec[num].y = 234;
      else if (y != 234) rec[num].y = 284;
    }
    else if (x >= 15 && x <= 36){
      if (y == 234 || y == 194) rec[num].y = 210;
      else if (y != 210) rec[num].y = 284;
    }
    else if (x >= 36 && x <= 102){
      if (y == 210 || y == 214) rec[num].y = 194;
      else if (y != 194) rec[num].y = 284;
    }
    else if (x >= 102 && x <= 117){
      if (y == 234 || y == 194) rec[num].y = 214;
      else if (y != 214) rec[num].y = 284;
    }
    else if (x >= 117 && x <= 165){
      if (y == 214 || (y == 174 && x <= 144)) rec[num].y = 234;
      else if (y != 174 && y != 234) rec[num].y = 284;
    }
    else if (x >= 165 && x <= 288){
      if (y == 234 || y == 264) rec[num].y = 284;
      else if (y != 284) rec[num].y = 174;
    }
    else if (x >= 288 && x <= 315){
      if (y == 230) rec[num].y = 264;
      else if (y != 174 && y != 264) rec[num].y = 284;
    }
    else if (x >= 315 && x <= 339){
      if (y == 264 || y == 174) rec[num].y = 230;
      else if (y != 230) rec[num].y = 284;
    }
    else if (x >= 339 && x <= 381){
      if (y == 230 || (y == 196 && x <= 360)) rec[num].y = 264;
      else if (y != 196 && y != 264) rec[num].y = 284;
    }
    else if (x >= 381 && x <= 456){
      if (y == 264 || (y == 196 && x >= 414) || (y == 170 && x <= 435) || y == 295) rec[num].y = 284;
      else if (y != 196 && y != 170) rec[num].y = 284;
    }
    else if (x >= 456 && x <= 495){
      if (y == 284) rec[num].y = 295;
      else if (y <= 280) rec[num].y = 170;
    }
    else if (x > 495 && x < 537) {
      //perform death
    }
    else if (x >= 537 && x <= 579){
      if (y == 284) rec[num].y = 295;
      else if (y <= 280) rec[num].y = 170;
    }
    else if (x >= 579 && x <= 644){
      if (y == 170 || y == 295 || (y == 175 && x <= 600)) rec[num].y = 284;
      else if (y < 284) rec[num].y = 175;
    }
  }
  else {
    if (x >= -21 && x <= 33){
      if (y == 263 || (y == 175 && x >= 12)) rec[num].y = 284;
      else if (y < 284 && x <= 12) rec[num].y = 175;
    }
    else if (x >= 33 && x <= 57){
      if (y == 242) rec[num].y = 263;
      else if (y != 263) rec[num].y = 284;
    }
    else if (x >= 57 && x <= 81){
      if (y == 224 || y == 263) rec[num].y = 242;
      else if (y != 242) rec[num].y = 284;
    }
    else if (x >= 81 && x <= 102){
      if (y == 203 || y == 242) rec[num].y = 224;
      else if (y != 224) rec[num].y = 284;
    }
    else if (x >= 102 && x <= 138){
      if (y == 182 || y == 224) rec[num].y = 203;
      else if (y != 203) rec[num].y = 284;
    }
    else if (x >= 138 && x <= 204){
      if (y <= 203) rec[num].y = 182;
      else if (y != 182) rec[num].y = 284;
    }
    else if (x >= 204 && x <= 228){
      if (y == 143) rec[num].y = 161;
      else if (y != 161 && y != 284) rec[num].y = 182 - .1316*(x - 182);
    }
    else if (x >= 228 && x <= 294){
      if (y == 161) rec[num].y = 143;
      else if (y != 143 && y != 284) rec[num].y = 182 - .1316*(x - 182);
    }
    else if (x >= 294 && x <= 345){
      if (y == 143) rec[num].y = 167;
      else if (y != 167) rec[num].y = 284;
    }
    else if (x >= 345 && x <= 393){
      if (y == 167 || y == 251 || (y == 188 && x >= 384)) rec[num].y = 284;
      else if (y != 284 && x > 384) rec[num].y = 188;
    }
    else if (x >= 393 && x <= 465){
      if (y == 188 && x >= 450) rec[num].y = 251;
      else if (y != 188) rec[num].y = 251;
    }
    else if (x >= 489 && x <= 570){
      rec[num].y = 218;
    }
  }
}
void up_check(SDL_Rect * rec, int num, int scr) {
  int x = rec[num].x - shift;
  if (scr == 1) x -= SCREEN_WIDTH-3;
  int y = rec[num].y;
  if (scr == 0) {
    if (x >= -21 && x <= 15){
      if (y == 284) rec[num].y = 234;
    }
    else if (x >= 15 && x <= 36){
      if (y == 284) rec[num].y = 210;
    }
    else if (x >= 36 && x <= 102){
      if (y == 284) rec[num].y = 194;
    }
    else if (x >= 102 && x <= 117){
      if (y == 284) rec[num].y = 214;
    }
    else if (x >= 117 && x <= 165){
      if (y == 284) rec[num].y = 234;
      else if (y == 234 && x >= 144) rec[num].y = 174;
    }
    else if (x >= 165 && x <= 288){
      if (y == 284) rec[num].y = 174;
    }
    else if (x >= 288 && x <= 315){
      if (y == 284) rec[num].y = 264;
      else if (y == 264) rec[num].y = 174;
    }
    else if (x >= 315 && x <= 339){
      if (y == 284) rec[num].y = 230;
    }
    else if (x >= 339 && x <= 381){
      if (y == 284) rec[num].y = 264;
      else if (x >= 360) rec[num].y = 196;
    }
    else if (x >= 381 && x <= 456){
      if (y == 284 && x <= 414) rec[num].y = 196;
      else if (y == 284 && x >= 360) rec[num].y = 170;
    }
    else if (x >= 456 && x <= 495){
      if (y == 295) rec[num].y = 170;
    }
    else if (x >= 537 && x <= 579){
      if (y == 295) rec[num].y = 170;
    }
    else if (x >= 579 && x <= 644){
      if (y == 284 && x >= 600) rec[num].y = 175;
    }
  }
  else {
    if (x >= -21 && x <= 33){
      if (y == 284 && x <= 12) rec[num].y = 175;
    }
    else if (x >= 33 && x <= 57){
      if (y == 284) rec[num].y = 263;
    }
    else if (x >= 57 && x <= 81){
      if (y == 284) rec[num].y = 242;
    }
    else if (x >= 81 && x <= 102){
      if (y == 284) rec[num].y = 224;
    }
    else if (x >= 102 && x <= 138){
      if (y == 284) rec[num].y = 203;
    }
    else if (x >= 138 && x <= 204){
      if (y == 284) rec[num].y = 182;
    }
    else if (x >= 204 && x <= 228){
      if (y < 284) rec[num].y = 161;
      else if (y == 284) rec[num].y = 182 - .1316*(x - 182);
    }
    else if (x >= 228 && x <= 294){
      if (y < 284) rec[num].y = 143;
      else if (y == 284) rec[num].y = 182 - .1316*(x - 182);
    }
    else if (x >= 294 && x <= 345){
      if (y == 284) rec[num].y = 167;
    }
    else if (x >= 345 && x <= 393){
      if (y == 284 && x >= 384) rec[num].y = 188;
    }
    else if (x >= 393 && x <= 465){
      if (y == 251 && x <= 450) rec[num].y = 188;
    }
  }
}

void down_check(SDL_Rect * rec, int num, int scr) {
  int x = rec[num].x - shift;
  if (scr == 1) x -= SCREEN_WIDTH-3;
  int y = rec[num].y;
  if (scr == 0) {
    if (x >= -21 && x <= 15){
      if (y == 234) rec[num].y = 284;
    }
    else if (x >= 15 && x <= 36){
      if (y == 210) rec[num].y = 284;
    }
    else if (x >= 36 && x <= 102){
      if (y == 194) rec[num].y = 284;
    }
    else if (x >= 102 && x <= 117){
      if (y == 214) rec[num].y = 284;
    }
    else if (x >= 117 && x <= 165){
      if (y == 234) rec[num].y = 284;
      else if (y == 174 && x >= 144) rec[num].y = 234;
    }
    else if (x >= 165 && x <= 288){
      if (y == 174) rec[num].y = 284;
    }
    else if (x >= 288 && x <= 315){
      if (y == 264) rec[num].y = 284;
      else if (y == 174) rec[num].y = 264;
    }
    else if (x >= 315 && x <= 339){
      if (y == 230) rec[num].y = 284;
    }
    else if (x >= 339 && x <= 381){
      if (y == 264) rec[num].y = 284;
      else if (y == 196 && x >= 360) rec[num].y = 264;
    }
    else if (x >= 381 && x <= 456){
      if (y == 196 && x <= 414) rec[num].y = 284;
      else if (y == 170 && x >= 360) rec[num].y = 284;
    }
    else if (x >= 456 && x <= 495){
      if (y == 170) rec[num].y = 295;
    }
    else if (x >= 537 && x <= 579){
      if (y == 170) rec[num].y = 295;
    }
    else if (x >= 579 && x <= 643){
      if (y == 175 && x >= 600) rec[num].y = 284;
    }
  }
  else {
    if (x >= -21 && x <= 33){
      if (y == 175 && x <= 12) rec[num].y = 284;
    }
    else if (x >= 33 && x <= 57){
      if (y == 263) rec[num].y = 284;
    }
    else if (x >= 57 && x <= 81){
      if (y == 242) rec[num].y = 284;
    }
    else if (x >= 81 && x <= 102){
      if (y == 224) rec[num].y = 284;
    }
    else if (x >= 102 && x <= 138){
      if (y == 203) rec[num].y = 284;
    }
    else if (x >= 138 && x <= 204){
      if (y == 182) rec[num].y = 284;
    }
    else if (x >= 204 && x <= 228){
      if (y == 161) rec[num].y = 182 - .1316*(x - 182);
      else if (y > 161 && y < 284) rec[num].y = 284;
    }
    else if (x >= 228 && x <= 294){
      if (y == 143) rec[num].y = 182 - .1316*(x - 182);
      else if (y > 161 && y < 284) rec[num].y = 284;
    }
    else if (x >= 294 && x <= 345){
      if (y == 167) rec[num].y = 284;
    }
    else if (x >= 345 && x <= 393){
      if (y == 188 && x >= 384) rec[num].y = 284;
    }
    else if (x >= 393 && x <= 465){
      if (y == 188 && x <= 450) rec[num].y = 251;
    }
  }
}
void moveDown(SDL_Rect * rec, int num){
  struct rect recty[20];
  initializeRect(&(recty[0]),0,234,24,50);
  initializeRect(&(recty[1]),24,234,42,50);
  initializeRect(&(recty[2]),42,234,109,50);
  initializeRect(&(recty[3]),109,234,126,50);
  initializeRect(&(recty[4]),126,234,174,50);
  initializeRect(&(recty[5]),174,234,288,50);
  initializeRect(&(recty[6]),288,234,321,50);
  initializeRect(&(recty[7]),321,234,345,50);
  initializeRect(&(recty[8]),345,234,384,50);
  initializeRect(&(recty[9]),459,234,498,50);
  initializeRect(&(recty[10]),498,234,576,50);
  initializeRect(&(recty[11]),576,234,640,50);

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
  recty->l = l;
}

int whereRectComapredToRect(struct rect rect1, struct rect rect2){
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
float calcCenter(int *cX, int *cY, struct rect recty){
  *cX = recty.x+recty.w/2;
  *cY = recty.y+recty.l/2;
}
int detectBulletIntersectRect(struct rifleGun rifle, SDL_Rect shooting_unit, SDL_Rect recty){
  int xRight = (int)(shooting_unit.x+10000*cos(-rifle.angle*M_PI /180.0));
  int xLeft = (int)(shooting_unit.x-10000*cos(-rifle.angle*M_PI /180.0));
  int yUp = (int)(shooting_unit.y-10000*sin(-rifle.angle*M_PI /180.0));
  int yDown = (int)(shooting_unit.y+10000*sin(-rifle.angle*M_PI /180.0));

  int actualShootingX = shooting_unit.x;
  int actualShootingY = shooting_unit.y;

  if (rifle.flip == SDL_FLIP_NONE){
    //if(shooting_unit.x>recty.x){
    //  return 0;
    //}
    if(SDL_IntersectRectAndLine(&recty,&(actualShootingX),&(actualShootingY),&xRight, &yUp))
      return 1;
    return 0;
  }
  else{
    //if(shooting_unit.x<recty.x){
    //  return 0;
    //}
    if(SDL_IntersectRectAndLine(&recty,&(actualShootingX),&(actualShootingY),&xLeft, &yDown))
      return 1;
    return 0;
  }
}
