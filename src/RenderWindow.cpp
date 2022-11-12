#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <vector>

#include "RenderWindow.hpp"
#include "Entity.hpp"

RenderWindow::RenderWindow(const char* p_title, int p_width, int p_height)
	:window(NULL), renderer(NULL)
{
	window = SDL_CreateWindow(p_title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, p_width, p_height, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		std::cout << "Error during window initialization: " << SDL_GetError() << std::endl; 
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if(renderer == NULL)
	{
		std::cout << "Error during renderer initialization: " << SDL_GetError() << std::endl;
	}
}

SDL_Texture* RenderWindow::loadTexture(const char* p_filePath)
{
	SDL_Texture* texture = NULL;
	texture = IMG_LoadTexture(renderer, p_filePath);

	if (texture == NULL)
	{
		std::cout << "Error during texture load for file " << p_filePath << ": " << SDL_GetError() << std::endl;
	}

	return texture;
}

void RenderWindow::clear()
{
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderClear(renderer);
}

void RenderWindow::render(std::vector<Entity>& p_entities)
{
	for (Entity& p_entity : p_entities)
	{
		SDL_Rect source;
		source.x = p_entity.getCurrentFrame().x;
		source.y = p_entity.getCurrentFrame().y;
		source.w = p_entity.getCurrentFrame().w;
		source.h = p_entity.getCurrentFrame().h;

		SDL_Rect dest;
		dest.x = p_entity.getX() * 3;
		dest.y = p_entity.getY() * 3;
		dest.w = p_entity.getCurrentFrame().w * 3;
		dest.h = p_entity.getCurrentFrame().h * 3;

		SDL_RenderCopy(renderer, p_entity.getTexture(), &source, &dest);
	}
}

void RenderWindow::display()
{
	SDL_RenderPresent(renderer);
}

void RenderWindow::cleanUp()
{
	SDL_DestroyWindow(window);
}