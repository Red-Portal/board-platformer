#include "player.hpp"

namespace board_platformer
{
    player::
    player(ps::child const& player_process)
        : _player_process(std::move(player_process))
    {
        
    }

    std::pair<unit_type, board_platformer::point>
    player::
    play_turn(game::game_board const& )
    {
        send_board_state();

        return { 0, board_platformer::point(0,0)}; 
    }
}
