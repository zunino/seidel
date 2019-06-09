#include <iostream>
using std::clog;

#include <cassert>

#include <SDL2/SDL.h>

#include "Texture.hpp"

extern std::ostream& operator<<(std::ostream&, const SDL_Color&);
extern bool operator==(const SDL_Color&, const SDL_Color&);

namespace {
    const int BIT_DEPTH = 32;
    const SDL_Color ZEROED {0, 0, 0, 0};
    const SDL_Color GREEN {0, 0, 255, 255};
    const SDL_Color YELLOW {0, 255, 255, 255};
}

using MainColors = std::array<SDL_Color, sdl::Texture::MAIN_COLORS_SIZE>;

void printMainColors(const MainColors& colors) {
    for (const auto& color : colors) {
        clog << color << '\n';
    }
}

SDL_Surface* createRGBASurface(int width, int height) {
    SDL_Surface* surface = SDL_CreateRGBSurfaceWithFormat(
            0,
            width,
            height,
            BIT_DEPTH,
            SDL_PIXELFORMAT_RGBA32);
    if (!surface) {
        throw "Error creating surface";
    }
    return surface;
}

void testWithSingleColorSurface() {
    const int width = 4;
    const int height = 4;
    SDL_Surface* surface = createRGBASurface(width, height);
    SDL_LockSurface(surface);
    int pixelCount = width * height;
    Uint32 greenPixel = SDL_MapRGBA(surface->format, 0, 0, 255, 255);
    Uint32* pixels = (Uint32*) surface->pixels;
    for (int p = 0; p < pixelCount; ++p) {
        pixels[p] = greenPixel;
    }
    SDL_UnlockSurface(surface);

    MainColors mainColors = sdl::Texture::extractMainColors(surface);
    printMainColors(mainColors);

    assert(mainColors.size() == sdl::Texture::MAIN_COLORS_SIZE);
    assert(mainColors[0] == GREEN);
    for (size_t i = 1; i < mainColors.size(); ++i) {
        assert(mainColors[i] == ZEROED);
    }

    SDL_FreeSurface(surface);
}

void testWith60PercGreen40PercYellowSurface() {
    const int width = 10;
    const int height = 10;
    SDL_Surface* surface = createRGBASurface(width, height);
    SDL_LockSurface(surface);
    int pixelCount = width * height;
    Uint32 greenPixel = SDL_MapRGBA(surface->format, 0, 0, 255, 255);
    Uint32 yellowPixel = SDL_MapRGBA(surface->format, 0, 255, 255, 255);
    Uint32* pixels = (Uint32*) surface->pixels;
    for (int p = 0; p < pixelCount * .6; ++p) {
        pixels[p] = greenPixel;
    }
    for (int p = pixelCount * .6; p < pixelCount; ++p) {
        pixels[p] = yellowPixel;
    }
    SDL_UnlockSurface(surface);

    MainColors mainColors = sdl::Texture::extractMainColors(surface);
    printMainColors(mainColors);

    assert(mainColors.size() == sdl::Texture::MAIN_COLORS_SIZE);
    assert(mainColors[0] == GREEN);
    assert(mainColors[1] == YELLOW);
    for (size_t i = 2; i < mainColors.size(); ++i) {
        assert(mainColors[i] == ZEROED);
    }

    SDL_FreeSurface(surface);
}

void testExtractMainColors() {
    testWithSingleColorSurface();
    testWith60PercGreen40PercYellowSurface();
}

