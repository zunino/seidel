/**
 * CollisionBox.cpp
 *
 * Implementation of collision detection between 2 2D boxes.
 *
 * Created 4 June 2019
 * Last modified 4 June 2019
 *
 * Andre Zunino <neyzunino@gmail.com>
 */

#include "CollisionBox.hpp"

namespace sdl {

    bool CollisionBox::collidesWith(const CollisionBox& rhs) const {
        return p1.x < rhs.p2.x
            && p2.x > rhs.p1.x
            && p1.y < rhs.p2.y
            && p2.y > rhs.p1.y;
    }

}

