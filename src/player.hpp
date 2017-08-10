
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

#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include <utility>

#include <boost/process/child.hpp>

#include <board_platformer/filesystem.hpp>
#include <board_platformer/types.hpp>
#include <board_platformer/detail/rpc_message.pb.h>

#include "game.hpp"

namespace board_platformer
{
    namespace ps = boost::process;

    class player
    {
    private:
        ps::child _player_process;

    public:
        player(ps::child const& player_process);

        std::pair<unit_type, board_platformer::point_t>
        play_turn(game::game_board const&);
    };
}

#endif 
