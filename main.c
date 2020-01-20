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
       strcat(cwd, "/rifle2.bmp");
       surface = SDL_LoadBMP(cwd);
       SDL_Texture* rifleText = SDL_CreateTextureFromSurface(rend, surface);
       SDL_Rect displayedRifle;
       SDL_QueryTexture(rifleText, NULL, NULL, &displayedRifle.w, &displayedRifle.h);
       SDL_FreeSurface(surface);
       displayedRifle.x = 0;
       displayedRifle.y = 0;
       displayedRifle.w = 300;
       displayedRifle.h = 100;
       calculateCenter(&rifle,displayedRifle);
       rifle.angle = 0;
       rifle.rifleMode = 0;

        // let us control our image position
        // so that we can move it with our keyboard.
        SDL_Rect * rect = malloc(6*sizeof(SDL_Rect));

        // connects our texture with rect to control position
        for (int i = 0; i < 6; i++) {
          SDL_QueryTexture(tex, NULL, NULL, &(rect[i].w), &(rect[i].h));
          if( rect+ i == NULL ){
              printf( "Unable to query texture %d! SDL Error: %s\n", i, SDL_GetError() );
          }
          rect[i].w /= 14;
          rect[i].h /= 16;
          switch(i) {
            case 0:
              rect[i].x = 12;
              rect[i].y = 284;
              break;
            case 1:
              rect[i].x = 70;
              rect[i].y = 194;
              break;
            case 2:
              rect[i].x = 190;
              rect[i].y = 174;
              break;
            case 3:
              rect[i].x = 400;
              rect[i].y = 284;
              break;
            case 4:
              rect[i].x = 520;
              rect[i].y = 170;
              break;
            case 5:
              rect[i].x = 400;
              rect[i].y = 196;
              break;
          }
        }

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
                        if (idx < 5) {
                          idx++;
                        }
                        else {
                          idx = 0;
                        }
                        break;
                    }
                    break;
                  case 1:
                  // keyboard API for key press
                    switch (event.key.keysym.scancode) {
                      case SDL_SCANCODE_UP:
                          up_check(rect,idx,screen);
                          //rect[idx].y += speed / 30;
                          break;
                      case SDL_SCANCODE_LEFT:
                          rect[idx].x -= speed / 30;
                          break;
                      case SDL_SCANCODE_DOWN:
                          down_check(rect,idx,screen);
                          //rect[idx].y -= speed / 30;
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
                        displayedRifle.x = rect[idx].x;
                        displayedRifle.y = rect[idx].y;
                        rifle.rifleMode = 1;
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
                        break;
                     }
                    break;
                  case 3:
                    switch (event.key.keysym.scancode) {
                      case SDL_SCANCODE_SPACE:
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
                        rifle.angle-=0.1;
                      case SDL_SCANCODE_DOWN:
                        rifle.angle-=0.1;
                      case SDL_SCANCODE_LEFT:
                      case SDL_SCANCODE_RIGHT:

                    }
                }
            }
            move(rect, idx, screen);
            if (rect[idx].x >= maps[1].x + 1) {
              screen = 1;
            }
            if (rect[idx].x <= maps[1].x +1) {
              screen = 0;
            }

            render(rend,tex,rect, mapsText, maps, screenText[mode], &(screens[mode]),&displayedRifle, rifleText, rifle);
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
