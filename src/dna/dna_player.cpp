#include "dna/dna_player.h"
#include "dna/dna_hitbox.h"

#include <bn_keypad.h>

#include "bn_sprite_items_dna_dot.h"

namespace dna {
    Player::Player(bn::fixed_point starting_pos, bn::fixed speed, bn::size size) :
    _sprite(bn::sprite_items::dna_dot.create_sprite(starting_pos)),
    _speed(speed),
    _hitbox(create_hitbox(_sprite, size)) {}
    
    void Player::update() {
        _update_position(); 
    }

    void Player::_update_position() {
        if (bn::keypad::left_held()) {
            _sprite.set_x(_sprite.x() - _speed);
        } 
        if (bn::keypad::right_held()) {
            _sprite.set_x(_sprite.x() + _speed);
        } 
        if (bn::keypad::up_held()) {
            _sprite.set_y(_sprite.y() - _speed);
        }
        if (bn::keypad::down_held()) {
            _sprite.set_y(_sprite.y() + _speed);
        }
    }

    void Player::player_hit() {
        
    } 
}