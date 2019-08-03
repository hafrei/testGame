#include "common.h"

extern void initSDL(void);
extern void cleanUp(void);
extern void prepareScene(void);
extern void presentScene(void);
extern void doInput(void);
extern SDL_Texture *loadTexture(char *filename);
extern void drawTexture(SDL_Texture *texture, int x, int y);

App app;
Entity player;