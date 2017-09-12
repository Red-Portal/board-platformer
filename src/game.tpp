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
#include <atomic>

#include "game.hpp"

namespace board_platformer
{
    game::
    game(size_t number_of_players,
         chrono::milliseconds const& time_count,
         std::vector<player_and_address>&& players)
        :_players(),
         _game_board(),
         _time_limit(time_count),
         _turn_number(0)
         
    {
        _players.reserve(number_of_players);

        auto player_id = 0u;
        for(auto& i : players)
        {
            _players.emplace_back(std::move(i.first),
                                  std::move(i.second),
                                  player_id++);
        }
    }

    void
    game::
    game_start()
    {
        game_loop();
    }

    
    game::
    make_game_status(player_id_t const& turn) const
    {
        return game_status_t(_game_board,);
    }

    player_id_t
    game::
    init_game(::game::game_board const& board) const
    {
        auto first_turn_id = GamePolicy::initialize_round(board, _players);

        return {first_turn_id};
    }

    player_id_t
    game::
    play_turn(player_id_t const& current_turn)
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

        auto game_status =
            game_status_t(moves, current_turn,
                          move_time, turn_number);

        return game_status;
    }

    bool
    process_move(game_status_t const& player_move_data) const
    {
        
    }

    player_id_t
    game::
    get_next_turn(game_status_t const& game_stats) const
    {
        
    }

    void
    game::
    game_loop()
    {
        using turn_info = game_status_t;

        _ui_events->game_start();
        auto turn = init_game(_game_board);

        auto flag = bool(true);
        
        do
        {
            //turn info
            auto turn_info = make_turn_info(turn, _time_limit) ;
            UIPolicy::before_move(turn_info);

            auto atomic_flag = std::atomic<bool>();
            UIPolicy::while_move(atomic_flag); 
            auto move_data = play_turn(turn);
            
            UIPolicy::after_move();
            flag = process_move(move_data);

        } while(flag);

        UIPolicy::game_over();
    }
}
