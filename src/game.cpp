#include "game.hpp"

#include <GLFW/glfw3.h>
#include <iostream>
#include <iostream>
#include <vector>

void Game::create_game(std::string player_name){
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
    wave.allEnemiesDead();
}


void Game::update(int player_action, std::pair<double, double> mouse_position)
{
    static bool woodTowerPurchased = false; // Variable statique pour suivre l'état de l'achat de la tour en bois
    static bool rockTowerPurchased = false; // Variable statique pour suivre l'état de l'achat de la tour en pierre

    float position_tower_x {-1.85f + static_cast<int>( static_cast<float>( mouse_position.first)/60)*(120.0f/720.0f)};
    float position_tower_y {0.85f - static_cast<int>( static_cast<float>( mouse_position.second)/60)*(120.0f/720.0f)};

    if (player_action == 1 && !woodTowerPurchased) //Pour tower Wood
    {
        if(this->player.money-60 >= 0){
            std::cout << "achat tour B dans les positions "<<mouse_position.first<<mouse_position.second << std::endl;
            Tower towerW = Tower {1, 20, 2, 1.5f, 60, Tower_Type::Wood,position_tower_x, position_tower_y};
            this->player.decreaseMoney(towerW.price);
            all_towers.push_back(towerW);
            //std::cout << "argent = " << this->player.money << std::endl;
            woodTowerPurchased = true;
            std::cout << "Nombre total de tours : " << all_towers.size() << std::endl;
        }
        else {
            std::cout << "Vous n'avez pas assez d'argent" << std::endl;
        }
    }
    else if (player_action == 2 && !rockTowerPurchased) // Pour tower Rock
    {
        if(this->player.money-150 >= 0){
            std::cout << "achat tour P dans les positions "<<mouse_position.first<<mouse_position.second << std::endl;
            Tower towerR = Tower {1, 80, 3, 1.5f, 90, Tower_Type::Rock,position_tower_x, position_tower_y};
            this->player.decreaseMoney(towerR.price);
            all_towers.push_back(towerR);
            //std::cout << "argent = " << this->player.money << std::endl;
            rockTowerPurchased = true;
            std::cout << "Nombre total de tours : " << all_towers.size() << std::endl;        
        }
        else {
            std::cout << "Vous n'avez pas assez d'argent" << std::endl;
        }
    }
    if (player_action == 0)
    {
        woodTowerPurchased = false;
        rockTowerPurchased = false;
    }
}

