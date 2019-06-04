/*
 * Texture.cpp
 *
 * Created 31 August 2014
 * Last modified 4 June 2019
 *
 * Andre Zunino <neyzunino@gmail.com>
 */

#include <SDL2/SDL_image.h>

#include "Texture.hpp"
#include "SDLError.hpp"

namespace sdl {

    Texture::Texture(SDL_Renderer* const renderer, const std::string& fileName)
            : sdlRenderer(renderer) {
        SDL_Surface* surface = IMG_Load(fileName.c_str());
        if (surface == nullptr) {
            throw SDLError();
        }
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        if (texture == 0) {
            throw SDLError();
        }
        sdlTexture = texture;
    }

    Texture::~Texture() {
        SDL_DestroyTexture(sdlTexture);
    }

}
