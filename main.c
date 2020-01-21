#include "display.h"
#include "move.h"
#include <time.h>

int main(){
  if (!init()) {
        printf("Failed to initialize\n");
      }
  else {
        int t = time(NULL);
        int mode = 0;
        struct rifleGun rifle;
        SDL_Window * win = SDL_CreateWindow( "Sandbox Wars", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
        if( win == NULL ){
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        // creates a renderer to render our images
        SDL_Renderer* rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
        int idx = 0;
        int screen = 0;
        SDL_Surface* surface;
        char cwd[100];
        getcwd(cwd, 100);
        strcat(cwd, "/nezuko.bmp");
        //Load splash image
        surface = SDL_LoadBMP(cwd );
        if( surface == NULL ){
            printf( "Unable to load image %s! SDL Error: %s\n", cwd, SDL_GetError() );
        }

        // loads image to our graphics hardware memory.
        SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);
        SDL_FreeSurface(surface);
        // clears main-memory
        //Creating array of Rect-screens
       //Creating array of Texture screens

       SDL_Rect * screens = malloc(4*sizeof(SDL_Rect));
       SDL_Texture ** screenText = malloc(4*sizeof(SDL_Texture *));
       char fileName[50];
       for (int i = 0;i < 4;i++){
         switch(i){
           case 0:
             strcpy(fileName,"/mainscreen.bmp");
             break;
           case 1:
             strcpy(fileName,"/movecontrol.bmp");
             break;
           case 2:
             strcpy(fileName,"/weapons.bmp");
             break;
           case 3:
             strcpy(fileName,"/guncontrol.bmp");
             break;
         }
         getcwd(cwd, 100);
         strcat(cwd, fileName);
         //Load splash image
         surface = SDL_LoadBMP(cwd);
         screenText[i] = SDL_CreateTextureFromSurface(rend, surface);
         SDL_QueryTexture(screenText[i], NULL, NULL, &(screens[i].w), &(screens[i].h));
         screens[i].x = 0;
         screens[i].y = 372;
         screens[i].w = SCREEN_WIDTH;
         screens[i].h = 115;
         if( surface == NULL ){
             printf( "Unable to load image %s! SDL Error: %s\n", cwd, SDL_GetError() );
         }
         SDL_FreeSurface(surface);
       }
       //Displaying Gun
       getcwd(cwd, 100);
       strcat(cwd, "/rifle3.bmp");
       surface = SDL_LoadBMP(cwd);
       SDL_Texture* rifleText = SDL_CreateTextureFromSurface(rend, surface);
       SDL_Rect displayedRifle;
       SDL_QueryTexture(rifleText, NULL, NULL, &displayedRifle.w, &displayedRifle.h);
       SDL_FreeSurface(surface);
       displayedRifle.x = 0;
       displayedRifle.y = 0;
       displayedRifle.w = 50;
       displayedRifle.h = 10;

       rifle.angle = 0;
       rifle.rifleMode = 0;
       rifle.flip = SDL_FLIP_NONE;


      SDL_Rect * maps = malloc(2*sizeof(SDL_Rect));
      SDL_Texture ** mapsText = malloc(2*sizeof(SDL_Texture *));
      for(int i = 0;i < 2;i++){
        getcwd(cwd, 100);
        switch(i){
          case 0:
            strcat(cwd,"/map1.bmp");
            break;
          case 1:
            strcat(cwd,"/map2.bmp");
            break;
        }
        //Load splash image
        surface = SDL_LoadBMP(cwd);
        mapsText[i] = SDL_CreateTextureFromSurface(rend, surface);
        SDL_QueryTexture(mapsText[i], NULL, NULL, &(maps[i].w), &(maps[i].h));
        switch(i){
          case 0:
            maps[i].x = 0;
            break;
          case 1:
            maps[i].x = SCREEN_WIDTH - 3;
            break;
        }
        maps[i].y = 0;
        maps[i].w = SCREEN_WIDTH;
        maps[i].h = SCREEN_HEIGHT;
        if( surface == NULL ){
            printf( "Unable to load image %s! SDL Error: %s\n", cwd, SDL_GetError() );
        }
        SDL_FreeSurface(surface);
      }

        // let us control our image position
        // so that we can move it with our keyboard.
        SDL_Rect * rect = malloc(6*sizeof(SDL_Rect));
        SDL_Rect * healthbars = malloc(6*sizeof(SDL_Rect));
        struct unit * units = malloc(6*sizeof(struct unit));
        // connects our texture with rect to control position
        srand(time(0));
        for (int i = 0; i < 6; i++) {
          SDL_QueryTexture(tex, NULL, NULL, &(rect[i].w), &(rect[i].h));
          if( rect+ i == NULL ){
              printf( "Unable to query texture %d! SDL Error: %s\n", i, SDL_GetError() );
          }

          rect[i].w /= 14;
          rect[i].h /= 16;

          switch(i) {
            case 0:
              rect[i].x = 417;
              rect[i].y = 284;
              break;
            case 1:
              rect[i].x = 113+SCREEN_WIDTH;
              rect[i].y = 203;
              break;
            case 2:
              rect[i].x = 291;
              rect[i].y = 174;
              break;
            case 3:
              rect[i].x = 245+SCREEN_WIDTH;
              rect[i].y = 281;
              break;
            case 4:
              rect[i].x = 150;
              rect[i].y = 234;
              break;
            case 5:
              rect[i].x = 332+SCREEN_WIDTH;
              rect[i].y = 167;
              break;
          }

          units[i].number = 0;
          units[i].health = rand()%75;
          units[i].weapon_id = 0;
          units[i].moves_left = 10;
          units[i].x = i * (SCREEN_WIDTH - rect[i].w)/6;
          units[i].y = (SCREEN_HEIGHT - rect[i].h) / 2;
          units[i].team = 0;
          units[i].unit_rect = rect[i];
          units[i].unit_tex = tex;

          // Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
          int rectx = rect[i].x - 30;
          int recty = rect[i].y - 10;
          if ((rectx <= 0)) {
            rectx = 1;
          } else if (recty <= 0) {
            recty = 1;
          } else if (rectx >= 540) {
            rectx = 539;
          } else if(recty >= 540) {
            recty = 539;
          }
          healthbars[i].x = rectx;
          healthbars[i].y = recty;
          healthbars[i].w = 100;
          healthbars[i].h = 5;
        }

        // controls animation loop
        int close = 0;

        // speed of box
        int speed = 100;

        // annimation loop
        while (!close) {
            SDL_Event event;

            // Events mangement
            while (SDL_PollEvent(&event)) {
              if (event.type == SDL_QUIT){
                close = 1;
                break;
              }
              else if(event.type == SDL_KEYDOWN){
                switch (event.key.keysym.scancode) {
                  case SDL_SCANCODE_D:
                    if (shift != -SCREEN_WIDTH){
                      shift -= 10;
                      for (int i = 0; i < 2; i++) {
                        maps[i].x -= 10;
                      }
                      for (int i = 0; i < 6; i++) {
                        rect[i].x -= 10;
                      }
                    }
                    break;
                  case SDL_SCANCODE_A:
                    if (shift != 0){
                      shift += 10;
                      for (int i = 0; i < 2; i++) {
                        maps[i].x += 10;
                      }
                      for (int i = 0; i < 6; i++) {
                        rect[i].x += 10;
                      }
                    }
                    break;
                }
                switch(mode){
                  case 0:
                    switch (event.key.keysym.scancode) {
                      case SDL_SCANCODE_1:
                        mode = 1;
                        break;
                      case SDL_SCANCODE_2:
                        mode = 2;
                        break;
                    }
                    break;
                  case 1:
                  // keyboard API for key press
                    switch (event.key.keysym.scancode) {
                      case SDL_SCANCODE_UP:
                        up_check(rect,idx,screen);
                        break;
                      case SDL_SCANCODE_LEFT:
                        rect[idx].x -= speed / 30;
                        break;
                      case SDL_SCANCODE_DOWN:
                        down_check(rect,idx,screen);
                        break;
                      case SDL_SCANCODE_RIGHT:
                        rect[idx].x += speed / 30;
                        break;
                      case SDL_SCANCODE_1:
                        mode = 2;
                        break;
                    }
                    break;
                  case 2:
                    switch (event.key.keysym.scancode) {
                      case SDL_SCANCODE_1:
                      //grenade
                        break;
                      case SDL_SCANCODE_2:
                        mode = 3;
                        displayedRifle.x = rect[idx].x+rect[idx].w/2;
                        displayedRifle.y = rect[idx].y+rect[idx].h/2-5;
                        rifle.rifleMode = 1;
                        calculateCenter(&rifle);
                        break;
                      case SDL_SCANCODE_3:
                        //boot
                        break;
                      case SDL_SCANCODE_4:
                        if (idx < 5) {
                          idx++;
                        }
                        else {
                          idx = 0;
                        }
                        mode = 0;
                        break;
                     }
                  case 3:
                    switch (event.key.keysym.scancode) {
                      case SDL_SCANCODE_SPACE:
                        //int j = 0;
                        for (int j=0;j<6;j++){
                          if(j==idx)
                            continue;
                          if(detectBulletIntersectRect(rifle,rect[j])){
                            units[idx].health-=30;
                          }
                        }
                        if (idx < 5) {
                            idx++;
                        }
                        else {
                          idx = 0;
                        }
                        break;
                      case SDL_SCANCODE_X:
                          rifle.rifleMode = 0;
                          mode = 2;
                          break;
                      case SDL_SCANCODE_UP:
                        if(rifle.angle>-45)
                          if(rifle.flip == SDL_FLIP_NONE)
                            rifle.angle-=1;
                        if(rifle.angle<45)
                          if(rifle.flip != SDL_FLIP_NONE)
                            rifle.angle+=1;
                        break;
                      case SDL_SCANCODE_DOWN:
                        if(rifle.angle<45)
                          if(rifle.flip == SDL_FLIP_NONE)
                            rifle.angle+=1;
                        if(rifle.angle>-45)
                          if(rifle.flip != SDL_FLIP_NONE)
                            rifle.angle-=1;
                        break;
                      case SDL_SCANCODE_LEFT:
                        if(rifle.flip == SDL_FLIP_NONE){
                          rifle.flip = SDL_FLIP_HORIZONTAL;
                          rifle.angle = 0;
                          rifle.center.x = -1*displayedRifle.w;
                        }
                        break;
                      case SDL_SCANCODE_RIGHT:
                        if(rifle.flip != SDL_FLIP_NONE){
                          rifle.flip = SDL_FLIP_NONE;
                          rifle.angle = 0;
                          rifle.center.x = 0;
                        }
                        break;
                    }
                }
                move(rect, idx, screen);
                move(healthbars, idx, screen); // make health bars move with player

                if (rect[idx].x >= maps[1].x + 1) {
                  screen = 1;
                }
                if (rect[idx].x <= maps[1].x +1) {
                  screen = 0;
                }
                if (t != time(NULL)) {
                  t = time(NULL);
                  printf("x: %d\t y: %d\n",rect[idx].x, rect[idx].y);
                }
                render(rend,tex,rect, mapsText, maps, screenText[mode], &(screens[mode]),healthbars, units, &displayedRifle, rifleText, rifle);
        }
      }
    }
    free(rect);
    free(maps);
    free(mapsText);
    free(screens);
    free(screenText);
    close1(rend,tex,win);
  }
  return 0;
}
