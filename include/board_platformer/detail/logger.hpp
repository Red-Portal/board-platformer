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

#include <boost/process/child.hpp>
#include <boost/process/io.hpp>
#include <boost/process/search_path.hpp>
#include <board_platformer/filesystem.hpp>

#include <string>
#include <mutex>
#include <thread>
#include <queue>
#include <iostream>
#include <memory>

namespace board_platformer
{
    namespace ps = boost::process;

    class global_logger
    {
    private:
        ps::opstream _log_stream;
        ps::ipstream _logger_status_stream;
        ps::child _logger;
        std::mutex _mtx;

        static bool _console_out;

        std::string format_log(std::string const& sender,
                               std::string const& message) const;

    public:
        global_logger();
        
        // using this overload
        // means using file log stream
        global_logger(bool use_file_log);

        static global_logger& get_singl(bool use_file_log = false);

        static void set_log_options(bool cout);

        void add_log(std::string const& sender,
                     std::string const& message);
    };
}

#endif
