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