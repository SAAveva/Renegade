#include <stdlib.h>
#include <stdint.h>
#include <vectors.h>

typedef enum {
	playerIdle = 0
}sprite;

typedef struct {
	position texCoords;
	scale texDimensions;
}texture;
typedef struct {
	texture* frames;
}animation;

uint8_t animationList[4] = {
	0, 0, 13, 28
};

void animationConfig(sprite sprite, uint8_t frameCount, animation* animation) {
	animation->frames = malloc(frameCount * sizeof(uint8_t));
	for (uint8_t i = 0; i < frameCount; i++) {
		animation->frames[i].texCoords.x = animationList[i * 4 + sprite];
		animation->frames[i].texCoords.y = animationList[i * 4 + 1 + sprite];
		animation->frames[i].texDimensions.width = animationList[i * 4 + 2 + sprite];
		animation->frames[i].texDimensions.height = animationList[i * 4 + 3 + sprite];
	}
}
void animationRemove(animation* animation) {
	free(&(animation->frames));
}
