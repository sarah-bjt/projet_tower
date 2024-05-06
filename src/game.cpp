#include <iostream>
#include <vector>
#include "game.hpp"
#include "tower.hpp"
#include "enemy.hpp"

void Game::create_game(){
    Tower tower_1 {1, 20, 2, 0.0005, 60, Tower_Type::Wood};
    tower_1.tower_map_apparition(12, 34);
}