#include <iostream>

#include "Vector.hpp"
using sdl::Vector;

std::ostream& operator<<(std::ostream& out, const sdl::Vector& v) {
    out << '(' << v.x << ", " << v.y << ')';
    return out;
}

void testBasicVector() {
    Vector v {3, 4};
    if (v.x != 3 || v.y != 4) {
        std::cerr << "Vector coordinates do not correspond to arguments\n";
    }
    std::clog << "v " << v << '\n';
}

void testVectorEquality() {
    Vector v1 {5, 3};
    Vector v2 {5, 3};
    bool equality = v1 == v2;
    if (!equality) {
        std::cerr << "Vectors v1 and v2 should have been deemed equal\n";
    }
    std::clog << "Vectors v1 " << v1 << " and v2 " << v2 << " are equal\n";
}

void testVectorInequality() {
    Vector v1 {5, 3};
    Vector v2 {5, 4};
    bool inequality = v1 != v2;
    if (!inequality) {
        std::cerr << "Vectors v1 and v2 should have been deemed not equal\n";
    }
    std::clog << "Vectors v1 " << v1 << " and v2 " << v2 << " are not equal\n";
}

void testVectorPlusEqual() {
    Vector v1 {3, 4};
    Vector v2 {2, 4};
    std::clog << "v1 " << v1 << '\n';
    std::clog << "v2 " << v2 << '\n';
    v1 += v2;
    std::clog << "v1 += v2\n";
    Vector vexpected {5, 8};
    if (!(v1 == vexpected)) {
        std::cerr << "Wrong resulting vector from plus-equal operation";
    }
    std::clog << "v1 " << v1 << '\n';
}

void testVectorAddition() {
    Vector v1 {3, 4};
    Vector v2 {2, 4};
    std::clog << "v1 " << v1 << '\n';
    std::clog << "v2 " << v2 << '\n';
    Vector v3 = v1 + v2;
    std::clog << "v3 = v1 + v2\n";
    Vector vexpected {5, 8};
    if (!(v3 == vexpected)) {
        std::cerr << "Wrong resulting vector from addition operation";
    }
    std::clog << "v3 " << v3 << '\n';
}

