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

#include <string>
#include <iostream>
#include <iomanip>
#include <ctime>

#include "logger.hpp"

namespace board_platformer
{
    using clock = std::chrono::system_clock;

    void
    parallel_logger::
    time_check(mtx_time_point& last_input_time,
               chrono::duration<int> const& _timeout)
    {
        while(true)
        {
            auto last_time = last_input_time.get_last_input_time();
            auto current_time_point = clock::now();
            std::this_thread::sleep_for(
                (last_time + _timeout) - current_time_point);

            if(last_time == last_input_time.get_last_input_time())
                exit(1);
        }
    }

    std::string
    parallel_logger::
    format_time_point(time_point const& init_time) const
    {
        char buffer[26];
        auto ctype_init_time = clock::to_time_t(init_time);
        struct tm* init_time_info = localtime(&ctype_init_time);
        strftime(buffer, 26, "%Y-%m-%d_%H:%M:%S", init_time_info); 

        return std::string(buffer);
    }

    fs::path
    parallel_logger::
    format_path(fs::path const& path)
    {
        auto end_letter = path.u8string().back();
        auto path_str = path.u8string();

        if( end_letter == '\\' || end_letter == '/')
            path_str.pop_back();
        return fs::path(path_str);
    }

    parallel_logger::
    parallel_logger(chrono::duration<int> timeout,
                    fs::path const& log_path)
        :_timeout(timeout),
         _last_input_time(chrono::system_clock::now()),
         _time_monitor(board_platformer::parallel_logger::time_check,
                       std::ref(_last_input_time),
                       std::ref(_timeout))
    {
        std::fstream fout;

        auto init_time = format_time_point(clock::now());

        auto path = format_path(log_path);

        auto formatted_path = path.u8string() + '/' + init_time;
        fs::create_directory(formatted_path);

        fout.open(formatted_path
                  + '/'
                  + init_time,
                  std::fstream::out);

        fout << "started log process at " << init_time << '\n'
             << "------------------------------------------\n"
             << std::endl;
        
        while(true)
        {
            std::string input;
            std::getline(std::cin, input);

            auto time_p = clock::now();
            _last_input_time.set_last_input_time(time_p);

            auto time_info = format_time_point(time_p);

            fout << time_info << "\n"
                 << input << std::endl;
        }
    }
}
