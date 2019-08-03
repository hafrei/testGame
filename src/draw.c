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
  SDL_Surface* loadedSurface = IMG_Load( filename );

  if( loadedSurface == NULL ) 
  { 
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Unable to load image %s! SDL_image Error: %s\n", filename, IMG_GetError() ); 
  } 
  else 
  {
  SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

  texture = SDL_CreateTextureFromSurface(app.renderer, loadedSurface);

  if( texture == NULL ) 
  { 
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Unable to load image %s! SDL_image Error: %s\n", filename, IMG_GetError() ); 
  } 

  SDL_FreeSurface(loadedSurface);

  }
  
  return texture;
}

void drawTexture(SDL_Texture *texture, int x, int y)
{
  SDL_Rect rect;

  rect.x = x;
  rect.y = y;

  //NULL, NULL because we're not reading a portion of a file
  SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);

  //Actually draws the texture
  SDL_RenderCopy(app.renderer, texture, NULL, &rect);
  
}