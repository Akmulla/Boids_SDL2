#include "draw.h"
#include "structs.h"

SDL_Texture* LoadTexture(char* filename)
{
	SDL_Texture* texture;

	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

	texture = IMG_LoadTexture(app.renderer, filename);

	return texture;
}

void Blit(SDL_Texture* texture, int x, int y)
{
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	//SDL_Texture* boidTexture = LoadTexture("Img/Arrow.png");
	//int result = SDL_QueryTexture(boidTexture, NULL, NULL, &dest.w, &dest.h);
	int result = SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(app.renderer, texture, NULL, &dest);
	//if (result)
	//{
	//	SDL_RenderCopy(app.renderer, texture, NULL, &dest);
	//}
	//else
	//{
	//	printf("error quering texture");
	//}
	
}