#include <iostream>

#include <SDL_image.h>

#include "Texture.hpp"

namespace Seidel {

    Texture::Texture(SDL_Renderer* const renderer, const std::string& fileName) throw (SDLError)
            : sdlRenderer(renderer) {
        std::clog << "Texture(renderer, fileName)\n";
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
        std::clog << "~Texture()\n";
        std::clog << "Destroying Texture\n";
        SDL_DestroyTexture(sdlTexture);
    }

}