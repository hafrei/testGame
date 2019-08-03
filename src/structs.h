//TODO: I don't like making player movement a pert of the app but it's a first pancake
typedef struct App {
  SDL_Renderer *renderer;
  SDL_Window *window;
  int up;
  int down;
  int left;
  int right;
} App;

typedef struct Entity {
  SDL_Texture *texture;
  int x;
  int y;
} Entity;