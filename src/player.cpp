#include "player.hpp"

namespace board_platformer
{
    player::
    player(ps::child const& player_process)
// : _player_process(std::move(player_process))
    {
    }

    std::pair<unit_type, board_platformer::point_t>
    player::
    play_turn(game::game_board const& )
    {

        return { 0, board_platformer::point_t(0,0)}; 
    }
}
