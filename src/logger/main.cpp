
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

#include <chrono>
#include <iostream>
#include <string>

#include "logger.hpp"

namespace bp = board_platformer;
namespace chrono = std::chrono;

int main(int argc, char** argv)
{
    std::cout << "started log process\n";

    int timeout = 10;

    auto path = std::string();
    for(auto i = 1; i < argc; ++i)
    {
        if(argv[i][0] == '-')
        {
            path = argv[i];
            path.erase(0, 1);
        }
        else
            timeout = std::stoi(argv[1]);
    }

    if(path.empty())
    {
        auto logger =
            bp::parallel_logger{chrono::duration<int>(timeout)};
    }
    else
    {
        auto logger =
            bp::parallel_logger{chrono::duration<int>(timeout), path};
    }
    
    return 0;
}
    
