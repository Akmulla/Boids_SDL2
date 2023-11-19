#include <stdio.h>
#include <SDL.h>
#include "defs.h"
#include "structs.h"
#include "graphics.h"

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

	int boidCount = 10;

	scene.boidCount = boidCount;
	scene.boids = malloc(sizeof(Boid) * boidCount);

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

