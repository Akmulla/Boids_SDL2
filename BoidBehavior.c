#include "BoidBehavior.h"

void ProcessSeparation()
{

}

void ProcessCohesion()
{

}

void ProcessAlignment()
{

}

void ApplyMovement()
{
	for (int i = 0; i < scene.boidCount; i++)
	{
		scene.boids[i].pos += scene.boids[i].v;
	}
}