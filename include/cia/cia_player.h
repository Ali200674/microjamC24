#pragma once

#include "bn_fixed_rect.h"
#include "bn_sprite_ptr.h"

namespace cia
{
    class player
    {
    public:
        player();
        void update();
        bn::fixed_rect rect() const;

    private:
        bn::sprite_ptr _sprite;
    };
}