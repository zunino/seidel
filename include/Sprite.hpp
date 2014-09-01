#ifndef SEIDEL_SPRITE_HPP
#define SEIDEL_SPRITE_HPP

#include <SDL.h>

#include "Texture.hpp"

namespace Seidel {

    class Sprite {

        public:
            /**
             * x, y: position of the sprite, i.e. where it's going to be drawn on the rendering context
             * fx, fy: position of the sprite frames in the texture
             * fw, fh: dimensions of each sprite frame (assumed to be the same for all frames)
             * fcounth: number of horizontal frames
             * fcountv: number of vertical frames
             */
            Sprite(const Texture& texture, int x, int y, int fx, int fy, int fw, int fh, int fcounth, int fcountv);
            virtual ~Sprite();

            void draw();
            virtual void update() = 0;

        private:
            Texture texture;

        protected:
            int fwidth;
            int fheight;
            int fcounth;
            int fcountv;
            float speed;

            SDL_Rect src;
            SDL_Rect dst;

            const Uint8* keyStates; // Pointer to SDL array with information about the state of keys
    };

}

#endif