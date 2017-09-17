#ifndef _GAME_STATUS_HPP_
#define _GAME_STATUS_HPP_

#include <vector>
#include <optional>
#include <functional>
#include <chrono>

#include <board_platformer/types.hpp>

namespace board_platformer
{
    namespace chrono = std::chrono;

    struct game_status_t
    {
        using player_moves = std::vector<point_t>;
        using player_moves_data = std::tuple<player_moves,
                                             chrono::milliseconds>;

        template<typename T>
        using optional_ref = std::optional<std::reference_wrapper<T>>;

        inline game_status_t(player_moves const& _moves,
                             player_id_t _turn,
                             chrono::milliseconds const& _time,
                             game_board_t const& _board,
                             size_t _turn_number)
            :game_board(_board),
             moves(std::ref(_moves)),
             turn(_turn),
             time(_time),
             turn_number(_turn_number) {}

        inline game_status_t(player_id_t _turn,
                             chrono::milliseconds const& _time,
                             game_board_t const& _board,
                             size_t _turn_number)
            :game_board(_board),
             moves({}),
             turn(_turn),
             time(_time),
             turn_number(_turn_number) {}
             
        game_board_t const& game_board;
        optional_ref<const player_moves> moves;
        player_id_t const& turn;
        chrono::milliseconds const& time;
        size_t turn_number;
    };

}

#endif
