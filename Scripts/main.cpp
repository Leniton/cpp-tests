#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>
#include <iostream>
#include "structs.h"
#include "init.h"
#include "input.h"
#include "draw.h"

Entity player;
Entity bullet;

void cleanup() 
{
    SDL_DestroyTexture(player.texture);
    SDL_DestroyTexture(bullet.texture);
    std::cout << "Cleanup function called at program exit!" << std::endl;
}

int main(int argc, char* argv[]) 
{
    initSDL();

    player.x = 100;
    player.y = 100;
    player.texture = loadTexture((char*)"Assets/kuru.gif");

    bullet.texture = loadTexture("Assets/kuru.jpg");

    atexit(cleanup);

    while (!app.quit)
    {
        prepareScene();

        doInput();

        if (app.up)
        {
            player.y -= 4;
        }

        if (app.down)
        {
            player.y += 4;
        }

        if (app.left)
        {
            player.x -= 4;
        }

        if (app.right)
        {
            player.x += 4;
        }

        if (app.fire && bullet.health == 0)
        {
            bullet.x = player.x;
            bullet.y = player.y;
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

        blit(player.texture, player.x, player.y,.2);

        if (bullet.health > 0)
        {
            blit(bullet.texture, bullet.x, bullet.y,.02);
        }

        presentScene();

        SDL_Delay(16);
    }

    return 0;
}