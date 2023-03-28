#pragma once
#include "static_board.hpp"

class view{
public:
    view(GoLboard const & board);
    void display() const;
private:
    GoLboard const & dowyswietlenia;

};