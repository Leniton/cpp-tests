#include <SDL.h>
#include "structs.h"

void prepareScene(void)
{
    SDL_SetRenderDrawColor(app.renderer, 96, 128, 128, 255);
    SDL_RenderClear(app.renderer);
}

void presentScene(void)
{
    SDL_RenderPresent(app.renderer);
}