#pragma once

#include "bot/bot.hpp"

class Location {
    public: 
    Location();
    void start();
    void stop();
    void update();

    Particle raycast(Particle& particle);
    Particle estimate();

    private:
    float _last_left_encoder;
    float _last_right_encoder;

};