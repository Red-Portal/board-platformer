#include <board_platformer/exceptions.hpp>

#include <string>

namespace board_platformer
{
    player_process_not_running::
    player_process_not_running(player_id_t const& id)
        : _error_player_id(id)
    {}

    player_id_t
    player_process_not_running::
    get_error_player_id() const
    {
        return _error_player_id;
    }

    virtual const char*
    what() const throw()
    {
        return std::string(
            std::string("process of ") + _error_player_id +
            std::string(" is not running")).c_str();
    }
}
