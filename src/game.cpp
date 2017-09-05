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

#include <algorithm>

#include "game.hpp"

namespace board_platformer
{
    game::
    game(size_t number_of_players, chrono::seconds const& time_count,
         std::unique_ptr<game_base>&& game_settings,
         std::unique_ptr<game_base>&& ui)
        :_players(),
         _game_settings(std::move(game_settings)),
         _ui_events(std::move(ui)),
         _game_board(),
         _time_limit(time_count),
         _turn_number(0)
         
    {
        _players.reserve(number_of_players);
    }

    void
    game::
    game_start()
    {
        game_loop();
    }

    void
    game::
    game_loop()
    {
        _ui_events->game_start();

        while(true)
        {
            _ui_events->before_move();
            
            _ui_events->while_move();

            _ui_events->after_move();
        }

        _ui_events->game_over();
    }

    void
    game::
    add_players(std::vector<player_and_address>&& players)
    {
        auto player_id = 0u;
        for(auto& i : players)
        {
            _players.emplace_back(std::move(i.first),
                                  i.second,
                                  player_id++);
        }
    }

    player_id_t
    game::
    init_game()
    {
        auto first_turn_id =
            _game_settings->initialize_round(_game_board, _players);

        return {first_turn_id};
    }

    game_status_t
    game::
    next_turn(player_id_t const& current_turn)
    {
        ++_turn_number;
        auto& current_player = *std::find_if(
            _players.begin(),
            _players.end(),
            [&current_turn](player const& elem){
                return elem.get_playerid() == current_turn;
            });

        auto [moves, move_time] =
            current_player.play_turn(_game_board, _time_limit);

        auto move_data = game_status_t(moves, current_turn,
                                       move_time, _turn_number);
        return move_data;
    }
}
