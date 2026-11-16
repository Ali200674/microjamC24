#include "dna_get_hooked.h"

#include "bn_keypad.h"

#include "mj/mj_game_list.h"

namespace
{
    constexpr bn::string_view code_credits[] = { "kohumukini" };
    constexpr bn::string_view graphics_credits[] = { "" };
    constexpr bn::string_view sfx_credits[] = {""};
    constexpr bn::string_view music_credits[] = {""};
}

MJ_GAME_LIST_ADD(dna::dna_get_hooked) 
MJ_GAME_LIST_ADD_CODE_CREDITS(code_credits)
MJ_GAME_LIST_ADD_GRAPHICS_CREDITS(graphics_credits)
MJ_GAME_LIST_ADD_MUSIC_CREDITS(music_credits)
MJ_GAME_LIST_ADD_SFX_CREDITS(sfx_credits)

namespace dna
{
    dna_get_hooked::dna_get_hooked([[maybe_unused]] int completed_games, [[maybe_unused]] const mj::game_data& data) :
    mj::game("dna") {}

    bn::string<16> dna_get_hooked::title() const {
        return "Harvest Fish!";
    }

    int dna_get_hooked::total_frames() const {
        return 600; 
    }

    mj::game_result dna_get_hooked::play([[maybe_unused]] const mj::game_data& data) {
        mj::game_result result(victory(), false); 
        return result; 
    }

    bool dna_get_hooked::victory() const {
        return false; 
    }

    void dna_get_hooked::fade_in([[maybe_unused]] const mj::game_data& data)
    {
    }

    void dna_get_hooked::fade_out([[maybe_unused]] const mj::game_data& data)
    {
    }
}