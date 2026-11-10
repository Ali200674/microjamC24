#include "cia_oceandive.h"

namespace cia
{
    cia_oceandive::cia_oceandive(int, const mj::game_data &) : mj::game("cia")
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