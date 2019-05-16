#include <iostream>

extern void testIntFromTo();
extern void testIntTo();

extern void testFloatFromTo();
extern void testFloatTo();

int main() {

    std::clog << "=== random-test\n";

    std::clog << "\ntestIntFromTo\n";
    testIntFromTo();

    std::clog << "\ntestIntTo\n";
    testIntTo();

    std::clog << "\ntestFloatFromTo\n";
    testFloatFromTo();

    std::clog << "\ntestFloatTo\n";
    testFloatTo();

}

