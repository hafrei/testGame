#include "common.h"

extern void initSDL(void);
extern void cleanUp(void);
extern void prepareScene(void);
extern void presentScene(void);
extern void doInput(void);
extern SDL_Texture *loadTexture(char *filename);

App app;
Entity player;