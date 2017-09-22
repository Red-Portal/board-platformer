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
    template<typename Path,
             typename String,
             typename IpAddress,
             typename NetworkPort, typename> 
    player_process_data::
    player_process_data(ProcessPath&& _process_path,
                        PlayerId&& _player_id,
                        IpAddress&& _ip,
                        NetworkPort&& _port)
        : process_path(std::forward<Path>(_process_path)),
          player_id(std::forward<String>(_player_id))
          ip(std::forward<IpAddress>(_ip)),
          port(std::forward<NetworkPort>(_port)) {}

    template<typename String,
             typename IpAddress,
             typename NetworkPort, typename>
    player_process_data::
    player_process_data(String&& _player_id,
                        IpAddress&& _ip,
                        NetworkPort&& _port)
        : process_path({}),
          player_id(std::forward<String>(_player_id)),
          ip(std::forward<IpAddress>(_ip)),
          port(std::forward<NetworkPort>(_port)) {}
}
