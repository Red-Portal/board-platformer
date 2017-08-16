#include "game.hpp"

namespace board_platformer
{
    game::
    game(std::vector<std::pair<ps::child, address_t>>&& players)
        :_players()
    {
        _players.reserve(players.size());

        auto player_id = 0u;
        for(auto& i : players)
        {
            _players.emplace_back(std::move(i.first),
                                  i.second,
                                  player_id++);
        }
    }
}
