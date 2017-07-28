#include "player.hpp"

namespace board_platformer
{
    player::
    player()
    {

    }

    std::pair<unit_type, board_platformer::point>
    player::
    play_turn(game::game_board const& )
    {
        return { 0, board_platformer::point(0,0)}; 
    }
}
