#include <stdio.h>
#include <SDL.h>
#include "defs.h"
#include "structs.h"
#include "graphics.h"
#include <SDL_image.h>

void ProcessInput(void)
{
	SDL_Event e;

	while (SDL_PollEvent(&e))
	{
		switch (e.type)
		{
		case SDL_QUIT:
			exit(0);
			break;
		}
	}
}

int main()
{


	if (InitializeGraphics(&app) < 0)
	{
		printf("Could not initialize graphics\n");
		return -1;
	}
	
	int boidCount = 1;

	Boid* boids = (Boid* )malloc(sizeof(Boid) * boidCount);

	if (boids)
	{
		for (int i = 0; i < boidCount; i++)
		{
			boids[i].pos.x = 100;
			boids[i].pos.y = 100;
		}
	}

	scene.boidCount = boidCount;
	scene.boids = boids;

	printf("Init\n");

	while (1)
	{
		ProcessInput();
		PrepareScene();
		DrawObjects();
		PresentScene();

		SDL_Delay(16);
	}

	return 0;
}

