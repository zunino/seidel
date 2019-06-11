#include <iostream>
#include <cassert>

#include "Vector.hpp"
using sdl::Vector;

const float EPSILON = 0.01f;

bool roughlyEqual(float a, float b, float epsilon = EPSILON) {
    return a - b < epsilon;
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
    std::clog << "v1 " << v1 << " += v2 " << v2;
    v1 += v2;
    Vector expected {5, 8};
    std::clog << " => v1 = " << v1 << '\n';
    assert(v1 == expected);
}

void testVectorAddition() {
    Vector v1 {3, 4};
    Vector v2 {2, 4};
    Vector v3 = v1 + v2;
    Vector expected {5, 8};
    std::clog << "v1 " << v1 << " + v2 " << v2 << " = " << v3 << '\n';
    assert(v3 == expected);
}

void testVectorMagnitude() {
    Vector v1 {3, 4};
    float magnitude1 = v1.mag();
    std::clog << "|v1 " << v1 << "| = " << magnitude1;
    assert(magnitude1 == 5.0f);
    std::clog << " OK" << '\n';

    Vector v2 {-5, 7};
    float magnitude2 = v2.mag();
    std::clog << "|v2 " << v2 << "| = " << magnitude2;
    assert(roughlyEqual(magnitude2, 8.6f));
    std::clog << " OK" << '\n';
}

void testVectorUnaryMinus() {
    Vector v1 {8, -6};
    Vector result = -v1;
    std::clog << "v1 " << v1 << "; -v1 = " << result << '\n';
    Vector expected = {-8, 6};
    assert(result == expected);
}

void testUnitVector() {
    Vector v1 {3, 5};
    Vector expected {0.514f, 0.857f};
    Vector result = v1.unit();
    std::clog << "v1 " << v1 << "; unit(v1) = " << result << '\n';
    assert(roughlyEqual(result.x, expected.x));
    assert(roughlyEqual(result.y, expected.y));
}

void testDefaultVector() {
    Vector v;
    std::clog << "v " << v << " should be (0, 0)";
    assert(v.x == 0.0f);
    assert(v.y == 0.0f);
    std::clog << " OK\n";
}

void testVectorSubtraction() {
    Vector v1 {3, 4};
    Vector v2 {2, 4};
    Vector v3 = v1 - v2;
    Vector expected {1, 0};
    std::clog << "v1 " << v1 << " - v2 " << v2 << " = " << v3 << '\n';
    assert(v3 == expected);
}

void testVectorMinusEqual() {
    Vector v1 {3, 4};
    Vector v2 {2, 4};
    std::clog << "v1 " << v1 << " -= v2 " << v2;
    v1 -= v2;
    Vector expected {1, 0};
    std::clog << " => v1 = " << v1 << '\n';
    assert(v1 == expected);
}

void testVectorScalarMultiplication() {
    Vector v1 {3, 5};
    Vector expected1 {12, 20};
    Vector result1 = v1 * 4;
    std::clog << "v1 " << v1 << " * 4 = " << result1 << '\n';
    assert(result1 == expected1);

    Vector v2 {4, 7};
    Vector expected2 {10, 17.5f};
    Vector result2 = v2 * 2.5f;
    std::clog << "v2 " << v2 << " * 2.5f = " << result2 << '\n';
    assert(result2 == expected2);
}

void testVectorScalarMultiplicationNonMember() {
    Vector v1 {5, -6};
    Vector expected1 {10, -12};
    Vector result1 = 2 * v1;
    std::clog << "2 * v1 " << v1 << " = " << result1 << '\n';
    assert(result1 == expected1);

    Vector v2 {-3, 9};
    Vector expected2 {-7.5f, 22.5f};
    Vector result2 = 2.5f * v2;
    std::clog << "2.5f * v2 " << v2 << " = " << result2 << '\n';
    assert(result2 == expected2);
}

void testVector() {
    testBasicVector();
    testVectorEquality();
    testVectorInequality();
    testVectorPlusEqual();
    testVectorAddition();
    testVectorMagnitude();
    testVectorUnaryMinus();
    testUnitVector();
    testDefaultVector();
    testVectorSubtraction();
    testVectorMinusEqual();
    testVectorScalarMultiplication();
    testVectorScalarMultiplicationNonMember();
}

