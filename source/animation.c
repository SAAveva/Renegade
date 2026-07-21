#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <vectors.h>
#include <world.h>
#include <animation.h>

void animationConfig(sprite sprite, uint8_t frameCount, animation* animation) {
	FILE* animations;
	animations = fopen("data/animations.bin", "rb");

	animation->frames = malloc(frameCount * sizeof(uint8_t));
	for (uint8_t i = 0; i < frameCount; i++) {
		fseek(animations, sizeof(uint8_t) * sprite, SEEK_SET);

		fread(&animation->frames[i].texCoords.x, sizeof(uint8_t), 1, animations);
		fread(&animation->frames[i].texCoords.y, sizeof(uint8_t), 1, animations);
		fread(&animation->frames[i].texDimensions.width, sizeof(uint8_t), 1, animations);
		fread(&animation->frames[i].texDimensions.height, sizeof(uint8_t), 1, animations);
	}
	fclose(animations);
}
void animationRemove(animation* animation) {
	free(&(animation->frames));
}
void playAnimations(SDL_Renderer* renderer, SDL_Texture* spritesheet) {
	if (World.Player.active) {
		SDL_Rect renderQuad = {
			World.Player.transform.position.x,
			World.Player.transform.position.y,
			World.Player.transform.scale.width,
			World.Player.transform.scale.height
		};
		SDL_Rect clip = {
			World.Player.animations[World.Player.animationPlaying].frames[World.Player.frameClock].texCoords.x,
			World.Player.animations[World.Player.animationPlaying].frames[World.Player.frameClock].texCoords.y,
			World.Player.animations[World.Player.animationPlaying].frames[World.Player.frameClock].texDimensions.width,
			World.Player.animations[World.Player.animationPlaying].frames[World.Player.frameClock].texDimensions.height
		};

		SDL_RenderCopy(renderer, spritesheet, &clip, &renderQuad);
		if (World.Player.frameClock < World.Player.frameCount) {
			World.Player.frameClock++;
		} else {
			World.Player.frameClock = 0;
		}
	}
	for (uint8_t i = 0; i < 16; i++) {
		if (World.enemies[i].active) {
			SDL_Rect renderQuad = {
				World.enemies[i].transform.position.x,
				World.enemies[i].transform.position.y,
				World.enemies[i].transform.scale.width,
				World.enemies[i].transform.scale.height
			};
			SDL_Rect clip = {
				World.enemies[i].animations[World.enemies[i].animationPlaying].frames[World.enemies[i].frameClock].texCoords.x,
				World.enemies[i].animations[World.enemies[i].animationPlaying].frames[World.enemies[i].frameClock].texCoords.y,
				World.enemies[i].animations[World.enemies[i].animationPlaying].frames[World.enemies[i].frameClock].texDimensions.width,
				World.enemies[i].animations[World.enemies[i].animationPlaying].frames[World.enemies[i].frameClock].texDimensions.height
			};

			SDL_RenderCopy(renderer, spritesheet, &clip, &renderQuad);
		}
	}
	for (uint8_t i = 0; i < 32; i++) {
		if (World.elements[i].active) {
			SDL_Rect renderQuad = {
				World.elements[i].transform.position.x,
				World.elements[i].transform.position.y,
				World.elements[i].transform.scale.width,
				World.elements[i].transform.scale.height
			};
			SDL_Rect clip = {
				World.elements[i].animation.frames[World.elements[i].frameClock].texCoords.x,
				World.elements[i].animation.frames[World.elements[i].frameClock].texCoords.y,
				World.elements[i].animation.frames[World.elements[i].frameClock].texDimensions.width,
				World.elements[i].animation.frames[World.elements[i].frameClock].texDimensions.height
			};

			SDL_RenderCopy(renderer, spritesheet, &clip, &renderQuad);
		}
	}
	for (uint8_t i =0; i < 8; i++) {
		if (World.interactables[i].active) {
			SDL_Rect renderQuad = {
				World.interactables[i].transform.position.x,
				World.interactables[i].transform.position.y,
				World.interactables[i].transform.scale.width,
				World.interactables[i].transform.scale.height
			};
			SDL_Rect clip = {
				World.interactables[i].animations[World.interactables[i].animationPlaying].frames[World.interactables[i].frameClock].texCoords.x,
				World.interactables[i].animations[World.interactables[i].animationPlaying].frames[World.interactables[i].frameClock].texCoords.y,
				World.interactables[i].animations[World.interactables[i].animationPlaying].frames[World.interactables[i].frameClock].texDimensions.width,
				World.interactables[i].animations[World.interactables[i].animationPlaying].frames[World.interactables[i].frameClock].texDimensions.height
			};

			SDL_RenderCopy(renderer, spritesheet, &clip, &renderQuad);
		}
	}
}
