/*
 * SDLError.cpp
 *
 * Created:  Aug 31, 2014
 * Modified: Aug 3, 2015
 * Author:   Andre Zunino <neyzunino@gmail.com>
 */

#include <SDL.h>

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
