#include <iostream>

#include "Random.hpp"

void testIntFromTo() {
    int num = sdl::random(10, 20);
    if (num < 10 || num > 20) {
        std::cerr << "Generated random int out of expected range: " << num << '\n';
    }
    std::clog << "num: " << num << '\n';
}

void testIntTo() {
    int num = sdl::random(10);
    if (num < 0 || num > 10) {
        std::cerr << "Generated random int out of expected range: " << num << '\n';
    }
    std::clog << "num: " << num << '\n';
}

void testFloatFromTo() {
    float num = sdl::random(10.0f, 20.0f);
    if (num < 10.0f || num > 20.0f) {
        std::cerr << "Generated random float out of expected range: " << num << '\n';
    }
    std::clog << "num: " << num << '\n';
}

void testFloatTo() {
    float num = sdl::random(10.0f);
    if (num < 0.0f || num > 10.0f) {
        std::cerr << "Generated random float out of expected range: " << num << '\n';
    }
    std::clog << "num: " << num << '\n';
}

void testRandom() {
    testIntFromTo();
    testIntTo();
    testFloatFromTo();
    testFloatTo();
}

