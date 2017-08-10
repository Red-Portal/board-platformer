#ifndef _LOGGER_HPP_
#define _LOGGER_HPP_

#include <boost/process/child.hpp>
#include <boost/process/io.hpp>
#include <boost/process/search_path.hpp>
#include <board_platformer/filesystem.hpp>

#include <string>
#include <mutex>
#include <iostream>
#include <memory>

namespace board_platformer
{
    namespace ps = boost::process;

    class global_logger
    {
    private:
        ps::opstream _log_stream;
        ps::child _logger;

        std::string format_log(std::string const& sender,
                               std::string const& message) const;

        global_logger();

    public:
        static global_logger& get_singleton();

        void add_log(std::string const& sender,
                     std::string const& message);
    };
}

#endif
