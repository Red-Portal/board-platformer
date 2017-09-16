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

#include <board_platformer/detail/logger.hpp>

namespace board_platformer
{
    bool
    global_logger::
    _console_out = true;

    global_logger::
    global_logger(bool use_file_log)
        :_log_stream(),
         _logger("board_platformer_logger", "10",
                 ps::std_in < _log_stream,
                 ps::std_out > _logger_status_stream)
    {
        (void)use_file_log;

        auto status = std::string();
        std::getline(_logger_status_stream, status);

        if(status != "started_log_process")
            throw; // I'll have to check this later

        add_log("global_logger",
                "initializing global_logger with file log output");
    }

    global_logger::
    global_logger()
        :_log_stream(),
         _logger()
    {}

    global_logger&
    global_logger::
    get_singl(bool use_file_log)
    {
        static std::unique_ptr<global_logger> _instance;

        if(use_file_log && _instance == nullptr)
            _instance = std::make_unique<global_logger>(true);
        else
            _instance = std::make_unique<global_logger>();

        return *_instance;
    }

    std::string
    global_logger::
    format_log(std::string const& sender,
               std::string const& message) const
    {
        std::string first =
            std::string("from ") + sender + std::string("\n");
        std::string second = message;

        return first + second;
    }

    void
    global_logger::
    set_log_options(bool cout)
    {
        global_logger::_console_out = cout;
    }

    void
    global_logger::add_log(std::string const& sender,
                           std::string const& message)
    {
        auto log = format_log(sender, message);

        auto lck = std::unique_lock<std::mutex>(_mtx);
        std::cout << log << std::endl;

        if(_console_out)
            _log_stream << log;
    }
}
