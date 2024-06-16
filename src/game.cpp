#include <iostream>
#include <vector>
#include "game.hpp"

int var {0};

void Game::create_game(){
    tower = Tower {1, 100, 3, 0.0005, 150, Tower_Type::Rock, -0.2f, -0.2f};
    wave = Wave {};
    wave.wave_setup();
}

void Game::start(){
    map.map_apparition(map1);
    tower.tower_map_apparition();
    wave.wave_forward();
    tower.tower_aiming(this->wave.enemys);
    for(auto& enemy : this->wave.enemys){
        enemy.enemy_arrives();
    }
    var++;
}