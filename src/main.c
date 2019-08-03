#include "main.h"

int main(int argc, char *argv[])
{
  memset(&app, 0, sizeof(App));
  memset(&player, 0, sizeof(Entity));

  initSDL();

  player.x = 100;
  player.y = 100;
  player.texture = loadTexture("resources/EyeMiddle.png");

  atexit(cleanUp);
  
  while(1){
    prepareScene();

    doInput();

    drawTexture(player.texture, player.x, player.y);

    presentScene();

    SDL_Delay(16);
  }
  
  return 0;
}
