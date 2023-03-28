#pragma once
#include <map>
#include <vector>
#include <utility>

class GoLboard
{
protected:
    std::map<std::pair<int,int>,bool> board;
private:
    int width=20;
    int height=20;
    virtual int countneighlivingcells(std::pair<int,int> coords);
public:
    explicit GoLboard(std::vector<std::pair<int,int>> structure);
    void change_life_of_cell(std::pair<int,int> coords);
    void changelifeofcells();
    int getwidth() const;
    int getheight() const;
    bool getcellinfo(std::pair<int,int> coords) const;
};