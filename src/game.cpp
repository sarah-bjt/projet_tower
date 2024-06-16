#include <iostream>
#include <vector>
#include "game.hpp"

int var {0};

void Game::create_game(){
    tower = Tower {1, 200, 3, 0.0005, 150, Tower_Type::Rock, 0.0f, 0.0f};
    wave = Wave {};
    wave.wave_setup();
}

void Game::start(){
    tower.tower_map_apparition();
    if(var > 20){
        wave.wave_forward(false, true, false, true, false, false);
    }
    else {
        wave.wave_forward(true, false, false, false, false, true);
    }
    tower.tower_aiming(this->wave.enemys);
    for(auto& enemy : this->wave.enemys){
        // if(enemy.enemy_arrives()){
        //     enemy.enemy_id = -2;
        // }
        enemy.enemy_arrives();
    }
    var++;
}