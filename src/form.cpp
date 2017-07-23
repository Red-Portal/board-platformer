#include <nana/gui.hpp>
#include <string>

#include "form.hpp"

namespace board_platformer
{
    main_form::
    main_form()
        : nana::form(nana::API::make_center(800, 450))
    {
        widget::caption(
            "Board Platformer - A Board game AI development platform");
        // auto text = std::string{"this is some test plain text!"};

    }
}
