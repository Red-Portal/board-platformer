#ifndef _UI_EVENT_HPP_
#define _UI_EVENT_HPP_

namespace board_platformer
{
    class ui_event
    {
    public:
        ui_event();

        virtual game_over() = 0;
        virtual after_move() = 0;
        virtual while_move() = 0;
        virtual before_move() = 0;
        virtual game_start() = 0;
    } 
}

#endif
