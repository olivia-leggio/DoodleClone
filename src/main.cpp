#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"

enum GAME_STATES {MENU, PLAYING, PAUSED};
enum CHAR_STATES {GROUNDED, JUMPING, FALLING, DEAD};

int main(int argc, char* args[])
{
	//SDL initialization
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	if(SDL_Init(SDL_INIT_VIDEO) > 0)
	{
		std::cout << "SDL_Init failed: " << SDL_GetError() << std::endl;
	}

	if(!(IMG_Init(IMG_INIT_PNG)))
	{
		std::cout << "SDL_Init failed: " << SDL_GetError() << std::endl;
	}

	//Rendering window
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	char window_title[] = "Doodle Clone";
	int window_width = 1280;
	int window_height = 720;
	RenderWindow window(window_title, window_width, window_height);


	//Game loop
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	SDL_Event event;
	bool gameRunning = true;
	GAME_STATES gameState = MENU;
	CHAR_STATES charState = GROUNDED;

	while (gameRunning)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				gameRunning = false;
			}
		}
	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}