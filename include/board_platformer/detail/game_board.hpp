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

#ifndef _GAME_BOARD_HPP_
#define _GAME_BOARD_HPP_

#include <array>

#include <board_platformer/types.hpp>

namespace board_platformer
{
    template<size_t tX, size_t tY>
    class game_board_impl
    {
    private:
        std::array<point_t, tX * tY> _board;

        inline size_t
        to_linear_idx(size_t x, size_t y) const noexcept
        { return tX * y + x; }

        inline coordinate_t 
        from_linear_idx(size_t lin) const noexcept
        {
            auto x = lin % tX;
            auto y = lin / tX;
            return {x, y};
        }

    public:
        game_board_impl()
            :_board()
        {
            for(auto i = 0u; i < tX * tY; ++i)
            {
                auto coord = from_linear_idx(i);
                _board[i] = point_t(coord, point_state_t(0));
            }
        } 

        typename std::array<point_t, tX * tY>::iterator
        begin() noexcept
        { return _board.begin(); }

        typename std::array<point_t, tX * tY>::iterator
        end() noexcept
        { return _board.begin(); }

        typename std::array<point_t, tX * tY>::const_iterator
        begin() const noexcept
        { return _board.begin(); }

        typename std::array<point_t, tX * tY>::const_iterator
        end() const noexcept
        { return _board.begin(); }

        typename std::array<point_t, tX * tY>::const_iterator
        cbegin() noexcept
        { return _board.cbegin(); }

        typename std::array<point_t, tX * tY>::const_iterator
        cend() noexcept
        { return _board.cbegin(); }

        constexpr size_t
        size() const noexcept
        { return _board.size(); }

        inline point_state_t
        operator()(size_t x, size_t y) const
        {
            return _board[to_linear_idx(x, y)].state;
        }

        inline point_state_t&
        operator()(size_t x, size_t y)
        {
            return _board[to_linear_idx(x, y)].state;
        }

        inline size_t
        col_size() const
        { return tX; }

        inline size_t
        row_size() const
        { return tY; }
    };
}

#endif
