/**
 * Vector.cpp
 *
 * Implementation of 2D vector that can be used to represent position,
 * velocity, acceleration etc.
 *
 * Created 1 June 2019
 * Last modified 1 June 2019
 *
 * Andre Zunino <neyzunino@gmail.com>
 */

#include "Vector.hpp"

namespace sdl {

    Vector Vector::operator+(const Vector& rhs) const {
        return Vector {x + rhs.x, y + rhs.y};
    }

    Vector& Vector::operator+=(const Vector& rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    bool Vector::operator==(const Vector& rhs) const {
        return x == rhs.x && y == rhs.y;
    }

    bool Vector::operator!=(const Vector& rhs) const {
        return !(*this == rhs);
    }

}

