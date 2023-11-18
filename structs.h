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

struct Boid
{
	struct Vector2 pos;
};