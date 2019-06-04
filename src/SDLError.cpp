/*
 * SDLError.cpp
 *
 * Created 31 August 2014
 * Last modified 4 June 2019
 *
 * Andre Zunino <neyzunino@gmail.com>
 */

#include <SDL2/SDL.h>

#include "SDLError.hpp"

namespace sdl {

    SDLError::SDLError()
            : errorMessage(SDL_GetError()) {
    }

    SDLError::SDLError(const std::string& userMessage) {
        errorMessage = userMessage + " [SDL_GetError]: " + SDL_GetError();
    }

    const std::string& SDLError::message() const {
        return errorMessage;
    }

}
