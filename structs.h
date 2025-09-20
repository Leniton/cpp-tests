#ifndef APP_H
#define APP_H
#include <SDL.h>

typedef struct {
    SDL_Renderer *renderer;
    SDL_Window *window;
} App;

extern App app;
#endif // APP_H