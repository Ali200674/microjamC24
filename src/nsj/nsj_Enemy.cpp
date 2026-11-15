#include "nsj_Enemy.h"
#include "nsj_player.h"
#include "bn_sprite_ptr.h"
#include "bn_sprite_items_nsj_fish.h"
#include "bn_sprite_items_nsj_hook.h"
#include <bn_keypad.h>
#include "nsj_boundingBox.h"


static constexpr bn::size ENEMY_SIZE = {8, 8};

Enemy::Enemy(bn::fixed x_start, bn::fixed y_start,bn::fixed speed) : sprite(bn::sprite_items::nsj_hook.create_sprite(x_start, y_start)),
                                                   x_speed(speed), y_speed(speed),
                                                   size(ENEMY_SIZE)
    {
        create_bounding_box(sprite, size);
    }

   

    void Enemy:: update(nsj::player& player){
        if (player.get_sprite().x() +20 > sprite.x())
        {
            sprite.set_x(sprite.x() + x_speed);
        }
       if (player.get_sprite().x() -20 < sprite.x())
        {
            sprite.set_x(sprite.x() - x_speed);
             
        }
        // TODO: Add logic for up and down
        if (player.get_sprite().y()+20> sprite.y())
         {
            sprite.set_y(sprite.y()  + y_speed) ;
         }

         if (player.get_sprite().y() -20 < sprite.y())
         {
             sprite.set_y(sprite.y() - y_speed);
         }

       bounding_box = create_bounding_box(sprite, size);

       
    }