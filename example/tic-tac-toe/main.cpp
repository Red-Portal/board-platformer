#include <iostream>
#include <chrono>

#include <board_platformer/game_manager.hpp>
#include <board_platformer/game_board.hpp>

#include "game_policy.hpp"
#include "ui_policy.hpp"

namespace bp = board_platformer;
namespace ttt = tic_tac_toe;

int main()
{
    auto game_board = bp::game_board_t(3, 3);

    size_t player_number = 2;

    auto game = bp::game_manager<ttt::game_policy,
                                 ttt::ui_policy>
        (player_number,
         std::move(game_board),
         std::chrono::seconds(2),
         std::vector<bp::player_process_data>());
}
