//Using SDL and standard IO
#include "display.h"


int main( int argc, char* args[] ){
  //Start up SDL and create window
   if( !init() ){
     printf( "Failed to initialize!\n" );
   }
   else{ //Load media
     if( !loadMedia() ){
       printf( "Failed to load media!\n" );
     }
     else{
       //Apply the image
       SDL_BlitSurface( gHelloWorld, NULL, gScreenSurface, NULL );

       SDL_UpdateWindowSurface( gWindow );

       SDL_Delay( 2000 );
     }
   }
   close1();

  return 0;
}
