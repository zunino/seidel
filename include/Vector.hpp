/**
 * Vector.hpp
 * 
 * Simple abstraction of a 2D vector that can be used to represent position,
 * velocity, acceleration etc.
 *
 * Created 1 June 2019
 * Last modified 4 June 2019
 *
 * Andre Zunino <neyzunino@gmail.com>
 */

#ifndef SEIDEL_VECTOR_HPP
#define SEIDEL_VECTOR_HPP

#include <iostream>

namespace sdl {

    struct Vector {
        Vector operator+(const Vector& rhs) const;
        Vector& operator+=(const Vector& rhs);
        bool operator==(const Vector& rhs) const;
        bool operator!=(const Vector& rhs) const;
        float mag() const;
        float x;
        float y;
    };

    std::ostream& operator<<(std::ostream& out, const sdl::Vector& v);

}

#endif

