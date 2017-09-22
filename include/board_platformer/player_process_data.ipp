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

#include <board_platformer/player_process_data.hpp>

namespace board_platformer
{
    player_process_data::
    player_process_data(fs::path const& _process_path,
                        ip_address_t const& _ip,
                        network_port_t const& _port)
        : process_path(_process_path),
          ip(_ip),
          port(_port) {}

    player_process_data::
    player_process_data(ip_address_t const& _ip,
                        network_port_t const& _port)
        : process_path({}),
          ip(_ip),
          port(_port) {}

    player_process_data::
    player_process_data(fs::path&& _process_path,
                        ip_address_t&& _ip,
                        network_port_t&& _port)
        : process_path(std::move(_process_path)),
          ip(std::move(_ip)),
          port(std::move(_port)) {}

    player_process_data::
    player_process_data(ip_address_t&& _ip,
                        network_port_t&& _port)
        : process_path({}),
          ip(std::move(_ip)),
          port(std::move(_port)) {}

}
