#include "cylinder_board.hpp"

cylinder_GoLboard::cylinder_GoLboard(std::vector<std::pair<int, int>> structure): GoLboard(structure)
{}

int cylinder_GoLboard::countneighlivingcells(std::pair<int,int> coords){
    int suma_zywych_komorek = 0;
    for (int i = coords.second - 1; i < coords.second  + 2; i++)
    {
        if ((coords.first-1)>-1&&board[{coords.first-1,(i+getwidth())%getwidth()}])
        {
            suma_zywych_komorek++;
        }
    }
    for (int i = coords.second - 1; i < coords.second + 2; i++)
    {
        if ((coords.first+1)<getheight()&&board[{coords.first+1,(i+getwidth())%getwidth()}])
        {
            suma_zywych_komorek++;
        }
    }
    for (int i = coords.second - 1; i < coords.second + 2; i = i + 2)
    {
        if (board[{coords.first,(i+getwidth())%getwidth()}])
        {
            suma_zywych_komorek++;
        }
    }
    return suma_zywych_komorek;
}