#pragma once

#include "enemy.hpp"
#include "path.hpp"

#include <vector>

struct Wave{
    int number_enemys;
    std::vector<Enemy> enemys {};
    WeightedGraph graph;

    //Il va me falloir une instance Path pour pouvoir gérer la direction de la vague, et ainsi faire tourner les ennemis un par un

    void create_wave(int level); // Doit prendre en paramètres le niveau dans lequel on est pour créer le tableau d'Enemys
    void wave_forward(); // Méthode qui fait avancer le tableau d'ennemis   //bool horizontal, bool vertical, bool UP, bool DOWN, bool LEFT, bool RIGHT
    void wave_setup(int level); // méthode pour mettre en place la wave
    bool enemys_of_one_wave_dead();
    void allEnemiesDead() const; //savoir si tous les ennemis sont mort 
};