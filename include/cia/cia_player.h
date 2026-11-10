#pragma once

#include <bn_fixed_rect.h>
#include <bn_fixed_point.h>
#include <bn_sprite_ptr.h>

namespace cia
{
    class player
    {
    public:
        player(bn::fixed_point starting_position, bn::fixed speed);
        void update();
        bn::fixed_rect rect() const;

    private:
        bn::sprite_ptr _sprite;

        bn::fixed _speed;
    };
}