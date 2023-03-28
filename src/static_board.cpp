#include "static_board.hpp"



GoLboard::GoLboard(std::vector<std::pair<int,int>> structure)
{
    for(int i = 0;i<height;i++)
    {
        for(int j=0;j<width;j++)
        {
            board.insert({{i,j}, false});
        }
    }
    if(structure.size()>0)
    {
    for(auto const& str : structure)
    {
        board[str]=true;
    }
    }
}


int GoLboard::countneighlivingcells(std::pair<int,int> coords)
    {
    int suma_zywych_komorek = 0;
    for (int i = coords.second - 1; i < coords.second  + 2; i++)
    {
        if (board.find({coords.first-1,i})!=board.end()&&board[{coords.first-1,i}])
        {
            suma_zywych_komorek++;
        }
    }
    for (int i = coords.second - 1; i < coords.second + 2; i++)
    {
        if (board.find({coords.first+1,i})!=board.end()&&board[{coords.first+1,i}])
        {
            suma_zywych_komorek++;
        }
    }
    for (int i = coords.second - 1; i < coords.second + 2; i = i + 2)
    {
        if (board.find({coords.first,i})!=board.end()&&board[{coords.first,i}])
        {
            suma_zywych_komorek++;
        }
    }
    return suma_zywych_komorek;
}
void GoLboard::changelifeofcells()
{
    std::vector<std::pair<int,int>> coords;
    for(auto const& [key,value] : board)
        {
        if(value&&(countneighlivingcells(key)!=2&&countneighlivingcells(key)!=3))
            {
                coords.push_back(key);
            }
            else if(!value&&countneighlivingcells(key)==3)
            {
                coords.push_back(key);
            }
        }
    for(auto const& coord : coords)
    {
        board[coord]=!board[coord];
    }
    coords.clear();
}
void GoLboard::change_life_of_cell(std::pair<int,int> coords)
{
    if(board.find(coords)!=board.end())
    {
        board[{coords.first,coords.second}]=!board[{coords.first,coords.second}];
    }

}


bool GoLboard::getcellinfo(std::pair<int, int> coords) const
{
    return board.at(coords);
}

int GoLboard::getheight() const {return height;}
int GoLboard::getwidth() const {return width;}