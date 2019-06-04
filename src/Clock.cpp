/*
 * Clock.cpp
 *
 * Created 31 August 2014
 * Last modified 4 June 2019
 *
 * Andre Zunino <neyzunino@gmail.com>
 */

#include <iostream>

#include "Clock.hpp"

namespace sdl {

    Clock::Clock(int fps)
        : singleFrameDuration{1000.0f / fps}, currentTicks{0}, elapsedTicks{0}, accumulatedTicks{0},
        frameCountForAvg{0}, avgFPS{0.0f} {
    }

    Uint32 Clock::elapsedMilliseconds() const {
        return SDL_GetTicks() - currentTicks;
    }

    void Clock::startFrame() {
        currentTicks = SDL_GetTicks();
    }

    void Clock::endFrame() {
        Uint32 previousTicks = currentTicks;
        currentTicks = SDL_GetTicks();
        elapsedTicks = currentTicks - previousTicks;
        accumulatedTicks += elapsedTicks;
        ++frameCountForAvg;
        if (frameCountForAvg == NO_OF_FRAMES_FOR_FPS_AVERAGE) {
            avgFPS = NO_OF_FRAMES_FOR_FPS_AVERAGE * 1000.0f / accumulatedTicks;
            frameCountForAvg = 0;
            accumulatedTicks = 0;
            std::clog << "== CLOCK AVERAGE FPS ========> " << avgFPS << std::endl;
        }
    }

    float Clock::remainingFrameTime() const {
        float remaining = singleFrameDuration - elapsedMilliseconds();
        return remaining > 0.0f ? remaining : 0.0f;
    }

}
