#include <SDL.h>
#include <iostream>
#include "structs.cpp"
#include "init.cpp"
#include "input.cpp"
#include "draw.cpp"

void cleanup() {
    std::cout << "Cleanup function called at program exit!" << std::endl;
}

int main(int argc, char* argv[]) 
{
    initializeApp(NULL,NULL);
    initSDL();

    atexit(cleanup);

    while (1)
    {
        prepareScene();

        doInput();

        presentScene();

        SDL_Delay(16);
    }

    return 0;
}