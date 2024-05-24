#include <iostream>
#include <vector>
#include "wave.hpp"
#include "enemy.hpp"

void Wave::create_wave(int level){
    if(level == 1){
        for(int i {0}; i<this->number_enemys; i++){
            Enemy one_enemy {1+i, 150, 0.5f, 20, Enemy_Type::Normal, 0.0f-(((float)i)/100.0f), 0.0f};
            if(i==3){
                one_enemy.life = 100;
                one_enemy.speed = 1.0f;
                one_enemy.money_reward = 30;
                one_enemy.type = Enemy_Type::Fast;
            }
            else if(i==8){
                one_enemy.life = 250;
                one_enemy.speed = 0.25f;
                one_enemy.money_reward = 50;
                one_enemy.type = Enemy_Type::Robust;
            }

            this->enemys.push_back(one_enemy);
        }
    }
    else if(level == 2){
        //En attente de réalisation 
    }
    else if(level == 3){
        //En attente de réalisation 
    }
}

void Wave::wave_setup(){
    this->create_wave(1);
    for(int i {0}; i<this->number_enemys; i++){
        this->enemys[i].enemy_apparition();
    }
}

void Wave::wave_forward(bool horizontal, bool vertical){
    if(horizontal && !vertical){
        for(int i {0}; i<this->number_enemys; i++){
            this->enemys[i].pos_X+=this->enemys[i].speed;
        }
    }
    else if(!horizontal && vertical){
        for(int i {0}; i<this->number_enemys; i++){
            this->enemys[i].pos_Y+=this->enemys[i].speed;
        }
    }
}