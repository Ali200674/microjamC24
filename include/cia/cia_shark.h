#pragma once

#include <bn_fixed_rect.h>
#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>
#include <bn_display.h>
#include <bn_random.h>
#include <bn_sprite_animate_actions.h>

#include "cia_player.h"

namespace cia
{
    class shark
    {
    private:
        // how far left and right the shark can spawn (a little past the screen edges)
        static constexpr int MAX_X = bn::display::width() / 2 + 20;
        static constexpr int MIN_X = -bn::display::width() / 2 - 20;

    public:
        // makes a shark with a random start spot and a speed
        shark(bn::random &rng, bn::fixed speed);
        // moves the shark toward the player, call this every frame
        void update(cia::player &player);
        // the shark's hitbox for checking collisions
        bn::fixed_rect rect() const;
        // picks a random spot off the edge of the screen to spawn at
        bn::fixed_point getRandomStartPos(bn::random &random) const;

    private:
        // the shark's sprite on screen
        bn::sprite_ptr _sprite;
        // the swimming animation (4 frames)
        bn::sprite_animate_action<4> _action;
        // how fast the shark moves
        bn::fixed _speed;
    };
}