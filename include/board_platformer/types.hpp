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

#include <board_plartformer/detail/strong_type.hpp>

namespace board_platformer
{
    STRONG_TYPE(uint16_t, unit_type) point_state_t;
    STRONG_TYPE(uint32_t, player_id_type) player_id_t;
    STRONG_TYPE(int64_t, player_score_type) player_score_t;

    class coordinate_t
    {
    private:
        size_t x;
        size_t y;

    public:
        template<typename T,
                 typename = typename
                 std::enable_if<std::is_integral<T>::value, T>::type>
        inline coordinate_t(T _x, T _y)
            : x(_x), y(_y)
        {}

        inline coordinate_t() = default;
        inline coordinate_t(coordinate_t const& other) = default;
        inline coordinate_t(coordinate_t&& other) noexcept = default;

        inline coordinate_t&
        operator=(coordinate_t const& other) = default;
        inline coordinate_t&
        operator=(coordinate_t&& other) noexcept = default;

        size_t get_x() const noexcept
        { return x; }
        size_t get_y() const noexcept
        { return y; }
    };

    class point_t
    {
    private:
        coordinate_t _position;

    public:
        inline point_t() = default;

        inline point_t(coordinate_t const& pt,
                       point_state_t const& _state)
            :_position(pt), state(_state) {}

        template<typename T,
                 typename = typename
                 std::enable_if<std::is_integral<T>::value, T>::type>
        inline point_t(T x, T y,
                       point_state_t const& _state)
            :_position(x, y), state(_state) {}

        inline point_t(point_t const& other) = default;
        inline point_t(point_t&& other) noexcept = default;
        
        inline point_t&
        operator=(point_t const& other) = default;
        inline point_t&
        operator=(point_t&& other) noexcept = default;

        inline coordinate_t const&
        get_position() const noexcept
        { return _position; }

        point_state_t state;
    };
}

#endif 
