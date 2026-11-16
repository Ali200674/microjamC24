#include "bn_sprite_items_dna_dot.h"

#include "dna_aquatic_life.h"
#include "dna_hitbox.h"
            
namespace dna {
    static constexpr bn::size SIZE(8, 8); 

    AquaticLife::AquaticLife(bn::random &random, bn::fixed speed, bn::size size) :
    _sprite(bn::sprite_items::dna_dot.create_sprite(getStartPosition(random))), 
    _speed(speed), 
    _hitbox(create_hitbox(_sprite, size)) {}

    bn::fixed_point AquaticLife::getStartPosition(bn::random &random) {
        bn::fixed randY = random.get_fixed(MIN_Y + 20, MAX_Y + 20); 
        bn::fixed startX = MAX_X - 5; 

        return bn::fixed_point(startX, randY); 
    }

    void AquaticLife::update() {
        _sprite.set_x(_sprite.x() - _speed); 
    }
}