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

#include <string>

#include <grpc++/create_channel.h>
#include <grpc++/client_context.h>
#include <grpc++/security/credentials.h>

#include <board_platformer/detail/rpc_message.pb.h>
#include <board_platformer/detail/player.hpp>
#include <board_platformer/detail/logger.hpp>

namespace board_platformer
{
    player::
    player(ps::child&& player_process,
           ip_address_t const& address,
           player_id_t const& player_id,
           network_port_t const& net_port)
        : _player_process(std::move(player_process)),
          _player_id(player_id),
          _net_port(net_port),
          _stub(comm::NewStub(
                    grpc::CreateChannel(
                        address.value,
                        grpc::InsecureChannelCredentials())))
    {}

    proto_player_move
    player::
    send_message(proto_board_state const& board) const
    {
        auto context = grpc::ClientContext();
        auto move = proto_player_move();
        _stub->send_board_state(&context, board, &move);

        return move;
    }

    proto_board_state
    player::
    serialize_board(game_board_t const& actual_board,
                    proto_board_state&& proto_board) const
    {
        size_t index = 0;
        for(auto const& i : actual_board)
        {
            ++index;
            proto_board.add_point_state();

            auto* pt_state = proto_board.mutable_point_state(index);
            pt_state->set_unit_type(i.state.value);
            auto* pt = pt_state->mutable_point();

            auto const& coord = i.get_position();
            pt->set_x(coord.get_x());
            pt->set_y(coord.get_y());
        }
        return proto_board; 
    }

    std::vector<point_t>
    player::
    deserialize_moves(proto_player_move const& moves) const
    {
        size_t size = moves.move_size();
        std::vector<point_t> deserialized_moves;

        for(auto i = 0u; i < size; ++i)
        {
            auto proto_move = moves.move(i);
            auto proto_point = proto_move.point();
            auto unit_type = proto_move.unit_type();

            auto move = point_t(proto_point.x(),
                                proto_point.y(),
                                unit_type);

            deserialized_moves.push_back(std::move(move));
        }

        return deserialized_moves;
    }

    std::tuple<std::vector<point_t>, duration_t>
    player::
    play_turn(game_board_t const& board,
              duration_t const& time_limit)
    {
        auto proto_board_blank = proto_board_state();
        auto proto_board =
            serialize_board(board, std::move(proto_board_blank));
        auto time_limit_s =
            chrono::duration_cast<chrono::seconds>(time_limit);

        proto_board.set_time_limit(time_limit_s.count());

        global_logger::get_singl()
            .add_log("player " + _player_id.value,
                     "waiting for player move..");

        auto start = clock::now();
        auto player_move = send_message(proto_board);
        auto end = clock::now();

        global_logger::get_singl()
            .add_log("player " + _player_id.value,
                     "received player move");

        auto moves = deserialize_moves(std::move(player_move));
        auto duration = end - start;
        auto dur =
            chrono::duration_cast<chrono::milliseconds>(duration);

        return {moves, dur}; 
    }

    player_id_t const&
    player::
    get_playerid() const noexcept
    {
        return _player_id;
    }
}
