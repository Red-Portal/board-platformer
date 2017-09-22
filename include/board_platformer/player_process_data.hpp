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
#include <string>
#include <optional>

#include <board_platformer/filesystem.hpp>
#include <board_platformer/types.hpp>

namespace board_platformer
{
    struct player_process_data
    {
        
        template<typename Path,
                 typename String,
                 typename IpAddress,
                 typename NetworkPort,
                 typename = std::enable_if<
                     std::is_same<
                         fs::path,
                         std::remove_reference<Path>>::value &&
                     std::is_same<
                         std::string,
                         std::remove_reference<String>>::value &&
                     std::is_same<
                         ip_address_t,
                         std::remove_reference<IpAddress>>::value &&
                     std::is_same<
                         network_port_t,
                         std::remove_reference<NetworkPort>>::value
                     >::type>
        inline
        player_process_data(Path const& _process_path,
                            String _player_id,
                            IpAddress const& _ip,
                            NetworkPort const& _port);

        template<typename String,
                 typename IpAddress,
                 typename NetworkPort,
                 typename = std::enable_if<
                     std::is_same<
                         std::string,
                         std::remove_reference<String>>::value &&
                     std::is_same<
                         ip_address_t,
                         std::remove_reference<IpAddress>>::value &&
                     std::is_same<
                         network_port_t,
                         std::remove_reference<NetworkPort>>::value
                     >::type>
        inline
        player_process_data(String _player_id,
                            IpAddress const& _ip,
                            NetworkPort const& _port);

        std::optional<fs::path> process_path;
        std::string player_id;
        ip_address_t ip;
        network_port_t port;
    };
}

#include <board_platformer/player_process_data.tpp>

#endif
