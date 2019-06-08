#include <iostream>
using std::clog;

#include <cassert>

#include "Utils.hpp"
using sdl::clamp;

void testClamp() {
    std::clog << "clamp(15, 10, 20) => 15 ";
    int result = clamp(15, 10, 20);
    assert(result == 15);
    clog << "OK\n";

    std::clog << "clamp(7, 10, 20) => 7 ";
    result = clamp(7, 10, 20);
    assert(result == 10);
    clog << "OK\n";

    std::clog << "clamp(22, 10, 20) => 20 ";
    result = clamp(22, 10, 20);
    assert(result == 20);
    clog << "OK\n";
}

void testUtils() {
    testClamp();
}

