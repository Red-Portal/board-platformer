#include "logger.hpp"

namespace board_platformer
{
    global_logger&
    global_logger::get_instance()
    {
        static std::unique_ptr<global_logger> _instance = nullptr;

        if(_instance == nullptr)
            _instance = std::unique_ptr<global_logger>();

        return *_instance;
    }
}
