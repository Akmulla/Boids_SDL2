#include <stdio.h>
#include <SDL.h>
#include "defs.h"
#include "structs.h"
#include "graphics.h"

struct App app;

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

	printf("Init\n");

	while (1)
	{
		ProcessInput();
	}

	return 0;
}

