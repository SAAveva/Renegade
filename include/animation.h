#ifndef ANIMATION_H
#define ANIMATION_H

#include <vectors.h>

extern unsigned int animationList[4];

typedef enum {
	player_idle = 0
}sprite;

typedef struct {
	position texcoords;
	scale texdimensions;
}texture;

typedef struct{
	texture* frames;
}animation;

void animationConfig(sprite sprite, unsigned int frameCount, animation* animation) {
	animation->frames = malloc(frameCount * sizeof(texture));
	for (unsigned int i = 0; i < frameCount; i++) {
		animation->frames[i].texcoords.x = animationList[i * 4 + sprite + 0];
		animation->frames[i].texcoords.y = animationList[i * 4 + sprite + 1];
		animation->frames[i].texdimensions.width = animationList[i * 4 + sprite + 2];
		animation->frames[i].texdimensions.height = animationList[i * 4 + sprite + 3];
	}
}
void animationRemove(animation* animation) {
	free(&(animation->frames));
}

#endif
