#pragma once
# include <vector>
#include <string>

struct Player {
    std::string name;
    int money = {200};
    int score = {0};
    //std::vector<Tower_Type> towers;
    std::string chooseName();
    int increaseMoney();
    int buy();
    int increaseScore();
    //void addTower(const Tower_Type& tower);
};