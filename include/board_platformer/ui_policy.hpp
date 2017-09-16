// Board Platformer. A Board Game AI Developing Platform
// Copyright (C) 2017  Red-Portal
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef _UI_POLICY_HPP_
#define _UI_POLICY_HPP_

namespace board_platformer
{
    class ui_policy_base
    {
    public:
        virtual void game_over() = 0;
        virtual void after_move() = 0;
        virtual void while_move() = 0;
        virtual void before_move() = 0;
        virtual void game_start() = 0;
    };
}

#endif
