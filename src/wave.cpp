#include <iostream>
#include <vector>
#include "wave.hpp"
#include "enemy.hpp"

void Wave::create_wave(int level){
    if(level == 1){
        for(int i {0}; i<this->number_enemys; i++){
            Enemy one_enemy {1+i, 150, 2, 20, Enemy_Type::Normal, 0, 0};
            if(i==3){
                one_enemy.life = 100;
                one_enemy.speed = 3;
                one_enemy.money_reward = 30;
                one_enemy.type = Enemy_Type::Fast;
            }
            else if(i==8){
                one_enemy.life = 250;
                one_enemy.speed = 1;
                one_enemy.money_reward = 50;
                one_enemy.type = Enemy_Type::Robust;
            }

            this->enemys.push_back(one_enemy);
        }
    }
}