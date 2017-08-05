#include <iostream>

#include <nana/gui.hpp>

#include "logger.hpp"
#include "form.hpp"
#include "game.hpp"

namespace bp = board_platformer;

int main()
{
    // auto main_form = board_platformer::main_form{};
    // main_form.show();
    // nana::exec();
    std::cout << "running!" << std::endl;
    bp::global_logger::get_singleton().add_log("me", "hi there!");

    return 0;
}
