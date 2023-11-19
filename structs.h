#pragma once

#include <SDL.h>

struct App {
	SDL_Renderer* renderer;
	SDL_Window* window;
} app;

struct Vector2
{
	double x;
	double y;
};

typedef struct Vector2 Vector2;

struct Boid
{
	Vector2 pos;
};

typedef struct Boid Boid;

struct Scene
{
	int boidCount;
	Boid* boids;
} scene;