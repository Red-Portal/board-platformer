#ifndef TTT_UI_POLICY_HPP
#define TTT_UI_POLICY_HPP

#include <board_platformer/ui_policy.hpp>

namespace bp = board_platformer;

namespace tic_tac_toe
{
    class ui_policy
        : public bp::ui_policy_base
    {
        void game_over() override;

        void after_move() override;

        void while_move() override;

        void before_move() override;

        void game_start() override;
    };
}

#endif
