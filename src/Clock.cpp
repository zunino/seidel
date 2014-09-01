#include <iostream>

#include "Clock.hpp"

namespace Seidel {

    Clock::Clock()
            : previousTicks(SDL_GetTicks()), accumulatedTicks(0), frameCountForAvg(0), avgFPS(0.0f) {
    }

    void Clock::update() {
        previousTicks = currentTicks;
        currentTicks = SDL_GetTicks();
        elapsedTicks = currentTicks - previousTicks;
        accumulatedTicks += elapsedTicks;
        ++frameCountForAvg;
        if (frameCountForAvg == NO_OF_FRAMES_FOR_FPS_AVERAGE) {
            avgFPS = NO_OF_FRAMES_FOR_FPS_AVERAGE * 1000.0 / accumulatedTicks;
            frameCountForAvg = 0;
            accumulatedTicks = 0;
            std::clog << "== CLOCK AVERAGE FPS ========> " << avgFPS << std::endl;
        }
    }

    void Clock::resetAccumulatedTicks() {
        accumulatedTicks = 0;
    }

}