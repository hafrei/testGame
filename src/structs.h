//TODO: I don't like making player movement a part of the app but it's a first pancake
typedef struct App {
  SDL_Renderer *renderer;
  SDL_Window *window;
  int up;
  int down;
  int left;
  int right;
  int fire;
} App;

typedef struct Entity {
  SDL_Texture *texture;
  int x;
  int y;
  int dx;
  int dy;
  int hp;
} Entity;