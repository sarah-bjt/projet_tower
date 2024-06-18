#pragma once

# include <vector>
#include <string>

struct Player {
    std::string name;
    int money = {200}; // Quantité d'argent initial
    int score = {0}; // Score initial

    void increaseMoney(int reward); // Méthode pour augmenter la somme d'argent
    void decreaseMoney(int price); // Méthode pour baisser la somme d'argent
    void increaseScore(int new_score); // Méthode pour augmenter le score
};