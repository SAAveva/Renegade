#include <stdio.h>
#include <SDL2/SDL.h>
#include <world.h>
#include <physics.h>
#include <animation.h>

SDL_Window* window;
SDL_Surface* winSurface;
SDL_Surface* spritesheet;

world world;

unsigned int init() {
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
	return 0;
}

unsigned int loadSpritesheet() {
	SDL_Surface* temp = SDL_LoadBMP("assets/spritesheet.bmp");
	if (!temp) {
		printf("error loading spritesheet: %s \n", SDL_GetError());
		return 1;
	}
	spritesheet = SDL_ConvertSurface(temp, winSurface->format, 0);
	SDL_FreeSurface(temp);
	if (!spritesheet) {
		printf("error converting spritesheet: %s \n", SDL_GetError());
		return 1;
	}
	return 0;
}

void killWindow() {
	SDL_FreeSurface(spritesheet);

	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main(int argc, char** args) {
	if (init() || loadSpritesheet()) return 1;

	SDL_FillRect(winSurface, NULL, SDL_MapRGB(winSurface->format, 255, 255, 255));
	SDL_UpdateWindowSurface(window);

	killWindow();
	return 0;
}
