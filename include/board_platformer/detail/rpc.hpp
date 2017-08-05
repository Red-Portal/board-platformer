#ifndef _RPC_HPP_
#define _RPC_HPP_

#include "strong_type.hpp"

namespace board_platformer
{
    namespace
    {
        namespace strong_type_types
        {
            enum class _process_id {null};
        }
    }
    typedef strong_type<uint16_t,
                        strong_type_types::_process_id> process_id;
}

#endif
