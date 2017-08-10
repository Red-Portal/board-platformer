
///////////////////////////////////////////////////////////////////////////////
// Board Platformer. A Board Game AI Developing Platform                     //
// Copyright (C) 2017  Red-Portal                                            //
//                                                                           //
//     This program is free software: you can redistribute it and/or modify  //
//     it under the terms of the GNU General Public License as published by  //
//     the Free Software Foundation, either version 3 of the License, or     //
//     (at your option) any later version.                                   //
//                                                                           //
//     This program is distributed in the hope that it will be useful,       //
//     but WITHOUT ANY WARRANTY; without even the implied warranty of        //
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         //
//     GNU General Public License for more details.                          //
//                                                                           //
//     You should have received a copy of the GNU General Public License     //
//     along with this program.  If not, see <http://www.gnu.org/licenses/>. //
///////////////////////////////////////////////////////////////////////////////

#include <string>
#include <iostream>

#include "logger.hpp"

namespace board_platformer
{

    parallel_logger::
    parallel_logger(fs::path const& log_path,
                    chrono::duration<int> timeout)
        :_timeout(timeout),
         _last_input_time(chrono::steady_clock::now()),
         _time_monitor(board_platformer::time_check,
                       std::ref(_last_input_time))
    {        
        std::fstream fout;
        
        while(true)
        {
            std::string input;
            std::getline(std::cin, input);

            _last_input_time.set_last_input_time(
                chrono::steady_clock::now());

            write_stream(fout, input);
        }
    }
         
    parallel_logger::
    parallel_logger(chrono::duration<int> timeout)
        :_timeout(timeout),
         _last_input_time(chrono::steady_clock::now()),
         _time_monitor(board_platformer::time_check,
                       std::ref(_last_input_time))
    {        
        while(true)
        {
            std::string input;
            std::getline(std::cin, input);

            _last_input_time.set_last_input_time(
                chrono::steady_clock::now());
            write_stream(input);
        }
    }
}
