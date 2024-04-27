#include "draw.h"
#include "structs.h"

SDL_Texture* LoadTexture(char* filename, SDL_Texture** texture)
{
	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

	*texture = IMG_LoadTexture(app.renderer, filename);

	return texture;
}

void Blit(SDL_Texture* texture, int x, int y, double angle)
{
    SDL_Rect dstRect;

    dstRect.x = x;
    dstRect.y = y;
    SDL_QueryTexture(texture, NULL, NULL, &dstRect.w, &dstRect.h);
    dstRect.x -= (dstRect.w / 2);
    dstRect.y -= (dstRect.h / 2);

    SDL_RenderCopyEx(app.renderer, texture, NULL, &dstRect, angle, NULL, SDL_FLIP_NONE);
}