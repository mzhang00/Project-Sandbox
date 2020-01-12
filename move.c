#include "move.h"

void move(SDL_Event ev, SDL_Rect * rec) {
  switch( ev.key.keysym.sym ){
      case SDLK_UP:
      //CS = KPS[ KEY_PRESS_SURFACE_UP ];
      rec->y+= 10;
      break;

      case SDLK_DOWN:
      //CS = KPS[ KEY_PRESS_SURFACE_DOWN ];
      rec->y-=10;
      break;

      case SDLK_LEFT:
      //CS = KPS[ KEY_PRESS_SURFACE_LEFT ];
      rec->x-=10;
      break;

      case SDLK_RIGHT:
      //CS = KPS[ KEY_PRESS_SURFACE_RIGHT ];
      rec->x+=10;
      break;

      default:
      //CS = KPS[ KEY_PRESS_SURFACE_DEFAULT ];
      break;
    }
}
