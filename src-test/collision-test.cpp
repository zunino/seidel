#include <iostream>
using std::clog;
#include <cassert>

#include "CollisionBox.hpp"
using sdl::CollisionBox;

std::ostream& operator<<(std::ostream& out, const CollisionBox& b) {
    out << "{(" << b.p1.x << ", " << b.p1.y << "), (" << b.p2.x << ", " << b.p2.y << ")}";
    return out;
}

void printTest(const CollisionBox& b1, const CollisionBox& b2, bool collision) {
    clog << b1 << " x " << b2 << " => " << (collision ? "collision!" : "no collision") << '\n';
}

void testCollisionB1BeforeB2() {
    CollisionBox b1 {{10, 10}, {20, 20}};
    CollisionBox b2 {{40, 10}, {50, 20}};
    bool collision;

    collision = b1.collidesWith(b2);
    assert(!collision);
    printTest(b1, b2, collision);

    collision = b2.collidesWith(b1);
    assert(!collision);
    printTest(b2, b1, collision);
}

void testCollisionB1EndInB2() {
    CollisionBox b1 {{10, 10}, {20, 20}};
    CollisionBox b2 {{15, 10}, {25, 20}};
    bool collision;

    collision = b1.collidesWith(b2);
    assert(collision);
    printTest(b1, b2, collision);

    collision = b2.collidesWith(b1);
    assert(collision);
    printTest(b2, b1, collision);
}

void testCollisionB1OnTopOfB2() {
    CollisionBox b1 {{10, 10}, {20, 20}};
    CollisionBox b2 {{10, 20}, {20, 30}};
    bool collision;

    collision = b1.collidesWith(b2);
    assert(!collision);
    printTest(b1, b2, collision);

    collision = b2.collidesWith(b1);
    assert(!collision);
    printTest(b2, b1, collision);
}

void testCollisions() {
    testCollisionB1BeforeB2();
    testCollisionB1EndInB2();
    testCollisionB1OnTopOfB2();
}

