#pragma once

struct Player {
    std::string name;
    int money = {200};
    int score = {0};
    std::string chooseName();
    int increaseMoney();
    int buy();
    int increaseScore();
};