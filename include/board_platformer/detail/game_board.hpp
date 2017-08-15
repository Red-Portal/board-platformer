///////////////////////////////////////////////////////////////////////////////
// Board Platformer. A Board Game AI Developing Platform                     //
// Copyright (C) 2017  Red-Portal                                            //
//                                                                           //
//     This program is free software: you can redistribute it and/or modify  //
//     it under the terms of the GNU General Public License as published by  //
//     the Free Software Foundation, either version 3 of the License, or     //
//     (at your option) any later version.                                   //
//                                                                           //
//     This program is distributed in the hope that it will be useful,       //
//     but WITHOUT ANY WARRANTY; without even the implied warranty of        //
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         //
//     GNU General Public License for more details.                          //
//                                                                           //
//     You should have received a copy of the GNU General Public License     //
//     along with this program.  If not, see <http://www.gnu.org/licenses/>. //
///////////////////////////////////////////////////////////////////////////////


#ifndef _GAME_BOARD_HPP_
#define _GAME_BOARD_HPP_

#include <array>

#include <board_platformer/types.hpp>

namespace game
{
    namespace bp = board_platformer;

    template<size_t tX, size_t tY>
    class game_board_impl
    {
    private:
        std::array<bp::point_state, tX * tY> _board;

    public:
        typename std::array<bp::point_state, tX * tY>::iterator
        begin() noexcept
        { return _board.begin(); }

        typename std::array<bp::point_state, tX * tY>::iterator
        end() noexcept
        { return _board.begin(); }

        typename std::array<bp::point_state, tX * tY>::const_iterator
        begin() const noexcept
        { return _board.begin(); }

        typename std::array<bp::point_state, tX * tY>::const_iterator
        end() const noexcept
        { return _board.begin(); }

        typename std::array<bp::point_state, tX * tY>::const_iterator
        cbegin() noexcept
        { return _board.cbegin(); }

        typename std::array<bp::point_state, tX * tY>::const_iterator
        cend() noexcept
        { return _board.cbegin(); }

        constexpr size_t
        size() const noexcept
        { return _board.size(); }

        bp::point_state
        operator()(size_t x, size_t y) const
        {
            return _board[tX * x + y];
        }

        bp::point_state&
        operator()(size_t x, size_t y)
        {
            return _board[tX * x + y];
        }
    };
}

#endif
