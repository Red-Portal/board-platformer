#include "logger.hpp"

namespace board_platformer
{
    global_logger&
    global_logger::get()
    {
        static std::unique_ptr<global_logger> _instance = nullptr;

        if(_instance == nullptr)
            _instance = std::unique_ptr<global_logger>();

        return *_instance;
    }

    std::string
    global_logger::
    format_log(std::string const& sender,
               std::string const& message) const
    {
        std::string first =
            std::string("from ") + sender + std::string("\n");
        std::string second =
            message + std::string("\n");

        return first + second;
    }

    void
    global_logger::add_log(std::string const& sender,
                           std::string const& message)
    {
        auto const& log_line = format_log(sender, message);
    }
}
