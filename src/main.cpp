#include "static_board.hpp"
#include "UserCommands.hpp"
#include "AlwaysNextTurn.hpp"
#include "UpdateController.hpp"
#include "InputController.hpp"
#include "cylinder_board.hpp"
#include "donut_board.hpp"
#include "view.hpp"
#include <time.h>
#include <cstdlib>


int main()
{
    srand(time(NULL));
    InputController inctrl;
    std::string plansza=inctrl.board_choice();
    AlwaysNextTurn auto_commands;
    UserCommands user_commands;
    if(plansza=="Static")
    {
        GoLboard gra(inctrl.start_state());
        view widok(gra);
        UpdateController upctrl(gra,widok);
        std::string commands=upctrl.input();
        if(commands=="user")
        {
            upctrl.game(user_commands);
        }
        else if(commands=="auto")
        {
            upctrl.game(auto_commands);
        }
    }
    else if(plansza=="Cylinder")
    {
        cylinder_GoLboard gra(inctrl.start_state());
        view widok(gra);
        UpdateController upctrl(gra,widok);
        std::string commands=upctrl.input();
        if(commands=="user")
        {
            upctrl.game(user_commands);
        }
        else if(commands=="auto")
        {
            upctrl.game(auto_commands);
        }
    }
    else
    {
        donut_GoLboard gra(inctrl.start_state());
        view widok(gra);
        UpdateController upctrl(gra,widok);
        std::string commands=upctrl.input();
        if(commands=="user")
        {
            upctrl.game(user_commands);
        }
        else if(commands=="auto")
        {
            upctrl.game(auto_commands);
        }
    }
    return 0;
}
