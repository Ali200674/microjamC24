#include "dna_hitbox.h"
#include "dna_player.h"

namespace dna {
    bn::rect create_hitbox(Player sprite, bn::size box_size) {
        return bn::rect(
            sprite.get_x().round_integer(), 
            sprite.get_y().round_integer(), 
            box_size.width(), 
            box_size.height()
        );
    }
}