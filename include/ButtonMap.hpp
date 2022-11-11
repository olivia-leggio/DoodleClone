#pragma once
#include <SDL2/SDL.h>

struct ButtonMap
{
	ButtonMap();

	SDL_Scancode UP;
	SDL_Scancode DOWN;
	SDL_Scancode LEFT;
	SDL_Scancode RIGHT;
	SDL_Scancode ESC;
	SDL_Scancode RETURN;
};