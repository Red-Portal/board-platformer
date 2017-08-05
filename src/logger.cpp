#include "logger.hpp"

#include <iostream>

namespace board_platformer
{
    global_logger::
    global_logger()
        :_log_stream(),
         _logger("board_platformer_logger", "10",
                 ps::std_in < _log_stream)
    {}

    global_logger&
    global_logger::
    get_singleton()
    {
        static global_logger _instance;
        return _instance;
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
    global_logger::add_log(std::string const& sender,
                           std::string const& message)
    {
        auto const& log_line = format_log(sender, message);

        _log_stream << log_line;
    }
}
