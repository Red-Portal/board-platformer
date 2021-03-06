
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

#ifndef _STRONG_TYPE_
#define _STRONG_TYPE_

#include <string>

#define STRONG_TYPE(TYPE, NAME)                         \
    namespace __strong_type_types{                      \
        enum class NAME##_{ null };                     \
    }                                                   \
    typedef strong_type<TYPE,                           \
                        __strong_type_types::NAME##_ > 


namespace board_platformer
{
    template<typename T, typename Type>
    struct strong_type
    {
        inline strong_type() = default;

        inline strong_type(T _val)
            :value(_val)
        {};

        inline strong_type&
        operator=(T _val) noexcept
        {
            value = _val;
        }

        inline bool
        operator==(strong_type<T, Type> const& _val)
            const noexcept
        {
            return _val.value == this->value;
        }

        inline bool
        operator!=(strong_type<T, Type> const& _val)
            const noexcept
        {
            return _val.value != this->value;
        }

        inline strong_type<T, Type>&
        operator=(strong_type<T, Type> const& other) = default;

        inline strong_type<T, Type>&
        operator=(strong_type<T, Type>&& other)
            noexcept = default;

        inline
        strong_type(strong_type<T, Type>&& other)
            noexcept = default;

        inline
        strong_type(strong_type<T, Type> const& other) = default;

        T value;
    };
}

#endif
