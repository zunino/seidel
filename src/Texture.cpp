/*
 * Texture.cpp
 *
 *  Created on: Aug 31, 2014
 * Modified on: Aug 3, 2015
 *      Author: Andre Zunino <neyzunino@gmail.com>
 */

#include <SDL_image.h>

#include "Texture.hpp"

namespace sdl {

Texture::Texture(SDL_Renderer* const renderer, const std::string& fileName) throw (SDLError)
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

} /* namespace sdl */
