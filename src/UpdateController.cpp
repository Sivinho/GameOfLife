#include "UpdateController.hpp"
#include <iostream>
#include <limits>
#include <cstdlib>

std::string UpdateController::input()
{
    std::string wybrany_tryb;
    while(true){
        std::cout << "Wybierz źródło komend: user, auto : "<<std::endl;
        std::cin >> wybrany_tryb;
        if(wybrany_tryb!="user"&&wybrany_tryb!="auto")
        {
            std::cout<<"Niepoprawne źródło komend!!! Spróbuj ponownie"<<std::endl;
            continue;
        }
        system("clear");
        return wybrany_tryb;
    }

}
std::pair<int,int> UpdateController::cell_to_change()
{
    int x1,y1;
    std::cout << "Podaj pole" << std::endl;
    std::cout << "Podaj numer wiersza licząc od jedynki:";
    std::cin >> x1;
    std::cout << "Podaj numer kolumny licząc od jedynki:";
    std::cin >> y1;
    while (std::cin.fail() != false)
    {
        std::cout << std::endl << "Podaj liczbe całkowitą!";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << std::endl << "Podaj pole" << std::endl;
        std::cout << "Podaj numer wiersza licząc od jedynki:";
        std::cin >> x1;
        std::cout << "Podaj numer kolumny licząc od jedynki:";
        std::cin >> y1;
    }
    std::pair<int,int> coords(x1-1,y1-1);
    return coords;
}

void UpdateController::game(CommandSource &commands)
{
    while(true)
    {
        system("clear");
        widok.display();
        std::string komenda =commands.next_command();
        if(komenda=="next")
        {
            plansza.changelifeofcells();
        }
        else if(komenda=="quit")
        {
            return;
        }
        else if(komenda=="change")
        {
            plansza.change_life_of_cell(cell_to_change());
        }
    }
}
