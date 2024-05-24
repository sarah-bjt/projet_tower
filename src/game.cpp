#include <iostream>
#include <vector>
#include "game.hpp"


void Game::create_game(){
    tower = Tower {1, 20, 2, 0.0005, 60, Tower_Type::Rock};
}

void Game::start(){
    tower.tower_map_apparition(0.0f, 0.0f);
}