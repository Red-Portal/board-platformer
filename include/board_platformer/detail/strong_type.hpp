#ifndef _STRONG_TYPE_
#define _STRONG_TYPE_

namespace board_platformer
{
    template<typename T>
    struct strong_type
    {
        inline strong_type(T _val)
            :value(_val)
        {};

        inline strong_type& operator=(T _val)
        {
            value = _val;
        }

        T value;
    };
}

#endif
