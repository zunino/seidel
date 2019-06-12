/**
 * Utils.cpp
 *
 * General utilities.
 *
 * Created 8 June 2019
 * Last modified 12 June 2019
 *
 * Andre Zunino <neyzunino@gmail.com>
 */

#include "Utils.hpp"

namespace sdl {

}

std::ostream& operator<<(std::ostream& os, const SDL_Color& c) {
    return os << '[' << int(c.r) << ", " << int(c.g) << ", " << int(c.b)
              << ", " << int(c.a) << ']';
}

