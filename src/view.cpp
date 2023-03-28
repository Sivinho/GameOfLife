#include "view.hpp"
#include <iostream>

view::view(const GoLboard &board) : dowyswietlenia(board){}

void view::display() const
{
    for(int i=0;i<dowyswietlenia.getheight();i++)
    {
        for(int j=0;j<dowyswietlenia.getwidth();j++)
        {

            if(dowyswietlenia.getcellinfo({i,j}))
            {
                std::cout << "\u2588";
            }
            else
            {
                std::cout << " ";
            }
        }
        std::cout<<std::endl;
    }

}
