#include "donut_board.hpp"

donut_GoLboard::donut_GoLboard(std::vector<std::pair<int,int>> structure): GoLboard(structure)
{}
int donut_GoLboard::countneighlivingcells(std::pair<int,int> coords){
    int suma_zywych_komorek = 0;
    for (int i = coords.second - 1; i < coords.second  + 2; i++)
    {
        if (board[{(coords.first-1+getheight())%getheight(),(i+getwidth())%getwidth()}])
        {
            suma_zywych_komorek++;
        }
    }
    for (int i = coords.second - 1; i < coords.second + 2; i++)
    {
        if (board[{(coords.first+1+getheight())%getheight(),(i+getwidth())%getwidth()}])
        {
            suma_zywych_komorek++;
        }
    }
    for (int i = coords.second - 1; i < coords.second + 2; i = i + 2)
    {
        if (board[{(coords.first+getheight())%getheight(),(i+getwidth())%getwidth()}])
        {
            suma_zywych_komorek++;
        }
    }
    return suma_zywych_komorek;
}