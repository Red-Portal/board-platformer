#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <experimental/filesystem>

#include <board_platformer/types.hpp>
#include <board_platformer/point.hpp>
#include <board_platformer/detail/rpc_message.pb.h>

#include "game.hpp"

namespace board_platformer
{

    class player
    {
    public:
        player();

        std::pair<unit_type, board_platformer::point>
        play_turn(game::game_board const&);
    };
}

#endif 
