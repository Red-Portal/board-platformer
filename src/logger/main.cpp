#include <chrono>
#include <string>

#include "logger.hpp"

namespace bp = board_platformer;
namespace chrono = std::chrono;

int main(int argc, char** argv)
{
    (void)argc;
    int timeout = std::stoi(argv[1]);
    bp::parallel_logger logger{chrono::duration<int>(timeout)};
    return 0;
}
    
