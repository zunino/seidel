/*
 * Text.hpp
 *
 * Created 12 June 2019
 * Last modified 12 June 2019
 *
 * Andre Zunino <neyzunino@gmail.com>
 */

#ifndef SEIDEL_TEXT_HPP
#define SEIDEL_TEXT_HPP

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

namespace sdl {

    struct Text;

    struct Font final {
        Font(const char* const name, int size);
        ~Font();
        operator TTF_Font*() const;
    private:
        TTF_Font* font;
    };

    struct Writer {
        friend struct Text;
        void write(const char* const text, int x, int y) const;
    private:
        Writer(SDL_Renderer* renderer, Font& font, const SDL_Color& color);
        SDL_Renderer* renderer;
        Font& font;
        SDL_Color color;
    };

    struct Text final {
        Text(SDL_Renderer* renderer);
        ~Text();
        Writer writer(Font& font, const SDL_Color& color);
    private:
        SDL_Renderer* renderer;
    };

}

#endif
