#include "cia_shark.h"
#include "cia_player.h"

#include "bn_sprite_items_cia_shark.h"

namespace cia
{
    static constexpr bn::fixed_size SHARK_SIZE(24, 12);

    shark::shark(bn::fixed_point starting_position, bn::fixed speed) : _sprite(bn::sprite_items::cia_shark.create_sprite(starting_position)),
                                                                       _speed(speed)
    {
        _sprite.set_horizontal_flip(true);
    }

    void shark::update(cia::player &player)
    {
        // If the shark is to the right of the player, go left
        if (_sprite.x() < player.getPlayerXPos())
        {
            _sprite.set_x(_sprite.x() + _speed);
        }

        // If the player is to the left of the player, go right
        if (_sprite.x() > player.getPlayerXPos())
        {
            _sprite.set_x(_sprite.x() - _speed);
        }

        // If the player is below the shark, go down
        if (_sprite.y() < player.getPlayerYPos())
        {
            _sprite.set_y(_sprite.y() + _speed);
        }

        // If the player is above the shark, go up
        if (_sprite.y() > player.getPlayerYPos())
        {
            _sprite.set_y(_sprite.y() - _speed);
        }
    }

    bn::fixed_rect shark::rect() const
    {
        return bn::fixed_rect(_sprite.position(), SHARK_SIZE);
    }
}
