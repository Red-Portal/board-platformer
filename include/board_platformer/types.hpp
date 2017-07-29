#ifndef _TYPES_HPP_
#define _TYPES_HPP_

#include <stdint.h>

#include "detail/strong_type.hpp"

namespace board_platformer
{
    typedef strong_type<uint32_t> unit_type;

    struct point_t
    {
        point_t(int _x, int _y)
            : x(_x), y(_y)
        {}

        int x;
        int y;
    };

    struct point_state
    {
        point_state(point_t _pt, unit_type const& _state)
            :point(_pt), state(_state)
        {}

        point_state(int x, int y, unit_type const& _state)
            :point(x, y), state(_state)
        {}
        
        point_t point;
        unit_type state;
    };
}

#endif 
