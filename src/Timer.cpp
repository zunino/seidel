/*
 * Timer.cpp
 *
 * Created 6 November 2020
 * Last modified 6 November 2020
 *
 * Andre Zunino <neyzunino@gmail.com>
 */

#include <Timer.hpp>

namespace sdl {

    Timer::Timer(Duration ttl) :
            start{Clock::now()},
            ttl{ttl}
    {}
    bool Timer::elapsed() const {
        return Clock::now() - start > ttl;
    }
    void Timer::reset() {
        start = Clock::now();
    }

}
