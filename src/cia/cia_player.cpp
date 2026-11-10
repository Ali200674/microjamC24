#include "cia/cia_player.h"

#include <bn_sprite_items_cia_scuba_player.h>
#include <bn_keypad.h>

namespace cia
{
    player::player() : _sprite(bn::sprite_items::cia_scuba_player.create_sprite(0, 0))
    {
    }

    void player::update()
    {
    }
}
