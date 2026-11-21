#include "nsj_Shark.h"
#include "nsj_boundingBox.h"
#include "bn_sprite_items_nsj_shark.h"

static constexpr bn::size SHARK_SIZE = {16, 16};

Shark::Shark(bn::fixed x_start, bn::fixed y_start,bn::fixed speed) : sprite(bn::sprite_items::nsj_shark.create_sprite(x_start, y_start)),
                                                   x_speed(speed), y_speed(speed),
                                                   size(SHARK_SIZE)
    {
        bounding_box=create_bounding_box(sprite, size);
    }


    void Shark:: update([[maybe_unused]]nsj::player& player){
         if (player.get_position().x() > sprite.x())
        {
            sprite.set_x(sprite.x() + x_speed);
            sprite.set_horizontal_flip(true);
        }
       else if (player.get_position().x() < sprite.x())
        {
            sprite.set_x(sprite.x() - x_speed);
             sprite.set_horizontal_flip(false);
        }
        if (player.get_position().y()> sprite.y())
         {
            sprite.set_y(sprite.y()  + y_speed) ;
         }

         else if (player.get_position().y() < sprite.y())
         {
             sprite.set_y(sprite.y() - y_speed);
         }

       bounding_box = create_bounding_box(sprite, size);




    }