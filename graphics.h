#pragma once
#include "structs.h"

SDL_Texture* boidTexture;

int InitializeGraphics();
int PrepareScene();
int PresentScene();
int DrawObjects();