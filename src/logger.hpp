#ifndef _LOGGER_HPP_
#define _LOGGER_HPP_

#include <board_platformer/filesystem.hpp>

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

    public:
        global_logger& get_instance();
    };
}

#endif
