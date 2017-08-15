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

#ifndef _GAME_HPP_
#define _GAME_HPP_

#include <array>

#include <board_platformer/detail/game_board.hpp>

namespace game
{
    namespace bp = board_platformer;

    // class game : public bp::game_base
    // {
        
    // };

    typedef game_board_impl<19, 19> game_board;
}

#endif
