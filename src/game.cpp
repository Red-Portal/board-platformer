// Board Platformer. A Board Game AI Developing Platform
// Copyright (C) 2017  Red-Portal
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include "game.hpp"

namespace board_platformer
{
    game::
    game(size_t number_of_players)
        :_players()
    {
        _players.reserve(number_of_players);
    }

    void
    game::
    add_players(
        std::vector<std::pair<ps::child, address_t>>&& players)
    {
        auto player_id = 0u;
        for(auto& i : players)
        {
            _players.emplace_back(std::move(i.first),
                                  i.second,
                                  player_id++);
        }
    }
}
