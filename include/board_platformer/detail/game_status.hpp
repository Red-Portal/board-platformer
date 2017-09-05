#ifndef _GAME_STATUS_HPP_
#define _GAME_STATUS_HPP_

#include <vector>
#include <optional>
#include <chrono>

#include <board_platformer/types.hpp>

namespace board_platformer
{
    namespace chrono = std::chrono;
    using player_moves = std::vector<point_t>;
    using player_moves_data = std::tuple<player_moves,
                                         chrono::milliseconds>;
    struct game_status_t
    {
        inline game_status_t(player_moves const& _moves,
                             player_id_t const& _previous_turn,
                             chrono::milliseconds const& move_time,
                             size_t turn_number);
        player_moves const& moves;
        player_id_t const& previous_turn;
        chrono::milliseconds const& move_time;
        size_t turn_number;
    };

    game_status_t::
    game_status_t(player_moves const& _moves,
                  player_id_t const& _previous_turn,
                  chrono::milliseconds const& _move_time,
                  size_t _turn_number)
        :moves(_moves),
         previous_turn(_previous_turn),
         move_time(_move_time),
         turn_number(_turn_number)
    {}
}

#endif
