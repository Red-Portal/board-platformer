// Board Platformer. A Board Game AI Developing Platform
// Copyright (C) 2017  Red-Portal
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef _GAME_MANAGER_HPP_
#define _GAME_MANAGER_HPP_

#include <vector>
#include <variant>
#include <memory>
#include <type_traits>
#include <chrono>
#include <vector>
#include <functional>

#include <board_platformer/types.hpp>
#include <board_platformer/detail/rpc.hpp>
#include <board_platformer/detail/game_board.hpp>
#include <board_platformer/detail/player.hpp>
#include <board_platformer/game_policy.hpp>
#include <board_platformer/ui_policy.hpp>
#include <board_platformer/messages.hpp>

#include <custom_settings.hpp>


namespace boost::process { class child; }

namespace board_platformer
{
    namespace chrono = std::chrono;
    namespace ps = boost::process;

    template<typename T>
    using ref = std::reference_wrapper<T>;

    using player_moves = std::vector<bp::point_t>;

    template<typename GamePolicy,
             typename UIPolicy,
             typename GameBoard,
             typename = std::enable_if<
                 std::is_same<GameBoard,
                              game_board_impl>::value>::type>
    class game_manager : public GamePolicy, public UIPolicy
    {
        using player_and_address = std::pair<ps::child, address_t>;
    private:
        std::vector<player> _players;
        // std::unique_ptr<game_base> _game_settings;
        // std::unique_ptr<game_base> _ui_events;
        ::game::game_board _game_board;
        chrono::milliseconds _time_limit;
        size_t _turn_number;

        game_status_t
        make_game_status(player_id_t const& turn) const;

        void
        game_loop(); 

        player_id_t
        init_game(::game::game_board const& board) const;

        game_status_t 
        play_turn(player_id_t const& current_turn);

        bool
        process_move(game_status_t const& player_move_data) const;
        
        
        game_status_t
        make_turn_info(player_id_t const& current_turn,
                       chrono::milliseconds const& time_limit) const;

        player_id_t
        get_next_turn(game_status_t const& game_status) const;

    public:
        explicit game_manager(
            size_t number_of_players,
            chrono::milliseconds const& time_count,
            std::vector<player_and_address>&& players);

        void game_start();
    };
}

#include <board_platformer/game_manager.tpp>

#endif
