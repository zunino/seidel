/*
 * Text.cpp
 *
 * Created 12 June 2019
 * Last modified 23 June 2019
 *
 * Andre Zunino <neyzunino@gmail.com>
 */

#include "Text.hpp"
#include "SDLError.hpp"

namespace sdl {

    // FONT

    Font::Font(std::string_view filespec, int size) {
        font = TTF_OpenFont(filespec.data(), size);
        if (!font) {
            throw SDLError("Error opening TTF font");
        }
    }

    Font::~Font() {
        TTF_CloseFont(font);
    }

    Font::operator TTF_Font*() const {
        return font;
    }

    // WRITER

    Writer::Writer(SDL_Renderer* renderer, Font& font, const SDL_Color& color)
            : renderer(renderer), font(font), color(color) {
    }

    void Writer::write_(SDL_Surface* surface, std::string_view text, int x, int y) const {
        int w, h;
        TTF_SizeText(font, text.data(), &w, &h);
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);
        SDL_Rect dstRect {x, y, w, h};
        SDL_RenderCopy(renderer, texture, NULL, &dstRect);
        SDL_DestroyTexture(texture);
    }

    void Writer::write(std::string_view text, int x, int y) const {
        SDL_Surface* surface = TTF_RenderText_Solid(font, text.data(), color);
        write_(surface, text, x, y);
    }

    void Writer::writeShaded(std::string_view text, int x, int y, const SDL_Color& bgColor) const {
        SDL_Surface* surface = TTF_RenderText_Shaded(font, text.data(), color, bgColor);
        write_(surface, text, x, y);
    }

    void Writer::writeBlended(std::string_view text, int x, int y) const {
        SDL_Surface* surface = TTF_RenderText_Blended(font, text.data(), color);
        write_(surface, text, x, y);
    }

    // TEXT

    Text::Text(SDL_Renderer* renderer)
            : renderer(renderer) {
        if (TTF_Init() != 0) {
            throw SDLError("Could not initialize TTF library");
        }
    }

    Text::~Text() {
        TTF_Quit();
    }

    Writer Text::writer(Font& font, const SDL_Color& color) const {
        return Writer {renderer, font, color};
    }

}

