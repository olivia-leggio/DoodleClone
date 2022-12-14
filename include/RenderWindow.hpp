#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <vector>

#include "Entity.hpp"

class RenderWindow
{
public:
	RenderWindow(const char* p_title, int p_width, int p_height);
	SDL_Texture* loadTexture(const char* p_filePath);
	void clear();
	void render(std::vector<Entity>& p_entities);
	void display();
	void cleanUp();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
};