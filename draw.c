#include "draw.h"
#include "structs.h"

SDL_Texture* LoadTexture(char* filename, SDL_Texture** texture)
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

	*texture = IMG_LoadTexture(app.renderer, filename);

	return texture;
}

void Blit(SDL_Texture* texture, int x, int y)
{
	SDL_Rect dest;

	dest.x = x - 32;
	dest.y = y - 32;

	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(app.renderer, texture, NULL, &dest);
}