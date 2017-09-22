#ifndef _BOARD_PLATFORMER_SOFT_EXCEPTIONS_HPP_
#define _BOARD_PLATFORMER_SOFT_EXCEPTIONS_HPP_

#include <board_platformer/types.hpp>

namespace board_platformer
{
    class player_process_not_running
        : public std::exception
    {
    private:
        player_id_t _error_player_id;

    public:
        player_process_not_running(player_id_t const& id);

        player_id_t
        get_error_player_id() const;

        virtual const char*
        what() const throw();
    }
}
#endif
