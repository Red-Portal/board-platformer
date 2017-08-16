#ifndef _GAME_MANAGER_HPP_
#define _GAME_MANAGER_HPP_

#include <vector>

#include <board_platformer/types.hpp>
#include <board_platformer/detail/rpc.hpp>

#include "player.hpp"

namespace boost::process { class child; }

namespace ps = boost::process;

namespace board_platformer
{
    class game
    {
    private:
        std::vector<player> _players;

    public:
        explicit game(
            std::vector<std::pair<ps::child, address_t>>&& players);
    };
}

#endif
