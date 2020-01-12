//Using SDL and standard IO
#include "display.h"

int main( int argc, char* args[] ){
  //Start up SDL and create window
  if( !init() ){
		printf( "Failed to initialize!\n" );
	}
	else{
    if( !loadMedia() )
		{
			printf( "Failed to load media!\n" );
		}
		else {
      int quit = 0;
      SDL_Event e;
      while (!quit) {
        while( SDL_PollEvent( &e ) != 0 ) {
           //User requests quit
           if( e.type == SDL_QUIT )
           {
             quit = 1;
             printf("Closing the window ...\n");
           }
           //Apply the image
          SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );

          //Update the surface
          SDL_UpdateWindowSurface( gXOut );
       }
      }
    }
  }
  close1();
  return 0;
}
