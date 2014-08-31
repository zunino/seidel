#include <iostream>

#include "SDL.hpp"

namespace Seidel {

    SDL::SDL(Uint32 flags) throw (SDLError) {
        std::clog << "SDL(Uint32)\n";
        if (SDL_Init(flags) != 0) {
            throw SDLError();
        }
    }

    SDL::~SDL() {
        std::clog << "~SDL()\n";
        SDL_Quit();
    }

}