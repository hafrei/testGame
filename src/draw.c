#include "draw.h"

void prepareScene(void)
{
  SDL_SetRenderDrawColor(app.renderer, 100, 0, 50, 255);
  SDL_RenderClear(app.renderer);
}

void presentScene(void)
{
  SDL_RenderPresent(app.renderer);
}

//We are defining a loading texture pointer
SDL_Texture *loadTexture(char *filename)
{
  SDL_Texture *texture;

  texture = IMG_LoadTexture(app.renderer, filename);

  return texture;
}

void drawTexture(SDL_Texture *texture, int x, int y)
{
  SDL_Rect rect;

  rect.x = x;
  rect.y = y;

  //NULL, NULL because we're not reading a portion of a file
  SDL_QueryTexture(texture, NULL, NULL, &rect.x, &rect.y);

  //Actually draws the texture
  SDL_RenderCopy(app.renderer, texture, NULL, &rect);
}