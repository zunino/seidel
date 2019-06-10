#include <iostream>

extern void testRandom();
extern void testVector();
extern void testCollisions();
extern void testUtils();
extern void testExtractMainColors();

int main() {
    // RANDOM
    std::clog << "== [RANDOM]==\n";
    testRandom();

    // VECTOR
    std::clog << "\n\n== [VECTOR] ==\n";
    testVector();

    // COLLISION
    std::clog << "\n\n== [COLLISION] ==\n";
    testCollisions();

    // UTILS
    std::clog << "\n\n== [UTILS] ==\n";
    testUtils();

    // TEXTURE
    std::clog << "\n\n== [TEXTURE] ==\n";
    testExtractMainColors();
}

