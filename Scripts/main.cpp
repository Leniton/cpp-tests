#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>
#include "structs.cpp"
#include "init.cpp"
#include "input.cpp"
#include "draw.cpp"
#include "test.h"

Entity e;
Entity bullet;

void cleanup() 
{
    SDL_DestroyTexture(e.texture);
    std::cout << "Cleanup function called at program exit!" << std::endl;
}

int main(int argc, char* argv[]) 
{
    initSDL();

    e.x = 100;
    e.y = 100;
    e.texture = loadTexture((char*)"Assets/kuru.gif");

    bullet.texture = loadTexture("Assets/kuru.jpg");

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

        if (app.fire && bullet.health == 0)
        {
            bullet.x = e.x;
            bullet.y = e.y;
            bullet.dx = 16;
            bullet.dy = 0;
            bullet.health = 1;
        }

        bullet.x += bullet.dx;
        bullet.y += bullet.dy;

        if (bullet.x > SCREEN_WIDTH)
        {
            bullet.health = 0;
        }

        blit(e.texture, e.x, e.y,.2);

        if (bullet.health > 0)
        {
            blit(bullet.texture, bullet.x, bullet.y,.02);
        }

        presentScene();

        SDL_Delay(16);
    }

    return 0;
}