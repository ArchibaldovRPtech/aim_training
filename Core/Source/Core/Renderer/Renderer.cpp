#include "Renderer.h"
#include <string>

namespace Renderer {

Texture::Texture():
	mTexture{nullptr},
	mWidth{0},
	mHeight{0}
{

}

Texture::~Texture(){
	destroy();
}

bool Texture::loadFromFile(SDL_Renderer* renderer, std::string path){
	destroy();

	if( SDL_Surface* loadedSurface = IMG_Load(path.c_str()); loadedSurface == nullptr){
		SDL_Log("Unable to load image %s! SDL_image error: %s\n", path.c_str(), SDL_GetError());
	}
	else {
		if( mTexture = SDL_CreateTextureFromSurface(renderer, loadedSurface); mTexture == nullptr){
			SDL_Log( "Unable to create texture from loaded pixels! SDL error: %s\n", SDL_GetError() );
		} else {
			mWidth = loadedSurface->w;
			mHeight = loadedSurface->h;
		}
		SDL_DestroySurface(loadedSurface);
	}
	return mTexture != nullptr;
}

void Texture::destroy(){
	SDL_DestroyTexture(mTexture);
	mTexture = nullptr;
	mWidth = 0;
	mHeight = 0;
}

void Texture::render(SDL_Renderer* renderer,float x,float y){
	SDL_FRect dstRect{ x, y, static_cast<float>( mWidth ), static_cast<float>( mHeight ) };
	SDL_RenderTexture( renderer, mTexture, nullptr, &dstRect );
}

int Texture::getWidth(){
	return mWidth;
}

int Texture::getHeight(){
	return mHeight;
}

bool Texture::isLoaded(){
	return mTexture != nullptr;
}
}
