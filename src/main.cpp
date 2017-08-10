
///////////////////////////////////////////////////////////////////////////////
// Board Platformer. A Board Game AI Developing Platform                     //
// Copyright (C) 2017  Red-Portal                                            //
//                                                                           //
//     This program is free software: you can redistribute it and/or modify  //
//     it under the terms of the GNU General Public License as published by  //
//     the Free Software Foundation, either version 3 of the License, or     //
//     (at your option) any later version.                                   //
//                                                                           //
//     This program is distributed in the hope that it will be useful,       //
//     but WITHOUT ANY WARRANTY; without even the implied warranty of        //
//     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         //
//     GNU General Public License for more details.                          //
//                                                                           //
//     You should have received a copy of the GNU General Public License     //
//     along with this program.  If not, see <http://www.gnu.org/licenses/>. //
///////////////////////////////////////////////////////////////////////////////

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
