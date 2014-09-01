#include <iostream>

#include <SDL_image.h>

#include "Sprite.hpp"

namespace Seidel {

    Sprite::Sprite(const Texture& texture, int x, int y, int fx, int fy, int fw, int fh, int fcounth, int fcountv)
            : texture(texture), fwidth(fw), fheight(fh), fcounth(fcounth), fcountv(fcountv), speed(0.0f),
              keyStates(SDL_GetKeyboardState(nullptr)) {
        std::clog << "Sprite(...)\n";

        src.x = fx;
        src.y = fy;
        src.w = fw;
        src.h = fh;

        dst.x = x;
        dst.y = y;
        dst.w = fw;
        dst.h = fh;
    }

    Sprite::~Sprite() {
        std::clog << "~Sprite()\n";
    }

    void Sprite::draw() {
        SDL_RenderCopy(texture.renderer(), texture, &src, &dst);
    }

}