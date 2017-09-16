#ifndef _TYPE_TRAITS_HPP_
#define _TYPE_TRAITS_HPP_

#include <type_traits>
#include <board_platformer/detail/game_board.hpp>

namespace board_platformer
{
    template <typename T>
    struct is_gameboard
        : std::false_type {};

    template <size_t X, size_t Y>
    struct is_gameboard<game_board_impl<X, Y>>
        : std::true_type {};
}

#endif
