#include "main.h"

void processInput(void)
{
  if(player.up)
  {
    player.en.y -= 4;
  }
  if(player.down)
  {
    player.en.y += 4;
  }
  if(player.left)
  {
    player.en.x -= 4;
  }
  if(player.right)
  {
    player.en.x += 4;
  }
  if(player.fire && shot.hp == 0)
  {
    shot.x = player.en.x;
    shot.y = player.en.y;
    shot.dx = 16;
    shot.dy = 0;
    shot.hp = 1;
  }
}

int main(int argc, char *argv[])
{
  memset(&app, 0, sizeof(App));
  memset(&shot, 0, sizeof(Entity));
  memset(&player, 0, sizeof(Player));

  initSDL();

  player.en.x = 100;
  player.en.y = 100;
  player.en.hp = 10;

  player.en.texture = loadTexture("resources/EyeMiddle.png");
  shot.texture = loadTexture("resources/Shot.png");

  if (player.en.texture == NULL)
  {
    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Failed to load texture image!\n" );
  }

  while(1){
    prepareScene();

    doInput();

    player.en.x += player.en.dx;
    player.en.y += player.en.dy;

    processInput();

    shot.x += shot.dx;
    shot.y += shot.dy;

    drawTexture(player.en.texture, player.en.x, player.en.y);
    
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