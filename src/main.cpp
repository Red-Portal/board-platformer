#include <nana/gui.hpp>

#include "form.hpp"

int main()
{
    auto main_form = bp::bp_form{};
    main_form.show();
    nana::exec();
    return 0;
}
