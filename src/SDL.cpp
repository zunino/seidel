/*
 * SDL.cpp
 *
 * Created:  Aug 31, 2014
 * Modified: Aug 3, 2015
 * Author:   Andre Zunino <neyzunino@gmail.com>
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
