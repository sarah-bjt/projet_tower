#pragma once

#include "enemy.hpp"
#include "path.hpp"

#include <vector>

struct Wave{
    int number_enemys;  //indique le nombre d'ennemis que contiendra la vague
    std::vector<Enemy> enemys {};  //Contient tous les ennemis de la vague
    WeightedGraph graph;  //Contient le graphe de la map

    void create_wave(int level); // Doit prendre en paramètres le niveau dans lequel on est pour créer le tableau d'Enemys
    void wave_forward(); // Méthode qui fait avancer le tableau d'ennemis 
    void wave_setup(int level); // méthode pour mettre en place la wave
    bool enemys_of_one_wave_dead(); //Méthode pour savoir si tous les ennemis de la vague sont mort sans lancer le message WIN
    void allEnemiesDead() const; //savoir si tous les ennemis sont mort 
};
