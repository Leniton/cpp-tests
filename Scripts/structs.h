#pragma once
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

class Entity {
    public:
    float x;
    float y;

    float dx;
    float dy;
    int health;
    SDL_Texture *texture;
};

class player : Entity
{
};