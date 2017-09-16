#include <iostream>

#include <board_platformer/game_manager.hpp>
#include <board_platformer/game_board.hpp>

#include "game_policy.hpp"
#include "ui_policy.hpp"

namespace bp = board_platformer;
namespace ttt = tic_tac_toe;

int main()
{
    typedef bp::game_board_t<3, 3> game_board;
    auto game = bp::game_manager<ttt::game_policy,
                                 ttt::ui_policy,
                                 game_board>();
}
