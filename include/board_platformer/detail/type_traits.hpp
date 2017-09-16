#ifndef _TYPE_TRAITS_HPP_
#define _TYPE_TRAITS_HPP_

#include <type_traits>

namespace board_platformer
{
    template<typename T, typename U>
    struct is_specialization_of;

    template<typename T, typename U>
    struct is_specialization_of
        : std::false_type {};

    template<typename T, typename U>
    struct is_specialization_of<T<U>>
        : std::true_type {};
}

#endif
