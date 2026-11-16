#include "nsj_player.h"
#include "bn_sprite_ptr.h"
#include "bn_fixed.h"
#include "bn_size.h"
#include "bn_rect.h"


class Shark{
    public:
    bn::sprite_ptr sprite;
     bn::fixed x_speed;
     bn::fixed y_speed;
     bn::size size;
     bn::rect bounding_box;

     Shark(bn::fixed x_start, bn::fixed y_start,bn::fixed speed);

          void update(nsj::player& player);

};