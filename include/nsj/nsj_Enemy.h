#pragma once
#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>
#include <bn_display.h>
#include <bn_rect.h>
//#include <bn_sprite_animate_actions.h>
#include <bn_random.h>
#include "nsj_player.h"


class Enemy{
    static constexpr int MAX_X = bn::display::width() / 2;
    static constexpr int MIN_X = -bn::display::width() / 2;
    static constexpr int MAX_Y = bn::display::height() / 2;
    static constexpr int MIN_Y = -bn::display::height() / 2;
    public:
     bn::sprite_ptr sprite;
     bn::fixed x_speed;
     bn::fixed y_speed;
     bn::size size;
     //bn::random rng;
     bn::rect bounding_box;
  
         Enemy(bn::fixed x_start, bn::fixed y_start,bn::fixed speed);

          void update(nsj::player& player);

     private:
    bn::random rng;
};