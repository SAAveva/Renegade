#include <stdbool.h>
#include <SDL2/SDL.h>

#include "world.h"
#include "physics.h"

void processInput(SDL_Event eventHandler, bool* quit, bool* grounded) {
	switch (eventHandler.type) {
		case SDL_QUIT:
			*quit = true;
			break;
		case SDL_KEYDOWN:
			switch (eventHandler.key.keysym.sym) {
				case SDLK_w:
					break;
				case SDLK_a:
					World.Player.transform.velocity.x = -World.Player.speed;
					break;
				case SDLK_s:
					break;
				case SDLK_d:
					World.Player.transform.velocity.x = World.Player.speed;
					break;
				case SDLK_LSHIFT:
					if (World.Player.transform.velocity.x >= World.Player.speed) {
						World.Player.transform.velocity.x *= 1.5f * World.Player.speed;
					}
					break;
				case SDLK_SPACE:
					if (*grounded) {
						*grounded = false;
						World.Player.transform.velocity.y = 250.0;
					}
					break;
				case SDLK_TAB:
					break;
				case SDLK_RETURN:
					break;
				case SDLK_ESCAPE:
					*quit = true;
					break;
				}
			break;
		case SDL_MOUSEBUTTONUP:
			switch (eventHandler.button.button) {
				case SDL_BUTTON_LEFT:
					break;
				case SDL_BUTTON_RIGHT:
					break;
			}
			break;
	}
}
