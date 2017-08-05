#ifndef _TYPES_HPP_
#define _TYPES_HPP_

#include <stdint.h>

#include "detail/strong_type.hpp"

namespace board_platformer
{
    namespace{
        namespace strong_type_types{
            enum class unit_type { null };
        }
    }
    typedef strong_type<uint16_t, strong_type_types::unit_type> unit_type;

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
