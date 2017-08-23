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

#ifndef _CUSTOM_SETTINGS_1_HPP_
#define _CUSTOM_SETTINGS_1_HPP_

#include <array>
#include <algorithm>

#include <board_platformer/detail/game_board.hpp>
#include <board_platformer/detail/game_base.hpp>

#include <../src/player.hpp> // should do something about this

namespace bp = board_platformer;

namespace game
{
    typedef bp::game_board_impl<19, 19> game_board;

    size_t const number_of_player = 2;

    class game_settings : public bp::game_base
    {
    private:
        std::optional<bp::player_id_t>
        check_line(game_board const& board)
        {
        }

    public:
        virtual bp::player_id_t
        play_next_turn(bp::player_id_t const& previous_turn) override final
        {
            if(previous_turn == 0)
                return {1};
            else
                return {0};
        }

        virtual bp::player_id_t
        initialize_round(
            game_board& board,
            std::vector<bp::player> const& players) override final
        {
            (void)players; // suppressing error message
            
            for(size_t i = 0; i < board.row_size(); ++i)
            {
                for(size_t j = 0; j < board.col_size(); ++j)
                    board(i, j) = bp::point_state_t(0);
            }

            return bp::player_id_t(0);
        }

        virtual std::optional<bp::player_id_t>
        check_winner(game_board const& current_board) override final
        {
            
        }
    };
}

#endif
