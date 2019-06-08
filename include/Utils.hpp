/**
 * Utils.hpp
 *
 * General utilities.
 *
 * Created 8 June 2019
 * Last modified 8 June 2019
 *
 * Andre Zunino <neyzunino@gmail.com>
 */

#ifndef SEIDEL_UTILS_HPP
#define SEIDEL_UTILS_HPP

namespace sdl {

    template <typename T>
    const T& clamp(const T& value, const T& min, const T& max) {
        if (value < min) {
            return min;
        } else if (value > max) {
            return max;
        } else {
            return value;
        }
    }

}

#endif

