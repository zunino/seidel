/*
 * SDL.cpp
 *
 *  Created on: Aug 31, 2014
 * Modified on: Aug 3, 2015
 *      Author: Andre Zunino <neyzunino@gmail.com>
 */

#include "SDL.hpp"

namespace sdl {

SDL::SDL(Uint32 flags) throw (SDLError) {
    if (SDL_Init(flags) != 0) {
        throw SDLError();
    }
}

SDL::~SDL() {
    SDL_Quit();
}

}
