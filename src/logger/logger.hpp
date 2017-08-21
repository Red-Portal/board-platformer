
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

#ifndef _LOGGER_HPP_
#define _LOGGER_HPP_

#include <thread>
#include <mutex>
#include <chrono>
#include <fstream>
#include <iostream>
#include <experimental/filesystem>

namespace board_platformer
{
    namespace chrono = std::chrono;
    namespace fs = std::experimental::filesystem;
    using time_point = chrono::time_point<chrono::system_clock>;

    class mtx_time_point
    {
    private:
        time_point _last_input_time;
        std::mutex _mtx;

    public:
        inline mtx_time_point(time_point point) 
            :_last_input_time(point) 
        {}

        inline void
        set_last_input_time(time_point const& point) 
        {
            std::lock_guard<std::mutex> lck(_mtx);
            _last_input_time = point;
        }

        inline time_point
        get_last_input_time() 
        {
            std::lock_guard<std::mutex> lck(_mtx);
            return _last_input_time;
        }
    };

    
    class parallel_logger
    {
    private:
        chrono::duration<int> const _timeout;
        mtx_time_point _last_input_time;
        std::thread _time_monitor;

        fs::path
        format_path(fs::path const& path);

        static void
        time_check(mtx_time_point& last_input_time,
                   chrono::duration<int> const& _timeout);

        std::string
        format_time_point(time_point const& init_time) const;
        
    public:
        explicit parallel_logger(chrono::duration<int> timeout,
                                 fs::path const& log_path = u8"./");
    };
}

#endif
