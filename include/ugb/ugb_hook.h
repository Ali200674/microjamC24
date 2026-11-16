#pragma once

#include "ugb/ugb_entity.h"

namespace ugb {

    class Hook : public Entity {
        public:
            Hook(bn::fixed_point spawn_position);
            void update() override;

        private:
            bn::fixed _spawn_y;
            bool _going_down;
    };
    
}