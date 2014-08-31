#ifndef SEIDEL_TEXTURE_HPP
#define SEIDEL_TEXTURE_HPP

#include <SDL.h>

#include "SDLError.hpp"

namespace Seidel {

    class Texture {

        public:
            Texture(SDL_Renderer* const renderer, const std::string& fileName) throw (SDLError);
            virtual ~Texture();

            SDL_Renderer* renderer() { return sdlRenderer; }
            operator SDL_Texture*() { return sdlTexture; }

        private:
            SDL_Renderer* sdlRenderer;
            SDL_Texture* sdlTexture;

    };

}

#endif