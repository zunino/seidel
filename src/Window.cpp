/*
 * Window.cpp
 *
 *  Created on: Aug 31, 2014
 * Modified on: Aug 3, 2015
 *      Author: Andre Zunino <neyzunino@gmail.com>
 */

#include "Window.hpp"

namespace sdl {

Window::Window(const char* title, int w, int h) throw (SDLError)
        : Window(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, 0) {
}

Window::Window(const char* title, int w, int h, Uint32 flags) throw (SDLError)
        : Window(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, flags) {
}

Window::Window(const char* title, int x, int y, int w, int h, Uint32 flags) throw (SDLError)
        : sdlRenderer(nullptr) {
    sdlWindow = SDL_CreateWindow(title,
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              w,
                              h,
                              SDL_WINDOW_RESIZABLE);
    if (sdlWindow == nullptr) {
        throw SDLError();
    }
}

Window::~Window() {
    SDL_DestroyRenderer(sdlRenderer);
    SDL_DestroyWindow(sdlWindow);
}

SDL_Renderer* Window::renderer() throw (SDLError) {
    return renderer(SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

SDL_Renderer* Window::renderer(Uint32 flags) throw (SDLError) {
    if (sdlRenderer == nullptr) {
        sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, flags);
        if (sdlRenderer == nullptr) {
            throw SDLError();
        }
    }
    return sdlRenderer;
}

} /* namespace sdl */
