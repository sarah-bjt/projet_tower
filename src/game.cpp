#include <iostream>
#include <vector>
#include "game.hpp"

int var {0};

void Game::create_game(){
    tower = Tower {1, 20, 2, 0.0005, 60, Tower_Type::Rock, 0.0f, 0.0f};
    wave = Wave {};
    wave.wave_setup();
}

void Game::start(){
    tower.tower_map_apparition(0.0f, 0.0f);
    if(var > 5){
        wave.wave_forward(false, true, false, true, false, false);
    }
    else {
        wave.wave_forward(true, false, false, false, false, true);
    }
    // for(Enemy enemy : wave.enemys){
    //     std::cout << enemy.pos_X << " et " << enemy.pos_Y << std::endl;
    // }
    tower.tower_aiming();
    var++;
}