#include <nana/gui.hpp>

#include "form.hpp"
#include "game.hpp"

int main()
{
    auto main_form = board_platformer::main_form{};
    main_form.show();
    nana::exec();
    return 0;
}
