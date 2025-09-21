#ifndef APP_H
#define APP_H
#include <SDL3/SDL.h>

typedef struct {
    SDL_Renderer *renderer;
    SDL_Window *window;
    int quit;

    int up;
    int down;
    int left;
    int right;
} App;

extern App app;

typedef struct {
    float x;
    float y;
    SDL_Texture *texture;
} Entity;
#endif // APP_H