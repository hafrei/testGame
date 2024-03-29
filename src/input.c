#include "input.h"

void keyDown(SDL_KeyboardEvent *event)
{
  if(event->repeat == 0)
  {
    if(event->keysym.sym == SDLK_UP)
    {
      player.up = 1;
    }
    if(event->keysym.sym == SDLK_DOWN)
    {
      player.down = 1;
    }
    if(event->keysym.sym == SDLK_LEFT)
    {
      player.left = 1;
    }
    if(event->keysym.sym == SDLK_RIGHT)
    {
      player.right = 1;
    }
    if(event->keysym.sym == SDLK_SPACE)
    {
      player.fire = 1;
    }
  }
}

void keyUp(SDL_KeyboardEvent *event)
{
    if(event->repeat == 0)
  {
    if(event->keysym.sym == SDLK_UP)
    {
      player.up = 0;
    }
    if(event->keysym.sym == SDLK_DOWN)
    {
      player.down = 0;
    }
    if(event->keysym.sym == SDLK_LEFT)
    {
      player.left = 0;
    }
    if(event->keysym.sym == SDLK_RIGHT)
    {
      player.right = 0;
    }
    if(event->keysym.sym == SDLK_SPACE)
    {
      player.fire = 0;
    }
  }
}

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
    
      case SDL_KEYDOWN:
        keyDown(&event.key);
        break;

      case SDL_KEYUP:
        keyUp(&event.key);
        break;

      default:
        break;
    }
  }
}