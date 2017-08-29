#ifndef _MOVE_HISTORY_HPP_
#define _MOVE_HISTORY_HPP_

#include <vector>
#include <chrono>

#include <board_platformer/types.hpp>

namespace board_platformer
{
    using player_moves = std::vector<bp::point_t>;
    using player_moves_data = std::tuple<player_moves,
                                         chrono::milliseconds>;
    struct move_history
    {
        player_moves moves;
        size_t turn_number;
        chrono::milliseconds move_time;
        player_id_t next_turn;
    };
}

#endif
