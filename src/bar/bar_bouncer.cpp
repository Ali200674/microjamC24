#include "bar_bouncer.h"

namespace bar
{
    bar_bouncer::bar_bouncer(bn::fixed x_start, bn::fixed y_start, bn::fixed base_speed, bn::size bouncer_size) : _sprite(bn::sprite_items::bar_bouncer.create_sprite(x_start, y_start)),
                                                                                                                  _horizontal_speed(base_speed), _size(bouncer_size),
                                                                                                                  _bounding_box(bar_create_bounding_box(_sprite, bouncer_size))
    {
    }

    void bar_bouncer::update()
    {
        bn::fixed y = get_sprite().y();

        set_collided(false);

        if (!is_hit())
        {
            y += _horizontal_speed;
        }
        else
        {
            y -= _horizontal_speed;
        }

        if (y <= MIN_Y)
        {
            set_hit(false);
        }

        set_hit(false);
        get_sprite().set_y(y);
        set_bounding_box(_sprite, _size);
    }
}