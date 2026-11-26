#pragma once

#include "mj/mj_game.h"
#include "cia/cia_player.h"
#include "cia/cia_shark.h"
#include <bn_regular_bg_ptr.h>
#include <bn_vector.h>
namespace cia
{
    // the most sharks that can be on screen at once
    static constexpr int sharkPoolSize = 16;

    class cia_oceandive : public mj::game
    {
    public:
        // sets up the game, completed_games is used to pick the difficulty
        cia_oceandive(int completed_games, const mj::game_data &data);

        bn::fixed_rect rect() const;
        // the name shown before the game starts
        bn::string<16> title() const override;
        // how many frames the game lasts
        int total_frames() const override;
        // runs every frame while the game is going
        mj::game_result play(const mj::game_data &data) override;
        // true if the player won
        bool victory() const override;
        void fade_in(const mj::game_data &data) override;
        void fade_out(const mj::game_data &data) override;

        // spawns one more shark
        void addNewShark(const mj::game_data &data);
        // sets shark speed and spawn rate based on difficulty
        void set_up_game(mj::difficulty_level level);

    private:
        // the ocean background
        bn::regular_bg_ptr _bg;
        // Sprites
        player _player;

        // Vector to hold all sharks
        bn::vector<shark, sharkPoolSize> _sharkPool = {};

        // Frame per seconds and decrementing variable for it
        // timer that counts down to the next shark spawn
        bn::fixed _frames = 60;
        // how much the timer drops each frame (bigger = sharks spawn faster)
        bn::fixed _frameDecrement;


        // True once the shark hits the player
        bool _hit;

        // The sharks speed
        bn::fixed _sharksSpeed;

        // How much games have been completed
        int _completedGames;
    };

}