#pragma once

#include "tower.hpp"
#include "enemy.hpp"

struct Game{
    //std::vector<Tower> tower; //(bullet dans tower ...)
    Tower tower;  //En fait ce serait un tableau de tower
    //Wave wave; (enemy dans wave...)
    //Map map;
    //Interface interface;
    //Player player;
    //Party party; (Path dans party...)

    //méthode pour créer le jeu
    void create_game();
    //méthode pour commencer le jeu et utiliser toutes les autres méthodes des autres struct
    void start();
};