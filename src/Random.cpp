/**
 * Random.cpp
 *
 * Implementation of random number generation utilities.
 *
 * Created 16 May 2019
 * Last modified 4 June 2019
 *
 * Andre Zunino <neyzunino@gmail.com>
 */

#include <random>

#include "Random.hpp"

namespace sdl {

    std::random_device rd;
    std::mt19937 randEng {rd()};
 
    int random(int from, int to) {
        std::uniform_int_distribution<int> dist(from, to);
        return dist(randEng);
    }

    int random(int to) {
        return random(0, to);
    }

    float random(float from, float to) {
        std::uniform_real_distribution<float> dist(from, to);
        return dist(randEng);
    }

    float random(float to) {
        return random(0.0f, to);
    }

}

