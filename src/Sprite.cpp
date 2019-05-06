/*
 * Sprite.cpp
 *
 *  Created:  Aug 31, 2014
 *  Modified: Jul 31, 2015
 *  Author:   Andre Zunino <neyzunino@gmail.com>
 */

#include "Texture.hpp"
#include "Sprite.hpp"

namespace sdl {

    Sprite::Sprite(Texture& texture, int tx, int ty, int fw, int fh, int fcount, float fps)
        : Sprite {texture, tx, ty, fw, fh, fcount, fps, 0} {
    }

    Sprite::Sprite(Texture& texture, int tx, int ty, int fw, int fh, int fcount, float fps, int initialFrame)
        : texture{texture}, zoomFactor{1.0f} {
        animationName = Animation::DEFAULT_ANIMATION_NAME;
        animations.insert(make_pair(animationName, Animation {animationName, tx, ty, fw, fh, fcount, fps,
                Animation::Type::CYCLIC, initialFrame}));
        src.x = tx;
        src.y = ty;
        src.w = fw;
        src.h = fh;
    }

    Sprite::~Sprite() {
    }

    void Sprite::updateRects() {
    }

    void Sprite::changeAnimation(const std::string& name, int initialFrame) {
        auto animIter = animations.find(name);
        if (animIter == animations.end()) {
            return;
        }
        animationName = name;
        animIter->second.frame = initialFrame;
        updateRects();
    }

    void Sprite::addAnimation(const std::string& name, int tx, int ty, int fw, int fh, int fcount, float fps,
            Animation::Type type) {
        Animation animation {name, tx, ty, fw, fh, fcount, fps, type};
        auto result = animations.insert(make_pair(name, animation));
        if (!result.second) { // key already exists; update value
            result.first->second = animation;
        }
    }

    void Sprite::update(float elapsedTime, float x, float y) {
        Animation& animation = animations.find(animationName)->second;
        dst.x = x - animation.fw * zoomFactor / 2;
        dst.y = y - animation.fh * zoomFactor / 2;
        dst.w = animation.fw * zoomFactor;
        dst.h = animation.fh * zoomFactor;
        animation.update(elapsedTime, src);
    }

    void Sprite::draw() const {
        SDL_RenderCopy(texture.renderer(), texture, &src, &dst);
    }

    /*
    * Sprite::Animation's implemention
    */

    const std::string Sprite::Animation::DEFAULT_ANIMATION_NAME = "default";

    Sprite::Animation::Animation(std::string name, int tx, int ty, int fw, int fh, int fcount,
            float fps, Type type, int initialFrame)
        : name{name}, tx{tx}, ty{ty}, fw{fw}, fh{fh}, fcount{fcount}, frameDuration{1000.0f / fps},
        accElapsedTime{0.0f}, type{type}, frame{initialFrame}, delta{1} {
    }

    void Sprite::Animation::changeType(Type type) {
        this->type = type;
    }

    void Sprite::Animation::update(float elapsedTime, SDL_Rect& src) {
        if (fcount < 2) {
            return;
        }
        accElapsedTime += elapsedTime;
        if (accElapsedTime < frameDuration) {
            return;
        }
        accElapsedTime -= frameDuration;
        frame += delta;
        if (frame > fcount - 1) {
            if (type == Type::CYCLIC) {
                frame = 0;
            } else if (type == Type::BOUNCE) {
                delta = -1;
                frame -= 2;
            }
        } else if (frame < 0) { // Type must be BOUNCE
            delta = 1;
            frame += 2;
        }
        src.x = tx + frame * src.w;
    }

}
