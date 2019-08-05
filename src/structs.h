//TODO: I don't like making player movement a part of the app but it's a first pancake
typedef struct App {
  SDL_Renderer *renderer;
  SDL_Window *window;
} App;

typedef struct Entity {
  SDL_Texture *texture;
  int x;
  int y;
  int dx;
  int dy;
  int hp;
} Entity;

typedef struct Player {
  Entity en;
  int up;
  int down;
  int left;
  int right;
  int fire;
} Player;