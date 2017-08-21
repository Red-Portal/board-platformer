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

#ifndef _GAME_MANAGER_HPP_
#define _GAME_MANAGER_HPP_

#include <vector>

#include <board_platformer/types.hpp>
#include <board_platformer/detail/rpc.hpp>
#include <custom_settings.hpp>

#include "player.hpp"

namespace boost::process { class child; }

namespace ps = boost::process;

namespace board_platformer
{
    class game : public game::game
    {
    private:
        std::vector<player> _players;

    public:
        explicit game(size_t number_of_players);
        
        void add_players(
            std::vector<std::pair<ps::child, address_t>>&& players);
    };
}

#endif
