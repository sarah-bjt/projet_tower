#include <iostream>
#include <vector>
#include "game.hpp"


void Game::create_game(){
    tower = Tower {1, 20, 2, 0.0005, 60, Tower_Type::Rock};
    wave = Wave {};
    wave.create_wave(1);
    for(int i {0}; i<10; i++){
        std::cout << wave.enemys[i].life << ", " << wave.enemys[i].pos_X << " et " << wave.enemys[i].pos_Y << std::endl;
    }
}

void Game::start(){
    tower.tower_map_apparition(0.0f, 0.0f);
    wave.wave_forward(false, true);
    for(Enemy enemy : wave.enemys){
        std::cout << enemy.pos_X << " et " << enemy.pos_Y << std::endl;
    }
}