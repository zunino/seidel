#include <SDL.h>

#include "SDLError.hpp"

namespace Seidel {

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