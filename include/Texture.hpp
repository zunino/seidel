/*
 * Texture.hpp
 *
 * Created 31 August 2014
 * Last modified 4 June 2019
 *
 * Andre Zunino <neyzunino@gmail.com>
 */

#ifndef SEIDEL_TEXTURE_HPP
#define SEIDEL_TEXTURE_HPP

#include <string>

#include <SDL2/SDL.h>

namespace sdl {

    class Texture final {

        public:
            Texture(SDL_Renderer* const renderer, const std::string& fileName);
            ~Texture();
            SDL_Renderer* renderer() { return sdlRenderer; }
            operator SDL_Texture*() { return sdlTexture; }

        private:
            SDL_Renderer* sdlRenderer;
            SDL_Texture* sdlTexture;

    };

}

#endif
