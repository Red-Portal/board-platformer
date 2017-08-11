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

#include <grpc++/create_channel.h>

#include "player.hpp"

namespace board_platformer
{
    player::
    player(ps::child&& player_process, adress_t const& address)
        : _player_process(std::move(player_process)),
          _stub(
              comm::NewStub(
                  grpc::CreateChannel(
                      address.value,
                      grpc::InsecureChannelCredentials())))
    {}

    proto_player_move
    player::
    play_turn_impl(proto_board_state const& board) const
    {
        auto context = grpc::ClientContext();
        auto move = proto_player_move();
        _stub->send_board_state(&context, board, &move);

        return move;
    }

    proto_board_state
    player::
    serialize_board(game::game_board const& actual_board,
                    proto_board_state&& proto_board) const
    {
        auto size = actual_board.size();
        for(auto& i : actual_board)
        {
            proto_board.add_point_state();

            auto* pt_state = proto_board.mutable_point_state(i);
            pt_state = set_unit_type(i.state);

            auto* pt = pt_state.mutable_point();
            pt->set_x(i.x);
            pt->set_y(i.y);
        }

        return proto_board; 
    }

    std::pair<unit_type, board_platformer::point_t>
    player::
    play_turn(game::game_board const& board,
              duration const& time_limit)
    {
        auto proto_board_blank = proto_board_state();

        auto proto_board =
            serialize_board(board, std::move(proto_board_blank));
        proto_board.set_time_limit(time_limit.count());

        auto player_move = play_turn_impl(proto_board);

        // add deserializing procedure
        // add rpc call time measuring procedure

        return { 0, board_platformer::point_t(0,0)}; 
    }
}
