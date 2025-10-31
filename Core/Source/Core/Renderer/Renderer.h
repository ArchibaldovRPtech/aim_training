#pragma once

#include <SDL3/SDL_surface.h>
#include <SDL3_image/SDL_image.h>
#include <string>

namespace Renderer {

	class Texture {

	public:
		Texture();

	~Texture();
	bool loadFromFile(SDL_Renderer* renderer, const std::string path);

	void destroy();

	void render(SDL_Renderer* renderer,float x,float y);

	int getWidth();
	int getHeight();
	bool isLoaded();

	private:
	SDL_Texture* mTexture;
	
	int mWidth;
	int mHeight;


};

}
