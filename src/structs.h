typedef struct App {
  SDL_Renderer *renderer;
  SDL_Window *window;
} App;

typedef struct Entity {
  int x;
  int y;
  SDL_Texture *texture;
} Entity;