#include "move.h"
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

extern int shift;

void move(SDL_Rect * rec, int num, int scr) {
  int x = rec[num].x - shift;
  if (scr == 1) x -= SCREEN_WIDTH;
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
      else if (y != 295) rec[num].y = 170;
    }
    else if (x > 495 && x < 537) {
      //perform death
    }
    else if (x >= 537 && x <= 579){
      if (y == 284) rec[num].y = 295;
      else if (y != 295) rec[num].y = 170;
    }
    else if (x >= 579 && x <= 644){
      if (y == 170 || y == 295 || (y == 175 && x <= 603)) rec[num].y = 284;
      else if (y != 284) rec[num].y = 175;
    }
  }
  else {
    if (x >= -21 && x <= 33){
      if (y == 263 || (y == 176 && x >= 12)) rec[num].y = 281;
      else if (y != 281 && x <= 12) rec[num].y = 176;
    }
    else if (x >= 33 && x <= 57){
      if (y == 242) rec[num].y = 263;
      else if (y != 263) rec[num].y = 281;
    }
    else if (x >= 57 && x <= 81){
      if (y == 224 || y == 263) rec[num].y = 242;
      else if (y != 242) rec[num].y = 281;
    }
    else if (x >= 81 && x <= 102){
      if (y == 203 || y == 242) rec[num].y = 224;
      else if (y != 224) rec[num].y = 281;
    }
    else if (x >= 102 && x <= 138){
      if (y == 182 || y == 224) rec[num].y = 203;
      else if (y != 203) rec[num].y = 281;
    }
    else if (x >= 138 && x <= 204){
      if (y <= 203) rec[num].y = 182;
      else if (y != 182) rec[num].y = 281;
    }
    else if (x >= 204 && x <= 228){
      if (y == 143) rec[num].y = 161;
      else if (y != 161 && y != 281) rec[num].y = 182 - .1316*(x - 182);
    }
    else if (x >= 228 && x <= 294){
      if (y == 161) rec[num].y = 143;
      else if (y != 143 && y != 281) rec[num].y = 182 - .1316*(x - 182);
    }
    else if (x >= 294 && x <= 345){
      if (y == 143) rec[num].y = 167;
      else if (y != 167) rec[num].y = 281;
    }
    else if (x >= 345 && x <= 393){
      if (y == 167 || y == 251 || (y == 188 && x >= 384)) rec[num].y = 281;
      else if (y != 281 && x > 384) rec[num].y = 188;
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
  if (scr == 1) x -= SCREEN_WIDTH;
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
      if (y == 284 && x >= 603) rec[num].y = 175;
    }
  }
  else {
    if (x >= -21 && x <= 33){
      if (y == 281 && x <= 12) rec[num].y = 176;
    }
    else if (x >= 33 && x <= 57){
      if (y == 281) rec[num].y = 263;
    }
    else if (x >= 57 && x <= 81){
      if (y == 281) rec[num].y = 242;
    }
    else if (x >= 81 && x <= 102){
      if (y == 281) rec[num].y = 224;
    }
    else if (x >= 102 && x <= 138){
      if (y == 281) rec[num].y = 203;
    }
    else if (x >= 138 && x <= 204){
      if (y == 281) rec[num].y = 182;
    }
    else if (x >= 204 && x <= 228){
      if (y < 281) rec[num].y = 161;
      else if (y == 281) rec[num].y = 182 - .1316*(x - 182);
    }
    else if (x >= 228 && x <= 294){
      if (y < 281) rec[num].y = 143;
      else if (y == 281) rec[num].y = 182 - .1316*(x - 182);
    }
    else if (x >= 294 && x <= 345){
      if (y == 281) rec[num].y = 167;
    }
    else if (x >= 345 && x <= 393){
      if (y == 281 && x >= 384) rec[num].y = 188;
    }
    else if (x >= 393 && x <= 465){
      if (y == 251 && x <= 450) rec[num].y = 188;
    }
  }
}

void down_check(SDL_Rect * rec, int num, int scr) {
  int x = rec[num].x - shift;
  if (scr == 1) x -= SCREEN_WIDTH;
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
      if (y == 175 && x >= 603) rec[num].y = 284;
    }
  }
  else {
    if (x >= -21 && x <= 33){
      if (y == 176 && x <= 12) rec[num].y = 281;
    }
    else if (x >= 33 && x <= 57){
      if (y == 263) rec[num].y = 281;
    }
    else if (x >= 57 && x <= 81){
      if (y == 242) rec[num].y = 281;
    }
    else if (x >= 81 && x <= 102){
      if (y == 224) rec[num].y = 281;
    }
    else if (x >= 102 && x <= 138){
      if (y == 203) rec[num].y = 281;
    }
    else if (x >= 138 && x <= 204){
      if (y == 182) rec[num].y = 281;
    }
    else if (x >= 204 && x <= 228){
      if (y == 161) rec[num].y = 182 - .1316*(x - 182);
      else if (y > 161 && y < 281) rec[num].y = 281;
    }
    else if (x >= 228 && x <= 294){
      if (y == 143) rec[num].y = 182 - .1316*(x - 182);
      else if (y > 161 && y < 281) rec[num].y = 281;
    }
    else if (x >= 294 && x <= 345){
      if (y == 167) rec[num].y = 281;
    }
    else if (x >= 345 && x <= 393){
      if (y == 188 && x >= 384) rec[num].y = 281;
    }
    else if (x >= 393 && x <= 465){
      if (y == 188 && x <= 450) rec[num].y = 251;
    }
  }
}
