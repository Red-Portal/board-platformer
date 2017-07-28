#include "logger.hpp"

namespace board_platformer
{
    global_logger&
    global_logger::get_instance()
    {
        mtx.lock();
        if(_instance == nullptr)
            _instance = std::make_unique<global_logger>();

        return *_instance;
    }
}
