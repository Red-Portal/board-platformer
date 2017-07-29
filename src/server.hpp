#ifndef _PROCESS_COMM_HPP_
#define _PROCESS_COMM_HPP_

#include <string>
#include <memory>

#include <grpc++/grpc++.h>
#include <board_platformer/detail/rpc_message.grpc.pb.h>
#include <board_platformer/detail/rpc_message.pb.h>

#include <board_platformer/detail/rpc.hpp>

namespace board_platformer
{
    class server
    {
    private:
        class grpc_service final
            : public board_platformer_comm::Service
        {
        private:
            grpc::Status
            send_board_state(grpc::ServerContext* context,
                             board_state const* state,
                             player_move* move) override;

        };

        std::unique_ptr<grpc::Server> _server_instance;
        
    public:
        server() = default;
        server(server&& other) = default;
        server& operator=(server&& other) = default;

        server(std::string net_address);

        void run_server();

        std::vector<point_state>
        play_turn(process_id const& id,
                  game::game_board const& current_board);
    }
}

#endif
