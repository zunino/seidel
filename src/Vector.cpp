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

#include <cmath>

#include "Vector.hpp"

namespace sdl {

    std::ostream& operator<<(std::ostream& out, const sdl::Vector& v) {
        out << '(' << v.x << ", " << v.y << ')';
        return out;
    }

    Vector Vector::operator+(const Vector& rhs) const {
        return Vector {x + rhs.x, y + rhs.y};
    }

    Vector Vector::operator-(const Vector& rhs) const {
        return Vector {x - rhs.x, y - rhs.y};
    }

    Vector Vector::operator*(int scalar) const {
        return *this * float(scalar);
    }

    Vector Vector::operator*(float scalar) const {
        return Vector {
            x * scalar,
            y * scalar
        };
    }

    Vector& Vector::operator+=(const Vector& rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }

    Vector& Vector::operator-=(const Vector& rhs) {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }

    bool Vector::operator==(const Vector& rhs) const {
        return x == rhs.x && y == rhs.y;
    }

    bool Vector::operator!=(const Vector& rhs) const {
        return !(*this == rhs);
    }

    Vector Vector::operator-() const {
        return Vector {-x, -y};
    }

    float Vector::mag() const {
        return std::hypot(x, y);
    }

    Vector Vector::unit() const {
        float magnitude = mag();
        return Vector {
            x / magnitude,
            y / magnitude
        };
    }

    Vector operator*(int scalar, const Vector& rhs) {
        return rhs * scalar;
    }

    Vector operator*(float scalar, const Vector& rhs) {
        return rhs * scalar;
    }

}

