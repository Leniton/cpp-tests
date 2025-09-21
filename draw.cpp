#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include "structs.h"

void prepareScene()
{
    SDL_SetRenderDrawColor(app.renderer, 96, 128, 128, 255);
    SDL_RenderClear(app.renderer);
}

void presentScene()
{
    SDL_RenderPresent(app.renderer);
}

SDL_Texture *loadTexture(char *filename)
{
    SDL_Texture *texture;

    SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

    texture = IMG_LoadTexture(app.renderer, filename);

    return texture;
}

void blit(SDL_Texture *texture, float x, float y)
{
    SDL_FRect dest;

    dest.x = x;
    dest.y = y;
    dest.w = 50;
    dest.h = 50;
    //SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

    //SDL_RenderCopy(app.renderer, texture, NULL, &dest);
    SDL_RenderTexture(app.renderer, texture, NULL, &dest);
}