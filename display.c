#include "display.h"

int init()
{
    //Initialization flag
    int success = 1;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_EVERYTHING ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = 0;
    }

    return success;
}

int loadMedia(SDL_Surface * gXOut){
    //Loading success flag
    int success = 1;
    char cwd[100];
    getcwd(cwd, 100);
    strcat(cwd, "/map.bmp");
    //Load splash image
    gXOut = SDL_LoadBMP(cwd );
    if( gXOut == NULL ){
        printf( "Unable to load image %s! SDL Error: %s\n", cwd, SDL_GetError() );
        success = 0;
    }
    return success;
}

void close1(SDL_Renderer * rend,SDL_Texture * tex, SDL_Window * win ){
    SDL_DestroyTexture(tex);
    tex = NULL;

    SDL_DestroyRenderer(rend);
    rend = NULL;
    //Destroy window
    SDL_DestroyWindow( win );
    win = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}

void clear(SDL_Renderer * renderer) {
    //SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
}

void render(SDL_Renderer* rend, SDL_Texture * tex, SDL_Rect *rect, SDL_Texture ** texts, SDL_Rect * rects, SDL_Texture * tex3, SDL_Rect * rect3,SDL_Rect * displayedRifle, SDL_Texture *rifleText, struct rifleGun rifle) {
  SDL_RenderClear(rend);
  for (int i = 0; i < 2;i++) {
    SDL_RenderCopy(rend, texts[i], NULL, &(rects[i]));
  }
  for (int i = 0; i < 6;i++) {
    SDL_RenderCopy(rend, tex, NULL, &(rect[i]));
  }
  SDL_RenderCopy(rend, tex3, NULL, rect3);

  //Displays rifle
  if(rifle.rifleMode){
    SDL_RenderCopyEx(rend,rifleText,NULL,displayedRifle,rifle.angle,&(rifle.center),rifle.flip);
  }


  // triggers the double buffers
  // for multiple rendering
  SDL_RenderPresent(rend);

  // calculates to 60 fps
  SDL_Delay(1000 / 60);
}
void calculateCenter(struct rifleGun * rifle, SDL_Rect displayedRifle){
  int finalX = displayedRifle.x;//+displayedRifle.w/2;
  int finalY = displayedRifle.y;//+displayedRifle.h/2;
  (&(rifle->center))->x =0;
  (&(rifle->center))->y =0;
}
