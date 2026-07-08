#include <stdio.h>
#include <SDL2/SDL.h>

int main(int argc, char** args) {
	SDL_Surface* winSurface = NULL;
	SDL_Window* window = NULL;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("error initializing sdl: %s \n", SDL_GetError());
		return 1;
	}

	window = SDL_CreateWindow("Renegade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
	if (!window) {
		printf("error crearing window: %s \n", SDL_GetError());
		return 1;
	}

	winSurface = SDL_GetWindowSurface(window);
	if (!winSurface) {
		printf("error getting surface: %s \n", SDL_GetError());
		return 1;
	}

	SDL_FillRect(winSurface, NULL, SDL_MapRGB(winSurface->format, 255, 255, 255));
	SDL_UpdateWindowSurface(window);

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
