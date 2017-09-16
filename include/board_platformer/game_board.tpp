namespace board_platformer
{
    template<size_t tX, size_t tY>
    size_t
    game_board_t<tX, tY>::
    to_linear_idx(size_t x, size_t y) const noexcept
    { return tX * y + x; }

    template<size_t tX, size_t tY>
    coordinate_t 
    game_board_t<tX, tY>::
    from_linear_idx(size_t lin) const noexcept
    {
        auto x = lin % tX;
        auto y = lin / tX;
        return {x, y};
    }

    template<size_t tX, size_t tY>
    game_board_t<tX, tY>::
    game_board_t()
        :_board()
    {
        for(auto i = 0u; i < tX * tY; ++i)
        {
            auto coord = from_linear_idx(i);
            _board[i] = point_t(coord, point_state_t(0));
        }
    } 

    template<size_t tX, size_t tY>
    typename std::array<point_t, tX * tY>::iterator
    game_board_t<tX, tY>::
    begin() noexcept
    { return _board.begin(); }

    template<size_t tX, size_t tY>
    typename std::array<point_t, tX * tY>::iterator
    game_board_t<tX, tY>::
    end() noexcept
    { return _board.end(); }

    template<size_t tX, size_t tY>
    typename std::array<point_t, tX * tY>::const_iterator
    game_board_t<tX, tY>::
    begin() const noexcept 
    { return _board.begin(); }

    template<size_t tX, size_t tY>
    typename std::array<point_t, tX * tY>::const_iterator
    game_board_t<tX, tY>::
    end() const  noexcept 
    { return _board.begin(); }

    template<size_t tX, size_t tY>
    typename std::array<point_t, tX * tY>::const_iterator
    game_board_t<tX, tY>::
    cbegin() const  noexcept 
    { return _board.cbegin(); }

    template<size_t tX, size_t tY>
    typename std::array<point_t, tX * tY>::const_iterator
    game_board_t<tX, tY>::
    cend() const   noexcept 
    { return _board.cbegin(); }

    template<size_t tX, size_t tY>
    constexpr size_t
    game_board_t<tX, tY>::
    size() const  noexcept 
    { return _board.size(); }

    template<size_t tX, size_t tY>
    point_state_t
    game_board_t<tX, tY>::
    operator()(size_t x, size_t y) const
    { return _board[to_linear_idx(x, y)].state; }

    template<size_t tX, size_t tY>
    point_state_t&
    game_board_t<tX, tY>::
    operator()(size_t x, size_t y)
    { return _board[to_linear_idx(x, y)].state; }

    template<size_t tX, size_t tY>
    size_t
    game_board_t<tX, tY>::
    col_size() const noexcept
    { return tX; }

    template<size_t tX, size_t tY>
    size_t
    game_board_t<tX, tY>::
    row_size() const noexcept
    { return tY; }
}
