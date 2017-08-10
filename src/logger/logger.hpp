
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
    using time_point = chrono::time_point<chrono::steady_clock>;

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

    namespace
    {
        inline void
        time_check(mtx_time_point& last_input_time)
        {
            while(true)
            {
                std::this_thread::sleep_for(chrono::seconds(1));

                auto current_time_point = chrono::steady_clock::now();

                auto duration = current_time_point
                    - last_input_time.get_last_input_time();

                if(duration > chrono::seconds(5))
                    exit(1);
            }
        }
    }
    
    class parallel_logger
    {
    private:
        chrono::duration<int> _timeout;
        mtx_time_point _last_input_time;
        std::thread _time_monitor;

        inline void write_stream(std::fstream& log_path,
                                 std::string const& message);

        inline void write_stream(std::string const& message);
    public:
        explicit parallel_logger(chrono::duration<int> timeout);

        explicit parallel_logger(fs::path const& log_path,
                                 chrono::duration<int> timeout);

    };

    inline void
    parallel_logger::
    write_stream(std::fstream& fout,
                 std::string const& message)
    {
        std::cout << message << std::endl;
        fout << message << std::endl;
    }

    inline void
    parallel_logger::
    write_stream(std::string const& message)
    {
        std::cout << message << std::endl;
    }
}
#endif
