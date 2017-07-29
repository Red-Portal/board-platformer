#ifndef _LOGGER_HPP_
#define _LOGGER_HPP_

#include <board_platformer/filesystem.hpp>

#include <string>
#include <mutex>
#include <memory>

namespace board_platformer
{
    namespace
    {
        const fs::path _log_path = "./log/"; 
    }

    class global_logger
    {
    private:
        std::mutex mtx;

        global_logger() = default;
        std::string format_log(std::string const& sender,
                               std::string const& message) const;

    public:
        global_logger& get();

        void add_log(std::string const& sender,
                     std::string const& message);
    };
}

#endif
