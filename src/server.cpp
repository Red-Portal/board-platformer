
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

#include "server.hpp"

namespace board_platformer
{
    grpc::Status
    server::grpc_service::
    send_board_state(grpc::ServerContext* context,
                     board_state const* state,
                     player_move* move) 
    {
        
    }

    server::
    server(std::string const& net_address)
    {
        grpc_service service;
        grpc::ServerBuilder builder;

        builder.AddListeningPort(
            net_address,
            grpc::InsecureServerCredentials());

        builder.RegisterService(&service);

        _server_instance = 
            std::unique_ptr<grpc::Server>(builder.BuildAndStart());
    }

    void
    server::
    run_server()
    {
        
    }

    std::vector<point_state_t>
    server::
    play_turn(process_id const& id,
              game::game_board const& current_board)
    {
        
    }
}
