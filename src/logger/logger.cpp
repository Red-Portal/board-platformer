#include "logger.hpp"

namespace board_platformer
{
    void
    time_check(time_point* last_input_time, std::mutex* mtx)
    {
        while(true)
        {
            std::this_thread::sleep_for(chrono::seconds(1));

            auto current_time_point = chrono::steady_clock::now();

            mtx->lock();
            auto duration = current_time_point - *last_input_time;
            mtx->unlock();

            if(duration > chrono::hours(1))
                exit(1);
        }
    }

    parallel_logger::
    parallel_logger()
        :_last_input_time(chrono::steady_clock::now()),
         _time_monitor(std::thread(&_last_input_time, &_mtx))
    {
        
    }

}
