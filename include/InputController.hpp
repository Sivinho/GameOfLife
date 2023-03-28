#pragma once
#include "Controller.hpp"


class InputController : public Controller
{
    std::string input() override;
public:
    std::string board_choice();
    std::vector<std::pair<int,int>> start_state();
};