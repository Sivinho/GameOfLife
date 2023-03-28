#include "UserCommands.hpp"
#include <iostream>


std::string UserCommands::next_command()
{
    std::string komenda;
    std::cout <<"Dostepne komendy: next,quit,change" <<std::endl<<"Podaj komende : ";
    std::cin >> komenda;
    if(komenda=="next")
    {
        return komenda;
    }
    else if(komenda=="quit")
    {
        return komenda;
    }
    else if(komenda=="change")
    {
        return komenda;
    }
    return "X";


}