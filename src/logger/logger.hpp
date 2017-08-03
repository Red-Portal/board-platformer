#ifndef _LOGGER_HPP_
#define _LOGGER_HPP_

#include <thread>
#include <mutex>
#include <chrono>

namespace board_platformer
{
    namespace chrono = std::chrono;
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
        void time_check(mtx_time_point* last_input_time);
    }
    

    class parallel_logger
    {
    private:
        chrono::duration<int> _timeout;
        std::thread _time_monitor;
        mtx_time_point _last_input_time;

        void read_input();
        time_point get_last_input_time();

    public:
        explicit parallel_logger(chrono::duration<int> timeout);

    };
}
#endif
