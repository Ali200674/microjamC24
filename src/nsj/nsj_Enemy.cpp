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
        bounding_box=create_bounding_box(sprite, size);
    }

   

    void Enemy:: update([[maybe_unused]]nsj::player& player){
    
             sprite.set_x(sprite.x() + x_speed);
    
    //    if (sprite.x() >=MAX_X)
    //     {
    //         x_speed= -x_speed;
             
    //     }
    //     else if(sprite.x() <=MIN_X)
    //      {
    //         x_speed= -x_speed;
    //      }

    if (sprite.x() >= MAX_X)
    {
        sprite.set_x(MIN_X);
        sprite.set_y(rng.get_int(-60, 40));
    }

    else if (sprite.x() <= MIN_X)
    {
        sprite.set_x(MAX_X);
        sprite.set_y(rng.get_int(-60, 40));
    }
       

       bounding_box = create_bounding_box(sprite, size);

       
    }