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

void ProcessBoids(Boid* boids, int boidCount)
{
	for (int i = 0; i < boidCount; i++)
	{
		Vector2 up = (Vector2){ 0,1 };
		Vector2 v = boids[i].v;
		double angle = GetAngle(v, up);
		boids[i].rotation = angle + 90;
		MultiplyVector(&v, DELTATIME);
		AddVector(&boids[i].pos, &v);
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

	Boid* boids = (Boid* )malloc(sizeof(Boid) * boidCount);

	if (boids)
	{
		for (int i = 0; i < boidCount; i++)
		{
			boids[i].pos.x = 100 + 100 * (double)i;
			boids[i].pos.y = 300;
			boids[i].rotation = i * 30.;
			boids[i].v = (Vector2) { 20,0 };
		}
	}

	scene.boidCount = boidCount;
	scene.boids = boids;

	printf("Init\n");

	while (1)
	{
		ProcessInput();
		PrepareScene();
		ProcessBoids(boids, boidCount);
		DrawObjects();
		PresentScene();

		SDL_Delay(TICK_RATE);
	}

	return 0;
}
