#ifndef WORLD_H
#define WORLD_H

#include <stdbool.h>
#include <vectors.h>
#include <animation.h>

typedef struct {
	animation animations[9];
	transform transform;
	unsigned int hp;
	unsigned int defense;
	unsigned int speed;
	unsigned int power;
	unsigned int mass;
}player;

typedef struct {
	animation animations[16];
	transform transform;
	unsigned int hp;
	unsigned int defense;
	unsigned int speed;
	unsigned int power;
	unsigned int mass;
	bool canCollide;
}enemy;

typedef struct {
	animation animations[3];
	transform transform;
	bool canCollide;
}interactable;

typedef struct {
	animation animation;
	transform transform;
	unsigned int mass;
	bool anchored;
	bool canCollide;
}element;

typedef struct {
	elememt elememts[32];
	enemy enemies[16];
	player Player;
	interactables interactables[8];
}world;

extern world world;

#endif
