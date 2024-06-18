#include "wave.hpp"

#include "enemy.hpp"
#include "utils.hpp"
#include "GLHelpers.hpp"
#include "eventDispatcher.hpp"


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <img/img.hpp>
#include <iostream>
#include <vector>
#include <sstream>
#include "simpletext.h"

double previous_time {0.0};  //intialisation pour l'enregistrement du temps en direct

void Wave::create_wave(int level){
    WeightedGraph graphe;
    std::filesystem::path path = make_absolute_path("data/niveau1.itd", true);
    read_itd_file(path.string(), graphe);
    this->graph = graphe;  //initialise le graphe que suivra la vague d'ennemis
    
    if(level == 1){  //Si c'est la vague numéro 1, on est donc au level 1
        for(int i {0}; i<this->number_enemys; i++){
            Enemy one_enemy {1+i, 150, 0.5f, 20, Enemy_Type::Normal, -1.8f-(((float)i)*(120.0f/720.0f)), 1.0f-2.0f*(120.0f/720.0f), 0, 1, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}};  //initialise les ennemis, on les met par défaut au type Normal
            if(i==3){  //condition pour intégrer des types d'ennemis différents dans une même vague
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
    else if(level == 2){ //Si c'est la vague numéro 2, on est donc au level 2
        for(int i {0}; i<this->number_enemys; i++){
            Enemy one_enemy {1+i, 150, 0.5f, 20, Enemy_Type::Normal, -1.8f-(((float)i)*(120.0f/720.0f)), 1.0f-2.0f*(120.0f/720.0f), 0, 1, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}}; //initialise les ennemis, on les met par défaut au type Normal
            if(i==3 || i==4 || i==7){  //condition pour intégrer des types d'ennemis différents dans une même vague
                one_enemy.life = 100;
                one_enemy.speed = 1.0f;
                one_enemy.money_reward = 30;
                one_enemy.type = Enemy_Type::Fast;
            }
            else if(i==8 || i==10){
                one_enemy.life = 250;
                one_enemy.speed = 0.25f;
                one_enemy.money_reward = 50;
                one_enemy.type = Enemy_Type::Robust;
            }

            this->enemys.push_back(one_enemy);  //ajout de l'ennemi dans le tableau d'ennemis de la vague
        }
    }
    else if(level == 3){ //Si c'est la vague numéro 3, on est donc au level 3
        for(int i {0}; i<this->number_enemys; i++){
            Enemy one_enemy {1+i, 150, 0.5f, 20, Enemy_Type::Normal, -1.8f-(((float)i)*(120.0f/720.0f)), 1.0f-2.0f*(120.0f/720.0f), 0, 1, {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}};  //initialise les ennemis, on les met par défaut au type Normal
            if(i==3 || i==4 || i==7 || i==13){  //condition pour intégrer des types d'ennemis différents dans une même vague
                one_enemy.life = 100;
                one_enemy.speed = 1.0f;
                one_enemy.money_reward = 30;
                one_enemy.type = Enemy_Type::Fast;
            }
            else if(i==8 || i==10 || i==14){
                one_enemy.life = 250;
                one_enemy.speed = 0.25f;
                one_enemy.money_reward = 50;
                one_enemy.type = Enemy_Type::Robust;
            }

            this->enemys.push_back(one_enemy);  //ajout de l'ennemi dans le tableau d'ennemis de la vague
        }
    }
}


void Wave::wave_setup(int level){ //Cette méthode appelle la création du jeu
    this->create_wave(level);
}

void Wave::wave_forward(){ //méthode pour faire avancer la vague d'ennemis vers son but
    const double time {glfwGetTime()/5}; //On le divise pour que les ennemis n'aillent pas trop vite
    const double time_elapse {time - previous_time};  //récupère le temps en direct
    previous_time = time;

    for (int i {0}; i < this->number_enemys; i++) {
        this->enemys[i].enemy_forward(time_elapse, this->graph);  //On fait avancer chaque ennemis de la vague, en donnant le graphe dont ils ont besoin
    }
}

bool Wave::enemys_of_one_wave_dead(){  //Méthode pour vérifier si les ennemis d'une vague sont tous mort. Celle-ci sert pour switcher entre chaque nouvelle vague d'ennemis
    for (const auto& enemy : enemys) {
        if (enemy.enemy_id != -1) {  // Si au moins un ennemi est vivant (son id n'est pas -1)
            return false;
        }
    }
    return true;
}

void Wave::allEnemiesDead() const {
    int death {0};
    bool all_death = true;
    for (const auto& enemy : enemys) {
        if (enemy.enemy_id != -1) {  // Si au moins un ennemi est vivant (son id n'est pas -1)
            all_death = false;
        }
    }
    if (!all_death){
        death = 0;
    }
    else{
        death = -1;
    }
    EventDispatcher::instance().enemy_happen(death); //informe que tous les ennemis ont été tué
}
