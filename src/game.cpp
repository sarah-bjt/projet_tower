#include "game.hpp"

#include <GLFW/glfw3.h>
#include <iostream>
#include <iostream>
#include <vector>

void Game::create_game(std::string player_name){
    waves.push_back(Wave {10});
    waves.push_back(Wave {12});
    waves.push_back(Wave {15});
    for(unsigned int i {0}; i<waves.size(); i++){
        waves[i].wave_setup(i+1);
    }
    player.name = player_name;
}

void Game::start(){
    map.map_apparition(map1); // fait apparaitre la map 
    for(unsigned int i {0}; i<all_towers.size(); i++){
        all_towers[i].tower_map_apparition();
    }
    // all_towers[0].tower_map_apparition();
    if(!this->waves[0].enemys_of_one_wave_dead()){
        waves[0].wave_forward();
        // all_towers[0].tower_aiming(this->wave.enemys);
        for(unsigned int i {0}; i<all_towers.size(); i++){
            all_towers[i].tower_aiming(this->waves[0].enemys, this->player);
        }
        for(auto& enemy : this->waves[0].enemys){
            enemy.enemy_arrives();
        }
    }
    else if(!this->waves[1].enemys_of_one_wave_dead()){
        waves[1].wave_forward();
        // all_towers[0].tower_aiming(this->wave.enemys);
        for(unsigned int i {0}; i<all_towers.size(); i++){
            all_towers[i].tower_aiming(this->waves[1].enemys, this->player);
        }
        for(auto& enemy : this->waves[1].enemys){
            enemy.enemy_arrives();
        }
    }
    else {
        //la dernière vague
        waves[waves.size()-1].wave_forward();
        // all_towers[0].tower_aiming(this->wave.enemys);
        for(unsigned int i {0}; i<all_towers.size(); i++){
            all_towers[i].tower_aiming(this->waves[waves.size()-1].enemys, this->player);
        }
        for(auto& enemy : this->waves[waves.size()-1].enemys){
            enemy.enemy_arrives();
        }
    }
    waves[waves.size()-1].allEnemiesDead(); //indique que tous les ennemies après les trois vagues sont bien mort, donc la partie est gagnée
}

// Cette fonction place une tour sur la grille en fonction de la position de la souris
void Game::update(int player_action, std::pair<double, double> mouse_position)
{
    static bool woodTowerPurchased = false; // Variable statique pour suivre l'état de l'achat de la tour en bois
    static bool rockTowerPurchased = false; // Variable statique pour suivre l'état de l'achat de la tour en pierre

    // ici x et y sont les coordonnées des cases où apparaissent les tours
    int x {static_cast<int>( static_cast<float>( mouse_position.first)/60)};
    int y {static_cast<int>( static_cast<float>( mouse_position.second)/60)};
    // les coordonnées exactes des tours
    float position_tower_x {-1.85f + x*(120.0f/720.0f)};
    float position_tower_y {0.85f - y*(120.0f/720.0f)};
    //Les tours ne peuvent être placées que sur des cases spécifiques (les "herbes")
    if (x > 11 ){return;}
    else if (y == 1 && (x < 5 || (x > 6 && x < 11))){return;}
    else if (y == 2 && (x == 4 || x == 7 || x == 10)){return;}
    else if (y == 3 && ((x >3 && x<8) || x == 10)){return;}
    else if (y == 4 && x==10 ){return;}
    else if (y == 5 && ((x >0 && x<5) ||(x >7 && x<11))){return;}
    else if (y == 6 && (x == 1 || x == 4 || x == 8)){return;}
    else if (y == 7 && (x == 1 || x == 4 || (x >7 && x<11)) ){return;}
    else if (y == 8 && (x == 4 || x == 10 || x<2 ) ) {return;}
    else if (y == 9 && (x == 4 || x == 10 )){return;}
    else if (y == 10 && (x >3 && x<11)){return;}


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
        if(this->player.money-90 >= 0){
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

