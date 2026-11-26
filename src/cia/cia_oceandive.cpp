#include "cia_oceandive.h"
#include "mj/mj_game_list.h"
#include "cia/cia_shark.h"
#include <bn_regular_bg_ptr.h>
#include <bn_regular_bg_items_cia_ocean_bg.h>
#include "bn_sound_items.h"
namespace
{
    // names that show up in the credits for each part of the game
    constexpr bn::string_view code_credits[] = {"Ali", "Alex"};
    constexpr bn::string_view graphics_credits[] = {""};
    constexpr bn::string_view sfx_credits[] = {""};
    constexpr bn::string_view music_credits[] = {""};
}

// these add our game to the microgame list so the main game can find it
MJ_GAME_LIST_ADD(cia::cia_oceandive)
MJ_GAME_LIST_ADD_CODE_CREDITS(code_credits)
MJ_GAME_LIST_ADD_GRAPHICS_CREDITS(graphics_credits)
MJ_GAME_LIST_ADD_MUSIC_CREDITS(music_credits)
MJ_GAME_LIST_ADD_SFX_CREDITS(sfx_credits)

namespace cia
{
    // sets the speed values depending on how hard the game is
    void cia_oceandive::set_up_game(mj::difficulty_level level) {
        // create a if statement for an easy mode
        if (level == mj::difficulty_level::EASY)
        {
            // bigger frameDecrement means sharks spawn faster
            _frameDecrement = 1.22;
            // how fast each shark swims
            _sharksSpeed = 0.41;
        }
        // make a medium mode
        else if (level == mj::difficulty_level::NORMAL)
        {
            _frameDecrement = 1.32;
            _sharksSpeed = 0.45;
        }
        // Assuming that we didn't go into the other if statements (This is for hard mode)
        else
        {
            _frameDecrement = 1.55;
            _sharksSpeed = 0.5;
        }
    }

    // adds one more shark to the game
    void cia_oceandive::addNewShark(const mj::game_data &data) {
        // only add one if the pool still has room
        if (!_sharkPool.full()) {
            _sharkPool.push_back(shark(data.random, _sharksSpeed));
        }
    }


    // sets up the background, the player, and picks the difficulty
    cia_oceandive::cia_oceandive([[maybe_unused]] int completed_game, [[maybe_unused]] const mj::game_data &data) : mj::game("cia"),
                                                                                                _bg(bn::regular_bg_items::cia_ocean_bg.create_bg(0, 0)),
                                                                                                _player(player({0, 20}, 1)),
                                                                                                _hit(false)
    {
        // the game gives us a recommended difficulty based on how many games were beat
        set_up_game(recommended_difficulty_level(completed_game, data));
        _completedGames = completed_game;
        // start the wave sound
        play_sound(bn::sound_items::cia_wave, completed_game, data);
    }

    // the name shown on screen before the game starts
    bn::string<16> cia_oceandive::title() const
    {
        return "Avoid The Shark!";
    }

    // how long the game lasts (300 frames is about 5 seconds)
    int cia_oceandive::total_frames() const
    {
        return 300;
    }

    // runs every frame while the game is going
    mj::game_result cia_oceandive::play(const mj::game_data &data)
    {
        // replay the wave sound every 3 seconds so it keeps looping
        _waveTimer++;
        if (_waveTimer >= 180)
        {
            play_sound(bn::sound_items::cia_wave, _completedGames, data);
            _waveTimer = 0;
        }

        // move the player with the d-pad
        _player.update();

        // go through every shark and make it chase the player
        for (shark& s : _sharkPool) {
            s.update(_player);

            // If the player intersects with the shark, the player loses.
            if (_player.rect().intersects(s.rect()))
            {
                _hit = true;
            }
        }

        // count down the timer for the next shark
        _frames -= _frameDecrement;

        // when the timer runs out, spawn a shark and start the timer over
        if (_frames < 0) {
            addNewShark(data);
            _frames = 60;
        }   

        // first value ends the game early if we got hit
        return mj::game_result(_hit, false);
    }

    // we win if we never got hit
    bool cia_oceandive::victory() const
    {
        return !_hit;
    }

    // nothing special for the fade in and fade out
    void cia_oceandive::fade_in(const mj::game_data &)
    {
    }

    void cia_oceandive::fade_out(const mj::game_data &)
    {
    }
}