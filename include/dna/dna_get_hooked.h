#ifdef DNA_GET_HOOKED_H
#define DNA_GET_HOOKED_H

#include "mj/mj_game.h"

namespace dna 
{
class dna_get_hooked : public mj::game {
    public: 
        dna_get_hooked(int completed_games, const mj::game_data& data);

        bn::string<16> title() const override; 

        int total_frames() const override; 

        mj::game_result play(const mj::game_data& data) override; 

        bool victory() const override; 

        void fade_in(const mj::game_data& data) override; 
        void fade_out(const mj::game_data& data) override; 
}
}

#endif