#include "cia/cia_player.h"

#include <bn_sprite_items_cia_scuba_player.h>
#include <bn_fixed_point.h>
#include <bn_fixed_rect.h>
#include <bn_fixed.h>
#include <bn_keypad.h>

// Namespace with code contained to cia game
namespace cia
{
    /**
     * Constructor for player. Takes a starting position as a bn::fixed_point and a speed as bn::fixed
     */
    player::player(bn::fixed_point starting_position, bn::fixed speed)
        : _sprite(bn::sprite_items::cia_scuba_player.create_sprite(starting_position)),
          _speed(speed)
    {
    }

    /**
     * Method for returning bounding box of player
     */
    bn::fixed_rect player::rect() const
    {
        return bn::fixed_rect(_sprite.position(), bn::fixed_size(32, 32));
    }

    /**
     * Method for updating the player based on the d-pad
     */
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

    /**
     * Returns if the player is out of bounds based on the screen
     */
    bool player::is_out_of_bounds() const
    {
        return _sprite.x() > MAX_X ||
               _sprite.x() < MIN_X ||
               _sprite.y() > MAX_Y ||
               _sprite.y() < MIN_Y;
    }
}
