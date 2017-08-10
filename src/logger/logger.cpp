#include <string>
#include <iostream>

#include "logger.hpp"

namespace board_platformer
{

    parallel_logger::
    parallel_logger(fs::path const& log_path,
                    chrono::duration<int> timeout)
        :_timeout(timeout),
         _last_input_time(chrono::steady_clock::now()),
         _time_monitor(board_platformer::time_check,
                       std::ref(_last_input_time))
    {        
        std::fstream fout;
        
        while(true)
        {
            std::string input;
            std::getline(std::cin, input);

            _last_input_time.set_last_input_time(
                chrono::steady_clock::now());

            write_stream(fout, input);
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
            write_stream(input);
        }
    }
}
