#pragma once
#include "static_board.hpp"

class donut_GoLboard:public GoLboard{

    int countneighlivingcells(std::pair<int,int> coords) override;
public:
    donut_GoLboard(std::vector<std::pair<int,int>> structure);
};