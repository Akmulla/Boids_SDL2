#pragma once
#include <SDL.h>

SDL_Texture* LoadTexture(char* filename, SDL_Texture** texture);
void Blit(SDL_Texture* texture, int x, int y);