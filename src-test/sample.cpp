#include <iostream>

#include "Seidel.hpp"

namespace {
    const int SPRITE_UPDATES_PER_SECOND = 5;
}

class Toon : public Seidel::Sprite {
    public:
        Toon(const Seidel::Texture& texture, int x, int y, int fx, int fy, int fw, int fh, int fcounth, int fcountv)
                :Sprite(texture, x, y, fx, fy, fw, fh, fcounth, fcountv) {
        }
        void update() override {
            int maxX = fwidth * fcounth;
            src.x += fwidth;
            if (src.x >= maxX) {
                src.x = 0;
            }
        }
    private:
        int maxZ; // emulation of movement along the z-axis, i.e. toward and away from the viewer
        int minZ;
};

int main() {
    using namespace Seidel;
    try {
        SDL sdl { SDL_INIT_VIDEO | SDL_INIT_AUDIO };
        Window window { "First Seidel Window!", 320, 200 };
        SDL_Renderer* renderer = window.renderer();
        Texture texture { renderer, "resources/enemies.png" };

        Sprite&& sprite1 = Toon { texture, 0, 0, 0, 0, 73, 104, 4, 1 };
        Sprite&& sprite2 = Toon { texture, 100, 0, 292, 0, 73, 104, 4, 1 };

        bool quit = false;
        SDL_Event event;

        Uint32 spriteAcc = 0;

        Clock clock;

        while (!quit) {

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

            if (spriteAcc >= 1000.0 / SPRITE_UPDATES_PER_SECOND) {
                sprite1.update();
                sprite2.update();
                spriteAcc = 0;
            }

            SDL_RenderClear(renderer);

            sprite1.draw();
            sprite2.draw();

            SDL_RenderPresent(renderer);
            SDL_Delay(10);

            clock.update();
            spriteAcc += clock.elapsedMilliseconds();
        }
    } catch (const SDLError& e) {
        std::cerr << e.message() << std::endl;
    }
}