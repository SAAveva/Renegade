#pragma once

typedef struct {
	float x;
	float y;
}position;

typedef struct {
	float width;
	float height;
}scale;

typedef struct {
	float x;
	float y;
}velocity;

typedef struct {
	float x;
	float y;
}knockback;

typedef struct {
	position position;
	velocity velocity;
	scale scale;
}transform;
