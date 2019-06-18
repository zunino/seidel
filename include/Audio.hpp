/*
 * Audio.hpp
 *
 * Created 18 June 2019
 * Last modified 18 June 2019
 *
 * Andre Zunino <neyzunino@gmail.com>
 */

#ifndef SEIDEL_AUDIO_HPP
#define SEIDEL_AUDIO_HPP

#include <cstdint>

#include <SDL2/SDL_mixer.h>

namespace sdl {

    struct Audio final {
        Audio();
        ~Audio();
    };

    struct Volume final {
        Volume(int vol);
        operator int() { return volume; }
    private:
        uint8_t volume;
    };

    struct Music final {
        Music(const char* const fileSpec);
        ~Music();
        operator Mix_Music*() { return music; }
        void play();
        void pause();
        void volume(Volume vol);
        Volume volume() const;
    private:
        Mix_Music* music;
    };

    struct Sfx final {
        Sfx(const char* const fileSpec);
        ~Sfx();
        operator Mix_Chunk*() { return sfx; }
        void play();
        void volume(Volume vol);
        Volume volume() const;
    private:
        Mix_Chunk* sfx;
    };

}

#endif
