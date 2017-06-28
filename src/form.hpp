#ifndef _FORM_HPP_
#define _FORM_HPP_

#include <nana/gui.hpp>
#include <nana/gui/widgets/label.hpp>

namespace bp
{
    class bp_form : public nana::form
    {
    private:
    public:
        bp_form();
        ~bp_form() = default;
    };
}

#endif
