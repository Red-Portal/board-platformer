
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


    namespace{
        namespace strong_type_types{
            enum class ip_address { null };
        }
    }
    typedef strong_type<std::string,
                        strong_type_types::ip_address> adress_t;

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
