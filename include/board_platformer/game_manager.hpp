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
#include <optional>
#include <memory>
#include <type_traits>
#include <chrono>
#include <vector>
#include <functional>

#include <boost/process/child.hpp>

#include <board_platformer/detail/player.hpp>
#include <board_platformer/filesystem.hpp>
#include <board_platformer/types.hpp>
#include <board_platformer/game_policy.hpp>
#include <board_platformer/player_process_data.hpp>
#include <board_platformer/game_board.hpp>
#include <board_platformer/ui_policy.hpp>
#include <board_platformer/messages.hpp>

namespace board_platformer
{
    namespace bp = board_platformer;
    namespace chrono = std::chrono;
    namespace pc = boost::process;

    template<typename T>
    using ref = std::reference_wrapper<T>;

    using player_moves = std::vector<bp::point_t>;

    template<typename GamePolicy,
             typename UIPolicy>
    class game_manager : public GamePolicy, public UIPolicy
    {
        static_assert(
            std::is_base_of<game_policy_base, GamePolicy>::value,
            "provided game policy is not a subtype of class game_policy_base");
        static_assert(
            std::is_base_of<ui_policy_base, UIPolicy>::value,
            "provided ui policy is not a subtype of class ui_policy_base");


    private:
        std::vector<player> _players;
        game_board_t _game_board;
        chrono::milliseconds _time_limit;
        size_t _turn_number;

        // game_status_t
        // make_game_status(player_id_t const& turn) const;

        void
        game_loop(); 

        player_id_t
        init_game(game_board_t const& board) const;

        // game_status_t 
        // play_turn(player_id_t const& current_turn);

        // bool
        // process_move(game_status_t const& player_move_data) const;
        
        
        // game_status_t
        // make_turn_info(player_id_t const& current_turn,
        //                chrono::milliseconds const& time_limit) const;

        // player_id_t
        // get_next_turn(game_status_t const& game_status) const;


        pc::child
        maybe_run_process(player_process_data const& player) const;

    public:
        explicit game_manager(
            size_t const number_of_players,
            game_board_t&& game_board,
            chrono::milliseconds const& time_count);

        void add_players(std::vector<player_process_data>&& players);

        void game_start();
    };
}

#include <board_platformer/game_manager.tpp>

#endif
