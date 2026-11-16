#include "dna/dna_player.h"
#include <bn_keypad.h>

#include "bn_sprite_items_dna_dot.h"

namespace dna {
    Player::Player(bn::fixed_point starting_pos, bn::fixed speed, bn::size size) :
    _sprite(bn::sprite_items::dot.create_sprite(starting_pos)),
    _speed(speed), 
    
    
    void update(); 
    void player_hit();  
}