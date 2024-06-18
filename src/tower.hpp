#pragma once

#include "bullet.hpp"
#include "wave.hpp"
#include "enemy.hpp"
#include <vector>

enum class Tower_Type { //Les différents types de Tour
    Wood,
    Rock
};

struct Tower{
    int tower_id; //identifiant de la tour
    int fire_power;  // La puissance de tire de la tour
    int fire_distance; // La distance max pour qu'une bullet atteigne un ennemi
    float fire_rythm;  // L'intervalle en millième de secondes entre chaque bullet de tirée.
    int price; // Le prix en fonction du type de tour
    Tower_Type type; //Le type de la tour

    float x_pos, y_pos;  //La position de la tour sur la map
    Bullet bullet;  //Son instance Bullet pour pouvoir la tirer sur les ennemis
    
    void tower_map_apparition();  //méthode pour faire apparaître les sprites des towers sur la map
    void tower_aiming(std::vector<Enemy>& enemys, Player& player);  //La méthode pour détecter un ennemi à partir de fire_distance et du tableau d'ennemis de wave
    void tower_fire(Enemy& enemy);  //méthode pour faire feu sur un ennemi quand il y a détection
};
