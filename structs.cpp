#include "structs.h"

App app;  // Define the global App variable

// Function to initialize the App structure
void initializeApp(SDL_Window *window, SDL_Renderer *renderer) {
    app.window = window;
    app.renderer = renderer;
}