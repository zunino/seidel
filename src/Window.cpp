/*
 * Window.cpp
 *
 * Created:  Aug 31, 2014
 * Modified: Aug 3, 2015
 * Author:   Andre Zunino <neyzunino@gmail.com>
 */

#include "Window.hpp"
#include "SDLError.hpp"

namespace sdl {

    Window::Window(const char* title, int w, int h)
            : Window(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, 0) {
    }

    Window::Window(const char* title, int w, int h, Uint32 flags)
            : Window(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, flags) {
    }

    Window::Window(const char* title, int x, int y, int w, int h, Uint32 flags)
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

    SDL_Renderer* Window::renderer() {
        return renderer(0);
    }

    SDL_Renderer* Window::renderer(Uint32 flags) {
        if (sdlRenderer == nullptr) {
            sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, flags);
            if (sdlRenderer == nullptr) {
                throw SDLError();
            }
        }
        return sdlRenderer;
    }

    void Window::clear(const SDL_Color& color) {
        SDL_Color curr;
        SDL_GetRenderDrawColor(renderer(), &curr.r, &curr.g, &curr.b, &curr.a);
        SDL_SetRenderDrawColor(renderer(), color.r, color.g, color.b, color.a);
        SDL_RenderClear(renderer());
        SDL_SetRenderDrawColor(renderer(), curr.r, curr.g, curr.b, curr.a);
    }

}
