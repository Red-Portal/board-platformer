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

#ifndef _GAME_POLICY_HPP_
#define _GAME_POLICY_HPP_

#include <stdint.h>
#include <optional>
#include <vector>
#include <chrono>

#include <custom_settings2.hpp>

#include <board_platformer/types.hpp>
#include <board_platformer/messages.hpp>

namespace board_platformer
{
    namespace chrono = std::chrono;
    class player;
      
    class game_policy_base
    {
    public:
        virtual player_id_t 
        initialize_round(game_board_t& board) = 0;

        virtual player_id_t
        get_next_turn_id(game_status_t const& game_state) const = 0;

        virtual std::optional<player_id_t>
        check_winner(game_status_t const& game_state) const = 0;

        virtual std::optional<std::string>
        is_invalid_move(game_status_t const& game_state)const = 0;
    };
}

#endif
