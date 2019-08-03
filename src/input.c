#include "input.h"

void doInput(void)
{
  SDL_Event event;

  while (SDL_PollEvent(&event))
  {
    
    switch (event.type)
    {
      case SDL_QUIT:
        exit(1); 
        break;
    
      default:
        break;
    }
  }
}