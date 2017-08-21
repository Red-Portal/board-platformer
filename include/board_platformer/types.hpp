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


#ifndef _TYPES_HPP_
#define _TYPES_HPP_

#include <stdint.h>

#include "detail/strong_type.hpp"

namespace board_platformer
{
    STRONG_TYPE(uint16_t, unit_type) point_state_t;
    STRONG_TYPE(uint32_t, player_id_type) player_id_t;

    struct coordinate_t
    {
        inline coordinate_t(int _x, int _y)
            : x(_x), y(_y)
        {}

        size_t const x;
        size_t const y;
    };

    struct point_t
    {
        inline point_t(coordinate_t const& _pt,
                       point_state_t const& _state)
            :position(_pt), state(_state)
        {}

        inline point_t(int x, int y,
                       point_state_t const& _state)
            :position(x, y), state(_state)
        {}

        coordinate_t const position;
        point_state_t state;
    };
}

#endif 
