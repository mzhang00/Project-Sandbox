#include "display.h"

int main(){
  if (!init()) {
        printf("Failed to initialize\n");
      }
  else {
        SDL_Window * win = SDL_CreateWindow( "Sandbox Wars", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
        if( win == NULL ){
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
        }
        // creates a renderer to render our images
        SDL_Renderer* rend = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

        SDL_Surface* surface;
        char cwd[100];
        getcwd(cwd, 100);
        strcat(cwd, "/stickman.bmp");
        //Load splash image
        surface = SDL_LoadBMP(cwd );
        if( surface == NULL ){
            printf( "Unable to load image %s! SDL Error: %s\n", cwd, SDL_GetError() );
        }

        // loads image to our graphics hardware memory.
        SDL_Texture* tex = SDL_CreateTextureFromSurface(rend, surface);
        // clears main-memory
        SDL_FreeSurface(surface);

        // let us control our image position
        // so that we can move it with our keyboard.
        SDL_Rect rect;

        // connects our texture with rect to control position
        SDL_QueryTexture(tex, NULL, NULL, &rect.w, &rect.h);

        // adjust height and width of our image box.
        rect.w /= 6;
        rect.h /= 6;

        // sets initial x-position of object
        rect.x = (SCREEN_WIDTH - rect.w) / 2;

        // sets initial y-position of object
        rect.y = (SCREEN_HEIGHT - rect.h) / 2;

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
                    case SDL_SCANCODE_W:
                    case SDL_SCANCODE_UP:
                        rect.y -= speed / 30;
                        break;
                    case SDL_SCANCODE_A:
                    case SDL_SCANCODE_LEFT:
                        rect.x -= speed / 30;
                        break;
                    case SDL_SCANCODE_S:
                    case SDL_SCANCODE_DOWN:
                        rect.y += speed / 30;
                        break;
                    case SDL_SCANCODE_D:
                    case SDL_SCANCODE_RIGHT:
                        rect.x += speed / 30;
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
            render(rend,tex,&rect);
        }

        // rectroy texture
        close1(rend,tex,win);
      }


  return 0;
}
