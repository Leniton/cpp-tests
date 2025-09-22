#include <SDL3/SDL.h>
#include <SDL3/SDL_keycode.h>
#include <iostream>

void doKeyDown(SDL_KeyboardEvent event)
{
    if (event.repeat != 0){ return;}
    if (event.key == SDLK_W)
    {
        app.up = 1;
    }
    if (event.key == SDLK_S)
    {
        app.down = 1;
    }
    if (event.key == SDLK_A)
    {
        app.left = 1;
    }
    if (event.key == SDLK_D)
    {
        app.right = 1;
    }
    if (event.key == SDLK_SPACE)
    {
        app.fire = 1;
    }

    if (event.key == SDLK_ESCAPE)
    {
        app.quit = 1;
    }
}
void doKeyUp(SDL_KeyboardEvent event)
{
    if (event.repeat != 0) {return;}
    if (event.key == SDLK_W)
    {
        app.up = 0;
    }
    if (event.key == SDLK_S)
    {
        app.down = 0;
    }
    if (event.key == SDLK_A)
    {
        app.left = 0;
    }
    if (event.key == SDLK_D)
    {
        app.right = 0;
    }
    if (event.key == SDLK_SPACE)
    {
        app.fire = 0;
    }

}

void doInput(void)
{
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_EVENT_QUIT:
                exit(0);
                break;
            case SDL_EVENT_KEY_DOWN:
                doKeyDown(event.key);
                break;
            case SDL_EVENT_KEY_UP:
                doKeyUp(event.key);
                break;
            default:
                break;
        }
    }
}