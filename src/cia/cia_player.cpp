#include "cia/cia_player.h"

#include <bn_sprite_items_cia_scuba_player.h>
#include <bn_fixed_point.h>
#include <bn_fixed_rect.h>
#include <bn_fixed.h>
#include <bn_keypad.h>

namespace cia
{
    player::player(bn::fixed_point starting_position, bn::fixed speed) : _sprite(bn::sprite_items::cia_scuba_player.create_sprite(starting_position)),
                                                                         _speed(speed)
    {
    }

    bn::fixed_rect player::rect() const
    {
        return bn::fixed_rect(_sprite.position(), bn::fixed_size(32, 32));
    }

    void player::update()
    {
        if (bn::keypad::left_held())
        {
            _sprite.set_horizontal_flip(true);
            _sprite.set_x(_sprite.x() - _speed);
        }
        if (bn::keypad::right_held())
        {
            _sprite.set_horizontal_flip(false);
            _sprite.set_x(_sprite.x() + _speed);
        }
        if (bn::keypad::up_held())
        {
            _sprite.set_y(_sprite.y() - _speed);
        }
        if (bn::keypad::down_held())
        {
            _sprite.set_y(_sprite.y() + _speed);
        }
    }
}
