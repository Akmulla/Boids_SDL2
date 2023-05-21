#include <stdio.h>
#include <SDL.h>
#include "defs.h"
#include "structs.h"
#include "graphics.h"

struct App app;

int main()
{
	if (InitializeGraphics(&app) < 0)
	{
		printf("Could not initialize graphics\n");
		return -1;
	}


	printf("Init\n");

	return 0;
}