#ifndef INPUT_H
#define INPUT_H

#include <stdbool.h>
#include <SDL2/SDL.h>

void processInput(SDL_Event eventHandler, bool* quit, bool* grounded);

#endif
