#ifndef TTT_GAME_POLICY_HPP
#define TTT_GAME_POLICY_HPP

#include <optional>

#include <board_platformer/game_policy.hpp>
#include <board_platformer/game_board.hpp>
#include <board_platformer/types.hpp>
#include <board_platformer/messages.hpp>

namespace tic_tac_toe
{
    namespace bp = board_platformer;

    class game_policy
        : public bp::game_policy_base
    {
        bp::player_id_t 
        initialize_round(bp::game_board_t& board) override
        {
            
        }

        bp::player_id_t
        get_next_turn_id(
            bp::game_status_t const& game_state) const override
        {
            
        }

        std::optional<bp::player_id_t>
        check_winner(
            bp::game_status_t const& game_state) const override
        {
            
        }

        std::optional<std::string>
        is_invalid_move(
            bp::game_status_t const& game_state) const override
        {
            
        }
    };
}

#endif
