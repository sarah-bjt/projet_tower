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
    WeightedGraph graphe;
    read_itd_file(make_absolute_path("data/niveau1.itd", true), graphe);
    for(int i {0}; i<graphe.node_positions.size(); i++){
        std::cout << graphe.node_positions[i].first << ", " << graphe.node_positions[i].second << std::endl;
    }
    this->graph = graphe;
    if(level == 1){
        for(int i {0}; i<this->number_enemys; i++){
            Enemy one_enemy {1+i, 150, 0.5f, 20, Enemy_Type::Normal, -1.8f-(((float)i)*(120.0f/720.0f)), 1.0f-2.0f*(120.0f/720.0f), 0, 1, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}};  //initialise l'ennemis
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

void Wave::wave_forward(){
    const double time {glfwGetTime()/40};
    const double time_elapse {time - previous_time};  //récupère le temps en direct
    previous_time = time;
    // for(int i {0}; i<this->number_enemys; i++){
    //     this->enemys[i].enemy_forward(time_elapse, horizontal, vertical, UP, DOWN, LEFT, RIGHT); //this->H, this->V, this->u, this->d, this->l, this->r
    // }
    for (int i {0}; i < this->number_enemys; i++) {
        // this->enemys[i].enemy_forward(time_elapse);
        this->enemys[i].enemy_forward(time_elapse, this->graph);
    }
}