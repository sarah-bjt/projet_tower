#include "game.hpp"

#include <GLFW/glfw3.h>
#include <iostream>
#include <iostream>
#include <vector>

void Game::create_game(std::string player_name){
    all_towers.push_back(Tower {1, 300, 3, 1.5f, 150, Tower_Type::Rock, -0.2f, -0.2f});
    wave = Wave {};
    wave.wave_setup();
    player.name = player_name;
}

void Game::start(){
    map.map_apparition(map1);
    // all_towers[0].tower_map_apparition();
    for(int i {0}; i<all_towers.size(); i++){
        all_towers[i].tower_map_apparition();
    }
    wave.wave_forward();
    // all_towers[0].tower_aiming(this->wave.enemys);
    for(int i {0}; i<all_towers.size(); i++){
        all_towers[i].tower_aiming(this->wave.enemys, this->player);
    }
    for(auto& enemy : this->wave.enemys){
        enemy.enemy_arrives();
    }
}


void Game::update(int player_action, std::pair<double, double> position)
{
    static bool woodTowerPurchased = false; // Variable statique pour suivre l'état de l'achat de la tour en bois
    static bool rockTowerPurchased = false; // Variable statique pour suivre l'état de l'achat de la tour en pierre

    if (player_action == 1 && !woodTowerPurchased) //Pour tower Wood
    {
        std::cout << "achat tour B" << std::endl;
        all_towers.push_back(Tower {1, 20, 2, 0.0005, 60, Tower_Type::Wood, static_cast<float>(position.first), static_cast<float>(position.second)});
        woodTowerPurchased = true;
        std::cout << "Nombre total de tours : " << all_towers.size() << std::endl;
    }
    else if (player_action == 2 && !rockTowerPurchased) // Pour tower Rock
    {
        std::cout << "achat tour P" << std::endl;
        all_towers.push_back(Tower {1, 80, 3, 0.0005, 150, Tower_Type::Rock, static_cast<float>(position.first), static_cast<float>(position.second)});
        rockTowerPurchased = true;
        std::cout << "Nombre total de tours : " << all_towers.size() << std::endl;
    }
    if (player_action == 0)
    {
        woodTowerPurchased = false;
        rockTowerPurchased = false;
    }
}

