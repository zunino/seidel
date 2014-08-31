#include <iostream>

#include "Window.hpp"

namespace Seidel {

    Window::Window(const char* title, int w, int h) throw (SDLError)
            : Window(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, 0) {
        std::clog << "Window(title, width, height)\n";
    }

    Window::Window(const char* title, int w, int h, Uint32 flags) throw (SDLError)
            : Window(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, w, h, flags) {
        std::clog << "Window(title, width, height, flags)\n";
    }

    Window::Window(const char* title, int x, int y, int w, int h, Uint32 flags) throw (SDLError)
            : sdlRenderer(nullptr) {
        std::clog << "Window(title, x, y, width, height, flags)\n";
        sdlWindow = SDL_CreateWindow(title,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  SDL_WINDOWPOS_UNDEFINED,
                                  w,
                                  h,
                                  0);
        if (sdlWindow == nullptr) {
            throw SDLError();
        }
    }

    Window::~Window() {
        std::clog << "~Window()\n";
        std::clog << "Destroying Renderer\n";
        SDL_DestroyRenderer(sdlRenderer);
        std::clog << "Destroying Window\n";
        SDL_DestroyWindow(sdlWindow);
    }

    SDL_Renderer* Window::renderer() throw (SDLError) {
        std::clog << "Window::renderer()\n";
        return renderer(SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    }

    SDL_Renderer* Window::renderer(Uint32 flags) throw (SDLError) {
        std::clog << "Window::renderer(flags)\n";
        if (sdlRenderer == nullptr) {
            sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, flags);
            if (sdlRenderer == nullptr) {
                throw SDLError();
            }
        }
        return sdlRenderer;
    }

}