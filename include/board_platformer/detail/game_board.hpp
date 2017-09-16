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
        to_linear_idx(size_t x, size_t y) const noexcept;

        inline coordinate_t 
        from_linear_idx(size_t lin) const noexcept;

    public:
        inline game_board_impl();

        inline typename std::array<point_t, tX * tY>::iterator
        begin() noexcept;

        inline typename std::array<point_t, tX * tY>::iterator
        end() noexcept;

        inline typename std::array<point_t, tX * tY>::const_iterator
        begin() const noexcept;

        inline typename std::array<point_t, tX * tY>::const_iterator
        end() const noexcept;

        inline typename std::array<point_t, tX * tY>::const_iterator
        cbegin() const noexcept;

        inline typename std::array<point_t, tX * tY>::const_iterator
        cend() const noexcept;

        constexpr size_t
        size() const noexcept;

        inline point_state_t
        operator()(size_t x, size_t y) const;

        inline point_state_t&
        operator()(size_t x, size_t y);

        inline size_t
        col_size() const noexcept;

        inline size_t
        row_size() const noexcept;
    };
}

#include <board_platformer/detail/game_board.tpp>

#endif
