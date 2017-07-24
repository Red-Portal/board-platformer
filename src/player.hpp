#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <experimental/filesystem>

#include <board_platformer/constants.hpp>

#include "game.hpp"

namespace board_platformer
{
    class player
    {
    public:
        player();

        std::pair<game::board_state, point>
        play_turn(game::board const&);
    };
}

#endif 
