/*
 * Audio.cpp
 *
 * Created 18 June 2019
 * Last modified 18 June 2019
 *
 * Andre Zunino <neyzunino@gmail.com>
 */

#include "Audio.hpp"
#include "SDLError.hpp"

namespace {
    const int AUDIO_SAMPLING_RATE = 44100;
    const int AUDIO_CHANNELS = 2;
    const int AUDIO_BUFFER_SIZE = 4096;
    const int MIN_VOLUME = 0;
    const int MAX_VOLUME = 128;
}

namespace sdl {

    // AUDIO

    Audio::Audio() {
        if (Mix_OpenAudio(
                    AUDIO_SAMPLING_RATE,
                    MIX_DEFAULT_FORMAT,
                    AUDIO_CHANNELS,
                    AUDIO_BUFFER_SIZE) == -1) {
            throw SDLError("Could not initialize audio mixer");
        }
    }

    Audio::~Audio() {
        Mix_CloseAudio();
    }

    // VOLUME

    Volume::Volume(int vol) {
        if (vol < MIN_VOLUME || vol > MAX_VOLUME) {
            throw SDLError("Invalid volume value");
        }
        volume = static_cast<uint8_t>(vol);
    }

    // MUSIC

    Music::Music(const char* const fileSpec) {
        music = Mix_LoadMUS(fileSpec);
        if (!music) {
            throw SDLError("Error loading music file");
        }
    }

    Music::~Music() {
        if (music) {
            Mix_FreeMusic(music);
        }
    }

    void Music::play() {
        if (Mix_PausedMusic()) {
            Mix_ResumeMusic();
            return;
        }
        if (Mix_PlayMusic(music, -1) == -1) {
            throw SDLError("Error playing music");
        }
    }

    void Music::pause() {
        Mix_PauseMusic();
    }

    void Music::volume(Volume vol) {
        Mix_VolumeMusic(vol);
    }

    Volume Music::volume() const {
        return Mix_VolumeMusic(-1);
    }

    // SFX
    Sfx::Sfx(const char* const fileSpec) {
        sfx = Mix_LoadWAV(fileSpec);
        if (!sfx) {
            throw SDLError("Error loading sfx file");
        }
    }

    Sfx::~Sfx() {
        if (sfx) {
            Mix_FreeChunk(sfx);
        }
    }

    void Sfx::play() {
        if (Mix_PlayChannel(-1, sfx, 0) == -1) {
            throw SDLError("Error playing sfx");
        }
    }

    void Sfx::volume(Volume vol) {
        Mix_VolumeChunk(sfx, vol);
    }

    Volume Sfx::volume() const {
        return Mix_VolumeChunk(sfx, -1);
    }

}

