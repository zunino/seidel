/*
 * SDL.cpp
 *
 * Created 31 August 2014
 * Last modified 4 June 2019
 *
 * Andre Zunino <neyzunino@gmail.com>
 */

#include "SDL.hpp"
#include "SDLError.hpp"

namespace sdl {

    SDL::SDL(Uint32 flags) {
        if (SDL_Init(flags) != 0) {
            throw SDLError();
        }
    }

    SDL::~SDL() {
        SDL_Quit();
    }

}
