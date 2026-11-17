#pragma once

#include <bn_sprite_ptr.h>
#include <bn_display.h>

#include "mj/mj_game.h"

#include "bar/bar_create_bounding_box.h"

#include "bn_sprite_items_bar_bouncer.h"

namespace bar
{
    class bar_bouncer
    {
    public:
        /**
         *  Bouncer constructor that creates sprites at the given coordinates and with randomized speeds. Extends the
         * Butano sprite pointer class bn::sprite_ptr.
         *
         *  @param start_x The starting x coordinate the bouncer spawns at
         *  @param start_y The starting y coordinate the bouncer spawns at
         */
        bar_bouncer(bn::fixed x_start, bn::fixed y_start, bn::fixed base_speed, bn::size bouncer_size);

        /**
         *  Updates the position of the Bouncer sprite by checking whether or not it's position is greater
         * than the bounds of the screen.
         */
        void update();

        bn::sprite_ptr get_sprite() const
        {
            return _sprite;
        }

        bn::fixed get_speed() const
        {
            return _horizontal_speed;
        }

        bn::size get_size() const
        {
            return _size;
        }

        bn::rect get_bounding_box() const
        {
            return _bounding_box;
        }

        void set_bounding_box(bn::sprite_ptr sprite, bn::size size)
        {
            _bounding_box = bar_create_bounding_box(sprite, size);
        }

        bool is_hit() const
        {
            return _is_hit;
        }

        void set_hit(bool set_status)
        {
            _is_hit = set_status;
        }

        bool is_collided() const
        {
            return _is_collided;
        }

        void set_collided(bool set_status)
        {
            _is_collided = set_status;
        }

    private:
        // The bounds of the screen
        static constexpr int MAX_X = bn::display::width() / 2;
        static constexpr int MIN_X = -bn::display::width() / 2;
        static constexpr int MAX_Y = bn::display::height() / 2;
        static constexpr int MIN_Y = -bn::display::height() / 2;

        bn::sprite_ptr _sprite;
        bn::fixed _horizontal_speed;
        bn::size _size;
        bn::rect _bounding_box;
        bool _is_hit;
        bool _is_collided;
    };
}