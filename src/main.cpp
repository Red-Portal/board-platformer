#include <nana/gui.hpp>
#include <nana/gui/widgets/button.hpp>

int main()
{
    nana::form fm;

    fm.caption(L"Hello, World!");
    nana::button btn(fm, nana::rectangle{20, 20, 150, 30});

    btn.caption(L"Quit");
    btn.events().click(nana::API::exit);
    fm.show(); 

    nana::exec();

    return 0;
}
