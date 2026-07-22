#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

#include "world.h"
#include "physics.h"
#include "animation.h"
#include "input.h"
#include "game.h"

SDL_Window* window = NULL;
SDL_Renderer* renderer = NULL;
SDL_Texture* spritesheet = NULL;

world World;

bool grounded = false;
bool quit = false;

bool gameInit() {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("error initializing sdl: %s\n", SDL_GetError());
		return false;
	}

	window = SDL_CreateWindow("Renegade", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
	if (!window) {
		printf("error creating window: %s\n", SDL_GetError());
		return false;
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (!renderer) {
		printf("error creating renderer: %s\n", SDL_GetError());
		return false;
	}

	World.Player.transform.position = (Vec) { .x = 0.0, .y = 0.0 };
	World.Player.transform.velocity = (Vec) { .x = 0.0, .y = 0.0 };

	animationConfig(playerIdle, 1, &World.Player.animations[0]);

	World.Player.animationPlaying = 0;
	World.Player.active = true;

	loadSpritesheet();

	return true;
}

bool loadSpritesheet() {
	SDL_Surface* temp = SDL_LoadBMP("assets/spritesheet.bmp");
	if (!temp) {
		printf("error loading spritesheet: %s\n", SDL_GetError());
		return false;
	}
	spritesheet = SDL_CreateTextureFromSurface(renderer, temp);
	SDL_FreeSurface(temp);
	if (!spritesheet) {
		printf("error converting spritesheet: %s\n", SDL_GetError());
		return false;
	}
	return true;
}

void killWindow() {
	SDL_DestroyTexture(spritesheet);
	spritesheet = NULL;

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	window = NULL;
	renderer = NULL;

	SDL_Quit();
}

int main(int argc, char** args) {
	if (!gameInit()) {
		fprintf(stderr, "Game couldn't initalize\n");
		return 1;
	}

	SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);

	SDL_Event eventHandler;
	while (!quit) {
		while (SDL_PollEvent(&eventHandler)) {
			processInput(eventHandler, &quit, &grounded);
		}
		SDL_RenderClear(renderer);

		physicsUpdatePlayer(&grounded);
		physicsUpdateEnemy();

		playAnimations(renderer, spritesheet);
		SDL_RenderPresent(renderer);
	}
	killWindow();

	return 0;
}
