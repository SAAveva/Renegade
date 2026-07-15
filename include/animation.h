#ifndef ANIMATION_H
#define ANIMATION_H

#include <vectors.h>

extern unsigned int animationList[4];

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

void animationConfig(sprite sprite, unsigned int frameCount, animation* animation);
void animationRemove(animation* animation);

#endif
