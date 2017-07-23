#ifndef _FORM_HPP_
#define _FORM_HPP_

#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>

#include "game.hpp"

namespace board_platformer
{
    class main_form: public nana::form
    {
        using widget = nana::widget;
    private:

    public:
        main_form();
        ~main_form() = default;
    };
}

#endif
