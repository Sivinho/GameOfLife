#include "InputController.hpp"
#include <iostream>
#include <cstdlib>
#include <algorithm>
#include <limits>
#include <cctype>

std::string InputController::input()
{
    std::string state;
    while(true){
        std::cout<<"Wybierz poczatkowy stan planszy"<<std::endl<<"Dostepne stany: Tub,Block,Beacon,Blinker,Random,Empty"<<std::endl<<"Podaj stan planszy: ";
        std::cin >> state;
        if(state!="Tub"&&state!="tub"&&state!="Block"&&state!="block"&&state!="Beacon"&&state!="beacon"&&state!="Blinker"&&state!="blinker"&&state!="random"&&state!="Random"&&state!="Empty"&&state!="empty")
        {
            std::cout<<"Niepoprawny stan planszy!! Spróbuj ponownie"<<std::endl;
            continue;
        }
        return state;
    }
}

std::vector<std::pair<int,int>> InputController::start_state()
{
    std::vector<std::pair<int,int>> structure;
    std::string state=input();
    if(state=="Block"||state=="block")
    {
        std::pair<int,int> c1(9,9);
        std::pair<int,int> c2(10,9);
        std::pair<int,int> c3(9,10);
        std::pair<int,int> c4(10,10);
        structure = {c1,c2,c3,c4};
        return structure;
    }
    else if(state=="Tub"||state=="tub")
    {
        std::pair<int,int> c1(9,9);
        std::pair<int,int> c2(8,10);
        std::pair<int,int> c3(9,11);
        std::pair<int,int> c4(10,10);
        structure = {c1,c2,c3,c4};
        return structure;
    }
    else if(state=="Blinker"||state=="blinker")
    {
        std::pair<int,int> c1(9,9);
        std::pair<int,int> c2(9,10);
        std::pair<int,int> c3(9,11);
        structure = {c1,c2,c3};
        return structure;
    }
    else if(state=="Beacon"||state=="beacon")
    {
        std::pair<int,int> c1(9,9);
        std::pair<int,int> c2(10,9);
        std::pair<int,int> c3(9,10);
        std::pair<int,int> c4(10,10);
        std::pair<int,int> c5(11,11);
        std::pair<int,int> c6(12,11);
        std::pair<int,int> c7(12,12);
        std::pair<int,int> c8(11,12);
        structure={c1,c2,c3,c4,c5,c6,c7,c8};
        return structure;
    }
    else if(state=="Random"||state=="random")
    {
        int number_of_lives;
        std::cout<<"Podaj liczbe zywych komórek do wylosowania na planszy: ";
        std::cin>>number_of_lives;
        if(std::isdigit(number_of_lives)==0)
        {
            while(true)
            {
                if(number_of_lives<0||number_of_lives>400)
                {
                    std::cout<<"Podaj liczbę z przedziału [0,400]!"<<std::endl;
                    std::cout<<"Podaj liczbe zywych komórek do wylosowania na planszy: ";
                    std::cin>>number_of_lives;
                    continue;
                }
                break;
            }
        }
        else {
            while (std::cin.fail() != false) {
                std::cout << std::endl << "Podaj liczbę!" << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << std::endl << "Podaj liczbe zywych komórek do wylosowania na planszy: ";
                std::cin >> number_of_lives;
            }
        }
        int k=0;
        while(k<number_of_lives)
        {
            int a=rand()%20;
            int b=rand()%20;
            std::pair<int,int> coords(a,b);
            if(std::find(structure.begin(),structure.end(),coords)==structure.end())
            {
                structure.push_back(coords);
                k++;
            }
        }
        return structure;
    }
    return structure;

}

std::string InputController::board_choice()
{
    std::string choice;
    while(true){
        std::cout<<"Wybierz plansze"<<std::endl<<"Dostepne plansze: Static,Cylinder,Donut"<<std::endl<<"Podaj plansze: ";
        std::cin >> choice;
        if(choice!="Static"&&choice!="Cylinder"&&choice!="Donut")
        {
            std::cout<<"Niepoprawny plansza!! Spróbuj ponownie"<<std::endl;
            continue;
        }
        return choice;
    }
}