#ifndef SEIDEL_CLOCK_HPP
#define SEIDEL_CLOCK_HPP

#include <SDL.h>

namespace Seidel {

    class Clock final {

        public:
            Clock();
            Uint32 elapsedMilliseconds() const {
                return elapsedTicks;
            }
            float elapsedSeconds() const {
                return elapsedTicks / 1000.0f;
            }
            float averageFPS() const {
                return avgFPS;
            }
            void update();
            void resetAccumulatedTicks();

        private:
            static const int NO_OF_FRAMES_FOR_FPS_AVERAGE = 30;
            Uint32 previousTicks;
            Uint32 currentTicks;
            Uint32 elapsedTicks;
            Uint32 accumulatedTicks;
            int frameCountForAvg;
            float avgFPS;
    };

}

#endif