#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <utility>

#include <boost/process/child.hpp>

#include <board_platformer/filesystem.hpp>
#include <board_platformer/types.hpp>
#include <board_platformer/point.hpp>
#include <board_platformer/detail/rpc_message.pb.h>

#include "game.hpp"

namespace board_platformer
{
    namespace ps = boost::process;

    class player
    {
    private:
        ps::child _player_process;

    public:
        player(ps::child const& player_process);

        std::pair<unit_type, board_platformer::point>
        play_turn(game::game_board const&);
    };
}

#endif 
