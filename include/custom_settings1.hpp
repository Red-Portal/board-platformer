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

#include <board_platformer/detail/game_board.hpp>
#include <board_platformer/detail/game_base.hpp>

namespace game
{
    namespace bp = board_platformer;

    template<size_t tX, size_t tY>
    void
    game_board_impl<tX, tY>::
    initialize_board(game_board_impl& board)
    {
        for(size_t i = 0; i < tX; ++i)
        {
            for(size_t j = 0; j < tY; ++j)
            {
                board(i, j) = bp::point_state_t(0);
            }
        }
    }

    typedef game_board_impl<19, 19> game_board;

    size_t const number_of_player = 2;

    class game : public bp::game_base
    {
        bp::player_id_t
        play_next_turn(bp::player_id_t const& previous_turn)
        {
            if(previoulue == 0)
                return {1};
            else
                return {0};
        }

        std::optional<bp::player_id_t>
        check_winner(game_board const& current_board,
                     bp::point_t const& last_move)
        {
            auto const x_size = current_board.get_column_size();
            auto const y_size = current_board.get_row_size();

            auto move_pos_x = last_move.position.x;
            auto move_pos_y = last_move.position.y;
            auto move_unit = last_move.state;

            {
                auto begin =  move_pos_x < 6 ? 0 : move_pos_x - 6;
                for(auto x = begin; x < begin + 6; ++x)
                {
                    for(auto i = x; i < 6; ++i)
                    {
                        if(current_board(i, move_pos_y) != move_unit)
                            goto out1;
                    }

                    return {move_unit.value};
                }
            }
        out1:
            
            {
                auto begin =  move_pos_y < 6 ? 0 : move_pos_y - 6;
                for(auto y = begin; y < begin + 6; ++y)
                {
                    for(auto i = y; i < 6; ++i)
                    {
                        if(current_board(move_pos_x, i) != move_unit)
                            goto out2;
                    }

                    return {move_unit.value};
                }
            }
        out2:

            {
                using iter = std::pair<size_t, size_t>;

                auto begin_x =  move_pos_x < 6 ? 0 : move_pos_x - 6;
                auto begin_y =  move_pos_y < 6 ? 0 : move_pos_y - 6;
                auto begin = iter(begin_x, begin_y); 
                for(auto& i = begin; i < + 6; ++x)
                {
                    for(auto i = x; i < 6; ++i)
                    {
                        if(current_board(i, move_pos_y) != move_unit)
                            goto out3;
                    }

                    return {move_unit.value};
                }
            }
        out3:
            ;
        }
    };
}

#endif
