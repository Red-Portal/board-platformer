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

#ifndef _BOARD_PLATFORMER_PLAYER_PROCESS_DATA_HPP_
#define _BOARD_PLATFORMER_PLAYER_PROCESS_DATA_HPP_

#include <type_traits>
#include <optional>

#include <board_platformer/filesystem.hpp>
#include <board_platformer/types.hpp>

namespace board_platformer
{
    struct player_process_data
    {
        inline
        player_process_data(fs::path const& _process_path,
                            ip_address_t const& _ip,
                            network_port_t const& _port);

        inline
        player_process_data(ip_address_t const& _ip,
                            network_port_t const& _port);

        inline
        player_process_data(fs::path&& _process_path,
                            ip_address_t&& _ip,
                            network_port_t&& _port);
        inline 
        player_process_data(ip_address_t&& _ip,
                            network_port_t&& _port);

        std::optional<fs::path> process_path;
        ip_address_t ip;
        network_port_t port;
    };
}

#include <board_platformer/player_process_data.ipp>

#endif
