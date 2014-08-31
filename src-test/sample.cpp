#include <iostream>

#include "Seidel.hpp"

class Toon : public Seidel::Sprite {
    public:
        Toon(const Seidel::Texture& texture, int x, int y, int fx, int fy, int fw, int fh, int fcounth, int fcountv)
                :Sprite(texture, x, y, fx, fy, fw, fh, fcounth, fcountv) {
        }
        void update() override {
            std::clog << "Toon::update\n";
            int maxX = fwidth * fcounth;
            src.x += fwidth;
            if (src.x >= maxX) {
                src.x = 0;
            }
        }
        void toony() {
            std::clog << "Toooooony\n";
        }
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
                        case SDLK_RIGHT:
                            sprite1.update();
                            break;
                    }
                }
            }

            if (quit) break;

            SDL_RenderClear(renderer);

            sprite1.draw();
            sprite2.draw();

            SDL_RenderPresent(renderer);
            SDL_Delay(200);
        }
    } catch (const SDLError& e) {
        std::cerr << e.message() << std::endl;
    }
}