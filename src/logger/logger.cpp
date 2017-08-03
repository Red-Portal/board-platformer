#include <string>
#include <iostream>

#include "logger.hpp"

namespace board_platformer
{
    void
    time_check(mtx_time_point& last_input_time)
    {
        while(true)
        {
            std::this_thread::sleep_for(chrono::seconds(1));

            auto current_time_point = chrono::steady_clock::now();

            auto duration = current_time_point
                - last_input_time.get_last_input_time();

            if(duration > chrono::seconds(5))
                exit(1);
        }
    }

    parallel_logger::
    parallel_logger(chrono::duration<int> timeout)
        :_timeout(timeout),
         _last_input_time(chrono::steady_clock::now()),
         _time_monitor(board_platformer::time_check,
                       std::ref(_last_input_time))
    {        
        while(true)
        {
            std::string input;
            std::getline(std::cin, input);

            _last_input_time.set_last_input_time(
                chrono::steady_clock::now());
        }
    }
}
