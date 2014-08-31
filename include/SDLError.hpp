#ifndef SEIDEL_SDLERROR_HPP
#define SEIDEL_SDLERROR_HPP

#include <string>

namespace Seidel {

    class SDLError {
        public:
            SDLError();                               // The error message is whatever is reported by SDL
            SDLError(const std::string& userMessage); // An extra description which will precede SDL's error message
            const std::string& message() const;
        private:
            std::string errorMessage;
    };

}

#endif