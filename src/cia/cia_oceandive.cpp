#include "cia_oceandive.h"
#include "mj/mj_game_list.h"

namespace
{
    constexpr bn::string_view code_credits[] = {"Ali & Alex"};
    constexpr bn::string_view graphics_credits[] = {"BOOM"};
    constexpr bn::string_view sfx_credits[] = {""};
    constexpr bn::string_view music_credits[] = {""};
}

MJ_GAME_LIST_ADD(cia::cia_oceandive)
MJ_GAME_LIST_ADD_CODE_CREDITS(code_credits)
MJ_GAME_LIST_ADD_GRAPHICS_CREDITS(graphics_credits)
MJ_GAME_LIST_ADD_MUSIC_CREDITS(music_credits)
MJ_GAME_LIST_ADD_SFX_CREDITS(sfx_credits)

namespace cia
{
    cia_oceandive::cia_oceandive([[maybe_unused]] int completed_game, [[maybe_unused]] const mj::game_data &data) : mj::game("cia"),
                                                                                                                    _player(player({0, 20}, 1))
    {
    }

    bn::string<16> cia_oceandive::title() const
    {
        return "Dive!";
    }

    int cia_oceandive::total_frames() const
    {
        return 300;
    }

    mj::game_result cia_oceandive::play(const mj::game_data &)
    {
        _player.update();
        return mj::game_result();
    }

    bool cia_oceandive::victory() const
    {
        return false;
    }

    void cia_oceandive::fade_in(const mj::game_data &)
    {
    }

    void cia_oceandive::fade_out(const mj::game_data &)
    {
    }
}