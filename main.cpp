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

    while (!app.quit)
    {
        prepareScene();

        doInput();

        if (app.up)
        {
            e.y -= 4;
        }

        if (app.down)
        {
            e.y += 4;
        }

        if (app.left)
        {
            e.x -= 4;
        }

        if (app.right)
        {
            e.x += 4;
        }

        blit(e.texture, e.x, e.y,.2);

        presentScene();

        SDL_Delay(16);
    }

    return 0;
}