#pragma once
#include "graphics.h"
#include "structs.h"
#include "defs.h"
#include "draw.h"

int InitializeGraphics()
{
	int rendererFlags, windowFlags;

	rendererFlags = SDL_RENDERER_ACCELERATED;

	windowFlags = 0;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("Couldn't initialize SDL: %s\n", SDL_GetError());
		return -1;
	}

	app.window = SDL_CreateWindow("Shooter 01", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, windowFlags);

	if (!app.window)
	{
		printf("Failed to open %d x %d window: %s\n", SCREEN_WIDTH, SCREEN_HEIGHT, SDL_GetError());
		return -1;
	}

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "linear");

	app.renderer = SDL_CreateRenderer(app.window, -1, rendererFlags);

	if (!app.renderer)
	{
		printf("Failed to create renderer: %s\n", SDL_GetError());
		return -1;
	}



	return 0;
}

int PrepareScene()
{
	SDL_SetRenderDrawColor(app.renderer, 96, 128, 255, 255);
	SDL_RenderClear(app.renderer);
}

int DrawObjects()
{
	SDL_Texture* boidTexture;
	boidTexture = LoadTexture("Img/Arrow.png");
	if (scene.boids)
	{
		for (int i = 0; i < scene.boidCount; i++)
		{
			Blit(boidTexture, scene.boids[i].pos.x, scene.boids[i].pos.y);
		}
	}
}

int PresentScene()
{
	SDL_RenderPresent(app.renderer);
}
