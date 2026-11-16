#pragma once
#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>
#include <bn_display.h>
#include <bn_rect.h>
//#include <bn_sprite_animate_actions.h>

#include "nsj_player.h"


class Enemy{
    static constexpr int MAX_X = bn::display::width() / 2;
    static constexpr int MIN_X = -bn::display::width() / 2;

    public:
     bn::sprite_ptr sprite;
     bn::fixed x_speed;
     bn::fixed y_speed;
     bn::size size;
     //bn::random rng;
     bn::rect bounding_box;
  
         Enemy(bn::fixed x_start, bn::fixed y_start,bn::fixed speed);

          void update(nsj::player& player);

    // private:
    //     // The sprite to display the player
    //     bn::sprite_ptr _sprite;
    //     bn::sprite_animate_action<4> _sprite_action;
       
    //     // The pixels/frame the player moves in each dimension
    //     bn::fixed _speed;

    //     /**
    //      * Reads from the d-pad and moves the player by one frame accordingly.
    //      */
    //     void _update_position();
};