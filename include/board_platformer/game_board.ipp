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


namespace board_platformer
{
    game_board_t::
    game_board_t(size_t const x_dim, size_t const y_dim)
        : _board(), _x_dim(x_dim), _y_dim(y_dim)
    {
        _board.reserve(_x_dim * _y_dim);

        for(auto i = 0u; i < _x_dim * _y_dim; ++i)
        {
            auto coord = from_linear_idx(i);
            _board.emplace_back(coord, point_state_t(0));
        }
    }

    size_t
    game_board_t::
    to_linear_idx(size_t x, size_t y) const noexcept
    { return _x_dim * y + x; }

    coordinate_t 
    game_board_t::
    from_linear_idx(size_t lin) const noexcept
    {
        auto x = lin % _x_dim;
        auto y = lin / _x_dim;
        return {x, y};
    }

    std::vector<point_t>::iterator
    game_board_t::
    begin() noexcept
    { return _board.begin(); }

    std::vector<point_t>::iterator
    game_board_t::
    end() noexcept
    { return _board.end(); }

    std::vector<point_t>::const_iterator
    game_board_t::
    begin() const noexcept 
    { return _board.begin(); }

    std::vector<point_t>::const_iterator
    game_board_t::
    end() const  noexcept 
    { return _board.begin(); }

    std::vector<point_t>::const_iterator
    game_board_t::
    cbegin() const  noexcept 
    { return _board.cbegin(); }

    std::vector<point_t>::const_iterator
    game_board_t::
    cend() const   noexcept 
    { return _board.cbegin(); }

    size_t
    game_board_t::
    size() const noexcept 
    { return _board.size(); }

    point_state_t
    game_board_t::
    operator()(size_t x, size_t y) const
    { return _board[to_linear_idx(x, y)].state; }

    point_state_t&
    game_board_t::
    operator()(size_t x, size_t y)
    { return _board[to_linear_idx(x, y)].state; }

    size_t
    game_board_t::
    col_size() const noexcept
    { return _x_dim; }

    size_t
    game_board_t::
    row_size() const noexcept
    { return _y_dim; }
}
