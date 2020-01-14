#include "display.h"

int main(){
  if (!init()) {
        printf("Failed to initialize\n");
      }
  else {
        //Different Types of Modes:
        //Start Mode- mainscreen.bmp - 0
        //Movement Mode- movement screen -1
        //Gun Mode- rifle.bmp - 2
        //Gun Control Mode -3
        int mode = 0;
        SDL_Window * win = SDL_CreateWindow( "Sandbox Wars", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
        if( win == NULL ){
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        // creates a renderer to render our images
        SDL_Renderer* rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
        int idx = 0;
        SDL_Surface* surface;
        char cwd[100];
        getcwd(cwd, 100);
        strcat(cwd, "/stickman.bmp");
        //Load splash image
        surface = SDL_LoadBMP(cwd );
        if( surface == NULL ){
            printf( "Unable to load image %s! SDL Error: %s\n", cwd, SDL_GetError() );
        }

        SDL_Surface* surface2 = NULL;
        getcwd(cwd, 100);
        strcat(cwd, "/map.bmp");
        //Load splash image
        surface2 = SDL_LoadBMP(cwd );
        SDL_Texture* tex2 = SDL_CreateTextureFromSurface(rend, surface2);
        SDL_Rect * background = malloc(sizeof(SDL_Rect));
        SDL_QueryTexture(tex2, NULL, NULL, &(background->w), &(background->h));
        background->x = 0;
        background->y = 0;
        background->w = SCREEN_WIDTH;
        background->h = SCREEN_HEIGHT;

        // loads image to our graphics hardware memory.
        SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);
        SDL_FreeSurface(surface);
        // clears main-memory


        //Creating array of Rect-screens
        //Creating array of Texture screens

        SDL_Rect * screens = malloc(4*sizeof(SDL_Rect));
        SDL_Rect * screenText = malloc(4*sizeof(SDL_Rect));
        char fileName[50];
        for(i=0;i<4;i++){
          switch(i){
            case 0:
              strcpy(fileName,"mainscreen.bmp");
            case 1:
              strcpy(fileName,"movecontrol.bmp");
            case 2:
              strcpy(fileName,"gunscreen.bmp");
            case 3:
              strcpy(fileName,"guncontrol.bmp");
          }
          getcwd(cwd, 100);
          strcat(cwd, fileName);
          //Load splash image
          surface = SDL_LoadBMP(cwd);
          SDL_Texture* tex3 = SDL_CreateTextureFromSurface(rend, surface);
          SDL_Rect *screen;
          SDL_QueryTexture(tex3, NULL, NULL, &screen->w, &screen->h);
          screen->x = 110;
          screen->y = 380;
          if( surface == NULL ){
              printf( "Unable to load image %s! SDL Error: %s\n", cwd, SDL_GetError() );
          }
          SDL_FreeSurface(surface);
          screens[i] = screen;

        }

        // let us control our image position
        // so that we can move it with our keyboard.
        SDL_Rect * rect = malloc(6*sizeof(SDL_Rect));

        // connects our texture with rect to control position
        for (int i = 0; i < 6; i++) {
          SDL_QueryTexture(tex, NULL, NULL, &(rect[i].w), &(rect[i].h));
          if( rect+ i == NULL ){
              printf( "Unable to query texture %d! SDL Error: %s\n", i, SDL_GetError() );
          }
          rect[i].w /= 3;
          rect[i].h /= 3;

          // sets initial x-position of object
          rect[i].x = i * (SCREEN_WIDTH - rect[i].w)/6;

          // sets initial y-position of object
          rect[i].y = (SCREEN_HEIGHT - rect[i].h) / 2;
        }
        // controls annimation loop
        int close = 0;

        // speed of box
        int speed = 300;

        // annimation loop
        while (!close) {
            SDL_Event event;

            // Events mangement
            while (SDL_PollEvent(&event)) {
                switch (event.type) {

                case SDL_QUIT:
                    // handling of close button
                    close = 1;
                    break;

                case SDL_KEYDOWN:
                    // keyboard API for key pressed
                    switch (event.key.keysym.scancode) {
                    case SDL_SCANCODE_UP:
                        rect[idx].y -= speed / 30;
                        break;
                    case SDL_SCANCODE_LEFT:
                        rect[idx].x -= speed / 30;
                        break;
                    case SDL_SCANCODE_DOWN:
                        rect[idx].y += speed / 30;
                        break;
                    case SDL_SCANCODE_RIGHT:
                        rect[idx].x += speed / 30;
                        break;
                    case SDL_SCANCODE_RETURN:
                        if (idx < 5) {
                          idx++;
                        }
                        else {
                          idx = 0;
                        }
                        break;
                    }
                }
            }
/*
            // right boundary
            if (rect.x + rect.w > 1000)
                rect.x = 1000 - rect.w;
            // left boundary
            if (rect.x < 0)
                rect.x = 0;
            // bottom boundary
            if (rect.y + rect.h > 1000)
                rect.y = 1000 - rect.h;
            // upper boundary
            if (rect.y < 0)
                rect.y = 0;
*/
            render(rend,tex,rect, tex2, background, tex3, gun_screen);
        }

        // rectroy texture
        free(rect);
        free(background);
        close1(rend,tex,win);
      }


  return 0;
}
