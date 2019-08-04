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
  if(app.fire && shot.hp == 0)
  {
    shot.x = player.x;
    shot.y = player.y;
    shot.dx = 16;
    shot.dy = 0;
    shot.hp = 1;
  }
}

int main(int argc, char *argv[])
{
  memset(&app, 0, sizeof(App));
  memset(&player, 0, sizeof(Entity));
  memset(&shot, 0, sizeof(Entity));

  initSDL();

  player.x = 100;
  player.y = 100;
  player.hp = 10;

  player.texture = loadTexture("resources/EyeMiddle.png");
  shot.texture = loadTexture("resources/Shot.png");

  if (player.texture == NULL)
  {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Failed to load texture image!\n" );
  }

  while(1){
    prepareScene();

    doInput();

    player.x += player.dx;
    player.y += player.dy;

    processInput();

    shot.x += shot.dx;
    shot.y += shot.dy;

    drawTexture(player.texture, player.x, player.y);
    
    if (shot.hp > 0)
    {
      drawTexture(shot.texture, shot.x, shot.y);
    }

    presentScene();

    SDL_Delay(16);
  }

  atexit(cleanUp);

  return 0;
}