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

#ifndef _BOARD_PLATFORMER_GAME_BOARD_HPP_
#define _BOARD_PLATFORMER_GAME_BOARD_HPP_

#include <vector>

#include <board_platformer/types.hpp>

namespace board_platformer
{
    class game_board_t
    {
    private:
        std::vector<point_t> _board;
        size_t const _x_dim;
        size_t const _y_dim;

        inline size_t
        to_linear_idx(size_t x, size_t y) const noexcept;

        inline coordinate_t 
        from_linear_idx(size_t lin) const noexcept;

    public:
        inline explicit
        game_board_t(size_t const x_dim, size_t const y_dim);

        inline game_board_t(game_board_t const& other);
        inline game_board_t(game_board_t&& other) noexcept;

        inline std::vector<point_t>::iterator
        begin() noexcept;

        inline std::vector<point_t>::iterator
        end() noexcept;

        inline std::vector<point_t>::const_iterator
        begin() const noexcept;

        inline std::vector<point_t>::const_iterator
        end() const noexcept;

        inline std::vector<point_t>::const_iterator
        cbegin() const noexcept;

        inline std::vector<point_t>::const_iterator
        cend() const noexcept;

        size_t
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

#include <board_platformer/game_board.ipp>

#endif
