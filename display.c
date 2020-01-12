#include "display.h"

int init()
{
    //Initialization flag
    int success = 1;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = 0;
    }
    else
    {
        //Create window
        gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = 0;
        }
        else
        {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }

    return success;
}

int loadMedia()
{
    //Loading success flag
    int success = 1;
    char * cwd = NULL;
    getcwd(cwd, sizeof(cwd));
    strcat(cwd, "/map.bmp");
    //Load splash image
    gHelloWorld = SDL_LoadBMP(cwd );
    if( gHelloWorld == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", cwd, SDL_GetError() );
        success = 0;
    }

    return success;
}

void close1()
{
    //Deallocate surface
    SDL_FreeSurface( gHelloWorld );
    gHelloWorld = NULL;

    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}
