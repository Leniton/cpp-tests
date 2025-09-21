#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>
#include "structs.cpp"
#include "init.cpp"
#include "input.cpp"
#include "draw.cpp"

Entity e;

void cleanup() 
{
    SDL_DestroyTexture(e.texture);
    std::cout << "Cleanup function called at program exit!" << std::endl;
}

int main(int argc, char* argv[]) 
{
    initializeApp(NULL,NULL);
    initSDL();

    e.x = 100;
    e.y = 100;
    e.texture = loadTexture((char*)"kuru.gif");

    atexit(cleanup);

    while (true)
    {
        prepareScene();

        doInput();

        blit(e.texture, e.x, e.y);

        presentScene();

        SDL_Delay(16);
    }

    return 0;
}