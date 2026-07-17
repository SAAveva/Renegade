#ifndef ANIMATION_H
#define ANIMATION_H

#include <stdint.h>
#include <vectors.h>

extern uint8_t animationList[4];

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

void animationConfig(sprite sprite, uint8_t frameCount, animation* animation);
void animationRemove(animation* animation);

#endif
