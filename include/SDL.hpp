#ifndef SEIDEL_SDL_HPP
#define SEIDEL_SDL_HPP

#include <SDL.h>

#include "SDLError.hpp"

namespace Seidel {

    class SDL final {
        public:
            SDL(Uint32 flags) throw (SDLError);
            ~SDL();
    };

}

#endif