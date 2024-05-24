#include <iostream>
#include <vector>
#include "wave.hpp"
#include "enemy.hpp"

void Wave::create_wave(int level){
    if(level == 1){
        for(int i {0}; i<10; i++){
            Enemy one_enemy {1+i, 150, 2, 20, Enemy_Type::Normal};
            if(i==3){
                one_enemy->life = 100;
                one_enemy->speed = 3;
                one_enemy->money_reward = 30;
            }
            
        }
    }
}