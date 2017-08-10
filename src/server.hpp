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

// #ifndef _PROCESS_COMM_HPP_
// #define _PROCESS_COMM_HPP_

// #include <string>
// #include <memory>

// #include <grpc++/grpc++.h>
// #include <grpc++/channel.h>
// #include <grpc++/client_context.h>
// #include <grpc++/create_channel.h>
// #include <grpc++/security/credentials.h>
// #include <board_platformer/detail/rpc_message.grpc.pb.h>
// #include <board_platformer/detail/rpc_message.pb.h>
// #include <boost/process/child.hpp>

// #include <board_platformer/detail/rpc.hpp>

// #include "game.hpp"

// namespace board_platformer
// {
//     namespace ps = boost::process;

//     class server_communicator
//     {
//     private:
//         ps::child _client;

//     public:
//         server_communicator(process_id const& id);

//         std::vector<point_state_t>
//         play_turn(process_id const& id,
//                   game::game_board const& current_board);
//     };
// }

// #endif
