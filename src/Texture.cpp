/*
 * Texture.cpp
 *
 * Created 31 August 2014
 * Last modified 12 June 2019
 *
 * Andre Zunino <neyzunino@gmail.com>
 */

#include <map>
#include <set>

#include <SDL2/SDL_image.h>

#include "Texture.hpp"
#include "Utils.hpp"
#include "SDLError.hpp"

bool operator==(const SDL_Color& lhs, const SDL_Color& rhs) {
    return lhs.r == rhs.r &&
           lhs.g == rhs.g &&
           lhs.b == rhs.b &&
           lhs.a == rhs.a;
}

bool operator<(const SDL_Color& lhs, const SDL_Color& rhs) {
    int lhsDword = (lhs.r << 24) + (lhs.g << 16) + (lhs.b << 8) + lhs.a;
    int rhsDword = (rhs.r << 24) + (rhs.g << 16) + (rhs.b << 8) + rhs.a;
    return lhsDword < rhsDword;
}

namespace sdl {

    Texture::Texture(SDL_Renderer* const renderer, const std::string& fileName)
            : sdlRenderer(renderer) {
        SDL_Surface* surface = IMG_Load(fileName.c_str());
        if (surface == nullptr) {
            throw SDLError();
        }
        sdlTexture = createTexture(renderer, surface);
    }

    Texture::Texture(SDL_Renderer* const renderer, SDL_Surface* const surface)
            : sdlTexture(createTexture(renderer, surface)) {
    }

    SDL_Texture* Texture::createTexture(SDL_Renderer* const renderer,
            SDL_Surface* const surface) {
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
        if (texture == 0) {
            throw SDLError();
        }
        return texture;
    }

    Texture::~Texture() {
        SDL_DestroyTexture(sdlTexture);
    }

    typedef std::pair<SDL_Color, int> HistogramEntry;

    struct ColorHistComp {
        bool operator()(const HistogramEntry& lhs, const HistogramEntry& rhs) const {
            return lhs.second > rhs.second;
        }
    };

    std::array<SDL_Color, Texture::MAIN_COLORS_SIZE> Texture::extractMainColors(
            SDL_Surface* const surface) {
        if (SDL_LockSurface(surface) != 0) {
            std::cerr << "Could not lock surface\n";
        }
        SDL_PixelFormat* format = surface->format;
        int bpp = format->BytesPerPixel;
        if (bpp != 4) {
            SDL_UnlockSurface(surface);
            throw "Only 32-bit surfaces are supported";
        }
        Uint32* pixels = (Uint32*) surface->pixels;
        std::map<SDL_Color, int> histogram;
        int pixelCount = surface->w * surface->h;
        for (int p = 0; p < pixelCount; ++p) {
            Uint32* pixel = pixels + p;
            Uint8 r, g, b;
            SDL_GetRGB(*pixel, format, &r, &g, &b);
            SDL_Color color {r, g, b, 255};
            if (r + g + b < 10) continue; // dismiss nearly-black pixels
            histogram[color]++;
        }
        SDL_UnlockSurface(surface);
        std::set<std::pair<SDL_Color, int>, ColorHistComp> sortedHistogram(
                std::make_move_iterator(std::begin(histogram)),
                std::make_move_iterator(std::end(histogram)));
        std::array<SDL_Color, MAIN_COLORS_SIZE> mainColors {};
        auto iter = std::begin(sortedHistogram);
        for (int i = 0; i < MAIN_COLORS_SIZE && iter != std::end(sortedHistogram); ++i) {
            mainColors[i] = iter->first;
            iter++;
        }
        return mainColors;
    }

}

