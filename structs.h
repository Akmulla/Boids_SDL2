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
void AddVector(Vector2* add_target, Vector2* b);
void MultiplyVector(Vector2* v, double c);
float GetAngle(Vector2 v1, Vector2 v2);

struct Boid
{
	Vector2 pos;
	Vector2 v;
	float rotation;
};

typedef struct Boid Boid;

struct Scene
{
	int boidCount;
	Boid* boids;
} scene;