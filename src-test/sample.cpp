#include <iostream>

#include "Seidel.hpp"

namespace {
    const int WINDOW_WIDTH = 400;
    const int WINDOW_HEIGHT = 320;
    const int TOON_UPDATES_PER_SECOND = 60;
    const int TOON_SPRITE_WIDTH = 72;
    const int TOON_SPRITE_HEIGHT = 95;
    const int TOON_SPRITE_PADDING = 30;
}

class Toon {
    public:
        Toon(sdl::Clock& clock, sdl::Sprite&& sprite)
            : x{0}, y{0}, z{1.0f}, clock{clock}, sprite{std::move(sprite)} {}
        std::tuple<float, float> position() const { return std::make_tuple(x, y); }
        void setPosition(float x, float y) { this->x = x; this->y = y; update(); }
        void update() {
            sprite.update(clock.frameDuration(), x, y);
            z += zDelta;
            if (z > MAX_Z) {
                z = MAX_Z;
                zDelta = -zDelta;
            } else if (z < MIN_Z) {
                z = MIN_Z;
                zDelta = -zDelta;
            }
            sprite.zoom(z);
        }
        void draw() const { sprite.draw(); }
    private:
        static constexpr float MIN_Z = 0.5f;
        static constexpr float MAX_Z = 1.5f;
        static float zDelta;
        float x;
        float y;
        float z; // 2D emulation of move along the z-axis (close and away from the camera)
        sdl::Clock& clock;
        sdl::Sprite sprite;
};

float Toon::zDelta = 0.005f;

int main() {
    using namespace sdl;
    try {
        SDL sdl {SDL_INIT_VIDEO | SDL_INIT_AUDIO};
        Window window {"First Seidel Window!", WINDOW_WIDTH, WINDOW_HEIGHT};
        SDL_Renderer* renderer = window.renderer();
        Texture texture {renderer, "resources/toons.png"};

        Clock clock {60_fps};

        Toon toon1 {clock, Sprite {texture, TOON_SPRITE_WIDTH *  4, 0, TOON_SPRITE_WIDTH, TOON_SPRITE_HEIGHT, 4, 3.5f}};
	Toon toon2 {clock, Sprite {texture, TOON_SPRITE_WIDTH *  8, 0, TOON_SPRITE_WIDTH, TOON_SPRITE_HEIGHT, 4, 7.0f}};
        Toon toon3 {clock, Sprite {texture, TOON_SPRITE_WIDTH * 12, 0, TOON_SPRITE_WIDTH, TOON_SPRITE_HEIGHT, 4, 3.5f}};

	float xpos = (WINDOW_WIDTH - (2 * TOON_SPRITE_WIDTH + 2 * TOON_SPRITE_PADDING)) / 2.0f;
	float ypos = WINDOW_HEIGHT / 2.0f;

        toon1.setPosition(xpos, ypos);
	toon2.setPosition(xpos + TOON_SPRITE_WIDTH + TOON_SPRITE_PADDING, ypos);
	toon3.setPosition(xpos + 2 * TOON_SPRITE_WIDTH + 2* TOON_SPRITE_PADDING, ypos);

        bool quit = false;
        SDL_Event event;
        while (!quit) {
            clock.startFrame();
            while (SDL_PollEvent(&event)) {
                if (event.type == SDL_QUIT) {
                    quit = true;
                } else if (event.type == SDL_KEYDOWN) {
                    int keyCode = event.key.keysym.sym;
                    switch (keyCode) {
                        case SDLK_ESCAPE:
                            quit = true;
                            break;
                    }
                }
            }
            if (quit) break;

            // Update game entities
            toon1.update();
            toon2.update();
            toon3.update();

            // Render frame
            SDL_RenderClear(renderer);
            toon1.draw();
            toon2.draw();
            toon3.draw();
            SDL_RenderPresent(renderer);

            // Control frame rate
            SDL_Delay(clock.remainingFrameTime());

            clock.endFrame();
        }
    } catch (const SDLError& e) {
        std::cerr << e.message() << std::endl;
    }
}
