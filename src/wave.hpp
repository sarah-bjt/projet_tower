#pragma once

#include <vector>
#include "enemy.hpp"

struct Wave{
    std::vector<Enemy> enemys {};
    int number_enemys {10};

    void create_wave(int level); // Doit prendre en paramètres le niveau dans lequel on est pour créer le tableau d'Enemys
    void wave_forward(bool horizontal, bool vertical); // Méthode qui fait avancer le tableau d'ennemis
};