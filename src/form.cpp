#include <nana/gui.hpp>
#include <string>

#include "form.hpp"

namespace bp
{
    bp_form::
    bp_form()
        : nana::form(nana::API::make_center(800, 450))
    {
        nana::widget::caption(
            "Board Platformer - A Board game AI development platform");
        // auto text = std::string{"this is some test plain text!"};
    }
}
