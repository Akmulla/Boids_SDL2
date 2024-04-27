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

void ProcessBoids(Boid* boids)
{

}

int main()
{
	if (InitializeGraphics(&app) < 0)
	{
		printf("Could not initialize graphics\n");
		return -1;
	}
	
	int boidCount = 10;

	Boid* boids = (Boid* )malloc(sizeof(Boid) * boidCount);

	if (boids)
	{
		for (int i = 0; i < boidCount; i++)
		{
			boids[i].pos.x = 100 + 100 * (double)i;
			boids[i].pos.y = 100;
			boids[i].rotation = i * 30.;
		}
	}

	scene.boidCount = boidCount;
	scene.boids = boids;

	printf("Init\n");

	while (1)
	{
		ProcessInput();
		PrepareScene();
		ProcessBoids(boids);
		DrawObjects();
		PresentScene();

		SDL_Delay(16);
	}

	return 0;
}

