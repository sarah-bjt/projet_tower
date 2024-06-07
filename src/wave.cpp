#include <iostream>
#include <vector>
#include "wave.hpp"
#include "enemy.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <img/img.hpp>

#include <sstream>

#include "simpletext.h"
#include "utils.hpp"
#include "GLHelpers.hpp"

double previous_time {0.0};

void Wave::create_wave(int level){
    if(level == 1){
        for(int i {0}; i<this->number_enemys; i++){
            Enemy one_enemy {1+i, 150, 0.5f, 20, Enemy_Type::Normal, 0.99f-(((float)i)*0.2f), 0.4f};  //initialise l'ennemis
            if(i==3){  //condition temporaire pour intégrer des types d'ennemis différents dans une même vague
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

            this->enemys.push_back(one_enemy);  //ajout de l'ennemi dans le tableau d'ennemis de la vague
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
    // for(int i {0}; i<this->number_enemys; i++){
    //     this->enemys[i].enemy_apparition();
    // }
}

void Wave::wave_forward(bool horizontal, bool vertical, bool UP, bool DOWN, bool LEFT, bool RIGHT){
    const double time {glfwGetTime()/10};
    const double time_elapse {time - previous_time};  //récupère le temps en direct
    previous_time = time;
    if(horizontal && !vertical){   // Vérifie les directions demandées pour toute la vague d'ennemis
        if(RIGHT && !LEFT){
            for(int i {0}; i<this->number_enemys; i++){
                this->enemys[i].pos_X+=this->enemys[i].speed*time_elapse;  //modifie la position de l'ennemi directement en ajoutant le temps direct multiplié par la vitesse de l'ennemi.
                this->enemys[i].enemy_apparition();  //Apelle la méthode d'apparition de l'ennemi
            }
        }
        else if(!RIGHT && LEFT){
            for(int i {0}; i<this->number_enemys; i++){
                this->enemys[i].pos_X-=this->enemys[i].speed*time_elapse;
                this->enemys[i].enemy_apparition();
            }
        }
    }
    else if(!horizontal && vertical){
        if(UP && !DOWN){
            for(int i {0}; i<this->number_enemys; i++){
                this->enemys[i].pos_Y+=this->enemys[i].speed*time_elapse;
                this->enemys[i].enemy_apparition();
            }
        }
        else if(!UP && DOWN){
            for(int i {0}; i<this->number_enemys; i++){
                this->enemys[i].pos_Y-=this->enemys[i].speed*time_elapse;
                this->enemys[i].enemy_apparition();
            }
        }
    }
}