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
#include <utility>

#include <boost/process/system.hpp>

#include <board_platformer/game_manager.hpp>
#include <board_platformer/exceptions.hpp>

namespace board_platformer
{
    template<class GamePolicy, class UIPolicy>
    game_manager<GamePolicy, UIPolicy>::
    game_manager(size_t number_of_players,
                 game_board_t&& game_board,
                 chrono::milliseconds const& time_count)
        :_players(),
         _game_board(std::move(game_board)),
         _time_limit(time_count),
         _turn_number(0)
         
    {
        _players.reserve(number_of_players);
    }

    template<class GamePolicy, class UIPolicy>
    void
    game_manager<GamePolicy, UIPolicy>::
    game_start()
    {
        game_loop();
    }

    
    // template<class GamePolicy, class UIPolicy>
    // game_status_t
    // game_manager<GamePolicy, UIPolicy>::
    // make_game_status(player_id_t const& turn) const
    // {
    //     // return game_status_t(_game_board);
    // }

    template<class GamePolicy, class UIPolicy>
    player_id_t
    game_manager<GamePolicy, UIPolicy>::
    init_game(game_board_t const& board) const
    {
        auto first_turn_id =
            GamePolicy::initialize_round(board, _players);

        return {first_turn_id};
    }

    // template<class GamePolicy, class UIPolicy>
    // game_status_t
    // game_manager<GamePolicy, UIPolicy>::
    // play_turn(player_id_t const& current_turn)
    // {
    //     ++_turn_number;
    //     auto& current_player = *std::find_if(
    //         _players.begin(),
    //         _players.end(),
    //         [&current_turn](player const& elem){
    //             return elem.get_playerid() == current_turn;
    //         });

    //     auto [moves, move_time] =
    //         current_player.play_turn(_game_board, _time_limit);

    //     auto game_status =
    //         game_status_t(moves, current_turn,
    //                       move_time, _turn_number);

    //     return game_status;
    // }

    // template<class GamePolicy, class UIPolicy>
    // bool
    // game_manager<GamePolicy, UIPolicy>::
    // process_move(game_status_t const& player_move_data) const
    // {
        
    // }

    // template<class GamePolicy, class UIPolicy>
    // player_id_t
    // game_manager<GamePolicy, UIPolicy>::
    // get_next_turn(game_status_t const& game_stats) const
    // {
        
    // }

    template<class GamePolicy, class UIPolicy>
    std::optional<pc::child>
    game_manager<GamePolicy, UIPolicy>::
    maybe_run_process(player_process_data const& player) const 
    {
        auto process = pc::child(pc::system(path.value()));

        if(process.running())
            return process;
        else
            return {};
    }

    template<class GamePolicy, class UIPolicy>
    void
    game_manager<GamePolicy, UIPolicy>::
    add_players(std::vector<player_process_data>&& players)
    {
        for(auto& player_data : players)
        {
            if(player_data.process_path.has_value())
            {
                auto maybe_process = maybe_run_process(player_data);

                if(!maybe_process)
                    throw player_process_not_running;
                else
                    _players.emplace_back(
                        std::move(maybe_process.value()),
                        player_data.ip,
                        player_id_t(player_data.player_id),
                        player_data.port);
            } 
            else
            {
                
            }
        }
    }

    template<class GamePolicy, class UIPolicy>
    void
    game_manager<GamePolicy, UIPolicy>::
    game_loop()
    {
        using turn_info = game_status_t;

        UIPolicy::game_start();
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
