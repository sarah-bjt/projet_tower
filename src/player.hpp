#pragma once

# include <vector>
#include <string>

struct Player {
    std::string name;
    int money = {200};
    int score = {0};

    void increaseMoney(int reward);
    void decreaseMoney(int price);
    void increaseScore(int new_score);
};