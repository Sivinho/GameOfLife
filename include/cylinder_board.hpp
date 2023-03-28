#pragma once
#include "static_board.hpp"

class cylinder_GoLboard:public GoLboard{

    int countneighlivingcells(std::pair<int,int> coords) override;
public:
    cylinder_GoLboard(std::vector<std::pair<int,int>> structure);
};