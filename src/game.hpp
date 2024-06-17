#pragma once

#include "tower.hpp"
#include "enemy.hpp"
#include "wave.hpp"
#include "map.hpp"
#include "App.hpp"

struct Game{
    //std::vector<Tower> tower; //(bullet dans tower ...)
    std::vector<Tower> all_towers {};  //En fait ce serait un tableau de tower
    Wave wave; //(enemy dans wave...)
    Map map;
    //Interface interface;
    //Player player;
    //Party party; (Path dans party...)

    //méthode pour créer le jeu
    void create_game();
    //méthode pour commencer le jeu et utiliser toutes les autres méthodes des autres struct
    void start();
    void update(int player_action, std::pair<double, double> position);
};

