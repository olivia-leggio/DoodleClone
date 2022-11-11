#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>

#include "RenderWindow.hpp"
#include "ButtonMap.hpp"

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
	int window_width = 720;
	int window_height = 1000;
	RenderWindow window(window_title, window_width, window_height);


	//Game loop
	//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
	SDL_Event event;
	bool gameRunning = true;
	GAME_STATES gameState = MENU;
	CHAR_STATES charState = GROUNDED;
	ButtonMap button;
	bool shooting = false;

	while (gameRunning)
	{
		//check all events before updating game state
		while (SDL_PollEvent(&event))
		{
			//window closed
			if (event.type == SDL_QUIT)
			{
				gameRunning = false;
			}

			//any key is pressed
			if (event.type == SDL_KEYDOWN)
			{
				SDL_Scancode scancode = event.key.keysym.scancode;
				
				if (scancode == button.UP)
				{
					std::cout << "UP button pressed" << std::endl;
				}
				if (scancode == button.DOWN)
				{
					std::cout << "DOWN button pressed" << std::endl;
				}
				if (scancode == button.LEFT)
				{
					std::cout << "LEFT button pressed" << std::endl;
				}
				if (scancode == button.RIGHT)
				{
					std::cout << "RIGHT button pressed" << std::endl;
				}
				if (scancode == button.ESC)
				{
					std::cout << "ESC button pressed" << std::endl;
				}
				if (scancode == button.RETURN)
				{
					std::cout << "RETURN button pressed" << std::endl;
				}
			}

			//mouse clicked
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				if (event.button.button == SDL_BUTTON_LEFT)
				{
					shooting = true;
					std::cout << "left click at point " << event.button.x << ", " << event.button.y << std::endl;
				}
			}
		}

		//update game state
		if(shooting)
		{
			//eventually run a calculation for projectile trajectory based on
			//event.button.x, event.button.y, and player position
			shooting = false;
		}
	}

	window.cleanUp();
	SDL_Quit();

	return 0;
}