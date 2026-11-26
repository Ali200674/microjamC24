#include "cia/cia_player.h"

#include <bn_sprite_items_cia_scuba_player.h>
#include <bn_fixed_point.h>
#include <bn_fixed_rect.h>
#include <bn_fixed.h>
#include <bn_keypad.h>

// Namespace with code contained to cia game
namespace cia
{
    // size of the player's hitbox (width, height)
    static constexpr bn::fixed_size PLAYER_SIZE(32, 18);

    /**
     * Constructor for player. Takes a starting position as a bn::fixed_point and a speed as bn::fixed
     */
    player::player(bn::fixed_point starting_position, bn::fixed speed)
        // makes the sprite at the starting position
        : _sprite(bn::sprite_items::cia_scuba_player.create_sprite(starting_position)),
          // loops through the 4 frames forever, switching every 6 ticks
          _action(bn::create_sprite_animate_action_forever(
              _sprite, 6, bn::sprite_items::cia_scuba_player.tiles_item(), 0, 1, 2, 3)),
          // save the speed that was passed in
          _speed(speed)
    {
    }

    /**
     * Method for returning bounding box of player
     */
    bn::fixed_rect player::rect() const
    {
        // hitbox is centered on the sprite and uses PLAYER_SIZE
        return bn::fixed_rect(_sprite.position(), PLAYER_SIZE);
    }

    /**
     * Method for updating the player based on the d-pad
     */
    void player::update()
    {

        // move the animation to the next frame
        _action.update();
        if (bn::keypad::left_held())
        {
            // flip the sprite so it faces left and move left
            _sprite.set_horizontal_flip(true);
            _sprite.set_x(_sprite.x() - _speed);
        }
        if (bn::keypad::right_held())
        {
            // face right and move right
            _sprite.set_horizontal_flip(false);
            _sprite.set_x(_sprite.x() + _speed);
        }
        if (bn::keypad::up_held())
        {
            // y gets smaller as you go up on the screen
            _sprite.set_y(_sprite.y() - _speed);
        }
        if (bn::keypad::down_held())
        {
            // y gets bigger as you go down on the screen
            _sprite.set_y(_sprite.y() + _speed);
        }
    }

    /**
     * Method that returns the x position of the player as a bn::fixed variable
     */
    bn::fixed player::get_x() const { return _sprite.x(); }

    /**
     * Method that returns the y position of the player as a bn::fixed variable
     */
    bn::fixed player::get_y() const { return _sprite.y(); }
}