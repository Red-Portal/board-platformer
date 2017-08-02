#ifndef _LOGGER_HPP_
#define _LOGGER_HPP_

#include <thread>
#include <mutex>
#include <chrono>

namespace board_platformer
{
    namespace chrono = std::chrono;
    using time_point = chrono::time_point<chrono::steady_clock>;

    namespace
    {
        void time_check(time_point* last_input_time,
                        std::mutex* mtx);
    }

    class parallel_logger
    {
    private:
        parallel_logger();

        time_point _last_input_time;
        std::mutex _mtx;
        std::thread _time_monitor;

        void read_input();
        time_point get_last_input_time();
    };
}


#endif
