#include "bn_sprite_items_ugb_hook.h"

#include "ugb/ugb_hook.h"

namespace ugb {

    Hook::Hook(bn::fixed_point spawn_position) : 
        Entity::Entity(bn::sprite_items::ugb_hook, spawn_position, 0.5), _spawn_y(spawn_position.y()), _going_down(true) {
        };

    void Hook::update() {
        bn::fixed current_y = _sprite.y();

        if (current_y >= _spawn_y + 32) {
            _going_down = false;
        } else if (current_y <= _spawn_y) {
            _going_down = true;
        }

        if (_going_down) {
            _sprite.set_y(current_y + _speed);
        } else {
            _sprite.set_y(current_y - _speed);
        }

        Entity::update();
    }
}