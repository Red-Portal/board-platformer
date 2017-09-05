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
#include <chrono>
#include <vector>
#include <functional>

#include <board_platformer/types.hpp>
#include <board_platformer/detail/rpc.hpp>
#include <board_platformer/detail/game_board.hpp>
#include <board_platformer/game_base.hpp>
#include <board_platformer/ui_events.hpp>
#include <board_platformer/game_status.hpp>

#include <custom_settings.hpp>

#include "player.hpp"

namespace boost::process { class child; }

namespace board_platformer
{
    namespace chrono = std::chrono;
    namespace ps = boost::process;

    template<typename T>
    using ref = std::reference_wrapper<T>;

    using player_moves = std::vector<bp::point_t>;

    class game
    {
        using player_and_address = std::pair<ps::child, address_t>;
    private:
        std::vector<player> _players;
        std::unique_ptr<game_base> _game_settings;
        std::unique_ptr<game_base> _ui_events;
        ::game::game_board _game_board;
        chrono::seconds _time_limit;
        size_t _turn_number;

        void
        game_loop(); 

        player_id_t init_game();

        void
        add_players(std::vector<player_and_address>&& players);

        game_status_t
        next_turn(player_id_t const& current_turn);

    public:
        explicit game(size_t number_of_players,
                      chrono::seconds const& time_count,
                      std::unique_ptr<game_base>&& game_settings,
                      std::unique_ptr<>&& ui);

        void game_start();
    };
}

#endif
