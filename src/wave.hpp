#pragma once

#include <vector>
#include "enemy.hpp"

struct Wave{
    std::vector<Enemy> enemys {};
    int number_enemys {10};

    //Il va me falloir une instance Path pour pouvoir gérer la direction de la vague, et ainsi faire tourner les ennemis un par un

    void create_wave(int level); // Doit prendre en paramètres le niveau dans lequel on est pour créer le tableau d'Enemys
    void wave_forward(bool horizontal, bool vertical, bool UP, bool DOWN, bool LEFT, bool RIGHT); // Méthode qui fait avancer le tableau d'ennemis
    void wave_setup(); // méthode pour mettre en place la wave
};