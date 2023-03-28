#pragma once
#include <string>
#include "Controller.hpp"
#include "AlwaysNextTurn.hpp"
#include "UserCommands.hpp"
#include <utility>

class UpdateController: public Controller
{
    GoLboard & plansza;
    view & widok;
    std::pair<int,int> cell_to_change();
public:
    std::string input() override;
    void game(CommandSource & commands);
    UpdateController(GoLboard & plansza, view & widok): plansza(plansza),widok(widok){}


};