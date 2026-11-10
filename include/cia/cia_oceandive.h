#pragma once

#include "mj/mj_game.h"


namespace cia
{

    class cia_oceandive : public mj::game
    {
        cia_oceandive(int completed_games, const mj::game_data& data);


        bn::string<16> title() const override;
        int total_frames() const override;
        mj::game_result play(const mj::game_data& data) override;
        bool victory() const override;
        void fade_in(const mj::game_data& data) override;
        void fade_out(const mj::game_data& data) override;
    };


}