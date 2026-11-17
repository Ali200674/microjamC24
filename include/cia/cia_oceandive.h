#pragma once

#include "mj/mj_game.h"
#include "cia/cia_player.h"
#include "cia/cia_shark.h"

#include <bn_vector.h>
namespace cia
{

    class cia_oceandive : public mj::game
    {
    public:
        cia_oceandive(int completed_games, const mj::game_data &data);

        bn::fixed_rect rect() const;
        bn::string<16> title() const override;
        int total_frames() const override;
        mj::game_result play(const mj::game_data &data) override;
        bool victory() const override;
        void fade_in(const mj::game_data &data) override;
        void fade_out(const mj::game_data &data) override;

        void addNewShark(const mj::game_data &data);

    private:
        // Sprites
        player _player;
        shark _shark;

        // Vector to hold all sharks
        bn::vector<shark, 16> sharkPool = {};

        // True once the shark hits the player
        bool _hit;

        // How much games have been completed
        int _completedGames;
    };

}