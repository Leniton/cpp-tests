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
    int fire;
} App;

App app;

typedef struct {
    float x;
    float y;

    float dx;
    float dy;
    int health;
    SDL_Texture *texture;
} Entity;
#endif // APP_H