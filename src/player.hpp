
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
#include <chrono>
#include <memory>
#include <stdint.h>

#include <boost/process/child.hpp>
#include <board_platformer/detail/rpc_message.grpc.pb.h>
#include <grpc/grpc.h>
#include <grpc++/client_context.h>
#include <grpc++/security/credentials.h>

#include <board_platformer/filesystem.hpp>
#include <board_platformer/types.hpp>
#include <board_platformer/detail/rpc_message.pb.h>

#include "game.hpp"

namespace board_platformer
{
    namespace ps = boost::process;
    namespace chrono = std::chrono;

    using comm = board_platformer_comm;
    using proto_player_move = player_move;
    using proto_board_state = board_state;
    using duration = chrono::duration<int64_t,std::milli>;

    class player
    {
    private:
        ps::child _player_process;
        std::unique_ptr<comm::Stub> _stub;

        proto_player_move
        play_turn_impl(proto_board_state const& board) const;

        proto_board_state
        serialize_board(game::game_board const& actual_board,
                        proto_board_state&& proto_board) const;

    public:
        inline player(ps::child&& player_process,
                      adress_t const& address);

        std::pair<unit_type, point_t>
        play_turn(game::game_board const& board,
                  duration const& time_limit);
    };
}

#endif 
