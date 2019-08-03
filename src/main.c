#include "main.h"

void processInput(void)
{
  if(app.up)
  {
    player.y -= 4;
  }
    if(app.down)
  {
    player.y += 4;
  }
    if(app.left)
  {
    player.x -= 4;
  }
    if(app.right)
  {
    player.x += 4;
  }
}

int main(int argc, char *argv[])
{
  memset(&app, 0, sizeof(App));
  memset(&player, 0, sizeof(Entity));

  initSDL();

  player.x = 100;
  player.y = 100;
  player.texture = loadTexture("resources/EyeMiddle.png");

  if (player.texture == NULL)
  {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Failed to load texture image!\n" );
  }

  while(1){
    prepareScene();

    doInput();

    processInput();

    drawTexture(player.texture, player.x, player.y);

    presentScene();

    SDL_Delay(16);
  }

  atexit(cleanUp);

  return 0;
}