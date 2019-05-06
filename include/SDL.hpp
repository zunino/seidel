/*
 * SDL.hpp
 *
*  Created: Aug 31, 2014
 * Author:  Andre Zunino <neyzunino@gmail.com>
 */

#ifndef SEIDEL_SDL_HPP
#define SEIDEL_SDL_HPP

#include <SDL.h>

namespace sdl {

    class SDL final {

        public:
            SDL(Uint32 flags);
            ~SDL();

    };

}

#endif
