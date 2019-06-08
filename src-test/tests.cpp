#include <iostream>

extern void testIntFromTo();
extern void testIntTo();

extern void testFloatFromTo();
extern void testFloatTo();

extern void testBasicVector();
extern void testVectorEquality();
extern void testVectorInequality();
extern void testVectorPlusEqual();
extern void testVectorAddition();

extern void testCollisions();

extern void testUtils();

int main() {

    // RANDOM
    std::clog << "== [RANDOM]==\n";

    std::clog << "\ntestIntFromTo\n";
    testIntFromTo();

    std::clog << "\ntestIntTo\n";
    testIntTo();

    std::clog << "\ntestFloatFromTo\n";
    testFloatFromTo();

    std::clog << "\ntestFloatTo\n";
    testFloatTo();

    // VECTOR
    std::clog << "\n\n== [VECTOR] ==\n";

    std::clog << "\ntestBasicVector\n";
    testBasicVector();

    std::clog << "\ntestVectorEquality\n";
    testVectorEquality();

    std::clog << "\ntestVectorInequality\n";
    testVectorInequality();

    std::clog << "\ntestVectorPlusEqual\n";
    testVectorPlusEqual();

    std::clog << "\ntestVectorAddition\n";
    testVectorAddition();

    // COLLISION
    std::clog << "\n\n== [COLLISION] ==\n";

    testCollisions();

    // UTILS
    std::clog << "\n\n== [UTILS] ==\n";

    testUtils();
}

